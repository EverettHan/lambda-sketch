#ifndef CATIAfrWindowManager_H
#define CATIAfrWindowManager_H

// COPYRIGHT DASSAULT SYSTEMES 2014/01/17

#include "CATAfrFoundation.h"
#include "CATAfrSnapAlignment.h"
#include "CATListOfCATFrmWindow.h"

//---------------------------------------------------------------------- Dialog
#include "CATDlgUtility.h"

#include "CATEventSubscriber.h"
#include "CATString.h"
#include "CATBoolean.h"

class CATViewer;
class CATDialog;
class CATFrmWindow;
class CATVizViewer;
class CATISYPIntrospectable_var;

/**
 * This interface allow to manage FrmWindow in CID_FRAME project.
 */
class ExportedByCATAfrFoundation CATIAfrWindowManager : public CATEventSubscriber
{

public:

  /** Get the singleton instance. Doesn't build it*/
  static CATIAfrWindowManager* GetInstance();

  /** @return the container of the top bar*/
  virtual CATBaseUnknown_var GetTopBarContainer() = 0;

  /** @return the container of the action bar*/
  virtual CATBaseUnknown* GetCtlForAB(CATFrmWindow* i_pWindow) = 0;

  /** 
   * [ConnectedDashboard] As of today, we can't connect directly the CEF context to the 3DDashboard platform; 
   * This call display a dialog box that allow to do this connection manually.
   */
  virtual void ConnectToDashboard() = 0;

  /** @return TRUE if the current FrmWindow is located in the active tab*/
  virtual CATBoolean IsCurrentWindowIsInActiveTab();

  virtual CATViewer * GetMainViewer() const ;

  virtual void InsertActionBarInView(CATFrmWindow * i_pWindow, const CATISYPIntrospectable_var & i_spABView) = 0;

  virtual void SetVisibilityAndDimensions(unsigned long uState,DRECT dimension) = 0; 

  /**
   * Activate the tab associated to the given identifier.
   *
   * @param i_pTabId the identifier of the tab to activate. This identifier
   * corresponds to the adress of the tab to activate (i.e.
   * CATVidCtlDashboardPage object).
   */
  virtual void ActivateTab(CATBaseUnknown * i_pTabId) = 0;

  /**
   * Flag indicating whether a CATFrmWindow is currently in the process
   * to be managed by VID windows manager.
   *
   * @return positive integer when a CATFrmWindow is currently in the process
   * to be managed by VID windows manager, 0 otherwise.
   */
  virtual int IsCurrentlyManagingWindow() = 0;

  /**
   * Returns the CATFrmWindow corresponding to the given viewer.
   */
  virtual CATFrmWindow * GetFrmWindowFromViewer(CATVizViewer* i_pVizViewer) = 0;

  /**
   * Moves the given window to the given side of the target window.
   * The two windows will be contained in the same dashboard page.
   */
  virtual void MoveWindowTo(CATFrmWindow * i_pWindowToMove, CATFrmWindow * i_pTargetWindow, CATAfrSnapAlignment i_snapAlignment) = 0;

  /**
  * Moves the given window into a new Tab.
  * Does nothing if the window is alone in its current Tab.
  */
  virtual void MoveIntoNewTab(CATFrmWindow * i_pWindowToMove) = 0;


  /**
   * Specifies whether the dashboard page containing the given window is maximized or not.
   */
  virtual void SetDashboardPageMaximizedState(CATFrmWindow * i_pWindow, CATBoolean i_maximizedState) = 0;

  /**
   * Get the maximized state of the given window.
   *
   * @param i_pWindow the CATFrmWindow object to test whether it is maximized
   * or not.
   * @param o_maximizedState the maximized state of i_pWindow.
   */
  virtual void GetDashboardPageMaximizedState(CATFrmWindow * i_pWindow, CATBoolean & o_maximizedState) = 0;

  /**
   * Disables the automatic dashboard page creation when creating and activating a new CATFrmWindow.
   * Each call to the DisableDashboardPageCreation method must be balanced to a call to the 
   * EnableDashboardPageCreation method.
   */
  virtual void DisableDashboardPageCreation() = 0;

  /**
   * Enables the automatic dashboard page creation when creating and activating a new CATFrmWindow.
   * Each call to the DisableDashboardPageCreation method must be balanced to a call to the 
   * EnableDashboardPageCreation method.
   */
  virtual void EnableDashboardPageCreation() = 0;

  /**
   * Streams the current dashboard layout with the (optional) given window list to stream.
   * @param i_pWindowList the list of windows to stream. If NULL, all the windows present in the session will be streamed.
   * @param o_stream the returned stream.
   * @return S_OK in case of success, E_FAIL otherwise.
   */
  virtual HRESULT StreamDashboard(CATLISTP(CATFrmWindow) * i_pWindowList, CATUnicodeString& o_stream) = 0;

  /**
   * Restores the dashboard layout from the given stream and the given window list.
   * @param i_pWindowList the list of windows corresponding to the stream.
   * @param i_stream the stream containing the dashboard layout to restore.
   * @return S_OK in case of success, E_FAIL otherwise.
   */
  virtual HRESULT RestoreDashboard(const CATLISTP(CATFrmWindow)& i_windowList, const CATUnicodeString& i_stream) = 0;

  /**
   * Close the current dashboard page when it is empty (i.e. it doesn't have
   * any widget in it) and activate a non empty dashboard page if any.
   *
   * This lets the CATPLMExitCmd command to work correctly because it needs a
   * current editor in order to initialize when there is editors to close.
   */
  virtual void EnsureNonEmptyCurrentPage() = 0;

  /**
   * Flag indicating whether a dashboard page is currently in the process
   * to be deleted.
   *
   * @return positive integer when a dashboard page is currently in the process
   * to be deleted, 0 otherwise.
   */
  virtual int IsCurrentlyDeletingDashboardPage() = 0;

protected:

  /** Sets the instance of the manager. Called by inheriting implementation*/
  static void SetInstance(CATIAfrWindowManager* i_pInstance);

private:

  static CATIAfrWindowManager* _s_pInstance;
};

#endif
