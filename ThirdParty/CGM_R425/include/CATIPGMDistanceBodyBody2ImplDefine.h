#include "CATIPGMVirtualImplDefine.h"

// ---------- CATDistanceBodyBody2

int CATCGM_ITF_IMPL_CLASS::Run()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.Run();
}

double CATCGM_ITF_IMPL_CLASS::GetDistance()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetDistance();
}

void CATCGM_ITF_IMPL_CLASS::GetResultPoints(
    CATMathPoint &oMathPoint1,
    CATMathPoint &oMathPoint2)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetResultPoints(
    oMathPoint1,
    oMathPoint2);
}

void CATCGM_ITF_IMPL_CLASS::GetLinkPoints(CATPoint *&oPoint1, CATPoint *&oPoint2)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetLinkPoints(oPoint1, oPoint2);
}

void CATCGM_ITF_IMPL_CLASS::GetSupportCells(CATCell *&oCell1, CATCell *&oCell2)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetSupportCells(oCell1, oCell2);
}

void CATCGM_ITF_IMPL_CLASS::SetReferencePoint(const CATMathPoint &iRefPoint)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetReferencePoint(iRefPoint);
}

void CATCGM_ITF_IMPL_CLASS::GetReferencePoint(CATMathPoint &oRefPoint)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetReferencePoint(oRefPoint);
}

void CATCGM_ITF_IMPL_CLASS::SetDistanceUpperBound(double iDistanceUpperBound)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetDistanceUpperBound(iDistanceUpperBound);
}

void CATCGM_ITF_IMPL_CLASS::SetTargetCells(
    CATLISTP(CATCell) &iCellsOnBody1,
    CATLISTP(CATCell) &iCellsOnBody2)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetTargetCells(
    iCellsOnBody1,
    iCellsOnBody2);
}

void CATCGM_ITF_IMPL_CLASS::SetDistanceType(CATDistanceBodyBodyType iType)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetDistanceType((CATDistanceBodyBody::CATDistanceType)iType);
}

CATDistanceBodyBodyType CATCGM_ITF_IMPL_CLASS::GetDistanceType()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return (CATDistanceBodyBodyType)HandledObject.GetDistanceType();
}

void CATCGM_ITF_IMPL_CLASS::SetDistanceMode(CATDistanceBodyBodyMode iMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetDistanceMode((CATDistanceBodyBody::CATDistanceMode)iMode);
}

CATDistanceBodyBodyMode CATCGM_ITF_IMPL_CLASS::GetDistanceMode()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return (CATDistanceBodyBodyMode)HandledObject.GetDistanceMode();
}

void CATCGM_ITF_IMPL_CLASS::ReplaceBody(
    CATBody *iBodyToReplace,
    CATGeoFactory *iFactoryOfNewBody,
    CATBody *iNewBody,
    const CATMathTransformation &iNewBodyTransformation)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.ReplaceBody(
    iBodyToReplace,
    iFactoryOfNewBody,
    iNewBody,
    iNewBodyTransformation);
}

