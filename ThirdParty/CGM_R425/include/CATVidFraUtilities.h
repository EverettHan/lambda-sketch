#ifndef CATVidFraUtilities_H
#define CATVidFraUtilities_H

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidFraWindow.h>

// System framework
#include <CATBoolean.h>

class CATVidModelWidget;
class CATVidFraDialogBox;
class CATVizViewer;
class CATVidFraLayoutData;
class CATVidFraBoxProperties;
class CATVidLay2DSyncToViewpointConstraints;
class CATVidWidget;
class CATPixelImage;
class CATString;
class CATBaseUnknown;
class CATUnicodeString;
class CATVidPalette;

/**
 * Sets or adds a named palette, that can be used by any FraWindow by using its name.
 */
ExportedByVisuDialog 
void SetPaletteFromName(const CATUnicodeString& i_paletteName, const CATVidPalette& i_palette);
/**
 * Recovers a palette from its name.
 * @return 1 if the palette is defined, 0 otherwise.
 */
ExportedByVisuDialog 
int GetPaletteFromName(const CATUnicodeString& i_paletteName, CATVidPalette& o_palette);


/**
 * Creates a VID dialog box.
 * @param i_pApplicativeWidget
 * The applicative widget, that is the content of the dialog box
 * @param i_fraBoxProperties
 * Title, icon name, dialog type, dialog life cycle, and dialog style of the dialog box
 * @param i_fraLayoutData
 * The layout data for side attach layout and (/or) dock layout
 * @param i_pVizViewer
 * The viewer containing the created dialog box
 * @parma i_activateFlag
 * Specifies whether the created dialog box must be activated or not
 */
ExportedByVisuDialog 
CATVidFraDialogBox * CATVidCreateDialog(CATVidModelWidget* i_pApplicativeWidget, 
                                       const CATVidFraBoxProperties& i_fraBoxProperties, 
                                       const CATVidFraLayoutData& i_fraLayoutData, 
                                       CATVizViewer* i_pVizViewer = 0, 
                                       CATBoolean i_activateFlag = FALSE);

/**
 * Creates a VID dialog box.
 * @param i_name
 * The identifier of the dialog box
 * @param i_pApplicativeWidget
 * The applicative widget, that is the content of the dialog box
 * @param i_fraBoxProperties
 * Title, icon name, dialog type, dialog life cycle, and dialog style of the dialog box
 * @param i_fraLayoutData
 * The layout data for side attach layout and (/or) dock layout
 * @param i_pVizViewer
 * The viewer containing the created dialog box
 * @parma i_activateFlag
 * Specifies whether the created dialog box must be activated or not
 */
ExportedByVisuDialog 
CATVidFraDialogBox * CATVidCreateDialog(const CATString& i_name, 
                                        CATVidModelWidget* i_pApplicativeWidget, 
                                        const CATVidFraBoxProperties& i_fraBoxProperties, 
                                        const CATVidFraLayoutData& i_fraLayoutData, 
                                        CATVizViewer* i_pVizViewer = 0, 
                                        CATBoolean i_activateFlag = FALSE);

/**
 * Sets the visibility of the specified docking area of the given viewer.
 * @param i_side
 *  0 : left
 *  1 : top
 *  2 : right
 *  3 : bottom
 * @param i_showDockFlag
 * TRUE to show the docked side, FALSE to hide it
 */
ExportedByVisuDialog 
void CATVidSetShowDockFlag(unsigned int i_side, CATBoolean i_showDockFlag, CATVizViewer* i_pVizViewer);

/**
 * Returns the visibility of the specified docking area of the given viewer.
 * @params i_side
 *  0 : left
 *  1 : top
 *  2 : right
 *  3 : bottom
 */
ExportedByVisuDialog 
CATBoolean CATVidGetShowDockFlag(unsigned int i_side, CATVizViewer* i_pVizViewer);

/**
 * Specifies whether the content of the specified docking area of the given viewer is visible (expanded and pinned)
 * or not (collapsed and unpinned).
 * @param i_dockArea : specifies the docking area
 * @param i_visibleFlag : if TRUE the specified docking area is expanded and pinned, otherwise it is collapsed and unpinned
 * @param i_pVizViewer : the viewer containing the docking area
 * @param i_ignoreUserPreferences : if TRUE this method does not take into account the user preferences concerning 
 * this docking area collapsed state, otherwise if the end user has interactively set a collapsed state this method does nothing 
 */
