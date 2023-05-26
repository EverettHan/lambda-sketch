// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBuildBarPolygon2D.h
//
//===================================================================
// September 2015 Creation: ndo
//===================================================================
#pragma once

#include "PolygonalOperators.h"
#include "CATErrorDef.h"     // HRESULT definition

class CATPolyPolygon2D;


/**
 * Removes all the faces and loops of the polygon (if any) and constructs a
 * set of wires (one for each bar.)
 * This operator is useful when one wants to constructs a polygon for visualization.
 * The result polygon may have self intersections.
 */
class ExportedByPolygonalOperators CATPolyBuildBarPolygon2D
{

public :

  CATPolyBuildBarPolygon2D () {}

  ~CATPolyBuildBarPolygon2D () {}

  /**
   * Builds a polygon consisting of wires.
   * @param iSeparateBars
   *   If this argument is set to true, vertices of valence greater than one are duplicated to separate the bars.
   *   Each loop consists of one bar max in this case.
   */
  HRESULT Run (CATPolyPolygon2D& ioPolygon, bool iSeparateBars = true);

};
