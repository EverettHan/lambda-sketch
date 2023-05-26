// COPYRIGHT DASSAULT SYSTEMES	2006

#ifndef CATOmbRelationsFilter_H
#define CATOmbRelationsFilter_H

/**
 * @level Protected
 * @usage U1
 */
#include "CATObjectModelerBase.h"
#include "CATOmbRelationInformation.h"
#include "CATUnicodeString.h"
#include "CATOmxAutoPtr.h"
#include "CATOmxDeprecated.h"

class CATOmbRelationsFilterImpl;
class CATOmbRelationsCondition;

typedef unsigned int CATOmbRelationsBasicFilters;

/**
* No filter
*/
#define CATOmbRelationsBasicFilter_None            0x00000000
/**
* Only displayable relations will be returned
* e.g. : system models like configuration or bridge will be not visible
*/
#define CATOmbRelationsBasicFilter_UIDisplayable   0x00000001

/**
 * Filter on relation metadata to be used in CATOmbRelationalBrowseServices.
 */
class ExportedByCATObjectModelerBase CATOmbRelationsFilter
{
public:
  // filter on role or category (see next constructor)
  enum FilterAttributeName { Role = 0, Category = 2 };

  /**
   * Build a filter based on a role AND category.
   */
  CATOmbRelationsFilter(const CATUnicodeString& iRole, const CATUnicodeString& iCategory);

  /**
  * Build a filter based on a role or category.
  */
  CATOmbRelationsFilter(FilterAttributeName iFilterAttr, const CATUnicodeString & iValue);

  /**
  * Build a filter based on Orientation.
  */
  CATOmbRelationsFilter(CATOmbRelationOrientation iOrientation);

  /**
  * Build basic filters.
  */
  CATOmbRelationsFilter(CATOmbRelationsBasicFilters iBasicFilters_MaskAnd);

  /** destructor*/
  ~CATOmbRelationsFilter();

  /**
   * broken design, do not use
   * use constructor with role AND category instead
   */
  CATOmbRelationsFilter& operator && (const CATOmbRelationsFilter & iRelationsFilter);

  /** @nodoc */
  inline CATOmbRelationsFilterImpl * GetLetter() { return _pLetter; };

  CATOmbRelationsFilter() = delete;
  OMX_DEPRECATED("not implemented") CATOmbRelationsFilter(const CATOmbRelationsFilter&);
  CATOmbRelationsFilter& operator=(const CATOmbRelationsFilter&) = delete;
private:
  CATOmxAutoPtr<CATOmbRelationsFilterImpl> _pLetter;
};

#endif
