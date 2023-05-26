#ifndef CATViz3DViewer_H
#define CATViz3DViewer_H
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "CATVisFoundation.h"
#include "CATVizViewer.h"
#include "CATProjectionType.h"
#include "CATMathDirectionf.h"
#include "VisClipPlaneDesc.h"
#include "CATIAV5Level.h"

class CAT3DScalePlaneRep;
class CAT3DBoundingSphere;
class CAT3DViewpoint;
class CAT3DViewport;
class CAT3DRep; 
class CAT2DRep;
class CAT3DAxisRep;
class CAT3DManipulator;
class CATBasic3DViewpointEditor;
class CAT2DAnnotationTextRep;
class CAT2DViewpoint;

/**
 * Class to display 3D Graphic Representations on the screen.
 * 
 */
enum ViewpointManipulationType { Rotate, RotateAxis, LookAt, Recenter, Translate, Zoom, TurnHead, ZoomArea, Fly, Walk};

class ExportedByCATVisFoundation CATViz3DViewer : public CATVizViewer
{

  CATDeclareClass;

  public :


  /**
   * Constructs a CATViz3DViewer.
   * @param iFather  
   * @param iStyle
   * @param iWidth  Width in pixel
   * @param iHeight Height in pixel
   * @param iViewerStyle Options of the viewer's behaviour.
   */
  CATViz3DViewer (
      const CATString & iName,
      const int iWidth= 800,
      const int iHeight= 500,
      const CATViewerStyle iViewerStyle=NULL);

  /** @nodoc */
  virtual void Create(
#ifdef _WINDOWS_SOURCE
      CATSysWidget iFather
#elif defined (_COCOA_SOURCE)
      void *iFather
#else
      CATSysWidget iFather
#endif	  
      );

  /** @nodoc */
  virtual void Create(CATSysWidgetEx iFather);


  /** @nodoc */
  virtual ~CATViz3DViewer();

  //  operation on the main 3D viewpoint
  //  ----------------------------------
  /**
   * Modifies the Main 3D viewpoint so that the specified CAT3DBoundingSphere 
   * takes as much place as possible on the screen.
   * @param iBs3D The CAT3DBoundingSphere you want to reframe on
   * @see CAT3DBoundingSphere
   */
  virtual void ReframeOn(const CAT3DBoundingSphere &iBs3D); // To frame on a specific bounding sphere
  /** 
   * Gets the CAT3DBoundingSphere of the scene displayed by the CATViz3DViewer.
   */
  CAT3DBoundingSphere GetGlobalBoundingSphere();

  //  definition and fog activation 
  //  -----------------------------

  /** @nodoc */
  void SetFogMode    (const int);
  /** @nodoc */
  int IsFogOn() const;

  /** @nodoc */
  CATMathDirectionf GetVertical();
  /** @nodoc */
  CATMathDirectionf & GetNorth () ;

  /** @nodoc */
  void SetGround (const CATMathDirectionf &vertical, const CATMathDirectionf &north);

  // Clipping plane (maximum 6)
  // -------------------------

  /** @nodoc */
  void AddClippingPlane (const int nb_planes, const float *point, const float *normal, const int clippingPlaneFlags = VisClipPlaneDesc::fCapping);
  /** @nodoc */
  void RemoveClippingPlane ();

  /** @nodoc */
  void AddCullingBox (const int nb_planes, const float *point, const float *normal);
  /** @nodoc */
  void RemoveCullingBox ();

  /** @nodoc */
  virtual void StartViewpointManipulation( const ViewpointManipulationType Type);
  /** @nodoc */
  virtual void StopViewpointManipulation();

  /** @nodoc */
  void RestoreLastMainViewpoint();

  /** @nodoc */
  void RefreshCurrentScaleTextRep ();
  /** @nodoc */
  void SetCurrentScaleDisplay(int i_onOff);
  /** @nodoc */
  void CurrentScaleTextRepCB (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);

  /**
   * Display the reference axes or hide them.
   * @param iOnOff
   *   Says the reference axes are to be drawn or not.
   * <br><b> Legal values</b>:
   * <li><tt>0</tt> hide the reference axes</li>
   * <li><tt>1</tt> display the reference axes (it's the default value)</li>.
   */
  virtual void SetReferenceAxis(int iOnOff);

  /** @nodoc */
  void SetAxisPickable(int OnOff);
  /** @nodoc */
  int IsAxisPickable ();
  /** @nodoc */
  virtual int IsReferenceAxis();

  // SpaceTarget rep display
  /** @nodoc */
  virtual void SetShowSpaceTarget(const int iOnOff);
  /** @nodoc */
  virtual int IsShowSpaceTarget();

  //  Navigation Mode
  /** @nodoc */
  virtual void SetNavigationStyle( const int iMode);
  /** @nodoc */
  virtual int GetNavigationStyle();

