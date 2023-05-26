#ifndef CATDLGWINDOW_H
#define CATDLGWINDOW_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//------------------------------------------------------------------------------
// Abstract: The base class for windows.
//           Cannot be instantiated.
//
//------------------------------------------------------------------------------
// Usage:    Do not use.
//------------------------------------------------------------------------------
// Inheritance: CATDlgWindow
//                CATDialog
//------------------------------------------------------------------------------
// Main methods:
//
//           SetDefaultOrientation     set default positioning ( hor / vert )
//           GetDefaultOrientation     get default positioning ( hor / vert )
//           Attach4Sides              fullfill frame with object
//           ResetAttachment           detach object
//           SetHorizontalAttachment   define horizontal positioning
//           SetVerticalAttachment     define vertical positioning
//           GetVerticalTabIndex       get vertical attachment number from dialog
//           GetHorizontalTabIndex     get horizontal attachment number from dialog
//           InsertAlongHorizontalTab  insert object into an horizontal attachment
//           InsertAlongVerticalTab    insert object into a vertical attachment
//           RemoveAlongHorizontalTab  remove object from an horizontal attachment
//           RemoveAlongVerticalTab    remove object from a vertical attachment
//           ReplaceKeepAttachments    substitute object with another
//           SetFullScreen             Maximize or Restore window size
//
//           SetGridColumnResizable    define Grid Column resize policy
//           SetGridRowResizable       define Grid Row resize policy
//           IsGridColumnResizable     ask Grid Column resize policy
//           IsGridRowResizable        ask Grid Row resize policy
//           IsMaximized               is window maximized?
//           IsMinimized               is window minimized?
//           Maximize                  to maximize a window
//           Minimize                  to minimize a window
//           Restore                   to restore a window to its previous size
//------------------------------------------------------------------------------
// Events:
//
//           GetWindSizeNotification    change of window size
//           GetWindCloseNotification   selection of window system menu close (Alt F4)
//           GetWindMoveNotification    Displacement of window
//           GetWindMaximizeNotification when a window is maximized
//           GetWindMinimizeNotification when a window is minimized
//           GetWindRestoreNotification  when a window is restored
//------------------------------------------------------------------------------
// Styles:
//           CATDlgGridLayout
//--------------------------------------------------------------------------

#include "CATDialog.h"

//--------------------------------------------------------------------------
class CATString;

#ifndef CATDlgWindow_ADD
/** @nodoc */
#define CATDlgWindow_ADD
#endif

#ifndef CATDlgWindow_LateADD
/** @nodoc */
#define CATDlgWindow_LateADD
#endif

//--------------------------------------------------------------------------
/**
 * Base class for all dialog window classes.
 * <b>Role</b>: The window object base class to share window and dialog 
 * box behavior. All the tasks described here consequently apply to any 
 * dialog window instance. Its derived classes are: 
 * <ul>
 * <li>@href CATDlgDocument </li>  
 * <li>@href CATDlgDialog </li>
 * <li>@href CATDlgNotify </li>
 * <li>@href CATDlgFile </li>
 * </ul> 
 * You cannot construct a CATDlgWindow directly: it can be constructed 
 * as the base class of one of its derived class only. 
 */
class ExportedByDI0PANV2 CATDlgWindow : public CATDialog
{
public:
  /**
   * @deprecated R422 Use GetMaximumSizeEx
   * Get maximum window size.
   * @param oHeight
   *   The maximum height.
   * @param oWidth
   *   The maximum width.
   */
  void GetMaximumSize(int* oHeight, int* oWidth);

