#ifndef CATPLMSessionDuplicateServicesForDWC_H 
#define CATPLMSessionDuplicateServicesForDWC_H 1
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMTosManager                  AuthorizedModule
#define CATOxiSessionDuplicate            AuthorizedModule
#define CATOmbDWC                         AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMSessionDuplicateServicesForDWC from a non-infrastructure module
@error
#endif
#undef CATPLMTosManager
#undef CATOxiSessionDuplicate
#undef CATOmbDWC
// ----------------------------------------------------------------------------------------------------------------------
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATIPLMSelectiveLoadingRuleSet.h"
#include "CATIPLMErrorCollector.h"

class CATPLMBag;
class CATComponentId;
class CATOmxKeyValueBlock;
class CATListValCATComponentId;

/**
* Duplicate services
*/
class ExportedByCATPLMTos CATPLMSessionDuplicateServicesForDWC
{
public:

  /**
  * Duplicates a component for CATDWC.
  * Duplicate is partially realized, propagate is strictly forbidden.
  * Is working only if authoring stream is accessible (No extra download will be done).
  *
  * @param iToDuplicate
  *        The component to be duplicated.
  * @param iBag
  *        A bag for managing life cycle.
  * @param oDuplicateResult
  *        The duplicated component.
  * @param ihOptionalRuleSet
  *        Optional rule set for managing selective loading.
  * @param ihOptionalErrorCollector
  *        Optional error collector.
  * @return
  *      S_OK if request succeeded
  *      E_FAIL if request failed
  *
  */
  static HRESULT DuplicateComponentForDWC(const CATComponentId               & iToDuplicate,
    CATPLMBag                          & iBag,
    CATComponentId                     & oDuplicateResult,
    CATIPLMSelectiveLoadingRuleSet*      ihOptionalRuleSet = nullptr,
    CATIPLMErrorCollector_var            ihOptionalErrorCollector = NULL_var);

};

#endif
