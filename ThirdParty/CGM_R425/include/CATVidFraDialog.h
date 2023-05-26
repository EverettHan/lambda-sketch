#ifndef CATVidFraDialog_h
#define CATVidFraDialog_h

// COPYRIGHT Dassault Systemes 2009

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidFraWindow.h>

// IntrospectionInfrastructure framework
#include <CATSYPEnumBitField.h>
#include <CATSYPDeclareEnumFactory.h>

// UIVCoreTools framework
#include <CATSYPHashMap.h>

// System framework
#include <CATUnicodeString.h>
#include <CATBoolean.h>
#include <CATBaseUnknown_WR.h>

class CATString;
class CATVidLayStack;
class CATVidLayCollection;
class CATVidCtlButton;
class CATVidWidget;
class CATSysWeakRef;
class CATSYPEvent;

/**
 * @ingroup VIDFrame
 * Class representing a Dialog Box with standard buttons (e.g. OK, Cancel buttons).
 * Use a CATVidFraDialog when you want to provide a short term command window that will be closed
 * when the user has ended with this command.
 *
 * @see CATVidFraWindow for a detailed description of the inherited capabilities.
 * Note that by default, a CATVidFraDialog is not resizable and has its CompactFlag property set to TRUE.
 *
 * The default life cycle of a CATVidFraDialog is CATVidUserSideDocumentLC, i.e its life cycle is bound to its 
 * associated viewer life cycle.
 *
 * The following code is an example of a CATVidFraDialog use : 
 * @code
 *   CATVidFraDialog * pDialog = new CATVidFraDialog(this, "DialogName");
 *   pDialog->SetApplicativeWidget(myWidget);
 *   pDialog->SetTitle("My title");
 *   pDialog->SetStandardButtons(CATVidFraDialog::StandardButtons(CATVidFraDialog::Ok | CATVidFraDialog::Cancel));
 *   pDialog->SetDefaultButton(CATVidFraDialog::Ok);
 *   pDialog->SetEscapeButton(CATVidFraDialog::Cancel);
 *   pDialog->SetAutoCloseFlag(TRUE);
 *   pDialog->SetCompactFlag(FALSE);
 *   pDialog->SetResizableFlag(TRUE);
 *   pDialog->SetVisibleFlag(TRUE);
 * @endcode
 *
 * @par Listening to the standard buttons click event
 * Each standard button of a CATVidFraDialog has a corresponding role (see the enum CATVidFraDialog::ButtonRole) 
 * and a dialog can contain only one button per role.
 * If you want to register a callback method that will be called when a standard button is clicked, you can
 * add a handler for the event associated to the button role.
 *
 * For example, the button CATVidFraDialog::Ok has the role CATVidFraDialog::AcceptRole, so 
 * the associated event to listen to is CATVidFraDialog::AcceptButtonClicked().
 * The following code registers the callback method MyClass::OkButtonClicked for the click event of 
 * the CATVidFraDialog::Ok button :
 * @code
 * AddCATSYPWRefMethEventHandler(pDialog, CATVidFraDialog::AcceptButtonClicked(), this, &MyClass::OkButtonClicked);
 *
 * void MyClass::OkButtonClicked(CATBaseUnknown *i_pSender, CATVidFraDialogButtonClickedEventArgs *i_pArgs) 
 * {
 *   CHECK_POINTER_RET(i_pArgs);
 *
 *   CATVidFraDialog * const pDialog = CAT_DYNAMIC_CAST(CATVidFraDialog, i_pArgs->GetOrigin());
 *   CHECK_POINTER_RET(pDialog);
 *
 *   // Retrieve the clicked button
 *   CATVidFraDialog::StandardButton buttonClicked = i_pArgs->GetStandardButton();
 *   ...
 * }
 * @endcode
 *
 * @par CATVidFraDialog life cycle
 * By default, the life cycle of a CATVidFraDialog is equal to CATVidUserSideDocumentLC,
 * i.e its life cycle is bound to its associated viewer life cycle. Such CATVidFraDialog cannot be created 
 * if no active viewer exists.
 * If you want to create a CATVidFraDialog with no associated viewer, you have to specify its life cycle as 
 * an application one by calling the following method (before calling SetVisibleFlag(TRUE)) :
 * @code
 * pDialog->SetLifeCycle(CATVidUserSideLC);
 * @endcode
 *
 * @see CATVidLifeCycle for the possible life cycles for a window
 */
