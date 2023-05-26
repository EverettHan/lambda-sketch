#ifndef __CATOmbLoadingModeRule_H
#define __CATOmbLoadingModeRule_H

/**
 * @level Protected 
 * @usage U1
 */

#include "CATOmbSwitchEngine.h"
#include "CATOmiLoadingModeRule.h"
#include "CATUnicodeString.h"


class ExportedByCATOmbSwitchEngine CATOmbLoadingModeRule: public CATOmiLoadingModeRule
{
public:
  CATOmbLoadingModeRule(CATOmbInternalLoadingModeRule* iRule):CATOmiLoadingModeRule(iRule) {}

  /**
   * Add an alternative target loading mode to a loading mode rule
   * If switch to primary target loading mode is not possible, component will be switched to this alternative loading mode.
   * Notice that adding alternative load mode has effect only on CATOmiSwitchEngine::ValidateSwitchOperations.
   * If a switch fails during CATOmiSwitchEngine::ExecuteSwitchOperations (due to some unpredictable unstream error, IO error...),  
   * switch engine will not try this alternative mode.
   */
  HRESULT AddAlternativeLoadingMode(const CATUnicodeString& iLoadingMode);
};

#endif
