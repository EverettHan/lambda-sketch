#ifndef VisTouchDevice_H
#define VisTouchDevice_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
//  Inheritance : VisTouchDevice
//					        CATDevice
//					          CATCallbackManager
//------------------------------------------------------------------------------
// Abstract : 	Logical multi touch device notifying manipulator of touch events 
//		          or notifying viewpoint manipulation.
//------------------------------------------------------------------------------
// Role :     Receive the basic touch event and interpret it as manipultion or as navigation.
//            For manipulation interpretation the manipulator are notified of their manipulation from event touch.
//            For navigation interpretation the viewpoint editor is notified of its manipulation.
//------------------------------------------------------------------------------
//  Main Methods :
//
//	  interpret the event of touch
//		  InterpretDeviceEvent
//------------------------------------------------------------------------------


#include "CATVisFoundation.h"
#include "CATDeviceEx.h"
#include "CATCommand.h"
#include "CATPickPath.h"
#include "CATPickPathList.h"
#include "VisMonotouchDeviceEvent.h"
#include "VisMultitouchDeviceEvent.h"
#include "VisMultitouchEvent.h"
#include "list.h"
#include "CATListOfInt.h"
#include "VisActivationTimer.h"
#include "CATMagnifierEvent.h"
#include "CATListOfVisTouchGesture.h"

class CATViewerEvent;
class CATKeyboardDevice;
class CATManipulator;
class VisTouchGestureRecognizer;
class VisTouchListener;
class VisTouchInterpretor;
class VisTouchGesture;
class CATTouchEditorManager;
class VisTouchGestureChooser;
class CATTouchMagnifierEditor;


class ExportedByCATVisFoundation VisTouchDevice : public CATDevice
{
  CATDeclareClass;

  friend class VisTouchGestureChooser;
  friend class CATTouchDeviceEditor;
  friend class CATTouchDeviceEditorA2X;
  friend class CATTouchMagnifierEditor;

public:

  // constructor / destructor
  VisTouchDevice(CATVizViewer *, CATViewerEvent *, CATDeviceEvent*, CATDeviceEvent*, CATKeyboardDevice *);
  virtual ~VisTouchDevice();

  // explore what is found
  // application can have a look on the SG under the touch when it receives the event
  virtual void InitPickPathList();
  virtual int MoveToNextPickPath();

  // modify _PickPathUnder and _PickPathList by doing a pick
  void DoPick();

  // interpret a contextual menu display
  void InterpretContextEvent(CATCommand *, CATNotification *, CATCommandClientData, int CtxShown);

  // interpret a touch event
  virtual int InterpretDeviceEvent(CATNotification *event, CATSubscriberData data);

  void SetMultiSelect(bool flag);
  bool GetMultiSelect() const;
  void SetMagnifierOverviewMode(bool iOverviewMode);
  bool GetMagnifierOverviewMode() const;
  void SetMagnifierSpecificMode(bool iSpecificMode);
  bool GetMagnifierSpecificMode() const;

  // d6f: Sets small, normal or large activation timer on touch device
  void SetActivationTimer(VisActivationTimer activationTimer);

  // d6f: Gets current activation timer of touch device
  VisActivationTimer GetActivationTimer() const;

  CATBoolean IsFirstTouch(const VisMultitouchEvent* ipTouchEvent,CATManipulator*& opPointedManip);

   // editors managment 
   int AddDeviceEditor (CATBaseUnknown * iEditor);
   int RemoveDeviceEditor (CATBaseUnknown * iEditor);

   // methods for Editors
  // void PerformTouch (const VisMultitouchEvent* ipTouchEvent);
   VisTouchGestureChooser *GetTouchGestureChooser () const;
   
private:
    
  // default constructor
  VisTouchDevice ();
  
  // copy constructor
  VisTouchDevice (const VisTouchDevice &);
  
  // assignment operator
  VisTouchDevice & operator  = (const VisTouchDevice &);

private :
  
  // decorrelation eventuelle des evenements
  void GetSeparateTouchEvent(const VisMultitouchEvent* ipTouchEvent, VisMultitouchEvent**& opTouchEventTab, int& oTouchEventTabSize);
  int IsNewTouchEvent(const VisMultitouchEvent* ipTouchEvent, int& oIsNewSeparateTouchEvent, int& oSeparateTouchIndex, const VisTouchEvent*& opDownTouchEvent, CATManipulator*& opPointedManip) const;
  void InitCurrentTouchEvent(int iIndex, const VisMultitouchEvent* ipTouchEvent);
  int InterpretDeviceEvent(const VisMultitouchEvent* ipTouchEvent, CATSubscriberData iSubscriberData);
  void SaveCurrentTouchEvent(int iIndex);
  void ResetSeparateTouchEvent(const VisMultitouchEvent* ipTouchEvent, VisMultitouchEvent** ipTouchEventTab, int iTouchEventTabSize);


