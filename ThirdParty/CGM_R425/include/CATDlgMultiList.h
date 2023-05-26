#ifndef CATDLGMULTILIST_H
#define CATDLGMULTILIST_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDlgControl.h"
#include "CATIAV5Level.h"

class CATNotification;
class CATString;
class CATUnicodeString;

class CATDlgCombo; // Do not remove: impact on CATCompositeUI etc.
class CATDialog;

class l_CATDialog;
class l_CATDlgMultiList;

#ifndef CATDlgMultiList_ADD
/** @nodoc */
#define CATDlgMultiList_ADD
#endif

#ifndef CATDlgMultiList_LateADD
/** @nodoc */
#define CATDlgMultiList_LateADD
#endif

/**
* applicative function for the sort in a CATDlgMultiList.
* @see #SetColumnSortMethod.
*/
typedef int (*CATDlgMultiListSortMethod)(CATUnicodeString, CATUnicodeString);

/**
 * Base class for lists with multiple columns.
 */
class ExportedByDI0PANV2 CATDlgMultiList : public CATDlgControl {

    public:

        /**
         * Constructor.
         * @param iParent
         * The parent widget.
         * @param iObjectName
         * The internal name of the multilist.
         * @param iStyle
         * The style of the multilist.
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>default</tt><dd> multiple selection is not allowed. </dd></dt>
         * <dt><tt>CATDlgLstMultisel</tt><dd> multiple selection is allowed. </dd></dt>
         * <dt><tt>CATDlgLstAutoSort</tt><dd> automatic sort is activated when the user presses the title of a column, see @href #SetColumnSortMethod. </dd></dt>
         * <dt><tt>CATDlgLstAllowEmptyCells</tt><dd> allow insertion of items at any position in a column. </dd></dt>
         * </dl>
         */
        CATDlgMultiList( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        /**
         * Destructor.
         */
        virtual ~CATDlgMultiList();

        /**
         * Returns the count of selected rows.
         */
        int     GetSelectCount();

        /**
         * Returns whether a row, identified by its index is selected or not.
         * @param iRowIndex
         * the index of the row.
         */
        CATBool IsSelect( int iRowIndex);

        /**
         * Returns whether a row, identified by its index is selected or not.
         */
        CATBool IsSelect( int nColumn, const CATUnicodeString& rString);

        /**
         * Returns the count of selected rows in the multilist and their row indices.
         * The size of the array should be defined by the method @href #GetSelectCount
         * @param ioTabRow
         * an array of row indices.
         * @param iSize
         * the size of the array.
         * @return
         * the number of selected rows.
         */
        int     GetSelect( int *ioTabRow, int iSize);

        /**
         * Returns the count of selected rows in a column of the multilist and their string values.
         * The size of the array should be defined by the method @href #GetSelectCount
         * @param iColumnIndex
         * a column index.
         * @param ioTabString
         * an array of strings to look up in the column.
         * @param iSize
         * the size of the array.
         * @return
         * the number of selected rows.
         */
        int     GetSelect( int iColumnIndex, CATUnicodeString *ioTabString, int iSize);

        /**
         * Returns the column index of the selected column.
         */
        int     GetSelectedColumn();

        /**
         * Clears the selection.
         */
        void    ClearSelect( );

        /**
         * Selects several rows of the multilist identified by their row indices.
         * @param iTabRow
         * an array of row indices to select.
         * @param iSize
         * the size of the array.
         * @param iNotify
         * Whether to trigger the <tt>GetListSelectNotification</tt>or not.
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>0</tt><dd> do not trigger the notification. </dd></dt>
         * <dt><tt>1</tt><dd> trigger the notification (default). </dd></dt>
         * </dl>
         * @return
         * the number of actually selected rows.
         */
        int     SetSelect( int *iTabRow , int iSize, int iNotify=1);

        /**
         * Selects several rows of the multilist identified by a column index and the
         * string values to look up in the row.
         * @param iColumnIndex
         * a column index.
         * @param iTabString
         * an array of strings to look up in the column.
         * @param iSize
         * the size of the array.
         * @param iNotify
         * Whether to trigger the <tt>GetListSelectNotification</tt>or not.
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>0</tt><dd> do not trigger the notification. </dd></dt>
         * <dt><tt>1</tt><dd> trigger the notification (default). </dd></dt>
         * </dl>
         * @return
         * the number of actually selected rows.
         */
        int     SetSelect( int iColumnIndex, CATUnicodeString *iTabString, int iSize, int iNotify=1);

        /**
         * Returns the row index under the cursor when a contextual menu is activated.
         */
        int     GetContextualLine();

        /**
         * Returns the column index under the cursor when a contextual menu is activated.
         */
        int     GetContextualColumn();

        /**
         * Sets whether the cells in a column identified by its index are editable.
         * @param iColumnIndex
         * the index of the column
         * @param iEditable
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>TRUE</tt><dd> the column cells are editable. </dd></dt>
         * <dt><tt>FALSE</tt><dd> the column cells are not editable. </dd></dt>
         * </dl>
         */
        void    SetColumnEditable(int iColumnIndex, int iEditable);

        /**
         * Sets whether the cells in a row identified by its index are editable.
         * @param iRowIndex
         * the index of the row
         * @param iEditable
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>TRUE</tt><dd> the row cells are editable. </dd></dt>
         * <dt><tt>FALSE</tt><dd> the row cells are not editable. </dd></dt>
         * </dl>
         */
        void    SetRowEditable(int iRowIndex, int iEditable);

        /**
         * Returns the coordinates of the cell which has been edited.
         * @param oRowIndex
         * the row index of the cell.
         * @param oColumnIndex
         * the column index of the cell.
         * @return
         * a boolean which indicates if there is currently an edited cell.
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>TRUE</tt><dd> there is an edited cell. </dd></dt>
         * <dt><tt>FALSE</tt><dd> there is no edited cell. </dd></dt>
         * </dl>
         */
        int     GetModifiedCell( int &oRowIndex, int &oColumnIndex );

        /**
         * Returns the count of columns.
         */
        int     GetColumnCount();

        /**
         * Sets the title of the multilist columns.
         * @param iArraySize
         * the size of the title array.
         * @param iTitleArray
         * an array of column titles.
         */
        void    SetColumnTitles( int iArraySize , CATUnicodeString *iTitleArray );

        /**
         * Hides or shows a column identified by its index.
         * @param iColumnIndex
         * the index of the column
         * @param iVisibility
         * a column visibility status
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>CATDlgShow</tt><dd> Show the column. </dd></dt>
         * <dt><tt>CATDlgHide</tt><dd> Hide the column. </dd></dt>
         * </dl>
         */
        void    SetColumnVisibility(int iColumnIndex, CATULong iVisibility);

        /**
         * Returns whether a column identified by its index is visible or hidden.
         * @param iColumnIndex
         * the index of the column
         * @return
         * a column visibility status
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>CATDlgShow</tt><dd> Show the column. </dd></dt>
         * <dt><tt>CATDlgHide</tt><dd> Hide the column. </dd></dt>
         * </dl>
         */
        CATULong GetColumnVisibility(int iColumnIndex);

        /**
         * Reorder a set of contiguous columns contained by the multilist.
         * @param iNewPosTab
         *  an array of integers which describes at which position the column
         *  currently at index <tt>0..iSize - 1</tt>should wind up.
         * @param iTabSize
         *  the size of the integer array.
         * @iFrom
         *  the column index of the first column to reorder.
         */
        void ReorderColumns(int *iNewPosTab, int iTabSize,int iFrom=0);

        /**
         * Synchronize another multilist with the receiver. Scrolling on the receiver
         * will be applied to the other multilist too.
         * @param iList
         * the other list.
         */ 
        void Synchronize(CATDlgMultiList *iList);


        /**
         * Returns the count of rows.
         */
        int  GetLineCount();

        /**
         * Returns the string in a cell identified by its row and column.
         * @param iColumnIndex
         * the column index of the cell.
         * @param oString
         * the string value of the cell.
         * param iRowIndex
         * the row index of the cell.
         */
        void GetColumnItem( int iColumnIndex, CATUnicodeString& oString, int iRowIndex );

        /**
         * Sets string value of a cell identified by its row and column,
         * or creates the cell.
         * @param iColumnIndex
         * the column index of the cell.
         * @param iString
         * the string value of the cell.
         * @param iRowIndex
         * the row index of the cell.
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>-1</tt><dd> the cell is appended to the multilist. </dd></dt>
         * <dt><tt>valid row index</tt><dd> the cell is placed at the specified row index. </dd></dt>
         * </dl>
         * @param iMode
         * a mode which describes how to alter the contents of the cell.
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>CATDlgDataAdd</tt><dd> the cell is created. </dd></dt>
         * <dt><tt>CATDlgDataModify</tt><dd> the cell is modified. </dd></dt>
         * </dl>
         * @return
         * the count of selected rows.
         */
        int  SetColumnItem( int iColumnIndex, const CATUnicodeString& iString, int iRowIndex=-1, CATULong iMode=CATDlgDataAdd );

        /**
         * Sets string value of several consecutive cells on a row identified by its index.
         * @param iColumnIndex
         * the column index of the first cell.
         * @param iStringArray
         * an array of strings.
         * @param iStringArraySize
         * the size of the array.
         * @param iRowIndex
         * the row index of the cells.
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>-1</tt><dd> the cells are appended to the multilist. </dd></dt>
         * <dt><tt>valid row index</tt><dd> the cells are placed at the specified row indices. </dd></dt>
         * </dl>
         * @param iMode
         * a mode which describes how to alter the contents of the cells.
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>CATDlgDataAdd</tt><dd> the cells are created. </dd></dt>
         * <dt><tt>CATDlgDataModify</tt><dd> the cells are modified. </dd></dt>
         * </dl>
         * @return
         * the count of selected rows.
         */
        int  SetColumnItems( int iColumnIndex, const CATUnicodeString* iStringArray, int iStringArraySize, int iRowIndex=-1, CATULong iMode=CATDlgDataAdd );

        /**
         * Sets string value and icon value of a cell identified by its row and column,
         * or creates the cell.
         * @param iColumnIndex
         * the column index of the cell.
         * @param iString
         * the string value of the cell.
         * @param iIconName
         * the name of the icon.
         * @param iRowIndex
         * the row index of the cell.
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>-1</tt><dd> the cell is appended to the multilist. </dd></dt>
         * <dt><tt>valid row index</tt><dd> the cell is placed at the specified row index. </dd></dt>
         * </dl>
         * @param iMode
         * a mode which describes how to alter the contents of the cell.
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>CATDlgDataAdd</tt><dd> the cell is created. </dd></dt>
         * <dt><tt>CATDlgDataModify</tt><dd> the cell is modified. </dd></dt>
         * </dl>
         * <br>
         * <b>Limitations:</b>
         * <dl>
         * <dt><dd>The column index must be different from 0.</dd></dt>
         * <dt><dd>The size of the icon must be 16x16.</dd></dt>
         * <dt><dd>For performance reasons, avoid using the icons in too many different columns.</dd></dt>
         * </dl>
         * @return
         * the count of selected rows.
         */
        int  SetColumnItem( int iColumnIndex, const CATUnicodeString& iString, const CATString& iIconName, int iRowIndex=-1, CATULong iMode=CATDlgDataAdd );

        /**
         * Removes a row indentified by its index from the multilist.
         * @param iRowIndex
         * the index of the row to remove.
         */ 
        void ClearLine( int iRowIndex );

        /**
         * Removes a list of rows indentified by their indices from the multilist.
         * @param iRowIndices
         * an array of row indices.
         * @param iRowIndicesCount
         * the size of the array.
         */ 
        void ClearLine( int *iRowIndices, int iRowIndicesCount );

        /**
         * Removes all the rows from the multilist.
         */ 
        void ClearLine( );

        /**
         * Returns the width of a given column in pixels.
         * @param iColumnIndex
         * the index of the column.
         */
        int  GetColumnPixelWidth(int iColumnIndex);

        /**
         * Sets the width of a given column in pixels.
         * @param iColumnIndex
         * the index of the column.
         * @param iPixelWidth
         * the width of the column, in pixels.
         */
        void SetColumnPixelWidth(int iColumnIndex, int iPixelWidth);

        /**
         * Returns the width of a given column in characters.
         * @param iColumnIndex
         * the index of the column.
         */
        int  GetColumnTextWidth(int iColumnIndex);

        /**
         * Sets the width of a given column in characters.
         * @param iColumnIndex
         * the index of the column.
         * @param iTextWidth
         * the width of the column, in characters.
         */
        void SetColumnTextWidth(int iColumnIndex, int iTextWidth);

        /**
         * Returns the total width of the multilist, in characters.
         */
        int  GetVisibleTextWidth();

        /**
         * Sets the total width of the multilist, in characters.
         * This method is not taken into account if SetVisibleColumnCount is called.
         * @param iTextWidth
         * the width of the multilist, in characters.
         */
        void SetVisibleTextWidth( int iTextWidth);

        /**
         * Returns count of currently visible rows.
         */
        int  GetVisibleLineCount();

        /**
         * Set the count of visible rows.
         * @param iRowCount
         * the count of visible rows.
         */
        void SetVisibleLineCount( int iRowCount);

        /**
         * Returns the index of the first visible row.
         */
        int GetFirstLine();

        /**
         * Scroll the list to make the specified row the first visible row.
         * @param iRowIndex
         * the index of the row which should become the first visible row.
         */
        int  SetFirstLine( int iRowIndex);

        /**
         * Set the width of the rectangle occupied by the multilist. 
         * This width is defined on the basis of the provided argument and of the actual widths of the columnns.
         * If called, this method overrides the width that may be provided through SetVisibleTextWidth.
         * @param iColumnCount
         * the count of visible columns.
         */
        void SetVisibleColumnCount(int iColumnCount);

        /**
         * Returns the number of visible columns.
         */
        int  GetVisibleColumnCount();

        /**
         * Set the display state of the titles of the multilist columns.
         * @param iState
         * The visibility state to set.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgShow</tt><dd> to show the titles,
         *   <dt><tt>CATDlgHide</tt><dd> to hide the titles.
         *   </dl>
         */
        void SetTitlesVisibility( CATULong iState);

        /**
         * Returns whether the titles of the multilist columns are visible or hidden.
         * @return
         * a titles visibility status
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>CATDlgShow</tt><dd> the titles are visible. </dd></dt>
         * <dt><tt>CATDlgHide</tt><dd> the titles are hidden. </dd></dt>
         * </dl>
         */
        CATULong GetTitlesVisibility();

        /**
         * Returns the title of a multilist column identified by its index.
         * @param iColumnIndex
         * the column index.
         * @param oString
         * the string value of the title.
         */
        void GetColumnTitle( int iColumnIndex, CATUnicodeString& oString);

        /**
         * Returns the event notification sent whenever the multilist selection changes.
         */
        CATNotification *GetListSelectNotification() const;

        /**
         * Returns the event notification sent whenever a line (and a cell) is double clicked.
         */
        CATNotification *GetListActivateNotification() const;

        /**
         * Returns the event notification sent whenever a multilist column is selected.
         */
        CATNotification *GetListColumnActivateNotification() const;

        /**
         * Returns the event notification sent whenever a multilist cell is modified.
         */
        CATNotification *GetListCellModifyNotification() const;

        /**
         * @nodoc
         * Returns the event notification sent whenever a multilist is clicked.
         */
        CATNotification *GetListSingleClickNotification() const;

        /**
         * Sets the sort method.
         * @param iColumnIndex
         * the index of the column.
         * @param iSortOrder
         * the sort mode.
         * <br>
         * <b>Legal values:</b>
         * <ul>
         * <li><tt>AlphabeticalOrder</tt> The sort is alphabetical, default.</li> 
         * <li><tt>NumericalOrder</tt> The sort is numerical.</li> 
         * <li><tt>UserDefinedOrder</tt> The sort is defined by the function provided as 3rd argument.</li> 
         * </ul>
         * @param ptrSortMethod
         * the applicative function to define how to compare two cells.
         * This parameter is ignored if the CATDlgLstSortOrder is different from UserDefinedOrder.
         * The function must return a negative value if its first argument is less than its second,
         * a zero if equal, and a positive value if greater.
         */
        void SetColumnSortMethod(int iColumnIndex, CATDlgLstSortOrder iSortOrder, CATDlgMultiListSortMethod ptrSortMethod=NULL);

        /**
         * Sorts a column in the multilist.
         * @param iColumnIndex
         * the index of the column.
         */
        void SortColumn(int iColumnIndex);

        /**
         * Edits a cell in the multilist.
         * @param iRowIndex
         * the index of the row.
         * @param iColumnIndex
         * the index of the column.
         * @param iEditable
         * <br>
         * <b>Legal values:</b>
         * <dl>
         * <dt><tt>TRUE</tt><dd> the cell turns to edit mode. </dd></dt>
         * <dt><tt>FALSE</tt><dd> the cell is not any more editable. </dd></dt>
         * </dl>
         */
        void EditCell( int iRowIndex, int iColumnIndex, int iEditable);

        /**
         * @nodoc
         * Sets the Read/Only Mode
         */
        void SetReadOnlyMode(int iReadOnlyMode);

        /**
         * @nodoc
         * Get internal object.
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
         * Address of internal object.
         */
         l_CATDlgMultiList* _frameMultiList;

         /** @nodoc */
         CATDlgMultiList_ADD
};

/** @nodoc */
CATDlgMultiList_LateADD

#endif
