#ifndef _IVIImmersiveConfigurationManager_H
#define _IVIImmersiveConfigurationManager_H

//COPYRIGHT DASSAULT SYSTEMES 2010

#include "CATVisItf.h"

#include "CATSysErrorDef.h"
#include "CATBoolean.h"

class ExportedByCATVisItf IVIImmersiveConfigurationManager
{
public:
  virtual ~IVIImmersiveConfigurationManager();
  
  static HRESULT GetManager(IVIImmersiveConfigurationManager*& opManager);  
  
  /**
   * Stereoscopy management
   */
  virtual HRESULT IsStereoscopyRequested(CATBoolean& obIsRequested) = 0;
  virtual HRESULT RequestStereoscopy(CATBoolean ibIsRequested) = 0;

  /**
   * Synchronization management. New render engine only.
   */
  virtual HRESULT IsSynchronizationRequested(CATBoolean& obIsRequested) = 0;
  virtual HRESULT RequestSynchronization(CATBoolean ibIsRequested) = 0;
  
  virtual HRESULT SaveConfiguration() = 0;
  
protected:
  IVIImmersiveConfigurationManager();
};

//------------------------------------------------------------------

#endif // _IVIImmersiveConfigurationManager_H
