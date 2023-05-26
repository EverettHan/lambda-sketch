// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATCSNURBSCurve2D.h
// Header definition of CATCSNURBSCurve2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2010  Creation:                  Vadim YELAGIN
//===================================================================
#ifndef CATCSNURBSCurve2D_H
#define CATCSNURBSCurve2D_H

#include "CATCDSVirtual.h"
#include "CATCSControledCurve2D.h"

class CATCDSNURBSCurve;

//-----------------------------------------------------------------------

/**
 * A concrete callback for 2D NURBS curve constucted on an array
 * of control points.
 */
class ExportedBySolverInterface CATCSNURBSCurve2D : public CATCSControledCurve2D
{
public:

 /**
  * Constructs an instance of 2D NURBS curve.
  * @param ipSketch
  *   A pointer to the sketch on which the 2D curve will be defined.
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
  *   Array of iNbPoints weights, defining the NURBS form.
  *   If iaWeights is NULL, equal weights are taken, and the curve is
  *   non-rational B-spline.
  */
  CATCSNURBSCurve2D(
    CATCSSketch* ipSketch,
    int iNbPoints,
    int iDegree,
    const double *iaKnots,
    CATCSPoint2D** iapPoints,
    const double *iaWeights = 0);

  /**
   * @nodoc only for internal use
   */
  CATCSNURBSCurve2D();

  ~CATCSNURBSCurve2D();

  /**
   * @nodoc only for internal use
   */
  void SetGeometry(int iNbPoints, int iDegree, const double *iaKnots, CATCSPoint2D** iapPoints, const double *iaWeights);
  void SetGeometry(int iDegree, const double *iaKnots, const double *iaWeights);

  CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;
  
  // Return the array of the coordinates of all control points.
  // The size of this array is 2*n control points
  double const * GetControlPointsCoords() const;
  void GetControlPointCoords(int iIndex, double &oX, double &oY);
  int GetNbOfControlPoints() const;
  int GetDegree() const;
  const double* GetKnots() const;
  CATCSPoint2D** GetControlPoints() const;
  CATCSPoint2D* GetControlPoint(int iIdx) const;
  const double* GetWeights() const;

  /**
  * EvaluateDerivWRTControlPoint2D() gives the Jacobian matrices of the three functions that map a given control point to a point resulting from an evaluation on the Nurbs
  * at a given parameter, or to the 1st or 2nd derivative of this evaluated point with respect to the parameter (and not to the control point)
  * @param iT
  *   Value of the Nurbs parameter 
  * @param ipControlPoint
  *   Pointer to the control point : the computed matrices oPoint[2][2], oFirstDeriv[2][2] and oSecondDeriv[2][2] are jacobian matrices 
  *   associated with the differential of functions that have this control point in input
  * @param oPoint
  *   Jacobian matrix of the function :ipControlPoint -> C(iT) if C stands for the NURBS Curve (note that oPoint is not a point but has dimension[2][2])
  * @param oFirstDeriv
  *   Jacobian matrix of the function :ipControlPoint -> dC/diT if C stands for the NURBS Curve (the derivative is w.r.t. the parameter)
  * @param oSecondDeriv
  *   Jacobian matrix of the function :ipControlPoint -> d2C/diT2 if C stands for the NURBS Curve (the 2nd derivative is w.r.t. the parameter)
 */
  CATCDSBoolean EvaluateDerivWRTControlPoint2D(
    double iT,
    const CATCSPoint2D* ipControlPoint,
    double oPoint[2][2],
    double oFirstDeriv[2][2],
    double oSecondDeriv[2][2]) CATCDSOverride;

  CATParamType GetLimits(
    double &oLow,
    double &oUp) CATCDSOverride;

  void Evaluate2D(
    double iT,
    double* oaPoint,
    double* oaFirstDeriv,
    double* oaSecondDeriv,
    double* oaThirdDeriv = 0) CATCDSOverride;

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

  virtual CATCDSBoolean Regenerate() CATCDSOverride;

  void GetDependencies(CATCDSLISTP(CATCSEntity) &oNodes) CATCDSOverride;

  CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) CATCDSOverride;

  // stubs
  int GetNbOfDiscontinuities() CATCDSOverride;
  void GetDiscontinuitiesParams(double*) CATCDSOverride;
  void EvaluateAtDiscontinuity2D(int iIdx,
                                         CATDiscontinuitySide iSide,
                                         double iT,
                                         double* oaPoint,
                                         double* oaFirstDeriv,
                                         double* oaSecondDeriv,
                                         double* oaThirdDeriv = 0) CATCDSOverride;

  void ApplyTransformation2D(double iMatrix[3][3]) CATCDSOverride;
  void GetDirection2D(double &oX, double &oY) CATCDSOverride;

  void GetBoundingBox(CATCDSBox *& oBox) CATCDSOverride;

  // Get the 2D box corresponding to a sub-interval of the parametric domain
  void Get2DBoundingBoxForSubDomain(double iWMin, double iWMax, CATCDSBox2D *& oBox) CATCDSOverride;
  
  CATCDSBoolean IsPeriodic() const;

  // IsValid() == TRUE if and only if the NURBS declaration is valid.
  CATCDSBoolean IsValid() const CATCDSOverride;

  /**
   * @nodoc only for internal use
   */
  virtual void CreateNURBSCurve(CATCSNEntity *ipNode);

  /**
   * @nodoc only for internal use
   */
  CATCDSBoolean IsDependencyCoincident(CATCSEntity const *ipDependency, double &oParam) const;

  /**
   * @nodoc only for internal use
   */
  CATCDSNURBSCurve* GetImp() { return _pImp; }

protected:
  CATCDSBoolean IsReady() const;
  CATCDSBoolean CheckValidity();

  CATCDSNURBSCurve *_pImp;
  int _NbPoints;
  int _Degree;
  double *_aKnots;
  CATCSPoint2D** _apPoints;
  double *_aWeights;

  CATCSExtrapolMode _extrapolMode;
  double _extrapolLow, _extrapolUp;

  CATCDSBoolean _isValid;
};

//-----------------------------------------------------------------------

#endif
