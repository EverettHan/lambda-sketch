// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPoly2ndAreaMoment2D.h
//
//===================================================================
//
// Usage notes:
// Computes the 2nd Moment of Area on a polygonal model according to x
// and y axis passing through a given point.
//
//===================================================================
//
// 2015-06-18 Creation: XXC
//===================================================================

#ifndef CATPoly2ndAreaMoment2D_H
#define CATPoly2ndAreaMoment2D_H

#include "PolygonalOperators.h"

#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATPolyPolygon2D.h"
class CATMathPoint2D;
class CATMathVector2D;
class CATMathTransformation2D;

class CATPolyLoop2D;

/**
 * This operator compute the second moment of area of a planar surface
 * according to a reference position in both x, y and xy.
 */
class ExportedByPolygonalOperators CATPoly2ndAreaMoment2D
{
 public:
  
  /** Run the second moment of area computation on the given polygon.
   *@param iPolygon: the polygon on which we compute the moment of area.
   *@param iOrigin: positions of x and y axis.
   *@param Ix, Iy, Ixy: the moments according respectively with respect to x direction, y direction and the product moment of area.
   */
  static HRESULT Run (const CATPolyPolygon2D * iPolygon, const CATMathPoint2D & iOrigin, double & Ix, double & Iy, double & Ixy);

  /** Run the second moment of area computation on the given polygon relatively to provided axis and center.
   *@param iPolygon: the polygon on which we compute the moment of area.
   *@param iOrigin: positions of x and y axis.
   *@param iXaxis: direction of the x axis, must be orthogonal to the provided y axis and normalized.
   *@param iYaxis: direction of the y axis, must be orthogonal to the provided x axis and normalized.
   *@param Ix, Iy, Ixy: the moments according respectively with respect to x direction, y direction and the product moment of area.
   */
  static HRESULT Run (const CATPolyPolygon2D * iPolygon, const CATMathPoint2D & iOrigin, const CATMathVector2D & iXaxis, const CATMathVector2D & iYaxis,
                      double & Ix, double & Iy, double & Ixy);
  
 private:

  static HRESULT LoopSecondAreaMoment (CATPolyLoop2D * iLoop, const CATMathTransformation2D & i,
                                       double & Ix, double & Iy, double & Ixy);

};

#endif
