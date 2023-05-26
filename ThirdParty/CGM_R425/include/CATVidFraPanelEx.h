#ifndef CATVidFraPanelEx_h
#define CATVidFraPanelEx_h

// COPYRIGHT Dassault Systemes 2012

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidFraPanel.h>
#include <CATVidEnum.h>

// System framework
#include <CATBoolean.h>

// friendship protection
#undef CATVIATreeViewFrame
#undef CATVIATreeViewFrameCID
#undef CATAfrSmartCtl
#undef CATVidTstFraPanelEx
#undef private

/**
 * @ingroup VIDFrame
 * Class representing a CATVidFraPanel with extended capabilities.
 * 
 * Warning : the CATVidFraPanelEx class usage is restricted to a limited set of callers.
 * @see CATVidFraPanel
 */
class ExportedByVisuDialog CATVidFraPanelEx : public CATVidFraPanel
{
  CATDeclareClass;

public:

  /**
  * Constructs a CATVidFraPanelEx
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
  CATVidFraPanelEx(
    CATCommand *i_pParent,
    const CATString& i_pIdentifier,
    CATVidHAlignment i_hAlign = CATVidHAlignRight,
    CATVidVAlignment i_vAlign = CATVidVAlignTop);

  /**
   * Specifies whether the window is maximized or not.
   * When an immersive window is maximized, it appears on top of the other windows
   * and takes all the floating area of its associated viewer.
   * @param i_maximizedFlag
   * The boolean allowing to maximize or restore the window.
   */
  void SetMaximizedFlag(CATBoolean i_maximizedFlag);

  /**
   * Hides or shows the 'Maximize' button.
   * @param i_maximizeButtonFlag
   * the boolean controling the visibility of the 'Maximize' button
   */
  void SetMaximizeButtonFlag(CATBoolean i_maximizeButtonFlag);

  /**
   * Sets the docking level used to dock the window to the main parent window.
   * The authorized values are : StrongDockLevel and OverlayDockLevel.
   * By default, the window docking level is equal to OverlayDockLevel.
   */
  void SetDockLevel(CATVidFraWindow::DockLevel i_dockLevel);

  /**
   * Sets the docking priority used to compute the order of the docked windows 
   * in the StrongDockLevel layout.
   * The smaller the priority is, the closer to the center area the docked window is.
   * If two windows docked in the same area have the same priority, the last docked window will be
   * placed closer to the center area than the first one.
   * For example, if two windows are docked in the Left area, the window with the higher priority
   * will be placed on the Left of the other one.
   * By default, the DockPriority property is set to 0.
   * This property is not used in the OverlayDockLevel layout since in this level, 
   * the docked windows are organized inside tab pages.
   * @see SetDockLevel
   */
  void SetDockPriority(int i_priority);

  /**
   * Specifies whether the window uses a background or not.
   * By default, the UseBackgroundFlag property is set to TRUE.
   */
  void SetUseBackgroundFlag(CATBoolean i_useBackgroundFlag);

  /**
  * Specifies whether the window background is draggable, i.e if the window can be moved
  * when the user is dragging the background, or not.
  * By default, the BackgroundDraggableFlag property is set to FALSE.
  */
  void SetBackgroundDraggableFlag(CATBoolean i_backgroundDraggableFlag);

  /**
    * Specifies whether the window title bar can be made visible or not.
    * By default, the TitleBarVisibleFlag property is set to TRUE.
    * @see CATVidFraWindow::GetTitleBarVisibleState
    */
  void SetTitleBarVisibleFlag(CATBoolean i_titleBarVisibleFlag);

  /**
    * Returns TRUE if the window title bar can be made visible, FALSE otherwise.
    * By default, the TitleBarVisibleFlag property is set to TRUE.
    * @see CATVidFraWindow::GetTitleBarVisibleState
    */
  CATBoolean GetTitleBarVisibleFlag() const;

private:

  CATBoolean _backgroundDraggableFlag;

  /**
   * Default constructor, used internally.
   */
  CATVidFraPanelEx();

  virtual ~CATVidFraPanelEx();

  friend class l_CATVidFraDialog;
  friend class CATVIATreeViewFrame;
  friend class CATVIATreeViewFrameCID;
  friend class CATAfrSmartCtl;
  friend class CATVidTstFraPanelEx;
  friend class CATGraph;
  friend class VIDGeneralController;
  friend class CATVidCtlTstShowWindow;
  friend class CATCfgCEFPanel;
  friend class DeclarativeDesignerDocument;
  friend class CATCXPBehaviorEditorCmd;
  friend class IVCameraViewerFraPanelEx;
  friend class DELEPDMWindowManager;
  friend class CATGVCGeomCompareGenericCmd;
  friend class CAT3DPTradeOffStudyCmd;
  friend class CATBIMManagerCmd;
  friend class IVSectionOptionsDialog;
  friend class IVMeasureOptionsDialog;
  friend class CATVidDesignerPanel;
  friend class CATDiscoverFraPanelEx;
  friend class CATFLEditorImmersiveTreePanel;
  friend class DELMfgLandingPageManager;
  friend class CATSbuCompareTextPanel;
  friend class CATCrDVidColorProperties;
};

#endif // CATVidFraPanelEx_h
