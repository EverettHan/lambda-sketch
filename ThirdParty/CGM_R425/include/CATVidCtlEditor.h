// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATVidCtlEditor.h
// Header definition of CATVidCtlEditor
//
//===================================================================
//
//  Jul 2006  Creation: jov
//===================================================================
#ifndef CATVidCtlEditor_H
#define CATVidCtlEditor_H

#include <VisuDialog.h>
#include <CATVidCtl.h>
#include <CATVidEnum.h>
#include <CATDlgUtility.h>
#include <CATUnicodeString.h>
#include <CATVidColor.h>
#include <CATBaseUnknown_WR.h>

class l_CATVidCtlEditor;
class CATVidLayLayer;
class CATVidCtlDlgContainer;
class CATVidCtlText;
class CATVidLayScrollable;
class CATVidGPSquare;
class CATDlgEditor;
/**
 * Base class for editor.
 * <b>Role</b>:
 * This widget is used to edit text, or values.
 * @ingroup VIDControls
 */
class ExportedByVisuDialog CATVidCtlEditor: public CATVidCtl
{
  CATDeclareClass;
public:
  /**
   * Constructs a CATVidCtlEditor.
   * No associsated style, use static factory CreateEditor
   */
  CATVidCtlEditor (CATCommand *i_pParent, const CATString & i_pIdentifier, CATDlgStyle i_style=NULL);
  /**
   * Constructs a CATVidCtlEditor.
   * No associsated style, use static factory CreateEditor
   */
  CATVidCtlEditor ();
  /**
   * Returns Get line count in case of multiline editor . 
   * A line finish with a carriage return, which is not returned by the function
   */
  int  GetLineCount();
  /**
   * Set string located to line number=i_index. 
   * @param i_line
   *   The line to set;
   * @param i_index
   *   The index of the line to return;
   *   <br>
   *   <b>Legal values</b> : from -1 to any positive value.
   *   Default value is -1, that is the last line.
   */
  int  SetLine( const CATUnicodeString& i_line, int i_index=-1 );
  /**
   * Returns string located to line number=i_index. 
   * @param o_line
   *   The line to return;
   * @param i_index
   *   The index of the line to return;
   *   <br>
   *   <b>Legal values</b> : from -1 to any positive value.
   *   Default value is -1, that is the last line.
   */
  void GetLine( CATUnicodeString& o_line, int i_index=-1 );
  /**
   * Returns last line. 
   */
  CATUnicodeString GetLine();
  /**
   *  Clear line located to line number=i_index. 
   * @param i_index
   *   The index of the line to return;
   *   <br>
   *   <b>Legal values</b> : from -1 to any positive value.
   *   Default value is -1, that is the last line.
   */
  void ClearLine( int i_index=-1 );
  /**
   * Set the maximum character count that a line can contain.
   * @param i_MaximumCharacterCount
   *   The maximum character count that a line can contain.
   */
  void SetMaxCharacterWidth( int i_MaximumCharacterCount );
  /**
   * Get the maximum character count that a line can contain.
   * @return
   *   The maximum character count that a line can contain.
   */
  int  GetMaxCharacterWidth();
  /**
   * Sets the data type of the editor
   * @param i_dataType
   * The data type of the editor to set.
   *   <br>
   *   <b>Legal values</b> : It can be set to either :
   *   <dl>
   *   <dt><tt>CATVidCtlEditorText</tt><dd>           
   *   <dt><tt>CATVidCtlEditorInt</tt><dd>            
   *   <dt><tt>CATVidCtlEditorFloat</tt><dd>          
   *   <dt><tt>CATVidCtlEditorAlphabetical</tt><dd>   
   *   <dt><tt>CATVidCtlEditorNumerical</tt><dd>      
   *   <dt><tt>CATVidCtlEditorAlphanumerical</tt><dd> 
   *   <dt><tt>CATVidCtlEditorDouble</tt><dd>         
   *   <dt><tt>CATVidCtlEditorPassword</tt><dd>       
   *   </dl>
   */
  void SetDataType(CATVidCtlEditorDataType i_dataType);
  /**
   * Returns the data type of the editor
   * The data type of the editor can be :
   *   <br>
   *   <dl>
   *   <dt><tt>CATVidCtlEditorText</tt><dd>           
   *   <dt><tt>CATVidCtlEditorInt</tt><dd>            
   *   <dt><tt>CATVidCtlEditorFloat</tt><dd>          
   *   <dt><tt>CATVidCtlEditorAlphabetical</tt><dd>   
   *   <dt><tt>CATVidCtlEditorNumerical</tt><dd>      
   *   <dt><tt>CATVidCtlEditorAlphanumerical</tt><dd> 
   *   <dt><tt>CATVidCtlEditorDouble</tt><dd>         
   *   <dt><tt>CATVidCtlEditorPassword</tt><dd>       
   *   </dl>
   */
  CATVidCtlEditorDataType GetDataType() const;
  /**
   * Set text of the editor, by clearing it first, with CR = \n
   * @param i_text
   *   The text to set;
   */
  void SetText( const CATUnicodeString &i_text);
  /**
   * Returns text of the editor, with CR = \n
   */
  CATUnicodeString GetText() const;
  /**
   * Set integer value on the editor, by clearing it first.
   * @param i_value
   *   The value to set;
   */
  void SetIntegerValue( int i_value);
  /**
   * Returns integer value of the editor (if set)
   */
  int  GetIntegerValue() const;
  /**
   * Set float value on the editor, by clearing it first.
   * @param i_value
   *   The value to set;
   */
  void SetFloatValue( float i_value);
  /**
   * Returns float value of the editor (if set)
   */
  float GetFloatValue() const;
  /**
   * Set double value on the editor, by clearing it first.
   * @param i_value
   *   The value to set;
   */
  void SetValue( double i_value);
  /**
   * Returns doule value of the editor (if set)
   */
  double GetValue() const;
  /**
   * Sets selection on the editor.
   * @param i_firstCharacterIndex
   *   The first char index;
   * @param i_lastCharacterIndex
   *   The last char index;
   */
  void SetSelection(int i_firstCharacterIndex, int i_lastCharacterIndex);
  /**
   * Returns selection on the editor.
   * @param o_firstCharacterIndex
   *   The first char index;
   * @param o_lastCharacterIndex
   *   The last char index;
   */
  void GetSelection(int& o_firstCharacterIndex, int& o_lastCharacterIndex) const;
  /**
   * Sets a flag that enable a text editor to have pultiple lines
   * @param i_multilineFlag
   *     The flag to set
   */
  void SetMultilineFlag(CATBoolean i_multilineFlag);
  /**
   * Returns the flag that enable a text editor to have pultiple lines
   */
  CATBoolean GetMultilineFlag() const;
  /**
   * Sets a flag that modify the use of the RETURN and SHIFT+RETURN key, 
   * in the case of multiline text editor.
   * @param i_shiftEnterActiveFlag
   *   <br>
   *   <dl>
   *   <dt><tt>FALSE</tt><dd> RETURN and SHIFT+RETURN add a carriage return (CR) in the text.
   *   <dt><tt>FALSE</tt><dd> SHIFT+RETURN adds a CR in the text. 
   *                          RETURN has the standard behavior. (ModifyExt+Modify events)
   *   </dl>
   */
  void SetShiftEnterActiveFlag(CATBoolean i_shiftEnterActiveFlag);
  /**
   * Returns a flag that modify the use of the RETURN and SHIFT+RETURN key, 
   * in the case of multiline text editor.
   *   <br>
   *   <dl>
   *   <dt><tt>FALSE</tt><dd> RETURN and SHIFT+RETURN add a carriage return (CR) in the text.
   *   <dt><tt>FALSE</tt><dd> SHIFT+RETURN adds a CR in the text. 
   *                          RETURN has the standard behavior. (ModifyExt+Modify events)
   *   </dl>
   **/
  CATBoolean GetShiftEnterActiveFlag() const;
  /**
   * Sets the first visible of scrollable to line corresponding to given index,
   * if possible, and in case of multiline editor.
   * @param i_firstVisibleLine
   *   The index of the line.
   */
  void SetFirstLine( int i_firstVisibleLine);
  /**
   * Returns the first visible of scrollable to line corresponding to given index,
   * if possible, and in case of multiline editor.
   * @param i_firstVisibleLine
   *   The index of the line.
   */
  int  GetFirstLine() const;
  /**
   * Sets a flag that enable the password display with ***
   * @param i_passwordFlag
   *     The flag to set
   */
  void SetPasswordFlag(CATBoolean i_passwordFlag);
  /**
   * Returns a flag that enable the password display with ***
   * @param i_passwordFlag
   *     The flag to set
   */
  CATBoolean GetPasswordFlag() const;
  /**
   * Sets a flag that enable to wrap word at the end of a line, in case of multiline text
   * @param i_wrapFlag
   *     The flag to set
   */
  void SetWordWrapFlag(CATBoolean i_wrapFlag);
  /**
   * Returns a flag that enable to wrap word at the end of a line, in case of multiline text
   */
  CATBoolean GetWordWrapFlag() const;
  /**
   * Sets a flag that enable to set ReadOnly mode on the editor
   * @param i_readOnlyFlag
   *     The flag to set
   */
  void SetReadOnlyFlag(CATBoolean i_readOnlyFlag);
  /**
   * Returns a flag that enable to set ReadOnly mode on the editor
   */
  CATBoolean GetReadOnlyFlag() const;
  /**
   * Sets the color used as hyperlink color
   * @param i_hyperlinkColor
   * The hyperlink color to set.
   */
  void SetHyperlinkColor( const CATVidColor &i_hyperlinkColor);
  /**
   * Returns the color used as hyperlink color
   */
  void GetHyperlinkColor(CATVidColor& o_color);
  /**
   * Sets the color used as visited hyperlink color
   * @param i_visitedHyperlinkColor
   * The hyperlink color to set.
   */
  void SetVisitedHyperlinkColor( const CATVidColor &i_visitedHyperlinkColor );
  /**
   * Returns the color used as visited hyperlink color
   */
  void GetVisitedHyperlinkColor(CATVidColor& o_color);
  /**
   * Sets a flag that allows to send EditKeybdEntryNotification 
   * when a keyboard touch is pressed
   * @param i_listenKeybdEntryFlag
   * The flag to set.
   */
  void SetListenKeybdEntryFlag(CATBoolean i_listenKeybdEntryFlag);
  /**
   * Returns a flag that allows to send EditKeybdEntryNotification 
   * when a keyboard touch is pressed
   */
  CATBoolean GetListenKeybdEntryFlag() const;
  /**
   * Returnst he last keyboard entry, when ListenKeybdEntryFlag is TRUE.
   */
  const CATUnicodeString& GetKeybdEntry() const;
  /**
   * Force by code the focus in of editor.
   * 
   * @note
   * If the focus mode (see @ref #SetFocusMode) is @ref #VID_FOCUS, you must
   * ensure that the editor is attached to a viewer (through its parent widgets)
   * and visible (including the visibility of its parent) before calling this 
   * function. Not respecting this pre-condition will result in a @ref #FAILURE 
   * and the editor won't have the focus.
   */
   void SwitchToEditMode();
  /**
   * Sets the color used as foreground color (for example, used to draw the text most of the time)
   * @param i_foregroundColor
   * The foreground color to set.
   */
  void SetForegroundColor( const CATVidColor &i_foregroundColor );
  /**
   * Returns the color used as foreground color (for example, used to draw the text most of the time)
   */
  const CATVidColor& GetForegroundColor( void ) const;
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
   * Returns the event notification sent whenever the editor text is modified.
   * This event is send whenever ModifyExt is send.
   */
  CATNotification *GetEditModifyNotification() const;
  /**
   * Returns the event notification sent whenever the RETURN key is clicked 
   * on multiline text editor, with ShiftEnterActiveFlag set to TRUE.
   * It is sent even if the text has not be modified
   */
  CATNotification *GetEditModifyExtNotification() const;
  /**
   * Returns the event notification sent whenever the editor selection is modified
   */
  CATNotification *GetSelectionChangeNotification() const;
  /**
   * Returns the event notification sent whenever the editor begins to be used
   */
  CATNotification *GetEditFocusInNotification() const;
  /**
   * Returns the event notification sent whenever a keyboard touch is pressed, 
   * and if the ListenKeybdEntryFlag is sert to TRUE.
   */
  CATNotification *GetEditKeybdEntryNotification() const;
  /*@nodoc*/
  virtual void TunnelInformation(const CATVidInformation& i_information);
  /**
   * Adds the line to the editor
   */
  unsigned int AddLine(const CATUnicodeString& i_line);
  /**
   * Clears all the lines
   */  
  void Clear();
  /**
   * Sets the color for specified characters
   */
  void SetColor(const CATVidColor& i_color, unsigned int i_firstCharColorIndex, unsigned int i_nbCharColor);
  /**
   * Focus mode of a @c CATVidCtlEditor.
   * The focus mode changes the way the @c CATVidCtlEditor handles keyboard focus.
   */
  enum FocusMode {
    /**
     * The editor is editable only if the user clicks on it.
     *
     * Moreover pressing TAB (or SHIFT-TAB) or ESCAPE when in edition has no effect.<br/>
     * Pressing ENTER will end the edition (if the content of the editor has been 
     * changed on Windows and in all cases on UNIX).<br/>
     * If the user want to give the focus to an other VID component or an other
     * dialog object, it has to click outside.
     *
     * This behavior is the default behavior.
     */
    CLICK_TO_EDIT,
    /**
     * The editor is editable as soon as it receive the VID focus.
     * 
     * Pressing TAB (or SHIFT-TAB) will transfer the focus to the next VID
     * component.
     *
     * Pressing ENTER or ESCAPE when editing the editor will have the same 
     * effect as pressing those keys while an other VID component has the focus
     * (i.e. it will press the default or escape buttons).<br/>
     * Note that pressing ENTER, even after the content of the editor has
     * been modified will not end the edition.
     *
     * @note
     * If the user clicks in the viewer or in a another window or does
     * anything that makes the @c CATDlgEditor used for edition lose the dialog's
     * focus, then the @c CATVidCtlEditor will exit edit mode. To put it again in
     * edit mode, the user has to click on it (as in @ref FocusMode#CLICK_TO_EDIT
     * mode).
     */
    VID_FOCUS
  };
  /**
   * Set the focus mode of the editor.
   *
   * The focus mode changes the way the @c CATVidCtlEditor handles keyboard focus.
   * See @ref #FocusMode enum documentation for details.
   *
   * By default the focus mode is @ref FocusMode#CLICK_TO_EDIT.
   * @param i_focusMode the focus mode to use.
   */
  void SetFocusMode(FocusMode i_focusMode);
  /**nodoc stop using it. do nothing.*/
  void SetUseGeometricTextGP(CATBoolean i_bUseGeometricTextGP);
  /**nodoc to remove*/
  void SelectAll();
  /**nodoc to remove*/
  void ResetSelection();
  /**nodoc to remove*/
  void SetFontHeight(unsigned int i_fontHeight);
  /**nodoc to remove*/
  unsigned int GetFontHeight() const;
  /**nodoc to remove*/
  void SetFont(CATUnicodeString i_Value);
  /**nodoc to remove*/
  CATUnicodeString  GetFont()const;
  /**nodoc to remove*/
  void SetBold(CATBoolean i_Value);
  /**nodoc to remove*/
  void SetUnderline(CATBoolean i_Value);
  /**nodoc to remove*/
  CATBoolean   GetUnderline() const;
  /**nodoc to remove*/
  void SetItalic (CATBoolean i_Value);
  /**nodoc to remove*/
  void SetTextColor(const CATVidColor& i_color);
protected:
  virtual ~CATVidCtlEditor ();

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlEditor (CATVidCtlEditor &);
  CATVidCtlEditor& operator=(CATVidCtlEditor& original);

