#include "CATIPGMOperatorImplDefine.h"

// ---------- CATGeoFilling

int CATCGM_ITF_IMPL_CLASS::AddConstraint(
    const CATCurve *iCurve,
    const CATCrvLimits &iLimits,
    const CATBoolean iIsBound,
    const double iTolerance)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.AddConstraint(
    iCurve,
    iLimits,
    iIsBound,
    iTolerance);
}

int CATCGM_ITF_IMPL_CLASS::AddConstraint(
    const CATPCurve *iPCurve,
    const CATCrvLimits &iLimits,
    const short iOrder,
    const CATBoolean iIsBound,
    const double iTolG0,
    const double iTolAngular,
    const double iTolCurvature)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.AddConstraint(
    iPCurve,
    iLimits,
    iOrder,
    iIsBound,
    iTolG0,
    iTolAngular,
    iTolCurvature);
}

int CATCGM_ITF_IMPL_CLASS::AddConstraint(
    const CATPoint *iPoint,
    const double iTolerance)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.AddConstraint(
    iPoint,
    iTolerance);
}

void CATCGM_ITF_IMPL_CLASS::SetMaxNumberOfSpans(const int iMaxNumberOfSpans)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetMaxNumberOfSpans(iMaxNumberOfSpans);
}

void CATCGM_ITF_IMPL_CLASS::SetContinuity(const int iContinuity)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetContinuity(iContinuity);
}

void CATCGM_ITF_IMPL_CLASS::SetLevel(const int iLevel)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetLevel(iLevel);
}

void CATCGM_ITF_IMPL_CLASS::SetC2CuttingsForNotClosedBoundaries()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetC2CuttingsForNotClosedBoundaries();
}


int CATCGM_ITF_IMPL_CLASS::IsInitialPlaneAcceptable(
    CATPlane *&oComputedPlane,
    CATAngle &oMaxPointsAngle,
    CATAngle &oMaxNormalsAngle)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.IsInitialPlaneAcceptable(
    oComputedPlane,
    oMaxPointsAngle,
    oMaxNormalsAngle);
}

int CATCGM_ITF_IMPL_CLASS::Link(const int iNumConst, const CATPCurve *iPCurve)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.Link(iNumConst, iPCurve);
}

/* Already defined in a parent class
int CATCGM_ITF_IMPL_CLASS::Run()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.Run();
}
*/

int CATCGM_ITF_IMPL_CLASS::GetNumberOfIncompatibilities() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetNumberOfIncompatibilities();
}

void CATCGM_ITF_IMPL_CLASS::BeginningIncompatibility()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.BeginningIncompatibility();
}

CATBoolean CATCGM_ITF_IMPL_CLASS::GetNextIncompatibility(
    int &oNumCont1,
    int &oNumCont2,
    double &oParam1,
    double &oParam2,
    FillingIncompatibilityType &oType,
    double &oValue)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetNextIncompatibility(
    oNumCont1,
    oNumCont2,
    oParam1,
    oParam2,
    oType,
    oValue);
}

CATNurbsSurface *CATCGM_ITF_IMPL_CLASS::GetSurface() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetSurface();
}

CATPCurve *CATCGM_ITF_IMPL_CLASS::GetPCurve(const int iNumConst)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetPCurve(iNumConst);
}

CATPointOnSurface *CATCGM_ITF_IMPL_CLASS::GetPointOnSurface(const int iNumConst)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetPointOnSurface(iNumConst);
}

double CATCGM_ITF_IMPL_CLASS::GetG0MaxDeviation() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetG0MaxDeviation();
}

double CATCGM_ITF_IMPL_CLASS::GetG1MaxDeviation() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetG1MaxDeviation();
}

double CATCGM_ITF_IMPL_CLASS::GetG2MaxDeviation() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetG2MaxDeviation();
}

double CATCGM_ITF_IMPL_CLASS::GetG0MaxDeviation(const int iNumConst) const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetG0MaxDeviation(iNumConst);
}

double CATCGM_ITF_IMPL_CLASS::GetG1MaxDeviation(const int iNumConst) const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetG1MaxDeviation(iNumConst);
}

double CATCGM_ITF_IMPL_CLASS::GetG2MaxDeviation(const int iNumConst) const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetG2MaxDeviation(iNumConst);
}

void CATCGM_ITF_IMPL_CLASS::SetOrientation(CATBoolean iKeepConvention)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetOrientation(iKeepConvention);
}

int CATCGM_ITF_IMPL_CLASS::G2ConstraintsLoaded()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.G2ConstraintsLoaded();
}

