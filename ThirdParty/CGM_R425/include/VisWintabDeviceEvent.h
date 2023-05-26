#ifndef VisWintabDeviceEvent_H
#define VisWintabDeviceEvent_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
// Class  :  	VisWintabDeviceEvent
// Date   :  	28/02/12
//-----------------------------------------------------------------------------
//  Inheritance : VisWintabDeviceEvent
//					      CATMouseEvent
//					        CATDeviceEvent
//					          CATTimeStampedEvent
//					            CATNotification
//-----------------------------------------------------------------------------
// Abstract : This class defines an event used by other events to describe an event 
//            from tablet devices.
//------------------------------------------------------------------------------
// Role :     The VisWintabDeviceEvent notifies the viewer of any tablet touch.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//-----------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATMouseEvent.h"
#include "VisWintabData.h"

class CATDevice;

class ExportedByCATVisFoundation VisWintabDeviceEvent : public CATMouseEvent
{
  CATDeclareClass;

public :

   // constructor / destructor
   VisWintabDeviceEvent();
   virtual ~VisWintabDeviceEvent();

  // Copy constructor and equal operator
	VisWintabDeviceEvent (const VisWintabDeviceEvent &);
   VisWintabDeviceEvent & operator = (const VisWintabDeviceEvent &);

   WintabPacket _WTData;

protected :

private:
};

#endif
