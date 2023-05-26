#include "CATICGMDynOperatorImplDefine.h"

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

void CATCGM_ITF_IMPL_CLASS::SetTrueMultiRibbonOnly()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetTrueMultiRibbonOnly();
}

