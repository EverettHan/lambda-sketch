#ifndef CATGraphicWindow_H
#define CATGraphicWindow_H

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   specialized support for graphic rendering
// ----------   
//
//------------------------------------------------------------------------------
// Usage :      is used as base class to implement different API dependant
// -------      rendering (OGL/GL/PEX/XGL/X11) 
//              contains multi processing management
//                       animation management 
//                       stereo management
//                       delta draw management
//                       
//------------------------------------------------------------------------------
// Main methods :
// --------------
//
//
//------------------------------------------------------------------------------
// Class :      CATGraphicWindow
// -------        CATSupport
//                  CATCallbackManager (System FW)
//
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"

#include "CATViewerUtility.h"
#include "CATSupport.h"
#include "CATMutex.h"
#include "CATVizPickOptions.h"
#include "IVisTexturePtr.h"

#ifdef _WINDOWS_SOURCE

// astuce pour by-passer un bug (?) des MFCs
// et permettre a un source de referencer a la fois
// iostream.h et afxwin.h meme indirectement.

#ifdef _WINDOWS_
#define _WINDOWS_AUX
#undef _WINDOWS_
#endif 

#include <afxwin.h>

#ifdef _WINDOWS_AUX
#define _WINDOWS_
#undef _WINDOWS_AUX
#endif

#include <sys/types.h>
#include <sys/timeb.h>
class CATWindowsDrawingArea;

#define Button1 1
#define Button2 2
#define Button3 3
#define Button4 4

#define ButtonPress   1
#define ButtonRelease 2
#define ButtonDoubleClick 3
#define ButtonMove    4
#define KeyPress 1
#define KeyRelease 2

#endif // fin _WINDOWS_SOURCE

#if defined (_COCOA_SOURCE) || defined (_ANDROID_SOURCE)
class VisDrawingAreaWrapper;

#define Button1 1
#define Button2 2
#define Button3 3
#define Button4 4
#define ButtonPress   1
#define ButtonRelease 2
#define ButtonDoubleClick 3
#define ButtonMove    4
#define KeyPress 1
#define KeyRelease 2

#endif // fin _COCOA_SOURCE

#if defined (_LINUX_SOURCE)
#ifdef _GTK_SOURCE
	// avoid including gtk/gtk.h here
	typedef struct _GtkWidget GtkWidget;
	class CATGTKDrawingArea;

	// TODO_GTK to be validated
	#define Button1 1
	#define Button2 2
	#define Button3 3
	#define Button4 4
	#define ButtonPress   1
	#define ButtonRelease 2
	#define ButtonDoubleClick 3
	#define ButtonMove    4
	#define KeyPress 1
	#define KeyRelease 2

#else
	#include <X11/Xlib.h>
	#include <X11/extensions/XInput.h>
	#include <Xm/Xm.h>
	#include <sys/time.h>
	#include <sys/types.h>
	#define ButtonDoubleClick  6 // cf X.h for button definitions
	class CATX11DrawingArea;
#endif
#endif

#if defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE)
#include <X11/Xlib.h>
#include <X11/extensions/XInput.h>
#include <Xm/Xm.h>
#include <sys/time.h>
#include <sys/types.h>
#define ButtonDoubleClick  6 // cf X.h for button definitions
#endif

// Events generated
#include "CATTimeStampedEvent.h"
#include "CATMouseEvent.h"
#include "CATDelayedCall.h"
#include "CATKeybdEvent.h"
#include "list.h"
#include "CATMathDirectionf.h"
#include "VisWintabData.h"
#include "CATBaseUnknown_WR.h"
#include "CATSysWidget.h"

#include "CATSysWidgetEx.h"
#include "CATBoolean.h"
#include "CATIAV5Level.h"

class CATVizDuration;
class CATRender;
class CATRep;
class CATPickPath;
class CATRepPath;
class CATPickPathList;
class CATViewpoint;
class CAT3DViewpoint;
class CATPixelImage;
class CATVizTimerInteraction;
class VisTouchDevice;
class VisMultitouchEvent;
class CATVisDeferredSwapEvent;
class CATVisNextDeferredDrawEvent;
class VisWintabDevice;
class VisWintabProximityEvent;
class VisWintabEvent;
class VisStylusDevice;
class VisStylusEvent;
class VisStylusVIDEvent;
class VisStylusButtonEvent;
class VisStylusAnalogEvent;
class VisStylusTrackerEvent;
class VisSUIEntityEvent;
class CATSYPEvent;
class CATSYPEventArgs;
class IVButtonEvtArgs;
class IVAnalogEvtArgs;
class IVTrackerEvtArgs;
class IVSUIEntityEvtArgs;
class CATTexturePixelImage;

