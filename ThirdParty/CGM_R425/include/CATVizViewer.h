#ifndef CATVizViewer_H
#define CATVizViewer_H
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATVisFoundation.h"

#include "CATCommand.h"
#include "CATVizCursor.h"
#include "list.h"
#include "CATViewerUtility.h"
#include "CATPickPathList.h"
#include "CATPickPath.h"
#include "CATProjectionType.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATBooleanDef.h"
#include "CATSysWidget.h"
#include "CATSysWidgetEx.h"
#include "CATBaseUnknown_WR.h"
#include "CATMagnifierEvent.h"

class CATGraphicWindow;
class CATManipulator;
class CATIndicator;
class CATViewpointEditor;
class CAT2DViewpointEditor;
class CAT3DViewpointEditor;
class CATViewerEvent;
class CATRepPath;
class CATNotification;
class CATDevice;
class CATDeviceEvent;
class CATKeybdEvent;
class CATIMEKeybdEvent;
class CATViewpoint;
class CAT2DViewpoint;
class CAT2DRep;
class CAT2DCustomRep;
class CAT2DBagRep;
class CAT3DViewpoint;
class CAT3DRep;
class CATColorMap;
class CATSupport;
class CATPixelImage;
class CATGraphicMaterial;
class CATKeyboardEvent;
class CATMouseEvent;
class CATIncrementEvent;
class CATMarshal;
class CAT3DLightSourceRep;
class CATVizDuration;
class CATVisInfiniteEnvironment;
class CATVisInfiniteEnvironmentOverload;
class CATVizContextualMenuHandler;
class CATVizStatusBarHandler;
class CATIVisuEventListener_var;
class CATVizPickOptions;
class CATMouseDevice;
class CATKeyboardDevice;
class CATSpaceDevice;
class CATViewer;
class CATVizBasePathElementRep;
class CATVizDisplayContext;
class CATVisuAnimationWeakRef;
class CATMathDirectionf;
class CATMathPointf;
class CATCallbackManager;
class VisTouchDevice;
class VisMonotouchDeviceEvent;
class VisMultitouchDeviceEvent;
class VisTouchViewerEvent;
class CATVisu3DViewpointAnimation;
class VisMultipipeConfiguration;
class VisWintabDevice;
class VisWintabDeviceEvent;
class CATVizDockingLayoutInfos;
class VisStylusDevice;
class VisStylusDeviceEvent;
class VisStylusVIDDeviceEvent;
class CATSpaceButtonEvent;

struct stack;
/** @nodoc */
struct ExportedByCATVisFoundation VP_token
{
  CATViewpoint* _VP;
  CATViewpointEditor* _VPE;
  CATCallback         _CB;

  /** @nodoc */
  VP_token(CATViewpoint* vp, CATViewpointEditor* vpe, CATCallback cb) { _VP = vp; _VPE = vpe; _CB = cb; };
};
/**
* Class to display Graphic Representations on the screen.
*
*/
class ExportedByCATVisFoundation CATVizViewer : public CATCommand
{
  friend class CATManipulator;
  friend class CATDrillSelector;
  CATDeclareClass;

public:
  /** @nodoc */
  CATDeclareCBEvent(VIEWER_UPDATE_FOR_RECORD);
  /** @nodoc */
  CATDeclareCBEvent(VIEWER_UPDATE);
  /** @nodoc */
  CATDeclareCBEvent(VIEWER_SELECTED);
  /** @nodoc */
  CATDeclareCBEvent(VIEWER_DESTROYED);
  /** @nodoc */
  CATDeclareCBEvent(VIEWER_MAINVIEWPOINT_CHANGED);
  /** @nodoc */
  CATDeclareCBEvent(VIEWER_BACKGROUND_CHANGED);
  /** @nodoc */
  CATDeclareCBEvent(VIEWER_BEGIN_VIEWPOINT_ANIMATION);
  /** @nodoc */
  CATDeclareCBEvent(VIEWER_END_VIEWPOINT_ANIMATION);
  /** @nodoc */
  CATDeclareCBEvent(VIEWER_BEGIN_VIEWPOINT_MANIPULATION);
  /** @nodoc */
  CATDeclareCBEvent(VIEWER_END_VIEWPOINT_MANIPULATION);
  /** @nodoc */
  CATDeclareCBEvent(VIEWER_VIEWMODE_CHANGED);
  // D6F
  /** @nodoc */
  CATDeclareCBEvent(VIEWER_MAGNIFIER_EVENT);
  /** @nodoc */
  CATDeclareCBEvent(VIEWER_MAGNIFIER_CONTEXTUAL_EVENT);
  // D6F

   /** @nodoc
   * SBP : (device split)
   */
  CATDeclareCBEvent(VIEWER_VIEWPOINTEDITOR_SET);

  /** @nodoc
  * JQT/JOV : (short help split)
  */
  CATDeclareCBEvent(VIEWER_UPDATE_MANIPULATOR);

  /** @nodoc */
  CATDeclareCBEvent(VIEWER_DO_PICKPATHLIST_SORT);

  /** @nodoc
  * AZX (New Quality Management)
  */
  CATDeclareCBEvent(VIEWER_QUALITY_CHANGED);

  /** @nodoc */
  CATDeclareCBEvent(VIEWER_TRANSFO_MODE_CHANGED);

  /** @nodoc
   * Callback sent when the viewer usable area has changed.
   * @see GetUsableArea
   */
  CATDeclareCBEvent(VIEWER_USABLE_AREA_CHANGED);

  /**
  * Constructs a CATVizViewer.
  * @param iFather
  * @param istyle
  * @param iwidth  Width in pixel
  * @param iheight Height in pixel
  * @param iViewerStyle
  *  Options of the viewer's behaviour. (Combinations of styles are alloyed)
  */
  CATVizViewer(const CATString& iName,
    const int iwidth = 400,
    const int iheight = 400,
    const CATViewerStyle iViewerStyle = NULL);


  // Destruction method:
  // -------------------
  //   The CATVizViewer class can t be built as a stand alone object. It must be
  //   inherited from to be efficient in displaying elements.

  virtual ~CATVizViewer();


  /** @nodoc */
  virtual CATCallbackManager* GetCallbackManager();

  /**
   * Adds a representation 2D in the main  CAT2DViewpoint.
   * <br>The representation will appear only at the next @href CATVizViewer#Draw
   * @param iRep
   *  The @href CAT2DRep to add
   */
  virtual void AddRep(CAT2DRep* iRep);

  /**
   * Removes a representation 2D from the main CAT2DViewpoint.
   *  The representation will disappear at the next @href CATVizViewer#Draw
   *   @param iRep the @href CAT2DRep to remove
   */
  virtual void RemoveRep(CAT2DRep* iRep);

  /**
   * Removes a representation 2D from the main CAT2DViewpoint.
   * The representation will appears at the next @href CATVizViewer#Draw
   * Use this method in the process of removing many representations
   *   @param iRep the @href CAT2DRep to remove
  */
  virtual void RemoveReps(CAT2DRep* iRep);

  /**
   * Updates the 2D viewpoint to take into account the removal of reps.
   * <br>Call that method after removing many representations with RemoveReps
   */
  virtual void End2DRemoveReps();

