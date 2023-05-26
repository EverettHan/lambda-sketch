#ifndef CATViewpointEditor_H
#define CATViewpointEditor_H
//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	Basic class of Viewpoint manipulation of a viewer. 
//------------------------------------------------------------------------------
// Usage :	Derive from this class to give a specific behaviour of your
//		manipulation in the xxxManipulate methods 
//
//		This class manage the sensitivity of movement and the dialog
//		with the mouse and mouse modifiers, keyboard modifiers
//
//------------------------------------------------------------------------------
// Class :	CATViewpointEditor
//		  CATCommand
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATCommand.h"
#include "CATCallbackManager.h"
#include "CATMouseEvent.h"
#include "CATKeyboardEvent.h"
#include "CATMathPoint2Df.h"
#include "CATVizCursor.h"

class CATNotification;
class CATViewpoint;
class CATVizViewer;
class CATViewer;
class CATMsgCatalog;

/** @nodoc 
*  WARNING : this class is defined in Visualization framework */
class CATViewer;

/** @nodoc*/
enum CATBasic3DViewpointEditorStatus
{
   VPEditorStop, 
   VPEditorWaitReleaseOrDrag2,
   VPEditorDrag2,
   VPEditorDrag1, 
   VPEditorWaitClic1OrDrag1, 
   VPEditorWaitControlReleaseOrDrag2,
   VPEditorControlDrag2,
   VPEditorControlDrag1,
   VPEditorShiftDrag2,
   VPEditorAltDrag2,
   VPEditorWheel
};

#define BasicActionNumber 23
/** @nodoc */
enum CATBasic3DMethods 
{
   Overall,

   Click2, 
   DoubleClick2,
   ControlClick2,

   Click2And1, 
   Drag2And1,
   ControlDrag2And1,

   //Drag with/without modifier
   Drag1,
   ControlDrag1,
   AltDrag1,
   ShiftDrag1,
   SpaceDrag1,

   Drag2,
   ControlDrag2,
   AltDrag2,
   ShiftDrag2,
   SpaceDrag2,

   Drag3,
   ControlDrag3,
   AltDrag3,
   ShiftDrag3,
   SpaceDrag3,

   WheelMove
};

/** @nodoc */
enum CATBasicAction
{
   CENTER      = 1,
   STEP_BACK   = 2,
   ZOOM_AREA   = 3,
   TRANSLATE   = 4,
   ZOOM        = 5,
   GO_BACKWARD = 6,
   GO_FORWARD  = 7,
   ROTATE      = 8,
   LOOK_AT     = 9,
   TURN_HEAD   = 10,
   WALK        = 11,
   FLY         = 12,
   SEEK        = 13,
   ROLL        = 14,
   DRAG        = 100,
   RELEASE     = 200,
   PRESS       = 300,
   CLICK       = 400,
   RELEASE_LEFT = 500,
   SELECT      = 600,
   REFRAME     = 700
  
};

#ifndef _CATTransformationsEventsLocks
#define CATTransformationsEventsLocks
typedef int CATTransformationEventLock;
#define TRANSEVTLOCK_ALLUNLOCKED            (0x0)
#define TRANSEVTLOCK_ZOOMS_LOCKED           (0x1)
#define TRANSEVTLOCK_ZOOMS_UNLOCKED         (0x2)
#define TRANSEVTLOCK_ROTATIONS_LOCKED       (0x4)
#define TRANSEVTLOCK_ROTATIONS_UNLOCKED     (0x8)
#define TRANSEVTLOCK_TRANSLATIONS_LOCKED    (0x10)
#define TRANSEVTLOCK_TRANSLATIONS_UNLOCKED  (0x20)
#define TRANSEVTLOCK_CENTERS_LOCKED         (0x40)
#define TRANSEVTLOCK_CENTERS_UNLOCKED       (0x80)
#define TRANSEVTLOCK_TOUCH_ZOOMS_LOCKED           (0x100)
#define TRANSEVTLOCK_TOUCH_ZOOMS_UNLOCKED         (0x200)
#define TRANSEVTLOCK_TOUCH_ROTATIONS_LOCKED       (0x400)
#define TRANSEVTLOCK_TOUCH_ROTATIONS_UNLOCKED     (0x800)
#define TRANSEVTLOCK_TOUCH_TRANSLATIONS_LOCKED    (0x1000)
#define TRANSEVTLOCK_TOUCH_TRANSLATIONS_UNLOCKED  (0x2000)
#define TRANSEVTLOCK_TOUCH_REFRAME_LOCKED    (0x4000)
#define TRANSEVTLOCK_TOUCH_REFRAME_UNLOCKED  (0x8000)
#endif

/** @nodoc */
typedef void (CATBaseUnknown::*CATMouseMethod)( CATMouseEvent &MouseEvent);
/** @nodoc */
typedef void (CATBaseUnknown::*CATKeyboardMethod)( CATKeyboardEvent &KeyboardEvent);

/**Basic class of Viewpoint manipulation of a viewer.
*/
class ExportedByCATVisFoundation CATViewpointEditor : public CATCommand
{
   friend class CATVizViewer;

   /**@nodoc */
   CATDeclareClass;

//------------------------------------------------------------------------------
public :