class ExportedByVisuDialog CATVidFraDialog : public CATVidFraWindow
{
  CATDeclareClass;

public:

  /**
   * Constructors
   */
  CATVidFraDialog();
  CATVidFraDialog(CATCommand *i_pParent, const CATString & i_pIdentifier);

  /**
   * Possible roles to assign to standard buttons.
   */
  enum ButtonRole 
  { 
    /** The button is invalid */
    InvalidRole = 0,
    /** Clicking the button causes the dialog to be accepted (e.g. OK) */
    AcceptRole,
    /** Clicking the button causes the dialog to be rejected (e.g. Cancel) */
    RejectRole,
    /** Clicking the button causes a destructive change (e.g. for Discarding Changes) */
    DestructiveRole,
    /** The button can be clicked to request help */
    HelpRole,
    /** The button is a "Yes"-like button */
    YesRole, 
    /** The button is a "No"-like button */
    NoRole,
    /** The button applies current changes */
    ApplyRole, 
    /** The button resets the dialog's fields to default values */
    ResetRole 
  };

  /**
   * Possible standard buttons for a CATVidFraDialog.
   * Each button has a defined ButtonRole.
   */
  enum StandardButton 
  { 
    /** An invalid button */
    NoButton          = 1,
    /** An "OK" button defined with the AcceptRole */
    Ok                = 1<<1,
    /** A "Open" button defined with the AcceptRole */
    Open              = 1<<2,
    /** A "Save" button defined with the AcceptRole */
    Save              = 1<<3,
    /** A "Cancel" button defined with the RejectRole */
    Cancel            = 1<<4,
    /** A "Close" button defined with the RejectRole */
    Close             = 1<<5,
    /** A "Discard" button defined with the DestructiveRole */
    Discard           = 1<<6,
    /** An "Apply" button defined with the ApplyRole */
    Apply             = 1<<7,
    /** A "Reset" button defined with the ResetRole */
    Reset             = 1<<8,
    /** A "Restore Defaults" button defined with the ResetRole */
    RestoreDefaults   = 1<<9,
    /** A "Help" button defined with the HelpRole */
    Help              = 1<<10,
    /** A "Save All" button defined with the AcceptRole */
    SaveAll           = 1<<11,
    /** A "Yes" button defined with the YesRole */
    Yes               = 1<<12,
    /** A "Yes to All" button defined with the YesRole */
    YesToAll          = 1<<13,
    /** A "No" button defined with the NoRole */
    No                = 1<<14,
    /** A "No to All" button defined with the NoRole */
    NoToAll           = 1<<15,
    /** An "Abort" button defined with the RejectRole */
    Abort             = 1<<16,
    /** A "Retry" button defined with the AcceptRole */
    Retry             = 1<<17,
    /** An "Ignore" button defined with the AcceptRole */
    Ignore            = 1<<18
  };
  CATSYP_DECLARE_ENUM_BIT_FIELD(StandardButtons, StandardButton);

  /**
   * Sets the standard buttons of the dialog.
   * @parma i_standardButtons
   * Mask representing the standard buttons of the dialog 
   * e.g.: pDialog->SetStandardButtons(CATVidFraDialog::StandardButtons(CATVidFraDialog::Ok | CATVidFraDialog::Cancel));
   * By default, there is no standard button defined.
   */
  void SetStandardButtons(CATVidFraDialog::StandardButtons i_standardButtons);
  CATVidFraDialog::StandardButtons GetStandardButtons() const;

