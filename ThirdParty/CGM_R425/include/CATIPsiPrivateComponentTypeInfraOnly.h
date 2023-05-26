// COPYRIGHT DASSAULT SYSTEMES 2005
/**
* @level Private
* @usage U1
*/
#undef ExportedByPLMPSISessionInterfaces

//-----------------------------------------------------
//  Check that only infrastructure modules can link on the exported symbols
//----------------------------------------------------

// List of forbidden re-define

#if defined (private) || defined(friend) || defined (protected)

#error Forbidden re-define of 'private', 'friend' or 'protected'
// Fatal error on solaris
@error

#endif


#define AuthorizedModule 999

// List of authorized infrastructure modules 
#define PLMPSISessionInterfaces		AuthorizedModule 
#define CATPLMPrdSessionServices	AuthorizedModule
#define CATPrdModelStructEdition	AuthorizedModule
#define CATPrdModelInit			AuthorizedModule
#define PrdTestStructureEdition		AuthorizedModule // XLU - 05/10/28 pour les tests de type apres replace
#define CATPrdModelProperties		AuthorizedModule // LCF - 05/09/14 modification d'archi : move de code de AS0STARTUP vers CATPrdModelEdition
#define CATPrdGraphNavig		AuthorizedModule // CHK - 05/12/12 Consistancy display for Representation Icon.
#define PLMProductCore2Visu		AuthorizedModule // CWZ 07.06.05, to be removed , eaiting for PC2 in CATPrdGraphNavig
#define CAT3DPhysicalRepProperties AuthorizedModule
#define CATPLMPrdFactory		AuthorizedModule
#define CAT3DPhysicalRepModel		AuthorizedModule
#define CATPrdModelRep		AuthorizedModule
#define PrdUnitTools		AuthorizedModule
#define PrdStressTestsAttributes		AuthorizedModule
#define CATPLMDocument        		AuthorizedModule
#define CATPrdRelationsPort			AuthorizedModule
#define CATPLMAbstractModel			AuthorizedModule
#define CATPLMPortFactory       AuthorizedModule
#define CATPrdModelConfig			AuthorizedModule
#define CATPrdModelCCP                        AuthorizedModule
#define CATPrdModelNavigation		AuthorizedModule
#define CATPrdLegacy                          AuthorizedModule
#define PLMOccurrenceProductViewer     AuthorizedModule
#define TempoVPMProduct     AuthorizedModule
#define	PLMStateModelProduct		   AuthorizedModule	
#define	PLMOccurrenceProduct		   AuthorizedModule	
#define PrdTest3DPartOperations		 AuthorizedModule
//ProductStructureClientModel
#define CATPrdPccAdaptors                     AuthorizedModule
#define CATPrdPccModelProp                    AuthorizedModule
#define CATRepPccModel                        AuthorizedModule
#define CATRepPccModelProp                    AuthorizedModule
#define CATPrdPccModelRep                     AuthorizedModule
#define CATPrdPccRelationsPort				  AuthorizedModule
#define CATPrdPccModelInit    				  AuthorizedModule
#define CATPrdPccModelNav					  AuthorizedModule
#define CATPrdPGPModel					     AuthorizedModule
//VPM Logical Modeler
#define CATVPMLogicalCreateFactory   AuthorizedModule
#define CATVPMLogicalPort            AuthorizedModule
#define CATVPMLogicalOpenSaveFactory AuthorizedModule
#define CATVPMLogicalConnection      AuthorizedModule
#define CATRFLPLMModelerImpl         AuthorizedModule
#define CATVPMLogicalModelerImpl     AuthorizedModule
#define CATVPMLogicalPublication     AuthorizedModule
#define CATFLModeler                 AuthorizedModule
#define CATLogCoreModelerOnSpecs     AuthorizedModule
#define ProductStructure3DPartImpl	 AuthorizedModule
#define PhysicalAbstractAdapt	 AuthorizedModule
#define PrdTestCATIPLM3DPart AuthorizedModule
#define PrdTestCATIPLM3DPart_OldTyping AuthorizedModule
//Implement Link Modeler:
#define PLMImplementLinkModelerImpl  AuthorizedModule
#define CATPLMPrdTstSOMSO_RepUpdateStatus_UC1 AuthorizedModule
#define PrdTestPLMIProductRepresentations AuthorizedModule
#define CATPLMPrdTstDump AuthorizedModule
#define PrdTestPGP AuthorizedModule // ODT : PGP
#define PrdTestPMR AuthorizedModule // ODT : PMR
#define ProductStructureOccVisProp AuthorizedModule //TBD2 : PGP
#define PrdOccModelUC_PGP_X5 AuthorizedModule //TBD2 : ODT PGP
#define TestPGPPMRBlock AuthorizedModule //TBD2 : ODT
#define TestReadPMRFromJavaWebServices AuthorizedModule //TBD2 : ODT
#define CATPrdTestOldPGPReset AuthorizedModule //TBD2 : ODT
#define PrdOccModelUC_PGPTarget AuthorizedModule //RSR7 : ODT PGP
#define CATPrdTestUtils AuthorizedModule //TBD2 : ODT
#define TestPMRWithBrokenSRs AuthorizedModule //TBD2 : ODT
#define TstPerfoPGP AuthorizedModule //TBD2 : ODT
#define CATPrdPGPPMRMigration AuthorizedModule //H95 : migration PGPPMR
#define CATPrdTools AuthorizedModule
#define PSUnitBase AuthorizedModule
#define CATPLMTstCnxSOSOAdd AuthorizedModule
#define CATPLMPortTstSOSOFalseImpact AuthorizedModule
#define PrdTestExtensionOnInstanceUC AuthorizedModule
#define CATPLMPortTstSOSOAdd AuthorizedModule
#define CATPLMPrdTstSOMSO_FakeRepExt_UC1 AuthorizedModule
#define PrdTestExtensionOnReferenceUC AuthorizedModule
#define PrdTestContinuousQuantityServices AuthorizedModule //CBL1 : ODT continuous quantity
#define PrdTestPerformClone AuthorizedModule
#define PrdTestRepComposition AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

