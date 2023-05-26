#undef ExportedByCATPLMFilterCfgLimitedAccess 

  //----------------------------------------------------
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
#define CATPLMItgTests                                 AuthorizedModule
#define CATPLMFilterCfgLimitedAccess                   AuthorizedModule
#define CATPLMServicesItf                              AuthorizedModule
#define CATPLMServicesUUID                             AuthorizedModule
#define CATPLMImplAdapterBase                          AuthorizedModule
#define CATPLMImplAdapterQLBase                        AuthorizedModule  // for exalead expand
#define CATPLMImplAdapterDOM                           AuthorizedModule
#define CATPLMxQueryPLMQL                              AuthorizedModule
#define CATCfgModel                                    AuthorizedModule // Config Model impl
#define CATCfgODT_VolatileFilter                       AuthorizedModule // Config Model ODT
#define CATPLMConfigAccess                             AuthorizedModule // ConfigAccess impl
#define CATCfgXMLExprParser                            AuthorizedModule // ConfigAccess impl
#define CATCfgAccessToolbox                            AuthorizedModule // ConfigAccess impl
#define CATCfgODT_GetConfigQueriesForReference         AuthorizedModule // ConfigAccess ODT
#define CATCfgODT_BuildConfigFilter                    AuthorizedModule // ConfigAccess ODT
#define CATCfgODT_BuildActivateFilter                  AuthorizedModule // ConfigAccess ODT
#define CATCfgODT_ReadXMLFilter                        AuthorizedModule // ConfigAccess ODT
#define CATCfgODT_ReadXMLFilter_2                      AuthorizedModule // ConfigAccess ODT
#define CATCfgODTUnitTest                              AuthorizedModule // ConfigAccess UT ODT
#define CATPLMDebugEngineImpl                          AuthorizedModule
#define CATPLMIndexItfImpl                             AuthorizedModule // For 3D Index
#define CATPLMImplProviderVPMV4                        AuthorizedModule // For VPMV4
#define CATPLMNav3DAltCfgFilter                        AuthorizedModule
#define CATPLMVP5ProviderImpl                          AuthorizedModule
#define CATPLMSpecServices                             AuthorizedModule
#define CATPLMSpecificationModel                       AuthorizedModule
#define CATImmNav3DCfgFilter                           AuthorizedModule
#define DELIPDProvider                                 AuthorizedModule // For IPD
#define DELIPDProviderDescTest                         AuthorizedModule // For IPD
#define DELIPDProviderTest                             AuthorizedModule // For IPD
#define CATCfgNavServices                              AuthorizedModule // For CFG
#define CATCfgXMLParser                                AuthorizedModule // For CFG this new modue replaces module CATCfgXMLExprParser
#define CATCfgXMLFilterParser                          AuthorizedModule // For CFG this new modue replaces module CATCfgXMLExprParser
#define CATCfgModelerServices                          AuthorizedModule
#define CATCfgFilter                                   AuthorizedModule
#define CATCfgInfraPrivateItf                          AuthorizedModule
#define CATCfgSessionFilters                           AuthorizedModule 
#define CATCfgSessionServices                          AuthorizedModule
#define CATCfgIntegration                              AuthorizedModule
#define TSTCATPLMDbgConfigAndFilterOnAttr              AuthorizedModule
#define IdxConfigCrawler                               AuthorizedModule // For IDX
#define CATPLMCompletionTests                          AuthorizedModule // For PJQ Tests
#define CATPLMxReadWriteXMQL                           AuthorizedModule // For xMQL coding
#define CATPCTExpand                                   AuthorizedModule // For xMQL test
#define CATPLMModelBuilderTests                        AuthorizedModule // For UWP test
#define CATCfgFavoritePVSMigrationBatch                AuthorizedModule // For 2013x only
#define CATPLMIntegrationAccess                        AuthorizedModule
#define CATCfgODT_CATIPLMFilterConfigProdConf          AuthorizedModule // For ubo tests
#define EBOMPSCollaborationModel                       AuthorizedModule
#define TSTCATPLMNavigate                              AuthorizedModule
#define CATImmPPRNavigatorServices                     AuthorizedModule
#define DELPPRWipmidCmd                                AuthorizedModule
#define CATCfgODT_CreateConfiguration                  AuthorizedModule
#define CATKPIWebinWinInfrastructure                   AuthorizedModule // ALO
#define CATKPIBVA                                      AuthorizedModule // ALO
#define CATWSPServices                                 AuthorizedModule // For TSK2214022 (YCN/BES)
#define CATFstVPMNavUserDefinedOpenUI                  AuthorizedModule
#define TSTCATPLMNavComplexAndMultiRoots               AuthorizedModule
#define CATCfgODT_CreateVolatileFilter_XMLDictionary   AuthorizedModule // Config Model ODT
#define CATImmVPMCfgFilter                             AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

        #error Forbidden Access To CATPLMCfgFilterLimitedAccess Services from a non-authorized module
        // Fatal error on solaris
        @error 
