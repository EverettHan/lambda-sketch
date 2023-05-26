#ifndef CATVidFraPanel_h
#define CATVidFraPanel_h

// COPYRIGHT Dassault Systemes 2011

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidFraWindow.h>
#include <CATVidEnum.h>
#include <CATVid.h>
#include <CATVidLaySideAttachConstraints.h>

// System framework
#include <CATUnicodeString.h>
#include <CATBoolean.h>

class CATVidWidget;
class CATString;
class CATVidCtlButton;

/**
 * @ingroup VIDFrame
 * Class representing a floating panel embedding an immersive widget.
 * A CATVidFraPanel is different from a CATVidFraDialog in the sense it has no standard buttons 
 * and takes a smaller place on the screen:
 *    - Use a CATVidFraPanel when you want to provide tools or controls that users can work with 
 *      while documents are open. A user can open several panels at a time ; they float on top of 
 *      the document windows and can be grouped together.
 *    - Use a CATVidFraDialog when you want to provide a short term command window that will be closed
 *      when the user has ended with this command.
 * 
 * @see CATVidFraWindow for a detailed description of the inherited capabilities.
 *
 * Note that by default, a CATVidFraPanel is not resizable and has its CompactFlag property set to TRUE
 * (see @ref #SetResizableFlag and @ref #SetCompactFlag methods).
 * By default, when created for the first time, a CATVidFraPanel is placed at the first available place 
 * starting from the top right corner of the viewer, but you can specify the preferred initial alignment 
 * in the constructor.
 *
 * The default life cycle of a CATVidFraPanel is CATVidUserSideDocumentLC, i.e its life cycle is bound to its 
 * associated viewer life cycle. When this viewer is destroyed, the window is destroyed too.
 * If the window is closed (by clicking on the 'Close' button) and if the AutoCloseFlag property 
 * is set to FALSE, the window is not destroyed, only the CATVidFraWindow::Closed event is sent. 
 * Set theAutoCloseFlag property to TRUE if you want your window automatically destroyed on the Close button click.
 *
 * @par Panel snapping
 *
 * A CATVidFraPanel is a snappable window ; if you move or resize a panel making one of its edges close to 
 * another snappable window or viewer edge, it will attract and stick until you have moved it far away enough. 
 * To temporarily disable window snapping, you can hold down the <Shift> key while moving or resizing the window.
 *
 * A CATVidFraPanel can also be grouped with other panels inside a CATVidFraWindowGroup either by code 
 * (see @ref #AttachToWindow method) or interactively if this panel is movable (see @ref #GetMovableFlag method).
 * If, while moving a panel, you position the mouse cursor over an edge of another panel and you release the mouse button, 
 * the moved Panel will form a group of Panels with the target one, making them dependant from each other for future 
 * interactions (move, resize ...)
 *
 * @par Panel docking
 *
 * A CATVidFraPanel can be docked in one of the docking areas of its parent window (Left, Right, Top or Bottom side),
 * either programmatically (see @ref #Dock method) or interactively.
 * 
 * If another window is already docked on the same area, the docked windows will be organized with tab pages.
 * By default, all the docking areas are allowed for a panel but you can restrict these allowed docking areas by calling
 * the method @ref #SetAllowedDockAreas. Call the methods @ref #Dock and @ref #Undock to dock or undock a panel programmatically.
 *
 * The following code is an example of a CATVidFraPanel use :
 * @code
 *   CATVidFraPanel * pPanel = new CATVidFraPanel(this, "PanelName");
 *   pPanel->SetApplicativeWidget(myWidget);
 *   pPanel->SetTitle("My title");
 *   pPanel->SetIconName("MyIcon.png");
 *   pPanel->SetCompactFlag(FALSE);
 *   pPanel->SetResizableFlag(TRUE);
 *   pPanel->SetAllowedDockAreas(CATVidFraWindow::DockAreas(CATVidFraWindow::LeftDockArea | CATVidFraWindow::RightDockArea));
 *   pPanel->SetVisibleFlag(TRUE);
 * @endcode
 */
class ExportedByVisuDialog CATVidFraPanel : public CATVidFraWindow
{
  CATDeclareClass;

public:

  /**
   * Constructs a CATVidFraPanel
   * @param i_pParent
   * Parent command
   * @param i_pIdentifier
   * Panel identifier ; this identifier is used to store the panel position and dimension in the 
   * user preferences to be restored in a future creation
   * @param i_hAlign
   * Specifies the preferred initial horizontal alignment of the panel
   * @param i_vAlign
   * Specifies the preferred initial vertical alignment of the panel
   *
   * @note The given horizontal and vertical alignment may be overridden in the following cases :
   *  - this panel is movable and has already been used in a previous session ; its last position has 
   *    been saved in the user preferences and will then be restored
   *  - the given alignments are in conflict with a currently displayed panel ; this panel will then be
   *    placed in the first available place (starting from these alignments) preventing any overlapping 
   *    with other panels
   */
  CATVidFraPanel(
        CATCommand *i_pParent, 
        const CATString& i_pIdentifier, 
        CATVidHAlignment i_hAlign = CATVidHAlignRight, 
        CATVidVAlignment i_vAlign = CATVidVAlignTop);

