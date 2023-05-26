// COPYRIGHT Dassault Systemes 2012
#ifndef CATOMYONLINEOFFLINECONNECTIONADAPTER_H_
#define CATOMYONLINEOFFLINECONNECTIONADAPTER_H_

#include "CATIOmyOnlineOfflineConnection.h"
#include "CATEventSubscriber.h"
#include "CATOMYBaseSession.h"
/**
 * @level Protected
 * @usage U4
 * Adapter for CATIOmyOnlineOfflineConnection callbacks management.
 */
class ExportedByCATOMYBaseSession CATOmyOnlineOfflineConnectionAdapter: public CATIOmyOnlineOfflineConnection
{
public:
  CATOmyOnlineOfflineConnectionAdapter();
  virtual ~CATOmyOnlineOfflineConnectionAdapter();

  /**
   * Default behavior is always FALSE. You may need to overload this method if needed.
   */
  CATBoolean NeedsCallbackForConnection();

  /**
   * Manages the internals for callback management for adding subscriptions.
   */
  CATCallback AddConnectionCallbackSubcription(CATBaseUnknown * iEventSubscriber,
      CATSubscriberMethod iMehtodToCall,
      CATSubscriberData iClientData=NULL);

  /**
   * Manages the internals for callback management for removing subscriptions.
   */
  HRESULT RemoveConnectionCallbackSubcription(CATBaseUnknown * iEventSubscriber,
      CATCallback iCallbackOnSwitch);

  /**
   * Emits a CATOmyOnlineOfflineConnectionSuccess notification
   */
  HRESULT ConnectionSuccess();

  /**
   * Emits a CATOmyOnlineOfflineConnectionFailure notification
   */
  HRESULT ConnectionFailure();

  HRESULT OfflineConnectionFailure();
  HRESULT SetFakeConnectionAbortedForOffline();
private:
  CATEventSubscriber * _CallbackManager;

  HRESULT _EmitConnectionNotif(CATNotification * iNotif);
};
#endif