  // modify the pointed manipulator and the event when touch position is modified
  void ElectionManipulator(const CATMathPoint2Df& iPoint, int iMode);


  enum VisTouch_Action {VisTouchAction_PreActivation=0,
                        VisTouchAction_Move,
                        VisTouchAction_MoveWithGesture,
                        VisTouchAction_PreActivationAndActivation,
                        VisTouchAction_Activation,
                        VisTouchAction_Selection,
                        VisTouchAction_ClosedReactivation,
                        VisTouchAction_Reactivation,
                        VisTouchAction_Manipulation,
                        VisTouchAction_ManipulationWithGesture,
                        VisTouchAction_EndManipulation,
                        VisTouchAction_HandOverPluginOnDown,
                        VisTouchAction_HandOverPointedOnDown,
                        VisTouchAction_Edition,
                        VisTouchAction_EndEdition,
                        VisTouchAction_Navigation,
                        VisTouchAction_None};


  void PerformTouchAction (const VisMultitouchEvent* ipTouchEvent, VisTouch_Action &currentAction, const VisTouchGesture* pTouchGesture, VisTouch_Action &iPreviousAction, VisMultitouchEvent& iPreviousMultitouchEvent);
  // select the right gesture
  void ChooseAppropriateGesture(CATListPV& ipCurrentGestureList, VisTouchGestureRecognizer*& opCurrentGesture, VisTouch_Action& oCurrentAction);
  void GetGestureListFromRecognizerList (CATListPV& pCurrentGestureList, CATLISTP(VisTouchGesture)& myGestureList);
  /*

  // select the right gesture during a manipulation
  void ChooseAppropriateGestureDuringManipulation(CATListPV& ipCurrentGestureList, VisTouchGestureRecognizer*& opCurrentGesture, VisTouch_Action& oCurrentAction);
  void ChooseAppropriateDownTypeGestureDuringManipulation(CATListPV& ipCurrentGestureList, VisTouchGestureRecognizer*& opCurrentGesture, VisTouch_Action& oCurrentAction);
  void ChooseAppropriateMoveTypeGestureDuringManipulation(CATListPV& ipCurrentGestureList, VisTouchGestureRecognizer*& opCurrentGesture, VisTouch_Action& oCurrentAction);
  void ChooseAppropriateUpTypeGestureDuringManipulation(CATListPV& ipCurrentGestureList, VisTouchGestureRecognizer*& opCurrentGesture, VisTouch_Action& oCurrentAction);
  void ChooseAppropriateUninterpretedGestureDuringManipulation(CATListPV& ipCurrentGestureList, VisTouchGestureRecognizer*& opCurrentGesture, VisTouch_Action& oCurrentAction);
  // select the right gesture during no manipulation
  void ChooseAppropriateGestureDuringNoManipulation(CATListPV& ipCurrentGestureList, VisTouchGestureRecognizer*& opCurrentGesture, VisTouch_Action& oCurrentAction);
  void ChooseAppropriateDownTypeGestureDuringNoManipulation(CATListPV& ipCurrentGestureList, VisTouchGestureRecognizer*& opCurrentGesture, VisTouch_Action& oCurrentAction);
  void ChooseAppropriateMoveTypeGestureDuringNoManipulation(CATListPV& ipCurrentGestureList, VisTouchGestureRecognizer*& opCurrentGesture, VisTouch_Action& oCurrentAction);
  void ChooseAppropriateUpTypeGestureDuringNoManipulation(CATListPV& ipCurrentGestureList, VisTouchGestureRecognizer*& opCurrentGesture, VisTouch_Action& oCurrentAction);
  void ChooseAppropriateUninterpretedGestureDuringNoManipulation(CATListPV& ipCurrentGestureList, VisTouchGestureRecognizer*& opCurrentGesture, VisTouch_Action& oCurrentAction);
  // select the right navigation gesture
  void ChooseAppropriateFirstClassNavigationGesture(CATListPV& ipCurrentGestureList, VisTouchGestureRecognizer*& opCurrentGesture, VisTouch_Action& oCurrentAction);
  void ChooseAppropriateNavigationGesture(CATListPV& ipCurrentGestureList, VisTouchGestureRecognizer*& opCurrentGesture, VisTouch_Action& oCurrentAction);
  */
  // init before touch sequence
  void ChoosePointedManip(const VisTouchGestureRecognizer* ipCurrentGesture);
  void ChoosePointedManip(const VisTouchGesture* ipCurrentGesture);
  // compute manipulator under touch point
  CATManipulator* ComputePointedManipulator(CATListPV& ipCurrentGestureList, CATPickPathList& oPickPathList, CATPickPath& oPickPath) const;
  CATManipulator* ComputePointedManipulator(const CATMathPoint2Df& iPoint, CATPickPathList& oPickPathList, CATPickPath& oPickPath) const;

