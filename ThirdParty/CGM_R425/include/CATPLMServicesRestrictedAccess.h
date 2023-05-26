#undef ExportedByCATPLMServicesRestrictedAccess 

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
#define CATPLMServicesItf                     AuthorizedModule
#define CATPLMImplAdapterBase                 AuthorizedModule
#define CATPLMImplAdapterClass                AuthorizedModule
#define TransitionEngine                      AuthorizedModule
#define CATDbdImportModeler                   AuthorizedModule
#define RecordManagement                      AuthorizedModule
#define VPMV4MappingToV6                      AuthorizedModule
#define CATDxp3DXMLIdentification             AuthorizedModule
#define DataExchangeProvider                  AuthorizedModule
#define CATPLMXmlSpecsConverter               AuthorizedModule
#define CATPLMDebugProviderImpl               AuthorizedModule
#define TSTCATPLMDebugRestrictedAccess	      AuthorizedModule
#define CATPLMSmarTeam1ProviderImpl	          AuthorizedModule
#define DELMHubProvider	                      AuthorizedModule
#define TSTCATVPMV4ProviderRestrictedAccess   AuthorizedModule
#define CATDCInfraMappingTbl                  AuthorizedModule
#define CATPLMVP5ProviderImpl                 AuthorizedModule
#define TestRestrictedAccessItf               AuthorizedModule
#define TransitionEngineBatch                 AuthorizedModule
#define CoexistenceBatchUI                    AuthorizedModule
#define CATPLMDebugV5ProviderDescImpl         AuthorizedModule
#define TSTCATPLMAdapters                     AuthorizedModule
#define TSTCATPLMxProviderRestrictedAccess    AuthorizedModule
#define XPdmProvider                          AuthorizedModule
#define CATDxpDataExchangeOutputer            AuthorizedModule
#define CoexistenceAdminFinalization          AuthorizedModule
#define SMTDEC_ODTServices                    AuthorizedModule
#define PLMBatchInfraServices                 AuthorizedModule
#define XPDMXMLProvider                       AuthorizedModule
#define CATDxp3DXMLRecordCreation             AuthorizedModule
#define CATDxp3DXMLRecordNavigation           AuthorizedModule
#define PLMCOEXMapping                        AuthorizedModule


#if _MK_MODNAME_ == AuthorizedModule

#else

      #error Forbidden Access To CATPLMServicesRestrictedAccess Services from a non-authorized module
        // Fatal error on solaris
        @error 
#endif

#undef AuthorizedModule

// List of authorized infrastructure modules 
#undef CATPLMServicesItf
#undef CATPLMImplAdapterBase
#undef CATPLMImplAdapterClass
#undef TransitionEngine
#undef CATDbdImportModeler
#undef RecordManagement
#undef VPMV4MappingToV6
#undef CATDxp3DXMLIdentification
#undef DataExchangeProvider
#undef CATPLMXmlSpecsConverter
#undef CATPLMDebugProviderImpl
#undef TSTCATPLMDebugRestrictedAccess
#undef CATPLMSmarTeam1ProviderImpl
#undef DELMHubProvider
#undef TSTCATVPMV4ProviderRestrictedAccess
#undef CATDCInfraMappingTbl
#undef CATPLMVP5ProviderImpl
#undef TestRestrictedAccessItf
#undef TransitionEngineBatch
#undef CoexistenceBatchUI
#undef CATPLMDebugV5ProviderDescImpl
#undef TSTCATPLMAdapters
#undef TSTCATPLMxProviderRestrictedAccess
#undef XPdmProvider
#undef CATDxpDataExchangeOutputer
#undef CoexistenceAdminFinalization
#undef SMTDEC_ODTServices
#undef PLMBatchInfraServices
#undef XPDMXMLProvider
#undef CATDxp3DXMLRecordCreation
#undef CATDxp3DXMLRecordNavigation
#undef PLMCOEXMapping


#if defined(__CATPLMServicesItf)
#define ExportedByCATPLMServicesRestrictedAccess DSYExport
#else
#define ExportedByCATPLMServicesRestrictedAccess DSYImport
#endif
#include "DSYExport.h"
