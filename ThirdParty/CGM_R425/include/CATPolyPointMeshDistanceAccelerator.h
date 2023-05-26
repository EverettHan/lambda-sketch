//=============================================================================
// COPYRIGHT Dassault Systemes 2007
//=============================================================================
//
// CATPolyMeshPointDistanceAccelerator.h
//
// Helper to accelerate distance computation when many 3D point are confronted
// to the same constant CATIPolyMesh.
//
//=============================================================================
// 2007-06-19   BPG: New.
//=============================================================================
#ifndef CATPolyMeshPointDistanceAccelerator_H
#define CATPolyMeshPointDistanceAccelerator_H

#include "CATErrorDef.h"

#include "CATMathBox.h"
#include "CATListOfInt.h"

#include "CATPolyPointMeshDistance.h"

//
class CATMathPoint;
class CATIPolyMesh;
class CATIPolyMeshTriangleIterator;
class CATPolySPOctreePartition;
class CATPolySPOctreeNode;

//
#include "CATPolySpatialPartitions.h"
class ExportedByCATPolySpatialPartitions CATPolyPointMeshDistanceAccelerator
{
protected:
  CATPolyPointMeshDistanceAccelerator(const CATIPolyMesh &Mesh, CATPolySPOctreePartition *Octree, double VoxelSize);
public:
  ~CATPolyPointMeshDistanceAccelerator();

  static CATPolyPointMeshDistanceAccelerator *New(const CATIPolyMesh &iMesh, CATIPolyMeshTriangleIterator &iTriangleIt);

public:
  inline const CATIPolyMesh &GetMesh() const;

public:
  HRESULT Run(const CATPolyPointMeshDistance &PointMeshDistance,
              const CATMathPoint &iP,
              CATPolyPointMeshDistance::Result &oResult) const;

protected:
  HRESULT RunOnTriangles(const CATPolyPointMeshDistance &PointMeshDistance,
                         CATPolySPOctreeNode &iNode, const CATMathBox &iNodeBBox, CATListOfInt ioTestedTriangles,
                         const CATMathPoint &iP, double &ioSquareRadius,
                         CATPolyPointMeshDistance::Result &oResult) const;

protected:
  inline CATBoolean IntersectP(const CATMathBox &iBBox, const CATMathPoint &iP, double iSquareRadius) const;
  CATBoolean BoxInSphereP(const CATMathBox &iBBox, const CATMathPoint &iP, double iSquareRadius) const;

protected:
  const CATIPolyMesh &_Mesh;
  CATPolySPOctreePartition *_Octree;
  const double _VoxelSize;
};

// ----------------------------------------------------------------------------

inline const CATIPolyMesh &
CATPolyPointMeshDistanceAccelerator::GetMesh() const
{
  return _Mesh;
}

#endif // !CATPolyMeshPointDistanceAccelerator_H
