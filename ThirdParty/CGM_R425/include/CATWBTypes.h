// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBTypes.h
// Header definition of CATWBTypes
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /06/06      Creation (Sergey Lipski)
// 23/03/17 Q48  Add to predefined constants
// 18/04/18 Q48  Add to predefined constants
// 07/03/19 Q48  Macros to define CATWBExpressionType --> single list to re-use
//                 NOTE - other types are still to do!
// 18/07/19 Q48  Migrate CATWBValueType to use list of macros --> better control
//                 NOTE - other types are still to do!
// 08/11/19 Q48  Add starting value to pre-defined constants enum
//===================================================================

#ifndef CATWBTypes_h
#define CATWBTypes_h

//-----------------------------------------------------------------------
// Macros to define enums (undefined at the end of the file)
//-----------------------------------------------------------------------
#define WBX_TYPE_MACRO_P(iType, iStrParse, iStrPrint) iType
#define WBX_TYPE_MACRO_S(iType, iStr) WBX_TYPE_MACRO_P(iType, iStr, iStr)
#define WBX_TYPE_MACRO(iType) WBX_TYPE_MACRO_S(iType, #iType)
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------

// Q48 19/07/19: Do not insert new entries to the middle of this list - the
//               values are streamed in JSON format. Please only append to it.
#define WBX_VALUE_TYPES WBX_TYPE_MACRO(vtUndefined), \
                        WBX_TYPE_MACRO(vtInteger), \
                        WBX_TYPE_MACRO(vtReal), \
                        WBX_TYPE_MACRO(vtIntegerInterval), \
                        WBX_TYPE_MACRO(vtRealInterval), \
                        WBX_TYPE_MACRO(vtIntegerEnum), \
                        WBX_TYPE_MACRO(vtRealEnum), \
                        WBX_TYPE_MACRO(vtBoolean), \
                        WBX_TYPE_MACRO(vtFraction)


enum CATWBValueType
{
  etValueTypeSTART = -1,
  WBX_VALUE_TYPES,
  etValueTypeEND
};

enum CATWBPredefinedConst
{
  // Starting value
  pcMin = -1,
  /**
  *  the ratio of circumference to diameter of a circle
  */
  pcPi,
  /**
  *  the ratio of circumference to diameter of a circle
  */
  pcPiByTwo,
  /**
  *  the degrees to radians conversion factor
  */
  pcDTOR,
  /**
  *  the radians to degrees conversion factor
  */
  pcRTOD,
  /**
  *  code for indefinite value
  */
  pcIndefinite,
  /**
  *  code for invalid value
  */
  pcInvalid,
  /**
  *  -1
  */
  pcMinusOne,
  /**
  *  0
  */
  pcZero,
  /**
  *  1
  */
  pcOne,
  /**
  *  2
  */
  pcTwo,
  /**
  *  3
  */
  pcThree,
  /**
  *number of elements of this enum
  */
  pcMax
};

