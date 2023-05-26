#ifndef CATTouchDeviceEditor_H
#define CATTouchDeviceEditor_H
//
// CATIA Version 6 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	Basic class of DeviceEditor. 
//------------------------------------------------------------------------------
// 
//
//------------------------------------------------------------------------------
// Class :	CATTouchDeviceEditor
//		  
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
//#include "CATCommand.h"
//#include "CATCallbackManager.h"
#include "CATExtITouchEditor.h"
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
//++vxg - 22:09:26 - To access protected actions to perform.
class CATTouchDeviceEditorA2X;
//--vxg - 22:09:26



class ExportedByCATVisFoundation CATTouchDeviceEditor : public CATExtITouchEditor
{
   
   /**@nodoc */
   CATDeclareClass;

//++vxg - 22:09:26 - To access protected actions to perform.
   friend class CATTouchDeviceEditorA2X;
//--vxg - 22:09:26

//------------------------------------------------------------------------------
public :

   /**@nodoc */
   /** Create a device editor that will modify the viewpoint.
   *  To be activated, the DeviceEditor has to be declared to the viewer
   *  with CATViewer::SetTouchDeviceEditor( iDeviceEditor)
   *  Create this CATTouchDeviceEditor by using factory static method CreateCATTouchDeviceEditor.
   */
  // Standard constructor
  // --------------------
 
 // static CATTouchDeviceEditor* CreateCATTouchDeviceEditor(CATVizViewer *iViewer);

  CATTouchDeviceEditor( CATDevice *iDevice, CATVizViewer *iVizViewer);

   /** Destruction of the viewpoint editor.
   *  before the destruction, the viewpoint editor has to be detached
   * form the viewer by CATViewer::SetViewpointEditor( NULL)
   */
   ~CATTouchDeviceEditor();
//------------------------------------------------------------------------------
   
   virtual CATTouchDeviceAction GetActionForInteraction (CATNotification *ievent, CATSubscriberData data, CATManipulator * iPointed,  CATManipulator * iPluged);
   virtual CATITouchEditor::InteractorPriority& GetPriority ();
 
 
   VisTouchGestureChooser * GetTouchGestureChooser () const;
  
   const VisTouchGesture* ChooseAppropriateGesture (VisTouchGestureChooser *iChooser, VisMultitouchEvent *ievent, CATManipulator * iPointed,  CATManipulator * iPluged);

protected :

   

//------------------------------------------------------------------------------

   CATVizViewer *_VizViewer;
  CATDevice *_Device;
  CATITouchEditor::InteractorPriority prio;

  //VisTouchDevice::VisTouch_Action _previousAction;
  //VisMultitouchEvent _previousMultitouchEvent;

  VisTouchDevice::VisTouch_Action _currentAction;
  const VisTouchGesture *_currentGesture;

  const VisTouchGesture* ChooseAppropriateGesture(VisTouchGestureChooser *iTList, VisMultitouchEvent  *ievent, CATManipulator * iPointed, CATManipulator * iPluged, VisTouchDevice::VisTouch_Action & currentAction);

protected:
  
  
   int PerformAction (CATNotification *ipTouchEvent, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int PerformNULLAction(CATNotification *ipTouchEvent, CATSubscriberData data, CATManipulator * iPointed, CATManipulator * iPluged);
};
#endif
