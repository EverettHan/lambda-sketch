#ifndef CATPLMAsyncRequestServicesLimitedAccess_H
#define CATPLMAsyncRequestServicesLimitedAccess_H

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

#define CATPLMxMQL                          AuthorizedModule
#define CATPLMxProcCall                     AuthorizedModule
#define CATPLMxReadWriteXMQL                AuthorizedModule
#define CATPLMServicesItf                   AuthorizedModule
#define CATPLMImplAdapterQLBase             AuthorizedModule
#define CATPLMDWSAccess                     AuthorizedModule
#define CATPLMAsync                         AuthorizedModule
#define CATPLMIntegration                   AuthorizedModule
#define CATPLMIntegrationAccess             AuthorizedModule
#define TSTCATPLMxCreateM1Urls              AuthorizedModule
#define TSTCATPLMxFTFlatTableError          AuthorizedModule
#define TSTCATPLMxFTLogCCM3                 AuthorizedModule
#define TSTCATPLMxFTLogCCMER4               AuthorizedModule
#define TSTCATPLMxFTLogCCMER5               AuthorizedModule
#define TSTCATPLMxFTImportError             AuthorizedModule
#define TSTCATPLMxFTImport                  AuthorizedModule
#define TSTCATPLMxJSProcedureCall           AuthorizedModule
#define TSTCATPLMxFTFlatTable               AuthorizedModule
#define mKOALA                              AuthorizedModule
#define VisuPLMHelpers_Base                 AuthorizedModule
#define CATPLMItgTests                      AuthorizedModule
#define CATPLMReplicationEngineCommon       AuthorizedModule
#define InMemoryContentManagement           AuthorizedModule
#define InMemoryContentManagementTests      AuthorizedModule
#define RETestQueryListPolicyStates         AuthorizedModule
#define TransitionEngine                    AuthorizedModule
#define CATUNIWorkshop                      AuthorizedModule
#define VisuDebugSelectiveLoadingTool       AuthorizedModule
#define VisuDebugSphericalOcclusionTool     AuthorizedModule
#define CATImmNavigatorsUI                  AuthorizedModule
#define TSTCATPLMxBasic                     AuthorizedModule
#define TSTCATPLMxBasicThreadSafety         AuthorizedModule
#define CATPLMAdapterOdtBase                AuthorizedModule
#define TSTCATPLMxBasicMinMaj               AuthorizedModule
#define TSTCATPLMxCATPLMQLWithSD            AuthorizedModule
#define TSTCATPLMxSyncQuery                 AuthorizedModule
#define PLMCOEXMapping                      AuthorizedModule
#define TSTCATPLMxCSCI                      AuthorizedModule
#define CATTCLRecordBuilderMainThread       AuthorizedModule
#define CATPLMxNLV                          AuthorizedModule
#define CATPLMiPMLDataStream                AuthorizedModule
//#define CATPLMTEBusinessLogic               AuthorizedModule
//#define CATDCInfraMappingTbl                AuthorizedModule
//#define CATPLMCoExMappingXML                AuthorizedModule
//#define TransferDataServices                AuthorizedModule
//#define CATPLMTETestTEProfile               AuthorizedModule
//#define CATPLMTENewMappingTester            AuthorizedModule
#define TSTCATPLMxBasicWithWithoutMonitoring  AuthorizedModule
#define TSTCATPLMxExpandModePushWithOverload2 AuthorizedModule
#define OMYTST_Relogin                        AuthorizedModule
#define TSTCATPLMxMinVersion                  AuthorizedModule
#define TSTCATPLMxQueryNoProviderConnected     AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access To CATPLMAsyncRequestServicesLimitedAccess Services from a non-authorized module
    // Fatal error on solaris
  @error
#endif

#undef AuthorizedModule
#undef CATPLMxMQL
#undef CATPLMxProcCall
#undef CATPLMxReadWriteXMQL
#undef CATPLMServicesItf
#undef CATPLMImplAdapterQLBase
#undef CATPLMDWSAccess
#undef CATPLMAsync
#undef CATPLMIntegrationAccess
#undef CATPLMIntegration
#undef TSTCATPLMxCreateM1Urls
#undef TSTCATPLMxFTFlatTableError
#undef TSTCATPLMxFTLogCCM3
#undef TSTCATPLMxFTLogCCMER4
#undef TSTCATPLMxFTLogCCMER5
#undef TSTCATPLMxFTImportError
#undef TSTCATPLMxFTImport
#undef TSTCATPLMxJSProcedureCall
#undef TSTCATPLMxFTFlatTable
#undef mKOALA
#undef VisuPLMHelpers_Base
#undef CATPLMItgTests
#undef CATPLMReplicationEngineCommon
#undef InMemoryContentManagement
#undef InMemoryContentManagementTests
#undef RETestQueryListPolicyStates
#undef TransitionEngine
#undef CATUNIWorkshop
#undef VisuDebugSelectiveLoadingTool
#undef VisuDebugSphericalOcclusionTool
#undef CATImmNavigatorsUI
#undef TSTCATPLMxBasic
#undef TSTCATPLMxBasicThreadSafety
#undef CATPLMAdapterOdtBase
#undef TSTCATPLMxBasicMinMaj 
#undef TSTCATPLMxCATPLMQLWithSD
#undef TSTCATPLMxSyncQuery
#undef PLMCOEXMapping
#undef TSTCATPLMxCSCI
#undef CATTCLRecordBuilderMainThread
#undef CATPLMxNLV
#undef CATPLMiPMLDataStream
  //#undef CATPLMTEBusinessLogic
  //#undef CATDCInfraMappingTbl
  //#undef CATPLMCoExMappingXML
  //#undef TransferDataServices
  //#undef CATPLMTETestTEProfile
  //#undef CATPLMTENewMappingTester
#undef TSTCATPLMxBasicWithWithoutMonitoring
#undef TSTCATPLMxExpandModePushWithOverload2
#undef OMYTST_Relogin
#undef TSTCATPLMxMinVersion
#undef TSTCATPLMxQueryNoProviderConnected


#undef ExportedByCATPLMAsync

#if defined(__CATPLMAsync)
#define ExportedByCATPLMAsync DSYExport
#else
#define ExportedByCATPLMAsync DSYImport
#endif
#include "DSYExport.h"

#endif
