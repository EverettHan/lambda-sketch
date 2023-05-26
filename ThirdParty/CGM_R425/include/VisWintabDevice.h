#ifndef VisWintabDevice_H
#define VisWintabDevice_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
//  Inheritance : VisWintabDevice
//					      CATDevice
//					         CATCallbackManager
//------------------------------------------------------------------------------
// Abstract : 	Logical Wintab device notifying manipulator of Wintab events 
//		         or notifying viewpoint manipulation.
//------------------------------------------------------------------------------
// Role :     Receive the Wintab event and interpret it as manipultion or as navigation.
//            For manipulation interpretation the manipulator are notified of their manipulation from Wintab event.
//            For navigation interpretation the viewpoint editor is notified of its manipulation.
//------------------------------------------------------------------------------
//  Main Methods :
//
//	  interpret the event of Wintab
//		  InterpretDeviceEvent
//------------------------------------------------------------------------------


#include "CATVisFoundation.h"
#include "CATDevice.h"
#include "CATCommand.h"
#include "CATPickPath.h"
#include "CATPickPathList.h"
#include "VisWintabDeviceEvent.h"
#include "CATMouseDevice.h"

class CATViewerEvent;
class CATKeyboardEvent;
class CATKeyboardDevice;
class CATManipulator;
class CAT3DViewpointEditor;
class VisWintabEvent;
class CATWintabEditorManager;

class ExportedByCATVisFoundation VisWintabDevice : public CATDevice
{
   CATDeclareClass;

public:

   // constructor / destructor
   VisWintabDevice(CATVizViewer *, CATViewerEvent *, CATDeviceEvent*, CATKeyboardDevice *);
   virtual ~VisWintabDevice();

   // explore what is found
   // application can have a look on the SG under the tablet pen when it receives the event
   virtual void InitPickPathList();
   virtual int MoveToNextPickPath();

   // modify _PickPathUnder and _PickPathList by doing a pick
   void DoPick();

   // interpret a contextual menu display
   void InterpretContextEvent(CATCommand *, CATNotification *, CATCommandClientData, int CtxShown);

   // interpret a Wintab event
   virtual int InterpretDeviceEvent(CATNotification *event, CATSubscriberData data);

   // editors managment 
   int AddDeviceEditor (CATBaseUnknown * iEditor);
   int RemoveDeviceEditor (CATBaseUnknown * iEditor);

private:

   // default constructor
   VisWintabDevice ();

   // copy constructor
   VisWintabDevice (const VisWintabDevice &);

   // assignment operator
   VisWintabDevice & operator  = (const VisWintabDevice &);

private :

   // modify the pointed manipulator and the event when tablet pen position is modified
   void ElectionManipulator(const CATMathPoint2Df& iPoint, int iMode=0);

   void ChoosePointedManip();

 
   int  IsValidMotionEvent (int& ifirstMove, VisWintabEvent &Motion);
   int IsValidPressEvent (VisWintabEvent &Press);


//private:
public :

   // callback method when the GeneralModifiers change
   void GeneralModifiersModifiedCB(CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);
     // send events to manipulator for action
   void PreActivation();
   void ActivationAndBeginManipulation();
   void Move();
   void Manipulation();
   void EndManipulation();
   void Edition();
private:

   // callback connected to the keyboard device
   CATCallback _GeneralModifiersCB;

   // all pathes selected by the device before election
   CATPickPathList _PickPathList;	

   // pick path of the selection/manipulated manipulator
   CATPickPath _PickPath;	

   // pick path under tablet pen
   CATPickPath _PickPathUnder;

   // curent wintab event
   VisWintabDeviceEvent& _CurrentWintabEvent;

   // internal state
   int _isOnMainViewpoint3D;
   int _isOnRep;

   MouseDeviceState  _state;

  //   device editor manager
   CATWintabEditorManager *_DeviceManager;
};

#endif
