// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATVidCtlButton.h
// Header definition of CATVidCtlButton
//
//===================================================================
//  March 2008  Creation: jov
//===================================================================
#ifndef CATVidCtlButton_H
#define CATVidCtlButton_H

#include <VisuDialog.h>
#include <CATVidCtl.h>
#include <CATBoolean.h>
#include <CAT4x4Matrix.h>
#include <CATMathPointf.h>
#include <CATVidCursor.h>
#include <CATVidColor.h>
#include <CATVid.h>
#include <CATSYPDeclareEnumFactory.h>

class CATVidMinMax;
class CATVidCtlMenuItem;
class CATVidCtlContextMenu;
class CATVidGP;
class CATVidTooltip;
class CATISYPCollection_var;
class CATISYPPresenter_var;
class CATVidCtlShortHelp;
class CATSYPDuration;
class CATPixelImage;
class CATVidCtlButtonTransferHandler;
class CATVidDnDTransferHandler;
class CATSYPDataBlock;
class CATSYPDataBlockFactory;

/**
 * This widget provides a standard styled button, and is the base class of 
 * other button widgets (see @ref CATVidCtlCheckBox, and @ref CATVidCtlRadioButton).
 *
 * @par Role
 * A button is mainly used to send Click events to listener.
 * It display a label, an icon and a tooltip, and emit a click notification when it is released, 
 * or pressed, depending its ClickMode property. It can be used as check button, or toggling button 
 * (that is a button with a switchable state) by setting its CheckMode property. The current state of 
 * a check button is given and modified by the property CheckState.
 * <br>
 *
 * @par Templates
 * Available template names : Button, Toolbar, Thumbnail
 *
 * @par Creation
 * @code
 * CATVidCtlButton* pButton = CATVidCtlButton::CreateButton(myCommandParent, "ButtonName");
 * @endcode
 * @image html CATVidCtlButton.PNG "Standard button in V6 theme"
 * @image html CATVidCtlButton-Bright.png "Standard button in V6 theme, bright ambiance"
 * @image html CATVidCtlButton-3DViaShape.PNG "Standard button in 3DViaShape theme"
 * @code
 * CATVidCtlButton* pButton = CATVidCtlButton::CreateThumbail(myCommandParent, "ButtonName");
 * @endcode
 * @image html CATVidCtlButton-Thumbnail.PNG "Thumbnail button in V6 theme"
 * @image html CATVidCtlButton-Thumbnail-Bright.png "Thumbnail in V6 theme, bright ambiance."
 * @image html CATVidCtlButton-Thumbnail-3DViaShape.PNG "Thumbnail in 3DViaShape theme"
 *
 * @par Redesigning the button in a theme
 * If you have a CATVidGP with a syp:name="PickZone", the code will automatically :
 * - Set PickFlag and UseManipulatorFlag to TRUE
 * - Connect GiveFocusOnDragFlag, AcceptFocusOnDropFlag and AllowDoubleClickEventEventFlag
 * - Subscribe to all GP events, to callback HandleEvent
 *
 * @ingroup VIDControls
 */
 //* @ htmlinclude class_c_a_t_boxing.html
class ExportedByVisuDialog CATVidCtlButton: public CATVidCtl
{
  CATDeclareClass;
  friend class l_CATVidCtlButton;
  friend class CATVidCtlButtonTransferHandler;
  friend class CATVidCtlButtonDataSupport;
  friend class CATVidTstCATVidCtlButtonTest;
public:
  /** @name Events
   * The events dispatched by @ref CATVidCtlButton instances.
   */
  /**@{*/

