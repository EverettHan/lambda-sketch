#ifndef CATVidFraWindow_h
#define CATVidFraWindow_h

// COPYRIGHT Dassault Systemes 2009

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidInformation.h>
#include <CATVidColor.h>
#include <CATVid.h>
#include <CATVidEnum.h>

// Mathematics framework
#include <CATMathPoint2Df.h>

// IntrospectionInfrastructure framework
#include <CATSYPEnumBitField.h>
#include <CATSYPDeclareEnumFactory.h>

// System framework
#include <CATCommand.h>
#include <CATBoolean.h>
#include <CATVidColor.h>

class l_CATVidFraWindow;
class CATVidWidget;
class CATString;
class CATUnicodeString;
class CATVizViewer;
class CATVidCtlButton;
class CATSYPTemplateData;
class CATVidFraWindowGroup;
class CATSYPEvent;
class CATSYPEventArgs;
class CATSYPEventHandler;
class CATSYPEventFactory;
class CATVidMdlContextMenu;

/**
 * @ingroup VIDFrame
 * Base Class for an immersive window.
 * <b>Role</b>: A window is the object allowing to display any widget in a viewer.
 *
 * Create a window by using a construtor declared in one of the inherited class of CATVidFraWindow.
 *
 * To destroy a window you have to call the RequestDelayedDestruction method. 
 * You can listen to the death of a window by subscribing to the CATVID_BOX_DESTRUCTION_REQUESTED callback.
 * To ensure your pointer to an immersive window is still valid before use, it is recommended to use a weak ref 
 * on your window instance, by using the helper class CATBaseUnknown_WR.
 *
 * @par Styling your window
 * If you want to create a new style for a window containing the 'Minimize', 'Extract' or 'Close' buttons,
 * the corresponding "syp:named" objects must be the following ones in your ".sypstyle" file :
 *
 * @li MinimizeButton [CATVidCtlButton]
 * @li ExtractButton [CATVidCtlButton]
 * @li CloseButton [CATVidCtlButton]
 *
 * @see CATVidFraDialog
 * @see CATVidFraMessageBox
 * @see CATVidFraPanel
 */
class ExportedByVisuDialog CATVidFraWindow : public CATCommand
{
  CATDeclareClass;

  /**
   * Declares a Callback sent whenever RequestDelayedDestruction 
   * is called on the window.
   */
  CATDeclareCBEvent(CATVID_BOX_DESTRUCTION_REQUESTED);

public:

  /**
   * Possible policies used when a window is minimized.
   * @see SetMinimizeFlag
   */
  enum MinimizePolicy {SendMinimizeEventOnly = 0, MinimizeInMinimizeBar};

  /**
   * Possible areas to use to attach a window to another one.
   * @see AttachToWindow
   */
  enum SnapArea {
    NoneArea = 0, 
    OutsideArea,
    TopArea, 
    BottomArea, 
    LeftArea, 
    RightArea, 
    InsideArea
  };

  /**
   * Possible areas to use to dock a window to the main parent window.
   * @see Dock
   * @see GetCurrentDockArea
   * @see GetDockLevel
   */
  enum DockArea {
    /** The window is not docked */
    NoneDockArea    = 1, 
    /** Top area of the window docking level */
    TopDockArea     = 1<<1, 
    /** Bottom area of the window docking level */
    BottomDockArea  = 1<<2, 
    /** Left area of the window docking level */
    LeftDockArea    = 1<<3, 
    /** Right area of the window docking level */
    RightDockArea   = 1<<4
  };
  CATSYP_DECLARE_ENUM_BIT_FIELD(DockAreas, DockArea);

  /**
   * Possible levels to use to dock a window to the main parent window.
   * @see Dock
   * @see GetDockLevel
   */
  enum DockLevel {
    /** 
     * Strong window docking level.
     * This docking level surrounds the Overlay docking level and restricts the floating windows position to its center area.
     * This level is used by docked windows like toolbars.
     * In this level, the docked windows are ordered according to their docking priority.
     * @see GetDockPriority
     * @see CATVidFraToolbar
     */
    StrongDockLevel    = 0, 
    /**
     * Overlay window docking level.
     * This docking level is placed in the center area of the Strong window docking level.
     * The floating windows are not constrained in their position by the Overlay docking level
     * and can then overlap windows docked in this docking level.
     * In this level, the docked windows are organized inside tab pages.
     */
    OverlayDockLevel,
    /**
     * Docking level corresponding to the restricted area.
     * This docking level is placed in the borders of the restricted area. The restricted area is used by 
     * the layout of the floating windows whose UseRestrictedAreaState property is equal to TRUE.
     * This area consists in the center area of the Overlay docking layout.
     * This level is reserved to the CATVidFraContextBar.
     */
    RestrictedAreaDockLevel
  };

  /**
   * Possible policies to use to dock a window when other docked windows exist in the same dock area.
   * @see Dock
   */
  enum DockPolicy {
    /** 
     * Default dock policy : equal to DockInNewTabPage.
     */
    DefaultDockPolicy, 
    /** 
     * The docked window will be placed in a new dedicated tab page.
     */
    DockInNewTabPage, 
    /** 
     * The docked window will be attached to another docked window if possible 
     * (to the Bottom window side for Left and Right dock areas, to the Right window side for Top and Bottom dock areas).
     * If there is no existing docked window on which the attachment can be done, the docked window will be 
     * placed in a new dedicated tab page.
     */
    AttachToOtherDockedWindow
  };

  /**
   * Possible window corners.
   */
  enum WindowCorner {
    TopLeftCorner = 0,
    TopRightCorner,
    BottomLeftCorner,
    BottomRightCorner
  };

  /**
   * Possible icons used to display an informative message in a window.
   */
  enum ActionIcon { 
    /** No icon used */
    NoIcon = 0, 
    /** Icon indicating that the message is asking a question */
    Question, 
    /** Icon indicating that the message is purely informative */
    Information, 
    /** Icon indicating that the message is a warning, but can be dealt with */
    Warning, 
    /** Icon indicating that the message represents a critical problem */
    Critical,
    /** Icon indicating that the message represents a success */
    Successful
  };

  /**
   * Use this method to detroy a window. It will destroy the whole widget tree of the applicative widget.
   * @see GetApplicativeWidget
   */
  virtual void RequestDelayedDestruction();

  /**
   * Sets the embedded applicative widget.
   */
  void SetApplicativeWidget(CATVidWidget * i_pAplicativeWidget);

  /**
   * Returns the embedded applicative widget.
   */
  CATVidWidget * GetApplicativeWidget() const;

  /**
   * Sets the window life cycle.
   * @return S_OK if the operation is successful, E_FAIL otherwise.
   */
  HRESULT SetLifeCycle(CATVidLifeCycle i_lifeCycle);

  /**
   * Returns the window life cycle.
   */
  CATVidLifeCycle GetLifeCycle() const;

  /**
   * Sets the title of the window, displayed generally on the top of 
   * the window.
   * @param i_title
   * the title of the window.
   */
  void SetTitle(const CATUnicodeString& i_title);

  /**
   * Returns the title of the window.
   */
  const CATUnicodeString& GetTitle() const;

  /**
   * Sets the crop policy of the window title label
   * @param i_crop
   *   <br>
   *   <b>Legal values</b> : It can be set to either :
   *   <dl>
   *   <dt><tt>CATVid::NoCrop</tt><dd> : the minimum dimension of the title label is function of the label dimension
   *   <dt><tt>CATVid::CropCut</tt><dd> : the dimension of the title label is not function of the label dimension, the label is cutted
   *   <dt><tt>CATVid::CropWithDots</tt><dd> : the dimension of the title label is not function of the label dimension, the label is cutted with dots
   *   </dl>
   * By default, the TitleCropPolicy property is set to CATVid::CropWithDots.
   */  
  void SetTitleCropPolicy(CATVid::CropPolicy i_cropPolicy);

