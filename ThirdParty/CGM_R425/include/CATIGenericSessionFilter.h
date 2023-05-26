// COPYRIGHT Dassault Systemes 2012
#ifndef CATIGenericSessionFilter_H
#define CATIGenericSessionFilter_H

/**
* @level Private
* @usage U3
*/

#include "CATBaseUnknown.h"
#include "CATPLMModelerOccInterfaces.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATBoolean.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerOccInterfaces IID IID_CATIGenericSessionFilter;
#else
extern "C" const IID IID_CATIGenericSessionFilter;
#endif

/**
 * Filter on occurrence tree
 */
class ExportedByCATPLMModelerOccInterfaces CATIGenericSessionFilter : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /**
  * Will be called during occurrence tree creation to determine if corresponding occurrence must be created
  * @param iPOI
  *    input path of instance
  *  @param oMustBeCreated
  *     TRUE  => corresponding occurrence IS     created
  *     FALSE => corresponding occurrence IS NOT created
  */
  virtual HRESULT IsDisplayed(const CATListValCATBaseUnknown_var& iPOI, CATBoolean& oMustBeCreated) = 0;

  /**
  * Compares 2 filters
  */
  virtual HRESULT IsEqual(const CATIGenericSessionFilter* iFilter, CATBoolean& oIsEqual) = 0;

  bool Equals(const CATIGenericSessionFilter& iOther) const;

  /**
  * Computes the default status. Ex : engineering activation is a default filter.
  */
  virtual CATBoolean IsDefaultFilter() = 0;
};

CATDeclareHandler(CATIGenericSessionFilter, CATBaseUnknown);

#endif
