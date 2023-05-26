//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Minimal Distance Operator between two CATPolyBody's. Inherited from the
// generic class CATPolyDistanceMinGenericDistance.
// The distance is given by the minimum distance realized by one point
// on each body. We consider the triangles of each CATPolyBody's as
// the two sets used in the generic class
// CATPolyDistanceGenericDistance.
//
//=============================================================================
// 2009-01-28   XXC: New.
//=============================================================================
#pragma once

#include "PolyBodyDistance.h"
#include "CATPolyBodyDistanceMinGeneric.h"

class PolyDistanceMinBBOper_Distance;
class CATMathBox;
class CATPolyBody;


class ExportedByPolyBodyDistance CATPolyBodyDistanceMin : public CATPolyBodyDistanceMinGeneric
{

public:

  CATPolyBodyDistanceMin(const CATTolerance & iTol);
  virtual ~CATPolyBodyDistanceMin();

  /** Defines the poly bodies to use in each set and initialize these
   *  sets by calling the initialization of the mother generic class.
   *@param iPolyBody_diff: the distant CATPolyBody to use to define
   *the set of vertices
   *@param iPolyBody_ref: the reference CATPolyBody to use to define
   *the set of triangles
   *@return S_OK if the initialisation worked, E_FAIL otherwise.
   */
  virtual HRESULT Initialize(CATPolyBody * iPolyBody1, CATPolyBody * iPolyBody2);

  static GenericDistanceMinOper_DataSet * BuildDetachedDataSet(CATPolyBody * iPolyBody);

  void Reboot();

  double GetMinimalDistance();
  HRESULT GetResults(double & MinimalDistance, CATMathPoint & P1, CATMathPoint & P2);

  static void DistanceTriangleTriangle(const CATMathPoint A[3], const CATMathPoint B[3],
                                       double & oDistance, CATMathPoint & oA, CATMathPoint & oB);

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
  PolyDistanceMinBBOper_Distance * _MinimumDistance; // Distance data for all vertices
};
