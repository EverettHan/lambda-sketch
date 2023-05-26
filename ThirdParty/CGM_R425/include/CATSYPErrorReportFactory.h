#ifndef CATSYPErrorReportFactory_H
#define CATSYPErrorReportFactory_H
class CATUnicodeString;

#include <CATBaseUnknown.h>
#include <IntroInfra.h>
class CATSYPErrorReport;
/**
 * Interface allowing to build error standard report.
 */
class ExportedByIntroInfra CATSYPErrorReportFactory : public CATBaseUnknown
{
public:
  /**
   * @return a new error report.
   */
  virtual CATSYPErrorReport* CreateReport() const = 0;
};

#endif
