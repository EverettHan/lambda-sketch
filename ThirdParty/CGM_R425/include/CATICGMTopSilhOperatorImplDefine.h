#include "CATICGMTopOperatorImplDefine.h"

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
