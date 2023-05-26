#ifndef CATPLMServicesProc_H
#define CATPLMServicesProc_H

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
#define DNBPPRNavCreateFromCmd                 AuthorizedModule
#define CATPLMServicesUUID                     AuthorizedModule
#define CATPLMServicesProc                     AuthorizedModule
#define CATPLMImplAdapterClass                 AuthorizedModule
#define CATPLMImplAdapterBase                  AuthorizedModule
#define CATPLMItgXProcedureEngine              AuthorizedModule
#define CATPLMIntegrationAccess                AuthorizedModule
#define CATPLMIntegration                      AuthorizedModule
#define CATPLMCompletion                       AuthorizedModule // PJQ: split de CATPLMIntegration.m
#define CATPLMServicesItf                      AuthorizedModule
#define TSTCATPLMAdapters                      AuthorizedModule
#define TSTCATPLMxProcedureCall                AuthorizedModule
#define CATPLMxProcCall                        AuthorizedModule
#define TSTCATPLMxProcedureCallBase            AuthorizedModule
#define TSTCATPLMxProcedureCallCAA1            AuthorizedModule
#define TSTCATPLMxProcedureCallCAA2            AuthorizedModule
#define TSTCATPLMxProcedureCallInfra           AuthorizedModule
#define CATCfgModel                            AuthorizedModule // EPB: project: external web service for RENAULT. Responsibles: ubo/dcu/mms. ubo is Member of Configuration Engine
#define ENOSTBasis                             AuthorizedModule // XJT: temporary 2011 for DRL and P&O multi team project - Should use a basic query instead
#define PLMMD1                                 AuthorizedModule // XJT: temporary 2011 for DRL and P&O multi team project - Should use a basic query instead
#define FolderAuthoringServices                AuthorizedModule // XJT: Attach and detach of CBP by procedure
#define CATDPCOntoType                         AuthorizedModule // XJT: Projet Knowledge Ontologies in debug FW
#define CATPLMDocModel                         AuthorizedModule // XJT: Upload de fichier pour document CBP
#define CATImmDocViewerCommon                  AuthorizedModule // EPB: delivered for Benoit CERRINA (bcc) responsible for document. retrieve a list of files locked on a document.
#define CATPLMOntoNav                          AuthorizedModule // EPB: delivered for BOUILLON Pascal projet: Knowledge Ontologies
#define DecIDFWriteClient                      AuthorizedModule // EPB: Search a xCAD document (CATIAV5,Solidworks,Autocad,ProE,...) using 3DLive/VPMNav. Delivered for JKR
#define XPGTransferCmd                         AuthorizedModule // EPB: Use of CATPLMProcedureParams.h . Delivered for DRT/ULV in xPDM/XPG context
#define XPGCommonServices                      AuthorizedModule // EPB: Use of CATPLMProcedureParams.h . Delivered for DRT/ULV in xPDM/XPG context
#define CATPLMActionClientCoreServices         AuthorizedModule // XJT: Use of CATPLMProcedureParams.h . Delivered for VPLMgetApplicabityFromChangeTask
#define PLMChangeBaseModelerUtilities          AuthorizedModule // XJT: Use of CATPLMProcedureParams.h . Delivered for ECA
#define SEDExecTest                            AuthorizedModule // XJT: Use of CATPLMProcedureParams.h . Delivered for Simulation
#define CATRGNCommands                         AuthorizedModule // XJT: Use of CATPLMProcedureParams.h . Delivered for CATRgnWinEditorUI (generation de rapport)
#define CATPLMInterCADImportExportCommands     AuthorizedModule // XJT: Use of CATPLMProcedureParams.h . Delivered for GSMUI (temporary) moved to another fw later
#define CATPLMAsync                            AuthorizedModule // L6I: AsyncProcedureCall dev
#define CATAsyncServices                       AuthorizedModule // L6I: AsyncProcedureCall dev
#define CATOmyAsyncPlatformTestCommon          AuthorizedModule // L6I: AsyncProcedureCall dev
#define CATOmyAsyncPlatformTestLauncher        AuthorizedModule // L6I: AsyncProcedureCall dev
#define CATOmyProcessVVSAsync                  AuthorizedModule // L6I: AsyncProcedureCall dev
#define CATPLMImplAdapterQLBase                AuthorizedModule // L6I: AsyncProcedureCall dev
#define CATPLMImplAdapterAsync                 AuthorizedModule // L6I: AsyncProcedureCall dev
#define CATPLMTagModeler                       AuthorizedModule // DTI: Autocompletion tag
#define CATCfgModelerServices                  AuthorizedModule
#define PLMCatalogDocument                     AuthorizedModule
#define DNBPPRNavCreateFromCmd                 AuthorizedModule
#define CATCfgSessionServices                  AuthorizedModule 
#define CATAsyncTasksPlatform                  AuthorizedModule
#define CATImmPPRNavigatorServices             AuthorizedModule // EPB: project MagicWip for 
#define TSTCATPLMxJSProcedureCall              AuthorizedModule
#define DELPPRWipmidCmd                        AuthorizedModule 
#define CATFstVPMNavUserDefinedOpenUI          AuthorizedModule 
#define CATPLMModelBuilder                     AuthorizedModule // PJQ: split de CATPLMIntegration.m

