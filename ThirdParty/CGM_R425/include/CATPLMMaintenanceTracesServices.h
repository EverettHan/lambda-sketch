#ifndef CATPLMMaintenaceTraceServices_h
#define CATPLMMaintenaceTraceServices_h

#include "CATPLMServicesItf.h"
class CATListValCATUnicodeString;
class CATUnicodeString;

/**
 * @level Protected
 * @usage U3
 */

class ExportedByCATPLMServicesItf CATPLMMaintenanceTracesServices
{
public:
  /** 
  * Add the given log info to the current log.
  *
  * @param iThem [in]
  *   A distinctive name for your information. May be used to extract only relevant type of informations
  * @param iOperation [in]
  *   The name of the operation. May be used to extract only relevant type of informations
  * @param iInfos [in]
  *   The various informations will be dumped as key=value
  */
  static void AddLogInfos(const CATUnicodeString& iThem, const CATUnicodeString& iOperation, const CATListValCATUnicodeString& iInfos);
};
#endif

