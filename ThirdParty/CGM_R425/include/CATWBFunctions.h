// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBFunctions.h
// Mathematical functions.
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /07/06     Creation (Sergey Lipski)
// 06/09/19 Q48 Versioning added through CATWBEnvironment
// 25/09/19 Q48 Add CATWBRound with three children (IR-668158)
//===================================================================

#ifndef CATWBFunctions_h
#define CATWBFunctions_h

#include "CATWBValue.h"
#include "CATWBConstants.h"

// Boolean functions

ExportedByWhiteBoxMath CATWBValue CATWBNot(const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBOr(const CATWBValue & iValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBAnd(const CATWBValue & iValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBEqual(const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBNotEqual(const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBLessEqual(const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBImplication(const CATWBValue & iValue1, const CATWBValue & iValue2);

// Arithmetic functions

ExportedByWhiteBoxMath CATWBValue CATWBSum (const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBSub (const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBMul (const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBDiv (const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBPow (const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBRoot(const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2,
                                            const CATWBValue * ipResValue = 0);
ExportedByWhiteBoxMath CATWBValue CATWBMod (const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBDim (const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBSign(const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBMin (const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBMax (const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2);

ExportedByWhiteBoxMath CATWBValue CATWBUnaryMinus(const CATWBEnvironment & iEnv, const CATWBValue & iValue1);

//params : x0, h0, x1, h1
ExportedByWhiteBoxMath CATWBValue CATWBStep(const CATWBEnvironment & iEnv, const CATWBValue & iValue, const double iaParams[4]);

// Trigonometric functions

ExportedByWhiteBoxMath CATWBValue CATWBSin(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBCos(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBTan(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBAsin(const CATWBEnvironment & iEnv, const CATWBValue & iValue,
                                            const CATWBValue * ipResValue = 0);
ExportedByWhiteBoxMath CATWBValue CATWBAcos(const CATWBEnvironment & iEnv, const CATWBValue & iValue,
                                            const CATWBValue * ipResValue = 0);
ExportedByWhiteBoxMath CATWBValue CATWBAtan(const CATWBEnvironment & iEnv, const CATWBValue & iValue,
                                            const CATWBValue * ipResValue = 0);
ExportedByWhiteBoxMath CATWBValue CATWBAtan2(const CATWBEnvironment & iEnv,
                                             const CATWBValue & iValue1,
                                             const CATWBValue & iValue2,
                                             const CATWBValue * ipResValue = 0);

// Hyperbolic functions

ExportedByWhiteBoxMath CATWBValue CATWBSinh(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBCosh(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBTanh(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBAsinh(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBAcosh(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBAtanh(const CATWBEnvironment & iEnv, const CATWBValue & iValue);

// Exponential functions

ExportedByWhiteBoxMath CATWBValue CATWBSqrt(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBLog(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBLn(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBExp(const CATWBEnvironment & iEnv, const CATWBValue & iValue);

// Rounding functions

ExportedByWhiteBoxMath CATWBValue CATWBAbs(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBCeil(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBFloor(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBRound(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBRound(const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2, const CATWBValue & iValue3);
ExportedByWhiteBoxMath CATWBValue CATWBTrunc(const CATWBEnvironment & iEnv, const CATWBValue & iValue);

// Information functions

ExportedByWhiteBoxMath CATCDSBoolean CATWBIsEmpty(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATCDSBoolean CATWBIsConsistent(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
ExportedByWhiteBoxMath CATCDSBoolean CATWBIsExact(const CATWBEnvironment & iEnv, const CATWBValue & iValue, const double iPrecision = -1);
ExportedByWhiteBoxMath CATCDSBoolean CATWBIsIndefinite(const CATWBValue & iValue);

ExportedByWhiteBoxMath CATCDSBoolean CATWBIsEqual(const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2, const double iPrecision = -1);
ExportedByWhiteBoxMath CATCDSBoolean CATWBContains(const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2);

// Set operation functions
//CATWBIntersect returns TRUE if ioValue1 changes and FALSE otherwise
ExportedByWhiteBoxMath CATCDSBoolean CATWBIntersect(const CATWBEnvironment & iEnv, CATWBValue & ioValue1, const CATWBValue & iValue2, const double iPrecision = -1);
ExportedByWhiteBoxMath void CATWBExclude(const CATWBEnvironment & iEnv, CATWBValue & ioValue1, const CATWBValue & iValue2);
ExportedByWhiteBoxMath void CATWBUnite(const CATWBEnvironment & iEnv, CATWBValue & ioValue1, const CATWBValue & iValue2);

//tmp kjd 27Oct2010
//ExportedByWhiteBoxMath CATCDSBoolean CATWBIsExact(const CATWBValue & iValue, double Precision);
//ExportedByWhiteBoxMath CATCDSBoolean CATWBIsEqual(const CATWBEnvironment & iEnv, const CATWBValue & iValue1, const CATWBValue & iValue2, double Precision);
//ExportedByWhiteBoxMath CATCDSBoolean CATWBIntersect(const CATWBEnvironment & iEnv, CATWBValue & ioValue1, const CATWBValue & iValue2, double Precision);
//tmp

#endif
