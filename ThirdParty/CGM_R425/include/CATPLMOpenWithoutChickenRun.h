#ifndef CATPLMOpenWithoutChickenRun_h
#define CATPLMOpenWithoutChickenRun_h

#include "CATPLMIntegrationAccess.h"

#include "CATLISTV_CATPLMID.h"
#include "CATAdpProtectedRepresentationMode.h"
#include "CATOmbLifeCycleRootsBag.h"
#include "CATPLMComponentData.h"
#include "CATIAdpErrorMonitor.h"
#include "CATAdpProtectedLinkFilteringMode.h"
/**
 * Class dedicated to very specific usage
 * CAUTION : Do not use without class owner agreement !!!!!!
 */

class CATOmbLoadingModeRuleSet;

class ExportedByCATPLMIntegrationAccess CATPLMOpenWithoutChickenRun
{
public:
  CATPLMOpenWithoutChickenRun();
  ~CATPLMOpenWithoutChickenRun();

  void AddInput(const CATPLMIDs& iListInstRef);

  void AddConnection(const CATPLMIDs& iListCnx);

  HRESULT Open(CATAdpProtectedRepresentationMode::RepresentationMode iRepModeOpen,
    const CATOmbLoadingModeRuleSet& iOmbLoadingMode,
    CATOmbLifeCycleRootsBag& ioBag,
    CATPLMComponentData& oOpenedComponents,
    CATIAdpErrorMonitor* iopIAdpErrorMonitor);

  HRESULT Open(CATAdpProtectedRepresentationMode::RepresentationMode iRepModeOpen,
    CATBoolean iWithMaterials,
    CATBoolean iWithDifs,
    CATBoolean iWithPlmParameters,
    CATAdpProtectedLinkFilteringMode iMfgProductionPlanningFilteringMode,
    CATAdpProtectedLinkFilteringMode iAllocatedResourceFilteringMode,
    CATAdpProtectedLinkFilteringMode iTimeConstraintFilteringMode,
    CATAdpProtectedLinkFilteringMode iProcessPrerequisiteFilteringMode,
    const CATOmbLoadingModeRuleSet& iOmbLoadingMode,
    CATOmbLifeCycleRootsBag& ioBag,
    CATPLMComponentData& oOpenedComponents,
    CATIAdpErrorMonitor* iopIAdpErrorMonitor);

private:
  CATPLMOpenWithoutChickenRun(const CATPLMOpenWithoutChickenRun&);
  CATPLMOpenWithoutChickenRun& operator=(const CATPLMOpenWithoutChickenRun&);

  CATPLMIDs _ListInstRef;
  CATPLMIDs _ListCnx;
};

#endif
