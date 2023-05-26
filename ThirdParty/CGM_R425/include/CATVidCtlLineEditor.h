// COPYRIGHT Dassault Systemes 2006
//===================================================================
//  Dec 2009  Creation: 3dPLM
//===================================================================
#ifndef CATVidCtlLineEditor_H
#define CATVidCtlLineEditor_H

#include <VisuDialog.h>
#include <CATVidCtl.h>
#include <CATVid.h>
#include <CATUnicodeString.h>
#include <CATVidColor.h>
#include <CATVidMargin.h>
#include <CATVidTextSelection.h>
#include <CATVidSelection.h>
#include <CAT4x4Matrix.h> 
#include <CATVidMouseAndKeyboardEventArgs.h>
#include <CATVidAction.h>
#include <CATVidTextCursor.h>
#include <CATVidCtlPopup.h>
#include <CATVidMdlStandardList.h>
#include <CATVidMdlSortFilterProxy.h>
#include <CATVidGPFontIcon.h>

class CATVidLayLayer;
class CATMathPointf;
class CATVidCtlCursorArea;
class CATVidValidator;
class CATVidMouseEventArgs;
class CATDlgEditor;
class CATSYPEventArgs;
class CATVidCtlLinePresenter;

/**
 * Simple line editor.
 * <b>Role</b>:
 * This widget is used to edit text, or values, when used through a SpinBox.
 * @see #CATVidCtlSpinBox and CATVidCtlDoubleSpinBox
 */
