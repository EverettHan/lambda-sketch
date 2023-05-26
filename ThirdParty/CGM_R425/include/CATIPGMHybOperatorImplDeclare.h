#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16

#ifdef CATIACGMR214CAA
#include "CATIPGMTopMultiResultImplDeclare.h"
#else
#include "CATIPGMTopOperatorImplDeclare.h"
#endif

  // ---------- CATHybOperator

/* Already defined in a parent class
  virtual CATBody *GetResult(CATCGMJournalList *iJournal);

  virtual CATBody *GetResult();
*/

  virtual void SetTolerance(double iTol);

  virtual double GetTolerance() const;

  virtual CATExtHybOperator *GetHybOperatorExtensible() const;

  virtual double GetDistance(CATDomain *iDomOfResultBody);