  void BuildEditor();

  void StopUseDlgEditor();

  void OnFocusOutCB (CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );
  void OnTextActivate (CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );
  void OnScrollAction (CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );
  void OnEditModifyExtCB (CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );
  void OnEditModifyCB (CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );
  void OnMouseEntryCB (CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );
  void OnMouseLeaveCB (CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );
  void OnSelectionChangeCB (CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );
  
  static int sKeyboardEntryCB(const CATUnicodeString &, void *);
  void KeyboardEntryCB(const CATUnicodeString &i_text);

  void ExitEditMode();

  /**
   * Update the content of the @c CATDlgEditor used for "edit" mode.
   * @note
   * This function does nothing if we are not in "edit" mode.
   * @param i_pUpdate a pointer to a function that will be used
   * to call the appropriate @c SetXXXX function of the @c CATDlgEditor.
   * Can't be @c NULL.
   * @param i_pData a pointer on the data that should be given to
   * the function @a i_pUpdate. Can't be @c NULL.
   */
  void UpdateDlgEditor(void (*i_pUpdate)(CATDlgEditor *i_pEditor, void *i_pData), void *i_pData);
  /**
   * Same behavior as @ref #SetText but does not update the
   * content of the @c CATDlgEditor even in edit mode.
   *
   * This function is used by internal code when it modifies
   * the content of this object with the value contained in
   * the @c CATDlgEditor.
   */
  void SetTextWODlgUpdate(const CATUnicodeString &i_text);
  /**
   * Same behavior as @ref #SetIntegerValue but does not update the
   * content of the @c CATDlgEditor even in edit mode.
   *
   * This function is used by internal code when it modifies
   * the content of this object with the value contained in
   * the @c CATDlgEditor.
   */
  void SetIntegerValueWODlgUpdate(int i_value);
  /**
   * Same behavior as @ref #SetFloatValue but does not update the
   * content of the @c CATDlgEditor even in edit mode.
   *
   * This function is used by internal code when it modifies
   * the content of this object with the value contained in
   * the @c CATDlgEditor.
   */
  void SetFloatValueWODlgUpdate(float i_value);
  /**
   * Same behavior as @ref #SetValue but does not update the
   * content of the @c CATDlgEditor even in edit mode.
   *
   * This function is used by internal code when it modifies
   * the content of this object with the value contained in
   * the @c CATDlgEditor.
   */
  void SetValueWODlgUpdate(double i_value);
  /**
   * Same behavior as @ref #SetLine but does not update the
   * content of the @c CATDlgEditor even in edit mode.
   *
   * This function is used by internal code when it modifies
   * the content of this object with the value contained in
   * the @c CATDlgEditor.
   */
  int SetLineWODlgUpdate(const CATUnicodeString& i_line, int i_index = -1);
  /**
   * Callback function for the TAB key in the @c CATDlgEditor used for edition.
   * This callback will be used when the @c FocusMode is @ref FocusMode#VID_FOCUS.
   * @param i_shiftDown the state of the SHIFT key when TAB was pressed (@c !=0 if
   * the SHIFT key was down).
   * @param i_pData the data associated with the callback. For this class it is the
   * pointer on the instance of @c CATVidCtlEditor that registered the callback.
   * @see CATDlgEditorProtected#SetTabCallback
   * @see #SetFocusMode
   */
  static void TabCallback(int i_shiftDown, void *i_pData);
  /**
   * Member function called by @ref #TabCallback.
   * @param i_shiftDown the value received by @c TabCallback.
   */
  void OnTabInDlgEditor(int i_shiftDown);
  /**
   * Callback function for the ENTER key in the @c CATDlgEditor used for edition.
   * This callback will be used when the @c FocusMode is @ref FocusMode#VID_FOCUS.
   * @param i_down @c !=0 if the ENTER is pressed down, @c 0 if ENTER key is released.
   * @param i_pData the data associated with the callback. For this class it is the
   * pointer on the instance of @c CATVidCtlEditor that registered the callback.
   * @see CATDlgEditorProtected#SetEnterCallback
   * @see #SetFocusMode
   */
  static void EnterCallback(int i_down, void *i_pData);
  /**
   * Member function called by @ref #EnterCallback.
   * @param i_down the value received by @c EnterCallback.
   */
  void OnEnterInDlgEditor(int i_down);
  /**
   * Callback function for the ESCAPE key in the @c CATDlgEditor used for edition.
   * This callback will be used when the @c FocusMode is @ref FocusMode#VID_FOCUS.
   * @see CATDlgEditorProtected#SetEscapeCallback
   * @see #SetFocusMode
   * @param i_down @c !=0 if the ESCAPE is pressed down, @c 0 if ESCAPE key is released.
   * @param i_pData the data associated with the callback. For this class it is the
   * pointer on the instance of @c CATVidCtlEditor that registered the callback.
   */
  static void EscapeCallback(int i_down, void *i_pData);
  /**
   * Member function called by @ref #EscapeCallback.
   * @param i_down the value received by @c EscapeCallback.
   */
  void OnEscapeInDlgEditor(int i_down);
  /**
   * Uninstall the current focus mode.
   * This function will be called before the focus mode is changed and when this
   * component is destroyed. It ensure that the previous focus mode won't affect
   * the new one and that all callbacks are removed when this component is destroyed.
   */
  void UninstallFocusMode();
  /**
   * Install the current focus mode.
   * This function will be called after the focus mode is changed and when this
   * component is built (in the constructor).
   */
  void InstallFocusMode();
  /**
   * Install the callbacks needed by @ref FocusMode#VID_FOCUS focus mode.
   * @note
   * It will install the callbacks on the @c CATDlgEditor pointed by
   * @ref #_dlgEditor_WR. It is invalid to call this function is @c _dlgEditor_WR
   * is invalid.
   * @note
   * This function must only be called when @ref #_focusMode is @c VID_FOCUS.
   */
  void InstallVidFocusEditorCallbacks();
  /**
   * Uninstall the callbacks needed by @ref FocusMode#VID_FOCUS focus mode.
   * @note
   * It will uninstall the callbacks on the @c CATDlgEditor pointed by
   * @ref #_dlgEditor_WR. It is invalid to call this function is @c _dlgEditor_WR
   * is invalid.
   * @note
   * This function must only be called when @ref #_focusMode is @c VID_FOCUS.
   */
  void UninstallVidFocusEditorCallbacks();
  /**
   * Generate a keyboard event and send it to VID infrastructure.
   * @note
   * The event will be sent to the @ref CATVidFraActivator corresponding to
   * the viewer that currently displays this editor.<br/>
   * As a consequence this editor must be displayed in a viewer when this
   * function is called.
   * @param i_keyCode the key code of the key. It must be a valid @ref CATKeyCode,
   * i.e. one of the value found in the anonymous enum containing @ref CATF1.
   * @param i_modifiers a bitfield combining @c CATModifier values, i.e. the values
   * in the anonymous enum containing CATControl.
   * @param i_down @c !=0 if the key is pressed down, @c 0 if the key is released.
   */
  void GenerateKeyEvent(int i_keyCode, int i_modifiers, int i_down);

