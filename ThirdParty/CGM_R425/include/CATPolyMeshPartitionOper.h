// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshPartitionOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  sep 2004 Creation: dhp
//===================================================================
#ifndef CATPolyMeshPartitionOper_h
#define CATPolyMeshPartitionOper_h

#include "CATPolyBaseSpatialPartitionOper.h"

#include "CATListOfInt.h"

#include "CATListPV.h"

#include "CATMathPoint.h"
#include "CATMathBox.h"

class CATIPolyMesh;
class CATPolyGriddedPositionsConst;

class CATHTableOfIntToPtr;
class CATBucketsOfInt;
class CATSetOfInt;

//#define DEBUG_MESH_PARTITION

#ifdef DEBUG_MESH_PARTITION
class CATCGMOutput;
#endif


class ExportedByCATPolyAnalyzeOperators CATPolyMeshPartitionOper : public CATPolyBaseSpatialPartitionOper
{
  
public :

  CATPolyMeshPartitionOper (const int sizeX,
    const int sizeY,
    const int sizeZ);

  ~CATPolyMeshPartitionOper (void);

  HRESULT AddMesh (const CATIPolyMesh * polyMesh, const CATPolyGriddedPositionsConst* iGriddedVertexPositions = 0);

  HRESULT RemoveMesh (const CATIPolyMesh * polyMesh);

  // Add a triangle to the partition.

  CATBoolean AddTriangle (const CATIPolyMesh * mesh, const int triangle);
  CATBoolean AddTriangles (const CATIPolyMesh * mesh, const CATListOfInt & triangles);

  // Remove a triangle from the partition.

  CATBoolean RemoveTriangle (const CATIPolyMesh * mesh, const int triangle);
  CATBoolean RemoveTriangles (const CATIPolyMesh * mesh, const CATListOfInt & triangles);

  CATBoolean ReplaceTriangle (const CATIPolyMesh * mesh, const int triangle, const CATListOfInt & triangles);

  // Get the triangles in the specified cell. Return true
  // if x, y, and z are in the proper bounds and the cell
  // contains triangles.

  CATBoolean GetTriangles (const int polyMeshIndex,
    const int x,
    const int y,
    const int z,
    CATListOfInt & triangles) const;

  CATBoolean UpdateTriangleIndices (const CATIPolyMesh * polyMesh, const CATBucketsOfInt & map);

  CATBoolean ResetTrianglePairIterator () ;
  CATBoolean ResetTrianglePairIterator (const CATIPolyMesh * mesh) ;

  CATBoolean GetNextTrianglePair (int & triangle0, int & triangle1);

  // Given a distance, return all pairs of triangles (from same mesh
  // but not direct neighbors) that are within the specified distance.

  CATBoolean GetTrianglePairsFromDistance (const double distance,
    CATListOfInt & triangles0,
    CATListOfInt & triangles1) const;

#ifdef DEBUG_MESH_PARTITION
  void Dump (CATCGMOutput & stream) const;

  void GetCellsFromTriangle (const CATIPolyMesh * polyMesh,
    const int triangle,
    CATListOfInt & cellsX,
    CATListOfInt & cellsY,
    CATListOfInt & cellsZ) const;
#endif

protected :

  HRESULT GetVertexPosition (const CATIPolyMesh * polyMesh, const int v, CATMathPoint& P) const;

  // Return pairs of potentially interesting triangles. The lists are generated
  // by retrieving all cells that contain triangles from both meshes. For each
  // cell, all pairs of triangles are generated and appended to the list.
  //
  // The lists are cleared before generating the pairs. The lists will
  // be the same size after the pairs have been generated.

  CATBoolean GetTrianglePairs (CATListOfInt & triangles0,
    CATListOfInt & triangles1) const;

  CATBoolean GetTrianglePairs (const int iMesh,
    CATListOfInt & triangles0,
    CATListOfInt & triangles1) const;

#ifdef DEBUG_MESH_PARTITION
  void PrintCell (CATCGMOutput & stream,
    void * cell) const;
#endif

  CATBoolean CleanupCell (void * cell);

  CATBoolean SetupMesh (const CATIPolyMesh * polyMesh);

  CATSetOfInt* GetTriangleSet (const CATIPolyMesh * polyMesh) const;

  CATHTableOfIntToPtr * GetTriangleCellMap (const CATIPolyMesh * polyMesh) const;

  CATBoolean GetTriangleCells (const CATMathPoint & p0,
    const CATMathPoint & p1,
    const CATMathPoint & p2,
    CATListOfInt & cellsX,
    CATListOfInt & cellsY,
    CATListOfInt & cellsZ) const;

  int GetPolyMeshIndex (const CATIPolyMesh * polyMesh) const;

  CATBoolean GetCellsOneMesh (const int iMesh,
    CATListOfInt & cellsX,
    CATListOfInt & cellsY,
    CATListOfInt & cellsZ) const;

  CATBoolean GetCellsTwoMeshes (CATListOfInt & cellsX,
    CATListOfInt & cellsY,
    CATListOfInt & cellsZ) const;

  void InvalidateTrianglePairs (void);

  const CATIPolyMesh * _polyMesh0;
  const CATIPolyMesh * _polyMesh1;

  const CATPolyGriddedPositionsConst* _GriddedVertexPositions0;
  const CATPolyGriddedPositionsConst* _GriddedVertexPositions1;

  CATSetOfInt* _TriangleSet0;
  CATSetOfInt* _TriangleSet1;

  CATHTableOfIntToPtr * _triangleCellMap0;
  CATHTableOfIntToPtr * _triangleCellMap1;

  CATListOfInt _trianglePairs0;
  CATListOfInt _trianglePairs1;

  int _trianglePairIndex;

};

#endif