// supported Device 
class CATMouseDevice;
class CATKeyboardDevice;
class CATSpaceDevice;
class CATResizeEvent;
class CATPressEvent;
class CATMotionEvent;
class CATReleaseEvent;
class CATLongPressEvent;
class CATLongMotionEvent;
class CATLongReleaseEvent;
class CATIncrementEvent;
class CATLeaveEvent;
class CATEnterEvent;
class CATDoubleClick;
class CATDevice;
class CATNotificationDispatcher;
class CATCullingThreads;
class CATWaitingPoint;
class CATMathPointf;
class CATMathDirectionf;
class CATWheelEvent;
class CATKeyTranslator;
class CATLongMouseListener;
class CATISpaceDriver;
class CATMathTransformation;

class VisMultipipeData;
class VisImmersiveData;

class CATVisuAnimationWeakRef;
class CATVisuContext;
class CATFrameData;

class VisFBO;
class CATSpaceButtonEvent;


class ExportedByCATVisFoundation CATGraphicWindow : public CATSupport
{
	CATDeclareClass;

	friend class CATCullingThreads;
#ifdef _WINDOWS_SOURCE
	friend class CATWindowsDrawingArea;
#endif
#ifdef _LINUX_SOURCE
#ifdef _GTK_SOURCE
	friend class CATGTKDrawingArea;
#else
	friend class CATX11DrawingArea;
#endif
#endif

public:

	//  connexion for viewer class notification
	//-----------------------------------------
	CATDeclareCBEvent(GRAPHIC_WINDOW_CLASS_CONNEXION);
	CATDeclareCBEvent(DEVICE_ACTION);
	CATDeclareCBEvent(KEYBD_EVENT);
	CATDeclareCBEvent(IME_KEYBD_EVENT);
	CATDeclareCBEvent(VIEWPOINT_MANIP);
	CATDeclareCBEvent(GRAPHICWINDOW_RESIZE);
	CATDeclareCBEvent(GRAPHICWINDOW_UPDATE);
  CATDeclareCBEvent(GRAPHICWINDOW_SWAP);
  CATDeclareCBEvent(GRAPHICWINDOW_NEXT_DEFERRED_DRAW);
	CATDeclareCBEvent(GRAPHICWINDOW_DEFERRED_SWAP);
	CATDeclareCBEvent(GRAPHICWINDOW_EXPOSE);
	CATDeclareCBEvent(GRAPHICWINDOW_BEGINTIMEWARP);
	CATDeclareCBEvent(GRAPHICWINDOW_TIMEWARP);
	CATDeclareCBEvent(GRAPHICWINDOW_ENDTIMEWARP);
	CATDeclareCBEvent(REPPATH_DRAWING);
	CATDeclareCBEvent(GRAPHICWINDOW_ENDING_DRAW);
	CATDeclareCBEvent(GRAPHICWINDOW_FOCUS_IN);
  CATDeclareCBEvent(GRAPHICWINDOW_FOCUS_OUT);
	CATDeclareCBEvent(GRAPHICWINDOW_POINTER_DEVICE_CHANGED);
	CATDeclareCBEvent(GRAPHICWINDOW_STEREOMODE_CHANGED);
	CATDeclareCBEvent(GRAPHICWINDOW_LOST_CAPTURE);


	// 'ors. Constructor is protected. Impossible to create directly a GW
	//---------------------------------------------------------------------------
	virtual ~CATGraphicWindow();
	virtual ULONG __stdcall Release();
	virtual void Create(CATSysWidgetEx);
	virtual void Create(CATSysWidget);

	virtual CATCallbackManager* GetCallbackManager();

	// viewpoint management
	//----------------------
	virtual void SetStereoMode(const int mode, const float eyeGap);
  
	void DrawRepPath(CATRepPath&, const int Undraw = 0);

	// FBO
	//----------------------
	void SetFBOFlag(CATBoolean i_fboFlag);
	CATBoolean GetFBOFlag() const;

	// Pick
	//----------------------
	CATVizPickOptions& GetPickingOptions();
	void Pick(const PickingStyle style, const float x, const float y, const float dx, const float dy, CATPickPathList&, CATRepPath* = NULL, const float* polygon = NULL, const int nb_point = 0, const int ipick_style = 0, int forceFullPick = 1, int ignoreNoPickFlag = 0, int ipickOnlyDialog = 0);

	void Pick(const CAT3DViewpoint&, const PickingStyle, const CATMathPointf&, const CATMathDirectionf&,
		const float, const float, const float, const float, CATPickPathList&, CATRepPath* = NULL, const int ipick_style = 0, int forceFullPick = 1, int ignoreNoPickFlag = 0, int useVptBagrep = 0, int includeDialogReps = 0, int iVIDPicking = 0);

