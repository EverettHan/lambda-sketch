#ifndef _CATStandard_Real_HeaderFile
#define _CATStandard_Real_HeaderFile

#include <float.h>
#include <math.h>
#include <values.h>

#ifdef WNT
# include <CATStandard_math.hxx>
#endif

#ifndef _CATStandard_TypeDef_HeaderFile
#include "CATStandard_TypeDef.hxx"
#endif

//#ifndef _CATStandard_Boolean_HeaderFile
//#include "CATStandard_Boolean.hxx"
//#endif
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
#endif  // __Standarad_API
*/

#include "SysCascade.h"

ExportedBySysCascade  Handle_CATStandard_Type& CATStandard_Real_Type_();

//typedef double CATStandard_Real;

//==== In this version "PI" is a global variables.
#ifdef PI
#undef PI
#endif 

#ifdef WNT
extern "C" ExportedBySysCascade  CATStandard_Real PI;
extern "C" ExportedBySysCascade  CATStandard_Real PI180;
extern "C" ExportedBySysCascade  CATStandard_Real CATStandard_PI;
extern "C" ExportedBySysCascade  CATStandard_Real CATStandard_PI180;
#else

const extern CATStandard_Real PI;
const extern CATStandard_Real PI180;

const extern CATStandard_Real CATStandard_PI;
const extern CATStandard_Real CATStandard_PI180;
#endif  /* WNT */
// ===============================================
// Methods from CATStandard_Entity class which are redefined:  
//    - Hascode
//    - IsEqual
//    - IsSimilar
//    - Shallowcopy
//    - ShallowDump
// ===============================================

// ==================================
// Methods implemeted in CATStandard_Real.cxx
// ==================================
//....             Herited from CATStandard_Storable
ExportedBySysCascade  CATStandard_Integer HashCode    (const CATStandard_Real, const CATStandard_Integer);  
ExportedBySysCascade  CATStandard_Real    ShallowCopy (const CATStandard_Real );  

ExportedBySysCascade  CATStandard_Real    ACos        (const CATStandard_Real );
ExportedBySysCascade  CATStandard_Real    ASin        (const CATStandard_Real );
ExportedBySysCascade  CATStandard_Real    ATan2       (const CATStandard_Real , const CATStandard_Real );
ExportedBySysCascade  CATStandard_Real    NextAfter   (const CATStandard_Real , const CATStandard_Real );
ExportedBySysCascade  CATStandard_Real    Sign        (const CATStandard_Real , const CATStandard_Real );
//class  CATStandard_OStream;
//void             ShallowDump(const CATStandard_Real, CATStandard_OStream& );

//-------------------------------------------------------------------
// RealSmall : Returns the smallest positive real
//-------------------------------------------------------------------
inline CATStandard_Real     RealSmall() 
{ return DBL_MIN; }

//-------------------------------------------------------------------
// Abs : Returns the absolute value of a real
//-------------------------------------------------------------------
inline CATStandard_Real     Abs(const CATStandard_Real Value) 
{ return fabs(Value); }


//-------------------------------------------------------------------
// IsEqual : Returns CATStandard_True if two reals are equal
//-------------------------------------------------------------------
inline CATStandard_Boolean  IsEqual (const CATStandard_Real Value1, 
				  const CATStandard_Real Value2) 
{ return Abs((Value1 - Value2)) < RealSmall(); }

//-------------------------------------------------------------------
// IsSimilar : Returns CATStandard_True if two reals are equal
//-------------------------------------------------------------------
inline CATStandard_Boolean  IsSimilar(const CATStandard_Real One, 
				  const CATStandard_Real Two)
{ return IsEqual (One,Two); }



         //  *********************************** //
         //       Class methods                  //
         //                                      //
         //  Machine-dependant values            //
         //  Should be taken from include file   //
         //  *********************************** //

//-------------------------------------------------------------------
// RealDigit : Returns the number of digits of precision in a real
//-------------------------------------------------------------------
inline CATStandard_Integer  RealDigits() 
{ return DBL_DIG; }

//-------------------------------------------------------------------
// RealEpsilon : Returns the minimum positive real such that 
//               1.0 + x is not equal to 1.0
//-------------------------------------------------------------------
inline CATStandard_Real     RealEpsilon() 
{ return DBL_EPSILON; }

