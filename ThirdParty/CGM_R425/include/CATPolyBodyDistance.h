//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Distance Operator between two CATPolyBody's. Inherited from the
// generic class CATPolyDistanceGenericDistance.
// The distance is given by the minimum distance from each vertex of
// the first poly body to the triangles in the second poly body.  We
// consider the vertices in the first poly body and the triangles in
// the second poly body as the first set and the second set used in
// the generic class CATPolyDistanceGenericDistance respectively. The
// distance is recorded in the distance layer
// (CATPolyBodyVertexDistanceLayer) associated to the first
// CATPolyBody.
//
//=============================================================================
// 2009-01-28   XXC: New.
// 2013-06-26   JXO: Added CATTolerance as input parameter
//=============================================================================
#pragma once

#include "PolyBodyDistance.h"
#include "CATPolyBodyDistanceGeneric.h"

class CATTolerance;
class CATMathBox;
class CATPolyBody;

class PolyDistanceBBOper_Distance;
class CATPolyBodyVertexDistanceLayer;

class ExportedByPolyBodyDistance CATPolyBodyDistance : public CATPolyBodyDistanceGeneric
{

public:

  /** Main class constructor.
   *@param iToleranceForLengthTest: defines the small epsilon
   *tolerance used for length and scalar products.
   */
  CATPolyBodyDistance(const CATTolerance & iTol);
  virtual ~CATPolyBodyDistance();

  /**
   * To make the result better, it can be computed from a larger set
   * of vertices by refining the first CATPolyBody by subdividing long
   * bars (triangle edges) until a given limit that corresponds to the
   * length under which a bar must not be refined. If the given value
   * is null or negative, the CATPolyBody is not refined. By default, the
   * resulting CATPolyBody is not refined.
   * Note that the length limit must be set BEFORE the initialization.
   */
  void SetRefinementLimit(double iLenghtLimit) { _RefineLimit = iLenghtLimit; }

  /** Defines the poly bodies to use in each set and initialize these
   *  sets by calling the initialization of the mother generic class.
   *@param iPolyBody_diff: the distant CATPolyBody to use to define
   *the set of vertices
   *@param iPolyBody_ref: the reference CATPolyBody to use to define
   *the set of triangles
   *@return S_OK if the initialization worked, E_FAIL otherwise.
   */
  virtual HRESULT Initialize(CATPolyBody * iPolyBody_diff, CATPolyBody * iPolyBody_ref);

  virtual HRESULT Run();

  /** Release the distance layer, if exists, and reboot the generic
   *  polyhedral distance operator.
   */
  virtual void Reboot();

  virtual CATPolyBodyVertexDistanceLayer * GetResult();
  virtual double GetMin() const;
  virtual double GetMax() const;

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
  /** Computes the minimal distance between a point and a triangle
   *  given by its three vertices.
   *@param iP: the point to measure the distance to the triangle.
   *@param iP1: the first vertices of the triangle.
   *@param iP2: the second vertices of the triangle.
   *@param iP3: the third vertices of the triangle.
   *@return Data containing the squared minimum distance between the
   *point iP and the triangle, the projection of iP on the triangle
   *giving the distance, the position of this projection (on the
   *border or inside the triangle).
   */
  static PolyDistanceBBOper_Distance * 
    PointTriangleDistance(const CATMathPoint & iP, const CATMathPoint & iP1,
                          const CATMathPoint & iP2, const CATMathPoint & iP3);


private:
  double _RefineLimit;

  int _Min[2]; // Contains the indices (face then vertex) for the minimum distance data
  int _Max[2]; // Contains the indices (face then vertex) for the maximum distance data
  CATPolyBodyVertexDistanceLayer * _DistancesData; // Distance data for all vertices
};
