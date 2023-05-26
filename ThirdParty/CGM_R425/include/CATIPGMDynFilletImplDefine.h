#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATIPGMDynOperatorImplDefine.h"

// ---------- CATDynFillet

void CATCGM_ITF_IMPL_CLASS::Append(CATDynFaceFaceFilletRibbon *iRibbonToAppend)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.Append(iRibbonToAppend);
}

void CATCGM_ITF_IMPL_CLASS::Append(CATDynEdgeFilletRibbon *iRibbonToAppend)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.Append(iRibbonToAppend);
}

void CATCGM_ITF_IMPL_CLASS::Append(CATDynRemoveFaceFilletRibbon *iRibbonToRemove)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.Append(iRibbonToRemove);
}

void CATCGM_ITF_IMPL_CLASS::SetPrevisualizationOnly()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetPrevisualizationOnly();
}

void CATCGM_ITF_IMPL_CLASS::SetVertexBlendList(
    CATLISTP(CATDynFilletBlendVertex) &iVertexBlendList)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetVertexBlendList(
    iVertexBlendList);
}

CATDynBlendVertexDiag *CATCGM_ITF_IMPL_CLASS::CreateVertexBlendDiag(int iVertexBlendIndex)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.CreateVertexBlendDiag(iVertexBlendIndex);
}

#ifdef CATIACGMV5R23
void CATCGM_ITF_IMPL_CLASS::AddLimitingElement(
    CATBody *iBody,
    CATDomain *iSkin,
    const CATOrientation iOrientation)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.AddLimitingElement(
    iBody,
    iSkin,
    iOrientation);
}
#endif

void CATCGM_ITF_IMPL_CLASS::AddLimitingElement(
    CATBody *iBody,
    CATDomain *iSkin,
    const CATOrientation iOrientation,
    const int iSmartCrossParting)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.AddLimitingElement(
    iBody,
    iSkin,
    iOrientation,
    iSmartCrossParting);
}

void CATCGM_ITF_IMPL_CLASS::SetTrueMultiRibbonOnly()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetTrueMultiRibbonOnly();
}

void CATCGM_ITF_IMPL_CLASS::GetSplittingElements(
    int iSupport,
    CATLISTP(CATGeometry) &oElementsList,
    CATListOfInt &oSides)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetSplittingElements(
    iSupport,
    oElementsList,
    oSides);
}

void CATCGM_ITF_IMPL_CLASS::SetHelpPoint(CATMathPoint &iHelpPoint)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetHelpPoint(iHelpPoint);
}

/* Already defined in a parent class
CATContextForFastRun *CATCGM_ITF_IMPL_CLASS::GetContextForFastRun(CATBoolean iGetOnly)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetContextForFastRun(iGetOnly);
}
*/

CATDynFilletContextForFastRun *CATCGM_ITF_IMPL_CLASS::GetDynFilletContextForFastRun(
    CATBoolean iGetOnly)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetDynFilletContextForFastRun(
    iGetOnly);
}

