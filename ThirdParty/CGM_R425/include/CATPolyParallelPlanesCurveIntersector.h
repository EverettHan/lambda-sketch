// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyParallelPlanesCurveIntersector.h
//
//===================================================================
//
// October 2009 Creation: ndo
//===================================================================
#ifndef CATPolyParallelPlanesCurveIntersector_H
#define CATPolyParallelPlanesCurveIntersector_H

#include "CATPolyMeshIntersectors.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATMathPoint.h"
#include "CATMathVector.h"


class CATIPolyCurve;
class CATIPolyCurveVertexIterator;
class CATPolyIntersectionPoint;
class CATMathTransformation;
class CATMathPlane;

class CATPolyExactArithmetic;
class CATPolyPolygon2D;
class CATPolyPolygonVertex3DPositionLayer;
class CATPolyVertex2D;


/*
* This operator computes the intersection between a curve and a plane.
* It can be called efficiently repeatedly for a series of parallel planes.
* There is no need of an instance of exact arithmetic for the operator except for construction of a section result
* (polygon 2D).
*/
class ExportedByCATPolyMeshIntersectors CATPolyParallelPlanesCurveIntersector
{

public :

  CATPolyParallelPlanesCurveIntersector (const CATMathVector& iDirection, 
                                         const CATIPolyCurve& iCurve, const CATMathTransformation* iCurvePosition = 0);

  ~CATPolyParallelPlanesCurveIntersector ();

  /**
  * Test whether a plane going through a point and parallel to the direction
  * intersects with a curve.
  * The method returns an enum describing the intersection (See CATPolyIntersection).
  * @param iOriginOfPlane
  *   A point in the plane.
  * @return
  *   An integer describing the intersection between the plane and the mesh,
  *   (See CATPolyIntersection::IntersectionType):
  *     CATPolyIntersection::eUndetermined:       Undetermined intersection.
  *     CATPolyIntersection::eNoIntersection:     No intersection.
  *     CATPolyIntersection::ePointIntersection:  Point intersection.
  *     CATPolyIntersection::eIntersection:       Intersection other than just point intersections.
  */
  int Intersect (const CATMathPoint& iOriginOfPlane);

  /**
  * Test whether a plane going through a point and parallel to the direction
  * intersects with a mesh.  The intersection data is fed to a polygon.
  * Upon a successful run, a valid polygon representing the intersection is constructed.
  * The method returns an enum describing the intersection (See CATPolyIntersection).
  * @param iOriginOfPlane
  *   A point in the plane.
  * @param iExactArithmetic
  *   An instance of exact arithmetic required for robust computation of the polygon 2D using the boolean operator.
  *   Note that the 3D coordinates of the vertices in the position layer are NOT gridded.
  * @param iPolygon
  *   The polygon operand to which are added the vertices and the bars.
  * @param iVertexPositionLayer
  *   A layer of true 3D positions of the intersection vertices.
  * @return
  *   An integer describing the intersection between the plane and the mesh,
  *   (See CATPolyIntersection::IntersectionType):
  *     CATPolyIntersection::eUndetermined:       Undetermined intersection.
  *     CATPolyIntersection::eNoIntersection:     No intersection.
  *     CATPolyIntersection::ePointIntersection:  Point intersection.
  *     CATPolyIntersection::eIntersection:       Intersection other than just point intersections.
  */
  int Intersect (const CATMathPoint& iOriginOfPlane,
                 const CATPolyExactArithmetic& iExactArithmetic,
                 CATPolyPolygon2D& iPolygon,
                 CATPolyPolygonVertex3DPositionLayer& iVertexPositionLayer);

private:

  CATMathVector _Direction;        // Direction of the planes.
  int _MainAxis;                   // Axis the closest to the direction (signed).

  const CATIPolyCurve& _Curve;
  const CATMathTransformation* _CurvePosition;
  CATIPolyCurveVertexIterator* _VertexIterator;

  double* _ReferenceDistances; // Distance of the vertices to the plane going through the origin. (Compact.)
  char* _VertexPositions;      // Position of the vertices w.r.t. the plane (-1, 0 or +1). (Compact.)

private:

  // Return the position of a vertex of the curve.
  void GetVertexPosition (const int v, CATMathPoint& P) const;

  void ComputeReferenceDistances ();
  HRESULT ComputeVertexPositions (const CATMathPoint& iOrigin);

  HRESULT ConstructIntersectionPoint (const CATPolyIntersectionPoint& iIntersectionPoint,
                                      const CATMathPlane& iPlane,
                                      int vertices[],
                                      CATMathPoint& oPoint) const;

  HRESULT AddVertex (const CATPolyIntersectionPoint& iIntersectionPoint,
                     const CATMathPlane& iPlane,
                     int vertices[],
                     const CATPolyExactArithmetic& iExactArithmetic,
                     CATPolyPolygon2D& iPolygon,
                     CATPolyPolygonVertex3DPositionLayer& iVertexPositionLayer,
                     CATPolyVertex2D*& vertex) const;

};

#endif