  /**
   * Adds a representation 3D in the Main 3D Viewpoint.
   * <br>The representation will appears only at the next CATVizViewer::Draw
   * @param iRep
   * The rep to Add
   */

  virtual void AddRep(CAT3DRep* iRep);

  /**
   * Removes a representation 3D from the main CAT3DViewpoint.
   * <br>The representation will appears at he next @href CATVizViewer#Draw
   * Use this method in the process of removing many representations
   * @param iRep
   * The 3D rep to remove
   */
  virtual void RemoveRep(CAT3DRep* iRep);

  /**
   * Removes a representation 3D from the Main CAT3DViewpoint to be visualized.
   * <br> The representation will appears at he next CATVizViewer::Draw
   * @param iRep
   * the 3D Rep to remove
   */
  virtual void RemoveReps(CAT3DRep* iRep);

  /**
   * Updates the 3D viewpoint to take into account the removal of reps.
   * <br>Call that method after removing many representations with RemoveReps
   */
  virtual void EndRemoveReps();

  /**
   * Adds a furtive representation in the Main CAT2DViewpoint.
   * <br><b>Role:</b>The furtive representation will be displayed
   * with the XOR color. See the @href #DrawElement method
   *  @param iRep
   *  the @href CAT2DRep to add
   */
  virtual void AddRepFurtive(CAT2DRep* iRep);

  /**
   * Removes a 2D furtive representation from Main 2D Viewpoint .
   *  @param iRep
   *  the @href CAT2DRep to remove
   */
  virtual void RemoveRepFurtive(CAT2DRep* iRep);

  /**
   * Removes a furtive representation from the Main 2D Viewpoint.
   * <br><b>Role:</b>The representation will disappear at the next @href CATVizViewer#Draw.
   * Use this method in the process of removing many representations.
   */

  virtual void RemoveRepsFurtive(CAT2DRep* iRep);

  /**
   * Updates the 2D viewpoint to take into account the removal of reps.
   * Call that method after removing many representations with RemoveRepsFurtive
   */
  virtual void End2DRemoveRepsFurtive();

  /**
   * Adds a 3D furtive representation in the main CAT3DViewpoint.
   * @param iRep
   * The 3D Rep to add
   */
  virtual void AddRepFurtive(CAT3DRep* iRep);

  /**
   * Removes a 3D furtive representation from main 3D Viewpoint.
   * @param iRep
   * The 3D Rep to remove
   */
  virtual void RemoveRepFurtive(CAT3DRep* iRep);

  /**
   * Removes a furtive representation from the main 3D Viewpoint.
   * <br>The representation will disappear at the next @href CATVizViewer#Draw
   * Use this method in the process of removing many representations
   * @param iRep
   * The 3D Rep to remove
   */
  virtual void RemoveRepsFurtive(CAT3DRep* iRep);

  /**
   * Updates the 3D viewpoint to take into account the removal of reps.
   * <br>Call that method after removing many representations with RemoveRepsFurtive
   */
  virtual void EndRemoveRepsFurtive();


  /**
    * Asks for generating a new "image" displayed in the Viewer's screen.
    * <br>
    * This image is composed of all representations attached to each viewpoint.
    * This image is not computed immediately but as soon as possible.
    */
  virtual void Draw();

  /**
   * Changes the Main Viewpoint to have all the repreentations visible on screen.
   */
  virtual void Reframe();

  /** @nodoc */
  virtual void ReframeAllViewpoints();

  /** @nodoc */
  virtual void ReframeOnGeometry();

  /** @nodoc */
  virtual void BeginDrawElement();

  /**
   * Draws a  CATRepPath without redrawing the entire screen .
   * <br> if the  @href CATRepPath is furtive. The  @href CATRepPath is drawn in XOR mode
   *  @param iPath
   * the  CATRepPath to redraw
  */
  virtual void DrawElement(CATRepPath& iPath);

  /** @nodoc */
  virtual void EndDrawElement(unsigned int saveRenderBuffer);

  /**
   * Draws a list of CATRepPath without redrawing the entire screen.
   *  if the  @href CATRepPath is furtive. The  @href CATRepPath is drawn in XOR mode
   * @param iPaths the list of  @href CATRepPath to redraw
   */
  virtual void DrawElements(::list<CATRepPath>& iPaths);

  /**
   * Undraws  a CATRepPath if it is Furtive .
   *  @param iPath the @href CATRepPath to undraw
   */
  virtual void UndrawElement(CATRepPath& iPath);

  /**
   * Undraws  a list of CATRepPath if they are Furtive .
   * @param iPaths the list of @href CATRepPath to undraw
   */
  virtual void UndrawElements(::list<CATRepPath>& iPaths);

  /**
   * Adds a new viewpoint in the Viewer's list with the highest/lowest priority.
   * The representations of this viewpoint will be displayed behind the other viewpoints
   * @param iViewpoint
   * the Viewpoint to add
   * @param iPlace
   * <b>Legal values</b>: Foreground and Background
   */
  void AddViewpoint(CATViewpoint* iViewpoint, const CATViewerPlacement iPlace);

  /**
   * Removes the viewpoint from the viewer's list.
   * @param iViewpoint
   * @href CATViewpoint to remove
   */
  void RemoveViewpoint(CATViewpoint* iViewpoint);


  /**
    * Sets the main viewpoint of the viewer.
    * @param viewpoint
    * the viewpoint that is to be manipulated by local transformations
    */
  virtual void SetMainViewpoint(CATViewpoint* viewpoint);

  /**
   * Gets the main CAT2DViewopint.
   * @return
   * the main @href CAT2DViewpoint
   */
  CAT2DViewpoint& GetMain2DViewpoint() const;

  /**
   * Gets the main CAT3DViewopint.
   * @return
   * the main @href CAT3DViewpoint
   */
  CAT3DViewpoint& GetMain3DViewpoint() const;

  /**
  * Gets the OverlayViewpoint.
  * <br><b>Role:</b>
  * This viewpoint is a @href CAT2DViewpoint displayed in front of any other representation
  * @return
  *  the overlay @href CAT2DViewpoint
  */
  CAT2DViewpoint& GetOverlayViewpoint() const;

  /**
   * Gets the main viewpoint.
   * <br>This viewpoint is the one being modified by local transformations
   */
  CATViewpoint& GetMainViewpoint() const;

  /**
   * Gets the V3D CAT3DViewpoint.
   * @return
   * the V3D @href CAT3DViewpoint
   */
  CAT3DViewpoint& GetV3DViewpoint() const;

  /**
   * Stores the Current MainViewpoint so that it can be restored later.
   */
  virtual void SaveViewpoint();

  /** Gets wether or not there is a viewpoint store before the current one.
   * @return the result of the test
   */
  virtual int IsPreviousViewpoint() const;

  /**
   * Restores the Viewpoint store before the current viepoint.
   */
  virtual void DisplayPreviousViewpoint();

  /**
  * Gets wether or not there is a viewpoint store after the current one.
  * @return the result of the test
  */
  virtual int IsNextViewpoint() const;

  /**
   * Restores the Viewpoint store after the current viepoint.
   */
  virtual void DisplayNextViewpoint();

  /**
   * Set the display context.
   */
  void SetDisplayContext(CATVizDisplayContext*);

