#include "CATICGMTopOperatorImplDefine.h"

// ---------- CATTopologicalFill

/* Already defined in a parent class
int CATCGM_ITF_IMPL_CLASS::Run()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.Run();
}
*/

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

void CATCGM_ITF_IMPL_CLASS::GetCenterPoint(CATVertex &ioCenterPoint)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetCenterPoint(ioCenterPoint);
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