  // reset after touch sequence
  void UpdateTouchSequence();

  // end of the navigation
  void EndNavigation();

  // send events to manipulator for action
  void PreActivation(const VisTouchGesture* ipCurrentGesture);
  void PreActivation(const VisTouchGesture* ipCurrentGesture, int& oSamePickPath);
  void ActivationAndBeginManipulation();
  void Move(const VisTouchGesture* ipCurrentGesture);
  void MoveWithGesture();
  void Manipulation(const VisTouchGesture* ipCurrentGesture);
  void ManipulationWithGesture();
  void EndManipulation(const VisTouchGesture* ipCurrentGesture);
  void Edition();
  void EndEdition();

  // Internal actions used by magnifier
  enum MagnifierAction  { MagnifierAction_NoManipulation=0,
                          MagnifierAction_Manipulation,
                          MagnifierAction_Navigation};

  // Process magnifier actions and states on down gesture
  void ProcessDownMagnifier ( const VisTouchGesture*& opCurrentGesture, const VisTouchGesture* ipGesture , VisTouch_Action& oCurrentAction , bool iIsActivateDownHold );

  // Process magnifier actions and states on move gesture
  void ProcessMoveMagnifier ( const VisTouchGesture*& opCurrentGesture , const VisTouchGesture* ipGesture , VisTouch_Action& oCurrentAction , bool iIsActivateDownHold , MagnifierAction iManipulate);

  // Process magnifier actions and states on Up gesture
  void ProcessUpMagnifier ( const VisTouchGesture*& opCurrentGesture, const VisTouchGesture* ipGesture , VisTouch_Action& oCurrentAction , bool iIsActivateDownHold , MagnifierAction iManipulate);

  // Process magnifier actions and states on downhold gesture
  void ProcessDownHoldMagnifier ( const VisTouchGesture*& opCurrentGesture, const VisTouchGesture* ipGesture , VisTouch_Action& oCurrentAction , bool iIsActivateDownHold , MagnifierAction iManipulate);

  // Shows the magnifier at given (x,y) coordinates. (x,y) coordinates are respect to viewer dimensions which owes the magnifier
  void ShowMagnifier(CATMagnifierEvent& magEvent);

  // Moves the magnifier at given (x,y) coordinates. (x,y) coordinates are respect to viewer dimensions which owes the magnifier
  void MoveMagnifier(CATMagnifierEvent& magEvent);

  // Hides the magnifier
  void HideMagnifier();

  // Checks the magnifier visibility on CID, VID, Actionbar etc.
  // Return value, true: magnifier can be displayed, false: magnifier can't be displayed
  bool DecideMagnifierVisibility(CATMagnifierEvent& magEvent) const;

  // Hides the magnifier if user moves his finger quickly
  bool HideMagnifierOnRapidMovement ( const CATMathVector2Df& vector );

  // Reshow the magnifier if user hold his finger for short time
  bool ReshowMagnifierOnShortHold ( const CATMathPoint2Df& point , const CATMathVector2Df& vector , int moveTime , CATMagnifierEvent& magEvent);

  // Checks the shorthold gesture while moving magnifier
  bool IsShortHoldWhileMovingMagnifier ( const CATMathVector2Df& vector , int moveTime );


public:
  // callback method when the GeneralModifiers change
  void GeneralModifiersModified(CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);

private:
  // compare previous event to new event
  int IsIdenticalMultiTouchEventState(VisTouch_Action iPreviousAction, const VisMultitouchEvent& iPreviousMultitouchEvent, VisTouch_Action iNewAction, const VisMultitouchEvent& iNewMultitouchEvent);

  // do a pick
  void Pick(const CATMathPoint2Df& iPoint, CATPickPathList& oPickPathList) const;

  // Sets activation timer for given touch interpretor
  void SetActivationTimer(VisTouchInterpretor* pTouchInterpretor);

  // Returns current short hold time
  int GetShortHoldTime();

  // Returns current long hold time
  int GetLongHoldTime();

