#ifndef _CATStandard_OStream_HeaderFile
#define _CATStandard_OStream_HeaderFile

#ifdef WNT
#include <Stream_WNT.h>
#else
#include <stream.h>
#endif

class Handle_CATStandard_Type;

#include "SysCascade.h"
/*
#ifndef ExportedBySysCascade 
# ifdef WNT
#  ifdef __CATStandard_DLL
#   define ExportedBySysCascade  __declspec( dllexport )
#  else
#   define ExportedBySysCascade  __declspec( dllimport )
#  endif  // __CATStandard_DLL
# else
#  define ExportedBySysCascade 
# endif  // WNT
#endif  // ExportedBySysCascade 
*/
ExportedBySysCascade  Handle_CATStandard_Type& CATStandard_OStream_Type_();

#define CATStandard_OStream ostream

#endif


