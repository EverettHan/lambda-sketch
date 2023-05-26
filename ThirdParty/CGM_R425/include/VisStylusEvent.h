#ifndef VisStylusEvent_H
#define VisStylusEvent_H

#include "CATVisFoundation.h"
#include "CATTimeStampedEvent.h"
#include "CATMathTransformation.h"
#include "VisStylusDeviceEvent.h"
class CATDevice;
class CATSupport;

/**
 * VisStylusEvent
 *
 * Usually emitted by the graphic window and interpreted by the
 * viewer/CATDevice (m_Device)
 */

class ExportedByCATVisFoundation VisStylusEvent: public CATTimeStampedEvent
{
  CATDeclareClass;

public:

  VisStylusEvent();
  VisStylusEvent(const CATMathTransformation& iPose, VisStylusButtonStatus iState);
  virtual ~VisStylusEvent();

  /** @nodoc */
  CATDevice* m_Device;

  // Get event publisher, it is the support on which the event has been executed
  CATSupport* m_Support;

  CATMathTransformation m_Pose;

  VisStylusButtonStatus m_ButtonState;

private:
  VisStylusEvent(const VisStylusEvent&);
  VisStylusEvent& operator=(const VisStylusEvent&);
};

#endif