  /**
   * Get the display context.
   */
  CATVizDisplayContext* GetDisplayContext();

  /** @nodoc */
  virtual void ZoomIn();

  /** @nodoc */
  virtual void ZoomOut();

  /**
   * Generates a CATPickPathList corresponding to all representations laying under
   *  the given position.
   *  @param  istyle
   *   A CATPickingStyle specifying the way the @href CATPickPathList is generated
   *  @param  ix
   *   The x coordinate of the position at wich we want to pick
   *  @param  iy
   *   The y coordinate of the position at wich we want to pick
   *  @param  idx
   *   The width in pixel
   *  @param  idy
   *   The height in pixel
   *  @param  oPlist
   *   The CATPickPathList generated
   *  @param  irepp
   *   The CATRepPath we want to pick on. If this parameter is NULL, we pick on all representations
   *  @param  ipolygon
   *   If the CATPickingStyle is CATPickingInsidePolygon, define the polygon used for the picking
   *  @param  inb_point
   *   If the CATPickingStyle is CATPickingInsidePolygon, define the number of points in the polygon
   *  @param  ipick_style
   *   The @href CATViewModeType used to do the picking
   *  @param  forceFullPick
   *   Set to false to enable VID picking optimization (picking may stop if a VID representation if found)
   *  @param ignoreNoPickFlag
   *   Set to true to include reps with no_pick flag set to true in picking result
   *
  */
  void Pick(const CATPickingStyle istyle, const float ix, const float iy, const float idx, const float idy, CATPickPathList& oPlist, CATRepPath* irepp = NULL, const float* ipolygon = NULL, const int inb_point = 0, const int ipick_style = 0, int forceFullPick = 1, int ignoreNoPickFlag = 0, int ipickOnlyDialog = 0);

  /**
   * Generates a CATPickPathList corresponding to all representations laying under
   *  the given position.
   *  @param  istyle      A CATPickingStyle specifying the way the @href CATPickPathList is generated
   *  @param  iorg        The Point from wich we pick
   *  @param  idir        The direction into wich we pick
   *  @param  ineard      The distance from iorg at wich we begin to pick
   *  @param  ifard       The distance from iorg at wich we stop to pick
   *  @param  oPlist      The @href CATPickPathList generated
   *  @param  irepp       The @href CATRepPath we want to pick on. If this parameter is NULL, we pick on all representations
   *  @param  ipick_style The @href CATViewModeType used to do the picking
   *  @param  forceFullPick Set to false to enable VID picking optimization (picking may stop if a VID representation if found)
   *  @param  ignoreNoPickFlag Set to true to include reps with no_pick flag set to true in picking result
  */
  void Pick(const CATPickingStyle istyle, const CATMathPointf& iorg, const CATMathDirectionf& idir, const float ineard, const float ifard, const float idx, const float idy, CATPickPathList& oPlist, CATRepPath* irepp = NULL, const int ipick_style = 0, int forceFullPick = 1, int ignoreNoPickFlag = 0, int includeDialogReps = 0, int iVIDPicking = 0);

  /**
   * same as above, but take an origin point with double precision
  */
  void Pick(const CATPickingStyle istyle, const CATMathPoint& iorg, const CATMathDirectionf& idir, const float ineard, const float ifard, const float idx, const float idy, CATPickPathList& oPlist, CATRepPath* irepp = NULL, const int ipick_style = 0, int forceFullPick = 1, int ignoreNoPickFlag = 0);

  /** @nodoc */
  void PickOnDialogGP(const float x, const float y, CATPickPathList& pickpath, int sense, CATSupport* ipSupport = NULL);

  /** @nodoc */
  void SetPickMode(const CATPickingStyle iStyle);

  /** @nodoc */
  CATPickingStyle GetPickMode() const;

  /** @nodoc */
  void SetPickWindowSize(int iPixelSize, int iFromSettings = 1);

  /** @nodoc */
  int  GetPickWindowSize() const;

  /** @nodoc */
  CATVizPickOptions& GetPickingOptions();

  /** @nodoc */
  void SetAccuratePickWindowSize(int iPixelSize, int iFromSettings = 1);

  /** @nodoc */
  int  GetAccuratePickWindowSize() const;

  /** @nodoc */
  void SetAccuratePickMode(int iOnOff, int iFromSettings = 1);

  /** @nodoc */
  int  GetAccuratePickMode() const;

  /** @nodoc */
  void SetAccuratePickOnDlgMode(int iOnOff);

  /** @nodoc */
  int  GetAccuratePickOnDlgMode() const;

  /** @nodoc */
  void SetPickOOCPointCloud(bool iOnOff);

  /** @nodoc */
  int  GetPickOOCPointCloud() const;

  /** @nodoc */
  void DoPickPathListSort(CATPickPathList& ioPickPathList);

  /** @nodoc */
  void SetHighlightMode(int iHighlightMode, int iFromSettings = 1);

  /** @nodoc */
  int GetHighlightMode() const;

  /** @nodoc */
  static CATVizViewer* GetCurrentViewer();

  /** @nodoc */
  static CATVizViewer* GetSelectedViewer();

  /** @nodoc */
  static void SetSelectedViewer(CATVizViewer*);

  /** @nodoc */
  static void SetCurrentViewer(CATVizViewer*);

  /** @nodoc */
  static void InitViewerClassList();

  /** @nodoc */
  static CATVizViewer* GetNextClassElement();

  /** @nodoc */
  CATPickPath& GetCurrentPath();

  /**
   * Sets the CATManipulator to activate on next mouse interaction.
   * @param iManip the @href CATManipulator to activate
   */
  void SetManipulatorToActive(CATManipulator* iManip);

  /**
  * Removes the CATManipulator to be activated.
  */
  void RemoveManipulatorToActive();

  /**
  * Gets the CATManipulator to activate.
  * @return  the @href CATManipulator to Activate
  */
  const CATManipulator* GetManipulatorToActive() const;

  /** @nodoc */
  void CheckAutomaticBehavior(CATDevice* ipDevice = NULL);

  /** @nodoc */
  ViewerInteractiveState GetInteractiveState() const;
  /** @nodoc */
  void SetInteractiveState(ViewerInteractiveState state);

  /** @nodoc */
  virtual void SetSaveIndicatorCursor(int iOnOff);

  /** @nodoc */
  virtual int GetSaveIndicatorCursor();


  /** @nodoc */
  void AddManipOnRepPath(CATVizBasePathElementRep* iPath);

  /** @nodoc */
  void RemoveManipOnRepPath(CATVizBasePathElementRep*);

  /**
   * Gets the size in pixel of the viewer.
   * @param owidth
   * @param oheight
   */
  void GetGraphicSize(float* owidth, float* oheight) const;

  /**
   * @nodoc
   * Retrieves the position and dimension of the usable area in the viewer.
   * By default, the usable area of a viewer is the entire viewer area, but it can be
   * modified by the VID infrastructure to specify the center area of the docking layout.
   * If the parameter i_strongDockingOnly is set to TRUE, this method will take into account
   * only the strong docking areas (e.g the Action Bar) and not the overlay docking areas (the areas
   * used by the VID panels).
   *
   * This usable area is used for example to position the reference axes in a 3D viewer.
   * @see GetGraphicSize
   */
  void GetUsableArea(float& o_x, float& o_y, float& o_width, float& o_height, CATBoolean i_strongDockingOnly = FALSE) const;

