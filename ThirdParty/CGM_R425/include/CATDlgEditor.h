#ifndef CATDLGEDITOR_H
#define CATDLGEDITOR_H

// COPYRIGHT DASSAULT SYSTEMES 1996

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Abstract: The base class for input fields
//
//------------------------------------------------------------------------------
// Usage:    Like any control, assign CATDlgEditor to any container or window.
//------------------------------------------------------------------------------
// Inheritance: CATDlgEditor
//                CATDlgControl
//                  CATDialog
//------------------------------------------------------------------------------
// Main methods:
//
//           GetLineCount               get number of rows
//           GetLine                    get row content
//           SetLine                    set row content
//           ClearLine                  reset row content
//           SetMaxCharacterWidth       set maximum number of characters
//           GetMaxCharacterWidth       get maximum number of characters
//           SetVisibleTextWidth        set number of visible columns
//           GetVisibleTextWidth        get number of visible columns
//           SetVisibleTextHeight       set number of visible rows
//           GetVisibleTextHeight       get number of visible rows
//           SetFirstLine               set row number of first visible row
//           GetFirstLine               get row number of first visible row
//           SetFirstColumn             set column number of first visible column
//           GetFirstColumn             get column number of first visible column
//           GetText                    get global text
//           SetText                    set global text
//           SetIntegerValue            set value for integer precision editors
//           GetIntegerValue            get value in the integer format
//           SetFloatValue              set value for float precision editors
//           GetFloatValue              get value in the floating point format
//           SetVerifyCallback          declare an exit to verify input string
//           SetInputCallback           declare an exit for input characters
//           SetValue                   set value for double precision editors
//           GetValue                   get value for double precision editors
//           SetSelection               selection of a range of characters
//           GetSelection               get current selection
//------------------------------------------------------------------------------
// Events:
//
//           GetEditModifyNotification       modification of entry field
//           GetSelectionChangeNotification  selection change in entry field
//           GetEditFocusInNotification      get keyboard focus
//           GetEditFocusOutNotification     lose keyboard focus
//------------------------------------------------------------------------------
// Styles:
//
//           CATDlgEdtReadOnly
//           CATDlgEdtMultiline
//           CATDlgEdtWrap
//           CATDlgEdtPassword          ( only for monoline editors )
//           CATDlgEdtInteger           id
//           CATDlgEdtFloat             id
//           CATDlgEdtAlphabetical      id
//           CATDlgEdtNumerical         id
//           CATDlgEdtAlphanumerical    id
//           CATDlgEdtDouble            Double precision field with unit
//           CATDlgEdtNoScrollBar       Multiline editor without scrollbar
//           CATDlgEdtStealFocus        Automatically gets focus 
//           CATDlgEdtNoCR              Multiline editor without carriage return characters
//------------------------------------------------------------------------------

//--------------------------------------------------------------------------
#include "CATBoolean.h"
#include "CATDlgControl.h"

//--------------------------------------------------------------------------
class CATString;
class CATUnicodeString;
class l_CATDialog;
class l_CATDlgEditor;
class CATDlgSYPInterval;
class CATDlgSYPColor;


#ifndef CATDlgEditor_ADD
/** @nodoc */
#define CATDlgEditor_ADD
#endif

#ifndef CATDlgEditor_LateADD
/** @nodoc */
#define CATDlgEditor_LateADD
#endif

/**
* Callback function for a CATDlgEditor.
* @see  CATDlgEditor#SetVerifyCallback, CATDlgEditor#SetInputCallback
*/
typedef int (*CATDlgEditorCallback)(const CATUnicodeString &, void *);


/**
 * Class to enable characters to be entered.
 * <b>Role</b>: Enables characters to be entered.
 * It allows the end user to enter a text, numerics, or both, 
 * or modify existing ones. The text can extend on one or several 
 * lines. Scrollbars can be added if the text is longer than the 
 * editor display area. Use editor whenever you propose to the 
 * end user to edit or modify a text or unpredictable numerical 
 * values. 
 * Usually you will instanciate this class, however, you may
 * derive it for example if you want to specialize it using
 * the SetColor method.
 */

