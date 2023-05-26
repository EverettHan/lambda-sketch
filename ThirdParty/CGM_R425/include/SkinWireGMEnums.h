//===================================================================
// COPYRIGHT Dassault Systemes 2014
//===================================================================
//
// SkinWireEnumsGM.h
// Enums for Skin & Wire GM objects
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// July 2014    Creation                                         FCX
//===================================================================

#ifndef SkinWireEnumsGM_H
#define SkinWireEnumsGM_H

enum CATCSCurveGMPropagationMode
{
  CSG0Propagation,
  CSG1Propagation,
  CSG2Propagation,
  CSG0G1Propagation
};

enum CATCSCurveGMContinuity
{
  CSUnknownContinuity = 0,
  CSG0Continuity,
  CSG1Continuity,
  CSG2Continuity
};

#endif
