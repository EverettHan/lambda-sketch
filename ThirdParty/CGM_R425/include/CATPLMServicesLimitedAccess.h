#undef ExportedByCATPLMServicesLimitedAccess 

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
// Rq: to ease our life during file merges, please don't reindent this list and add only to the begining or the end of the lists.

#define PLMLibraryModelImpl AuthorizedModule
#define CATDbdImportModeler AuthorizedModule
#define CATPLMItgRemoteStatusTests AuthorizedModule
#define CATOxiStatutRemote AuthorizedModule
#define CATOxiStatutRemoteAttrLink AuthorizedModule
#define CATPLMAdapterOdtBase AuthorizedModule
#define CATPLMCertifLibrary AuthorizedModule
#define CATPCTExpand AuthorizedModule
#define CATPLMChangeStatus AuthorizedModule
#define CATPLMCompletion AuthorizedModule
#define CATPLMCompletionAccess AuthorizedModule
#define CATPLMDTc AuthorizedModule
#define CATPLMDWSAccess AuthorizedModule
#define CATPLMDebugEngineImpl AuthorizedModule
#define CATPLMDebugProviderImpl AuthorizedModule
#define CATPLMDebugServices AuthorizedModule
#define CATPLMDwhImpl AuthorizedModule
#define CATPLMEV5ProviderImpl AuthorizedModule
#define CATPLMEV5ProviderR15Impl AuthorizedModule
#define CATPLMEmptyProviderImpl AuthorizedModule
#define CATPLMFstRelServices AuthorizedModule
#define CATPLMGRDProviderImpl AuthorizedModule
#define CATPLMIdentification_PLM AuthorizedModule
#define CATPLMImpactGraph AuthorizedModule
#define CATPLMImplAdapterBase AuthorizedModule
#define CATPLMImplAdapterClass AuthorizedModule
#define CATPLMImplAdapterQLBase AuthorizedModule
#define CATPLMImplRecordReadSetVPMV4 AuthorizedModule
#define CATPLMIndexCrawlerV6 AuthorizedModule
#define CATPLMIntegration AuthorizedModule
#define CATPLMIntegrationBase AuthorizedModule
#define CATPLMIntegrationAccess AuthorizedModule
#define CATPLMIntegrationAccessBase AuthorizedModule
#define CATPLMItgQuery AuthorizedModule
#define CATPLMItgTestIntegrationAccess AuthorizedModule
#define CATPLMItgTests AuthorizedModule
#define CATPLMLPr AuthorizedModule
#define CATPLMFXn AuthorizedModule
#define CATPLMMLCSExchange AuthorizedModule
#define CATPLMMessages AuthorizedModule
#define CATPLMMigrateTSTData AuthorizedModule
#define CATPLMModelBuilder AuthorizedModule
#define CATPLMOpenUI AuthorizedModule
#define CATPLMPXnProviderImpl AuthorizedModule
#define CATPLMPsp AuthorizedModule
#define CATPLMQLServices AuthorizedModule
#define CATPLMQL_Visitor AuthorizedModule
#define CATPLMREDataAccessor AuthorizedModule
#define CATPLMREOperationManager AuthorizedModule
#define CATPLMReplicationEngineCommon AuthorizedModule
#define CATPLMREPlug AuthorizedModule
#define CATPLMSSpMS_TestCEStamp AuthorizedModule
#define CATPLMSaveReturnMsg AuthorizedModule
#define CATPLMServicesItf AuthorizedModule
#define CATPLMServicesLimitedAccess AuthorizedModule
#define CATPLMServicesUUID AuthorizedModule
#define CATPLMSmarTeam1ProviderImpl AuthorizedModule
#define CATPLMStatutRemote AuthorizedModule
#define CATPLMSynchronization AuthorizedModule
#define CATPLMTestCommands AuthorizedModule
#define CATPLMTestProviderPerformance AuthorizedModule
#define CATPLMVP5ProviderImpl AuthorizedModule
#define CATPLMiPMLBase AuthorizedModule
#define CATPLMiPMLDataStream AuthorizedModule
#define CATPLMxQueryDataSet AuthorizedModule
#define CATPLMxQueryMsg AuthorizedModule
#define CATPLMxQueryPLMQL AuthorizedModule
#define CATPLMxQueryXMQL AuthorizedModule
#define CATPLMxQueryWriteXMQL AuthorizedModule // 16x
#define CATPLMxReadWriteXMQL AuthorizedModule  // 17x
#define CATVPMNavPLMAccessBase AuthorizedModule
#define CoexistenceAdminFinalization AuthorizedModule
#define CoexistenceRepairSDBatch AuthorizedModule
#define DELMHubProvider AuthorizedModule
#define ERS0ReplicationUtils AuthorizedModule
#define PLMMngtLock AuthorizedModule
#define PLMQLEditorUI AuthorizedModule
#define RecordManagement AuthorizedModule
#define CATPLMiPMLSend AuthorizedModule
#define TSTCATPLMAdapters AuthorizedModule
#define TSTCATPLMDbgCreateStructureInfra AuthorizedModule
#define TSTCATPLMDbgExpandModePush AuthorizedModule
#define TSTCATPLMDbgExpandOptNavOnSelectTypes AuthorizedModule
#define TSTCATPLMDbgLinkOnAttrAndSRv3 AuthorizedModule
#define TSTCATPLMDbgLinkSRv3 AuthorizedModule
#define TSTCATPLMDbgOpenConBrokenLink AuthorizedModule
#define TSTCATPLMENOVIACheckEdit AuthorizedModule
#define TSTCATPLMENOVIAClone AuthorizedModule
#define TSTCATPLMENOVIADeleteRef AuthorizedModule
#define TSTCATPLMENOVIAMaturity AuthorizedModule
#define TSTCATPLMENOVIANewVersion AuthorizedModule
#define TSTCATPLMTypeServices AuthorizedModule
#define TSTCATPLMVariant AuthorizedModule
#define TSTCATPLMAppIdOpen AuthorizedModule
#define TSTCATPLMxAttributeLink AuthorizedModule
#define TSTCATPLMxBlobOpen AuthorizedModule
#define TSTCATPLMxCBPExtension AuthorizedModule
#define TSTCATPLMxDeleteRef AuthorizedModule
#define TSTCATPLMxLinkOnAttrAndSRv3 AuthorizedModule
#define TSTCATPLMxLinkSRv3 AuthorizedModule
#define TSTCATPLMxLogCCM AuthorizedModule  // 16x
#define TSTCATPLMxFTLogCCM AuthorizedModule  // 17x
#define TSTCATPLMxOpen AuthorizedModule
#define TSTCATPLMxQueryAllAttr AuthorizedModule
#define TSTCATPLMxQueryExpand AuthorizedModule
#define TSTCATPLMxQuerySemanticRelation AuthorizedModule
#define TSTCATPLMxQueryStreamDescriptor_1 AuthorizedModule
#define TSTCATPLMxQueryStreamDescriptor_2 AuthorizedModule
#define TSTCATPLMxSaveAction AuthorizedModule
#define TSTCATPLMxSaveCBP AuthorizedModule
#define TestRepModifyer AuthorizedModule
#define TransitionEngine AuthorizedModule
#define VPLMIndexGeometryOnlyToolbox AuthorizedModule
#define VPLMIndexerDerivedObjToolbox AuthorizedModule
#define CATImmVPMRefreshExpand AuthorizedModule
#define TSTCATPLMDbgSaveBasicAttrMapping AuthorizedModule
#define TSTCATPLMDbgUpdateBasicAttrMapping2 AuthorizedModule
#define CATPLMDebugProviderImpl AuthorizedModule
#define ProviderPerformanceImpl AuthorizedModule
#define TSTCATPLMDbgMinVersion AuthorizedModule
#define TSTCATPLMxMinVersion AuthorizedModule
#define TSTCATPLMDbgV_DerivedFrom AuthorizedModule
#define TSTCATPLMDbgCloning AuthorizedModule
#define TSTCATPLMxCloning AuthorizedModule
#define CATAsyncTasksPlatform AuthorizedModule
#define CATPLMImplAdapterAsync AuthorizedModule
#define CATPLMImplAdapterItf AuthorizedModule
#define AdpTests AuthorizedModule
#define TSTCATPLMDbgBasicRemoveInstAndAttrMapping AuthorizedModule
#define TSTCATPLMDbgExpandModePushWithOverload AuthorizedModule
#define TSTCATPLMDbgExpandWithOverload AuthorizedModule
#define TSTCATPLMxExpandModePushWithOverload AuthorizedModule
#define TSTCATPLMxExpandWithOverload AuthorizedModule
#define TSTCATPLMNavigate AuthorizedModule
#define CATPLMToolkit AuthorizedModule
#define CATPLMReplicationEngineCommon AuthorizedModule
#define CATFbdMappingTable AuthorizedModule
#define TSTCATPLMxTransferOwnership2 AuthorizedModule
#define TSTCATPLMDbgMixMinMajVersion3 AuthorizedModule
#define TSTCATPLMxExpandModePushWithSR AuthorizedModule
#define TSTCATPLMxCloningPLMxT AuthorizedModule
#define TSTCheckEdit AuthorizedModule
#define TSTCATPLMxExpandSR AuthorizedModule
#define TSTCATPLMxExpandSRBenchmark AuthorizedModule
#define TSTCATPLMxNavSR AuthorizedModule
#define TSTCATPLMxWMQueryPLMIDFromPhysicalId AuthorizedModule
#define CATPLMComponentChecker AuthorizedModule
#define TSTCATPLMAppIdDeleteRef AuthorizedModule
#define CATKPIBVA AuthorizedModule
#define TSTCATPLMAppIdStrongRelations AuthorizedModule
#define TSTCATPLMxCATPLMQL AuthorizedModule
#define TSTCATPLMDbgCATPLMQL AuthorizedModule
#define TSTCATPLMxVersioningCBP AuthorizedModule
#define TSTCATPLMxImportIRPC AuthorizedModule
#define TSTCATPLMWMTimeout AuthorizedModule
#define TSTCATPLMxCSCI AuthorizedModule
#define TSTCATPLMxExpandPerfo AuthorizedModule
#define TSTCATPLMNavComplexAndMultiRoots AuthorizedModule
#define CATTCLRecordBuilderMainThread AuthorizedModule
#define CATPrdPGPPMRMigration AuthorizedModule
#define TSTCATPLMxSaveIRPC AuthorizedModule
#define TSTCATPLMxSaveER AuthorizedModule
#define CATPostConversion AuthorizedModule
#define TSTCATPLMBasicQueryWithDate AuthorizedModule
#define TSTCATPLMxImportER AuthorizedModule
#define TSTCATPLMxNavModePush AuthorizedModule
#define TSTCATPLMxNav2 AuthorizedModule
#define TstTestEngineUtilities AuthorizedModule
#define TSTCATPLMDbgBasicQueryWithDate AuthorizedModule
#define TSTCATPLMDbgImportIRPC         AuthorizedModule
#define TSTCATPLMBasicQueryEnumBinDat  AuthorizedModule
#define TSTCATPLMxImportSaveIRPCError  AuthorizedModule
#define TSTCATPLMDbgImportSaveIRPCError  AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

