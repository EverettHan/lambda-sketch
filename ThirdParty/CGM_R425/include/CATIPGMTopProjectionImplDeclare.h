#include "CATIPGMTopOperatorImplDeclare.h"

  // ---------- CATTopProjection

  virtual void SetDomainToProject(CATDomain *iDomain);

  virtual void SetDomainSupport(CATDomain *iDomain);

  virtual void SetMaxDistance(double iDistance);

  virtual void SetBestSolWanted(CATLONG32 bestsol);

  virtual double GetDistance(CATDomain *iDomainOfResultBody);

  virtual CATBody *GetLine(CATDomain *iDomainOfResultBody);

  virtual double GetMaxDistance();

