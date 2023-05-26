#ifndef CATLongReleaseEvent_H
#define CATLongReleaseEvent_H

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	Elementary event sent by the physical device to the logical 
//		device (CATDevice) containing the physical button number
//		when it has been released.
//------------------------------------------------------------------------------
// Usage :	Used to communicate from the GraphicWindow (that reaceve
//		X-events) to the Viewer which dispatch then to the device.
//------------------------------------------------------------------------------
// Class :	CATReleaseEvent
//		  CATTimeStampedEvent
//------------------------------------------------------------------------------
#include "CATTimeStampedEvent.h"
#include "CATVisFoundation.h"

class CATDevice;
class CATSupport;

/**
* Event notifying of a button pressed on a long click from any kind of device.
*
* <b>Role</b>: Notifies the viewer of any button released from a long click from devices 
*/
class ExportedByCATVisFoundation CATLongReleaseEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

  public :

  /** @nodoc */
  CATLongReleaseEvent();

  /** @nodoc */
  virtual ~CATLongReleaseEvent();
   
  /** @nodoc */
  CATDevice *Device;

  /** @nodoc */
  CATSupport *pSupport;

  /**
   * Button number that is being released.
   * This value must be read only.
   */
  int Button;

  /** @nodoc */
  int XPos;
  /** @nodoc */
  int YPos;

   private :

	int _MouseFlags; // mouse buttons state  cf CATMouseEvent for masks

	friend class CATGraphicWindow;

};

#endif