  /**
   * @nodoc
   * Sets the position and dimension of the usable area in the viewer.
   * This method should only be called by the VID infrastructure to specify
   * the center area of the overlay docking layout.
   * @see GetUsableArea
   */
  void SetUsableArea(float i_x, float i_y, float i_width, float i_height, CATBoolean i_strongDockingOnly);

  /**
  * Gets the Inverse of the size(height) of a pixel in millimeter.
  */
  float GetMMInSupportUnit() const;

  /** @nodoc */
  void ComputeModelFromDeviceEvent(CATMathPointf& o_NearPoint, CATMathPointf& o_FarPoint,
    CATViewpoint& i_Viewpoint, CATDeviceEvent& i_DeviceEvent);
  /** @nodoc */
  void ComputeModelFromDeviceEvent(CATMathPoint& o_NearPoint, CATMathPoint& o_FarPoint,
    CATViewpoint& i_Viewpoint, CATDeviceEvent& i_DeviceEvent);
  /** @nodoc */
  void GetViewpointCoordinatesFromPixel(CATMathPointf& neard, CATMathPointf& fard,
    const CATViewpoint&, const float xPixel, const float yPixel);


  /**
   * Sets the current indicator. The Background and foreground indicator are
   * two uniques indicators. When you set the indicators, YOU MUST SAVE the
   * previous one to put yours. Then at the end of your use, you connect back
   * the saved one.
   * @param iIndic the @href CATIndicator
   * @param iPlace Placement Background or Foregroung
   * @return Previous Current indicator to save.
   */
  CATIndicator* SetIndicator(CATIndicator* iIndic, const CATViewerPlacement iPlace);

  /**
   * Gets the CATSupport associated to the CATVizViewer.
   * @return the @href CATSupport
   **/
  CATSupport& GetSupport() const;

  /** @nodoc */
  CATMouseDevice& GetMouseDevice() const;

  /** @nodoc */
  CATSpaceDevice& GetSpaceDevice() const;

  /** @nodoc */
  VisTouchDevice& GetTouchDevice() const;

  /** @nodoc */
  VisWintabDevice& GetWintabDevice() const;

  /** @nodoc */
  VisStylusDevice& GetStylusDevice() const;

  /** @nodoc */
  void SetSpaceFocus(int spaceFocusEnable) { _spaceFocusEnable = spaceFocusEnable; };

  /** @nodoc */
  int GetSpaceFocus(void) { return _spaceFocusEnable; };

  /** @nodoc */
  virtual CATViewpointEditor* SetViewpointEditor(CATViewpointEditor* Editor);
  /** @nodoc */
  virtual CAT2DViewpointEditor* Get2DViewpointEditor();// {return _2DViewpointEditor;};
  /** @nodoc */
  virtual CAT3DViewpointEditor* Get3DViewpointEditor();// {return _3DViewpointEditor;};

 /** @nodoc */
  virtual void Preactivate(CATManipulator* Manipulator, CATDevice* Device);
  /** @nodoc */
  virtual void MoveOver(CATManipulator* Manipulator, CATDevice* Device);
  /** @nodoc */
  virtual void Move(CATManipulator* Manipulator, CATDevice* Device);
  /** @nodoc */
  virtual void EndPreactivate(CATManipulator* Manipulator, CATDevice* Device);
  /** @nodoc */
  virtual void Activate(CATManipulator* Manipulator, CATDevice* Device);
  /** @nodoc */
  virtual void BeginManipulate(CATManipulator* Manipulator, CATDevice* Device);
  /** @nodoc */
  virtual void Manipulate(CATManipulator* Manipulator, CATDevice* Device);
  /** @nodoc */
  virtual void EndManipulate(CATManipulator* Manipulator, CATDevice* Device);
  /** @nodoc */
  virtual void Context(CATManipulator* Manipulator, CATDevice* Device);
  /** @nodoc */
  virtual void EndContext(CATManipulator* Manipulator, CATDevice* Device);
  /** @nodoc */
  virtual void Edit(CATManipulator* Manipulator, CATDevice* Device);
  /** @nodoc */
  virtual void EndEdit(CATManipulator* Manipulator, CATDevice* Device);

  /**
   * Sets the cursor displayed when the mouse is over the viewer.
   * @param iCursor
   */
  CATVizCursor::CATVizStyle SetCursor(CATVizCursor::CATVizStyle iCursor);
  /** nodoc*/
  void SetCursorHandler(CATVizCursor*);
  /** nodoc*/
  //void SetOldCursorHandler(CATVizCursor* ptr);
  /** nodoc*/
  void SetStatusBarHandler(CATVizStatusBarHandler* i_pStatusBarHandler);
  /** nodoc*/
  void SetStatusBarTemporaryText(CATUnicodeString i_message);

  /** @nodoc */
  void ChangeFocusMagnifier(int xClient, int yClient, int widthClient, int heightClient);

  /** @nodoc */
  void SetStereoMode(const int mode = 0, const float eyeGap = 0.f);

  /** @nodoc */
  void GetStereoMode(int* mode, float* eyeGap) const;

  /** @nodoc */
  virtual void SetOcclusionMode(const int mode);

  /** @nodoc */
  int GetOcclusionMode() const;


  /** @nodoc */
  CATPixelImage* GrabPixelImage(void);

  /** @nodoc */
  CATPixelImage* GrabPixelImage(int x0, int y0, int width, int height,
    CATPixelImage* image = NULL);
  /** @nodoc */
  void GetMousePosition(int* x, int* y);



  /**
   * @nodoc
   * Z Buffer access:
   *
   *   - ReadZBuffer: <format> indicates the type of data that is to be returned
   *   by the call: 0 UNSIGNED_BYTE, 1 BYTE, 2 UNSIGNED_SHORT, 3 SHORT,
   *   4 UNSIGNED_INT, 5 INT, 6 FLOAT. Returned pointer has to be freed after
   *   use (a call to malloc is made inside the routine).
   */
  void* ReadZBuffer(int format);

  /** @nodoc */
  void* ReadFrameBuffer(int format);

  /** @nodoc */
  /*
   *  Parameter iOnOff :
   *    0   Not activated
   *    1   Activated with both ZBuffer and FrameBuffer support
   *    2   Activated with FrameBuffer support only
   *    3   Activated with ZBuffer support only
   */
  void ActivateSprites(int iOnOff);
  /** @nodoc */
  int AreSpritesActivated(void);

  /**
   * Sets the viewer's FullScreen state.
   *  @param iOnOff the FullScreen mode
   */
  virtual void SetFullScreen(const int iOnOff = 1);

  /**
   * Gets whether or not the Viewer is in fullScreen.
   */
  virtual int IsFullScreen() const;

  /**
   * Sets the viewmode for viewer enclosed in the current CATSupport.
   * @param iMode
   * The viewer mode
   * <br><b>Legal values:</b> @href CATViewModeType
   * @param iActive
   * 0 = off.
   * 1 = on.
   *
   */
  void SetViewMode(const int iMode, const int iActive);

  /**
   * Returns whether or not the given mode is active.
   * @param iMode
   * the viewer mode.
   * <br><b>Legal values:</b> @href CATViewModeType
   */
  int ViewMode(const int iMode) const;

