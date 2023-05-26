#ifndef CATPLMSelectiveLoadingRuleSet_H
#define CATPLMSelectiveLoadingRuleSet_H
/* -*-c++-*- */
/**
 * @level Private
 * @usage U1
 */
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATIPLMSelectiveLoadingRuleSet.h"

class CATOmbLoadingModeRuleSet;

/**
* Managing selective loading rules
*/
namespace CATPLMSelectiveLoadingRuleSet
{
  ExportedByCATPLMTos CATOmxSR<CATIPLMSelectiveLoadingRuleSet> BindRuleSet(CATOmbLoadingModeRuleSet & iRuleSet);
};

#endif
