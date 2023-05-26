// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATCSControledSurface.h
// Header definition of CATCSControledSurface
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Sep 2010  Creation:                  Vadim Yelagin
//  Aug 2011  Renaming from CATCSSplineSurface                  FCX
//===================================================================
#ifndef CATCSControledSurface_H
#define CATCSControledSurface_H

#include "CATCDSVirtual.h"
#include "CATCSSurface.h"

class CATCSPoint;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * An extended callback for parametric surface.
 * Provides an information about derivatives wrt control points
 * and control variables.
 */
class ExportedBySolverInterface CATCSControledSurface: public CATCSSurface
{
public:
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  // Evaluate the surface derivatives wrt control point
  // This method must be re-defined if surface depends on points.
  virtual CATCDSBoolean EvaluateDerivWRTControlPoint(
    double iU,
    double iV,
    const CATCSPoint* ipControlPoint,
    double oPoint[3][3],
    double oUDeriv[3][3],
    double oVDeriv[3][3]);

  // Evaluate the surface derivatives wrt control variable.
  // This method must be re-defined if surface depends on variables.
  virtual CATCDSBoolean EvaluateDerivWRTControlVariable(
    double iU,
    double iV,
    const CATCSVariable* ipControlVariable,
    double oaPoint[3],
    double oaUDeriv[3],
    double oaVDeriv[3]);
};

//-----------------------------------------------------------------------

#endif
