#ifndef CATDLGFRAME_H
#define CATDLGFRAME_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */


//------------------------------------------------------------------------------
// Abstract: The base class for frames.
//
//------------------------------------------------------------------------------
// Usage:    Assign a CATDlgFrame to any other container or window.
//------------------------------------------------------------------------------
// Inheritance: CATDlgFrame
//                CATDlgBox
//                  CATDialog
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
//
//           SetGridColumnResizable    define Grid Column resize policy
//           SetGridRowResizable       define Grid Row resize policy
//           IsGridColumnResizable     ask Grid Column resize policy
//           IsGridRowResizable        ask Grid Row resize policy
//------------------------------------------------------------------------------
// Styles:
//
//           CATDlgFraNoFrame
//           CATDlgFraNoTitle
//           CATDlgGridLayout
//------------------------------------------------------------------------------

//--------------------------------------------------------------------------
#include "CATDlgBox.h"

//--------------------------------------------------------------------------
class CATString;
class l_CATDialog;
class l_CATDlgFrame;
class CATDlgControl;
class CATDlgBlackBox;

#ifndef CATDlgFrame_ADD
/** @nodoc */
#define CATDlgFrame_ADD
#endif

#ifndef CATDlgFrame_LateADD
/** @nodoc */
#define CATDlgFrame_LateADD
#endif

//--------------------------------------------------------------------------
/**
 * Class to gather controls having something in common.
 * <b>Role</b>: Gathers controls having something in common.
 * The frame is designed to group several Dialog framework objects, 
 * like controls and labels, having something in common from the user 
 * or from the application point of view. The frame is the basic 
 * container to gather controls, and possibly other containers. 
 * These objects should be related to each other.
 * A frame can be visible or invisible. A visible frame is displayed 
 * as a rectangular box, and can have a title.
 * <p>
 * Use frames whenever you want to group objects that relate 
 * to each other. 
 * <p>
 * The frame layout may be manipulated either using tabulations
 * or using a grid.
 */

class ExportedByDI0PANV2 CATDlgFrame : public CATDlgBox
{

//--------------------------------------------------------------------------
 public:

//      constructor - destructor
/**
 * Constructs a class to gather controls having something in common.
 * <br><b>Role</b>: Constructs a class to gather controls having something 
 * in common.
 * @param iParent
 *   The parent of the frame.
 * @param iDialogObjectName
 *   The dialog object name. 
 * @param iStyle
 *   The application window styles. You can cumulate several
 *   styles using a logical or.
 *   <br><b>Legal values</b>: 
 *   <ul>
 *   <li> <tt>NULL (default)</tt> so that the 
 *   frame is visible and has a title, and so that its layout is 
 *   managed using tabulations </li> 
 *   <li> <tt>CATDlgFraNoTitle</tt> if the 
 *   frame has no title </li> 
 *   <li><tt>CATDlgFraNoFrame</tt> 
 *   if the frame is not visible, its contents remaining visible,
 *   (this hides the title if any) </li> 
 *   <li><tt>CATDlgGridLayout</tt> if the 
 *   frame layout is managed using a grid.</li>
 *   </ul>
 */
        CATDlgFrame( CATDialog *iParent, const CATString& iDialogObjectName, 
                     CATDlgStyle iStyle=NULL);
/**
 * @nodoc 
 */
        virtual ~CATDlgFrame();

//      get internal object
/**
 * @nodoc 
 */
        virtual l_CATDialog* GetLetterObject();

/**
 * @nodoc 
 * Resets the internal object.
 */
        virtual void ResetLetterObject();

//      basic layout management
/**
 * Set the frame default layout orientation.
 * The default orientation is taken into account when no other 
 * layout information is provided. 
 * @param iLayoutOrientation
 *   The layout orientation.
 *   <br><b>Legal values</b>: <tt>Vertical</tt> so that the 
 *   children be presented along a vertical line, or 
 *   <tt>Horizontal</tt> so that the 
 *   children be presented along a horizontal line.
 */
        void SetDefaultOrientation(Orientation iLayoutOrientation) ;
/**
 * Get the frame default layout orientation.
 * The default orientation is taken into account when no other 
 * layout information is provided. 
 * @return
 *   The layout orientation.
 *   <br><b>Legal values</b>: <tt>Vertical</tt> if the 
 *   children are presented along a vertical line, or 
 *   <tt>Horizontal</tt> if the 
 *   children are presented along a horizontal line.
 */
        Orientation GetDefaultOrientation() ;
/**
 * Fullfills the current frame with a delivered object.
 * @param iFillingObject
 *   The object with witch the frame is to be filled.
 */
        void Attach4Sides(CATDialog *iFillingObject) ;
/**
 * Detach a delivered object from all its attachments 
 * within the current frame.
 * @param iObject
 *   The object to detach.
 */

