//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2014
//=============================================================================
//
// Minimal Distance Operator between a point cloud and an assembly of
// triangulated surfaces. The Point Cloud is given by a
// CAT3DPointSetKDTree and the assembly by a CATBVHTree. The result
// consists in a distance and two 3D points, the first from the Point
// Cloud, the second lying on a surface from the BVH Assembly. Only
// triangle meshes are considered in the given assembly.
//
//=============================================================================
// 2021-07-06   XXC: New. Inspired by CATPolyBodyDeviation.
//=============================================================================

#ifndef CATPolyPCAssemblyMinimalDistance_H
#define CATPolyPCAssemblyMinimalDistance_H

#include "PolyBodyDistance.h"

#include "CATListPV.h"
#include "CATListOfDouble.h"
#include "CATPolyRefCounted.h"
#include "CATMathInline.h"
#include "CATMathPoint.h"

#include "CATMapOfPtrToInt.h"
#include "CATHTableOfPtrToPtr.h"

#include "CATTolerance.h"

#include "CATPolyBodyDeviation.h"

class CATMathTransformation;
class CATPolyBoundingVolume;

class CATBVHTree;
class CATBVHNodeConst;
class CAT3DPointSetKDTree;
class Deviation_Surface;
class Deviation_Node;

class ExportedByPolyBodyDistance CATPolyPCAssemblyMinimalDistance
{
public:

  /** Main class constructor.
   *@param iToleranceForLengthTest: defines the small epsilon
   *tolerance used for length and scalar products.
   */
  CATPolyPCAssemblyMinimalDistance (const CATTolerance & iTol = CATGetDefaultTolerance ());
  ~CATPolyPCAssemblyMinimalDistance ();

  /** Option: if set to true, consider assembly surfaces as part of
   * solids with consistent orientation, distances are signed and
   * negative distance value means the point is in the interior of a
   * solid, thus the distance is null. If set to false, the distance
   * is unsigned, surfaces are considered as skins. Default is false
   * (skin meshes). Considering the inclusion detection is much more
   * costly (almost similar to deviation computation, the convergence
   * is much slower), use it with care.
   */
  inline void DetectInclusion(bool iSolidInclusion) {
    _SolidAssembly = iSolidInclusion;
  }

  inline void InitCeilingMeasure (double iCeilingMeasure) {
    _Infinite = iCeilingMeasure;
  }

  /** Set the point cloud to be used, given as a CAT3DPointSetKDTree.
   * @return Succeed if every initialization of internal data was
   * fine, fail otherwise.
   */
  HRESULT SetPointCLoud(const CAT3DPointSetKDTree & iPointCloud);

  /** Set the assembly meshes to be used, given as a CATBVHTree.
   * @return Succeed if every initialization of internal data was
   * fine, fail otherwise.
   */
  HRESULT SetAssembly(const CATBVHTree & iAssembly);

  /** Run the computation according to an optional position of the
   * overall assembly meshes. Set to null or identity for the original
   * position.
   *@return S_OK if a minimal distance has been computed, which can be
   *retrieved through method @GetResult. S_FALSE if everything was
   *fine, but no distance could computed considering the infinite
   *ceiling measure given by the CATTolerance::Infinite method in
   *constructor, or the @InitCeilingMeasure method. Fail if something
   *got wrong.
   */
  HRESULT Run (const CATMathTransformation * iSurfacePosition = NULL);

  /** Retrieves the minimal distance between a point from the point
   * cloud, and a point on a mesh from the assembly, and the position
   * of those points.
   *@return S_OK if a measure is available (if the @Run method
   *succeeded with code S_OK), E_FAIL otherwise.
   */
  HRESULT GetResult (double & oDistance, CATMathPoint & oPCNearestPoint, CATMathPoint & oAssemblyNearestPoint) const;

private:

  void ResetPC ();
  void RebootPC ();

  HRESULT Descent (const Deviation_Node & iNode, CATListPV & oChildrenNodes);

  /** Computes the distance between a small point cloud and a small
   *  mesh. Consists basically in iterating on each point then on each
   *  triangles then to computes the distance for each couple
   *  point/triangle.
   *@param iPoints: the vertices in the first set.
   *@param iMesh: the triangle of the second set.
   */
  void ElementToElementDistance (const CAT3DPointSetKDTree & iPoints, const Deviation_Surface & iMesh);

  const CATPolyBoundingVolume* GetBVHNodeBV (CATBVHNodeConst& iNode);

private:

  bool _SolidAssembly;

  double _ToleranceForLengthTest, _Infinite;
  double _CeilingMeasure;
  double * _MapKDTreeNodeToDistance;

  const CAT3DPointSetKDTree * _PointSet;
  CATBVHNodeConst * _TriangleSet;

  CATHTableOfPtrToPtr _BVHLeafToTriangles;
  CATHTableOfPtrToPtr _BVHNodeToTransformedBV;

  int _MinPointSet, _MinMap; // Contains the index

  CATPolyBodyDeviation::PolyDeviationMap * _DistancesData; // Distance data for all vertices
  const CATMathPoint ** _BarReferences;

  const CATMathTransformation * _MeshPosition;
};

#endif //CATPolyPCAssemblyMinimalDistance_H
