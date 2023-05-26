#ifndef CATReleaseEvent_H
#define CATReleaseEvent_H

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

#include "CATVisFoundation.h"
#include "CATTimeStampedEvent.h"

class CATDevice;
class CATSupport;

/**
* Event notifying of a button released from any kind of device.
*
* <b>Role</b>: Notifies the viewer of any button released from devices 
*/
class ExportedByCATVisFoundation CATReleaseEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

  public :

  /** @nodoc */
  CATReleaseEvent();

  /** @nodoc */
  virtual ~CATReleaseEvent();
   
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
  int doNotChooseManipulator;

  /** @nodoc */
  int XPos;
  /** @nodoc */
  int YPos;

  private :

	int _MouseFlags; // mouse buttons state  cf CATMouseEvent for masks

	friend class CATGraphicWindow;
	friend class CATMouseDevice;
	friend class CATViewer;

};

#endif
