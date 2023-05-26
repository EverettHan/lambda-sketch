#ifndef VISGPGPUPROGRAMINITIALIZER_H_
#define VISGPGPUPROGRAMINITIALIZER_H_

#include "CATVisFoundation.h"

#include "CATBaseUnknown.h"
#include "VisGPGPUEncapsulation.h"

class ExportedByCATVisFoundation VisGPGPUProgramInitializer : public CATBaseUnknown
{
  friend class VisGenericProgramTstClass;
  friend class VisGPGPUManager; //To hack CATBaseUnknown private attribute and have access to m_cRef, to check leak

public : 

  VisContextHandle        _contextHandle;
  VisCommandQueueHandle * _commandQueueHandleList;
  VisDeviceHandle       * _deviceHandleList;
  unsigned int            _nbDevices;
  unsigned int            _nbCommandQueues;

  VisGPGPUProgramInitializer();

protected :

  ~VisGPGPUProgramInitializer();
};


#endif //VISGPGPUPROGRAMINITIALIZER_H_
