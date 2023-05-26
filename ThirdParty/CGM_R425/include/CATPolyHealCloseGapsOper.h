// COPYRIGHT DASSAULT SYSTEMES 2003, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyHealCloseGapsOper.h
// Header definition of CATPolyHealCloseGapsOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// jun 2004 Creation: dhp
//===================================================================
#ifndef CATPolyHealCloseGapsOper_h
#define CATPolyHealCloseGapsOper_h

#include "CATPolyHealOperators.h"
#include "CATPolyModOper.h"

#include "CATLISTV_CATPolyMPoint.h"

class CATIPolyMesh;
class CATPolyMPoint;

class CATPolySpatialPartitionOper;

/**
* Heals the mesh. Only those gaps that can be closed by unambiguously projecting
* a vertex to a boundary are closed.
*/

class ExportedByCATPolyHealOperators CATPolyHealCloseGapsOper : public CATPolyModOper
{

public:

  CATPolyHealCloseGapsOper (CATIPolyMesh * polyMesh,
    const CATListOfInt & holeVertices,
    const CATListOfInt & freeBarVertices0,
    const CATListOfInt & freeBarVertices1);

  ~CATPolyHealCloseGapsOper (void);

  void SetTolerance (const double tolerance);

  HRESULT Run (void);

  int GetNumProjectedVertices (void) const;

  CATBoolean GetVerticesToHeal (CATListOfInt & verticesToHeal,
    CATListValCATPolyMPoint & meshPointsToHeal) const;
    
  CATBoolean GetVerticesToHeal (CATListOfInt & verticesToHeal,
    CATListPV & meshPointsToHeal) const;

  int GetNumVerticesToHeal (void) const;
    
private:

  CATBoolean CloseGaps (void);

  CATListOfInt _holeVertices;

  double _tolerance;

  CATPolySpatialPartitionOper * _spatialPartition;

  int _numProjectedVertices;

};

#endif

