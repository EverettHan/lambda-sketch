// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMPointTopoUtil.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Apr 2005 Creation: ndo
//===================================================================
#ifndef CATPolyMPointTopoUtil_h
#define CATPolyMPointTopoUtil_h

#include "CATPolyMiscellaneous.h"
#include "CATErrorDef.h"     // HRESULT definition
#include "CATBoolean.h"
#include "CATListOfInt.h"

class CATIPolyMesh;
class CATPolyMPointTopo;


class ExportedByCATPolyMiscellaneous CATPolyMPointTopoUtil 
{
public :

  /**
  * Constructor.
  */
	CATPolyMPointTopoUtil (const CATIPolyMesh * polyMesh);

  /**
  * Destructor.
  */
	~CATPolyMPointTopoUtil (void);

  /**
  * Tests if a mesh point is on a hole.
  * @param meshPoint
  *   The mesh point to test.
  * @return
  *   TRUE if the mesh point is on a hole and FALSE otherwise.
  */
  CATBoolean IsHoleMeshPoint (const CATPolyMPointTopo& meshPoint);

  /**
  * Given a valid mesh point, returns a triangle that the mesh point is part of.
  * @param meshPoint
  *   A mesh point.
  * @return
  *   The triangle to which the mesh point belongs.  (One of the triangle to which the mesh point belongs if 
  *   the mesh point is a bar point or a vertex point.)
  */
  HRESULT GetTriangle (const CATPolyMPointTopo& meshPoint, int & returnTriangle);

  /**
  * Tests if the two mesh points are topologically in the same triangle.
  * @param meshPoint0
  *   The first meshpoint.
  * @param meshPoint1
  *   The second meshpoint.
  * @return
  *   The triangle number if the two mesh points are in the same triangle and
  *   0 otherwise.
  */
  // Different behavior compared to IsSegmentOnTriangle ().
  HRESULT SameTriangle (const CATPolyMPointTopo& meshPoint0, const CATPolyMPointTopo& meshPoint1,
                        int& returnTriangle);

  HRESULT SameTriangle (const CATPolyMPointTopo& meshPoint0, const CATPolyMPointTopo& meshPoint1);

  /** 
  * Given two mesh points, check if the two points are on a same and unique bar.
  * @param meshPoint0
  *   The first mesh point.
  * @param meshPoint1
  *   The second mesh point.
  * @param oBarVertex0
  *   The first vertex of the bar if found otherwise 0.
  * @param oBarVertex1
  *   The second vertex of the bar if found otherwise 0.
  * @return
  *   TRUE if the two mesh points are on the same and unique bar.
  *   FALSE otherwise.
  */
  CATBoolean IsSegmentOnBar (const CATPolyMPointTopo& meshPoint0, const CATPolyMPointTopo& meshPoint1,
                             int& oBarVertex0, int& oBarVertex1) const;

  /** 
  * Given two mesh points, check if the two points are on a same and unique triangle.
  * A segment on a triangle cannot be a segment on a bar.
  * @param meshPoint0
  *   The first mesh point.
  * @param meshPoint1
  *   The second mesh point.
  * @param oTriangle
  *   The triangle if found otherwise 0.
  * @return
  *   TRUE if the two mesh points are on the same and unique triangle.
  *   FALSE otherwise.
  */
  CATBoolean IsSegmentOnTriangle (const CATPolyMPointTopo& meshPoint0, const CATPolyMPointTopo& meshPoint1,
                                  int& oTriangle) const;

  /**
  * Checks whether a mesh point is on a specific bar.
  */
  static CATBoolean IsMeshPointOnBar (const CATPolyMPointTopo& meshPoint,
                                      const int iBarVertex0, const int iBarVertex1);

  /**
  * Tests if a mesh point is topologically in the same triangle as a bar.
  * @param meshPoint0
  *   The meshpoint.
  * @param barVertex0
  *   The index of the first vertex of the bar.
  * @param barVertex1
  *   The index of the second vertex of the bar.
  * @return
  *   The triangle number if the two mesh points are in the same triangle and
  *   0 otherwise.
  */
  HRESULT CheckSameTriangleMeshPointBar (const CATPolyMPointTopo& meshPoint0,
                                         const int barVertex0, const int barVertex1,
                                         int & returnTriangle);

  /**
  * Tests if a mesh point is topologically in the same triangle as a vertex.
  * @param meshPoint
  *   The meshpoint.
  * @param vertex
  *   The relative index of the vertex.
  * @return
  *   The triangle number if the mesh point is in the same triangle as the vertex and
  *   0 otherwise.
  */
  HRESULT CheckSameTriangleMeshPointVertex (const CATPolyMPointTopo& meshPoint0,
                                            const int vertex,
                                            int & returnTriangle);

  /**
  * Checks if the mesh point belongs to the triangle.
  * @param meshPoint
  *   The mesh point to check.
  * @param triangle
  *   The index of the triangle.
  * @return
  *   The triangle number if the mesh point belongs to the triangle and 0 otherwise.
  */
  HRESULT CheckSameTriangleMeshPointTriangle (const CATPolyMPointTopo& meshPoint,
                                              const int triangle,
                                              int & returnTriangle);

  /**
  * Returns a triangle index different from 0 if the two mesh points define a segment
  * that is on a unique triangle.
  * @param meshPoint0
  *   The start of the mesh-point segment.
  * @param meshPoint1
  *   The end of the mesh-point segment.
  * @param returnTriangle
  *   The triangle on which the segment lies.  If the segment is shared by two or more triangles
  *   then the method returns 0.
  */
  HRESULT GetTriangleFromMeshPointSegment (const CATPolyMPointTopo& meshPoint0,
                                           const CATPolyMPointTopo& meshPoint1,
                                           int & returnTriangle);

  /**
  * Returns all the triangles that share the mesh-point segment.
  * @param meshPoint0
  *   The start of the mesh-point segment.
  * @param meshPoint1
  *   The end of the mesh-point segment.
  * @param oTriangles
  *   The triangles on which the segment lies.
  */
  HRESULT GetTrianglesFromMeshPointSegment (const CATPolyMPointTopo& meshPoint0,
                                            const CATPolyMPointTopo& meshPoint1,
                                            CATListOfInt& oTriangles);

private :

  const CATIPolyMesh * _PolyMesh;

};

#endif
