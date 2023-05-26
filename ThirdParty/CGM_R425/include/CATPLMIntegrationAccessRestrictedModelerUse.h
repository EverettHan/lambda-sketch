#undef ExportedByCATPLMIntegrationAccessRestrictedModelerUse 

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
#define CATPLMItgTestBase                     AuthorizedModule
#define CATPLMIntegrationAccess               AuthorizedModule
#define TSTCATAdpProtectedDeleteServices      AuthorizedModule
#define TSTCATAdpSimulateDeleteServices       AuthorizedModule
  // CATAdpProtectedDeleteServices - Test de suppression avec ou sans action
#define CATPLMItgTestIntegrationAccess        AuthorizedModule
#define PLMFolderModelImpl                    AuthorizedModule
  // CATAdpProtectedDeleteServices - Gestion des templates de composants, modeler PLMKnowledgeTemplate.
#define CATPLMTemplates                       AuthorizedModule
#define CATPrdAccessImpl                      AuthorizedModule
  // Service de destruction de references du modeler Simulation
#define CATSimPLMModelerItfCPP                AuthorizedModule
  // CATAdpProtectedDeleteServices - Module de tests chez DXP pour import/export/Reimport dans EV5 (probleme du test d'unicité des refs).
#define CATPLMDataExchange                    AuthorizedModule
  // CATAdpProtectedDeleteServices - Gestion des reps correspondant a des zips de ressources applicatives, modeler PLMKbaRZIP.
#define PLMKbaBuildtime                       AuthorizedModule
  // CATAdpProtectedDeleteServices - Gestion des familles de composants.
#define CATComponentsFamily                   AuthorizedModule
  // CATAdpProtectedDeleteServices - PLM Resource Set modeler
#define CATPLMRscSetRepModel                  AuthorizedModule
  // CATAdpProtectedDeleteServices - Functional modeler
#define DELPLMAccessDeleteRef                 AuthorizedModule
  // CATAdpProtectedDeleteServices - Action Reference modeler
#define PLMActionViewerDocument               AuthorizedModule
#define GUIDPLMChangeBaseModelerInterfaces    AuthorizedModule
  // CATAdpProtectedDeleteServices - External Document Rep Reference modeler
#define PLMDmtDocumentDCCP                    AuthorizedModule
#define CATImmDocCommon                       AuthorizedModule
  // CATAdpProtectedDeleteServices LogicalModeler et FunctionalModeler.
#define CATLogicalModelerAccess               AuthorizedModule
#define CATFunctionalModelerAccess            AuthorizedModule
  // CATAdpProtectedDeleteServices Context modeler
#define CATWSPServices                        AuthorizedModule
  // FW modeler CATMatNavigation - for CATAdpProtectedDeleteServices use (material modeler).
#define CATMatDeleteServices                  AuthorizedModule
  // FW modeler CATMappingModeler - for CATAdpProtectedDeleteServices use (material modeler).
#define CATMappingModelerQuery                AuthorizedModule
  // Project and Task modeler reference - for CATAdpProtectedDeleteServices use.
#define CATPLMCollabUtils                     AuthorizedModule
  // MFA - Unification du code modeler pour utilisation de CATAdpProtectedDeleteServices.
#define PLMMngtDelete                         AuthorizedModule
  // LST - CATAdpProtectedDeleteServices pour modeler CATSysBehaviorLibrary.
#define CATSysLibModelerServices              AuthorizedModule
  // PBV - CATAdpProtectedDeleteServices pour odts infra oxi.
#define CATPLMIdentification_PLM              AuthorizedModule
  // ZUP - Odt
#define CATPLMItgTestOfflineContent           AuthorizedModule
  // JBB - DWS: destruction des workspaces
#define CATPLMWorkspaceImpl                   AuthorizedModule
#define CATPLMItgTests              AuthorizedModule
  // Delete de Refs/Entities pour Engineering specifications - @deprecated V6R425?
#define CATEnsTechCompanyStdsModeler          AuthorizedModule
  // Delete de Refs/Entities pour Engineering specifications - replaces CATEnsTechCompanyStdsModeler stating V6R423
#define CATEseGenericLightImplementations     AuthorizedModule
  // Delete de Refs/Entities pour Simu
#define CATSimPLMDelete                       AuthorizedModule
  // Delete d'Entities BioMockup
#define CATBioKweMockupAccess                 AuthorizedModule
  // Delete of Assessment results (QCC)
#define CATPLMAssessmentResult                AuthorizedModule
  // TUTUAKU Edem - nouveau modeler de filtre 
#define EBOMPSCollaborationModel               AuthorizedModule
  // JRZ To test expand by set bit a deleted ref in the middle
#define CATPCTExpand                           AuthorizedModule
  // NR8 To test MQL open
#define CATPCTOpen                             AuthorizedModule
#define CATItgTestLib                          AuthorizedModule
#define LPUICommands AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

#error Forbidden Access To CATPLMIntegrationAccessRestrictedModelerUse Services from a non-authorized module
  // Fatal error on solaris
  @error 
#endif


#undef AuthorizedModule
#undef CATPLMItgTestBase
#undef CATPLMIntegrationAccess
#undef TSTCATAdpProtectedDeleteServices
#undef TSTCATAdpSimulateDeleteServices
#undef CATPLMItgTestIntegrationAccess
#undef PLMFolderModelImpl
#undef CATPLMTemplates
#undef CATPrdAccessImpl
#undef CATSimPLMModelerItfCPP
#undef CATPLMDataExchange
#undef PLMKbaBuildtime
#undef CATComponentsFamily
#undef CATPLMRscSetRepModel
#undef DELPLMAccessDeleteRef
#undef PLMActionViewerDocument
#undef GUIDPLMChangeBaseModelerInterfaces
#undef PLMDmtDocumentDCCP
#undef CATImmDocCommon
#undef CATLogicalModelerAccess
#undef CATFunctionalModelerAccess
#undef CATWSPServices
#undef CATMatDeleteServices
#undef CATMappingModelerQuery
#undef CATPLMCollabUtils
#undef PLMMngtDelete
#undef CATSysLibModelerServices
#undef CATPLMIdentification_PLM
#undef CATPLMItgTestOfflineContent
#undef CATPLMWorkspaceImpl
#undef CATPLMItgTests
#undef CATEnsTechCompanyStdsModeler
#undef CATEseGenericLightImplementations
#undef CATSimPLMDelete
#undef CATBioKweMockupAccess
#undef CATPLMAssessmentResult
#undef EBOMPSCollaborationModel
#undef CATPCTExpand
#undef CATPCTOpen
#undef LPUICommands
#undef CATItgTestLib

#if defined(__CATPLMIntegrationAccess)
#define ExportedByCATPLMIntegrationAccessRestrictedModelerUse DSYExport
#else
#define ExportedByCATPLMIntegrationAccessRestrictedModelerUse DSYImport
#endif
#include "DSYExport.h"


