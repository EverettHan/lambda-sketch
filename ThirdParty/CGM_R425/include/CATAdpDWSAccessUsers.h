/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Private
 * @usage U3
*/
// aa
#undef ExportedByCATPLMIntegrationDWSAccessUse 
#if defined (private) || defined(friend) || defined (protected)
#error Forbidden re-define of 'private', 'friend' or 'protected'
// Fatal error on solaris
@error 
#endif

#define AuthorizedModule     999
// List of authorized infrastructure modules 
#define CATPLMDWSAccess AuthorizedModule
#define CATPLMSessionContentAccess AuthorizedModule
#define CATPLMItgTestIntegrationAccess AuthorizedModule
#define CATPLMOpenUI AuthorizedModule
#define CATPLMWorkspaceImpl AuthorizedModule
#define CATPLMClientCoreModel AuthorizedModule // PC2
#define CATPLMUIEditability AuthorizedModule
#define PLMSupplierProposalUI AuthorizedModule // Batch Editor
#define CATAuthoringServices AuthorizedModule
#define CATPLMCompare AuthorizedModule
#define CoexDesignWorkspace AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access to CATAdpProtectedDWSAccess from a non-authorized module
// Fatal error on solaris
@error 
#endif
#undef CATPLMDWSAccess
#undef CATPLMSessionContentAccess
#undef CATPLMItgTestIntegrationAccess
#undef CATPLMOpenUI   
#undef CATPLMWorkspaceImpl   
#undef CATPLMClientCoreModel 
#undef CATPLMUIEditability 
#undef PLMSupplierProposalUI 
#undef CATAuthoringServices 
#undef CATPLMCompare 
#undef CoexDesignWorkspace 

#if defined(__CATPLMIntegrationAccess)
#define ExportedByCATPLMIntegrationDWSAccessUse DSYExport
#else
#define ExportedByCATPLMIntegrationDWSAccessUse DSYImport
#endif
#include "DSYExport.h"
