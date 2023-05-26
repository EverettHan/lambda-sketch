#ifndef CATSYPErrorMgt_H
#define CATSYPErrorMgt_H

#include <CATSysBoolean.h>
#include <IntroInfra.h>
class CATUnicodeString;

/**
 * Interface presenting eror reporting managment
 */
class ExportedByIntroInfra CATSYPErrorMgt
{
public:
  virtual ~CATSYPErrorMgt(){};
  /** Error severity*/
  enum Severity {
    /** Error */
    Error = 0, 
    /**Warning */
    Warning};
  /** Constructor*/
  CATSYPErrorMgt(){_errorOccuredFlag=0;}
  /** Clone function
   * Needs to be reimplemented in inheriting functions.
   */
  virtual CATSYPErrorMgt* Clone() const = 0;
  /**
   * Adds an error to the report.
   * @param i_message the message describing the error
   * @param i_errorType the severity of the error
   */
  virtual void AddError(const CATUnicodeString& i_message, CATSYPErrorMgt::Severity i_errorType=Error){if (i_errorType==Error)_errorOccuredFlag = TRUE;}
  /** @return a flag indicating if an error has been happend to the error report */
  CATBoolean GetErrorOccuredFlag() const{return _errorOccuredFlag;}
  
protected:
  void SetErrorOccuredFlag(unsigned char i_ErrorOccuredFlag){_errorOccuredFlag = i_ErrorOccuredFlag;}
  
private:
  CATBoolean _errorOccuredFlag;
};

#endif
