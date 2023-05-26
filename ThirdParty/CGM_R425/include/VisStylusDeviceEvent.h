#ifndef VisStylusDeviceEvent_H
#define VisStylusDeviceEvent_H

#include "CATVisFoundation.h"

#include "CATDeviceEvent.h"
#include "CATMathTransformation.h"

class CATDevice;
class IVButtonEvtArgs;
class IVAnalogEvtArgs;
class IVTrackerEvtArgs;
class IVSUIEntityEvtArgs;

enum VisStylusButtonStatus { STYLUS_LEAVE, STYLUS_MOVE_WITHOUTPICK, STYLUS_MOVE, STYLUS_PRESS, STYLUS_RELEASE, STYLUS_MOVE_PRESSED};
/**
 * VisStylusDeviceEvent
 *
 * Usually use by the CATStylusDevice in order to send data to its manipulators
 */
class ExportedByCATVisFoundation VisStylusDeviceEvent: public CATDeviceEvent
{
  CATDeclareClass;

public:

  VisStylusDeviceEvent();
  virtual ~VisStylusDeviceEvent();

  CATMathTransformation m_Pose;
  VisStylusButtonStatus m_ButtonState;

  IVButtonEvtArgs const* m_pButtonEvtArgs;
  IVAnalogEvtArgs const* m_pAnalogEvtArgs;
  IVTrackerEvtArgs const* m_pTrackerEvtArgs;
  IVSUIEntityEvtArgs const* m_pSUIEntityEvtArgs;

private:
  VisStylusDeviceEvent(const VisStylusDeviceEvent&);
  VisStylusDeviceEvent& operator=(const VisStylusDeviceEvent&);
};

#endif