#error Forbidden Access To CATPLMServicesLimitedAccess Services from a non-authorized module
  // Fatal error on solaris
  @error
#endif

#undef AuthorizedModule

#undef PLMLibraryModelImpl 
#undef CATDbdImportModeler
#undef CATPLMItgRemoteStatusTests 
#undef CATOxiStatutRemote
#undef CATOxiStatutRemoteAttrLink
#undef CATPLMAdapterOdtBase
#undef CATPCTExpand
#undef CATPLMCertifLibrary
#undef CATPLMChangeStatus
#undef CATPLMCompletion
#undef CATPLMCompletionAccess
#undef CATPLMDWSAccess
#undef CATPLMDebugEngineImpl
#undef CATPLMDebugProviderImpl
#undef CATPLMDebugServices
#undef CATPLMDwhImpl
#undef CATPLMEV5ProviderImpl
#undef CATPLMEV5ProviderR15Impl
#undef CATPLMEmptyProviderImpl
#undef CATPLMFstRelServices
#undef CATPLMGRDProviderImpl
#undef CATPLMIdentification_PLM
#undef CATPLMImpactGraph
#undef CATPLMImplAdapterBase
#undef CATPLMImplAdapterClass
#undef CATPLMImplAdapterQLBase
#undef CATPLMImplRecordReadSetVPMV4
#undef CATPLMIndexCrawlerV6
#undef CATPLMIntegration
#undef CATPLMIntegrationBase
#undef CATPLMIntegrationAccess
#undef CATPLMIntegrationAccessBase
#undef CATPLMItgQuery
#undef CATPLMItgTestIntegrationAccess
#undef CATPLMItgTests
#undef CATPLMLPr
#undef CATPLMFXn
#undef CATPLMMLCSExchange
#undef CATPLMMessages
#undef CATPLMMigrateTSTData
#undef CATPLMModelBuilder
#undef CATPLMOpenUI 
#undef CATPLMPXnProviderImpl
#undef CATPLMPsp
#undef CATPLMQLServices
#undef CATPLMQL_Visitor
#undef CATPLMREDataAccessor
#undef CATPLMREOperationManager
#undef CATPLMReplicationEngineCommon
#undef CATPLMREPlug
#undef CATPLMSSpMS_TestCEStamp
#undef CATPLMSaveReturnMsg
#undef CATPLMServicesItf
#undef CATPLMServicesLimitedAccess
#undef CATPLMServicesUUID
#undef CATPLMSmarTeam1ProviderImpl
#undef CATPLMStatutRemote
#undef CATPLMSynchronization
#undef CATPLMTestCommands
#undef CATPLMTestProviderPerformance
#undef CATPLMVP5ProviderImpl
#undef CATPLMiPMLBase
#undef CATPLMiPMLDataStream
#undef CATPLMxQueryDataSet
#undef CATPLMxQueryMsg
#undef CATPLMxQueryPLMQL
#undef CATPLMxQueryXMQL
#undef CATPLMxQueryWriteXMQL // 16x
#undef CATPLMxReadWriteXMQL  // 17x
#undef CATVPMNavPLMAccessBase
#undef CoexistenceAdminFinalization
#undef CoexistenceRepairSDBatch
#undef DELMHubProvider
#undef ERS0ReplicationUtils
#undef PLMMngtLock
#undef PLMQLEditorUI
#undef RecordManagement
#undef CATPLMiPMLSend
#undef TSTCATPLMAdapters
#undef TSTCATPLMDbgCreateStructureInfra
#undef TSTCATPLMDbgExpandModePush
#undef TSTCATPLMDbgExpandOptNavOnSelectTypes
#undef TSTCATPLMDbgLinkOnAttrAndSRv3
#undef TSTCATPLMDbgLinkSRv3
#undef TSTCATPLMDbgOpenConBrokenLink
#undef TSTCATPLMENOVIACheckEdit
#undef TSTCATPLMENOVIAClone
#undef TSTCATPLMENOVIADeleteRef
#undef TSTCATPLMENOVIAMaturity
#undef TSTCATPLMENOVIANewVersion
#undef TSTCATPLMTypeServices
#undef TSTCATPLMVariant
#undef TSTCATPLMAppIdOpen
#undef TSTCATPLMxAttributeLink
#undef TSTCATPLMxBlobOpen
#undef TSTCATPLMxCBPExtension
#undef TSTCATPLMxDeleteRef
#undef TSTCATPLMxLinkOnAttrAndSRv3
#undef TSTCATPLMxLinkSRv3
#undef TSTCATPLMxLogCCM  // 16x
#undef TSTCATPLMxFTLogCCM  //17x
#undef TSTCATPLMxOpen
#undef TSTCATPLMxQueryAllAttr
#undef TSTCATPLMxQueryExpand
#undef TSTCATPLMxQuerySemanticRelation
#undef TSTCATPLMxQueryStreamDescriptor_1
#undef TSTCATPLMxQueryStreamDescriptor_2
#undef TSTCATPLMxSaveAction
#undef TSTCATPLMxSaveCBP
#undef TestRepModifyer
#undef TransitionEngine
#undef VPLMIndexGeometryOnlyToolbox
#undef VPLMIndexerDerivedObjToolbox
#undef CATImmVPMRefreshExpand
#undef TSTCATPLMDbgSaveBasicAttrMapping
#undef TSTCATPLMDbgUpdateBasicAttrMapping2
#undef CATPLMDebugProviderImpl
#undef ProviderPerformanceImpl
#undef TSTCATPLMDbgMinVersion
#undef TSTCATPLMxMinVersion
#undef TSTCATPLMDbgV_DerivedFrom
#undef TSTCATPLMDbgCloning
#undef TSTCATPLMxCloning
#undef CATAsyncTasksPlatform
#undef CATPLMImplAdapterAsync
#undef CATPLMImplAdapterItf
#undef AdpTests
#undef TSTCATPLMDbgBasicRemoveInstAndAttrMapping
#undef TSTCATPLMDbgExpandModePushWithOverload
#undef TSTCATPLMDbgExpandWithOverload
#undef TSTCATPLMxExpandModePushWithOverload
#undef TSTCATPLMxExpandWithOverload
#undef TSTCATPLMNavigate
#undef CATPLMToolkit 
#undef CATFbdMappingTable 
#undef CATPLMReplicationEngineCommon
#undef CATFbdMappingTable
#undef TSTCATPLMxTransferOwnership2
#undef TSTCATPLMDbgMixMinMajVersion3
#undef TSTCATPLMxExpandModePushWithSR
#undef TSTCATPLMxCloningPLMxT
#undef TSTCheckEdit
#undef TSTCATPLMxExpandSR
#undef TSTCATPLMxExpandSRBenchmark
#undef TSTCATPLMxNavSR
#undef TSTCATPLMxWMQueryPLMIDFromPhysicalId
#undef CATPLMComponentChecker
#undef TSTCATPLMAppIdDeleteRef
#undef CATKPIBVA
#undef TSTCATPLMAppIdStrongRelations
#undef TSTCATPLMxCATPLMQL
#undef TSTCATPLMDbgCATPLMQL
#undef TSTCATPLMxVersioningCBP
#undef TSTCATPLMxImportIRPC
#undef TSTCATPLMWMTimeout
#undef TSTCATPLMxCSCI
#undef TSTCATPLMxExpandPerfo
#undef TSTCATPLMNavComplexAndMultiRoots
#undef CATTCLRecordBuilderMainThread
#undef CATPrdPGPPMRMigration
#undef TSTCATPLMxSaveIRPC
#undef TSTCATPLMxSaveER
#undef CATPostConversion
#undef TSTCATPLMBasicQueryWithDate
#undef TSTCATPLMxImportER
#undef TSTCATPLMxNavModePush
#undef TSTCATPLMxNav2
#undef TstTestEngineUtilities
#undef TSTCATPLMDbgBasicQueryWithDate
#undef TSTCATPLMDbgImportIRPC
#undef TSTCATPLMBasicQueryEnumBinDat
#undef TSTCATPLMxImportSaveIRPCError
#undef TSTCATPLMDbgImportSaveIRPCError

#if defined(__CATPLMServicesItf)
#define ExportedByCATPLMServicesLimitedAccess DSYExport
#else
#define ExportedByCATPLMServicesLimitedAccess DSYImport
#endif
#include "DSYExport.h"