	void Pick(const CAT3DViewpoint&, const PickingStyle, const CATMathPoint&, const CATMathDirectionf&,
		const float, const float, const float, const float, CATPickPathList&, CATRepPath* = NULL, const int ipick_style = 0, int forceFullPick = 1, int ignoreNoPickFlag = 0, int useVptBagrep = 0, int includeDialogReps = 0, int iVIDPicking = 0);

	void Pick(const CAT3DViewpoint& i3DVpt, const PickingStyle iStyle, const CATMathPoint& iOrigin, double iRadius, 
		CATPickPathList& ioPickPathList, const int iViewModeStyle = 0, int iIgnoreNoPickFlag = 0, int iUseVptBagrep = 0, int iIncludeDialogReps = 0, int iStopAfterFirstPick = 0, int iVIDPicking = 0, const CATMathDirectionf& iDir = CATMathDirectionf());

	// Animations
	//----------------------
	int GetAnimationCount();
  /** @param i_pVisuAnimation [out, CATVisuAnimationWeakRef#Release] */
	void AddAnimation(CATVisuAnimationWeakRef* i_pVisuAnimation);
	void AbortAllAnimations(CATBoolean cutShortFlag = TRUE);
	void StepAnimations();
	float AlarmClockForAnimations();

	// Vrac
	//----------------------
	virtual void Swap();

	virtual void SetPolygonDrawingMode(const int) = 0;

	virtual void RendertoPixelBuffer(int); // usefull ?
	virtual short SetContext();
	virtual void UnsetContext();

	enum EPerfoOptimType
	{
		eMatrixMode,
		eSharing,
		eEngineModeMainVp,
		eEngineModeOtherVp
	};

  virtual void SetPerfoOptim(EPerfoOptimType iType, int iMode);
  virtual int GetPerfoOptim(EPerfoOptimType iType);

	//++ New RenderEngine
	virtual void DrawRequest();
	virtual bool NeedDrawEvent();
	//-- New RenderEngine


#ifdef _WINDOWS_SOURCE
	virtual void DestroyDriver() = 0;
#endif

	/**
	* MPCulling
	*/
	virtual void SetMultiThreadCullingMode(int nb_thread);

	virtual CATRender* CreateCullingRender();
	void CleanCullingRender(CATRender*);

	virtual CATVisuContext* GetVisuContext();

	virtual void* ReadZBuffer(int format) = 0;
	virtual void* ReadFrameBuffer(int format, int buffer = 0) = 0;
	virtual CATTexturePixelImage* GrabPixelZImage(int x, int y, int width, int height, CATTexturePixelImage* img = NULL, int buffer = 0) = 0;
	/**
	* Returns the grabbed <tt>CATPixelImage</tt> by reading the pixel rectangle at specified location (lower left corner) and size (rectangular block of pixels) from the framebuffer.
	* @param x
	*   Specify the X window coordinate of the first pixel that is read from the frame buffer.
	* @param y
	*   Specify the Y window coordinate of the first pixel that is read from the frame buffer.
	* @param width
	*  The width of the captured image that specifies the horizontal dimension of the pixel rectangle to read. width <= 0 is invalid.
	* @param height
	*  The height of the captured image that specifies the vertical dimension of the pixel rectangle to read. height <= 0 is invalid.
	* @param img
	*  The input pointer to the <tt>CATPixelImage</tt>.
	*  The default value for this parameter is NULL.
	*  Only <tt>CATPixelImageFormat</tt> RGBA is supported.
	*  If provided the pixels of img will be modified with pixel rectangle and the same is returned.
	* @param buffer
	*  The frame buffer to read from. The default value for this parameter is 0.
	*  0 = Front Buffer
	*  1 = Back Buffer
	* @return
	*  The pointer to the new or modifed input <tt>CATPixelImage</tt>. Values for pixels that lie outside the Buffer are undefined.
	*/
	virtual CATPixelImage* GrabPixelImage(int x, int y, int width, int height, CATPixelImage* img = NULL, int buffer = 0) = 0;

	// TMP MPKVisuRender --> from protected
	virtual void ExposeWindow() = 0;

	void GenerateUpdateEvent(int isMainWindow);	// to avoid recording GetTimeOfDay for the first animation step
	void GenerateSwapEvent(int iDeferredMode, bool iRefreshedVisu);
  void GenerateNextDeferredDrawEvent();

