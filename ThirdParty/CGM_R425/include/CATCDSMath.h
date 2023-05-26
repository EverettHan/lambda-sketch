// COPYRIGHT DASSAULT SYSTEMES 2009
//=============================================================================
//
// CATCDSMath:
//   Additional overloaded math functions.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Oct 2009  Creation                         Vladislav Kornienkoint
//=============================================================================

#ifndef CATCDSMath_h
#define CATCDSMath_h

#include <math.h>
#include <limits.h>

#include "CATCDSInline.h"
#include "CATCDSBoolean.h"
#include "CATCDSMathConstant.h"
#include "CATCDSCPlusPlusVersions.h"

template <class T>
CATCDSInline T const & CATCDSMin(T const &iValueA, T const &iValueB)
{ 
  return (iValueA > iValueB) ? iValueB : iValueA;
}

template <class T>
CATCDSInline T const & CATCDSMin(T const &iValueA, T const &iValueB, T const &iValueC)
{ 
  return CATCDSMin(CATCDSMin(iValueA, iValueB), iValueC);
}

template <class T>
CATCDSInline T const & CATCDSMax(T const &iValueA, T const &iValueB)
{ 
  return (iValueA < iValueB) ? iValueB : iValueA;
}

template <class T>
CATCDSInline T const & CATCDSMax(T const &iValueA, T const &iValueB, T const &iValueC)
{ 
  return CATCDSMax(CATCDSMax(iValueA, iValueB), iValueC);
}

template<class T>
CATCDSInline T CATCDSSquare(T const &iValue)
{
  return iValue * iValue;
}

template<class T>
CATCDSInline T CATCDSCube(T const &iValue)
{ 
  return iValue * iValue * iValue;
}

template<class T>
CATCDSInline int CATCDSSign(T const &iValue)
{ 
  return (iValue > 0) ? 1 : ((iValue < 0) ? -1 : 0);
}

CATCDSInline double CATCDSMsign(double iValueA, double iValueB) { return (iValueB < 0.0) ? -iValueA : iValueA; }

#define CATCDSSin sin
#define CATCDSCos cos
#define CATCDSTan tan
#define CATCDSExp exp
#define CATCDSLog log
#define CATCDSLog10 log10
#define CATCDSAcos acos
#define CATCDSAsin asin
#define CATCDSSqrt sqrt
#define CATCDSSinh sinh
#define CATCDSCosh cosh
#define CATCDSTanh tanh

CATCDSInline double CATCDSPow(double iValue, double iExponent) { return pow(iValue, iExponent); }
CATCDSInline double CATCDSPow(double iValue, int iExponent) { return pow(iValue, iExponent); }
CATCDSInline double CATCDSPow(unsigned int iValue, unsigned int iExponent)
  { unsigned int x = iValue, y = 1; while(iExponent) {if(iExponent & 1) {y *= x;} x *= x; iExponent >>= 1;} return y;}

CATCDSInline double CATCDSAtan(double iValue) { return atan(iValue); }
CATCDSInline double CATCDSAtan(double iSinus, double iCosinus) { return atan2(iSinus, iCosinus); }

CATCDSInline double CATCDSFabs(double iValue)
{
#if defined(_WINDOWS_SOURCE)
  return fabs(iValue);
#else
  return (iValue >= 0.0) ? iValue : -iValue;
#endif
}

CATCDSInline int CATCDSAbs(int iValue) { return (iValue >= 0) ? iValue : -iValue; }

template<class T>
CATCDSInline void CATCDSSwap(T &ioValueA, T&ioValueB)
{
  T temp(CDS_MOVE(ioValueA));
  ioValueA = CDS_MOVE(ioValueB);
  ioValueB = CDS_MOVE(temp);
}

CATCDSInline int CATCDSCeil(double iValue)  { return (int) ceil(iValue); }        //@FDTOI
CATCDSInline int CATCDSFloor(double iValue) { return (int) floor(iValue); }       //@FDTOI
CATCDSInline int CATCDSRound(double iValue) { return (int) floor(iValue + 0.5); } //@FDTOI
CATCDSInline int CATCDSTrunc(double iValue) { return (int) iValue; }              //@FDTOI
CATCDSInline double CATCDSTruncF(double iValue, int iDecimals) {return ((double)CATCDSFloor(iValue * CATCDSPow(10, iDecimals))) / CATCDSPow(10, iDecimals);}

CATCDSInline double CATCDSAsinh(double iValue) { return CATCDSSign(iValue) * CATCDSLog(CATCDSFabs(iValue) + CATCDSSqrt(CATCDSSquare(iValue) + 1.0)); }
CATCDSInline double CATCDSAcosh(double iValue) { return CATCDSLog(iValue + CATCDSSqrt(CATCDSSquare(iValue) - 1.0)); }
CATCDSInline double CATCDSAtanh(double iValue) { return 0.5 * (CATCDSLog(iValue + 1.0) - CATCDSLog(1.0 - iValue)); }

CATCDSInline double CATCDSLog2(double iValue) { return CATCDSLog(iValue) / CATCDSLOG2; }

#if defined(_WINDOWS_SOURCE)
#include <float.h>
inline double CATCDSNextAfter(double a, double b)
{
  return _nextafter(a, b);
}
#else
#include <math.h>
inline double CATCDSNextAfter(double a, double b)
{
  return nextafter(a, b);
}
#endif

#endif
