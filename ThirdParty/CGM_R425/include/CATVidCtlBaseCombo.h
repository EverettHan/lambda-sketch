#ifndef CATVidCtlBaseCombo_h
#define CATVidCtlBaseCombo_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialog framework
#include <CATVidCtl.h>
#include <VisuDialog.h>
#include <CATVidEnum.h>
#include <CATVidColor.h>
#include <CATVid.h>

// IntrospectionInfrastructure framework
#include <CATSYPDeclareEnumFactory.h>

// Mathematics framework
#include <CATMathPoint2Df.h>

// System framework
#include <CATBoolean.h>
#include <CATUnicodeString.h>
#include <CATLISTV_CATBaseUnknown.h>

#include <list.h>

class CATVidLayGrid;
class CATVidFraDialogBox;
class CATVidLaySideAttach;
class CATVidCtlButton;
class CATVidCtlComboItem;
class CATSYPEvent;
class CATVidCtlPopup;
class CATVidLayScrollable;
class CATVidLayGridIterator;
class CATVidSpacer;
class CATVidGPSquare;
class CATVidMouseEventArgs;
class CATNotification;

/**
 * Base class for combo box widgets.
 * <b>Role</b>:
 * A combo box consists in a combination of a drop-down list and a single-line (editable or not) textbox. 
 * This component allows the end user to either type a value directly into the control (in the case of an editable 
 * combo box) or choose from a list of existing options displayed in the drop-down popup.
 * 
 * A view of the selected widget is diplayed on the combo box top line.
 * <br>
 * For standard usage, use the <b>CATVidCtlSimpleCombo</b> class, which provides a simple standard interface.
 * For more complex usage requiring customization, use the <b>CATVidCtlCustomCombo</b>, which provides customizable data templates.
 * @ingroup VIDControls
 */
class ExportedByVisuDialog CATVidCtlBaseCombo : public CATVidCtl
{
  CATDeclareClass;

public:

  /**
   * This enum specifies how the size hint of the CATVidCtlBaseCombo should 
   * adjust when new content is added or content changes.
   * @see SetSizeAdjustPolicy
   */
   enum SizeAdjustPolicy 
   { 
     /** The top line minimum width will be computed from its first line only */
     NoAdjust = 0, 
     /** The top line minimum width will be computed from its entire contents (can be time consuming) */
     AdjustToContents,
     /** The top line and the popup minimum width will be null and the text may be cropped */
     Crop,
     /** The top line minimum width will be null and the text may be cropped */
     CropTopLine,
		 /** The top line may be cropped at beginning*/
		 CropTopLineBeginWithDots,
		 /** The top line may be cropped at middle*/
		 CropTopLineMiddleWithDots,
		 /** The top line may be cropped at end*/
		 CropTopLineWithDoth
   };

  /**
   * Specifies the index of the item to select in the combobox.
   * The current index can change when inserting or removing items.
   * By default, for an empty combo box or a combo box in which no current item is set, this property has a value of -1.
   * The first element of a combo box has an index equal to 0.
   */
  void SetSelectedIndex(int i_index);

  /**
   * Returns the index of the current selected item in the combobox.
   * The current index can change when inserting or removing items.
   * By default, for an empty combo box or a combo box in which no current item is set, this property has a value of -1.
   * The first element of a combo box has an index equal to 0.
   */
  int GetSelectedIndex() const;

  /**
   * Removes the item at the given index from the combobox. This will update the current index if the index is removed.
   * virtual from CATVidCtlBaseCombo   
   */
  virtual void ClearLine(int i_index);

  /**
   * Clears the combobox, removing all items.
   * virtual from CATVidCtlBaseCombo   
   */
  virtual void Clear();

  /**
   * Clears only the items in the popup.
   */
  void ClearList();
  
  /**
   * Specifies whether the combo box displays the top line or not.
   * By default, the UseTopLineFlag property is set to TRUE.
   */
  void SetShowTopLineFlag(CATBoolean i_showTopLineFlag);

  /**
   * Returns TRUE if the combo box displays the top line, FALSE otherwise.
   */
  CATBoolean GetShowTopLineFlag() const;

  /**
   * Specifies whether the combo box displays the drop down button or not.
   * By default, the ShowDropDownButtonFlag property is set to TRUE.
   */
  void SetShowDropDownButtonFlag(CATBoolean i_showFlag);

  /**
   * Returns TRUE if the combo box displays the drop down button, FALSE otherwise.
   */
  CATBoolean GetShowDropDownButtonFlag() const;

  /**
   * Specifies whether the combo box popup must be dropped or undropped.
   * By default, the DropListFlag property is set to FALSE.
   */
  void SetDropListFlag(CATBoolean i_boolean);
  CATBoolean GetDropListFlag() const;

  /**
   * Drops the popup.
   * @see SetDropListFlag
   */
  void DropList();

  /**
   * Undrops the popup.
   * @see SetDropListFlag
   */
  void UnDropList();

