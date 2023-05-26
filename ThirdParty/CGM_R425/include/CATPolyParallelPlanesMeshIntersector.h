// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyParallelPlanesMeshIntersector.h
//
//===================================================================
// June 2008 Creation: ndo
//===================================================================
#ifndef CATPolyParallelPlanesMeshIntersector_H
#define CATPolyParallelPlanesMeshIntersector_H

#include "CATPolyMeshIntersectors.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMapOfIntToInt.h"


class CATIPolyMesh;
class CATIPolySurfaceVertexIterator;
class CATIPolySurfaceVertexPositionConstLayer;
class CATPolyIntersectionPoint;
class CATMathTransformation;
class CATMathPlane;

class CATPolyExactArithmetic;
class CATPolyBooleanOper2D;
class CATPolyPolygonVertex3DPositionLayer;
class CATPolyPolygonBarSurfaceLayer;
class CATMathPoint;
class CATMathPoint2D;
class CATPolyVertex2D;
class CATPolyBar2D;


/*
* This operator computes the intersection between a mesh and a plane.
* It can be called efficiently repeatedly for a series of parallel planes.
* There is no need of an instance of exact arithmetic for the operator except for construction of a section result
* (polygon 2D).
*/
class ExportedByCATPolyMeshIntersectors CATPolyParallelPlanesMeshIntersector
{

public :

  CATPolyParallelPlanesMeshIntersector (const CATMathVector& iDirection,
    const CATIPolyMesh& iMesh, const CATMathTransformation* iMeshPosition = 0,
    bool iIsVolume = false,
    unsigned int iFaceID = 0);

  ~CATPolyParallelPlanesMeshIntersector ();

  /**
   * Set the half thickness of the plane.  All points within that distance to the plane will be considered on the plane.
   * By default, the plane does not have a thickness.
   */
  inline void SetHalfThickness (const double iHalfThickness);

public:

  class PolygonBuilder
  {
  public:

    virtual HRESULT AddVertex (const CATMathPoint& iPoint, int iVertex1, int iVertex2, CATPolyVertex2D*& oVertex) = 0;

    virtual HRESULT AddBar (CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1, int iTriangle,
      int iMultiplicity, CATPolyBar2D*& oBar) = 0;

  };

  // Construct a default PolygonBuiler based on CATPolyBooleanOper2D.
  PolygonBuilder* NewDefaultBooleanBuilder (const CATMathVector& iDirection,
    const CATIPolyMesh& iMesh,
    const CATPolyExactArithmetic* iExactArithmetic,
    CATPolyBooleanOper2D& iBooleanOper,
    CATPolyPolygonVertex3DPositionLayer& iVertexPositionLayer,
    CATPolyPolygonBarSurfaceLayer& iBarSurfaceLayer,
    unsigned int iFaceID = 0);

public:

  /**
  * Test whether a plane going through a point and parallel to the direction
  * intersects with a mesh.
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
  * intersects with a mesh.  The intersection data is fed to a boolean operator.
  * After addition of all the data to the boolean operator, it should be run in the union mode 
  * (CATPolyBooleanOper2D::eBooleanUnion) for volume data and in the default mode
  * for surfaces (CATPolyBooleanOper2D::eBooleanNone). Upon a successful run, a valid polygon representing the 
  * intersection is constructed.
  * The method returns an enum describing the intersection (See CATPolyIntersection).
  * @param iOriginOfPlane
  *   A point in the plane.
  * @param iExactArithmetic
  *   An instance of exact arithmetic required for robust computation of the polygon 2D using the boolean operator.
  *   Note that the 3D coordinates of the vertices in the position layer are NOT gridded.
  * @param iPolygonBuilder
  *   An operator to which the intersection points and segments are added with the correct multiplicity:
  *   For example: CATPolyBooleanOper2D or CATPolyPolygonWNBuilder2D.
  *   This operator encapsulates a CATPolyPolygon2D operand.
  * @param iVertexPositionLayer
  *   A layer of true 3D positions of the intersection vertices.
  * @param iBarSurfaceLayer
  *   A layer of surface support of the intersection bars.  The surface support is the input mesh.
  * @return
  *   An integer describing the intersection between the plane and the mesh,
  *   (See CATPolyIntersection::IntersectionType):
  *     CATPolyIntersection::eUndetermined:       Undetermined intersection.
  *     CATPolyIntersection::eNoIntersection:     No intersection.
  *     CATPolyIntersection::ePointIntersection:  Point intersection.
  *     CATPolyIntersection::eIntersection:       Intersection other than just point intersections.
  */
  int Intersect (const CATMathPoint& iOriginOfPlane,
    PolygonBuilder& iPolygonBuilder);

  int Intersect (const CATMathPoint& iOrigin,
    const CATPolyExactArithmetic& iExactArithmetic,
    CATPolyBooleanOper2D& iBooleanOper,
    CATPolyPolygonVertex3DPositionLayer& iVertexPositionLayer,
    CATPolyPolygonBarSurfaceLayer& iBarSurfaceLayer);

private:

  CATMathVector _Direction;        // Direction of the planes.
  int _MainAxis;                   // Axis the closest to the direction (signed).
  const unsigned int _FaceID;

  const CATIPolyMesh& _Mesh;
  const CATMathTransformation* _MeshPosition;
  CATIPolySurfaceVertexIterator* _VertexIterator;
  CATIPolySurfaceVertexPositionConstLayer* _VertexPositionLayer;

  bool _IsVolume;

  CATMapOfIntToInt _MapVertexToIndex;  // Mapping of vertices to indices in contiguous and compact arrays.

  double _HalfThickness;       // Half-thickness of the plane.
  double* _ReferenceDistances; // Distance of the vertices to the plane going through the origin. (Compact.)
  char* _VertexPositions;      // Position of the vertices w.r.t. the plane (-1, 0 or +1). (Compact.)

private:

  // Return the position of a vertex of the mesh.
  void GetVertexPosition (const int v, CATMathPoint& P) const;

  void ComputeReferenceDistances ();
  HRESULT ComputeVertexPositions (const CATMathPoint& iOrigin);

  int CompareNormals (const int vertices[]) const;

  HRESULT AddVertex (const CATPolyIntersectionPoint& iIntersectionPoint,
    const CATMathPlane& iPlane,
    int vertices[],
    PolygonBuilder& iPolygonBuilder,
    CATPolyVertex2D*& vertex) const;

  HRESULT AddBar (const CATPolyIntersectionPoint& I,
    const CATPolyIntersectionPoint& J,
    CATPolyVertex2D* vertexI,
    CATPolyVertex2D* vertexJ,
    int t,  // Index of the triangle.
    PolygonBuilder& iPolygonBuilder) const;

};


inline void CATPolyParallelPlanesMeshIntersector::SetHalfThickness (const double iHalfThickness)
{
  _HalfThickness = iHalfThickness;
}

#endif
