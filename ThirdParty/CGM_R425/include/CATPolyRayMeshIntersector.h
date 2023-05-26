//=============================================================================
// COPYRIGHT Dassault Systemes 2007
//=============================================================================
//
// CATPolyRayMeshIntersector.h
//
// Compute the intersection between a 3D ray and a triangular mesh.
//
//=============================================================================
// 2007-07-09   BPG: New.
//=============================================================================
#ifndef CATPolyMeshPointDistance_H
#define CATPolyMeshPointDistance_H

#include "CATErrorDef.h"

#include "CATPolyRayTriangleIntersector.h"

//
class CATMathPoint;

class CATIPolyMesh;
class CATIPolyMeshTriangleIterator;

class CATPolyRayMeshIntersectorAccelerator;

//
#include "CATPolyMeshIntersectors.h"

/** Operator computing the distance between a 3D point and a CATIPolyMesh.
 */
class ExportedByCATPolyMeshIntersectors CATPolyRayMeshIntersector
{
  // --------------------------------------------------------------------------
  /** @name Life-cycle
      @{ */
public:
  /** Create an instance of CATPolyRayMeshIntersector.

      @param iEpsilonForLengthTest See CATPolyRayTriangleIntersector.
  */
  inline CATPolyRayMeshIntersector(double iEpsilonForLengthTest);
  /** @} */

  // --------------------------------------------------------------------------
  /** @name Computation
      @{ */
public:
  /** Auxiliary class describing the result of a 3D point to mesh distance computation
   */
  class Result
  {
  public:
    inline Result();

  public:
    /** Return the triangle of the mesh realizing the minimal distance. */
    inline int GetTriangle() const;
    /** Return the description of the point on the triangle realizing the
        minimal distance. */
    inline const CATPolyRayTriangleIntersector::Result &GetTriangleIntersectorResult() const;

  protected:
    friend class CATPolyRayMeshIntersector;

    int _t;
    CATPolyRayTriangleIntersector::Result _RTIResult;
  };

public:
  /** Compute the intersection between a ray and a mesh.
   
      @param iOrigin The origin of the ray

      @param iDirection The direction of the ray
   
      @param iMesh The mesh
      
      @param iTriangleIt An iterator on the (sub)set of mesh triangles to consider
   
      @param oResult Result slot which will be filled with the nearest triangles
   
      @return On success, return S_OK when at least one triangle satisfying the
      conditions could be found, S_FALSE otherwise. On internal error, return
      E_FAIL or E_OUTOFMEMORY.
  */
  HRESULT Run(const CATMathPoint &iOrigin, const CATMathVector &iDirection,
              const CATIPolyMesh &iMesh, CATIPolyMeshTriangleIterator &iTriangleIt,
              CATPolyRayMeshIntersector::Result &oResult) const;

public:
  /** Compute the distance between a 3D point and a mesh using an accelerator.
   
      This is the recommended way when the usage pattern is "several 3D points
      being compared to one constant mesh". See also
      CATPolyRayMeshIntersectorAccelerator to understand how to build one.
   
      @param iP The 3D point
   
      @param iAccelerator The accelerator
   
      @param oResult Result slot which will be filled with the nearest triangles
   
      @return On success, return S_OK when at least one triangle satisfying the
      conditions could be found, S_FALSE otherwise. On internal error, return
      E_FAIL or E_OUTOFMEMORY.
  */
  HRESULT Run(const CATMathPoint &iOrigin, const CATMathVector &iDirection,
              const CATPolyRayMeshIntersectorAccelerator &iAccelerator,
              CATPolyRayMeshIntersector::Result &oResult) const;
  /** @} */

protected:
  const double _EpsilonForLengthTest;
};

// ----------------------------------------------------------------------------

//
inline
CATPolyRayMeshIntersector::Result::Result():
  _t(0)
{}

inline int
CATPolyRayMeshIntersector::Result::GetTriangle() const
{
  return _t;
}

inline const CATPolyRayTriangleIntersector::Result &
CATPolyRayMeshIntersector::Result::GetTriangleIntersectorResult() const
{
  return _RTIResult;
}

//

inline
CATPolyRayMeshIntersector::CATPolyRayMeshIntersector(double iEpsilonForLengthTest):
  _EpsilonForLengthTest(iEpsilonForLengthTest)
{}

#endif // !CATPolyRayMeshIntersector_H
