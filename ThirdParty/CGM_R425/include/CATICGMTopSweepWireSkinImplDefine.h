#include "CATICGMTopMultiResultImplDefine.h"

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
