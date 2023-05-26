// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyProgressiveGapClosingOper.h
// Header definition of CATPolyProgressiveGapClosingOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// mar 2004 Creation: dhp
//===================================================================
#ifndef CATPolyProgressiveGapClosingOper_h
#define CATPolyProgressiveGapClosingOper_h

#include "CATPolyHealOperators.h"
#include "CATPolyModOper.h"
#include "CATBoolean.h"
#include "CATListPV.h"
#include "CATLISTV_CATPolyMPoint.h"

class CATIPolyMesh;
class CATPolyMCurve;
class CATPolyVertexProjectRecord;
class CATMathPoint;


/**
* Implements the progressive gap closing algorithm.
*/

class ExportedByCATPolyHealOperators CATPolyProgressiveGapClosingOper : public CATPolyModOper
{

public:

  CATPolyProgressiveGapClosingOper (CATIPolyMesh * polyMesh);

  ~CATPolyProgressiveGapClosingOper (void);

  void SetTolerance (const double tolerance);

  HRESULT Run (const CATListOfInt & vertices,
    const CATListValCATPolyMPoint & meshPoints);

  CATListPtrCATPolyMCurve _tmpMeshCurves;

  int GetNumProjectedVertices (void) const;

private:

  CATBoolean CloseGaps (const CATListPV & projectRecords);

  CATPolyVertexProjectRecord * BuildProjectRecord (const int vertex,
    const CATPolyMPoint & meshPoint) const;

  double _tolerance;

  int _numProjectedVertices;

};

#endif

