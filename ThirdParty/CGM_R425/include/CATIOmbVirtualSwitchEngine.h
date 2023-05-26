#ifndef __CATIOmbSwitchHelper_H
#define __CATIOmbSwitchHelper_H

#include "CATBaseUnknown.h"
#include "CATOmxSR.h"
#include "CATPLMCompletionLevel.h"
#include "CATUnicodeString.h"
#include "CATListOfCATOmyCioUrlUsageCtx.h"
#include "CATOmbSwitchEngine.h"
#include "CATOmxSharable.h"

class CATIPLMRecordRead;
class CATOmbLoadingModeRuleSet;
class CATIOmiSwitchEngine;
class CATPLMID;
class CATComponentId;

/**
 * Interface allowing to find out what a switch (CATIOmiSwitchEngine)
 * would do if called with same arguments.
 * It does not require model to have been created in session.
 */
class CATIOmbVirtualSwitchEngine: public CATBaseUnknown
{
public:
  /** Allocate a virtual switch engine */
  static ExportedByCATOmbSwitchEngine CATOmxSR<CATIOmbVirtualSwitchEngine> Create();

  /** Handle to internal object*/
  class Component: public CATOmxSharable {};

  /** @see CATIOmiSwitchEngine::AddLoadingModeRules*/
  virtual HRESULT AddLoadingModeRules(const CATOmbLoadingModeRuleSet& iRuleSet) = 0;

  /** 
   * register a component in engine.
   * @param iRecord
   *    "record" containing persisted SD view
   * @param iPLMID
   *   PLMID corresponding to this record
   * @param iCompletionLevel
   *   CompletionLevel corresponding to this record
   */
  virtual CATOmxSR<CATIOmbVirtualSwitchEngine::Component> RegisterComponent(CATIPLMRecordRead& iRecord,const CATPLMID& iPLMID,const CATPLMCompletionLevel& iCompletionLevel) = 0;

  /** 
   * register a component which exist in session in engine.
   */
  virtual CATOmxSR<CATIOmbVirtualSwitchEngine::Component> RegisterComponent(const CATComponentId& iCID) = 0;

  /**
   * Compute target loading mode according to provided loading mode rule set.
   */
  virtual HRESULT ComputeTargetLoadingMode(CATIOmbVirtualSwitchEngine::Component& iComponent,CATUnicodeString& oLoadingMode) = 0;

  /**
   * List the urls of the streams that would get loaded if switch was executed.
   */
  virtual HRESULT ListUrlsToLoad(CATIOmbVirtualSwitchEngine::Component& iComponent,const CATUnicodeString& iLoadMode,CATListOfCATOmyCioUrlUsageCtx& oUrls) = 0;

  /**
   * Make a snapshot of this object.
   * This snapshot will contain some results that could be reused by other APIs in order to save CPU time.
   * Returned value can be NULL if no optimisation is worth considering
   *
   * 
   * Supported/interesting scenario:
   * Use CATIOmbVirtualSwitchEngine to list the urls that must be downloaded by a switch operation.
   * Once done, create a snapshot
   * call CATOmyCioAccess::OpenConnections on the urls to download
   * if CATOmyCioAccess::OpenConnections fails, this snapshot must be killed.
   * 
   * Create the real switch engine object
   * Associate the snapshot object to the CATIOmiSwitchEngine through AssociateSnapshotToSwitchEngine
   * (at this point you must kill your reference to the snapshot)
   *
   * call the switch engine API
   *
   * If everything is ok, CATOmyCioAccess::OpenConnections call will not be performed again allowing CPU cost reduction.
   *
   * Notice CATIOmbVirtualSwitchEngine & CATIOmiSwitchEngine operations may not match (different modes, different objects)
   * In this case the optimisation will be reduced or impossible but it should work exactly the same.
   */
  virtual CATOmxSR<CATOmxSharable> Snapshot() = 0;

  /**
   * Associate a snapshot obtained through method hereabove to a switch engine instance.
   */
  static ExportedByCATOmbSwitchEngine HRESULT AssociateSnapshotToSwitchEngine(CATIOmiSwitchEngine* iSwitchEngine,CATOmxSharable* iSnapshot);
};


#endif
