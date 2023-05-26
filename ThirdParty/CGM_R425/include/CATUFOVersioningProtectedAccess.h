#ifndef CATUFOVersioningProtectedAccess_H
#define CATUFOVersioningProtectedAccess_H

#define AuthorizedModule                  999
#define CATUFO                            AuthorizedModule
#define CATOmbLinkTrader                  AuthorizedModule
#define CATPLMIntegration                 AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to link services from a non-infrastructure module
@error
#endif

#undef AuthorizedModule
#undef CATUFO
#undef CATOmbLinkTrader
#undef CATPLMIntegration

/**
 * @level Protected
 * @usage U1
 */
#include "ExportedByCATPLMIdentification.h"
#include "IUnknown.h"
#include "CATOmxOHMap.h"
#include "CATPLMID.h"
  class CATProxySpace;

class ExportedByCATPLMIdentification CATUFOVersioningProtectedAccess
{
public:
  static HRESULT RegisterVersioning(const CATOmxOHMap<CATPLMID, CATPLMID> &iOldToNew, const CATProxySpace & iSpace);
};

#endif
