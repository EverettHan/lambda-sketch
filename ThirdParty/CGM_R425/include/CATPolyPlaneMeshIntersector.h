// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPlaneMeshIntersector.h
// Header definition of CATPolyPlaneMeshIntersector
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// March 2006 Creation: ndo
//===================================================================
#ifndef CATPolyPlaneMeshIntersector_H
#define CATPolyPlaneMeshIntersector_H

#include "CATPolyMeshIntersectors.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATLib.h"          // Definition of NULL.
#include "CATMathPoint.h"
#include "CATMathVector.h"

class CATIPolyMesh;
class CATPolyIntersectionPoint;
class CATPolyBooleanSegments1;
class CATMathPlane;


class ExportedByCATPolyMeshIntersectors CATPolyPlaneMeshIntersector
{

public :

  CATPolyPlaneMeshIntersector ();
  ~CATPolyPlaneMeshIntersector ();

  /**
  * Test whether a plane intersects with a mesh and calculate their intersection.
  * The method returns an enum describing the intersection (See CATPolyIntersection).
  * @param iPlane
  *   The input plane.
  * @param iMesh
  *   The input mesh. 
  * @return
  *   An integer describing the intersection between the plane and the mesh,
  *   (See CATPolyIntersection::IntersectionType):
  *     CATPolyIntersection::eUndetermined:       Undetermined intersection.
  *     CATPolyIntersection::eNoIntersection:     No intersection.
  *     CATPolyIntersection::ePointIntersection:  Point intersection.
  *     CATPolyIntersection::eIntersection:       Intersection other than just point intersections.
  */
  int Intersect (const CATMathPlane& iPlane, const CATIPolyMesh& iMesh);

  /* Returns the intersection segments between the plane and the mesh.
  *  The triangles that are coplanar with the plane are not reported.
  */
  const CATPolyBooleanSegments1* GetIntersectionSegments () const;

protected :

  const CATIPolyMesh* _Mesh;

  // Definition of the plane.
  CATMathPoint _Origin;    // Origin of the plane.
  CATMathVector _Normal;   // Normal to the plane.
  int _MainAxis;                   // Axis the closest to the direction (signed).

  CATPolyBooleanSegments1* _IntersectionSegments;

  int ComputeVertexPosition (const CATMathPoint& iPoint) const;
  HRESULT ComputeVertexPositions (int*& oVertexPositions) const;

  void AddSegment (const CATPolyIntersectionPoint& I, const CATPolyIntersectionPoint& J);
  int CompareNormals (const int iVertices[3]) const;

};

#endif

