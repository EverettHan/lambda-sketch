#include "CATIPGMTopOperatorImplDefine.h"

// ---------- CATTopologicalFill

/* Already defined in a parent class
int CATCGM_ITF_IMPL_CLASS::Run()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.Run();
}
*/

void CATCGM_ITF_IMPL_CLASS::SetCanonicalDetection()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetCanonicalDetection();
}

double CATCGM_ITF_IMPL_CLASS::GetG0MaxDeviation()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetG0MaxDeviation();
}

CATAngle CATCGM_ITF_IMPL_CLASS::GetG1MaxDeviation()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetG1MaxDeviation();
}

double CATCGM_ITF_IMPL_CLASS::GetG2MaxDeviation()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetG2MaxDeviation();
}

double CATCGM_ITF_IMPL_CLASS::GetG0MaxDeviation(
    const CATEdge *iEdge,
    CATMathPoint *ioMaxPoint)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetG0MaxDeviation(
    iEdge,
    ioMaxPoint);
}

CATAngle CATCGM_ITF_IMPL_CLASS::GetG1MaxDeviation(
    const CATEdge *iEdge,
    CATMathPoint *ioMaxPoint)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetG1MaxDeviation(
    iEdge,
    ioMaxPoint);
}

double CATCGM_ITF_IMPL_CLASS::GetG2MaxDeviation(
    const CATEdge *iEdge,
    CATMathPoint *ioMaxPoint)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetG2MaxDeviation(
    iEdge,
    ioMaxPoint);
}

double CATCGM_ITF_IMPL_CLASS::GetG0MaxAccuracy()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetG0MaxAccuracy();
}

/* Already defined in a parent class
CATBody *CATCGM_ITF_IMPL_CLASS::GetResult()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetResult();
}
*/

void CATCGM_ITF_IMPL_CLASS::SetInputValidationMode(const CATLONG32 iMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetInputValidationMode(iMode);
}

void CATCGM_ITF_IMPL_CLASS::SetTransitionContinuity(
    const CATLONG32 iWhichWire,
    const CATLONG32 iTransitionContinuity)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetTransitionContinuity(
    iWhichWire,
    iTransitionContinuity);
}

void CATCGM_ITF_IMPL_CLASS::SetSimplifyOption(CATBoolean iSimplify)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetSimplifyOption(iSimplify);
}

void CATCGM_ITF_IMPL_CLASS::SetTangencyParameter(
    const CATLONG32 iside,
    const double iTangencyParameter)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetTangencyParameter(
    iside,
    iTangencyParameter);
}

void CATCGM_ITF_IMPL_CLASS::GetCenterPoint(CATVertex &ioCenterPoint)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetCenterPoint(ioCenterPoint);
}

CATBoolean CATCGM_ITF_IMPL_CLASS::IsCenterPointCreated() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.IsCenterPointCreated();
}

void CATCGM_ITF_IMPL_CLASS::SetCenterPoint(CATVertex &iCenterPoint)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetCenterPoint(iCenterPoint);
}

void CATCGM_ITF_IMPL_CLASS::ResetCenterPoint()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.ResetCenterPoint();
}

void CATCGM_ITF_IMPL_CLASS::SetFlatFaceMode(const CATLONG32 iMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetFlatFaceMode(iMode);
}

void CATCGM_ITF_IMPL_CLASS::SetLinkedTopology(const CATLONG32 iLevel)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetLinkedTopology(iLevel);
}

void CATCGM_ITF_IMPL_CLASS::SetBody(CATBody *ioBody, CATShell *ioShell)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetBody(ioBody, ioShell);
}

void CATCGM_ITF_IMPL_CLASS::OrientationByFirstEdge()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.OrientationByFirstEdge();
}

void CATCGM_ITF_IMPL_CLASS::AddInnerWires(
    CATLISTP(CATBody) const &iListOfWires,
    CATLISTP(CATBody) const &iListOfSupports,
    CATListOfInt &iListOfInnerTransitionContinuity)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.AddInnerWires(
    iListOfWires,
    iListOfSupports,
    iListOfInnerTransitionContinuity);
}

void CATCGM_ITF_IMPL_CLASS::SetPassingCurves(CATLISTP(CATBody) const &iListOfWires)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetPassingCurves(iListOfWires);
}

void CATCGM_ITF_IMPL_CLASS::SetPassingPoints(CATLISTP(CATBody) const &iListOfVertices)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetPassingPoints(iListOfVertices);
}

void CATCGM_ITF_IMPL_CLASS::SetGapTolerance(const double iTolerance)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetGapTolerance(iTolerance);
}

void CATCGM_ITF_IMPL_CLASS::SetSurfaceParameters(
    int iDegreeU,
    int iDegreeV,
    int iNumberUOfPatch,
    int iNumberVOfPatch)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetSurfaceParameters(
    iDegreeU,
    iDegreeV,
    iNumberUOfPatch,
    iNumberVOfPatch);
}

void CATCGM_ITF_IMPL_CLASS::GetSurfaceParameters(
    int &oDegreeU,
    int &oDegreeV,
    int &oNumberUOfPatch,
    int &oNumberVOfPatch)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetSurfaceParameters(
    oDegreeU,
    oDegreeV,
    oNumberUOfPatch,
    oNumberVOfPatch);
}

void CATCGM_ITF_IMPL_CLASS::UsingCommonSupport()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.UsingCommonSupport();
}

CATLONG32 CATCGM_ITF_IMPL_CLASS::GetLinkedTopology() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetLinkedTopology();
}

CATLONG32 CATCGM_ITF_IMPL_CLASS::Check()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.Check();
}

CATTopologicalFillType CATCGM_ITF_IMPL_CLASS::GetFillType()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return (CATTopologicalFillType)HandledObject.GetFillType();
}

