//===================================================================
// COPYRIGHT Dassault Systemes 2014
//===================================================================
#ifndef CATVidTextCursor_H
#define CATVidTextCursor_H
#include "VisuDialog.h"
#include "CATVidTextStyle.h"
#include "CATSYPMacros.h"
class CATVidWidget;
class CATVidGPText;
class l_CATVidEditorBase;

#define CATVidTextDocument l_CATVidEditorBase

/**
* @c CATVidTextCursor provides a cursor representation for rich text editor control.
* The cursor of an editor must be retrieved on a TextEditor as a reference, this way:
* CATVidTextCursor& cursor = myEditor->GetTextCursor();
* @see CATVidTextStyle, @see CATVidCtlTextEditor.
*/
class ExportedByVisuDialog CATVidTextCursor
{
FORCE_STACK_ALLOCATION();
public:
  /**
  * Enums to define how to move the cursor.
  */
  enum MoveOperation {
    /** Move to the start of the document. OldEditorWidget, SMAWflAutCommand, SMAWflAutScript*/
    Start,
    /** Move to the end of the document. OldEditorWidget, SMAWflAutCommand SMAWflAutScript, */
    End,
    /** Move to the start of the current Paragraph. */
    StartOfParagraph,
    /** Move to the end of the current Paragraph. */
    EndOfParagraph,
    /** Move to the start of the current line.  */
    StartOfLine,
    /** Move to the end of the current line. SMAWflAutScript*/
    EndOfLine,
    /** Move to the start of the current word. */
    StartOfWord,
    /** Move to the end of the current word. */
    EndOfWord,
    /** Move to the start of the previous Paragraph. */
    PreviousParagraph,
    /** Move to the beginning of the next Paragraph. SMAWflAutScript*/
    NextParagraph,
    /** Move to the beginning of the previous word. */
    PreviousWord,
    /** Move to the next word. OldEditorWidget*/
    NextWord,
    /** Move to the previous character. OldEditorWidget*/
    PreviousCharacter,
    /** Move to the next character. OldEditorWidget*/
    NextCharacter,
    /** Move same character position of previous line. */
    Up,
    /** Move same character position of next line. OldEditorWidget*/
    Down,
    /** Move left one character. */
    Left,
    /** Move right one character. SMAWflAutCommand, SMAWflAutScript*/
    Right,
    /** Move left one word (Same as PreviousWord). */
    WordLeft,
    /** Move right one word (Same as NextWord). */
    WordRight,
  };
 /**
  * Enum to define mode of cursor movement
  */
  enum MoveMode 
  { 
    /** Update cursor position while moving. No selection will be made. */
    MoveAnchor=0, 
    /** Update the selection while moving. */
    KeepAnchor
  };
  /**
  * Enum to define what to select
  */
  enum SelectionType 
  {
    /** Entier document */
    Document=0,
    /** Paragraph under cursor */
    ParagraphUnderCursor,
    /** Line under cursor */
    LineUnderCursor,
    /** Word under cursor */
    WordUnderCursor
  };
  enum TextElementLevel
  {
    LetterLevel=0, 
    WordLevel, 
    LineLevel, 
    ParagraphLevel,
    DocumentLevel
  };
  /** Used to specify a movement of cursor or a selection */
  enum MovementType
  {
    Forward, 
    Backward
  };

  /*
  * Gets the anchor position
  * This is the same as @ref #GetPosition unless there is a selection. If cursor is moved with @c KeepAnchor 
  * @ref #MoveMode, @ref #GetPosition marks one end of the selection and @ref #GetAnchor marks the other end.
  * @return global cursor position with respect to start of document in terms of number of characters 
  */
  INLINE int GetAnchor() const
  {
    return _anchor;
  }
  /*
  * Check if cursor is at the end of a line, or at the end of the text.
  * @return @c TRUE if cursor is that's the case; otherwise return @c FALSE.
  */
  int CheckIfParagraphEnd() const;
  /*
   * Check if cursor is at the start of a line.
 * @return @c TRUE if cursor is that's the case; otherwise return @c FALSE.
  */
  int CheckIfParagraphStart() const;
  /*
  * Check if cursor is at the end of the document.
  * @return @c TRUE if cursor is that's the case; otherwise return @c FALSE.
  */
  int CheckIfAtEnd() const;
  /*
  * Check if cursor is at the start of the document.
  * @return @c TRUE if cursor is that's the case; otherwise return @c FALSE.
  */
  int CheckIfAtStart() const;

  /*
  * Clears the current selection by setting the anchor to the cursor position.
  * Note that it does not delete the text of the selection.
  */
  void ClearSelection();
  /*
  * If there is no selected text, deletes the character at the current cursor position; 
  * otherwise deletes the selected text.
  */
  void DeleteChar();
  /*
  * If there is no selected text, deletes the character before the current cursor position; 
  * otherwise deletes the selected text.
  */
  void DeletePreviousChar();
  /*
  * Get if selection is present
  * @return @c TRUE if the cursor contains a selection; otherwise returns @c FALSE.
  */
  int GetSelectionFlag()const;

