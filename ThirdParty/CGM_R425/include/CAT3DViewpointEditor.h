#ifndef CAT3DViewpointEditor_H
#define CAT3DViewpointEditor_H
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :
#include "CATVisFoundation.h"

#include "CATViewpointEditor.h"
#include "CAT3DViewpoint.h"
#include "CATMathPointf.h"
#include "CATMathPoint.h"
#include "CATMathVectorf.h"
#include "CATMathDirectionf.h" 
#include "CATMouseEvent.h" 
#include "CATMathLine.h"
#include "CATDataType.h"

# define DBG(a) " "#a"=" << a

class CAT3DViewpoint;
class CATPickPath;
class CATRep;
class CAT2DRep;
class CAT3DRep;
class CATViz3DViewer;
class CATManipulator;
class CATMouseEvent;
class CATKeyboardEvent;
class CATString;
class CAT3DBagRep;
class CATFlyGlider;
class CAT3DFlyRep;
class CATPickPathList;
class VisTouchGesture;
class CATVisuAnimationWeakRef;
class CATMathTransformation;
class CATMathQuaternion;


/** 	Basic class of 3D Viewpoint manipulation describing the basic
 *      movements of manipulation.
 *     <p>
 *     Contains the basic movements that can be driven with devices.
 */

/** @nodoc*/
enum CATBasic3DViewpointEditorMode
{
  VPEditorStopMode,
  VPEditorDefaultMode,
  VPEditorRotateMode, 
  VPEditorRotateAxisMode, 
  VPEditorZoomMode, 
  VPEditorZoomAreaMode,
  VPEditorLookAtMode,
  VPEditorTranslateMode,
  VPEditorTiltMode,
  VPEditorFullMode,
  VPEditorMechMode,
  VPEditorKeepSightMode,
  VPEditorExamineMode, 
  VPEditorWalkMode,
  VPEditorFlyMode,
  VPEditorDirectFlyMode,
  VPEditorDirectWalkMode,
  VPEditorRecenterMode
};

//------------------------------------------------------------------------------

class ExportedByCATVisFoundation CAT3DViewpointEditor : public CATViewpointEditor
{
  CATDeclareClass;

  //------------------------------------------------------------------------------
public :

  /** Create a viewpoint editor that will modify the 3D viewpoint.
   *  To be activated, the viewpointEditor has to be declared to the viewer
   *  with CATViewer::SetViewpointEditor( iViewpointEditor)
   *  @param iName name for record
   *  @param iViewpoint The viewpoint manipulated.
   */
  CAT3DViewpointEditor( const CATString &iName, CAT3DViewpoint &Viewpoint);
  virtual ~CAT3DViewpointEditor();

  /** 
   * Activate the Viewpoint editor. This method is called by the viewers only.
   * The activation is called when the Viewpoint editor is attached to the viewer.
   * see CATViewer::SetViewpointEditor
   */
  virtual void Activate( CATNotification *event);
  
  //  Target pick
  void SetTargetOnFrontObject();
  void SetTargetOnPickedObject( CATMouseEvent &MouseEvent, const float MoveOf = 0.0);
  void JumpBackwardOf( const float MoveOf = 1.0);
  //  Integration of walk functionality
  void LockHorizontal();
  void UnlockHorizontal();
  int IsHorizontalLocked() const;
  virtual void SetWarningMessageWhenLocked(const boolean isWarningNeeded=true);

  void DefineViewpoint(const CATMathPointf& eye,const CATMathPointf& ul,const CATMathPointf& ur,const CATMathPointf& lr,const CATMathPointf& ll, const int is_assym = 0);

  /**
   *  Get the speeds of the navigation. The are used for display only.
   *  @param oTranslationSpeed Speed vector of translation (in model's unit per seconds)
   *  @param oRotationSpeed Speed vector of rotation (direction is the rotation axis, lenght is
   *              radians per seconds)
   */
  void GetSpeeds( CATMathVectorf &oTranslationSpeed,  CATMathVectorf &oRotationSpeed) const;
  void ChangeSpeed ( float);
  float GetSpeed ( void);
  
  /**
  *
  */
  static void RotateAround( CAT3DViewpoint &Viewpoint3D, const CATMathVector &iRotationStep, const CATMathDirectionf &iVertical);

  // 3Dconnexion devices (SpaceMouse, SpaceBall, SpaceNavigator, etc)
 // virtual void SetSpaceTarget( const CATMathPointf& );
 // virtual CATMathPointf GetSpaceTarget();
   virtual void SetSpaceTarget( const CATMathPoint& );
   virtual CATMathPoint GetSpaceTarget();

