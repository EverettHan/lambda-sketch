// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATCSControledCurve.h
// Header definition of CATCSControledCurve
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2010  Creation:                  Vadim YELAGIN
//  Aug 2011  Renaming from CATCSSplineCurve                    FCX
//===================================================================
#ifndef CATCSControledCurve_H
#define CATCSControledCurve_H

#include "CATCDSVirtual.h"
#include "CATCSCurve.h"

class CATCSPoint;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * An extended callback for parametric curve.
 * Provides an information about derivatives wrt control points
 * and control variables.
 */
class ExportedBySolverInterface CATCSControledCurve: public CATCSCurve
{
public:
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  // Evaluate the curve derivatives wrt control point
  // This method must be re-defined if curve depends on points.
  virtual CATCDSBoolean EvaluateDerivWRTControlPoint(double iT,
    const CATCSPoint* ipControlPoint,
    double oPoint[3][3],
    double oFirstDeriv[3][3],
    double oSecondDeriv[3][3]);

  // Evaluate the curve derivatives wrt control variable.
  // This method must be re-defined if curve depends on variables.
  virtual CATCDSBoolean EvaluateDerivWRTControlVariable(double iT,
    const CATCSVariable* ipControlVariable,
    double oaPoint[3],
    double oaFirstDeriv[3],
    double oaSecondDeriv[3]);
};

//-----------------------------------------------------------------------

#endif