	// Navigation
	//----------------------
	//Viewpoint manipulation mode (=1 : viewpoint manipulation)
	inline void SetViewpointManipulationMode(int iVpManipMode = 1) { _viewpointManipulationMode = iVpManipMode >= 0 ? iVpManipMode : 0; };
	inline int  GetViewpointManipulationMode() { return _viewpointManipulationMode; };

	// mGPU 
	//----------------------
	const VisMultipipeData* GetMultipipeData() const;
	VisMultipipeData* GetMultipipeData();
	void CreateVirtualMultipipeData();
	void CreateSlaveMultipipeData();
	// mGPU slave and virtual windows management
	// method on virtual window
	int IsVirtualWindow() const;
	int GetNbSlaveWindow() const;
	CATGraphicWindow* GetSlaveWindow(int iIndex) const;
	void InitSlaveViewpoints();
	// method on slave window
	int IsSlaveWindow() const;
	CATGraphicWindow* GetVirtualWindow();
	// mGPU draw management
	void SetVirtualWindowDrawMode(unsigned int iVirtualWindowDrawMode);
	void SetTrackingDraw(unsigned int iDrawForTracking);
	void SetTrackingDrawEnd();
	void ComputeDrawForVirtualWindow();
	void SetMasterGWForPassiveStereoCulling(CATGraphicWindow* ipMasterGWForPassiveStereoCulling);
	void GetMasterGWForPassiveStereoCulling(CATGraphicWindow*& opMasterGWForPassiveStereoCulling);
	// mGPU data
	const VisImmersiveData* GetImmersiveData() const;
	VisImmersiveData* GetImmersiveData();
	// watermark
	bool IsWatermarkActivated() const;
	void SetWatermarkActivation(bool activated);
	unsigned int GetWatermarkVOffset() const;
	// mGPU post effect management
	void ApplyDistorsion();
	CATSupport* GetPostEffectSupport() { return _pPostEffectSupport; };
	// Hololens
	IVisTexturePtr const& OffscreenTexture() const;
	// Infinite Environment, still usefull ?
	void SetInfiniteEnvironment(CATVisInfiniteEnvironment* iEnv);
	void SetInfiniteEnvironment(const CATString& iName);
	void PushInfiniteEnvironment(CATVisInfiniteEnvironment* iEnv);
	void PushInfiniteEnvironment(const CATString& iName);
	void PopInfiniteEnvironment();
	void PushOverloadInfiniteEnvironment(CATVisInfiniteEnvironmentOverload* iOverloadEnv);
	// View Mode, still usefull ?
	void SetViewMode(const int iMode, const int iActive);

	// CID Frame Management
	//----------------------
	// Sets a pointer on a VidCtlViewer, responsible for the display and the interaction interface.
	void SetViewObject(const CATBaseUnknown_var& i_pViewObject);
	CATBaseUnknown_var GetViewObject() const;
	CATBoolean IsCIDMainFrame();
	void SetCIDMainFrame(int iValue);
	CATBoolean IsHiddenGraphicWindow();
	void SetHiddenGraphicWindow(int HiddenValue);
	CATBoolean IsHiddenGraphicWindowVisible() const;
	void SetHiddenGraphicWindowVisibility(CATBoolean iVisibilityValue);
	// Determine if Draw Request on CATViewer associated to CATGraphicWindow will be discarded
	CATBoolean IsDrawDiscarded();
	CATBoolean IsDrawNeeded();

	// OS Drawing Area
	//----------------------
#if defined (_WINDOWS_SOURCE)
	CATWindowsDrawingArea* GetDrawingArea();
#elif defined (_LINUX_SOURCE) && defined (_GTK_SOURCE)
	CATGTKDrawingArea* GetDrawingArea();
#elif defined (_LINUX_SOURCE)
	CATX11DrawingArea* GetDrawingArea();
	Window GetWindow();
#elif defined (_COCOA_SOURCE) || defined (_ANDROID_SOURCE)
	VisDrawingAreaWrapper* GetDrawingAreaWrapper();
#else
	Window GetWindow();
#endif

	// Handle GW
	//----------------------
	void AddDevice(CATDevice*);
	virtual void ResizeWindow(const float iWidth, const float iHeight);
	void SetFocus();
	void GetMousePosition(int* x, int* y);
	void SetMousePosition(int  x, int  y);
	void SetReplayMousePosition(const int ReplayMouseXPosition, const int ReplayMouseYPosition);
	void ChangeFocusMagnifier(int xClient, int yClient, int widthClient, int heightClient);
	void GetWindowPosition(int& x, int& y, int& width, int& height);
#if defined (_WINDOWS_SOURCE)
	//Handle Cursor for Fly/Walk
	//HCURSOR  SDLCursorMap_ = nullptr;
	HCURSOR GetStaticCursor();
	void SetStaticCursor(HCURSOR mycurosr);
#endif

