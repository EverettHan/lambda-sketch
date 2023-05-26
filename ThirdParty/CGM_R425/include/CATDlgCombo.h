#ifndef CATDLGCOMBO_H
#define CATDLGCOMBO_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDlgControl.h"


class CATString;
class CATUnicodeString;
class l_CATDialog;
class l_CATDlgCombo;

#ifndef CATDlgCombo_ADD
/** @nodoc */
#define CATDlgCombo_ADD
#endif

#ifndef CATDlgCombo_LateADD
/** @nodoc */
#define CATDlgCombo_LateADD
#endif

/**
* Callback function for a CATDlgCombo.
* @see  CATDlgCombo#SetInputCallback
*/
typedef int (*CATDlgComboCallback)(const CATUnicodeString &, void *);


/** 
 * Base class for combo boxes.
 * <b>Role</b>:
 * The combo allows the end user to choose a value or an option by selecting a character string from a predefined list,
 * or through a keyboard entry.
 * <br>
 * Use a combo whenever you propose to the end user to select an alphanumerical value from a discrete list,
 * or enter an alphanumerical value to update a discrete list. 
 */
class ExportedByDI0PANV2 CATDlgCombo : public CATDlgControl
{

 public:

       /** 
        * Constructs a CATDlgCombo.
        * @param iParent
        *   The parent of the combo box.
        * @param iObjectName
        *   The name of the combo box.
        * @param iStyle
        *   The style of the combo box.
        * The style can be :
        *   <dl>
        *   <dt><tt>default</tt><dd> if no value is passed, for the standard combo, 
        * composed of an entry zone which displays the selected value, and a list permanently displayed.
        *   <dt><tt>CATDlgCmbDropDown</tt><dd> for the drop down combo, composed of an entry zone which displays 
        * the selected value, and the list of values to select in, displayed when the arrow located on the right 
        * of the entry zone is selected.
        *   <dt><tt>CATDlgCmbOptionStyle</tt><dd> for the option style combo. On UNIX, it is very close to the 
        * drop down combo, with a Motif style. On Windows, this style is equivalent to <tt>CATDlgCmbDropDown</tt> combo.        
        *   <dt><tt>CATDlgCmbEntry</tt><dd> to allow keyboard text entry in addition to text selection
        * for drop down and standard combos.
        *   <dt><tt>CATDlgCmbDouble</tt><dd> if the entered number must be a double precision floating number.
        *   <dt><tt>CATDlgCmbColor</tt><dd> to show a color palette. Available in conjunction with <tt>CATDlgCmbDropDown</tt> only.
        *   <dt><tt>CATDlgCmbLineType</tt><dd> to show a linetype palette. Available in conjunction with <tt>CATDlgCmbDropDown</tt> only.
        *   <dt><tt>CATDlgCmbBitmap</tt><dd> to show an icon palette. Available in conjunction with <tt>CATDlgCmbDropDown</tt> only.
        *   </dl>
        */
        CATDlgCombo( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgCombo();

       /**
        * Returns the number of lines of the combo box.
        */
        int  GetLineCount();

       /**
        * Retrieves the contents of the line from its index (first line has 0 for index).
        * @param oLine
        * The returned contents of the specified line.
        * @param iIndex
        * The index of the line.
        */
        void GetLine( CATUnicodeString& oLine, int iIndex );

       /**
        * Returns the contents of the line from its index, for <tt>CATDlgCmbDouble</tt> style only (first line has 0 for index).
        * @param iIndex
        * The index of the line.
        */
        double GetLine( int iIndex );

       /**
        * Adds or modifies one line containing a string.
        * @param iLine
        * The contents of the line to add or modify.
        * @param iIndex
        * The index to specify where to add the new line or which line to modify.
        * If no value is passed, new lines are added at the end of the list.
        * @param iModeAddOrModify
        * The mode to specify whether you add a new line (<tt>CATDlgDataAdd</tt> set by default) or
        * you modify an existing line (<tt>CATDlgDataModify</tt>).
        * @return the index of the first added or modified line in the list.
        */
        int  SetLine( const CATUnicodeString& iLine, int iIndex=-1, CATULong iModeAddOrModify=CATDlgDataAdd );

       /**
        * Adds or modifies several lines containing strings.
        * @param iLinesArray
        * The contents of the lines to add.
        * @param iNbLines
        * The number of lines to add.
        * @param iIndex
        * The index to specify where to add the new lines or which line to modify.
        * If no value is passed, new lines are added at the end of the list.
        * @param iModeAddOrModify
        * The mode to specify whether you add a new line (<tt>CATDlgDataAdd</tt> set by default) or
        * you modify an existing line (<tt>CATDlgDataModify</tt>).
        * @return the index of the first added or modified line in the list.
        */
        int  SetLine( const CATUnicodeString* iLinesArray, int iNbLines, int iIndex=-1, CATULong iModeAddOrModify=CATDlgDataAdd );

       /**
        * Adds or modifies one line containing a double.
        * @param iVal
        * The contents of the line to add or modify (for <tt>CATDlgCmbDouble</tt> style only).
        * @param iIndex
        * The index to specify where to add the new line or which line to modify.
        * If no value is passed, new lines are added at the end of the list.
        * @param iModeAddOrModify
        * The mode to specify whether you add a new line (<tt>CATDlgDataAdd</tt> set by default) or
        * you modify an existing line (<tt>CATDlgDataModify</tt>).
        * @return the index of the first added or modified line in the list.
        */
        int  SetLine( double iVal, int iIndex=-1, CATULong iModeAddOrModify=CATDlgDataAdd );

       /**
        * Adds or modifies several lines containing doubles.
        * @param iValArray
        * The contents of the lines to add (for <tt>CATDlgCmbDouble</tt> style only).
        * @param iNbLines
        * The number of lines to add.
        * @param iIndex
        * The index to specify where to add the new lines or which line to modify.
        * If no value is passed, new lines are added at the end of the list.
        * @param iModeAddOrModify
        * The mode to specify whether you add a new line (<tt>CATDlgDataAdd</tt> set by default) or
        * you modify an existing line (<tt>CATDlgDataModify</tt>).
        * @return the index of the first added or modified line in the list.
        */
        int  SetLine( const double* iValArray, int iNbLines, int iIndex=-1, CATULong iModeAddOrModify=CATDlgDataAdd );

       /**
        * Adds or modifies one line containing a colored rectangle and a string.
        * @param iVal
        * The contents of the line to add or modify.
        * @param iRed,iGreen,iBlue
        * The RGB composants of the color of the specified line.
        * @param iIndex
        * The index to specify where to add the new line or which line to modify.
        * If no value is passed, new lines are added at the end of the list.
        * @param iModeAddOrModify
        * The mode to specify whether you add a new line (<tt>CATDlgDataAdd</tt> set by default) or
        * you modify an existing line (<tt>CATDlgDataModify</tt>).
        * @return the index of the first added or modified line in the list.
        */
        int  SetLine( const CATUnicodeString& iVal, unsigned char iRed, unsigned char iGreen, unsigned char iBlue,
                      int iIndex=-1, CATULong iModeAddOrModify=CATDlgDataAdd );

       /**
        * Retrieves the contents of the line from its index (first line has 0 for index).
        * @param oVal
        * The returned contents of the specified line.
        * @param oRed,oGreen,oBlue
        * The returned RGB composants of the color of the specified line.
        * @param iIndex
        * The index of the line.
        */
        void GetLine( CATUnicodeString& oVal, unsigned char& oRed, unsigned char& oGreen, unsigned char& oBlue, int iIndex);

       /**
        * Adds or modifies one line containing a drawn line and a string.
        * @param iVal
        * The contents of the line to add or modify.
        * @param iMask
        * The mask.
        * @param iRepet
        * The number of pixels for each bit of the mask.
        * @param iWeight
        * The height of the line (in pixels).
        * @param iIndex
        * The index to specify where to add the new line or which line to modify.
        * If no value is passed, new lines are added at the end of the list.
        * @param iModeAddOrModify
        * The mode to specify whether you add a new line (<tt>CATDlgDataAdd</tt> set by default) or
        * you modify an existing line (<tt>CATDlgDataModify</tt>).
        * @return the index of the first added or modified line in the list.
        */
        int  SetLine( const CATUnicodeString& iVal, unsigned short iMask, unsigned short iRepet, unsigned short iWeight,
                      int iIndex=-1, CATULong iModeAddOrModify=CATDlgDataAdd );

       /**
        * Retrieves the contents of the line from its index (first line has 0 for index).
        * @param oVal
        * The returned contents of the specified line.
        * @param oMask
        * The returned mask.
        * @param oRepet
        * The returned number of pixels for each bit of the mask.
        * @param oWeight
        * The returned height of the line (in pixels).
        * @param iIndex
        * The index of the line.
        */
        void GetLine( CATUnicodeString& oVal, unsigned short& oMask, unsigned short& oRepet, unsigned short& oWeight,
                      int iIndex);

       /**
        * Adds or modifies one line containing a monochrome icon and a string.
        * @param iVal
        * The contents of the line to add or modify.
        * @param iBitmap
        * The monochrome bitmap representing the icon.
        * The length expected is (iWidth+7)/8 * iHeight
        * @param iWidth
        * The width of the icon.
        * @param iHeight
        * The height of the icon.
        * @param iIndex
        * The index to specify where to add the new line or which line to modify.
        * If no value is passed, new lines are added at the end of the list.
        * @param iModeAddOrModify
        * The mode to specify whether you add a new line (<tt>CATDlgDataAdd</tt> set by default) or
        * you modify an existing line (<tt>CATDlgDataModify</tt>).
        * @return the index of the first added or modified line in the list.
        */
        int  SetLine( const CATUnicodeString& iVal, const char* iBitmap, int iWidth, int iHeight,
                      int iIndex=-1, CATULong iModeAddOrModify=CATDlgDataAdd );

       /**
        * Retrieves the contents of the line from its index (first line has 0 for index).
        * @param oVal
        * The returned contents of the specified line.
        * @param oBitmap
        * The returned bitmap representing the icon.
        * @param oWidth
        * The returned width of the icon.
        * @param oHeight
        * The returned height of the icon.
        * @param iIndex
        * The index of the line.
        */
        void GetLine( CATUnicodeString& oVal, char* oBitmap, int& oWidth, int& oHeight, int iIndex);

       /**
        * Adds or modifies one line containing an icon and optionally a string.
        * @param iVal
        * The contents of the line to add or modify.
        * @param iIcon
        * The name of the icon.
        * @param iIndex
        * The index to specify where to add the new line or which line to modify.
        * If no value is passed, new lines are added at the end of the list.
        * @param iModeAddOrModify
        * The mode to specify whether you add a new line (<tt>CATDlgDataAdd</tt> set by default) or
        * you modify an existing line (<tt>CATDlgDataModify</tt>).
        * @return the index of the first added or modified line in the list.
        */
        int  SetLine( const CATUnicodeString& iVal, const CATString& iIcon, int iIndex=-1, CATULong iModeAddOrModify=CATDlgDataAdd );

       /**
        * Retrieves the contents of the line from its index (first line has 0 for index).
        * @param oVal
        * The returned contents of the specified line.
        * @param oIcon
        * The returned name of the icon.
        * @param iIndex
        * The index of the line.
        */
        void GetLine( CATUnicodeString& oVal, CATString& oIcon, int iIndex);
 
       /**
        * Deletes the line specified by the index passed in argument (first line has 0 for index).
        * @param iIndex
        * The index of the line to delete.
        */
        void ClearLine( int iIndex);

       /**
        * Deletes the lines specified by the array of index passed in argument (first line has 0 for index).
        * @param iLinesToClear
        * The array of index of the lines to delete.
        * @param iNumberOfLinesToClear
        * The number of lines to delete.
        */
        void ClearLine( int *iLinesToClear, int iNumberOfLinesToClear );

       /**
        * Deletes all the lines.
        */
        void ClearLine( );

       /**
        * Returns the number of visible characters in the entry zone.
        */
        int  GetVisibleTextWidth();

       /**
        * Sets the number of visible characters in the entry zone.
        * @param iColumns
        * The number of visible character to set for the entry zone.
        */
        void SetVisibleTextWidth( int iColumns);

       /**
        * Returns the number of visible lines of the combo box.
        */
        int  GetVisibleTextHeight();

       /**
        * Sets the number of visible lines of the combo box.
        * @param iRows
        * The number of visible lines to set for the combo box.
        */
        void SetVisibleTextHeight( int iRows);

       /**
        * Returns the number of visible characters in dropdown window.
        */
        int  GetDropDownTextWidth();

       /**
        * Sets the number of visible characters in dropdown window.
        * Under Windows, this value is ignored given that the dropdown window is dimensioned to accomodate both the actual max line width and the size available on the display monitor.
        * @param iColumns
        * The number of visible characters to set.
        */
        void SetDropDownTextWidth( int iColumns);

       /**
        * Returns the selected line number.
        */
        int  GetSelect();

       /**
        * Clears the selection and reinitializes the selected line number.
        */
        void ClearSelect();

       /**
        * Selects a line from its index (first line has 0 for index).
        * @param iIndex
        * The index of the line to select.
        * @param iNotify
        * Set this parameter to a non null value if you want the corresponding notification to be sent.
        * Otherwise set it to 0, so no notification will be sent. 
        * @return the index of the selected line.
        */
        int  SetSelect( int iIndex, int iNotify=1);

       /**
        * Selects a line from its contents.
        * @param iString
        * Contents of the line to select.
        * @param iNotify
        * Set this parameter to a non null value if you want the corresponding notification to be sent.
        * Otherwise set it to 0, so no notification will be sent. 
        * @return the index of the selected line.
        */
        int  SetSelect( const CATUnicodeString& iString, int iNotify=1);

       /**
        * Selects a line from its double contents.
        * @param iVal
        * Contents of the line to select (for <tt>CATDlgCmbDouble</tt> style only).
        * @param iNotify
        * Set this parameter to a non null value if you want the corresponding notification to be sent.
        * Otherwise set it to 0, so no notification will be sent. 
        * @return the index of the selected line.
        */
        int  SetSelect( double iVal, int iNotify=1);

       /**
        * Retrieves the keyboard entry field.
        * @param oEntry
        * The returned entry field.
        */
        void GetField( CATUnicodeString& oEntry);

       /**
        * Returns the keyboard entry field for a double combo.
        */
        double GetField();

       /**
        * Sets the keyboard entry field with a string.
        * @param iEntry
        * The entry field to set.
        */
        void SetField( const CATUnicodeString& iEntry);

       /**
        * Sets the keyboard entry field for a double combo.
        * @param iEntry
        * The entry field to set.
        */
        void SetField( double iEntry);

       /**
        * Clears the keyboard entry field.
        */
        void ClearField();

       /**
        * Declares your own function to execute when a character is entered.
        * <br><b>Role</b>: Declares your own function to execute when a 
        * character is entered. Enables to declare an exit to verify 
        * the input character. This method is relevant for CATDlgCmbEntry style combos
        * only. 
        * @param iCheckingFunction
        *   The applicative function to check the input character.
        * @param iUsefulData
        *   The data that will be transmited to the application when calling
        *   its function. It is the contents of the field casted as a pointer 
        *   to void. 
        */
        void SetInputCallback(CATDlgComboCallback iCheckingFunction, 
                              void * iUsefulData);

       /**
        * Returns the event notification sent whenever a value is selected in the list.
        */
        CATNotification *GetComboSelectNotification() const;

       /**
        * Returns the event notification sent whenever the keyboard entry is modified by selection.
        */
        CATNotification *GetComboModifyNotification() const;

       /**
        * Returns the event notification sent whenever the keyboard entry is modified by pressing the "Enter" key.
        */
        CATNotification *GetComboModifyExtNotification() const;

       /**
        * Returns the event notification sent whenever the list of values is displayed.
        */
        CATNotification *GetComboDropNotification() const;

       /**
        * Returns the event notification sent whenever the list of values is hidden
        */
        CATNotification *GetComboCloseUpNotification() const;

       /**
        * Returns the event notification sent whenever the keyboard entry is modified by editing.
        */
        CATNotification *GetEditModifyNotification() const;

       /**
        * Returns the event notification sent whenever a combo is clicked.
        */
        CATNotification *GetComboSingleClickNotification() const;

       /**
        * Returns the index of the selected string if this string exists in the combo.
        * @param iString
        *   The selected string.
        * @return The index of the string or -1 if the string does not exist in the combo.
        */
        int  Locate( const CATUnicodeString& iString );

       /**
        * @nodoc
        * Returns the internal object.
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

 private:

       /**
        * @nodoc
        * Address of the internal object.
        */
        l_CATDlgCombo* _frameCombo;

        /** @nodoc */
        CATDlgCombo_ADD
};

/** @nodoc */
CATDlgCombo_LateADD

#endif
