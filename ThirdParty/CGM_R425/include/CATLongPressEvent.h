#ifndef CATLongPressEvent_H
#define CATLongPressEvent_H

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	Elementary event sent by the physical device to the logical 
//		device (CATDevice) containing the physical button number
//		when it has been pressed.
//------------------------------------------------------------------------------
// Usage :	Used to communicate from the GraphicWindow (that reaceve
//		X-events) to the Viewer which dispatch then to the device.
//------------------------------------------------------------------------------
// Class :	CATPressEvent
//		  CATTimeStampedEvent
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
// #ifdef _WINDOWS_SOURCE

// ZZ extrait de X11/X.h

// Key masks. Used as modifiers to GrabButton and GrabKey, results of QueryPointer,
// state in various key-, mouse-, and button-related events.

// #define ShiftMask		(1<<0)
// #define LockMask		(1<<1)
// #define ControlMask		(1<<2)
// #define Mod1Mask		(1<<3)
// #define Mod2Mask		(1<<4)
// #define Mod3Mask		(1<<5)
// #define Mod4Mask		(1<<6)
// #define Mod5Mask		(1<<7)

/* button masks.  Used in same manner as Key masks above. Not to be confused
   with button names below. */

// #define Button1Mask		(1<<8)
// #define Button2Mask		(1<<9)
// #define Button3Mask		(1<<10)
// #define Button4Mask		(1<<11)
// #define Button5Mask		(1<<12)

// #endif

#include "CATTimeStampedEvent.h"
class CATDevice;
class CATSupport;

/**
* Event notifying of a button pressed on a long click from any kind of device.
*
* <b>Role</b>: Notifies the viewer of any button pressed from devices 
*/
class ExportedByCATVisFoundation CATLongPressEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

  public :

  /** @nodoc */
  CATLongPressEvent();

  /** @nodoc */
  virtual ~CATLongPressEvent();

  /** @nodoc */
  CATDevice *Device;

  /** @nodoc */
  CATSupport *pSupport;

  /**
   * Button number that is being pressed.
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
