// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATCSNURBSConicArc2D.h
// Header definition of CATCSNURBSConicArc2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2013  Creation:                  GN6
//===================================================================
#ifndef CATCSNURBSConicArc2D_H
#define CATCSNURBSConicArc2D_H

#include "CATCDSVirtual.h"
#include "CATCSNURBSCurve2D.h"

class CATCDSNURBSCurve;

//-----------------------------------------------------------------------

/**
 * A concrete callback for 2D NURBS conic arc constucted on an array
 * of 3 control points.
 */
class ExportedBySolverInterface CATCSNURBSConicArc2D : public CATCSNURBSCurve2D
{
public:
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
  */
  CATCSNURBSConicArc2D(CATCSSketch* ipSketch,
                       CATCSPoint2D** iapPoints,
                       CATCSVariable* ipBezierRho);
  
  void SetGeometry(CATCSPoint2D** iapPoints,
                   CATCSVariable* ipBezierRho);

  // These methods are derived to prevent the user to use it for conic's arcs :
  // these methods don't have any sense for conic's arcs.
  virtual void SetGeometry(int iNbPoints, int iDegree, const double *iaKnots,
                           CATCSPoint2D** iapPoints, const double *iaWeights);
  virtual void SetGeometry(int iDegree, const double *iaKnots,
                           const double *iaWeights);

  virtual ~CATCSNURBSConicArc2D();

  CATCDSBoolean Regenerate() CATCDSOverride;

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
  CATCDSBoolean ComputeConicProperties(double oAxisDirection[2], double& oEccentricity,
                                       double oNearVertex[2], double oNearFocus[2]) const;
  
 /**
  * Returns the Bezier Rho parameter.
  */
  virtual CATCSVariable* GetBezierRho() const;

  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  virtual void GetDependencies(CATCDSLISTP(CATCSEntity) &oNodes) CATCDSOverride;
  
  // Evaluate the derivative with respect to the Bezier Rho parameter
  virtual CATCDSBoolean EvaluateDerivWRTControlVariable2D(double iT,
                                                          const CATCSVariable* ipControlVariable,
                                                          double oaPoint[2],
                                                          double oaFirstDeriv[2],
                                                          double oaSecondDeriv[2]) CATCDSOverride;
  
  /**
   * @nodoc only for internal use
   */
  CATCSNURBSConicArc2D();
 
  /**
   * @nodoc only for internal use
   */
  void CreateNURBSCurve(CATCSNEntity *ipNode);

private:
  //double ComputeWeightWithBezierRho() const;

  // This variable is created in this class.
  // Variable's value between 0 and 1 (0 and 1 excluded) defining the conic's shape.
  // 0 < iBezierRho < 0.5 : Ellipse arc.
  // iBezierRho = 0.5     : Parabola arc.
  // 0.5 < iBezierRho < 1 : Hyperbola arc.
  CATCSVariable* _pBezierRho;

};

//-----------------------------------------------------------------------

#endif
