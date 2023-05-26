#ifndef CATPLMSemanticRecordServices_H
#define CATPLMSemanticRecordServices_H
// COPYRIGHT DASSAULT SYSTEMES 2011

/**
* @level Protected
* @usage U1
*/

#include "CATPLMServicesItf.h"

#include "CATSysErrorDef.h"

class CATIPLMAttrRead;
class CATOmxAny;

/**
 * Toolbox for sematic information computed from attributes in a record.
 */
class ExportedByCATPLMServicesItf CATPLMSemanticRecordServices
{
public:

  /**
  * Find update stamp information inside a list of attribute.
  *
  * @param iAttrRead
  *   The attribute access block where information will be searched.
  * 
  * @param oUpdateStamp
  *   The value of the update stamp in a variant form. The value can be an integer or an uuid.
  *
  * @return
  *   S_OK    : The value is correctly computed.
  *   E_FAIL  : The information inside the attributes can't return a valid value.
  */
  static HRESULT GetUpdateStampValue(CATIPLMAttrRead * iAttrRead, CATOmxAny & oUpdateStamp);
};

#endif
