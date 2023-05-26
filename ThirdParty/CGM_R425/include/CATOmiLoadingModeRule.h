/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005
//-----------------------------------------------------------------------------
//
#ifndef CATOmiLoadingModeRule_H
#define CATOmiLoadingModeRule_H

/**
* @level Protected
* @usage U6
*/

#include "CATOmiSwitchEngineItf.h"
#include "CATErrorDefs.h"

class CATOmbInternalLoadingModeRule;

/**
* Defines a Rule to determine the target loading mode of a RepRef
* This class has to be derived in order to provide the different rules to the switch engine.
* Using these rules, the switch engine will determine the loading mode to use.
*/
class ExportedByCATOmiSwitchEngineItf CATOmiLoadingModeRule
{
public:
  CATOmbInternalLoadingModeRule* rule;

  CATOmiLoadingModeRule(CATOmbInternalLoadingModeRule* iRule);

  virtual ~CATOmiLoadingModeRule();
private:
  CATOmiLoadingModeRule();
  CATOmiLoadingModeRule(const CATOmiLoadingModeRule&);
  CATOmiLoadingModeRule& operator=(const CATOmiLoadingModeRule&);
};

#endif
