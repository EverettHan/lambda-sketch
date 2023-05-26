#ifndef CATWintabDeviceEditor_H
#define CATWintabDeviceEditor_H
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
//		with the Wintab and Wintab modifiers, keyboard modifiers
//
//------------------------------------------------------------------------------
// Class :	CATWintabDeviceEditor
//		  CATCommand
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
//#include "CATCommand.h"
//#include "CATCallbackManager.h"
#include "CATExtIWintabEditor.h"
#include "CATIWintabEditor.h"



/** @nodoc 
*  WARNING : this class is defined in Visualization framework */


class CATVizViewer;
class CATDevice;



class ExportedByCATVisFoundation CATWintabDeviceEditor : public CATExtIWintabEditor
{
   
   /**@nodoc */
   CATDeclareClass;

//------------------------------------------------------------------------------
public :

   /**@nodoc */
   /** Create a device editor that will modify the viewpoint.
   *  To be activated, the DeviceEditor has to be declared to the viewer
   *  with CATViewer::SetWintabDeviceEditor( iDeviceEditor)
   *  Create this CATWintabDeviceEditor by using factory static method CreateCATWintabDeviceEditor.
   */
  // Standard constructor
  // --------------------
 
  //static CATWintabDeviceEditor* CreateCATWintabDeviceEditor(CATVizViewer *iViewer);

  CATWintabDeviceEditor( CATDevice *iDevice, CATVizViewer *iVizViewer);

   /** Destruction of the viewpoint editor.
   *  before the destruction, the viewpoint editor has to be detached
   * form the viewer by CATViewer::SetViewpointEditor( NULL)
   */
   ~CATWintabDeviceEditor();
//------------------------------------------------------------------------------
   
   virtual CATDeviceAction GetActionForInteraction (CATWintabInteraction_Id ident, CATNotification *ievent, CATSubscriberData data, CATManipulator * iPointed,  CATManipulator * iPluged);
   virtual CATIWintabEditor::InteractorPriority& GetPriority ();
 
   int Move (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int ActivationAndBeginManipulation (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int Manipulation (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged);
   int EndManipulation (CATNotification *event, CATSubscriberData data,  CATManipulator * iPointed,  CATManipulator * iPluged); 
   
protected :

   

//------------------------------------------------------------------------------
private :
   CATVizViewer *_VizViewer;
  CATDevice *_Device;
  CATIWintabEditor::InteractorPriority prio;
  
};
#endif
