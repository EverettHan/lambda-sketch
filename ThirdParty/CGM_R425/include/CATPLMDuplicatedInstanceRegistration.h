#ifndef CATPLMDuplicatedInstanceRegistration_H 
#define CATPLMDuplicatedInstanceRegistration_H
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMTos                         AuthorizedModule
#define CATOxiDuplicatedInstanceHistory   AuthorizedModule
#define CATOxiLocalSaveDiffTodoRecovery   AuthorizedModule
#define CATPLMClientCoreModel             AuthorizedModule
#define CATPrdModelStructEdition          AuthorizedModule
#define CATOxiUFOSaveLog                  AuthorizedModule
#define CATPLMIdentification_PLM          AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMDuplicatedInstanceRegistration from a non-infrastructure module
@error
#endif
#undef CATPLMTos
#undef CATOxiDuplicatedInstanceHistory
#undef CATOxiLocalSaveDiffTodoRecovery
#undef CATPLMClientCoreModel
#undef CATPrdModelStructEdition
#undef CATOxiUFOSaveLog
#undef CATPLMIdentification_PLM
// ----------------------------------------------------------------------------------------------------------------------
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"

class CATComponentId;

/**
* Duplicated instances registration
*/
class ExportedByCATPLMTos CATPLMDuplicatedInstanceRegistration
{
public:

  /**
  * Register instance duplication
  *  - Associates same logical family
  *  - Creates an historical dependency between new and old instance
  *
  * @param iNewInstance
  * @param iOldInstance
  * @param iReplace
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RegisterDuplication(const CATComponentId & iNewInstance, const CATComponentId & iOldInstance);

  /**
  * Prepare duplicate operation
  *
  * @param iOldInstance
  * @param iCopyLogicalId
  *        Keep logical associativity
  * @param iKeepAssociativityWithMemoryDependency
  *        Keep associativity between previous and new instance with a memory dependency
  * @param iDynamicRerouteWhenDuplicatedInstanceIsRemoved
  *        Instance has to be removed before. Raised an arror if instance is not deleted.
  *        Reroute is possible only on unsensitive relations.
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static void PrepareDuplicate(const CATComponentId  & iOldInstance,
    CATBoolean              iDynamicRerouteWhenDuplicatedInstanceIsRemoved);

  /**
  * Register instance duplication
  *  - Associates same logical family
  *  - Creates an historical dependency between new and old instance
  *
  * @param iNewInstance
  * @param iOldInstance
  * @param iCopyLogicalId
  *        Keep logical associativity
  * @param iKeepAssociativityWithMemoryDependency
  *        Keep associativity between previous and new instance with a memory dependency
  * @param iDynamicRerouteWhenDuplicatedInstanceIsRemoved
  *        Instance has to be removed before. Raised an arror if instance is not deleted.
  *        Reroute is possible only on unsensitive relations.
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT FinalizeDuplicate(const CATComponentId  & iNewInstance,
    const CATComponentId  & iOldInstance,
    CATBoolean              iCopyLogicalId,
    CATBoolean              iKeepAssociativityWithMemoryDependency,
    CATBoolean              iDynamicRerouteWhenDuplicatedInstanceIsRemoved);
};

#endif
