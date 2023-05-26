// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBuildSimplePolygonOper2D.h
//
//===================================================================
// December 2006 Creation: ndo
//===================================================================
#ifndef CATPolyBuildSimplePolygonOper2D_H
#define CATPolyBuildSimplePolygonOper2D_H

#include "PolygonalOperators.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"     // HRESULT definition

class CATPolyPolygon2D;
class CATMathPoint2D;


/**
 Operator that constructs a simple polygon from a sequence of points forming a loop.
*/

class ExportedByPolygonalOperators CATPolyBuildSimplePolygonOper2D
{

public :

  CATPolyBuildSimplePolygonOper2D ();

  ~CATPolyBuildSimplePolygonOper2D ();

  void SetPolygon(CATPolyPolygon2D &ioResult);

  /**
   * Constructs a simple polygon from a sequence of points forming a loop.  First and last point in the 
   * array of points should not be the same.
   * @param iNbVertices
   *   The number of vertices in the array of points.
   * @param iPoints
   *   An array of CATMathPoint2D to be added to the polygon.
   * @param iInvertOrientation
   *   An optional argument to invert the orientation of the loop.
   */
  HRESULT Run (const int iNbVertices, const CATMathPoint2D* iPoints, 
               const CATBoolean iInvertOrientation = FALSE);

  /**
   * Extracts the constructed polygon from the operator after a call to the Run method.  
   * @return
   *   The constructed polygon.  This polygon should be deleted after a call to this method.
   */
  CATPolyPolygon2D* GetPolygon ();

private :

  CATPolyPolygon2D* _Polygon;
  bool _ownsPolygon;
};

inline void CATPolyBuildSimplePolygonOper2D::SetPolygon(CATPolyPolygon2D &ioResult)
{
  _Polygon = &ioResult;
  _ownsPolygon = false;
}

#endif
