//============================================================================
//==== Titre: CATStandard_Boolean.hxx
//==== Role : The headr file of primitve type "Boolean" from package "CATStandard"
//==== 
//==== Implementation:  This is a primitive type implementadef with typedef
//====        typedef int CATStandard_Boolean
//====        #define CATStandard_False 0
//====        #define CATStandard_True  1
//============================================================================

#ifndef _CATStandard_Boolean_HeaderFile
#define _CATStandard_Boolean_HeaderFile

//typedef unsigned int CATStandard_Boolean;


#include "SysCascade.h"

#ifndef _CATStandard_TypeDef_HeaderFile
#include "CATStandard_TypeDef.hxx"
#endif

//#define CATStandard_False (CATStandard_Boolean) 0
//#define CATStandard_True  (CATStandard_Boolean) 1

//#ifndef _CATStandard_Integer_HeaderFile
//#include "CATStandard_Integer.hxx"
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
ExportedBySysCascade  Handle_CATStandard_Type& CATStandard_Boolean_Type_();
//class CATStandard_OStream;
//void ShallowDump (const CATStandard_Boolean, CATStandard_OStream& );
// ===============================================
// Methods from CATStandard_Entity class which are redefined:  
//    - Hascode
//    - IsEqual
//    - IsSimilar
//    - Shallowcopy
//    - ShallowDump
// ===============================================


// ==================================
// Method implemented in CATStandard_Boolean.cxx
// ==================================
ExportedBySysCascade  CATStandard_Boolean ShallowCopy (const CATStandard_Boolean); 
ExportedBySysCascade  CATStandard_Integer HashCode    (const CATStandard_Boolean, const CATStandard_Integer);

// ===============
// inline methods 
// ===============

// ------------------------------------------------------------------
// IsEqual : Returns CATStandard_True if two booleans have the same value
// ------------------------------------------------------------------
inline CATStandard_Boolean IsEqual(const CATStandard_Boolean One
			       ,const CATStandard_Boolean Two)
{ return One == Two; }

// ------------------------------------------------------------------
// IsSimilar : Returns CATStandard_True if two booleans have the same value
// ------------------------------------------------------------------
inline CATStandard_Boolean IsSimilar(const CATStandard_Boolean One
				 ,const CATStandard_Boolean Two)
{ return One == Two; }


#endif
