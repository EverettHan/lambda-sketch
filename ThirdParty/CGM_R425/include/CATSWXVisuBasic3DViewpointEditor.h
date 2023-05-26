#ifndef CATSWXVisuBasic3DViewpointEditor_H
#define CATSWXVisuBasic3DViewpointEditor_H

#include "CATVisFoundation.h"
#include "CATBasic3DViewpointEditor.h"
#include "CATKeybdEvent.h"

class CATViewpointEditor;
class CAT3DIndicator;
class CATMouseEvent;
class CAT3DViewpoint;
class CATNotification;
class CATPickPath;
class CAT3DRep;
class CATKeybdEvent;
class CATUnicodeString;

//-----------------------------------------------------------------------

/**
* Class to handle viewpoint manipulations in a style similar to SolidWorks V1.
* Key features include:
*   -View rotations that center around model center, or where a mouse pick intersects
*    if zoomed in.
*   -Mousewheel zooming that keeps position under mouse cursor stable while zooming
*/
class ExportedByCATVisFoundation CATSWXVisuBasic3DViewpointEditor: public CATBasic3DViewpointEditor
{
	CATDeclareClass;

public:

	// Standard constructors and destructors
	// -------------------------------------
	CATSWXVisuBasic3DViewpointEditor (CAT3DViewpoint & i3DVp, CATVizViewer *iFather=NULL);
	virtual ~CATSWXVisuBasic3DViewpointEditor ();

	virtual void Activate( CATNotification *iNotification);

	virtual void SetMode( const CATBasic3DViewpointEditorMode iMode);

	virtual void StopRotate( CATMouseEvent &iMouseEvent);
	virtual void StartRotate( CATMouseEvent &iMouseEvent);
	virtual void DriveRotate( CATMouseEvent &iMouseEvent);

	virtual void DriveAxisRotate(CATMouseEvent &iMouseEvent);

	virtual void StartAndDisplayTarget( CATMouseEvent &iMouseEvent);
	virtual void MouseTranslate( CATMouseEvent &iMouseEvent);
	virtual void StopAndHideTarget( CATMouseEvent &iMouseEvent);
	virtual void DriveZoom( CATMouseEvent &iMouseEvent);

	virtual void DriveRoll(CATMouseEvent &iMouseEvent);

	virtual void StartConstrainedRotate( CATMouseEvent &iMouseEvent);

	virtual CATMathPointf GetRotationCenter();

	virtual int ZoomOnWheel(const CATNotification* ipEvent);
	virtual int DriveWheelZoom(CATMouseEvent &iMouseEvent);
	virtual int ZoomBy(float iZoomChangeFactor, bool iKeepUnderMouse);

	void TestPrivateMethodsWithNull();

	void StartTranslate(CATMouseEvent &iMouseEvent);
	void StopTranslate(CATMouseEvent &iMouseEvent);
	void TranslateView(const CATMathVectorf& iTranslation);
	void DoTranslate(const CATMathPointf &iPickStartPt, int iTargetX, int iTargetY);

	virtual void HandleKeyboardEvent(const CATNotification* ipEvent, CATVizViewer* ipViewer);

	void ViewpointAnimCallback(CATCallbackEvent iPublishedEvent, void* iPublishingObject, CATNotification* iNotification,
							   CATSubscriberData iClientData, CATCallback iCallback);

	HRESULT PerformPick(float iMx, float iMy, CATPickPath &oPickPath, bool iSpiralOutward = true);
	HRESULT PerformPick(float iMx, float iMy, CATMathPointf &oModelPt, bool iSpiralOutward = true);

	void Reframe();
	void ReframeOn(const CAT3DBoundingSphere &iBS3D);

	CAT3DViewpoint *Get3DViewpointToEdit() const;

	void BeginAnimationDefine();
	void EndAnimationDefineAndAnimate();
	void AnimateViewpointTo(const CAT3DViewpoint *iTargetVP, float iDuration = 0.8f);
	void SetViewpoint(const CAT3DViewpoint *iTargetVP);

