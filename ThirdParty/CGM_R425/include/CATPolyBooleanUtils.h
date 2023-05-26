// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanUtils.h
// Header definition of CATPolyBooleanUtils
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Jan 2005 Creation: NDO
//===================================================================
#ifndef CATPolyBooleanUtils_H
#define CATPolyBooleanUtils_H

#include "CATPolyBooleanOperators.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATMathPoint.h"
#include "CATMathPoint2D.h"

class CATPolyExactArithmetic;
class CATIPolyMesh;
class CATPolyGriddedMeshAndBarsConst;
class CATPolyIntersectionPoint;
class CATCGMOutput;

/**
* Geometrical utilities for Boolean operators using exact arithmetic.
*/
class ExportedByCATPolyBooleanOperators CATPolyBooleanUtils
{

public:

/** @name Comparison Utilities
    @{ */

  /**
   * Compares the projections of two points onto on a Cartesian plane.
   * @param iExactArithmetic
   *   The instance of exact arithmetic.
   * @param iPoint1
   *   The first point.
   * @param iPoint2
   *   The second point.
   * @param iDir
   *   The direction of the plane on which the points are projected.
   *   <ul>
   *     <li> -1 or +1: (O,y,z) plane.
   *     <li> -2 or +2: (O,z,x) plane.
   *     <li> -3 or +3: (O,x,y) plane.
   *   </ul>
   * @return
   *   <tt>TRUE</tt> if the points are equal and <tt>FALSE</tt> otherwise.
   */
  static CATBoolean CompareMathPoints (const CATPolyExactArithmetic& iExactArithmetic,
                                       const CATMathPoint& iPoint1, const CATMathPoint& iPoint2, const int iDir);

/** @} */

public:

/** @name Inclusion Utilities
    @{ */

  static CATBoolean IsInsideBoundingBoxOfBar (const CATMathPoint2D& iPoint,
                                              const CATMathPoint2D& iBarPoint0, 
                                              const CATMathPoint2D& iBarPoint1);

  static CATBoolean IsInsideBoundingBoxOfBar (const CATMathPoint& iPoint,
                                              const CATMathPoint& iBarPoint0, 
                                              const CATMathPoint& iBarPoint1);

  static CATBoolean IsInsideBoundingBoxOfTriangle (const CATMathPoint& iPoint,
                                                   const CATMathPoint& iTrianglePoint0, 
                                                   const CATMathPoint& iTrianglePoint1, 
                                                   const CATMathPoint& iTrianglePoint2);

/** @} */

public:

/** @name Local position utilities
    @{ */

  /**
   * Returns the local position near a triangle of the segment from the triangle to a point. 
   * This is regardless of the position of the point w.r.t. the mesh.
   * (This is a local position w.r.t. a plane.)
   * @return
   * <ul>
   *   <li> +1: if, locally near the triangle, the segment to the point is inside the mesh.
   *   <li>  0: if, locally near the triangle, the segment to the point is on the mesh.
   *   <li> -1: if, locally near the triangle, the segment to the point is outside the mesh.
   * </ul>
   * If the method fails and the position cannot be determined, it returns any other arbitrary value.
   */
  static int GetLocalPositionOfPointNearTriangle (CATPolyGriddedMeshAndBarsConst& iOperand, 
                                                  const int triangle,
                                                  const CATMathPoint& iPoint);

  /**
   * Returns the local position around a bar of the segment from the bar to a point. 
   * This is regardless of the position of the point w.r.t. the mesh.
   * (This is a local boolean operation around the circumference of a circle.)
   * @return
   * <ul>
   *   <li> +1: if, locally around the bar, the segment to the point is inside the mesh.
   *   <li> 0: if, locally around the bar, the segment to the point is on the mesh.
   *   <li> -1: if, locally around the bar, the segment to the point is outside the mesh.
   * </ul>
   * If the method fails and the position cannot be determined, it returns any other arbitrary value.
   */
  static int GetLocalPositionOfPointNearBar (CATPolyGriddedMeshAndBarsConst& iOperand, 
                                             const int barVertex0, const int barVertex1,
                                             const CATMathPoint& iPoint);

  /**
   * Return the local position around a vertex of the segment from the vertex to a point. 
   * This is regardless of the position of the point w.r.t. the mesh.
   * (This is a local boolean operation around the surface of a sphere.)
   * @return
   * <ul>
   *   <li> +1: if, locally around the vertex, the segment to the point is inside the mesh.
   *   <li> 0: if, locally around the vertex, the segment to the point is on the mesh.
   *   <li> -1: if, locally around the vertex, the segment to the point is outside the mesh.
   * </ul>
   * If the method fails and the position cannot be determined, it returns any other arbitrary value.
   */
  static int GetLocalPositionOfPointNearVertex (CATPolyGriddedMeshAndBarsConst& iOperand, 
                                                const int vertex,
                                                const CATMathPoint& iPoint);

/** @} */

public:

/** @name Other Utilities
    @{ */

  /**
   * Checks whether two points have their coordinates consistently oriented w.r.t to the 
   * three directions: <tt>xDir</tt>, <tt>yDir</tt>, <tt>zDir</tt>.
   */
  static CATBoolean AreConsistentPoints (const CATPolyExactArithmetic& iExactArithmetic,
                                         const CATMathPoint& iPoint0, const CATMathPoint& iPoint1,
                                         const int xDir, const int yDir, const int zDir);

  /**
   * Checks whether the intersection segment, defined by IJ, lies along a bar of the triangle. 
   * If it does, then report the index of the bar of the triangle it is on.
   * It also reports the orientation of the segment, w.r.t. the bar.
   * @param oOrientation
   *   The reported orientation of the segment.
   * <ul>
   *   <li> +1: if the segment IJ is oriented in the direction of the bar.
   *   <li>  0: the direction of the segment IJ cannot be determined by this function even if the segment
   *            lies on a bar.  (Direction can be determined by another mean.)
   *   <li> -1: if the segment IJ is oriented in the direction opposite to the bar.
   * </ul>
   */
  static CATBoolean IsSegmentOnBar (const int iMesh,
                                    const CATPolyIntersectionPoint& I, 
                                    const CATPolyIntersectionPoint& J,
                                    int& barIndex, int& oOrientation);

  static void PrintIntersectionPoint (CATCGMOutput & stream,
                                      const CATPolyIntersectionPoint & point,
                                      const CATIPolyMesh * polyMesh0,
                                      const CATIPolyMesh * polyMesh1);

/** @} */

};


#endif

