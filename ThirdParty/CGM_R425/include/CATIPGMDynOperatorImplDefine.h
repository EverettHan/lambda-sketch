#include "CATIPGMTopOperatorImplDefine.h"

// ---------- CATDynOperator

CATBody *CATCGM_ITF_IMPL_CLASS::GetBooleanResult() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetBooleanResult();
}

CATCGMJournalList *CATCGM_ITF_IMPL_CLASS::GetBooleanJournal() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetBooleanJournal();
}