  /** @nodoc */
  void UpdateActiveLightSource();


  /** @nodoc */
  void UpdateLights(CAT3DViewpoint* iVp = NULL);


  /**
   * Gets the two CAT3DLightSourceRep associated to the viewer.
   */
  void GetLightSourceReps(const CAT3DLightSourceRep*& lightRep1,
    const CAT3DLightSourceRep*& lightRep2);

  /**
   * Sets the two CAT3DLightSourceRep associated to the viewer.
   * @param lightRep1 the first light source
   * @param lightRep2 the second light source
   */
  void SetLightSourceReps(CAT3DLightSourceRep* lightRep1,
    CAT3DLightSourceRep* lightRep2);

  /**
   * Sets the global ambient light color.
   *@param iR
   * the red composant color.
   *@param iG
   * the green composant color.
   *@param iB
   * the blue composant color.
   */
  void SetGlobalAmbientLight(const float iR, const float iG, const float iB);

  /**
   * Retreives the global ambient light color.
   *@param oR
   * the red composant color.
   *@param oG
   * the green composant color.
   *@param oB
   * the blue composant color.
   */
  void GetGlobalAmbientLight(float* oR, float* oG, float* oB);

  /**
   * Sets default material properties.
   *@param iDiffAmbCoef
   * the diffuse and ambient coefficient.
   *@param iSpecCoef
   * the specular coefficient.
   *@param iShininess
   * the shininess.
   */
  void SetDefaultMaterialProperties(float iDiffAmbCoef, float iSpecCoef, float iShininess);

  /**
   * Activates or Deactivates the global ambient light.
   *@param iOnOff
   * 0 = off.
   * 1 = on.
   */
  void SetAmbientActivation(unsigned int iOnOff);

  /**
   * Sets the background color.
   *@param iR
   * the red composant color.
   *@param iG
   * the green composant color.
   *@param iB
   * the blue composant color.
   */
  virtual void SetBackgroundColor(const float iR, const float iG, const float iB,
    const int save = 1);
  /**
   * Retreives the background color.
   *@param oR
   * the red composant color.
   *@param oG
   * the green composant color.
   *@param oB
   * the blue composant color.
   */
  void         GetBackgroundColor(float* oR, float* oG, float* oB);

  /**
   *  Sets whether or not the background is graduated.
   *@param iActive
   * 0 = off.
   * 1 = on.
   */
  virtual void SetGraduatedBackground(const int iActive);

  /** Gets whether or not the background is graduated.
  * @return the result of the test*/
  int          IsBackgroundGraduated() const;

  /** @nodoc */
  virtual void SetSaveBackgroundColor(const float, const float, const float);

  /** @nodoc */
  void GetSaveBackgroundColor(float*, float*, float*);

  /**
   * Gets the CATColormMap.
   * @return the CATColorMap
   */
  CATColorMap& GetCATColormap();

  /** @nodoc */
  CAT2DBagRep* GetbackgroundBag();

  /** @nodoc */
  virtual void Create(
#ifdef _WINDOWS_SOURCE
      CATSysWidget iFather
#elif defined (_COCOA_SOURCE)
      void* iFather
#else
      CATSysWidget iFather
#endif	  
  );

  /** @nodoc */
  virtual void Create(
    CATSysWidgetEx iFather
  );

  /**
   * Resize the viewer
   *@param iWidth
   * the new width in pixel for the viewer.
   *@param iHeight
   * the new width in pixel for the viewer.
   */
  void Resize(const float iWidth, const float iHeight);

  /** @nodoc */
  void ResizeWindow(CATCommand*, CATNotification*, CATCommandClientData);


  /** @nodoc */
  void ResetTexture(void);

  /** @nodoc */
  void SetLightSourceTexture(void);

  /** @nodoc */
  void SetTexture(CATGraphicMaterial* ioMat);

  /** @nodoc */
  CATGraphicMaterial* GetTexture(void) const;

  /** @nodoc */
  CATULONG32 GetFrameDuration(void);

  /** @nodoc */
  virtual float GetLastUpdateDuration(void) const;
  /** @nodoc */
  virtual void  GetLastUpdateDuration(float& o_fTotal, float& o_fCulling, float& o_fDraw, float& o_fOCulling, float& o_fODraw) const;
  /** @nodoc */
  void InterpretUpdate(CATCallbackEvent Id, void* From, CATNotification* Event, CATSubscriberData Data, CATCallback Callback);
  /** @nodoc */
  void SetLastUpdateDuration(CATVizDuration* i_pDuration);
  /** @nodoc */
  void GetLastUpdateDuration(CATVizDuration** o_ppDuration);
  /** @nodoc */
  void GenerateUpdateEvent();

  /** @nodoc */
  void GetLinetypeTable(int nbseg[7], float des[7][16]) const;



  /** @nodoc */
  void SetStaticQuality(float, int);
  /** @nodoc */
  void GetStaticQuality(float*, int*);
  /** @nodoc */
  void SetDynamicQuality(float, int);
  /** @nodoc */
  void GetDynamicQuality(float*, int*);
  /** @nodoc */
  void SetCullVanishingRatio(float);
  /** @nodoc */
  void GetCullVanishingRatio(float*);
  /** @nodoc */
  int  GetOutlineMode();
  /** @nodoc */
  void SetOutlineMode(const int);


  /** @nodoc */
  void SetTransparencyMode(const int);
  /** @nodoc */
  int  GetTransparencyMode() const;

  /** @nodoc */
  void SetAntiAliasingMode(const int);
  /** @nodoc */
  int  GetAntiAliasingMode() const;

  /** @nodoc */
  void SetAAFactor(const unsigned int iFactor);

  /** @nodoc */
  unsigned int GetAAFactor() const;


  /**
  * Gets the default CATIndicator associated to the backGround.
  */
  CATIndicator* GetDefaultBackgroundIndicator() const;


  /** @nodoc */
  int AnimateViewpoint(const CATMathPointf&,
    const CATMathPointf&,
    const CATMathPointf&,
    const int iDuration = 800); //Required duration in ms
/** @nodoc */
  int AnimateViewpoint(const CAT3DViewpoint&, const int iDuration = 800); //Required duration in ms;
 /** @nodoc */
  int AnimateViewpoint(const CAT2DViewpoint&, const int iDuration = 800); //Required duration in ms;
 /** @nodoc */
  int AnimateViewpoint(const CATVisu3DViewpointAnimation* ip3DViewpointAnimation);
  /** @nodoc */
  void AddAnimation(CATVisuAnimationWeakRef* i_pVisuAnimation);
  /**
    * @nodoc
    * 1 = POINT, 2= LINE, 3 = FILL
    */
  void SetPolygonDrawingMode(const int);

  /** @nodoc */
  void SetLogicalOperation(const int type); /* type = 0 : COPY          => source
                                                          1 : CLEAR         => 0
                                                          2 : SET           => 1
                                                          3 : COPY          => source
                                                          4 : COPY_INVERTED => ~source
                                                          5 : NOOP          => destination
                                                          6 : INVERT        => ~destination
                                                          7 : AND           => source & destination
                                                          8 : NAND          => ~(source & destination)
                                                          9 : OR            => source | destination
                                                         10 : NOR           => ~(source | destination)
                                                         11 : XOR           => source ^ destination
                                                         12 : EQUIV         => ~(source ^ destination)
                                                         13 : AND_REVERSE   => source & ~destination
                                                         14 : AND_INVERTED  => ~source & destination
                                                         15 : OR_REVERSE    => source | ~destination
                                                         16 : OR_INVERTED   => ~source | destination */