  //  Viewpoint save and restore mechanisms
  /** Stores the Current MainViewpoint so that it cn be restored later. */
  virtual void SaveViewpoint();

  /** Restores the Viewpoint store before the current viepoint.*/
  virtual void DisplayPreviousViewpoint();

  /** Restores the Viewpoint store after the current viepoint.*/
  virtual void DisplayNextViewpoint();

  /** Changes the viewpoint that is affected by Local Transformation .*/
  virtual void SetMainViewpoint (CATViewpoint *);

  /** @nodoc */
  virtual void SetDefault2DViewpointEditor(CAT2DViewpointEditor *defaultViewpointEditor);
  
  /** @nodoc */
  virtual void SetDefault3DViewpointEditor(CATBasic3DViewpointEditor *defaultViewpointEditor);

  /** @nodoc */
  void ChangeFlySpeed( int s);

  /** @nodoc */
  CATViewpointEditor * GetManipulatedViewpointEditor();

  /** @nodoc */
  virtual void ActivateScalePlane(  const int Activate, const float Scale=1.0f, const float Width=200.0f, const float Height = 100.0f, 
                                    const int ShowPlane = 1, const float LineWidth=10.0f, const float LineHeight=10.0f);
  /** @nodoc */
  virtual int  IsScalePlaneActivated();

  //------------------------------------------------------------------------------

  protected :

  /** @nodoc */
  virtual void EndManipulate( CATCommand *Command, CATNotification *Notification, CATCommandClientData Data);

  /**
   * @nodoc
   * Method called when the position and dimension of the usable area in the viewer has changed.
   * @see GetUsableArea
   */
  virtual void OnUsableAreaChanged();


  CATViewpointEditor *_ManipulatedViewpointEditor;
  CATIndicator *_ViewpointIndicator;
  CATIndicator *_LastIndicator;

  // Ground informations for Viewpoint manipulation:
  // -----------------------------------------------

  CATMathDirectionf _north;	
  CAT3DScalePlaneRep *_3DScalePlaneRep;
  ProjectionType _ProjectionTypeForScalePlane;
  int _ScalePlaneActivated;
  int _ShowScalePlane;

  private :
  void MainViewpointChanged (CATCommand *, CATNotification *, CATCommandClientData); 
  //  Viewpoint save mechanisms
  virtual void ViewpointChanged( CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback); 

  CATCallback _AnimationStartCB1, _ViewpointChangeCB1, _AnimationStopCB1;
  CATCallback _AnimationStartCB2, _ViewpointChangeCB2, _AnimationStopCB2;

  void PreviousViewpoint (CATCommand *, CATNotification *, CATCommandClientData); // scroll to previous Viewpoint
  void NextViewpoint     (CATCommand *, CATNotification *, CATCommandClientData); // scroll to next Viewpoint

  int _IsReferenceAxisOn;
  int _IsShowSpaceTarget;

  CATCallback    _AxisViewpointCB, _AxisResizeCB;
  CAT3DAxisRep   *_Axis3DRep;
  CAT3DViewpoint *_Axis3DViewpoint;
  CAT3DManipulator  *_AxisManipulator;
  int _AxisPickable;
  int _LastMode;

  short _currentScaleDisplayFlag;
  CATCallback  _currentScaleModifCB, _currentScaleResizeCB;
  CAT2DAnnotationTextRep* _pCurrentScaleTextRep;
  CAT2DViewpoint *_currentScale2DViewpoint;

  CATNotification *  _ManipulatorChangedEvt;
  CATBasic3DViewpointEditor *_default3DViewpointEditor;
  CAT2DViewpointEditor *_default2DViewpointEditor;

  void UpdateAxisPosition();

  void ModifyAxis (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);

  int _save_state;
  int _saveValue, _saveFog;
  float _saveAmbientLight[3];

  public :

  //  Event Define
  //  ------------

  /** @nodoc */
  CATDeclareCBEvent (NAVIGATION_GROUND_CHANGE);
  /** @nodoc */
  CATDeclareCBEvent (VIEWPORT_EVENT);
  /** @nodoc */
  CATDeclareCBEvent (ROTATE_EVENT);
  /** @nodoc */
  CATDeclareCBEvent (POSITION_EVENT);
  /** @nodoc */
  CATDeclareCBEvent (NAVIGATION_TURN_AROUND_ACTIVATED);
  /** @nodoc */
  CATDeclareCBEvent (NAVIGATION_WALK_ACTIVATED);
  /** @nodoc */
  CATDeclareCBEvent (NAVIGATION_FLY_ACTIVATED);
  /** @nodoc */
  CATDeclareCBEvent (NAVIGATION_VIEWPOINT_ACTION_ENDED);
  /** @nodoc */
  CATDeclareCBEvent (NAVIGATION_3D_PICKING);
  /** @nodoc */
  CATDeclareCBEvent (FOG_CHANGE_EVENT);
};


#endif
