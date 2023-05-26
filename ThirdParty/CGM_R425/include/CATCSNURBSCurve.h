// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATCSNURBSCurve.h
// Header definition of CATCSNURBSCurve
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2010  Creation:                  Vadim YELAGIN
//===================================================================
#ifndef CATCSNURBSCurve_H
#define CATCSNURBSCurve_H

#include "CATCDSVirtual.h"
#include "CATCSControledCurve.h"

class CATCDSNURBSCurve;

//-----------------------------------------------------------------------

/**
 * A concrete callback for 3D NURBS curve constructed on an array
 * of control points.
 */
class ExportedBySolverInterface CATCSNURBSCurve : public CATCSControledCurve
{
public:

  /**
   * Constructs an instance of 3D NURBS curve.
   * @param iNbPoints
   *   Number of control points. Should be (iDegree+1) or greater.
   * @param iDegree
   *   Degree of NURBS. Should be 1 or greater.
   * @param iaKnots
   *   Array of (iNbPoints+iDegree+1) knots, defining the NURBS shape
   *   and parameterization.
   *   iaKnots[i+1] should be equal to or greater than iaKnots[i].
   *   Lower and upper bound of curve parameter will be equal to
   *   iaKnots[iDegree] and iaKnots[iNbPoints] respectively.
   * @param iapPoints
   *   Array of iNbPoints pointers to the NURBS control points.
   *   The order of points corresponds to NURBS definition, each point
   *   can be present in the array any number of times.
   * @param iaWeights
   *   Array of iNbPoints weights, defining the NURBS shape.
   *   If iaWeights is NULL, equal weights are taken, and the curve is
   *   non-rational B-spline.
   * @param iPeriodic
   *   Specifies, whether the NURBS parameterization is periodic.
   *   Does not affect the NURBS shape. In order to continuously connect
   *   the NURBS boundary points, iaKnots, iapPoints and iaWeights
   *   arrays should be properly "wrapped".
   */
  CATCSNURBSCurve(
    int iNbPoints,
    int iDegree,
    const double *iaKnots,
    CATCSPoint** iapPoints,
    const double *iaWeights = 0);

  /**
   * @nodoc only for internal use
   */
  CATCSNURBSCurve();

  ~CATCSNURBSCurve();


  /**
   * @nodoc only for internal use
   */
  void SetGeometry(int iNbPoints, int iDegree, const double *iaKnots, CATCSPoint** iapPoints, const double *iaWeights);
  void SetGeometry(int iDegree, const double *iaKnots, const double *iaWeights);

  CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;
  
  // Return the array of the coordinates of all control points.
  // The size of this array is 3*n control points
  double const * GetControlPointsCoords() const;
  void GetControlPointCoords(int iIndex, double &oX, double &oY, double &oZ);
  int GetNbOfControlPoints() const;
  int GetDegree() const;
  const double* GetKnots() const;
  CATCSPoint** GetControlPoints() const;
  CATCSPoint* GetControlPoint(int iIdx) const;
  const double* GetWeights() const;

  /**
  * EvaluateDerivWRTControlPoint() gives the Jacobian matrices of the three functions that map a given control point to a point resulting from an evaluation on the Nurbs
  * at a given parameter, or to the 1st or 2nd derivative of this evaluated point with respect to the parameter (and not to the control point)
  * @param iT
  *   Value of the Nurbs parameter 
  * @param ipControlPoint
  *   Pointer to the control point : the computed matrices oPoint[3][3], oFirstDeriv[3][3] and oSecondDeriv[3][3] are jacobian matrices 
  *   associated with the differential of functions that have this control point in input
  * @param oPoint
  *   Jacobian matrix of the function :ipControlPoint -> C(iT) if C stands for the NURBS Curve (note that oPoint is not a point but has dimension[3][3])
  * @param oFirstDeriv
  *   Jacobian matrix of the function :ipControlPoint -> dC/diT if C stands for the NURBS Curve (the derivative is w.r.t. the parameter)
  * @param oSecondDeriv
  *   Jacobian matrix of the function :ipControlPoint -> d2C/diT2 if C stands for the NURBS Curve (the 2nd derivative is w.r.t. the parameter)
 */
  CATCDSBoolean EvaluateDerivWRTControlPoint(
    double iT,
    const CATCSPoint* ipControlPoint,
    double oPoint[3][3],
    double oFirstDeriv[3][3],
    double oSecondDeriv[3][3]) CATCDSOverride;
  
  CATParamType GetLimits(
    double &oLow,
    double &oUp) CATCDSOverride;

  void Evaluate(
    double iT,
    double* oaPoint,
    double* oaFirstDeriv,
    double* oaSecondDeriv,
    double* oaThirdDeriv) CATCDSOverride;
 
  // Extend the parametric domain from [Low, Up] to [iNewLow, iNewUp], assuming iNewLow<Low and iNewUp>Up
  // Returns FALSE if extrapolation is not allowed for the given curve and/or for the given extrapolation mode
  // derived from CATCSCurve2D
  CATCDSBoolean Extrapolate(double iNewLow, double iNewUp, CATCSExtrapolMode iMode = exLINEAR) CATCDSOverride;

  CATCSExtrapolMode GetExtrapolationMode() const CATCDSOverride;
  CATCSExtrapolMode GetExtrapolationMode(double & oNewLow, double & oNewUp) const;

  // Get the initial limits, not taking into account a possible extrapolation
  // This method must be redefined in all classes that implement Extrapolate() method
  // derived from CATCSCurve2D
  CATParamType GetInitialLimits(double &oInitialLow, double &oInitialUp) CATCDSOverride;

  CATCDSBoolean Regenerate() CATCDSOverride;
 
  void GetDependencies(CATCDSLISTP(CATCSEntity) &oNodes) CATCDSOverride;

  CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) CATCDSOverride;

  // stubs
  int GetNbOfDiscontinuities() CATCDSOverride;
  void GetDiscontinuitiesParams(double*) CATCDSOverride;
  void EvaluateAtDiscontinuity(int iIdx,
                                       CATDiscontinuitySide iSide,
                                       double iT,
                                       double* oaPoint,
                                       double* oaFirstDeriv,
                                       double* oaSecondDeriv,
                                       double* oaThirdDeriv) CATCDSOverride;
  
  CATCDSBoolean IsPeriodic() const;

  // IsValid() == TRUE if and only if the NURBS declaration is valid.
  CATCDSBoolean IsValid() const CATCDSOverride;

  /**
   * @nodoc only for internal use
   */
  void CreateNURBSCurve(CATCSNEntity *ipNode);

  CATCDSBoolean IsDependencyCoincident(CATCSEntity const *ipDependency, double &oParam) const;
  
private:
  CATCDSBoolean CheckValidity();

  CATCDSBoolean IsReady() const;

  int _NbPoints;
  int _Degree;
  double *_aKnots;
  CATCSPoint** _apPoints;
  double *_aWeights;

  CATCSExtrapolMode _extrapolMode;
  double _extrapolLow, _extrapolUp;

  CATCDSBoolean _isValid;
  CATCDSNURBSCurve *_pImp;
};

//-----------------------------------------------------------------------

#endif
