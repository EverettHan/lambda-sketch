#ifndef VisSpaceViewerEvent_H
#define VisSpaceViewerEvent_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
// Class  :  	VisSpaceViewerEvent
// Date   :  	28/06/11
//-----------------------------------------------------------------------------
//  Inheritance : VisSpaceViewerEvent
//					        CATViewerEvent
//					          CATTimeStampedEvent
//					            CATNotification
//-----------------------------------------------------------------------------
// Abstract : This class defines an event send to manipulator by viewer 
//            to describe a space event.
//-----------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATViewerEvent.h"
class VisTouchGesture;


class ExportedByCATVisFoundation VisSpaceViewerEvent : public CATViewerEvent
{
  CATDeclareClass;

public:

  // constructor / destructor
  VisSpaceViewerEvent(CATDeviceEvent *e = NULL, CATPickPath *p = NULL);
  virtual ~VisSpaceViewerEvent();

  // modify the device event
  void SetDeviceEvent(CATDeviceEvent* ipDeviceEvent);

};

#endif // VisSpaceViewerEvent_H

