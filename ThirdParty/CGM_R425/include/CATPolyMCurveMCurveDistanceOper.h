// COPYRIGHT Dassault Systemes 2003, all rights reserved.
//===================================================================
//
// CATPolyMCurveMCurveDistanceOper.h
// Header definition of CATPolyMCurveMCurveDistanceOper.
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  mar 2004 Creation: dhp
//===================================================================
#ifndef CATPolyMCurveMCurveDistanceOper_H
#define CATPolyMCurveMCurveDistanceOper_H

#include "CATPolyMCurveAnalyzeOperators.h"
#include "CATPolyMCurveAnalyzeOper.h"

#include "CATBoolean.h"

#include "CATListOfDouble.h"
#include "CATListOfInt.h"

class CATPolyMCurve;
class CATMathSetOfPoints;


class ExportedByCATPolyMCurveAnalyzeOperators CATPolyMCurveMCurveDistanceOper : public CATPolyMCurveAnalyzeOper
{

public:

  CATPolyMCurveMCurveDistanceOper (void);

  ~CATPolyMCurveMCurveDistanceOper (void);

  HRESULT Run (CATPolyMCurve * meshCurve0,
    CATPolyMCurve * meshCurve1);

  double GetMinDistance (void) const;
  double GetMaxDistance (void) const;

protected :

  CATBoolean UpdatePointDistances (const CATMathSetOfPoints & points0,
    const CATMathSetOfPoints & points1);

  CATBoolean UpdateSegmentDistances (const CATMathSetOfPoints & points0,
    const CATMathSetOfPoints & points1);

  double _minDistance;
  double _maxDistance;

};

#endif
