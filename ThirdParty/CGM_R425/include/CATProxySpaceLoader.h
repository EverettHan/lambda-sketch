#ifndef _CATProxySpaceLoader_H
#define _CATProxySpaceLoader_H
// ----------------------------------------------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2007
/**
 * @level Private
 * @usage U1
 */
 // ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMTos                         AuthorizedModule
#define CATPLMIntegration                 AuthorizedModule
#define CATPLMIntegrationAccess           AuthorizedModule
#define CATImmVPMModel                 AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to link services from a non-infrastructure module
@error
#endif
#undef CATPLMTos   
#undef CATPLMIntegration
#undef CATPLMIntegrationAccess
#undef CATImmVPMModel

#include "ExportedByCATPLMTos.h"
#include "CATTosMacros.h"
#include "CATProxySpace.h"
#include "CATComponentIdLoadingMediator.h"
#include "CATBoolean.h"
#include "CATPLMCompletionLevel.h"

class CATComponentId;
class CATPLMID;
class CATIPLMIntegRecordRead;
class CATIPLMRecordRead;
class CATOmxAny;

class ExportedByCATPLMTos CATProxySpaceLoader
{
public:

  /**
  * Temporaire pour limiter l'acces aux APIs et faire des mesures d'impacts
  */
  static HRESULT PrepareOpen(CATProxySpace & iSpace, const CATPLMID & iIdentifier, CATComponentId & oHandle);

  /**
  * Load Component definition
  *
  *  - PLM attributes
  *  - structural definition (ownership, instanceof)
  *  - relational view
  *
  * @return
  *    S_OK : if succeeded
  */
  static HRESULT LoadComponentDefinition(CATComponentId & iCID, CATIPLMRecordRead * iRecordRead, CATPLMCompletionLevel iCompletionLevel = CATPLMCompletionLevel_Null);

  /**
  * Temporaire pour limiter l'acces aux APIs et faire des mesures d'impacts
  */
  static HRESULT FinalyseOpen(CATComponentId & iHandle, CATBaseUnknown * iCBU);

  static HRESULT ClearAfterOpenFailure(CATComponentId & iHandle);
};

#endif
