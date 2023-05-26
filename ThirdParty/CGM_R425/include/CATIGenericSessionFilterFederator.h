// COPYRIGHT Dassault Systemes 2012
#ifndef CATIGenericSessionFilterFederator_H
#define CATIGenericSessionFilterFederator_H

/**
* @level Private
* @usage U3
*/

#include "CATIGenericSessionFilter.h"
#include "CATPLMModelerOccInterfaces.h"
#include "CATOmxSR.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerOccInterfaces IID IID_CATIGenericSessionFilterFederator;
#else
extern "C" const IID IID_CATIGenericSessionFilterFederator;
#endif

class CATListPtrCATIGenericSessionFilter;

/**
 * this interface is a CATIGenericSessionFilter implemented through a list of CATIGenericSessionFilter.
 * The semantic is AND (an occurrence is created if IsDisplayed return TRUE for ALL filters)
 *
 * this interface must not be implemented
 * an instance of this interface can be retrieved using
 *   CATIGenericSessionFilterFederator::Create
 * or
 *   CATFilterFederatorFactory implementation of CATIGenericSessionFilterFactory
 *
 */
class ExportedByCATPLMModelerOccInterfaces CATIGenericSessionFilterFederator : public CATIGenericSessionFilter
{
  CATDeclareInterface;
public:
  /**
  * @nodoc
  * warning: unicity (CATIGenericSessionFilter::IsEqual semantic is not ensured)
  */
  virtual HRESULT AddFilter(const CATIGenericSessionFilter* iFilter) = 0;

  /**
  * @nodoc
  * warning: unicity (CATIGenericSessionFilter::IsEqual semantic is not ensured)
  */
  virtual HRESULT RemoveFilter(const CATIGenericSessionFilter* iFilter) = 0;

  /**
  * @nodoc
  * returned pointers must be release'd
  */
  virtual HRESULT ListFilters(CATListPtrCATIGenericSessionFilter& oFilters) = 0;

  /**
   * Creates a CATIGenericSessionFilterFederator agregating input filter
   */
  static CATOmxSR<CATIGenericSessionFilterFederator> Create(CATIGenericSessionFilter& iFilter);
};

CATDeclareHandler(CATIGenericSessionFilterFederator, CATBaseUnknown);

#endif
