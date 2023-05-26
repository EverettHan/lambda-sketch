// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATCSControledCurve2D.h
// Header definition of CATCSControledCurve2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2010  Creation:                  Vadim YELAGIN
//  Aug 2011  Renaming from CATCSSplineCurve2D                  FCX
//===================================================================
#ifndef CATCSControledCurve2D_H
#define CATCSControledCurve2D_H

#include "CATCDSVirtual.h"
#include "CATCSCurve2D.h"

class CATCSPoint2D;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * An extended callback for 2D parametric curve.
 * Provides an information about derivatives wrt control points
 * and control variables.
 */
class ExportedBySolverInterface CATCSControledCurve2D: public CATCSCurve2D
{
public:
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  // Evaluate the curve derivatives wrt control point.
  // This method must be re-defined if curve depends on points.
  virtual CATCDSBoolean EvaluateDerivWRTControlPoint2D(double iT,
    const CATCSPoint2D* ipControlPoint,
    double oPoint[2][2],
    double oFirstDeriv[2][2],
    double oSecondDeriv[2][2]);

  // Evaluate the curve derivatives wrt control variable.
  // This method must be re-defined if curve depends on variables.
  virtual CATCDSBoolean EvaluateDerivWRTControlVariable2D(double iT,
    const CATCSVariable* ipControlVariable,
    double oaPoint[2],
    double oaFirstDeriv[2],
    double oaSecondDeriv[2]);
};

//-----------------------------------------------------------------------

#endif
