// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATCSInterpolationNURBSCurve.h
// Header definition of CATCSInterpolationNURBSCurve
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jan 2012  Creation:                  GN6
//===================================================================
#ifndef CATCSInterpolationNURBSCurve_H
#define CATCSInterpolationNURBSCurve_H


#include "CATCDSVirtual.h"
#include "CATCSControledCurve.h"

class CATCSLine;
class CATCSInterpolationNURBSCurveImp;
class CATCSNInterpolationNURBSCurve;

//-----------------------------------------------------------------------

/**
 * A concrete callback for 3D NURBS curve constructed on an array
 * of control points.
 */
class ExportedBySolverInterface CATCSInterpolationNURBSCurve : public CATCSControledCurve
{
public:
  CATCSInterpolationNURBSCurve();
  ~CATCSInterpolationNURBSCurve();

  void SetPeriodic(CATCDSBoolean iPeriodic);

  void SetConditions(int iNbConditions, CATCSInterpolConditionType *iaConditionTypes, double *iaConditionParameters, CATCSPoint **iapConditionPoints,
    CATCSVariable **iapConditionVariables, CATCSLine **iapConditionLines, double *iaConditionValues);

  int GetNbOfInterpolationPoints() const;
  CATCSPoint* GetInterpolationPoint(int iIdx) const;
  double GetInterpolationPointParameter(int iIdx) const;
  CATCSLine* GetFirstDerivativeDirection(int iIdx) const;
  CATCDSBoolean GetFirstDerivativeNorm(int iIdx, double & oValue) const;
  CATCSVariable* GetFirstDerivativeNorm(int iIdx) const;
  CATCSLine* GetSecondDerivativeDirection(int iIdx) const;
  CATCDSBoolean GetSecondDerivativeNorm(int iIdx, double & oValue) const;
  CATCSVariable* GetSecondDerivativeNorm(int iIdx) const;
  CATCDSBoolean GetCurvature(int iIdx, double & oValue) const;
  CATCSVariable* GetCurvature(int iIdx) const;

  int FindDependence(CATCSEntity const *ipEntity) const;

  void AddInterpolationPoint(int iIdx, CATCSPoint *ipPoint);
  void RemoveInterpolationPoint(int iIdx);
  void SetFirstDerivativeDirection(int iIdx, CATCSLine *ipLine);
  void RemoveFirstDerivativeDirection(int iIdx);
  void SetFirstDerivativeNorm(int iIdx, double iNorm);
  void SetFirstDerivativeNorm(int iIdx, CATCSVariable *ipVariable);
  void RemoveFirstDerivativeNorm(int iIdx);
  void SetSecondDerivativeDirection(int iIdx, CATCSLine *ipLine);
  void RemoveSecondDerivativeDirection(int iIdx);
  void SetSecondDerivativeNorm(int iIdx, double iNorm);
  void SetSecondDerivativeNorm(int iIdx, CATCSVariable *ipVariable);
  void RemoveSecondDerivativeNorm(int iIdx);
  void SetCurvature(int iIdx, double iCurvature);
  void SetCurvature(int iIdx, CATCSVariable *ipVariable);
  void RemoveCurvature(int iIdx);

  CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  void GetDependencies(CATCDSLISTP(CATCSEntity) &oNodes) CATCDSOverride; 
  
  CATCDSBoolean Regenerate() CATCDSOverride;
  
  CATCDSBoolean Extrapolate(double iNewLow, double iNewUp, CATCSExtrapolMode iMode) CATCDSOverride;

  CATCDSBoolean IsParameterizationFixed() const;
  CATCDSBoolean IsPeriodic() const;
  
  //int GetNbPassagePoints() const;

  int GetDegree() const;
  int GetCurrentDegree() const;
  void SetDegree(int iDegree);

  void SetInterpParametersAndKnots(int iDegree, double *iaConditionParameters, double *iaKnots);
  void SetInterpParametersAndKnots(double *iaConditionParameters, double *iaKnots);

  CATCDSBoolean HasKnots() const;
  double const * GetKnots() const;
  double const * GetWeights() const;
  int GetNbOfControlPoints() const;
  void GetControlPointCoords(int iIndex, double &oX, double &oY, double &oZ) const;
  double const * GetControlPointsCoords() const;
  
  /*void GetPassagePointCoords(int iIndex, double & oX, double & oY, double & oZ) const;
  void GetFirstDerivative(int iIndex, double & oX, double & oY, double & oZ) const;
  void GetSecondDerivative(int iIndex, double & oX, double & oY, double & oZ) const;
  void GetSecondDerivativeNorm(int iIndex, double & oNorm) const;
  void GetFirstDerivativeDir(int iIndex, double & oX, double & oY, double & oZ) const;
  void GetFirstDerivativeNorm(int iIndex, double & oNorm) const;  */
  
  CATParamType GetLimits(double &oLow, double &oUp) CATCDSOverride;

  int GetNbOfDiscontinuities() CATCDSOverride;
  void GetDiscontinuitiesParams(double*) CATCDSOverride;

  void Evaluate(double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv) CATCDSOverride;

  void EvaluateAtDiscontinuity(int iIdx, CATDiscontinuitySide iSide, double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv) CATCDSOverride;

  CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) CATCDSOverride;

  // IsValid() == TRUE if and only if the NURBS declaration is valid.
  CATCDSBoolean IsValid() const CATCDSOverride;

  void ComputeNURBSDefinition(int &onControlPoints, int &oDegree, double const *&oaKnots, double const *&oaControlPointsCoords, double const *&oaWeights) const;
  void ComputeClampedNURBSDefinition(int &onControlPoints, int &oDegree, double *&oaKnots, double *&oaControlPointsCoords, double *&oaWeights) const;

  void SetUseChordLengthParametrization(CATCDSBoolean iUseChordLengthParametrization);
  CATCDSBoolean IsUseChordLengthParametrization() const;

  void CreateInterpolationNURBSCurve(CATCSNEntity *ipNode);


private:
  CATCDSBoolean IsTangentLine(CATCSEntity *ipEntity) const;

  CATCDSBoolean IsCurvatureLine(CATCSEntity *ipEntity) const;

  double GetDependencyParameter(CATCSEntity const *ipDependency) const;

  CATCSInterpolationNURBSCurveImp *_pImp;

  friend class CATCSNInterpolationNURBSCurve;
  friend class CATCDSLoaderImp;
};

//-----------------------------------------------------------------------

#endif
