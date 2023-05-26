#ifndef CATVisuContext_H
#define CATVisuContext_H

#include "SGInfra.h"

//------------------------------------
/**
 * Defines the graphic acceleration capability associated to the context
 * It can be one of the three following values :
 *  - HardwareAcceleration
 *    This context relies on the hardware capabilities of the graphics board to perform its rendering
 *  - SoftwareAcceleration
 *    This context relies on software capabilities to perform its rendering
 *  - Unknown (default value)
 *    No information is available for this context
 */
#ifndef _GraphicAcceleration
#define _GraphicAcceleration
enum GraphicAcceleration
{
	Unknown								= 0,
  HardwareAcceleration	= 1,
  SoftwareAcceleration	= 2,
  kAccelerationProfiles	= 3,
  kBestAvailableProfile	= HardwareAcceleration
};
#endif // _GraphicAcceleration
//------------------------------------


//-----------------------------------------------------------------------
// ORE Suppression
// This code is only usefull to not break the build

class CATVisGPUStorageManager;
class CATVisuContext
{
public:
  CATVisuContext() {};
  ~CATVisuContext() {};
  CATVisGPUStorageManager*  GetGPUStorageManager() {return nullptr;}
};

#endif
//-----------------------------------------------------------------------
