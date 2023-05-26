// COPYRIGHT DASSAULT SYSTEMES 2006

// ExportedByCATPLMIntegrationInterfaces module header

/** @required */ 

#undef ExportedByCATPLMIntegrationInterfaces

  //-----------------------------------------------------
  //  Check that only authorized modules can link on the exported symbols
  //----------------------------------------------------

// List of forbidden re-define

#if defined (private) || defined(friend) || defined (protected)

	#error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 

#endif


#define AuthorizedModule 999

// List of authorized infrastructure modules 

#define CATPLMIntegrationInterfaces							    AuthorizedModule
#define CATPLMIntegration                           AuthorizedModule
#define CATPLMIntegrationAccess                     AuthorizedModule   // IntegrationAccess exposure
#define CATPLMCAAIntegAccess                        AuthorizedModule   // IntegrationAccess exposure 
#define CATPLMChangeStatus                          AuthorizedModule   // VPMNav 
#define CATImmVPMOpenEngine                         AuthorizedModule   // VPMNav: fill engine
#define CATPLMClientCoreModel                       AuthorizedModule   // Client Core
#define CATPLMManageMaturity                        AuthorizedModule   // Maturity Engine
#define CATPLMItgTests                              AuthorizedModule   // Maturity Engine
#define CATPLMOpenAndManageMaturity                 AuthorizedModule   // odt in CATPLMIntegration
#define CATPLMExpandEngineBatch                     AuthorizedModule   // odt in CATPLMIntegration
#define DELPLMPFTest                                AuthorizedModule   // Maturity Engine pour odt Process.
#define PLMMaturityTestN1                           AuthorizedModule   // CAA Adp service in ProductStructure.tst. Should be removed when service is moves in CATPLMIntegrationAccess
#define PLMMaturityMngt                             AuthorizedModule   //Maturity engine pour VPMNav (TrashBox management)
#define CATPLMBriefcaseUtilities                    AuthorizedModule   //Maturity engine pour ImportBriefcase tant que les services adp ne sont pas multiroot

#if _MK_MODNAME_ == AuthorizedModule

#else

	    #error Access To CATPLMIntegrationInterfaces services from a non-authorized module is prohibited
        // Fatal error on solaris
        @error 

#endif

#undef CATPLMIntegrationInterfaces           
#undef CATPLMIntegration           
#undef CATPLMIntegrationAccess           
#undef CATPLMCAAIntegAccess           
#undef CATPLMChangeStatus           
#undef CATImmVPMOpenEngine           
#undef CATPLMManageMaturity  
#undef CATPLMItgTests         
#undef CATPLMClientCoreModel           
#undef CATPLMOpenAndManageMaturity           
#undef CATPLMExpandEngineBatch           
#undef DELPLMPFTest           
#undef PLMMaturityTestN1
#undef PLMMaturityMngt
#undef SWXPDMGeneral


#undef AuthorizedModule           

// ExportedByCATPLMIntegrationInterfaces def
#if defined __CATPLMIntegrationInterfaces
#define ExportedByCATPLMIntegrationInterfaces DSYExport
#else
#define ExportedByCATPLMIntegrationInterfaces DSYImport
#endif
#include "DSYExport.h"
