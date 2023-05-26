#ifndef CATOmbRestrictedServicesForPLMCore2_H
#define CATOmbRestrictedServicesForPLMCore2_H

/**
 * @level Private
 * @usage U1
 */
#include "IUnknown.h"
#include "CATOmbLinkTrader.h"
#include "CATCollec.h"
#include "CATBoolean.h"
#include "CATOmbLink.h"
#include "CATDataType.h"
#include "CATOmxList.h"
#include "CATPLMPath.h"

class CATComponentId;
class CATListPtrCATIPLMScopeBaseEntity;
class CATIComponentIdSimpleHashTable;
class CATLISTV(CATComponentId);

class ExportedByCATOmbLinkTrader CATOmbRestrictedServicesForPLMCore2
{
  //restricted to PLMCore2...and some "happy" few 
  friend class OmbTST;
  friend class CATPCCMemPLMSpecializedEntity_PLMScopeBaseEntity;
  friend class CATOmbRepRefScopeBaseEntityAdapter;
  friend class CATOmbConnectionScopeBaseEntityAdapter;
  friend class CATEPLMDocScopeBaseEntity;
  friend class CATOmbTst_RestrictedServicesForPLMCore2;
  friend class CATPLMScopeServices;
  friend class CATLifeCycleDocument;
  friend class CATOxiRelational;
  friend class CATPCCFeatureServices;
  friend class CATPCCMemLightInternalObjectWithSR;
  friend class CATPCCRelationalServices;
  friend class CATOxiInstanceWithSRs;
  friend class CATPCCMemPathAccess;

private:
  /** operates stuff on thingies (thank me for that documentation that is far more helpful than the initial one) */
  static HRESULT ComputeScopesFromComponentId(const CATComponentId & iCID, CATListPtrCATIPLMScopeBaseEntity & oLScopeBaseEntity);
  static HRESULT ComputeScopesFromComponentId(const CATComponentId &iCID, CATLISTV(CATComponentId) &oComponents);
  static HRESULT ComputeScopesFromComponentId(const CATComponentId &iCID, CATIComponentIdSimpleHashTable *iopComponents, CATBoolean iWithSynchronizedLinks = TRUE);
  static HRESULT GetImpactedObjectsInScope(const CATComponentId &iCID, CATIComponentIdSimpleHashTable *iopComponents);
  /** same but in an "optimised" fashion this time, keep on searching there might exist an ultimate one which does the thing betterly */
  static HRESULT ComputeOptimisedScopesFromComponentId(const CATComponentId &iCID, CATIComponentIdSimpleHashTable *iopComponents);

  static HRESULT GetPLMPathFromComponentId(const CATComponentId &iCID, CATOmxList<CATPLMPath>& oPath);

};

#endif
