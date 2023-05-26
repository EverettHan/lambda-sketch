//===================================================================
// COPYRIGHT Dassault Systemes 2013/09/05
//===================================================================
// CATVidCtlCodeEditor.cpp
// Header definition of class CATVidCtlCodeEditor
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/09/05 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATVidCtlCodeEditor_H
#define CATVidCtlCodeEditor_H

#include "VisuDialog.h"
#include "CATVidCtl.h"

class CATVidCtlImageAndLabelCombo;
class CATVidCtlLineEditor;
class CATVidCtlWebViewer;
class CATVidJSMessageEventArgs;
//class CATVidWebContextMenuEventArgs;
//-----------------------------------------------------------------------

class ExportedByVisuDialog CATVidCtlCodeEditor: public CATVidCtl
{
  CATDeclareClass;
  DeclareResource(CATVidCtlCodeEditor, CATVidCtl);

public:
  // Standard constructors and destructors
  // -------------------------------------
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  CATVidCtlCodeEditor();
  [[deprecated("CATVidCtlCodeEditor::CreateCodeEditor() is deprecated, please use CATVidCtlCodeMirror::CreateCodeMirror() instead.")]]
  static CATVidCtlCodeEditor* CreateCodeEditor(CATCommand* i_pParent, const CATString& i_pIdentifier);

  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Sets the text to be displayed
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetText(const CATUnicodeString& iText);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Requests the text currently displayed
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void RequestText();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Sets the size of the text to be displayed
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetFontSize(int i_Size);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Gets the size of the text displayed
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  int GetFontSize() const { return _fontSize; }
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to show line numbers to the left of the editor
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetShowLineNumbers(CATBoolean i_ShowLineNumbers);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Returns whether the line numbers are displayed in the left of the editor
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  CATBoolean GetShowLineNumbers() const { return _showLineNumbers; }
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether editor should scroll or wrap for long lines
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetLineWrappingFlag(CATBoolean i_LineWrappingFlag);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Returns whether editor scrolls or not for long lines
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  CATBoolean GetLineWrappingFlag() const { return _lineWrappingFlag; }
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to disable editing of the editor content by the user
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetReadOnlyFlag(CATBoolean i_ReadOnlyFlag);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Returns whether editing of the editor content is disabled or not
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  CATBoolean GetReadOnlyFlag() const { return _readOnlyFlag; }
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to enable a syntax mode on the editor content
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetSyntaxMode(const CATUnicodeString& i_SyntaxMode);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Returns syntax mode of the editor
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  CATUnicodeString GetSyntaxMode() const { return _syntaxMode; }
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to allow the user to add/remove breakpoints
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetBreakpointsSupport(CATBoolean i_BreakpointsSupport);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Returns whether adding/removing breakpoints is allowed
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  CATBoolean GetBreakpointsSupport() const { return _breakpointsSupport;}
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to set how bold or thin characters in text should be displayed.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetBoldFlag(CATBoolean i_BoldFlag);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Returns how bold or thin characters in text are displayed.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  CATBoolean GetBoldFlag() const { return _boldFlag; }
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to set italic characters or not in text should be displayed.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetItalicFlag(CATBoolean i_ItalicFlag);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Returns TRUE if text is displayed in italic mode.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  CATBoolean GetItalicFlag() const { return _italicFlag; }
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to set the font name of the editor content
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetFontName(const CATUnicodeString& i_FontName);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Returns font name used by the editor
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  CATUnicodeString GetFontName() const { return _fontName; }
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Returns the cursor position in the editor
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  CATMathPoint2Df GetCursorPosition() const { return _cursorPosition; }
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to show editor's status bar
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetShowStatusBar(CATBoolean i_ShowStatusBar);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Returns whether the status bar is displayed or not
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  CATBoolean GetShowStatusBar() const { return _showStatusBar; }
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Returns status bar information
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  CATUnicodeString GetStatusBarInfo() const { return _statusBarInfo; }
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * If a debugger is used with this component, it allows to manage that the debugger is currently in a break state.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetBreakState(CATBoolean i_BreakState);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * If a debugger is used with this component, it returns TRUE if the debugger is currently in a break state.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  CATBoolean GetBreakState() const { return _breakState; }
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to show editor's find bar
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetShowFindBar(CATBoolean i_ShowFindBar);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Returns whether the find bar is displayed or not
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  CATBoolean GetShowFindBar() const { return _showFindBar; }
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to toggle a breakpoint at current selected line.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void ToggleBreakpoint();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to toggle a breakpoint activity at current selected line.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void ToggleBreakpointActivity();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to enable all breakpoints
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void EnableAllBreakpoints();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to disable all breakpoints
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void DisableAllBreakpoints();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to delete all breakpoints
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void DeleteAllBreakpoints();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to enable a breakpoint at given line
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void EnableBreakpoint(int i_Line);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to disable a breakpoint at given line
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void DisableBreakpoint(int i_Line);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to delete a breakpoint at given line
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void DeleteBreakpoint(int i_Line);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to display execution marker at given line
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void DisplayExecutionMarker(int i_Line);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to display (and scroll to if necessary) the given line
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void ScrollToLine(int i_Line);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Whether to clear undo history
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void ClearHistory();
  /** 
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Request the currently selected code.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void RequestSelection();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Set the current selection
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetSelection(int i_LineStart, int i_CharStart, int i_LineEnd, int i_CharEnd);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Register external css file
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void RegisterExternalCss(const CATUnicodeString& i_CssPath);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Request the currently selected code range.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void RequestSelectionRange();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Can be use to mark a range of text with a specific CSS class name
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void MarkText(int i_LineStart, int i_CharStart, int i_LineEnd, int i_CharEnd, CATUnicodeString i_ClassName);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Can be use to unmark a range of text
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void UnMarkText(int i_LineStart, int i_CharStart, int i_LineEnd, int i_CharEnd);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Set focus on code editor
   * @param iDisplayVirtualKeyboard in Touch environment, enables to display virtual keyboard
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void SetFocus(CATBoolean iDisplayVirtualKeyboard=FALSE);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Reset focus on code editor
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void ResetFocus();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Insert text at the given position
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void InsertText(const CATUnicodeString& i_Text, int i_LineStart, int i_CharStart);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Replace text from start position to end position
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void ReplaceText(const CATUnicodeString& i_Text, int i_LineStart, int i_CharStart, int i_LineEnd, int i_CharEnd);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever the text changes
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* TextChanged();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever the text is requested by code
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* TextRequested();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever the text selection is requested by code.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* SelectionRequested();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever the text selection range is requested by code.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* SelectionRangeRequested();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever Ctrl+S is activated on the editor
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* AskForSave();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever F5 is activated on the editor during debugging session
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* Continue();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever F10 is activated on the editor during debugging session
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* StepOver();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever F11 is activated on the editor during debugging session
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* StepIn();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever Shift+F11 is activated on the editor during debugging session
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* StepOut();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever Shift+F5 is activated on the editor during debugging session
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* Stop();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever Ctr+F5 is activated on the editor
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* Break();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever F5 is activated on the editor
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* Run();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever F9 is activated on the editor
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* BreakpointToggled();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever Ctrl+F9 is activated on the editor
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* BreakpointActivityToggled();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever Shift+Ctrl+F10 is activated on the editor and all breakpoints have been enabled
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* AllBreakpointsEnabled();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever Shift+Ctrl+F10 is activated on the editor and all breakpoints have been disabled
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* AllBreakpointsDisabled();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever Shift+Ctrl+F9 is activated on the editor
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* AllBreakpointsDeleted();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever the editor is ready to use
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* Ready();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever the selection or cursor moves
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* CursorActivity();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever the editor is focused
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* Focus();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever the editor focus is lost
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* Blur();
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Emitted whenever a context menu is about to be displayed.
   */
  /* [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  static CATSYPEvent* ContextMenu(); */
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Handled whenever find feature is cancelled.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void OnCancelFind(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Handled whenever find next occurence is asked.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void OnFind(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Handled whenever find previous occurence is asked.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void OnFindPrev(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Handled whenever text to find is changed.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void OnFindTextChanged(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  /**
   * @deprecated
   * @c CATVidCtlCodeEditor is deprecated, please use @ref CATVidCtlCodeMirror instead.
   *
   * Handled whenever find is asked.
   */
  [[deprecated("CATVidCtlCodeEditor is deprecated, please use CATVidCtlCodeMirror instead.")]]
  void OnFindReturnPressed(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

protected: 
  virtual ~CATVidCtlCodeEditor ();

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlCodeEditor (CATVidCtlCodeEditor &);
  CATVidCtlCodeEditor& operator=(CATVidCtlCodeEditor&);

  virtual void TemplateDataUpdated();
  void OnModesComboSelect(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_spArgs);
  void HandleCEFEvent(CATBaseUnknown* i_pSender, CATVidJSMessageEventArgs* i_spArgs);
  //void HandleCEFContextMenu(CATBaseUnknown* i_pSender, CATVidWebContextMenuEventArgs* i_spArgs);
  CATUnicodeString _GetEditorRscPath(); 
  void    _SetCMBoolOption(const CATUnicodeString& i_Option, CATBoolean i_Value);
  void    _SetCMStringOption(const CATUnicodeString& i_Option, const CATUnicodeString& i_Value);
  void    _SetCMStyleAttribute(const CATUnicodeString& i_Attribute, const CATUnicodeString& i_Value);
  void    _SetCMArg(const CATUnicodeString& i_Arg, const CATUnicodeString& i_Attribute, const CATUnicodeString& i_Value);
  void    _SendCommand(const CATUnicodeString& i_CommandID, const CATUnicodeString& i_CommandData);
  void    _CallJSOnEditor(const CATUnicodeString& iFunction);
  void    _OnJavaScriptNotification(const CATUnicodeString& i_CommandArgs);
  HRESULT _URLDecode(const CATUnicodeString& iUrl, CATUnicodeString& oUrl);
  void    _URLEncode(CATUnicodeString& ioUrl);
  void    _HandleJavaScriptCommand(const CATUnicodeString& i_Command);
  void    _SetCursorPosition(const CATMathPoint2Df& iCursorPosition); 
  void    _SetStatusBarInfo(const CATUnicodeString& iStatusBarInfo);
  void    _TreatParams(const CATUnicodeString& iParams);
  void    _SetReady();
  void    _BuildStatusBarInfo(int iLine, int iChar);
  CATUnicodeString _BuildStartAndEndPosition(int i_LineStart, int i_CharStart, int i_LineEnd, int i_CharEnd);

  CATVidCtlWebViewer* _webViewer;
  CATVidCtlImageAndLabelCombo* _modesCombo; 
  CATVidCtlLineEditor*  _findEditor;

  int _fontSize;
  CATBoolean _showLineNumbers;
  CATBoolean _lineWrappingFlag; 
  CATBoolean _readOnlyFlag;
  CATUnicodeString _syntaxMode;
  CATBoolean _breakpointsSupport;
  CATBoolean _boldFlag;
  CATBoolean _italicFlag;
  CATUnicodeString _fontName; 
  CATMathPoint2Df _cursorPosition;
  CATBoolean _showStatusBar;
  CATUnicodeString _statusBarInfo; 
  CATBoolean _breakState;
  CATBoolean _showFindBar;
  CATBoolean _findQueryDirty;
  CATUnicodeString _searchedPattern;
};

//-----------------------------------------------------------------------

#endif