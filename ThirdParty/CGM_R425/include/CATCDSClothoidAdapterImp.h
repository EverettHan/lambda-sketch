#ifndef CATCDSTransitionCurveImp_H
#define CATCDSTransitionCurveImp_H

#include "CATCDSVirtual.h"
#include "StreamGM.h"

#include "CATICDSClothoidAdapter.h"

class CATCDSFactoryImp;
class CATConstraintSolver;
class CATCSTransitionCurve2D;
class CATCSTransitionCurve2DImp;

// Implementation class definition
class ExportedByStreamGM CATCDSClothoidAdapterImp CATCDSFinal : public CATICDSClothoidAdapter
{
public:
  CATCDSClothoidAdapterImp();
  ~CATCDSClothoidAdapterImp();

  CATCDSClothoidAdapterImp(CATICDSLine2D *ipInitialLine, int iInitialOrient, CATICDSCircle2D *ipFinalCircle);

  CATCDSClothoidAdapterImp(CATICDSCircle2D *ipInitialLine, int iInitialOrient, CATICDSCircle2D *ipFinalCircle);

  CATCDSClothoidAdapterImp(CATICDSPoint2D *ipInitialPoint, CATICDSLine2D *ipInitialLine, int iInitialOrient, CATICDSPoint2D *ipFinalPoint);

  CATCDSClothoidAdapterImp(CATICDSPoint2D *ipInitialPoint, CATICDSLine2D *ipInitialLine, int iInitialOrient, int iSide, CATICDSLine2D *ipFinalLine, int iFinalOrient,
    double const *ipA2, double const *ipLength, double const *ipRadius, double const *ipShift);

  CATCDSClothoidAdapterImp(CATICDSPoint2D *ipInitialPoint, CATICDSLine2D *ipInitialLine, int iInitialOrient, int iSide,
    double const *ipA2, double const *ipLength, double const *ipRadius, double const *ipAngle, double const *ipShift);

  CATCDSClothoidAdapterImp(CATCSTransitionCurve2DImp const& ipTransitionCurve);

  virtual void SetInitialPoint(CATICDSPoint2D* iInitialPoint)  CATCDSOverride;

  virtual void SetInitialLine(CATICDSLine2D* iInitialLine, int iOrientation)  CATCDSOverride;

  virtual void SetInitialCircle(CATICDSCircle2D* iInitialCircle, int iOrientation)  CATCDSOverride;

  virtual void SetFinalPoint(CATICDSPoint2D* iFinalPoint)  CATCDSOverride;

  virtual void SetFinalLine(CATICDSLine2D* iFinalLine, int iOrientation)  CATCDSOverride;

  virtual void SetFinalCircle(CATICDSCircle2D* iFinalCircle)  CATCDSOverride;

  virtual void SetSide(int const& iSide) CATCDSOverride ;

  virtual void SetScale(CATCDSScale iScale) CATCDSOverride;

  virtual void SetInitialParameters(double const *ipA2, double const *ipLength, double const *ipRadius, double const *ipAngle, double const *ipShift) CATCDSOverride;

  virtual CATICDSPoint2D* GetInitialPoint() const CATCDSOverride;

  virtual CATICDSLine2D* GetInitialLine() const CATCDSOverride;

  virtual CATICDSCircle2D* GetInitialCircle() const CATCDSOverride;

  virtual int GetInitialOrient() const CATCDSOverride;

  virtual CATICDSPoint2D* GetFinalPoint() const CATCDSOverride;

  virtual CATICDSLine2D* GetFinalLine() const CATCDSOverride;

  virtual int GetFinalOrient() const CATCDSOverride;

  virtual CATICDSCircle2D* GetFinalCircle() const CATCDSOverride;

  virtual int GetSide() const CATCDSOverride;

  virtual void GetInitialParameters(double const *&opA2, double const *&opLength, double const *&opRadius, double const *&opAngle, double const *&opShift) CATCDSOverride;

  virtual CATCDSBoolean CreateCurve(CATPlane &iPlane, CATCurve *&opTransitionCurve, double oaPoint[2]) const CATCDSOverride;

  virtual CATCDSBoolean Regenerate() CATCDSOverride;

  virtual CATCDSParamType GetLimits(double &oLow, double &oUp) const CATCDSOverride;

  virtual void Evaluate2D(double iT,
    double* oaPoint,
    double* oaFirstDeriv,
    double* oaSecondDeriv,
    double* oaThirdDeriv) const CATCDSOverride;

  virtual int GetNbOfDiscontinuities() const CATCDSOverride;

  virtual void GetDiscontinuitiesParams(double *oaValues) const CATCDSOverride;

  virtual void EvaluateAtDiscontinuity2D(int iIdx,
    CATCDSDiscontinuitySide iSide,
    double iT,
    double* oaPoint,
    double* oaFirstDeriv,
    double* oaSecondDeriv,
    double* oaThirdDeriv) const CATCDSOverride;

  virtual CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) const CATCDSOverride;

  virtual void GetDirection2D(double &oX, double &oY) const CATCDSOverride;

  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  virtual void SetGeoFactory(CATGeoFactory* ipGeoFactory) CATCDSOverride;
  virtual CATGeoFactory* GetGeoFactory() const CATCDSOverride;

  CATCSTransitionCurve2D* GetClothoid(void) const CATCDSOverride;

private :
  CATCSTransitionCurve2DImp* _pImp;
};

#endif
