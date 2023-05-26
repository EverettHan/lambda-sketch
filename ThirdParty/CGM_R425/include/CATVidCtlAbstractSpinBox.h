#ifndef CATVidCtlAbstractSpinBox_H
#define CATVidCtlAbstractSpinBox_H

// COPYRIGHT Dassault Systemes 2006

#include <VisuDialog.h>
#include "CATVidMouseWheelEventArgs.h"
#include <CATVidCtl.h>
#include <CATVid.h>
#include <CATUnicodeString.h>
#include <CATVidColor.h>
#include <CATVidMargin.h>
#include <CATDataType.h>
#include <CATBaseUnknown_WR.h>
#include <CATVidValidator.h>

class CATVidValidator;
class CATVidCtlLineEditor;
class l_CATVidCtlAbstractSpinBox;
class CATSYPEventArgs;
class CATVidCtlButton;
class CATVidMouseAndKeyboardEventArgs;
class CATVidTstSpinBox;

/**
 * Base class for spin box.
 * <b>Role</b>:
 * This widget is used to edit numerical values.
 *
 * @par Styling your CATVidCtlAbstractSpinBox
 * Here are the mandatory "syp:named" objects that must be found in the 
 * template of your ".sypstyle" file : 
 *
 * @li 'U1' [CATVidCtlButton]
 * @li 'D1' [CATVidCtlButton]
 */
class ExportedByVisuDialog CATVidCtlAbstractSpinBox : public CATVidCtl
{
  CATDeclareClass;
public:
  enum CATVidSpinBoxEvents { Spinner_ValueChanged =0, Spinner_EditingFinished};
  enum Range { Left = 0, Within, Right };
  enum SpinBoxButtonStyle { UpDownArrows=0,PlusMinus};
  enum CorrectionMode { CorrectToPreviousValue=0, CorrectToNearestValue};
  enum StepEnabled { StepBothDir=0,StepUpEnabled,StepDownEnabled};
  /**
  * Returns the current button style mode.
  * The possible values can be either UpDownArrows or PlusMinus. The default is UpDownArrows.
  */
  CATVidCtlAbstractSpinBox::SpinBoxButtonStyle GetSpinBoxButtonStyle() const;
  /**
  * Sets the current button style mode.
  * The possible values can be either UpDownArrows or PlusMinus. The default is UpDownArrows.
  * @param i_buttonStyle
  *  Allowed values are:
  *   CATVidCtlAbstractSpinBox::UpDownArrows
  *   CATVidCtlAbstractSpinBox::PlusMinus
  */
  void SetSpinBoxButtonStyle(CATVidCtlAbstractSpinBox::SpinBoxButtonStyle i_buttonStyle);
  /**
   * Returns the alignment of the text set using CATVid::Alignment enum values
   */
  CATVid::Alignment GetAlignment()const;

  /**
   * Sets a alignment of the text using CATVid::Alignment enum values
   * @param i_alignment
   *  Allowed values are:
   *  CATVid::AlignLeft
   *  CATVid::AlignCenter
   *  CATVid::AlignRight
   */
  void SetAlignment(CATVid::Alignment i_alignment);

  /**
  * Returns the mode set to correct an Intermediate value if editing finishes.
  * The default mode is CATVidCtlAbstractSpinBox::CorrectToPreviousValue.
  */
  CATVidCtlAbstractSpinBox::CorrectionMode GetCorrectionMode() const;
  /**
  * Sets the mode to correct an Intermediate value if editing finishes.
  * The default mode is CATVidCtlAbstractSpinBox::CorrectToPreviousValue.
  * @param i_alignment
  *   CATVidCtlAbstractSpinBox::CorrectToPreviousValue
  *   CATVidCtlAbstractSpinBox::CorrectToNearestValue
  */
  void SetCorrectionMode(CATVidCtlAbstractSpinBox::CorrectionMode i_correctionMode);
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
  * Returns the special-value text.
  */

  /* 
  * Sets Visibility of Up Down Button when spin box is read only
  * This flag has no effect if spin box is editable 
  */
  void SetButtonsVisibleFlag(CATBoolean i_readOnlyFlag);