class ExportedByVisuDialog CATVidCtlLineEditor: public CATVidCtl
{
  friend class CATVidTstCATVidCtlLineEditor;
  CATDeclareClass;
public:
  /**
  * Constructs a CATVidCtlLineEditor with standard style.
  * @param i_pParent
  *   The parent of the widget.
  * @param i_pIdentifier
  *   The name of the widget.
  */
  static CATVidCtlLineEditor* CreateEditor(CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
  * Constructs a CATVidCtlLineEditor.
  * No associsated style, use static factory CreateEditor
  */
  CATVidCtlLineEditor ();
  /** Destructor */
  virtual ~CATVidCtlLineEditor ();
  /**
   * Set text of the editor, by clearing it first, with CR = \n
   * @param i_text
   *   The text to set;
   */
  int SetText( const CATUnicodeString &i_text);
  /**
   * Returns text of the editor, with CR = \n
   */
  CATUnicodeString GetText() const;
  /**
  * Deletes any selected text, inserts newText, and validates the result. If it is valid, it sets it as the new contents of the line edit.
  */
  int Insert          (CATUnicodeString & i_newText );
  /**
  * Deselects any selected text.
  */
  int Deselect ();
  /**
  * Selects all the text (i.e. highlights it) and moves the cursor to the end. 
  * This is useful when a default value has been inserted because if the user types before clicking on the widget, the selected text will be deleted.
  */
  int SelectAll ();
  /**
  * Returns the widget's text margins for left, top, right, and bottom.
  */
  CATVidMargin GetTextMargins() const;
  /**
  * Sets the widget's text margins for left, top, right, and bottom.
  */
  void SetTextMargins ( const CATVidMargin& i_margin);
  /**
  * Returns current cursor position for this line edit.
  */
  int GetCursorPosition () const;
  /**
  * Sets current cursor position for this line edit.
  */
  int SetCursorPosition ( int i_pos);
  /**
  * This property holds whether there is any text selected.
  */
  CATBoolean GetSelectedTextFlag () const;
  /**
  * This property holds the displayed text.
  * If echoMode is Normal this returns the same as text(); if CATVid::EchoMode is Password or 
  * PasswordEchoOnEdit it returns a string of asterisks text().length() characters long, 
  * e.g. "******"; if CATVid::EchoMode is NoEcho returns an empty string, "".
  * By default, this property contains an empty string.
  */
  CATUnicodeString GetDisplayText () const;
  /**
  * This property holds the selected text.
  * If there is no selected text this property's value is an empty string.
  */
  CATUnicodeString GetSelectedText () const;
  /**
  * This property holds the maximum permitted length of the text.
  */
  int GetMaxLength () const;
  /**
  * This property holds the maximum permitted length of the text.
  */
  void SetMaxLength (int i_length);
  /** 
   * returns TRUE if there is no text in the LineEditor
   */
  int GetIsEmptyFlag() const;
   
  /**
   * Sets a flag that enable to set ReadOnly mode on the editor
   * User can still select the text.
   * @param i_readOnlyFlag
   *     The flag to set
   */
  void SetReadOnlyFlag(CATBoolean i_readOnlyFlag);
  /**
   * Returns a flag that enable to set ReadOnly mode on the editor
   */
  CATBoolean GetReadOnlyFlag() const;

   /**
   * Sets the color used as background color
   * @param i_backgroundColor
   * The background color to set.
   */
  void SetBackgroundColor( const CATVidColor &i_backgroundColor );
  /**
   * Returns the color used as background color
   */
  const CATVidColor& GetBackgroundColor( void ) const;
  /**
   * Sets the color used as foreground color (for example, used to draw the text most of the time)
   * @param i_foregroundColor
   * The foreground color to set.
   */
  void SetForegroundColor( const CATVidColor &i_foregroundColor );
  /**
   * Returns the color used as foreground color (for example, used to draw the text most of the time)
   */
  const CATVidColor& GetForegroundColor() const;
  /**
   * @return the applied background color. May be influenced by the IncorrectInputFlag.
   */
  CATVidColor GetAppliedBackgroundColor() const;
  /**
   * @return the applied border color. May be influenced by the IncorrectInputFlag.
   */
  CATVidColor GetAppliedBorderColor() const;
  /**
   * Sets the incorrect input flag, that will modify the visual feedback of the line editor.
   */
  void SetIncorrectInputFlag(int i_incorrectInputFlag);
  /**
   * @return the incorrect input flag, that will modify the visual feedback of the line editor.
   */
  int GetIncorrectInputFlag() const;
  /** Sets a flag that forces the incorrect input flag when the field is empty.*/
  void SetEmptyAsIncorrectInputFlag(int i_emptyAsIncorrectInputFlag);
  /** @return a flag that forces the incorrect input flag when the field is empty.*/
  int GetEmptyAsIncorrectInputFlag() const;


  /**
   * Returns a alignment of the text
   *  CATVidHAlignLeft   0
   *  CATVidHAlignCenter 1
   *  CATVidHAlignRight  2
   */
  // To be defined in CATVid.h
  CATVid::Alignment  GetAlignment () const;
  /**
   * Sets a alignment of the text
   *  CATVidHAlignLeft   0
   *  CATVidHAlignCenter 1
   *  CATVidHAlignRight  2
   */
  void SetAlignment (CATVid::Alignment i_flag );
  /**
   * Sets echo mode for the text
   * CATVidLineEdit::Normal	            0	Display characters as they are entered. This is the default.
   * CATVidLineEdit::NoEcho	            1	Do not display anything. This may be appropriate for passwords where even the length of the password should be kept secret.
   * CATVidLineEdit::Password	          2	Display asterisks instead of the characters actually entered.
   */
   void SetEchoMode (CATVid::EchoMode i_EchoMode );
   /**
   * Gets echo mode for the text
   * CATVidLineEdit::Normal	            0	Display characters as they are entered. This is the default.
   * CATVidLineEdit::NoEcho	            1	Do not display anything. This may be appropriate for passwords where even the length of the password should be kept secret.
   * CATVidLineEdit::Password	          2	Display asterisks instead of the characters actually entered.
   */
    CATVid::EchoMode GetEchoMode () const;
  /**
   * Sets return key type for the virtual keyboard
   * CATVid::DefaultReturnKey  0  Display the default return key type. This is the default.
   * CATVid::GoReturnKey,      1  Display the "Go" return key type.
   * CATVid::SearchReturnKey,  2  Display the "Search" return key type.
   * CATVid::SendReturnKey,    3  Display the "Send" return key type.
   * CATVid::DoneReturnKey,    4  Display the "Done" return key type.
   * CATVid::NextReturnKey     5  Display the "Next" return key type.
   */
   void SetReturnKeyType (CATVid::ReturnKeyType i_ReturnKeyType );
   /**
   * Gets return key type for the virtual keyboard
   * CATVid::DefaultReturnKey  0  Display the default return key type. This is the default.
   * CATVid::GoReturnKey,      1  Display the "Go" return key type.
   * CATVid::SearchReturnKey,  2  Display the "Search" return key type.
   * CATVid::SendReturnKey,    3  Display the "Send" return key type.
   * CATVid::DoneReturnKey,    4  Display the "Done" return key type.
   * CATVid::NextReturnKey     5  Display the "Next" return key type.
   */
   CATVid::ReturnKeyType GetReturnKeyType () const;
   /**
   * Sets the height of the text to be displayed
   */
   void SetFontHeight(int i_height);
   /**
   * Gets the height of the text to be displayed
   */
   int GetFontHeight() const;
   /**
   * Sets the font to be used while displaying text in editor.
   * Useful only if SetTesselateFontFlag is set to TRUE
   * Font FAMILY name to be provided.
   * Display is subject to availability of font
   */
   void SetFontName(const CATUnicodeString& iFontName);
   /**
   * Gets the font being used to display the text in editor
   */
   CATUnicodeString GetFontName() const;
   /**
   * Displays the text in bold form (subject to avialability of appropriate font)
   */
   void SetBoldFlag(CATBoolean i_MakeBold);
   /**
   * Returns whether the text is displayed in bold form (TRUE if SetBold call is made with argument TRUE, FALSE otherwise)
   */
   CATBoolean GetBoldFlag() const;
   /**
   * Displays the text in italic form (subject to avialability of appropriate font)
   */
   void SetItalicFlag(CATBoolean i_MakeItalic);
   /**
   * Returns whether the text is displayed in italic form (TRUE if SetBold call is made with argument TRUE, FALSE otherwise)
   */
   CATBoolean GetItalicFlag() const;
   /**
   * Displays the text with underline
   */
   void SetUnderlineFlag(CATBoolean i_MakeUnderline);
   /**
   * Returns whether the text is displayed with underline
   */
   CATBoolean GetUnderlineFlag() const;
   /**
   * Selects text from position start to end position
   */
   void SetSelection(const CATVidTextSelection & i_Selection);
   /**
   * Gets text from position start to end position
   */
   CATVidTextSelection GetSelection() const;

   /**
   * Sets the color used as cursor color
   * @param i_cursorColor
   * The cursor color to set.
   */
  void SetCursorColor( const CATVidColor &i_cursorColor );
  /**
   * Returns the color used as cursor color
   */
  const CATVidColor& GetCursorColor() const;
   /**
   * Sets the color used as selection color
   * @param i_selectionColor
   * The selection color to set.
   */
  void SetSelectionColor( const CATVidColor &i_selectionColor );
  /**
   * Returns the color used as cursor color
   */
  const CATVidColor& GetSelectionColor() const;
 /**
  * Sets the LineEditor's validation mask. Validators can be used instead of, or in conjunction with masks
  * The table below shows the characters that can be used in an input mask. A space character, the default character for a blank, is needed for cases where a character is permitted but not required.
  * Character	Meaning
  * A	ASCII alphabetic character required. A-Z, a-z.
  * a	ASCII alphabetic character permitted but not required.
  * N	ASCII alphanumeric character required. A-Z, a-z, 0-9.
  * n	ASCII alphanumeric character permitted but not required.
  * X	Any character required.
  * x	Any character permitted but not required.
  * 9	ASCII digit required. 0-9.
  * 0	ASCII digit permitted but not required.
  * D	ASCII digit required. 1-9.
  * d	ASCII digit permitted but not required (1-9).
  * The mask consists of a string of mask characters and separators, optionally followed by a semicolon 
  * and the character used for blanks. The blank characters are always removed from the text after editing.
  * Mask	
  * 000.000.000.000;_	IP address; blanks are _.
  * 0000-00-00	ISO Date; blanks are space
  * AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#	License number; blanks are - and all (alphabetic) characters are converted to uppercase.
  */
  int SetInputMask(const CATUnicodeString& i_InputMask);
  /**
  * Returns the inputmask specified for the editor
  */
  CATUnicodeString GetInputMask() const;
  /**
   * The placeholder text will be displayed when no text is entered in the LineEditor.
   * It disappears when text is entered.
   * It acts as an indicator on what should be entered (e.g. "login", "search", ...).
   */
  void SetPlaceholderText(const CATUnicodeString& i_PlaceholderText);
  /**
  * Returns the placeholder text specified by the user.
  */
  const CATUnicodeString& GetPlaceholderText() const;
  /**
   * Returns TRUE if the entire text must be selected when the editor gains the focus with a mouse click, FALSE otherwise.
   * By default, the SelectAllTextOnFocusFlag property is set to FALSE.
   * Note that whatever the SelectAllTextOnFocusFlag property value is, the entire text is selected when the 
   * editor gains the focus via the Tab key.
   */
  CATBoolean GetSelectAllTextOnFocusFlag() const;
  /**
   * Specifies whether the entire text must be selected when the editor gains the focus with a mouse click or not.
   * By default, the SelectAllTextOnFocusFlag property is set to FALSE.
   * Note that whatever the SelectAllTextOnFocusFlag property value is, the entire text is selected when the 
   * editor gains the focus via the Tab key.
   */
  void SetSelectAllTextOnFocusFlag(CATBoolean iFlag); 
  /**
   * Specifies whether the editor border is visible or not.
   */
  void SetBorderVisibleFlag(CATBoolean i_visibleFlag);
  /**
   * Returns TRUE if the editor border is visible, FALSE otherwise.
   */
  CATBoolean GetBorderVisibleFlag() const;
  /**
   * Specifies whether the reset button is visible or not.
   * If it is, it will appear only when text is entered, and clicking on it will reset the text (empty the LineEditor).
   */
  void SetResetButtonVisibleFlag(CATBoolean i_resetButtonVisibleFlag);
  /**
   * Returns TRUE if the reset button is visible, FALSE otherwise.
   */
  CATBoolean GetResetButtonVisibleFlag() const;
  /**
  * Clears the contents of the line edit.
  */
  int Clear  ();
  /**
  * Copies the selected text to the clipboard, if there is any, and if echoMode() is Normal.
  */
  int Copy ();
  /**
  * Copies the selected text to the clipboard and deletes it, if there is any, and if echoMode() is Normal,
  * if line edit is read only, cut() will copy without deleting.
  * If input mask is set, cut() will copy without deleting.
  * If the validation disallows deleting the selected text, cut() will copy without deleting.
  */
  int Cut    ();
  /**
  * Inserts the clipboard's text at the cursor position, deleting any selected text, providing the line edit is not read-only.
  * If input mask is set, Paste operation will fail
  * If validator is set , Paste operation will fail if resulting text is invalid
  */
  int Paste  ();
  /**
   * Sets this line edit to only accept input that the validator, v, will accept. This allows you to place any arbitrary constraints on the text which may be entered.
   * If v == 0, setValidator() removes the current input validator. The initial setting is to have no input validator (i.e. any input is accepted up to maxLength()).
   * Life cycle of i_pValidator is controlled by the client application.
  */
  int SetValidator(CATVidValidator* i_pValidator);
  /**
   * Returns a pointer to the current input validator, or 0 if no validator has been set.
  */
  const CATVidValidator* GetValidator() const;
  
  /**
   * Set the FocusedFlag property value.
   * This property is usefull to give the Line editor focus by binding.
   * When this property is set to TRUE, the Line editor imediately take the focus.
   * Note that set property to FALSE will have no effect on the line editor.
   */
  void SetFocusedFlag(const CATBoolean& i_FocusedFlag);
  /**
   * Specifies whether the editor value is undefined or not.
   * When a value is undefined, the editor view does not display any value until the end user enters one.
   * By default, the UndefinedFlag property is set to FALSE.
   */
  void SetUndefinedFlag(CATBoolean i_undefinedFlag);
  /**
   * Returns TRUE if the editor value is undefined, FALSE otherwise.
   */
  CATBoolean GetUndefinedFlag() const;
    /**
  * If no text is selected, deletes the character to the left of the text cursor and 
  * moves the cursor one position to the left. If any text is selected, the cursor is 
  * moved to the beginning of the selected text and the selected text is deleted.
  */
  void HandleBackspaceKey ();
  /**
  * Moves the cursor back steps characters. If mark is true each character moved 
  * over is added to the selection; if mark is false the selection is cleared.
  */
  void MoveCursorBackward      (CATBoolean i_mark, int i_steps = 1 );
  /**
  * Moves the cursor forward steps characters. If mark is true each character moved 
  * over is added to the selection; if mark is false the selection is cleared. 
  */
  void MoveCursorForward       (CATBoolean i_mark, int i_steps = 1 );
  /**
  * Moves the cursor one word backward. If mark is true, the word is also selected.
  */
  void MoveCursorWordBackward  (CATBoolean i_mark );
  /**
  * Moves the cursor one word forward. If mark is true, the word is also selected.
  */
  void MoveCursorWordForward   (CATBoolean i_mark );
  /**
  * If no text is selected, deletes the character to the right of the text cursor. 
  * If any text is selected, the cursor is moved to the beginning of the selected text and the selected text is deleted.
  */
  void HandleDeleteKey ();
  /**
  * Moves the text cursor to the end of the line unless it is already there. 
  * If mark is true, text is selected towards the last position; otherwise, any selected text is unselected if the cursor is moved.
  */
  void HandleEndKey    (CATBoolean i_mark );
  /**
  * Moves the text cursor to the beginning of the line unless it is already there. 
  * If mark is true, text is selected towards the first position; otherwise, any selected text is unselected if the cursor is moved.
  */
  void HandleHomeKey   (CATBoolean i_mark );
  /**
  * Get the @c SelectionChanged event.
  * The @c SelectionChanged event is emitted whenever the editor selection is modified.
  * @par EventProperties
  *   - Name: @c "SelectionChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPSelectionEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* SelectionChanged();
  /**
  * Get the @c CursorPositionChanged event.
  * The @c CursorPositionChanged event is emitted whenever the cursor position is changed.
  * @par EventProperties
  *   - Name: @c "CursorPositionChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* CursorPositionChanged();
  /**
  * Get the @c TextChanged event.
  * The @c TextChanged event is emitted whenever the text changes. 
  * Unlike GetTextEditNotification(), this event is also sent when the text is changed programmatically, 
  * for example, by calling setText().
  * @par EventProperties
  *   - Name: @c "TextChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* TextChanged();
  /**
  * Get the @c TextEdited event.
  * The @c TextEdited event is emitted whenever the text is edited. 
  * @par EventProperties
  *   - Name: @c "TextEdited"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* TextEdited();
  /**
  * Get the @c TextActivated event.
  * The @c TextActivated event is emitted whenever the editor receives focus.
  * @par EventProperties
  *   - Name: @c "TextActivated"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* TextActivated();
  /**
  * Get the @c EditingFinished event.
  * The @c EditingFinished event is emitted whenever the editor lose focus.
  * @par EventProperties
  *   - Name: @c "EditingFinished"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATVidFocusChangedEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* EditingFinished();
  /**
  * Get the @c ReturnPressed event.
  * The @c ReturnPressed event is emitted whenever the Return key is pressed (editor should be in focus).
  * @par EventProperties
  *   - Name: @c "ReturnPressed"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* ReturnPressed();   

  /** 
  * Get the @c ReturnReleased event.
  * The @c ReturnReleased event is emitted whenever the Return key is released (editor should be in focus).
  * @par EventProperties
  *   - Name: @c "ReturnReleased"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* ReturnReleased();

  /** 
  * Get the @c BackspacePressed event.
  * The @c BackspacePressed event is emitted whenever the Backspace key is pressed (editor should be in focus)
  * The event is emmited even if the editor is empty.
  * @par EventProperties
  *   - Name: @c "BackspacePressed"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* BackspacePressed(); 

  /** 
  * Get the @c EscapePressed event.
  * The @c EscapePressed event is emitted whenever the Escape key is pressed (editor should be in focus)
  * The event is emmited even if the editor is empty.
  * @par EventProperties
  *   - Name: @c "EscapePressed"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* EscapePressed();

	/**
	* Get the @c FontIconButtonPressed event.
	* The @c FontIconButtonPressed event is emitted whenever the font icon button is pressed
	* @par EventProperties
	*   - Name: @c "FontIconButtonPressed"
	*   - Type of propagation: @c NoPropagation
	*   - Type of argument: @ref CATSYPEventArgs
	*
	* @return the event instance. @c AddRef has NOT been called on the returned pointer.
	*/
	static CATSYPEvent* FontIconButtonPressed();

  /**
  * Sets given color to charcters specified
  * User can call this function multiple times to set colors to different zones.
  * Previous color of a zone is overwritten by newly applied color. #SetForegroundColor will
  * overwrite colors set to all zones (foreground color will be applied to entire text)
  * @param i_stIndex start character index. Legal value: from 0 to (size of text-1).
  * @param i_enIndex end character index. Legal value: from 0 to (size of text-1).
  * @param i_zoneColor color to be applied
  * User can call this function multiple times to set colors to different zones.
  */
  void SetZoneColor(int i_stIndex, int i_enIndex, const CATVidColor &i_zoneColor);
  /**
   * Temporaly made available on line editor
  */
  /* Gives the focus to the line editor
  *  @param iDisplayVirtualKeyboard in Touch environment, enables to display virtual keyboard
  */
  void SetFocus(CATBoolean iDisplayVirtualKeyboard=FALSE);
  void ResetFocus();
  //Get Cursor in LineEditor
  CATVidTextCursor& GetTextCursor();
  
	/**
	* This property is used to set AutoCompleteMode.
	* Default Mode is CATVidAutoCompleteMode:None - Disabled autocomplete
	* You can set CATVidAutoCompleteMode:Suggest. You must specify the source for autocompletion. 
	* The property is CATVidAutoCompleteMode:None for a Readonly editor. The Model for Autocompletion is built once the AutoCompleteMode property is set other than None.
	**/
	void SetAutoCompleteMode(CATVid::AutoCompleteMode i_autocompleteMode);

	/**
	* Sets AutoCompleteSource property for a line editor. 
	* For any value other than CATVidAutoCompleteMode:None An auxiliary drop-down list is displayed. This drop-down is populated with 
	* one or more suggested completion strings. Other options include 
	* CATVidAutoCompleteSource::History - based on history for current editor instance ( It could be specific to session or saved to repository)
	* CATVidAutoComlpeteSource::Custom - User must provide a default list of strings that shall be considered as a custom source using SetAutoCompleteCustomSource
	* CATVidAutoCompleteSource::CustomHistory - User to provide a deafult list of strings using SetAutoCompleteCustomSource. For an empty editor, on set text, history is displayed else custom source.
	**/
  void SetAutocompleteSourceType(CATVid::AutoCompleteSource i_autocompleteSourceType);

	/**
	* Use this API to set custom source for autocompletion. This API must be used after setting AutoCompleteSource Property to CATVidAutoCompleteSource:Custom and
	* for AutoComplete mode other than CATVidAutoCompleteMode:None.
	* @Param _pAutoCompleteCustomSource : A Model for custom source. You can provide your own Filte proxy for the Model. see @SetAutoCompletionFilterProxy however you can
	* use the default implementation of filters. The default filteration is done on the property "Text" , so in order to use the default filter, you must absolutely have "Text" property in your model.
	**/
	void SetAutoCompleteCustomSource(CATVidMdlStandardList* _pAutoCompleteCustomSource);

	/**
	* Use this API to set custom source for autocompletion. This API must be used after setting AutoCompleteSource Property to CATVidAutoCompleteSource:Custom and
	* for AutoComplete mode other than CATVidAutoCompleteMode:None.
	* The source is generated from array of CATUnicodeString.
	**/
	void SetAutoCompleteCustomSourceFromStringArray(CATSYPDynArray<CATUnicodeString>* _pAutoCompleteCustomSourceFromStringArray);

	/**
	* Set this flag to specify that the filteration to be done by matching prefix only. (Default is TRUE)
	**/
	void SetAutoCompletionMatchPrefixOnlyFlag(CATBoolean i_bMatchPrefixOnly);
	
	/**
	* Use this API to override the default filteration and sort parameters for custom source. 
	* Sets the autocompletion filter and sort options for custom source
	* @Parameter i_pAutoCompleteFilterproxy : pointer to CATVidMdlSortFilterProxy 
	**/
	void SetAutoCompletionFilterProxy(CATVidMdlSortFilterProxy* i_pFilterProxy);

	/**
	* Use this API to show/hide FontIconButton
	* @Parameter bVisibleFlag: True to enable.
	**/
	void SetFontIconButtonVisibleFlag(CATBoolean bVisibleFlag);

	/*
	* Get Visible state of fonticon button
	*/
	CATBoolean GetFontIconButtonVisibleFlag();

	/**
	* Use this API to enable/diasble FontIconButton 
	* @Parameter bEnableFlag: True to enable.
	**/
	void SetFontIconButtonEnableFlag(CATBoolean bEnableFlag);

	/*
	* Get Enable/Disable state of fonticon button
	*/
	CATBoolean GetFontIconButtonEnableFlag();

	/**
	* Use this API to set an icon to FonticonButton
	* @Parameter CATVidGPFontIcon::IconName : Enum value to specify icon name.
	**/
	void SetFontIconName(CATVidGPFontIcon::IconName iName);

	/*
	* Get valid state of editor
	*/
	CATBoolean GetValidState();

	/* 
	* Get FontIcon name enum value from Fonticon Button
	*/
	CATVidGPFontIcon::IconName GetFontIconName();
	
	CATVid::AutoCompleteMode GetAutoCompleteMode();
	CATVid::AutoCompleteSource GetAutoCompleteSourceType();
	CATSYPDynArray<CATUnicodeString>* GetAutoCompleteCustomSourceArray();
	CATVidMdlStandardList* GetAutoCompleteCustomSource();
	CATBoolean GetAutoCompletionMatchPrefixOnlyFlag();
	CATVidMdlSortFilterProxy* GetAutoCompletionFilterProxy();
	void SetHistoryRecordLimit(int i_nRecordLimit);

	/**
   * Returns the combo box popup.
   * For internal use only.
   */
  CATVidCtlPopup * GetAutoCompletionPopup() const;

  /** Do not use it, has to be private.*/
  void HandleOnMoveOver(CATBaseUnknown* pSender, CATVidMouseEventArgs* pEvntArg);
  /** Do not use it, has to be private.*/
  void HandleOnClick(CATBaseUnknown* pSender, CATVidMouseEventArgs* pEvntArg);
  /** Do not use it, has to be private.*/
  void HandleDoubleClick(CATBaseUnknown* pSender, CATVidMouseEventArgs* pEvntArg);
  /** Do not use it, has to be private.*/
  void HandleOnDrag(CATBaseUnknown* pSender, CATVidMouseEventArgs* pEvntArg);
  /** Do not use it, has to be private.*/
  void HandleOnReleaseClick(CATBaseUnknown* pSender, CATVidMouseEventArgs* pEvntArg);
  /** Do not use it, has to be private.*/
  void HandleOnMouseEntry(CATBaseUnknown* pSender, CATVidMouseEventArgs* pEvntArg);
  /** Do not use it, has to be private.*/
  void HandleOnMouseLeave(CATBaseUnknown* pSender, CATVidMouseEventArgs* pEvntArg);
  /** Do not use it, has to be private.*/
  void HandleOnContextMenuRequired(CATBaseUnknown* pSender, CATVidMouseAndKeyboardEventArgs* pEvntArg);
  /** Do not use it, has to be private.*/
  void HandleOnContextMenuHidden(CATBaseUnknown* pSender, CATSYPEventArgs* pEvntArg);
protected:
  virtual void TunnelInformation(const CATVidInformation& i_information);
  /** @copydoc CATVidCtl#TemplateDataUpdated */
  virtual void TemplateDataUpdated();
private:
  static void sOnTimer(CATCommand* iCmd, int iTime, void* iClientData);
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlLineEditor (CATVidCtlLineEditor &);
  CATVidCtlLineEditor& operator=(CATVidCtlLineEditor& original); 
  friend class l_CATVidCtlEditorBase;
  friend class l_CATVidCtlLineEditor;
public:
  /**
   * @name Deprecated members
   */
  /*@{*/ 
  int GetCursorPositionAt ( const CATMathPointf & i_pos ) const{return 0;}
  CATBaseUnknown* GetEditorContent(){return 0;}
  CATBaseUnknown* GetPlaceholderLine(){return 0;}
  void SetCursorPoint( const CATMathPoint2Df &i_cursorPoint ){}
  const CATMathPoint2Df& GetCursorPoint( void ) const{static CATMathPoint2Df dummy; return dummy;}
  void SetSelectionFromPoint( const CATMathPoint2Df &i_cursorPoint ){}
  const CATMathPoint2Df& GetSelectionFromPoint( void ) const{static CATMathPoint2Df dummy; return dummy;}
  void SetSelectionToPoint( const CATMathPoint2Df &i_cursorPoint ){}
  const CATMathPoint2Df& GetSelectionToPoint( void ) const{static CATMathPoint2Df dummy; return dummy;}
  CAT4x4Matrix GetOffsetMatrix(){return CAT4x4Matrix();}
  void SetOffsetMatrix(CAT4x4Matrix& i_matrix){}
  int GetActualFontHeight() const{return 0;}
  void SetTesselateFontFlag(const CATBoolean& i_tesselateFontFlag){}
  CATBoolean GetTesselateFontFlag() const{return 0;}
  CATBoolean GetCursorVisibleFlag () const;
  void  SetCursorVisibleFlag (CATBoolean iFlag){}
  CATBoolean GetSelectionVisibleFlag () const;
	
  /**
   * Returns the event notification sent whenever the cursor position is changed
   * DEPRICATED: Use new VID propagating events (see: http://codewiki/codewiki/index.php/VID_:_Events_Migration)
   */
  CATNotification *GetCursorPositionChangedNotification() const;
  /**
   * Returns the event notification sent whenever the editor selection is modified
   * DEPRICATED: Use new VID propagating events (see: http://codewiki/codewiki/index.php/VID_:_Events_Migration)
   */
  CATNotification *GetSelectionChangeNotification() const;
  /**
   * This signal is emitted whenever the text changes. 
   * Unlike GetTextEditNotification(), this event is also sent when the text is changed programmatically, 
   * for example, by calling setText().
   * DEPRICATED: Use new VID propagating events (see: http://codewiki/codewiki/index.php/VID_:_Events_Migration)
   */
  CATNotification *GetTextChangedNotification() const;
  /**
   * This signal is emitted whenever the text is edited. 
   * DEPRICATED: Use new VID propagating events (see: http://codewiki/codewiki/index.php/VID_:_Events_Migration)
   */
  CATNotification *GetTextEditNotification() const;
  /**
   * Get the text activate notification
   * DEPRICATED: Use new VID propagating events (see: http://codewiki/codewiki/index.php/VID_:_Events_Migration)
   */
  CATNotification *GetTextActivateNotification() const;
  /**
   * Get the Editing finished notification
   * DEPRICATED: Use new VID propagating events (see: http://codewiki/codewiki/index.php/VID_:_Events_Migration)
   */
  CATNotification * GetEditingFinishedNotification()const;
  /**
   * Get the Return Pressed notification
   * DEPRICATED: Use new VID propagating events (see: http://codewiki/codewiki/index.php/VID_:_Events_Migration)
   */
  CATNotification * GetReturnPressedNotification()const;

  /**
  * Get the Return Released notification
  * DEPRICATED: Use new VID propagating events (see: http://codewiki/codewiki/index.php/VID_:_Events_Migration)
  */
  CATNotification * GetReturnReleasedNotification()const;

  /*@}*/ 
};
//-----------------------------------------------------------------------

#endif
