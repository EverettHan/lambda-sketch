// COPYRIGHT DASSAULT SYSTEMES 2003, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyHealOper.h
// Header definition of CATPolyHealOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// nov 2003 Creation: dhp
//===================================================================
#ifndef CATPolyHealOper_h
#define CATPolyHealOper_h

#include "CATPolyHealOperators.h"
#include "CATPolyModOper.h"

#include "CATLISTP_CATPolyMCurve.h"
#include "CATListOfInt.h"
#include "CATListPV.h"
#include "CATBoolean.h"

class CATIPolyMesh;
class CATPolyMPoint;


class ExportedByCATPolyHealOperators CATPolyHealOper : public CATPolyModOper
{

public:

  CATPolyHealOper (CATIPolyMesh * polyMesh);

  ~CATPolyHealOper (void);

  void SetTolerance (const double tolerance);

  HRESULT Run (void);

  HRESULT Run (const int vertex,
    const int edgeVertex0,
    const int edgeVertex1);

  int GetNumUnhealedVertices (void) const;

  HRESULT GetUnhealedVertexInfo (const int index,
    int & vertex,
    CATListOfInt & barVertices0,
    CATListOfInt & barVertices1) const;

  void GetHealInfo (int & numFreeVertices0,
    int & numFreeVertices1,
    double & percentHealed) const;

private:

  // CATBoolean RemoveNonManifoldBars (void);

  int GetNumFreeVertices (void) const;

  CATBoolean GetHoleVertices (CATListOfInt & holeVertices) const;

  CATBoolean MergeVertexGroups (const double vertexTolerance);

  CATBoolean RemoveCones (void);

  CATBoolean CloseGaps (const double tolerance,
    int & numProjectedVertices);

  CATBoolean BuildBoundaryMeshCurves (CATListPtrCATPolyMCurve & meshCurves,
    const CATBoolean breakFlag);

  CATBoolean MatchAndHealBoundaries (void);

  CATBoolean HealClosedBoundaries (void);

  CATBoolean GetUnhealedVertices (void);

  CATBoolean CleanupUnhealedVertices (void);

  double _tolerance;

  int _numFreeVertices0;
  int _numFreeVertices1;

  CATListOfInt _unhealedVertices;
  int _numUnhealedVertices;

  CATListPV _unhealedBarVertices0;
  CATListPV _unhealedBarVertices1;

};

#endif