ExportedByVisuDialog 
void CATVidSetDockContentVisibleFlag(CATVidFraWindow::DockArea i_dockArea, CATBoolean i_visibleFlag, CATVizViewer* i_pVizViewer, CATBoolean i_ignoreUserPreferences = TRUE);

/**
 * Returns TRUE if the content of the specified docking area of the given viewer is visible (expanded and pinned), 
 * FALSE otherwise (collapsed and unpinned).
 */
ExportedByVisuDialog 
CATBoolean CATVidGetDockContentVisibleFlag(CATVidFraWindow::DockArea i_dockArea, CATVizViewer* i_pVizViewer);

/**
 * Sets the width of the specified docking area of the given viewer.
 * params i_side
 *  0 : left
 *  1 : top
 *  2 : right
 *  3 : bottom
 */
ExportedByVisuDialog 
void CATVidSetDockWidth(unsigned int i_side, float i_width, CATVizViewer* i_pVizViewer);

/**
 * Returns the width of the specified docking area of the given viewer.
 * params i_side
 *  0 : left
 *  1 : top
 *  2 : right
 *  3 : bottom
 */
ExportedByVisuDialog 
float CATVidGetDockWidth(unsigned int i_side, CATVizViewer* i_pVizViewer);

/**
 * Activates the window, identified by the given name, which is docked 
 * in the specified docking area of the given viewer.
 * params i_side
 *  0 : left
 *  1 : top
 *  2 : right
 *  3 : bottom
 */
ExportedByVisuDialog
void CATVidActivateDockedTab(unsigned int i_side, CATVizViewer* i_pVizViewer, const CATString& i_name);

/**
 * Returns the identifier of the active docked window contained in the 
 * specified docking area of the given viewer.
 * params i_side
 *  0 : left
 *  1 : top
 *  2 : right
 *  3 : bottom
 */
ExportedByVisuDialog
CATString CATVidGetActivatedDockedTab(unsigned int i_side, CATVizViewer* i_pVizViewer);

/**
 * Specifies whether the immersive windows of the given viewer must be displayed or not.
 * windows with AlwaysVisibleFlag set to TRUE are not hidden.
 */
ExportedByVisuDialog
void CATVidSetShowDialogFlag(CATBoolean i_showDockFlag, CATVizViewer* i_pVizViewer);

/**
 * Returns TRUE if the immersive windows of the given viewer must be displayed, FALSE otherwise.
 */
ExportedByVisuDialog
CATBoolean CATVidGetShowDialogFlag(CATVizViewer* i_pVizViewer);

/**
* Set whether a window is always visible or not; such windows remains visible while calling #CATVidSetShowDialogFlag
* @param i_pIdentifier : window string identifier
* @param i_showFlag : if TRUE, the window is always shown, else it is hidden
* @param i_pVizViewer: Viewer in which window identified by 'i_pIdentifier' is displayed 
*
* @see #CATVidSetShowDialogFlag
*/
ExportedByVisuDialog
int CATVidSetWindowAlwaysVisibleFlag(const CATString & i_pIdentifier,CATBoolean i_showFlag, CATVizViewer* i_pVizViewer);

/**
 * Returns TRUE if the immersive windows of the given identifier and viewer must be displayed, FALSE otherwise.
 */
ExportedByVisuDialog
CATBoolean CATVidGetWindowAlwaysVisibleFlag(const CATString & i_pIdentifier, CATVizViewer* i_pVizViewer);

/**
 * Returns TRUE if user preferences exist for the window identified by the given name, FALSE otherwise.
 */
ExportedByVisuDialog
CATBoolean CATVidWindowPreferencesExist(const CATString & i_windowName);

/**
 * Sets the viewpoint layout constraints for the given widget.
 * If the widget is already in the viewpoint layout, this method will update its constraints.
 * There is NO need to call CATVidRemoveWidgetSyncWithViewpoint before calling CATVidAddWidgetSyncWithViewpoint.
 */
