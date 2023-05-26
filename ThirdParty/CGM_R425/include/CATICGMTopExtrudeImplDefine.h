#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATICGMTopOperatorImplDefine.h"

// ---------- CATTopExtrude

void CATCGM_ITF_IMPL_CLASS::SetProfileClosure()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetProfileClosure();
}

void CATCGM_ITF_IMPL_CLASS::SetOperation(CATTopBooleanType iBoolType)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetOperation(iBoolType);
}

void CATCGM_ITF_IMPL_CLASS::SetTrim(CATBody *iTrimBody)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetTrim(iTrimBody);
}

void CATCGM_ITF_IMPL_CLASS::SetResultMode(CATBoolean iBothResultRequired)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetResultMode(iBothResultRequired);
}

#ifdef CATIACGMV5R23
void CATCGM_ITF_IMPL_CLASS::SetThinSolidMode(
    const CATBoolean iThinSolidMode,
    const CATBoolean iIsNeutralFiber,
    const double iThinSolidThickness[2],
    CATLISTP(CATDomain) *iWireListWithReverseThinSolidSide)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetThinSolidMode(
    iThinSolidMode,
    iIsNeutralFiber,
    iThinSolidThickness,
    iWireListWithReverseThinSolidSide);
}
#endif

void CATCGM_ITF_IMPL_CLASS::SetSimplification(CATBoolean iSimplify)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetSimplification(iSimplify);
}

/* Already defined in a parent class
void CATCGM_ITF_IMPL_CLASS::SetFreezeMode(CATBodyFreezeMode iOnOrOff)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetFreezeMode(iOnOrOff);
}

CATBodyFreezeMode CATCGM_ITF_IMPL_CLASS::GetFreezeMode() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetFreezeMode();
}
*/

CATBoolean CATCGM_ITF_IMPL_CLASS::CheckOperands(CATLONG32 &oNbError, CATError **&oErrors)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.CheckOperands(oNbError, oErrors);
}

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

CATBoolean CATCGM_ITF_IMPL_CLASS::IsResultInvariant() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.IsResultInvariant();
}

