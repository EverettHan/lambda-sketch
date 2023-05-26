//============================================================================
//==== Titre: CATStandard_CString.hxx
//==== Role : The headr file of primitve type "CString" from package "CATStandard"
//==== 
//==== Implementation:  This is a primitive type implementadef with typedef
//====        typedef char* CATStandard_CString;
//============================================================================

#ifndef _CATStandard_CString_HeaderFile
#define _CATStandard_CString_HeaderFile

//typedef char* CATStandard_CString;

#ifndef _CATStandard_TypeDef_HeaderFile
#include "CATStandard_TypeDef.hxx"
#endif

#include <string.h>

#ifdef OS_AIX
#include <strings.h>
#endif

#ifdef WNT
#define strcasecmp stricmp
#endif

//#ifndef _CATStandard_Integer_HeaderFile
//#include "CATStandard_Integer.hxx"
//#endif
//#ifndef _CATStandard_Address_HeaderFile
//#include "CATStandard_Address.hxx"
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

ExportedBySysCascade  Handle_CATStandard_Type& CATStandard_CString_Type_();

inline  CATStandard_Integer Abs (const CATStandard_Integer);
inline CATStandard_CString ShallowCopy (const CATStandard_CString Value);
inline CATStandard_Boolean IsSimilar(const CATStandard_CString One
				 ,const CATStandard_CString Two);
inline CATStandard_Boolean IsEqual(const CATStandard_CString One
			       ,const CATStandard_CString Two);
ExportedBySysCascade  CATStandard_Integer HashCode (const CATStandard_CString,
                           const CATStandard_Integer);
inline CATStandard_Integer HashCode (const CATStandard_CString,
                                  const CATStandard_Integer,
                                  const CATStandard_Integer);
inline CATStandard_Integer HashCode (const CATStandard_CString,
                                  const CATStandard_Integer ,
                                  const CATStandard_Integer ,
                                  CATStandard_Integer& );
CATStandard_Integer HashCodes (const CATStandard_CString ,
                            const CATStandard_Integer  );
inline CATStandard_Boolean ISEQUAL(const CATStandard_CString One ,
                                const CATStandard_Integer LenOne ,
			        const CATStandard_CString Two,
                                const CATStandard_Integer LenTwo );
inline CATStandard_Integer HASHCODE (const CATStandard_CString,
                                  const CATStandard_Integer,
                                  const CATStandard_Integer);
inline CATStandard_Integer HASHCODE (const CATStandard_CString,
                                  const CATStandard_Integer,
                                  const CATStandard_Integer ,
                                  CATStandard_Integer& );
ExportedBySysCascade  CATStandard_Integer HASHCODES (const CATStandard_CString,
                            const CATStandard_Integer);


//class CATStandard_OStream;
//void ShallowDump (const CATStandard_CString, CATStandard_OStream& );
//============================================================================
//==== ShallowCopy: Returns a CString
//============================================================================
inline CATStandard_CString ShallowCopy (const CATStandard_CString Value)
{
  return Value;
}

//============================================================================
//==== IsSimilar : Returns CATStandard_True if two booleans have the same value
//============================================================================
inline CATStandard_Boolean IsSimilar(const CATStandard_CString One
				 ,const CATStandard_CString Two)
{ 
  return (strcmp(One,Two) == 0);
}

//============================================================================
// IsEqual : Returns CATStandard_True if two CString have the same value
//============================================================================
inline CATStandard_Boolean IsEqual(const CATStandard_CString One
			       ,const CATStandard_CString Two)
{ 
  return (One == Two);
}

//============================================================================
//==== HashCode of CString. Returns the HashCode itself and
//====                              the HashCode % Upper
//============================================================================
inline CATStandard_Integer HashCode (const CATStandard_CString Value,
                                  const CATStandard_Integer Len , 
			          const CATStandard_Integer Upper ,
                                  CATStandard_Integer& aHashCode )
{
  aHashCode = HashCodes( Value , Len );
  return (Abs( aHashCode ) % Upper ) + 1 ;
}

//============================================================================
//==== HashCode of CString. Returns the HashCode itself and
//====                              the HashCode % Upper
//============================================================================
inline CATStandard_Integer HashCode (const CATStandard_CString Value,
                                  const CATStandard_Integer Len ,
			          const CATStandard_Integer Upper )
{
  return (Abs( HashCodes( Value , Len ) ) % Upper ) + 1 ;
}

//============================================================================
//==== HashCode of CString converted to uppercase. Returns the HashCode itself
//====                               and the HashCode % Upper
//============================================================================
inline CATStandard_Integer HASHCODE (const CATStandard_CString Value,
                                  const CATStandard_Integer Len , 
			          const CATStandard_Integer Upper ,
                                  CATStandard_Integer& aHashCode )
{
  aHashCode = HASHCODES( Value , Len );
  return (Abs( aHashCode ) % Upper ) + 1 ;
}

//============================================================================
//==== HashCode of a CString converted to uppercase
//============================================================================
inline CATStandard_Integer HASHCODE (const CATStandard_CString Value,
                                  const CATStandard_Integer Len , 
                                  const CATStandard_Integer Upper)
{
  return (Abs( HASHCODES( Value , Len ) ) % Upper ) + 1 ;
}

//============================================================================
// IsEqual : Returns CATStandard_True if two CString have the same value
//============================================================================
inline CATStandard_Boolean ISEQUAL(const CATStandard_CString One ,
                                const CATStandard_Integer LenOne ,
			        const CATStandard_CString Two,
                                const CATStandard_Integer LenTwo )
{ 
  return ( ( LenOne == LenTwo ) &&
           ( strcasecmp( One , Two ) == 0 ) );
}
#endif



