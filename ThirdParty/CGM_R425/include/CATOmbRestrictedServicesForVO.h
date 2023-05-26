#ifndef CATOmbRestrictedServicesForVO_H
#define CATOmbRestrictedServicesForVO_H

/**
 * @level Private
 * @usage U1       
 */

#include "IUnknown.h"
#include "CATOmbLinkTrader.h"

class CATIVO;
class CATComponentId;

class ExportedByCATOmbLinkTrader CATOmbRestrictedServicesForVO
{
  friend class OmbTST;
  friend class CATPLMELRerouteManager;
  friend class CATPLMLinksRerouteImpl;
  friend class CATOmbVOSnapshotFactoryAdapter;
private:

  /**
  * Reserves or retrieves an existing complex component identifier from a Virtual Object
  * 
  * @return
  *     S_OK    : if an associated ComponentId has been found
  *     S_FALSE : if no associated ComponentID
  *     E_FAIL  : if failed
  */
  static HRESULT RetrievesOrReservesAnEquivalentComponentId (const CATIVO * iVO, CATComponentId & oCID);
};

#endif
