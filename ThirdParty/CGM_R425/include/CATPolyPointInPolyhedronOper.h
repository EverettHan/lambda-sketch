// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPointInPolyhedronOper.h
//
//===================================================================
// October 2005  Creation: ndo
//===================================================================
#ifndef CATPolyPointInPolyhedronOper_H
#define CATPolyPointInPolyhedronOper_H

#include "CATPolyAnalyzeOper.h"
#include "CATPolyAnalyzeOperators.h"
#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "CATIAV5Level.h"

class CATPolyExactArithmetic;
class CATIPolyMesh;
class CATIPolySurfaceVertexPositionConstLayer;
class CATPolyGriddedPositionsConst;
class CATIPolyMeshTriangleIterator;
class CATMathPoint;
class CATBVHNodeConst;

/**
 * This operator tests a point and reports if it is inside, on or outside a polyhedron.
 * The polyhedron must be closed with an interior and exterior.  The polyhedron is represented 
 * by a set of triangular faces (CATIPolyMesh object). It may have non-manifold bars and vertices
 * (and also degenerate triangles).
 */
class ExportedByCATPolyAnalyzeOperators CATPolyPointInPolyhedronOper : public CATPolyAnalyzeOper
{

public:

  CATPolyPointInPolyhedronOper (const CATPolyExactArithmetic& iExactArithmetic);

  CATPolyPointInPolyhedronOper (const CATIPolyMesh& iMesh,
                                CATPolyGriddedPositionsConst& iGriddedVertexPositions);

  virtual ~CATPolyPointInPolyhedronOper ();

  void SetMesh (const CATIPolyMesh* iMesh);

  /**
  * Tests if a point is inside, on or outside a polyhedron.
  * @param iPoint
  *   The point to be tested.
  * @return 
  *   -1: The point is outside the polyhedron.
  *    0: The point is on the polyhedron.
  *   +1: The point is inside the polyhedron
  */
  int IsInside (const CATMathPoint& iPoint);

  /**
  * Tests if a point is inside, on or outside the shell of a polyhedron.
  * @param iPoint
  *   The point to be tested.
  * @param iTriangleIterator
  *   An iterator going through the triangles of a shell of the polyhedron.  The shell must be closed.
  *   The shell may contain non-manifold vertices and bars.
  * @return 
  *   -1: The point is outside the polyhedron.
  *    0: The point is on the polyhedron.
  *   +1: The point is inside the polyhedron
  */
  int IsInside (const CATMathPoint& iPoint, CATIPolyMeshTriangleIterator& iTriangleIterator);

#ifdef CATIAR420
  /**
  * Tests if a point is inside, on or outside the shell of a polyhedron.
  * @param iPoint
  *   The point to be tested.
  * @param iMeshBVHNode
  *   A bounding volume hierarchy of the shell of the polyhedron. The leaves of the
  *   BVH must contain attributes of type 'CATPolyBVHAttribute'.
  * @return
  *   -1: The point is outside the polyhedron.
  *    0: The point is on the polyhedron.
  *   +1: The point is inside the polyhedron
  */
  int IsInside (const CATMathPoint& iPoint, CATBVHNodeConst& iMeshBVHNode);
#endif

public:

  // DEPRECATED.
  int IsInside (const CATMathPoint& iPoint, const CATListOfInt& iTriangles);

private:

  const CATPolyExactArithmetic& _ExactArithmetic;

  CATIPolySurfaceVertexPositionConstLayer* _PosLayer;
  CATPolyGriddedPositionsConst* _GriddedVertexPositions;

private:

  HRESULT GetVertexPosition (const int v, CATMathPoint& P) const;

  /**
  * Returns TRUE if the point P is in the triangle (A,B,C).
  * On (O,x,y), the projection of P is already assumed to be in the projected triangle.
  * The point P is also assumed to be coplanar with (A,B,C).
  */
  CATBoolean IsPointInTriangle (const CATMathPoint& P,
                                const CATMathPoint& A, const CATMathPoint& B, const CATMathPoint& C) const;

#ifdef CATIAR420
  /**
  * Descends the BVH tree and returns the list of triangles of the polyhedron that may
  * intersect the ray originating from iPoint and parallel to the z-axis in the positive
  * direction.
  */
  CATListOfInt DescendBVH (const CATMathPoint& iPoint, CATBVHNodeConst& iMeshBVHNode);
#endif

};

#endif
