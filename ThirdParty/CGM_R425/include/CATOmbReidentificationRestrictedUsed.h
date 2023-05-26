#ifndef CATOmbReidentificationRestrictedUsed_H
#define CATOmbReidentificationRestrictedUsed_H

#define AuthorizedModule                  999
#define CATOmbLinkTrader                  AuthorizedModule
#define CATPLMIntegration                 AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATOxReidentificationRestrictedUsed from a non-infrastructure module
@error
#endif
#undef CATOmbLinkTrader
#undef CATPLMIntegration

#include "CATObjectModelerBase.h"
#include "CATAssert.h"
#include "CATPLMSRIds.h"
#include "CATPLMID_Simple.h"
#include "CATPLMCEStamp.h"
#include "CATOmxArray.h"
#include "CATOmxOHMap.h"
#include "CATOmbIdsToUpdate.h"
#include "CATOmxDeprecated.h"

class CATPLMCEStamp;
class CATPLMID;
class CATProxySpace;
class CATProxyTransaction;



namespace CATOmbReidentificationRestrictedUsed
{
  /**
   * operates actions on the internal stuff of the thingies
   */
  ExportedByCATObjectModelerBase HRESULT ReidentifyInSession(const CATProxyTransaction & iWorkingContext, const CATOmxOHMap<CATPLMID_Simple, CATOmbIdsToUpdate>& iIdMapping);

  OMX_DEPRECATED("removed") inline HRESULT ReidentifyInSession(const CATProxyTransaction & iWorkingContext, const CATOmxOHMap<CATPLMID, CATPLMID>& iToReplace) { return E_NOTIMPL; }
};

#endif
