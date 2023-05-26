// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATFrameManager.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2003  Creation: jov
//===================================================================
#ifndef CATFrameManager_H
#define CATFrameManager_H

#include "CATVisFoundation.h"
#include "list.h"
#include "CATCallbackManager.h"

#if !defined (_NO_X11_SOURCE) && (defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE))
#include <X11/Xlib.h>
#include <Xm/Xm.h>
#endif

class CATGraphicWindow;
class CATSupport;
class CATGWFrames;
class CATPassIterator;
class CATVisGPUStorageManager;
class CATWindowsDrawingArea;
//-----------------------------------------------------------------------

/**
 *
 */
class ExportedByCATVisFoundation CATFrameManager : public CATCallbackManager
{
  friend class CATWindowsDrawingArea;
public:

  CATDeclareClass;
  CATDeclareCBEvent (FRAMEMANAGER_BEGINFRAME);
  CATDeclareCBEvent (FRAMEMANAGER_ENDFRAME);

  // Standard constructors and destructors
  // -------------------------------------
  CATFrameManager ();
  virtual ~CATFrameManager ();

  void DrawRequest    (CATGraphicWindow *i_prGraphicWindow);
  void DoDrawJob      ();
  bool IsRunning      () const;

  void SetNewAlgoOnGW (CATGraphicWindow* i_prGW);
  void UnregisterGW   (CATGraphicWindow* i_prGraphicWindow);

#if !defined (_NO_X11_SOURCE) && (defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE))
  void SetAppContext(XtAppContext appContext);
#endif

  void ResetAndRedraw();

  // @return true if any frame needs a draw
  bool NeedDrawEvent() const;

  inline int IsDoUpdateSent() const { return m_DoUpdateSent; }

  /** i_prGraphicWindow should be a CATGraphicWindow */
  bool IsDrawRequested(CATSupport* i_prGraphicWindow) const;

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATFrameManager (CATFrameManager &);
  CATFrameManager& operator=(CATFrameManager&);

  void _InitEventLoopCB       ();
  void _ReleaseEventLoopCB    ();
  //void _EventLoopCB           ();
  void _SendEventInEventLoop  (CATGraphicWindow* i_prGraphicWindow);
  void _SetDrawDone           ();
  void _ExecuteLDH            ();
  void _DrawRequest(CATGraphicWindow* i_prGraphicWindow);
  void _DoDrawJob();
  CATGWFrames* _GetFrame(CATGraphicWindow* iWindow);

  inline void _SetDoUpdateSent(bool doUpdateSent) { m_DoUpdateSent = doUpdateSent; }


  int                   m_DoUpdateSent;
  list<CATGWFrames>     m_FramesList;

  int                   m_InitCBDone;
  //int                   m_SlaveMode;

#if !defined (_NO_X11_SOURCE) && (defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE))
  void *                m_PrDisplay;
  Widget                m_PrShell;
  Atom                  m_AtomId;
  XEvent                m_Event;
  XtAppContext          m_AppContext;

  static void _InterpretClientMessageEvent ( Widget, XtPointer, XEvent *);
#endif

public:
  // deprecated
  // Old OrE code

  // Only used by print
  // Use method "IsRunning" to known if some frame are executing
  list <CATPassIterator> GiveAllPassIterators();
};

//-----------------------------------------------------------------------
#endif
