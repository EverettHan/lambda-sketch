// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBarCollapseOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Sep 2001/Aug 2005 Creation: NDO
//===================================================================
#ifndef CATPolyBarCollapseOper_h
#define CATPolyBarCollapseOper_h

#include "CATPolyModOperators.h"
#include "CATPolyModOper.h"
#include "CATBoolean.h"
#include "CATMathPoint.h"
#include "CATIAV5Level.h"

class CATIPolyMesh;
class CATPolySurfaceVertexNNormalsLayer;
class CATIPolySurfaceVertexNormalLayer;
class CATPolyBarCollapseSelfIntersectChecker;

/*
Operator that performs bar collapses.  This operator also supports the merge of two vertices
that are not necessarily connected by a bar.  Several options are available to turn on or off
topology and geometry checks prior to the collapse.
*/
class ExportedByCATPolyModOperators CATPolyBarCollapseOper : public CATPolyModOper
{

public:

  CATPolyBarCollapseOper(CATIPolyMesh * polyMesh);

  ~CATPolyBarCollapseOper(void);

  /**
  * Turns on or off the non-manifold bar check prior to a bar collapse (topology check).
  * With this option on, a collapse is not allowed if the contraction creates a non-manifold bar.
  * Default is on.
  */
  void SetCheckNonManifoldBars(const CATBoolean iCheck);

  /**
  * Turns on or off the non-manifold vertex check prior to a bar collapse (topology check).
  * With this option on, a collapse is not allowed if the contraction creates a non-manifold vertex.
  * Default is on.
  */
  void SetCheckNonManifoldVertices(const CATBoolean iCheck);

  /**
  * Turns on or off the triangle normals check prior to a bar collapse (geometry check).
  * With this option on, no bar collapse occurs when the normals are flipped.
  * Default is on.
  */
  void SetCheckNormals(const CATBoolean iCheck);

  /**
  * Turns on or off the triangle sizes check prior to a bar collapse (geometry check).
  * With this option on, no bar collapse occurs when the sizes (angles and bar length) become below set values.
  * Default is on.
  */
  void SetCheckSizes(const CATBoolean iCheck);

  /**
  * Turns on or off the self-intersection check prior to a bar collapse.
  * This is quite expensive, so it is turned off be default. When on, collapses resulting in self-intersections are rejected.
  */
  HRESULT SetCheckSelfIntersections(const CATBoolean iCheck, const double iVoxelSize);

  /**
  * Disables all geometric checks.
  **/
  void DisableGeometricChecks();

  /**
  * Set the minimum angle in radians acceptable in a triangle after a bar collapse.
  * Option SetCheckSizes must be turned on.
  */
  void SetMinimumAngle(const double iAngle);

  /**
  * Set the minimum bar length acceptable in a triangle after a bar collapse.
  * Option SetCheckSizes must be turned on.
  */
  void SetMinimumEdgeLength(const double iBarLength);

  /**
  * To collapse a valid bar defined by the pair of vertices, (vertexToKeep, vertexToRemove),
  * (1) set the bar to collapse into the operator, SetBarToCollapse, (2) run the operator, Run, and
  * (3) get the information such as modified triangles after the collapse, GetCollapseResults.
  * Topology and geometry tests are by default turned on.  If the pair contraction passes these tests,
  * the collapse occurs.  Otherwise, it fails.  The tests can be turned off.
  * Pair contraction also works between two vertices that do not define a valid bar.  This can be used
  * for healing purposes.
  * Topology tests include:
  *   1) Non-manifold bar creation test;
  *   2) Non-manifold vertex creation test.
  * Geometry tests include:
  *   1) Triangle normal test;
  *   2) Size of triangles after the collapse (bar lengths and angles);
  *   3) External geometry test through a callback.
  * Parameters:
  * @param iVertexToKeep
  *   The first vertex defining the bar.  That vertex will remain valid after the pair contraction.
  * @param iVertexToRemove
  *   The second vertex defining.  That vertex will be removed during the pair contraction.
  * @param iNewPoint
  *   The coordinates of the vertex after a successful pair contraction.  The coordinates of the vertex
  *   are used to perform the geometry tests.
  */
  void SetBarToCollapse(const int iVertexToKeep, const int iVertexToRemove, const CATMathPoint& iNewPoint);

  /**
  * When known in advance, this method offers to specify whether each vertex involved in the collapse is a hole vertex or not.
  * When not specified, this information is queried from the mesh itself.
  */
  void SetVertexHoleStatus(const CATBoolean iIsVertexToKeepHole, const CATBoolean iIsVertexToRemoveHole);

  /**
  * Runs the bar collapse.
  * @return
  *   S_OK if the collapse or contraction is successful.
  *   E_FAIL if the collapse or contraction fails.
  */
  HRESULT Run(void);

  //New API
  CATBoolean CheckBeforeRun();
  HRESULT RunWithoutCheck();

