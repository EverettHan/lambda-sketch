#include "CATIPGMTopOperatorImplDefine.h"

// ---------- CATSolidPrimitive

CATCGM_ITF_IMPL_CLASS::operator CATBody *()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.operator CATBody *();
}

CATGeoFactory *CATCGM_ITF_IMPL_CLASS::GetFactory()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetFactory();
}

/* Already defined in a parent class
CATBody *CATCGM_ITF_IMPL_CLASS::GetResult()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetResult();
}
*/

CATCGMJournalList *CATCGM_ITF_IMPL_CLASS::GetReport()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetReport();
}

