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
#define CATPLMItgTests                    AuthorizedModule
#define CATPLMIntegration                 AuthorizedModule
#define CATPLMWorkspaceImpl               AuthorizedModule
#define CATPLMWorkspaceImplCompEngine     AuthorizedModule
#define CATPLMWorkspaceImplOpEngine       AuthorizedModule
#define CATPCTEditabilityTests            AuthorizedModule
#define CATPLMItgTestBase                 AuthorizedModule
#define CATPLMModelBuilderTests           AuthorizedModule
#define CATPLMItgTestIntegrationAccess    AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
	    #error Forbidden access to Workspace/Reference apis from non-infrastructure module
        @error 
#endif
#undef CATPLMIntegrationInterfaces
#undef CATPLMIntegrationAccess
#undef CATPLMItgTests
#undef CATPLMIntegration
#undef CATPLMWorkspaceImpl
#undef CATPLMWorkspaceImplCompEngine
#undef CATPLMWorkspaceImplOpEngine
#undef CATPCTEditabilityTests
#undef CATPLMItgTestBase
#undef CATPLMModelBuilderTests
#undef CATPLMItgTestIntegrationAccess
// ----------------------------------------------------------------------------------------------------------------------

#undef AuthorizedModule           

#if defined (__CATPLMIntegrationInterfaces)
#define ExportedByCATPLMIntegrationInterfaces DSYExport
#else
#define ExportedByCATPLMIntegrationInterfaces DSYImport
#endif
#include "DSYExport.h"
