
/**
* @level Private
* @usage U1
*/


#ifndef __CATPLMAdapterNotification_h__
#define __CATPLMAdapterNotification_h__

#include "CATNotification.h"
#include "CATPLMAdapterEvents.h"
#include "CATLISTP_CATPLMProviderEvent.h"
#include "CATTime.h"
#include "CATSysSimpleHashTable.h"
#include "CATUnicodeString.h"
#include "CATLib.h"
#include "CATPLMServicesItf.h"

class CATPLMProviderEvent;
class CATPLMRepositoryName;


/**
* Class representing a PLM adapter notification.
* <br><b>Role</b>: For each command executed by the PLM Adapter (Query, Expand, Save, ...), a
* new notification is created to collect information on what append during this action.</br>
* This notification collection information from connected provider to report their activities.
*/
class ExportedByCATPLMServicesItf CATPLMAdapterNotification : public CATNotification
{
  CATDeclareClass;

public:
  virtual ULONG __stdcall AddRef();
  virtual ULONG __stdcall Release();

  /**
  * Constructs this object.
  */
  CATPLMAdapterNotification(CATPLMAdapterEvents iEvent);

  /**
  * Destructs this object.
  */
  virtual ~CATPLMAdapterNotification();

  /**
  * Gets the time when this notification iscreated
  * @return
  *   The creation time.
  */
  CATUnicodeString& GetCreationTime();

  /**
  * Gets the elapsed time spent by the PLMAdapter command.
  * @return
  *   The elapsed time.
  */
  unsigned int GetElapsedTime() const;

  /**
  * Get the PLM adapter event associated with this notification.
  * @return
  *   The PLM Adapter Event.
  */
  CATPLMAdapterEvents GetAdapterEvent() const;

  /**
  * Gets the number of events added by a provider.
  * @param iRepositoryName [in]
  *   The repository name of a provider.
  * @param iInstanceId [in]
  *   The instance id
  *
  * @return
  *   Explain return values
  *
  */
  unsigned int GetNbPvEvents(const CATPLMRepositoryName& iRepositoryName, const CATUnicodeString& iInstanceId) const;

  /**
  * Provides the list of events added by a provider.
  * @param iRepositoryName [in]
  *   The repository name of the provider.
  * @param iInstanceId [in]
  *   The name of the instance of provider.
  * @param oEvents [out]
  *   The list of events.
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL.
  */
  HRESULT GetPvEvents(const CATPLMRepositoryName& iRepositoryName, const CATUnicodeString& iInstanceId, CATLISTP_CATPLMProviderEvent*& oEvents) const;

  /**
  * Gets the number of provider events added in this notification.
  * @return
  *   The number of events.
  */
  unsigned int GetNbPvEvents() const;

  /**
  * Provides all provider events stored in this notification.
  * @param oEvents [out]
  *   All provider events added. This list is the same for all providers that have added an event in this notification.
  */
  void GetPvEvents(CATLISTP_CATPLMProviderEvent& oEvents) const;

  /**
  * Sets this notification to state ready to dispatch.
  * <br><b>Role</b>: This method computes the elapsed time spent by this notification.
  */
  void SetReadyToDispatch();

  /**
   * Sets the satus of the notification
   */
  void SetStatus(HRESULT iHR);

  /**
   * Gets the internal Status of the Notification
   */
  HRESULT GetStatus();

  /*------------------------------*\
  |  Method reserved for provider  |
  \*------------------------------*/

  /**
  * Adds an event in this notification.
  * <br><b>Role</b>: This new event is indexed by provider.
  * @param iEvent [in]
  *   The event to add in this notification.
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL.
  */
  HRESULT AddPvEvent(CATPLMProviderEvent* iEvent);

