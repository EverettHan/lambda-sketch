// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonBuilder2D.h
//
//===================================================================
// March 2018 - Creation: ndo
//===================================================================
#ifndef CATPolyPolygonBuilder2D_H
#define CATPolyPolygonBuilder2D_H

#include "PolygonalOperators.h"
#include "CATErrorDef.h"     // HRESULT definition

class CATPolyPolygon2D;
class CATMathPoint2D;
class CATPolyPolygonObserver2D;


/**
 Operator that builds a polygon from a sequence of points defining the loops of a polygon.
 It constructs a polygon with just one solid face bounded by the input loops (multiple-loop polygon).
 It does not construct any other loops besides the input loops. 
 The output polygon can be fed to boolean operators as an input operand; the operator will then
 resolve any intersections there could be between the bars of the polygon.
*/

class ExportedByPolygonalOperators CATPolyPolygonBuilder2D
{

public:

  CATPolyPolygonBuilder2D () {}

  ~CATPolyPolygonBuilder2D () {}

public:

  /**
   * Interface of an iterator cycling through all the points for all
   * the loops of the polygon to build. The iterator provides access to the 
   * positions of the vertices for all the loops of the polygon.  
   *
   * If the polygon consists of just one loop (simple polygon), then it iterates
   * through all the positions in sequence just once. 
   * 
   * If the polygon consists of multiple loops, a null position must be returned 
   * after cycling through all the vertices of a loop before proceeding through 
   * the vertices of the next loop. This signals the completion of a loop. 
   * As for a simple polygon, the iterator should cycle through the vertices of
   * a loop just once.
   */
  class PointIterator
  {

  public:

    virtual PointIterator& Begin () = 0;

    virtual bool End () const = 0;

    virtual PointIterator& operator++ () = 0;

  public:

    /**
     * Returns a pointer to the position of the current vertex.
     * A null pointer signals the end of the construction of a loop.
     */
    virtual const CATMathPoint2D* GetPosition () = 0;

  };

public:

   /**
    * Builds a CATPolyPolygon2D object given an iterator cycling through the loops of the polygon face.
    * The solid face constructed in this manner may have multiple loops.
    * @param iPointIterator
    *   The iterator cycling through all the vertex positions of the polygon to construct.
    * @param oOutput Polygon
    *   The output polygon.  It must be deleted by the caller.
    * @param iObserver
    *   An optional observer of polygon events.  
    *   If set, this observer will be registered with the new polygon.
    *   It can be used to associate points added to the polygon (see PointIterator) to the new polygon vertices.
    */
  HRESULT Run (PointIterator& iPointIterator, CATPolyPolygon2D*& oOutputPolygon, CATPolyPolygonObserver2D* iObserver = 0);

};

#endif