  /**
   * Get maximum window size.
   * @param oHeight
   *   The maximum height.
   * @param oWidth
   *   The maximum width.
   * @param iAlreadyScaled
   *   Specifies if oHeight, oWidth must respect the current display scaling.
   *   When FALSE, oHeight, oWidth coordiantes will match a 100% display scaling.
   *   When TRUE, oHeight, oWidth coordiantes will match the current display scaling.
   */
  void GetMaximumSizeEx(int* oHeight, int* oWidth, CATBoolean iAlreadyScaled);

/**
 * @nodoc 
 * Makex the window contents occupy the full screen.
 * @param iFullScreenFlag
 *   <br><b>Legal values</b>: <tt>1</tt> so that the window contents 
 *   occupy the full screen, or <tt>0</tt> so that the window contents
 *   be restored to its previous size.
 */
        void SetFullScreen(int iFullScreenFlag);
/**
 * @nodoc 
 */
        void SetImmersive(int iFullScreenFlag);
/**
 * Returns the CATDlgWindSizeNotification event notification.
 * It is sent whenever the window is resized.
 */
        CATNotification *GetWindSizeNotification() const;
/**
 * Returns the CATDlgWindCloseNotification event notification.
 * It is sent whenever the window is closed.
 */
        CATNotification *GetWindCloseNotification() const;
/**
 * Returns the CATDlgWindMoveNotification event notification.
 * It is sent whenever the window is moved.
 */
        CATNotification *GetWindMoveNotification() const;
/**
 * Returns the CATDlgWindMaximizeNotification event notification.
 * It is sent whenever the window is maximized.
 */
        CATNotification *GetWindMaximizeNotification() const;
/**
 * Returns the CATDlgWindMinimizeNotification event notification.
 * It is sent whenever the window is minimized.
 */
        CATNotification *GetWindMinimizeNotification() const;
/**
 * Returns the CATDlgWindRestoreNotification event notification.
 * It is sent whenever the window is restored to its previous size 
 * after being minimized or maximized.
 */
        CATNotification *GetWindRestoreNotification() const;
            
//      context-sensitive help
/**
 * Activates the help on context.
 * This method will be called when the "What's This" command is 
 * selected. This selection might be through a dedicated icon or, on Windows only,
 * through the panel question mark selection, or, on Windows and UNIX,
 * through the panel help button selection. 
 * <p>
 * The "What's This" command turns the cursor to a question mark, and then 
 * when the end-user clicks a control, displays the control associated 
 * "Long Help" in a balloon. The clicks, after displaying the balloon,
 * ends the current "What's This" command.
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * 
 */
        void QueryHelpOnContext();

//      layout management for the derived CATDlgDialog and CATDlgDocument
/**
 * Sets the window default layout orientation.
 * The default orientation is taken into account when no other 
 * layout information is provided. 
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iLayoutOrientation
 *   The layout orientation.
 *   <br><b>Legal values</b>: <tt>Vertical</tt> so that the 
 *   children be presented along a vertical line, or 
 *   <tt>Horizontal</tt> so that the 
 *   children be presented along a horizontal line.
 */
        void SetDefaultOrientation(Orientation iLayoutOrientation) ;
/**
 * Gets the window default layout orientation.
 * The default orientation is taken into account when no other 
 * layout information is provided. 
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @return
 *   The layout orientation.
 *   <br><b>Legal values</b>: <tt>Vertical</tt> if the 
 *   children are presented along a vertical line, or 
 *   <tt>Horizontal</tt> if the 
 *   children are presented along a horizontal line.
 */
        Orientation GetDefaultOrientation() ;
/**
 * Fullfills the current window with a delivered object.
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iFillingObject
 *   The object with witch the window is to be filled.
 */
        void Attach4Sides(CATDialog *iFillingObject) ;

/**
 * Detaches a delivered object from all its attachments 
 * within the current window.
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iObject
 *   The object to detach.
 */
        void ResetAttachment(CATDialog *iObject) ;
/**
 * Creates horizontal tabulation lines.
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iHorizontalTabLineIndex
 *   The horizontal tabulation line index.
 * @param iAttachmentMode
 *   The attachment mode.
 *   <br><b>Legal values</b>: 
 *   <ul>
 *   <li><tt>CATDlgTopOrLeft</tt> so that the 
 *   objects be attached using their top sides</li> 
 *   <li><tt>CATDlgTopOrLeftRelative</tt> so that the 
 *   objects be attached using their top sides and so that
 *   resizing be enabled</li>
 *   <li><tt>CATDlgRightOrBottom</tt> so that the 
 *   objects be attached using their bottom side</li>
 *   <li><tt>CATDlgRightOrBottomRelative</tt> so that the 
 *   objects be attached using their bottom sides and so that
 *   resizing be enabled</li>
 *   <li><tt>CATDlgCenter</tt> so that the 
 *   objects be attached using their center</li>
 *   <li><tt>CATDlgCenterRelative</tt> so that the objects be 
 *   attached using their center and so that resizing be enabled</li>
 * </ul>
 * @param iAttachedObject1
 *   The first attached object.
 * @param ...
 *   The other attached objects
 */
        void SetHorizontalAttachment(CATDlgTabIndex iHorizontalTabLineIndex,
                            CATDlgAttachment iAttachmentMode, 
                            CATDialog *iAttachedObject1, ...);
/**
 * Creates vertical tabulation lines.
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iVerticalTabLineIndex
 *   The vertical tabulation line index.
 * @param iAttachmentMode
 *   The attachment mode.
 *   <br><b>Legal values</b>:
 *  <ul>
 *   <li><tt>CATDlgTopOrLeft</tt> so that the 
 *   the objects be attached using their left sides</li>
 *   <li><tt>CATDlgTopOrLeftRelative</tt> so that the 
 *   the objects be attached using their left sides and so that
 *   resizing be enabled</li>
 *   <li><tt>CATDlgRightOrBottom</tt> so that the 
 *   the objects be attached using their right sides</li>
 *   <li><tt>CATDlgTopOrLeftRelative</tt> so that the 
 *   the objects be attached using their right sides and so that
 *   resizing be enabled</li>
 *   <li><tt>CATDlgCenter</tt> so that the 
 *   the objects be attached using their center </li>
 *   <li><tt>CATDlgCenterRelative</tt> so that the objects be 
 *   attached using their center and so that resizing be enabled</li>
 *  </ul>
 * @param iAttachedObject1
 *   The first attached object.
 * @param ...
 *   The other attached objects
 */
        void SetVerticalAttachment  (CATDlgTabIndex iVerticalTabLineIndex,
                            CATDlgAttachment iAttachmentMode, 
                            CATDialog *iAttachedObject1, ...);
/**
 * Retrieves the vertical tabulation line index to 
 * which a given object is attached.
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iObject
 *   The object.
 * @param iAttachmentMode
 *   The attachment mode.
 * @return 
 *   The vertical tabulation index.
 */
        int GetVerticalTabIndex(CATDialog * iObject, 
                                CATDlgAttachment iAttachmentMode);
/**
 * Retrieves the horizontal tabulation line index to 
 * which a given object is attached.
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iObject
 *   The object.
 * @param iAttachmentMode
 *   The attachment mode.
 * @return 
 *   The horizontal tabulation index.
 */
        int GetHorizontalTabIndex(CATDialog * iObject, 
                                  CATDlgAttachment iAttachmentMode);
/**
 * Inserts an object along an horizontal tabulation 
 * line with respect to an already inserted object.
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iTabulationIndex
 *   The tabulation index.
 * @param iControlToInsert
 *   The control to insert.
 * @param iReferenceControl
 *   The reference control
 * @param iInsertionMode
 *   Where to insert
 */
        void InsertAlongHorizontalTab(CATDlgTabIndex iTabulationIndex, 
                              CATDialog * iControlToInsert,
                              CATDialog * iReferenceControl, 
                              InsertionMode iInsertionMode);
/**
 * Inserts an object along an vertical tabulation 
 * line with respect to an already inserted object.
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iTabulationIndex
 *   The tabulation index.
 * @param iControlToInsert
 *   The control to insert.
 * @param iReferenceControl
 *   The reference control
 * @param iInsertionMode
 *   Where to insert
 */
        void InsertAlongVerticalTab(CATDlgTabIndex iTabulationIndex, 
                              CATDialog * iControlToInsert,
                              CATDialog * iReferenceControl, 
                              InsertionMode iInsertionMode);
/**
 * Detaches an object from an horizontal tabulation line.
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iTabulationIndex
 *   The tabulation index.
 * @param iControlToDetach
 *   The control to detach.
 */
        void RemoveAlongHorizontalTab(CATDlgTabIndex iTabulationIndex, 
                                      CATDialog * iControlToDetach);
/**
 * Detaches an object from an vertical tabulation line.
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iTabulationIndex
 *   The tabulation index.
 * @param iControlToDetach
 *   The control to detach.
 */
        void RemoveAlongVerticalTab  (CATDlgTabIndex iTabulationIndex, 
                                      CATDialog * iControlToDetach);
/**
 * Replaces an object by another.
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iReplacingObject
 *   The replacing object.
 * @param iObjectToReplace
 *   The object to replace.
 */
        void ReplaceKeepAttachments(CATDialog * iReplacingObject , 
                                    CATDialog * iObjectToReplace);
//      grid layout management (active with CATDlgGridLayout style)
/**
 * Defines Grid Column resize policy.
 * This is available only if the current window is a grid 
 * (CATDlgGridLayout style).
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iColumnIndex
 *   The column index.
 * @param iResizableFlag
 *   Integer specifying if the column is to be resizable.
 *   <br><b>Legal values</b>: <tt>1</tt> if the column is to
 *   be resizable, or <tt>0</tt> otherwise.
 */
        void SetGridColumnResizable(short int iColumnIndex, 
                                    int iResizableFlag=1);
/**
 * Defines Grid Row resize policy.
 * This is available only if the current window is a grid 
 * (CATDlgGridLayout style).
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iRowIndex
 *   The row index.
 * @param iResizableFlag
 *   Integer specifying if the row is to be resizable.
 *   <br><b>Legal values</b>: <tt>1</tt> if the row is to
 *   be resizable, or <tt>0</tt> otherwise.
 */
        void SetGridRowResizable(short int iRowIndex, 
                                 int iResizableFlag=1);
/**
 * Returns if a grid column is resizable.
 * This is available only if the current window is a grid 
 * (CATDlgGridLayout style).
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iColumnIndex
 *   The column index.
 */
        int IsGridColumnResizable(short int iColumnIndex);
/**
 * Returns if a grid row is resizable.
 * This is available only if the current window is a grid 
 * (CATDlgGridLayout style).
 * This deals only with the @href CATDlgDialog and @href CATDlgDocument derived
 * classes from this based class.
 * @param iRowIndex
 *   The row index.
 */
        int IsGridRowResizable(short int iRowIndex);

//      state of a window
/**
 * Gets the window maximized/minimized state.
 * @return
 *   <br><b>Legal values</b>: <tt>1</tt> if the window is currently
 *   maximized, or <tt>0</tt> otherwise.
 */
        int IsMaximized();
/**
 * Gets the window maximized/minimized state.
 * @return
 *   <br><b>Legal values</b>: <tt>1</tt> if the window is currently
 *   minimized, or <tt>0</tt> otherwise.
 */
        int IsMinimized();
/**
 * Maximizes the window.
 */
        void Maximize();
/**
 * Minimizes the window.
 */
        void Minimize();
/**
 * Restores the window to its previous size after being minimized 
 * or maximized.
 */
        void Restore();
/**
 * @nodoc
 * Requests the ClassName, IsA, and IsAKindOf methods to be created.
 */
        CATDeclareClass ;

//--------------------------------------------------------------------------
 protected:

//      constructor - destructor
/**
 * @nodoc 
 */
        CATDlgWindow( CATDialog *iParent, const CATString& iDialogObjectName, 
                      CATDlgStyle iStyle=NULL);             
/**
 * @nodoc 
 */
        CATDlgWindow( CATDialog *iParent, CATCommand *eventMgr, 
                      const CATString& iDialogObjectName, CATDlgStyle iStyle=NULL);
/**
 * @nodoc 
 */
        virtual ~CATDlgWindow();

        /** @nodoc */
        CATDlgWindow_ADD
};

/** @nodoc */
CATDlgWindow_LateADD

#endif