  virtual void SpaceMove (CATMathVectorf& translation, CATMathVectorf& rotation);

  void SetRotateAxis ( CATMathLine& axis);

  CATFlyGlider* InitFly(int showRep=1);
  void StartFly( void);
  void EndFly( void);
  void CleanFly( void);

  inline void SetFallMode(const int iFallMode) {_FallMode = iFallMode;};
  inline int IsFallMode() {return _FallMode;};

  // 1 : CATPickingRender collision detection
  // 2 : CATCollisionRender collision detection
  inline int GetCollisionDetectiontype () {return _DetectionCollisionType;};
  inline void SetCollisionDetectiontype (int type) {_DetectionCollisionType = type;};

  // SetCenter 
  // default is 0.5,0.5
  void SetRotationCenterDirection(float width_ratio,float height_ratio);
  void GetRotationCenterPixelCoordinates(int& x,int& y);

  // SetCenter
  CATMathPointf GetRotationCenter(int iDynamic=0);
  CATMathPoint GetRotationCenterd(int iDynamic=0);

  inline float GetSphereRadius() {return _SphereRadius;};   
  inline float GetSightHeight() {return _SightHeight;};   
  inline void SetSphereRadius(float SphereRadius) {_SphereRadius = SphereRadius;};
  inline void SetSightHeight(float SightHeight) {_SightHeight = SightHeight;};

  CATFlyGlider *GetFlyGlider() {return _pGlider;};

  // Get mouse position in a viewpoint
  int GetMousePosition(CATMouseEvent & iMouseEvent, CATMathPoint2Df & oPoint);

  CATMathDirectionf GetLastGravity();

  /**
   * Method to handle all keyboard events related to viewpoint location modification.
   */
  virtual void HandleKeyboardEvent(const CATNotification* ipEvent, CATVizViewer* ipViewer);

  /**
   * Method to handle all touch gestures related to viewpoint modification.
   */
  virtual void TouchGesture(const VisTouchGesture* ipTouchGesture);

	/**
   * Method to rotate the viewpoint around a specific point with euler angles.
   * incrementing iPitch will increment viewpoint rotation around Right
   * incrementing iYaw will increment viewpoint rotation around Up
   * incrementing iRoll will increment viewpoint rotation around Sight
   */
	 void RotateAroundRotationCenter( const double iPitch, const double iYaw, const double iRoll, const CATMathPointf& iRotationCenter);
	 void RotateAroundRotationCenter( const double iPitch, const double iYaw, const double iRoll);

//   void RotateAroundRotationCenterEulerZXY( const double iEulerZ, const double iEulerX, const double iEulerY);

   void RotateAroundRotationCenter(const CATMathTransformation& iTransfo);

   void RotateAroundRotationCenter(const CATMathQuaternion& iQuat);
  
  /**
   * Set the physical gravity direction in the reference frame of the viewpoint.
   */
   void ApplyPhysicalGravity(const CATMathDirectionf& iPhysicalGravity, CAT3DViewpoint* iopViewpoint = NULL, const unsigned int iInit = 0);

   CATMathAxis GetViewpointAxis() const;
   void SetViewpointAxis(const CATMathAxis& iNewAxis);

  //------------------------------------------------------------------------------
protected :

  CAT3DViewpoint *_3DViewpoint;
  CATViz3DViewer *_3DViewer;

  virtual void ShowFocusPoint(CAT3DRep *Rep=NULL, int IsFurtive = TRUE, int iForce=0); // IsFurtive : TRUE , furtif, FALSE, non Furtif
  virtual void HideFocusPoint(int iForce=0);
  virtual void ShowTarget( CATMouseEvent& );
  virtual void HideTarget( CATMouseEvent& );

  // 3Dconnexion devices support (SpaceMouse, SpaceBall, SpaceNavigator, SpacePilot, etc)
  virtual void SetAutoSpaceTargetSuspend(const int suspend);
  virtual int GetAutoSpaceTargetSuspend();
  virtual void CalculateAutoSpaceTarget();
  void CreateSpaceTargetRep();
  void DestroySpaceTargetRep();
  virtual void ShowSpaceTarget(int redraw = FALSE);
  virtual void HideSpaceTarget(int redraw = FALSE);
 // CATMathPointf _SpaceTarget; // Rotation center for 3Dconnexion devices
  CATMathPoint _SpaceTarget; // Rotation center for 3Dconnexion devices

  //  Tools of navigation
  CAT2DRep *_ZeroSpeedRep;

