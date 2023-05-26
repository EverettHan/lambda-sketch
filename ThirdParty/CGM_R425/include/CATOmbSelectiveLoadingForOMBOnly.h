// COPYRIGHT DASSAULT SYSTEMES 2005

// ExportedByCATOmbSelectiveLoading module header

/** @required */ 

#undef ExportedByCATOmbSelectiveLoading

  //-----------------------------------------------------
  //  Check that only infrastructure modules can link on the exported symbols
  //----------------------------------------------------

// List of forbidden re-define

#if defined (private) || defined(friend) || defined (protected)

	#error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 

#endif


#define AuthorizedModuleForSelectiveLoading 887

// Check no one makes a declaration to by-pass our control. 
#if _MK_MODNAME_ == AuthorizedModuleForSelectiveLoading  
  #error Module declared as authorized by another header  
  // Fatal error on solaris
    @error 
#endif    

// List of authorized infrastructure modules 
#define CATOmbSelectiveLoading							    AuthorizedModuleForSelectiveLoading
#define CATOmbSwitchEngine                      AuthorizedModuleForSelectiveLoading
#define CATOmbLifeCycle                         AuthorizedModuleForSelectiveLoading
#define CATOmbLinks                             AuthorizedModuleForSelectiveLoading
#define CATPLMStreamDescriptor                  AuthorizedModuleForSelectiveLoading
#define CATOmbRCAEngine						              AuthorizedModuleForSelectiveLoading
#define AC0XXLNK      						              AuthorizedModuleForSelectiveLoading // pour les traces
#define CATOmbTransientServices                 AuthorizedModuleForSelectiveLoading
#define CATOmbImportExport		                	AuthorizedModuleForSelectiveLoading
#define CATOmbNonCATIADocument	            		AuthorizedModuleForSelectiveLoading
#define CATOmbConverter	                  			AuthorizedModuleForSelectiveLoading
#define AD0XXBAS			                        	AuthorizedModuleForSelectiveLoading
#define CATOmbTechnologicalRep	            		AuthorizedModuleForSelectiveLoading
#define CATPLMDocEnv					AuthorizedModuleForSelectiveLoading

// Implementation du modele PLMCore2
#define CATPLMClientCoreModel                   AuthorizedModuleForSelectiveLoading

//debug
#define CATOmbDebugWorkshop   	            		AuthorizedModuleForSelectiveLoading


// ODT Section
#define SelectiveLoadingTST_BasicSwitch         AuthorizedModuleForSelectiveLoading
#define CATPCTMemPLMSpecializedEntity_RepRefLoadingBehavior AuthorizedModuleForSelectiveLoading
#define SelectiveLoadingTST_RepRefTSTImpl       AuthorizedModuleForSelectiveLoading
#define SelectiveLoadingTST_RepRefMigration       AuthorizedModuleForSelectiveLoading
#define SelectiveLoadingTST_ValidateServices	AuthorizedModuleForSelectiveLoading
#define PLMStreamDescriptor_SaveError		AuthorizedModuleForSelectiveLoading
#define CATOmbSelectiveLoadingDictionaryAccess	AuthorizedModuleForSelectiveLoading
#define SelectiveLoadingTST_OmbRepRefInit	AuthorizedModuleForSelectiveLoading
#define SelectiveLoadingTST_OmbRepRefSave	AuthorizedModuleForSelectiveLoading
#define SelectiveLoadingTST_ReInitRepRef	AuthorizedModuleForSelectiveLoading
#define SwitchEngineTST_CheckDirtyTest		AuthorizedModuleForSelectiveLoading
#define SelectiveLoadingTST_AbstractSynchronousSDs	AuthorizedModuleForSelectiveLoading
#define NonCATIADoc_CreateNonCATIARepRefsWithTwoAuthoring AuthorizedModuleForSelectiveLoading
#define CATOxiConcurrentEngineeringSolver AuthorizedModuleForSelectiveLoading
#define SelectiveLoadingTST_OmbRepRefMultiSDBasicTest AuthorizedModuleForSelectiveLoading
#define SelectiveLoadingTST_OmbRepRefMultiSD_PLMx AuthorizedModuleForSelectiveLoading
#define PLMStreamDescriptor_TestSynchroStamp AuthorizedModuleForSelectiveLoading
#define SimulationNavDataModel               AuthorizedModuleForSelectiveLoading
#define CATOmbTestLib_PLM                    AuthorizedModuleForSelectiveLoading
#define CATOxiBagFileLegacy                  AuthorizedModuleForSelectiveLoading


#if _MK_MODNAME_ == AuthorizedModuleForSelectiveLoading

#else

	    #error Forbidden Access To CATOmbSelectiveLoading Services from a non-OMB module
        // Fatal error on solaris
        @error 

#endif

#undef CATOmbSelectiveLoading           
#undef CATOmbSwitchEngine
#undef CATOmbLifeCycle
#undef CATOmbLinks
#undef CATPLMClientCoreModel
#undef CATPLMStreamDescriptor      
#undef CATOmbRCAEngine
#undef AC0XXLNK
#undef CATOmbTransientServices
#undef CATOmbImportExport
#undef CATOmbNonCATIADocument			
#undef CATOmbConverter
#undef AD0XXBAS
#undef CATOmbTechnologicalRep
#undef CATPLMDocEnv

//debug
#undef CATOmbDebugWorkshop

//ODT Section
#undef SelectiveLoadingTST_BasicSwitch
#undef CATPCTMemPLMSpecializedEntity_RepRefLoadingBehavior
#undef SelectiveLoadingTST_RepRefTSTImpl
#undef SelectiveLoadingTST_RepRefMigration
#undef SelectiveLoadingTST_ValidateServices
#undef PLMStreamDescriptor_SaveError	
#undef CATOmbSelectiveLoadingDictionaryAccess
#undef SelectiveLoadingTST_OmbRepRefInit
#undef SelectiveLoadingTST_OmbRepRefSave
#undef SelectiveLoadingTST_ReInitRepRef
#undef SwitchEngineTST_CheckDirtyTest
#undef SelectiveLoadingTST_AbstractSynchronousSDs
#undef NonCATIADoc_CreateNonCATIARepRefsWithTwoAuthoring
#undef CATOxiConcurrentEngineeringSolver
#undef SelectiveLoadingTST_OmbRepRefMultiSDBasicTest
#undef SelectiveLoadingTST_OmbRepRefMultiSD_PLMx
#undef PLMStreamDescriptor_TestSynchroStamp
#undef SimulationNavDataModel
#undef CATOmbTestLib_PLM
#undef CATOxiBagFileLegacy

#if _MK_MODNAME_ == AuthorizedModuleForSelectiveLoading
  #error Declared Module has not been undeclared correctly
  // Fatal error on solaris
  @error 
#endif 


// ExportedByCATOmbSelectiveLoading def

#if defined __CATOmbSelectiveLoading
#define ExportedByCATOmbSelectiveLoading DSYExport
#else
#define ExportedByCATOmbSelectiveLoading DSYImport
#endif
#include "DSYExport.h"

#undef AuthorizedModuleForSelectiveLoading

#include "CATErrorDef.h"
