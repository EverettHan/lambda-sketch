#include "CATIPGMTopOperatorImplDefine.h"

// ---------- CATDistanceBodyBody

double CATCGM_ITF_IMPL_CLASS::GetDistance()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetDistance();
}

void CATCGM_ITF_IMPL_CLASS::GetPoints(CATMathPoint &oPoint1, CATMathPoint &oPoint2)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetPoints(oPoint1, oPoint2);
}

void CATCGM_ITF_IMPL_CLASS::GetPoints(CATPoint *&oPoint1, CATPoint *&oPoint2)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetPoints(oPoint1, oPoint2);
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

void CATCGM_ITF_IMPL_CLASS::ReplaceBody(CATBody *iBodyToReplace, CATBody *iNewBody)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.ReplaceBody(iBodyToReplace, iNewBody);
}

void CATCGM_ITF_IMPL_CLASS::SetDistanceMax(double iDistanceMax)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetDistanceMax(iDistanceMax);
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

void CATCGM_ITF_IMPL_CLASS::SetDistanceMode(CATDistanceBodyBodyMode iMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetDistanceMode((CATDistanceBodyBody::CATDistanceMode)iMode);
}
