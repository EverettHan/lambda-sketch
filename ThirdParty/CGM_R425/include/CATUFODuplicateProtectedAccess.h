#ifndef CATUFODuplicateProtectedAccess_H
#define CATUFODuplicateProtectedAccess_H

#define AuthorizedModule                  999
#define CATUFO                            AuthorizedModule
#define CATPLMIntegration                 AuthorizedModule
#define CATPLMIdentification_PLM          AuthorizedModule
#define CATOxiUFOLog                      AuthorizedModule
#define CATOxiUFOInsert                   AuthorizedModule
#define CATOxiUFOInsertUndoRedo           AuthorizedModule
#define CATOxiUFOMoveToUndoRedo           AuthorizedModule
#define CATOxiUFOMinorSupport             AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to link services from a non-infrastructure module
@error
#endif

#undef CATUFO
#undef CATPLMIntegration
#undef CATPLMIdentification_PLM
#undef CATOxiUFOLog
#undef CATOxiUFOInsert
#undef CATOxiUFOInsertUndoRedo
#undef CATOxiUFOMoveToUndoRedo
#undef CATOxiUFOMinorSupport

  /**
  * @level Protected
  * @usage U1
  */
#include "ExportedByCATPLMIdentification.h"
#include "IUnknown.h"
#include "CATOmxArray.h"
#include "CATPLMID.h"

  class CATUuid;
class CATListValCATComponentId;
class CATProxySpace;

class ExportedByCATPLMIdentification CATUFODuplicateProtectedAccess
{
public:
  static HRESULT RegisterDuplication(const CATOmxArray<CATPLMID> & iListOfOriginComponents,
                                     const CATOmxArray<CATPLMID> & iListOfDuplicatedComponents, const CATProxySpace & iSpace);

};

#endif
