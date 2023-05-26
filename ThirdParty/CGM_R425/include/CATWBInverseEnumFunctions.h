// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATWBInverseEnumFunctions
// Enum inverse mathematical functions.
//
//===================================================================
//
// Usage notes: Functions for White Box Solver support in CDS.
//
//===================================================================
//
//  May 2008  Creation                          Vitali TELERMAN, DS.
//===================================================================

#ifndef CATWBInverseEnumFunctions_h
#define CATWBInverseEnumFunctions_h

#include "CATWBValue.h"

// Unary inverse functions

ExportedByWhiteBoxMath CATWBIntegerEnum CATWBInverseAbs(const CATWBEnvironment & iEnv, const CATWBIntegerEnum & iFValue, const CATWBIntegerEnum & iValue);
ExportedByWhiteBoxMath CATWBRealEnum CATWBInverseAbs(const CATWBEnvironment & iEnv, const CATWBRealEnum & iFValue, const CATWBRealEnum & iValue);

// Binary inverse functions

ExportedByWhiteBoxMath CATWBIntegerEnum CATWBInverseMin(const CATWBEnvironment & iEnv, const CATWBIntegerEnum & iFValue, const CATWBIntegerEnum & iValue1, const CATWBIntegerEnum & iValue2);
ExportedByWhiteBoxMath CATWBRealEnum CATWBInverseMin(const CATWBEnvironment & iEnv, const CATWBRealEnum & iFValue, const CATWBRealEnum & iValue1, const CATWBRealEnum & iValue2);

ExportedByWhiteBoxMath CATWBIntegerEnum CATWBInverseMax(const CATWBEnvironment & iEnv, const CATWBIntegerEnum & iFValue, const CATWBIntegerEnum & iValue1, const CATWBIntegerEnum & iValue2);
ExportedByWhiteBoxMath CATWBRealEnum CATWBInverseMax(const CATWBEnvironment & iEnv, const CATWBRealEnum & iFValue, const CATWBRealEnum & iValue1, const CATWBRealEnum & iValue2);

#endif
