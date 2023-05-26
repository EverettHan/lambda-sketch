#undef ExportedByCATOmyExposedDictonnaryCacheServices

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


#define AuthorizedModuleForDico     975

// Check no one makes a declaration to by-pass our control. 
#if _MK_MODNAME_ == AuthorizedModuleForDico
  #error Module declared as authorized by another header  
  // Fatal error on solaris
  @error 
#endif  

// List of authorized infrastructure modules 

#define CATOMYUtils AuthorizedModuleForDico
#define OMYTST_TestCache AuthorizedModuleForDico
#define OMYTST_ExposedDictionnaryCache AuthorizedModuleForDico
#define ENODicBase AuthorizedModuleForDico
#define CATPLMImplAdapterBase AuthorizedModuleForDico


#if _MK_MODNAME_ == AuthorizedModuleForDico

#else

	    #error Forbidden Access To CATOmyExposedDictonnaryCacheServices Services from a non-authorized module
        // Fatal error on solaris
        @error 
#endif

#undef CATOMYUtils
#undef OMYTST_TestCache
#undef OMYTST_ExposedDictionnaryCache
#undef ENODicBase
#undef CATPLMImplAdapterBase


#if _MK_MODNAME_ == AuthorizedModuleForDico
	#error Declared Module has not been undeclared correctly
	// Fatal error on solaris
	@error
#endif


#ifdef  __ExportedByCATOmyExposedDictonnaryCacheServices

#define ExportedByCATOmyExposedDictonnaryCacheServices DSYExport
#else
#define ExportedByCATOmyExposedDictonnaryCacheServices DSYImport
#endif
#include "DSYExport.h"
