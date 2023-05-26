#ifndef CATAfrFrameLayoutServices_H
#define CATAfrFrameLayoutServices_H
//
// Copyright Dassault Systemes 2004
//------------------------------------------------------------------------------
// Abstract: the CATAfrFrameLayoutServices manages the position and size of the Application Frame main window
//------------------------------------------------------------------------------
// Usage:    An application may subscribe to the resize and move events or set the size or position of the main window
//------------------------------------------------------------------------------
// Inheritance: CATAfrFrameLayoutServices
//                 CATCallbackManager (System framework)
//------------------------------------------------------------------------------
#include "CATCallbackManager.h"
#include "CATAfrFoundation.h"
#include "CATAfrSnapAlignment.h"
#include "CATBoolean.h"
#include "CATListOfCATFrmWindow.h"
#include "CATSYPMacros.h"
#include "CATLISTP_CATBaseUnknown.h"
#include "CATString.h"

class CATString;
class CATUnicodeString;
class CATFrmWindow;
class CATISYPIntrospectable_var;
class CATIAfrActionBarServices;

class ExportedByCATAfrFoundation CATAfrFrameLayoutServices: public CATCallbackManager
{
  
public:
  
  CATDeclareClass;

  CATAfrFrameLayoutServices ();
  virtual ~CATAfrFrameLayoutServices ();  
  
  CATDefineCBEventInHeader(ApplicationFrameResized)
  CATDefineCBEventInHeader(ApplicationFrameMoved)
  CATDefineCBEventInHeader(FILE_DROPPED_ON_APPLICATION)
  CATDefineCBEventInHeader(AFR_OBJECT_EDITION)
  CATDeclareCBEvent(WINDOW_NAME_CHANGED);
  CATDeclareCBEvent(CONTEXT_ID_CHANGED);

  static CATAfrFrameLayoutServices * GetCATAfrFrameLayoutServices();
  
  void SetDimensions (int px, int py, int haut, int larg);
  void Resize (int haut, int larg);
  void SetPosition (int px, int py);
  
  /**
   * Moves the given window to the given side of the target window.
   * The two windows will be contained in the same dashboard page.
   */
  void MoveWindowTo(CATFrmWindow * i_pWindowToMove, CATFrmWindow * i_pTargetWindow, CATAfrSnapAlignment i_snapAlignment);

  /**
  * Moves the given window into a new Tab.
  * Does nothing if the window is alone in its current Tab.
  */
  void MoveIntoNewTab(CATFrmWindow * i_pWindowToMove);

  /**
   * Specifies whether the dashboard page containing the given window is maximized or not.
   */
  void SetDashboardPageMaximizedState(CATFrmWindow * i_pWindow, CATBoolean i_maximizedState);

  /**
   * Streams the current dashboard layout with the (optional) given window list to stream.
   * @param i_pWindowList the list of windows to stream. If NULL, all the windows present in the session will be streamed.
   * @param o_stream the returned stream.
   * @return S_OK in case of success, E_FAIL otherwise.
   */
  HRESULT StreamDashboard(CATLISTP(CATFrmWindow) * i_pWindowList, CATUnicodeString& o_stream);

  /**
   * Restores the dashboard layout from the given stream and the given window list.
   * @param i_pWindowList the list of windows corresponding to the stream.
   * @param i_stream the stream containing the dashboard layout to restore.
   * @return S_OK in case of success, E_FAIL otherwise.
   */
  HRESULT RestoreDashboard(const CATLISTP(CATFrmWindow)& i_windowList, const CATUnicodeString& i_stream);

  enum  CATAfrWindowArrange {VerticalArrangement, HorizontalArrangement, GridArrangement};

  void TileInEachTabPage(int iArrangementType = VerticalArrangement );
  void TileInActiveTabPage(int iArrangementType = VerticalArrangement );
  void TileListInNewTabPage(CATLISTP(CATBaseUnknown) & iWindowList, int iArrangementType = VerticalArrangement );

private:

  void WindowResizedCB(CATCallbackEvent, void *, CATNotification *Event, CATSubscriberData , CATCallback);
  void WindowMovedCB  (CATCallbackEvent, void *, CATNotification *Event, CATSubscriberData , CATCallback);

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATAfrFrameLayoutServices (const CATAfrFrameLayoutServices &);
  CATAfrFrameLayoutServices & operator= (const CATAfrFrameLayoutServices &);

  /**
   * Get the view of the ActionBar.
   * Only used by AfrWindowManagerVIDMDI in order to layout it in CID Frame.
   *
   * @return the view of the ActionBar.
   */
  CATISYPIntrospectable_var GetActionBarCtl();
  friend class AfrWindowManagerVIDMDI;

  static CATAfrFrameLayoutServices * _pCATAfrFrameLayoutServices;

  CATIAfrActionBarServices * _pABServicesItf;
  
};

/**
 * Helper class to prevent the automatic dashboard page creation when creating and activating a new CATFrmWindow.
 * This class must be used on the stack before creating the new CATFrmWindow if you want to prevent the 
 * new tab page creation, whatever the current settings value : 
 *
 * CATAfrDisableDashboardPageCreation noNewPage;
 *
 * CATFrmWindow * pFrmWindow = new CATFrmWindow(...);
 * pLayout->SetCurrentWindow(pFrmWindow);
 *
 */
class ExportedByCATAfrFoundation CATAfrDisableDashboardPageCreation
{
  FORCE_STACK_ALLOCATION();

public :

  CATAfrDisableDashboardPageCreation();
  ~CATAfrDisableDashboardPageCreation();
};

/**
 * Notification class to hold the argument when the event CONTEXT_ID_CHANGED is
 * sent.
 *
 * The argument contains the name of the new context (i.e. tab page) that is
 * currently being activated. When the last tab page is closed, _contextId is
 * set to empty string.
 */
class ExportedByCATAfrFoundation CATContextIdChangedNotif : public CATNotification
{
  CATDeclareClass;
public:
  explicit CATContextIdChangedNotif(const CATString & i_id) : _contextId(i_id) {}
  virtual ~CATContextIdChangedNotif(){}

  const CATString & GetContextId() const { return _contextId; }

private:
  CATContextIdChangedNotif(const CATContextIdChangedNotif&);
  CATContextIdChangedNotif& operator=(const CATContextIdChangedNotif &);

  CATString _contextId;
};

#endif