#endif
	
#undef CATPLMItgTests
#undef CATPLMFilterCfgLimitedAccess
#undef CATPLMServicesItf
#undef CATPLMServicesUUID
#undef CATPLMImplAdapterDOM
#undef CATPLMImplAdapterBase
#undef CATPLMImplAdapterQLBase
#undef CATPLMxQueryPLMQL
#undef CATCfgModel
#undef CATCfgODT_VolatileFilter
#undef CATPLMConfigAccess
#undef CATCfgAccessToolbox
#undef CATCfgODT_GetConfigQueriesForReference
#undef CATCfgODT_BuildConfigFilter
#undef CATCfgODT_BuildActivateFilter
#undef CATCfgODT_ReadXMLFilter
#undef CATCfgODT_ReadXMLFilter_2
#undef CATCfgODTUnitTest
#undef CATCfgXMLExprParser
#undef CATPLMDebugEngineImpl
#undef CATPLMIndexItfImpl
#undef CATPLMImplProviderVPMV4
#undef CATPLMNav3DAltCfgFilter
#undef CATPLMVP5ProviderImpl
#undef CATPLMSpecServices
#undef CATPLMSpecificationModel
#undef CATImmNav3DCfgFilter
#undef DELIPDProvider
#undef DELIPDProviderDescTest
#undef DELIPDProviderTest
#undef CATCfgNavServices
#undef CATCfgXMLParser
#undef CATCfgXMLFilterParser
#undef CATCfgModelerServices
#undef CATCfgFilter
#undef CATCfgInfraPrivateItf
#undef CATCfgSessionFilters
#undef CATCfgSessionServices
#undef CATCfgIntegration
#undef TSTCATPLMDbgConfigAndFilterOnAttr
#undef IdxConfigCrawler
#undef CATPLMCompletionTests
#undef CATPLMxReadWriteXMQL
#undef CATPCTExpand
#undef CATPLMModelBuilderTests
#undef CATCfgFavoritePVSMigrationBatch
#undef CATPLMIntegrationAccess
#undef CATCfgODT_CATIPLMFilterConfigProdConf
#undef EBOMPSCollaborationModel
#undef TSTCATPLMNavigate
#undef CATImmPPRNavigatorServices
#undef DELPPRWipmidCmd
#undef CATCfgODT_CreateConfiguration
#undef CATKPIWebinWinInfrastructure
#undef CATKPIBVA
#undef CATWSPServices
#undef CATFstVPMNavUserDefinedOpenUI
#undef TSTCATPLMNavComplexAndMultiRoots
#undef CATCfgODT_CreateVolatileFilter_XMLDictionary
#undef CATImmVPMCfgFilter

#if defined(__CATPLMServicesItf)
#define ExportedByCATPLMFilterCfgLimitedAccess DSYExport
#else
#define ExportedByCATPLMFilterCfgLimitedAccess DSYImport
#endif
#include "DSYExport.h"