  /**
   * Sets the button to call when ENTER key is pressed and released while one of 
   * child widget of this window has the focus.
   */
  void SetDefaultButton(CATVidFraDialog::StandardButton i_button);
  CATVidFraDialog::StandardButton GetDefaultButton() const;

  /**
   * Sets the button to call when ESCAPE key is pressed and released while one of 
   * child widget of this window has the focus.
   */
  void SetEscapeButton(CATVidFraDialog::StandardButton i_button);
  CATVidFraDialog::StandardButton GetEscapeButton() const;

  /**
   * Sets the label of the given default button.
   * By default, the label of the standard buttons is retrieved in the CATVidFraDialog.CATNls file
   */
  void SetButtonLabel(CATVidFraDialog::StandardButton i_button, const CATUnicodeString& i_label);
  CATUnicodeString GetButtonLabel(CATVidFraDialog::StandardButton i_button) const;

  /**
   * Sets the EnableFlag property of the given default button.
   * By default, each standard button is enabled.
   */
  void SetButtonEnableFlag(CATVidFraDialog::StandardButton i_button, CATBoolean i_enableFlag);
  CATBoolean GetButtonEnableFlag(CATVidFraDialog::StandardButton i_button) const;

  /**
   * Specifies whether the dialog is modal or not.
   * A modal dialog prevents user interaction outside its window until it is closed.
   * By default, the ModalFlag property is set to FALSE.
   */
  void SetModalFlag(CATBoolean i_modalFlag);

  /**
   * Returns TRUE if the dialog is modal, FALSE otherwise.
   * A modal dialog prevents user interaction outside its window until it is closed.
   * By default, the ModalFlag property is set to FALSE.
   */
  CATBoolean GetModalFlag() const;

  /**
   * Sets the panel horizontal alignment.
   * The horizontal alignment is used to compute the new window position when its containing viewer or
   * when its applicative widget is resized:
   *   * if the panel is left aligned, then on resize its left corners x coordinates will not change
   *   * if the panel is right aligned, then on resize its right corners x coordinates will not change
   *
   * This method does not modify the current window position.
   * Note that this alignment may change interactively if the end user snaps this window on the border 
   * of its containing viewer or on the edge of another snappable window.
   */
  void SetHorizontalAlignment(CATVid::Alignment i_hAlignment);

  /**
   * Sets the window vertical alignment.
   * The vertical alignment is used to compute the new window position when its containing viewer or
   * when its applicative widget is resized:
   *   * if the window is top aligned, then on resize its top corners y coordinates will not change
   *   * if the window is bottom aligned, then on resize its bottom corners y coordinates will not change
   *
   * This method does not modify the current window position.
   */
  void SetVerticalAlignment(CATVid::VAlignment i_vAlignment);

  /**
   * Displays a furtive message with the given icon and informative text.
   * The message appears at the bottom of the window.
   * @param i_informationIcon the icon associated to the message.
   * @param i_informationText the informative text to display.
   * @param i_duration duration in second of the message display. If this duration is equal or less than 0, 
   * the duration is infinite.
   * @param i_closableFlag specifies whether the message can be interactively closed or not.
   */
  void ShowMessage(
          CATVidFraWindow::ActionIcon i_informationIcon, 
          const CATUnicodeString& i_informationText, 
          float i_duration = 0.f, 
          CATBoolean i_closableFlag = FALSE);

  /**
   * Hides the furtive message if any.
   */
  void HideMessage();

  /**
   * Sets visibility of a check box in the footer. State of the checkBox may be connected by introspection.
   */
  void SetCheckBoxVisibleFlag(CATBoolean i_checkBoxVisibleFlag);
  CATBoolean GetCheckBoxVisibleFlag() const;
  /**
   * Sets the the checked state of the check box
   */
  void SetCheckBoxState(CATBoolean i_checkBoxState);
  CATBoolean GetCheckBoxState() const;
  /**
   * Sets the checkBox text
   */
  void SetCheckBoxText(CATUnicodeString i_checkBoxText);
  CATUnicodeString GetCheckBoxText() const;

