#ifndef CATIPLMSelectiveLoadingRuleSet_H
#define CATIPLMSelectiveLoadingRuleSet_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
 * @level Private
 * @usage U3
 */
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATOmxSR.h"
#include "CATOmxSharable.h"
class CATOmbLoadingModeRuleSet;

/**
* Interface for managing selective loading mode.
*/
class CATIPLMSelectiveLoadingRuleSet : public CATOmxSharable
{
public:
  virtual CATOmbLoadingModeRuleSet& GetRuleSet() = 0;
};

typedef CATOmxSR<CATIPLMSelectiveLoadingRuleSet> CATIPLMSelectiveLoadingRuleSet_var;

#endif
