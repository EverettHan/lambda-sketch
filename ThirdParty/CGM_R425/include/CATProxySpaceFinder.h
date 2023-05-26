#ifndef CATProxySpaceFinder_H
#define CATProxySpaceFinder_H

#include "ExportedByCATPLMTos.h"
#include "CATPLMRepositoryName.h"
#include "CATProxySpaceCategory.h"
#include "CATUnicodeString.h"
#include "CATUuid.h"
#include "CATOmxIter.h"
#include "CATPLMID.h"
#include "CATOmxOptional.h"

class CATProxySpace;
class CATOmxTextStream;
class CATProxySpaceFinder;
CATOmxTextStream& operator<<(CATOmxTextStream&, const CATProxySpaceFinder&);

/**
 * Find and create TOS spaces (CATProxySpace)
 * a TOS space is identified by:
 *   - a repository (@href CATProxySpace::GetRepositoryName) for example "PLM1" for MatrixOne or "TST" for TSTPROVIDER
 *   - a category   (@href CATProxySpace::GetSpaceCategory) see @href CATProxySpaceCategory
 *   - a name       (@href CATProxySpace::GetSpaceName)
 *   - an uuid      (@href CATProxySpace::GetUuid) it is non zero (and unique) for "incoming" spaces, zero for others
 */
class CATProxySpaceFinder
{
  CATOmx::optional<CATPLMRepositoryName> m_repository;
  CATOmx::optional<CATProxySpaceCategory> m_category;
  CATOmx::optional<CATUnicodeString> m_name;
  CATUuid m_uuid = CATUuid(nullptr);
  friend CATOmxTextStream& operator<<(CATOmxTextStream&, const CATProxySpaceFinder&);
public:
  /** default constructor, no field is set*/
  CATProxySpaceFinder() = default;
  /** default constructor, category is set*/
  CATProxySpaceFinder(CATProxySpaceCategory iCategory) :m_category(iCategory) {}
  ExportedByCATPLMTos ~CATProxySpaceFinder();
  CATProxySpaceFinder(const CATProxySpaceFinder&) = delete;
  CATProxySpaceFinder& operator=(const CATProxySpaceFinder&) = delete;

  /** select repository (must be non empty) */
  CATProxySpaceFinder& SetRepository(const CATPLMRepositoryName& repository) { m_repository = repository; return *this; }

  /** copy repository from a PLMID (must be non empty) */
  CATProxySpaceFinder& SetRepository(const CATPLMID& id)
  {
    CATPLMRepositoryName repository;
    id.GetRepositoryName(repository);
    return SetRepository(repository);
  }

  /** select category */
  CATProxySpaceFinder& SetCategory(CATProxySpaceCategory category) { m_category = category; return *this; }

  /** select name (must be non empty) */
  CATProxySpaceFinder& SetName(const CATUnicodeString& name) { m_name = name; return *this; }

  /** select uuid (must be non zero) */
  CATProxySpaceFinder& SetUuid(const CATUuid& uuid) { m_uuid = uuid; return *this; }

  /**
   * Find all spaces matching constraints
   * Notice that CatProxySpaceCategory_Incoming spaces are not returned
   * unless their uuid has been provided
   */
  ExportedByCATPLMTos CATOmxIter<CATProxySpace> FindAll() const;

  /**
   * Find the unique space matching constraints
   * If several spaces match, none is returned
   * if you provided
   *   {uuid}                        for "incoming" spaces
   *   {repository, category, name}  for others
   * you are guaranteed to retrieve zero or one space
   * in other cases, you should not use this method
   */
  ExportedByCATPLMTos CATProxySpace FindUnique() const;

  /**
   * Create proxy space
   * repository/category/name fields are mandatory
   * uuid is mandatory if category is CatProxySpaceCategory_Incoming, forbidden elsewhere
   * returns empty in case of failure (invalid inputs or space already exists)
   */
  ExportedByCATPLMTos CATProxySpace Create() const;

  /**
   * Find unique space matching constraints or create it
   */
  ExportedByCATPLMTos CATProxySpace FindOrCreate() const;
};

#endif
