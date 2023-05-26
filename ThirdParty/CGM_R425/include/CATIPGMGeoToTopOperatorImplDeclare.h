#include "CATIPGMTopOperatorImplDeclare.h"

  // ---------- CATGeoToTopOperator

  virtual void SetTolerance(double iTol);

  virtual double GetTolerance() const;

  virtual void SetUseGeometriesInJournalItems(int iUseGeometriesInJournalItems);

  virtual void Report(
    CATCGMJournal ::Type iType,
    const CATGeometry *iBeforeObjects,
    const CATGeometry *iAfterObjects,
    CATCGMJournalInfo *iOptionalInfo);

  virtual CATCGMJournalList *GetReport();

