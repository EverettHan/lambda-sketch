#ifndef CATPLMONLINESWITCHBLLAUNCHER_H_
#define CATPLMONLINESWITCHBLLAUNCHER_H_

#include "CATPLMIntegrationBase.h"
#include "CATBaseUnknown.h"
#include "CATEventSubscriberTypedefs.h"
#include "CATNotification.h"
#include "CATProxySpace.h"

class CATNotification;
class CATComponentIdSet;
class CATComponentId;

class ExportedByCATPLMIntegrationBase CATPLMOnlineSwitchBLLauncher : public CATBaseUnknown
{
  CATProxySpace _space;
  CATCallback _callback;
public:
  CATPLMOnlineSwitchBLLauncher();
  ~CATPLMOnlineSwitchBLLauncher();

  void SetProxySpace(const CATProxySpace & iSpace);
private:
  void OnOnlineOfflineSwitch(CATCallbackEvent iEvent, void *,
      CATNotification * iNotification, CATSubscriberData iClientData, CATCallback iCallback);
};

#endif /* CATPLMONLINESWITCHBLLAUNCHER_H_ */