	// Handle Events
	//----------------------
	/**
	* Signal that the current event about Tab key dispatched by @ref #OnKeybdEvent
	* function must be consumed by CATWindowsDrawingArea::PreTranslateMessage.
	*
	* This function must be called by a code that is called back synchronously
	* by @ref #OnKeybdEvent. It can be the code listening for @c KEYBD_EVENT
	* or a listener registered using @ref CATVizViewer#AddEventListener.
	*
	* Calling this function outside a call to @c OnKeybdEvent will have no effect.
	*
	* The purpose of this function is to enable VID (Visu Immersive Dialog) code
	* to handle the TAB key to do its own focus cycle. If the Tab key event
	* is not consumed then the default behavior of dialog will be executed
	* either:
	*   - a @c SetFocus will be called on the viewer (this is an issue for
	*     the @c CATVidCtlEditor since it displays a dialog CATDlgEditor that
	*     would lose its focus in that case)
	*   - or the focus will be given to the power input in CATIA
	*
	* Please do not use this function without permission.
	*/
	void ConsumeTabKeyEvent();
	/**
	* Sets a flag indicating if the GW automatically regain focus on
	* mouse action.In case of CID popup, the focus is managed directly by CID,
	* so the regainFocusFlag must be FALSE.
	* Default value is TRUE.
	*/
	void SetRegainFocusFlag(CATBoolean i_regainFocusFlag) { _regainFocusFlag = i_regainFocusFlag; }
	/**
	* @return the regainFocusFlag.
	*/
	CATBoolean GetRegainFocusFlag()const { return _regainFocusFlag; }
	CATBoolean IsTouchEnabled() const;
	// events managed just before draw
	void ExecutePendingEvents();
	//JMA PROJET LINUX
	int GetKeyStatus(CATKeyCode iKey);
	int GetKeyboardStatus(int iKey); // keyboard status
	CATString GetKeyboardLayout(); // keyboard layout
								   // Mouse
#ifdef _WINDOWS_SOURCE
	void HandleMouseMove(int x, int y, int buttons, int drawPending, int force = 0);  // old method used in the tests : do not remove 
#endif
	void HandleMouseMove(int x, int y, int buttons, CATUINT32 iModifier, int drawPending, int force = 0);
	void HandleMouseMove(int x, int y, int buttons, CATUINT32 iModifier, int drawPending, int force, CATLONG64 isystemTime);
	void HandleMouseLeave();
	void HandleMouseEntry();
#ifdef _WINDOWS_SOURCE
	void HandleMouseButtonEvent(int ButtonNumber, UINT nFlags, int EventType, int x = -1, int y = -1); // old method
#endif
	void HandleMouseButtonEvent(int iButtonNumber, CATUINT32 iModifier, int iButtonStates, int iEventType, int x, int y);
	void HandleMouseButtonEvent(int iButtonNumber, CATUINT32 iModifier, int iButtonStates, int iEventType, int x, int y, CATLONG64 isystemTime);
	void HandleMouseWheel(float wheel, CATModifier mod, CATLONG64 isystemTime);
	void HandleMouseWheel(float wheel, CATModifier mod = CATNone);
	void GenerateMissingMouseEvents(int ButtonNumber, int iModifier, int iButtonStates, int x, int y, CATLONG64 isystemTime);
	void ResendEvent(CATNotification* i_pNotification, const CATMathPoint2Df& i_posInViewer);
	// Keybooard
	void HandleKeyboardEvent(int KeyNum, int EventType);
	void HandleKeyCodeEvent(CATKeybdType iType, CATKeyCode iKeyCode, CATModifier iModifier, CATLONG64 isystemTime);
	void HandleCharEvent(CATKeybdType iType, CATUINT32 iCharCode, CATModifier iModifier, CATLONG64 isystemTime);
#ifdef _WINDOWS_SOURCE
	void OnKeybdEvent(CATKeybdType type, UINT key, UINT flags, UINT iKeyCodeType = 0);// keyCodeType: 0=character; 1=VK_Code
#endif
#if defined (_LINUX_SOURCE) && !defined (_GTK_SOURCE)
	void OnKeybdEvent(CATKeybdType type, KeySym key, CATUINT32 flags, CATUINT32 iKeyCodeType = 0);// keyCodeType: 0=character; 1=VK_Code
#endif
#if defined (_LINUX_SOURCE) && defined (_GTK_SOURCE)
	// TODO_GTK to be validated
	void OnKeybdEvent(CATKeybdType type, CATUINT32 key, CATUINT32 flags, CATUINT32 iKeyCodeType = 0);// keyCodeType: 0=character; 1=VK_Code
#endif
#if defined(_COCOA_SOURCE) || defined(_WINDOWS_SOURCE) || defined (_ANDROID_SOURCE)
#ifdef _DARWIN_SOURCE //MacOS
	void OnKeybdEvent(CATKeybdType type, CATUINT32 key, CATUINT32 flags, CATUINT32 iKeyCodeType = 0);// keyCodeType: 0=character; 1=VK_Code
#endif
#endif
																									 // Wintab
	void SetMouseDeviseForWintab();
	void UnsetMouseDeviseForWintab();
	void HandleWintabProximity(int leaveMode);
	void HandleWintabProximity(int leaveMode, CATLONG64 iTime);
	void HandleWintabEvent(const float x, const float y, const WintabPacket& WTData, int ButtonNumber, int EventType);
	void HandleWintabEvent(const float x, const float y, const WintabPacket& WTData, int ButtonNumber, int iModifier, int EventType, CATLONG64 iTime);
	CATBoolean IsWintabLoaded();
	void SetWintabLoaded();
	// Touch
	void HandleTouchEvent(int x, int y, int touchType, int touchID, CATLONG64 touchTime);
	void DispatchTouchEvent();
	void CancelTouchEvent();
	// Space Mouse
	void HandleSpaceEvent(CAT4x4Matrix& increment, CATString cmdHeader, int pressed, int EventType);
	void HandleSpaceEvent(CAT4x4Matrix& increment, CATString cmdHeader, int pressed, int EventType, CATLONG64 isystemTime);
	// VR
	void HandleStylusEvent(const CATMathTransformation& iPose, unsigned int iState);
	void HandleStylusEvent(const int& iXPosInPixels, const int& iYPosInPixels, unsigned int iState, CATLONG64 isystemTime);
	void HandleStylusButtonEvent(CATBaseUnknown* iSender, IVButtonEvtArgs const* ipArgs);
	void HandleStylusAnalogEvent(CATBaseUnknown* iSender, IVAnalogEvtArgs const* ipArgs);
	void HandleStylusTrackerEvent(CATBaseUnknown* iSender, IVTrackerEvtArgs const* ipArgs);
	void HandleSUIEntityEvent(CATBaseUnknown* iSender, IVSUIEntityEvtArgs const* ipArgs);
	// Delayed Event
	DelayedId SetDelayedCall(unsigned int delay, CATBaseUnknown* instance, CATDelayedMethod method, CATDelayedData data);
#if !defined (_NO_X11_SOURCE) && (defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE))
	static void RunDelayed(XtPointer data, XtIntervalId* Id);
#endif
	void RunDelayed(DelayedCall* call);
	void CancelDelayedCall(DelayedId id);
	void CancelAllDelayedCall(void);
	// Send Events
	void SendButtonPressed(CATPressEvent&);
	void SendButtonReleased(CATReleaseEvent&);
	void SendMouseMoved(CATMotionEvent&);
	void SendLongButtonPressed();
	void SendLongButtonReleased();
	void SendLongMouseMoved();
	void SendDoubleClicked(CATDoubleClick&);
	// Usefull ?
	void SendEventWhenDrawing(const int YesNo);
	// Long Mouse ModeCATUpdateEvent
	int GetLongMouseMode() { return _longMouseMode; };
	void SetLongMouseMode(int mode) { _longMouseMode = mode; };
	void HandleLostCapture();

#if /*defined (_LINUX_SOURCE) ||*/ defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE)
	inline Widget GetBaseWidget() { return _baseWidget; };
#endif
#if	defined(_LINUX_SOURCE)
#ifdef _GTK_SOURCE
	inline GtkWidget* GetBaseWidget() { return _baseWidget; };
#else
	inline Widget GetBaseWidget() { return _baseWidget; };
#endif
#endif

