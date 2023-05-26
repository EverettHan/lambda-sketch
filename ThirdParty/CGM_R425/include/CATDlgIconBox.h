#ifndef CATDLGICONBOX_H
#define CATDLGICONBOX_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//------------------------------------------------------------------------------
// Abstract: The base class for icon boxes.
//
//------------------------------------------------------------------------------
// Usage:    Like any control, assign CATDlgIconBox to any container or window.
//------------------------------------------------------------------------------
// Inheritance: CATDlgIconBox
//                CATDlgControl
//                  CATDialog
//------------------------------------------------------------------------------
// Main methods:
//
//           GetSelect                  get selected icon
//           SetSelect                  force selection of icon
//------------------------------------------------------------------------------
// Events:
//
//           GetIBoxSelectNotification  selection of an icon
//           GetIBoxModifyNotification  change of current icon state
//------------------------------------------------------------------------------
// Styles:
//
//           CATDlgCtrHorizontal
//           CATDlgCtrVertical
//           CATDlgIboxNoHandler   ( cannot be detached )
//------------------------------------------------------------------------------

//--------------------------------------------------------------------------
#include "CATDlgBox.h"

//--------------------------------------------------------------------------
class CATString;
class l_CATDialog;
class l_CATDlgIconBox;

#ifndef CATDlgIconBox_ADD
/** @nodoc */
#define CATDlgIconBox_ADD
#endif

#ifndef CATDlgIconBox_LateADD
/** @nodoc */
#define CATDlgIconBox_LateADD
#endif

//--------------------------------------------------------------------------
/**
 * Class to make a dropdown menu in a toolbar.
 * <b>Role</b>: Makes a dropdown menu in a toolbar.
 * The icon box is used in a toolbar to build a pull-down (dropdown) menu 
 * composed of icons. Each of  these icons represents a command and can be 
 * clicked to fire an action. To open the icon box, the end user clicks the 
 * arrow. This displays the icons available in the icon box. The icon the 
 * user will click will remain the only one displayed afterwards. 
 */
class ExportedByDI0PANV2 CATDlgIconBox : public CATDlgBox
{

//--------------------------------------------------------------------------
 public:

//      constructor - destructor
/**
 * Makes a dropdown menu in a toolbar.
 * <br><b>Role</b>: Makes a dropdown menu in a toolbar.
 * @param iParent
 *   The parent of the icon box. 
 * @param iDialogObjectName
 *   The dialog object name. 
 * @param iStyle
 *   The application window styles. You can cumulate several
 *   styles using a logical or.
 *   <br><b>Legal values</b>:
 *   <ul>
 *   <li><tt>NULL (default)</tt> so that the 
 *   icon box be vertical </li>
 *   <li><tt>CATDlgCtrHorizontal</tt> if the 
 *   icon box is horizontal</li>
 *   </ul>
 */
        CATDlgIconBox( CATDialog *iParent, const CATString& iDialogObjectName, 
                       CATDlgStyle iStyle=NULL);
/**
 * @nodoc 
 */
        virtual ~CATDlgIconBox();

//      Layout management
/**
 * Set the number of icons per line.
 * @param iIconPerLineCount
 *   The icon per line count.
 */ 
        void SetNumIconPerRow(int iIconPerLineCount);
/**
 * Get the number of icons per line.
 * @return
 *   The number of icons per line.
 *   It begins with 0.
 */ 
 
        int  GetNumIconPerRow();

//      Selection management
/**
 * Gets the selected icon.
 * @return
 *   The index of the selected icon.
 *   It begins with 0.
 */ 
        int  GetSelect();

/**
 * Set the selected icon.
 * @param iIconToSelectIndex 
 *   Index of the icon to select
 * @param iSendingNotificationFlag
 *   To specify if you want the corresponding notification to be sent.
 *   <br><b>Legal values</b>: <tt>1</tt>: default (or any non NULL value)
 *   if you want the notification to be sent, or <tt>NULL</tt> otherwise.
 * @return
 *   The index of the selected icon.
 *   It begins with 0.
 */ 

        int  SetSelect( int iIconToSelectIndex, int iSendingNotificationFlag = 1 );
/**
 * Set the selected icon.
 * @param iIconToSelectName
 *   Name of the icon to select
 * @param iSendingNotificationFlag
 *   To specify if you want the corresponding notification to be sent.
 *   <br><b>Legal values</b>: <tt>1</tt>: default (or any non NULL value)
 *   if you want the notification to be sent, or <tt>NULL</tt> otherwise.
 * @return
 *   The index of the selected icon.
 *   It begins with 0.
 */ 
        int  SetSelect( const CATString& iIconToSelectName, 
                        int iSendingNotificationFlag = 1 );

//      get event notifications
/**
 * Returns the CATDlgIconBoxSelectNotification event notification.
 * It is sent whenever an icon of an icon box is selected.
 */
        CATNotification *GetIBoxSelectNotification() const;
/**
 * Returns the CATDlgIconBoxModifyNotification event notification.
 * It is sent whenever the icon displayed as the icon box is 
 * selected..
 */
        CATNotification *GetIBoxModifyNotification() const;

//      get internal object
/**
 * @nodoc 
 */
        virtual l_CATDialog* GetLetterObject();

//     resets the internal object.
/**
 * @nodoc 
 */
        virtual void ResetLetterObject();

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
        l_CATDlgIconBox* _frameIconBox;

        /** @nodoc */
        CATDlgIconBox_ADD
};

/** @nodoc */
CATDlgIconBox_LateADD

#endif