  /**
   * @return the crop policy of the window title label
   * @see SetTitleCropPolicy
   */  
  CATVid::CropPolicy GetTitleCropPolicy() const;

  /**
   * Returns TRUE if the title bar is visible, FALSE otherwise.
   */
  virtual CATBoolean GetTitleBarVisibleState() const;

  /**
   * Sets the name of the icon representing this window.
   * This icon may be displayed in the title bar of the window,
   * in the minimize bar when the window is minimized and in the docking tab page 
   * when the window is docked.
   * The expected icon dimension is 16x16 pixels (the old format 18x14 pixels is still supported).
   * @param i_iconName
   * The name of the icon, that is, the name of the resource located 
   * in the GraphicPath of the application.
   */
  void SetIconName(const CATUnicodeString& i_iconName);

  /**
   * Returns the icon name of the window.
   */
  const CATUnicodeString& GetIconName() const;

  /**
   * Specifies whether the window must display its icon in the title bar or not.
   */
  void SetShowIconInTitleBar(CATBoolean i_showFlag);

  /**
   * Returns TRUE if the window must display its icon in the title bar, FALSE otherwise.
   */
  CATBoolean GetShowIconInTitleBar() const;

  /**
   * Returns the dimension of the window icon.
   */
  CATMathPoint2Df GetIconDimension() const;

  /**
   * Sets the visibility flag of the window.
   * 
   * If a visible window is minimized or if it is contained in an invisible group, its VisibleFlag property
   * can still be equal to TRUE, but its VisibleState property will be equal to FALSE.
   * To check whether your window is visible or not, you can use the GetVisibleState method.
   * To ensure the window content is visible, you can call the @ref #EnsureVisible method.
   * 
   * The window is built the first time the method SetVisibleFlag is called ; the user preferences
   * are then read to restore the window properties that were modified by the end user during the last session
   * (position, dimension, expanded state, group attachment, docking area ...). If you want to specify
   * default values for these window properties, you must set these values before calling the SetVisibleFlag method.
   *
   * The texture used for the visibility animation is computed during the call to the SetVisibleFlag method ;
   * you must then ensure that the ApplicativeWidget has previously been set before calling SetVisibleFlag.
   *
   * @param i_visibleFlag the visibility of the window.
   *
   * @see GetVisibleState
   * @see GetContentVisibleState
   * @see EnsureVisible
   * @see VisibleStateChanged
   */
  void SetVisibleFlag(CATBoolean i_visibleFlag);

  /**
   * Returns the visibility flag of the window
   */
  CATBoolean GetVisibleFlag() const;
 
  /**
  * Sets if the window must be visible even if the document is deactivated.
  * @param i_visibleOnDocumentDeactivatedFlag the visibility of the window when the document is deactivated
  */
  void SetVisibleOnDocumentDeactivatedFlag(CATBoolean i_visibleOnDocumentDeactivatedFlag);
  
  /**
  * Returns TRUE if the window is visible even if the document is deactivated
  */
  CATBoolean GetVisibleOnDocumentDeactivatedFlag() const;
  /**
   * Returns TRUE if the window is visible, FALSE otherwise.
   * A window is considered as visible to the user when all the 
   * following conditions are fulfilled : 
   * @li the window has its VisibleFlag property set to TRUE
   * @li the window is not minimized
   * @li if the window is embedded in a group, the group is visible
   * @li if the window is docked, the docking window is expanded and the tab page 
   * containing the window is activated
   *
   * Note that a window can be visible but its content hidden, i.e its ContentVisibleState property
   * is equal to FALSE (for example if the window is collapsed or if it is embedded in 
   * a group in an inactive tab).
   * To ensure the window content is visible, you can call the @ref #EnsureVisible method.
   *
   * @see GetVisibleFlag
   * @see GetMinimizeFlag
   * @see GetWindowGroup
   * @see GetContentVisibleState
   * @see VisibleStateChanged
   */
  CATBoolean GetVisibleState() const;

  /**
   * @return which animation is used when the window visibility property is changed.
   * @see CATVidFraWindow#SetVisibleFlag
   * @see CATVid#VisibilityPolicy
   */
  CATVid::VisibilityPolicy GetVisibilityPolicy() const;

  /**
   * Returns TRUE if the window content is visible (expanded), FALSE otherwise (collapsed).
   * Only the collapsible windows can have their content collapsed.
   * @see GetCollapsibleState
   */
  CATBoolean GetContentVisibleFlag() const;

  /**
   * Returns TRUE if the window content is visible to the user, FALSE otherwise.
   * The content of a window is considered as visible to the user when all the 
   * following conditions are fulfilled : 
   * @li the window is visible
   * @li the window is not minimized
   * @li the window is expanded
   * @li if the window is docked, the docking window is expanded and the tab page 
   * containing the window is activated
   *
   * @see GetVisibleFlag
   * @see GetVisibleState
   * @see GetContentVisibleFlag
   * @see GetMinimizeFlag
   * @see ContentVisibleStateChanged
   */
  CATBoolean GetContentVisibleState() const;

  /**
   * @return which animation is used when the window content visibility property is changed.
   * @see CATVidFraWindow#GetContentVisibleFlag
   * @see CATVid#VisibilityPolicy
   */
  CATVid::VisibilityPolicy GetContentVisibilityPolicy() const;

  /**
   * Ensures that the window content is visible to the user.
   * This method calls SetVisibleFlag(TRUE) and add the following treatments :
   * @li if the window is minimized, this method restores it
   * @li if the window is collapsed, this method expands it
   * @li if the window is docked, this method ensures that the docking window is expanded
   * and it activates the tab page containing the window
   *
   * @see GetContentVisibleState
   * @see ContentVisibleStateChanged
   */
  void EnsureVisible();

  /**
   * Returns TRUE if the window is collapsible, i.e if the window content can be hidden or shown by the user, FALSE otherwise.
   * A CATVidFraPanel is collapsible but a CATVidFraDialog is not.
   */
  CATBoolean GetCollapsibleState() const;

  /**
   * Specifies whether the window uses margins or not.
   * By default, the UseMarginsFlag property is set to TRUE.
   */
  void SetUseMarginsFlag(CATBoolean i_useMarginsFlag);

  /**
   * Returns TRUE if the window uses margins, FALSE otherwise.
   */
  CATBoolean GetUseMarginsFlag() const;
  
  /** 
   * Returns the orientation of the window.
   * This orientation impacts the way the window will be collapsed (horizontally or vertically).
   */
  CATVid::Orientation GetOrientation() const;

  /**
   * Sets the minimize flag of the window. When an immersive window is minimized, 
   * it appears in a minimize bar located inside the viewer.
   * If a window is not visible, the minimize flag has no "visible" influence.
   * @param i_minimizeFlag
   * The boolean allowing to minimize or restore the window.
   *
   * @see GetContentVisibleState
   */
  void SetMinimizeFlag(CATBoolean i_minimizeFlag);

  /**
   * Returns TRUE if the window is minimized, FALSE otherwise.
   */
  CATBoolean GetMinimizeFlag() const;

