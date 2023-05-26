#ifndef CATSYPTxtErrorReport_H
#define CATSYPTxtErrorReport_H

#include <IntroInfra.h>
#include <CATSYPErrorReport.h>
#include <CATUnicodeString.h>

/**
 */
class ExportedByIntroInfra CATSYPTxtErrorReport : public CATSYPErrorReport
{
public:
  /** Constructor*/
  CATSYPTxtErrorReport();
  virtual ~CATSYPTxtErrorReport();
  /**@copydoc CATSYPErrorReport#AddError */
  virtual void AddError(const CATUnicodeString& i_message, CATSYPErrorReport::Severity i_errorType=Error);
  /**@copydoc CATSYPErrorReport#ToString */
  virtual CATUnicodeString ToString() const;
  /**@copydoc CATSYPErrorReport#Clone */
  virtual CATSYPTxtErrorReport* Clone() const;
  
private:
  CATUnicodeString _stringReport;
};

#endif
