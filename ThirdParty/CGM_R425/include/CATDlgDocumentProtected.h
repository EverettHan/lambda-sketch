#ifndef CATDLGDOCUMENTPROTECTED_H
#define CATDLGDOCUMENTPROTECTED_H
// DBE Nov 2004 for Web Viewer use
#include "DI0PANV2.h"
#include "CATBoolean.h"
#include "CATDlgDocument.h"

class CATNotification;
class CATBaseUnknown;
class CATDlgDialog;

ExportedByDI0PANV2 void CATDlgDocumentHideToolBars(CATDlgDocument* win, CATBoolean b);

#ifdef DRIVER_WINDOWS
extern "C" ExportedByDI0PANV2 void AttachToExternalWindow(HWND hWnd);
#endif

#ifdef DRIVER_MOTIF
#include <X11/Xlib.h>
extern "C" void AttachToExternalWindow(Window w);
#endif

extern "C" ExportedByDI0PANV2 void DetachFromExternalWindow();

class  ExportedByDI0PANV2 CATDlgDocumentProtected
{
  public:
    static void ChangeToolBarContext(CATDlgDocument* win, const CATString& context);
    static void ChangeToolBarContext(CATDlgDocument* win, const CATString& context, const CATListOfCATString& contextToolbarList);
    static void ChangeToolBarContext(CATDlgDocument* win, const CATString& context, CATBaseUnknown** contextToolbarList, const int contextToolbarListSize);
    static CATNotification* GetDocToolbarConfigChangedNotification(CATDlgDocument* win);

    static CATNotification* GetKeyboardEarlyNotification(CATDlgDocument* win);
    static CATUnicodeString GetCurrentKeyboardCombination(CATDlgDocument* win);
    static void SetKeyboardEventConsumedStatus(CATDlgDocument* win, CATBoolean b);

 /**
     * This event is sent when a menu is displayed.
     * It is used in particular by CID to close opened modal popup
     */
    CATDeclareCBEvent(MenuSelected);
 /**
 * Declares the ToolbarConfigurationChanged event.
 * <br><b>Role</b>
 * This event is sent by the @href CATDlgDocument whenever a toolbar belonging to the CATDlgDocument 
 * is created, deleted, shown, hidden, docked or undocked or when the CATDlgDocument is resised.
 * This event matches specific needs and should not be called by most applications.
 */
    CATDeclareCBEvent(ToolbarConfigurationChanged);

 /**
 * Declares the ActiveMDIChildWindowChanged event.
 * <br><b>Role</b>
 * This event is sent through DispatchCallbacks by the @href CATDlgDocument when :
 *  - it has the CATDlgWndFrameMDI style
 *  - and the active MDI child window changes.
 */
    CATDeclareCBEvent(ActiveMDIChildWindowChanged);

 /**
 * Declares the HybridActiveWindowChanged event.
 * <br><b>Role</b>
 * This event is sent through DispatchCallbacks by the @href CATDlgDocument whenever the hybrid active window changes.
 * Please ref to GetHybridActiveWindow method for a definition of the notion of the hybrid active window 
 */
    CATDeclareCBEvent(HybridActiveWindowChanged);

// Ajout ERS proto PLM Bar VID
 /**
 * Declares the BackgroundColorChanged event.
 * <br><b>Role</b>
 * This event is sent through DispatchCallbacks by the @href CATDlgDocument whenever the viewer background color of the active and maximized window changes.
 * Please ref to GetSpecialBackgroundColor method for a definition of the notion of the background color 
 */
    CATDeclareCBEvent(BackgroundColorChanged);

/**
 * Gets the current hybrid active window, if there is one.
 * @return
 *   The hybrid active window.
 *   <b>Legal values</b>: <tt>NULL</tt>: if the 
 *   main window does not currently include the active window, <tt>Other</tt> 
 *   otherwise.
 *   
 *   If not NULL, the value returned is AddRef'd and must be Released once the caller does not need it any longer.
 *
 *   Hybrid active window definition :
 *   - In the case of a CATDlgDocument SDI (that is, without the CATDlgWndFrameMDI style ).
 *
 *     If the desktop active window is a CATDlgDocument window or a CATDlgDialog window
 *     (necessarily without the CATDlgWndChildMDI style  in this case) then the hybrid active window is this window.
 *     Otherwise the hybrid active window does not exist and the pointer returned is NULL. 

 *   - In the case of a CATDlgDocument MDI (that is, with the CATDlgWndFrameMDI style).
 *
 *     If the desktop active window is a CATDlgDialog window without the CATDlgWndChildMDI style 
 *      then the hybrid active window is this window.
 *     If the desktop active window is the CATDlgWndFrameMDI CATDlgDocument window,  
 *      then the hybrid active window is the current CATDlgWndChildMDI CATDlgDialog window if it exists. 
 *     In all the other cases, the hybrid active window does not exist and the pointer returned is NULL. 
         
 */
    static CATDlgWindow* GetHybridActiveWindow(CATDlgDocument* win);

    static void ResetIconBoxToolBars(CATDlgDocument* win);

  /**
   * Deactivates or reactivates "focus theft" by editors with CATDlgEdtStealFocus style (generally the "power input" editor in CATIA)
   * 
   * @param win
   *  The dialog object.
   * @param iActive
   *  FALSE  : focus theft will no longer occur 
   *  TRUE   : focus theft is reactivated (if CATDlgEdtStealFocus style editor does exist in the hierarchy under the CATDlgDocument)
   */
    static void SetFocusTheftActive(CATDlgDocument* win, CATBoolean b);
    static CATBoolean IsFocusTheftActive(CATDlgDocument* win);

