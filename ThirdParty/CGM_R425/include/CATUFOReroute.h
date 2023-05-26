#ifndef _CATUFOREROUTE_H_
#define _CATUFOREROUTE_H_
/**
 * @level Protected
 * @usage U1
 */

 // SystemTS
#include "IUnknown.h"
// ObjectModelerCollection
#include "CATOmxIter.h"
// CATPLMIdentification
#include "CATUFOUserActionInformation.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"

class CATProxySpace;
class CATUFOServiceOutput;
class CATOmbRerouteRequest;

class ExportedByCATObjectModelerBase CATUFOReroute
{
private:
  friend class CATPLMClientCoreInsertPrivateManager;
  friend class CATPLMClientCorePrivateMoveToManager;
  friend class CATPLMClientCoreSimulationDAGReplacePrivateManager;
  friend class CATPLMClientCorePrivateReplaceManager;
  friend class CATOmbRerouteAssistantManagerAccess;
  friend class CATOxiRerouteUFO;

  // entry point for automatic reroute (immediate mode)
  static HRESULT RelationalRerouteOnUserAction(CATProxySpace & iProxySpace, CATOmxIter<CATUFOUserActionInformation> & iImpactedIterator, CATUFOServiceOutput *& opOutput);

  // entry point for assisted reroute (defered mode)
  static HRESULT RelationalRerouteRequestProcessing(CATOmbRerouteRequest & ioRequest);
};

#endif