	// Dialog Update Display
	//----------------------
	void RegisterAppCallbacks();
	void UnRegisterAppCallbacks();
	void OnUPDATEDISPLAY(CATCallbackEvent, void*, CATNotification*, CATSubscriberData, CATCallback);

	// Draw
	//----------------------
	void SendDoUpdateInEventQueue(bool iGlobalDrawRequestFlagNotOnIdle);
	void SetAlwaysDrawn();
	bool GetDrawRequestFlag();
	void SetDrawRequestFlag(bool ival);
	bool GetDrawRequestFlagOnIdle();
	void SetDrawRequestFlagOnIdle(bool ival);
	bool GetDrawNeedFlag();
	void SetDrawNeedFlag(bool ival);
	bool GetDrawOnGoingFlag();
	void SetDrawOnGoingFlag(bool ival);
	bool IsValidWindow();

	static int _depth; // ZBuffer depth value; // usefull ?

protected:

	// 'ors. Constructor is protected. Impossible to create directly a GW
	//---------------------------------------------------------------------------
	CATGraphicWindow(const int, const int, const int alwaysDrawn = 0);
	// Constructor for a CATGraphicWindow using a CATSupport
	// Used for batch mode only
	CATGraphicWindow(const CATSupport&);

	void Clean();

	void GenerateBeginDrawingEvent();

