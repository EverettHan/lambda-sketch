#include "CATIPGMTopOperatorImplDefine.h"

// ---------- CATGMPolyTopOperator

HRESULT CATCGM_ITF_IMPL_CLASS::RunAndGetResult(CATBody * &oResultBody, CATError * &oResultError)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.RunAndGetResult(oResultBody, oResultError);
}