  // method needed for touch editor's action
  void SetCurrentTouchParams (VisTouch_Action &currentAction,  VisTouchGestureRecognizer* pCurrentGesture);
  void GetMyCurrentAction (VisTouch_Action& myAction);
  VisTouchGestureRecognizer*GetMyCurrentGesture ();
 
private:
  friend class IVVisuFwdDevice;
  //friend class CATGraphicWindow;
  void SetNavigationMode(int iNavigationMode){_isNavigationMode = iNavigationMode;};

  void SetNavigationTouchMode (int iMode);
  void RestaurePreviousTouchMode ();
  void SavePreviousNavigationMode(); 

  //determine if the touch is pointing inside a 3D viewpoint
  CATBoolean Is3DViewPointed( CATManipulator *iPointedManip, CATPickPath &iPickPath );
  // 
  // when a pen (wacom) is present, and if the touch inside 3Dviewer is reserved only for navigation, The pick is done on the first down event.
  // the first down gesture decides if the Navigation only mode is on or off.
  CATBoolean _NavigationTouchOn;
  
  // Current activation timer of this touch device
  VisActivationTimer _activationTimer;
private:

  // callback connected to the keyboard device
  CATCallback _GeneralModifiersCB;

  // all pathes selected by the device before election
  CATPickPathList _PickPathList;	

  // pick path of the selection/manipulated manipulator
  CATPickPath _PickPath;	

  // pick path under mouse
  CATPickPath _PickPathUnder;

  // pick path of the previously manipulated manipulator after a tap to enable tap down behavior
  CATPickPath _prevTapedPickPath;

  // touch event
  VisMonotouchDeviceEvent& _currentMonotouchEvent;
  VisMultitouchDeviceEvent& _currentMultitouchEvent;

  // touch listener
  VisTouchListener* _pTouchListener;

  // touch interpretor
  VisTouchInterpretor* _pTouchInterpretor;

  // internal state
  int _drawPending;
  int _isOnMainViewpoint3D;
  int _isOnRep;
  VisTouch_Action _previousAction;
  VisMultitouchEvent _previousMultitouchEvent;

  inline VisTouch_Action getPreviousAction() { return _previousAction; };
  inline void setPreviousAction(VisTouch_Action iaction) { _previousAction = iaction; };
  inline VisMultitouchEvent getPreviousMultitouchEvent() { return _previousMultitouchEvent; };
  inline void setPreviousMultitouchEvent(VisMultitouchEvent iMultitouchEvent) { _previousMultitouchEvent = iMultitouchEvent; };

  int _isNavigationMode;
  int _isPreviousNavigationMode;
  CATBoolean _NavigationModeModified;
  bool _multiSelect;
  bool _magnifierDefaultMode;
  bool _magnifierSpecificMode;
  bool _magnifierOverviewMode;

  bool _magnifierShown;
  int _elaspsedTime;
  bool _isDownHoldDone;
  bool _isLongHoldDone;
  bool _showMagnifierContextualMenu;
  CATPickPathList _lastMagSelectedPickPathList;

  struct VisSeparateTouchState
  {
    CATManipulator* pFirstPointedManip;
    CATManipulator* pPointedManip;
    CATManipulator* pPlugedManip;
    CATListOfInt touchIdList;                // liste des id des points de contact associés à un manipulateur plugges
    CATPickPathList pickPathList;	                    // all pathes selected by the device before election
    CATPickPath pickPath;	                            // pick path of the selection/manipulated manipulator
    CATPickPath pickPathUnder;                         // pick path under mouse
    VisTouchListener* pTouchListener;                  // touch listener
    VisTouchInterpretor* pTouchInterpretor;            // touch listener
    int isOnMainViewpoint3D;                           // touch begin on main 3DVpt
    int isOnRep;                                       // touch begin on a rep
    VisTouch_Action previousAction;                    // previous Action
    VisMultitouchEvent previousMultitouchEvent;        // previous Event
  };
  list<VisSeparateTouchState> _pSeparateTouchList; // liste des touch decorreles

  // previous pick values during an event interpretation
  mutable int _pickUpdate;
  mutable CATMathPoint2Df _prevPickPoint;
  mutable CATPickPathList _prevPickPathList;

  //   device editor manager
   CATTouchEditorManager *_DeviceManager;
   CATTouchMagnifierEditor *_magnifierEditor;

  // VisTouch_Action _myCurrentAction;
  // VisTouchGestureRecognizer* _myCurrentGesture;

   VisTouchGestureChooser *_myGestureChooser;
};

#endif