  /**
   * Get the @c CheckBoxClicked event.
   *
   * The @c CheckBoxClicked event is emitted when a standard button
   * with an AcceptRole is clicked.
   *
   * @par EventProperties
   *   - Name: @c "CheckBoxClicked"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer. 
   */
  static CATSYPEvent * CheckBoxClicked();

  /**
  * Returns the @c InformationVisibleStateChanged event.
  * The @c InformationVisibleStateChanged event is emitted whenever the Information visibility has changed.
  * @see SetShowInformationFlag
  * @par EventProperties
  *   - Name: @c "InformationVisibleStateChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on the returned pointer.
  */
  static CATSYPEvent * InformationVisibleStateChanged();

  /**
   * Returns the role of the given standard button.
   */
  static CATVidFraDialog::ButtonRole GetButtonRole(CATVidFraDialog::StandardButton i_button);
  
  /**
   * Get the @c AcceptButtonClicked event.
   *
   * The @c AcceptButtonClicked event is emitted when a standard button
   * with an AcceptRole is clicked.
   *
   * @par EventProperties
   *   - Name: @c "AcceptButtonClicked"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidFraDialogButtonClickedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer. 
   */
  static CATSYPEvent * AcceptButtonClicked();

  /**
   * Get the @c RejectButtonClicked event.
   *
   * The @c RejectButtonClicked event is emitted when a standard button
   * with a RejectRole is clicked.
   *
   * @par EventProperties
   *   - Name: @c "RejectButtonClicked"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidFraDialogButtonClickedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer. 
   */
  static CATSYPEvent * RejectButtonClicked();

  /**
   * Get the @c DestructiveButtonClicked event.
   *
   * The @c DestructiveButtonClicked event is emitted when a standard button
   * with a DestructiveRole is clicked.
   *
   * @par EventProperties
   *   - Name: @c "DestructiveButtonClicked"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidFraDialogButtonClickedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer. 
   */
  static CATSYPEvent * DestructiveButtonClicked();

  /**
   * Get the @c HelpButtonClicked event.
   *
   * The @c HelpButtonClicked event is emitted when a standard button
   * with a HelpRole is clicked.
   *
   * @par EventProperties
   *   - Name: @c "HelpButtonClicked"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidFraDialogButtonClickedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer. 
   */
  static CATSYPEvent * HelpButtonClicked();

  /**
   * Get the @c YesButtonClicked event.
   *
   * The @c YesButtonClicked event is emitted when a standard button
   * with a YesRole is clicked.
   *
   * @par EventProperties
   *   - Name: @c "YesButtonClicked"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidFraDialogButtonClickedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer. 
   */
  static CATSYPEvent * YesButtonClicked();

  /**
   * Get the @c NoButtonClicked event.
   *
   * The @c NoButtonClicked event is emitted when a standard button
   * with a NoRole is clicked.
   *
   * @par EventProperties
   *   - Name: @c "NoButtonClicked"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidFraDialogButtonClickedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer. 
   */
  static CATSYPEvent * NoButtonClicked();

  /**
   * Get the @c ApplyButtonClicked event.
   *
   * The @c ApplyButtonClicked event is emitted when a standard button
   * with an ApplyRole is clicked.
   *
   * @par EventProperties
   *   - Name: @c "ApplyButtonClicked"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidFraDialogButtonClickedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer. 
   */
  static CATSYPEvent * ApplyButtonClicked();

  /**
   * Get the @c ResetButtonClicked event.
   *
   * The @c ResetButtonClicked event is emitted when a standard button
   * with a ResetRole is clicked.
   *
   * @par EventProperties
   *   - Name: @c "ResetButtonClicked"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidFraDialogButtonClickedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer. 
   */
  static CATSYPEvent * ResetButtonClicked();

