#ifndef VisMonotouchDeviceEvent_H
#define VisMonotouchDeviceEvent_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
// Class  :  	VisMonotouchDeviceEvent
// Date   :  	28/06/11
//-----------------------------------------------------------------------------
//  Inheritance : VisMonotouchDeviceEvent
//					        CATMouseEvent
//					          CATDeviceEvent
//					            CATTimeStampedEvent
//					              CATNotification
//-----------------------------------------------------------------------------
// Abstract : This class defines an event to notify of a single touch interaction 
//            considered as a mouse interaction.
//------------------------------------------------------------------------------
// Role :     Notifies the manipulator of a mono touch interaction.
//            The VisMonotouchDeviceEvent is given by the CATVizViewer to the manipulator 
//            by calling Manipulator behavior methods.
//            It is send inside a VisTouchViewerEvent.
//            It informs the viewer and the manipulators of a single touch action, as a
//            motion or a touch down/up
//            VisMonotouchDeviceEvent overload CATMouseEvent in order to keep mouse compatility
//            of the applications. If the touch is equivalent to a mouse interaction, the 
//            applicative mouse behavior is used for touch.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//-----------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATMouseEvent.h"
#include "VisListOfTouchEvent.h"
class VisTouchEvent;
class VisMultitouchEvent;


class ExportedByCATVisFoundation VisMonotouchDeviceEvent : public CATMouseEvent
{
  CATDeclareClass;

public:

  // constructor / destructor
  VisMonotouchDeviceEvent();

  virtual ~VisMonotouchDeviceEvent();

  // Init with the touch event list
  void InitWithMultiTouchEvent(const VisMultitouchEvent* ipEvent);

  // Get each touch event from index 0 to count-1
  int GetTouchEventCount();
  VisTouchEvent* GetTouchEvent(int iTouchEventIndex);

private:

  // Remove all touch event from the list
  void RemoveAllEvents();

  CATListPtrVisTouchEvent _touchEventList;
};

#endif
