#ifndef CATOmbLoadingModeRuleByCompletionLevel_H
#define CATOmbLoadingModeRuleByCompletionLevel_H

/**
 * @level Protected 
 * @usage U1
 */

#include "CATOmbLoadingModeRule.h"
#include "CATPLMCompletionLevel.h"

/**
 * This class allows to associate a load mode to the completion level of a PLM component.
 * Pass it to CATIOmiSwitchEngine::AddLoadingModeRule.
 */
class ExportedByCATOmbSwitchEngine CATOmbLoadingModeRuleByCompletionLevel:public CATOmbLoadingModeRule
{
public:
  CATOmbLoadingModeRuleByCompletionLevel(const CATPLMCompletionLevel& iCompletionLevel,const CATUnicodeString& iLoadingMode);
  virtual  ~CATOmbLoadingModeRuleByCompletionLevel();
};

#endif