  /**
   * Get the @c StandardButtonClick event.
   *
   * The @c StandardButtonClick event is emitted when any standard button is clicked.
   *
   * @par EventProperties
   *   - Name: @c "StandardButtonClick"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidFraDialogButtonClickedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer. 
   */
  static CATSYPEvent * StandardButtonClick();

  /**
   * Returns the event corresponding to the click on a standard button with the given role.
   */
  static CATSYPEvent * GetButtonClickedEventFromRole(CATVidFraDialog::ButtonRole i_role);

  // Implementation of the CATISYPPresenter interface
  void SetChild(CATBaseUnknown_var i_spToConnect);
  virtual CATBaseUnknown_var GetChild();

  CATVidLayCollection* GetButtonCollection();

  CATVidLayStack * GetButtonFrame();

  /**
   * Sets the embedded Preferences widget.
   */
  void SetPreferencesWidget(CATVidWidget * i_pPreferencesWidget);

  /**
   * Returns the embedded Preferences widget.
   */
  CATVidWidget * GetPreferencesWidget() const;

  /**
   * Hides or shows Preferences widget of the window.
   * The PreferencesWidget must have been set otherwise this method will fail.
   * By default, the ShowPreferencesFlag property is set to FALSE.
   */
  void SetShowPreferencesFlag(CATBoolean i_showPreferencesFlag);

  /**
   * Returns TRUE if the Preferences widget of the window is visible, FALSE otherwise.
   */
  CATBoolean GetShowPreferencesFlag() const;

  /**
   * Hides or shows the 'ShowPreferences' button.
   * @param i_showPreferencesButtonFlag
   * the boolean controlling the visibility of the 'ShowPreferences' button
   * By default, the ShowPreferencesButtonFlag property is set to TRUE.
   */
  void SetShowPreferencesButtonFlag(CATBoolean i_showPreferencesButtonFlag);

  /**
   * Returns TRUE if the 'ShowPreferences' button is visible, FALSE otherwise.
   */
  CATBoolean GetShowPreferencesButtonFlag() const;
  CATBoolean GetShowPreferencesButtonState() const;

  /**
   * Hides or shows the 'Help' button in the title bar.
   * Clicking on the Help button will display the Help window containing the Help widget.
   * @see SetHelpWidget
   * @param i_helpButtonFlag
   * the boolean controlling the visibility of the 'Help' button
   * By default, the HelpButtonFlag property is set to FALSE.
   */
  void SetHelpButtonFlag(CATBoolean i_helpButtonFlag);

  /**
   * Returns TRUE if the 'Help' button is visible in the title bar, FALSE otherwise.
   */
  CATBoolean GetHelpButtonFlag() const;
  CATBoolean GetHelpButtonState() const;

  /**
   * Sets the embedded Help widget that will be displayed in the Help window.
   * @see SetHelpButtonFlag
   */
  void SetHelpWidget(CATVidWidget * i_pHelpWidget);

  /**
  * Returns the embedded Help widget.
  */
  CATVidWidget * GetHelpWidget() const;

  /**
  * Hides or shows the 'Information' button in the title bar.
  * Clicking on the Information button will toggle the ShowInformationFlag property.
  * @param i_informationButtonFlag
  * the boolean controlling the visibility of the 'Information' button
  * By default, the InformationButtonFlag property is set to FALSE.
  */
  void SetInformationButtonFlag(CATBoolean i_informationButtonFlag);

  /**
  * Returns TRUE if the 'Information' button is visible in the title bar, FALSE otherwise.
  */
  CATBoolean GetInformationButtonFlag() const;