  /**
  * Returns the results of a successful bar collapse.
  * Note that if the bar is non-manifold, more than two triangles are removed by the operator.
  * See GetRemovedTriangles below.
  * @param oTriangle1
  *   The first triangle removed during the bar collapse.  This is an output parameter
  *   which is set to an index different from 0 only when at least one triangle is removed.
  *   Note that this is no longer a valid triangle since the triangle has been removed.
  * @param oTriangle2
  *   The second triangle removed during the bar collapse.  This is an output parameter
  *   which is set to an index different from 0 only when two triangles are removed.
  *   Note that this is no longer a valid triangle since the triangle has been removed.
  * @param oOppositeVertex1
  *   The vertex from oTriangle1 opposite to the bar.  This is an output parameter
  *   which is set to a valid index different from 0 only when at least one triangle is removed.
  * @param oOppositeVertex2
  *   The vertex from oTriangle2 opposite to the bar.  This is an output parameter
  *   which is set to a valid index different from 0 only when at least two triangles are removed.
  * @param oNbRemovedTriangles
  *   The number of removed triangles.  This number can be greater than two if the bar was non-manifold.
  * @return
  *   TRUE.
  */
  CATBoolean GetCollapseResults(int& oTriange1,
    int& oTriangle2,
    int& oOppositeVertex1,
    int& oOppositeVertex2,
    int& oNbRemovedTriangles) const;

  /**
  * Returns the list of updated triangles after a successful bar collapse.
  */
  CATBoolean GetModifiedTriangles(int& oRemovedTriangle0,
    int& oRemovedTriangle1,
    CATListOfInt& oUpdatedTriangles) const;

  /**
  * Returns the list of triangles that have been removed.
  */
  const CATListOfInt& GetRemovedTriangles() const;

protected:

  /**
  * Virtual method to overwrite in a derived class if one wants to test
  * the impact of the bar collapse on the model.  The call is made before the bar collapse.
  * @param iPoints
  *   Coordinates of vertices of the current triangle (array of dimension 3.)
  * @param iNewPoint
  *   Coordinates of the new point.
  * @param iVertexIndex
  *   Index between 0 and 2 of the point being replaced in the array by the new point.
  * @return
  *   <tt>TRUE<\tt> if the geometry test is valid.
  *   <tt>FALSE<\tt> if the geometry test is invalid.
  */
  virtual CATBoolean CheckGeometryExternal(const CATMathPoint iPoints[],
    const CATMathPoint& iOldPoint,
    const CATMathPoint& iNewPoint) const;

  /**
  * Virtual method called before a bar is collapse.  If this method returns FALSE, the bar will not be collapsed.
  */
  virtual CATBoolean IsBarOkToCollapse(const int iVertexToKeep, const int iVertexToRemove,
    const CATMathPoint& iNewPoint) const;

private:

  // This method performs the two topology checks:
  //   1) Check that the collapse does not create non-manifold bars.
  //   2) Check that the collapse does not create non-manifold vertices.
  // A collapse that creates non-manifold bars, creates non-manifold vertices.  If the topology check
  // for non-manifold vertices is turned on, then the topology check for non-manifold bars is turned on.
  // On the opposite, if the topology check for non-manifold bars is turned off, then the topology check for 
  // non-manifold vertices is turned off.
  CATBoolean CheckTopology() const;
  // This method is dedicated to be used in CheckTopology
  // iAroundWhichVertex = 0 -> we will check around the vertex to keep
  // iAroundWhichVertex = 1 -> we will check around the vertex to remove
  CATBoolean TrianglesMakeAContiguousFan(const int & iAroundWhichVertex) const;

  // This method performs the geometry checks.
  CATBoolean CheckGeometry(const int vertex, const CATMathPoint& newPoint, const CATListOfInt& triangles, const int* vertices) const;

  CATBoolean CheckTriangleNormal(const CATMathPoint points[], const CATMathPoint& oldPoint, const CATMathPoint& newPoint) const;

  CATBoolean CheckTriangleSize(const CATMathPoint points[], const CATMathPoint& oldPoint, const CATMathPoint& newPoint) const;

  CATBoolean CheckSelfIntersections() const;

  HRESULT InitializeChecker(const double iVoxelSize);

  CATBoolean GetOppositeBar(const int triangle, const int vertex, int* bar);
  CATBoolean GetOppositeVertex(const int* vertices, const int vertex, int& oppositeVertex);

  void InitializeLists();
  void ClearLists();
  void ClearAllocatedData();

  HRESULT UpdateVertexNormals();
  void RemoveTriangleAndVertexNormals(const int iIndex);

  CATBoolean IsVertexToKeepHole() const;

  CATBoolean IsVertexToRemoveHole() const;

  CATPolySurfaceVertexNNormalsLayer* _VertexNormals;

  CATBoolean _CheckNonManifoldBars;     // Topology check.
  CATBoolean _CheckNonManifoldVertices; // Topology check.
  CATBoolean _CheckNormals;             // Geometry check.
  CATBoolean _CheckSizes;               // Geometry check.
  CATBoolean _CheckExternal;            // Geometry check.
  CATBoolean _CheckSelfIntersections;   // Special  check.

  CATPolyBarCollapseSelfIntersectChecker* _SelfIntersectionChecker;

  double _MinimumAngleCosine;
  double _MinimumBarLength;

  int _VertexToKeep;
  int _VertexToRemove;

  CATMathPoint _NewPoint;

  enum VertexHoleStatus
  {
    UNSET,
    HOLE,
    NONHOLE
  };

  VertexHoleStatus _IsVertexToKeepHole;
  VertexHoleStatus _IsVertexToRemoveHole;

  CATListOfInt _TrianglesToRemove;
  CATListOfInt _OppositeVertices;
  CATListOfInt _TrianglesVertexToKeep;
  CATListOfInt _TrianglesVertexToRemove;

  CATListOfInt _Faces;  // A list of face indices associated to a vertex for update of the vertex normals.
  CATListOfInt _Triangles; // A list of neighbor triangles of an opposite vertex to the bar.

  int* _VerticesK;
  int* _VerticesR;

  int* _FacesOfTrianglesVertexToKeep;
  int* _FacesOfTrianglesVertexToRemove;
};

#endif
