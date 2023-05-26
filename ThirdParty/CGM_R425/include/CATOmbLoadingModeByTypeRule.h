/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATOmbLoadingModeByTypeRule_H
#define CATOmbLoadingModeByTypeRule_H

/**
 * @level Protected 
 * @usage U1
 */

#include "CATOmbSwitchEngine.h"
#include "CATOmbLoadingModeRule.h"

/**
* This object specifies which rule should be used to determine the loading mode 
* according to the late type of the main stream descriptor. 
*/
class ExportedByCATOmbSwitchEngine CATOmbLoadingModeByTypeRule: public CATOmbLoadingModeRule
{
public:
  /**
  * Specifies the loading mode if a given main stream descriptor type is available on the component. 
  * @param iStreamType
  *       The late type of the main stream descriptor
  * @param iLoadinMode
  *       The loading mode to be used if such stream type is available
  */
  CATOmbLoadingModeByTypeRule(const CATUnicodeString &iStreamType, const CATUnicodeString &iLoadingMode);

  virtual ~CATOmbLoadingModeByTypeRule();
};

#endif


