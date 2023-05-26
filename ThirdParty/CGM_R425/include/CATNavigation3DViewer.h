#ifndef CATNavigation3DViewer_H
#define CATNavigation3DViewer_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	Interactive window to composed by a viewpoint interactions
//		tool bar and a viewer s area.
//------------------------------------------------------------------------------
// Usage :	The toolbar is composed by :
//		  - Navigation style frame :
//		    + TurnAround ( MouseButton2 (MB2) to turn, MB2+MB1 to zoom)
//		    + Walk horizontaly
//		    + Fly in space
//		  - Viewpoint basic commands frame :
//		    + Reframe 
//		    + LookAt
//		    + Previous viewpoint
//		    + Next viewpoint
//		  - Visualization attributes frame :
//		    + Light sources (0-1-2, directions and global intensity)
//		    + Clipping planes ( near/far)
// 		    + Ground ( perpendicular to the vectical)
//		    + Performance ( for debug ; shoud not be here !!!)
//		 The graphics area is a 3D Viewer.
//------------------------------------------------------------------------------
// Main methods :
//	Toolbar layout
//	    AddIconFrame : Add a frame at the right in the toolbar
//	    ActivateMenu : Display the toolbar (default)
//	    DeactivateMenu : Hide toolbar
//
//	Viewpoint 
//	    SaveViewpoint : Save the current viewpoint (restorable with icons)
//	    Reframe : Do a reframe of the MainMiewpoint
//
//	Dashboard
//	    SetDashboardOn/Off : Display/hide tools (displayed over 3D area) for navigation
//
//	
//------------------------------------------------------------------------------
// Class :	CATNavigation3DViewer
//		  CAT3DViewer
//		    CATViewer
//------------------------------------------------------------------------------

#include "CATVisController.h"
#include "CAT3DViewer.h"
#include "CATViz3DViewer.h"


class CAT3DViewpoint;

class CATDlgRadioButton;
class CATDlgPushButton;
class CATDlgCheckButton;
class CATDlgCombo;
class CATVisProtocolUIPanels;
class CATBasic3DViewpointEditor;
class CAT2DViewpointEditor;

class CAT3DGroundTranslator;
class CAT3DManipulator;
class CATGroundRep;
class CATIndicator;
class CAT2DDashboardRep;
class CAT3DAxisRep;

/**
* Class to display 3D Graphic Representations on the screen, adding
* the Local Transformations.
* When beeing instantiated, this class creates a Basic2DViewpointEditor and associate
* it to the Main2DViewpoint, and a CATBsic3DViewpointeditor and associate it to the
* Main3DViewpoint
*/
class ExportedByCATVisController CATNavigation3DViewer : public CAT3DViewer
{
  CATDeclareClass;

public :

  DeclareResource(CATNavigation3DViewer,CATViewer)

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

  /**
   * Creates a 3D Dialog frame.
   * @param iFather Dialog object the viewer will be inserted into.
   * @param iName Name of the viewer.
   * @param iStyle Frame style (See CATDlgFrame styles)
   * @param iWidth Width of the viewer's window (in pixel)
   * @param iHeight Height of the viewer's window
   * @param iViewerStyle Options of the viewer's behaviour.
   */   
  CATNavigation3DViewer ( CATDialog *iFather, const CATString &iName, CATDlgStyle style=NULL, 
                          const int iWidth = 800, const int Height= 500, 
                          const CATViewerStyle iViewerStyle=NULL);

  /** @nodoc */
  virtual ~CATNavigation3DViewer();

  /** @nodoc */
  virtual void StartViewpointManipulation( const ViewpointManipulationType Type);
  /** @nodoc */
  virtual void StopViewpointManipulation();

  //  Light sources
  /** @nodoc */
  virtual void SetLightSourcesEditor(const int OnOff);
  /** @nodoc */
  virtual int  IsLightSourcesEditorOn() const;

  //  Depth Effect
  /** @nodoc */
  virtual void SetDepthEffectEditor(const int OnOff);
  /** @nodoc */
  virtual int  IsDepthEffectEditorOn() const;

  //  Dashboard
  /** @nodoc */
  virtual void SetDashboardOn();
  /** @nodoc */
  virtual void SetDashboardOff();
  /** @nodoc */
  virtual int IsDashboard();

  //  Axisboard
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

  //  Ground
  /** @nodoc */
  enum GroundStyle { NoGround, HorizontalPlane, CuboidRoom, GridPlane };
  /** @nodoc */
  virtual void SetGroundStyle( const GroundStyle iGroundStyle=NoGround);
  /** @nodoc */
  virtual GroundStyle GetGroundStyle() const;

  //  Navigation Mode
  /** @nodoc */
  virtual void SetNavigationStyle( const int iMode);
  /** @nodoc */
  virtual int GetNavigationStyle();

   //  Synchronization Mode
  /** @nodoc */
  // 0 = No Synchronization
  // 1 = Synchro Asynchronous
  // 2 = Sync Synchronous
  virtual void SetSynchronization( const int iMode);
  /** @nodoc */
  virtual int GetSynchronization();


  //  Viewpoint save and restore mechanisms
  /** Stores the Current MainViewpoint so that it cn be restored later. */
  virtual void SaveViewpoint();

  /** Restores the Viewpoint store before the current viepoint.*/
  virtual void DisplayPreviousViewpoint();

  /** Restores the Viewpoint store after the current viepoint.*/
  virtual void DisplayNextViewpoint();

  /** Changes the viewpoint that is affected by Local Transformation .*/
  virtual void SetMainViewpoint (CATViewpoint *);

  //  Occlusion Mode
  /** @nodoc */
  virtual void SetOcclusionMode (const int Mode);


