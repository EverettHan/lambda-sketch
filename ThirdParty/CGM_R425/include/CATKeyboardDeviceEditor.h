#ifndef CATKeyboardDeviceEditor_H
#define CATKeyboardDeviceEditor_H
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
// Class :	CATKeyboardDeviceEditor
//		  CATCommand
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
//#include "CATCommand.h"
//#include "CATCallbackManager.h"
//#include "CATDeviceEditor.h"
#include "CATExtIKeyboardEditor.h"


class CATVizViewer;
class CATDevice;
class CATKeybdEvent;


/** @nodoc */
// typedef void (CATBaseUnknown::*CATMouseAction)( CATMouseEvent &MouseEvent);
/** @nodoc */
//typedef void (CATBaseUnknown::*CATKeyboardMethod)( CATKeyboardEvent &KeyboardEvent);

/**Basic class of Viewpoint manipulation of a viewer.
*/

class ExportedByCATVisFoundation CATKeyboardDeviceEditor : public CATExtIKeyboardEditor
{
   
   /**@nodoc */
   CATDeclareClass;

//------------------------------------------------------------------------------
public :

   /**@nodoc */
   /** Create a device editor that will modify the viewpoint.
   *  To be activated, the DeviceEditor has to be declared to the viewer
   *  with CATViewer::SetMouseDeviceEditor( iDeviceEditor)
   *  Create this CATKeyboardDeviceEditor by using factory static method CreateCATKeyboardDeviceEditor.
   */
  // Standard constructor
  // --------------------
 
  static CATKeyboardDeviceEditor* CreateCATKeyboardDeviceEditor(CATVizViewer *iViewer);

  CATKeyboardDeviceEditor( CATDevice *iDevice, CATVizViewer *iVizViewer);

   /** Destruction of the viewpoint editor.
   *  before the destruction, the viewpoint editor has to be detached
   * form the viewer by CATViewer::SetViewpointEditor( NULL)
   */
   ~CATKeyboardDeviceEditor();
//------------------------------------------------------------------------------
   
   virtual CATKeyboardAction GetActionForInteraction (CATKeyboardInteraction_Id ident, CATKeybdEvent *ievent, CATSubscriberData data, CATManipulator * iPointed,  CATManipulator * iPluged);
   virtual CATIKeyboardEditor::InteractorPriority& GetPriority ();
   virtual CATBoolean IsNeeded ();

   int PressedKeyAction (CATKeybdEvent *KeyboardEvent, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int BroadcastModifiersAction (CATKeybdEvent *KeyboardEvent, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int BroadcastControlKeyAction (CATKeybdEvent *KeyboardEvent, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
private :
   int MouseReceiveKeyEvent ();
   //int MouseReceiveKeyEvent (CATKeybdEvent *KeyboardEvent, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int ViepointEditorManipulate ();
   //int ViepointEditorManipulate (CATKeybdEvent *KeyboardEvent, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   //int PointedManipulate (CATKeybdEvent *KeyboardEvent, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int PointedManipulate (CATManipulator * iPointed);


private :
  CATVizViewer *_VizViewer;
  CATDevice *_Device;
  CATIKeyboardEditor::InteractorPriority prio;
  
  
};
#endif
