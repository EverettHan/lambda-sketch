#ifndef VisDrawingAreaWrapper_H
#define VisDrawingAreaWrapper_H
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
//  Inheritance : VisDrawingAreaWrapper
//------------------------------------------------------------------------------
// Abstract : 	view wrapper for Cocoa plateform.
//------------------------------------------------------------------------------
// Role :     
//     This class wraps the CAEAGLLayer from CoreAnimation into a convenient UIView subclass.
//     The view content is basically an EAGL surface you render your OpenGL scene into.
//     Note that setting the view non-opaque will only work if the EAGL surface has an alpha channel.
//------------------------------------------------------------------------------
//  Main Methods :
//
//------------------------------------------------------------------------------
#if defined (_COCOA_SOURCE) || defined (_ANDROID_SOURCE)

#ifdef _DARWIN_SOURCE
#define VisCommonDrawingArea VisMacOSDrawingArea
#elif defined (_IOS_SOURCE)
#define VisCommonDrawingArea VisIOSDrawingArea
#elif defined (_ANDROID_SOURCE)
#define VisCommonDrawingArea DSYSysJNIJObject
#endif

#ifdef _COCOA_SOURCE
#ifdef __OBJC__
@class VisCommonDrawingArea;
#else // C++
typedef struct objc_object VisCommonDrawingArea;
#endif
#endif

#ifdef _ANDROID_SOURCE
#include <map>
#include <set>
class DSYSysJNIJObject;
#endif

#include "CATSysWidget.h"
class CATGraphicWindow;


class VisDrawingAreaWrapper
{

public:

  // constructor / destructor
  VisDrawingAreaWrapper(int iWidth, int iHeight);
  VisDrawingAreaWrapper();
  virtual ~VisDrawingAreaWrapper();

  // creation
  void Create(CATSysWidget);

  // drawing area resize
  void Resize(int iWidth, int iHeight);

  // graphic window pointer 
  void SetGraphicWindow(CATGraphicWindow*);

  // drawing area (EAGL view) pointer 
  VisCommonDrawingArea* GetDrawingArea();

  // post Update notification in notification's queue asynchronously 
  void SendDoUpdateInEventQueue();

#ifdef _ANDROID_SOURCE
  // graphic window pointer
  CATGraphicWindow* GetGraphicWindow();

  // viewport update
  void UpdateViewport(int iWidth, int iHeight);

  // check if drawing area Surface is ready
  inline bool IsDrawingAreaReady() const { return my_drawingAreaReady; }

  // remove drawing area ready flag
  void ResetDrawingAreaReady();

  // wrapper access with ID
  static VisDrawingAreaWrapper* GetWrapperWithID(int iID);

  // set rendering pause state
  static bool SetRenderingPauseState( bool iState );
#endif
  
#ifdef _IOS_SOURCE
  void DisplayLegacyEngineWarning();
#endif

private:

  VisCommonDrawingArea* my_pDrawingArea;
#ifdef _ANDROID_SOURCE
	CATGraphicWindow*	my_pGraphicWindow;
  int   my_ID;
  bool  my_drawingAreaReady;
  bool  my_needFirstExpose;

  static std::map<int,VisDrawingAreaWrapper*> s_ValidWrappers;

  static void _CheckAndApplyRenderingPause();
  static std::set<int> s_DrawingAreasWithSurface;
  static bool s_RenderingPaused;
#endif
};

#ifdef _ANDROID_SOURCE

#include "CATVisFoundation.h"
#include <jni.h>

extern "C"
{
  // Rendering native calls
  JNIEXPORT void JNICALL Java_com_dsy_visu_core_CATVisDrawingArea_nativeOnSurfaceChanged(JNIEnv* ijEnv, jobject ijObj);
  JNIEXPORT void JNICALL Java_com_dsy_visu_core_CATVisDrawingArea_nativeOnDraw(JNIEnv* ijEnv, jobject ijObj);

  // Touch native calls
  JNIEXPORT void JNICALL Java_com_dsy_visu_core_CATVisDrawingArea_nativeDispatchTouchEvent (JNIEnv* ijEnv, jobject ijObj);
  JNIEXPORT void JNICALL Java_com_dsy_visu_core_CATVisDrawingArea_nativeCancelTouchEvent (JNIEnv* ijEnv, jobject ijObj);
  JNIEXPORT void JNICALL Java_com_dsy_visu_core_CATVisDrawingArea_nativeHandleTouchEvent (JNIEnv* ijEnv, jobject ijObj, jfloat x, jfloat y,  jint cursorType, jint pointerId , jlong time);

  // Application pause management
  ExportedByCATVisFoundation void AndroidSuspendRendering();
  ExportedByCATVisFoundation void AndroidResumeRendering();
}

#endif

#endif
#endif
