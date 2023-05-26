#undef ExportedByCATPLMIntegrationAccessRestrictedCollabUse 
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

#define CATPLMIntegrationAccess               AuthorizedModule
#define CATPLMItgTestIntegrationAccess        AuthorizedModule
#define CATDMUCollaborative                   AuthorizedModule
#define CATCollabEngine                       AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

	    #error Forbidden Access To CATPLMIntegrationAccessRestrictedCollabUse Services from a non-authorized module
        // Fatal error on solaris
        @error 
#endif


#undef CATPLMIntegrationAccess            
#undef CATPLMItgTestIntegrationAccess            
#undef CATDMUCollaborative            
#undef CATCollabEngine

#if defined(__CATPLMIntegrationAccess)
#define ExportedByCATPLMIntegrationAccessRestrictedCollabUse DSYExport
#else
#define ExportedByCATPLMIntegrationAccessRestrictedCollabUse DSYImport
#endif
#include "DSYExport.h"


