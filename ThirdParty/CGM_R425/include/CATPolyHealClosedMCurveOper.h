// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyHealClosedMCurveOper.h
// Header definition of CATPolyHealClosedMCurveOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// sep 2004 Creation: dhp
//===================================================================
#ifndef CATPolyHealClosedMCurveOper_h
#define CATPolyHealClosedMCurveOper_h

#include "CATPolyHealOperators.h"
#include "CATPolyModOper.h"
#include "CATBoolean.h"
#include "CATLISTV_CATPolyMPoint.h"

class CATIPolyMesh;
class CATPolyMCurve;
class CATMathPoint;


/**
* Heals a closed mesh curve. Right now it works only on mesh curves with
* four points (three unique points).
*/

class ExportedByCATPolyHealOperators CATPolyHealClosedMCurveOper : public CATPolyModOper
{

public:

  CATPolyHealClosedMCurveOper (CATIPolyMesh * polyMesh);

  ~CATPolyHealClosedMCurveOper (void);

  void SetTolerance (const double tolerance);

  HRESULT Run (CATPolyMCurve * meshCurve);

  int GetNumProjectedVertices (void) const;

private:

  CATBoolean GetClosestPoint (CATPolyMCurve * meshCurve,
    const int meshPointIndex,
    int & segment,
    CATMathPoint & point,
    double & distance) const;

  CATBoolean GetMinVertexToVertexDistance (CATPolyMCurve * meshCurve,
    int & index0,
    int & index1,
    double & distance) const;

  CATBoolean HealMeshCurve4Points (CATPolyMCurve * meshCurve);

  CATBoolean HealMeshCurve (CATPolyMCurve * meshCurve);

  double _tolerance;

  int _numProjectedVertices;

};

#endif

