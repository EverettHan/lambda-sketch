// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInvertOrientationOper2D.h
//
//===================================================================
// October 2006  Creation: NDO
//===================================================================
#ifndef CATPolyInvertOrientationOper2D_H
#define CATPolyInvertOrientationOper2D_H

#include "PolygonalOperators.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)

class CATPolyPolygon2D;


/**
 * This operator inverts the orientation of a CATPolyPolygon2D object.
 * CCW loops become CW loops and vice-versa.
 * See CATPolySwitchOrientation () in CATPolyPolygonServices2D.
 * @see CATPolyPolygonServices2D
 */
class ExportedByPolygonalOperators CATPolyInvertOrientationOper2D 
{

public:

  CATPolyInvertOrientationOper2D () {}

  ~CATPolyInvertOrientationOper2D () {}

  /**
   * Runs the operator.
   * The operator is done in-place.
   * @return
   *   S_OK if the operator runs successfully and E_FAIL otherwise.
   */
  HRESULT Run (CATPolyPolygon2D& ioPolygon);

public:

  /**
   * @deprecated
   */
  inline HRESULT Run (CATPolyPolygon2D* ioPolygon);

};

inline HRESULT CATPolyInvertOrientationOper2D::Run (CATPolyPolygon2D* ioPolygon)
{
  return ioPolygon ? Run (*ioPolygon) : S_FALSE;
}

#endif