  /**
   * Default constructor, used internally.
   */
  CATVidFraPanel();

  /**
   * Specifies whether the window content is visible (expanded) or not (collapsed).
   * By default, the ContentVisibleFlag property is set to TRUE.
   * The window content can be hidden only if the window is collapsible, ie if 
   * the CollapsibleState property is equal to TRUE.
   *
   * @see GetContentVisibleState
   * @see SetCollapsibleFlag
   * @see GetCollapsibleState
   */
  void SetContentVisibleFlag(CATBoolean i_visible);

  /**
   * Specifies whether the window is collapsible, i.e if the window content can be hidden or shown by the user, or not.
   * By default, the CollapsibleFlag property is set to TRUE.
   */
  void SetCollapsibleFlag(CATBoolean i_flag);

  /**
   * Returns TRUE if the window is collapsible, i.e if the window content can be hidden or shown by the user, FALSE otherwise.
   * Note that the collapsible state depends on this flag but also on the current window place (docked, undocked ...).
   * By default, the CollapsibleFlag property is set to TRUE.
   * @see GetCollapsibleState
   */
  CATBoolean GetCollapsibleFlag() const;

  /**
   * Sets the areas of the main parent window where this window can be docked.
   * By default, all the docking areas are allowed.
   * Example of code modifying the allowed docking areas of a CATVidFraPanel :
   * @code
   *   pPanel->SetAllowedDockAreas(CATVidFraWindow::DockAreas(CATVidFraWindow::LeftDockArea | CATVidFraWindow::RightDockArea));
   * @endcode
   * 
   * Example of code disabling the docking capability of a CATVidFraPanel :
   * @code
   *   pPanel->SetAllowedDockAreas(CATVidFraWindow::DockAreas(CATVidFraWindow::NoneDockArea));
   * @endcode
   */
  void SetAllowedDockAreas(CATVidFraWindow::DockAreas i_areas);

  /**
   * Specifies whether the window can be a floating one, i.e an undocked window, or not.
   * If i_floatableFlag is equal to FALSE and the window is floating, this method will try to dock the window to
   * the last used docking area.
   * By default, the FloatableFlag property is set to TRUE.
   * @see Undock
   */
  void SetFloatableFlag(CATBoolean i_floatableFlag);

  /**
   * Returns TRUE if the window can be a floating one, i.e an undocked window, 
   * FALSE otherwise.
   * By default, the FloatableFlag property is set to TRUE.
   * @see Undock
   */
  CATBoolean GetFloatableFlag() const;

  /**
   * Specifies whether the window has the strong snapping capability, i.e can be attached to another one, or not.
   * By default, the SnappableFlag property is set to TRUE.
   * @see CanBeSnapSource
   */
  void SetSnappableFlag(CATBoolean i_snappableFlag);

  /**
   * Returns TRUE if the window has the strong snapping capability, i.e can be attached to another one,
   * FALSE otherwise.
   * By default, the SnappableFlag property is set to TRUE.
   * @see CanBeSnapSource
   */
  CATBoolean GetSnappableFlag() const;

  /**
   * Specifies whether the window can be automatically extracted when the end user drags it
   * outside its associated viewer and automatically inserted when it drags it inside it, or not.
   * By default, the AutoExtractableFlag property is set to TRUE.
   * @see GetAutoExtractableFlag
   * @see SetExtractedFlag
   */
  void SetAutoExtractableFlag(CATBoolean i_autoExtractableFlag);

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
   * Sets the button to call when ENTER key is pressed and released 
   * while one of child widgets of this window has the focus.
   * @see #GetDefaultButton
   * @see #SetEscapeButton
   */
  void SetDefaultButton(CATVidCtlButton * i_pButton);

  /**
   * Returns the button that will be called when ENTER key is press and released
   * while one of child widgets of this window has the focus.
   *
   * @return a pointer on the button. Note that @ref CATBaseUnknown#AddRef
   * has NOT been called on the returned value. It must not be released.<br/>
   * The returned value is @c NULL if there is no default button.
   * @see #SetDefaultButton
   * @see #GetEscapeButton
   */
  CATVidCtlButton * GetDefaultButton();

  /**
   * Sets the button to call when ESCAPE key is pressed and released 
   * while one of child widget of this window has the focus.
   * @see #GetEscapeButton
   * @see #SetDefaultButton
   */
  void SetEscapeButton(CATVidCtlButton * i_pButton);

  /**
   * Returns the button that will be called when ESCAPE key is press and released
   * while one of child widget of this window has the focus.
   *
   * @return a pointer on the button. Note that @ref CATBaseUnknown#AddRef
   * has NOT been called on the returned value. It must not be released.<br/>
   * The returned value is @c NULL if there is no default button.
   *
   * @see #SetEscapeButton
   * @see #GetDefaultButton
   */
  CATVidCtlButton * GetEscapeButton();

