#ifndef VisStylusVIDDeviceEvent_H
#define VisStylusVIDDeviceEvent_H

#include "CATVisFoundation.h"

#include "CATMouseEvent.h"
#include "CATMathTransformation.h"
#include "VisStylusDeviceEvent.h"
class CATDevice;

/**
 * VisStylusVIDDeviceEvent
 *
 * Event specific to the Stylus device but seen as a CATMouseEvent in order to access the pixel coordinates of the aimed point.
 */

class ExportedByCATVisFoundation VisStylusVIDDeviceEvent: public CATMouseEvent
{
  CATDeclareClass;

public:

  VisStylusVIDDeviceEvent();
  virtual ~VisStylusVIDDeviceEvent();

  VisStylusButtonStatus m_ButtonState;

private:
  VisStylusVIDDeviceEvent(const VisStylusVIDDeviceEvent&);
  VisStylusVIDDeviceEvent& operator=(const VisStylusVIDDeviceEvent&);
};

#endif
