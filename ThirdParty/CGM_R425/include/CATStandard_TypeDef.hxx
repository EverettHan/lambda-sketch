#ifndef _CATStandard_TypeDef_HeaderFile
#define _CATStandard_TypeDef_HeaderFile
typedef int CATStandard_Integer;
typedef double CATStandard_Real;
typedef unsigned int CATStandard_Boolean;
typedef float CATStandard_ShortReal;
typedef char  CATStandard_Character;
typedef short CATStandard_ExtCharacter;
typedef unsigned char  CATStandard_Byte;
typedef char* CATStandard_CString;
typedef void* CATStandard_Address;
typedef short* CATStandard_ExtString;

#define CATStandard_False (CATStandard_Boolean) 0
#define CATStandard_True  (CATStandard_Boolean) 1

#ifdef WNT
/*
# ifndef ExportedBySysCascade 
#  define ExportedBySysCascade  __declspec( dllexport )
# endif  /* ExportedBySysCascade  */

# ifndef CATStandard_IMPORT
#  define CATStandard_IMPORT __declspec( dllimport )
# endif  /* CATStandard_IMPORT */

#else  /* WNT */
/*
# ifndef ExportedBySysCascade 
#  define ExportedBySysCascade 
# endif  /* ExportedBySysCascade  */

# ifndef CATStandard_IMPORT
#  define CATStandard_IMPORT
# endif  /* CATStandard_IMPORT */

#endif  /* WNT */
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

#include "SysCascade.h"

/*
class ostream;
ExportedBySysCascade  void ShallowDump(const CATStandard_Boolean, ostream& );
ExportedBySysCascade  void ShallowDump(const CATStandard_CString, ostream& );
ExportedBySysCascade  void ShallowDump(const CATStandard_Character, ostream& );
ExportedBySysCascade  void ShallowDump(const CATStandard_ExtCharacter, ostream& );
ExportedBySysCascade  void ShallowDump(const CATStandard_ExtString, ostream& );
ExportedBySysCascade  void ShallowDump(const CATStandard_Integer, ostream& );
ExportedBySysCascade  void ShallowDump(const CATStandard_Address, ostream& );
ExportedBySysCascade  void ShallowDump(const CATStandard_Real, ostream& );
ExportedBySysCascade  void ShallowDump(const CATStandard_ShortReal, ostream& );
*/

#endif

