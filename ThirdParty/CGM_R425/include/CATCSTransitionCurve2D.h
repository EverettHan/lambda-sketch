// COPYRIGHT DASSAULT SYSTEMES 2016

#ifndef CATCSTransitionCurve2D_H
#define CATCSTransitionCurve2D_H

#include "CATCDS.h"
#include "CATCDSVirtual.h"
#include "CATCDSEnums.h"
#include "CATICDSBBoxCurve2DAdapter.h"
#include "CATCDSListP.h"

class CATConstraintSolver;
class CATCSCircle2D;
class CATCSLine2D; 
class CATCSPoint2D;
class CATCurve;
class CATGeoFactory;
class CATICDSClothoidAdapter;
class CATCDSStream;
class CATCivilCurveEvaluator;

#define MAX_CLOTHO_PARAMS 2

// ----------------------------------------------------------------------
// te9, creation
//-----------------------------------------------------------------------

class ExportedBySolverInterface CATCSTransitionCurve2D : public CATCSCurve2D
{
public:
 
  virtual CATCDSBoolean IsValid() const = 0;

  virtual CATParamType GetLimits(double &oLow, double &oUp)  = 0;

  virtual CATCDSBoolean Regenerate()  = 0;

  virtual void GetDependencies(CATCDSLISTP(CATCSEntity) &oNodes) const = 0;

  virtual void Evaluate2D(double iT,
                  double* oaPoint,
                  double* oaFirstDeriv,
                  double* oaSecondDeriv,
                  double* oaThirdDeriv = 0) = 0;

  virtual int GetNbOfDiscontinuities() const  = 0;

  virtual void GetDiscontinuitiesParams(double *oaValues) const  = 0;

  virtual void EvaluateAtDiscontinuity2D(int iIdx,
                                 CATDiscontinuitySide iSide,
                                 double iT,
                                 double* oaPoint,
                                 double* oaFirstDeriv,
                                 double* oaSecondDeriv,
                                 double* oaThirdDeriv = 0)   = 0;

  virtual void GetDirection2D(double &oX, double &oY)   = 0;

  virtual void ApplyTransformation2D(double iMatrix[3][3]) = 0;

  virtual CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength)  = 0;

  //virtual CATCDSBoolean IsMatched(CATCSType iType) const  = 0;

  virtual void GetDependencies(CATCDSLISTP(CATCSEntity) &oNodes) = 0;

  virtual void SetClothoidAdapter(CATICDSClothoidAdapter * ipAdapter) = 0;

  virtual void SetInitialPoint(CATCSPoint2D* ipInitialPoint) = 0;

  virtual void SetInitialLine(CATCSLine2D* ipInitialLine, int iOrientation) = 0;

  virtual void SetInitialCircle(CATCSCircle2D* ipInitialCircle, int iOrientation) = 0;

  virtual void SetInitialSpiral(CATCSTransitionCurve2D* ipInitialSpiral, int iOrientation) = 0;

  virtual void SetFinalPoint(CATCSPoint2D* ipFinalPoint) = 0;

  virtual void SetFinalLine(CATCSLine2D* ipFinalLine, int iFinalOrient) = 0;

  virtual void SetFinalCircle(CATCSCircle2D* ipFinalCircle) = 0;

  virtual void SetSide(int const& iSide) = 0;

  virtual void SetInitialParameters(double const *ipA2, double const *ipLength, double const *ipRadius, double const *ipAngle, double const *ipShift) = 0;

  virtual CATCSPoint2D* GetInitialPoint() const = 0;

  virtual CATCSLine2D* GetInitialLine() const = 0;

  virtual int GetInitialOrient() const = 0;

  virtual CATCSPoint2D* GetFinalPoint() const = 0;

  virtual CATCSLine2D* GetFinalLine() const = 0;

  virtual int GetFinalOrient() const = 0;

  virtual CATCSCircle2D* GetInitialCircle() const = 0;

  virtual CATCSCircle2D* GetFinalCircle() const = 0;

  virtual int GetSide() const = 0;

  virtual void GetInitialParameters(double const *&opA2, double const *&opLength, double const *&opRadius, double const *&opAngle, double const *&opShift) = 0;

  virtual void GetInitialParameters(double *&opA2, double *&opLength, double *&opRadius, double *&opAngle, double *&opShift) = 0;

  virtual void GetParameters(double &oA2, double  &oLength, double  &oRadius, double  &oAngle, double  &oShift) = 0;

  virtual void SetGeoFactory(CATGeoFactory* ipGeoFactory) = 0;
  virtual CATGeoFactory * GetGeoFactory() const = 0;
  virtual void SetScale(CATCDSScale iScale) = 0;
  virtual CATCDSTransitionCurveType GetCDSTransitionCurveType() const = 0;
  virtual void SetTransitionCurveType(CATCDSTransitionCurveType iType) = 0;

  virtual CATCDSBoolean GetDepsDistWithFixLength(double const iLength, double const* iParams, double& oDistance) = 0;
  virtual CATCDSBoolean GetDistanceEndObjStartCu(double const iLength, double const* iParams, double& oDistance, CATCDSBoolean iProjectOnLine = FALSE) = 0;
  virtual CATCDSBoolean GetDistanceStartObjEndCu(double const iLength, double const* iParams, double& oDistance) = 0;
  virtual CATCDSBoolean GetDistanceStartEndCu(double const iLength, double const* iParams, double& oDistance) = 0;
  virtual CATCDSBoolean GetLengthWithDepsDistance(double const iDistance, double const* iParams, double& oLength) = 0;

  virtual CATCDSBoolean GetTSCSTFromPositionFromLnPositionsAndParams(double const* aLine1Coords,
    double const* aLine2Coords,
    int const iInitOrient1,
    int const iInitOrient2,
    int const iSide1,
    int const iSide2,
    double const iLength1,
    double const iLength2,
    double& iRadius,
    double* oaPoint1,
    double* oaPoint2,
    double* oaCenterCircle) = 0;

  virtual CATCDSBoolean SwitchObjectsTCToParamsTC(CATCDSBoolean const iSwap, CATCSPoint2D* iStartPoint, double const& iLength) = 0;
  virtual CATCDSBoolean SwapCircles() = 0;


  virtual CATICDSClothoidAdapter* const GetClothoidAdapter() const = 0;

  virtual void Write(CATCDSStream & ioStream) = 0;
};

//-----------------------------------------------------------------------

#endif
