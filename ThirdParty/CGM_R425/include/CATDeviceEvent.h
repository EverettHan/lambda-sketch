#ifndef CATDeviceEvent_H
#define CATDeviceEvent_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATVisFoundation.h"
#include "CATVisFoundation.h"

#include "CATTimeStampedEvent.h"

/**
  * Class to notify an event from a device.
  *
  * <b>Role</b>: Describe the nature of the event and
  * provide additionnal information specific to that event.
  * This class is derived for specific devices.
  * It Handles communication between the viewer, the manipulator ans
  * the CATDevices.
  */

class ExportedByCATVisFoundation CATDeviceEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

  public:
    /** @nodoc */
    CATDeviceEvent();

    virtual ~CATDeviceEvent();

    /**
      * State of the Crtl and Shift Keyboard keys when the event occured.
      * <br>The state is set on a bit:
      * <ul>
      * <li><tt>ShiftModifierOn</tt>: The bit mask for the Shift key </li>
      * <li><tt>ControlModifierOn</tt>: The bit mask for the Control key </li>
      * </ul>
      */
    int GeneralModifier;	// Modifiers status shared by all devices

    /** 
    * @nodoc 
    * ShiftModifierOn : the Shift key is down
    */
    #define ShiftModifierOn    (1<<0)
    /** @nodoc 
    * ControlModifierOn : the Control (Ctrl) key is down
    */
    #define ControlModifierOn  (1<<2)
    /** 
    * @nodoc 
    * AltModifierOn : the Alt key is down
    */ 
    #define AltModifierOn      (1<<3)
    /** @nodoc 
    * SpaceModifierOn : the Space bar key is down
    */
    #define SpaceModifierOn    (1<<4)

};

#endif