  /**
   * Get the @c Drag event.
   *
   * The @c Drag event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "Drag"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *Drag();
  /**
   * Get the @c Click event.
   *
   * The @c Click event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "Click"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *Click();
  /**
   * Get the @c Press event.
   *
   * The @c Press event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "Press"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *Press();
  /**
   * Get the @c ReleaseEvt event.
   *
   * The @c ReleaseEvt event is dispatched on the button when 
   *
   * @par Event Name Specificity
   * The function name is @c ReleaseEvt but the name seen by
   * introspection (i.e. returned by @ref
   * CATSYPEventDescriptor#GetName) and the debug name of the returned
   * event (i.e. returned by @ref CATSYPEvent#GetName) is @c
   * "Release".
   *
   * @par
   * This bypass was necessary since this event existed before the
   * creation of @ref CATSYPEvent events. As a consequence this was
   * not an issue when it was introduced to give it the name of an
   * existing function. Since the introspection name is used in @c
   * .sypstyle files it can't be changed easily. And the debug name
   * returned by @ref CATSYPEvent#GetName is used by @ref
   * CATSYPEventCompatHandler and can't also be changed.
   *
   * @par EventProperties
   *   - Name: @c "Release". Note that it is different than the 
   *     function name since @c Release is already a member function 
   *     of @ref CATBaseUnknown class. See above.
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *ReleaseEvt();
  /**
   * Get the @c MultiplePress event.
   *
   * The @c MultiplePress event is dispatched on the button when 
   * It is sent only if AllowMultiplePressFlag is set to TRUE (The default is FALSE).
   *
   * @par EventProperties
   *   - Name: @c "MultiplePress"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *MultiplePress();
  /**
   * Get the @c DoubleClick event.
   *
   * The @c DoubleClick event is dispatched on the button when 
   * It is sent only if AllowDoubleClickEventFlag is set to TRUE (which is the default).
   *
   * @par EventProperties
   *   - Name: @c "DoubleClick"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *DoubleClick();
  /**
   * Get the @c DoubleRelease event.
   *
   * The @c DoubleRelease event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "DoubleRelease"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *DoubleRelease();
  /**
   * Get the @c RightClick event.
   *
   * The @c RightClick event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "RightClick"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *RightClick();
  /**
   * Get the @c Entry event.
   *
   * The @c Entry event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "Entry"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *Entry();
  /**
   * Get the @c Leave event.
   *
   * The @c Leave event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "Leave"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *Leave();
  /**
   * Get the @c MoveOver event.
   *
   * The @c MoveOver event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "MoveOver"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *MoveOver();
  /**
   * Get the @c BeginPreDrop event.
   *
   * The @c BeginPreDrop event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "BeginPreDrop"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *BeginPreDrop();
  /**
   * Get the @c PreDrop event.
   *
   * The @c PreDrop event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "PreDrop"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *PreDrop();
  /**
   * Get the @c EndPreDrop event.
   *
   * The @c EndPreDrop event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "EndPreDrop"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *EndPreDrop();
  /**
   * Get the @c Drop event.
   *
   * The @c Drop event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "Drop"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *Drop();
  /**
   * Get the @c PostDrop event.
   *
   * The @c PostDrop event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "PostDrop"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *PostDrop();
  /**
   * Get the @c Hold event.
   *
   * The @c Hold event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "Hold"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *Hold();
  /**
   * Get the @c LongHold event.
   *
   * The @c LongHold event is dispatched on the button when 
   *
   * @par EventProperties
   *   - Name: @c "LongHold"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *LongHold();
  /**
  * Get the @c CheckStateChanged event.
  *
  * The @c CheckStateChanged event is dispatched on the button when
  *
  * @par EventProperties
  *   - Name: @c "CheckStateChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *CheckStateChanged();
  /**
  * Get the @c ValueChanged event.
  *
  * The @c ValueChanged event is dispatched on the button when
  *
  * @par EventProperties
  *   - Name: @c "ValueChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *ValueChanged();
  /**@}*/

public:
  /**
   * Constructs a CATVidCtlButton.
   * No associsated style, use static factory CreateButton
   */
  CATVidCtlButton();
  /**
   * Constructs a CATVidCtlButton.
   * No associsated style, use static factory CreateButton
   */
  CATVidCtlButton(CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
   * Constructs a CATVidCtlButton with standard button style.
   * @param i_pParent
   *   The parent of the button.
   * @param i_pIdentifier
   *   The name of the button.
   */
  static CATVidCtlButton* CreateButton(CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
   * Constructs a CATVidCtlButton with thumbnail style.
   * @param i_pParent
   *   The parent of the button.
   * @param i_pIdentifier
   *   The name of the button.
   */
  static CATVidCtlButton* CreateThumbnail(CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
   * Constructs a CATVidCtlButton with toolbar style.
   * @param i_pParent
   *   The parent of the button.
   * @param i_pIdentifier
   *   The name of the button.
   */
  static CATVidCtlButton* CreateToolbarButton(CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
   * Constructs a CATVidCtlButton with a compact template (same as deprecated @ref CreateTouchButton).
   * The button does not stretch when attached so the picking area is larger than the button rep.
   * @param i_pParent
   *   The parent of the button.
   * @param i_pIdentifier
   *   The name of the button.
   */
  static CATVidCtlButton* CreateCompactButton(CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
   * Constructs a CATVidCtlButton with an immersive template.
   * The button is meant to be used within a Viewer and inside a 3D scene
   * @param i_pParent
   *   The parent of the button.
   * @param i_pIdentifier
   *   The name of the button.
   */
  static CATVidCtlButton* CreateImmersiveButton(CATCommand* i_pParent, const CATString& i_pIdentifier);

public:
  enum State {Off=0, On, Over, OnAndOver, OnPressed, OffPressed};

  enum ButtonAndDeviceStateEnum { Out = 0, PressedAndOut, Hover, PressedAndHover, Checked_Out, Checked_PressedAndOut, Checked_Hover, Checked_PressedAndHover };

	enum ModelStateEnum { Unchecked = 0, Checked, MixedUnchecked, MixedChecked};
  /**
   * Sets the Click mode of the button
   * @param i_clickMode
   * The click mode of the button to set.
   *   <br>
   *   <b>Legal values</b> : It can be set to either :
   *   <dl>
   *   <dt><tt>0</tt><dd> to send Click notification by releasing the button,
   *   <dt><tt>1</tt><dd> to send Click notification by pressing the button.
   *   </dl>
   */
  void SetClickMode(unsigned int i_clickMode);
  /**
   * @return the Click mode of the button.
   * <br>
   * The click mode of the button can be:
   *   <dl>
   *   <dt><tt>0</tt><dd> Click notification is sended by releasing the button.
   *   <dt><tt>1</tt><dd> Click notification is sended by pressing the buttton.
   *   </dl>
   */
  unsigned int GetClickMode() const;
  /**
   * Sets the check mode of the button
   * @param i_checkMode
   * The check mode of the button to set.
   *   <br>
   *   <b>Legal values</b> : It can be set to either :
   *   <dl>
   *   <dt><tt>0</tt><dd> to have standard button behavior
   *   <dt><tt>1</tt><dd> to have check button behavior, that is using a check state on or off.
   *   </dl>
   */
  void SetCheckMode(unsigned int i_checkMode);
  /**
   * @return the check mode of the button
   *   <br>
   * The check mode of the button can be:
   *   <dl>
   *   <dt><tt>0</tt><dd> standard button behavior
   *   <dt><tt>1</tt><dd> check button behavior, that is using a check state on or off.
   *   </dl>
   */
  unsigned int GetCheckMode() const;
  /**
   * Sets the check state of the button when its Check mode is set to 1
   * @param i_checkState
   * The check state of the button to set.
   *   <br>
   *   <b>Legal values</b> : It can be set to either :
   *   <dl>
   *   <dt><tt>FALSE</tt><dd> to put the button in uncheck state,
   *   <dt><tt>TRUE</tt><dd> to put the button in check state
   *   </dl>
   */
  void SetCheckState(const CATBoolean i_state);
  /**
   * @return the check state of the button in check mode
   *   <br>
   * The check state of the button can be:
   *   <dl>
   *   <dt><tt>FALSE</tt><dd> check button is unchecked,
   *   <dt><tt>TRUE</tt><dd> check button is checked.
   *   </dl>
   */
  CATBoolean GetCheckState() const;
  /**
   * The button is partially checked. It represents a mixed state. <br/>
   * For example in a hierarchical model, if some children items of the button are checked, but not all. <br/>
   * According to ergonomic rules, it should not be used for representing a third state (use a combo instead),
   * nor for an undetermined state (use default value instead).
   *   <dl>
   *   <dt><tt>TRUE :</tt><dd> Set it to TRUE to represent a mixed state. <br/>
   *     Warning : only do this in a component that handles mixed state, i.e. have a visualization for it. For now, it's only the case for CATVidCtlCheckBox. <br/>
   *     Warning2 : the value of CheckState does not really have a meaning when MixedState is TRUE. Test the MixedState, then the CheckState. <br/>
   *     Warning3 : it will work only when CheckMode is set to 1.
   *   <dt><tt>FALSE :</tt><dd> This should not been done by code, in a normal use (rather by clicking on the button). <br/>
   *     The CheckState is defined by the value of AllCheckedAfterMixedStateFlag (default : TRUE, so CheckState will be TRUE).
   *   </dl>
   * You could need to set SetCyclingThreeStateFlag(CATBoolean) and SetAllCheckedAfterMixedStateFlag(CATBoolean).
   */
  void SetMixedState(const CATBoolean i_mixedState);
  /**
   * @see SetMixedState
   */
  CATBoolean GetMixedState() const;
  /**
   * When working with a mixed state (see SetMixedState), the default behavior is : when you click on the button, to be check or not (depending on AllCheckedAfterMixedStateFlag),
   * then cycling between checked and not-checked. <br/>
   * If you don't do anything each time you press the button (for example in a apply/cancel panel), you could want to cycle through the tree states (checked - not checked - mixed). <br/>
   * This way, it acts as an undo when you come back to mixed state. <br/>
   * Default : FALSE.
   */
  void SetCyclingThreeStateFlag(const CATBoolean i_cyclingThreeStateFlag);
  /**
   * @see SetCyclingThreeStateFlag
   */
  CATBoolean GetCyclingThreeStateFlag() const;
  /**
   * Defines whether the button should be checked when MixedState become FALSE ( by code, introspection, or clicking on the mixed state button.<br/>
   * Default : TRUE.
   */
  void SetAllCheckedAfterMixedStateFlag(const CATBoolean i_allCheckedAfterMixedStateFlag);
  /**
   * @see SetAllCheckedAfterMixedStateFlag
   */
  CATBoolean GetAllCheckedAfterMixedStateFlag() const;
  /**
   * @deprecated
   * Please use @ref CATVidMdlContextMenu (see @ref CATVidCtl#GetContextMenu) 
   * instead of deprecated CATVidCtlContextMenu.
   *
   * Adds an item to the contextual menu of the button (appearing on right click).
   * The button control takes the ownership of the CATVidCtlMenuItem, without AddRef.
   * The menu items shoulf be kept as weak ref to avoid dead pointer conflict.
   * @param i_pPushItem
   * The new menu item to add to the contextual menu. Its a command, and its RequestDelayedDestruction is handled by the button
   */  
  void AddItemToContextualMenu(CATVidCtlMenuItem* i_pPushItem);
  /**
   * @deprecated
   * Please use @ref CATVidMdlContextMenu (see @ref CATVidCtl#GetContextMenu) 
   * instead of deprecated CATVidCtlContextMenu.
   *
   * Remove an item to the contextual menu of the button (appearing on right click)
   * @param i_pPushItem
   * The menu item to remove to the contextual menu. Its a command, and its RequestDelayedDestruction is NO MORE handled by the button
   */  
  void RemoveItemFromContextualMenu(CATVidCtlMenuItem* i_pPushItem);
  /**
   * Sets a flag that allows to send MultiplePress notification when mouse remain pressed.
   * Default is FALSE.
   * @param i_allowMultiplePressFlag
   * The flag of the button to set.
   */
  void SetAllowMultiplePressFlag(const CATBoolean i_allowMultiplePressFlag);
  /**
   * @see SetAllowMultiplePressFlag
   **/
  CATBoolean GetAllowMultiplePressFlag() const;
  /**
   * Sets a flag that allows to send DoubleClick notification.
   * Normally bound to CATVidGP::SetAllowDoubleClickEventFlag.
   * Default is TRUE.
   * When set to FALSE, an other click will be sent, instead of a DoubleClick.
   */
  void SetAllowDoubleClickEventFlag(const CATBoolean i_allowDoubleClickEventFlag);
  /**
   * @see SetAllowDoubleClickEventFlag
   **/
  CATBoolean GetAllowDoubleClickEventFlag() const;
  /**
   * Sets the string displayed in tooltip when mouse stay above the button without press
   * No tooltip will be displayed if the string is empty
   * @param i_tooltip
   * The String to display in tooltip.
   */
  void SetTooltip(const CATUnicodeString& i_tooltip);
  /**
   * @return the string displayed in tooltip when mouse stay above the button without press
   **/
  const CATUnicodeString GetTooltip() const;  

  /**
   * @return the transfer handler used in Drag & Drop
   **/
  virtual CATVidDnDTransferHandler* GetTransferHandler()const;

  /**
   * Asserts that @c i_pTransferHandler is a @c CATVidCtlButtonTransferHandler.
   * @copydoc CATVidCtl#SetTransferHandler.
   **/
  virtual void SetTransferHandler(CATVidDnDTransferHandler* i_pTransferHandler);

  /**
   * @name Notifications
   */
  /*@{*/ 
  /** @return the event notification sent whenever the button is clicked. */
  CATNotification* GetClickNotification() const;
  /** @return the event notification sent whenever the button is dragged. */
  CATNotification* GetDragNotification() const;
  /** @return the event notification sent whenever the button is pressed. */
  CATNotification* GetPressNotification() const;
  /** @return the event notification sent whenever the button is released. */
  CATNotification* GetMouseReleaseNotification() const;
  /**
   * @return the event notification sent whenever the button remain pressed.
   * <br />
   * This notification is sended only if AllowMultiplePressflag is set to TRUE
   */
  CATNotification* GetMultiplePressNotification() const;
  /** @return the event notification sent whenever the button is double-clicked. */
  CATNotification* GetDoubleClickNotification() const;
  /** @return the event notification sent whenever the button is right clicked. */
  CATNotification* GetRightClickNotification() const;
  /** @return the event notification sent whenever the mouse entries the button. */
  CATNotification* GetMouseEntryNotification() const;
  /** @return the event notification sent whenever the mouse moves over the button. */
  CATNotification* GetMouseMoveOverNotification() const;
  /** @return the event notification sent whenever the mouse leaves the button. */
  CATNotification* GetMouseLeaveNotification() const;
  /** @return the event notification sent whenever */
  CATNotification* GetBeginPreDropNotification() const;
  /** @return the event notification sent whenever */
  CATNotification* GetPreDropNotification() const;
  /** @return the event notification sent whenever */
  CATNotification* GetEndPreDropNotification() const;
  /** @return the event notification sent whenever */
  CATNotification* GetDropNotification() const;
  /** @return the event notification sent when drop is done */
  CATNotification* GetPostDropNotification() const;

  /*@}*/ 

  enum Emphasize { Emphasize_NoEmphasize=0, Emphasize_Primary , Emphasize_Secondary, Emphasize_Success, Emphasize_Info, Emphasize_MediumAttention, Emphasize_HighAttention };
  CATVidCtlButton::Emphasize GetEmphasize() const;
  void SetEmphasize(CATVidCtlButton::Emphasize i_emphasize);


  /**
   * Sets the color used as foreground color (for example, used to draw the text of the button most of the time)
   * @param i_foregroundColor
   * The foreground color to set.
   */
  void SetForegroundColor( const CATVidColor &i_foregroundColor );
  /**
   * @return the color used as foreground color (for example, used to draw the text of the button most of the time)
   */
  const CATVidColor &GetForegroundColor( void ) const;
  /**
   * Sets the color used as background color
   * @param i_backgroundColor
   * The background color to set.
   */
  void SetBackgroundColor( const CATVidColor &i_backgroundColor );
  /**
   * @return the color used as background color
   */
  const CATVidColor &GetBackgroundColor( void ) const;
  /**
   * Sets a relative path to locate a ressource icon
   * @param i_icon
   * The relative path to localte ressource.
   */
  void SetIcon( const CATUnicodeString &i_icon );
  /**
   * @return the relative path to locate a ressource icon
   **/
  const CATUnicodeString &GetIcon( void ) const;
  /**
   * Sets the image used for the icon
   * @param i_pImage
   * The image to use for the icon.
   */
  void SetIconPixelImage(CATPixelImage* i_pImage);
  /**
   * @return the image used for the icon
   */
  CATPixelImage* GetIconPixelImage() const;
  /**
   * Sets a color used to replace dynamically every black pixels of the icon image
   * @param i_colorizeIconBlackPixelTo
   * The colorize color to set.
   */
  void SetColorizeIconBlackPixelTo( const CATVidColor & i_colorizeIconBlackPixelTo);
  /**
   * @return a color used to replace dynamically every black pixels of the icon image
   **/
  const CATVidColor &GetColorizeIconBlackPixelTo() const;
  /** @return a flag specifying if SetColorizeIconBlackPixelTo has been called.*/
  CATBoolean GetColorizeIconBlackPixelFlag() const;
  /**
   * Sets the dimension of the icon
   */
  void SetIconDimension( const CATMathPoint2Df &i_iconDimension );
  /**
   * @return the dimension of the icon
   */
  const CATMathPoint2Df& GetIconDimension() const;
  /**
   * Sets the label of the button
   */
  void SetLabel( const CATUnicodeString &iLabel );
  /**
   * @return the label of the button
   */
  const CATUnicodeString &GetLabel( void ) const;
  /**
   * Sets the font height of the label
   */
  void SetFontHeight(unsigned int i_fontHeight);
  /**
   * @return the font height of the label
   */
  unsigned int GetFontHeight() const;
  /**
   * Sets the font weight of the label
   */
  void SetFontWeight(unsigned int i_fontWeight);//0:Std; 1:Bold
  /**
   * @return the font weight of the label
   */
  unsigned int GetFontWeight() const;
  /**
   * Sets the underline flag of the label
   */
  void SetUnderlineFlag(CATBoolean i_underlineFlag);
  /**
   * @return the underline flag of the label
   */
  CATBoolean GetUnderlineFlag() const;
  /**
   * Sets the crop policy of the label
   * @param i_crop
   *   <br>
   *   <b>Legal values</b> : It can be set to either :
   *   <dl>
   *   <dt><tt>CATVid::NoCrop</tt><dd> : the minimum dimension of the button is function of the label dimension
   *   <dt><tt>CATVid::CropCut</tt><dd> : the dimension of the button is not function of the label dimension, the label is cutted
   *   <dt><tt>CATVid::CropWithDots</tt><dd> : the dimension of the button is not function of the label dimension, the label is cutted with dots
   *   </dl>
   */  
  void SetCropPolicy(CATVid::CropPolicy i_cropPolicy);
  /**
   * @return the crop policy of the label
   *   <br>
   * The crop property can be:
   *   <dl>
   *   <dt><tt>CATVid::NoCrop</tt><dd> : the minimum dimension of the button is function of the label dimension
   *   <dt><tt>CATVid::CropCut</tt><dd> : the dimension of the button is not function of the label dimension, the label is cutted
   *   <dt><tt>CATVid::CropWithDots</tt><dd> : the dimension of the button is not function of the label dimension, the label is cutted with dots
   *   <dt><tt>CATVid::CropBeginWithDots</tt><dd> : the dimension of the button is not function of the label dimension, the label is cutted with dots in the begining.
   *   <dt><tt>CATVid::CropMiddleWithDots</tt><dd> : the dimension of the button is not function of the label dimension, the label is cutted with dots in the middle.
   *   </dl>
   */  
  CATVid::CropPolicy GetCropPolicy() const;
  /**
   * @return if the mouse is over the button. It works in drag mode (left mouse buitton pressed)
   * and in standard mode (left mouse button is not pressed)
   */
  CATBoolean GetMouseOverFlag() const;
  /**
   * @deprecated use the property "VisualState" instead.
   * @return if the button reflect the MouseOverFlag. If CheckMode=0, it is identical to MouseOverFlag.
   * In case of CheckMode==1 && CheckState==1, the OverFlag is always null. But in this state, pressing
   * the button will involve CheckState==0, and OverFlag will become 1. For Styling purpose.
   */
  CATBoolean GetOverFlag() const;
  /**
   * The property VisualState is used for styling purpose only.
   * It depends on the values of "OnFlag" and "MouseOverFlag" :
   *   - CATVidCtlButton::Off if OnFlag:0 and MouseOverFlag:0
   *   - CATVidCtlButton::On if OnFlag:1 and MouseOverFlag:0
   *   - CATVidCtlButton::Over if OnFlag:0 and MouseOverFlag:1
   *   - CATVidCtlButton::OnAndOver if OnFlag:1 and MouseOverFlag:1
   * The property "OverFlag" is now deprecated.
   */
  CATVidCtlButton::State GetVisualState() const;
  CATVidCtlButton::ButtonAndDeviceStateEnum GetButtonAndDeviceState() const;


	CATVidCtlButton::ModelStateEnum GetModelState() const;

	/**
	* The property VisualState is used for styling purpose only.
	*/
	int GetHoveringVisualState();

  /**
   * @return if the mouse button is pressed.
   */
  CATBoolean GetButtonPressedFlag()const;
  /**
   * @return if the button reflects the ButtonPressedFlag.
   * For a standard push button, OnFlag become 0 when draging out, and 1 when re-draging in.
   * For a check button, the onFlag is toggled  when pressing it.
   */
  CATBoolean GetOnFlag()const;
  /** @return if an icon is used. For styling purpose*/
  virtual CATBoolean GetUseIconFlag() const;
  /** @return if a label is used. For styling purpose*/
  CATBoolean GetUseLabelFlag() const;
  /** @return 0 if empty, 1 if only label, 2 if only icon, 3 if label and icon. Foir styling purpose.*/  
  CATBoolean GetContentState() const;

  /**
   * Sets the horizontal alignment of the button label.
   * By default, the HorizontalAlignment property is set to CATVid::AlignCenter.
   */
  void SetHorizontalAlignment(CATVid::Alignment i_hAlign);

  /**
   * Returns the horizontal alignment of the button label.
   */
  CATVid::Alignment GetHorizontalAlignment() const;

  /**
   * Handles all events of button view. Should be private.
   */
  void HandleEvent(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  /**@deprecated Called internally, should be private.*/
  void SetMouseOverFlag(const CATBoolean i_mouseOverFlag);
  /**@deprecated Called internally, should be private.*/
  void SetOnFlag(const CATBoolean i_onFlag);
  /**@deprecated Called internally, should be private.*/
  void SetOverFlag(const CATBoolean i_overFlag);

  void SetShortHelpAttachmentSide(unsigned int i_shortHelpAttachmentSide);
  unsigned int GetShortHelpAttachmentSide() const;
  void SetCursorShape(CATVid::MouseCursorShape i_cursor);
  CATVid::MouseCursorShape GetCursorShape() const;
  /**
   * @return the result point in device independant pixels (dp).
   */
  CATMathPointf GetManipulatorResultPoint();
  /**
   * @return the transformation matrix in device independant pixels (dp).
   */
  const CAT4x4Matrix& GetTransformationMatrix() const;
  /** @param i_squareLimits in device independant pixels (dp) */
  void SetDragLimits(const CATVidMinMax & i_squareLimits);
  CATISYPCollection_var GetMenuContextualItems();
  CATISYPPresenter_var GetShortHelpItem();
  void SetIconFilter(const unsigned int& i_iconFilter);
  const unsigned int &GetIconFilter( void ) const;
  void SetShortHelpBeginTime(const CATSYPDuration& i_duration);
  CATSYPDuration GetShortHelpBeginTime() const;
  void SetDefaultFlag(const CATBoolean i_defaultFlag);
  CATBoolean GetDefaultFlag() const;
  void SetAutoDefaultFlag(const CATBoolean i_autoDefaultFlag);
  CATBoolean GetAutoDefaultFlag() const;
  void SetGiveFocusOnDragFlag(CATBoolean i_giveFocusOnDragFlag);
  CATBoolean GetGiveFocusOnDragFlag() const;
  void SetAcceptFocusOnDropFlag(CATBoolean i_acceptFocusOnDropFlag);
  //Change the manipulator on drag only after a hold
  void SetGiveFocusOnHoldDragFlag(CATBoolean i_giveFocusOnDragFlag);
  CATBoolean GetGiveFocusOnHoldDragFlag() const;
  CATBoolean GetAcceptFocusOnDropFlag() const;
  const char* GetPressNotificationName() const;
  
  void SetAutomaticIconDimensionFlag(CATBoolean i_AutomaticIconDimensionFlag);
  CATBoolean GetAutomaticIconDimensionFlag() const;

 /**
  * Sets the data template to use to build the content of the button.
  *
  * @param i_dataTemplate the name of the data template to use. Cannot be an
  * empty string.
  *
  * @param i_styleSheet the sypstyle file in which the data template is
  * defined. Cannot be an empty string.
  *
  * Before calling this method, please check that your style sheet contains
  * @c i_dataTemplate.
  *
  * If using your own data-block for the button, call @ref #SetContentDataBlock
  * before @ref #SetContentDataTemplate.
  *
  * @see #SetContentDataBlock
  */
  void SetContentDataTemplate(const CATUnicodeString& i_dataTemplateName, const CATUnicodeString& i_styleSheet);

   /**
  * Sets the stylesheet that contains the data template used to compute the
  * view of the button content. Always use in coordination with
  * @ref #SetContentDataTemplateName. Does not update the current view.
  *
  * @param i_dataTemplateStyleSheet name of the stylesheet that contains the
  * data template to use to build the view of displayed items.
  *
  * @see SetContentDataTemplateName
  */
  void SetContentDataTemplateStyleSheet(const CATUnicodeString& i_dataTemplateStyleSheet);

  /**
  * Sets the name of the data template to use to compute the view of the button
  * content. Always use in coordination with
  * @ref #SetContentDataTemplateStyleSheet. Does not update the current view.
  *
  * @param i_dataTemplateName name of the data template to use.
  *
  * @see #SetContentDataTemplateStyleSheet
  */
  void SetContentDataTemplateName(const CATUnicodeString& i_dataTemplateName);

 /**
  * @return the stylesheet in which the data template of the button content can
  * be found.
  */
  CATUnicodeString GetContentDataTemplateStyleSheet() const;

 /** @return the name of the data template used to build the header view. */
  CATUnicodeString GetContentDataTemplateName() const;

 /**
  * Releases the previous content data block and associates the new one to the
  * current button content data template; the button content view will be
  * regenerated.
  * 
  * @par 
  * The default data-block contains the following properties:
  * @li
  *
  * @param i_pDataBlock : the data-block representing the button content. Cannot
  * be @c NULL.
  *
  * @see #SetContentDataTemplate
  */
  void SetContentDataBlock(CATSYPDataBlock* i_pDataBlock);

  /** @return the data-block representing the button content. */
  CATSYPDataBlock * GetContentDataBlock() const;

  /**
   * Returns TRUE if the button is under a drag interaction, FALSE otherwise.
   */
  CATBoolean GetDraggedState() const;

  // DEPRECATED:

  /**
   * @deprecated Use @ref CATVidCtl drag-and-drop instead.
   *
   * @param i_dragAndDropFlag @c TRUE to allow drag and drop, @c FALSE else.
   *
   * @see #GetDragAndDropFlag
   */
  void SetDragAndDropFlag(const CATBoolean i_dragAndDropFlag);
  /**
   * @deprecated Use @ref CATVidCtl drag-and-drop instead.
   *
   * @par
   * The @c DragAndDropFlag is used to declare a control as dragable. As soon 
   * as the flag is put to @c TRUE, the control will take priority over all its 
   * parents controls when a drag is performed (even if it has no transfer 
   * handler). The control which will be dragged on a drag action is the 
   * outermost control of the widget tree being under the mouse and 
   *
   * @par
   * Default value of the flag is @c FALSE.
   *
   * @return the drag and drop flag of the control.
   *
   * @see #GetTransferHandler
   */
  CATBoolean GetDragAndDropFlag() const;
  /**
   * @deprecated Use @ref CATVidCtl drag-and-drop instead.
   *
   * @return @c TRUE if the control has a default transfer handler, @c FALSE
   * else. The default transfer handler will not be built when calling this
   * function.
   */
  CATBoolean HasDefaultTransferHandler() const;

  /**
   * @deprecated Use @ref CreateCompactButton instead.
   *
   * Constructs a CATVidCtlButton with a specific template for multi-touch mode.
   * The button does not stretch when attached so the picking area is larger than the button rep.
   * @param i_pParent
   *   The parent of the button.
   * @param i_pIdentifier
   *   The name of the button.
   */
  static CATVidCtlButton* CreateTouchButton(CATCommand *i_pParent, const CATString & i_pIdentifier);

  /**
   * @copydoc l_CATVidCtl#TemplateDataUpdated
   * Here are the optional "syp:named" objects :
   * @li CATVidCtl [Content] button content
   */
  virtual void TemplateDataUpdated();

  /**
  * Sets the value of the button
  * @param i_value the value of the button
  */
  void SetValue(const CATBaseUnknown_var& i_value);

  /**
  * @return the value of the button.
  */
  const CATBaseUnknown_var& GetValue() const;

  /**
   * Specifies whether the button uses margins or not in its content
   * By default, the UseMarginsFlag property is set to TRUE.
   */
  void SetUseMarginsFlag(CATBoolean i_useMarginsFlag);

  /**
   * Returns TRUE if the window uses margins, FALSE otherwise.
   */
  CATBoolean GetUseMarginsFlag() const;

/**
  * Sets the valueAsString of the button
  * @param i_valueAsString the value as a string of the button
  */
  void SetValueAsString(const CATUnicodeString& i_valueAsString);

/**
  * @return the valueAsString of the button.
  */
  CATUnicodeString GetValueAsString() const;


  /**
   * Specifies whether the window uses margins or not.
   * By default, the UseMarginsFlag property is set to TRUE.
   */
  void SetUseContentMinimumDimensionFlag(CATBoolean i_useContentMinimumDimensionFlag);

  /**
   * Returns TRUE if the window uses margins, FALSE otherwise.
   */
  CATBoolean GetUseContentMinimumDimensionFlag() const;

  protected:
  /**
   * Constructs a CATVidCtlButton.
   * No associated style, use static factory CreateButton
   */
  CATVidCtlButton(CreateLetterFunc i_pCreateLetterFunc);
  /**
   * Constructs a CATVidCtlButton.
   * No associated style, use static factory CreateButton
   */
  CATVidCtlButton(CATCommand *i_pParent, const CATString & i_pIdentifier, CreateLetterFunc i_pCreateLetterFunc);

  virtual ~CATVidCtlButton ();
  void OnClickAction(CATSYPEventArgs* i_pArgs);
  virtual void UpdateStateView(){};
  virtual void TunnelInformation(const CATVidInformation& i_information);
  virtual void SetCheckState_internal(const CATBoolean i_state);

  void SetButtonPressedFlag(const CATBoolean i_buttonPressedFlag);

  /** Fill the factory for the default button content. */
  static void FillDefaultContentFactory(CATSYPDataBlockFactory & i_factory);
  /** @return the factory for the default button content. */
  virtual CATSYPDataBlockFactory * GetContentFactory() const;

  void UpdateEmphasizeStyle();


private:
  /** static constructor */
  static void initCATVidCtlButton();

  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlButton (CATVidCtlButton &);
  CATVidCtlButton& operator=(CATVidCtlButton& original);

 /**
  * Updates the view of the button content depending on the current data
  * data template and data block.
  */
  void UpdateContentView();

 /**
  * Create default button content data block.
  */
 CATSYPDataBlock * CreateDefaultContentDB();

 /**
  * Connect the button content view properties with the data block properties.
  */
  void ConnectDBProperties();

  /**
   * Method called when CATVidInfo_Disable is received to
   * handle the case where the button is disabled while pressed.
   */
  void OnDisable();

  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example. (see @ref #HandleEvent documentation
   * for details).
   */
  void OnDrag(CATSYPEventArgs *i_pArgs);
  /** 
   * @deprecated @see CATVidGP::TouchMove
   * This handler on deprecated @ ref TouchMove event is used to desactivate the
   * click of the button when a parent scrollable has consumed the Drag.
   */
  void OnTouchMove(CATSYPEventArgs *i_pArgs);
  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example. (see @ref #HandleEvent documentation
   * for details).
   */
  void OnMouseEntry(CATSYPEventArgs *i_pArgs);
  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example. (see @ref #HandleEvent documentation
   * for details).
   */
  void OnMouseLeave(CATSYPEventArgs *i_pArgs);
  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example. (see @ref #HandleEvent documentation
   * for details).
   */
  void OnMouseMoveOver(CATSYPEventArgs *i_pArgs);
  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example or by keyboard code in @ref
   * l_CATVidWidget. (see @ref #HandleEvent documentation for
   * details).
   */
  void OnPress(CATSYPEventArgs *i_pArgs);
  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example or by keyboard code in @ref
   * l_CATVidWidget. (see @ref #HandleEvent documentation for
   * details).
   */
  void OnRelease(CATSYPEventArgs *i_pArgs);
  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example or by keyboard code in @ref
   * l_CATVidWidget. (see @ref #HandleEvent documentation for
   * details).
   */
  void OnMultiplePress(CATSYPEventArgs *i_pArgs);
  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example. (see @ref #HandleEvent documentation
   * for details).
   */
  void OnRightClick(CATSYPEventArgs *i_pArgs);
  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example. (see @ref #HandleEvent documentation
   * for details).
   */
  void OnEndContext(CATSYPEventArgs *i_pArgs);
  /** 
   * Method for @ref CATVidGP::DoubleClick events.
   * If AllowDoubleClickFlag is FALSE, this method won't be called,
   * OnPress will be called instead.
   *
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example. (see @ref #HandleEvent documentation
   * for details).
   */
  void OnDoubleClick(CATSYPEventArgs *i_pArgs);
  /**
   * Method for @ref CATVidGP::DoubleRelease events.
   * If AllowDoubleClickFlag is FALSE, this method won't be called,
   * OnRelease will be called instead.
   *
   * @param i_pArgs the event arguments. Can't be @NULL.
   */
  void OnDoubleRelease(CATSYPEventArgs *i_pArgs);
  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example. (see @ref #HandleEvent documentation
   * for details).
   */
  void OnBeginPreDrop(CATSYPEventArgs *i_pArgs);
  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example. (see @ref #HandleEvent documentation
   * for details).
   */
  void OnPreDrop(CATSYPEventArgs *i_pArgs);
  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example. (see @ref #HandleEvent documentation
   * for details).
   */
  void OnEndPreDrop(CATSYPEventArgs *i_pArgs);
  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example. (see @ref #HandleEvent documentation
   * for details).
   */
  void OnDrop(CATSYPEventArgs *i_pArgs);
  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example. (see @ref #HandleEvent documentation
   * for details).
   */
  void OnHold(CATSYPEventArgs *i_pArgs);
  /** 
   * @param i_pArgs the event argument. May be @c NULL when called by
   * @ref #Replay for example. (see @ref #HandleEvent documentation
   * for details).
   */
  void OnLongHold(CATSYPEventArgs *i_pArgs);
  /**
   * @param i_eventName the name of the event as returned by @ref CATSYPEvent#GetName.
   *
   * @param i_pArgs the dispatching arguments of the event. Can be @c
   * NULL for example when this function is called by @ref #Replay
   * function. Note that the events may be event of @ref CATVidGP or a
   * @ref CATVidCtlButton (or maybe other classes, but at least those
   * two). Since those classes shares homonymous events they are
   * handle the same way.
   */

  void ChangeState();
  void HandleEvent(const CATUnicodeString &i_eventName, CATSYPEventArgs *i_pArgs);
  void HideTooltip();
  void OnPostDrop();
  void HideShortHelp();
  
  void PropagateEventFromGP(CATSYPEventArgs* i_pSourceArgs, CATSYPEvent* i_pTargetEvent, CATNotification* i_pNotification);
  void SetMouseOverFlag(const CATBoolean i_mouseOverFlag, CATSYPEventArgs* i_pArgs);

  void UpdateMarginStyle();
  void UpdateUseContentMinimumDimensionStyle();

  private:
  CATVidGP *_pManipGP;
  CATPixelImage* _pImage;
  CATVidCtlContextMenu*           _pContextMenu;
  CATMathPointf                   _manipulatorResultPoint; // in dp
  CAT4x4Matrix                    _manipulatorMatrix; // in dp
  CATVid::MouseCursorShape             _cursorShape;
  unsigned int                    _iconFilter;
  CATVidColor                     _foregroundColor;
  CATVidColor                     _backgroundColor;
  CATVidColor                     _colorizeIconBlackPixelTo;
  int                             _fontHeight;
  int                             _shortHelpAttachmentSide;
  unsigned int                    _fontWeight;
  CATVid::CropPolicy              _cropPolicy;
  CATMathPoint2Df                 _iconDimension;
  CATVidCtl* _pShortHelpCtl;
  float _shortHelpBeginTimeInSecond;
  CATSYPEventArgs* _lastTouchMoveEventArgs;
  CATMathPoint2Df _touchPosition;

  CATSYPDataBlock * _pContentDataBlock;
  CATUnicodeString _contentDataTemplateName;
  CATUnicodeString _contentDataTemplateStyleSheet;

  CATSYPTemplateData * _pContentTemplateData;

  Emphasize _emphasize;

  unsigned int _colorizeIconBlackPixelFlag      : 1;
  unsigned int _overFlag                        : 1;
  unsigned int _checkMode                       : 2;
  unsigned int _clickMode                       : 1;
  unsigned int _checkState                      : 1;
  unsigned int _onFlag                          : 1;
  unsigned int _mixedState                      : 1;
  unsigned int _cyclingThreeStateFlag           : 1;
  unsigned int _allCheckedAfterMixedStateFlag   : 1;
  unsigned int _allowMultiplePressFlag          : 1;
  unsigned int _allowDoubleClickEventFlag       : 1;
  unsigned int _cutLabelFlag                    : 1;
  unsigned int _defaultFlag                     : 1;
  unsigned int _autoDefaultFlag                 : 1;
  unsigned int _underlineFlag                   : 1;
  unsigned int _giveFocusOnDragFlag             : 1;
  unsigned int _giveFocusOnHoldDragFlag         : 1;
  unsigned int _automaticIconDimensionFlag      : 1;
  unsigned int _acceptFocusOnDropFlag           : 1;
  unsigned int _clickDisabledFlag               : 1;
  unsigned int _hAlign                          : 1;
  unsigned int _useMarginsFlag                  : 1;
  unsigned int _useContentMinimumDimensionFlag         : 1;
  unsigned int _longHoldOccuredFlag             : 8;

  /** Static factory for default content data-block */
  static CATSYPDataBlockFactory * _spContentFactory;

#ifndef VID_DEPRECATED
  protected:
  CATBoolean _sendPressAndReleaseNotificationFlag;
  public:
  CATNotification *GetPressAndReleaseNotification() const;
  void SetOverCursorInt(unsigned int i_cursor);
  void SetOverCursor(CATVidCursor::CATVidCursorStyle i_cursor);
  void SetCropProperty(CATVidLabelCropProperty i_crop);
  CATVidLabelCropProperty GetCropProperty() const;
#endif
  friend class CATVidSessionCleaner;
};

CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVidCtlButton__State);
CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidCtlButton__ButtonAndDeviceStateEnum);
CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidCtlButton__ModelStateEnum);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVidCtlButton__Emphasize);

//-----------------------------------------------------------------------
#endif
