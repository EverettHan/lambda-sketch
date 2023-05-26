#ifndef VisWintabViewerEvent_H
#define VisWintabViewerEvent_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2012
//-----------------------------------------------------------------------------
// Class  :  	VisWintabViewerEvent
// Date   :  	22/11/12
//-----------------------------------------------------------------------------
//  Inheritance : VisWintabViewerEvent
//					        CATViewerEvent
//					          CATTimeStampedEvent
//					            CATNotification
//-----------------------------------------------------------------------------
// Abstract : This class defines an event send to manipulator by viewer 
//            to describe a stylus event.
//------------------------------------------------------------------------------
// Role :     The VisWintabViewerEvent notifies the manipulator that a stylus event occured.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//	  get the device event:
//          a VisStylusProximityDeviceEvent in case of stylus proximity
//          a VisWintabDeviceEvent in case of stylus move
//		  GetDeviceEvent
//
//-----------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATViewerEvent.h"


class ExportedByCATVisFoundation VisWintabViewerEvent : public CATViewerEvent
{
  CATDeclareClass;

public:

  // constructor / destructor
  VisWintabViewerEvent(CATDeviceEvent *e = NULL, CATPickPath *p = NULL);
  virtual ~VisWintabViewerEvent();

  // modify the device event
  void SetDeviceEvent(CATDeviceEvent* ipDeviceEvent);
};

#endif // VisWintabViewerEvent_H