  CATBoolean GetButtonsVisibleFlag() const;

  const CATUnicodeString& GetSpecialValueText() const;
  /**
  * Sets the special-value text.
  * If set, the spin box will display this text instead of a numeric value whenever the current value 
  * is equal to minimum(). Typical use is to indicate that this choice has a special (default) meaning.
  * @param i_specialValueText
  *   The text to set
  */
  void SetSpecialValueText(const CATUnicodeString& i_specialValueText);

  CATUnicodeString GetText() const;

  /**
  * Returns the wrapping flag value set by the user that makes the spin box is circular/ normal.
  */
  CATBoolean GetWrappingFlag() const;
  /**
  * Sets flag to make the spin box is circular/ normal.
  * If wrapping is true stepping up from maximum() value will take you to the minimum() value and 
  * vica versa. Wrapping only make sense if you have minimum() and maximum() values set.
  * @param i_wrappingFlag
  *   The flag to set
  */
  void SetWrappingFlag(CATBoolean i_wrappingFlag);
 /*
  * Virtual function that is called whenever the user triggers a step. 
  * The steps parameter indicates how many steps were taken, 
  * If you subclass CATVidCtlAbstractSpinBox you must reimplement this function. 
  * Note that this function is called even if the resulting value will be outside the bounds of minimum and maximum. 
  * It's this function's job to handle these situations.
  * @param i_nbSteps
  *   The number of steps to change the value
  */
  virtual CATINT32 StepBy(CATINT32 i_nbSteps) = 0;

