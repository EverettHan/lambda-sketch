#ifndef CATKeyboardEvent_H
#define CATKeyboardEvent_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATVisFoundation.h"

#include "CATDeviceEvent.h"

class CATMathVectorf;


/**
* Event notifying of a keyboard action.
*
* <b>Role</b>: Communicates key press and release from the graphic
* window to the viewer
*/
class ExportedByCATVisFoundation CATKeyboardEvent : public CATDeviceEvent
{
 CATDeclareClass;

 public :
    /** @nodoc */
    CATKeyboardEvent();

    virtual ~CATKeyboardEvent();

    /** @nodoc */
    int IsArrow( CATMathVectorf &Jump) const;	// convert the event into a vector

    // LeftKey=-X, RightKey=+X, UpKey=+Y, DownKey=-Y, PageUpKey=+Z, PageDownKey=-Z
    /** @nodoc */
    int Key;	// Key pressed or depressed

       #define LeftKey        1
       #define RightKey       2
       #define UpKey          3
       #define DownKey        4
       #define PageUpKey      5
       #define PageDownKey    6
       #define InsertKey      7
       #define DeleteKey      8
       #define HomeKey        9
       #define EndKey        10
       #define EscapeKey     11
       #define ShiftKey      12
       #define ControlKey    13
       #define EnterKey      14
       #define AltKey        15
       #define SpaceKey      16
   
};


#endif
