#ifndef CATOmyOnlineOfflineSwitch_h
#define CATOmyOnlineOfflineSwitch_h

/**
 * @level Protected
 * @usage U1
 */

#include "CATBoolean.h"
#include "CATOMYBaseSession.h"
#include "CATOmySessionRecordServices.h"
#include "CATEventSubscriber.h"

class CATIOmyOnlineOfflineConnection;
class ExportedByCATOMYBaseSession CATOmyOnlineOfflineSwitch
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
  * Returns TRUE if the user is working offline (due to network deconnection).
  * Note that if the switch is not available, this method will always return FALSE.
  */
  static CATBoolean IsOfflineAuto();

  static CATBoolean IsConnectedToNetwork();

  /*
  * Returns TRUE if the user is working offline. If the session is offline, the 'offline error'
  * popup will be sent.
  * Note that if the switch is not available, this method will always return FALSE.
  */
  static CATBoolean IsOfflineWithReport(CATBoolean iKillRunningCommand = FALSE);

  /*
  * Inform if it is possible to perform an online/offline switch.
  */
  static CATBoolean CanSwitchOffline();

  /*
  * Inform if it is possible to perform an online/offline switch.
  */
  static CATBoolean CanSwitch();

  /*
  * Adds a callback for the "CATOmyOnlineOfflineSwitchOccured" event.
  * This event is triggered once a successful switch has occured.
  * See @CATEventSubscriber::AddCallback for details on the arguments.
  */
  static CATCallback AddCallbackOnSwitch(CATBaseUnknown * iEventSubscriber,
    CATSubscriberMethod iMehtodToCall,
    CATSubscriberData iClientData = NULL);

  /*
  * Removes a callback for the "CATOmyOnlineOfflineSwitchOccured" event.
  * See @CATEventSubscriber::RemoveCallback for details on the arguments.
  */
  static void RemoveCallbackOnSwitch(CATBaseUnknown * iEventSubscriber,
    CATCallback iCallbackOnSwitch);

  // If variable OK, Activates Offline Favorites and deactivate classical offline
  // Target : R418
  static CATBoolean SwitchOfflineToOfflineContents();

  struct SwitchToPLMQL
  {
    SwitchToPLMQL()
    {
      AdditionalOfflineInit();
    }
    ~SwitchToPLMQL()
    {
      SetOfflineInitHasDone();
    }
  };

private:
  static HRESULT CheckSwitchRequest(RecordMode iFrom, RecordMode iTo);
  static HRESULT Switch(RecordMode iFrom, RecordMode iTo);
  static void EmitCallback();

  //Those two methods are here to switch to PLMQL
  //as we are not able to record xMQL messages yet
  static void SetOfflineInitHasDone();
  static void AdditionalOfflineInit();
  //
  static CATBoolean IsOfflineInitDone();

  friend class xMQLQueryFilter;
  friend class CATPLMOnlineOfflineSwitcher;
  friend class OmyOfflineTestUtils;
  friend class CATPLMInitSessionCmd;
  friend class CATPLMSessionImageManagerImpl;
  friend class CATOmyVariables;
  friend class TestFaradayBaseEnvHook;
  friend class CATPLMxQueryAdapter;
  friend class CATPLMxTransaction;
  friend class TSTCATPLMxNavOnlineOfflineSwitch;
  friend class CATPLMSemanticRelationStore;
  friend class TSTCATPLMxNavOnlineOfflineSwitchUsingCache;
};
#endif
