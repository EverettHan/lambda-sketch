// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPointInPolygonOper2D.h
//
//===================================================================
// June 2010 Creation: NDO
//===================================================================
#ifndef CATPolyPointInPolygonOper2D_H
#define CATPolyPointInPolygonOper2D_H

#include "PolygonalOperators.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATPolySegment2D;
class CATPolySegmentIterator2D;

class CATPolyArcPolygon2D;
class CATPolyPolygon2D;
class CATPolyLoop2D;
class CATPolyFace2D;
class CATPolyBar2D;

class CATPolyExactArithmetic;
class CATMathPoint2D;


/**
 * Operator checking if a point is inside, on or outside a polygon.
 *
 * See also CATPolyIsInsidePolygon in CATPolyGeoServices.h.
 * @see CATPolyGeoServices
*/
class ExportedByPolygonalOperators CATPolyPointInPolygonOper2D
{

public:

  /**
   * @param iExactArithmetic
   *   An exact arithmetic instance.
   */
  CATPolyPointInPolygonOper2D (const CATPolyExactArithmetic& iExactArithmetic);

  ~CATPolyPointInPolygonOper2D () {}

public:

  /**
   * Tests if a point is inside, on or outside a polygon. 
   * The polygon is defined by a sequence of segments (linear or circular).
   * @param iPointToTest
   *   The point to be tested.
   * @param iSegmentIterator
   *   An iterator through the segments of the polygon.
   * @return 
   * <ul>
   *   <li> -1: The point is outside the polygon.
   *   <li>  0: The point is on the polygon.
   *   <li> +1: The point is inside the polygon.
   * </ul>
   */
  int IsInsidePolygon (const CATMathPoint2D& iPointToTest, CATPolySegmentIterator2D& iSegmentIterator);

public:

  /**
   * Tests if a point is inside, on or outside a polygon. 
   * @param iPointToTest
   *   The point to be tested.
   * @param iPolygon
   *   The input polygon.  The polygon may have several faces. 
   *   However all bars of the polygons should be part of the boundary;
   *   This means they should be the border between a hole face and a solid face.
   * @return 
   * <ul>
   *   <li> -1: The point is outside the polygon.
   *   <li>  0: The point is on the polygon.
   *   <li> +1: The point is inside the polygon.
   * </ul>
   */
  int IsInsidePolygon (const CATMathPoint2D& iPointToTest, const CATPolyPolygon2D& iPolygon);

  /**
   * Tests if a point is inside, on or outside an arc polygon. 
   * The polygon is defined by a sequence of points forming a loop.
   * A segment is automatically added between the last and first point of the sequence to close the loop.
   * @param iPointToTest
   *   The point to be tested.
   * @param iPolygon
   *   The input polygon.
   * @return 
   * <ul>
   *   <li> -1: The point is outside the polygon.
   *   <li>  0: The point is on the polygon.
   *   <li> +1: The point is inside the polygon.
   * </ul>
   */
  int IsInsidePolygon (const CATMathPoint2D& iPointToTest, const CATPolyArcPolygon2D& iPolygon);

public:

  /**
   * Tests if a point is inside, on or outside a loop of a polygon. 
   * The polygon is defined by a sequence of points forming a loop.
   * A segment is automatically added between the last and first point of the sequence to close the loop.
   * @param iPointToTest
   *   The point to be tested.
   * @param iPolygon
   *   The input polygon.
   * @param iLoop
   *   The input loop.
   * @return 
   * <ul>
   *   <li> -1: The point is outside the polygon.
   *   <li>  0: The point is on the polygon.
   *   <li> +1: The point is inside the polygon.
   * </ul>
   */
  int IsInsidePolygon (const CATMathPoint2D& iPointToTest, 
                       const CATPolyPolygon2D& iPolygon, CATPolyLoop2D* iLoop);

  /**
   * Tests if a point is inside, on or outside a face of a polygon. 
   * The polygon is defined by a sequence of points forming a loop.
   * A segment is automatically added between the last and first point of the sequence to close the loop.
   * @param iPointToTest
   *   The point to be tested.
   * @param iPolygon
   *   The input polygon.
   * @param iFace
   *   The input face.
   * @return 
   * <ul>
   *   <li> -1: The point is outside the polygon.
   *   <li>  0: The point is on the polygon.
   *   <li> +1: The point is inside the polygon.
   * </ul>
   */
  int IsInsidePolygon (const CATMathPoint2D& iPointToTest, 
                       const CATPolyPolygon2D& iPolygon, CATPolyFace2D* iFace);

private:

  const CATPolyExactArithmetic& _ExactArithmetic;

private:

  CATPolyBar2D* IsInside (const CATMathPoint2D& iPointToTest, 
                          const CATPolyPolygon2D& iPolygon, CATPolyLoop2D* loop, int& isInside);

};

#endif
