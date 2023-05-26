#ifndef   _CATStandard_PrimitiveTypes_HeaderFile
#define   _CATStandard_PrimitiveTypes_HeaderFile

#include <stddef.h>
#include <stdlib.h>

class CATStandard_Type;
class Handle_CATStandard_Type;

class Handle_CATStandard_Transient;
class CATStandard_Transient;

#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif
#ifndef _CATStandard_Boolean_HeaderFile
#include "CATStandard_Boolean.hxx"
#endif
#ifndef _CATStandard_Integer_HeaderFile
#include "CATStandard_Integer.hxx"
#endif
#ifndef _CATStandard_Real_HeaderFile
#include "CATStandard_Real.hxx"
#endif
#ifndef _CATStandard_Character_HeaderFile
#include "CATStandard_Character.hxx"
#endif
#ifndef _CATStandard_ExtCharacter_HeaderFile
#include "CATStandard_ExtCharacter.hxx"
#endif
#ifndef _CATStandard_CString_HeaderFile
#include "CATStandard_CString.hxx"
#endif
#ifndef _CATStandard_ExtString_HeaderFile
#include "CATStandard_ExtString.hxx"
#endif
//#ifndef _CATStandard_OStream_HeaderFile
//#include "CATStandard_OStream.hxx"
//#endif
//#ifndef _CATStandard_IStream_HeaderFile
//#include "CATStandard_IStream.hxx"
//#endif
//#ifndef _CATStandard_SStream_HeaderFile
//#include "CATStandard_SStream.hxx"
//#endif
#ifndef _CATStandard_Address_HeaderFile
#include "CATStandard_Address.hxx"
#endif
#ifndef _CATStandard_Storable_HeaderFile
#include "CATStandard_Storable.hxx"
#endif
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

ExportedBySysCascade  CATStandard_Address ShallowCopy(const CATStandard_Address, 
		     const Handle_CATStandard_Type& );

ExportedBySysCascade  CATStandard_Integer HashCode(const CATStandard_Address, 
			  const CATStandard_Integer,
			  const Handle_CATStandard_Type&);
//class ostream;
//ExportedBySysCascade  void ShallowDump(const CATStandard_Address,
//		 const Handle_CATStandard_Type&, 
//		 ostream &aOut);

#endif