                                                         //*** UNDER REMOVAL: ***********************************************************
                                                          /** @nodoc */
  void AddRepOverlay(CAT2DRep*);
  /** @nodoc */
  void RemoveRepOverlay(CAT2DRep*);
  /** @nodoc */
  void AddRepFurtiveOverlay(CAT2DRep*);
  /** @nodoc */
  void RemoveRepFurtiveOverlay(CAT2DRep*);
  /** @nodoc */
  virtual void SetPreselectModeOn();
  /** @nodoc */
  void SetMesh(const int);
  /** @nodoc */
  void SetOutLine(const int);
  /** @nodoc */
  void SetHLR(const int);
  /** @nodoc */
  void SetEdge(const int);
  /** @nodoc */
  void SetMaterialRep(const int);
  /** @nodoc */
  void AddForeGroundViewpoint(CATViewpoint*);
  /** @nodoc */
  CATIndicator* SetBackgroundIndicator(CATIndicator*);
  /** @nodoc */
  CATIndicator* SetForegroundIndicator(CATIndicator*);
  /** @nodoc */
  CATIndicator* GetBackgroundIndicator();
  /** @nodoc */
  CATIndicator* GetForegroundIndicator();
  /** @nodoc */
  CATKeyboardDevice& GetKeyboardDevice();
  /** @nodoc */
  CATKeyboardEvent& GetKeyboardEvent();
  /** @nodoc */
   //void ComputeViewpoint(int vp3d=1);
 //**********************************************************************

   /**
    * @nodoc
    * Associates a CATViewpointEditor to a CATViewpoint.
    */
  void SetViewpointEditor(CATViewpoint* viewpoint, CATViewpointEditor* viewpointEditorMonipulatingIt);

  /** @nodoc */
  CATViewpointEditor* GetViewpointEditor(CATViewpoint* viewpoint);

  /** @nodoc */
  CATViewerStyle GetViewerStyle();

  /** @nodoc */
  void SetWorldOrientation(CATVisWorldOrientation iWorldOrientation);
  /** @nodoc */
  CATVisWorldOrientation GetWorldOrientation() const;

  /** @nodoc */
  void RemoveUpdateCB();


  /** @nodoc */
  void ReloadModifier();

  /**
   * @nodoc
   * Locks/Unlocks the viewer's draw.
   * @param iValue
   *  iValue = 0 -- Draw is Unlocked
   *           1 -- Draw is locked
   */
  void LockDrawRequest(int iValue);

  /** @nodoc */
  virtual void RestoreLastMainViewpoint();

  /** @nodoc */
  ::list<VP_token>& GetViewpointEditionList();

  /** @nodoc */
  inline void SetGradientStyle(int style);

  /** @nodoc */
  stack& GetDelayedStack() { return _DelayedStack; };

  /** @nodoc */
  void UnreferenceManipulator(CATManipulator* Manipulator);

  /** @nodoc */
  void UpdateBackground(CATCallbackEvent  e,
    void* p,
    CATNotification* n,
    CATSubscriberData d,
    CATCallback       c);
  /** @nodoc */
  inline CATViewer* GetCATViewer() const;

  /** @nodoc */
  void DoPickNextTime();

  /** @nodoc */
  void DontPickNextTime();

  /** @nodoc */
  int IsThereAPickingNextTime();



  /** @nodoc */
  inline void SetContextualMenuHandler(CATVizContextualMenuHandler* iPtr);

  /** @nodoc */
  void SendCATContext(CATManipulator*, CATNotification*);

  /** @nodoc */
  inline CATViewerEvent* GetMouseVEvent();
  /** @nodoc */
  inline CATViewerEvent* GetSpaceVEvent();
  /** @nodoc */
  inline VisStylusVIDDeviceEvent* GetStylusVIDEvent();
  /** @nodoc */
  void IncrementPick(const float x, const float y, CATPickPathList& pickpath, int sense, CATSupport* ipSupport = NULL);
  /** @nodoc */
  CATManipulator* ChooseManipulator(CATPickPathList& pickPath, CATPickPath& PickPathChoosen);
  /** @nodoc */
  CATManipulator* ComputeManipulator(CATPickPathList& pickPath, CATPickPath& PickPathChoosen);
  /** @nodoc */
  void SetLocalTransformation(boolean i_bLocalTransformation);

  /** @nodoc */
  void GetMultiThreadCullingPerformances(int* nb_thread, float** threaded_duration);

  /** @nodoc */
  virtual void ActivateScalePlane(const int Activate, const float Scale = 1.0f, const float Width = 200.0f, const float Height = 100.0f,
    const int ShowPlane = 1, const float LineWidth = 10.0f, const float LineHeight = 10.0f);
  /** @nodoc */
  virtual int  IsScalePlaneActivated();

  /** @nodoc */
  static void GetSessionDynamicQuality(float&, int&);

  /** @nodoc */
  static void SetSessionDynamicQuality(float, int);

  /** @nodoc */
  //virtual  void EnableAltDrillSelector(int state);

  /** @nodoc */
  //int GetAltDrillSelectorFlag();

  /** @nodoc */
  void SetSpecific2DMode(const int iOnOff);

  /** @nodoc */
  int GetSpecific2DMode();

  /** @nodoc */
  int GetAnimationCount();
  /** @nodoc */
  void AbortAllAnimations(CATBoolean cutShortFlag = TRUE);
  /** @nodoc */
  float AlarmClockForAnimations();
  /** @nodoc */
  static void WakeUpAnimations(void* i_pData);

  /** @nodoc */
  void SetInfiniteEnvironment(CATVisInfiniteEnvironment* iEnv);
  /** @nodoc */
  void SetInfiniteEnvironment(const CATString& iName);
  /** @nodoc */
  void PushInfiniteEnvironment(const CATString& iName);
  /** @nodoc */
  void PopInfiniteEnvironment();
  /** @nodoc */
  void PushOverloadInfiniteEnvironment(CATVisInfiniteEnvironmentOverload* iOverloadEnv);
  /** @nodoc */
  void PopOverloadInfiniteEnvironment(CATVisInfiniteEnvironmentOverload* iOverloadEnv = NULL);
  /** @nodoc */
  const CATString& GetInfiniteEnvironmentRootName();
  /** @nodoc */
  CATVisInfiniteEnvironment* GetCloneOfInfiniteEnvironment();
  /** @nodoc */
  void LockInfiniteEnvGroundUpdate(int iOnOff);
  /** @nodoc */
  void InvalidInfiniteEnv(int iForceUpdate = 0);

  /** @nodoc
  */
  enum EventListenerPosition { PreVIDVisuListener, VIDVisuListener, StandardVisuListener, HiddenViewerVisuListener };
  void AddEventListener(const CATIVisuEventListener_var& i_spVisuEventListener, EventListenerPosition = StandardVisuListener);
  void AddEventListener(const CATIVisuEventListener_var& i_spVisuEventListener, int i_insertAtBeginning);
  void RemoveEventListener(const CATIVisuEventListener_var& i_spVisuEventListener);

