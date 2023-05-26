#ifndef CATVidFraWindowGroup_h
#define CATVidFraWindowGroup_h

// COPYRIGHT Dassault Systemes 2011

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidFraWindow.h>
#include <CATVid.h>

// IntrospectionInfrastructure framework
#include <CATSYPDeclareEnumFactory.h>

// UIVCoreTools framework
#include <CATSYPArray.h>

// System framework
#include <CATBoolean.h>
#include <CATListPV.h>
#include <CATListOfFloat.h>
#include <CATListOfCATUnicodeString.h>

class CATString;

/**
 * @ingroup VIDFrame
 * Class representing a group of floating windows snapped to each other.
 * 
 * @see CATVidFraWindow
 */
class ExportedByVisuDialog CATVidFraWindowGroup : public CATVidFraWindow
{
  CATDeclareClass;

public:

  /**
   * Possible types for a window group.
   */
  enum GroupType {
    /** The group layouts its embedded windows in a grid */
    GroupAsGrid = 0, 
    /** The group layouts its embedded windows in a tab control */
    GroupAsTab
  };

  /**
   * Constructors
   */
  CATVidFraWindowGroup(CATVidFraWindowGroup::GroupType i_type = CATVidFraWindowGroup::GroupAsGrid);
  CATVidFraWindowGroup(CATCommand *i_pParent, const CATString & i_pIdentifier, CATVidFraWindowGroup::GroupType i_type = CATVidFraWindowGroup::GroupAsGrid);

  /**
   * Returns the group type.
   * @see AttachWindow
   */
  CATVidFraWindowGroup::GroupType GetGroupType() const;

  /**
   * Adds the given window to the group, by snapping it to the the specified area of the target window.
   * @param i_pWindowToAttach
   * The window to attach to the group ; the window must be snappable (@see CATVidFraWindow::CanBeSnapSource()) otherwise the method will return E_FAIL
   * @param i_pSnapTargetWindow
   * The target window on which the moved window will be snapped ; this window must belong to the group and must accept the 
   * window to attach for the specified area (@see CATVidFraWindow::CanBeSnapTarget()) otherwise the method will return E_FAIL
   * You can pass NULL if the group is empty
   * @param i_snapArea
   * The area of the target window on which the moved window will be snapped. The possible snapping areas are depending on the group type :
   *  - if the group is of type GroupAsGrid, the possible snapping areas are TopArea, BottomArea, LeftArea or RightArea.
   *  - if the group is of type GroupAsTab, the possible snapping area is InsideArea.
   * 
   * @see GetGroupType
   */
  HRESULT AttachWindow(
    CATVidFraWindow * i_pWindowToAttach,
    CATVidFraWindow * i_pSnapTargetWindow,
    CATVidFraWindow::SnapArea i_snapArea);

  /**
   * Removes the given window from the group.
   * Warning : this method may destroy the group if, once the removal is done, this group contains only one or zero embedded window.
   * @param i_pWindowToDetach
   * The window to detach
   */
  HRESULT DetachWindow(CATVidFraWindow * i_pWindowToDetach);

  /**
   * Retrieves the list of all the windows embedded in the group.
   */
  void GetEmbeddedWindows(CATListPV& o_windows) const;

  /**
   * Sets the list of the windows embedded in the group that are currently active.
   * This method only works for group of type GroupAsTab. For a GroupAsGrid group, this method does nothing.
   * All the windows passed as argument must already be embedded in the group.
   */
  HRESULT SetCurrentWindows(const CATSYPDynArray<CATVidFraWindow *>& i_windows);

  /**
   * Retrieves the list of the windows embedded in the group that are currently active.
   */
  void GetCurrentWindows(CATSYPDynArray<CATVidFraWindow *>& o_windows) const;

  /**
   * Specifies whether the window group content is visible (expanded) or not (collapsed).
   * By default, the ContentVisibleFlag property is set to TRUE.
   * The window group content can be hidden only if the window is collapsible, ie if 
   * the CollapsibleState property is equal to TRUE. 
   * Only the window groups of type GroupAsTab are collapsible.
   *
   * @see GetContentVisibleState
   * @see SetCollapsibleFlag
   * @see GetCollapsibleState
   */
  void SetContentVisibleFlag(CATBoolean i_visible);

  /**
   * Returns the requested minimum size of the tab bar buttons.
   * This method is only valid for group of type GroupAsTab.
   */
  int GetMinimumTabSize() const;

  /**
   * Returns the preferred size common to all the tab bar buttons.
   * This method is only valid for group of type GroupAsTab.
   */
  float GetPreferredTabSize() const;

  /**
   * Returns TRUE if the preferred size of the tab bar buttons is computed directly from the text of the button, FALSE otherwise.
   * This method is only valid for group of type GroupAsTab.
   */
  CATBoolean GetUsePreferredSizeFromTextFlag() const;

  /**
   * Returns the embedded preferences widget associated to the window.
   */
  CATVidWidget * GetPreferencesWidget() const;

  /**
   * Hides or shows preferences widget of the current window.
   * The PreferencesWidget must have been set on the current window otherwise this method will fail.
   * By default, the ShowPreferencesFlag property is set to FALSE.
   */
  void SetShowPreferencesFlag(CATBoolean i_showPreferencesFlag);

  /**
   * Returns TRUE if the preferences widget of the window is visible, FALSE otherwise.
   */
  CATBoolean GetShowPreferencesFlag() const;

  /**
   * Returns TRUE if the 'ShowPreferences' button is visible, FALSE otherwise.
   */
  CATBoolean GetShowPreferencesButtonState() const;

protected:

  virtual ~CATVidFraWindowGroup();

  // Overriden methods
  virtual void WriteWindowPreferences();
  virtual HRESULT ReadWindowPreferences(CATBoolean i_positionAndDimensionOnly = FALSE);
  virtual void Close();

  /**
   * Retrieves the embedded windows ordered according to their position in the grid.
   * @parma o_columns
   * The retrieved list of columns ; each column item consists in a pointer on a CATListPV 
   * containing the CATVidFraWindow pointers corresponding to this column.
   * The caller must delete these CATListPV pointers.
   */
  void _GetOrderedEmbeddedWindows(CATListPV& o_columns);

private:
  virtual void Build();
  void BuildDefaultProperties(CATVidFraWindowGroup::GroupType i_type);
  friend class l_CATVidFraWindow;
};

CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidFraWindowGroup__GroupType);

#endif // CATVidFraWindowGroup_h
