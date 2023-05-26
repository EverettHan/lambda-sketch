#undef ExportedByCATPLMCertifLibrary 

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

#define CATPLMCertifLibrary             AuthorizedModule
#define CATPLMTestProviderPerformance   AuthorizedModule
#define CATPLMCertifProvider            AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else
  #error Forbidden Access To CATPLMCertifLibrary Services from a non-authorized module
  // Fatal error on solaris
  @error 
#endif

#undef CATPLMCertifLibrary
#undef CATPLMTestProviderPerformance
#undef CATPLMCertifProvider

#if defined(__CATPLMCertifLibrary)
#define ExportedByCATPLMCertifLibrary DSYExport
#else
#define ExportedByCATPLMCertifLibrary DSYImport
#endif
#include "DSYExport.h"
