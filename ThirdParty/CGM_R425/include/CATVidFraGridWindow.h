#ifndef CATVidFraGridWindow_h
#define CATVidFraGridWindow_h

// COPYRIGHT Dassault Systemes 2012

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidFraWindow.h>
#include <CATVid.h>

// Mathematics framework
#include <CATMathPoint2Df.h>

// System framework
#include <CATBoolean.h>
#include <CATUnicodeString.h>

class CATVidCtlInteractiveWindowGrid;
class CATVidFraGridWindowGroup;
class CATVidLayGridConstraints;
class CATVidCtlDashboardPage;
class CATSYPEventArgs;
class CATVidDraggedEventArgs;
class CATSYPEventArgs;
class CATVidDroppedEventArgs;
class CATPixelImage;

/**
 * @ingroup VIDFrame
 * Class representing a window that can be used in an interactive grid.
 * 
 * @see CATVidCtlInteractiveWindowGrid
 */
class ExportedByVisuDialog CATVidFraGridWindow : public CATVidFraWindow
{
  CATDeclareClass;

public:

  /**
   * Constructs a CATVidFraGridWindow
   * @param i_pParent
   * Parent command
   * @param i_pIdentifier
   * window identifier ; this identifier is used to store the window position and dimension in the 
   * user preferences to be restored in a future creation
   * @param i_pInteractiveGrid
   * The interactive grid that will layout the window
   */
  CATVidFraGridWindow(
        CATCommand *i_pParent, 
        const CATString& i_pIdentifier,
        CATVidCtlInteractiveWindowGrid * i_pInteractiveGrid = NULL);

  /**
   * Default constructor, used internally.
   */
  CATVidFraGridWindow();

  /**
   * Sets the associated interactive grid.
   */
  void SetInteractiveGrid(CATVidCtlInteractiveWindowGrid * i_pInteractiveGrid);

  /**
   * Returns the associated interactive grid.
   */
  CATVidCtlInteractiveWindowGrid * GetInteractiveGrid() const;

  /**
   * Returns the dashboard page containing the grid window.
   */
  CATVidCtlDashboardPage * GetDashboardPage() const;

  /**
   * Sets the dashboard page containing the grid window.
   */
  void SetDashboardPage(CATVidCtlDashboardPage * i_pDashboardPage);

  /**
   * Sets the window grid constraints.
   */
  void SetGridConstraints(const CATVidLayGridConstraints& i_gridConstraints);
  const CATVidLayGridConstraints& GetGridConstraints() const;

  /**
   * Sets the weight for the column corresponding to the window grid constraints.
   */
  void SetColumnWeight(float i_columnWeight);
  float GetColumnWeight() const;
  
  /**
   * Sets the weight for the row corresponding to the window grid constraints.
   */
  void SetRowWeight(float i_rowWeight);
  float GetRowWeight() const;

  /**
   * Specifies whether the window content is visible (expanded) or not (collapsed).
   * By default, the ContentVisibleFlag property is set to TRUE.
   *
   * @see GetContentVisibleState
   */
  void SetContentVisibleFlag(CATBoolean i_visible);

  /**
   * Specifies whether the window can be maximized or not.
   * By default, the MaximizableFlag property is set to TRUE.
   * @see SetMaximizedFlag
   */
  void SetMaximizableFlag(CATBoolean i_maximizableFlag);

  /**
   * Returns TRUE if the window can be maximized, FALSE otherwise.
   */
  CATBoolean GetMaximizableFlag() const;

  /**
   * Specifies whether the window is maximized or not.
   * When a window is maximized, it appears on top of the other windows
   * and takes all the available space of its associated interactive grid.
   * @param i_maximizedFlag
   * The boolean allowing to maximize or restore the window.
   * @see SetMaximizableFlag
   */
  void SetMaximizedFlag(CATBoolean i_maximizedFlag);

  /**
   * Hides or shows the 'Maximize' button.
   * @param i_maximizeButtonFlag
   * the boolean controling the visibility of the 'Maximize' button
   * By default, the MaximizeButtonFlag property is set to TRUE.
   */
  void SetMaximizeButtonFlag(CATBoolean i_maximizeButtonFlag);

  /**
   * Returns TRUE if the 'Maximize' button is visible, FALSE otherwise.
   * This method returns TRUE if both the MaximizeButtonFlag and MaximizableFlag properties
   * are set to TRUE.
   */
  CATBoolean GetMaximizeButtonState() const;

