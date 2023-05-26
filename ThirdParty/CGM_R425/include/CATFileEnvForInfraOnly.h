// COPYRIGHT DASSAULT SYSTEMES 2007

// ExportedByCATFileEnv module header

/** @required */ 

#undef ExportedByCATFileEnv

//-----------------------------------------------------
//  Check that only infrastructure modules can link on the exported symbols
//----------------------------------------------------

// List of forbidden re-define

#if defined (private) || defined(friend) || defined (protected)

#error Forbidden re-define of 'private', 'friend' or 'protected'
// Fatal error on solaris
@error 

#endif


#define AuthorizedModuleForCATFileEnv 987

// Check no one makes a declaration to by-pass our control. 
#if _MK_MODNAME_ == AuthorizedModuleForCATFileEnv  
#error Module declared as authorized by another header
// Fatal error on solaris
@error
#endif  

// List of authorized infrastructure modules 
#define CATFileEnv                    AuthorizedModuleForCATFileEnv
#define CATFbdModeler							    AuthorizedModuleForCATFileEnv //FBDI old module
#define CATFbdImportFile					    AuthorizedModuleForCATFileEnv // FBDI new module
#define PLMBatchDocAnalysis_UI			  AuthorizedModuleForCATFileEnv 

// odts section
#define FBDIServicesTST_FileLocators  AuthorizedModuleForCATFileEnv

#if _MK_MODNAME_ == AuthorizedModuleForCATFileEnv

#else

#error Forbidden Access To CATFileEnv Services from a non-infrastructure module
// Fatal error on solaris
@error 

#endif

#undef CATFileEnv
#undef CATFbdModeler            //FBDI old module
#undef CATFbdImportFile         // FBDI new module
#undef FBDIServicesTST_FileLocators
#undef PLMBatchDocAnalysis_UI

#if _MK_MODNAME_ == AuthorizedModuleForCATFileEnv  
#error Module has not been undeclared correctly. Check this header. 
// Fatal error on solaris
@error
#endif  

#undef AuthorizedModuleForCATFileEnv

// ExportedByCATOmbSelectiveLoading def

#if defined __CATFileEnv
#define ExportedByCATFileEnv DSYExport
#else
#define ExportedByCATFileEnv DSYImport
#endif
#include "DSYExport.h"

#include "CATErrorDef.h"