        void ResetAttachment(CATDialog *iObject) ;
/**
 * Creates horizontal tabulation lines.
 * @param iHorizontalTabLineIndex
 *   The horizontal tabulation line index.
 * @param iAttachmentMode
 *   The attachment mode.
 *   <br><b>Legal values</b>: 
 * <ul>
 *   <li><tt>CATDlgTopOrLeft</tt> so that the 
 *   objects be attached using their top sides </li> 
 *   <li><tt>CATDlgTopOrLeftRelative</tt> so that the 
 *   objects be attached using their top sides and so that
 *   resizing be enabled</li> 
 *   <li><tt>CATDlgRightOrBottom</tt> so that 
 *   the objects be attached using their bottom sides</li> 
 *   <li><tt>CATDlgRightOrBottomRelative</tt> so that 
 *   the objects be attached using their bottom sides and so that
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
 * @param iVerticalTabLineIndex
 *   The vertical tabulation line index.
 * @param iAttachmentMode
 *   The attachment mode.
 *   <br><b>Legal values</b>: 
 * <ul>
 *   <li><tt>CATDlgTopOrLeft</tt> so that the 
 *   objects be attached using their left sides</li>
 *   <li><tt>CATDlgTopOrLeftRelative</tt> so that the 
 *   objects be attached using their left sides and so that
 *   resizing be enabled </li>
 *   <li><tt>CATDlgRightOrBottom</tt> so that the 
 *   objects be attached using their right sides</li>
 *   <li> <tt>CATDlgRightOrBottomRelative</tt> so that the 
 *   objects be attached using their right sides and so that
 *   resizing be enabled </li>
 *   <li><tt>CATDlgCenter</tt> so that the 
 *   objects be attached using their center </li>
 *   <li><tt>CATDlgCenterRelative</tt> so that the objects be 
 *   attached using their center and so that resizing be enabled</li>
 * </ul>
 * @param iAttachedObject1
 *   The first attached object.
 * @param ...
 *   The other attached objects
 */
        void SetVerticalAttachment  (CATDlgTabIndex iVerticalTabLineIndex,
                        CATDlgAttachment iAttachmentMode, CATDialog *iAttachedObject1, ...);
/**
 * Retrieves the vertical tabulation line index to 
 * which a given object is attached.
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
 * Detach an object from an horizontal tabulation line.
 * @param iTabulationIndex
 *   The tabulation index.
 * @param iControlToDetach
 *   The control to detach.
 */
        void RemoveAlongHorizontalTab(CATDlgTabIndex iTabulationIndex, 
                                      CATDialog * iControlToDetach);
/**
 * Detach an object from an vertical tabulation line.
 * @param iTabulationIndex
 *   The tabulation index.
 * @param iControlToDetach
 *   The control to detach.
 */
        void RemoveAlongVerticalTab  (CATDlgTabIndex iTabulationIndex, 
                                      CATDialog * iControlToDetach);
/**
 * Replace an object by another.
 * @param iReplacingObject
 *   The replacing object.
 * @param iObjectToReplace
 *   The object to replace.
 */
        void ReplaceKeepAttachments(CATDialog * iReplacingObject,
                                    CATDialog * iObjectToReplace);

//      grid layout management (active with CATDlgGridLayout style)
/**
 * Defines Grid Column resize policy.
 * This is available only if the current frame is a grid 
 * (CATDlgGridLayout style)
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
 * This is available only if the current frame is a grid 
 * (CATDlgGridLayout style)
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
 * Specifies if a grid column is resizable.
 * This is available only if the current frame is a grid 
 * (CATDlgGridLayout style)
 * @param iColumnIndex
 *   The column index.
 */
        int IsGridColumnResizable(short int iColumnIndex);
/**
 * Specifies if a grid row is resizable.
 * This is available only if the current frame is a grid 
 * (CATDlgGridLayout style)
 * @param iRowIndex
 *   The row index.
 */
        int IsGridRowResizable(short int iRowIndex);
/**
 * @nodoc 
 */
        void OpenContextualMenu(float x, float y);

/**
 * @nodoc
 * Requests the ClassName, IsA, and IsAKindOf methods to be created.
 */
        CATDeclareClass ;
//--------------------------------------------------------------------------
 private:

//      address of internal object.
/**
 * @nodoc 
 */
        l_CATDlgFrame* _frameFrame;

        /** @nodoc */
        CATDlgFrame_ADD
};

/** @nodoc */
CATDlgFrame_LateADD

#endif