  //------------------------------------------------------------------------------
  //  Put temporarly in public, waiting the accelerators of Dialog framework
  //  to be able to call this commands from a menu for example
  /** @nodoc */
  CATDlgPushButton  *_previous;
  /** @nodoc */
  CATDlgPushButton  *_next;
  /** @nodoc */
  CATDlgPushButton  *_reframe;
  /** @nodoc */
  CATDlgCheckButton *_light;
  /** @nodoc */
  CATDlgCheckButton *_nearfarfog;
  /** @nodoc */
  CATDlgCheckButton *_ground;

  /** @nodoc */
  void ActivateReframe    (CATCommand *, CATNotification *, CATCommandClientData);
  /** @nodoc */
  void ActivateGround     (CATCommand *, CATNotification *, CATCommandClientData); 

  /** @nodoc */
  void ChangeFlySpeed( int s);

  /** @nodoc */
  CATViewpointEditor * GetManipulatedViewpointEditor();

  //------------------------------------------------------------------------------
protected :

  /** @nodoc */
  virtual void InitNavigationFrame( CATDialog *iParent);
  //  Viewpoint interactive mode (Examine, Walk, Fly)
  /** @nodoc */
  CATDlgCheckButton *_Rotate, *_Zoom, *_LookAt, *_Translate, *_Recenter, *_Tilt;
  /** @nodoc */
  virtual void ChangeNavigationStyle( CATCommand *Command, CATNotification *Notification, CATCommandClientData Data);
  /** @nodoc */
  CATDlgCombo *_NavigationStyle;

  // Viewpoint interaction done by manipulator (Via button1)
  /** @nodoc */
  virtual void SetViewpointManip( CATCommand *Command, CATNotification *Notification, CATCommandClientData Data);
  /** @nodoc */
  virtual void EndManipulate(CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);
  /** @nodoc */
  CATDlgCheckButton *_LastCheckedButton;

  //  Viewpoint save mechanisms
  /** @nodoc */
  virtual void ViewpointChanged( CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback); 
  /** @nodoc */
  CATCallback _AnimationStartCB1, _ViewpointChangeCB1, _AnimationStopCB1;
  /** @nodoc */
  CATCallback _AnimationStartCB2, _ViewpointChangeCB2, _AnimationStopCB2;

  //  Viewpoint restore mechanisms
  /** @nodoc */
  void PreviousViewpoint (CATCommand *, CATNotification *, CATCommandClientData); // scroll to previous Viewpoint
  /** @nodoc */
  void NextViewpoint     (CATCommand *, CATNotification *, CATCommandClientData); // scroll to next Viewpoint

  //  Light sources
  /** @nodoc */
  CATVisProtocolUIPanels* _lightSourcePanel;
  /** @nodoc */
  void LightSourcePanelDestroyed (CATCommand *, CATNotification *, CATCommandClientData);

  //  Visibility settings
  /** @nodoc */
  CATVisProtocolUIPanels *_VisibilityPopup;
  /** @nodoc */
  void VisibilityPopupDestroyed (CATCommand *, CATNotification *, CATCommandClientData);

  //  Ground
  /** @nodoc */
  void GroundChanged (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);  

  //  Dashboard
  /** @nodoc */
  int _IsDashboardOn;
  /** @nodoc */
  CAT2DDashboardRep *_DashboardRep;
  /** @nodoc */
  CATCallback _ResizeCB;
  /** @nodoc */
  void GraphicSizeChanged(CATCallbackEvent , void *, CATNotification *, CATSubscriberData , CATCallback ); 

private :

  //  General Layout
  /** @nodoc */
  void Create (CATCommand *, CATNotification *, CATCommandClientData); 

  /** @nodoc */
  void DeviceActionCB( CATCallbackEvent Id, void *From, CATNotification *Event, CATSubscriberData Data, CATCallback Callback);

  /** @nodoc */
  int ZoomOnWheel (CATNotification *); 
  /** @nodoc */
  int MouseMove (CATNotification *); 
  /** @nodoc */
  int ViewpointTranslate (CATNotification *); 

  /** @nodoc */
  CATCallback      _ManipulationEndedCB;
  /** @nodoc */
  CAT3DAxisRep   *_Axis3DRep;
  /** @nodoc */
  CAT3DViewpoint *_Axis3DViewpoint;
  /** @nodoc */
  CAT3DManipulator  *_AxisManipulator;

  /** @nodoc */
  void ModifyAxis (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);

  /** @nodoc */
  void ActivateLight      (CATCommand *, CATNotification *, CATCommandClientData); // light source Editor
  /** @nodoc */
  void ActivateNearfarfog (CATCommand *, CATNotification *, CATCommandClientData); // near far fog Editor

  // Ground/Axis representation in the center of the model
#define NGROUNDS 6
  /** @nodoc */
  CATGroundRep *_GroundReps[NGROUNDS];
  /** @nodoc */
  CAT3DGroundTranslator *_GroundManip;
  /** @nodoc */
  CATMathPointf         *_GroundCenter;
  /** @nodoc */
  CATCallback            _GroundCB; 
  /** @nodoc */
  float                  _GroundRadius;
  /** @nodoc */
  GroundStyle _GroundStyle;

  /** @nodoc */
  int _saveValue, _saveFog;

  /** @nodoc */
  int _save_state;

  CATVizCursor::CATVizStyle _PreviousCursor;
  int _inEdgeCursor;


  /** @nodoc */
  int _synchroMode;
  /** @nodoc */
  CATNavigation3DViewer();
  /** @nodoc */
  CATNavigation3DViewer(const CATNavigation3DViewer&);
  /** @nodoc */
  CATNavigation3DViewer& operator=(const CATNavigation3DViewer&);
};

#endif
