#ifndef CATSYPSimpleErrorMgt_H
#define CATSYPSimpleErrorMgt_H

#include <IntroInfra.h>
#include <CATSYPErrorMgt.h>
/**
 * Interface presenting eror reporting managment, with an XML syntax.
 */
class ExportedByIntroInfra CATSYPSimpleErrorMgt : public CATSYPErrorMgt
{
public:
  /** Constructor*/
  CATSYPSimpleErrorMgt();
  /**@copydoc CATSYPErrorReport#AddError */
  virtual void AddError(const CATUnicodeString& i_message, CATSYPErrorMgt::Severity i_errorType=Error);
};

#endif
