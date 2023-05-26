#ifndef CATMouseDevice_H
#define CATMouseDevice_H
//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	Logical device transforming basic events into Viewer and
//		pmanipulator's calls.	
//------------------------------------------------------------------------------
// Usage :	Create the device where you receave the event and add it to
//		the viewer
//------------------------------------------------------------------------------
// Class :	CATMouseDevice
//		  CATDevice
//		    CATObject
//------------------------------------------------------------------------------
#include "CATDevice.h"
#include "CATCommand.h"
#include "CATPickPath.h"
#include "CATPickPathList.h"
#include "CATVisFoundation.h"
class CATMouseEvent;
class CATManipulator;
class CATKeyboardEvent;
class CATKeyboardDevice;
class CATPathElement;
class CATSupport;
class CATMotionEvent;
class CATPressEvent;
class CATMouseDeviceEditor;
class CATMouseEditorManager;
class CAT2DViewpoint;
typedef unsigned int CATModifier;

enum MouseDeviceState { ViewpointManipulate, ManipulatorDrag, ManipulatorMove };

#ifdef _WINDOWS_SOURCE
#else
#ifndef _POINTL_DEFINED
#define _POINTL_DEFINED
/**
 * @nodoc 
 */
typedef struct _POINTL
{
        LONG x;
        LONG y;
}POINTL;
#endif
#endif

class ExportedByCATVisFoundation CATMouseDevice : public CATDevice
{
  CATDeclareClass;

  friend class CATDrillSelector;
  friend class VisTouchDevice;
  friend class VisWintabDevice;

//------------------------------------------------------------------------------
  public:

    CATMouseDevice( CATVizViewer *, CATViewerEvent *, CATKeyboardDevice *Keyboard);	 
    virtual ~CATMouseDevice();

    //  to explore what is found
    //  ------------------------
    virtual void InitPickPathList();
    virtual int MoveToNextPickPath();

    //  event
    //  ----- 
    void SetCurrentEventMousePoint(float x, float y);
    void SetBusy(int iBusy);
    void SetPressedButton(int i_pressedButon);
    int GetPressedButton()const;

    CATMouseEvent& GetCurrentMouseEvent(){return CurrentMouseEvent;};

    void DragAndDropInformation(CATCommand *, CATNotification *, 
                                CATCommandClientData);
    void InterpretContextEvent(CATCommand *, CATNotification *, 
                               CATCommandClientData, int CtxShown);
    void RescueManipulators();
    CATBoolean IsInRescueManipulatorMode();
    void SetRescueManipulatorMode(int i);
    void SetIgnoreBusyMode();
    void UnsetIgnoreBusyMode();

    virtual int InterpretDeviceEvent( CATNotification *event, 
                                      CATSubscriberData data);
    void ReceiveKeyEvent ( CATKeyboardEvent & key );

    MouseDeviceState GetState( void);
    void SetState (MouseDeviceState  i_state);
    CATManipulator* GetDraggedOverManipulator();
    void SetDraggedOverManipulator( CATManipulator *Manip);

    CATManipulator * FindDraggedOverAgent(CATNotification *source, int mode = 0);

    //  picking
    //  -------
    void DoPick(int mode = 0);

    int StickToNextObject();

    void ElectionManipulator();  // new ElectionManipulator

    void ElectionManipulatorWithoutDoPick(); // old ElectionManipulator

    void ElectionManipulator(CATPickPathList* pickpathlist);
    void ElectionManipulatorWithoutDoPick(CATPickPathList* pickpathlist);

    static int _sModifier;

    // <FBJ dev='drillselection'>
    // drill selection
    //------------------
    void StartDrill();
    // </FBJ>

    // drill selection editor
    //  <JMA dev='drillselection'> : SetIsIdle à TRUE force le device a ne pas effectuer les mises à jour de ses manipulators pointes 
    //      on laisse alors cette mise à jour aux editors 
    //------------------
    void SetIsIdle (CATBoolean iIdle);
    CATBoolean IsIdle ();
    //</JMA : drill editor>

    // query on modifiers and status symetric to update which is done in CATGraphicWindow
    CATUINT32 getGeneralModifiers ();
    int getButtonsStatus ();
    void SetEventPublisherSupport (CATSupport* iSupport);

    void FillDragNotification ( CATNotification *old_notif, CATNotification *new_notif,  CATMathPoint2Df i_posInViewer, void *iTargetDialog );
    void FillDragNotification ( CATNotification *old_notif, CATNotification *new_notif);
//------------------------------------------------------------------------------
    /* Callback when the GeneralModifiers changes */
     void GeneralModifiersModified(  CATCallbackEvent, void *, CATNotification *,
                                    CATSubscriberData, CATCallback);

     /**/
     void SetIsRunningForWintabDevice (CATBoolean ivalue);
  private:
    
    // Default Constructor
    CATMouseDevice ();
    // Copy Constructor
    CATMouseDevice (const CATMouseDevice &);
    // Assignment Operator
    CATMouseDevice & operator  = (const CATMouseDevice &);

    /* This callback is connected to the Keyboard device */
    CATCallback _GeneralModifiersCB;
    /* Callback when the GeneralModifiers changes */
   // void GeneralModifiersModified(  CATCallbackEvent, void *, CATNotification *,
   //                                 CATSubscriberData, CATCallback);

    // updates and queries for InterpretDeviceEvent
    int UpdateCurrentEventWithModifiers ();
    void UpdateCurrentMouseEventFlagsAndSupport (CATNotification *ievent);
    int IsValidMotionEvent (int& ifirstMove, CATMotionEvent &Motion);
    int IsValidPressEvent (CATPressEvent &Press);
    
    


