#include "CATIPGMHybOperatorImplDefine.h"

// ---------- CATHybOperatorImp

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

int CATCGM_ITF_IMPL_CLASS::Run()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.Run();
}
*/

void CATCGM_ITF_IMPL_CLASS::SetCheckReport(short mode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetCheckReport(mode);
}

short CATCGM_ITF_IMPL_CLASS::GetCheckReport() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetCheckReport();
}

CATExtHybOperatorImp *CATCGM_ITF_IMPL_CLASS::GetHybOperatorImpExtensible() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetHybOperatorImpExtensible();
}

