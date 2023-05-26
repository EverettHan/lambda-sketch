#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATICGMDynOperatorImplDefine.h"

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

void CATCGM_ITF_IMPL_CLASS::SetTrueMultiRibbonOnly()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetTrueMultiRibbonOnly();
}

void CATCGM_ITF_IMPL_CLASS::SetHelpPoint(CATMathPoint &iHelpPoint)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetHelpPoint(iHelpPoint);
}

