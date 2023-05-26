#include "CATIPGMDynOperatorImplDefine.h"

// ---------- CATDynChamfer

void CATCGM_ITF_IMPL_CLASS::Append(CATDynChamferRibbon *iRibbonToAppend)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.Append(iRibbonToAppend);
}

void CATCGM_ITF_IMPL_CLASS::SetPrevisualizationOnly()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetPrevisualizationOnly();
}

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

/* Already defined in a parent class
CATContextForFastRun *CATCGM_ITF_IMPL_CLASS::GetContextForFastRun(CATBoolean iGetOnly)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetContextForFastRun(iGetOnly);
}
*/

CATDynChamferContextForFastRun *CATCGM_ITF_IMPL_CLASS::GetDynChamferContextForFastRun(
    CATBoolean iGetOnly)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetDynChamferContextForFastRun(
    iGetOnly);
}

