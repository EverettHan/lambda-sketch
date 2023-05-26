#ifndef CATVBAInclude_h
#define CATVBAInclude_h

#ifdef _WINDOWS_SOURCE

#include "CATVBACodeMacro.h"

#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC6
        #pragma include_alias( "Atlbase.h",  "CAT_Atlbase.h" )
        #pragma include_alias( "Atlcom.h",   "CAT_Atlcom.h"  )
        #pragma include_alias( "Atlconv.h",  "CAT_Atlconv.h" )
        #pragma include_alias( "Atlctl.h",   "CAT_Atlctl.h"  )
        #pragma include_alias( "Atliface.h", "CAT_Atliface.h")
        #pragma include_alias( "Atlwin.h",   "CAT_Atlwin.h"  )
        
        #pragma include_alias( "Statreg.h",   "CAT_Statreg.h"  )
        #pragma include_alias( "Statreg.cpp", "CAT_Statreg.cpp"  )
        
        #pragma include_alias( "Atlconv.cpp",  "CAT_Atlconv.cpp" )
        #pragma include_alias( "Atlctl.cpp",   "CAT_Atlctl.cpp"  )
        #pragma include_alias( "Atlwin.cpp",   "CAT_Atlwin.cpp"  )
        #pragma include_alias( "Atlimpl.cpp",  "CAT_Atlimpl.cpp"  )

#else // _MSC_VER >= 1300 : VC7 and above

#if !defined(DS_VBA7_Integration)
    #pragma include_alias( "ApcMfc.h",   "ApcMfc7.h"  )
    #pragma include_alias( "objext.h",   "objext7.h"  )
#endif

#endif

#endif // _WINDOWS_SOURCE
#endif // CATVBAInclude_h
