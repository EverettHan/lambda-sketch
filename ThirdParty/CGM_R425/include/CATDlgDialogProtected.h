#ifndef CATDLGDIALOGPROTECTED_H
#define CATDLGDIALOGPROTECTED_H

// DBE Feb 2005 + Apr 2005
#include "DI0PANV2.h"
#include "CATBoolean.h"

class CATNotification;
class CATDlgDialog;
class CATDialog;

class l_CATDialog;

class ExportedByDI0PANV2 CATDlgDialogProtected
{
  public :
  static void SetViewer(CATDlgDialog* dia, CATDialog* viewer);
  static void SetViewerBackgroundColor(CATDlgDialog* app, unsigned char ucr, unsigned char ucg, unsigned char ucb);
  // JOV + DBE Apr 2012
  // if the keyboard focus is on a "widget" within non MDI child CATDlgDialog, returns this CATDlgDialog.
  // Otherwise, returns NULL;
  static CATDlgDialog* GetCurrentFocusOwner();

  /**
   * @deprecated R422 Use SetRectRelativePositionEx
   * Set the dialog position relative to its parent
   * @param iDialog the dialog to position
   * @param iRelX, iRelY the relative position
   */
  static void SetRectRelativePosition(CATDlgDialog * iDialog, int iRelX, int iRelY);

  /**
   * Set the dialog position relative to its parent
   * @param iDialog the dialog to position
   * @param iRelX, iRelY the relative position
   * @param iAlreadyScaled specifies if iRelX, iRelY respect the current display scaling
   * When FALSE, iRelX, iRelY must match a 100% display scaling, they will be automatically scaled according to current display scaling
   * When TRUE, iRelX, iRelY must match the current display scaling, they won't be scaled
   */
  static void SetRectRelativePositionEx(CATDlgDialog * iDialog, int iRelX, int iRelY, CATBoolean iAlreadyScaled);

  /**
   * Supported on Windows only
   * Prevents window activation both after creation and after show
   */
  static void NoDefaultActivation(CATDlgDialog* dia);

  /**
   * Supported on Windows only
   * Set/Reset topmost style for Z order
   */
  static void SetTopMost(CATDlgDialog* dia, CATBoolean topMost);

  /**
   * Supported on Windows only
   */
  static CATNotification* GetDiaActivateNotification(CATDlgDialog* dia);
  static CATNotification* GetDiaDeactivateNotification(CATDlgDialog* dia);

  /**
   * @deprecated R422 Use SetMinSizeEx
   * Set the minimal size of a panel
   * @param iDialog the panel
   * @param iWidth, iHeight the dimensions
   */
  static void SetMinSize(CATDlgDialog * iDialog, int iWidth, int iHeight);

  /**
   * Set the minimal size of a panel
   * @param iDialog the panel
   * @param iWidth, iHeight the dimensions
   * @param iAlreadyScaled specifies if iWidth, iHeight respect the current display scaling
   * When FALSE, iWidth, iHeight must match a 100% display scaling, they will be automatically scaled according to current display scaling
   * When TRUE, iWidth, iHeight must match the current display scaling, they won't be scaled
   */
  static void SetMinSizeEx(CATDlgDialog * iDialog, int iWidth, int iHeight, CATBoolean iAlreadyScaled);

  /**
   * Inhibates the default processing of Escape Key for non MDI Child CATDlgDialog windows
   * Escape keys events are then processed by the parent window.
   * (actual effect on Windows only)
   */
  static void SetIgnoreEscapeKey(CATDlgDialog * iDialog, CATBoolean iIgnoreEscapeKey);

private:
#if defined (DRIVER_COCOA) || defined (DRIVER_ANDROID)
  static void ClientToScreen(l_CATDialog *, int&, int&);
#endif
};
#endif
