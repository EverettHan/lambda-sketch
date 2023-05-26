// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Protected
 * @usage U1
 */

#ifndef CATPLMCompleteGraphWithFilter_h
#define CATPLMCompleteGraphWithFilter_h

#include "CATPLMIntegration.h"
#include "CATIPLMCompleteGraph.h"
#include "CATPLMIDSet.h"
#include "CATPLMCompletionParameters.h"
#include "CATLISTV_CATPLMID.h"
#include "CATPLMCompletionData.h"
#include "CATPLMCompletionDataOnTos.h"
#include "CATProxySpace.h"
#include "CATOmxSR.h"

class CATIPLMCompletionTypeRetriever;
class CATIPLMQueryFilter;
class CATPLMCompleteGraphWithFilterImpl;
class CATPLMCompletionSpaceManager;
class CATIAdpErrorMonitor;
class CATIAdpErrorMonitorAbstract;
class ExportedByCATPLMIntegration CATPLMCompleteGraphWithFilter : public CATIPLMCompleteGraph
{
  CATDeclareClass;

public:

  // ctor
  CATPLMCompleteGraphWithFilter(const CATPLMCompletionParameters& iCompletionParams,
    const CATIPLMCompletionTypeRetriever* iTypeRetriever,
    CATIAdpErrorMonitorAbstract* iMonitor = nullptr);
  CATPLMCompleteGraphWithFilter(const CATPLMCompletionParameters& iCompletionParams,
    const CATProxySpace& iTargetSpace,
    const CATIPLMCompletionTypeRetriever* iTypeRetriever,
    CATIAdpErrorMonitorAbstract* iMonitor = nullptr);
  CATPLMCompleteGraphWithFilter(const CATPLMCompleteGraphWithFilter&) = delete;
  CATPLMCompleteGraphWithFilter(CATPLMCompleteGraphWithFilter&&) = delete;

  // dtor
  virtual ~CATPLMCompleteGraphWithFilter();

  // assignment
  CATPLMCompleteGraphWithFilter& operator =(const CATPLMCompleteGraphWithFilter&) = delete;
  CATPLMCompleteGraphWithFilter& operator =(CATPLMCompleteGraphWithFilter&&) = delete;

  HRESULT AddElementsToComplete(CATPLMCompletionData& iElementsToComplete,
    CATPLMCompletionParameters::Action iCompletionAction, CATIPLMQueryFilter* iFilter);

  HRESULT AddElementsToComplete(const CATPLMIDSet& iElementsToComplete,
    CATPLMCompletionParameters::Action iCompletionAction, CATIPLMQueryFilter* iFilter);


  HRESULT Complete(const CATLISTV(CATPLMID)& iIds, const CGMode& iMode);
  HRESULT GetComponents(CATLISTV(CATPLMID)& oIds);
  HRESULT GetErrorMonitor(CATIAdpErrorMonitor*& /*oErrorMonitor*/) { return E_FAIL; }

  HRESULT GetComplexComponents(CATLISTV(CATPLMID)& oIds);

  HRESULT GetCompletionSpace(CATProxySpace& oCompletionSpace);

private:

  void _Init(const CATPLMCompletionParameters& iCompletionParams,
    const CATProxySpace& iTargetSpace,
    const CATIPLMCompletionTypeRetriever* iTypeRetriever,
    CATIAdpErrorMonitorAbstract* iMonitor);
  CATProxySpace _InitProxySpace(const CATProxySpace& iConstructorProxySpace);

  CATPLMCompletionDataOnTos m_completedData;
  CATPLMIDs m_inputs;
  CATOmxAutoPtr<CATPLMCompleteGraphWithFilterImpl> m_impl;
  HRESULT m_completionResult{ E_FAIL };
  CATOmxAutoPtr<CATPLMCompletionSpaceManager> m_completionSpaceManager;
  CATProxySpace m_implProxySpace;
  CATOmxSR<CATIAdpErrorMonitor> m_errorMonitor{ nullptr };
};
#endif
