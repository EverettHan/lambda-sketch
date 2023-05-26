#include "CATIPGMTopOperatorImplDeclare.h"

  // ---------- CATTopShellUnfoldTransfer

  virtual void SetTransfertTolerance(double iTol);

  virtual void SetClean(CATBoolean iClean);

  virtual void SetAssemblyTolerance(double iAsslyTol);

  virtual int RunTransfer(
    const CATLISTP(CATBody) &iBodiesToTransfer,
    CATLISTP(CATBody) &ioBodiesTransferred,
    CATCGMJournalList *iReport,
    CATBoolean iReverse);

  virtual int RunTransfer(
    CATBody *iBody,
    CATBody *&oBody,
    CATCGMJournalList *iReport,
    CATBoolean iReverse);

  virtual int IsInputShellFlattenedInputBody() const;


