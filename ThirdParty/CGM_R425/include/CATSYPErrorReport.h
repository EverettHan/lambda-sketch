#ifndef CATSYPErrorReport_H
#define CATSYPErrorReport_H

#include <IntroInfra.h>
#include <CATSYPErrorMgt.h>

class CATUnicodeString;
/**
 * Interface presenting eror reporting managment
 */
class ExportedByIntroInfra CATSYPErrorReport : public CATSYPErrorMgt
{
public:
  /**
   * @return the result of the report as a unicodestring
   */
  virtual CATUnicodeString ToString() const = 0;
  virtual CATSYPErrorReport* Clone() const = 0;
};

#endif
