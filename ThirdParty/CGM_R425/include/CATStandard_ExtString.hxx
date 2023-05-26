//============================================================================
//==== Titre: CATStandard_ExtString.hxx
//==== 
//==== Implementation:  This is a primitive type implementadef with typedef
//====        typedef short* CATStandard_ExtString;
//============================================================================

#ifndef _CATStandard_ExtString_HeaderFile
#define _CATStandard_ExtString_HeaderFile


//typedef short* CATStandard_ExtString;
#ifndef _CATStandard_TypeDef_HeaderFile
#include "CATStandard_TypeDef.hxx"
#endif

//#ifndef _CATStandard_Integer_HeaderFile
//#include "CATStandard_Integer.hxx"
//#endif
//#ifndef _CATStandard_Boolean_HeaderFile
//#include "CATStandard_Boolean.hxx"
//#endif

class Handle_CATStandard_Type;
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

ExportedBySysCascade  Handle_CATStandard_Type& CATStandard_ExtString_Type_();
//class CATStandard_OStream;
//void ShallowDump (const CATStandard_ExtString, CATStandard_OStream& );
//============================================================================
//==== ShallowCopy: Returns a CString
//============================================================================
inline CATStandard_ExtString ShallowCopy (const CATStandard_ExtString Value)
{
  return Value;
}

//============================================================================
//==== HashCode : Returns a HashCode ExtString
//============================================================================
ExportedBySysCascade  CATStandard_Integer HashCode (const CATStandard_ExtString, const CATStandard_Integer);

//============================================================================
//==== IsSimilar : Returns CATStandard_True if two booleans have the same value
//============================================================================
inline CATStandard_Boolean IsSimilar(const CATStandard_ExtString One
				 ,const CATStandard_ExtString Two)
{ return One == Two; }

//============================================================================
// IsEqual : Returns CATStandard_True if two ExtString have the same value
//============================================================================
inline CATStandard_Boolean IsEqual(const CATStandard_ExtString One
			       ,const CATStandard_ExtString Two)
{ return One == Two; }


#endif






