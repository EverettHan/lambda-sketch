// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanSegmentsOper.h
//
//===================================================================
// December 2005 Creation: ndo
//===================================================================
#ifndef CATPolyBooleanSegmentsOper_H
#define CATPolyBooleanSegmentsOper_H

#include "CATPolyBooleanOperators.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATLib.h"  // Definition of NULL.

class CATIPolyMesh;
class CATPolyGriddedMeshAndBarsConst;
class CATPolyTopoUtil;
class CATPolyIntersectionPoint;
class CATPolyBooleanSegments1;
class CATPolyTriangleIntersector;
class CATPolyExactArithmetic;
class CATPolyAttributeDomains;
class CATMathPoint;

class CATPolyMeshPartitionOper;


class ExportedByCATPolyBooleanOperators CATPolyBooleanSegmentsOper
{

public :

  CATPolyBooleanSegmentsOper (CATPolyGriddedMeshAndBarsConst& iOperand0, CATPolyGriddedMeshAndBarsConst& iOperand1,
                              CATPolyMeshPartitionOper& iMeshPartition);

  ~CATPolyBooleanSegmentsOper ();

  /**
   * Sets the type of operation to perform.
   * @param iOperation
   *   The type of boolean operation (see CATPolyBoolean::BooleanOperation enum.)
   */
  void SetBooleanOperation (const int iOperation);

  /**
   * Sets the shells that have been identified for each operand.
   * If the shells are set before running the operator, then the operator determines the positions 
   * of the shells w.r.t. the other operand when there is at least a contact between the shell
   * and the operand.
   */
  void SetShells (const CATPolyAttributeDomains* iShells0, const CATPolyAttributeDomains* iShells1);

  HRESULT Run ();

  const CATPolyBooleanSegments1* GetIntersectionSegments () const;

  enum ShellPosition
  {
    eShellUnknown = -65536, 
    eShellOutside = -2,    // Shell outside the operand.  (No overlapping facets.)
    eShellOutsideOn = -1,  // Shell outside with facets overlapping the operand.
    eShellOn = 0,          // Shell has facets overlapping the operand.
    eShellInsideOn = 1,    // Shell inside with facets overlapping the operand.
    eShellInside = 2,      // Shell inside the operand.  (No overlapping facets.)
    eShellIntersect = 4
  };

  /**
   * Returns the position of the shell of an operand (0 or 1) w.r.t. the other operand.
   * The returned value is as follows:
   *   o eShellUnknown: The shell is unknown to this operator (no contact with the mesh).
   *                    Its position is not set.
   *   o eShellOutside: The shell is outside the other operand.
   *   o eShellOn: The shell is on the other operand.
   *   O eShellInside: The shell is inside the other operand.
   *   o eShellIntersect: The shell intersects the mesh.
   */
  ShellPosition GetShellPosition (const int iMesh, const int iShell) const;

private:

  const CATPolyExactArithmetic& _ExactArithmetic;
  CATPolyMeshPartitionOper& _MeshPartition;

  CATPolyGriddedMeshAndBarsConst* _GriddedOperands[2];
  CATPolyTopoUtil* _TopoUtil[2];

  const CATPolyAttributeDomains* _Shells[2];   // The set of shells for the two operands.
  ShellPosition* _ShellPosition[2];            // For each shell a flag set to 1 when there is a contact.
                                               // and 0 when there is no contact.

  CATPolyBooleanSegments1* _IntersectionSegments;

  CATPolyTriangleIntersector* _TriangleIntersector;

  int _BooleanOperation;

private:

  /** 
   * Checks the triangles from Mesh A and Mesh B and determine whether they are degenerate or not.
   */
  void CheckTriangles (const int iTriangleA, const int iTriangleB) const;

  /**
   * Finds the triangle(s) on which the segment defined by the two intersection points lies.
   * The method returns the number of triangles found: 1 or 2 depending whether the segment lies on a bar.
   *   @param iMesh
   *      The mesh on which to find the triangles.
   *   @param iPoint1
   *      The first intersection point.
   *   @param iPoint2
   *      The second intersection point.
   *   @param oBar
   *      A pointer to the index of the bar on which the intersection segment lies (set only if different from NULL.)
   *      If the segment is on a bar, this index is set to the bar index: 0, 1, 2
   *      If the segment is not on a bar, this index is set to -1.  
   *      This bar index refers to the triangle referenced by the two intersection point.  It is always
   *      the first triangle: oTriangles[0].
   *   @return
   *      The number of triangles found.
   */
  int GetTriangles (const int iMesh,
                    const CATPolyIntersectionPoint& iPoint1, const CATPolyIntersectionPoint& iPoint2,
                    int oTriangles[2], int* oBar = NULL) const;

  /**
   * Finds the two vertices that are opposed the the common bar between the two triangles.
   * The method returns the number of vertices found: 2 when the two triangles share a common bar.
   *   @param iMesh
   *      The mesh to which the triangles belong.
   *   @param iTriangles
   *      The two triangles.
   *   @param oOppositeVertices
   *      The vertices that are opposite to the common bar between the two triangles,
   *      respectively for the first and second triangles.
   *   @return
   *      The number of vertices: 2 when the triangles share a common bar.
   */
  int GetOppositeVertices (const int iMesh,
                           const int iTriangles[],
                           CATMathPoint oOppositeVertices[]) const;
 
