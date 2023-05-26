#include "CATIPGMTopOperatorImplDefine.h"

// ---------- CATTopMultiResult

CATLONG32 CATCGM_ITF_IMPL_CLASS::GetNumberOfResults() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
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