	void OnMainViewpointChanged(CATCallbackEvent ie, void *, CATNotification *iEvent, CATSubscriberData is, CATCallback icb);

	void SetIndicator(CAT3DIndicator *ipIndic);

	void InternalDeviceEventCB(CATCallbackEvent ie, void *, CATNotification *iEvent, CATSubscriberData is, CATCallback icb);
	static void RebuildFromWheelEventCB(CATCommand* iCmd, int iTime, void* iClientData);
	//Tobii Methods
	//--------
	//now in SWXTobiiEventMap
	
	//void TobiiLink();
	//void TobiiPanToPoint();
	//void StartEyeTracking();
	//void TobiiRotate();
	//void TobiiLivePan();
	//CATMathPointf GetPointFromEyes(CATMathPointf pt);
	///tobii header
	//void SetupTobii();
	//void ReturnMain3DViewpoint(CAT3DViewpoint &oVizViewer);
	
	//was private
	//CATMathPointf GetMouseIntersectionWithTrackballPlane(float iX, float iY);
	//--------
	//////////end tobii
protected:
	virtual void Focus( CATMouseEvent &iMouseEvent);

private:
	void ClearRotatePtGP();
	void ShowRotatePoint(const CATUnicodeString &iWidgetClassName);
	void HideRotatePoint();

	void BuildMousePosition(CATMouseEvent &iMouseEvent);
	//moved to public for tobii
	CATMathPointf GetMouseIntersectionWithTrackballPlane(float iX, float iY);
	//--------
	CATMathPointf UnprojectOntoPickPlane(const CATMathPointf& iWorldPoint, float iX, float iY);

	void PerformRotation(const CATMathVector& iTrackballRotation) const;

	void ProcessKeyboardEvent(const CATKeybdEvent& iKeyEvent);

	CATMathPoint2Df ComputePixelFromModel( const CATMathPointf &iPtModel );

	bool CanSeeModelBounds();

	CATMathPointf GetRotationCenterFromModelBounds(float iMx, float iMy);

	void DeleteAnimation();

	////-----------------------------------------------------------------------
	//// Methods for XBox Controller
	////-----------------------------------------------------------------------
	//void XBoxControllerLink();
	//CATMathPointf GetPointFromJoystickInput(const double iX, const double iY);
	//void RotateAboutAxis(int iLeftOrRight, double iValue);
	//void RotateThetaAboutXorY(int iX, int iY, double iTheta);
	////-----------------------------------------------------------------------

	CAT3DIndicator *mIndicator;
	CATMathPointf mRotateCenterOnMouseDown;
	CATMathPointf mTranslatePointOnMouseDown;

	CAT3DViewpoint *mTargetViewpointForAnim;

	CATPickPath *mRepPath;
	CAT3DRep *mRotateCenterRep;
	int       mRotateCenterRepIsFurtive;

	// A list of all pending keyboard presses
	list<CATKeybdEvent> mKeyPressQueue;
	CATKeybdEvent       mLastKeyEvent;
	CATCallback         mViewpointAnimCallback;
	CATCallback         mMainViewpointChangedCallback;

	float     mWidestAngle;

	CATMathLine mRotationAxis;
	bool        mRotateAroundAxis;	// True if rotation should be constrained around axis
	bool        mAxisOriginNeedsDefined;

	static const int mDynamicHoldBetweenKeysMS;


	// JMA 08/06/2018

	CATVizViewer* mVizViewer;
	CATCallback mMouseCB;

	CATMouseEvent *mLastWheelEvent;
	int mRebuildTimerCallbackID;

	void RebuildFromWheelEvent();
	int HandleWheelZoom(CATMouseEvent &iMouseEvent);
	void HandleZoomDynamics();

	static const int mRemoveDynamicTimeoutMS;

	//tobii keyboard boolean
	//------
	//bool tobiiZoomDown;
	//-----
	
};

//-----------------------------------------------------------------------

#endif

