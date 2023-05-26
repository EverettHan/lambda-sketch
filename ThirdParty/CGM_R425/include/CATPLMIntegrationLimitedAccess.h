#undef ExportedByCATPLMIntegrationLimitedAccess 

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

#define CATPLMClientCoreServices                AuthorizedModule
#define CATPLMIntegrationAccess                 AuthorizedModule
#define CATPLMCAAIntegAccess                    AuthorizedModule
#define AS0STARTUP                              AuthorizedModule // Bilan a faire pour virer PLMServices de ProductStructure
#define CATPLMPrdProperties                     AuthorizedModule // Bilan a faire pour virer PLMServices de ProductStructure
#define PLMPSIUserExit                          AuthorizedModule // Bilan a faire 
#define CATPLMIntegrationLimitedAccess          AuthorizedModule
#define TSTCATAdpProtectedVersiongErrorCase     AuthorizedModule // For GetAdpIdentificatorFromPLMID
#define CATPLMItgTestIntegrationAccess          AuthorizedModule // for GetPLMIDFromCATBaseUnknown
#define CATPLMDocEnvBatchTest                   AuthorizedModule // For GetPLMIDFromAdpIdentificator
#define CATImmVPMCommand                        AuthorizedModule 
#define CATPLMReplication_Common                AuthorizedModule // ODTs replication for GetPLMIDFromAdpIdentificator
#define CATImmVPMMetaDataFrame                  AuthorizedModule // CATPLMUIImpl pour utilisation de GetPLMTypeFromAdpType
#define CATPLMPrdSessionServices                AuthorizedModule // CATPLMPrdIntegration pour GetAdpTypeFromPLMType
#define TSTCATAdpLockServices                   AuthorizedModule // For PrivateToolbox
#define CATPLMInAccItf                          AuthorizedModule // ODTs replication for CATAdpLimitedAccessToolbox_GetAdpIdentificatorFromPLMID
#define CATPLMDocument                          AuthorizedModule 
#define CATPLMRepresentation                    AuthorizedModule
#define CATPLMTestCommands                      AuthorizedModule //To mix AdpServices and lower level services in debug open command
#define CATPLMSpecServices                      AuthorizedModule // CATPLMSpecification - Sauvegarde de query
#define PLMDisplayServices                      AuthorizedModule // PLMNavigationServices 
#define PLMAliasAdapter                         AuthorizedModule // PLMNavigationServices 
#define PLM3DSearchUtilities                    AuthorizedModule 
#define CATOmbMigrationAccess                   AuthorizedModule // FDBI Engine 16/02/2006
#define CAT3DPhysicalRepModel                   AuthorizedModule
#define CATPrdModelInit                         AuthorizedModule
#define CATPrdModelProperties                   AuthorizedModule
#define CATPrdModelStructEdition                AuthorizedModule
#define CATDxpImporterExporter	                AuthorizedModule
#define CATVPMNavPLMAccessBase	                AuthorizedModule
#define TSTCATAdpProtectedCloningServices       AuthorizedModule // For GetAdpIdentificatorFromPLMID
#define PLMBatchProviderVPLMImpl                AuthorizedModule //Due to move from DocTypLCAImpl to PLMBatchProviderVPLMImpl.
#define PLMBatchVPLMServices                    AuthorizedModule //Due to move from DocTypLCAImpl to PLMBatchVPLMServices.
#define CATPCDCmd                               AuthorizedModule // For PLMSample2 (debug)
#define CATPrdPccModelInit                      AuthorizedModule // Rearchitecture PS (CATAdpLimitedAccessToolbox::GetPLMTypeFromAdpType)
#define CATPLMIntegrationUse                    AuthorizedModule // Service CAA Open et Save
#define CATPLMIdentification_PLM                AuthorizedModule
#define CATPLMIntegration                       AuthorizedModule
#define CATPLMItgXOpener                        AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

	    #error Forbidden Access To CATPLMIntegrationLimitedAccess Services from a non-authorized module
        // Fatal error on solaris
        @error 
#endif


#undef CATPLMClientCoreServices              
#undef CATPLMIntegrationAccess      
#undef CATPLMCAAIntegAccess
#undef AS0STARTUP								    
#undef CATPLMPrdProperties					    
#undef PLMPSIUserExit							    
#undef CATPLMIntegrationLimitedAccess        
#undef TSTCATAdpProtectedVersiongErrorCase   
#undef CATPLMDocEnvBatchTest                 
#undef CATImmVPMCommand                      
#undef CATPLMReplication_Common              
#undef CATImmVPMMetaDataFrame                
#undef CATPLMPrdSessionServices              
#undef TSTCATAdpLockServices                 
#undef CATPLMInAccItf                        
#undef CATPLMDocument                        
#undef CATPLMRepresentation                  
#undef CATPLMTestCommands                    
#undef CATPLMSpecServices                    
#undef PLMDisplayServices                    
#undef PLMAliasAdapter                       
#undef PLM3DSearchUtilities                  
#undef CATOmbMigrationAccess                 
#undef CAT3DPhysicalRepModel                 
#undef CATPrdModelInit                       
#undef CATPrdModelProperties                 
#undef CATPrdModelStructEdition              
#undef CATDxpImporterExporter
#undef CATVPMNavPLMAccessBase
#undef TSTCATAdpProtectedCloningServices
#undef PLMBatchProviderVPLMImpl
#undef PLMBatchVPLMServices
#undef CATPCDCmd
#undef CATPrdPccModelInit
#undef CATPLMItgTestIntegrationAccess
#undef CATPLMIntegrationUse
#undef CATPLMIdentification_PLM
#undef CATPLMIntegration
#undef CATPLMItgXOpener   

#if defined(__CATPLMIntegrationAccess)
#define ExportedByCATPLMIntegrationLimitedAccess DSYExport
#else
#define ExportedByCATPLMIntegrationLimitedAccess DSYImport
#endif
#include "DSYExport.h"


