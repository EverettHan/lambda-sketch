// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATWBInverseIntervalFunctions
// Interval inverse mathematical functions.
//
//===================================================================
//
// Usage notes: Functions for White Box Solver support in CDS.
//
//===================================================================
//
//  May 2008  Creation                          Vitali TELERMAN, DS.
//===================================================================

#ifndef CATWBInverseIntervalFunctions_h
#define CATWBInverseIntervalFunctions_h

#include "CATWBIntervalTypes.h"
#include "CATWBEnvironment.h"

// Unary inverse functions

ExportedByWhiteBoxMath CATWBIntegerInterval CATWBInverseAbs(const CATWBIntegerInterval & iFValue, const CATWBIntegerInterval & iValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBInverseAbs(const CATWBRealInterval & iFValue, const CATWBRealInterval & iValue);

ExportedByWhiteBoxMath CATWBRealInterval CATWBInverseCeil(const CATWBRealInterval & iFValue);
ExportedByWhiteBoxMath CATWBRealInterval CATWBInverseFloor(const CATWBRealInterval & iFValue);

// Binary inverse functions

ExportedByWhiteBoxMath CATWBIntegerInterval CATWBInverseMod1(const CATWBEnvironment & iEnv, const CATWBIntegerInterval & iFValue, const CATWBIntegerInterval & iValue1, const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBInverseMod1(const CATWBEnvironment & iEnv, const CATWBRealInterval & iFValue, const CATWBRealInterval & iValue1, const CATWBRealInterval & iValue2);
ExportedByWhiteBoxMath CATWBIntegerInterval CATWBInverseMod2(const CATWBEnvironment & iEnv, const CATWBIntegerInterval & iFValue, const CATWBIntegerInterval & iValue1, const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBInverseMod2(const CATWBEnvironment & iEnv, const CATWBRealInterval & iFValue, const CATWBRealInterval & iValue1, const CATWBRealInterval & iValue2);

ExportedByWhiteBoxMath CATWBIntegerInterval CATWBInverseMin(const CATWBIntegerInterval & iFValue, const CATWBIntegerInterval & iValue1, const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBInverseMin(const CATWBRealInterval & iFValue, const CATWBRealInterval & iValue1, const CATWBRealInterval & iValue2);

ExportedByWhiteBoxMath CATWBIntegerInterval CATWBInverseMax(const CATWBIntegerInterval & iFValue, const CATWBIntegerInterval & iValue1, const CATWBIntegerInterval & iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBInverseMax(const CATWBRealInterval & iFValue, const CATWBRealInterval & iValue1, const CATWBRealInterval & iValue2);

ExportedByWhiteBoxMath CATWBRealInterval CATWBInversePow1(const CATWBEnvironment & iEnv, const CATWBRealInterval & iFValue, const CATWBRealInterval & iValue1, const CATWBRealInterval & iValue2);
ExportedByWhiteBoxMath CATWBRealInterval CATWBInversePow2(const CATWBEnvironment & iEnv, const CATWBRealInterval & iFValue, const CATWBRealInterval & iValue1, const CATWBRealInterval & iValue2);

ExportedByWhiteBoxMath CATWBBoolean CATWBInverseOr(const CATWBBoolean & iFValue, const CATWBBoolean & iValue);
ExportedByWhiteBoxMath CATWBBoolean CATWBInverseAnd(const CATWBBoolean & iFValue, const CATWBBoolean & iValue);
ExportedByWhiteBoxMath CATWBBoolean CATWBInverseImplication1(const CATWBBoolean & iFValue, const CATWBBoolean & iValue);
ExportedByWhiteBoxMath CATWBBoolean CATWBInverseImplication2(const CATWBBoolean & iFValue, const CATWBBoolean & iValue);

#endif
