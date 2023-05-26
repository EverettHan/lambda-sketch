/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATOmbDefaultLoadingModeRule_H
#define CATOmbDefaultLoadingModeRule_H

/**
 * @level Protected 
 * @usage U1
 */

#include "CATOmbSwitchEngine.h"
#include "CATOmbLoadingModeRule.h"

class ExportedByCATOmbSwitchEngine CATOmbDefaultLoadingModeRule:public CATOmbLoadingModeRule
{
public:
  /**
  * Specifies the default loading mode for all components. 
  * @param iDefaultLoadingMode 
  *       The default loading mode.  
  */

  CATOmbDefaultLoadingModeRule(const CATUnicodeString& iDefaultLoadingMode);

  /**
  * Destroys the service.    
  *<br> Frees the ressources of this object. 
  **/
  virtual ~CATOmbDefaultLoadingModeRule();

private:

  // Copy Constructor and copy operator are forbidden. 
  CATOmbDefaultLoadingModeRule (CATOmbDefaultLoadingModeRule &);
  CATOmbDefaultLoadingModeRule& operator=(CATOmbDefaultLoadingModeRule&);

};

#endif


