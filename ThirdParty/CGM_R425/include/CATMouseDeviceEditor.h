#ifndef CATMouseDeviceEditor_H
#define CATMouseDeviceEditor_H
//
// CATIA Version 6 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	Basic class of DeviceEditor. 
//------------------------------------------------------------------------------
// Usage :	Derive from this class to give a specific behaviour of your
//		manipulation in the xxxManipulate methods 
//
//		This class manage the sensitivity of movement and the dialog
//		with the mouse and mouse modifiers, keyboard modifiers
//
//------------------------------------------------------------------------------
// Class :	CATMouseDeviceEditor
//		  CATCommand
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
//#include "CATCommand.h"
//#include "CATCallbackManager.h"
#include "CATDeviceEditor.h"
#include "CATIMouseEditor.h"



/** @nodoc 
*  WARNING : this class is defined in Visualization framework */
/*
enum CATMouseInteraction_Id {

   CATMouseInteraction_None,
   CATMouseInteraction_Press1,			//left button down                                                      done
   CATMouseInteraction_Press2,			//midle button down                                                     done
   CATMouseInteraction_Press3,			//right button down
   CATMouseInteraction_Press12,			//left button down then middle button down (both are hold down)         done
   CATMouseInteraction_Press21,			//middle button down then left button down (both are hold down)         done
   CATMouseInteraction_DoubleClick1,	//left button double clicked                                          done
   CATMouseInteraction_DoubleClick2,	//middle button double clicked                                        done
   CATMouseInteraction_Move0,			//mouse move no buttons are pressed                                       done
   CATMouseInteraction_Move1,			//mouse move left button is pressed                                       done
   CATMouseInteraction_Move2,			//mouse move middle button is pressed                                     done
   CATMouseInteraction_Move3,			//mouse move right button is pressed 
   CATMouseInteraction_MouseLeave,		//mouse leave                                                         done
   CATMouseInteraction_Press1Click2,	//left button is pressed as the middle button is clicked (pressed and released)
   CATMouseInteraction_Press2Click1,    //middle button is pressed as the left button is clicked (pressed and released)
   CATMouseInteraction_Release1,		//left button is released                                               done
   CATMouseInteraction_Release2,		//middle button is released                                             done
   CATMouseInteraction_Release3,		//right button is released
   CATMouseInteraction_Wheel,			//mouse wheel is moving)
  
} ;
*/
//#define MouseInteractionNumber 23

/** @nodoc */
// typedef void (CATBaseUnknown::*CATMouseAction)( CATMouseEvent &MouseEvent);
/** @nodoc */
//typedef void (CATBaseUnknown::*CATKeyboardMethod)( CATKeyboardEvent &KeyboardEvent);

/**Basic class of Viewpoint manipulation of a viewer.
*/

class ExportedByCATVisFoundation CATMouseDeviceEditor : public CATDeviceEditor
{
   
   /**@nodoc */
   CATDeclareClass;

//------------------------------------------------------------------------------
public :

   /**@nodoc */
   /** Create a device editor that will modify the viewpoint.
   *  To be activated, the DeviceEditor has to be declared to the viewer
   *  with CATViewer::SetMouseDeviceEditor( iDeviceEditor)
   *  Create this CATMouseDeviceEditor by using factory static method CreateCATMouseDeviceEditor.
   */
  // Standard constructor
  // --------------------
 
  static CATMouseDeviceEditor* CreateCATMouseDeviceEditor(CATVizViewer *iViewer);

  CATMouseDeviceEditor( CATDevice *iDevice, CATVizViewer *iVizViewer);

   /** Destruction of the viewpoint editor.
   *  before the destruction, the viewpoint editor has to be detached
   * form the viewer by CATViewer::SetViewpointEditor( NULL)
   */
   ~CATMouseDeviceEditor();
//------------------------------------------------------------------------------
   
   virtual CATDeviceAction GetActionForInteraction (CATMouseInteraction_Id ident, CATNotification *ievent, CATSubscriberData data, CATManipulator * iPointed,  CATManipulator * iPluged);
   virtual CATIMouseEditor::InteractorPriority& GetPriority ();

   int Edit (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int ConvertDoubleClickToSimple (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int ActivateAndBeginManipulate (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int BeginManipulateViewpointEditor (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int MoveMoveoverOrPreactivatePointedManip (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int ManipulatePlugedManip (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int HandOverPlugedManip (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int EndPreactivateOnLeave (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int ManipulateViewpointEditor (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int EndPlugedActionPreactivateNewManip (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int EndViewpointEditorActionPreactivateNewManip (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int MoveWithWheel (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int ManipulateWithWheel (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int ManipulateViewpointEditorWithWheel (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int OpenContextualMenu (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);

protected :

   

//------------------------------------------------------------------------------
private :
  CATIMouseEditor::InteractorPriority prio;
  
};
#endif