  /**
   * Display the @c CATDlgEditor for edition of this editor.
   * @note
   * This function must not be called if the CATDlgEditor is already visible.
   * @note
   * The @c CATDlgEditor is available through the weak-reference @ref #_dlgEditor_WR.
   */
  void InternalSwitchToEditMode();

  /**
   * Syncrhonize this object with the @c CATDlgEditor used for edition.
   * @note
   * This function must only be called when the component is in "edit"
   * mode, i.e. when the @c CATDlgEditor exists (@ref #_dlgEditor_WR valid).
   */
  void PullDlgEditorState();

  /**
   * Give the VID focus to this editor in its viewer.
   *
   * @note
   * You must ensure that the editor is attached to a viewer (through its parent widgets)
   * and visible (including the visibility of its parent) before calling this 
   * function. Not respecting this pre-condition will result in a @ref #FAILURE 
   * and the editor won't have the focus.
   */
  void RequestVIDFocusInViewer();
private:
  friend class l_CATVidCtlEditor;


  CATVidCtlDlgContainer* _pCommonDlgEditor;
  CATBaseUnknown_WR _dlgEditor_WR;
  CATVidCtlText* _pCtlText;
  CATVidCtlText* _pCtlPassword;
  CATVidLayScrollable *_pScrollableContainer;
  CATVidLayLayer* _pLayLayer;
  CATVidGPSquare* _pBackground;
  CATDlgStyle _style;
  int _fontHeight;
  int _interline;
  int _leftMargin;
  int _topMargin;
  CATUnicodeString _keybdEntry;
  int _keybdEntryCount;

  CATVidColor _backgroundColor;
  CATVidColor _foregroundColor;

  CATBoolean _shiftEnterActiveFlag;

  int _firstSelectedCharacterIndex;
  int _lastSelectedCharacterIndex;

  int _maximumCharacterCount;

  CATBoolean _editModeFlag;
  CATBoolean _listenKeybdEntryFlag;

  CATBoolean _modifyExtCalled;

  CATBoolean _mousePressFlag;
  CATBoolean _focusOutRequested;
  /** boolean state set to @c != 0 by @ref #UpdateDlgEditor before
   *  updating the @c CATDlgEditor in edit mode. */
  int _inAnCallToUpdateDlgEditor;
  /** the focus mode, see @ref FocusMode documentation for details */
  FocusMode _focusMode;
#ifndef VID_DEPRECATED
  public:
  void SetColor(const CATVidColor& i_color);
  void SetDefaultTextColor(const CATVidColor& i_color);
  void SetColor(unsigned char i_r, unsigned char i_g, unsigned char i_b, unsigned char i_a);
  CATNotification *GetEditFocusOutNotification() const;
#endif
};
//-----------------------------------------------------------------------

#endif
