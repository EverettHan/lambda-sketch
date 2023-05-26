#ifndef CATTouchMagnifierEditor_H
#define CATTouchMagnifierEditor_H
//
// CATIA Version 6 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	Basic class of DeviceEditor. 
//------------------------------------------------------------------------------
// 
//
//------------------------------------------------------------------------------
// Class :	CATTouchMagnifierEditor
//		  
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
//#include "CATCommand.h"
//#include "CATCallbackManager.h"
#include "CATTouchDeviceEditor.h"
#include "CATITouchEditor.h"
#include "VisMultitouchEvent.h"
#include "VisTouchDevice.h"

class VisTouchGesture;
class VisTouchGestureChooser;


/** @nodoc 
*  WARNING : this class is defined in Visualization framework */


class CATVizViewer;
class CATDevice;
class VisMultitouchEvent;
class VisTouch_Action;



class ExportedByCATVisFoundation CATTouchMagnifierEditor : public CATTouchDeviceEditor
{
   
   /**@nodoc */
   CATDeclareClass;

//------------------------------------------------------------------------------
public :

   /**@nodoc */
   /** Create a device editor that will modify the viewpoint.
   *  To be activated, the DeviceEditor has to be declared to the viewer
   *  with CATViewer::SetTouchDeviceEditor( iDeviceEditor)
   *  Create this CATTouchMagnifierEditor by using factory static method CreateCATTouchMagnifierEditor.
   */
  // Standard constructor
  // --------------------
 
 // static CATTouchMagnifierEditor* CreateCATTouchMagnifierEditor(CATVizViewer *iViewer);

  CATTouchMagnifierEditor( CATDevice *iDevice, CATVizViewer *iVizViewer);

   /** Destruction of the viewpoint editor.
   *  before the destruction, the viewpoint editor has to be detached
   * form the viewer by CATViewer::SetViewpointEditor( NULL)
   */
   ~CATTouchMagnifierEditor();
//------------------------------------------------------------------------------
   
   virtual CATTouchDeviceAction GetActionForInteraction (CATNotification *ievent, CATSubscriberData data, CATManipulator * iPointed,  CATManipulator * iPluged);
   virtual CATITouchEditor::InteractorPriority& GetPriority ();
   virtual CATBoolean IsNeeded(int iGeneralModifiers);
 
  // VisTouchGestureChooser * GetTouchGestureChooser () const;
  
  // const VisTouchGesture* ChooseAppropriateGesture (VisTouchGestureChooser *iChooser, VisMultitouchEvent *ievent, CATManipulator * iPointed,  CATManipulator * iPluged);

protected :

   

//------------------------------------------------------------------------------
private :
  /* CATVizViewer *_VizViewer;
  CATDevice *_Device;
  CATITouchEditor::InteractorPriority prio;

  VisTouchDevice::VisTouch_Action _previousAction;
  VisMultitouchEvent _previousMultitouchEvent;

  VisTouchDevice::VisTouch_Action _currentAction;
  const VisTouchGesture *_currentGesture;

  const VisTouchGesture* ChooseAppropriateGesture (VisTouchGestureChooser *iTList, VisMultitouchEvent  *ievent, CATManipulator * iPointed,  CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);
  */
  // int PerformAction (CATNotification *ipTouchEvent, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
  // int PerformNULLAction(CATNotification *ipTouchEvent, CATSubscriberData data, CATManipulator * iPointed, CATManipulator * iPluged);
   int ProcessDownMagnifier(CATNotification *ipTouchEvent, CATSubscriberData data, CATManipulator * iPointed, CATManipulator * iPluged);
   int ProcessDownHoldMagnifierInActivation(CATNotification *ipTouchEvent, CATSubscriberData data, CATManipulator * iPointed, CATManipulator * iPluged);
   int ProcessDownHoldMagnifier(CATNotification *ipTouchEvent, CATSubscriberData data, CATManipulator * iPointed, CATManipulator * iPluged);
   int ProcessMoveMagnifier(CATNotification *ipTouchEvent, CATSubscriberData data, CATManipulator * iPointed, CATManipulator * iPluged);
   int ProcessMoveMagnifierInNavigation(CATNotification *ipTouchEvent, CATSubscriberData data, CATManipulator * iPointed, CATManipulator * iPluged);
   int ProcessMoveMagnifierInManipulation(CATNotification *ipTouchEvent, CATSubscriberData data, CATManipulator * iPointed, CATManipulator * iPluged);
   int ProcessUpMagnifier(CATNotification *ipTouchEvent, CATSubscriberData data, CATManipulator * iPointed, CATManipulator * iPluged);
   int ProcessUpMagnifierInManipulation(CATNotification *ipTouchEvent, CATSubscriberData data, CATManipulator * iPointed, CATManipulator * iPluged);
   int ProcessHideMagnifier(CATNotification *ipTouchEvent, CATSubscriberData data, CATManipulator * iPointed, CATManipulator * iPluged);
   
};
#endif
