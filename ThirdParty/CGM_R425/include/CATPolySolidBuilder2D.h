// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySolidBuilder2D.h
//
//===================================================================
// January 2009 Creation: ndo
//===================================================================
#ifndef CATPolySolidBuilder2D_H
#define CATPolySolidBuilder2D_H

#include "PolygonalOperators.h"
#include "CATErrorDef.h"     // HRESULT definition

class CATPolyPolygon2D;
class CATPolyVertex2D;
class CATPolyBar2D;

class CATMathPoint2D;
class CATPolyExactArithmetic;


/**
  This operator builds a valid CATPolyPolygon2D instance representing a solid object from a
  set of segments defining its boundaries.  A segment defining the boundary must separate solid 
  from void.

  The segments do not need to be consistently oriented.  However, they need to define distinct loops
  that represent the outer and inner boundaries of the solid.  It will fail otherwise as it cannot 
  remove the ambiguities.  For instance, if the input set includes segments that do not separate 
  solid from void, then the operator will fail.

  The segments should not be intersecting except at their shared vertices.

  In the following examples of valid and invalid sets of segments, the "*" represents the vertices.
  Segments are defined by sequences of "-" or "|".  The "." represents the solid part.

  Examples of a valid set of segments:

    (1) Simple polygon:                              (2) Complex polygon:

        *-----*-----------*                              *-----*-----------*
        |.................|                              |.................|
        |.................|                              |.................|
        |.................|                              |....*------*.....|
        |.................*                              |....|      |.....*
        |.................|                              |....|      |.....|
        |.................|                              |....*------*.....|
        |.................|                              |.................|
        |.................|                              |.................|
        *-----*----*------*                              *-----*----*------*

  Examples of an invalid set of segments (in each of these cases, there are segments that do not
  separate solid from void.)

    (3) Ambiguous:                                   (4) Ambiguous:

        *-----*-----------*                              *-----*-----------*
        |     |           |                              |.................|
        |     |           |                              |.................|
        |     |           |                              |....*--*---*.....|
        |  ?  |    ?      *                              |....|? | ? |.....*
        |     |           |                              |....|  |   |.....|
        |     |           |                              |....*------*.....|
        |     |           |                              |.................|
        |     |           |                              |.................|
        *-----*----*------*                              *-----*----*------*

    (5) Ambiguous:               

        *-----*-----------*
        |                 |
        |                 |
        |    ?            |
        |          *------|
        |          |      |
        |          |  ?   |
        |          |      |
        *-----*----*------*

  As long as there are no intersecting segments and ambiguous segments, the operator will not fail.

*/

class ExportedByPolygonalOperators CATPolySolidBuilder2D
{

public:

  CATPolySolidBuilder2D (const CATPolyExactArithmetic& iExactArithmetic);

  ~CATPolySolidBuilder2D ();

public:

  /**
   * Sets an empty polygon to be filled with the result of the operation.
   * @param ioResult
   *   An empty polygon.
   */
  void Set (CATPolyPolygon2D& ioResult);

public:

  /**
   * Adds a vertex to the polygon given its coordinates.
   */
  HRESULT AddVertex (const CATMathPoint2D& iPoint, CATPolyVertex2D* &oVertex);

  /**
   * Adds a segment (bar) to the polygon given two distinct vertices.
   * The segment separates solid from void.
   */
  HRESULT AddBar (CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1, CATPolyBar2D* &oBar);

public:

  /**
   * Constructs a valid CATPolyPolygon2D object representing the solid after addition
   * of all its vertices and bars.
   */
  HRESULT Run ();

private :

  const CATPolyExactArithmetic& _ExactArithmetic;

  CATPolyPolygon2D* _Polygon;  // Working polygon.

};

#endif
