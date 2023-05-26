// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATCSNURBSSurface.h
// Header definition of CATCSNURBSSurface
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Sep 2010  Creation:                  Vadim Yelagin
//===================================================================
#ifndef CATCSNURBSSurface_H
#define CATCSNURBSSurface_H

#include "CATCDSVirtual.h"
#include "CATCSControledSurface.h"

class CATCDS3Point;

//-----------------------------------------------------------------------

/**
 * A concrete callback for 3D NURBS surface constucted on an array
 * of control points.
 */
class ExportedBySolverInterface CATCSNURBSSurface : public CATCSControledSurface
{
public:

  /**
   * Constructs an instance of 3D NURBS surface.
   * @param iUNbPoints
   * @param iVNbPoints
   *   Number of control points. Should be (iDegree+1) or greater.
   * @param iUDegree
   * @param iVDegree
   *   Degree of NURBS. Should be 0 or greater.
   * @param iaUKnots
   * @param iaVKnots
   *   Array of (iNbPoints+iDegree+1) knots, defining the NURBS shape
   *   and parameterization.
   *   iaKnots[i+1] should be equal to or greater than iaKnots[i].
   *   Lower and upper bound of surface parameter will be equal to
   *   iaKnots[iDegree] and iaKnots[iNbPoints] respectively.
   * @param iapPoints
   *   Array of iUNbPoints*iVNbPoints pointers to the NURBS control points.
   *   The order of points corresponds to NURBS definition, each point
   *   can be present in the array any number of times.
   * @param iaWeights
   *   Array of iUNbPoints*iVNbPoints weights, defining the NURBS shape.
   *   If iaWeights is NULL, equal weights are taken, and the surface is
   *   non-rational B-spline surface.
   * @param iUPeriodic
   * @param iVPeriodic
   *   Specifies, whether the NURBS parameterization is periodic.
   *   Does not affect the NURBS shape. In order to continuously connect
   *   the NURBS boundary points, iaKnots, iapPoints and iaWeights
   *   arrays should be properly "wrapped".
   */
  CATCSNURBSSurface(
    int iUNbPoints,
    int iVNbPoints,
    int iUDegree,
    int iVDegree,
    const double *iaUKnots,
    const double *iaVKnots,
    CATCSPoint** iapPoints,
    const double *iaWeights = 0,
    CATCDSBoolean iUPeriodic = FALSE,
    CATCDSBoolean iVPeriodic = FALSE);

  virtual ~CATCSNURBSSurface();

  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  int GetUNbOfControlPoints() const;
  int GetVNbOfControlPoints() const;
  int GetUDegree() const;
  int GetVDegree() const;
  const double* GetUKnots() const;
  const double* GetVKnots() const;
  CATCSPoint* GetControlPoint(int iIdx) const;
  const double* GetWeights() const;

  virtual CATCDSBoolean EvaluateDerivWRTControlPoint(
    double iU,
    double iV,
    const CATCSPoint* ipControlPoint,
    double oPoint[3][3],
    double oUDeriv[3][3],
    double oVDeriv[3][3]) CATCDSOverride;
  virtual CATParamType GetFirstLimits(
    double &oLow,
    double &oUp) CATCDSOverride;
  virtual CATParamType GetSecondLimits(
    double &oLow,
    double &oUp) CATCDSOverride;
  virtual void Evaluate(
    double  iU,
    double  iV,
    double* oaPoint,
    double* oaUDeriv,
    double* oaVDeriv,
    double* oaU2Deriv,
    double* oaUVDeriv,
    double* oaV2Deriv) CATCDSOverride;
  virtual CATCDSBoolean Regenerate() CATCDSOverride;
  virtual void GetDependencies(CATCDSLISTP(CATCSEntity) &oNodes) CATCDSOverride;

private:
  CATCDSBoolean _isOk;
  int _size;
  int _uNbPoints;
  int _vNbPoints;
  CATCSPoint** _apPoints;
  double* _aWeights;
  int _dim;
  int _uDegree;
  int _vDegree;
  double* _aUKnots;
  double* _aVKnots;
  CATCDSBoolean _isUPeriodic;
  CATCDSBoolean _isVPeriodic;
  CATCDS3Point* _aCoords;
  CATCDSBoolean _isBuffered;
  double _bufferedU;
  double _bufferedV;

  double* _aU0;
  double* _aU1;
  double* _aU2;
  double* _aV0;
  double* _aV1;
  double* _aV2;
  int _uShift;
  int _vShift;
  double* _aCoefs;
  double* _aUDerivs;
  double* _aVDerivs;
  double* _aU2Derivs;
  double* _aUVDerivs;
  double* _aV2Derivs;

  void EvaluateCoefs(double iU, double iV);
  void Erase();
};

//-----------------------------------------------------------------------

#endif