  /**
   * Specifies whether the grid window is pinned or not.
   * When the window is pinned, it is displayed on top of the maximized grid window.
   * By default, the PinnedFlag property is set to FALSE.
   * @see SetMaximizedFlag
   */
  void SetPinnedFlag(CATBoolean i_pinnedFlag);

  /**
   * Returns TRUE if the grid window is pinned, FALSE otherwise.
   */
  CATBoolean GetPinnedFlag() const;

  /**
   * Hides or shows the 'Pin' button.
   * @param i_pinButtonFlag
   * the boolean controling the visibility of the 'Pin' button
   * By default, the PinButtonFlag property is set to TRUE.
   */
  void SetPinButtonFlag(CATBoolean i_pinButtonFlag);

  /**
   * Returns TRUE if the 'Pin' button is visible, FALSE otherwise.
   */
  CATBoolean GetPinButtonFlag() const;
  CATBoolean GetPinButtonState() const;

  /**
   * Specifies whether the window can be automatically extracted when the end user drags it
   * outside its associated interactive grid and automatically inserted when it drags it inside it, or not.
   * By default, the AutoExtractableFlag property is set to TRUE.
   * @see GetAutoExtractableFlag
   * @see SetExtractedFlag
   */
  void SetAutoExtractableFlag(CATBoolean i_autoExtractableFlag);

  /**
   * Moves the grid window to the given side of the target grid window.
   * The two grid windows will be contained in the same dashboard page and in the same interactive grid.
   */
  void MoveTo(CATVidFraGridWindow * i_pTargetGridWindow, CATVid::SnapAlignment i_snapAlignment);

  /**
   * Specifies whether the window has the strong snapping capability, i.e can be grouped with another one, or not.
   * By default, the SnappableFlag property is set to TRUE.
   * @see CanBeSnapSource
   */
  void SetSnappableFlag(CATBoolean i_snappableFlag);

  /**
   * Returns TRUE if the window has the strong snapping capability, i.e can be grouped with another one,
   * FALSE otherwise.
   * By default, the SnappableFlag property is set to TRUE.
   * @see CanBeSnapSource
   */
  CATBoolean GetSnappableFlag() const;

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
   * Specifies the index of the widget to display in the control.
   * @param i_index
   * The index of the widget to display.
   * Valid values are :
   *    0 : the first embedded widget
   *    1 : the second embedded widget
   */
  void SetDisplayedWidgetIndex(int i_displayedWidgetIndex);

  /**
   * Returns the index of the widget to display in the control.
   */
  int GetDisplayedWidgetIndex() const;

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
   * Returns the group containing the grid window or NULL if no such group exists.
   * @see GetAttachedToGroupFlag
   */
  CATVidFraGridWindowGroup * GetGridWindowGroup() const;

  /**
   * Returns the active grid window.
   */
  static CATVidFraGridWindow * GetActiveGridWindow();

  /**
   * Returns TRUE if the 'Menu' button is visible, FALSE otherwise.
   */
  CATBoolean GetMenuButtonState() const;

  /**
   * Returns the title bar minimum dimension.
   */
  CATMathPoint2Df GetTitleBarMinimumDimension() const;

  /**
   * Returns a preview image of the window.
   */
  CATPixelImage * ComputePreviewImage(const CATMathPoint2Df& i_dimension, CATMathPoint2Df& o_dimension) const;

  // Implementation of the CATISYPPresenter interface
  void SetChild(CATBaseUnknown_var i_spToConnect);
  virtual CATBaseUnknown_var GetChild();

  void ShowPreferencesCB(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void ShowMenuCB(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void DraggedCB(CATBaseUnknown * i_pSender, CATVidDraggedEventArgs * i_pArgs);
  void DnDMoveCB(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void DroppedCB(CATBaseUnknown * i_pSender, CATVidDroppedEventArgs * i_pArgs);
  void ContextMenuCB(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

  void OnMaximizeAction(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  void OnDeleteAction(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  void OnPinAction(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

  /**
   * Returns the @c DashboardPageChanged event.
   * The @c DashboardPageChanged event is emitted whenever the window is
   * associated to a new dashboard page.
   * @par EventProperties
   *   - Name: @c "DashboardPageChanged"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidDashboardPageChangedEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent * DashboardPageChanged();
  
protected:

  virtual ~CATVidFraGridWindow();

  // Overriden methods
  virtual void WriteWindowPreferences();
  virtual HRESULT ReadWindowPreferences(CATBoolean i_positionAndDimensionOnly = FALSE);

private:

  virtual void Build();

  friend class l_CATVidFraGridWindow;
};

#endif // CATVidFraGridWindow_h
