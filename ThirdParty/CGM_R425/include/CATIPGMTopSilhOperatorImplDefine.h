#include "CATIPGMTopOperatorImplDefine.h"

// ---------- CATTopSilhOperator

void CATCGM_ITF_IMPL_CLASS::SetProjectionScreenForShadows(
    CATBody *iScreenBody,
    CATBoolean iLightSourceInFront,
    CATBoolean iFillHoles)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetProjectionScreenForShadows(
    iScreenBody,
    iLightSourceInFront, iFillHoles);
}

void CATCGM_ITF_IMPL_CLASS::SetProjectionScreenForShadows(
    const CATMathPlane &iScreenPlane,
    CATBoolean iLightSourceInFront,
    CATBoolean iFillHoles)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetProjectionScreenForShadows(
    iScreenPlane,
    iLightSourceInFront, iFillHoles);
}

void CATCGM_ITF_IMPL_CLASS::EnableWireMode()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.EnableWireMode();
}

void CATCGM_ITF_IMPL_CLASS::SetViewPoint(const CATMathPoint &iPt)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetViewPoint(iPt);
}

void CATCGM_ITF_IMPL_CLASS::SetViewDirection(const CATMathDirection &iDir)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetViewDirection(iDir);
}

void CATCGM_ITF_IMPL_CLASS::DisableReflectLineComputation()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.DisableReflectLineComputation();
}

void CATCGM_ITF_IMPL_CLASS::SetShadowScreen(
    CATBody *iScreenBody,
    int iOutputDim,
    int iViewSide)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetShadowScreen(
    iScreenBody,
    iOutputDim,
    iViewSide);
}

void CATCGM_ITF_IMPL_CLASS::SetSilhouetteSelectionMode(
    int iSilhTypes,
    int iStoreOutputDomainTypes)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetSilhouetteSelectionMode(
    iSilhTypes,
    iStoreOutputDomainTypes);
}

void CATCGM_ITF_IMPL_CLASS::GetOutputDomainType(
    CATDomain *iOutputDomain,
    int &oSilhDomainType)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetOutputDomainType(
    iOutputDomain,
    oSilhDomainType);
}