#error Forbidden Access To PLMPSISessionInterfaces from a non-infrastructure module
// Fatal error on solaris
@error

#endif

#undef PLMPSISessionInterfaces
#undef CATPLMPrdSessionServices           
#undef CATPrdModelStructEdition           
#undef CATPrdModelInit
#undef PrdTestStructureEdition
#undef CATPrdModelProperties
#undef CATPrdGraphNavig
#undef CAT3DPhysicalRepProperties
#undef CATPLMPrdFactory
#undef CAT3DPhysicalRepModel
#undef PrdUnitTools
#undef PrdStressTestsAttributes
#undef CATPLMDocument
#undef CATPrdRelationsPort
#undef CATPLMAbstractModel
#undef CATPLMPortFactory
#undef CATPrdModelConfig
#undef CATPrdModelCCP
#undef CATPrdModelNavigation
#undef CATPrdLegacy
#undef PLMOccurrenceProductViewer
#undef TempoVPMProduct
#undef PLMStateModelProduct
#undef PLMOccurrenceProduct
#undef PrdTest3DPartOperations	
//ProductStructureClientModel
#undef CATPrdPccAdaptors
#undef CATPrdPccModelProp
#undef CATRepPccModel
#undef CATRepPccModelProp
#undef CATPrdPccRelationsPort
#undef CATPrdPccModelInit
#undef CATPrdPccModelRep 
#undef CATPrdPccModelNav
#undef CATPrdPGPModel
//VPM Logical Modeler
#undef CATVPMLogicalCreateFactory
#undef CATVPMLogicalPort
#undef CATVPMLogicalOpenSaveFactory
#undef CATVPMLogicalConnection
#undef CATRFLPLMModelerImpl 
#undef CATVPMLogicalModelerImpl
#undef CATVPMLogicalPublication
#undef CATFLModeler
#undef CATLogCoreModelerOnSpecs
#undef ProductStructure3DPartImpl
#undef PhysicalAbstractAdapt
#undef PrdTestCATIPLM3DPart
#undef PrdTestCATIPLM3DPart_OldTyping
//Implement Link Modeler:
#undef PLMImplementLinkModelerImpl
#undef CATPLMPrdTstSOMSO_RepUpdateStatus_UC1 
#undef PrdTestPLMIProductRepresentations 
#undef CATPLMPrdTstDump
// ODT
#undef PrdTestPGP
#undef PrdTestPMR
#undef ProductStructureOccVisProp
#undef PrdOccModelUC_PGP_X5
#undef TestPGPPMRBlock
#undef PrdOccModelUC_PGPTarget
#undef CATPrdTestUtils
#undef TestPMRWithBrokenSRs
#undef TstPerfoPGP
#undef CATPrdPGPPMRMigration
#undef PrdTestContinuousQuantityServices

#undef CATPrdTools
#undef PSUnitBase
#undef CATPLMTstCnxSOSOAdd
#undef CATPLMPortTstSOSOFalseImpact
#undef PrdOccModelUC_PGP_X5
#undef TestReadPMRFromJavaWebServices
#undef CATPrdTestOldPGPReset
#undef PrdTestExtensionOnInstanceUC
#undef CATPLMPortTstSOSOAdd
#undef CATPLMPrdTstSOMSO_FakeRepExt_UC1
#undef PrdTestExtensionOnReferenceUC
#undef PrdTestPerformClone
#undef PrdTestRepComposition 

// ExportedByPLMPSISessionInterfaces def

#if defined __PLMPSISessionInterfaces
#define ExportedByPLMPSISessionInterfaces DSYExport
#else
#define ExportedByPLMPSISessionInterfaces DSYImport
#endif
#include "DSYExport.h"

#include "CATErrorDef.h"
