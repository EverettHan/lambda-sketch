#include "CATIPGMOperatorImplDeclare.h"

  // ---------- CATGeoFilling

  virtual int AddConstraint(
    const CATCurve *iCurve,
    const CATCrvLimits &iLimits,
    const CATBoolean iIsBound,
    const double iTolerance);

  virtual int AddConstraint(
    const CATPCurve *iPCurve,
    const CATCrvLimits &iLimits,
    const short iOrder,
    const CATBoolean iIsBound,
    const double iTolG0,
    const double iTolAngular,
    const double iTolCurvature);

  virtual int AddConstraint(
    const CATPoint *iPoint,
    const double iTolerance);

  virtual void SetMaxNumberOfSpans(const int iMaxNumberOfSpans);

  virtual void SetContinuity(const int iContinuity);

  virtual void SetLevel(const int iLevel);
  virtual void SetC2CuttingsForNotClosedBoundaries();

  virtual int IsInitialPlaneAcceptable(
    CATPlane *&oComputedPlane,
    CATAngle &oMaxPointsAngle,
    CATAngle &oMaxNormalsAngle);

  virtual int Link(const int iNumConst, const CATPCurve *iPCurve);

/* Already defined in a parent class
  virtual int Run();
*/

  virtual int GetNumberOfIncompatibilities() const;

  virtual void BeginningIncompatibility();

  virtual CATBoolean GetNextIncompatibility(
    int &oNumCont1,
    int &oNumCont2,
    double &oParam1,
    double &oParam2,
    FillingIncompatibilityType &oType,
    double &oValue);

  virtual CATNurbsSurface *GetSurface() const;

  virtual CATPCurve *GetPCurve(const int iNumConst);

  virtual CATPointOnSurface *GetPointOnSurface(const int iNumConst);

  virtual double GetG0MaxDeviation() const;

  virtual double GetG1MaxDeviation() const;

  virtual double GetG2MaxDeviation() const;

  virtual double GetG0MaxDeviation(const int iNumConst) const;

  virtual double GetG1MaxDeviation(const int iNumConst) const;

  virtual double GetG2MaxDeviation(const int iNumConst) const;

  virtual void SetOrientation(CATBoolean iKeepConvention);

  virtual int G2ConstraintsLoaded();

