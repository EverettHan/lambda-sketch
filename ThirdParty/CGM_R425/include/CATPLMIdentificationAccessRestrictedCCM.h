#undef ExportedByCATPLMIdentificationAccessRestrictedCCM 
/**
 * @level Private
 * @usage U3
 */

#if defined (private) || defined(friend) || defined (protected)
#error Forbidden re-define of 'private', 'friend' or 'protected'
 // Fatal error on solaris
@error
#endif


#define AuthorizedModule     999
// List of authorized infrastructure modules 
#define CATPLMIdentificationAccess            AuthorizedModule
#define CATCfgIntegrationAuthoring            AuthorizedModule
#define CATCfgModelerServicesAuthoring        AuthorizedModule
#define CATOxUFOCMMTestLib                    AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access To ExportedByCATPLMIdentificationAccessRestrictedCCM Services from a non-authorized module
  // Fatal error on solaris
  @error
#endif

#undef AuthorizedModule
#undef CATPLMIdentificationAccess
#undef CATCfgIntegrationAuthoring
#undef CATCfgModelerServicesAuthoring
#undef CATOxUFOCMMTestLib

#if defined(__CATPLMIdentificationAccess)
#define ExportedByCATPLMIdentificationAccessRestrictedCCM DSYExport
#else
#define ExportedByCATPLMIdentificationAccessRestrictedCCM DSYImport
#endif
#include "DSYExport.h"


