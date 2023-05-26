//===================================================================
// COPYRIGHT Dassault Systemes 2016
//===================================================================
//
// CATCSSkinWireImpEnums.h
// Class defining enums for Skin & Wire CDS implementation objects
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// March 2016  Creation                                         FCX
//===================================================================

#ifndef CATCSSkinWireImpEnums_H
#define CATCSSkinWireImpEnums_H

enum CATCSCrvParamType
{
  CSParamBounded,
  CSParamPeriodic
};

enum CATCSDiscontinuitySide
{
  CSLower,
  CSUpper,
  CSNoDiscontinuity
};

enum CATCSCurveCGMContinuityImp
{
  UnknownContinuity = 0,
  G0Continuity,
  G1Continuity,
  G2Continuity
};

#endif
