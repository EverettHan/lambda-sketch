#ifndef CATSYPTxtErrorReportFactory_H
#define CATSYPTxtErrorReportFactory_H
class CATUnicodeString;

#include <CATSYPErrorReportFactory.h>
#include <IntroInfra.h>
/**
 * Interface allowing to build error report.
 */
class ExportedByIntroInfra CATSYPTxtErrorReportFactory : public CATSYPErrorReportFactory
{
public:
  CATSYPTxtErrorReportFactory();
  virtual ~CATSYPTxtErrorReportFactory();
  /**
   * @return a new error report
   */
  virtual CATSYPErrorReport* CreateReport() const ;
};

#endif