  /**
   * Sets the header widget.
   * The header widget is an optional widget that is placed between the panel title bar and 
   * its applicative widget.
   */
  void SetHeaderWidget(CATVidWidget * i_pHeaderWidget);

  /**
   * Returns the header widget.
   */
  CATVidWidget * GetHeaderWidget() const;

  /**
   * Specifies whether the window header must be visible or not.
   * By default, the HeaderVisibleFlag property is set to TRUE.
   * @see SetHeaderWidget
   */
  void SetHeaderVisibleFlag(CATBoolean i_headerVisibleFlag);

  /**
   * Returns TRUE if the window header must be visible, FALSE otherwise.
   * @see SetHeaderWidget
   */
  CATBoolean GetHeaderVisibleFlag() const;

  /**
   * Returns TRUE if the window header is visible, FALSE otherwise.
   * To be visible, the window header must have been set with the method SetHeaderWidget
   * and the HeaderVisibleFlag property must be set to TRUE.
   * @see SetHeaderVisibleFlag
   * @see SetHeaderWidget
   */
  CATBoolean GetHeaderVisibleState() const;
  /**
   * Sets the embedded preferences widget associated to the window.
   */
  void SetPreferencesWidget(CATVidWidget * i_pPreferencesWidget);

  /**
   * Returns the embedded preferences widget associated to the window.
   */
  CATVidWidget * GetPreferencesWidget() const;

  /**
   * Hides or shows preferences widget of the window.
   * The PreferencesWidget must have been set otherwise this method will fail.
   * By default, the ShowPreferencesFlag property is set to FALSE.
   */
  void SetShowPreferencesFlag(CATBoolean i_showPreferencesFlag);

  /**
   * Returns TRUE if the preferences widget of the window is visible, FALSE otherwise.
   */
  CATBoolean GetShowPreferencesFlag() const;

  /**
   * Hides or shows the 'ShowPreferences' button.
   * @param i_showPreferencesButtonFlag
   * the boolean controling the visibility of the 'ShowPreferences' button
   * By default, the ShowPreferencesButtonFlag property is set to TRUE.
   */
  void SetShowPreferencesButtonFlag(CATBoolean i_showPreferencesButtonFlag);

  /**
   * Returns TRUE if the 'ShowPreferences' button is visible, FALSE otherwise.
   */
  CATBoolean GetShowPreferencesButtonFlag() const;
  CATBoolean GetShowPreferencesButtonState() const;

  /**
   * Specifies whether the panel is pinned or not in its window group. It is only
   * relevant if the panel is in a WindowGroupAsTab.
   * When the docking panel is pinned, its content is always visible even if an other tab is selected.
   * By default, the PinnedFlag property is set to FALSE.
   */
  void SetPinnedFlag(CATBoolean i_pinnedFlag);
  CATBoolean GetPinnedFlag() const;

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
   * Sets the floating constraints used to position the window in its floating area.
   */
  void SetFloatConstraints(const CATVidLaySideAttachConstraints& i_constraints);

  /**
   * Returns the floating constraints used to position the window in its floating area.
   */
  const CATVidLaySideAttachConstraints& GetFloatConstraints() const;

  /**
   * Specifies the window type.
   * The authorized values are : CATVidImmersiveDialog, CATVidDockDialog or CATVidBottomFloatDialog.
   */
  void SetDialogType(CATVidDialogType i_dialogType);

  /**
   * Returns the window type.
   */
  CATVidDialogType GetDialogType() const;

  /**
  * Returns TRUE if the Panel is in customize mode, FALSE otherwise.
  */
  CATBoolean GetCustomizeFlag() const;

  /**
   * Specifies which animation is used when the window visibility property is changed.
   * @param i_VisibilityPolicy the visibility policy. 
   * Default value is ScaleAnimation.
   * The possible values for a CATVidFraPanel are :
   *     - ScaleAnimation
   *     - AlphaAnimation
   *     - NoAnimation
   * @see CATVidFraWindow#SetVisibleFlag
   * @see CATVid#VisibilityPolicy
   */
  void SetVisibilityPolicy(CATVid::VisibilityPolicy i_visibilityPolicy);

  // Implementation of the CATISYPPresenter interface
  void SetChild(CATBaseUnknown_var i_spToConnect);
  virtual CATBaseUnknown_var GetChild();
  
protected:

  virtual ~CATVidFraPanel();

  // Overriden methods
  virtual void WriteWindowPreferences();
  virtual HRESULT ReadWindowPreferences(CATBoolean i_positionAndDimensionOnly = FALSE);

private:

  virtual void Build();

  /**
   * @copydoc CATVidFraWindow#GetENTERButton
   * @note
   * Children class of this class must NOT override this function.
   * Instead they should use @ref #SetDefaultButton.
   */
  virtual CATVidCtlButton * GetENTERButton();

  /**
   * @copydoc CATVidFraWindow#GetESCButton
   * @note
   * Children class of this class must NOT override this function.
   * Instead they should use @ref #SetEscapeButton.
   */
  virtual CATVidCtlButton *GetESCButton();
};

#endif // CATVidFraPanel_h
