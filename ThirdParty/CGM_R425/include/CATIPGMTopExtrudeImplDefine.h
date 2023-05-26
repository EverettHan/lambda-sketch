#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATIPGMTopOperatorImplDefine.h"

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

void CATCGM_ITF_IMPL_CLASS::SetOldShapeRequested(CATBoolean iOldShapeOn)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetOldShapeRequested(iOldShapeOn);
}

void CATCGM_ITF_IMPL_CLASS::SetRelimitationMode(short iMode, short iAutomaticDirectionInversion)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetRelimitationMode(iMode, iAutomaticDirectionInversion);
}

void CATCGM_ITF_IMPL_CLASS::SetReversePolarity(CATBoolean iPolarity)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetReversePolarity(iPolarity);
}

void CATCGM_ITF_IMPL_CLASS::UnsetCheckTopoTwist(CATBoolean iUnsetCheckTopoTwist)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.UnsetCheckTopoTwist(iUnsetCheckTopoTwist);
}

#ifdef CATIACGMV5R23
CATBoolean CATCGM_ITF_IMPL_CLASS::GetAxisWasAutoInverted()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetAxisWasAutoInverted();
}
#endif

void CATCGM_ITF_IMPL_CLASS::SetThinSolidMode(
    const CATBoolean iThinSolidMode,
    const CATBoolean iIsNeutralFiber,
    double *iThinSolidThickness,
    CATLISTP(CATDomain) *iWireListWithReverseThinSolidSide)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetThinSolidMode(
    iThinSolidMode,
    iIsNeutralFiber,
    iThinSolidThickness,
    iWireListWithReverseThinSolidSide);
}

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

CATBoolean CATCGM_ITF_IMPL_CLASS::HasConsistentOperandes(
    CATLONG32 &oNbError,
    CATError **&oErrors)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.HasConsistentOperandes(
    oNbError,
    oErrors);
}

CATBoolean CATCGM_ITF_IMPL_CLASS::CheckOperands(CATLONG32 &oNbError, CATError **&oErrors)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.CheckOperands(oNbError, oErrors);
}

#ifdef CATIACGMR215CAA
CATBody *CATCGM_ITF_IMPL_CLASS::GetExtrapolatedLimitBody(CATTopLimit iLimit)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetExtrapolatedLimitBody(iLimit);
}

void CATCGM_ITF_IMPL_CLASS::SetJournalMode(short iJournalMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetJournalMode(iJournalMode);
}
#endif

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

