#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATIPGMDynOperatorImplDefine.h"

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

void CATCGM_ITF_IMPL_CLASS::Add(
    CATSurface *iPartingSurface,
    CATOrientation iPartingOrientation,
    CATBoolean iIsPartingUntil)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.Add(
    iPartingSurface,
    iPartingOrientation,
    iIsPartingUntil);
}

void CATCGM_ITF_IMPL_CLASS::Add(
    CATPlane *iPartingPlane,
    CATOrientation iPartingOrientation,
    CATBoolean iIsPartingUntil)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.Add(
    iPartingPlane,
    iPartingOrientation,
    iIsPartingUntil);
}

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

CATOrientation CATCGM_ITF_IMPL_CLASS::GetCalculatedOrientationOnParting()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetCalculatedOrientationOnParting();
}

void CATCGM_ITF_IMPL_CLASS::Add(CATDynDraftDomain *iDraftDomain)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.Add(iDraftDomain);
}

void CATCGM_ITF_IMPL_CLASS::Add(
    CATDynDraftDomain *iDraftDomain1,
    CATDynDraftDomain *iDraftDomain2,
    CATDynDraftBothSidesType iBothSidesType,
    double iIdealRadius)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.Add(
    iDraftDomain1,
    iDraftDomain2,
    iBothSidesType,
    iIdealRadius);
}

void CATCGM_ITF_IMPL_CLASS::SetPrevisualizationOnly()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetPrevisualizationOnly();
}

void CATCGM_ITF_IMPL_CLASS::SetPrevisualizationMode(CATDynDraftPrevisualization iMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetPrevisualizationMode(iMode);
}

void CATCGM_ITF_IMPL_CLASS::SetJunctionMode(CATBoolean iJunctionMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetJunctionMode(iJunctionMode);
}

CATDynValidShellType CATCGM_ITF_IMPL_CLASS::ValidateShellOutput(CATLISTP(CATBody) &oListBody)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.ValidateShellOutput(oListBody);
}

void CATCGM_ITF_IMPL_CLASS::SetJournalInfoMode(CATPGMDynDraftJournalInfoMode iInfoMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetJournalInfoMode((CATDynDraft::JournalInfoMode)iInfoMode);
}

CATDynDraftFillFunction CATCGM_ITF_IMPL_CLASS::GetUntwistDraftFillFunction() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetUntwistDraftFillFunction();
}

CATBoolean CATCGM_ITF_IMPL_CLASS::IsUntwistDraftFillFunctionUsed() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.IsUntwistDraftFillFunctionUsed();
}

void CATCGM_ITF_IMPL_CLASS::SetUntwistDraftFillFunction(CATDynDraftFillFunction iFillFct)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetUntwistDraftFillFunction(iFillFct);
}

/* Already defined in a parent class
CATContextForFastRun *CATCGM_ITF_IMPL_CLASS::GetContextForFastRun(CATBoolean iGetOnly)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetContextForFastRun(iGetOnly);
}
*/

CATDynDraftContextForFastRun *CATCGM_ITF_IMPL_CLASS::GetDynDraftContextForFastRun(
    CATBoolean iGetOnly)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetDynDraftContextForFastRun(
    iGetOnly);
}

#ifdef CATIACGMR214Code  
void CATCGM_ITF_IMPL_CLASS::SetInitialFacePropag( CATBoolean iActive)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetInitialFacePropag(iActive);
}
#endif
 
void CATCGM_ITF_IMPL_CLASS::SetStepDraftMode( CATDynDraftStepDraftMode iStepDraftMode )
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetStepDraftMode((CATDynDraft::StepDraftMode)iStepDraftMode);
}



