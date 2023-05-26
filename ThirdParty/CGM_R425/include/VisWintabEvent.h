#ifndef VisWintabEvent_H
#define VisWintabEvent_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
// Class  :  	VisWintabEvent
// Date   :  	28/02/12
//-----------------------------------------------------------------------------
//  Inheritance : VisWintabEvent
//		               CATTimeStampedEvent
//				            CATNotification
//-----------------------------------------------------------------------------
// Abstract : This class defines an event used by other events to describe a touch 
//            from tablet devices.
//------------------------------------------------------------------------------
// Role :     The VisWintabEvent notifies the viewer of any tablet touch.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//-----------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATTimeStampedEvent.h"
#include "CATMathPoint2Df.h"
#include "VisWintabData.h"

class CATDevice;
class CATSupport;

class ExportedByCATVisFoundation VisWintabEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

public :

  // constructor / destructor
  VisWintabEvent();
  virtual ~VisWintabEvent();

  // Copy constructor and equal operator
	VisWintabEvent (const VisWintabEvent &);
  VisWintabEvent & operator = (const VisWintabEvent &);

  // Get device plugged for this event
  CATDevice* Device;

  // Get event publisher, it is the support on which the event has been executed
  CATSupport* pSupport;

  CATMathPoint2Df Point; // Pixel coordinates pointed by the cursor on the window
  int _pressedButton;	  // Pressed mouse button 
  int _eventType;

  WintabPacket _WTData;

protected :

private:
};

#endif
