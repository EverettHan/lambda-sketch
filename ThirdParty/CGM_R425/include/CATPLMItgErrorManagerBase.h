// COPYRIGHT Dassault Systemes 2010
#ifndef CATPLMItgErrorManagerBase_H
#define CATPLMItgErrorManagerBase_H

#include "CATPLMIntegrationBase.h"
#include "CATBaseUnknown.h"
#include "CATError.h"
#include "CATIOmyIncidentCollector.h"
#include "CATOmxSR.h"
class CATIAdpErrorMonitor;
class CATString;
class CATPLMID;
class CATComponentId;
class CATIPLMCompRecordReadSet;
class CATOmxKeyValueBlock;

class ExportedByCATPLMIntegrationBase CATPLMItgErrorManagerBase
{
public:

  CATPLMItgErrorManagerBase(CATOmxSR<CATIOmyIncidentCollector> iCollector);
  CATPLMItgErrorManagerBase();
  ~CATPLMItgErrorManagerBase();

  HRESULT AddErrorToMonitoring(const CATString & iErrorCatalog, const CATString & iErrorKey,
    const CATPLMID & iPID, const CATComponentId & iCID,
    CATErrorType iSeverity = CATErrorTypeFatal);

  HRESULT AddErrorToMonitoring(const CATString & iErrorCatalog, const CATString & iErrorKey,
    const CATPLMID & iPID, CATErrorType iSeverity = CATErrorTypeFatal);

  HRESULT AddErrorToMonitoring(const CATString & iErrorCatalog, const CATString & iErrorKey,
    const CATComponentId & iCID, CATErrorType iSeverity = CATErrorTypeFatal);

  HRESULT AddErrorToMonitoring(const CATString & iErrorCatalog, const CATString & iErrorKey,
    CATErrorType iSeverity = CATErrorTypeFatal);

private:
  CATOmxSR<CATIOmyIncidentCollector> _spIncidentCollector;
};

#endif