  /**
   * Sets the drop side of the Combo. Can be modified internally for visibility reasons, 
   * or if entry value is not correct.
   * By default, the DropSide property is set to CATVid::Bottom.
   * @param i_side the wished drop side of the combo.
   * <br><b>Legal values</b>:
   *     <tt>CATVid::Top</tt>
   *     <tt>CATVid::Bottom</tt>
   */
  void SetDropSide(CATVid::Side i_side);

  /**
   * @returns the actual drop side of the combo.
   * Can be either
   *     <tt>CATVid::Top</tt> or
   *     <tt>CATVid::Bottom</tt>
   */
  CATVid::Side GetDropSide() const;

  /**
   * Returns the number of lines of the combo box.
   */
  int GetLineCount() const;

  /**
   * This property holds the maximum allowed number of visible items.
   * By default, this property has a value of 10.
   */
  void SetMaxVisibleItems(int i_maxVisibleItems);

  /**
   * @return the maximum allowed number of visible items
   */
  int GetMaxVisibleItems() const;

  /**
   * Sets the policy describing how the size of the combobox changes when the content changes.
   * The default value is AdjustToContents. Note that this option could be time consuming, 
   * as the every item has to be build to recover its width! For big models, better use CATVidCtlBaseCombo::Crop
   * or CATVidCtlBaseCombo::CropTopLine option.
   */
  void SetSizeAdjustPolicy(CATVidCtlBaseCombo::SizeAdjustPolicy i_policy);
  CATVidCtlBaseCombo::SizeAdjustPolicy GetSizeAdjustPolicy() const;
 
  /**
   * Specifies whether a "more" button is displayed at the bottom of the combo box popup or not.
   * When the "more" button is pressed, the combo box will send the @c ComboMoreButtonPress event and undrop the popup.
   * By default, the MoreButtonFlag property is set to FALSE.
   */
  void SetMoreButtonFlag(CATBoolean i_moreButtonFlag);
  CATBoolean GetMoreButtonFlag() const;

  /**
   * Returns TRUE if the top line has the focus, FALSE otherwise.
   */
  CATBoolean GetTopLineFocusedFlag() const;

  /**
   * Sets the color used as background color
   * @param i_backgroundColor
   * The background color to set.
   */
  void SetBackgroundColor(const CATVidColor &i_backgroundColor);

  /**
   * @return the color used as background color
   */
  const CATVidColor& GetBackgroundColor() const;

  /**For modelview combos only (CATVidCtlSimpleCombo and CATVidCtlCustomCombo)
  * Flag allowing to control if keyboard navigation only preselect the combo items. (Warning this happens only if drop list is visible.
  * When this flag is set to TRUE, the user must validate keyboard navigation by pressing enter key (or with the mouse), or cancel with pressing escape key.
  * Default value for this flag is TRUE.
  */
  void SetKeyboardOnlyPreselectWithDropListFlag(CATBoolean i_KeyboardOnlyPreselectWithDropListFlag);

  /**
  * Return the KeyboardOnlyPreselectWithDropListFlag value.
  */
  CATBoolean GetKeyboardOnlyPreselectWithDropListFlag() const;  

  /**
   * Gets the @c TopLinePress event.
   * 
   * The @c TopLinePress is emitted when the top line is pressed.
   * If this event is consumed, the combo box popup is not automatically displayed.
   * 
   * @par EventProperties
   *   - Name: @c "TopLinePress"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent* TopLinePress();

  /**
   * Gets the @c ComboPreDropDown event.
   * 
   * The @c ComboPreDropDown is emitted just before the combo box popup is displayed.
   * You can listen to this event to change the model data of the combo just before it is displayed.
   * 
   * @par EventProperties
   *   - Name: @c "ComboPreDropDown"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent* ComboPreDropDown();

  /**
   * Gets the @c ComboSelect event.
   * 
   * The @c ComboSelect is emitted when a entry is selected on the combo.
   * It is not emitted if the index of the entry is the same than the previously selectionned.
   * 
   * @par EventProperties
   *   - Name: @c "ComboSelect"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent* ComboSelect();

  /**
   * Gets the @c ComboActivate event.
   * 
   * The @c ComboActivate is emitted when the user chooses an item in the combobox. Note that this event is sent 
   * even when the choice is not changed. If you need to know when the choice actually changes, use the event ComboSelect.   
   * 
   * @par EventProperties
   *   - Name: @c "ComboActivate"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent* ComboActivate();

   /**
   * Gets the @c ComboPreSelect event.
   * 
   * The @c ComboPreSelect is emitted when a entry is preselected on the combo.(mouse is over the combo item).
   * It is not emitted if the index of the entry is the same than the previously preselectionned.
   * 
   * @par EventProperties
   *   - Name: @c "ComboPreSelect"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent* ComboPreSelect();

  /**
   * Gets the @c ComboMoreButtonPress event.
   * 
   * The @c ComboMoreButtonPress is emitted when the "more" button is pressed.
   * This button is visible only if the flag MoreButtonFlag is activated.
   * 
   * @par EventProperties
   *   - Name: @c "ComboMoreButtonPress"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   * 
   * @see SetMoreButtonFlag
   */
  static CATSYPEvent* ComboMoreButtonPress();
   /**
   * Gets the @c ComboClose event.
   * 
   * The @c ComboClose is emitted just after the combo box popup is hidden.
   * You can listen to this event to perform actions when the popup is closed (even if the model data has not changed).
   * 
   * @par EventProperties
   *   - Name: @c "ComboClose"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent* ComboClose();

  /**
   * @returns the event notification sent whenever a value is selected in the combo box.
   * Better use the CATSYPEvent, more powerfull and flexibles.
   */
  CATNotification *GetComboSelectNotification() const;

