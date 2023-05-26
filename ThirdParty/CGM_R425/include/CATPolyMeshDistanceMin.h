//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Minimal Distance Operator between two CATIPolyMesh's. Inherited from the
// generic class CATPolyDistanceMinGenericDistance.
// The distance is given by the minimum distance realized by one point
// on each mesh. One considers the triangles of each CATIPolyMesh's as
// the two sets used in the generic class
// CATPolyDistanceGenericDistance.
//
//=============================================================================
// 2009-04-06   XXC: New.
//=============================================================================

#ifndef CATPolyMeshDistanceMin_H
#define CATPolyMeshDistanceMin_H

#include "CATPolyDistanceOperators.h"
#include "CATPolyBodyDistanceMinGeneric.h"

class PolyDistanceMinMeshOper_Distance;
class CATMathBox;
class CATIPolyMesh;
class CATMathTransformation;

class ExportedByPolyhedralDistanceOperators CATPolyMeshDistanceMin : public CATPolyBodyDistanceMinGeneric
{

public:

  CATPolyMeshDistanceMin(const CATTolerance & iTol);
  virtual ~CATPolyMeshDistanceMin();

  /** Defines the poly bodies to use in each set and initialize these
   *  sets by calling the initialization of the mother generic class.
   *@param iPolyBody_diff: the distant CATPolyBody to use to define
   *the set of vertices
   *@param iPolyBody_ref: the reference CATPolyBody to use to define
   *the set of triangles
   *@param iPosition1: position of iPolyMesh1 relatively to iPolyMesh2
   *@return S_OK if the initialisation worked, E_FAIL otherwise.
   */
  virtual HRESULT Initialize(CATIPolyMesh * iPolyMesh1, CATIPolyMesh * iPolyMesh2,
                             const CATMathTransformation * iPosition1 = NULL, const CATMathTransformation * iPosition2 = NULL);
  static GenericDistanceMinOper_DataSet * BuildDetachedDataSet(CATIPolyMesh * iPolyMesh, const CATMathTransformation * iPosition = NULL);

  void Reboot();

  double GetMinimalDistance();
  HRESULT GetResults(double & MinimalDistance, CATMathPoint & P1, CATMathPoint & P2);

protected:

  /** Implementation of the abstract method used in the mother generic
   *  class. This implementation computes the minimal distance between
   *  two triangles.
   *@param iElement1: the triangle of the first set/CATPolyBody.
   *@param iElement2: the triangle of the second set/CATPolyBody.
   */
  virtual GenericDistanceMinOper_Distance * ElementToElementDistance(const GenericDistanceMinOper_Element& iElement1,
                                                                     const GenericDistanceMinOper_Element& iElement2) const;

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
  virtual HRESULT UpdateDistanceIfNeeded(const GenericDistanceMinOper_Distance & iDistance);

private:
  PolyDistanceMinMeshOper_Distance * _MinimumDistance; // Distance data for all vertices
};

#endif CATPolyMeshDistanceMin_H
