// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodySimpleClashFaceEdgeIterator.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Nov 2009 Creation: JXO
//===================================================================

#ifndef CATPolyBodySimpleClashFaceEdgeIterator_h
#define CATPolyBodySimpleClashFaceEdgeIterator_h

#include "PolyBodyBVHOperators.h"
#include "CATPolyBodySimpleClashOper.h"
#include "CATPolyRefCounted.h"

// Math
#include "CATMathPoint.h"
#include "CATBoolean.h"
#include "CATListPV.h"


class CATIPolyCurveIterator;
class CATCellId;

class ExportedByPolyBodyBVHOperators CATPolyBodySimpleClashFaceEdgeIterator : public CATPolyRefCounted
{
public:
  CATPolyBodySimpleClashFaceEdgeIterator();
  ~CATPolyBodySimpleClashFaceEdgeIterator();

  /**
   * Sets the iterator at the beginning
   */
  void Begin();
  /**
   * Returns TRUE if you're at the end (no result in this case), FALSE otherwise.
   */
  CATBoolean End();
  /**
   * Increments the iterator.
   */
  void operator ++();

  /**
   * Results:
   */

  /**
   * First colliding face index (index in polybody)
   * May be -1 if in EdgesAgainstFaces, EdgesAgainstEdges or EdgesAgainstAll mode.
   */
  int GetFirstFaceIndex();
  /**
   * Second colliding face index (index in polybody)
   * May be -1 if in FacesAgainstEdges, EdgesAgainstEdges or AllAgainstEdges mode.
   */
  int GetSecondFaceIndex();
  /**
   * First colliding edge index (index in polybody)
   * May be -1 if in FacesAgainstFaces, FacesAgainstEdges or FacesAgainstAll mode.
   */
  int GetFirstEdgeIndex();
  /**
   * Second colliding edge index (index in polybody)
   * May be -1 if in EdgesAgainstFaces, FacesAgainstFaces or AllAgainstFaces mode.
   */
  int GetSecondEdgeIndex();

  /**
   * First Id.
   * Release after use.
   * @return [out, IUnknown#Release]
   */
  CATCellId * GetFirstId();
  /**
   * Second Id.
   * Release after use.
   * @return [out, IUnknown#Release]
   */
  CATCellId * GetSecondId();

  /**
   * In case of one edge colliding one face, we return intersection points.
   * This method returns the number of intersections.
   */
  int GetNbOfIntersections();
  /**
   * Returns an intersection point, positionned in absolute referential.
   * Index begins at 0.
   */
  CATMathPoint GetIntersectionPoint(int index);
  /**
   * Returns a bar index on the edge, for corresponding intersection.
   * Both index begin at 0 (bar index and intersection index)
   * Returns -1 if no bar index was added to the intersection.
   */
  int GetBarIndex(int index);
  /**
   * Returns the index of the triangle in the poly surface, for corresponding intersection.
   * Input argument 'index' begins at 0.
   * Returns -1 if no triangle index was added to the intersection.
   */
  int GetTriangleIndex(int index);

  /**
   * In case of two faces colliding, we return a curve.
   * DO not delete!
   */
  const CATIPolyCurveIterator * GetIntersectionCurve();

  /**
   * Returns clash status
   */
  CATPolyBodySimpleClashOper::ClashStatus GetClashStatus();

  /**
   * Adds a new set of intersection points.
   * points now belong to the iterator, do not delete it.
   * Release given cells id after this call.
   * barindices, triangleindices: indices in cell (index of bar in edge, of triangle in face)
   */
  void AddIntersectionPoints(CATCellId * cellid1, CATCellId * cellid2, int nbpoints, CATMathPoint * points, int * barindices = 0, int * triangleindices = 0);
  /**
   * Adds a new curve. Do not delete given curve!
   * Release given cell id after this call.
   */
  void AddCurves(CATCellId * cellid1, CATCellId * cellid2, CATIPolyCurveIterator * pCurves, CATPolyBodySimpleClashOper::ClashStatus status);

private:
  CATListPV _Results;
  int _index;

};

#endif /* CATPolyVisuInterfBVHTreeSet_h */