ExportedByVisuDialog
void CATVidAddWidgetSyncWithViewpoint(CATVidModelWidget* i_pApplicativeWidget, const CATVidLay2DSyncToViewpointConstraints& i_constraints, CATVizViewer* i_pVizViewer);

/**
 * Removes the given widget from the viewpoint layout.
 */
ExportedByVisuDialog
void CATVidRemoveWidgetSyncWithViewpoint(CATVidModelWidget* i_pApplicativeWidget, const CATVidLay2DSyncToViewpointConstraints& i_constraints, CATVizViewer* i_pVizViewer);

/**
 * Sets the current VID theme.
 */
ExportedByVisuDialog
void CATVidSetSYPTheme(const CATUnicodeString& i_theme);

/**
 * Create a @c CATPixelImage from a widget. If an opaque @c CATPixelImage is
 * required (RGB), the view of the widget will be composed with the 
 * background color of its viewer.
 * 
 * @param i_pWidget the widget from which an image must be taken.
 * @param i_opaque @c TRUE if the returned @c CATPixelImage must be opaque
 * (RGB), @c FALSE else (RGBA).
 * @param i_premultipliedImage @c TRUE if the returned @c CATPixelImage must 
 * be premultiplied, @c FALSE else.
 *
 * @return a @c CATPixelImage of the widget.
 */
ExportedByVisuDialog
CATPixelImage* CATVidCreatePixelImageFromWidget(CATVidWidget* i_pWidget, CATBoolean i_opaque = TRUE);

/**
  * Returns the widget that has the VID focus in the given viewer. 
  * This widget is the one on which the keyboard and mouse events will be dispatched.
  *
  * AddRef has NOT been called on the returned value.
  */
ExportedByVisuDialog
CATVidWidget * CATVidGetFocusedWidget(CATVizViewer * i_pVizViewer);

/*
* Reset CID focus. If a viewer is given as parameter, we reset the focus for this viewer
* else if no viewer is given, we reset focus for all viewers.
*/
ExportedByVisuDialog 
void ResetFocus(CATVizViewer * i_pVizViewer = NULL);

/**
  * This flag activates the touch-ready mode in CID. When activated, the size of all CID frames
  * and widgets will be multiplied by the touch factor to allow for easier touch interaction.
  *
  * Default value is @c FALSE.
  *
  * @return @c TRUE if CID is in touch-ready mode, @c FALSE else.
  *
  * @see CATVidGetTouchFactor
  */
ExportedByVisuDialog
CATBoolean CATVidGetTouchFlag();

/**
 * @param i_flag @c TRUE if CID is in touch-ready mode, @c FALSE else.
 *
 * @see CATVidGetTouchFlag
 */
ExportedByVisuDialog
void CATVidSetTouchFlag(const CATBoolean& i_flag);

/**
  * When the touch flag is activated, the size of all CID frames 
  * and widgets will be multiplied by the touch factor.
  *
  * Default value is <tt>1.25</tt>.
  *
  * @return the current touch factor
  *
  * @see CATVidGetTouchFlag
  */
ExportedByVisuDialog
float CATVidGetTouchFactor();

/**
 * @param i_factor multiplying factor for the size of widgets and frames in touch-ready mode.
 *
 * @see CATVidGetTouchFactor
 */
ExportedByVisuDialog
void CATVidSetTouchFactor(float i_factor);

/**
  * Get density factor to use in VID for specific viewer.
  *
  * It is by default the viewer density unless the density is forced
  * by environment variable.
  *
  * @param i_pVizViewer the viewer; can't be @c NULL.
  *
  * @return the density factor.
  */
ExportedByVisuDialog
float CATVidGetViewerDensity(CATVizViewer *i_pVizViewer);


ExportedByVisuDialog
void CATVidGetImmersiveWindowList(CATVizViewer * i_pVizViewer, CATSYPDynArray<CATVidFraWindow*>& o_list);



/**
 * Specifies whether the the specified docking area of the given viewer pinned pref should be ignored
 */
ExportedByVisuDialog
void CATVidSetDockIgnorePreferredPinnedFlag(CATVidFraWindow::DockArea i_dockArea, CATBoolean i_ignorePreferredPinnedFlag, CATVizViewer* i_pVizViewer);

#endif
