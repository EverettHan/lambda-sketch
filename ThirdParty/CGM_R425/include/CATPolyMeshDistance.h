//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Distance Operator between two CATIPolyMesh's. Inherited from the
// generic class CATPolyDistanceGenericDistance.
// The distance is given by the minimum distance from each vertex of
// the first poly mesh to the triangles in the second poly mesh. One
// considers the vertices in the first mesh and the triangles in
// the second mesh as the first set and the second set used in
// the generic class CATPolyDistanceGeneric respectively. The
// distance is recorded in the distance layer
// (CATPolyVertexDistanceLayer) associated to the first
// CATIPolyMesh.
//
//=============================================================================
// 2009-01-28   XXC: New.
// 2013-06-26   JXO: Added CATTolerance as input parameter
//=============================================================================

#ifndef CATPolyMeshDistance_H
#define CATPolyMeshDistance_H

#include "CATPolyDistanceOperators.h"
#include "CATPolyBodyDistanceGeneric.h"

#include  "CATTolerance.h"
#include "CATIAV5Level.h"
class CATMathBox;
class CATIPolyMesh;
class CATPolyMeshDistanceLayer;
#ifdef CATIAR418
class CATPolyMeshDistanceObserver;
class CATechExt;
#endif //CATIAR418

class ExportedByPolyhedralDistanceOperators CATPolyMeshDistance : public CATPolyBodyDistanceGeneric
{

public:

  /** Main class constructor.
   */
  CATPolyMeshDistance(const CATTolerance & iTol = CATGetDefaultTolerance()); // Default tolerance for MRS who uses this operator
  virtual ~CATPolyMeshDistance();

  /**
   * To make the result better, it can be computed from a larger set
   * of vertices by refining the first CATIPolyMesh by subdividing
   * long bars (triangle edges) until a given limit that corresponds
   * to the length under which a bar must not be refined. If the given
   * value is null or negative, the CATIPolyMesh is not refined. By
   * default, the resulting CATIPolyMesh is not refined.
   * Note that the length limit must be set BEFORE the initialization.
   */
  void SetRefinementLimit(double iLenghtLimit);

  /** Defines the poly Meshes to use in each set and initialize these
   *  sets by calling the initialization of the mother generic class.
   *@param iPolyMesh_diff: the distant CATIPolyMesh to use to define
   *the set of vertices
   *@param iPolyMesh_ref: the reference CATIPolyMesh to use to define
   *the set of triangles
   *@return S_OK if the initialization worked, E_FAIL otherwise.
   */
  virtual HRESULT Initialize(CATIPolyMesh * iPolyMesh_diff, CATIPolyMesh * iPolyMesh_ref);

  /** Release the distance layer, if exists, and reboot the generic
   *  polyhedral distance operator.
   */
  virtual void Reboot();

  virtual CATPolyMeshDistanceLayer * GetResult();

#ifdef CATIAR418
  virtual HRESULT Run();

   // ...
  // For internal use
public:
  inline void SetObserver (CATPolyMeshDistanceObserver* iObserver);
  inline CATPolyMeshDistanceObserver* GetObserver () const;

protected:
  CATPolyMeshDistanceObserver* _Observer;
  CATechExt * _PhoenixExtension;
#endif //CATIAR418

protected:

  /** Implementation of the pure abstract method used in the mother
   *  generic class. Computes the distance between a vertex of the
   *  first set and a triangle of the second set.
   *@param iElement1: the vertex of the first set.
   *@param iElement2: the triangle of the second set.
   */
  virtual GenericDistanceOper_Distance * ElementToElementDistance(const GenericDistanceOper_Element& iElement1,
                                                                  const GenericDistanceOper_Element_ref& iElement2) const;
  /** Implementation of the pure abstract method used in the mother
   *  generic class. Computes the distance between a vertex of the
   *  first set and box.
   *@param iElement1: the vertex of the first set.
   *@param iElement2: the bounding box.
   */
  virtual double ElementToBoxDistance(const GenericDistanceOper_Element& iElement, const CATMathBox& iBox) const;

  /** Updates the current distance data associated to a given element
   * in the first set, according to a given distance, only if
   * needed. The current distance is unchanged if the update is not
   * required.
   *@param iElement: a vertex of the first set.
   *@param iDistance: the distance.
   *@return S_OK if an update was needed and everything has gone
   *right, S_FALSE if the distance did not need to be updated, E_FAIL
   *if something has gone wrong.
   */
  virtual HRESULT UpdateDistanceIfNeeded(const GenericDistanceOper_Element * iElement,
                                         const GenericDistanceOper_Distance & iDistance);

private:
  double _RefineLimit;
  CATTolerance _Tol;

  CATPolyMeshDistanceLayer * _DistancesData; // Distance data for all vertices
};

#ifdef CATIAR418
inline void CATPolyMeshDistance::SetObserver (CATPolyMeshDistanceObserver* iObserver)
{
  _Observer = iObserver;
}

inline CATPolyMeshDistanceObserver* CATPolyMeshDistance::GetObserver () const
{
  return _Observer;
}
#endif //CATIAR418

#endif // CATPolyMeshDistance_H
