// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySpatialPartitionOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  mar 2004 Creation: dhp
//===================================================================
#ifndef CATPolySpatialPartitionOper_h
#define CATPolySpatialPartitionOper_h

#include "CATPolyBaseSpatialPartitionOper.h"

#include "CATListOfInt.h"

#include "CATListPV.h"

#include "CATMathPoint.h"
#include "CATMathBox.h"

class CATIPolyMesh;

class PartitionCell;

class CATMapOfIntToPtr;
class CATMapOfIntInt;

class CATCGMOutput;

class ExportedByCATPolyAnalyzeOperators CATPolySpatialPartitionOper : public CATPolyBaseSpatialPartitionOper
{
  
public :

  CATPolySpatialPartitionOper (const int sizeX,
    const int sizeY,
    const int sizeZ);

  ~CATPolySpatialPartitionOper (void);

  CATBoolean AddVerticesAndBars (CATIPolyMesh * polyMesh,
    const CATListOfInt & vertices,
    const CATListOfInt & barVertices0,
    const CATListOfInt & barVertices1);

  /* CATBoolean AddVertices (CATIPolyMesh * polyMesh,
    const CATListOfInt & vertices); */

  CATBoolean GetVertices (const int vertex,
    const double distance,
    CATListOfInt & vertices) const;

  CATBoolean GetBars (const int vertex,
    const double distance,
    CATListOfInt & edgeVertices0,
    CATListOfInt & edgeVertices1) const;

protected : 

  // CATBoolean InternalRun (void);

  void PrintCell (CATCGMOutput & stream,
    void * cell) const;

  CATBoolean CleanupCell (void * cell);

  CATBoolean AddVertex (const int vertex);

  CATBoolean AddBar (const int barIndex,
    const int vertex0,
    const int vertex1);

  void GetBarCells (const int vertex0,
    const int vertex1,
    CATListOfInt & cellsX,
    CATListOfInt & cellsY,
    CATListOfInt & cellsZ) const;

  CATBoolean BuildVertices (void);

  CATBoolean BuildBars (void);

  CATIPolyMesh * _polyMesh;

  CATListOfInt _vertices;
  int _numVertices;

  CATListOfInt _barVertices0;
  CATListOfInt _barVertices1;

  int _numBars;

};

#endif
