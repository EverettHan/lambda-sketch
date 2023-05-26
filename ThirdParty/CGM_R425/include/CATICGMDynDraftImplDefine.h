#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATICGMDynOperatorImplDefine.h"

// ---------- CATDynDraft

void CATCGM_ITF_IMPL_CLASS::Add(
    CATBody *iPartingElement,
    CATOrientation iPartingOrientation,
    CATBoolean iIsPartingUntil)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.Add(
    iPartingElement,
    iPartingOrientation,
    iIsPartingUntil);
}

#ifdef CATIACGMV5R23
void CATCGM_ITF_IMPL_CLASS::AddLimiting(
    CATBody *iLimitingElement,
    CATOrientation iLimitingOrientation,
    CATBoolean iIsLimitingUntil)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.AddLimiting(
    iLimitingElement,
    iLimitingOrientation,
    iIsLimitingUntil);
}
#endif

void CATCGM_ITF_IMPL_CLASS::Add(CATDynDraftDomain *iDraftDomain)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.Add(iDraftDomain);
}

void CATCGM_ITF_IMPL_CLASS::SetPrevisualizationOnly()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetPrevisualizationOnly();
}

#ifdef CATIACGMV5R23
void CATCGM_ITF_IMPL_CLASS::SetPrevisualizationMode(CATDynDraftPrevisualization iMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetPrevisualizationMode(iMode);
}
#endif

void CATCGM_ITF_IMPL_CLASS::SetJunctionMode(CATBoolean iJunctionMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetJunctionMode(iJunctionMode);
}

