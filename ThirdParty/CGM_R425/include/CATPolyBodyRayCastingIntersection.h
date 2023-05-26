// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyRayCastingIntersection.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// February 2012 Creation: JXO
//===================================================================
#ifndef CATPolyBodyRayCastingIntersection_h
#define CATPolyBodyRayCastingIntersection_h

// Poly
class CATCompareElements;
#include "CATCellId.h"
#include "CATEventQueue.h"
#include "CATPolyPool.h"

// Math
#include "CATMathPoint.h"
#include "CATMathVector.h"

// System
#include "CATBoolean.h"

// ExportedBy
#include "PolyBodyBVHOperators.h"

#ifndef CATPolyBodyProjectedPoint_H
#define CATPolyBodyProjectedPoint_H
/**
 * Intersection structure:
 * It contains three points defining the intersection triangle,
 * Three normals,
 * Three barycentric coordinates.
 */
struct CATPolyBodyProjectedPoint
{
  CATMathPoint p1, p2, p3;
  CATMathVector n1, n2, n3;
  double w1, w2, w3;
};
#endif

/**
 * Class describing the intersection of one ray with the scene.
 */
class ExportedByPolyBodyBVHOperators CATPolyBodyRayCastingIntersection
{
  CATPolyDeclarePooledNew;
public:
  /** Constructor */
  CATPolyBodyRayCastingIntersection(const CATMathPoint & iOrig, int rayid = -1, double iTol = 0.);
  /** Destructor */
  ~CATPolyBodyRayCastingIntersection();

  /**
   * This method returns the number of intersections.
   */
  int GetNbOfIntersections() const;
  /**
   * Sets the iterator at the beginning. Intersections are sorted,
   * from the closest to the origin of the ray to the farthest.
   * Note that in case "negative" intersections are also reported,
   * Intersections are sorted from the most "negative" to the farthest.
   */
  CATPolyBodyRayCastingIntersection & Begin();
  /**
   * Returns TRUE if you're at the end (no result in this case), FALSE otherwise.
   */
  CATBoolean End();
  /**
   * Increments the iterator.
   */
  CATPolyBodyRayCastingIntersection & operator ++();


  /**
   * Ray id (see @CATPolyBodyRayCastingOper::CastMultipleRays)
   */
  int GetRayId();

  /**
   * Colliding PolyBody (in the BVHTreeSet) id.
   */
  int GetBodyId();

  /**
   * Colliding face index (index in polybody)
   */
  int GetFaceIndex();

  /**
   * Face Id.
   * Release after use.
   */
  CATCellId * GetFaceId();

  /**
   * Returns an intersection point, positionned in absolute referential.
   */
  CATMathPoint GetIntersectionPoint();

  /**
   * Returns the normal to the surface at the intersection point.
   */
  CATMathVector GetIntersectionNormal();

  /**
   * Returns the index of the intersecting triangle, in the intersecting poly surface.
   */
  int GetTriangleIndex();


  /**
   * Adds a new point.
   * @param iPoint Intersection point.
   * @param iNormal Normal to the surface at the intersection point.
   * @param iBodyId Id of Body in BVHTreeSet.
   * @param iCellid cell id of face. Release given cell id after this call.
   * @param iFaceIndex index of face in poly body.
   * @param iTriangleIndex index of triangle in poly surface.
   */
  void AddIntersectionPoint(const CATMathPoint & iPoint, const CATMathVector & iNormal, int iBodyId = -1, CATCellId * iCellid = 0, int iFaceIndex = -1, int iTriangleIndex = -1, CATPolyBodyProjectedPoint * pPoint = 0);

  /** @nodoc */
  HRESULT GetTrianglePoints(CATMathPoint & oP1, CATMathPoint & oP2, CATMathPoint & oP3);
  /** @nodoc */
  HRESULT GetTriangleNormals(CATMathVector & oN1, CATMathVector & oN2, CATMathVector & oN3);
  /** @nodoc */
  HRESULT GetTriangleWs(double & oW1, double & oW2, double & oW3);

private:
  CATCompareElements & m_Compare;
  CATEventQueue m_Points;
  CATEventQueue::Iterator m_Iterator;
  int m_RayId;
};

#endif
