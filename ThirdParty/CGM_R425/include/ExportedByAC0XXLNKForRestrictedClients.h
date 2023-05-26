// COPYRIGHT DASSAULT SYSTEMES 2003
/**
* @level Protected
* @usage U3
*/
// ExportedByAC0XXLNKForRestrictedClients module header

#undef ExportedByAC0XXLNK

  //-----------------------------------------------------
  //  Check that only infrastructure modules can link on the exported symbols
  //----------------------------------------------------

// List of forbidden re-define

#if defined (private) || defined(friend) || defined (protected)

	#error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 

#endif

#define AuthorizedModuleForDocPathServices 111

// Check no one makes a declaration to by-pass our control. 
#if _MK_MODNAME_ == AuthorizedModuleForDocPathServices  
  #error Module declared as authorized by another header  
  // Fatal error on solaris
  @error 
#endif    

// List of authorized infrastructure modules 
#define AC0XXLNK					AuthorizedModuleForDocPathServices
#define CATCLGTST_FBDI				AuthorizedModuleForDocPathServices
#define CATFbdImportNewVersion		AuthorizedModuleForDocPathServices
#define PrdTestAttMap_Migration		AuthorizedModuleForDocPathServices
#define TestFileEngine				AuthorizedModuleForDocPathServices
#define TestGraphBuilderR205		AuthorizedModuleForDocPathServices
#define TstFBDImport				AuthorizedModuleForDocPathServices
#define PrdTestAttMap				AuthorizedModuleForDocPathServices
#define PrdTestPSFactories			AuthorizedModuleForDocPathServices
#define CATFbdImportInterfaces		AuthorizedModuleForDocPathServices
#define CATFbdMappingTable			AuthorizedModuleForDocPathServices
#define CATFbdModeler				AuthorizedModuleForDocPathServices
#define CATFbdImportUI				AuthorizedModuleForDocPathServices
#define PLMBatchFBDI_UI				AuthorizedModuleForDocPathServices
#define OmbTestMisc					AuthorizedModuleForDocPathServices
#define CATClnSpecs					AuthorizedModuleForDocPathServices



#if _MK_MODNAME_ == AuthorizedModuleForDocPathServices

#else

	    #error Forbidden Access To AC0XXLNK Services from a non-client module
        // Fatal error on solaris
        @error 

#endif

#undef  AC0XXLNK
#undef  CATCLGTST_FBDI								
#undef  CATFbdImportNewVersion		
#undef  PrdTestAttMap_Migration		
#undef  TestFileEngine				
#undef  TestGraphBuilderR205		
#undef  TstFBDImport				
#undef  PrdTestAttMap				
#undef  PrdTestPSFactories			
#undef  CATFbdImportInterfaces		
#undef  CATFbdMappingTable			
#undef  CATFbdModeler				
#undef  CATFbdImportUI				
#undef  PLMBatchFBDI_UI
#undef  OmbTestMisc
#undef  CATClnSpecs	


#if _MK_MODNAME_ == AuthorizedModuleForDocPathServices
#error Declared Module has not been undeclared correctly
		// Fatal error on solaris
		@error 
#endif 



// ExportedByAC0XXLNKForInfraOnly def

#if defined (__AC0XXLNK)
#define ExportedByAC0XXLNK DSYExport
#else
#define ExportedByAC0XXLNK DSYImport
#endif
#include "DSYExport.h"

