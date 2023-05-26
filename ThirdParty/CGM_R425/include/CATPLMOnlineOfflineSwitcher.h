#ifndef CATPLMOnlineOfflineSwitcher_h
#define CATPLMOnlineOfflineSwitcher_h

/**
 * @level Protected
 * @usage U1
 */
 
#include "CATPLMIntegrationAccess.h"
#include "CATIOmyOnlineOfflineConnection.h"
#include "CATOmySessionRecordServices.h"

#include "CATBoolean.h"
#include "CATIAV5Level.h"

class CATProxySpace;
class CATIAdpErrorMonitor;

class ExportedByCATPLMIntegrationAccess CATPLMOnlineOfflineSwitcher
{
public:
  /*
  * Returns TRUE if the user is working online.
  * Note that if the switch is not available, this method will always return TRUE.
  */
  static CATBoolean IsOnline();

  /*
  * Returns TRUE if the user is working offline.
  * Note that if the switch is not available, this method will always return FALSE.
  */
  static CATBoolean IsOffline();
  
  /*
  * Same as previous, but the error is reported to the current CATIPLMMaintenanceTubeErrorReporter
  * In an interactive session, this will a warning panel.
  */
  static CATBoolean IsOfflineWithReport();

  /*
  * Inform if it is possible to perform an online/offline switch.
  * @param ioErrorMonitor : error monitor to retrieve more informations on why the switch is not available.
  */
  static CATBoolean CanSwitch(CATIAdpErrorMonitor * ioErrorMonitor = NULL);

private:
  /*
  * Switch online. Returns S_OK if the switch operated normaly, S_FALSE if the session was already
  * online, E_NOTIMPL if the switch is not available and E_FAIL if an other error occured.
  *
  * iConnection should manage the connection to the current provider. Before the switch, Disconnect
  * will be called, after the switch, Connect will be called.
  *
  * If iSpace is not specified, the current Authoring space will be used.
  */
  static HRESULT SwitchOnline(CATIOmyOnlineOfflineConnection * iConnection, CATIAdpErrorMonitor * ioErrorMonitor = NULL);
  static HRESULT SwitchOnline(CATIOmyOnlineOfflineConnection * iConnection, const CATProxySpace & iSpace, CATIAdpErrorMonitor * ioErrorMonitor = NULL);

  /*
  * Only restore the connection to Offline provider (ie. the offline tube impersonating the online)
  */
  static HRESULT CancelSwitchOnline(CATIOmyOnlineOfflineConnection * iConnection, CATIAdpErrorMonitor * ioErrorMonitor = NULL);

  /*
  * Handles reconnection if offline switch fails. This can happen if login parameters changed since first connection.
  * (ie. switching collab space) TODO : handle switch collab space
  */
  static HRESULT CancelSwitchOffline(CATIOmyOnlineOfflineConnection * iConnection, CATIAdpErrorMonitor * ioErrorMonitor = NULL);


  /*
  * Switch offline. Returns S_OK if the switch operated normaly, S_FALSE if the session was already
  * offline, E_NOTIMPL if the switch is not available and E_FAIL if an other error occured.
  *
  * iConnection should manage the connection to the current provider. Before the switch, Disconnect
  * will be called, after the switch, Connect will be called.
  *
  * If iSpace is not specified, the current Authoring space will be used.
  */
  static HRESULT SwitchOffline(CATIOmyOnlineOfflineConnection * iConnection, CATIAdpErrorMonitor * ioErrorMonitor = NULL);
  static HRESULT SwitchOffline(CATIOmyOnlineOfflineConnection * iConnection, const CATProxySpace & iSpace, CATIAdpErrorMonitor * ioErrorMonitor = NULL);

  static HRESULT SwitchOfflineAuto(CATIOmyOnlineOfflineConnection * iConnection, CATIAdpErrorMonitor * ioErrorMonitor = NULL);

  static HRESULT Switch(RecordMode iFrom, RecordMode iTo, CATIOmyOnlineOfflineConnection * iConnection, CATIAdpErrorMonitor * ioErrorMonitor);
  static void EmitCallback();
  static HRESULT Disconnect();

  static HRESULT GetStreams(const CATProxySpace & iSpace);
  static HRESULT RunLocalSave();
#if !defined(CATIAR424)
  static HRESULT IsConnectedToDWS(CATIAdpErrorMonitor * ioErrorMonitor);
#endif 

  friend class CATPLMOnlineOfflineConnectionCallbackManager;
  friend class CATOxiOnlineOfflineSwitch;
  friend class CATPLMFaradayCmd;
  friend class CATOmyOnlineOfflineSwitchCallback;
  friend class CATAdpAllInOneOffline;
  friend class CATPLMItgNetworkEvent;
};
#endif
