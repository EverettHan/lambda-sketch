#ifndef VisMultitouchEvent_H
#define VisMultitouchEvent_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
// Class  :  	VisMultitouchEvent
// Date   :  	28/06/11
//-----------------------------------------------------------------------------
//  Inheritance : VisMultitouchEvent
//					        CATTimeStampedEvent
//					          CATNotification
//-----------------------------------------------------------------------------
// Abstract : This class defines an event notifying of a multi touch from 
//            touch devices.
//------------------------------------------------------------------------------
// Role :     Notifies the viewer of any multi touch sequence from devices 
//            The VisMultitouchEvent is send by the CATGraphicWindow to 
//            notify the viewer.
//            It contains several or one VisTouchEvent, each of them 
//            describing a touche.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//	  manage the event of one touch
//		  GetTouchEventCount
//		  GetTouchEvent
//-----------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATTimeStampedEvent.h"
#include "CATDevice.h"
#include  "VisListOfTouchEvent.h"
class VisTouchEvent;
class CATSupport;

class ExportedByCATVisFoundation VisMultitouchEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

public:

  // constructor / destructor
  VisMultitouchEvent();
  virtual ~VisMultitouchEvent();

  // Copy constructor and equal operator
  VisMultitouchEvent (const VisMultitouchEvent &);
  VisMultitouchEvent& operator = (const VisMultitouchEvent &);

  // Get device plugged for this event
  CATDevice* Device;

  // Get event publisher, it is the support on which the event has been executed
  CATSupport *pSupport;

  // Fill the touch event list
  void AddEvent(const VisTouchEvent* ipEvent);
  void RemoveAllEvents();

  // Get each touch event from index 0 to count-1
  int GetTouchEventCount() const;
  const VisTouchEvent* GetTouchEvent(int iTouchEventIndex) const;

  void ModifyTouchEvent (int iTouchEventIndex, VisTouchEvent* NewValue);

private:

  CATListPtrVisTouchEvent _touchEventList;
};

#endif
