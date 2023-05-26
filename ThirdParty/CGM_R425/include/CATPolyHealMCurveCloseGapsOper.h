// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyHealMCurveCloseGapsOper.h
// Header definition of CATPolyHealMCurveCloseGapsOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// jul 2004 Creation: dhp
//===================================================================
#ifndef CATPolyHealMCurveCloseGapsOper_h
#define CATPolyHealMCurveCloseGapsOper_h

#include "CATPolyHealOperators.h"
#include "CATPolyModOper.h"
#include "CATLISTV_CATPolyMPoint.h"
#include "CATListOfInt.h"

class CATIPolyMesh;
class CATPolyMCurve;


/**
* Closes gaps between two mesh curves. (The Run function that takes multiple
* mesh curves is currently not implemented.)
*
* The two mesh curves will only be considered for healing if the ratio of their
* lengths is greater than the specified length ratio.
*/

class ExportedByCATPolyHealOperators CATPolyHealMCurveCloseGapsOper : public CATPolyModOper
{

public:

  CATPolyHealMCurveCloseGapsOper (CATIPolyMesh * polyMesh);

  ~CATPolyHealMCurveCloseGapsOper (void);

  void SetTolerance (const double tolerance);

  void SetLengthRatio (const double lengthRatio);

  HRESULT Run (CATPolyMCurve * meshCurve0,
    CATPolyMCurve * meshCurve1);

  HRESULT Run (const CATListPtrCATPolyMCurve & meshCurves);

  int GetNumProjectedVertices (void) const;

  CATListOfInt _verticesToHeal;
  CATListValCATPolyMPoint _meshPointsToHeal;

private:

  CATBoolean GetVerticesToHeal (CATPolyMCurve * meshCurve0,
    CATPolyMCurve * meshCurve1,
    CATListOfInt & verticesToHeal,
    CATListValCATPolyMPoint & meshPointsToHeal) const;

  double _tolerance;

  double _lengthRatio;

  int _numProjectedVertices;

};

#endif