  /**
   * Deactivates or reactivates "Del" key as an accelerator
   * 
   * @param win
   *  The dialog object.
   * @param iActive
   *  FALSE  : if "Del" is defined as an accelerator for a CATDialog object under the CATDlgDocument, this role is deactivated
   *  TRUE   : if "Del" is defined as an accelerator for a CATDialog object under the CATDlgDocument, this role is reactivated
   */
    static void SetDelAccelActive(CATDlgDocument* win, CATBoolean iActive);
    static CATBoolean IsDelAccelActive(CATDlgDocument* win);

  /**
   * Deactivates or reactivates a key string as an accelerator
   * 
   * @param win
   *  The dialog object.
   * @param iKey
   *  The accelerator key
   * @param iActive
   *  FALSE  : if iKey is defined as an accelerator for a CATDialog object under the CATDlgDocument, this role is deactivated
   *  TRUE   : if iKey is defined as an accelerator for a CATDialog object under the CATDlgDocument, this role is reactivated
   */
    static void SetAccelActive(CATDlgDocument* win, const CATUnicodeString& iKey, CATBoolean iActive);

/**
   * Deactivates or reactivates all the accelerators corresponding to one character key without modifier
   * 
   * @param win
   *  The dialog object.
   * @param iActive
   *  FALSE  : all the accelerators corresponding to one character key without modifier get deactivated
   *  TRUE   : all the accelerators corresponding to one character key without modifier get reactivated
   */
    static void SetMonoCharAccelActive(CATDlgDocument* win, CATBoolean iActive);

  /**
   * Background color
   * 
   * @param win
   *  The dialog object.
   * @param r,g,b
   *  The components of the color
   * @return
   *  FALSE  : No special color set, returning the default background color.
   *  TRUE   : A special color was set, returning it.
   */
    static CATBoolean GetSpecialBackgroundColor(CATDlgDocument* win, unsigned char& r, unsigned char& g, unsigned char& b);
 /**
  * Activates an internalized document child window.
  * This method relates only to MDI-style CATDlgDocument windows.
  * @param win
  *  The dialog object.
  * @param iChildWindow
  *   The internalized document child window to activate. 
  *
  * The processing is asynchronous, that is, done on the next OnIdle or the next call to UpdateDisplay.
  * That makes the difference with CATDlgDocument::MDIACtivate method. 
  * For compatibility reasons, that, unfortunately, cannot be the default. 
  */
   static void AsynchronousMDIActivate(CATDlgDocument* win, CATDlgDialog* iChildWindow);

   static CATBoolean IsTabbedMDI (CATDlgDocument* win);
   static void MDITabNewGroup (CATDlgDocument* win, CATBoolean bVert=TRUE);
   static CATBoolean IsNewTabGroupAuthorized (CATDlgDocument* win, CATBoolean bVert);

 /**
  * ExtendedTile
  *
  * - with classical MDI, perfoms a tile layout on a list of MDI child windows. The other MDI child windows are minimized.
  * - with MDI Tab page implementation (available under CATDlgTabbedMDI variable on Windows platform as of R2013x)
  *   - if needed, moves all MDI child windows into one group.
  *   - all the MDI child windows belonging to the list but the first window are moved to a new individual tab group.
  * 
  * In both cases, the current active MDI child window remains the same.
  * It is recommended to set it as the first element of the list.
  * 
  * @param win
  *  The CATDlgDocument object on which this static method is to operate.
  * @param windowList
  *   The list of MDI child windows which are going to take part in the tiling operation.
  * @param count
  *   The size of the list
  * @param type
  *   The type of tiling
  *  CATDlgTileVertical (default)  
  *  CATDlgTileHorizontal (default)
  */

   static void ExtendedTile(CATDlgDocument* win, CATDlgDialog* windowList[], int count, int type = CATDlgTileVertical);
   static void GlobalTile(CATDlgDocument* win);
   static void MoveChildrenInOneGroup (CATDlgDocument* win);

   // DBE Sep2012
   static void SetFreeResize(CATDlgDocument* iWin); // for SDI style only

   // @deprecated R422 Use SetCompassBarWidthEx
   static void SetCompassBarWidth(CATDlgDocument * iDocument, int iCompassBarWidth);
   // @deprecated R422 Use SetCompassBarHeightEx
   static void SetCompassBarHeight(CATDlgDocument * iDocument, int iCompassBarHeight);
   // @deprecated R422 Use SetActionBarHeightEx
   static void SetActionBarHeight(CATDlgDocument * iDocument, int iActionBarHeight);

   /**
    * @param iAlreadyScaled
    * When FALSE, size must match a 100% display scaling, it will be automatically scaled according to current display scaling.
    * When TRUE, size must match the current display scaling, it won't be scaled.
    */
   static void SetCompassBarWidthEx(CATDlgDocument * iDocument, int iCompassBarWidth, CATBoolean iAlreadyScaled);
   static void SetCompassBarHeightEx(CATDlgDocument * iDocument, int iCompassBarHeight, CATBoolean iAlreadyScaled);
   static void SetActionBarHeightEx(CATDlgDocument * iDocument, int iActionBarHeight, CATBoolean iAlreadyScaled);

   static CATNotification* GetCreateNewTabGroupCapabilityChangedNotification(CATDlgDocument* win);

   static CATDlgDialog* UseHiddenMDITab(CATDlgDocument* win, CATBoolean b); // DBE Mar 2013

   static void ActivateKeyboardAccelerators(CATDlgDocument* win, CATBoolean b); // DBE Jun 2014 for "Creative experience"
   static CATBoolean GetKeyboardAcceleratorsActivation(CATDlgDocument* win); // DBE July 2014 

   static CATDialog* GetCurrentContextualMenuOwner(CATDlgDocument* win); // DBE Nov 2015 
};
#endif
