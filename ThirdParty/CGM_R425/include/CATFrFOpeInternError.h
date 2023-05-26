#ifndef CATFRFOPEINTERNERROR_H
#define CATFRFOPEINTERNERROR_H
#include "FrFOpeUtil.h"

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATErrors.h"

class ExportedByFrFOpeUtil CATFrFOpeInternError : public CATInternalError
{
 public:
  CATDeclareErrorClass(CATFrFOpeInternError, CATInternalError)
};

#endif
