#ifndef CATPLMITGSESSIONCOMPONENTSQUERY_H_
#define CATPLMITGSESSIONCOMPONENTSQUERY_H_

#include "CATProxySpace.h"
#include "CATPLMIntegrationBase.h"
#include "CATComponentIdStatus.h"
#include "CATPLMBagType.h"
#include "CATOmxOrderedOSet.h"
#include "CATComponentId.h"
#include "CATComponentIdStatus.h"
#include "CATOmyAsserts.h"
#include "CATOmxList.h"
#include "CATLISTV_CATComponentId.h"
#include "CATLISTV_CATIPLMLogState.h"
class CATComponentIdSet;
class CATComponentIdFilter;

class ExportedByCATPLMIntegrationBase CATPLMItgSessionComponentsQuery
{
protected:
  CATProxySpace _space;

public:
  CATPLMItgSessionComponentsQuery(const CATProxySpace & iSpace = CATProxySpace_Null);

  /**
   * Retrieves all active components in session.
   */
  CATComponentIdSet * GetSessionComponents(CATComponentIdStatus iStatus = CATComponentIdStatus_All);

private:
  CATProxySpace GetValidSpace(const CATProxySpace & iWorkspace);
  HRESULT GetComponentFilter(CATComponentIdStatus iStatus, CATComponentIdFilter & oFilter);
};
#endif /* CATPLMITGSESSIONCOMPONENTSQUERY_H_ */
