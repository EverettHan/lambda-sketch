#undef ExportedByCATPLMIntegrationAccessRestrictedDWSUse 
//-----------------------------------------------------
//  Check that only authorized modules can link on the exported symbols
//aa ----------------------------------------------------
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

#define CATPLMIntegrationAccess AuthorizedModule
#define CATPLMWorkspaceImpl AuthorizedModule
#define CATPLMWorkspaceImplOpEngine AuthorizedModule
#define CATPLMDmtDocCommands AuthorizedModule
#define CATPLMItgTestIntegrationAccess AuthorizedModule
#define CATPLMItgTests AuthorizedModule
#define PLMDesignWorkspaceFBDI AuthorizedModule
#define CATFbdModeler AuthorizedModule
#define CATFbdMappingTable AuthorizedModule
#define CATDWCompatibilityUI AuthorizedModule
#define CoexDesignWorkspace  AuthorizedModule // CATBack
#define SMAMDLUtils AuthorizedModule
#define CATPLMTemplates AuthorizedModule
#define CoexistenceAdmin AuthorizedModule // Mapping V6/V6
#define CATPLMSessionContentAccess AuthorizedModule
#define PLMBatchVPLMServices AuthorizedModule
#define CATImmCaptureCmd AuthorizedModule // 3DLive
#define CATFmtBatchServices AuthorizedModule // Model Assembly pour Simulation
#define CATPCTEditabilityTests AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

	    #error Forbidden Access To CATPLMIntegrationAccessRestrictedDWSUse Services from a non-authorized module
        // Fatal error on solaris
        @error 
#endif


#undef CATPLMIntegrationAccess            
#undef CATPLMWorkspaceImpl            
#undef CATPLMWorkspaceImplOpEngine            
#undef CATPLMDmtDocCommands            
#undef CATPLMItgTestIntegrationAccess            
#undef CATPLMItgTests
#undef PLMDesignWorkspaceFBDI  
#undef CATFbdModeler            
#undef CATFbdMappingTable 
#undef CATDWCompatibilityUI   
#undef CoexDesignWorkspace   
#undef SMAMDLUtils
#undef CATPLMTemplates
#undef CoexistenceAdmin   
#undef CATPLMSessionContentAccess
#undef PLMBatchVPLMServices
#undef CATImmCaptureCmd 
#undef CATFmtBatchServices 
#undef CATPCTEditabilityTests

#if defined(__CATPLMIntegrationAccess)
#define ExportedByCATPLMIntegrationAccessRestrictedDWSUse DSYExport
#else
#define ExportedByCATPLMIntegrationAccessRestrictedDWSUse DSYImport
#endif
#include "DSYExport.h"


