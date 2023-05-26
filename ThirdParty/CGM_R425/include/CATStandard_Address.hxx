//============================================================================
//==== Titre: CATStandard_Address.hxx
//==== Role : The headr file of primitve type "Address" from package "CATStandard"
//==== 
//==== Implementation:  This is a primitive type implementadef with typedef
//====        typedef char* Address;
//============================================================================

#ifndef _CATStandard_Address_HeaderFile
#define _CATStandard_Address_HeaderFile

//typedef void* CATStandard_Address;


#ifndef _CATStandard_TypeDef_HeaderFile
#include "CATStandard_TypeDef.hxx"
#endif


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

//#ifndef _CATStandard_Integer_HeaderFile
//#include "CATStandard_Integer.hxx"
//#endif
//#ifndef _CATStandard_Boolean_HeaderFile
//#include "CATStandard_Boolean.hxx"
//#endif

class Handle_CATStandard_Type;

#include "SysCascade.h"
#include "CATDataType.h"

ExportedBySysCascade  Handle_CATStandard_Type& CATStandard_Address_Type_();
//class CATStandard_OStream;
//void ShallowDump (const CATStandard_Address, CATStandard_OStream& );
//============================================================================
//==== ShallowCopy: Returns a CString
//============================================================================
inline CATStandard_Address ShallowCopy (const CATStandard_Address Value)
{
  return Value;
}

//============================================================================
//==== HashCode : Returns a HashCode CString
//============================================================================
inline CATStandard_Integer HashCode (const CATStandard_Address Value, 
				  const CATStandard_Integer Upper)
{
  CATLONGPTR aCATConvert = (CATLONGPTR)Value;
  CATStandard_Integer aRes;
  aRes = (int) (aCATConvert % Upper);
  return aRes + 1;
}


//============================================================================
//==== IsSimilar : Returns CATStandard_True if two booleans have the same value
//============================================================================
inline CATStandard_Boolean IsSimilar(const CATStandard_Address One
				 ,const CATStandard_Address Two)
{ return One == Two; }

//============================================================================
// IsEqual : Returns CATStandard_True if two CString have the same value
//============================================================================

inline CATStandard_Boolean IsEqual(const CATStandard_Address One
			       ,const CATStandard_Address Two)
{ return One == Two; }

#endif