//-------------------------------------------------------------------
// RealFirst : Returns the minimum negative value of a real
//-------------------------------------------------------------------
inline CATStandard_Real     RealFirst() 
{CATStandard_Real aValue = -DBL_MAX; return aValue; }
  
//-------------------------------------------------------------------
// RealFirst10Exp : Returns the minimum value of exponent(base 10) of
//                  a real.
//-------------------------------------------------------------------
inline CATStandard_Integer  RealFirst10Exp() 
{ return DBL_MIN_10_EXP; }

//-------------------------------------------------------------------
// RealLast : Returns the maximum value of a real
//-------------------------------------------------------------------
inline CATStandard_Real     RealLast() 
{ return  DBL_MAX; }

//-------------------------------------------------------------------
// RealLast10Exp : Returns the maximum value of exponent(base 10) of
//                 a real.
//-------------------------------------------------------------------
inline CATStandard_Integer  RealLast10Exp() 
{ return  DBL_MAX_10_EXP; }

//-------------------------------------------------------------------
// RealMantissa : Returns the size in bits of the matissa part of a 
//                real.
//-------------------------------------------------------------------
inline CATStandard_Integer  RealMantissa() 
{ return  DBL_MANT_DIG; }

//-------------------------------------------------------------------
// RealRadix : Returns the radix of exponent representation
//-------------------------------------------------------------------
inline CATStandard_Integer  RealRadix() 
{ return  FLT_RADIX; }

//-------------------------------------------------------------------
// RealSize : Returns the size in bits of an integer
//-------------------------------------------------------------------
inline CATStandard_Integer  RealSize() 
{ return BITS(CATStandard_Real); }



         //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
         //   End of machine-dependant values   //
         //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//


//-------------------------------------------------------------------
// IntToReal : CATConverts an integer in a real
//-------------------------------------------------------------------
inline CATStandard_Real     IntToReal(const CATStandard_Integer Value) 
{ return Value; }

//-------------------------------------------------------------------
// ATan : Returns the value of the arc tangent of a real
//-------------------------------------------------------------------
inline CATStandard_Real     ATan(const CATStandard_Real Value) 
{ return atan(Value); }

//-------------------------------------------------------------------
// ATanh : Returns the value of the hyperbolic arc tangent of a real
//-------------------------------------------------------------------
inline CATStandard_Real     ATanh(const CATStandard_Real Value) 
{ return atanh(Value); }


//-------------------------------------------------------------------
// Ceiling : Returns the smallest integer not less than a real
//-------------------------------------------------------------------
inline CATStandard_Real     Ceiling (const CATStandard_Real Value) 
{ return ceil(Value); }

//-------------------------------------------------------------------
// Cos : Returns the cosine of a real
//-------------------------------------------------------------------
inline CATStandard_Real     Cos (const CATStandard_Real Value) 
{ return cos(Value); }

//-------------------------------------------------------------------
// Cosh : Returns the hyperbolic cosine of a real
//-------------------------------------------------------------------
inline CATStandard_Real     Cosh (const CATStandard_Real Value) 
{ return cosh(Value); }

//-------------------------------------------------------------------
// ACosh : Returns the hyperbolic Arc cosine of a real
//-------------------------------------------------------------------
inline CATStandard_Real     ACosh (const CATStandard_Real Value) 
{ return acosh(Value); }

//-------------------------------------------------------------------
// Epsilon : Returns a real + the smallest real positive value.
//-------------------------------------------------------------------
inline CATStandard_Real     Epsilon (const CATStandard_Real Value) 
{
  CATStandard_Real aEpsilon;

  if (Value>=0.0){
    aEpsilon = NextAfter(Value, RealLast()) - Value;
  } else {
    aEpsilon = Value - NextAfter(Value, RealFirst());
  }
  return aEpsilon;
}

//-------------------------------------------------------------------
// Exp : Returns the exponential function of a real
//-------------------------------------------------------------------
inline CATStandard_Real     Exp (const CATStandard_Real Value) 
{ return exp(Value); }

//-------------------------------------------------------------------
// Floor : Return the largest integer not greater than a real
//-------------------------------------------------------------------
inline CATStandard_Real     Floor (const CATStandard_Real Value) 
{ return floor(Value); }

