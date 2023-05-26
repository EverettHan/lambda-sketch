// COPYRIGHT DASSAULT SYSTEMES 2010
/** @required */ 

#undef ExportedByCATPLMIntegrationInterfaces

#if defined (private) || defined(friend) || defined (protected)
	#error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 
#endif

// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMIntegrationInterfaces       AuthorizedModule
#define CATPLMIntegrationAccess           AuthorizedModule
#define CATPLMItgTestIntegrationAccess    AuthorizedModule
#define CATPLMIntegration                 AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
	    #error Forbidden access to Workspace/Reference apis from non-infrastructure module
        @error 
#endif
#undef CATPLMIntegrationInterfaces
#undef CATPLMIntegrationAccess
#undef CATPLMItgTestIntegrationAccess
#undef CATPLMIntegration
// ----------------------------------------------------------------------------------------------------------------------

#undef AuthorizedModule           

#if defined (__CATPLMIntegrationInterfaces)
#define ExportedByCATPLMIntegrationInterfaces DSYExport
#else
#define ExportedByCATPLMIntegrationInterfaces DSYImport
#endif
#include "DSYExport.h"
