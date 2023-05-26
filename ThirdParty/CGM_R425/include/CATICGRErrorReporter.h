#ifndef CATICGRErrorReporter_H
#define CATICGRErrorReporter_H

#include "CATBaseUnknown.h"
#include "SGInfra.h"
class CATError;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySGInfra IID IID_CATICGRErrorReporter;
#else
extern "C" const IID IID_CATICGRErrorReporter;
#endif

class ExportedBySGInfra CATICGRErrorReporter : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual HRESULT ReportSaveError(const char *errorKey, const char *errorCatalog, const char *nlsParameter) = 0;
  virtual HRESULT ReportLoadError(const char *errorKey, const char *errorCatalog, const char *nlsParameter) = 0;
};

#endif