  /** deprecated*/
  void InsertParagraph();
  /*
  * Inserts text at the current position, using the current text style.
  * If there is a selection, the selection is deleted and replaced by text,
  * @param i_text text to insert
  */
  void InsertText ( const CATUnicodeString& i_text, int i_XHTMLFormatFlag=0 );
  /*
  * Inserts text at the current position, using specified text style.
  * If there is a selection, the selection is deleted and replaced by text,
  * @param i_text text to insert
  * @param i_style style for text to insert
  */
  void InsertText ( const CATUnicodeString& i_text, const CATVidTextStyle& i_style );
  /*
  * Moves the cursor by performing the given operation, given number of times, using the specified mode.
  * @param i_operation @ref #MoveOperation to perform.
  * @param i_mode @ref #MoveMode to be used for this operation. Default value is @c MoveAnchor.
  * @return @c TRUE if operation was completed successfully, otherwise returns @c FALSE.
  */
  int MovePosition ( CATVidTextCursor::MoveOperation i_operation, CATVidTextCursor::MoveMode i_mode = MoveAnchor, int i_nbIterations=1);

  void MovePosition ( CATVidTextCursor::MovementType i_movementType, CATVidTextCursor::TextElementLevel i_txtElementLevel, CATVidTextCursor::MoveMode i_mode);
  /*
  * Moves the cursor to the absolute position in the document.
  * @param i_pos New absolute position to set
  * @param i_moveMode @ref #MoveMode to be used. Default is @c MoveAnchor.
  */
  int SetPosition ( int i_pos, MoveMode i_moveMode = MoveAnchor );
  /*
  * Gets the absolute position of the cursor within the document. 
  * @return global cursor position with respect to start of document in terms of number of characters 
  */
  int GetPosition ()const;
  /*
  * If there is a selection, its content is deleted; otherwise does nothing.
  * @return the number of deleted characters.
  */
  int RemoveSelectedText ();
  /*
  * Selects text in the document according to the given selection.
  * @param i_selection what to select
  */
  void Select ( CATVidTextCursor::SelectionType i_selection );
  /*
  * Gets text currently selected. The string returned can be empty if there is no selection.
  * This only returns the text, with no rich text formatting information
  * @return text string
  */
  CATUnicodeString GetSelectedText ()const;
  /*
  * Gets end positon of selection.
  * @return absolute cursor position for end of slection or current position if there is no selection.
  */
  int GetSelectionEnd()const;
  /*
  * Gets start positon of selection.
  * @return absolute cursor position for start of slection or current position if there is no selection.
  */
  int GetSelectionStart()const;
  /*
  * If the cursor has a selection, the given style is applied to 
  * the current selection. Otherwise if the cursor is inside the bounds of a word, the style will be applied to
  * the whole word automatically. If the text is empty, the style is applied as default style.
  * In other cases, nothing is done.
  * @param i_style text style
  * @return 1 if the style has been applied, 0 if not. 
  */
  int SetCharStyle ( const CATVidTextStyle& i_style );
  /*
  * In case of selected text, returns the style of it, that is, the common style properties of the selection.
  * If the cursor is inside the bounds of a word, returns the common style properties of the it.
  * If the text is empty, the returned style is the default one.
  * Otherwise return an empty style.
  */
  CATVidTextStyle GetCharStyle () const;
  /**
  * In case of selected text, returns the style of it, that is, the common style properties of the selection.
  * If the cursor is inside the bounds of a word, returns the common style properties of the it.
  * If the text is empty, the returned style is the default one.
  * Otherwise return the style of the character located at the cursor position (or at the last character when cursor is at the very end of the text).
   */
  CATVidTextStyle GetCharFormat()const;
  void SetCharFormat ( const CATVidTextStyle& i_style );

  /**
  * Set cursor color
  * @param i_color color to set
  */
  void SetCursorColor(const CATVidColor& i_color);
  /**
  * Get current cursor color
  * @return color of cursor
  */
  const CATVidColor& GetCursorColor() const;
private:
  // 
  CATVidTextCursor(l_CATVidEditorBase* i_editor);
  /**
  * Constructs a @c CATVidTextCursor.
  * @param ipRichText CATVidTextDocument class instance (Not accesible outside this framework)
  */
  CATVidTextCursor(l_CATVidEditorBase& i_editor);
  /**
  * Destructor
  */
  ~CATVidTextCursor ();

  CATVidTextCursor ( CATVidTextCursor & i_cursor );
  CATVidTextCursor& operator= ( CATVidTextCursor & i_cursor );
private:
  int ComputePosition(CATVidTextCursor::MovementType i_movementType, CATVidTextCursor::TextElementLevel i_txtElementLevel) const;
  l_CATVidEditorBase& _editor;
  friend class SMAWflScriptUI;
  friend class SMAWflAutCommand;
  friend class SMAWflAutScript;
  friend class l_CATVidCtlEditorBase;
  friend class l_CATVidEditorBase;
  CATVidGPText& _text;
  int _position;
  int _anchor;
};
//-----------------------------------------------------------------------

#endif