   /** @nodoc */
   CATDeclareCBEvent (VIEWPOINTEDITOR_DESTROYED); //Event sent when the viewpoint editor is destroyed.

   /** Create a viewpoint editor that will modify the viewpoint.
   *  To be activated, the viewpointEditor has to be declared to the viewer
   *  with CATViewer::SetViewpointEditor( iViewpointEditor)
   *  @param iName name for record
   *  @param iViewpoint The viewpoint manipulated.
   */
   CATViewpointEditor( const CATString &iName, CATViewpoint *Viewpoint = NULL);

   /** Destruction of the viewpoint editor.
   *  before the destruction, the viewpoint editor has to be detached
   * form the viewer by CATViewer::SetViewpointEditor( NULL)
   */
   ~CATViewpointEditor();

   /** 
   * Activate the Viewpoint editor. This method is called by the viewers only.
   * The activation is called when the Viewpoint editor is attached to the viewer.
   * see CATViewer::SetViewpointEditor
   */
   virtual void Activate( CATNotification *event);
   /** 
   * Begin the manipulation of  the Viewpoint editor. This method is called by the viewers only
   */
   virtual void BeginManipulate( CATNotification *event);
   /** 
   * Manipulate the Viewpoint editor. This method is called by the viewers only
   */
   virtual void Manipulate( CATNotification *event);
   /** 
   * Ends the manipulation of the Viewpoint editor. This method is called by the viewers only
   */
   virtual void EndManipulate( CATNotification *event);
   /** 
   * Unactivate the Viewpoint editor. This method is called by the viewers only. 
   * The activation ends when the Viewpoint editor is detattached from the viewer.
   */
   virtual void EndActivate( CATNotification *event);

   /**
   * Method to handle all keyboard events related to viewpoint location modification.
   */
   virtual void HandleKeyboardEvent(const CATNotification* ipEvent, CATVizViewer* ipViewer);

   /**
   * Method to manage the lock/unlock of specific viewpoint transformations.
   */
   void SetTransformationsEventsLocks(CATTransformationEventLock iLock);

   /**
   * Method to retrieve the lock/unlock state of specific viewpoint transformations.
   */
   CATTransformationEventLock GetTransformationsEventsLocks();
   
   /**
   * Query to know if the action for mouse wheel was set.
   */
   CATBoolean WheelActionPending();

   /** 
   * 
   */
   virtual bool IsEditGestureUsed();

   virtual void SpaceButtonAction(CATString headerId);

//------------------------------------------------------------------------------
protected :

   /** nodoc */
   void SetViewer(CATViewer*);
   /** nodoc */
   inline void SetVizViewer(CATVizViewer* v) {_pVizViewer=v;};

   // Standard values of for manipulation
   static float _TurnAngle;		// Turn with keys;

   //  Dialog mechanism
   int _LastGeneralModifier, _LastMouseModifiers;

   CATViewpoint *_Viewpoint;
   CATVizViewer *_pVizViewer;

   // Attention !!! SVQ 06/02/02 : _Viewer est utilisé dans des classes derivees (CATGlider3DViewpointEditor dans CATIAApplicationFrame)

   CATViewer *_Viewer;

   //  Dialog state machine
   CATBasicAction _ActionName[BasicActionNumber];
   CATVizCursor::CATVizStyle _Cursor[BasicActionNumber];
   CATMouseMethod _StartAction[BasicActionNumber];
   CATMouseMethod _DriveAction[BasicActionNumber];
   CATKeyboardMethod _KeyAction[BasicActionNumber];
   CATMouseMethod _StopAction[BasicActionNumber];
   int            _ActionLocked[BasicActionNumber];

   CATMouseEvent _LastMouseEvent;
   CATBasic3DViewpointEditorStatus _EditorStatus;

   /**
   * Display the message in the Viewer's SetStatusBarTemporaryText. 
   * Usually, text writen is the different possiblility of dialog with mouse button press
   * repease and mouse drag.
   */
   virtual void SetMessage (const int Msg1 = 0, const int Msg2 = 0, const int Msg3 = 0, const int Msg4 = 0);
   virtual void SetMessage (const float speed);
   virtual void SetLockMessage (const CATBasic3DMethods act);
   bool _NeedWarningWhenLocked;

   /**
   * Set the cursor in the Viewer. 
   */
   virtual CATVizCursor::CATVizStyle SetCursor( const CATVizCursor::CATVizStyle iCursor);

   /**
   * Initialize to null all the _StartAction methods pointers.
   * This initialization is needed before defining the dialog.
   */
   virtual void InitActionPointers();

   void Start( CATMouseEvent &MouseEvent);
   void Stop( CATMouseEvent &MouseEvent);
   CATMathPoint2Df _FirstMousePoint;
   CATMathPoint2Df _LastMousePoint;

   //------------------------------------------------------------------------------
   int _CurrentAction;
   int _NActions;
   //------------------------------------------------------------------------------

   // Keyboard transformations
   CATTransformationEventLock _TransformationsEventsLocks;

   void InitActionLock();

   CATVizCursor::CATVizStyle _PreviousCursor;

//------------------------------------------------------------------------------
private :

   CATMouseEvent _InitialPress;	//  for ClicOrDrag
   CATMsgCatalog *_resourceCatalog;
};
#endif