//-------------------------------------------------------------------
// IntegerPart : Returns the integer part of a real
//-------------------------------------------------------------------
inline CATStandard_Real     IntegerPart (const CATStandard_Real Value) 
{ return ( (Value>0) ? floor(Value) : ceil(Value) ); }

//-------------------------------------------------------------------
// Log : Returns the naturaOPl logarithm of a real
//-------------------------------------------------------------------
inline CATStandard_Real     Log (const CATStandard_Real Value) 
{ return log(Value); }

//-------------------------------------------------------------------
// Log10 : Returns the base-10 logarithm of a real 
//-------------------------------------------------------------------
inline CATStandard_Real     Log10 (const CATStandard_Real Value) 
{ return log10(Value); }

//-------------------------------------------------------------------
// Max : Returns the maximum value of two reals
//-------------------------------------------------------------------
inline CATStandard_Real     Max (const CATStandard_Real Val1, 
                              const CATStandard_Real Val2) 
{
  if (Val1 >= Val2) {
    return Val1;
  } else {
    return Val2;
  }
}

//-------------------------------------------------------------------
// Min : Returns the minimum value of two reals
//-------------------------------------------------------------------
inline CATStandard_Real     Min (const CATStandard_Real Val1, 
                              const CATStandard_Real Val2)
{
  if (Val1 <= Val2) {
    return Val1;
  } else {
    return Val2;
  }
}

//-------------------------------------------------------------------
// Pow : Returns a real to a given power
//-------------------------------------------------------------------
inline CATStandard_Real     Pow (const CATStandard_Real Value, const CATStandard_Real P)
{ return pow(Value,P); }

//-------------------------------------------------------------------
// RealPart : Returns the fractional part of a real.
//-------------------------------------------------------------------
inline  CATStandard_Real    RealPart (const CATStandard_Real Value) 
{ return fabs(IntegerPart(Value) - Value); }

//-------------------------------------------------------------------
// RealToInt : Returns the integer part of a real (in an integer)
//-------------------------------------------------------------------
inline  CATStandard_Integer RealToInt (const CATStandard_Real Value) 
{ 
#ifdef WNT
return ( (Value>0) ? (CATStandard_Integer)floor(Value) : (CATStandard_Integer)ceil(Value) );
#else
return ( (Value>0) ? floor(Value) : ceil(Value) ); 
#endif
}

//-------------------------------------------------------------------
// Round : Returns the nearest integer of a real
//-------------------------------------------------------------------
inline CATStandard_Real     Round (const CATStandard_Real Value) 
{ return IntegerPart(Value + (Value > 0 ? 0.5 : -0.5)); }

//-------------------------------------------------------------------
// Sin : Returns the sine of a real
//-------------------------------------------------------------------
inline CATStandard_Real     Sin (const CATStandard_Real Value) 
{ return sin(Value); }

//-------------------------------------------------------------------
// Sinh : Returns the hyperbolic sine of a real
//-------------------------------------------------------------------
inline CATStandard_Real     Sinh(const CATStandard_Real Value) 
{ return sinh(Value); }

//-------------------------------------------------------------------
// ASinh : Returns the hyperbolic arc sine of a real
//-------------------------------------------------------------------
inline CATStandard_Real     ASinh(const CATStandard_Real Value) 
{ return asinh(Value); }

//-------------------------------------------------------------------
// Sqrt : Returns the square root of a real
//-------------------------------------------------------------------
inline CATStandard_Real     Sqrt (const CATStandard_Real Value) 
{ return sqrt(Value); }

//-------------------------------------------------------------------
// Square : Returns a real to the power 2
//-------------------------------------------------------------------
inline CATStandard_Real     Square(const CATStandard_Real Value) 
{ return Value * Value; }

//-------------------------------------------------------------------
// Tan : Returns the tangent of a real
//-------------------------------------------------------------------
inline CATStandard_Real     Tan (const CATStandard_Real Value) 
{ return tan(Value); }

//-------------------------------------------------------------------
// Tanh : Returns the hyperbolic tangent of a real
//-------------------------------------------------------------------
inline CATStandard_Real     Tanh (const CATStandard_Real Value) 
{ return tanh(Value); }

#endif
