// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBuildSimpleWireOper2D.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// December 2006 Creation: ndo
//===================================================================
#ifndef CATPolyBuildSimpleWireOper2D_H
#define CATPolyBuildSimpleWireOper2D_H

#include "PolygonalOperators.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"     // HRESULT definition

class CATPolyPolygon2D;
class CATMathPoint2D;


/**
 Operator that constructs a simple wire from a sequence of points.
*/

class ExportedByPolygonalOperators CATPolyBuildSimpleWireOper2D
{

public :

  CATPolyBuildSimpleWireOper2D ();

  ~CATPolyBuildSimpleWireOper2D ();

  // Construct a simple wire from a sequence of points.
  HRESULT Run (const int iNbVertices, const CATMathPoint2D* iPoints);

  /*
   * Get the result polygon.  The polygon returned must be deleted (delete) after use of this API.
   */
  CATPolyPolygon2D* GetPolygon ();

private :

  CATPolyPolygon2D* _Polygon;

};

#endif
