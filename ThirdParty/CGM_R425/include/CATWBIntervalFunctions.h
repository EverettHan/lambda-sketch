// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBIntervalFunctions.h
// Interval mathematical functions.
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /07/06     Creation (Sergey Lipski)
//===================================================================

#ifndef CATWBIntervalFunctions_h
#define CATWBIntervalFunctions_h

#include "CATWBIntervalTypes.h"
#include "CATWBConstants.h"
#include "CATWBFraction.h"

// Interval create functions

ExportedByWhiteBoxMath CATWBIntegerInterval CATWBCreateIntegerInterval(int iValue);
ExportedByWhiteBoxMath CATWBIntegerInterval CATWBCreateIntegerInterval(int iLow, int iHigh);
ExportedByWhiteBoxMath CATWBIntegerInterval CATWBCreateIntegerInterval(const CATWBRealInterval & iValue);

ExportedByWhiteBoxMath CATWBRealInterval CATWBCreateRealInterval(double iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBCreateRealInterval(double iLow, double iHigh);
ExportedByWhiteBoxMath CATWBRealInterval CATWBCreateRealInterval(const CATWBIntegerInterval & iValue);

#ifdef WDE1Proto_LongInteger
ExportedByWhiteBoxMath CATWBFraction CATWBCreateFraction(double iN, double iM, int iK = 0, double pgcd = 0);
#else
ExportedByWhiteBoxMath CATWBFraction CATWBCreateFraction(int iN, int iM, int iK = 0, int pgcd = 0);
#endif
// Boolean interval functions

ExportedByWhiteBoxMath CATWBBoolean CATWBEqual(const CATWBEnvironment & iEnv,
                                               const CATWBIntegerInterval & iValue1
                                               , const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATWBBoolean CATWBLessEqual(const CATWBEnvironment & iEnv,
                                                   const CATWBIntegerInterval & iValue1,
                                                   const CATWBIntegerInterval & iValue2);

ExportedByWhiteBoxMath CATWBBoolean CATWBEqual(const CATWBEnvironment & iEnv,
                                               const CATWBRealInterval & iValue1,
                                               const CATWBRealInterval & iValue2);
ExportedByWhiteBoxMath CATWBBoolean CATWBLessEqual(const CATWBEnvironment & iEnv,
                                                   const CATWBRealInterval & iValue1,
                                                   const CATWBRealInterval & iValue2);

// Arithmetic interval functions

ExportedByWhiteBoxMath CATWBIntegerInterval CATWBSum(const CATWBEnvironment & iEnv
                                                     , const CATWBIntegerInterval & iValue1,
                                                     const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATWBIntegerInterval CATWBSub(const CATWBEnvironment & iEnv,
                                                     const CATWBIntegerInterval & iValue1,
                                                     const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATWBIntegerInterval CATWBMul(const CATWBEnvironment & iEnv,
                                                     const CATWBIntegerInterval & iValue1,
                                                     const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATWBIntegerInterval CATWBDiv(const CATWBEnvironment & iEnv,
                                                     const CATWBIntegerInterval & iValue1,
                                                     const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATWBIntegerInterval CATWBMod(const CATWBEnvironment & iEnv,
                                                     const CATWBIntegerInterval & iValue1,
                                                     const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATWBIntegerInterval CATWBMin(const CATWBEnvironment & iEnv,
                                                     const CATWBIntegerInterval & iValue1,
                                                     const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATWBIntegerInterval CATWBMax(const CATWBEnvironment & iEnv,
                                                     const CATWBIntegerInterval & iValue1,
                                                     const CATWBIntegerInterval & iValue2);

ExportedByWhiteBoxMath CATWBRealInterval CATWBSum(const CATWBEnvironment & iEnv,
                                                  const CATWBRealInterval & iValue1,
                                                  const CATWBRealInterval & iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBSub(const CATWBEnvironment & iEnv,
                                                  const CATWBRealInterval & iValue1,
                                                  const CATWBRealInterval & iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBMul(const CATWBEnvironment & iEnv
                                                  , const CATWBRealInterval & iValue1,
                                                  const CATWBRealInterval & iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBDiv(const CATWBEnvironment & iEnv,
                                                  const CATWBRealInterval & iValue1,
                                                  const CATWBRealInterval & iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBPow(const CATWBEnvironment & iEnv,
                                                  const CATWBRealInterval & iValue1,
                                                  const CATWBRealInterval & iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBPow(const CATWBEnvironment & iEnv,
                                                  const CATWBRealInterval & iValue1,
                                                  int iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBMod(const CATWBEnvironment & iEnv,
                                                  const CATWBRealInterval & iValue1,
                                                  const CATWBRealInterval & iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBMin(const CATWBEnvironment & iEnv,
                                                  const CATWBRealInterval & iValue1,
                                                  const CATWBRealInterval & iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBMax(const CATWBEnvironment & iEnv,
                                                  const CATWBRealInterval & iValue1,
                                                  const CATWBRealInterval & iValue2);

ExportedByWhiteBoxMath CATWBRealInterval CATWBRootPositive(const CATWBEnvironment & iEnv,
                                                           const CATWBRealInterval & iValue1,
                                                           int iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBRootNegative(const CATWBEnvironment & iEnv,
                                                           const CATWBRealInterval & iValue1,
                                                           int iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBRoot(const CATWBEnvironment & iEnv,
                                                   const CATWBRealInterval & iValue1,
                                                   int iValue2,
                                                   const CATWBRealInterval & iResValue);

// Trigonometric interval functions

ExportedByWhiteBoxMath CATWBRealInterval CATWBSin(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBCos(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBTan(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBAsin(const CATWBEnvironment & iEnv,
                                                   const CATWBRealInterval & iValue,
                                                   const CATWBRealInterval & iResValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBAcos(const CATWBEnvironment & iEnv,
                                                   const CATWBRealInterval & iValue,
                                                   const CATWBRealInterval & iResValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBAtan(const CATWBEnvironment & iEnv,
                                                   const CATWBRealInterval & iValue,
                                                   const CATWBRealInterval & iResValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBAtan2(const CATWBEnvironment & iEnv,
                                                    const CATWBRealInterval & iValue1,
                                                    const CATWBRealInterval & iValue2,
                                                    const CATWBRealInterval & iResValue);

// Hyperbolic interval functions

ExportedByWhiteBoxMath CATWBRealInterval CATWBSinh(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBCosh(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBTanh(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBAsinh(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBAcosh(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBAtanh(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);

// Exponential interval functions

ExportedByWhiteBoxMath CATWBRealInterval CATWBSqrt(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBLog(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBLn(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBExp(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);

// Rounding interval functions

ExportedByWhiteBoxMath CATWBIntegerInterval CATWBAbs(const CATWBEnvironment & iEnv, const CATWBIntegerInterval & iValue);

ExportedByWhiteBoxMath CATWBRealInterval CATWBAbs(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBCeil(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBFloor(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBRound(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBTrunc(const CATWBEnvironment & iEnv, const CATWBRealInterval & iValue);

// Information interval functions

ExportedByWhiteBoxMath CATCDSBoolean CATWBIsEmpty(const CATWBIntegerInterval & iValue);
ExportedByWhiteBoxMath CATCDSBoolean CATWBIsEmpty(const CATWBRealInterval & iValue,
                                                  double iEps = CATWBAbsPrecision);

ExportedByWhiteBoxMath CATCDSBoolean CATWBIsConsistent(const CATWBIntegerInterval & iValue);
ExportedByWhiteBoxMath CATCDSBoolean CATWBIsConsistent(const CATWBRealInterval & iValue,
                                                       double iEps = CATWBAbsPrecision);

ExportedByWhiteBoxMath CATCDSBoolean CATWBIsExact(const CATWBIntegerInterval & iValue);
ExportedByWhiteBoxMath CATCDSBoolean CATWBIsExact(const CATWBRealInterval & iValue,
                                                  double iEps = CATWBAbsPrecision);

ExportedByWhiteBoxMath CATCDSBoolean CATWBIsInfinite(const CATWBIntegerInterval & iValue);
ExportedByWhiteBoxMath CATCDSBoolean CATWBIsInfinite(const CATWBRealInterval & iValue);

ExportedByWhiteBoxMath CATCDSBoolean CATWBIsFinite(const CATWBIntegerInterval & iValue);
ExportedByWhiteBoxMath CATCDSBoolean CATWBIsFinite(const CATWBRealInterval & iValue);

ExportedByWhiteBoxMath CATCDSBoolean CATWBIsEqual(const CATWBIntegerInterval & iValue1,
                                                  const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATCDSBoolean CATWBIsEqual(const CATWBRealInterval & iValue1,
                                                  const CATWBRealInterval & iValue2,
                                                  double iEps = CATWBAbsPrecision);

ExportedByWhiteBoxMath CATCDSBoolean CATWBContains(const CATWBIntegerInterval & iValue1,
                                                   const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATCDSBoolean CATWBContains(const CATWBRealInterval & iValue1,
                                                   const CATWBRealInterval & iValue2,
                                                   double iEps = CATWBAbsPrecision);

// Characteristic interval functions

ExportedByWhiteBoxMath double CATWBMiddle(const CATWBRealInterval & iValue);

ExportedByWhiteBoxMath int CATWBWidth(const CATWBIntegerInterval & iValue);
ExportedByWhiteBoxMath double CATWBWidth(const CATWBRealInterval & iValue);

ExportedByWhiteBoxMath int CATWBMAG(const CATWBIntegerInterval & iValue);
ExportedByWhiteBoxMath double CATWBMAG(const CATWBRealInterval & iValue);

ExportedByWhiteBoxMath int CATWBSignum(const CATWBRealInterval & iValue);

// Set operation interval functions

ExportedByWhiteBoxMath CATWBIntegerInterval CATWBIntersect(const CATWBIntegerInterval & iValue1,
                                                           const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBIntersect(const CATWBRealInterval & iValue1,
                                                        const CATWBRealInterval & iValue2,
                                                        double iEps = CATWBAbsPrecision);

ExportedByWhiteBoxMath CATWBIntegerInterval CATWBUnite(const CATWBIntegerInterval & iValue1,
                                                       const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBUnite(const CATWBRealInterval & iValue1,
                                                    const CATWBRealInterval & iValue2,
                                                    double iEps = CATWBAbsPrecision);

#endif