  /** @nodoc */
  static const char* GetName(CATPLMAdapterEvents iEvent);

private:
  /** List of all provider events of this notification */
  CATLISTP_CATPLMProviderEvent _AllPvEvents;
  /** Adapted command executed*/
  CATPLMAdapterEvents _AdapterCmd;
  /** Timer used to compute elapsed time*/
  CATTimerId _TimerId;
  /** Creation time of this notification*/
  CATUnicodeString _CreationTimeStr;
  /** Elapsed time of this command in ms*/
  CATULONG32 _ElapsedTime;
  /** Boolean to indicate if all provider events have been added in this notification. */
  CATBoolean ReadyToDispatch;
  /** Hash table to store Provider Events indexed by provider. */
  CATSysSimpleHashTable _HashTab;
  /** Status of the notification */
  HRESULT _HR;
};

/** @nodoc */
#define DECLAREADAPTERNOTIF(NOTIF) \
class ExportedByCATPLMServicesItf CATPLMAdapterNotification_##NOTIF: public CATPLMAdapterNotification \
  { \
    CATDeclareClass; \
  public:  \
  CATPLMAdapterNotification_##NOTIF():CATPLMAdapterNotification(AdpEvent_##NOTIF){}; \
  virtual ~CATPLMAdapterNotification_##NOTIF(){}; \
  };

/** @nodoc */
#define IMPLEMENTADAPTERNOTIF(NOTIF) \
  CATImplementClass(CATPLMAdapterNotification_##NOTIF, Implementation, CATPLMAdapterNotification, CATnull);


DECLAREADAPTERNOTIF(PrepareConnect)
DECLAREADAPTERNOTIF(Connect)
DECLAREADAPTERNOTIF(Query)
DECLAREADAPTERNOTIF(Expand)
DECLAREADAPTERNOTIF(Navigate)
DECLAREADAPTERNOTIF(Open)
DECLAREADAPTERNOTIF(FetchQuery)
DECLAREADAPTERNOTIF(QueryCount)
DECLAREADAPTERNOTIF(Save)
DECLAREADAPTERNOTIF(Import)
DECLAREADAPTERNOTIF(NewVersion)
DECLAREADAPTERNOTIF(CheckEdit)
DECLAREADAPTERNOTIF(DeleteRef)
DECLAREADAPTERNOTIF(Maturity)
DECLAREADAPTERNOTIF(Clone)
DECLAREADAPTERNOTIF(Copy)
DECLAREADAPTERNOTIF(LockUnlock)
DECLAREADAPTERNOTIF(Metadata)
DECLAREADAPTERNOTIF(Disconnect)
DECLAREADAPTERNOTIF(LoadEnvironment)
DECLAREADAPTERNOTIF(LoadDomain)
DECLAREADAPTERNOTIF(LoadModeler)
DECLAREADAPTERNOTIF(Commit)
DECLAREADAPTERNOTIF(Rollback)
DECLAREADAPTERNOTIF(PushExpand)
DECLAREADAPTERNOTIF(AutoNaming)
DECLAREADAPTERNOTIF(Versioning)
DECLAREADAPTERNOTIF(ProcedureCall)
DECLAREADAPTERNOTIF(ChangeControl)
DECLAREADAPTERNOTIF(History)
DECLAREADAPTERNOTIF(WspMngt)
DECLAREADAPTERNOTIF(QueryValidity)
DECLAREADAPTERNOTIF(SearchQuery)// EPB FTS 10:03:25
DECLAREADAPTERNOTIF(Refresh)
DECLAREADAPTERNOTIF(CompletionSuggestion)
DECLAREADAPTERNOTIF(WspReservation)
DECLAREADAPTERNOTIF(SPD_Query)
DECLAREADAPTERNOTIF(SPD_Expand)
DECLAREADAPTERNOTIF(SPD_Open)
DECLAREADAPTERNOTIF(SPD_PushExpand)
DECLAREADAPTERNOTIF(SPD_SearchQuery)
DECLAREADAPTERNOTIF(CuttingXMQLRequest)
DECLAREADAPTERNOTIF(XMQLRequest)


#endif //__CATPLMAdapterNotification_h__
