// COPYRIGHT Dassault Systemes 2012
#ifndef CATIGenericSessionFilterFactory_H
#define CATIGenericSessionFilterFactory_H

/**
* @level Private
* @usage U3
*/

#include "CATBaseUnknown.h"
#include "CATPLMModelerOccInterfaces.h"
#include "CATBoolean.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerOccInterfaces IID IID_CATIGenericSessionFilterFactory;
#else
extern "C" const IID IID_CATIGenericSessionFilterFactory ;
#endif

class CATIGenericSessionFilter;

/**
* This interface is to be implemented by any kind of generic filter factory.
* Ex : factory for filter federator, configuration filter, etc ...
* The factory is to be retrieved via ::CATInstantiateComponent("xxxFactory", IID_CATIGenericSessionFilterFactory, (void**)&factory)
*/

class ExportedByCATPLMModelerOccInterfaces CATIGenericSessionFilterFactory : public CATBaseUnknown
{
  CATDeclareInterface;

public : 

  /**
  * Computes a generic filter for the given data.
  *  @param iData
  *      - either NULL : to create a filter federator (CATIGenericSessionFilterFederator*), or a configured split filter
  *      - or CATICfgSessionFilter* to create a configuration filter, or an engineering activation filter
  *  @param oFilter
  *      The computed filter
  */
  virtual HRESULT CreateGenericSessionFilter(const CATBaseUnknown* iData, CATIGenericSessionFilter*& oFilter) = 0;
};

CATDeclareHandler(CATIGenericSessionFilterFactory, CATBaseUnknown);

#endif
