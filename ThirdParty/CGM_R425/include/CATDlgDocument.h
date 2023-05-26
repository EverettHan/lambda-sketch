#ifndef CATDLGDOCUMENT_H
#define CATDLGDOCUMENT_H


// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */



#include "CATDlgWindow.h"
#include "CATBoolean.h"

class CATDlgBarMenu;
class l_CATDlgDocument;
class CATDlgContextualMenu;
class CATDlgStatusBar;
class CATInteractiveApplication;
class CATDlgDialog;
class CATDlgToolBar;

#ifndef CATDlgDocument_ADD
/** @nodoc */
#define CATDlgDocument_ADD
#endif

#ifndef CATDlgDocument_LateADD
/** @nodoc */
#define CATDlgDocument_LateADD
#endif

/**
 * Class to create an application main window.
 * <b>Role</b>: An application window is the main application 
 * window. It can contain one or several dialog windows, each 
 * containing a document's presentation, depending on the 
 * application is SDI (Single Document Interface) or MDI 
 * (Multiple Document Interface), and other dialog windows, 
 * such as the Macro window. In addition, it usually features a 
 * menu bar, toolbars, and a status bar. 
 * Toolbars can be docked to its frame sides, or undocked as 
 * independent dialog boxes.  
 * Use the application window as a base class when you want to 
 * create the window for a new application.
 * The parent of an instance of a class that derives from 
 * CATDlgDocument must be an instance of a class that derives 
 * from CATInteractiveApplication.
 * <p>
 * <b>note:</b> This class is called the Dialog Document.
 * So that not to make any confusion with the memory
 * documents that are edited during a CATIA session, we
 * will call below these last ones "internalized document".  
 */


//--------------------------------------------------------------------------
class ExportedByDI0PANV2 CATDlgDocument : public CATDlgWindow
{

//--------------------------------------------------------------------------
 public:


/**
 * Constructs an application main window.
 * <b>Role</b>: Constructs an application window. 
 * Regarding the use of this method, you have to know that, 
 * to create the main window for your application, you  
 * must derive the current class. 
 * @param iParent
 *   The parent of the CATDlgDocument.
 * @param iDialogObjectName
 *   The dialog object name. 
 * @param iStyle
 *   The application window style.
 *   <br><b>Legal values</b>: <tt>NULL (default)</tt> for a SDI
 *   application (see above), or <tt>CATDlgWndFrameMDI</tt> 
 *   the application must be MDI (see above).
 */
        CATDlgDocument( CATInteractiveApplication *iParent, 
                        const CATString& iDialogObjectName, 
                        CATDlgStyle iStyle=NULL);

        virtual ~CATDlgDocument();

//      Get menu, bar objects
/**
 * Get the contextual menu, if there is one, for the current 
 * main window.
 * @return
 *   The contextual menu.
 *   <b>Legal values</b>: <tt>NULL</tt>: if the current
 *   main window has no contextual menu, <tt>Other</tt> 
 *   otherwise.
 */
        CATDlgContextualMenu* GetContextualMenu();
/**
 * Get the menu bar, if there is one, for the current 
 * main window.
 * @return
 *   The menu bar for this main window.
 *   <b>Legal values</b>: <tt>NULL</tt>: if the current
 *   main window has no menu bar, <tt>Other</tt> otherwise.
 */
        CATDlgBarMenu*        GetMenuBar();
/**
 * Get the status bar, if there is one, of the current main 
 * window.
 * @return
 *   Status bar dialog object.
 */

        CATDlgStatusBar*      GetStatusBar();

//      Multiple document interface methods
/**
 * Specifies if the current main window is MDI or SDI.
 * @return
 *   Boolean specifying if the current main window is MDI or SDI.
 *   <br><b>Legal values</b>: <tt>1</tt>: if the current main
 *   window is MDI, or <tt>0</tt>: otherwise. 
 */
        int IsMDI();
/**
 * Activates an internalized document child window.
 * This method relates only to MDI-style CATDlgDocument
 * windows.
 * @param iChildWindow
 *   The internalized document child window to activate. 
 */

        void MDIActivate(CATDlgDialog* iChildWindow);
/**
 * Get the current internalized document active window.
 * This method relates only to MDI-style CATDlgDocument
 * windows.
 * @return
 *   The internalized document child window currently activated. 
 */

        CATDlgDialog* MDIGetActive();
/**
 * Arranges spacially the icons of the internalized documents
 * child windows which are currently minimized.
 * This method must be called by an application
 * when the current main window has been resized.
 */
        void MDIIconArrange();
/**
 * Maximizes spacially the size of an internalized document child 
 * window.
 * This method relates only to MDI-style CATDlgDocument
 * windows.
 * @param iChildWindow
 *   The internalized document child window to maximize
 *   spacially. 
 */
        void MDIMaximize(CATDlgDialog* iChildWindow);

/**
 * Minimizes spacially the size of an internalized document child 
 * window.
 * This method relates only to MDI-style CATDlgDocument
 * windows.
 * @param iChildWindow
 *   The internalized document child window to minimize
 *   spacially. 
 */

        void MDIMinimize(CATDlgDialog* dlg);
/**
 * Activates the internalized document child window which just
 * follows the currently active internalized document child 
 * window.
 * This method relates only to MDI-style CATDlgDocument
 * windows.
 */


