#ifndef CATSFDagNodeQuery_H
#define CATSFDagNodeQuery_H

#include "GMScalarFieldsOperators.h"

#include "CATBoolean.h"
#include "CATUnicodeString.h"

// CGM
#include "CATICGMObject.h"

// Scalar Fields
#include "SFTypes.h"
#include "CATImplicitResource.h"

// STD
#include <memory>

namespace SF
{
  class SFDagNode;
  using  SFDagNodePtr = std::shared_ptr<SFDagNode>;
}

/**
 * CATSFDagNodeQuery contains methods to introspect specific node types members.
 * This class is meant to be overridden by node type.
 * You can use GetTypedQuery to easily get the right derived class for you specific
 * node type.
 */
class ExportedByGMScalarFieldsOperators CATSFDagNodeQuery
{
public:
  typedef std::unique_ptr<CATSFDagNodeQuery>      UPtr;
  typedef std::shared_ptr<CATSFDagNodeQuery>      Ptr;

  /**
   * ctor
   *
   */
  CATSFDagNodeQuery();
  
  /**
   * ctor
   *
   */
  CATSFDagNodeQuery(const CATSFDagNodeQuery& iOther);

  /**
   * dtor
   */
  virtual ~CATSFDagNodeQuery();

  /**
   * These are needed convenience but don't use :).
   */
  virtual void* GetImpl() = 0;
  virtual void* GetNodeImpl() = 0;
  virtual SF::SFDagNodePtr& GetNode() = 0;

protected:
};

ExportedByGMScalarFieldsOperators CATSFDagNodeQuery::Ptr  GetSFDgNodeQuery(const SF::SFDagNodePtr& iNode);

/**
* unordered_set is used for de duplication. We need to define a hash function
* (and one for equality) for the unordered_set. PtrHashFct is used for that.
*/
struct ExportedByGMScalarFieldsOperators CATSFDagNodeQueryRawPtrHashFct {
  size_t operator()(CATSFDagNodeQuery* iDagQuery) const;
};

struct ExportedByGMScalarFieldsOperators CATSFDagNodeQueryPtrHashFct {
  size_t operator()(CATSFDagNodeQuery::Ptr iDagQuery) const;
};

/**
  * unordered_set is used for de duplication. We need to define an equality function.
  */
struct ExportedByGMScalarFieldsOperators CATSFDagNodeQueryRawPtrEqualFct {
  bool operator ()(CATSFDagNodeQuery* iDagQuery1, CATSFDagNodeQuery* iDagQuery2) const;
};

struct ExportedByGMScalarFieldsOperators CATSFDagNodeQueryPtrEqualFct {
  bool operator ()(CATSFDagNodeQuery::Ptr iDagQuery1, CATSFDagNodeQuery::Ptr iDagQuery2) const;
};

#endif // CATSFDagNodeQuery_H
