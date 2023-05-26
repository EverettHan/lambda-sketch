/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Private
 * @usage U3
*/
#undef ExportedByCATPLMIntegrationDWSQueryUse 
#if defined (private) || defined(friend) || defined (protected)
#error Forbidden re-define of 'private', 'friend' or 'protected'
// Fatal error on solaris
@error 
#endif

#define AuthorizedModule     999
// List of authorized infrastructure modules 
#define CATPLMIntegrationAccess AuthorizedModule
#define CATPLMWorkspaceImpl AuthorizedModule
#define TSTCATAdpProtectedDWSQuery AuthorizedModule
#define SMAMDLUtils AuthorizedModule // Simulia
#define CoexDesignWorkspace AuthorizedModule // CATBack
#define PLMCopyCommands AuthorizedModule // Duplicate
#define CATPLMDuplicate AuthorizedModule // Duplicate
#define CoexistenceAdmin AuthorizedModule // Mapping V6/V6 (old module, to be removed)
#define CoexAdmin AuthorizedModule // Mapping V6/V6
#define CATPLMSessionContentAccess AuthorizedModule
#define CATPLMItgTestIntegrationAccess AuthorizedModule
#define CATPLMOpenUI AuthorizedModule
#define PLMBatchVPLMServices AuthorizedModule
#define CATFmtBatchServices AuthorizedModule // Model Assembly pour Simulation
#define PLMSupplierProposalUI AuthorizedModule // Batch Editor
#define PLMCatalogCommands AuthorizedModule // IsAttachedToWorkspace::IsAttachedToWorkspace
#define PLMCatalogCommandsViewer AuthorizedModule // IsAttachedToWorkspace::IsAttachedToWorkspace
#define CATPLMReplicationEngineBase AuthorizedModule // IsAttachedToWorkspace::GetWorkspaceIdValue - blocage export 3dxml
#define CATCfgFavoritePVSMigrationBatch AuthorizedModule // Migration de config sur donnees DWS.
#define VPMEBOMAccessServices AuthorizedModule      //EBOM - IR-261251
#define CATPLMMatrixSyncRequestUI  AuthorizedModule //EBOM - IR-261251
#define CATPLMUIEditability  AuthorizedModule // Test workspace pour switch editability dans UWP.
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access to CATAdpProtectedDWSQuery from a non-authorized module
// Fatal error on solaris
@error 
#endif
#undef CATPLMIntegrationAccess
#undef CATPLMWorkspaceImpl
#undef TSTCATAdpProtectedDWSQuery
#undef SMAMDLUtils
#undef CoexDesignWorkspace
#undef PLMCopyCommands
#undef CATPLMDuplicate
#undef CoexAdmin
#undef CoexistenceAdmin
#undef CATPLMSessionContentAccess   
#undef CATPLMItgTestIntegrationAccess   
#undef CATPLMOpenUI   
#undef PLMBatchVPLMServices
#undef CATFmtBatchServices 
#undef PLMSupplierProposalUI 
#undef PLMCatalogCommands 
#undef PLMCatalogCommandsViewer 
#undef CATPLMReplicationEngineBase 
#undef CATCfgFavoritePVSMigrationBatch 
#undef VPMEBOMAccessServices
#undef CATPLMMatrixSyncRequestUI
#undef CATPLMUIEditability

#if defined(__CATPLMIntegrationAccess)
#define ExportedByCATPLMIntegrationDWSQueryUse DSYExport
#else
#define ExportedByCATPLMIntegrationDWSQueryUse DSYImport
#endif
#include "DSYExport.h"