	virtual void CleanRenderingContext();
	VisFBO* GetBackBufferFBO();
	virtual void _ForceSynchro();

	// TMP MPKVisuRender --> to public
	//virtual void ExposeWindow() = 0;
	virtual void ResizeWindow();

	// Notification from CATWindowsDrawingArea that it is destroyed.
	// Really need this function
	virtual void OnBaseWindowDestroyed() {}

protected:

	unsigned char _drawOffScreenFlag; // usefull ?
	CATVisuContext* _pOffScreenContext;  // usefull ?

	VisFBO* _offscreenFBO; // usefull ?

#if defined (_WINDOWS_SOURCE)
	CATWindowsDrawingArea* _pBaseWindow;    // pointeur sur la fenetre WINDOWS associee
#elif defined (_COCOA_SOURCE) || defined (_ANDROID_SOURCE)
	VisDrawingAreaWrapper* _pDrawingAreaWrapper;
#elif defined (_LINUX_SOURCE) && defined (_GTK_SOURCE)
	CATGTKDrawingArea* _pBaseWindow;
#else
	CATX11DrawingArea* _pBaseWindow;    // pointeur sur la fenetre WINDOWS associee
	static XVisualInfo* _visual;
	static Colormap    _colormap;
	Window      _window;
	Atom        _atomId;
#endif

	// mGPU draw management
	unsigned int _virtualWindowDrawMode;
	unsigned int _drawForTracking;
	int _drawOnlySlaveWindows;

	//  class init
	//  ----------
	static int _initDone;

	//++ CATGraphicWindow Destroy Management
	static void DestroyLockedGraphicWindow(void); // usefull ?

	static int                    _nb_lock;// usefull ?
	static list<CATGraphicWindow> _listOfCATGraphicWindow;// usefull ?
	static CATMutex               _mutexGraphicWindow;// usefull ?
													  //-- CATGraphicWindow Destroy Management

private:
	void GenerateMissingKeyboardEvents(CATUINT32 iOldModifier, CATUINT32 iNewModifier);
	void AddModifierEvent(CATModifier Modifier, CATKeybdType EventType, int iKey, int iType);
	void UpdateGeneralModifiers(CATDeviceEvent* Event, CATUINT32 iModifier);
	void RescueManipulators();
	void UnsetRescueMode();
	//void IgnoreMouseDeviceBusyMode();
#if defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE)
	static void InterpretDestroyEvent(Widget, XtPointer, XtPointer);
	static void InterpretExposeEvent(Widget, XtPointer, XtPointer);
	static void InterpretInputEvent(Widget, XtPointer, XtPointer);
	static void InterpretMotionEvent(Widget, XtPointer, XEvent*);
	static void InterpretKeyboardEvent(Widget, XtPointer, XEvent*);
	static void InterpretFocusChange(Widget, XtPointer, XEvent*);
#endif
	void ComputeMousePositionInVp(CATMotionEvent* iMotionEvent);

	void AddSpaceMouseDriver();
	void RemoveSpaceMouseDriver();

	void SetTouchEnabled(CATBoolean);

	void PickFromViewpoint(const CAT3DViewpoint& vp, const PickingStyle style, CATViewpoint& pick_vp,
		const float dx, const float dy, CATPickPathList& pickpath, CATRepPath* path, const int ipick_style, int ignoreNoPickFlag);

	// mGPU post effect management
	void CreatePostEffectSupport(CATRep* ipLeft3DRep, CATRep* ipRight3DRep);
	void DestroyPostEffectSupport();

private:
#ifdef _WINDOWS_SOURCE
	HCURSOR  SDLCursorMap_ = nullptr;
#endif
	int _ExposeDone; // usefull ?
  
	CATBoolean _offScreenRenderBufferFlag;

	CATVisDeferredSwapEvent*      _deferredSwapEvent;
  CATVisNextDeferredDrawEvent*  _nextDeferredDrawEvent;

	CATVizPickOptions _pickOptions;

	CATVizTimerInteraction* _pFrameRatePerfoInteraction;
	CATVizDuration* _pFrameRate;
	CATVizDuration* _pLatency;

