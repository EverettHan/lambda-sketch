#include "CATIPGMTopOperatorImplDefine.h"

// ---------- CATTopShellUnfoldTransfer

void CATCGM_ITF_IMPL_CLASS::SetTransfertTolerance(double iTol)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetTransfertTolerance(iTol);
}

void CATCGM_ITF_IMPL_CLASS::SetClean(CATBoolean iClean)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetClean(iClean);
}

void CATCGM_ITF_IMPL_CLASS::SetAssemblyTolerance(double iAsslyTol)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetAssemblyTolerance(iAsslyTol);
}

int CATCGM_ITF_IMPL_CLASS::RunTransfer(
    const CATLISTP(CATBody) &iBodiesToTransfer,
    CATLISTP(CATBody) &ioBodiesTransferred,
    CATCGMJournalList *iReport,
    CATBoolean iReverse)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.RunTransfer(
    iBodiesToTransfer,
    ioBodiesTransferred,
    iReport,
    iReverse);
}

int CATCGM_ITF_IMPL_CLASS::RunTransfer(
    CATBody *iBody,
    CATBody *&oBody,
    CATCGMJournalList *iReport,
    CATBoolean iReverse)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.RunTransfer(
    iBody,
    oBody,
    iReport,
    iReverse);
}

int CATCGM_ITF_IMPL_CLASS::IsInputShellFlattenedInputBody() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.IsInputShellFlattenedInputBody();
}


