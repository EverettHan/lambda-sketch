#include "CATICGMTopOperatorImplDefine.h"

// ---------- CATTopMultiResult

CATLONG32 CATCGM_ITF_IMPL_CLASS::GetNumberOfResults() const
{
  const CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetNumberOfResults();
}

void CATCGM_ITF_IMPL_CLASS::BeginningResult()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.BeginningResult();
}

CATBoolean CATCGM_ITF_IMPL_CLASS::NextResult()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.NextResult();
}

/* Already defined in a parent class
CATBody *CATCGM_ITF_IMPL_CLASS::GetResult(CATCGMJournalList *iJournal)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetResult(iJournal);
}

CATBody *CATCGM_ITF_IMPL_CLASS::GetResult()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetResult();
}
*/