  /**
  * Steps down by single step value.
  * Calling this slot is analogous to calling StepBy(-1);
  */
  CATINT32 StepDown();
  /**
  * Steps up by single step value.
  * Calling this slot is analogous to calling StepBy(1);
  */
  CATINT32 StepUp();
  /**
  * Returns the widget's text margins for left, top, right, and bottom.
  */
  CATVidMargin GetTextMargins() const;
  /**
  * Sets the widget's text margins for left, top, right, and bottom.
  */
  void SetTextMargins(const CATVidMargin & i_margins);
  /**
  * This property holds the maximum permitted length of the text.
  */
  CATINT32 GetMaxLength() const;
  /**
  * This property holds the maximum permitted length of the text.
  */
  void SetMaxLength (CATINT32 i_length);
  /**
  * Sets the color used as background color
  * @param i_backgroundColor
  *   The background color to set.
  */
  void SetBackgroundColor(const CATVidColor &i_backgroundColor);
  /**
  * Returns the color used as background color
  */
  const CATVidColor& GetBackgroundColor() const;
  /**
  * Sets the color used as foreground color (for example, used to draw the text most of the time)
  * @param i_foregroundColor
  *   The foreground color to set.
  */
  void SetForegroundColor(const CATVidColor &i_foregroundColor);
  /**
   * Returns the color used as foreground color (for example, used to draw the text most of the time)
   */
  const CATVidColor& GetForegroundColor() const;
   /**
   * Sets the height of the text to be displayed
   */
   void SetFontHeight(CATINT32 i_height);
   /**
   * Gets the height of the text to be displayed
   */
   CATINT32 GetFontHeight() const;
   /**
   * Sets the font to be used while displaying text in editor.
   * Font FAMILY name to be provided.
   * Display is subject to availability of font
   * @param iFontName
   *   The fontname to set.
   */
   void SetFontName(const CATUnicodeString& iFontName);
   /**
   * Gets the font being used to display the text in editor
   */
   const CATUnicodeString& GetFontName() const;
   /**
   * Displays the text in bold form (subject to avialability of appropriate font)
   * @param i_MakeBold
   *   The flag to make the text bold or normal.
   */
   void SetBoldFlag(CATBoolean i_MakeBold);
   /**
   * Returns whether the text is displayed in bold form (TRUE if SetBold call is made with argument TRUE, FALSE otherwise)
   */
   CATBoolean GetBoldFlag() const;
   /**
   * Displays the text in italic form (subject to avialability of appropriate font)
   * @param i_MakeItalic
   *   The flag to make the text italic or normal.
   */
   void SetItalicFlag(CATBoolean i_MakeItalic);
   /**
   * Returns whether the text is displayed in italic form (TRUE if SetBold call is made with argument TRUE, FALSE otherwise)
   */
   CATBoolean GetItalicFlag() const;
   /**
   * Displays the text with underline
   * @param i_MakeUnderline
   *   The flag to make the text underline or normal.
   */
   void SetUnderlineFlag(CATBoolean i_MakeUnderline);
   /**
   * Returns whether the text is displayed with underline
   */
   CATBoolean GetUnderlineFlag() const;
  /**@deprecated */
  void SetTesselateFontFlag(const CATBoolean& i_tesselateFontFlag){}
  /**@deprecated */
  CATBoolean GetTesselateFontFlag() const{return 0;}
   /**
    * Sets the color used as cursor color
    * @param i_cursorColor
    *  The cursor color to set.
    */
  void SetCursorColor(const CATVidColor &i_cursorColor);
  /**
   * Returns the color used as cursor color
   */
  const CATVidColor& GetCursorColor() const;
  /**
   * Sets the color used as selection color
   * @param i_selectionColor
   *  The selection color to set.
   */
  void SetSelectionColor(const CATVidColor &i_selectionColor);
  /**
   * Returns the color used as cursor color
   */
  const CATVidColor& GetSelectionColor() const;  
  /**
   * Sets the editor text.
   */
  void SetEditorText(const CATUnicodeString& i_editorText);
  /**
   * Returns the editor text.
   */
  const CATUnicodeString& GetEditorText() const;
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
  * Clears the contents of the line edit.
  */
  virtual CATINT32 Clear();
  /**
  * Selects all the text (i.e. highlights it) and moves the cursor to the end. 
  * This is useful when a default value has been inserted because if the user types before clicking on the widget, the selected text will be deleted.
  */
  CATINT32 SelectAll();
  /**
  * Deselects any selected text.
  */
  CATINT32 Deselect();
  /**
  * Copies the selected text to the clipboard and deletes it, if there is any, and if echoMode() is Normal,
  * if line edit is read only, cut() will copy without deleting.
  * If input mask is set, cut() will copy without deleting.
  * If the validation disallows deleting the selected text, cut() will copy without deleting.
  */
  CATINT32 Cut();
  /**
  * Copies the selected text to the clipboard, if there is any, and if echoMode() is Normal.
  */
  CATINT32 Copy();
  /**
  * Inserts the clipboard's text at the cursor position, deleting any selected text, providing the line edit is not read-only.
  * If input mask is set, Paste operation will fail
  * If validator is set , Paste operation will fail if resulting text is invalid
  */
  CATINT32 Paste();
  
