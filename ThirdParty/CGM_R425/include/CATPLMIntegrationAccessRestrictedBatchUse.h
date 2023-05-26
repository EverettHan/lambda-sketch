#undef ExportedByCATPLMIntegrationAccessRestrictedBatchUse 

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
#define CATDMUUtilityBI                       AuthorizedModule // DMU batches.
#define TSTCATAdpProtectedDWSQuery            AuthorizedModule
#define CATPLMItgTestIntegrationAccess        AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

	    #error Forbidden Access To CATPLMIntegrationAccessRestrictedBatchUse Services from a non-authorized module
        // Fatal error on solaris
        @error 
#endif


#undef CATDMUUtilityBI
#undef CATPLMIntegrationAccess            
#undef TSTCATAdpProtectedDWSQuery
#undef CATPLMItgTestIntegrationAccess

#if defined(__CATPLMIntegrationAccess)
#define ExportedByCATPLMIntegrationAccessRestrictedBatchUse DSYExport
#else
#define ExportedByCATPLMIntegrationAccessRestrictedBatchUse DSYImport
#endif
#include "DSYExport.h"