  /** @nodoc */
  CATManipulator* GetNextActivatedManipulator() const
  {
    return _pNextActivatedManipulator;
  }
  /** @nodoc */
  CATManipulator* GetNextPreactivatedManipulator() const
  {
    return _pNextPreactivatedManipulator;
  }

  /** @nodoc */
  int IsMultipipeActivated();
  /*nodoc*/
  void SetMultipipeConfiguration(const VisMultipipeConfiguration& iMultipipeConfiguration);
  /** @nodoc */
  void GetMultipipeConfiguration(VisMultipipeConfiguration*& opMultipipeConfiguration);
  /*nodoc*/
  void SetMultipipeMode(const int iOnOff = 1);

  /** @nodoc Sets a pointer on a VidCtlViewer, responsible for the display and the interaction interface.*/
  void SetViewObject(const CATBaseUnknown_var& i_pViewObject);
  /** @nodoc */
  CATBaseUnknown_var GetViewObject() const;
  /** @nodoc Indicates if the Viewer is visualized through a VidCtlViewer, or a CATViewer either.*/
  int IsDisplayedThroughCID();

  /** @nodoc */
  void ShowMagnifier(float x, float y);
  /** @nodoc */
  void DispatchMagnifierEvent(CATMagnifierEvent& magEvent);
  /** @nodoc */
  void HideMagnifier();
  /** @nodoc */
  void MoveMagnifier(float x, float y);
  /** @nodoc */
  void ShowMagnifierContextualMenu();
  /** @nodoc */
  void SetWalkFlyActivated(int iwalkFlyActivated);
  /** @nodoc */
  int GetWalkFlyActivated() const;

protected:
  /*  only usable by CATViewer class */
  friend class CATViewer;
  /** @nodoc */
  void       SetCATViewer(CATViewer*);

  /** @nodoc */
  void SetPickEditor();
  /** @nodoc */
  int  GetPickEditor();

private:
  void DispatchUpdateForRecord(CATViewerEvent* pViewerEvent);

protected:

  /** @nodoc */
  void OnDeviceAction(CATCallbackEvent  e,
    void* p,
    CATNotification* n,
    CATSubscriberData d,
    CATCallback       c);

  /**
   * @nodoc
   * Method called when the position and dimension of the usable area in the viewer has changed.
   * @see GetUsableArea
   */
  virtual void OnUsableAreaChanged();

  ViewerInteractiveState _iState;

  CATSysWidgetEx _motif;
/*#ifdef _WINDOWS_SOURCE
  CATSysWidgetEx _motif;

#elif defined (_COCOA_SOURCE)
  void* _motif;

#else
  CATSysWidgetEx _motif;
#endif	
*/

  CATMouseDevice* _mouseAgent;
  CATMouseEvent* _mouseEvent;
  CATViewerEvent* _mouseVEvent;

  CATKeyboardDevice* _keyboardAgent;
  CATKeyboardEvent* _keyboardEvent;
  CATViewerEvent* _keyboardVEvent;

  CATSpaceDevice* _spaceAgent;
  CATIncrementEvent* _incrementEvent;
  CATViewerEvent* _spaceVEvent;
  int _spaceFocusEnable;

  VisTouchDevice* _touchAgent;
  VisMultitouchDeviceEvent* _multitouchEvent;
  VisMonotouchDeviceEvent* _monotouchEvent;
  VisTouchViewerEvent* _multitouchVEvent;

  VisWintabDevice* _wintabAgent;
  VisWintabDeviceEvent* _wintabEvent;
  CATViewerEvent* _wintabVEvent;

  VisStylusDevice* _stylusAgent;
  VisStylusDeviceEvent* _stylusEvent;
  VisStylusVIDDeviceEvent* _stylusVIDEvent;
  CATViewerEvent* _stylusVEvent;

  CATCallbackManager* _CallbackManager;

  CATViewerStyle _ViewerStyle;

  CAT3DLightSourceRep* _lightRep1;
  CAT3DLightSourceRep* _lightRep2;

  CATGraphicWindow* realisation_;
  int _isBuilt;

  CATIndicator* _Indicator[2];
  CAT2DViewpointEditor* _2DViewpointEditor;
  CAT3DViewpointEditor* _3DViewpointEditor;
  CATBaseUnknown_WR _3DViewpointEditor_WR;
  CATBaseUnknown_WR _2DViewpointEditor_WR;


  CATViewpoint* _ManipulatedViewpoint;
  ::list<VP_token> _ViewpointEditionList;

  float        _static_sag;
  int          _static_cull_size;
  float        _dynamic_sag;
  int          _dynamic_cull_size;
  float        _cullVanishingRatio;
  int          _hlr_state;
  int          _Outline;
  int          _ViewerUpdated;
  CAT2DCustomRep* _backgroundRep;
  CAT2DBagRep* _backgroundBag;

  CATViewpoint* _MainViewpoint;
  CAT3DViewpoint* _Main3DViewpoint;
  CAT2DViewpoint* _Main2DViewpoint;
  CAT2DViewpoint* _MainOverlayViewpoint;
  CAT2DViewpoint* _backgroundViewpoint;
  int _CanSave3DViewpoint;
  int _CanSave2DViewpoint;
  int _backgroundGraduated;

  CATIndicator* _default2DBackgroundIndicator;
  CATIndicator* _default3DBackgroundIndicator;
  CATIndicator* _2DBackgroundIndicator;
  CATIndicator* _3DBackgroundIndicator;
  CATIndicator* _2DForegroundIndicator;
  CATIndicator* _3DForegroundIndicator;

  int _walkFlyActivated;

  CATSpaceButtonEvent* _spaceButtonEvent;
  CATViewerEvent* _spaceButtonVEvent;

protected:
  stack& _DelayedStack;

  int _gradientstyle;

  CATViewpoint* _lastMainViewpoint;
  ::list<CATVizBasePathElementRep> _pathManipulators;

  int _saveIndicatorCursor;

  boolean _bLocalTransformation;

private:

  void Pick(const CATPickingStyle istyle, const float ix, const float iy, const float idx, const float idy, CATGraphicWindow* pGraphicWindow, CATPickPathList& oPlist, CATRepPath* irepp = NULL, const float* ipolygon = NULL, const int inb_point = 0, const int ipick_style = 0, int forceFullPick = 1, int ignoreNoPickFlag = 0, int iDialogOnly = 0);

  template<typename PointType>
  void Pick(const PickingStyle style, const PointType& org, const CATMathDirectionf& dir, const float neard, const float fard, const float dx, const float dy, CATPickPathList& pickpath, CATRepPath* path, const int ipick_style, int forceFullPick, int ignoreNoPickFlag, int includeDialogReps = 0, int iVIDPicking = 0);

  void CreateSlaveGraphicWindow(CATSysWidgetEx ipFather, int iDisplayIndex);

  CATManipulator* ComputeManipulator(CATPickPathList& pickPath, int iModifyViewerState, CATPickPath& PickPathChoosen);

  void DrillActivate(CATManipulator* Manipulator, CATDevice* Device);

