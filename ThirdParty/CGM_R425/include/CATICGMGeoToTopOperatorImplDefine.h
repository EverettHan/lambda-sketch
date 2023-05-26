#include "CATICGMTopOperatorImplDefine.h"

// ---------- CATGeoToTopOperator

void CATCGM_ITF_IMPL_CLASS::SetTolerance(double iTol)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetTolerance(iTol);
}

double CATCGM_ITF_IMPL_CLASS::GetTolerance() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetTolerance();
}

CATCGMJournalList *CATCGM_ITF_IMPL_CLASS::GetReport()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetReport();
}

