#include "CATLISTV_CATPLMID.h"
#include "CATIPLMCompleteGraph.h"
#include "CATPLMIntegrationBase.h"
#include "IUnknown.h"

class CATIAdpErrorMonitor;
class ExportedByCATPLMIntegrationBase CATAdpRawCompleteGraph : public CATIPLMCompleteGraph
{
  CATDeclareClass;
  CATPLMIDs _plmids;
public:
  HRESULT Complete( const CATLISTV(CATPLMID) & iIds , const CGMode & iMode );
  HRESULT GetComponents(CATLISTV(CATPLMID) & oIds);
  HRESULT GetErrorMonitor(CATIAdpErrorMonitor *& oErrorMonitor);
};
