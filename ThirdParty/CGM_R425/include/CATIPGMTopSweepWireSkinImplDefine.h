#include "CATIPGMTopMultiResultImplDefine.h"

// ---------- CATTopSweepWireSkin

void CATCGM_ITF_IMPL_CLASS::SetShellOrientation(const int iOrientation)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetShellOrientation(iOrientation);
}

void CATCGM_ITF_IMPL_CLASS::SetGuideOrientation(const int iOrientation)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetGuideOrientation(iOrientation);
}

void CATCGM_ITF_IMPL_CLASS::GetResultInformation(
    int &ioShellOrientation,
    int &ioWireOrientation,
    int &ioIndex)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetResultInformation(
    ioShellOrientation,
    ioWireOrientation,
    ioIndex);
}

/* Already defined in a parent class
int CATCGM_ITF_IMPL_CLASS::Run()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.Run();
}
*/

CATSweepProfileInfo *CATCGM_ITF_IMPL_CLASS::GetProfileInfo()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetProfileInfo();
}

void CATCGM_ITF_IMPL_CLASS::SetModeTrim(const int iMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetModeTrim(iMode);
}

void CATCGM_ITF_IMPL_CLASS::SetReconfigFillFunction(CATFilletReconfigFillFunction iFillFct)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetReconfigFillFunction(iFillFct);
}

CATFilletReconfigFillFunction CATCGM_ITF_IMPL_CLASS::GetFilletReconfigFillFunction() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetFilletReconfigFillFunction();
}

