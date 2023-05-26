#ifndef CATINTERACTIVEAPPLICATIONPROTECTED_H
#define CATINTERACTIVEAPPLICATIONPROTECTED_H

#include "DI0PANV2.h"
#include "CATString.h"
#include "CATDlgUtility.h"
#include "CATBoolean.h"
#include "CATInteractiveApplication.h"

#include "CATSysWidgetEx.h"

#ifdef DRIVER_MOTIF
#include <X11/Xlib.h>
#endif // DRIVER_MOTIF

class CATDlgWindow;
class l_CATDialog;

enum CATDlgIconSize { Small, Normal };

class ExportedByDI0PANV2 CATInteractiveApplicationProtected
{
  public :
  static CATInteractiveApplication* GetApplication(); // DBE Nov 2008. Request PA Bily
  static CATDlgWindow* GetMainWindow(CATInteractiveApplication* app); // DBE Nov 2008. Request PA Bily
  // DBE Feb 2005 for 3D for all use
  static void SetToolBarVerticalBackground(CATInteractiveApplication* app, const CATString& bmpName);
  static void SetToolBarHorizontalBackground(CATInteractiveApplication* app, const CATString& bmpName);
  static void SetToolBarRightBottomCorner(CATInteractiveApplication* app, const CATString& bmpName);
  // DBE May 2005 for SmartTeam Integration use
  static void HideSplashScreen(CATInteractiveApplication* app);
  // DBE Apr 2007 for 3D LIve Embed use
  // needs to be called in BeginApplication
  static void SetIconSize(CATInteractiveApplication* app, CATDlgIconSize size);
  // DBE Sep 2008 for MNT IR 629026 
  static void SetEarlyRemoveBusyCursorMode(CATInteractiveApplication* app , CATBoolean OnOff);
  // SCA Sep 2010 for Yun YWG
  static CATBoolean IsAContextualMenuDisplayed(CATInteractiveApplication* app);
  // DBE Nov 2013
  static void InitInASecondaryThread(CATInteractiveApplication* app);  
  // NCT Nov 2014
  static void SetDnDTouchMode(CATBoolean iFlag);
  // NCT May 2015
  static void SetDnDDragSource(l_CATDialog * iSource);

#if defined(DRIVER_WINDOWS)
  /**
   * Type of filter function expected by @ref
   * #SetWin32AcceleratorFilter.
   *
   * @param i_accelerator the shortcut that may be filtered. It is a
   * bitfield composed by combination of optional modifiers @c Meta,
   * @c Ctrl and @c DlgShift and an other constant @c UIK_XXX defined
   * in file <pre>CATDlgKeySym.h</pre>.
   *
   * @param i_hwnd the target window of the key-press event.
   *
   * @return @c !=0 if the execution of the accelerator potentially
   * associated with the pressed key should be disabled.
   *
   * @see #SetWin32AcceleratorFilter
   */
  typedef int (*Win32AcceleratorFilterFunc)(CATDlgAccelerator i_accelerator, HWND i_hwnd);
  /**
   * Set a function that filters for some standard key-press events
   * before the menu accelerators code is called.
   *
   * The filter function decides if either the accelerator code is
   * called for the event or if the event is directly propagated to
   * the focused component.
   *
   * When the accelerator code is called and if the event corresponds
   * to an existing accelerator, then the event won't be propagated to
   * the focused component. If no accelerator corresponds to the
   * event, then the event is still propagated to the focused
   * component.
   *
   * @par Need
   * The application may have set a standard shortcuts as a menu
   * accelerator (for example `Delete' key may be associated with a
   * menu item); in that case it would prevent any focusable component
   * from using the same key as a shortcut (for example in case of
   * `Delete' key to implement a function that deletes text in an
   * editor).
   *
   * @par
   * Using the filter function an infrastructure can decide to prevent
   * the interpretation of an event as an menu accelerator and instead
   * ensure that the event is propagated to the focused component.
   *
   * @par Filterable Shortcuts
   * Only a subset of events can be filtered, they are listed below.
   *
   * @par
   * Filterable shortcuts are all bits combinations of Ctrl/Alt/Shift
   * modifiers (represented as `Ctrl', `Meta' and `DlgShift' macros)
   * with the following keys (the preprocessor macros used are defined
   * in CATDlgKeySym.h):
   *   - Backspace: UIK_BackSpace
   *   - Insert: UIK_Insert
   *   - Clear: UIK_Clear
   *   - Delete: UIK_Delete
   *   - 0 .. 9 (not keypad): UIK_0 .. UIK_9
   *   - 0 .. 9 (keypad): UIK_KP_0 .. UIK_KP_9
   *   - a .. z: UIK_a .. UIK_z
   *   - Multiply (keypad): UIK_KP_Multiply
   *   - Add (keypad): UIK_KP_Add
   *   - Separator (keypad): UIK_KP_Separator
   *   - Substract (keypad): UIK_KP_Subtract
   *   - Decimal (keypad): UIK_KP_Decimal
   *   - Divide (keypad): UIK_KP_Divide
   *   - Space: UIK_space
   *   - Page Up: UIK_Prior
   *   - Page Down: UIK_Next
   *   - End: UIK_End
   *   - Home: UIK_Home
   *   - Left: UIK_Left
   *   - Up: UIK_Up
   *   - Right: UIK_Right
   *   - Down: UIK_Down
   *   - Return (both normal and keypad): UIK_Return
   *
   * @par
   * Note that the above list may grow in the future. As a consequence
   * a filter function should test explictely for the shortcuts it
   * wants to filter and not assume that it is one of the list above.
   *
   * @par Key Release
   * Note that even if an accelerator is executed with a key-press
   * event, the corresponding key-release is always dispatched to the
   * focused component.
   *
   * @par Usage Limitation
   * As of today only (2011-09) Visualizaton Immersive Dialog (VID)
   * infrastructure code is allowed to call this function. If any
   * other client code calls this function it will break some
   * behaviors in VID.
   *
   * @par
   * If you want to use the same kind of filtering as VID does by
   * calling this function, please contact Dialog team.
   *
   * @par Known Limitations
   * On a french keyboard (or any other keyboard having an AltGr key),
   * pressing AltGr with another key seem to trigger accelerators of
   * that key as if no modifier was pressed, even though Microsoft
   * Windows pretends that both `left control' and `right alt' are
   * pressed. This specific case is not handled by the current
   * implementation and the result is that for example pressing
   * `AltGr+Delete' won't call the filter function and will call an
   * accelerator associated to `Delete' key.
   *
   * @param i_pFunc the filtering function. Use @c NULL to disable
   * filtering (as if this function has never been called).
   */
  static void SetWin32AcceleratorFilter(Win32AcceleratorFilterFunc i_pFunc);
#elif defined(DRIVER_MOTIF)
  /**
   * Type of filter function expected by @ref
   * #SetX11AcceleratorFilter.
   *
   * @param i_accelerator the shortcut that may be filtered. It is a
   * bitfield composed by combination of optional modifiers @c Meta,
   * @c Ctrl and @c DlgShift and an other constant @c UIK_XXX defined
   * in file <pre>CATDlgKeySym.h</pre>.
   *
   * @param i_window the target window of the key-press event.
   *
   * @return @c !=0 if the execution of the accelerator potentially
   * associated with the pressed key should be disabled.
   *
   * @see #SetX11AcceleratorFilter
   */
  typedef int (*X11AcceleratorFilterFunc)(CATDlgAccelerator i_accelerator, Window i_window);
  /**
   * Set a function that filters for some standard @c KeyPress events
   * before the menu accelerators code is called.
   *
   * The filter function decides if either the accelerator code is
   * called for the event or if the event is directly propagated to
   * the focused component.
   *
   * As of today (2011-09-19), even when the accelerator code is
   * called with an event that corresponds to an existing accelerator,
   * the event is also propagated to the focused component.
   *
   * @par Need
   * The application may have set a standard shortcuts as a menu
   * accelerator (for example `Delete' key may be associated with a
   * menu item); in that case it would prevent any focusable component
   * from using the same key as a shortcut (for example in case of
   * `Delete' key to implement a function that deletes text in an
   * editor).
   *
   * @par
   * Using the filter function an infrastructure can decide to prevent
   * the interpretation of an event as an menu accelerator and instead
   * ensure that the event is propagated only to the focused
   * component.
   *
   * @par Filterable Shortcuts
   * Only a subset of events can be filtered, they are listed below.
   *
   * @par
   * Filterable shortcuts are all bits combinations of Ctrl/Alt/Shift
   * modifiers (represented as `Ctrl', `Meta' and `DlgShift' macros)
   * with the following keys (the preprocessor macros used are defined
   * in CATDlgKeySym.h):
   *   - Backspace: UIK_BackSpace
   *   - Insert: UIK_Insert
   *   - Clear: UIK_Clear
   *   - Delete: UIK_Delete
   *   - 0 .. 9 (not keypad): UIK_0 .. UIK_9
   *   - 0 .. 9 (keypad): UIK_KP_0 .. UIK_KP_9
   *   - a .. z: UIK_a .. UIK_z
   *   - Multiply (keypad): UIK_KP_Multiply
   *   - Add (keypad): UIK_KP_Add
   *   - Separator (keypad): UIK_KP_Separator
   *   - Substract (keypad): UIK_KP_Subtract
   *   - Decimal (keypad): UIK_KP_Decimal
   *   - Divide (keypad): UIK_KP_Divide
   *   - Space: UIK_space
   *   - Page Up: UIK_Prior
   *   - Page Down: UIK_Next
   *   - End: UIK_End
   *   - Home: UIK_Home
   *   - Left: UIK_Left
   *   - Up: UIK_Up
   *   - Right: UIK_Right
   *   - Down: UIK_Down
   *   - Return (both normal and keypad): UIK_Return
   *
   * @par
   * Note that the above list may grow in the future. As a consequence
   * a filter function should test explictely for the shortcuts it
   * wants to filter and not assume that it is one of the list above.
   *
   * @par Key Release
   * Note that even if an accelerator is executed with a key-press
   * event, the corresponding key-release is always dispatched to the
   * focused component.
   *
   * @par Usage Limitation
   * As of today (2011-09) only Visualizaton Immersive Dialog (VID)
   * infrastructure code is allowed to call this function. If any
   * other client code calls this function it will break some
   * behaviors in VID.
   *
   * @par
   * If you want to use the same kind of filtering as VID does by
   * calling this function, please contact Dialog team.
   *
   * @param i_pFunc the filtering function. The event corresponding to
   * the press event will be passed to this function. Use @c NULL to
   * disable filtering (as if this function has never been called).
   */
  static void SetX11AcceleratorFilter(X11AcceleratorFilterFunc i_pFunc);
#endif // DRIVER_WINDOWS

  typedef int (*AcceleratorFilterFunc)(CATDlgAccelerator i_accelerator, CATSysWidgetEx i_widget);
  static void SetAcceleratorFilter(AcceleratorFilterFunc i_pFunc);

  /**
   * Get status of the CATDDEON environment variable.
   * It's not mandatory to use Dialog Declarative Engine but could be used in your code to active or not
   * Dialog Declarative Engine by your own implementation.
   * @return a boolean.
   * @return true if environment variable is activated.
   */

  static CATBool CATDlgIsDDEActivated();

#ifdef _MOBILE_SOURCE
  /**
   * Remove the root window background to free up allocated memory
   */
  static void RemoveRootWindowBackground();
#endif

  /**
  * Declares the DLGNOTIFYDISPLAYBLOCKEDENTER event.
  * <br><b>Role</b>
  * This event is sent through DispatchCallbacks by @href CATDlgNotify objects whenever the DisplayBlocked method is entered,
  * unless the CATDlgnotify's style is CATDlgWndNoButton.
  */
  CATDeclareCBEvent(DLGNOTIFYDISPLAYBLOCKEDENTER);

  // DBE Jul 2018
  static void ExplicitCleanUp(CATInteractiveApplication* app);

};

#endif
