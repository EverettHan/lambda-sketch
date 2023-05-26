#ifndef CATMouseEvent_H
#define CATMouseEvent_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATVisFoundation.h"
#include "CATDeviceEvent.h"
#include "CATMathPoint2Df.h"


/**
* Event to notify of a mouse Interaction.
*
* <b>Role</b>: Notify of a mouse interaction.
* It informs the viewer and the manipulators of a mouse action, be it a
* motion or a button press/release
*/

#define CATMouseEventButtonDown 1
#define CATMouseEventButtonUp 2
#define CATMouseEventMove 3
#define CATMouseEventWheel 4
#define CATMouseEventDoubleClick 5
#define CATMouseEventNone 0

#define CATMouseButtonPressed 1
#define CATMouseButtonReleased 2

	
#define MouseLeftButtonMask	    (1<<0) 
#define MouseMiddleButtonMask 	(1<<1) 
#define MouseRightButtonMask	(1<<2) 

typedef enum MouseButton 
{
	LeftMouseButton = 1,
	RightMouseButton = 3,
	MiddleMouseButton = 2
	
} MouseButton ;

class ExportedByCATVisFoundation CATMouseEvent : public CATDeviceEvent
{
//------------------------------------------------------------------------------
  CATDeclareClass;

  public :
  /** @nodoc */
    CATMouseEvent();
    virtual ~CATMouseEvent();

  /** @nodoc */
    CATMathPoint2Df Point; // Pixel coordinates pointed by the cursor on the window
  /** @nodoc */
    CATMathPoint2Df PtVpt;	// Pixel coordinates pointed by the cursor on the activated viewpoint
   /** @nodoc */
   int MouseModifiers;		// Status of mouse modifiers 
      // MouseModifier1On : A second mouse button is pressed ( the lefter non-pressed button )
      // MouseModifier1On : A third mouse button is pressed ( the lefter non-pressed button )
      #define MouseModifier1On	(1<<0) 
      #define MouseModifier2On	(1<<1) 
      #define MouseButtonLeft 	(1<<2) 
      #define MouseButtonRight	(1<<3) 

   /** @nodoc */
  // IsButtonPressed :
  // gives the information about the current state of the given button : ibutton.
  // 
  // If the ibutton is pressed, IsButtonPressed returns FALSE. True - otherwise.
  // Ibutton can take 3 values LeftMouseButton, RightMouseButton or MiddleMouseButton
  //
   CATBoolean IsButtonPressed (MouseButton ibutton) ;

    /** @nodoc */
  // GetMouseEventType :
  // gives the information about the latest event that occured through the mouse 
  // The event's type can be either 
  // CATMouseEventButtonDown    : any mouse button was pressed and a PresseEvent was triggered , 
  // or CATMouseEventButtonUp   : any mouse button was released and a ReleaseEvent was triggered,
  // or CATMouseEventMove       : mouse was moved (no other change occured) and a MoveEvent was trigerred
  // or CATMouseEventWheel      : mouse wheel  changed and MotionEvent was trigerred
  // 
  // CATMouseEvent is updated by CATMouseDevice which receives the Press, Release, wheel and Motion events.
   int GetMouseEventType ();  //ButtonDown, MouseWheel, ButtonUp, MouseMove
   
 

    //--------------------------------

   /** @nodoc */
   // Pressed mouse button  : the latest button pressed or released 
   int _pressedButton; 
 
  
   float _wheel;

private :

    int _buttonType;    // down, up, move, wheel, none
	void SetMouseEventType ( int iType);

	int _MouseFlags ; // bit map of all the mouse buttons : left, middle, right 
  void SetMouseFlags ( int iButtonsState);



friend class CATMouseDevice;
friend class CATViewer;
friend class CATGraphicWindow;
};

#endif
