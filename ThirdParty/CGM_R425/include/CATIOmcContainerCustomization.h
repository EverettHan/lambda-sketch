#ifndef __CATIOmcContainerCustomization_H
#define __CATIOmcContainerCustomization_H

#include "CATOmcEnv.h"
#include "CATBaseUnknown.h"

extern ExportedByCATOmcBase IID IID_CATIOmcContainerCustomization;

/**
 * This interface will allow to implement specific behaviors on containers.
 * It can be fully overriden but must never be called directory.
 */
class ExportedByCATOmcBase CATIOmcContainerCustomization: public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /**
   * Will be called after container creation.
   */
  virtual HRESULT AfterCreation(CATBoolean iNoDoc); //Not pure virtual on purpose, tired of adapters...
};


#endif