  /**
   * Returns TRUE if the window is maximized, FALSE otherwise.
   * When an immersive window is maximized, it appears on top of the other windows
   * and takes all the floating area of its associated viewer.
   */
  CATBoolean GetMaximizedFlag() const;

  /**
   * Specifies whether the window can be extracted or not.
   * If SetExtractableFlag(FALSE) is called on an extracted window, the window will be
   * inserted in its associated viewer.
   * @see SetExtractedFlag
   */
  void SetExtractableFlag(CATBoolean i_extractableFlag);

  /**
   * Returns TRUE if the window can be extracted, FALSE otherwise.
   * By default, the ExtractableFlag property is set to TRUE.
   */
  CATBoolean GetExtractableFlag() const;

  /**
   * Returns TRUE if the window can be automatically extracted when the end user drags it
   * outside its associated viewer and automatically inserted when it drags it inside it,
   * FALSE otherwise.
   * By default, the AutoExtractableFlag property is set to TRUE for CATVidFraPanel and CATVidFraDialog,
   * and set to FALSE for the other types of CATVidFraWindow.
   * @see SetExtractedFlag
   */
  CATBoolean GetAutoExtractableFlag() const;

  /**
   * Sets the extracted flag of the window.
   *
   * @param i_extractedFlag
   * - TRUE to extract the window : this method will fail if the window is not extractable (see GetExtractableFlag).
   *   When an immersive window is extracted, a new Dialog frame is build around the window
   *   and it is no more immersive. The widgets inside the extracted window are not replaced.
   *   If the viewer inside which the window is inserted is destroyed, and that the 
   *   lifecycle of the window is not bound to it, the window will be automatically extracted.
   * - FALSE to insert it in its associated viewer (returned by GetViewer) if any,
   *   or in the active viewer if the lifecycle of the window is not bound to a particular viewer.
   *   If there is no Viewer or Active document, the call to SetExtractedFlag(FALSE) used to 
   *   insert the window in a viewer will fail.
   */
  void SetExtractedFlag(CATBoolean i_extractedFlag);

  /**
   * Returns the extracted flag of the window.
   */
  CATBoolean GetExtractedFlag() const;

  /**
   * Returns the extracted state of the window.
   * This method returns TRUE if the window has its extracted flag set to TRUE or
   * if it is contained in an extracted group, FALSE otherwise.
   * @see GetExtractedFlag
   * @see GetWindowGroup
   */
  CATBoolean GetExtractedState() const;

  /**
   * Sets the dimension of the window, by taking into account the minimum 
   * dimensions of the widget tree.
   * @param i_dimension
   * the wished dimension of the window. It will be limited by the 
   * minimum dimension of the applicative widget.
   * @see GetApplicativeWidget
   */
  void SetDimension(const CATMathPoint2Df &i_dimension);

  /**
   * Returns the dimension of the window.
   */
  const CATMathPoint2Df& GetDimension() const;

  /**
   * Sets the ability for a window to be moved by the end user.
   * @param i_movableFlag
   * TRUE if the window can be moved by the end user, FALSE otherwise.
   */
  void SetMovableFlag(CATBoolean i_movableFlag);

  /**
   * Returns the movable flag of the window.
   */
  CATBoolean GetMovableFlag() const;
  CATBoolean GetMovableState() const;

  /**
   * Sets the ability for the window to be resized by the end user.
   * @param i_resizableFlag
   * TRUE if the window can be resized by the end user, FALSE otherwise.
   * @warning A compact window is not resizable.
   * @see SetCompactFlag
   * @see GetResizableState
   */
  void SetResizableFlag(CATBoolean i_resizableFlag);

  /**
   * Returns the resizable flag of the window.
   */
  CATBoolean GetResizableFlag() const;

  /**
   * Returns TRUE if the window can be resized by the end user, FALSE otherwise.
   */
  CATBoolean GetResizableState() const;

  /**
   * Hides or shows the 'Minimize' button.
   * @param i_minimizeButtonFlag
   * the boolean controlling the visibility of the 'Minimize' button
   */
  void SetMinimizeButtonFlag(CATBoolean i_minimizeButtonFlag);

  /**
   * Returns TRUE if the 'Minimize' button is visible, FALSE otherwise.
   */
  CATBoolean GetMinimizeButtonFlag() const;
  CATBoolean GetMinimizeButtonState() const;

  /**
   * Returns TRUE if the 'Maximize' button is visible, FALSE otherwise.
   * By default, the 'Maximize' button is not visible.
   */
  CATBoolean GetMaximizeButtonFlag() const;

  /**
   * Hides or shows the 'Extract' button.
   * @param i_extractButtonFlag
   * the boolean controlling the visibility of the 'Extract' button
   */
  void SetExtractButtonFlag(CATBoolean i_extractButtonFlag);

  /**
   * Returns TRUE if the 'Extract' button is visible, FALSE otherwise.
   */
  CATBoolean GetExtractButtonFlag() const;
  CATBoolean GetExtractButtonState() const;

  /**
   * Hides or shows the 'Close' button.
   * @param i_closeButtonFlag
   * the boolean controlling the visibility of the 'Close' button
   */
  void SetCloseButtonFlag(CATBoolean i_closeButtonFlag);

  /**
   * Returns TRUE if the 'Close' button is visible, FALSE otherwise.
   */
  CATBoolean GetCloseButtonFlag() const;
  CATBoolean GetCloseButtonState() const;

  /**
   * Sets the window as active or inactive. 
   * Activating a window will deactivate the current activated window if any.
   * If the activated window is attached to a group, this method will also activate all
   * the windows contained in this group ; the GetActiveWindow method will then return the group.
   * The activated window has the keyboard focus.
   * @see GetActiveWindow
   */
  void SetActiveFlag(CATBoolean i_activeFlag);

  /**
   * Returns TRUE if the window is activated, FALSE otherwise.
   */
  CATBoolean GetActiveFlag() const;

  /**
   * Returns the current activated window if any, NULL otherwise.
   */
  static CATVidFraWindow * GetActiveWindow();

  /**
   * Specifies whether the window is vertically compact or not.
   * It will always fit its minimal height, while displaying all widgets it contains.
   * A vertically compact window can still be resized horizontally if its CompactFlag property
   * is set to FALSE and its ResizableFlag property to TRUE.
   */
  void SetVerticallyCompactFlag(CATBoolean i_compactFlag);

  /**
   * @return TRUE if the window is vertically compact, FALSE otherwise.
   * @see SetVerticallyCompactFlag
   */
  CATBoolean GetVerticallyCompactFlag() const;
  CATBoolean GetVerticallyCompactState() const;

  /**
   * Specifies whether the window is horizontally compact or not.
   * It will always fit its minimal width, while displaying all widgets it contains.
   * An horizontally compact window can still be resized vertically if its CompactFlag property
   * is set to FALSE and its ResizableFlag property to TRUE.
   */
  void SetHorizontallyCompactFlag(CATBoolean i_compactFlag);

  /**
   * @return TRUE if the window is horizontally compact, FALSE otherwise.
   * @see SetHorizontallyCompactFlag
   */
  CATBoolean GetHorizontallyCompactFlag() const;
  CATBoolean GetHorizontallyCompactState() const;

  /**
   * Sets the window as compact.
   * It will always fit its minimal dimension, while displaying all widgets it contains.
   * @warning A compact window will no longer be resizable.
   */
  void SetCompactFlag(CATBoolean i_compactFlag);

  /**
   * @return the CompactFlag, TRUE or FALSE.
   * @see SetCompactFlag
   */
  CATBoolean GetCompactFlag() const;
  CATBoolean GetCompactState() const;

