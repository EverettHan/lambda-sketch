// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCATPolySegmentIterator2D.h
//
//===================================================================
// June 2010 Creation: NDO
//===================================================================
#ifndef CATPolyCATPolySegmentIterator2D_H
#define CATPolyCATPolySegmentIterator2D_H

#include "CATErrorDef.h"
#include "CATBoolean.h"


/**
* Interface to a segment iterator.
* A segment can be:
* <ul>
*   <li> A straight-line segment;
*   <li> A circular-arc segment.
* </ul>
*/
class CATPolySegmentIterator2D
{

public:

  virtual CATPolySegmentIterator2D& Begin () = 0;
  virtual CATBoolean End () const = 0;
  virtual CATPolySegmentIterator2D& operator++ () = 0;

public:

  /**
    * Returns the start point of the segment.
    */
  virtual const CATMathPoint2D& GetStartPoint () const = 0;

  /**
    * Returns the end point of the segment.
    */
  virtual const CATMathPoint2D& GetEndPoint () const = 0;

  /**
    * Returns an arc point of the segment if the segment is a circular arc.
    */
  virtual const CATMathPoint2D* GetArcPoint () const = 0;

};

#endif
