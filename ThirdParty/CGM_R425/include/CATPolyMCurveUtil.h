// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMCurveUtil.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// mar 2004 Creation: dhp
//===================================================================
#ifndef CATPolyMCurveUtil_h
#define CATPolyMCurveUtil_h

#include "CATPolyMCrv.h"
#include "CATBoolean.h"
#include "CATLISTP_CATPolyMCurve.h"

class CATIPolyMesh;
class CATPolyMCurve;
class CATPolyMPoint;
class CATMathPoint;
class CATMathBox;


/**
* Class with some miscellaneous utilities for mesh curves.
*/
class ExportedByCATPolyMCrv CATPolyMCurveUtil 
{

public :

  /**
  * Default constructor.
  */
	CATPolyMCurveUtil (void);

  /**
  * Destructor.
  */
	~CATPolyMCurveUtil (void);

  static CATBoolean HasCommonEndpoints (CATPolyMCurve * meshCurve0, CATPolyMCurve * meshCurve1);

  /**
  * Checks whether the mesh curve is a hole curve, that is:
  *   1) It is a vertex path.
  *   2) Its segments are all free edges.
  * @param meshCurve
  *   The mesh curve.
  */
  static CATBoolean IsHoleCurve (CATPolyMCurve* meshCurve);

  /**
  * Returns <tt>TRUE</tt> if the mesh curve passes by the triangle and <tt>FALSE</tt> otherwise.
  * @param meshCurve
  *   The mesh curve.
  * @param triangle
  *   The relative index of the triangle.
  */
  static CATBoolean HasTriangle (CATPolyMCurve* meshCurve, const int triangle);

  /**
  * Returns the index of the last mesh point whose distance from the
  * start of the mesh curve is less than the specified distance.
  * @param meshCurve
  *   The mesh curve.
  * @param distance
  *   The specified distance.
  * @return
  *   The index of the mesh point whose distance is less than the
  *   specified distance. Returns zero if <tt>meshCurve</tt> is null
  *   or the distance is not in the valid range (greater than zero
  *   and less than the length of the mesh curve).
  */
  static int GetIndexFromDistance (CATPolyMCurve * meshCurve, const double distance);

  /**
  * Returns the total distance from the start of the mesh curve to the
  * mesh point at the specified index.
  * @param meshCurve
  *   The mesh curve.
  * @param index
  *   The index of the mesh point for which the distance is calculated.
  * @return
  *   The distance to the specified mesh point or zero if the index
  *   is not in the valid range.
  */
  static double GetDistanceFromIndex (CATPolyMCurve * meshCurve, const int index);

  /**
  * Given a point on the mesh curve, returns the index, i, of the segment (i, i+1) from the
  * mesh curve on which the point lies.
  * If the point does not lie on the mesh curve, then the method returns 0.
  * @param meshCurve
  *   The mesh curve.
  * @param point
  *   A point.
  * @return
  *   The index, i, of the mesh point which defines the start of the segment (i, i+1) on
  *   which the point lies.
  */
  //static int GetIndexFromPoint (CATPolyMCurve* meshCurve, const CATMathPoint& point);

  /**
  * Return the total number of points in the list of mesh curves.
  * @param meshCurves
  *   The list of mesh curves.
  * @return
  *   The total number of points in the mesh curves.
  */
  static int GetNumPoints (const CATListPtrCATPolyMCurve & meshCurves);

  /**
  * Breaks the specified mesh curve into several mesh curves.
  * @param meshCurve
  *   The mesh curve to break.
  * @param breakPoints
  *   The indices at which the mesh curve should be broken.
  * @param newMeshCurevs
  *   The resulting mesh curves. These need to be released by the caller.
  * @return
  *   TRUE if the operation succeeded and FALSE otherwise.
  */
  static CATBoolean BreakMeshCurve (CATPolyMCurve * meshCurve, const CATListOfInt & breakPoints,
                                    CATListPtrCATPolyMCurve & newMeshCurves);

  static CATBoolean BreakMeshCurve (const CATListOfInt & meshPointIndices, const CATListOfInt & breakPoints,
                                    CATListPV & newMeshPointIndices);

  /**
  * Returns the index of the segment in which meshPoint lies.
  * If meshPoint is not a vertex in the mesh curve or doesn't
  * lie on one of the segments than zero is returned.
  */
  static int GetMeshPointIndex (CATPolyMCurve * meshCurve, const CATPolyMPoint & meshPoint);

  /**
  * Splices meshCurveToSplice into meshCurve. The indices are
  * those returned from GetMeshPointIndex. The portion of meshCurve
  * between startIndex and endIndex is removed and replaced with
  * meshCurveToSplice.
  */
  static CATBoolean Splice (CATPolyMCurve * meshCurve,
    CATPolyMCurve * meshCurveToSplice,
    const int startIndex,
    const int endIndex);

  static CATBoolean Chop (CATPolyMCurve * meshCurve,
    CATPolyMCurve * meshCurve0,
    CATPolyMCurve * meshCurve1,
    const CATPolyMPoint & meshPoint0,
    const CATPolyMPoint & meshPoint1,
    const CATBoolean closed);

  static CATBoolean Chop (CATPolyMCurve * meshCurve,
    CATPolyMCurve * meshCurve0,
    CATPolyMCurve * meshCurve1,
    const CATPolyMPoint & meshPoint0,
    const CATPolyMPoint & meshPoint1,
    const int startIndex,
    const int endIndex,
    const CATBoolean closed);

  static void SortByLength (CATListPtrCATPolyMCurve & meshCurves);

  static int GetNumCommonEndpoints (CATPolyMCurve * meshCurve0,
    CATPolyMCurve * meshCurve1);

  static double GetMinSegmentLength (CATPolyMCurve * meshCurve);

  static double GetMaxSegmentLength (CATPolyMCurve * meshCurve);

  static CATBoolean Decompose (CATPolyMCurve * meshCurve,
    CATListPtrCATPolyMCurve & meshCurves);

  static unsigned Hash (CATPolyMCurve * meshCurve);

  static CATBoolean GetBox (const CATListPtrCATPolyMCurve & meshCurves,
    CATMathBox & box);

  /**
  * Returns the poly mesh associated with the mesh curves. If more than one
  * poly mesh is referenced by the mesh curves then return NULL.
  */
  static CATIPolyMesh * GetPolyMesh (const CATListPtrCATPolyMCurve & meshCurves);

  static CATBoolean GetMeshCurveInsideTriangle (const int triangle,
    CATPolyMCurve * meshCurve,
    const CATListOfInt & meshPointIndices,
    CATListPV & newSegments);

};

#endif