  /**
   * Sets the opacity value of the window 
   * @param i_opacityValue
   * The opacity value.
   * <br><b>Legal values</b>: the opacity can be set from 0 (transparent)
   * to 255 (opaque)
   */
  void SetOpacity(unsigned int i_opacity);

  /**
   * Returns the opacity value
   */
  unsigned int GetOpacity() const;

  /**
   * Sets a palette name to the window. If a palette corresponding is found, the defined color role will be searched inside it.
   */
  void SetPaletteName(const CATUnicodeString& i_paletteName);
  /**
   * @return the palette name sets by the customer. Default is an empty string.
   */
  const CATUnicodeString& GetPaletteName()const;


  /**
   * Returns the panel horizontal alignment.
   * The horizontal alignment is used to compute the new window position when its containing viewer or
   * when its applicative widget is resized:
   *   * if the panel is left aligned, then on resize its left corners x coordinates will not change
   *   * if the panel is right aligned, then on resize its right corners x coordinates will not change
   */
  CATVid::Alignment GetHorizontalAlignment() const;

  /**
   * Returns the window vertical alignment.
   * The vertical alignment is used to compute the new window position when its containing viewer or
   * when its applicative widget is resized:
   *   * if the window is top aligned, then on resize its top corners y coordinates will not change
   *   * if the window is bottom aligned, then on resize its bottom corners y coordinates will not change
   */
  CATVid::VAlignment GetVerticalAlignment() const;

  /**
   * @copydoc CATISYPTemplate#SetTemplateName
   */
  void SetTemplateName(const CATUnicodeString& i_templateName);
  /**
   * @copydoc CATISYPTemplate#GetTemplateName
   */
  const CATUnicodeString& GetTemplateName() const;
  /**
   * @copydoc CATISYPTemplate#SetVariationName
   */
  void SetVariationName(const CATUnicodeString& i_variationName);
   /**
   * @copydoc CATISYPTemplate#GetVariationName
   */
  const CATUnicodeString& GetVariationName() const;
    /**
   * @copydoc CATISYPTemplate#SetTemplatedView
   */
  void SetTemplatedView(CATBaseUnknown_var& i_spView, CATSYPTemplateData* i_pTemplateData);
  /**
  * @copydoc CATISYPTemplate#GetTemplateDate
  */
  CATSYPTemplateData* GetTemplateData() const;

  /**
   * Brings the window on top of its layer.
   */
  void BringToFront();

  /**
   * Brings the window on bottom of its layer.
   */
  void BringToBack();

  /**
   * Returns the @c Closed event.
   * The @c Closed event is emitted whenever the window is closed.
   * @par EventProperties
   *   - Name: @c "Closed"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent *Closed();

  /**
   * Returns the @c Minimized event.
   * The @c Minimized event is emitted whenever the window is minimized.
   * @see SetMinimizeFlag
   * @par EventProperties
   *   - Name: @c "Minimized"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * Minimized();

  /**
   * Returns the @c Maximized event.
   * The @c Maximized event is emitted whenever the window is maximized.
   * @par EventProperties
   *   - Name: @c "Maximized"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * Maximized();

  /**
   * Returns the @c Restored event.
   * The @c Restored event is emitted whenever the window is restored from a minimized or maximized state.
   * @see SetMinimizeFlag
   * @par EventProperties
   *   - Name: @c "Restored"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * Restored();

  /**
   * Returns the @c Extracted event.
   * The @c Extracted event is emitted whenever the window is extracted.
   * @par EventProperties
   *   - Name: @c "Extracted"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * Extracted();

  /**
   * Returns the @c Inserted event.
   * The @c Inserted event is emitted whenever the window is inserted in the viewer.
   * @par EventProperties
   *   - Name: @c "Inserted"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * Inserted();

  /**
   * Returns the @c Activated event.
   * The @c Activated event is emitted whenever the window is activated.
   * @see SetActiveFlag
   * @par EventProperties
   *   - Name: @c "Activated"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * Activated();

  /**
   * Returns the @c Deactivated event.
   * The @c Deactivated event is emitted whenever the window is deactivated.
   * @see SetActiveFlag
   * @par EventProperties
   *   - Name: @c "Deactivated"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * Deactivated();

  /**
   * Returns the @c VisibleStateChanged event.
   * The @c VisibleStateChanged event is emitted whenever the window visiblity has changed.
   * @see SetVisibleFlag
   * @par EventProperties
   *   - Name: @c "VisibleStateChanged"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * VisibleStateChanged();

  /**
   * Returns the @c ContentVisibleStateChanged event.
   * The @c ContentVisibleStateChanged event is emitted whenever the window content visiblity has changed.
   * @see GetContentVisibleState
   * @par EventProperties
   *   - Name: @c "ContentVisibleStateChanged"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * ContentVisibleStateChanged();

  /**
   * Returns the @c PrePlaceChanged event.
   * The @c PrePlaceChanged event is emitted just before the window place is changed, i.e just before the window
   * is docked, undocked, maximized, extracted or inserted in the viewer. 
   * @par EventProperties
   *   - Name: @c "PrePlaceChanged"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidFraPrePlaceChangedEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   * @see PlaceChangedEvt
   */
  static CATSYPEvent * PrePlaceChanged();

  /**
   * Returns the @c PlaceChangedEvt event.
   * The @c PlaceChangedEvt event is emitted whenever the window place has changed, i.e when the window
   * is docked, undocked, maximized, extracted or inserted in the viewer. 
   * @par EventProperties
   *   - Name: @c "PlaceChangedEvt"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * PlaceChangedEvt();

  /**
   * Returns the @c OrientationChanged event.
   * The @c OrientationChanged event is emitted whenever the window orientation has been changed.
   * @par EventProperties
   *   - Name: @c "OrientationChanged"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * OrientationChanged();

  /**
   * Returns the @c MouseEnter event.
   * The @c MouseEnter event is emitted when the mouse enters the window
   * @par EventProperties
   *   - Name: @c "MouseEnter"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * MouseEnter();

  /**
   * Returns the @c MouseLeave event.
   * The @c MouseLeave event is emitted when the mouse leaves the window.
   * @par EventProperties
   *   - Name: @c "MouseLeave"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * MouseLeave();

  /**
   * Returns the @c DragStart event.
   * The @c DragStart event is emitted when the window starts to be dragged.
   * @par EventProperties
   *   - Name: @c "DragStart"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * DragStart();

  /**
   * Returns the @c Drag event.
   * The @c Drag event is emitted when the window is dragged.
   * @par EventProperties
   *   - Name: @c "Drag"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * Drag();

  /**
   * Returns the @c DragEnd event.
   * The @c DragEnd event is emitted when the window ends to be dragged.
   * @par EventProperties
   *   - Name: @c "DragEnd"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * DragEnd();

  /**
   * Returns the @c DimensionChanged event.
   * The @c DimensionChanged event is emitted whenever the window dimension is changed.
   * @par EventProperties
   *   - Name: @c "DimensionChanged"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * DimensionChanged();

  /**
   * @name Notifications
   */
  /*@{*/ 
  /**
   * Returns the notification sent when the window is closed.
   * @deprecated use the #Closed event instead.
   */
  CATNotification * GetCloseNotification() const;
  /**
   * Returns the notification sent when the window is minimized.
   * @deprecated use the #Minimized event instead.
   */
  CATNotification * GetMinimizeNotification() const;
  /**
   * Returns the notification sent when the window is maximized.
   * @deprecated use the #Maximized event instead.
   */
  CATNotification * GetMaximizeNotification() const;
  /**
   * Returns the notification sent when the window is restored from a minimized or maximized state.
   * @deprecated use the #Restored event instead.
   */
  CATNotification * GetRestoreNotification() const;
  /**
   * Returns the notification sent when the window is extracted.
   * @deprecated use the #Extracted event instead.
   */
  CATNotification * GetExtractNotification() const;
  /**
   * Returns the notification sent when the window is inserted in the viewer.
   * @deprecated use the #Inserted event instead.
   */
  CATNotification * GetInsertNotification() const;
  /**
   * Returns the notification sent when the window is activated.
   * @deprecated use the #Activated event instead.
   */
  CATNotification * GetSelectNotification() const;
  /**
   * Returns the notification sent when the window is deactivated.
   * @deprecated use the #Deactivated event instead.
   */
  CATNotification * GetDeactivateNotification() const;
  /**
   * Returns the notification sent when the window visiblity has changed.
   * @see SetVisibleFlag
   * @deprecated use the #VisibleStateChanged event instead.
   */
  const char* GetVisibleStateChangeNotification() const;
  /*@}*/ 

