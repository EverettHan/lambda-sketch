//=============================================================================
// COPYRIGHT Dassault Systemes 2007
//=============================================================================
//
// CATPolyPointMeshDistance.h
//
// Compute the distance between a 3D point and a CATIPolyMesh.
//
//=============================================================================
// 2007-06-19   BPG: New.
//=============================================================================
#ifndef CATPolyMeshPointDistance_H
#define CATPolyMeshPointDistance_H

#include "CATErrorDef.h"
#include "CATPolyPointTriangleDistance.h"
#include "CATIAV5Level.h"

//
class CATMathPoint;

class CATIPolyMesh;
class CATIPolyMeshTriangleIterator;

class CATPolyPointMeshDistanceAccelerator;

#ifdef CATIAR418
class CATPolyPointMeshDistanceObserver;
class CATechExt;
#endif //CATIAR418

//
#include "CATPolyMeshIntersectors.h"

/** Operator computing the distance between a 3D point and a CATIPolyMesh.
 */
class ExportedByCATPolyMeshIntersectors CATPolyPointMeshDistance
{
  // --------------------------------------------------------------------------
  /** @name Life-cycle
      @{ */
public:
  /** Create an instance of CATPolyPointMeshDistance.

      @param iResolutionForLengthTest See CATPolyPointTriangleDistance.

      @param iEpsilonForLengthTest See CATPolyPointTriangleDistance.
  */
  CATPolyPointMeshDistance(double iResolutionForLengthTest, double iEpsilonForLengthTest);
  virtual ~CATPolyPointMeshDistance();
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

    inline void Invalidate ();

  public:
    /** Return the triangle of the mesh realizing the minimal distance. */
    inline int GetTriangle() const;
    /** Return the description of the point on the triangle realizing the
        minimal distance. */
    inline const CATPolyPointTriangleDistance::Result &GetTriangleDistanceResult() const;

  protected:
    friend class CATPolyPointMeshDistance;

    int _t;
    CATPolyPointTriangleDistance::Result _TDResult;
  };

public:
  /** Compute the distance between a 3D point and a mesh.
   
      @param iP The 3D point
   
      @param iMesh The mesh
      
      @param iTriangleIt An iterator on the set of mesh triangles to consider
   
      @param oResult Result slot which will be filled with the nearest triangles
   
      @return On success, return S_OK when at least one triangle satisfying the
      conditions could be found, S_FALSE otherwise. On internal error, return
      E_FAIL or E_OUTOFMEMORY.
  */
  HRESULT Run(const CATMathPoint &iP, const CATIPolyMesh &iMesh, CATIPolyMeshTriangleIterator &iTriangleIt,
              CATPolyPointMeshDistance::Result &oResult) const;

public:
  /** Compute the distance between a 3D point and a mesh using an accelerator.
   
      This is the recommended way when the usage pattern is "several 3D points
      being compared to one constant mesh". See also
      CATPolyPointMeshDistanceAccelerator to understand how to build one.
   
      @param iP The 3D point
   
      @param iAccel The accelerator
   
      @param oResult Result slot which will be filled with the nearest triangles
   
      @return On success, return S_OK when at least one triangle satisfying the
      conditions could be found, S_FALSE otherwise. On internal error, return
      E_FAIL or E_OUTOFMEMORY.
  */
  HRESULT Run(const CATMathPoint &iP, const CATPolyPointMeshDistanceAccelerator &iAccel,
              CATPolyPointMeshDistance::Result &oResult) const;
  /** @} */

protected:
  const double _ResolutionForLengthTest;
  const double _EpsilonForLengthTest;

#ifdef CATIAR418
  // For internal use
public:
  inline void SetObserver (CATPolyPointMeshDistanceObserver* iObserver);
  inline CATPolyPointMeshDistanceObserver* GetObserver () const;

protected:
  CATPolyPointMeshDistanceObserver* _Observer;
  CATechExt * _PhoenixExtension;
#endif //CATIAR418
};

// ----------------------------------------------------------------------------

//
inline
CATPolyPointMeshDistance::Result::Result():
  _t(0)
{}

inline void CATPolyPointMeshDistance::Result::Invalidate ()
{
  _t = 0;
  _TDResult.Invalidate ();
}

inline int
CATPolyPointMeshDistance::Result::GetTriangle() const
{
  return _t;
}

inline const CATPolyPointTriangleDistance::Result &
CATPolyPointMeshDistance::Result::GetTriangleDistanceResult() const
{
  return _TDResult;
}

//
#ifdef CATIAR418
inline void CATPolyPointMeshDistance::SetObserver (CATPolyPointMeshDistanceObserver* iObserver)
{
  _Observer = iObserver;
}

inline CATPolyPointMeshDistanceObserver* CATPolyPointMeshDistance::GetObserver () const
{
  return _Observer;
}
#endif //CATIAR418

#endif // !CATPolyPointMeshDistance_H
