#ifndef VisTouchViewerEvent_H
#define VisTouchViewerEvent_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
// Class  :  	VisTouchViewerEvent
// Date   :  	28/06/11
//-----------------------------------------------------------------------------
//  Inheritance : VisTouchViewerEvent
//					        CATViewerEvent
//					          CATTimeStampedEvent
//					            CATNotification
//-----------------------------------------------------------------------------
// Abstract : This class defines an event send to manipulator by viewer 
//            to describe a touch event.
//------------------------------------------------------------------------------
// Role :     The VisTouchViewerEvent notifies the manipulator that a touch event occured.
//            It contains the recognized gesture from touch sequence.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//	  get the device event:
//          a VisMonoTouchEvent in case of touch gesture equivalent to a mouse event
//          a VisMultiTouchEvent instead
//		  GetTouchGesture
//
//	  get the touch gesture
//		  GetTouchGesture
//-----------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATViewerEvent.h"
class VisTouchGesture;


class ExportedByCATVisFoundation VisTouchViewerEvent : public CATViewerEvent
{
  CATDeclareClass;

public:

  // constructor / destructor
  VisTouchViewerEvent(CATDeviceEvent *e = NULL, CATPickPath *p = NULL);
  virtual ~VisTouchViewerEvent();

  // modify the device event
  void SetDeviceEvent(CATDeviceEvent* ipDeviceEvent);

  // get/set the identified touch gesture
  void SetTouchGesture(const VisTouchGesture* ipTouchGesture);
};

#endif // VisTouchViewerEvent_H

