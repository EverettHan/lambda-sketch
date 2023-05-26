#ifndef CATDeviceEditor_H
#define CATDeviceEditor_H
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
// Class :	CATDeviceEditor
//		  CATCommand
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATBaseUnknown.h"
//#include "CATCommand.h"
#include "CATCallbackManager.h"
#include "CATExtIMouseEditor.h"
//#include "CATManipulator.h"




class CATDevice;
class CATManipulator;
class CATVizViewer;
class CATNotification;


/** @nodoc 
*  WARNING : this class is defined in Visualization framework */


/** @nodoc */
//typedef int (CATBaseUnknown::*CATDeviceAction)(CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
/** @nodoc */
// typedef void (CATBaseUnknown::*CATMouseAction)( CATMouseEvent &MouseEvent);
/** @nodoc */
//typedef void (CATBaseUnknown::*CATKeyboardMethod)( CATKeyboardEvent &KeyboardEvent);

/**Basic class of Viewpoint manipulation of a viewer.
*/
class ExportedByCATVisFoundation CATDeviceEditor : public CATExtIMouseEditor
{
   
   /**@nodoc */
   CATDeclareClass;

//------------------------------------------------------------------------------
public :

   /** @nodoc */
  // CATDeclareCBEvent (VIEWPOINTEDITOR_DESTROYED); //Event sent when the viewpoint editor is destroyed.

   /** Create a device editor that will modify the viewpoint.
   *  To be activated, the DeviceEditor has to be declared to the viewer
   *  with CATViewer::SetDeviceEditor( iDeviceEditor)
   *  @param iName name for record
   *  @param iDevice The device manipulated.
   */
   CATDeviceEditor( CATDevice *iDevice, CATVizViewer *iVizViewer);

   /** Destruction of the viewpoint editor.
   *  before the destruction, the viewpoint editor has to be detached
   * form the viewer by CATViewer::SetViewpointEditor( NULL)
   */
   ~CATDeviceEditor();

   /*
   * GetKeyState returns status for a ikey : Ikey is a CATkeycode 
   * return value is 1 when key is pressed and 0 if it is released.
   * return value is -1 when ikey is not found
   */
   int GetKeyState (int iKey);
//------------------------------------------------------------------------------
protected :

   /**
   * Initialize to null all the _StartAction methods pointers.
   * This initialization is needed before defining the dialog.
   */
  
   CATVizViewer *_VizViewer;
   CATDevice *_Device;
   //------------------------------------------------------------------------------
   
   //------------------------------------------------------------------------------

//------------------------------------------------------------------------------
private :
  
  

};
#endif