  /**
  * Hides or shows the Information widget in the Dialog.
  * It is up to the Dialog responsible to provide such Information widget whose visibility is linked to the ShowInformationFlag property.
  * When the value of the ShowInformationFlag property changes, the InformationVisibleStateChanged event is fired.
  * @param i_showInformationFlag
  * the boolean controlling the visibility of the 'Information' widget
  * By default, the ShowInformationFlag property is set to FALSE.
  */
  void SetShowInformationFlag(CATBoolean i_showInformationFlag);

  /**
  * Returns TRUE if the 'Information' widget is visible in the Dialog, FALSE otherwise.
  */
  CATBoolean GetShowInformationFlag() const;

  /**
   * Returns the expected standard button.
   */
  CATVidCtlButton* GetButton(CATVidFraDialog::StandardButton i_button);

  /**
   * Callback method registered on the check box click event.
   */
  void CheckBoxClickedCB(CATBaseUnknown * i_pSender, CATSYPEventArgs *i_pArgs);

  /**
  * Callback method registered on the help button click event.
  */
  void HelpCB(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

protected:

  virtual ~CATVidFraDialog();

  // Overriden methods
  virtual void WriteWindowPreferences();
  virtual HRESULT ReadWindowPreferences(CATBoolean i_positionAndDimensionOnly = FALSE);


  /**
   * Method called when a standard button is clicked.
   * This method can be overriden.
   */
  virtual void StandardButtonClicked(const CATString& i_name);

  /**
   * Method called when a standard button with an AcceptRole is clicked.
   * This method can be overriden.
   */
  virtual void Accept();

  /**
   * Method called when a standard button with a RejectRole or DestructiveRole is clicked.
   * This method can be overriden.
   */
  virtual void Reject();

private:

  /**
   * Builds the dialog.
   */
  virtual void Build();

  /**
   * Callback method registered on the standard button click event.
   */
  void StandardButtonClickedCB(CATBaseUnknown * i_pSender, CATSYPEventArgs *i_pArgs);

  /**
   * @copydoc CATVidFraWindow#GetENTERButton
   * @note
   * Children class of this class must NOT override this function.
   * Instead they should use @ref #SetDefaultButton.
   */
  virtual CATVidCtlButton *GetENTERButton();

  /**
   * @copydoc CATVidFraWindow#GetESCButton
   * @note
   * Children class of this class must NOT override this function.
   * Instead they should use @ref #SetEscapeButton.
   */
  virtual CATVidCtlButton *GetESCButton();

  static CATVidFraDialog::StandardButton GetStandardButtonFromString(const CATString& i_name);

  /**
   * Updates the standard buttons.
   */
  void UpdateButtonsFromFlag();

  /**
   * A standard button descriptor.
   */
  struct StandardButtonDescriptor 
  {
    StandardButtonDescriptor();
    ~StandardButtonDescriptor();

    /**
     * The standard button label.
     */
    CATUnicodeString label;

    /**
     * The standard button EnableFlag.
     */
    CATBoolean enableFlag;

  private:

    StandardButtonDescriptor(const StandardButtonDescriptor&);
    StandardButtonDescriptor &operator=(const StandardButtonDescriptor&);
  };

  StandardButtonDescriptor * _GetOrCreateDescriptor(CATVidFraDialog::StandardButton i_button);

private:

  CATVidFraDialog::StandardButtons _standardButtons;
  CATVidFraDialog::StandardButton _defaultButton;
  CATVidFraDialog::StandardButton _escapeButton;
  CATSYPHashMap<int, StandardButtonDescriptor *> _buttonDescriptors;

  CATSysWeakRef * _pLayStackWR;

  CATBaseUnknown_WR _preferencesWidgetWR; // The preferences widget (a CATVidWidget instance)
  CATBoolean _showPreferencesFlag;
  CATBoolean _showPreferencesButtonFlag;

  unsigned int _checkBoxVisibleFlag : 1;
  unsigned int _checkBoxState : 1;
  CATUnicodeString _checkBoxText;
  friend class l_CATVidFraDialog;
};

CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVidFraDialog__StandardButton);

#endif // CATVidFraDialog_h
