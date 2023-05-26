#ifndef CATFrmAuxWindow_H
#define CATFrmAuxWindow_H

// COPYRIGHT DASSAULT SYSTEMES 2005
//------------------------------------------------------------------------------
// Abstract: Working area to visualize application data:
//           geometries, graphs, ...
//
//------------------------------------------------------------------------------
// Usage:    A CATFrmAuxWindow is a rectanglar subarea of an application frame.
//           It allows to display and manipulate application data.
//           It has always a ApplicationWindow as Parent.
// 
//           This class will be derived by application to display in Windows
//           of the ApplicationFrame the application data.   
//------------------------------------------------------------------------------
// Inheritance: CATDlgDialog (Dialog framework)
//------------------------------------------------------------------------------
// Main methods:    
//
//           AddCommand
//           ExecuteCommand
//           GetViewer
//           GetEditor
//       
//------------------------------------------------------------------------------
// Events:    
//	       AUXWINDOW_ACTIVATED    (from uncurrent window to current window)
//	       AUXWINDOW_DEACTIVATED  (from current window to uncurrent window)
//	       AUXWINDOW_CREATED
//	       AUXWINDOW_DELETED
//         VIEWER_SELECTED    (MouseButton1 Down on a Viewer) (sender is viewer)
//         VIEWER_ACTIVATED   (The CurrentViewer has been changed) (sender is viewer)
//         VIEWPOINT_CHANGED  (The main viewpoint of the currentViewer has been changed) (sender is window)
//         VIEWER_SHOW        (the viewer is seen in show space)
//         VIEWER_NO_SHOW     (the viewer is seen in noshow space)
//------------------------------------------------------------------------------

#include "CATAfrFoundation.h"
#include "CATDlgInclude.h"
#include "CATDlgDialog.h"
#include "CATFrmWindow.h"

class CATFrmLayout;
class CATDlgFrame;
class CATViewer ;
class CATFrmEditor ;

/** 
 * @nodoc
 * Defines the MDI state of the window.
 * @param MinimizeWindow
 *  The <tt>CATFrmAuxWindow</tt> is minimized.
 * @param MaximizeWindow
 *  The <tt>CATFrmAuxWindow</tt> is maximized.
 * @param RestoredWindow
 *  The <tt>CATFrmAuxWindow</tt> is restored.
 * @see CATFrmAuxWindow#GetWindowMDIState
 */
//enum  CATFrmAuxWindowState {MinimizeWindow, RestoredWindow, MaximizeWindow};

/**
 * Class to provid a working area to visualize application data.
 * <b>Role</b>: Allows to display and manipulate application data.
 * This basic class will be derived by application to display 
 * the application's specific data. See also: @href CATFrmNavigGraphicWindow, 
 * @href CATFrmGraphAnd3DWindow and @href CATFrmGraphAnd2DWindow.
 */
class ExportedByCATAfrFoundation CATFrmAuxWindow: public CATDlgDialog
{
   friend class CATFrmWindow;

   DeclareResource(CATFrmAuxWindow, CATDlgDialog) ;

   public:

      /**
      * Event sent when the window is activated.
      */
      CATDeclareCBEvent(AUXWINDOW_ACTIVATED);
      
      /**
      * Event sent when the window is deactivated.
      */
      CATDeclareCBEvent(AUXWINDOW_DEACTIVATED);
      
      /** @nodoc */
      CATDeclareCBEvent(AUXWINDOW_CREATED);
      /**
      * Event sent when the window is deleted.
      */
      /** @nodoc */
      CATDeclareCBEvent(AUXWINDOW_DELETED);
      /** @nodoc do not use */
      CATDeclareCBEvent(AUXWINDOW_MOVED);
      /** @nodoc do not use */
      CATDeclareCBEvent(AUXWINDOW_RESIZED);
      /** @nodoc do not use */
      CATDeclareCBEvent(AUXWINDOW_MAXIMIZED);
      /** @nodoc do not use */
      CATDeclareCBEvent(AUXWINDOW_MINIMIZED);
      /** @nodoc do not use */
      CATDeclareCBEvent(AUXWINDOW_RESTORED);
      /** @nodoc */
      CATDeclareCBEvent(VIEWER_SELECTED);
      /** @nodoc */
      CATDeclareCBEvent(VIEWER_ACTIVATED);
      /** @nodoc */
      CATDeclareCBEvent(VIEWPOINT_CHANGED);
      
      CATDeclareClass ;
   
//------------------------------------------------------------------------------


      // Constructor
      // -----------
      /**
      * Constructs a CATFrmAuxWindow.
      * @param iMainWindow 
      *   The parent window.
      * @param iAuxWindowName 
      *   The title of aux window.
      */
      CATFrmAuxWindow(CATFrmWindow * iMainWindow, const CATUnicodeString & iAuxWindowName = "");
      
      // Duplicator
      // ----------
      /**
      * Creates and returns a new window of the same document.
      */
      virtual CATFrmAuxWindow * DuplicateWindow();
      
      // Destructor
      // ----------
      virtual ~CATFrmAuxWindow();
      /**
      * Close the window.
      */
      virtual void            DeleteWindow();
      
      // Execute a View menu item command
      // --------------------------------
      /** @nodoc */
      virtual HRESULT  ExecuteCommand(const CATString & commandId);
      
      // Get current viewer
      // ------------------
      /**
      * Returns the frame in wich the viewer will be attached.
      */
      virtual CATDlgFrame     * GetViewerFrame();

      /** @nodoc */
      virtual void              SetViewerFrame(CATDlgFrame *);
      
      /**
      * Returns the viewer created in the window.
      */
      virtual CATViewer       * GetViewer();
      /**
      * Changes the current viewer of the window.
      * @param iViewer 
      *   The new current viewer.
      */
      virtual void              SetViewer(CATViewer * iViewer);
      
      /** 
      * @nodoc
      * Returns the MDI state of the window.
      * <br><b>Caution</b>:Never try to change the MDI status of the window thanks to
      * the Dialog Framework. You can only know the status of a <tt>CATFrmAuxWindow</tt>, and 
      * you can't change its state.
      */
      CATFrmWindowState GetWindowMDIState();                  // MinimizeWindow/RestoredWindow
      
      /**
      * Changes the active auxwindow.
      */
      virtual void              Activate();

      /**
      * Returns the main window.
      */
      virtual CATFrmWindow *  GetMainWindow();

   protected:
    
      //Internal use only
      //-----------------
      /** @nodoc */
      void	             SetWindowMDIState(CATFrmWindowState); //(MinimizeWindow/RestoredWindow)
      
      /** @nodoc */
      virtual void       InitDuplicatedWindow(CATFrmAuxWindow * ipDupWindow);
    
   private:
    
      CATFrmWindow       *_mainWindow;
      CATFrmLayout       *_currentLayout;
      CATFrmEditor       *_currentEditor;
      CATFrmWindowState   _currentMDIState;
      CATViewer          *_currentViewer;
      
      CATDlgFrame        *_viewerFrame;
      
      void               AddCB();
      void               RemoveCB();
      void               Deactivate();
      
      // Call back
      CATCallbackManager * _callbackManager;
      
      void SetActiveCB           (CATCallbackEvent event, void *, CATNotification * notif, CATSubscriberData data, CATCallback);
      void ChangeMainViewpointCB (CATCallbackEvent event, void *, CATNotification * notif, CATSubscriberData data, CATCallback);
      void WindowCB              (CATCallbackEvent event, void *, CATNotification * notif, CATSubscriberData data, CATCallback);
      
      void MDICB                 (CATCommand*, CATNotification *, CATCommandClientData);
}; 
#endif
