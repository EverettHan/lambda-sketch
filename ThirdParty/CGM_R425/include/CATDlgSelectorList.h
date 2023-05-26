#ifndef CATDLGSELECTORLIST_H
#define CATDLGSELECTORLIST_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATDlgControl.h"

class CATString;
class CATUnicodeString;
class l_CATDialog;
class l_CATDlgSelectorList;
class CATDlgContextualMenu;

#ifndef CATDlgSelectorList_ADD
/** @nodoc */
#define CATDlgSelectorList_ADD
#endif

#ifndef CATDlgSelectorList_LateADD
/** @nodoc */
#define CATDlgSelectorList_LateADD
#endif


/** 
 * Base class for lists.
 * <b>Role</b>:
 * The selector list allows the end user to select one or several values among a
 * discrete list of predefined values. The values are generally character strings.
 * Scrollbars are added if the list is longer or wider than the list display area.
 * The selected value(s) is (are) highlighted. The end user cannot enter values and
 * can only select among those proposed.
 * <br>
 * Use selector list whenever you propose to the end user to select values from a predefined list.
 */
class ExportedByDI0PANV2 CATDlgSelectorList : public CATDlgControl
{

 public:

			/** 
			 * Constructs a CATDlgSelectorList.
			 * @param iParent
			 *   The parent of the selector list.
			 * @param iObjectName
			 *   The name of the selector list.
			 * @param iStyle
			 *   The style of the selector list.
			 * The style can be :
			 *   <dl>
			 *   <dt><tt>NULL</tt><dd> : if no value is passed, only a single value can be selected, 
			 *   <dt><tt>CATDlgLstMultisel</tt><dd> : several values can be selected using the Shift and Ctrl keys. 
			 *   </dl>
			 */
        CATDlgSelectorList( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgSelectorList();

			/**
			 * Returns the number of selected items.
			 */
        int     GetSelectCount();

			/**
			 * Returns TRUE if the given line specified by its number is selected, FALSE otherwise.
			 * A CATBool is a short.
			 * @param iRow
			 * The number of the specified line.
			 */
        CATBool IsSelect( int iRow);

			/**
			 * Returns TRUE if the given line specified by its contents is selected, FALSE otherwise.
			 * A CATBool is a short.
			 * @param iString
			 * The contents of the specified line.
			 */
        CATBool IsSelect( const CATUnicodeString& iString);

			/**
			 * Retrieves the selected lines as an array of int.
			 * Pay attention to properly allocate and deallocate the array.
			 * @param oTabRow
			 * The pointer to the returned array of int.
			 * @param iSize
			 * The size of the array.
			 * @return the number of selected lines.
			 */
        int     GetSelect( int *oTabRow, int iSize);

			/**
			 * Retrieves the selected lines as an array of CATUnicodeString.
			 * Pay attention to properly allocate and deallocate the array.
			 * @param oTabString
			 * The pointer to the returned array of CATUnicodeString.
			 * @param iSize
			 * The size of the array.
			 * @return the number of selected lines.
			 */
        int     GetSelect( CATUnicodeString* oTabString, int iSize);

			/**
			 * Deselects all selected lines.
			 */
        void    ClearSelect( );

			/**
			 * Sets the selected lines from an array of int.
			 * @param iTabRow
			 * The pointer to the array of int representing the numbers of the lines to select.
			 * @param iSize
			 * The size of the array.
			 * @param iNotify
			 * Set this parameter to a non null value if you want the corresponding notification to be sent.
			 * Otherwise set it to 0, so no notification will be sent. 
			 * @return the number of selected lines.
			 */
        int     SetSelect( int *iTabRow, int iSize, int iNotify=1);

			/**
			 * Sets the selected lines from an array of CATUnicodeString.
			 * @param iTabString
			 * The pointer to the array of CATUnicodeString representing the contents of the lines to select.
			 * @param iSize
			 * The size of the array.
			 * @param iNotify
			 * Set this parameter to a non null value if you want the corresponding notification to be sent.
			 * Otherwise set it to 0, so no notification will be sent. 
			 * @return the number of selected lines.
			 */
        int     SetSelect( CATUnicodeString *iTabString, int iSize, int iNotify=1);

			/**
			 * Returns the line number of the selected line under the mouse when the end user displays the contextual menu.
			 */
        int     GetContextualLine();

			/**
			 * Returns the number of lines in the list.
			 */
        int  GetLineCount();

			/**
			 * Retrieves the contents of a line given its number.
			 * @param oString
			 * The returned contents of the specified line.
			 * @param iRow
			 * The number of the line.
			 */
        void GetLine( CATUnicodeString& oString, int iRow);

			/**
			 * Sets or modifies the contents of a line given its number.
                         * <br><b>Role:</b>This method sets or modifies the contents of a 
                         * line given its position. If the line was selected, see @href #SetSelect ,
                         * the line is no more. 
			 * @param iString
			 * The contents of the specified line.
			 * @param iIndex
			 * The number of the line to add or modify. If iIndex is omitted or set to -1, the line is appended to the list .The first element of the list is 0;
			 * @param iMode
			 *   Two modes are available :
			 *   <dl>
			 *   <dt><tt>CATDlgDataAdd</tt><dd> to add a line, which is the default, 
			 *   <dt><tt>CATDlgDataModify</tt><dd> to modify an existing line. 
			 *   </dl>
			 */
        int  SetLine( const CATUnicodeString& iString, int iIndex=-1, CATULong iMode=CATDlgDataAdd );

			/**
			 * Sets or modifies the contents of one or several contigous lines given
                         *  the number of the first line.
                         * <br><b>Role:</b>This method sets or modifies the contents of one or  
                         * several contigous lines given the position of the first line. All the 
                         * selected lines, see @href #SetSelect are no more. 
			 * @param iString
			 * The array of contents of the specified lines.
			 * @param iNbLines
			 * The number of lines to add or modify.
			 * @param iIndex
			 * The number of the first line to add or modify. If iIndex is omitted or set to -1, the lines are appended to the list.
			 * @param iMode
			 *   Two modes are available :
			 *   <dl>
			 *   <dt><tt>CATDlgDataAdd</tt><dd> to add lines, which is the default, 
			 *   <dt><tt>CATDlgDataModify</tt><dd> to modify existing lines. 
			 *   </dl>
			 */
        int  SetLine( const CATUnicodeString *iString, int iNbLines, int iIndex=-1, CATULong iMode=CATDlgDataAdd );

			/**
			 * Deletes a line from its number.
			 * @param iIndex
			 * The number of the line to delete.
			 */
        void ClearLine( int iIndex );

			/**
			 * Deletes several lines from their numbers.
			 * @param iRow
			 * The array of int representing the numbers of the lines to delete.
			 * @param iLines
			 * The number of lines to delete.
			 */
        void ClearLine( int *iRow, int iLines );

			/**
			 * Deletes all lines.
			 */
        void ClearLine( );

			/**
			 * Returns the number of visible characters.
			 */
        int  GetVisibleTextWidth();

			/**
			 * Sets the number of visible characters.
			 * @param iWidth
			 * The number of visible characters to set.
			 */
        void SetVisibleTextWidth( int iWidth);

			/**
			 * Returns the visible text height.
			 */
        int  GetVisibleTextHeight();

			/**
			 * Sets the visible text height.
			 * @param iHeight
			 * The visible text height to set.
			 */
        void SetVisibleTextHeight( int iHeight);

			/**
			 * Returns the first visible line position.
			 */
        int  GetFirstLine();

			/**
			 * Sets the first visible line position.
			 * @param iRow
			 * The position to set for the first visible line.
			 * @return the first visible line position.
			 */
        int  SetFirstLine( int iRow);

			/**
			 * Returns the first visible character position.
			 */
        int  GetFirstColumn();

			/**
			 * Sets the first visible character position.
			 * @param iColumn
			 * The position to set for the first visible character.
			 * @return the first visible character position.
			 */
        int  SetFirstColumn( int iColumn);

			/**
			 * @nodoc
			 */
        int  GetItemRect(int, DRECT&);

			/**
			 * Returns the event notification sent whenever a line is selected.
			 * <br><b>Role:</b>This notification is sent when the end user select
			 * an item of the list. So it means that the Dialog object must 
			 * contain at least one item.
			 */
        CATNotification *GetListSelectNotification() const;

			/**
			 * Returns the event notification sent whenever a line is double clicked.
			 */
        CATNotification *GetListActivateNotification() const;

			/**
			 * @nodoc 
			 * Returns the event notification sent whenever a list is clicked.
			 */
        CATNotification *GetListSingleClickNotification() const;

			/**
			 * @nodoc 
			 * Returns the internal object.
			 */
        virtual l_CATDialog* GetLetterObject();

			/**
			 * @nodoc 
			 * Resets internal object.
			 */
        virtual void ResetLetterObject();

       /**
        * @nodoc
        * Requests the ClassName, IsA, and IsAKindOf methods to be created.
        */
        CATDeclareClass ;
 private:

			/**
			 * @nodoc 
			 * Address of the internal object.
			 */
        l_CATDlgSelectorList* _frameListChooser;

        /** @nodoc */
        CATDlgSelectorList_ADD
};

/** @nodoc */
CATDlgSelectorList_LateADD

#endif
