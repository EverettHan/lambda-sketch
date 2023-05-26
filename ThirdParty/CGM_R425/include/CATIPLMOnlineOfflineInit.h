#ifndef CATIPLMOnlineOfflineInit_h
#define CATIPLMOnlineOfflineInit_h

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMOnlineOfflineInit;
#else
extern "C" const IID IID_CATIPLMOnlineOfflineInit;
#endif

class ExportedByCATPLMIntegrationInterfaces CATIPLMOnlineOfflineInit : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /**
  * Method called during session initialistion to handle data necessary for nomad use.
  * While online, all client-server calls will be recorded. While starting a session in
  * offline mode, the recorded messages are sent back to the application. The messages
  * are expected to be run in the same order.
  * @returns
  * <dl>
  * <dt>S_OK</dl><dd>Everything went ok, the session initialisation can continue.</dd>
  * <dt>E_*</dl><dd>Something went wrong, the session initialisation should stop.</dd>
  * </dl>
  */
  virtual HRESULT OnlineOfflineInit() =0 ;
};
CATDeclareHandler(CATIPLMOnlineOfflineInit,CATBaseUnknown);
#endif
