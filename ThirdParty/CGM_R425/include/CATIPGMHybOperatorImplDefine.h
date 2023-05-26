#define CATCGM_ITF_OverrideTopOperatorFreezeMode // CATHybOperator overrides these methods with another signature...

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16

#ifdef CATIACGMR214CAA
#include "CATIPGMTopMultiResultImplDefine.h"
#else
#include "CATIPGMTopOperatorImplDefine.h"
#endif

#undef CATCGM_ITF_OverrideTopOperatorFreezeMode

// ---------- CATHybOperator

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

CATBodyFreezeMode CATCGM_ITF_IMPL_CLASS::GetFreezeMode() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  short iFreezeMode1 = HandledObject.GetFreezeMode();
  if (iFreezeMode1 == 0)
    return CATBodyFreezeOff;
  else if (iFreezeMode1 == 1)
    return CATBodyFreezeOn;
  else
    return CATBodyFreezeOrCompletionInvalid;
}

void CATCGM_ITF_IMPL_CLASS::SetFreezeMode(CATBodyFreezeMode iOnOrOff)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  short iFreezeMode2 = iOnOrOff == CATBodyFreezeOn ? 1 : 0;
  HandledObject.SetFreezeMode(iFreezeMode2);
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

CATExtHybOperator *CATCGM_ITF_IMPL_CLASS::GetHybOperatorExtensible() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetHybOperatorExtensible();
}

double CATCGM_ITF_IMPL_CLASS::GetDistance(CATDomain *iDomOfResultBody)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetDistance(iDomOfResultBody);
}

