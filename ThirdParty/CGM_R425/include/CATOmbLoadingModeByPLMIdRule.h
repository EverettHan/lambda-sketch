#ifndef CATOmbLoadingModeByPLMIdRule_H
#define CATOmbLoadingModeByPLMIdRule_H

/**
 * @level Protected 
 * @usage U1
 */

#include "CATOmbSwitchEngine.h"
#include "CATOmbLoadingModeRule.h"

#include "CATUnicodeString.h"
class CATPLMID;

/**
* This object specifies which rule should be used to determine the loading mode 
* of a given component. 
*/
class ExportedByCATOmbSwitchEngine CATOmbLoadingModeByPLMIdRule: public CATOmbLoadingModeRule
{
public:

  /* Constructor
  *
  * @param iComponentId
  *       the id of the component
  * @param iLoadingMode
  *       The loading mode to be used if such stream type is available
  */
  CATOmbLoadingModeByPLMIdRule(const CATPLMID& iComponentId, const CATUnicodeString& iLoadingMode);

  virtual ~CATOmbLoadingModeByPLMIdRule();
};

#endif


