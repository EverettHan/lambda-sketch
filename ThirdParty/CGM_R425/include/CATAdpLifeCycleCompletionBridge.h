/**
* @level Protected
* @usage U1  
*/
#ifndef CATAdpLifeCycleCompletionBridge_h
#define CATAdpLifeCycleCompletionBridge_h

#include "CATPLMIntegrationAccess.h"
#include "IUnknown.h"
#include "CATLISTV_CATPLMID.h"

class CATString;


class ExportedByCATPLMIntegrationAccess CATAdpLifeCycleCompletionBridge
{
public:
  virtual HRESULT CompleteForLifeCycle( const CATString & iOperationName, const CATPLMIDs & iInputs, CATPLMIDs & oCompleteScope) = 0;
};

class ExportedByCATPLMIntegrationAccess CATAdpLifeCycleCompletionBridgeAccess
{
public:
  static CATAdpLifeCycleCompletionBridge * GetAdpLifeCycleCompletionBridge();
};
#endif
