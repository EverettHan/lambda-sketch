// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMCurveSpatialPartitionOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  aug 2004 Creation: dhp
//===================================================================
#ifndef CATPolyMCurveSpatialPartitionOper_h
#define CATPolyMCurveSpatialPartitionOper_h

#include "CATPolyBaseSpatialPartitionOper.h"
#include "CATPolyMCurveAnalyzeOperators.h"

#include "CATLISTP_CATPolyMCurve.h"

class CATIPolyMesh;

class ExportedByCATPolyMCurveAnalyzeOperators CATPolyMCurveSpatialPartitionOper : public CATPolyBaseSpatialPartitionOper
{
  
public :

  CATPolyMCurveSpatialPartitionOper (const int sizeX,
    const int sizeY,
    const int sizeZ);

  ~CATPolyMCurveSpatialPartitionOper (void);

  CATBoolean AddMeshCurves (const CATListPtrCATPolyMCurve & meshCurves);

  CATBoolean GetMeshCurves (CATPolyMCurve * meshCurve,
    const double distance,
    CATListPtrCATPolyMCurve & meshCurves) const;

protected :

  CATBoolean CleanupCell (void * cell);

private :

  void PrintCell (CATCGMOutput & stream,
    void * cell) const;

  void CleanupMeshCurveCells (void);

  CATBoolean BuildMeshCurve (const int meshCurveIndex);

  int GetMeshCurveIndex (CATPolyMCurve * meshCurve) const;

  CATListPtrCATPolyMCurve _meshCurves;

  CATListPV * _meshCurveCells;

};

#endif

