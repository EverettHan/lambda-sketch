/**
* @level Private
* @usage U3
*/
// COPYRIGHT DASSAULT SYSTEMES 2008

// ExportedByCATPLMIntegrationAccess module header

#undef ExportedByCATPLMIntegrationAccess

  //-----------------------------------------------------
  //  Check that only infrastructure modules can link on the exported symbols
  //----------------------------------------------------

// List of forbidden re-define

#if defined (private) || defined(friend) || defined (protected)

	#error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 

#endif


#define AuthorizedModuleForErrorInterpreterAccess 666

// Check no one makes a declaration to by-pass our control. 
#if _MK_MODNAME_ == AuthorizedModuleForErrorInterpreterAccess
  #pragma message("[Warning] Module declared as authorized by another header.")
#endif  


// List of authorized infrastructure modules 

#define CATPLMIntegrationAccess		AuthorizedModuleForErrorInterpreterAccess
#define TSTCATIAdpErrorImplement    AuthorizedModuleForErrorInterpreterAccess 

#if _MK_MODNAME_ == AuthorizedModuleForErrorInterpreterAccess

#else

	    #error Forbidden Access To CATIAdpErrorInterpreter from a non-infrastructure module
        // Fatal error on solaris
        @error 

#endif

#undef CATPLMIntegrationAccess
#undef TSTCATIAdpErrorImplement

// Check we did not forget to remove all definition
#if _MK_MODNAME_ == AuthorizedModuleForErrorInterpreterAccess
  #pragma message("[Warning] Module declared has not been undeclared correctly.")
#endif  

// ExportedByCATPLMIntegrationAccess def

#if defined __CATPLMIntegrationAccess
#define ExportedByCATPLMIntegrationAccess DSYExport
#else
#define ExportedByCATPLMIntegrationAccess DSYImport
#endif
#include "DSYExport.h"
