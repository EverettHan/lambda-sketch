// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCheckOper2D.h
//
//===================================================================
// November 2004 Creation: ndo
//===================================================================
#ifndef CATPolyCheckOper2D_H
#define CATPolyCheckOper2D_H

#include "PolygonalBoolean.h"
#include "IUnknown.h"   // For the definition of HRESULT.
#include "CATBoolean.h"
#include "CATPolyIntersection.h"
#include "CATPolyPolygon2D.h"

class CATPolyVertex2D;
class CATPolyExactArithmetic;
class CATMathPoint2D;


/**
 This operator checks a polygon or a list of segments for intersection others than shared vertices.
 It reports an error when two bars or two segments intersect.
*/
class ExportedByPolygonalBoolean CATPolyCheckOper2D
{

public :

  inline CATPolyCheckOper2D (const CATPolyExactArithmetic& iExactArithmetic);

  ~CATPolyCheckOper2D () {}
 
  /**
   * Finds if there is an intersection between two input segments in O(n log n). 
   * The method reports the type of the intersection in an argument (see CATPolyIntersection::IntersectionType).
   * @param iPoints
   *   An array of points that the segments are referring to.
   * @param iNbPoints
   *   The number of points.
   * @param iSegments
   *   An array of point indices defining the segments.  Each segment is defined by a pair of points.
   *   The segments are stored consecutively in this array.
   *   The size of this array is 2 * iNbSegments.
   * @param iNbSegments
   *   The number of segments to test.
   * @param oIntersectionType
   *   The type of intersection between the segments (see CATPolyIntersection::IntersectionType.)
   * @param oSegment0Beg
   *   The index of the start of Segment 0 that intersects with Segment 1.
   * @param oSegment0End
   *   The index of the end of Segment 0 that intersects with Segment 1.
   * @param oSegment1Beg
   *   The index of the start of Segment 1 that intersects with Segment 0.
   * @param oSegment1End
   *   The index of the end of Segment 1 that intersects with Segment 0.
   * @param oClosestPoint
   *   The index of an extremity of Segment 0 or 1 that is the closest to the other segment (respectively,
   *   Segment 1 or 0).  If the segments are colinear, this is the index of an extremity on the other segment.
   *   If the segments are identical, then this index is set to -1.
   * @return
   *   S_OK if the method runs successfully and E_FAIL otherwise.
   */
  HRESULT Run (const CATMathPoint2D* iPoints, const int iNbPoints,
               const int* iSegments, const int iNbSegments,
               int& oIntersectionType,
               int& oSegment0Beg, int& oSegment0End,
               int& oSegment1Beg, int& oSegment1End,
               int& oClosestPoint) const;

  /**
   * Finds if there is an intersection between two bars of the input polygon in O(n log n). 
   * The method reports the type of the intersection in an argument (see CATPolyIntersection::IntersectionType).
   * @param iPolyPolygon
   *   The input CATPolyPolygon2D.
   * @param oIntersectionType
   *   The type of intersection between the bars (see CATPolyIntersection::IntersectionType.)
   * @param oBar0Vertex0
   *   The start vertex of the first intersecting bar.
   * @param oBar0Vertex1
   *   The end vertex of the first intersecting bar.
   * @param oBar1Vertex0
   *   The start vertex of the second intersecting bar.
   * @param oBar1Vertex1
   *   The end vertex of the second intersecting bar.
   * @param oClosestVertex
   *   One of the vertex from Bar 0 or Bar 1 which is the closest to the other bar (respectively,
   *   Bar 1 or 0).  If the bars are colinear, this is the vertex lying on the other bar.
   * @return
   *   S_OK if the method runs successfully and E_FAIL otherwise.
   */
  HRESULT Run (const CATPolyPolygon2D& iPolygon,
               int& oIntersectionType,
               CATPolyVertex2D*& oBar0Vertex0, CATPolyVertex2D*& oBar0Vertex1,
               CATPolyVertex2D*& oBar1Vertex0, CATPolyVertex2D*& oBar1Vertex1,
               CATPolyVertex2D*& oClosestVertex) const;

public:

  HRESULT FullCheck (const CATPolyPolygon2D& iPolygon, 
                     CATPolyIntersection::Type& oIntersectionType,
                     CATPolyPolygon2D::Orientation& oOrientation) const;

protected:

  const CATPolyExactArithmetic& _ExactArithmetic;

protected:

  HRESULT CheckPrivate (const CATPolyPolygon2D& iPolygon,
                        CATPolyIntersection::Type& oIntersectionType,
                        CATPolyVertex2D*& oBar0Vertex0, CATPolyVertex2D*& oBar0Vertex1,
                        CATPolyVertex2D*& oBar1Vertex0, CATPolyVertex2D*& oBar1Vertex1,
                        CATPolyVertex2D*& oClosestVertex,
                        CATPolyPolygon2D::Orientation& oOrientation) const;

public:

  // DO NOT USE.
  inline CATPolyCheckOper2D (const CATPolyExactArithmetic* iExactArithmetic);

};

inline CATPolyCheckOper2D::CATPolyCheckOper2D (const CATPolyExactArithmetic& iExactArithmetic) :
  _ExactArithmetic (iExactArithmetic)
{
}

// Obsolete
inline CATPolyCheckOper2D::CATPolyCheckOper2D (const CATPolyExactArithmetic* iExactArithmetic) :
  _ExactArithmetic (*iExactArithmetic)
{
}

#endif
