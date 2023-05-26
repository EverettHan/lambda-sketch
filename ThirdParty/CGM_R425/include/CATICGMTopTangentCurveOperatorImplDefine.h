#include "CATICGMTopMultiResultImplDefine.h"

// ---------- CATTopTangentCurveOperator

void CATCGM_ITF_IMPL_CLASS::SetTangentOrientation(int iTangentOrientation, int iRankWire)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetTangentOrientation(iTangentOrientation, iRankWire);
}

void CATCGM_ITF_IMPL_CLASS::SetCurvatureOrientation(int iCurvatureOrientation, int iIWire)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetCurvatureOrientation(iCurvatureOrientation, iIWire);
}

void CATCGM_ITF_IMPL_CLASS::GetOrientationOnWire(
    int &ioTangentOrient,
    int &ioCurvatureOrient,
    int &ioIdem,
    int iRankWire)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetOrientationOnWire(
    ioTangentOrient,
    ioCurvatureOrient,
    ioIdem,
    iRankWire);
}

void CATCGM_ITF_IMPL_CLASS::GetDiscriminationIndex(int &ioIndex)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetDiscriminationIndex(ioIndex);
}

int CATCGM_ITF_IMPL_CLASS::GetTangentOrientation(int iRankWire) const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetTangentOrientation(iRankWire);
}

int CATCGM_ITF_IMPL_CLASS::GetCurvatureOrientation(int iRankWire) const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetCurvatureOrientation(iRankWire);
}

CATBody *CATCGM_ITF_IMPL_CLASS::GetResultWithConditions(
    CATOrientation *iCrvOr,
    CATOrientation *iTngOr,
    int iIndex,
    CATBoolean &oUseOrientationCondition,
    CATBoolean &oUseIndexCondition,
    CATCGMJournalList *CurJourn)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetResultWithConditions(
    iCrvOr,
    iTngOr,
    iIndex,
    oUseOrientationCondition,
    oUseIndexCondition,
    CurJourn);
}