  void ModifyAccuratePickingWithStandardPicking(CATPickPathList& ioAccuratePickpath, CATPickPathList& iExtendedPickpath);

  //Useful to known whether or not a draw request is taken into account or not. 
  int _IsDrawLocked;

  void InterpretViewerSelected(CATNotification* Event);

  void Animated(CATCallbackEvent, void*, CATNotification*,
    CATSubscriberData, CATCallback);

  void CheckAnimationsCB(CATCallbackEvent, void*, CATNotification*,
    CATSubscriberData, CATCallback);
  //void StepAnimations();

  CATCallback      _animationCB;

  CATVisuAnimationWeakRef* _p2DViewpointAnimationWR;
  CATVisuAnimationWeakRef* _p3DViewpointAnimationWR;



  CATPickPath	_currentPath;
  CATPickPathList _currentPickPathList;
  int _pickPathListPointer;

  CATManipulator* _manipulatorToActive;
  CATManipulator* _manipulatorPrevious;

  float _LastUpdateTotalDuration;
  float _LastUpdateCullingDuration;
  float _LastUpdateDrawDuration;
  float _LastUpdateOCullingDuration;
  float _LastUpdateODrawingDuration;

  CATVizDuration* _pDuration;
  int       _nbDuration;

  void ViewpointModified(CATCallbackEvent, void*, CATNotification*, CATSubscriberData Data, CATCallback);

  static CATVizViewer* _currentViewer; // positionné par le CATViewer des qu'il recoit un evenement cf InterpretDeviceEvent
  static CATVizViewer* _SelectedViewer; // positionné par la CATFrmWindow lorsqu'elle est activee
  static ::list<CATVizViewer> _viewerClass;

  CATVizDockingLayoutInfos* _pDockingLayoutInfos;

  int _pickToDo;

#define MAX_SAVED_VIEWPOINTS 20
  CAT3DViewpoint* _saved3DViewpoint[MAX_SAVED_VIEWPOINTS];
  CAT2DViewpoint* _saved2DViewpoint[MAX_SAVED_VIEWPOINTS];
  int _nSaved3DViewpoints;
  int _nSaved2DViewpoints;
  int _i3DViewpoint;
  int _i2DViewpoint;
  int _nNext3DViewpoints, _nNext2DViewpoints;

  CATCallback _updateCB;

  unsigned int InternalKeyboardAction(CATKeybdEvent* i_pEvent);
  unsigned int InternalIMEKeyboardAction(CATIMEKeybdEvent* i_pEvent);
  unsigned int InternalDeviceAction(CATNotification* i_pNotification);
  void InternalKeyboardAction_post(CATKeybdEvent* i_pEvent);
  void InternalDeviceAction_post(CATNotification* i_pNotification);
  CATBoolean _keyboardIsOverrun;


  CATCallback       _DeviceActionCB;
  float             _RedSave;
  float             _GreenSave;
  float             _BlueSave;
  int               _drillx, _drilly;
  unsigned int      _altEvent : 1;
  int               _IsFullScreen;
  unsigned int      _beginDrawElement;

  // backward pointer to CATViewer
  CATViewer* _backviewer;
  // pointer to handle Cursor changes
  CATVizCursor* _cursor_handler;
  //CATVizCursor*                 _old_cursor_handler;
  // pointer to handle contextual menu events dispatch
  CATVizContextualMenuHandler* _ctx_handler;
  // pointer to handle status bar events dispatch
  CATVizStatusBarHandler* _statusBarHandler;

  int _pickEditorActivated;

  //MPCulling
  int    _nb_culling_thread;
  float* _threaded_culling_duration;

  CATViewpoint* _mainDialogViewpoint;
  CATViewpoint* _mainV3DViewpoint;

  //Management of Define level of detail and Define pixel culling commands
  //Define the dynamic pixel culling and the dynamic level of detail used
  //when creating a new CATVizViewer.
  static float _sessionDynamicLOD;
  static int   _sessionDynamicPixelCulling;

  // environement infinis
  void UpdateEnvironment();

  CATLISTV(CATBaseUnknown_var) _preVIDEventListeners;
  CATLISTV(CATBaseUnknown_var) _VIDEventListeners;
  CATLISTV(CATBaseUnknown_var) _postVIDEventListeners;
  CATLISTV(CATBaseUnknown_var) _visuEventListenersForHiddenViewers;

  CATLISTV(CATBaseUnknown_var) _freezedVisuEventListenerList;

  // keep the next manipulators to activate or preactivate during the EndActivate and EndPreactivate calls
  // on current manipulator in order to set them on EndActivate and EndPreactivate events dispatch.
  // Need by application to know futur manipulator and to choose their behavior according to it.
  // For example EndActivate/Activate could be called on the same manipulator by visu infra, application could ignored these events in this case.
  CATManipulator* _pNextActivatedManipulator;
  CATManipulator* _pNextPreactivatedManipulator;

  //private:
   // this is transfered to graphicwindow :  CATBaseUnknown_WR _visViewWR;

public:
  /** @nodoc */
// SetOnlyNavigationTouchMode : when the wacom driver is present, the application may want to keep touch interaction only for navigation
// (no selection no edition) and wacom pen for selection.
// default value is false for OnlyNavigationTouchMode. By default the touch is behaving like a mouse (selection, edition and navigation gestures)
// SetOnlyNavigationTouchMode returns TRUE only when this mode is possible ie when wacom pen driver is loaded and active, False otherwise
  CATBoolean SetOnlyNavigationTouchMode(CATBoolean iMode);


  /** @nodoc */
  // true when application has successfully set the OnlyNavigationTouchMode
  CATBoolean IsOnlyNavigationTouchMode();

  /** @nodoc */
  // true when wacom pen driver is loaded and active
  CATBoolean IsWintabLoaded();

  /** @nodoc  */
  //this function  works on  windows 8 and above.It return TRUE when touch is enabled on Viewer. It  always return TRUE  for lower version of windows and other type of OS
  CATBoolean  IsTouchEnabled() const;

  /** @nodoc  */
  //InterpretKeybdEvent is called in keyboard device. It let ViewpointEditor to onerride Keyboard event behavior
  // it will be replaced by an editor of keyboard device
  void InterpretKeybdEvent(CATCallbackEvent e, void* pv, CATNotification* n, CATSubscriberData d, CATCallback cb);

  CATBoolean IsKeyboardOverrun();
  void SetKeyboardIsOverrun();

private:
  CATBoolean _OnlyNavigationTouchMode;
  CATBoolean _KeyboardIsOverrun;

};

inline void CATVizViewer::SetGradientStyle(int style)
{
  _gradientstyle = style;
}

inline CATViewer* CATVizViewer::GetCATViewer() const
{
  return _backviewer;
}

inline void CATVizViewer::SetContextualMenuHandler(CATVizContextualMenuHandler* ptr)
{
  _ctx_handler = ptr;
}

inline CATViewerEvent* CATVizViewer::GetMouseVEvent()
{
  return _mouseVEvent;
}

inline CATViewerEvent* CATVizViewer::GetSpaceVEvent()
{
  return _spaceVEvent;
}

inline VisStylusVIDDeviceEvent* CATVizViewer::GetStylusVIDEvent()
{
  return _stylusVIDEvent;
}

#endif