  //  Viewpoint modification tools
  void Jump( const CATMathVectorf &TranslationStep, const CATMathVectorf &RotationStep);		// no iverride usage, use Jump( const CATMathVector &TranslationStep, const CATMathVector &RotationStep); instead
  void JumpAround(const CATMathVectorf &TranslationStep, const CATMathVectorf &RotationStep);

  virtual void Jump( const CATMathVector &TranslationStep, const CATMathVector &RotationStep);
  virtual void JumpAround( const CATMathVector &TranslationStep, const CATMathVector &RotationStep);

  //  Main Speed mechanism
  CATMathVectorf _RotateSpeed;
  CATMathVectorf _TranslateSpeed;
  CATMathVectorf _MouseTranslateSpeed, _MouseRotateSpeed;
  virtual void UpdateSpeed( const CATULONG32 time);

  virtual void UpdateAnimation( const CATULONG32 time);
  CATCallback _AnimationCB;
  CATULONG32 _UpdateTime;
  virtual void ComputeNextStep( CATCallbackEvent Id, void *From, CATNotification *Event, CATSubscriberData Data, CATCallback Callback);

  //  _ViewpointBuilder 
  CATManipulator *_ViewpointBuilder;
  float _ModelSize;	// size of the model :  FontSpeed reference dimension

  // Starts and stops
  virtual void StartAndDisplayTarget( CATMouseEvent &MouseEvent);
  virtual void StopAndHideTarget( CATMouseEvent &MouseEvent);
  virtual void StopAndPickTarget( CATMouseEvent &MouseEvent);
  virtual void StopAndHideAndPickTarget( CATMouseEvent &MouseEvent);
  //
  virtual void StartViewpointDefinition( CATMouseEvent &MouseEvent);
  virtual void DriveViewpointDefinition( CATMouseEvent &MouseEvent);
  virtual void StopViewpointDefinition( CATMouseEvent &MouseEvent);
  virtual void DriveZoomAndTurn( CATMouseEvent &MouseEvent);
  virtual void KeyZoomAndTurn( CATKeyboardEvent &KeyboardEvent);
  virtual void KeyboardTranslate( CATKeyboardEvent &KeyboardEvent);
  virtual void KeyZoom( CATKeyboardEvent &KeyboardEvent);
  virtual void DriveZoom( CATMouseEvent &MouseEvent);
  CATPickPath *_RepPath;
  CAT3DRep *_FocusRep;
  int       _FocusRepIsFurtive;
  virtual void DriveRoll( CATMouseEvent &MouseEvent);
  virtual void StopRoll( CATMouseEvent &MouseEvent);
  virtual void KeyRoll( CATKeyboardEvent &KeyboardEvent);
  virtual void DriveTilt( CATMouseEvent &MouseEvent);
  virtual void KeyTilt( CATKeyboardEvent &KeyboardEvent);
  virtual void MouseTranslate( CATMouseEvent &MouseEvent);
  virtual void Recenter( CATMouseEvent &MouseEvent);
  virtual HRESULT RecenterWithAnimation(const CATMathPoint2Df& iRecentringPoint);
  static double _mouseRotCoef;		// (rad)
  static double _frontExpCoef;
  virtual void StartFly( CATMouseEvent &MouseEvent);
  virtual void DriveFly( CATMouseEvent &MouseEvent);
  virtual void UpdateFlyRep();
  virtual void KeyFly( CATKeyboardEvent &KeyboardEvent);
  virtual void Focus( CATMouseEvent &MouseEvent);
  virtual void InitializeThrust();
  virtual void ChangeThrust( int Way, CATULONG32 time);
  void InverseSpeed( CATULONG32 time);
  virtual void StopFly( CATMouseEvent & CATMouseEvent);
  virtual void ComputeDirection( CATMouseEvent &MouseEvent, const int XFilter=0);
  //  Speed prototype change
  int _IsMouseFlying;		// Flag saying if we are fly with mouse use
  int _SpeedType;		// 0=NotFlying  1=Forward  -1=Backward
  float _SpeedValue;

  static int HeadTilt(CAT3DViewpoint & iViewpoint3D);

  //Drag with MB2
  //virtual void StartDrag2( CATMouseEvent &MouseEvent);
  //virtual void DriveDrag2( CATMouseEvent &MouseEvent);
  //virtual void StopDrag2 ( CATMouseEvent &MouseEvent);
  CATMathPlane _drag2Plane;

  //  Integration of walk functionality
  int _IsHorizontalLocked;
  //CATMathDirectionf _HorizontalPlaneDirection;
  //CATMathPointf _HorizontalPlanePoint;
  CATMathDirection _HorizontalPlaneDirection;
  CATMathPoint _HorizontalPlanePoint;
  CATMathDirection _LastGravity;
  CATRep *_WalkPlaneRep;

