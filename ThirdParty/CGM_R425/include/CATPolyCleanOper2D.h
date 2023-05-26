// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCleanOper2D.h
// Header definition of CATPolyCleanOper2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// April 2006 Creation: ndo
//===================================================================
#ifndef CATPolyCleanOper2D_H
#define CATPolyCleanOper2D_H

#include "PolygonalOperators.h"

#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"
#include "CATListPV.h"

class CATPolyExactArithmetic;
class CATHTableOfIntInt;
class CATMathPoint2D;


/**
 This operator cleans a set of segments by eliminating references to duplicate vertices,
 degenerate segments and splitting intersecting segments.   The segments are contained in 
 a hash table.  The segments are defined by pair of indices into an array of points (C-Style).  The array
 of points can contain points with identical coordinates and unreferenced by any segment.  The split of
 segments is done by insertion of existing points (the closest or the point on a segment).  No new point
 is created.  Under this condition, the intersection between two segments should not be far from one of 
 the intersecting segment.
*/
class ExportedByPolygonalOperators CATPolyCleanOper2D
{

public :

  CATPolyCleanOper2D (const CATPolyExactArithmetic& iExactArithmetic);

  ~CATPolyCleanOper2D ();

  /**
   * Turn on or off an option to remove opposite segments.  When this option is turned on, opposite 
   * segments cancel each other.
   */
  void SetRemoveOppositeSegments (const CATBoolean iRemoveOppositeSegments);

  /**
   *
   * Method that processes the list of segments to:
   *   1) Eliminate references to duplicate vertices;
   *   2) Split the segments that are intersecting.
   * To split the intersecting segments, the method uses the closest extremity from one of the segment
   * to the other.  It does not construct an intersection point.
   * @param iPoints
   *   An array of points the segments are referring to.
   * @param iNbPoints
   *   The number of points.
   * @param ioSegments
   *   A set of segments stored in the hash table and referring to the points.  The segments
   *   are defined by pair of integer indices.  The indices are within the range [0, iNbPoints - 1].
   *   However, an extra dummy point can be prepended to the array (index 0) if the segments start
   *   referencing the points at 1. Segments may be deleted and added in this set during processing.
   * @return
   *   S_OK if the method runs successfully and E_FAIL otherwise.
   */
  HRESULT Run (const CATMathPoint2D* iPoints, const int iNbPoints,
               CATHTableOfIntInt* ioSegments);

protected :

  const CATPolyExactArithmetic& _ExactArithmetic;
  int* _IndexMap;

  CATBoolean _RemoveOppositeSegments;

  HRESULT RemoveDuplicatePointsAndDegenerateSegments (const CATMathPoint2D* iPoints,
                                                      const int iNbPoints,
                                                      CATHTableOfIntInt* ioSegments);

  HRESULT ProcessIntersectingSegments (const CATMathPoint2D* iPoints,
                                       const int iNbPoints,
                                       CATHTableOfIntInt* ioSegments) const;

  HRESULT RemoveOppositeSegments (CATHTableOfIntInt* ioSegments) const;

};

#endif
