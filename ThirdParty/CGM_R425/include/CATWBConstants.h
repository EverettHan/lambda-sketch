// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBConstants.cpp
// Implementation of mathematical constants.
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /07/06     Creation (Sergey Lipski)
//===================================================================

#ifndef CATWBConstants_h
#define CATWBConstants_h

#include "WhiteBoxMath.h"

// single constants
extern ExportedByWhiteBoxMath double CATWBMaxReal; // maximal real value
extern ExportedByWhiteBoxMath double CATWBMinReal; // minimal positive real value
extern ExportedByWhiteBoxMath double CATWBMaxExpReal; // ln(CATWBMaxReal)
extern ExportedByWhiteBoxMath double CATWBMaxHypReal; // acosh(CATWBMaxReal)
extern ExportedByWhiteBoxMath int CATWBMaxPowExpReal; // log(CATWBMaxReal, MAX_DOUBLE)
extern ExportedByWhiteBoxMath int CATWBMaxInteger; // maximal integer value

extern ExportedByWhiteBoxMath double CATWBAbsPrecision; // accuracy for math functions
extern ExportedByWhiteBoxMath double CATWBOnePlusEps;
const int CATWBMaxEnumSize = 50;

// single constants
extern ExportedByWhiteBoxMath double CATWBSingleReal_Any;
extern ExportedByWhiteBoxMath double CATWBSingleReal_Nil;
extern ExportedByWhiteBoxMath int CATWBSingleInteger_Any;
extern ExportedByWhiteBoxMath int CATWBSingleInteger_Nil;

#include "CATWBIntervalTypes.h"

// interval constants
extern ExportedByWhiteBoxMath CATWBRealInterval CATWBReal_Any;
extern ExportedByWhiteBoxMath CATWBRealInterval CATWBReal_Nil;
extern ExportedByWhiteBoxMath CATWBRealInterval CATWBReal_Pos;
extern ExportedByWhiteBoxMath CATWBRealInterval CATWBReal_Trig;
extern ExportedByWhiteBoxMath CATWBRealInterval CATWBReal_TrigInv;
extern ExportedByWhiteBoxMath CATWBIntegerInterval CATWBInteger_Any;
extern ExportedByWhiteBoxMath CATWBIntegerInterval CATWBInteger_Nil;

#endif
