// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATWBInverseFunctions
// Inverse mathematical functions.
//
//===================================================================
//
// Usage notes: Functions for White Box Solver support in CDS.
//
//===================================================================
//
//  May 2008  Creation                          Vitali TELERMAN, DS.
//===================================================================

#ifndef CATWBInverseFunctions_h
#define CATWBInverseFunctions_h

#include "CATWBValue.h"
#include "CATWBEnvironment.h"

// Unary inverse functions

ExportedByWhiteBoxMath CATWBValue CATWBInverseAbs(const CATWBEnvironment & iEnv,
                                                  const CATWBValue & iFValue,
                                                  const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBInverseCeil(const CATWBEnvironment & iEnv,
                                                   const CATWBValue & iFValue,
                                                   const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBInverseFloor(const CATWBEnvironment & iEnv
                                                    , const CATWBValue & iFValue,
                                                    const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBInverseRound(const CATWBEnvironment & iEnv,
                                                    const CATWBValue & iFValue,
                                                    const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBInverseTrunc(const CATWBEnvironment & iEnv,
                                                    const CATWBValue & iFValue,
                                                    const CATWBValue & iValue);

// Binary inverse functions

ExportedByWhiteBoxMath CATWBValue CATWBInverseMod1(const CATWBEnvironment & iEnv,
                                                   const CATWBValue & iFValue,
                                                   const CATWBValue & iValue1,
                                                   const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBInverseMod2(const CATWBEnvironment & iEnv,
                                                   const CATWBValue & iFValue,
                                                   const CATWBValue & iValue1,
                                                   const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBInverseMin(const CATWBEnvironment & iEnv,
                                                  const CATWBValue & iFValue,
                                                  const CATWBValue & iValue1,
                                                  const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBInverseMax(const CATWBEnvironment & iEnv,
                                                  const CATWBValue & iFValue,
                                                  const CATWBValue & iValue1,
                                                  const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBInversePow1(const CATWBEnvironment & iEnv,
                                                   const CATWBValue & iFValue,
                                                   const CATWBValue & iValue1,
                                                   const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBInversePow2(const CATWBEnvironment & iEnv,
                                                   const CATWBValue & iFValue,
                                                   const CATWBValue & iValue1,
                                                   const CATWBValue & iValue2);

ExportedByWhiteBoxMath CATWBValue CATWBInverseAtan21(const CATWBEnvironment & iEnv,
                                                     const CATWBValue & iFValue,
                                                     const CATWBValue & iValue1,
                                                     const CATWBValue & iValue2);
ExportedByWhiteBoxMath CATWBValue CATWBInverseAtan22(const CATWBEnvironment & iEnv,
                                                     const CATWBValue & iFValue,
                                                     const CATWBValue & iValue1,
                                                     const CATWBValue & iValue2);

ExportedByWhiteBoxMath CATWBValue CATWBInverseDim1(const CATWBEnvironment & iEnv,
                                                   const CATWBValue & iFValue,
                                                   const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBInverseDim2(const CATWBEnvironment & iEnv,
                                                   const CATWBValue & iFValue,
                                                   const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBInverseSign1(const CATWBEnvironment & iEnv,
                                                    const CATWBValue & iFValue,
                                                    const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBInverseSign2(const CATWBEnvironment & iEnv,
                                                    const CATWBValue & iFValue,
                                                    const CATWBValue & iValue);

ExportedByWhiteBoxMath CATWBValue CATWBInverseStep(const CATWBEnvironment & iEnv,
                                                   const CATWBValue & iFValue,
                                                   const double iaParams[4]);

ExportedByWhiteBoxMath CATWBValue CATWBInverseOr(const CATWBEnvironment & iEnv,
                                                 const CATWBValue & iFValue,
                                                 const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBInverseAnd(const CATWBEnvironment & iEnv,
                                                  const CATWBValue & iFValue,
                                                  const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBInverseImplication1(const CATWBEnvironment & iEnv,
                                                           const CATWBValue & iFValue,
                                                           const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBInverseImplication2(const CATWBEnvironment & iEnv,
                                                           const CATWBValue & iFValue,
                                                           const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBInverseEqual(const CATWBEnvironment & iEnv,
                                                    const CATWBValue & iFValue,
                                                    const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBInverseNotEqual(const CATWBEnvironment & iEnv,
                                                       const CATWBValue & iFValue,
                                                       const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBInverseLessEqual1(const CATWBEnvironment & iEnv,
                                                         const CATWBValue & iFValue,
                                                         const CATWBValue & iValue);
ExportedByWhiteBoxMath CATWBValue CATWBInverseLessEqual2(const CATWBEnvironment & iEnv,
                                                         const CATWBValue & iFValue,
                                                         const CATWBValue & iValue);

#endif