 /**
  * Checks the validity of the current value in the spin box, if the text is invalid or in intermediate state
  * it is corrected as per the correction mode. Also raised the ValueChanged event if the value of the spin box 
  * has been changed.
  */
  CATINT32 InterpretText();
  /**
  * Returns the value change event notification.
  * @deprecated Use new VID propagating events (see: http://codewiki/codewiki/index.php/VID_:_Events_Migration)
  */
  CATNotification * GetValueChangedNotification()const;
  /**
  * Returns the editing finished event notification.
  * @deprecated Use new VID propagating events (see: http://codewiki/codewiki/index.php/VID_:_Events_Migration)
  */
  CATNotification * GetEditingFinishedNotification()const;
  /**
   * Returns the @c ValueChanged event.
   * The @c ValueChanged event is emitted whenever the spin box value has changed.
   * @par EventProperties
   *   - Name: @c "ValueChanged"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* ValueChanged();
  /**
   * Returns the @c EditingFinished event.
   * The @c EditingFinished event is emitted whenever editing of line editor present inside the spin box is 
   * finished (either Return key is pressed or the spin box loses focus).
   * @par EventProperties
   *   - Name: @c "EditingFinished"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* EditingFinished();
  /**
   * Returns the @c UpOrDownButtonPressed event.
   * The @c UpOrDownButtonPressed event is emitted whenever the 'Up' or 'Down' button of the spin box is pressed.
   * @par EventProperties
   *   - Name: @c "UpOrDownButtonPressed"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* UpOrDownButtonPressed();

  /**
   * Returns the @c UpOrDownButtonReleased event.
   * The @c UpOrDownButtonReleased event is emitted whenever the 'Up' or 'Down' button of the spin box is released.
   * @par EventProperties
   *   - Name: @c "UpOrDownButtonReleased"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* UpOrDownButtonReleased();

	/** 
	* Get the @c EscapePressed event.
	* The @c EscapePressed event is emitted whenever the Escape key is pressed (spin box should be in focus)
	* The event is emmited even if the spin box is empty.
	* @par EventProperties
	*   - Name: @c "EditingEscaped"
	*   - Type of propagation: @c NoPropagation
	*   - Type of argument: @ref CATSYPEventArgs
	*
	* @return the event instance. @c AddRef has NOT been called on the returned pointer.
	*/
	static CATSYPEvent* EditingEscaped();
  /**
  * Event handler for 'Up' or 'Down' Button events
   */
  void HandleAbstractSpinBoxEventUpOrDown(CATBaseUnknown* pSender, CATSYPEventArgs* pEventArgs);
	/**
 	 * Emit EditingEscaped event 
	 */
	void HandleEditingEscaped(CATBaseUnknown* pSender, CATSYPEventArgs* pEventArgs);
  /**
   * Event handler for 'ContextMenuHidden' event
   */
  void HandleOnContextMenuHidden(CATBaseUnknown* pSender, CATSYPEventArgs* pEvntArgs);
  /**
   * Event handler for 'ContextMenuRequired' event 
   */
  void HandleOnContextMenuRequired(CATBaseUnknown* pSender, CATVidMouseAndKeyboardEventArgs* pEvntArg);
  
  /**
   * Temparorily made available on spin box
   */
  void SetFocus();
  void ResetFocus();
  /**
   * Returns TRUE if the line editor has the focus, FALSE otherwise.
   * @see SetFocus
   * @see GetLineEditor
   */
  CATBoolean GetEditorFocusedFlag() const;
 /**
  * Get the Line validator
  */
  CATVidValidator* GetValidator();
  /**
  * Set the Line validator
  */
  void SetValidator(CATVidValidator* i_pValidator);

  /**
  * If the value entered in spinner is in intermidiate mode, This function sets the valid value in spinner.
  * Value is set according to the correction mode set on the control.
  */
  virtual CATINT32 SetCorrectedValue();



  /**
  * Returns the spin box's prefix.
  */
  CATUnicodeString GetPrefix();

  /**
  * Sets the spin box's prefix.
  * The prefix is prepended to the start of the displayed value.
  * Typical use is to display a unit of measurement or a currency symbol. For example: "$"
  * To turn off the prefix display, set this property to an empty string The default is no prefix.
  * The prefix is not displayed for the minimum value if Special Value Text is not empty.
  * @param i_strPrefix
  *  The prefix to set.
  */
  void SetPrefix(CATUnicodeString i_strPrefix);

  /**
  * Returns the spin box's suffix.
  */
  CATUnicodeString GetSuffix();

  /**
  * Sets the suffix of the spin box.
  * The suffix is appended to the end of the displayed value.
  * Typical use is to display a unit of measurement or a currency symbol. For example: "mm"
  * To turn off the suffix display, set this property to an empty string.
  * The default is no suffix. The suffix is not displayed for the minValue() if specialValueText() is not empty.
  * @param i_strPrefix
  *  The suffix to set.
  */
  void SetSuffix(CATUnicodeString i_strSuffix);

  /**
  * Returns TRUE if the trailing zeros must be displayed, FALSE otherwise.
  */
  CATBoolean GetShowTrailingZerosFlag() const;

  /**
  * Specifies whether the trailing zeros must be displayed or not.
  */
  void SetShowTrailingZerosFlag(CATBoolean i_flag);

  /**
  * Set Line Editor
  */
  void SetLineEditor(CATVidCtlLineEditor *	i_pLineEditor);

  /**
  * Returns the line editor
  */
  CATVidCtlLineEditor* GetLineEditor() const;

  CATUnicodeString GetCleanText();

