#ifndef _CATPLMSessionExtractor_H
#define _CATPLMSessionExtractor_H
// ----------------------------------------------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMTos                         AuthorizedModule
#define CATPLMExternals                   AuthorizedModule
#define CATPLMCollabMgt                   AuthorizedModule
#define CATPLMIntegration                 AuthorizedModule
#define CATPLMIntegrationBase             AuthorizedModule
#define CATOxiRelationAccess              AuthorizedModule
#define CATOxiSessionManager              AuthorizedModule
#define CATPLMIdentification_PLM          AuthorizedModule
#define CATPLMTosManager                  AuthorizedModule
#define CATPLMTosStream                   AuthorizedModule
#define CATOxiReidentify                  AuthorizedModule
#define CATPLMOfflineContentBase          AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMSessionExtractor from a non-infrastructure module
@error
#endif
#undef CATPLMTos
#undef CATPLMExternals
#undef CATPLMCollabMgt
#undef CATPLMIntegration
#undef CATPLMIntegrationBase
#undef CATOxiRelationAccess
#undef CATOxiSessionManager
#undef CATPLMIdentification_PLM
#undef CATPLMTosManager
#undef CATPLMTosStream
#undef CATOxiReidentify
#undef CATPLMOfflineContentBase
// ----------------------------------------------------------------------------------------------------------------------

#include "ExportedByCATPLMTos.h"
#include "CATComponentId.h"
#include "CATCollec.h"

class CATPLMSemanticRelation;
class CATLISTP(CATPLMSemanticRelation);
class CATBinary;

/**
* Access to PLM relations
*/
class CATPLMSessionExtractor
{
public:
  CATPLMSessionExtractor(const CATComponentId & iCID) :_CID(iCID) {}

  /**
  * Asks for a component to export session state.
  * <br><b>Role:</b>This method enables to export session state for a late send to a specific repository.
  * @param oSessionState [out]
  *   The result of the export operation.
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt>: The data were succesfully generated.</li>
  *   <li><tt>E_FAIL</tt>: Failure occured during the treatment.</li>
  *   </ul>
  */
  ExportedByCATPLMTos HRESULT ExtractMemoryState(CATBinary & oSessionState);

  /**
  * Asks for a component to export relations.
  * <br><b>Role:</b>This method enables to export relations component for a late send to a specific repository.
  * @param oResult [out]
  *   The result of the export operation.
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt>: The relation were succesfully generated.</li>
  *   <li><tt>E_FAIL</tt>: Failure occured during the treatment.</li>
  *   </ul>
  */
  ExportedByCATPLMTos HRESULT ExtractRelations(CATOmxArray<CATPLMSemanticRelation> & ioSRList);

private:
  const CATComponentId _CID;
};

#endif
