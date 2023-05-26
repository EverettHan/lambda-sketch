//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2012/02/13
//===================================================================
// CATAfrActionBarViewerManager.cpp
// Header definition of class CATAfrActionBarViewerManager
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/02/13 Creation: qf1
//===================================================================

#ifndef CATAfrActionBarViewerManager_H
#define CATAfrActionBarViewerManager_H

#include "CATAfrFoundation.h"
#include "CATSysBoolean.h"
#include "CATBaseUnknown_WR.h"
#include "CATEventSubscriber.h"
#include "CATEventSubscriberTypedefs.h"

class CATViewer;
class CATVizViewer;
class CATSYPEvent;
class CATSYPEventFactory;
class CATSYPEventHandler;
class CATSYPEventHandlersSupport;
class CATDlgFrame;
class CATFrmWindow;

//-----------------------------------------------------------------------


/**
 * Manager for the ActionBar viewer.
 * @code
 * // --- RETRIEVE THE MANAGER -------------------
 * CATAfrActionBarViewerManager* pActionBarViewerManager = CATAfrActionBarViewerManager::Get();
 * if(pActionBarViewerManager)
 * {
 *   (...)
 * }
 * 
 * // --- ONLY FOR ACTION BAR -------------------
 * CATAfrActionBarViewerManager* pActionBarViewerManager = CATAfrActionBarViewerManager::Get();
 * if(pActionBarViewerManager)
 * {
 *   CHECK_TRUE(AddCATSYPWRefMethEventHandler(pActionBarViewerManager,
 *                                            CATAfrActionBarViewerManager::ActionBarViewerChanged(),
 *                                            this,
 *                                            &XXXXXX::OnActionBarViewerChanged));
 * }
 * (...)
 * void XXXXXX::OnActionBarViewerChanged(CATBaseUnknown* i_pSender, CATSYPEventArgs* ipArgs)
 * {
 *   CATAfrActionBarViewerManager* pActionBarViewerManager = CAT_DYNAMIC_CAST(CATAfrActionBarViewerManager, i_pSender);
 *   CHECK_POINTER_RET(pActionBarViewerManager);
 *   // Retrieve the AB VizViewer with : pActionBarViewerManager->GetActionBarVizViewer();
 * }
 * @endcode
 */
class ExportedByCATAfrFoundation CATAfrActionBarViewerManager : public CATEventSubscriber
{
  CATDeclareClass;

  friend class CATAfrToolLineToolbar;
  friend class SWXUiCommandManagerPanelComponent;
  friend class AfrActionBarViewerManager;
  friend class AfrWindowManagerVIDMDI;

public:
  //void NeedToExtractActionBar(CATBoolean i_needToExtract, CATDlgFrame* i_pDlgFrameForActionBar = NULL);
  //void NeedToHideActionBar(CATBoolean i_needTohide);
  CATVizViewer* GetActionBarVizViewer();
  static int GetActionBarHeight();
  /**
   * Get the @c ActionBarViewerChanged event.
   * 
   * The @c ActionBarViewerChanged is emitted when the ActionBar needs to insert a new viewer.
   * Reasons can be :
   * - change of workbench
   * - it needs to be extracted
   * - it needs to be hidden
   * Use GetActionBarViewer to retrieve it.
   * 
   * @par EventProperties
   *   - Name: @c "ActionBarViewerChanged"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   * 
   * @see NeedToExtractActionBar
   * @see NeedToHideActionBar
   */
  static CATSYPEvent* ActionBarViewerChanged();
  int AddHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents = 0);
  int RemoveHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler);
  
private: // reserved to friend classes
  /**
   * Retrieves the ActionBarViewerManager singleton.
   * If you call it before CATFrmLayout::GetCurrentLayout() is not NULL,
   * it will return NULL (the singleton has not been instantiated).
   */
  static CATAfrActionBarViewerManager* Get();

private: // internal methods
  CATAfrActionBarViewerManager();
  ~CATAfrActionBarViewerManager();
  void InternalUpdateViewer();
  void InternalHideActionBar();
  void InternalExtractActionBar();
  void InternalInsertActionBar();
  void InternalSetActionBarViewer(CATViewer* i_viewer);
  CATFrmWindow* InternalGetActiveWindow();
  void OnViewerActivated(CATCallbackEvent iEvent, void *iPublisher, CATNotification *ipNotification, CATSubscriberData iData, CATCallback iCallbackId);
  void OnViewerUpdated(CATCallbackEvent iEvent, void *iPublisher, CATNotification *ipNotification, CATSubscriberData iData, CATCallback iCallbackId);
  void OnWindowDeleted(CATCallbackEvent iEvent, void *iPublisher, CATNotification *ipNotification, CATSubscriberData iData, CATCallback iCallbackId);
  CATViewer* InternalCreateOrGetActionBarExtractedViewer();
  void SetFullscreenForDesignMode(CATBoolean i_fullscreenForDesignMode);
  CATBoolean GetFullscreenForDesignMode();
  void SetSynchroFullscreen(CATBoolean i_synchroFullScreen);
  CATBoolean GetSynchroFullscreen();
  CATBoolean IsCurrentViewerInFullScreen() const;

private: // internal members
  CATBoolean _isCurrentViewerInFullScreen;
  CATBoolean _isFullScreenForDesignMode;
  CATBoolean _isSynchroFullScreen;
  CATBaseUnknown_WR _wrActionBarLastViewer;
  CATCallback _viewerUpdatedCB;
  static CATAfrActionBarViewerManager* actionBarViewerManagerSingleton;

private: // event sending management
  static CATSYPEventFactory* GetEventFactory();
  static CATSYPEventFactory* _pEventFactory;
  CATSYPEventHandlersSupport* GetEventHandlersSupport();
  CATSYPEventHandlersSupport* _pSupport;

};

//-----------------------------------------------------------------------

#endif