  CATVidDoubleValidator* _GetDoubleValidator();

protected:
  /**
   * Constructs a CATVidCtlAbstractSpinBox.
   * No associsated style, use static factory CreateEditor
   */
  CATVidCtlAbstractSpinBox();
  /** Destructor*/
  virtual ~CATVidCtlAbstractSpinBox();
  /**
   * @copydoc CATVidCtl#TemplateDataUpdated
   * Here are the mandatory "syp:named" objects : 
   * @li 'U1' [CATVidCtlButton]
   * @li 'D1' [CATVidCtlButton]
   */
  virtual void TemplateDataUpdated();
  /**
   * Returns the 'U1' up button.
   */
  CATVidCtlButton * _GetUpButton() const;
  /**
   * Returns the 'D1' down button.
   */
  CATVidCtlButton * _GetDownButton() const;

  void RaiseEvent(CATVidSpinBoxEvents i_eventType);

  /**
   * Event handler for the events corresponding to the start of the edition.
   */
  void HandleTextActivatedEvent(CATBaseUnknown* pSender, CATSYPEventArgs* pEventArgs);
  /**
   * Event handler for the events corresponding to the end of the edition.
   */
  void HandleEditingFinishedEvent(CATBaseUnknown* pSender, CATSYPEventArgs* pEventArgs);
  /**
  * Event handler for the 'TextEdited' event sent by the line editor.
  */
  void HandleTextEditedEvent(CATBaseUnknown* pSender, CATSYPEventArgs* pEventArgs);
  /**
   * Event handler for the 'Press' event sent by the spin box 'Up' and 'Down' buttons.
   */
  void HandleUpOrDownButtonPressEvent(CATBaseUnknown* pSender, CATSYPEventArgs* pEventArgs);
  /**
   * Event handler for the 'ReleaseEvt' event sent by the spin box 'Up' and 'Down' buttons.
   */
  void HandleUpOrDownButtonReleaseEvent(CATBaseUnknown* pSender, CATSYPEventArgs* pEventArgs);
  /**
   * Event handler for 'MouseWheel' event sent by the CATVidGP::Wheel() event 
   */
  void HandleMouseWheel(CATBaseUnknown *i_pSender, CATVidMouseWheelEventArgs *i_pArgs); 

	/*
	* To not raise unwanted Spinner_ValueChanged event with doublespinbox in following case :
	* - up/down button multiple press context.
	*	- EditingFinished context.
	*/
	CATBoolean _NeedToRaiseValueChangedEvent();
  
private:
  CATVidCtlAbstractSpinBox (CATVidCtlAbstractSpinBox &);
  CATVidCtlAbstractSpinBox& operator=(CATVidCtlAbstractSpinBox& original);
  virtual CATUnicodeString GetTextFromValue(double i_value);
  virtual CATBoolean IsNewVersionForODT();
  virtual void UpdateCursorPosition();
  void SendUpOrDownButtonReleasedIfNeeded();
  
  CATVidValidator *_pValidator;
  CATUnicodeString _editorText;
  CATBoolean _undefinedFlag;
  CATUnicodeString _strLastInterpretedText;

  CATVidCtlLineEditor *	_pLineEditor;
	CATBoolean _raiseValueChangedEvent;
  CATBoolean _bDirtyFlag;
  CATBoolean _buttonPressed;
public:
  CATINT32 SetCleanText(const CATUnicodeString &);

public:
  /** @deprecated */
  CATVidCtlAbstractSpinBox::StepEnabled GetStepEnabledFlag() const;
  /** @deprecated */
  void SetStepEnabledFlag(CATVidCtlAbstractSpinBox::StepEnabled i_stepEnabledFlag);
  //DNBIgpArcSeamSearchParametersPage
  CATBoolean CheckIfAcceptableInput() { return 1; }

  friend class l_CATVidCtlAbstractSpinBox;
  friend class CATVidTstSpinBox;
  
};

CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVidCtlAbstractSpinBox__SpinBoxButtonStyle);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVidCtlAbstractSpinBox__CorrectionMode);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVidCtlAbstractSpinBox__StepEnabled);

#endif

