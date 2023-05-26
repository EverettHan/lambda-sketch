// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyConvexHullOper2D.h
//
//===================================================================
// Mars 2008 Creation: zfi
//===================================================================
#ifndef CATPolyConvexHullOper2D_H
#define CATPolyConvexHullOper2D_H

#include "PolygonalOperators.h"
#include "CATErrorDef.h"  // Definition of HRESULT.
#include "CATBoolean.h"
#include "CATListPV.h"

class CATPolyPolygon2D;
class CATPolyExactArithmetic;
class CATPolyVertex2D;


class ExportedByPolygonalOperators CATPolyConvexHullOper2D
{
public :

  CATPolyConvexHullOper2D (const CATPolyExactArithmetic& iExactArithmetic);
  ~CATPolyConvexHullOper2D ();
  
  /**
   * Computes the convex hull (convex contour) of a set of points.
   * @param iPolygon
   *   Polygon containing the set of points
   * @param oVertices
   *  A list of pointers(CATPolyVertex2D*), containing sorted vertices of the computed contour
   * @return
   *   S_OK if the contour is computer successfully.
   *   E_FAIL otherwise.
   */
  HRESULT Run (const CATPolyPolygon2D& iPolygon, CATListPV& oVertices) const;

private:

  CATBoolean RightTurn (CATPolyVertex2D* iV1,CATPolyVertex2D* iV2,CATPolyVertex2D* iV3) const;

private :

  const CATPolyExactArithmetic& _ExactArithmetic;

};

#endif