  virtual void StartRotate( CATMouseEvent &MouseEvent);
  virtual void DriveRotate( CATMouseEvent &MouseEvent);
  virtual void StopRotate( CATMouseEvent &MouseEvent);
  virtual void KeyRotate( CATKeyboardEvent &KeyboardEvent);
  virtual void DriveAxisRotate( CATMouseEvent &MouseEvent);

  CATFlyGlider* _pGlider;
  CAT3DFlyRep* _flyRep;

  float        _RxCenter;
  float        _RyCenter;

  CATMathVectorf _LastDriftSpeed;
 // float _LastDist;                  // Pour l'initialisation de la vitesse en mode Fly
  double  _LastDist;                  // Pour l'initialisation de la vitesse en mode Fly

  /**
  * @return IUnknown#Release
  */
  CATPickPath* CollisionPick(const CATMathVectorf& dirPick,float dist,const CATMathPointf& from,float &MinDistance);
  int _DetectionCollisionType;

  //CATMathPointf _rotationCenter;	// For Rotation
  CATMathPoint _rotationCenter;	// For Rotation
  CAT3DViewpoint _vp3DForAnim;// For viewpoint animation
  int _repeatCount;
  int _isCylindricView;

  // Touch
  virtual HRESULT BeginTouchManipulate();
  virtual HRESULT EndTouchManipulate(int iInteruptViewpointAnimation);
  virtual HRESULT TouchManipulate(const VisTouchGesture * iGesture);
  HRESULT Zoom(const VisTouchGesture * iGesture);
  HRESULT Translate(const VisTouchGesture * iGesture);
  HRESULT ScreenPlaneRotation(const CATMathPoint2Df& iRotateCenter, float iRotationAngle);
  virtual HRESULT Recentring(const VisTouchGesture * iGesture);
  virtual HRESULT Rotate(const VisTouchGesture * iGesture);
  virtual HRESULT Navigate(const VisTouchGesture * iGesture);
  virtual HRESULT AnimateRotation(const VisTouchGesture * iGesture);
  virtual HRESULT Reframe(const VisTouchGesture * iGesture);
  int GetRotationMatrix(const CATMathPoint2Df& iOriginRotationPoint, const CATMathPoint2Df& iEndedRotationPoint, int iFlickGesture, CATMathDirectionf& oRotationDirection, float& oRotationAngle, CATMathPointf& oRotationCenter, CAT4x4Matrix& oRotationTransfo);
  void MultiSelOnOff(int iOnOff);

  //------------------------------------------------------------------------------
private :

  //  Target pick
  HRESULT SetTargetOnPickedObject( const CATMathPoint2Df& iPoint, CAT3DViewpoint*& iopViewpoint, CAT3DViewpoint*& iopViewpointForPickPath, const float MoveOf = 0.0);
  HRESULT SetOldTargetOnPickedObject(const CATMathPoint2Df& iPoint, int NotFound, int isRecordReplay, CAT3DViewpoint*& iopViewpoint, CATPickPath *PickPath, const float MoveOf);

  //  Rotation
  int GetSphereIntersection( CATDeviceEvent *Notification, 
    const CATMathPoint &iCenter, const float iRadius, int &ioSide, CATMathPoint &oIntersection);

  float _SoftballRadius;
  int _SoftballSide, _IsSoftballRoll;
  int _SideTurn;
  int BodyColors[18];
  CAT3DBagRep *_CursorRep;
  CAT3DBagRep *_SpaceTargetRep;
  CAT3DRep *_TargetRep;
  int _IsPickNeeded;
  int _FallMode;
  float _SphereRadius;
  float _SightHeight;

  // Touch
  int _isTwoFingersNavigation;
 // CATMathPointf _twoFingersRotationCenterPoint;
  CATMathPoint _twoFingersRotationCenterPoint;
  int _multiSelBehavior;
  int _multiSelTrapStyle;
  int _viewpointAnimatedFlag;
  CATVisuAnimationWeakRef* _p3DViewpointAnimationWR;
  CATUINTPTR _3DViewpointAnimationBeginTime;

  CAT3DRep * UpdateBall();
  //CATVizCursor::CATVizStyle _PreviousCursor;
  CATMathPoint _LastContactPoint;	// For feedback ball rep display

  int _rotateAroundAxis;	// For Rotation
  CATMathLine _AxisLine;	// For Rotation

 
  void ViewpointDestroyedCB(CATCallbackEvent, void *, CATNotification *Event, CATSubscriberData , CATCallback);

public :

  virtual int ZoomOnWheel(const CATNotification* ipEvent);

};
#endif

 
 