// Q48 19/07/19: Do not insert new entries to the middle of this list - the
//               values are streamed in JSON format. Please only append to it.
#define WBX_TYPES WBX_TYPE_MACRO_S(etNone, "none"), \
                  WBX_TYPE_MACRO_S(etVariable, "variable"), \
                  WBX_TYPE_MACRO_S(etConstant, "constant"), \
                  WBX_TYPE_MACRO_P(etNot, "Not", "!"), \
                  WBX_TYPE_MACRO_P(etOr, "Or", " || "), \
                  WBX_TYPE_MACRO_P(etAnd, "And", " && "), \
                  WBX_TYPE_MACRO_P(etEqual, "Equal", "=="), \
                  WBX_TYPE_MACRO_P(etNotEqual, "nEqual", "!="), \
                  WBX_TYPE_MACRO_P(etLessEqual, "lEqual", "<="), \
                  WBX_TYPE_MACRO_S(etImplication, "imply"), \
                  WBX_TYPE_MACRO_P(etSum, "Sum", "+"), \
                  WBX_TYPE_MACRO_P(etProduct, "Product", "*"), \
                  WBX_TYPE_MACRO_P(etQuotient, "Quotient", "/"), \
                  WBX_TYPE_MACRO_P(etPower, "Pow", "^"), \
                  WBX_TYPE_MACRO_S(etRoot, "Root"), \
                  WBX_TYPE_MACRO_S(etSqrt, "Sqrt"), \
                  WBX_TYPE_MACRO_S(etLog, "Log"), \
                  WBX_TYPE_MACRO_S(etLn, "Ln"), \
                  WBX_TYPE_MACRO_S(etExp, "Exp"), \
                  WBX_TYPE_MACRO_S(etSin, "Sin"), \
                  WBX_TYPE_MACRO_S(etCos, "Cos"), \
                  WBX_TYPE_MACRO_S(etTan, "Tan"), \
                  WBX_TYPE_MACRO_S(etAsin, "aSin"), \
                  WBX_TYPE_MACRO_S(etAcos, "aCos"), \
                  WBX_TYPE_MACRO_S(etAtan, "aTan"), \
                  WBX_TYPE_MACRO_S(etAtan2, "aTan2"), \
                  WBX_TYPE_MACRO_S(etDim, "Dim"), \
                  WBX_TYPE_MACRO_S(etSign, "Sign"), \
                  WBX_TYPE_MACRO_S(etStep, "Step"), \
                  WBX_TYPE_MACRO_S(etSinh, "Sinh"), \
                  WBX_TYPE_MACRO_S(etCosh, "Cosh"), \
                  WBX_TYPE_MACRO_S(etTanh, "Tanh"), \
                  WBX_TYPE_MACRO_S(etAsinh, "aSinh"), \
                  WBX_TYPE_MACRO_S(etAcosh, "aCosh"), \
                  WBX_TYPE_MACRO_S(etAtanh, "aTanh"), \
                  WBX_TYPE_MACRO_S(etAbs, "Abs"), \
                  WBX_TYPE_MACRO_S(etCeil, "Ceil"), \
                  WBX_TYPE_MACRO_S(etFloor, "Floor"), \
                  WBX_TYPE_MACRO_S(etRound, "Round"), \
                  WBX_TYPE_MACRO_S(etTrunc, "Trunc"), \
                  WBX_TYPE_MACRO_S(etMod, "Mod"), \
                  WBX_TYPE_MACRO_S(etMin, "Min"), \
                  WBX_TYPE_MACRO_S(etMax, "Max"), \
                  WBX_TYPE_MACRO_S(etIfThenElse, "IfThenElse"), \
                  WBX_TYPE_MACRO_S(etBlackBox, "Bbx"), \
                  WBX_TYPE_MACRO_P(etUnaryMinus, "Minus", "-"), \
                  WBX_TYPE_MACRO_P(etMinus, "Minus", "-"), \
                  WBX_TYPE_MACRO_S(etIntegrate, "Int"), \
                  WBX_TYPE_MACRO_S(etFrac, "Frac")

enum CATWBExpressionType
{
  etTypeSTART = -1,
  WBX_TYPES,
  etTypeEND
};

enum CATWBComparisonType
{
  ctNone,
  ctLE,
  ctLT,
  ctGE,
  ctGT,
};

enum CATWBBlackBoxAlgorithm
{
  bbaGradient,
  bbaQuadratic
};

enum CATWBEquationType
{
  eqNone,

  eqEQ,
  eqNE,
  eqLE,
  eqLT,
  eqGE,
  eqGT,
  eqMinimize,
  eqMaximize
};

enum CATWBNodeType
{
  ntUndefined,
  ntConstant,
  ntVariable,
  ntOperator,
  ntEquation
};

//-----------------------------------------------------------------------
// Remove the macros to define enums (defined at the top of the file)
//-----------------------------------------------------------------------

#undef WBX_TYPE_MACRO
#undef WBX_TYPE_MACRO_S
#undef WBX_TYPE_MACRO_P

//-----------------------------------------------------------------------
#endif // CATWBTypes_h
