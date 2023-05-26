#ifndef CATLongMotionEvent_H
#define CATLongMotionEvent_H

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
* Event notifying of a motion from any kind of device comming after a long press event.
*
* <b>Role</b>: Notifies the viewer of any motion from devices.
*/
class ExportedByCATVisFoundation CATLongMotionEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

  public :
  /** @nodoc */
    CATLongMotionEvent();
    virtual ~CATLongMotionEvent();

  /** @nodoc */
    int _buttons;

  /** @nodoc */
    CATDevice *Device;
  /** @nodoc */
  CATSupport *pSupport;
  /** @nodoc */
    float V[6];
  /** @nodoc */
    int _drawPending;

private :

	int _MouseFlags; // mouse buttons state  cf CATMouseEvent for masks

	friend class CATGraphicWindow;
	friend class CATMouseDevice;
};

#endif