#if _MK_MODNAME_ == AuthorizedModule

#else

#error Forbidden Access To CATPLMServicesProc Services from a non-authorized module
  // Fatal error on solaris
  @error
#endif

#undef AuthorizedModule

  // List of authorized infrastructure modules 
#undef CATPLMServicesUUID
#undef CATPLMServicesProc
#undef CATPLMImplAdapterClass
#undef CATPLMImplAdapterBase
#undef CATPLMItgXProcedureEngine 
#undef CATPLMIntegrationAccess
#undef CATPLMIntegration
#undef CATPLMCompletion
#undef CATPLMServicesItf
#undef TSTCATPLMAdapters
#undef TSTCATPLMxProcedureCall
#undef CATPLMxProcCall
#undef TSTCATPLMxProcedureCallBase
#undef TSTCATPLMxProcedureCallCAA1
#undef TSTCATPLMxProcedureCallCAA2
#undef TSTCATPLMxProcedureCallInfra
#undef CATCfgModel
#undef ENOSTBasis
#undef PLMMD1
#undef FolderAuthoringServices
#undef CATDPCOntoType
#undef CATPLMDocModel
#undef CATImmDocViewerCommon
#undef CATPLMOntoNav
#undef DecIDFWriteClient
#undef XPGTransferCmd
#undef XPGCommonServices
#undef CATPLMActionClientCoreServices
#undef PLMChangeBaseModelerUtilities
#undef SEDExecTest
#undef CATRGNCommands
#undef CATPLMInterCADImportExportCommands
#undef CATPLMAsync
#undef CATAsyncServices
#undef CATOmyAsyncPlatformTestCommon
#undef CATOmyAsyncPlatformTestLauncher
#undef CATOmyProcessVVSAsync
#undef CATPLMImplAdapterQLBase
#undef CATPLMImplAdapterAsync
#undef CATPLMTagModeler
#undef CATCfgModelerServices
#undef PLMCatalogDocument
#undef DNBPPRNavCreateFromCmd
#undef CATCfgSessionServices
#undef CATAsyncTasksPlatform
#undef CATImmPPRNavigatorServices
#undef TSTCATPLMxJSProcedureCall
#undef DELPPRWipmidCmd
#undef CATFstVPMNavUserDefinedOpenUI
#undef CATPLMModelBuilder 

#if defined(__CATPLMServicesItf)
#define ExportedByCATPLMServicesProc DSYExport
#else
#define ExportedByCATPLMServicesProc DSYImport
#endif
#include "DSYExport.h"

#endif  