	list <CATVisuAnimationWeakRef> _visuAnimationList;

	int _viewpointManipulationMode;

	// Private Services on CATGraphicWindow
	// Only accessible through VisuDirectAccessItf framework
	friend class CATVisPrivateServices;
	CATDeclareCBEvent(GRAPHICWINDOW_BEGINING_DRAW);

	// mGPU
	VisMultipipeData* _pMultipipeData;
	CATGraphicWindow* _pMasterGWForPassiveStereoCulling;
	VisImmersiveData* _pImmersiveData;
	CATSupport* _pPostEffectSupport;
	IVisTexturePtr _pOffscreenTexture;

	// Draw
	bool _DrawingRequested;
	bool _DrawingRequestedOnIdle;
	bool _DrawingNeeded;
	bool _DrawingOnGoing;
	bool _alwaysDrawn;
	bool _forcedDraw;

	// CID Frame
	bool _HiddenGW;
	bool _HiddenGWVisibility;
	bool _CidGW;
	CATBaseUnknown_WR _visViewWR;

	CATBoolean _WintabLoaded;
#if defined (_LINUX_SOURCE)
#ifdef _GTK_SOURCE
	GtkWidget * _baseWidget;
#else
	Widget _baseWidget;
	XtAppContext _AppContext;
#endif
#endif
#if /* defined (_LINUX_SOURCE) ||*/ defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE)
	Widget _baseWidget;
	XtAppContext _AppContext;
#endif

	// Viewer Devices
	CATMouseDevice* _MouseDevice;
	CATKeyboardDevice* _KeyboardDevice;
	CATSpaceDevice* _SpaceDevice;
	VisTouchDevice* _TouchDevice;
	VisWintabDevice* _WintabDevice;
	VisStylusDevice* _StylusDevice;

	// To recevice events from space devices
	CATISpaceDriver* _piSpaceDriver;

	// Events
	CATMouseEvent         _mouseEvent; // usefull ?
	CATResizeEvent* _ResizeEvent;
	CATPressEvent* _PressEvent;
	CATMotionEvent* _MotionEvent;
	CATMotionEvent* _lastMotionEvent;
	CATReleaseEvent* _ReleaseEvent;
	CATLongPressEvent* _LongPressEvent;
	CATLongMotionEvent* _LongMotionEvent;
	CATLongReleaseEvent* _LongReleaseEvent;
	CATIncrementEvent* _IncrementEvent;
	CATLeaveEvent* _MouseLeaveEvent;
	CATEnterEvent* _MouseEnterEvent;
	CATDoubleClick* _DoubleClick;
	CATWheelEvent* _WheelEvent;
	VisMultitouchEvent* _MultitouchEvent;
	VisWintabProximityEvent* _WintabProximityEvent;
	VisWintabEvent* _WintabEvent;
	VisStylusEvent* _StylusEvent;
	VisStylusVIDEvent* _StylusVIDEvent;
	VisStylusButtonEvent* _StylusButtonEvent;
	VisStylusAnalogEvent* _StylusAnalogEvent;
	VisStylusTrackerEvent* _StylusTrackerEvent;
	VisSUIEntityEvent* _StylusSUIEntityEvent;
	CATSpaceButtonEvent* _SpaceButtonEvent;

	int _longMouseMode;
	CATBoolean _touchEnabled;

	CATBoolean _LostCaptureOccured;

#if defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE)
	int _IsDoubleClickPossible;
	float _ClickXMousePos;
	float _ClickYMousePos;
#endif

	CATKeyTranslator* keyTranslator;
	CATLongMouseListener* mouseListener;
	void OnTimer(void*);
	DelayedId timer;
	void OnTimerMouseMove(void*);
	DelayedId timerMouseMove;

	// Record Mouse Position for ODT Replay:
	int _ReplayMouseXPosition;
	int _ReplayMouseYPosition;

	int _sendEventWhenDrawing; // usefull ?

	unsigned long _lastMotionTime;

	int _isLastPositionTouchOne;
	int _touchPositionId;
	int _xTouchPosition;
	int _yTouchPosition;
	/** flag set by @ref #ConsumeTabKeyEvent function by a caller to signal that the
	*  current event about Tab key dispatched by OnKeybdEvent function must be
	*  consumed by CATWindowsDrawingArea::PreTranslateMessage. */
	int _consumeTabKeyEvent;
	/**
	* Flag set by CID on popup GW, to prevent it to assign itself the focus,
	* as it is manage'd directly by CID. (cf CATVidCtlPopup)
	*/
	unsigned char _regainFocusFlag;
};

#endif