class ExportedByDI0PANV2 CATDlgEditor : public CATDlgControl
{

//--------------------------------------------------------------------------
 public:

//      constructor - destructor
/**
 * Constructs an input field.
 * <br><b>Role</b>: Constructs an input field. 
 * @param iParent
 *   The parent of the editor.
 * @param iDialogObjectName
 *   The dialog object name. 
 * @param iStyle
 *   The application window styles. You can cumulate several
 *   styles using a logical or.
 *   <br><b>Legal values</b>: <tt>NULL (default)</tt> so that the 
 *   text extend on a single line, or 
 *   <tt>CATDlgEdtMultiline</tt> if the text can extend on several
 *   lines, or <tt>CATDlgEdtReadOnly</tt> 
 *   if the text cannot be edited.
 *   <p>
 *   For single line editors only, you can use also:
 *   <tt>CATDlgEdtPassword</tt> if the text is hidden, or 
 *   <tt>CATDlgEdtInteger</tt> if the text must be an integer, or 
 *   <tt>CATDlgEdtFloat</tt> if the text must be a float, or 
 *   <tt>CATDlgEdtAlphabetical</tt> if the text must contain only 
 *   alphabetical characters, or 
 *   <tt>CATDlgEdtNumerical</tt> if the text must contain only 
 *   numerical characters, or 
 *   <tt>CATDlgEdtAlphanumerical</tt> if the must contain only 
 *   alphanumerical characters, or 
 *   <tt>CATDlgEdtDouble</tt> if the text must be a double, 
 *   expressed in the chosen unit.
 *   <p>
 *   For multiple line editors only, you can use also:
 *   <tt>CATDlgEdtWrap</tt> if the text automatically skips to 
 *   the next line, or 
 *   <tt>CATDlgEdtNoScrollBar</tt> if the editor has no 
 *   scrollbars, or 
 *   <tt>CATDlgEdtNoCR</tt> if the text doesn' include carriage 
 *   return characters.
 */
        CATDlgEditor( CATDialog *iParent, 
                      const CATString& iDialogObjectName, 
                      CATDlgStyle iStyle=NULL);
/**
 * @nodoc 
 */
        virtual ~CATDlgEditor();

//      content management
/**
 * Get the line count.
 * @return
 *   The line count.
 */
        int  GetLineCount();
/**
 * Extracts a line for a multiple line editor.
 * <br><b>Role</b>: Extracts a line from the current multiple line editor.
 * @param oLine
 *   The line extracted.
 * @param iIndex
 *   The index of the line to extract. 
 *   An index ranges from 0 to the line count - 1. 
 */
        void GetLine( CATUnicodeString& oLine, int iIndex=-1 );
/**
 * Sets a line contents for a multiple line editor.
 * <br><b>Role</b>: Sets a line contents in the current multiple line editor.
 * @param iLine
 *   The line.
 * @param iIndex
 *   The line index. 
 *   <br><b>Legal values</b>: <tt>-1</tt> so that the provided string
 *   be added as a new line to the current multiple line editor, or 
 *   <tt>Other (from 0 to the line count - 1)</tt> for the index itself.
 * @return 
 *   The line count. 
 */
        int  SetLine( const CATUnicodeString& iLine, int iIndex=-1 );
/**
 * Reset the context of a line.
 * <br><b>Role</b>: Reset the contents of a line contents (multiple line 
 * editor case), or the contents of the text (single line editor case).
 * @param iLineIndex
 *   The line index.
 *   An index ranges from 0 to the line count - 1. 
 */
        void ClearLine( int iLineIndex=-1 );
/**
 * Set the maximum character count that a line can contain.
 * @param iMaximumCharacterCount
 *   The maximum character count that a line can contain.
 */
        void SetMaxCharacterWidth( int iMaximumCharacterCount);
/**
 * Get the maximum character count that a line can contain.
 * @return
 *   The maximum character count that a line can contain.
 */
        int  GetMaxCharacterWidth( );
/**
 * Sets the text in a single line editor.
 * @param iText
 *   The text.
 * @param iSendingNotificationFlag
 *   To specify if you want the CATDlgEditModifyNotification notification 
 *   to be sent. 
 *   <br><b>Legal values</b>: <tt>1</tt>: (or any non NULL value)
 *   if you want the notification to be sent, or <tt>NULL</tt> (default) otherwise.
 *   <br><b>Beware:</b> for upward compatibily reasons, the default value is not consistent
 *   with other methods.
 */
        void SetText( const CATUnicodeString &iText, int iSendingNotificationFlag=0 );
/**
 * Extracts the text from a single line editor.
 * @return
 *   The text extracted.
 */
        CATUnicodeString& GetText();
/**
 * Set value for integer precision editors.
 * <br><b>Role</b>: Set the value for a integer precision editor.
 * @param iIntegerValue
 *   The integer value.
 * @param iSendingNotificationFlag
 *   To specify if you want the CATDlgEditModifyNotification notification 
 *   to be sent. 
 *   <br><b>Legal values</b>: <tt>1</tt>: default (or any non NULL value)
 *   if you want the notification to be sent, or <tt>NULL</tt> otherwise.
 */
        void SetIntegerValue( int iIntegerValue, int iSendingNotificationFlag=1 );
/**
 * Get an integer from the contents of a line (multiple line editor case),
 * or from the contents of the text (single line editor case).
 * @return
 *   The integer.
 */
        int   GetIntegerValue();
/**
 * Set value for float precision editors.
 * <br><b>Role</b>: Set the value for a float precision editor.
 * @param iFloatValue
 *   The float value.
 * @param iSendingNotificationFlag
 *   To specify if you want the CATDlgEditModifyNotification notification 
 *   to be sent. 
 *   <br><b>Legal values</b>: <tt>1</tt>: default (or any non NULL value)
 *   if you want the notification to be sent, or <tt>NULL</tt> otherwise.
 */
        void SetFloatValue( float iFloatValue, int iSendingNotificationFlag=1 );
/**
 * Get an float from the contents of a line (multiple line editor case),
 * or from the contents of the text (single line editor case).
 * @return
 *   The float.
 */
        float GetFloatValue();
/**
 * Declare your own function to execute when a string is entered.
 * <br><b>Role</b>: Declare your own function to execute when a 
 * string is entered. Enables to declare an exit to verify 
 * the input string.
 * @param iCheckingFunction
 *   The applicative function to check the input string.
 * @param iUsefulData
 *   The data that will be transmited to the application when calling
 *   its function. It is the contents of the filed casted as a pointer 
 *   to void. 
 */
        void SetVerifyCallback(CATDlgEditorCallback iCheckingFunction, 
                               void * iUsefulData);
/**
 * Declare your own function to execute when a character is entered.
 * <br><b>Role</b>: Declare your own function to execute when a 
 * character is entered. Enables to declare an exit to verify 
 * the input character.
 * @param iCheckingFunction
 *   The applicative function to check the input character.
 * @param iUsefulData
 *   The data that will be transmited to the application when calling
 *   its function. It is the contents of the filed casted as a pointer 
 *   to void. 
 */
        void SetInputCallback(CATDlgEditorCallback iCheckingFunction, 
                              void * iUsefulData);
/**
 * Set value for double precision editors.
 * <br><b>Role</b>: Set the value for a double precision editor.
 * @param iDoubleValue
 *   The double value.
 * @param iSendingNotificationFlag
 *   To specify if you want the CATDlgEditModifyNotification notification 
 *   to be sent. 
 *   <br><b>Legal values</b>: <tt>1</tt>: default (or any non NULL value)
 *   if you want the notification to be sent, or <tt>NULL</tt> otherwise.
 */
        void SetValue( double iDoubleValue, int iSendingNotificationFlag=1 );
/**
 * Get value for double precision editors.
 * <br><b>Role</b>: Get the value for a double precision editor.
 * @return
 *   The double value.
 */
        double GetValue();

//      Layout management
/**
 * Get the visible text width.
 * @return
 *   The visible text width.
 */
        int  GetVisibleTextWidth();
/**
 * Set the visible text width.
 * @param iColumnCount
 *   The visible text width (column count).
 */
        void SetVisibleTextWidth( int iColumnCount);
/**
 * Get the visible text height.
 * @return
 *   The visible text height.
 */
        int  GetVisibleTextHeight();
/**
 * Set the visible text height.
 * @param iRowCount
 *   The visible text height (row count).
 */
        void SetVisibleTextHeight( int iRowCount);
/**
 * Get the position of the first visible line.
 * @return 
 *   The visible text first line.
 */
        int  GetFirstLine();
/**
 * Set the position of the first visible line.
 * @param iFirstVisibleLine
 *   The visible text first line.
 */
        int  SetFirstLine( int iFirstVisibleLine);
/**
 * Get the position of the first visible character in the line.
 * @return 
 *   The visible text first visible column.
 */
        int  GetFirstColumn();
/**
 * Set the position of the first visible character in the line.
 * @param iFirstVisibleColumn
 *   The visible text first visible column.
 */
        int  SetFirstColumn( int iFirstVisibleColumn);

/**
 * Set the current selected sub-string.
 * @param iFirstCharacterIndex
 *   The selected sub-string first character index.
 * @param iLastCharacterIndex
 *   The selected sub-string last character index.
 */
        void SetSelection(int iFirstCharacterIndex, int iLastCharacterIndex);
/**
 * Get the current selected sub-string.
 * @param oFirstCharacterIndex
 *   The selected sub-string first character index.
 * @param oLastCharacterIndex
 *   The selected sub-string last character index.
 */
        void GetSelection(int& oFirstCharacterIndex, int& oLastCharacterIndex);

//      Additional Keystrokes to get Focus
/**
 * @nodoc 
 */
        void SetAdditionalKeystrokesToGetFocus(unsigned long *lst, int nb);

/**
 * Dynamically changes the capability for the end user to change the editor's contents.
 * @param iReadOnly
 */
        void SetReadOnly(CATBoolean iReadOnly);

//      get event notifications
/**
 * Returns the CATDlgEditModifyNotification event notification.
 * It is sent whenever a line is modified.
 */
        CATNotification *GetEditModifyNotification() const;
/**
 * Returns the CATDlgEditModifyExtNotification event notification.
 * It is sent whenever a line is modified and the key "Enter" is pressed.
 */
        CATNotification *GetEditModifyExtNotification() const;
/** 
 * Returns the CATDlgSelectionChangeNotification event notification.
 * It is sent by CATDlgEditor whenever the 
 * selection in entry field is changed.
 */
        CATNotification *GetSelectionChangeNotification() const;
/** 
 * Returns the CATDlgEditFocusInNotification event notification. 
 * which is sent by CATDlgEditor whenever 
 * it gets the keyboard focus.
 */
        CATNotification *GetEditFocusInNotification() const;
/** 
 * Returns the CATDlgEditFocusOutNotification event notification.
 * It is sent by CATDlgEditor whenever it losts 
 * the keyboard focus.
 */
        CATNotification *GetEditFocusOutNotification() const;
/*
 * Sets the behavior regarding TAB key for multiline editors.
 * By default, TAB key press results in the insertion of a TAB character in the text and does not give keyboard focus to another control.
 * @param i_bTabChangesFocusFlag
 * <br>
 * <b>Legal values:</b>
 * <dl>
 * <dt><tt>TRUE</tt><dd> TAB key press should change focus. </DD></dt>
 * <dt><tt>FALSE</tt><dd> if TAB should be accepted as text input. (default)</dd></dt>
 * </dl>
 */
        void SetTabChangesFocusFlag(CATBoolean i_bTabChangesFocusFlag);

/**
 * @nodoc 
 */
        void SetWcsManagement(CATBoolean);

/**
 * @nodoc 
 * Get internal object
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

//--------------------------------------------------------------------------
 protected:
/**
 * Sets the field color.
 * <br><b>Role</b>: Sets the field color in additive coordinates. 
 * @param iRedComponent
 *   The color red component.
 *   <br><b>Legal values</b>: from 0 (minimum additive
 *   red component) to 255 (maximum). 
 * @param iGreenComponent
 *   The color green component. 
 *   <br><b>Legal values</b>: from 0 (minimum additive
 *   green component) to 255 (maximum). 
 * @param iBlueComponent
 *   The color blue component. 
 *   <br><b>Legal values</b>: from 0 (minimum additive
 *   blue component) to 255 (maximum). 
 */
        void SetColor(unsigned char iRedComponent, 
                      unsigned char iGreenComponent, 
                      unsigned char iBlueComponent);

//--------------------------------------------------------------------------
 private:

//      address of internal object.
/**
 * @nodoc 
 */
        l_CATDlgEditor* _frameEditor;

        /** @nodoc */
        CATDlgEditor_ADD
};

/** @nodoc */
CATDlgEditor_LateADD

#endif
