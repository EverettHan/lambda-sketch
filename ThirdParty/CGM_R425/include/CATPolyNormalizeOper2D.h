// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyNormalizeOper2D.h
// Header definition of CATPolyNormalizeOper2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// December 2006 Creation: ndo
//===================================================================
#ifndef CATPolyNormalizeOper2D_H
#define CATPolyNormalizeOper2D_H

#include "PolygonalOperators.h"
#include "CATErrorDef.h"  // Definition of HRESULT.

class CATPolyPolygon2D;
class CATPolyExactArithmetic;


/**
 This operator normalizes a polygon.
*/
class ExportedByPolygonalOperators CATPolyNormalizeOper2D
{

public :

  CATPolyNormalizeOper2D (const CATPolyExactArithmetic* iExactArithmetic);

  ~CATPolyNormalizeOper2D ();

  HRESULT Run (CATPolyPolygon2D* iPolygon);

private :

  const CATPolyExactArithmetic* _ExactArithmetic;

};

#endif
