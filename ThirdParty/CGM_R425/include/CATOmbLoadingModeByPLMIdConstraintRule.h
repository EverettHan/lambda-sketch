/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2019

#ifndef CATOmbLoadingModeByPLMIdConstraintRule_H
#define CATOmbLoadingModeByPLMIdConstraintRule_H

/**
* @level Protected
* @usage U1
*/

#include "CATOmbSwitchEngine.h"
#include "CATOmbLoadingModeRule.h"

/**
* This object specifies which rule should be used to determine minimum loading mode to reach for a given PLMID.
*/
class ExportedByCATOmbSwitchEngine CATOmbLoadingModeByPLMIdConstraintRule : public CATOmbLoadingModeRule
{
public:
  /**
  * Specifies the loading mode if a given main stream descriptor type is available on the component.
  * @param iStreamType
  *       The late type of the main stream descriptor
  * @param iLoadinMode
  *       The loading mode to be used if such stream type is available
  */
  CATOmbLoadingModeByPLMIdConstraintRule(const CATPLMID& iComponentId, const CATUnicodeString &iDefaultLoadingMode);

  virtual ~CATOmbLoadingModeByPLMIdConstraintRule();
};

#endif
