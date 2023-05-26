#ifndef VisMultitouchDeviceEvent_H
#define VisMultitouchDeviceEvent_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
// Class  :  	VisMonotouchDeviceEvent
// Date   :  	28/06/11
//-----------------------------------------------------------------------------
//  Inheritance : VisMultitouchDeviceEvent
//					        CATDeviceEvent
//					          CATTimeStampedEvent
//					            CATNotification
//-----------------------------------------------------------------------------
// Abstract : This class defines an event to notify of a touch interaction 
//            with several or one fingers.
//------------------------------------------------------------------------------
// Role :     Notifies the manipulator of a multitouch interaction.
//            The VisMultitouchDeviceEvent is given by the CATVizViewer to the manipulator 
//            by calling Manipulator behavior methods.
//            It is send inside a VisTouchViewerEvent.
//            It informs the viewer and the manipulators of a multitouch or mmonotouch action, as a
//            flicks or a pinch.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//	  manage the touch event
//		  InitWithMultiTouchEvent
//		  GetTouchEvent
//-----------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATDeviceEvent.h"
#include "VisListOfTouchEvent.h"
class VisTouchEvent;
class VisMultitouchEvent;


class ExportedByCATVisFoundation VisMultitouchDeviceEvent : public CATDeviceEvent
{
  CATDeclareClass;

public:
  
  // constructor / destructor
  VisMultitouchDeviceEvent();

  virtual ~VisMultitouchDeviceEvent();

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
