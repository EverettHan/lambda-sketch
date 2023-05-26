#ifndef CATKeyboardDevice_H
#define CATKeyboardDevice_H
//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	Logical device converting keyboard actions in KeyboardEvent 
//		for Manipulators and ViewpointEditors
//------------------------------------------------------------------------------
// Usage :	Create the keyboard where the basic events are detected and 
//		add it in the Viewer's device list  
//------------------------------------------------------------------------------
// Heritage :	CATKeyboardDevice
//		  CATDevice
//		    CATCallbackManager (SYSTEM framework)
//------------------------------------------------------------------------------
#include "CATDevice.h"

#include "CATKeyboardEvent.h"
#include "CATVisFoundation.h"
#include "CATKeybdEventType.h" 

class CATVizViewer;
class CATViewerEvent;
class CATKeyboardEditorManager;
class CATKeybdEvent;

class ExportedByCATVisFoundation CATKeyboardDevice : public CATDevice
{
  CATDeclareClass;

  public:
  ///////

  CATKeyboardDevice( CATVizViewer *, CATViewerEvent * );
  virtual ~CATKeyboardDevice ();
 
  virtual int InterpretDeviceEvent( CATNotification *event, 
                                    CATSubscriberData data);
  CATDefineCBEvent (GENERAL_MODIFIERS_MODIFIED)
  virtual CATCallbackManager *GetCallbackManager();
  int GetKeyStatus ( CATKeyCode iKey);
  int NbOfPressedKeys ();

  virtual int InternalKeyboardCB( CATCallbackEvent, void *,
                                    CATNotification *n, CATSubscriberData, CATCallback);

  void GetNameFromCATKeyCode ( CATKeyCode iKey, CATUnicodeString& Name );

  CATUINT32 GetVkeyFromCATKeyCode(CATKeyCode iKey);
  CATUINT32 GetkeyFromCATKeyCode ( CATKeyCode iKey);
	int GetKeyCodeFromVKcode(int iVkCode); // translation needed for ODTs that are registered with VKcode

    int AddKeyboardDeviceEditor (CATBaseUnknown * iEditor);
    int RemoveKeyboardDeviceEditor (CATBaseUnknown * iEditor);

    void BroadcastModifiers ();
    void MouseReceiveKeyEvent ();
    void ViepointEditorManipulate ();
    CATBoolean IsInternalModifier (CATKeyCode i_Code);

    // retore state catviewer
    CATKeybdEvent *GenerateMissingKeybdEventFromKeyboardEvent (CATNotification *i_event);
    CATBoolean IsModifierUptodate (int imodifier,  int itype);
    CATBoolean IsAModifier (int imodifier);
    CATBoolean IsACATKeyCodeModifier (int imodifier);
  private :
    CATCallbackManager *_CallbackManager;

 
    CATKeyboardEditorManager * _DeviceEditor;
 

private :
  void UpdateGeneralModifiersOnDevices (CATCallbackEvent, void *, CATNotification *Event, CATSubscriberData, CATCallback);
  void UpdateKeyboardEventWithKey (CATKeybdEvent* i_pKeybdEvent);

  CATKeyCode GetCATKeyCodeFromKeyboardEvent (int icode);
 // CATModifier GetCATModifierFromVKey (int ikey);
  CATModifier GetCATModifierFromCATKeyCode(CATKeyCode ikey);
 
};

#endif