    CATSupport* _pEventPublisherSupport;
    CATBoolean  _bManipSkippedOnDrag;


    CATBoolean IsOnDialogGP (int mode=0);
//------------------------------------------------------------------------------
  public :
    // Device Editor Managment
    //void SetDeviceEditor (CATMouseDeviceEditor *iEditor);
    //CATMouseDeviceEditor * GetDeviceEditor ();
    int AddMouseDeviceEditor (CATBaseUnknown * iEditor);
    //int AddMouseDeviceEditor (CATBaseUnknown * iEditor, const CATModifier & iModifier);
    //int RemoveMouseDeviceEditor (CATBaseUnknown * iEditor, const CATModifier & iModifier);
    int RemoveMouseDeviceEditor (CATBaseUnknown * iEditor);


    // ActionMethods 
    void ActivateAndBeginManipulate ();
    void ChangePreactivatedManipulator (CATManipulator  *iOldPointed);
    void ChangeUsedManipulator ();
    void EndManipulateAndPreactivate ();
    void EndManipulateAndMoveOver ();
    void ManipulationHandOver ();
    void EndPreactivateOnLeave ();
    void PreactivateNewManip ();
    void NewPickAndManipElection ();
    void InitCurrentEventMouseModifiers ();
    void EndViewpointEditorAction ();
    void EndPlugedAction ();
    void MoveMoveOverOrPreactivate ();
    void MoveWithWheel (int iwheel);
    void ManipulateWithWheel (int iwheel);
    void ManipulateViewpointEditorWithWheel (int iwheel);
    void OpenContextualMenu( POINTL& point);

    void SetStartDrill (int istart);
    CATBoolean IsDrillRequired ();
    void SetActivateRunning (int iRunning);

    //query for mouse device editor
    
    //CATManipulator  * GetManipToMove ();
    void SetManipToMove (CATManipulator  *iManip);
    //CATManipulator  * GetManipToMoveOver ();
    void SetManipToMoveOver (CATManipulator  *iManip);
    //CATBoolean GetManipToChangePreactivate (CATManipulator  *&oOldManip);
    
    // AllowRMBDown is set by default to true : every viewer should be allowed to treat RMB down interaction
    // however for the hidden viewer we set this AllowRMBDown to False
    // it is only wen a CATMouseInteraction_Press3 is done over hidden viewer "texture" that we set the Hidden viewer's Allow value to true, and immediatly
    // CID Viewer 's allow value turns to false : We give the priority to hidden viewer for CATMouseInteraction_Press3.
    // RMBDown is special because it is used for Contextual menu . 
    // If we do not block RMBDown on CID Viewer, it would always be used for the CID Viewer  contextual menu, even if the hidden viewer should have it.
    // This is beacause the Hidden viewer's events are always delt with after those of CID Viewer.
    // please cf l_CATVidCtlViewer 
    void AllowRMBDown (CATBoolean iRMBDownIsAllowed);
    CATBoolean IsRMBDownAllowed ();
    
    //IsDefaultRMBDownAction : we need to know if the Action for RMB down is from default editor or from an external editor.
    // if external user wills to override the RMBdown, then we allow it even if the AllowRMBDown blocks it.
    CATBoolean IsDefaultRMBDownAction ();
    void SetIsDefaultRMBDownAction (CATBoolean iDefaultRMBDownAction);
    CATBoolean GetIsRunningForWintabDevice ();
 
//------------------------------------------------------------------------------
  private :
    //CATMouseDeviceEditor * _DeviceEditor;
    CATMouseEditorManager * _DeviceEditor;

    CATManipulator  *_ManipToMove;
    CATManipulator  *_ManipToMoveOver;
    CATManipulator  *_LastManipInPreactivate;
    CATBoolean _shouldChangePreactivate;
   // CATManipulator  *_NewManipToPreactivate;
    void SetManipToChangePreactivate (CATManipulator  *iOldManip);
    void InitMoveOrPreactivateManipData ();
    
	CATBoolean Manipulate2DViewpointEditorWithWheel(int iwheel, CAT2DViewpoint* pvp, CATViewpointEditor* editor_pvp);
	CAT2DViewpoint* SearchGraphViewpoint();

  protected :
    
    //  drag and drop management
    //  ------------------------
    CATManipulator *_draggedOverManipulator;

    //  All path selected by the device before election
    //  -----------------------------------------------
    CATPickPathList _PickPathList;	

    // pick path of the selection/manipulated manipulator
    //  -----------------------------------------------
    CATPickPath _PickPath;	

    // pick path under mouse
    CATPickPath _PickPathUnder;
    CATNotification *_LastMotionEvent;	

    CATMouseEvent &CurrentMouseEvent;

    // is useful to implement double click.
    //int _manipDone;
    //int _Button4Mode;

    //  last mode stored 
    //  to stick to right solution during arrow manipulation
    //  ----------------------------------------------------
    //int _mode;
    int _under;

    unsigned long _lastPressTime;

    unsigned int _PressedButton:3;
    unsigned int _busy:1;
    
    MouseDeviceState _state:3;

    unsigned int _startDrill : 1;
    unsigned int _activateRunning : 1;
    unsigned int _pointedManipNotRefresh : 1;
//
    // special traitement pour drill editor
    CATBoolean _isIdle ;


    private :
    
    CATBoolean _isRMBDownAllowed;
    CATBoolean _isDefaultRMBDownAction;
    CATBoolean _rescueMode;
    CATBoolean _ignoreBusy;

    // for ODT only 
    CATBoolean _isAccuratePickOnDlgPossible;
    CATBoolean _isVptEditorTestPossible;

    CATBoolean _isRunningForWintabDevice;
};

#endif