  /**
   * Inserts the window in the current active document.
   * If it is extracted, it will be inserted in the active document.
   * If it is immersive in another document, it will be moved from this one 
   * to the active one.
   * @see InsertInViewer
   */ 
  void InsertInActiveDocument();

  /**
   * Associates the window to the given viewer.
   * If it is extracted, it will stay extracted but the associated viewer will be changed.
   * If it is immersive in another viewer, it will be moved from this one 
   * to the given one.
   * @see GetViewer
   * @see InsertInActiveDocument
   */
  void InsertInViewer(CATVizViewer* i_pVizViewer);
  
  /**
   * Returns the associated viewer of the window.
   */
  CATVizViewer * GetViewer() const;
  
  /**
   * Returns the position of the window.
   * The returned coordinates are relative to the associated viewer (returned by GetViewer).
   */
  CATMathPoint2Df GetPosition() const;

  void SetMinimizePolicy(CATVidFraWindow::MinimizePolicy i_policy);
  CATVidFraWindow::MinimizePolicy GetMinimizePolicy () const;

  /**
   * Specifies whether the window must be automatically closed when the user clicks on a standard button with a role
   * equals to AcceptRole, RejectRole or DestructiveRole or on the close button of the title bar.
   * When the window is automatically closed, an internal call to RequestDelayedDestruction() is done
   * so the window is no longer usable.
   * By default, the AutoCloseFlag property is set to FALSE.
   */
  void SetAutoCloseFlag(CATBoolean i_autoCloseFlag);
  CATBoolean GetAutoCloseFlag() const;

  /**
   * Specifies whether the position of the window is limited to its viewer bounding rectangle,
   * whatever its contraints are, or not (in which case the window may be clipped).
   * By default the ConstraintUpdateAllowedFlag property is set to TRUE.
   */
  void SetConstraintUpdateAllowedFlag(CATBoolean i_constraintUpdateAllowedFlag);

  /**
   * Returns TRUE if the position of the window is limited to its viewer bounding rectangle,
   * whatever its contraints are, FALSE otherwise (in which case the window may be clipped).
   * By default the ConstraintUpdateAllowedFlag property is set to TRUE.
   */
  CATBoolean GetConstraintUpdateAllowedFlag() const;

  /**
   * Returns TRUE if the window can be snapped during move or resize to the given area
   * of the given target window, FALSE otherwise.
   * A CATVidFraPanel is snappable but a CATVidFraDialog is not.
   * @see AttachToWindow
   */
  CATBoolean CanBeSnapSource(CATVidFraWindow * i_pTargetWindow, CATVidFraWindow::SnapArea i_targetArea) const;

  /**
   * Returns TRUE if the window can be a snapping target at the given area for the given snappable window.
   * @see AttachToWindow
   */
  CATBoolean CanBeSnapTarget(CATVidFraWindow * i_pSourceWindow, CATVidFraWindow::SnapArea i_targetArea) const;

  /**
   * Returns the active snapping area.
   */
  CATVidFraWindow::SnapArea GetActiveSnapArea() const;

  /**
   * Attaches the window to the given area of the given target window.
   * The attached windows will be contained in a CATVidFraWindowGroup.
   * This method will fail if the window cannot be a snapping source for the given 
   * target window and the given area.
   * @see CanBeSnapSource
   * @see CanBeSnapTarget
   * @see GetWindowGroup
   */
  HRESULT AttachToWindow(CATVidFraWindow * i_pTargetWindow, CATVidFraWindow::SnapArea i_targetArea, CATBoolean i_beforeTargetWindow = FALSE);

  /**
   * Returns the group containing the window or NULL if no such group exists.
   * @see GetAttachedToGroupFlag
   */
  CATVidFraWindowGroup * GetWindowGroup() const;

  /**
   * Returns TRUE if the window is attached to a group, FALSE otherwise.
   */
  CATBoolean GetAttachedToGroupFlag() const;

  /**
   * Returns TRUE if the window is docked, attached to a group or maximized, FALSE otherwise.
   */
  CATBoolean GetEmbeddedState() const;

  /**
   * Returns the areas of the main parent window where this window can be docked.
   * A CATVidFraPanel can be dockable but a CATVidFraDialog cannot.
   * @see Dock
   */
  CATVidFraWindow::DockAreas GetAllowedDockAreas() const;

  /**
   * Returns TRUE if the window can be a floating one, i.e an undocked window, 
   * FALSE otherwise.
   * @see Undock
   */
  CATBoolean GetFloatableState() const;

  /**
   * Specifies whether the window is horizontally stretchable or not, i.e. whether this window, when docked in a horizontal dock,
   * will take all the available width of the docking area.
   */
  void SetHorizontallyStretchableFlag(CATBoolean i_stretchableFlag);
  CATBoolean GetHorizontallyStretchableFlag() const;

  /**
   * Specifies whether the window is vertically stretchable or not, i.e. whether this window, when docked in a vertical dock,
   * will take all the available height of the docking area.
   */
  void SetVerticallyStretchableFlag(CATBoolean i_stretchableFlag);
  CATBoolean GetVerticallyStretchableFlag() const;

  /**
   * Returns TRUE if the window is currently stretchable, FALSE otherwise.
   * If the window is docked, this method will depend on the HorizontallyStretchableFlag or VerticallyStretchableFlag
   * property value (according to the docking area), otherwise it will return FALSE.
   * @see GetHorizontallyStretchableFlag
   * @see GetVerticallyStretchableFlag
   */
  CATBoolean GetStretchableState() const;

  /**
   * Returns TRUE if the window is docked to the main parent window, FALSE otherwise.
   * @see Dock
   * @see Undock
   */
  CATBoolean GetDockedFlag() const;

  /**
   * Returns the current docking area if the window is docked to the main parent window, or
   * CATVidFraWindow::NoneDockArea otherwise.
   * @see GetDockedFlag
   */
  CATVidFraWindow::DockArea GetCurrentDockArea() const;

  /**
   * If the window is docked, returns the docking index, else returns -1
   */
  int GetDockIndex() const;

