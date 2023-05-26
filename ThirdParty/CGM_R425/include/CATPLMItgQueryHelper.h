#ifndef CATPLMItgQueryHelper_h
#define CATPLMItgQueryHelper_h

#include "CATPLMIntegrationBase.h"
#include "CATBaseUnknown.h"
class CATPLMItgQueryFilterCondition;
class CATComponentId;
class CATString;
class CATPLMID;
class CATPLMID_Any;
class CATBinary;

class ExportedByCATPLMIntegrationBase CATPLMItgQueryHelper
{
 
public:
  CATPLMItgQueryHelper();
  HRESULT GetPhysId(const CATPLMID & iPLMID, CATPLMID_Any & oPhysId);
  HRESULT GetBinaryFromPLMID_Any(const CATPLMID_Any & iId, CATBinary & oBinary);

private: //pas de copie
  CATPLMItgQueryHelper(const CATPLMItgQueryHelper & iQuery);
  CATPLMItgQueryHelper& operator=(const CATPLMItgQueryHelper&);

};

#endif
