
/**
* @level Private
* @usage U3
*/

#ifndef __CATIPLMCompCallbackPublisher_H__
#define __CATIPLMCompCallbackPublisher_H__

#if defined (private) || defined(friend) || defined (protected)

#error Forbidden re-define of 'private', 'friend' or 'protected'
// Fatal error on solaris
@error
#endif


#define AuthorizedModule     999

// List of authorized infrastructure modules 

#define CATPLMServicesLimitedAccess         AuthorizedModule
#define CATPLMServicesItf                   AuthorizedModule
#define CATPLMServicesUUID                  AuthorizedModule
#define CATPLMAdapterCoreStructure          AuthorizedModule
#define CATPLMAdapterUI	                    AuthorizedModule
#define CATPLMAdapterToolbar                AuthorizedModule
#define CATPLMImplAdapterBase               AuthorizedModule
#define TSTCATPLMCompCallbackMgr            AuthorizedModule
#define CATPLMEV5AccessServices	            AuthorizedModule // provider EV5
#define CATPLMSmarTeam1ProviderImpl         AuthorizedModule // provider SMT MX1
#define CATPLMDebugEngineImpl               AuthorizedModule // provider TST
#define CATPLMDebugProviderImpl             AuthorizedModule// provider TST
#define CATPLMSessionImages                 AuthorizedModule //
#define CATPLMImplAdapterQLBase             AuthorizedModule // provider BaseImpl (PLMQL)
#define CATServerCallEngine                 AuthorizedModule
#define CATPLMSessionRecorder               AuthorizedModule // Session Recorder
#define CATPLMxODTBase                      AuthorizedModule // ODT Check
#define CATPLMIndexExpandServices           AuthorizedModule
#define CATPLMMntRecorder                   AuthorizedModule // For Support tools R207
#define CATPLMImplAdapterAsync              AuthorizedModule // superdodu access to events
#define CATPLMModelBuilder                  AuthorizedModule
#define CATPLMAsync                         AuthorizedModule
#define CATPLMxMQL                          AuthorizedModule
#define TSTCATPLMxBasicMinMaj               AuthorizedModule
#define CATPLMxReadWriteXMQL                AuthorizedModule
#define TSTCATPLMxCuttingXMQLRequest        AuthorizedModule
#define ObjectModelerSystem                 AuthorizedModule
#define CATAsyncTasksPlatform_NG            AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

#error Forbidden Access To CATIPLMCompCallbackPublisher Services from a non-authorized module
    // Fatal error on solaris
  @error
#endif

#undef AuthorizedModule		
#undef CATPLMServicesLimitedAccess
#undef CATPLMServicesItf
#undef CATPLMServicesUUID
#undef CATPLMAdapterCoreStructure
#undef CATPLMAdapterUI
#undef CATPLMAdapterToolbar
#undef CATPLMImplAdapterBase
#undef TSTCATPLMCompCallbackMgr
#undef CATPLMEV5AccessServices
#undef CATPLMSmarTeam1ProviderImpl
#undef CATPLMDebugEngineImpl
#undef CATPLMDebugProviderImpl
#undef CATPLMSessionImages
#undef CATPLMImplAdapterQLBase
#undef CATServerCallEngine
#undef CATPLMSessionRecorder
#undef CATPLMxODTBase
#undef CATPLMIndexExpandServices
#undef CATPLMMntRecorder
#undef CATPLMImplAdapterAsync
#undef CATPLMModelBuilder
#undef CATPLMAsync
#undef CATPLMxMQL
#undef TSTCATPLMxBasicMinMaj
#undef CATPLMxReadWriteXMQL
#undef TSTCATPLMxCuttingXMQLRequest
#undef ObjectModelerSystem
#undef CATAsyncTasksPlatform_NG

#if defined(__ObjectModelerSystem)
#define ExportedByObjectModelerSystem DSYExport
#else
#define ExportedByObjectModelerSystem DSYImport
#endif
#include "DSYExport.h"

#include "CATWTypes.h"
#include "CATBaseUnknown.h"
#include "CATPLMAdapterEvents.h"
#include "CATEventSubscriber.h"

#ifndef LOCAL_DEFINITION_FOR_IID
  extern ExportedByObjectModelerSystem IID IID_CATIPLMCompCallbackPublisher;
#else
  extern "C" const IID IID_CATIPLMCompCallbackPublisher;
#endif


class CATPLMAdapterNotification;

/**
* Interface restricted to the CATPLMAdapter usage.
*/
class ExportedByObjectModelerSystem CATIPLMCompCallbackPublisher : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Creates an internal notification in the Adapter Callback extension
  * @param iEvent [in]
  *   The event of the notification.
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL.
  */
  virtual HRESULT CreateInternalNotification(CATPLMAdapterEvents iEvent) = 0;

  /**
  * Dispatches the current notification.
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL.
  */
  virtual HRESULT DispatchCallBacks(HRESULT iHR) = 0;

  /**
  * Removes all Callbacks registered to the CATPLMAdpater.
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL.
  */
  virtual HRESULT RemoveCallbacks() = 0;
};


#endif // __CATIPLMCompCallbackPublisher_H__