  /**
   * Docks the window to the specified area of the main parent window.
   * According to the dock policy, the docked window will be placed in a new dedicated tab page (DockInNewTabPage)
   * or will be attached to another docked window if possible (AttachToOtherDockedWindow).
   * This method will fail if the given area is equal to CATVidFraWindow::NoneDockArea or does not
   * belong to the allowed docking areas of the window.
   * @param i_dockArea
   * The area where the window must be docked
   * @param i_dockPolicy
   * Policy to use to dock the window when other docked windows exist in the same dock area.
   * @param i_dockIndex
   * Index of the window in the tab of the docking area. Equal to -1 by default which means the window will placed at the end of the tab. 0 would mean the window will be docked as the first window of the tab.
   * @see GetAllowedDockAreas
   * @see DockPolicy
   */
  HRESULT Dock(CATVidFraWindow::DockArea i_dockArea, CATVidFraWindow::DockPolicy i_dockPolicy = CATVidFraWindow::DefaultDockPolicy, int i_dockIndex = -1);

  /**
   * Undocks the window from the main parent window and sets the window floating.
   * This method will fail if the GetFloatableState method returns FALSE.
   * @see GetFloatableState
   */
  HRESULT Undock();

  /**
   * Returns the docking level used to dock the window to the main parent window.
   * By default, the window docking level is equal to OverlayDockLevel.
   * @see Dock
   */
  CATVidFraWindow::DockLevel GetDockLevel() const;

  /**
   * Returns the docking priority used to compute the order of the docked windows 
   * in the StrongDockLevel layout.
   * The smaller the priority is, the closer to the center area the docked window is.
   * If two windows docked in the same area have the same priority, the last docked window will be
   * placed closer to the center area than the first one.
   * For example, if two windows are docked in the Left area, the window with the higher priority
   * will be placed on the Left of the other one.
   * By default, the DockPriority property is set to 0.
   * This property is not used in the OverlayDockLevel layout since in this level, 
   * the docked windows are organized inside tab pages.
   * @see GetDockLevel
   */
  int GetDockPriority() const;

  /**
   * Returns the color used for the active snapping edge.
   */
  CATVidColor GetSnapEdgeColor() const;

  /**
   * Returns TRUE if the top window border is visible, FALSE otherwise.
   */
  CATBoolean GetTopBorderVisibleState() const;

  /**
   * Returns TRUE if the bottom window border is visible, FALSE otherwise.
   */
  CATBoolean GetBottomBorderVisibleState() const;

  /**
   * Returns TRUE if the left window border is visible, FALSE otherwise.
   */
  CATBoolean GetLeftBorderVisibleFlag() const;
  CATBoolean GetLeftBorderVisibleState() const;

  /**
   * Returns TRUE if the right window border is visible, FALSE otherwise.
   */
  CATBoolean GetRightBorderVisibleFlag() const;
  CATBoolean GetRightBorderVisibleState() const;

  /**
   * Returns TRUE if the window uses an icon, FALSE otherwise.
   */
  CATBoolean GetUseIconFlag() const;

  /**
   * Returns TRUE if the window uses a background, FALSE otherwise.
   */
  CATBoolean GetUseBackgroundFlag() const;
  CATBoolean GetUseBackgroundState() const;

  /**
    * Returns TRUE if the window background is draggable, i.e if the window can be moved 
    * when the user is dragging the background, FALSE otherwise.
    */
  CATBoolean GetBackgroundDraggableFlag() const;

  /**
  * Returns TRUE if the title bar background is visible, FALSE otherwise.
  */
  CATBoolean GetTitleBarBackgroundVisibleFlag() const;

  /**
  * Returns TRUE if the title bar border is visible, FALSE otherwise.
  */
  CATBoolean GetTitleBarBorderVisibleFlag() const;

  /**
   * Returns TRUE if the window uses an anchor point and if this anchor point is visible, FALSE otherwise.
   * The anchor point visibility is dependent on the type of window (CATVidPhylactereDialog, CATVidFraLabel, ...) 
   * and on its location : if the window is docked or attached to a group, the anchor point will not be visible.
   * If a window is not visible, its anchor point is not visible either.
   * @see CATVidFraLabel
   */
  CATBoolean GetAnchorPointVisibleState() const;

  /**
   * Returns TRUE if the 'Top' handle used to resize the window is enabled, FALSE otherwise.
   */
  CATBoolean GetTopResizeHandleEnableState() const;
  /**
   * Returns TRUE if the 'Left' handle used to resize the window is enabled, FALSE otherwise.
   */
  CATBoolean GetLeftResizeHandleEnableState() const;
  /**
   * Returns TRUE if the 'Right' handle used to resize the window is enabled, FALSE otherwise.
   */
  CATBoolean GetRightResizeHandleEnableState() const;
  /**
   * Returns TRUE if the 'Bottom' handle used to resize the window is enabled, FALSE otherwise.
   */
  CATBoolean GetBottomResizeHandleEnableState() const;
  /**
   * Returns TRUE if the 'TopLeft' handle used to resize the window is enabled, FALSE otherwise.
   */
  CATBoolean GetTopLeftResizeHandleEnableState() const;
  /**
   * Returns TRUE if the 'TopRight' handle used to resize the window is enabled, FALSE otherwise.
   */
  CATBoolean GetTopRightResizeHandleEnableState() const;
  /**
   * Returns TRUE if the 'BottomLeft' handle used to resize the window is enabled, FALSE otherwise.
   */
  CATBoolean GetBottomLeftResizeHandleEnableState() const;
  /**
   * Returns TRUE if the 'BottomRight' handle used to resize the window is enabled, FALSE otherwise.
   */
  CATBoolean GetBottomRightResizeHandleEnableState() const;

  /**
   * Returns the letter of the window.
   * internal use only, l_CATVidFraWindow is private.
   */
  l_CATVidFraWindow& GetVidLetter() const {return *_pLetter;};

  /**
   * Returns the window corresponding to the given name in the specified viewer.
   * This method will also search in the list of ApplicationLC windows.
   * If the passed i_pVizViewer is NULL, this method will search in all the viewers.
   */
  static CATVidFraWindow * GetWindowFromName(CATVizViewer * i_pVizViewer, const CATString& i_pIdentifier);

  /**
   * Returns the window containing the given widget.
   */
  static CATVidFraWindow * GetContainingWindow(CATVidWidget * pWidget);

