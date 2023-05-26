// COPYRIGHT DASSAULT SYSTEMES 2003, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBoundaryOper.h
// Header definition of CATPolyBoundaryOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// dec 2003 Creation: dhp
//===================================================================

#ifndef CATPolyBoundaryProjectOper_h
#define CATPolyBoundaryProjectOper_h

#include "CATPolyAnalyzeOper.h"
#include "CATPolyAnalyzeOperators.h"

#include "CATLISTV_CATPolyMPoint.h"

#include "CATListOfInt.h"
#include "CATPolyMPoint.h"

#include "CATListPV.h"
#include "CATMathPoint.h"

class CATPolySpatialPartitionOper;

class ExportedByCATPolyAnalyzeOperators CATPolyBoundaryProjectOper : public CATPolyAnalyzeOper
{
  
public :

  CATPolyBoundaryProjectOper (CATIPolyMesh * polyMesh);

  CATPolyBoundaryProjectOper (CATIPolyMesh * polyMesh,
    CATPolySpatialPartitionOper * spatialPartition);

  ~CATPolyBoundaryProjectOper (void);

  void SetTolerance (const double tolerance);

  HRESULT RunOnVertex (const int vertex,
    CATPolyMPoint & projectedMeshPoint);

  HRESULT RunOnVertex (const int vertex,
    CATListValCATPolyMPoint & projectedMeshPoints);

private :

  CATBoolean ProjectToBar (const CATMathPoint & vertexPoint,
    const int vertex0,
    const int vertex1,
    CATMathPoint & pointOnLine,
    double & distance) const;

  CATBoolean Project (const int vertex);

  void CleanupInfoList (void);

  CATPolySpatialPartitionOper * _spatialPartitionNew;
  CATPolySpatialPartitionOper * _spatialPartition;

  CATListPV _projectInfoList;

  double _tolerance;

};

#endif

