#ifndef VisStylusVIDEvent_H
#define VisStylusVIDEvent_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2017
//-----------------------------------------------------------------------------
// Class  :  	VisStylusVIDEvent
// Date   :  	24/11/2017
//-----------------------------------------------------------------------------
//  Inheritance : VisStylusVIDEvent
//					        CATMouseEvent
//					          CATDeviceEvent
//					            CATTimeStampedEvent
//					              CATNotification
//-----------------------------------------------------------------------------
// Abstract : 
//------------------------------------------------------------------------------
// Role :    
//-----------------------------------------------------------------------------
//  Main Methods :
//
//-----------------------------------------------------------------------------


#include "CATMathTransformation.h"
#include "CATVisFoundation.h"
#include "CATMouseEvent.h"
#include "VisStylusVIDDeviceEvent.h"
class CATDevice;
class CATSupport;

class ExportedByCATVisFoundation VisStylusVIDEvent : public CATMouseEvent
{
  CATDeclareClass;

public:

  // constructor / destructor
  VisStylusVIDEvent();

  virtual ~VisStylusVIDEvent();

  /** @nodoc */
  CATDevice* m_Device;

  // Get event publisher, it is the support on which the event has been executed
  CATSupport* m_Support;

  //CATMathTransformation m_Pose;

  VisStylusButtonStatus m_ButtonState;

private:

};

#endif
