#ifndef CATSpaceListenerBase_H
#define CATSpaceListenerBase_H
 
// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATVisFoundation.h"
#include "CATNotification.h"
#include "CATThrMessage.h"
#include "CATCallbackManager.h"


#if !defined (_NO_X11_SOURCE) && (defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE))
#include <Xm/Xm.h>
#endif

class CATResourceLock;
class CATUnicodeString;
class CATGraphicWindow;
class CATSpaceListenerBase;
class CATSpaceCalibration;

#ifdef _WINDOWS_SOURCE
//#include <afxwin.h>
//#include <afxmt.h>
class CWnd;
class CATSpaceHiddenWnd;
#endif

//FUN078923 - I2S
#include "list.h"
#include "CATSpaceCmdInfo.h"

typedef struct CATTypeSpaceEvent_s
{
  int type;
  union {
    struct {
      int number;
      int pressed;
    } btn;
    double mat[16];
  };
  CATString headerId; //FUN078923 - I2S
} CATTypeSpaceEvent;


class ExportedByCATVisFoundation CATSpaceNotification : public CATNotification
{
  CATDeclareClass;

public :
  CATSpaceNotification(void);
  virtual ~CATSpaceNotification(void);

  CATTypeSpaceEvent _event;

private:
  // Not implemented
  CATSpaceNotification(const CATSpaceNotification &);
  CATSpaceNotification & operator= (const CATSpaceNotification &);
};

class ExportedByCATVisFoundation CATSpaceListenerBase
{
public:
  static CATSpaceListenerBase *GetInstance(void);
  void Release();

  int InitBase(void);

  int RegisterWindow(CATGraphicWindow *pWindow);
  int UnregisterWindow(CATGraphicWindow *pWindow);

  int OnEvent(CATTypeSpaceEvent *pEvent);

  void SetSpaceDeviceID(int devID, int devOrientation = 0);
  int  GetSpaceDeviceID(int *pOrientation = NULL);

  void SetTranslationOff(CATBoolean value);
  void SetRotationOff(CATBoolean value);
  void SetDominant(CATBoolean value);
  void SetSensitivity(float value);

  void SetFunctionCount(int count);  
  void AddFunction(int function, int fctID, CATUnicodeString &fctTitle);
  
  void GetDriverFunction(int fct);
  void SetButtonAssignment(int button, int fctID);
  void GetDriverButtonAssignment(int button);
  void SetDriverButtonAssignment(int button, int fctID);
  void SetDriverButtonRestoreDefault(int button);

  void SetDriverButtonText(int button, CATUnicodeString &cmdTitle);
  void SetDriverInfoLineText(CATUnicodeString &infoLine);

  void SetDriverTranslation(CATBoolean value);
  void SetDriverRotation(CATBoolean value);
  void SetDriverDominant(CATBoolean value);
  void SetDriverSensitivity(float value);

  CATDeclareCBEvent(DEVICE_EVENT);
  CATDeclareCBEvent(SPACE_BUTTON_EVENT);

  CATCallbackManager *GetCallbackManager(void) {return _pCallbackMgr;};

#ifdef _WINDOWS_SOURCE
  CWnd* GetCATSpaceHiddenWnd() { return (CWnd*) _pWnd;}
#endif

#if !defined (_NO_X11_SOURCE) && (defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE))
  int ForceActiveWindow(int force);
#endif

private :
  CATSpaceListenerBase();
  ~CATSpaceListenerBase();
  
  CATCallbackManager *_pCallbackMgr;
  CATSpaceNotification *_pSpaceNotif;

  CATSpaceCalibration *_pSpaceCalibration;

  static CATSpaceListenerBase *_instance;
  static CATResourceLock      *_instanceLock;
  int                         _held;
  
#if defined (_WINDOWS_SOURCE)
  CATSpaceHiddenWnd *_pWnd;
#elif defined (_COCOA_SOURCE) || defined (_ANDROID_SOURCE) /** on iOS : no 3DConnexion devices are supported **/

#elif defined (_LINUX_SOURCE) && defined (_GTK_SOURCE)
// TODO_GTK
#else
  Widget _widget; // Top Level Shell widget

  void SetWidget(Widget widget);
  void UnsetWidget(void);
  Widget GetTopLevelShellWidget(Widget widget);
  static void OnWidgetDestroy(Widget widget, XtPointer clientdata, XtPointer pointer);
  static void SpaceCallback(Widget widget, XtPointer clientdata, XEvent *pXEvent);
  static Bool CheckMotionEvent(Display *pDisplay, XEvent *pEXvent, char *arg);

  static Atom _MotionAtom;
  static Atom _ButtonPressAtom;
  static Atom _ButtonReleaseAtom;
  static Atom _CommandAtom;

  inline static Atom GetMotionAtom(void) {return _MotionAtom;};
  inline static Atom GetButtonPressAtom(void) {return _ButtonPressAtom;};
  inline static Atom GetButtonReleaseAtom(void) {return _ButtonReleaseAtom;};
  inline static Atom GetCommandAtom(void) {return _CommandAtom;};
#endif
  
  // Copy constructor, not implemented
	CATSpaceListenerBase(const CATSpaceListenerBase &iObjectToCopy);
	// Assignment operator, not implemented
	CATSpaceListenerBase & operator = (const CATSpaceListenerBase &iObjectToCopy);

public:
  void WriteCmdListToDriverPanel(list<CATSpaceCmdInfo> & spaceMouseCmdList, CATString workbenchName, CATUnicodeString workbenchTitle);
  int OnButtonEvent(CATTypeSpaceEvent* pEvent);
};

#endif

