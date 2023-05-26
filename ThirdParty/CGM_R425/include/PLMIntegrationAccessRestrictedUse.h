/* -*-c++-*- */
//-----------------------------------------------------
//  Check that only authorized modules can link on the exported symbols
//----------------------------------------------------

/**
 * @level Private
 * @usage U3
 */

#undef ExportedByPLMIntegrationAccessRestrictedUse 
#if defined (private) || defined(friend) || defined (protected)
	#error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 
#endif

#define AuthorizedModule     999
// List of authorized infrastructure modules 
#define CATPLMIntegration AuthorizedModule
#define CATPLMIntegrationAccess AuthorizedModule
#define CATPLMCAAIntegAccess AuthorizedModule
#define CATPLMIntegrationUse AuthorizedModule

// Systems application (CATSysBehaviorPLMModeler) - For CompleteWithRepRefs use.
#define CATPbmModelerImpl AuthorizedModule

// VPMNAV use of CompleteWithCnxAndPorts.
#define CATPLMCompletionServices AuthorizedModule

// TST frameworks (CATAdpPrivateTransactionHistory,CATAdpPrivateTransactionHistoryPool)
#define CATPLMItgTestIntegrationAccess AuthorizedModule

// CATImmVPMNavPCC for RecordReadSet to AdpQueryResult list transformation (bolino)
#define CATImmVPMNavPCC AuthorizedModule

// For Component Family overwrite mode.
#define CATComponentsFamily AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
	    #error Forbidden Access To PLMIntegrationAccessRestrictedUse Services from a non-authorized module
        // Fatal error on solaris
        @error 
#endif
#undef CATPLMIntegration  
#undef CATPLMIntegrationAccess
#undef CATPLMCAAIntegAccess
#undef CATPLMIntegrationUse
#undef CATPLMCompletionServices
#undef CATPbmModelerImpl
#undef CATPLMItgTestIntegrationAccess
#undef CATImmVPMNavPCC
#undef CATComponentsFamily

#if defined(__CATPLMIntegrationAccess)
#define ExportedByPLMIntegrationAccessRestrictedUse DSYExport
#else
#define ExportedByPLMIntegrationAccessRestrictedUse DSYImport
#endif
#include "DSYExport.h"
