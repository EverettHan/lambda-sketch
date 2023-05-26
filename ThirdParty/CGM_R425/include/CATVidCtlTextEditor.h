// COPYRIGHT Dassault Systemes 2011
//===================================================================
//  Dec 2009  Creation: 3dPLM
//===================================================================
#ifndef CATVidCtlTextEditor_H
#define CATVidCtlTextEditor_H
// Local
#include <VisuDialog.h>
#include <CATVidCtlAbstractScrollableArea.h>
#include "CATVidTextStyle.h"
#include "CATVidTextCursor.h"
#include <CATVid.h>
#include <CATVidTextSelection.h>

class CATVidGPSquare;
class CATVidLayLayer;
class l_CATVidCtlTextEditor;
class CATSYPOutputStream;
class CATSYPInputStream;
class CATVidTooltip;
class CATSYPEvent;
class CATDlgEditor;
class CATVidMouseWheelEventArgs;
class CATVidTextSelection;
class CATVidGPText;

/**
* @ingroup VIDControls
*
* @c CATVidCtlTextEditor provides a rich text editor control.
*
* @par Presentation 
* The text can be editable or read-only (@ref #SetReadOnlyFlag). Its presentation 
* can be changed using various functions such as @ref #SetWordWrapMode, @ref 
* #SetAlignment, @ref #SetBackgroundColor). In case text area is 
* larger than editor frame, horizontal and vertical scrollbars are displayed.
*
* @par Creation
* @code
* CATVidCtlButton* pButton = CATVidCtlTextEditor::CreateEditor(myCommandParent, "EditorName");
* @endcode
* There is only one template available for this class:
* @li default template is named TextEditor
*
* @par Cursor
* Text is always inserted at current cursor position, represented in code by @ref CATVidTextCursor. 
* Cursor position is shown by blinking vertical line. Its color can be customized. Cursor is not seen in 
* case of read-only mode or text editor is not in focus. Cursor can be moved by calling @ref 
* #MoveCursor. Otherwise, user can use mouse to click at desiered cursor position 
* (if mouse interactions are enabled using @ref #SetTextInteractionFlags). 
* Also, following keybord shortcuts are available for moving cursor,  
* @li HOME move cursor to start of text row
* @li END move cursor to end of text row
* @li CNTRL+HOME move cursor to start of document
* @li CNTRL+END move cursor to end of document
* @li ARROW KEYS move cursor in respective direction by one character (horizontally) or one row (vertically)
* @li PAGE UP moved text down by one visible page (cursor position is updated)
* @li PAGE DOWN moved text up by one visible page (cursor position is updated)
*
* @par Selection
* By default, text can be selected using mouse or keyboard. In case text is readonly, its not possible to 
* select text using keyboard. Otherwise, text can be selected using SHIFT key with combination of cursor 
* posision modification keys (described above). SHIFT key can also be used together with mouse to select 
* text. Current text selection is represented by CATVidTextSelection (@see CATVidTextSelection), where 
* -2,-2 represents no selection. 
*
* @par Edition
* Programatically, text can be set to editor using @ref #SetText (in current text style) 
* or using @ref CATVidTextCursor. 
* Below keys are suported while modifying text in editor (which is not read-only).
* @li ENTER create new paragraph
* @li SHIFT+ENTER create new line in existing paragraph
* @li DELETE delete character present after cursor
* @li BACKSPACE delete character present before cursor
* @li CNTRL+X (SHIFT+DELETE) cuts text to clipboard 
* @li CNTRL+C (SHIFT+INSERT) copies text from clipboard 
* @li CNTRL+V (CNTRL+DELETE) pastes text from clipboard 
* @li Any other alphanumeric key will enter character in editor
* Any entered text will overwrite selected text (if present).
*
* @par Styles
* Various styles such as Bold, Italics, colors etc are available (@ref CATVidTextStyle). 
* Usage of SetCurrentCharFormat : In case selection is present style of selection will be changed. If cursor is present in between word,
* style of word will be changed. Otherwise, nothing is done.
* If user specify SetStyleForCharInsertion. This style will be applied whenever text is inserted. To reset this style, customer 
* can call ResetStyleForCharInsertion.
*
* @par Export/Import
* Text export and import is currently supported only for XHTML but with limited tags and strict structure. 
* (@ref ExportInXHTML)
* 
* @par Limitations
* @li MIME Data
* @li Undo / Redo Support
* @li Context sensitive menu
* @li Drag'n drop
* @li Copy paste of rich text.
* 
* @see CATVidTextStyle, @see CATVidTextCursor, @see CATVidTextSelection, @see CATVidCtlAbstractScrollableArea
*/
class ExportedByVisuDialog CATVidCtlTextEditor: public CATVidCtlAbstractScrollableArea
{
  CATDeclareClass;
public:
  /**
  * @deprecated. Simply use the ReadOnlyFlag.
  */
  enum TextInteractionFlags {
    /**  Sets the ReadOnlyFlag to TRUE. */
    NoTextInteraction	= 0,
    /**  Sets the ReadOnlyFlag to TRUE. */
    TextSelectableByMouse=1,
    /**  Sets the ReadOnlyFlag to FALSE. */
    TextEditable=2,
    /** Sets the ReadOnlyFlag to TRUE. Launch an hyperlink is made by simply click on it*/
    TextBrowserInteraction=3
  };
  #define TextEditorInteraction TextEditable
  /**
  * Constructs a CATVidCtlTextEditor with standard style.
  * @param i_pParent
  *   The parent of the widget.
  * @param i_pIdentifier
  *   The name of the widget.
  */
  static CATVidCtlTextEditor* CreateEditor(CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
  * Constructs a CATVidCtlLineEditor.
  * No associsated style, use static factory @ref #CreateEditor
  */
  CATVidCtlTextEditor ();
  /** 
  * Desctructor 
  */
  virtual ~CATVidCtlTextEditor ();
  /*
  * Sets the text overwrite mode (existing text will be overwritten by text entered by user).
  * By default this is @c FALSE, thus newly entered text will not replace existing text.
  * @param i_overwriteModeFlag overwite mode to set
  */
  void SetOverwriteModeFlag(CATBoolean i_overwriteModeFlag);
  /*
  * Gets the text overwrite mode 
  * By default this is @c FALSE
  * @return current overwrite mode 
  */
  CATBoolean GetOverwriteModeFlag() const;
  /**
  * Set text of the editor.
  * This function will first clear amy existing text. Any occurence of \n will add new line.
  * The applied with style will be initialized will default style, and overloaded eventually by the StyleForCharInsertion, is set.
  * @param i_text  The text to set
  */
  void SetText( const CATUnicodeString &i_text);
  /**
  * Gets the text present in editor. \n will be inserted for every new line.
  * @return text string
  */
  CATUnicodeString GetText() const;
  /**
   * Sets if pressing ENTER will create a new paragpraph, or just a new line.
   */
  void SetCreateNewParagraphOnEnterFlag(int i_createNewParagraphOnEnterFlag);
  /** @return if if pressing ENTER will create a new paragpraph, or just a new line*/
  int GetCreateNewParagraphOnEnterFlag() const;

  /**
  * Sets if pressing ENTER (or escape) is quiting the edition mode.
  * In this case (QuitEditionOnEnterOrEscapeFlag=1), no new line is added to text editor but enter (escape) pressed event is transmitted (for example to launch ok (or cancel) on embedding dialog.)
  * If this property is set to 1, carriage return can be carried out in the editor by pressing SHIFT + ENTER keys.
  * 
  */
  void SetQuitEditionOnEnterOrEscapeFlag(int i_quitEditionOnEnterOrEscapeFlag);

  /**
  * return QuitEditionOnEnterOrEscapeFlag value (see explanation above.)
  */
  int GetQuitEditionOnEnterOrEscapeFlag()const;


  /**
  * Sets the ReadOnly mode of the editor
  * Cursor will not be shown. User can still select the text using mouse.
  * @param i_readOnlyFlag @c TRUE to enable ReadOnly mode otherwise @c FALSE
  */
  void SetReadOnlyFlag(CATBoolean i_readOnlyFlag);
  /**
  * Get ReadOnly mode flag of the editor
  * @return @c TRUE if ReadOnly mode is enabled otherwise @c FALSE
  */
  CATBoolean GetReadOnlyFlag() const;
  /*
  * Sets the behavior regarding TAB key
  * By default, TAB is accepted as number of spaces set using @ref #SetTabStopWidth.
  * @param i_bTabChangesFocusFlag @c TRUE if TAB should change focus or @c FALSE if TAB should be accepted as text input.
  */
  void SetTabChangesFocusFlag(CATBoolean i_bTabChangesFocusFlag);
  /*
  * Gets the behavior regarding TAB key
  * @return @c TRUE if TAB will change focus or @c FALSE if TAB will be accepted as text input.
  */
  CATBoolean GetTabChangesFocusFlag() const;
  /*
  * Sets the tab width 
  * Applicable in case @ref #SetTabChangesFocusFlag is set to @c FALSE
  * By default, tab width is 4 (spaces)
  * @param i_Width number of spaces to be inserted in text in place of one TAB.
  */
  void SetTabStopWidth(int i_Width);
  /*
  * Sets the tab width 
  * By default, tab width is 4 (spaces)
  * @return number of spaces to be inserted in text in place of one TAB.
  */
  int GetTabStopWidth() const;
  /*
  * Set maximum number of characters to be displayed in editor
  * NOTE:
  * @li New line is considered as one character
  * @li Usage: set this property once when editor is created changing this property 
  *     dynamically is not desiered.
  * @li Nothing is done if editor already have more than maximum number of characters set. 
  *     ofcource, no more characters will be accepted.
  * @param i_nbChars Number of characters
  */
  void SetMaxNumberOfCharacters(int i_nbChars);
  /*
  * Returns maximum number of characters allowed
  * Returned value is useless if #SetMaxNumberOfCharacters is not called before
  * @return number of characters
  */
  int GetMaxNumberOfCharacters() const; 
  /*
  * Sets text wrapping mode for text displayed in editor.
  * @param iMode can be one of the @ref CATVid#WordWrapMode
  * @li NoWrap : Text is not wrapped at all.
  * @li WordWrap : Text is wrapped at word boundaries.
  * @li WrapAnywhere : Text can be wrapped at any point on a line, even if it occurs in the middle of a word.
  * @li WrapAtWordBoundaryOrAnywhere : If possible, wrapping occurs at a word boundary; otherwise it will occur at the appropriate point on the line, even in the middle of a word.
  */
  void SetWordWrapMode(CATVid::WordWrapMode iMode);
  /*
  * Gets text wrapping mode for text displayed in editor.
  * @return @ref CATVid#WordWrapMode specifying current word wrap mode
  */
  CATVid::WordWrapMode GetWordWrapMode() const;
  /**
  * Sets horizontal text alignment 
  * @param i_flag @ref CATVid#Alignment values (AlignLeft, AlignCenter or AlignRight)
  */
  void SetAlignment (CATVid::Alignment i_flag );
  /**
  * Gets horizontal text alignment 
  * @return @ref CATVid#Alignment values (AlignLeft, AlignCenter or AlignRight)
  */
  CATVid::Alignment  GetAlignment () const;
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
  /*
  * Returns whether text can be pasted from the clipboard into the textedit.
  * Text can't be pasted in editor is in ReadOnly mode.
  * @return @c TRUE if text can be pasted otherwise @c FALSE
  */
  CATBoolean GetCanPasteFlag() const;
  /**
  * Clears the contents of the text editor.
  * User can Clear editor text even in ReadOnly mode.
  * @return 1 if succeeded other wise 0.
  */
  int Clear  ();
  /**
  * Copies the selected text to the clipboard, if there is any
  * Text formating is not copied
  * @return 1 if succeeded other wise 0.
  */
  int Copy   ();
  /**
  * Copies the selected text to the clipboard and deletes it, if there is any.
  * if text editor is read only, cut() will copy without deleting.
  * @return 1 if succeeded other wise 0.
  */
  int Cut    ();
  /**
  * Pastes the text from clipboard at the current position in editor.
  * Not possible to paste if editor is read only
  * @return 1 if succeeded other wise 0.
  */
  int Paste ();
  /**
   * Merge the default style of the editor with the overloaded properties of the given style.
   * It allows to replace all the individual modifications of Bold, Italic, and so on.
   */
  void SetDefaultStyle(const CATVidTextStyle& i_style);
  /**
   * @return the default style of the editor.
   */
  CATVidTextStyle GetDefaultStyle() const;
  /*
  * If there is a selection, return the style of the selection. 
  * If the cursor is inside the bounds of a word, it will return the style of the word.
  * In these both cases, some parts of the style may be unset, 
  * as some style can be different in some parts of the selection.
  * @return current text style
  * @see CATVidTextStyle 
  */
  CATVidTextStyle GetCurrentCharFormat () const;
  /*
  * Sets the text style as current. This style will be used to,
  * @li change style of selected text (if any)
  * @li apply to a word, if there is no selection but cursor in present within a word.
  * @return 1 if the style has been applied, 0 of not (none of the two above cases.)
  * @see CATVidTextStyle 
  */
  void SetCurrentCharFormat ( const CATVidTextStyle& i_format );
  /**
   * @return the style of a specific character.
   */
  CATVidTextStyle GetFormatAtCharIndex(int i_charIndex) const;
  /**
   * Sets the style used for inserting text. Note that the i_styleForCharInsertion will be merged
   * with the style already set by calling this method earlier.
   * To reset the style for insertion, just call #ResetStyleForCharInsertion.
   * Note that this style will overload the current style resulting of the current selection or current cursor position.
   * To ensure a complete style overloading, you should first create a complete style by calling GetDefaultStyle, 
   * and then modify the returned style by adding the special attributes to use when inserting text.
   */
  void SetStyleForCharInsertion(const CATVidTextStyle& i_styleForCharInsertion);
  /**
   * @return the style used when inserting text.
   */
  CATVidTextStyle GetStyleForCharInsertion() const;
  /**
   * Resets the style used for text insertion.
   */
  void ResetStyleForCharInsertion();
  /*
  * Moves the cursor by performing the given operation.
  * @param i_operation enum defined @ref CATVidTextCursor#MoveOperation 
  * @param i_mode enum to indicate move mode @ref CATVidTextCursor#MoveMode. If mode is KeepAnchor, 
  * the cursor selects the text it moves over. This has same effect as holding down the Shift key 
  * and moving the cursor with the arrow keys to select text.
  * @return 1 if succeeded otherwise 0
  */
  int MoveCursor(CATVidTextCursor::MoveOperation i_operation, CATVidTextCursor::MoveMode i_mode = CATVidTextCursor::MoveAnchor );
  /*
  * Scrolls the text edit so that the anchor with the given name is visible; 
  * does nothing if the name is empty, or is already visible, or isn't found.
  * NOTE: Function not implemented. Contact team if needed.
  */
  int ScrollToHyperlink(const CATUnicodeString& i_strHyperlinkName);
  /*
  * Selects all text.
  * @return 1 if succeeded otherwise 0
  */
  int SelectAll();
  /*
  * Get text cursor
  * @return the cursor object
  * @see CATVidTextCursor
  */
  CATVidTextCursor& GetTextCursor();
  /**
  * Sets the Foreground color of the editor
  * @param iColor color for Foreground
  */
  void SetForegroundColor(const CATVidColor & iColor);
  /**
  * Get Foreground color of the editor
  * @return the Foreground color 
  */
  const CATVidColor& GetForegroundColor() const;
  /**
  * Sets the background color of the editor
  * @param iColor color for background
  */
  void SetBackgroundColor(const CATVidColor & iColor);
  /**
  * Get background color of the editor
  * @return the background color 
  */
  const CATVidColor& GetBackgroundColor() const;
  /**
  * Resets the selection inside the editor
  */
  void ResetSelection();
  /**
  * Selects the text inside the editor
  * @param i_Selection selection to be set 
  * @see CATVidTextSelection 
  */
  void SetSelection(const CATVidTextSelection & i_Selection);
  /**
  * Get current selection
  * @return the selection inside the editor. (-2, -2) represent no selection
  * @see CATVidTextSelection 
  */
  CATVidTextSelection GetSelection() const;
  /**
  * Fills an output stream with UTF-8 format XHTML 1.0 valid stream.
  * @param o_outputStream stream to be filled
  * @see CATSYPOutputStream
  */
  void ExportInXHTML(CATSYPOutputStream& o_outputStream) const;
  /**
  * Read the document from a XHTML 1.0 stream. 
  * The following structure is supported :
  * @code
  * <html>
  *   <body>
  *     <p>
  *       <span style="[...]">Text</span> of a <span style="[...]">paragraph</span> [...]
  *     </p>
  *     <p>
  *       <span style="[...]">Another </span> paragraph <span style="[...]">written</span> [...]
  *     </p>
  *   </body>
  * </html>
  * @endcode
  *
  * The span tag is however optional. It is only included when the style overloads. If span tag is not present, the text shall follow the body textstyle.
  *
  * Characters may not be present outside @c <p> tag, style attribute may be present on @c <p> and @c <span> tags.
  * The following CSS style attributes are supported : 
  * @li @c font-weight (bold)
  * @li @c font-style  (italic)
  * @li @c text-decoration (underline)
  * @li @c color (only with format rgb(r,g, b);)
  * @li @c font-size (in px)
  * @li @c font-family
  * @param i_inputStream stream containing valid document
  * @param i_size size of stream
  */
  void SetXHTMLText(const CATUnicodeString& i_xhtmlText);
  /**
  * Gets XHTML 1.0 data from editor
  * Format same as that described in #ImportFromXHTML
  * @return CATUnicodeString representing XHTML 1.0 data
  */
  CATUnicodeString GetXHTMLText() const;

  /**
  * Get the @c TextChanged event.
  * The @c TextChanged event is emitted by the editor when it's contents change.
  * for example, when text is inserted or deleted, or when formatting is applied.
  * @par EventProperties
  *   - Name: @c "TextChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* TextChanged();

  /**
  * Get the @c SelectionChanged event.
  * The @c SelectionChanged event is emitted by the editor when it's selection is modified.
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
  * The @c CursorPositionChanged event is emitted by the editor when the position of the cursor changed.
  * @par EventProperties
  *   - Name: @c "CursorPositionChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPCursorEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* CursorPositionChanged();

  /**
  * Get the @c TextActivated event.
  * The @c TextActivated event is emitted by the editor when it receive focus.
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
  * The @c EditingFinished event is emitted by the editor when it lose focus.
  * @par EventProperties
  *   - Name: @c "EditingFinished"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* EditingFinished();

  /**
  * Get the @c HyperlinkClicked event.
  * The @c HyperlinkClicked event is emitted by the editor when user activates an hyperlink.
  * If the event is not consumed, the text editor will try to open the URL associated to the hyperlink.
  * @par EventProperties
  *   - Name: @c "HyperlinkClicked"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPHyperlinkEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* HyperlinkActivated();  
  
  /**
  * Get the @c ReleaseEvt event.
  * The @c ReleaseEvt event is emitted by the editor when mouse click is released.
  * @par EventProperties
  *   - Name: @c "ReleaseEvt"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  * 
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent* ReleaseEvt();

  /**
  * Set focus on text editor
  * Asserts if viewer is not yet attached to widget.
  * Should not be used immediately after creating text editor. Makes sense to call SetFocus after entier dialog is 
  * displayed in viewer.
  * @param iDisplayVirtualKeyboard in Touch environment, enables to display virtual keyboard
  */
  void SetFocus(CATBoolean iDisplayVirtualKeyboard=FALSE);
  /**
  * Reset focus on text editor
  */
  void ResetFocus();

  /** @copydoc CATVidCtlAbstractScrollableArea#ScrollContentBy*/
  virtual void ScrollContentBy(int i_iDeltaX, int i_iDeltaY);
	//----
  void SetBorderVisibleFlag(CATBoolean i_visibleFlag); 
  CATBoolean GetBorderVisibleFlag() const;
	CATVidColor GetAppliedBorderColor() const;
	//----
protected:
  /** @copydoc CATVidWidget#TunnelInformation */
  virtual void TunnelInformation(const CATVidInformation& i_information);
  virtual void TemplateDataUpdated();
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlTextEditor (CATVidCtlTextEditor &);
  CATVidCtlTextEditor& operator=(CATVidCtlTextEditor& original);
  void AddEventNotifications();
  void OnScrollbarSlide(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void ScrollToCursorLocation(const CATMathPoint2Df& i_cursorLocation, int i_lineHeight);
 void HandleMouseWheel(CATBaseUnknown *i_pSender, CATVidMouseWheelEventArgs *i_pArgs);
 CATVidGPText* GetGPText();
public:
 /**
  * @deprecated
  */
  CATVidTextDocument* GetDocument();
  /**
   * @deprecated
   */
  void SetCursorHeight(float iHeight){}
  /**
   * @deprecated
   */
  float GetCursorHeight() const{return 0;}
  /**
  * Sets the position of cursor displayed
  * @parama i_cursorPoint 2D point in viewport coordinate 
  */
  void  SetCursorPoint( const CATMathPoint2Df &i_cursorPoint ){}
  /**
  * Gets the position of cursor displayed
  * @return 2D point in viewport coordinate 
  */
  const CATMathPoint2Df& GetCursorPoint( void ) const{static CATMathPoint2Df dummy;return dummy;}
  /*
  * Moves cursor to closed possible position of given point.
  * @param i_Point 2D point (in viewport coordinates).
  * @return @ref CATVidTextCursor representing current cursor
  */
  CATVidTextCursor& GetCursorForPosition(const CATMathPoint2Df &i_Point);

  CATBoolean GetCursorVisibleFlag () const;
 /*
  * @deprecated use simply ReadOnlyFlag.
  */
  void SetTextInteractionFlags (CATVidCtlTextEditor::TextInteractionFlags i_textInteractionFlags);
  /*
  * @deprecated use simply ReadOnlyFlag.
  */
  CATVidCtlTextEditor::TextInteractionFlags GetTextInteractionFlags () const;

  friend class l_CATVidEditorBase;
  friend class VIDWithStyleBehaviour;
};
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVidCtlTextEditor__TextInteractionFlags);
//-----------------------------------------------------------------------
#endif