  /**
   * Specifies the index of the preselected item in the combo box popup.
   */
  void SetPreselectedIndex(int i_preselectedIndex);
  int GetPreselectedIndex() const;

  /**
   * Sets an icon on the top line, displayed for all possible selected items.
   * @see SetIconDimension
   */
  void SetIcon(const CATUnicodeString& i_icon);

  /**
   * @return the icon on the top line, displayed for all possible selected items.
   */
  const CATUnicodeString& GetIcon() const;

  /**
   * Sets the icon dimension.
   * @see SetIcon
   */
  void SetIconDimension(const CATMathPoint2Df& i_iconDimension);

  /**
   * @return the icon dimension
   */
  const CATMathPoint2Df& GetIconDimension() const;

  /**
   * @return the read only flag indicating if an icon has been set on the combo.
   */
  CATBoolean GetUseIconFlag() const;

  /**
   * @return a read only property indicating if an eventual top line text should be cropped.
   */
  CATVid::CropPolicy GetCropPolicy() const;

  /**@copydoc CATVidWidget#TunnelInformation*/
  virtual void TunnelInformation(const CATVidInformation& i_information);

  /**
   * Returns the combo box top line container.
   * For internal use only.
   */
  CATVidWidget * GetTopLineWidget() const;

  /**
   * Returns the combo box popup.
   * For internal use only.
   */
  CATVidCtlPopup * GetPopup() const;

  /**
  * Callback for press on top line.
  */
  void OnTopLinePress(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

protected:

  /**
   * Constructs a CATVidCtlButton.
   * No associsated style, use static factory CreateButton
   */
  CATVidCtlBaseCombo(CreateLetterFunc i_pCreateLetterFunc);
  /**
   * Constructs a CATVidCtlButton.
   * No associsated style, use static factory CreateButton
   */
  CATVidCtlBaseCombo(CATCommand *i_pParent, const CATString & i_pIdentifier, CreateLetterFunc i_pCreateLetterFunc);

  /** Destructor*/
  virtual ~CATVidCtlBaseCombo();

  /** 
   * Sets the widget embedded in the combo box top line.
   */
  void SetTopLine(CATVidWidget * i_pWidget);

  /** 
   * Returns the widget embedded in the combo box top line.
   */
  CATVidWidget * GetTopLine() const;

  /** Virtual method called whenever an item is preselected in the combo box popup.*/
  virtual void OnPreselect() {}

  /** Virtual method called whenever an item is selected in the combo box.*/
  virtual void OnSelect();

  /**
   * Clears the model.
   */
  virtual void ClearModel();

  /**
   * Sets the index of the first visible item in the combo box popup.
   */
  void SetFirstElementInList(int i_index);

  /**
   * Returns the index of the first visible item in the combo box popup.
   */
  int GetFirstElementInList() const;

private:

  CATVidCtlBaseCombo (CATVidCtlBaseCombo &);
  CATVidCtlBaseCombo& operator=(CATVidCtlBaseCombo& original);

  /**
   * Builds the combo box.
   */
  void BuildCATVidCtlBaseCombo();

  /**
   * Initialize the "software record level" of the CATVidCtlBaseCombo if we are
   * capturing a record ODT.
   *
   * @see s_IsReplayingCATVidCtlBaseComboOfOldOdt
   */
  static void s_InitializeCATVidCtlBaseComboSRL();

  /**
   * Check if we are replaying an old Record ODT.
   *
   * The "software record level" used for versioning this modification
   * is named CATVidCtlBaseCombo and is positioned in the constructor of this
   * class (only once, for the first instance).
   *
   * @return @c != 0 if we are replaying and if the odt has been recorded
   * before the modification has been made.
   *
   * @see s_InitializeCATVidCtlBaseComboSRL
   */
  static int s_IsReplayingCATVidCtlBaseComboOfOldOdt(int i_level);
  
  friend class l_CATVidCtlBaseCombo;
  friend class l_CATVidCtlLegacyBaseCombo;
  friend class l_CATVidCtlModelViewBaseCombo;	
};

CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidCtlBaseCombo__SizeAdjustPolicy);

#endif // CATVidCtlBaseCombo_h
