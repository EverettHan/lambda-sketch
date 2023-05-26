#include "CATICGMTopOperatorImplDeclare.h"

  // ---------- CATTopMultiResult

  virtual CATLONG32 GetNumberOfResults() const;

  virtual void BeginningResult();

  virtual CATBoolean NextResult();

/* Already defined in a parent class
  virtual CATBody *GetResult(CATCGMJournalList *iJournal);
*/