  /** @ingroup groupVidEvents
   * Add a handler for a given event.
   *
   * The handlers will be called in the order of their registration.
   *
   * If this function is called during the dispatch of an event, the
   * registered event handler won't be called for this dispatch but
   * will only be called for next dispatches.
   *
   * It is possible to call mutliple times this function with the same
   * event and the same handler instance. In that case there will be
   * multiple registrations; no checks are made for duplication (the
   * caller will have to call @ref #RemoveHandler multiple times).
   *
   * @par Method of an object
   * You may use @ref #AddCATSYPWRefMethEventHandler to add a handler
   * that calls a method of an object. For example:
   * @code
   * #include <CATSYPCheck.h>
   * #include <CATSYPWRefMethEventHandler.h>
   *
   * class CallbackObject : public CATBaseUnknown
   * {
   *   CATDeclareClass;
   * public:
   *   CallbackObject();
   *   ~CallbackObject();
   *   void Callback(CATBaseUnknown *i_pSender, MyEventArgs *i_pArgs);
   * };
   * CATImplementClass(CallbackObject, Implementation, CATBaseUnknown, CATNull);
   *
   * void MyClass::Init()
   * {
   *   ...
   *   MyWindow * const pWindow = ...;
   *   CallbackObject * const pCallbackObj = ...;
   *   // note: MyWidget::Evt event uses arguments of type MyEventArgs
   *   CHECK_TRUE(AddCATSYPWRefMethEventHandler(pWindow,
   *                                            MyWindow::Evt(), 
   *                                            pCallbackObj,
   *                                            &CallbackObject::Callback));
   *   ...
   * }
   * @endcode
   *
   * @par Window & Widget Events
   * Events on windows (@ref CATVidFraWindow) and events on widgets
   * (@ref CATVidWidget) both use the same event propagation
   * infrastructure (@ref CATSYPEvent) but do not belong to the same
   * object tree. As a consequence events on widgets are never
   * dispatched through windows, and events on windows are never
   * dispatch on widgets.
   *
   * @par
   * That is also why there are two different event factories, the one
   * for windows is returned by @ref CATVidFraWindow#GetEventFactory
   * and the one for widgets is returned by @ref
   * CATVidWidget#GetEventFactory.
   *
   * @param i_pEvent the event that we are interested in. Note that @c
   * AddRef will be called on the event. Can't be @c NULL.
   *
   * @param i_pHandler the handler to call. Can't be @c NULL. 
   * @c AddRef will be called on this pointer. Note that the type of 
   * @c CATSYPEventArgs supported by this handler will be compared to
   * the type of arguments of the event. It must be a super-type of
   * the one of the event.
   *
   * @param i_handleConsumedEvents @c !=0 if the handler should be
   * called for consumed events.
   *
   * @return @c !=0 if succeeded, @c 0 if failed to add handler due to
   * invalid input or internal error (in that case a @ref FAILURE has
   * been raised).
   *
   * @see #AddCATSYPStaticEventHandler
   * @see #AddCATSYPWRefMethEventHandler
   * @see #RemoveHandler 
   * @see #Dispatch
   */
  int AddHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents = 0);

  /** @ingroup groupVidEvents
   * Remove an handler for an event.
   *
   * If this function is called during the dispatch of an event, the
   * unregistered event handler will be called for this dispatch but
   * will not be called for next dispatches.
   *
   * If the same handler has been added multiple times, this function
   * removes the first found registration (starting the look up from
   * the most ancient registration).
   *
   * @param i_pEvent the event. Can't be @c NULL.
   *
   * @param i_pHandler the handler. Can't be @c NULL.
   *
   * @return @c !=0 if succeeded, @c 0 if failed to remove handler due
   * to invalid input or internal error (in that case a @ref FAILURE has
   * been raised) or if the handler was never registered for the given
   * event (in that case NO @ref FAILURE is raised, it is valid to do
   * so; this is important for auto-remove handlers).
   *
   * @see #AddHandler
   */
  int RemoveHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler);

  /** @ingroup groupVidEvents
   * Dispatch the event.
   *
   * The event will be dispatched in the tree of windows depending on
   * the propagation mode of the event (@ref
   * CATSYPEvent#GetPropagation).<br/>
   * When the propagation is @ref CATSYPEvent#OriginToRoot or @ref
   * CATSYPEvent#RootToOrigin, the path is built using @ref
   * CATVidFraWindow#GetFatherWindow (when the propagation is @ref
   * CATSYPEvent#NoPropagation, the path will only contain the
   * origin).
   *
   * The list of handlers that will be called will be frozen before
   * the first handler is called; as a consequence, changes in the
   * tree hierarchy or in the handlers for the event at each node
   * won't have any effect on the dispatch of this event (but will
   * have effect on next dispatches, even on dispatches that may be
   * triggered by handlers of this event).
   *
   * This call is synchronous; it is blocking until the dispatch is
   * ended.
   *
   * The dispatch is reentrant; it is safe to call @c Dispatch while
   * being called on a handler by another call to @c Dispatch. The
   * first @c Dispatch will simply be paused until the new @c Dispatch
   * has ended (@c Dispatch is synchronous) and then it will be
   * resumed an continue as expected.
   *
   * The event arguments instance will be passed to each handler; it
   * may be used to pass informations between handlers and/or to give
   * a result to the dispatch. Since the call of @c Dispatch is
   * synchronous, the caller may look at the state of the arguments
   * after the dispatch (for example after the dispatch the caller can
   * check if the event has been consumed).
   *
   * The origin on the event argument (@ref CATSYPEventArgs#GetOrigin)
   * must be either @c NULL or equal to this window. If @c NULL, it
   * will be positioned by this function to this window.
   *
   * Handlers are called in the order of their registration.<br/>
   *
   * When a hanlder consume the event (@ref CATSYPEventArgs#Consume),
   * the handlers that should have been called after it and that are
   * not registered to be called for consumed events are not
   * called.<br/>
   * This include the handlers on the same window. For example if two
   * handlers have been registered (with @c i_handleConsumedEvents=0)
   * on a widget for the same event and the first one consume the
   * event, the second one (in the order of registration) won't be
   * called.
   *
   * @par Sample
   * Assuming the event @c MyEvt of widget @c MyWindow uses arguments
   * of type @ref CATSYPEventArgs:
   * @code
   * CATVidFraWindow * const pOrigin = ...;
   *
   * // instantiate the arguments of the event
   * CATSYPEventArgs * const pEventArgs = 
   *   new CATSYPEventArgs(MyWindow::MyEvt());
   *
   * // dispatch the event
   * CHECK_TRUE(pOrigin->Dispatch(pEventArgs));
   *
   * // check if the event has been consumed
   * if (! pEventArgs->IsConsumed()) {
   *   ...
   * }
   *
   * // release the arguments
   * pEventArgs->Release();
   * @endcode
   * 
   * @param i_pArgs the arguments of the event to dispatch (the
   * dispatched event is retrieved using @ref
   * CATSYPEventArgs#GetEvent). @ref CATSYPEventArgs#GetOrigin must be
   * either this object or @c NULL.
   *
   * @return @c !=0 if the dispatch succeeded, @c 0 if failed.
   *
   * @see #AddHandler
   */
  int Dispatch(CATSYPEventArgs *i_pArgs);

  /** @ingroup groupVidEvents
   * Get the event factory to use to build windows' events.
   *
   * This function should be used through the @ref
   * CATImplementSYPEvent macro.
   *
   * @return the event factory. Never @c NULL.
   *
   * @see CATImplementSYPEvent
   */
  static CATSYPEventFactory *GetEventFactory();
  
  /**
   * Sets the command identifier.
   * @param iIdentifier
   *   The identifier to set to the command
   * @see CATCommand
   */
   void  SetName(CATString & iIdentifier);

  void MinimizeCB(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void MaximizeCB(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void ExtractCB(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void CloseCB(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void DragCB(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void ExpandCollapseCB(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

  // Deprecated, do not use
  void CloseCB(const CATUnicodeString &i_eventName, const CATBaseUnknown_var &i_input, CATBaseUnknown_var &o_output);
  void DragCB(const CATUnicodeString &i_eventName, const CATBaseUnknown_var &i_input, CATBaseUnknown_var &o_output);

	/**
	* Computes the density to use to display the window.
	*
	* @return the density of the immersive window if the window exists,
	* the default density to use in CID else. 
	*/
	float GetDensity() const;

	//---------------------------------------------------------------------------
  //                             Context menu
  //---------------------------------------------------------------------------
  /**
   * Each window can be enriched with a context menu, available on right
   * click on window title bar. At first call, if no context menu has been defined,
   * this getter calls @ref #BuildDefaultContextMenu and returns it.
   *
   * @return the not @c NULL current context menu associated to this 
   * window. @ AddRef has not been called on returned pointer.
   *
   * @see GiveContextMenu
   */
  CATVidMdlContextMenu * GetContextMenu();
  /**
   * @return the current context menu associated to this window title bar, @c NULL if
   * it has not been instanciated yet. @c AddRef has not been called on 
   * returned pointer.
   *
   * @see #GetContextMenu
   */
  CATVidMdlContextMenu * GiveContextMenu() const;
  /**
   * @return TRUE if a context menu has been defined on the window title bar, 
   * @c FALSE else.
   */
  CATBoolean HasAContextMenu() const;
	/**
   * A default context menu is already associated to this window title bar, available by 
   * calling @ref #GetContextMenu. Nonetheless, if you need to associate an
   * already instanciated context menu to the window title bar, you can do so by
   * calling this setter. @c AddRef will be called on input pointer; you
   * are responsible for releasing your own pointer.
   *
   * @param i_pMdlContextMenu a context menu to associate to the window.
   *
   * @see #GetContextMenu
   */
  void SetContextMenu(CATVidMdlContextMenu * i_pMdlContextMenu);

	/** 
   * Get the @c PreContextMenuRequired event. 
   *
   * @par
   * The @c PreContextMenuRequired event is emitted just before the
   * @c ContextMenuRequiredEvent, after a right click on the title bar of the window.
   * It is transmitted from the root widget to the origin @c CATVidGP 
   * of the @c CATVidGP#RightClick event.
   *
   * @par EventProperties
   *   @li Name: @c "PreContextMenuRequired"
   *   @li Type of propagation: @c RootToOrigin
   *   @li Type of argument: @ref CATVidMouseAndKeyboardEventArgs
   *
   * It allows a father widget of the window to take responsibility over
   * the context menu.
   * 
   * If this event is consumed on a window, the @c ContextMenuRequired
   * events of its children are never sent. You can fill-in and/or display
   * your own context menu instead (see @ref #DisplayContextMenuAtDefaultPosition).
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer. 
   *
   * @see ContextMenuRequired
   */
  static CATSYPEvent * PreContextMenuRequired();
  
  /** 
   * Get the @c ContextMenuRequired event. 
   *
   * @par
   * The @c ContextMenuRequired event is emitted on right click on the title bar of the window.
   * if the window has a not @c NULL context menu (see @ref #GetContextMenu). 
   * If you plan to fill-in the context menu dynamically, it must be created
   * empty beforehand.
   * 
   * @par EventProperties
   *   @li Name: @c "ContextMenuRequired"
   *   @li Type of propagation: @c OriginToRoot
   *   @li Type of argument: @ref CATVidMouseAndKeyboardEventArgs
   *
   * @par 
   * If the event is emitted because of a right click on the window, the 
   * arguments of the right click can be recovered by calling 
   * @ref CATVidMouseAndKeyboardEventArgs#GetMouseEventArgs. On that case,
   * @ref CATVidMouseAndKeyboardEventArgs#GetKeyboardEvent returns @c NULL.
   *
   * @par 
   * Else, the event is emitted because of a click on the context menu key on
   * windows. This keyboard event can be recovered by calling
   * @ref CATVidMouseAndKeyboardEventArgs#GetKeyboardEvent.
   * On that case, @ref CATVidMouseAndKeyboardEventArgs#GetMouseEventArg
   * returns @c NULL.
   *
   * @par Dynamic context menu 
   * If you listen to this event, you can fill-in the context menu just before
   * display. Still, you must have set an empty context menu or called
   * @ref #BuildDefaultContextMenu once to receive the event. If you do not
   * consume the event, the context menu will be displayed by the 
   * infrastructure just after you filled it.
   *
   * @par 
   * If you consume this event, the context menu will not be displayed by the 
   * infrastructure. This allows you to:
   * @li deactivate context menu on right click: do nothing when receiving the
   * event and display the context menu by yourself when you need it
   * (call #DisplayContextMenuAtDefaultPosition)
   * @li display the context menu at another position than the default one 
   * (call @ref #DisplayContextMenu).
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer. 
   *
   * @see PreContextMenuRequired
   */
  static CATSYPEvent * ContextMenuRequired();
 
  /** 
   * Get the @c ContextMenuHidden event. 
   *
   * @par
   * The @c ContextMenuHidden event is emitted just after the window displayed context
   * menu is hidden.
   * 
   * @par EventProperties
   *   @li Name: @c "ContextMenuHidden"
   *   @li Type of propagation: @c OriginToRoot
   *   @li Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer. 
   */
  static CATSYPEvent * ContextMenuHidden();

protected:

  CATVidFraWindow();
  CATVidFraWindow(CATCommand *i_pParent, const CATString & i_pIdentifier);
  virtual ~CATVidFraWindow();

  l_CATVidFraWindow* _pLetter;

  void Extract();
  virtual void Close();

  // Write/Read the window Preferences
  virtual void WriteWindowPreferences();
  virtual HRESULT ReadWindowPreferences(CATBoolean i_positionAndDimensionOnly = FALSE);

  virtual void Build();

  /**
   * Returns the button to call when ENTER key is pressed and released while one of 
   * child widget of this window has the focus.
   *
   * @note
   * The default implementation returns @c NULL, that means that ENTER key is
   * not handled.
   *
   * @note
   * When ENTER is pressed, the button receives an event indicating that SPACE 
   * is pressed. And when ENTER is released the button receives an event indicating 
   * that SPACE is released.
   *
   * @note
   * The class that overrides this method should also ensure that the returned
   * button has its default flag set (see @ref CATVidCtlButton#SetDefaultFlag).
   * This is not mandatory but it will ensure that the fact that this button is
   * a default one is clearly visible to the user.
   *
   * @return the button to call. @c NULL if there is no default button.
   * @see #GetESCButton
   */
  virtual CATVidCtlButton *GetENTERButton();

  /**
   * Returns the button to call when ESCAPE key is pressed and released while one of 
   * child widget of this window has the focus.
   *
   * @note
   * The default implementation returns @c NULL, that means that ESCAPE key is
   * not handled.
   *
   * @note
   * When ESCAPE is pressed, the button receives an event indicating that SPACE 
   * is pressed. And when ESCAPE is released, the button receives an event 
   * indicating that SPACE is released.
   *
   * @note
   * The class that overrides this method may also ensure that the returned
   * button has the "auto-default" flag (see @ref CATVidCtlButton#SetAutoDefaultFlag).
   * This is not mandatory but will make pressing ENTER while the button has the
   * focus press this button instead of pressing the default button (@ref #GetENTERButton).
   *
   * @return the button to call. @c NULL if there is no button associated with ESCAPE.
   * @see #GetENTERButton
   */
  virtual CATVidCtlButton *GetESCButton();

  /**
   * Called when the window is docked, undocked, maximized, extracted or inserted in the viewer. 
   * @see PlaceChangedEvt
   */
  virtual void PlaceChanged();

private:

private:

  CATUnicodeString _templateName;
  CATUnicodeString _variationName;

  friend class CATVidFraWindowManager;
  friend class l_CATVidFraWindow;
  friend class CATVidFraWindowGroup;
  friend class l_CATVidFraWindowGroup;
  friend class l_CATVidFraWindowGroupAsGrid;
  friend class l_CATVidFraWindowGroupAsTab;
  friend class l_CATVidFraDockingWindow;
  friend class CATVidFraDefaultDockOrganizer;
  friend class l_CATVidFraVisuDialogBox;
  friend class CATVidRecorder;
};

CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidFraWindow__MinimizePolicy);
CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidFraWindow__SnapArea);
CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidFraWindow__DockArea);
CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidFraWindow__DockLevel);
CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidFraWindow__WindowCorner);
CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidFraWindow__ActionIcon);

#endif // CATVidFraWindow_h
