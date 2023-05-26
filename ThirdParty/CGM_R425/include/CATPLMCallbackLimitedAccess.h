#undef ExportedByCATPLMCallbackLimitedAccess 

//-----------------------------------------------------
//  Check that only authorized modules can link on the exported symbols
//----------------------------------------------------

/**
* @level Private
* @usage U3
*/


// List of forbidden re-define

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
#define TSTCATAdpProtectedVersioningServicesGetMajorVersionFamily AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

#error Forbidden Access To CATPLMCallbackLimitedAccess Services from a non-authorized module
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
#undef TSTCATAdpProtectedVersioningServicesGetMajorVersionFamily

#if defined(__CATPLMServicesItf)
#define ExportedByCATPLMCallbackLimitedAccess DSYExport
#else
#define ExportedByCATPLMCallbackLimitedAccess DSYImport
#endif
#include "DSYExport.h"


