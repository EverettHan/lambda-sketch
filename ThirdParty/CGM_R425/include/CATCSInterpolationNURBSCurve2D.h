// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATCSInterpolationNURBSCurve2D.h
// Header definition of CATCSInterpolationNURBSCurve2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2011  Creation:                                         FCX
//===================================================================
#ifndef CATCSInterpolationNURBSCurve2D_H
#define CATCSInterpolationNURBSCurve2D_H

#include "CATCDSVirtual.h"
#include "CATCSControledCurve2D.h"

class CATCSLine2D;
class CATCSSketch;
class CATCSInterpolationNURBSCurveImp;
class CATCSNInterpolationNURBSCurve;
class CATCDSBox2D;

//-----------------------------------------------------------------------

/**
* A concrete callback for 2D NURBS curve constucted from interpolation
* conditions.
*/

/*
* Prerequisite :
*  there is at least 2 points for the interpolation
*  the interpolation conditions are given in the growing parameter order
*/
class ExportedBySolverInterface CATCSInterpolationNURBSCurve2D : public CATCSControledCurve2D
{
public:
  CATCSInterpolationNURBSCurve2D();
  ~CATCSInterpolationNURBSCurve2D();

  void SetPeriodic(CATCDSBoolean iPeriodic);

  void SetConditions(int iNbConditions, CATCSInterpolConditionType *iaConditionTypes, double *iaConditionParameters, CATCSPoint2D **iapConditionPoints,
    CATCSVariable **iapConditionVariables, CATCSLine2D **iapConditionLines, double *iaConditionValues);  

  int GetNbOfInterpolationPoints() const;
  CATCSPoint2D* GetInterpolationPoint(int iIdx) const;
  double GetInterpolationPointParameter(int iIdx) const;
  CATCSLine2D* GetFirstDerivativeDirection(int iIdx) const;
  CATCDSBoolean GetFirstDerivativeNorm(int iIdx, double & oValue) const;
  CATCSVariable* GetFirstDerivativeNorm(int iIdx) const;
  CATCSLine2D* GetSecondDerivativeDirection(int iIdx) const;
  CATCDSBoolean GetSecondDerivativeNorm(int iIdx, double & oValue) const;
  CATCSVariable* GetSecondDerivativeNorm(int iIdx) const;
  CATCDSBoolean GetCurvature(int iIdx, double & oValue) const;
  CATCSVariable* GetCurvature(int iIdx) const;

  int FindDependence(CATCSEntity const *ipEntity) const;

  void AddInterpolationPoint(int iIdx, CATCSPoint2D *ipPoint);
  void RemoveInterpolationPoint(int iIdx);
  void SetFirstDerivativeDirection(int iIdx, CATCSLine2D *ipLine);
  void RemoveFirstDerivativeDirection(int iIdx);
  void SetFirstDerivativeNorm(int iIdx, double iNorm);
  void SetFirstDerivativeNorm(int iIdx, CATCSVariable *ipVariable);
  void RemoveFirstDerivativeNorm(int iIdx);
  void SetSecondDerivativeDirection(int iIdx, CATCSLine2D *ipLine);
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

  void SetDegree(int iDegree);
  int GetDegree() const;
  int GetCurrentDegree() const;

  void SetInterpParametersAndKnots(int iDegree, double *iaConditionParameters, double *iaKnots);
  void SetInterpParametersAndKnots(double *iaConditionParameters, double *iaKnots);

  CATCDSBoolean HasKnots() const;
  double const * GetKnots() const;
  double const * GetWeights() const;
  int GetNbOfControlPoints() const;
  void GetControlPointCoords(int iIndex, double &oX, double &oY) const;
  double const * GetControlPointsCoords() const; 

  CATParamType GetLimits(double &oLow, double &oUp) CATCDSOverride;

  int GetNbOfDiscontinuities() CATCDSOverride;
  void GetDiscontinuitiesParams(double*) CATCDSOverride;

  void Evaluate2D(double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv = 0) CATCDSOverride;

  void EvaluateAtDiscontinuity2D(int iIdx, CATDiscontinuitySide iSide, double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv = 0) CATCDSOverride;

  CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) CATCDSOverride;

  void ApplyTransformation2D(double iMatrix[3][3]) CATCDSOverride;
  void GetDirection2D(double &oX, double &oY) CATCDSOverride;

  void GetBoundingBox(CATCDSBox *& oBox) CATCDSOverride;

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
  CATCDSBox2D *_pBoundingBox;

  friend class CATCSNInterpolationNURBSCurve;
  friend class CATCDSLoaderImp;
};

//-----------------------------------------------------------------------

#endif
