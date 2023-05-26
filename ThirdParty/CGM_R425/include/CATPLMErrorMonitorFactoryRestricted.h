/**
* @level Private
* @usage U3
*/
// COPYRIGHT DASSAULT SYSTEMES 2008

// ExportedByCATPLMIntegrationInterfaces module header

#undef ExportedByCATPLMIntegrationInterfaces

  //-----------------------------------------------------
  //  Check that only infrastructure modules can link on the exported symbols
  //----------------------------------------------------

// List of forbidden re-define

#if defined (private) || defined(friend) || defined (protected)

	#error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 

#endif


#define AuthorizedModuleForErrorMonitorFactory 666

// Check no one makes a declaration to by-pass our control. 
#if _MK_MODNAME_ == AuthorizedModuleForErrorMonitorFactory
  #pragma message("[Warning] Module declared as authorized by another header.")
#endif  


// List of authorized infrastructure modules 

#define CATPLMIntegrationInterfaces  AuthorizedModuleForErrorMonitorFactory
#define CATPLMIntegrationAccess		 AuthorizedModuleForErrorMonitorFactory
#define CATPLMIntegration		 AuthorizedModuleForErrorMonitorFactory

#if _MK_MODNAME_ == AuthorizedModuleForErrorMonitorFactory

#else

	    #error Forbidden Access To CATIPLMErrorMonitorFactory from a non-infrastructure module
        // Fatal error on solaris
        @error 

#endif

#undef CATPLMIntegrationInterfaces
#undef CATPLMIntegrationAccess
#undef CATPLMIntegration


// Check we did not forget to remove all definition
#if _MK_MODNAME_ == AuthorizedModuleForErrorMonitorFactory
  #pragma message("[Warning] Module declared has not been undeclared correctly.")
#endif  

// ExportedByCATPLMIntegrationAccess def

#if defined __CATPLMIntegrationInterfaces
#define ExportedByCATPLMIntegrationInterfaces DSYExport
#else
#define ExportedByCATPLMIntegrationInterfaces DSYImport
#endif
#include "DSYExport.h"