  /*
   * Checks whether the pair is contributing to the boolean operation.
   * If the pair is contributing, the method also returns the correct orientation of the pair:
   *   - If oOrientation = +1, then the orientation is: IJ.
   *   - If oOrientation = -1, then the orientation is: JI.
   */
  CATBoolean IsPairContributing (const CATPolyIntersectionPoint& I, const CATPolyIntersectionPoint& J,
                                 int& oOrientation) const;

  /*
   * This method checks whether a pair of triangles is contributing to the boolean operation in the case of an 
   * intersection segment lying on a bar for each triangle (bar-bar case.)  The pair consists of the first 
   * triangles of the first and second arguments respectively for Mesh 0 and Mesh 1: (iTrianglesMesh0[0], iTrianglesMesh1[0]).
   * The pair of triangles is contributing if the two triangles sharing the bar for Mesh 0 (or equivalently Mesh 1) are 
   * on opposite sides of Mesh 1 (or equivalently Mesh 0.)  If the pair is contributing, the method also returns the 
   * position (inside/outside) of its two triangles with respect to the other mesh.
   */
  CATBoolean IsPairContributingBarBarCase (const int iTrianglesMesh0[], const int iTrianglesMesh1[],
                                           int& oPosTriangleMesh0, int& oPosTriangleMesh1) const;

  CATBoolean IsPairContributingBarTriangleCase (const int iTrianglesMesh0[], const int iTriangleMesh1) const;
  CATBoolean IsPairContributingTriangleBarCase (const int iTriangleMesh0, const int iTrianglesMesh1[]) const;

  /*
   * This method classifies the position of a vertex from Mesh 1 with respect to Mesh 0 when the intersection 
   * is along bars from Mesh 0 and Mesh 1.  When classified a vertex is either inside or outside the mesh because
   * the on-cases are reclassified either inside or outside. (Returned value cannot be OnMesh!)
   * The tested vertex is opposite the bar from a triangle from Mesh 1.
   * The arguments are as follows:
   * - Triangle from Mesh 1 to which the vertex belongs.
   * - Coordinates of the vertex tested.
   * - Triangle 0 from Mesh 0 against which the point is tested.
   * - Triangle 1 from Mesh 0 against which the point is tested.
   * - The vertex opposite to the bar from Triangle 0 from Mesh 0.
   */
  int ClassifyPositionBarBarCaseMesh0 (const CATMathPoint iPntsTMesh1[3], 
                                       const CATMathPoint& iOppVertexTMesh1,
                                       const CATMathPoint iPntsT0Mesh0[3],
                                       const CATMathPoint iPntsT1Mesh0[3],
                                       const CATMathPoint& iOppVertexT0Mesh0) const;

  /*
   * This method classifies the position of a vertex from Mesh 0 with respect to Mesh 1 when the intersection 
   * is along bars from Mesh 0 and Mesh 1.  When classified a vertex is either inside or outside the mesh because
   * the on-cases are reclassified either inside or outside. (Returned value cannot be OnMesh!)
   * The tested vertex is opposite the bar from a triangle from Mesh 0.
   * The arguments are as follows:
   * - Triangle from Mesh 0 to which the vertex belongs.
   * - Coordinates of the vertex tested.
   * - Triangle 0 from Mesh 1 against which the point is tested.
   * - Triangle 1 from Mesh 1 against which the point is tested.
   * - The vertex opposite to the bar from Triangle 0 from Mesh 1.
   */
  int ClassifyPositionBarBarCaseMesh1 (const CATMathPoint iPntsTMesh0[3], 
                                       const CATMathPoint& iOppVertexTMesh0,
                                       const CATMathPoint iPntsT0Mesh1[3],
                                       const CATMathPoint iPntsT1Mesh1[3],
                                       const CATMathPoint& iOppVertexT0Mesh1) const;

  /*
   * Finds a contributing triangle pair that has not been visited yet.
   * If the pair contributes, the method finds the intersection between the two triangles 
   * (a line segment defined by two intersection points.)
   * The current implementation is highly inefficient.
   * @return
   *   <ul>
   *      <li> S_OK when a contributing pair is found.
   *      <li> S_FALSE when no contributing pair is found.
   *      <li> E_FAIL when an error occurs.
   *   </ul>
   */
  HRESULT FindContributingPair (CATPolyIntersectionPoint& I, CATPolyIntersectionPoint& J);

  void UpdateShellPosition (const int iMesh, const int iShell, const ShellPosition iPosition);

  HRESULT ProcessPointIntersection (const int triangle[], const CATMathPoint pnts[][3]);

  /*
   * Processes a segment intersection.
   * @return
   *   <ul>
   *      <li> S_OK when a contributing pair is found.
   *      <li> S_FALSE when no contributing pair is found.
   *      <li> E_FAIL when an error occurs.
   *   </ul>
   */
  HRESULT ProcessSegmentIntersection (const int triangle[], const CATMathPoint pnts[][3],
                                      CATPolyIntersectionPoint& I, CATPolyIntersectionPoint& J);

};

#endif

