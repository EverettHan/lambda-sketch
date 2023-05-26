#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATICGMTopOperatorImplDeclare.h"

  // ---------- CATTopExtrude

  virtual void SetProfileClosure();

  virtual void SetOperation(CATTopBooleanType iBoolType);

  virtual void SetTrim(CATBody *iTrimBody);

  virtual void SetResultMode(CATBoolean iBothResultRequired);

#ifdef CATIACGMV5R23
  virtual void SetThinSolidMode(
    const CATBoolean iThinSolidMode,
    const CATBoolean iIsNeutralFiber,
    const double iThinSolidThickness[2],
    CATLISTP(CATDomain) *iWireListWithReverseThinSolidSide);
#endif

  virtual void SetSimplification(CATBoolean iSimplify);

/* Already defined in a parent class
  virtual void SetFreezeMode(CATBodyFreezeMode iOnOrOff);

  virtual CATBodyFreezeMode GetFreezeMode() const;
*/

  virtual CATBoolean CheckOperands(CATLONG32 &oNbError, CATError **&oErrors);

  virtual CATBody *GetBooleanResult() const;

  virtual CATCGMJournalList *GetBooleanJournal() const;

  virtual CATBoolean IsResultInvariant() const;

