#undef ExportedByCATOMYBaseSessionRestrictedUseForIntegration 

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

#define CATOMYBaseSession AuthorizedModule
#define CATPLMIntegrationAccess AuthorizedModule
#define CATPLMIntegrationUse AuthorizedModule 
#define CATOMY AuthorizedModule 
#define CATPLMItgXOpener AuthorizedModule
#define CATSetupDataFinder AuthorizedModule
#define CATPLMTagDB AuthorizedModule
#define CATPLMItgTestIntegrationAccess AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

#error Forbidden Access To CATOMYBaseSessionRestrictedUseForIntegration Services from a non-authorized module
// Fatal error on solaris
@error
#endif


#undef CATOMYBaseSession            
#undef CATPLMIntegrationAccess            
#undef CATPLMIntegrationUse 
#undef CATOMY
#undef CATPLMItgXOpener   
#undef CATSetupDataFinder   
#undef CATPLMTagDB
#undef CATPLMItgTestIntegrationAccess

#if defined(__CATOMYBaseSession)
#define ExportedByCATOMYBaseSessionRestrictedUseForIntegration DSYExport
#else
#define ExportedByCATOMYBaseSessionRestrictedUseForIntegration DSYImport
#endif
#include "DSYExport.h"
