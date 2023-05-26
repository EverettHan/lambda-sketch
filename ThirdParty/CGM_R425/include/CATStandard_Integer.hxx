#ifndef _CATStandard_Integer_HeaderFile
#define _CATStandard_Integer_HeaderFile

#ifndef _CATStandard_TypeDef_HeaderFile
#include "CATStandard_TypeDef.hxx"
#endif

#include <limits.h>
#ifdef HPUX
#undef MAXINT
#endif
#include <values.h>
#include "CATDataType.h"

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

ExportedBySysCascade  Handle_CATStandard_Type& CATStandard_Integer_Type_();
// ===============================================
// Methods from CATStandard_Entity class which are redefined:  
//    - Hascode
//    - IsEqual
//    - IsSimilar
//    - Shallowcopy
//    - ShallowDump
// ===============================================

// ==================================
// Methods implemeted in CATStandard_Integer.cxx
// ==================================

#ifdef Complete_Standard_Integer

ExportedBySysCascade  CATStandard_Integer CharToInt   (const CATStandard_Character me); 
ExportedBySysCascade  CATStandard_Integer CharToInt   (const CATStandard_CString   me); 
ExportedBySysCascade  CATStandard_Integer ShallowCopy (const CATStandard_Integer   me);   
#endif

ExportedBySysCascade  CATStandard_Integer NextPrimeForMap(const CATStandard_Integer anInt ) ;
ExportedBySysCascade  CATLONG32             NextPrime   (const CATLONG32               me);
ExportedBySysCascade  CATStandard_Integer HashCode    (const CATStandard_Integer, const CATStandard_Integer);
// ===============
// Inline methods
// ===============

// ------------------------------------------------------------------
// Abs : Returns the absolute value of an Integer
// ------------------------------------------------------------------
inline  CATStandard_Integer Abs (const CATStandard_Integer Value) 
{ 
  if ( Value > 0 ) {
    return Value; 
  } else if ( Value < 0 ) {
    return -Value;
  }
  else
    return 0 ;
}

#ifdef Complete_Standard_Integer
// ------------------------------------------------------------------
// IsEqual : Returns CATStandard_True if two integers are equal
// ------------------------------------------------------------------
inline CATStandard_Boolean IsEqual(const CATStandard_Integer One
			       ,const CATStandard_Integer Two)
{ return One == Two; }

// ------------------------------------------------------------------
// IsSimilar : Returns CATStandard_True if two integers are equal
// ------------------------------------------------------------------
inline CATStandard_Boolean IsSimilar (const CATStandard_Integer One, 
				   const CATStandard_Integer Two)
{ return One == Two; }


// ------------------------------------------------------------------
// IsEven : Returns CATStandard_True if an integer is even
// ------------------------------------------------------------------
inline CATStandard_Boolean IsEven (const CATStandard_Integer Value) 
{ return Value % 2 == 0; }


// ------------------------------------------------------------------
// IsOdd : Returns CATStandard_True if an integer is odd
// ------------------------------------------------------------------
inline CATStandard_Boolean IsOdd (const CATStandard_Integer Value) 
{ return Value % 2 == 1; }
#endif

// ------------------------------------------------------------------
// Max : Returns the maximum integer between two integers
// ------------------------------------------------------------------
inline CATStandard_Integer  Max (const CATStandard_Integer Val1,
			      const CATStandard_Integer Val2) 
{
  if (Val1 >= Val2) 
    return Val1;
  else
    return Val2;
}

// ------------------------------------------------------------------
// Min : Returns the minimum integer between two integers
// ------------------------------------------------------------------
inline CATStandard_Integer  Min (const CATStandard_Integer Val1, 
			      const CATStandard_Integer Val2) 
{
  if (Val1 <= Val2) 
    return Val1;
  else 
    return Val2;
}

// ------------------------------------------------------------------
// Modulus : Returns the remainder of division between two integers
// ------------------------------------------------------------------
inline CATStandard_Integer  Modulus (const CATStandard_Integer Value, 
				  const CATStandard_Integer Divisor) 
{ return Value % Divisor; }

// ------------------------------------------------------------------
// Square : Returns the square of an integer
// ------------------------------------------------------------------
inline CATStandard_Integer Square(const CATStandard_Integer Value) 
{ return Value * Value; }

// ------------------------------------------------------------------
// IntegerFirst : Returns the minimum value of an integer
// ------------------------------------------------------------------
inline CATStandard_Integer  IntegerFirst()     
{ return INT_MIN; }

// ------------------------------------------------------------------
// IntegerLast : Returns the maximum value of an integer
// ------------------------------------------------------------------
inline CATStandard_Integer  IntegerLast()     
{ return  INT_MAX; }

// ------------------------------------------------------------------
// IntegerSize : Returns the size in digits of an integer
// ------------------------------------------------------------------
inline CATStandard_Integer  IntegerSize()     
{ return (BITS(CATStandard_Integer)); }

#endif 
