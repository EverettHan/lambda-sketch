#ifndef CATMotionEvent_H
#define CATMotionEvent_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATVisFoundation.h"

#include "CATTimeStampedEvent.h"

/** @nodoc */
#define ButtonMask(i) ((1<<(i))-1)

class CATDevice;
class CATSupport;

/**
* Event notifying of a motion from any kind of device.
*
* <b>Role</b>: Notifies the viewer of any motion from devices 
*/
class ExportedByCATVisFoundation CATMotionEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

  public :
  /** @nodoc */
    CATMotionEvent();
    virtual ~CATMotionEvent();

  /** @nodoc */
    int _buttons;

  /** @nodoc */
    CATDevice *Device;
  /** @nodoc */
    CATSupport *pSupport;
  /** @nodoc */
    float V[6];
  /** @nodoc */
    float Vpt[2];
  /** @nodoc */
    int _drawPending;
  /** @nodoc */
    int _timeExpired;
  /** @nodoc */
    int _forceMotion;
	
private :

	int _MouseFlags; // mouse buttons state  cf CATMouseEvent for masks


	friend class CATGraphicWindow;
	friend class CATMouseDevice;
	friend class CATViewer;
};

#endif
