// COPYRIGHT Dassault Systemes 2003, all rights reserved.
//===================================================================
//
// CATPolyMCurveDistanceOper.h
// Header definition of CATPolyMCurveDistanceOper.
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  apr 2004 Creation: dhp
//===================================================================
#ifndef CATPolyMCurveDistanceOper_H
#define CATPolyMCurveDistanceOper_H

#include "CATPolyMCurveAnalyzeOperators.h"
#include "CATPolyMCurveAnalyzeOper.h"

#include "CATBoolean.h"
#include "CATMathPoint.h"

class CATPolyMCurve;
class CATPolyPointToPolyLineDistanceOper;

class ExportedByCATPolyMCurveAnalyzeOperators CATPolyMCurveDistanceOper : public CATPolyMCurveAnalyzeOper
{

public:

  CATPolyMCurveDistanceOper (CATPolyMCurve * meshCurve);

  ~CATPolyMCurveDistanceOper (void);

  HRESULT Run (const CATMathPoint & point);

  void GetProjectInfo (double & distance,
    int & segment,
    CATMathPoint & projectedPoint) const;

  double GetDistance (void) const;

protected :

  CATPolyMCurve * _meshCurve;

  CATPolyPointToPolyLineDistanceOper * _distanceOper;

  double _distance;
  int _segment;
  CATMathPoint _projectedPoint;

};

#endif
