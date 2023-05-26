
#undef ExportedByPLMBusinessLogicRestrictedInterfaces

//--------------------------------------------------------------------
// Check that only authorized modules can link on the exported symbols
//--------------------------------------------------------------------

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

#define AuthorizedModule 999

// List of authorized modules
#define PLMBusinessLogicInterfaces              AuthorizedModule
#define PLMBusinessLogicManager                 AuthorizedModule
#define PLMBusinessLogicServices                AuthorizedModule
#define CATPLMUIAccess                          AuthorizedModule
#define CATFbdModeler                           AuthorizedModule

#define PLMBLIdentificationInitializationUC     AuthorizedModule
#define PLMBLImportExportAttributesValuationUC  AuthorizedModule
#define PLMBLImportExportAttributesValuationFBDIUC  AuthorizedModule
#define PLMBLFinalizationForOfflineUC  AuthorizedModule
#define PLMBLUserOperationExecutedUC  AuthorizedModule


#if _MK_MODNAME_ == AuthorizedModule

#else

#error Forbidden access to restricted interfaces from a non-authorized module
// Fatal error on solaris
@error
#endif

#undef PLMBusinessLogicInterfaces
#undef PLMBusinessLogicManager
#undef PLMBusinessLogicServices
#undef CATPLMUIAccess
#undef CATFbdModeler
#undef PLMBLIdentificationInitializationUC
#undef PLMBLImportExportAttributesValuationUC
#undef PLMBLFinalizationForOfflineUC
#undef PLMBLUserOperationExecutedUC

#if defined(__PLMBusinessLogicInterfaces)
#define ExportedByPLMBusinessLogicRestrictedInterfaces DSYExport
#else
#define ExportedByPLMBusinessLogicRestrictedInterfaces DSYImport
#endif
#include "DSYExport.h"