        void MDINext();
/**
 * Activates the internalized document child window which just
 * preceeds the currently active internalized document child 
 * window.
 * This method relates only to MDI-style CATDlgDocument
 * windows.
 */


        void MDIPrevious();
/**
 * Restores spacially the size of an internalized document child 
 * window previously maximized or minimized spacially.
 * This method relates only to MDI-style CATDlgDocument
 * windows.
 * @param iChildWindow
 *   The internalized document child window to restore
 *   spacially. 
 */

        void MDIRestore(CATDlgDialog* iChildWindow);
/**
 * Shows spacially the current main window internalized document 
 * child windows under a tiled form. 
 * This method relates only to MDI-style CATDlgDocument
 * windows.
 * @param iTilingType
 *   The tiling type. 
 *   <br><b>Legal values</b>: 
 *   <tt>CATDlgTileHorizontal (default)</tt> for an horizontal
 *   tiling, <tt>CATDlgTileVertical</tt> for a vertical
 *   tiling, <tt>CATDlgTileSkipHidden</tt> to specify that
 *   the tiling process must not impact the minimized 
 *   internalized document child windows. This last option
 *   may be associated to one of the two previous ones,
 *   using a logical or.
 */

        void MDITile(int iTilingType=CATDlgTileHorizontal); 
/**
 * Shows spacially the current main window internalized document 
 * child windows under a cascade form. 
 * This method relates only to MDI-style CATDlgDocument
 * windows.
 * @param iCascadeType
 *   The cascade type. 
 *   <br><b>Legal values</b>: 
 *   <tt>0 (default)</tt> if the cascade process must impact the
 *   minimized internalized document child windows, 
 *   <tt>CATDlgTileSkipHidden</tt> to specify that
 *   the cascade process must not impact the minimized 
 *   internalized document child windows.
 */

        void MDICascade(int iCascadeType=0);  

//      get event notifications
/**
 * Returns the CATDlgDroppedFileNotification event notification.
 * It is sent whenever the end user drops an object in a 
 * document window.
 */
        CATNotification *GetDroppedFileNotification() const;
/**
 * Returns the CATDlgDSLogoNotification event notification.
 * It is sent whenever the end user select the CATIA logo
 * which is displayed in the bottom-right corner of the
 * application window. In CATIA, this event notification
 * activates the in-line documentation process.
 */
        CATNotification *GetDSLogoNotification() const;
/**
 * Returns the CATDlgEscapeNotification event notification.
 * It is sent whenever the end user press the escape
 * key. In CATIA, this event notification, when a command is
 * being used, ends the command. 
 */
        CATNotification *GetEscapeNotification() const;

/**
 * @nodoc
 * Returns the CATDlgSessionNotification event notification.
 * It is sent whenever the system sends a power or session
 * management event to CATIA.
 */
        CATNotification *GetSessionNotification () const;
/**
 * Specify whether the window (and its child windows) accept drop of files
 * under Windows.
 * If this method is not called, default is TRUE.
 * To be taken into account, this method must be called just after object allocation.   
 * @param iAccept
 * <br>
 * <b>Legal values:</b>
 * <dl>
 * <dt><tt>TRUE</tt><dd> the window accepts drop of files under Windows. </dd></dt>
 * <dt><tt>FALSE</tt><dd> the window does not accept drop of files under Windows. </dd></dt>
 * </dl>
 */
        void AcceptFileDrop(CATBoolean iAccept);

//      get internal object
/**
 * @nodoc 
 * Gets the internal object.
 */
        virtual l_CATDialog* GetLetterObject();

/**
 * @nodoc 
 * Resets the internal object.
 */
        virtual void ResetLetterObject();

/**
 * @nodoc
 * Requests the ClassName, IsA, and IsAKindOf methods to be created.
 */
        CATDeclareClass ;

        CATDeclareCBEvent(WindowCreated);
#if defined(DRIVER_WINDOWS) && !defined(DRIVER_MAINWIN)

        // get OLE flags
/**
 * @nodoc 
 */
        BOOL IsOleModeSet() const;
/**
 * @nodoc 
 */
        BOOL IsOleInPlace() const;

        // set OLE flags
        // SetOleStyle                Set/Unset CATDlgWndOlexxx flags
/**
 * @nodoc 
 */
        void    SetOleStyle(CATDlgStyle);

        // negociates OLE in-place toolbars space
/**
 * @nodoc 
 */
        virtual BOOL RenegociateTBSpace(const BORDERWIDTHS &);

        // a surcharger
/**
 * @nodoc 
 */
        virtual BOOL CanReparentToolBars();

        // a surcharger
/**
 * @nodoc 
 */
        virtual BOOL CanReparentViewer ();
/**
 * @nodoc 
 */
        virtual BOOL BuildOleSharedMenuBar();
/**
 * @nodoc 
 */
        virtual void DestroyOleSharedMenuBar();  

#endif//_WINDOWS_SOURCE AND NOT DRIVER_MAINWIN
//--------------------------------------------------------------------------
 private:

//      address of internal object.
/**
 * @nodoc 
 */
        l_CATDlgDocument *_frameDocumentWindow;    

/** @nodoc */
        CATDlgDocument_ADD
};

/** @nodoc */
CATDlgDocument_LateADD

#endif
