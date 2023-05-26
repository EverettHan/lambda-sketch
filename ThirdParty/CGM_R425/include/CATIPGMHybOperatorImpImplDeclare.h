#include "CATIPGMHybOperatorImplDeclare.h"

  // ---------- CATHybOperatorImp

/* Already defined in a parent class
  virtual CATBody *GetResult(CATCGMJournalList *iJournal);

  virtual CATBody *GetResult();

  virtual void SetTolerance(double iTol);

  virtual double GetTolerance() const;

  virtual int Run();
*/

  virtual void SetCheckReport(short mode);

  virtual short GetCheckReport() const;

  virtual CATExtHybOperatorImp *GetHybOperatorImpExtensible() const;

