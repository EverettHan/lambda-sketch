#ifndef CATICDSNURBSConicArc2D_H
#define CATICDSNURBSConicArc2D_H

// COPYRIGHT DASSAULT SYSTEMES  2013

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"
#include "CATICDSNURBSCurve2D.h"

class CATICDSPoint;
class CATICDSVariable;

/**
 *
 * A 2D NURBS conic arc constructed from an array of 3 control points, and a conic parameter (BezierRho).
 */
class ExportedBySolverInterface CATICDSNURBSConicArc2D : public CATICDSNURBSCurve2D
{
public:
 /**
  * Compute conic's properties.
  * @param oAxisDirection
  *   Direction from the directrix of the conic to the near focus.
  *   Consequently, it is also the direction from the near vertex
  *   to the near focus and it is perpendicular to the directrix.
  * @param oEccentricity
  *   Ratio of distances from any point on the conic to the focus
  *   over the distance from that point to the directrix.
  * @param oNearVertex
  *   It is the point on the conic closest to the directrix.
  * @param oNearFocus
  *   It is the nearest focus of oNearVertex.
  * @return
  *   TRUE if and only if the computation has succeeded.
  */
  virtual CATCDSBoolean ComputeConicProperties(double oAxisDirection[2], double& oEccentricity,
                                               double oNearVertex[2], double oNearFocus[2]) const = 0;
  
  /**
   * Returns the control point at the given index.
   * @param iIdx
   * Index of point to return. Must be 0 or greater and less or equal than 2.
   */
  //virtual CATICDSPoint2D* GetControlPoint(int iIdx) const = 0;


 /**
  * Returns the Bezier Rho parameter.
  */
  virtual CATICDSVariable* GetBezierRho() const = 0;


 /**
  * Constructs an instance of 2D NURBS conic arc.
  * @param iapPoints
  *   Array of 3 pointers to the conic arc control points in the following order :
  *   start point, middle point (intersection of the 2 tangents), end point
  * @param ipBezierRho
  *   Variable's value must be between 0 and 1 (0 and 1 excluded).
  *   It defines the conic's shape :
  *   - 0 < ipBezierRho < 0.5 : Ellipse arc.
  *   - ipBezierRho = 0.5     : Parabola arc.
  *   - 0.5 < ipBezierRho < 1 : Hyperbola arc.
  *   This value can change during the solve.
  * @SIZE iapPoints 3
  */
  static CATICDSNURBSConicArc2D* Create(CATICDSFactory *ipFactory,
                                        CATICDSPoint2D **iapPoints,
                                        CATICDSVariable *ipBezierRho);

  virtual ~CATICDSNURBSConicArc2D() {}
};

#endif
