#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATIPGMTopOperatorImplDeclare.h"

  // ---------- CATTopExtrude

  virtual void SetProfileClosure();

  virtual void SetOperation(CATTopBooleanType iBoolType);

  virtual void SetTrim(CATBody *iTrimBody);

  virtual void SetResultMode(CATBoolean iBothResultRequired);

  virtual void SetOldShapeRequested(CATBoolean iOldShapeOn);

  virtual void SetRelimitationMode(short iMode, short iAutomaticDirectionInversion);

  virtual void SetReversePolarity(CATBoolean iPolarity);

  virtual void UnsetCheckTopoTwist(CATBoolean iUnsetCheckTopoTwist);

#ifdef CATIACGMV5R23
  virtual CATBoolean GetAxisWasAutoInverted();
#endif

  virtual void SetThinSolidMode(
    const CATBoolean iThinSolidMode,
    const CATBoolean iIsNeutralFiber,
    double *iThinSolidThickness,
    CATLISTP(CATDomain) *iWireListWithReverseThinSolidSide);

  virtual void SetSimplification(CATBoolean iSimplify);

/* Already defined in a parent class
  virtual void SetFreezeMode(CATBodyFreezeMode iOnOrOff);

  virtual CATBodyFreezeMode GetFreezeMode() const;
*/

  virtual CATBoolean HasConsistentOperandes(
    CATLONG32 &oNbError,
    CATError **&oErrors);

  virtual CATBoolean CheckOperands(CATLONG32 &oNbError, CATError **&oErrors);

#ifdef CATIACGMR215CAA
  virtual CATBody *GetExtrapolatedLimitBody(CATTopLimit iLimit);

  virtual void SetJournalMode(short iJournalMode);
#endif

  virtual CATBody *GetBooleanResult() const;

  virtual CATCGMJournalList *GetBooleanJournal() const;

  virtual CATBoolean IsResultInvariant() const;

