#ifndef VisWintabProximityEvent_H
#define VisWintabProximityEvent_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2012
//-----------------------------------------------------------------------------
// Class  :  	VisWintabProximityEvent
// Date   :  	28/02/12
//-----------------------------------------------------------------------------
//  Inheritance : VisWintabProximityEvent
//		               CATTimeStampedEvent
//				            CATNotification
//-----------------------------------------------------------------------------
// Abstract : This class defines an event to describe a proximity 
//            from tablet devices.
//------------------------------------------------------------------------------
// Role :     The VisWintabProximityEvent notifies the viewer of any tablet proximity, stylus entering or leaving.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//-----------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATTimeStampedEvent.h"
class CATDevice;
class CATSupport;

class ExportedByCATVisFoundation VisWintabProximityEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

public:

  // constructor / destructor
  VisWintabProximityEvent();
  virtual ~VisWintabProximityEvent();

  // Copy constructor and equal operator
  VisWintabProximityEvent (const VisWintabProximityEvent &);
  VisWintabProximityEvent & operator = (const VisWintabProximityEvent &);

  // Get device plugged for this event
  CATDevice* Device;

  // Get event publisher, it is the support on which the event has been executed
  CATSupport* pSupport;

  // Get the entry or leave mode of the stylus
  // The _leaveMode is non-zero when the cursor is entering the context
  // and zero when it is leaving the context
  int _leaveMode;
};
#endif
