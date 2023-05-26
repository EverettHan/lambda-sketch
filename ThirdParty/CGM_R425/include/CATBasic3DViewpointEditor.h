#ifndef CATBasic3DViewpointEditor_H
#define CATBasic3DViewpointEditor_H
//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	Basic class of Viewpoint manipulation of a (3D) viewer. Drive
//		the basic movement and the side movement
//------------------------------------------------------------------------------
// Usage :	Derive from this class to give a specific behaviour of your
//		manipulation in the xxxManipulate methods 
//------------------------------------------------------------------------------
// Class :	CATBasic3DViewpointEditor
//		  CATViewpointEditor
//		    CATCommand
//------------------------------------------------------------------------------
#include "CATVisFoundation.h"

#include "CAT3DViewpointEditor.h"
#include "CATMathPoint2D.h"
#include "CATMathVectorf.h"

class CAT3DViewpoint;
class CATMouseEvent;
class CATKeyboardEvent;
class CAT2DRectangleRep;
class CAT2DRep;
class CAT2DIndicator;
class CATSpaceExamine;
class CATSpaceListenerBase;
/*
enum CATBasic3DViewpointEditorMode {
  VPEditorRotateMode, 
  VPEditorRotateAxisMode, 
  VPEditorZoomMode, 
  VPEditorZoomAreaMode,
  VPEditorLookAtMode,
  VPEditorTranslateMode,
  VPEditorTiltMode,
  VPEditorFullMode,
  VPEditorMechMode,
  VPEditorKeepSightMode,
  VPEditorExamineMode, 
  VPEditorWalkMode,
  VPEditorFlyMode,
  VPEditorDirectFlyMode,
  VPEditorDirectWalkMode};
*/
/**
* Class defining the basic Local Transformation behavior.
*/
class ExportedByCATVisFoundation CATBasic3DViewpointEditor : public CAT3DViewpointEditor
{
 CATDeclareClass;

//------------------------------------------------------------------------------
  public :
    /** Create the viewpoint editor that will modify the 3D viewpoint with
     * the basic dialogs
     *  To be activated, the viewpointEditor has to be declared to the viewer
     *  with CATViewer::SetViewpointEditor( iViewpointEditor)
     *  @param iName name for record
     *  @param iViewpoint The viewpoint manipulated.
     *  @param iMode The style of manipulation
     *  <ul>
     *  <li> VPEditorExamineMode : It is the most used : translation/rotate/zoom
     *  <li> VPEditorWalkMode : walk in the fixed from horizontal plane
     *  <li> VPEditorFlyMode : Fly in space 
     *  <li> VPEditorRotateMode : only rotate
     *  <li> VPEditorZoomMode : only zoom
     *  <li> VPEditorZoomAreaMode : only the definition of viewpoint with zoom area
     *  <li> VPEditorLookAtMode : only the definition of viewpoint with pyramid
     *  <li> VPEditorTranslateMode : only translate
     *  <li> VPEditorTiltMode : only tilt
     *  <li> VPEditorMechMode : (SHOULD deseapears : now identical to Examine)
     *  <li> VPEditorKeepSightMode : only translation and zoom (the sight direction does not change)
     *  </ul>
     */
    CATBasic3DViewpointEditor( const CATString &iName, CAT3DViewpoint &Viewpoint,
	  const CATBasic3DViewpointEditorMode iMode=VPEditorExamineMode);
    virtual ~CATBasic3DViewpointEditor();

    /** 
     * Activate the Viewpoint editor. This method is called by the viewers only.
     * The activation is called when the Viewpoint editor is attached to the viewer.
     * see CATViewer::SetViewpointEditor
     */
    virtual void Activate( CATNotification *event);
    
    /** 
     * Ends the manipulation and reconfigure the dialog. In fly and walk modes, the dialog has
     * been changed.
     */
    virtual void EndManipulate( CATNotification *event);
    
    /**
     * Set the mode of viewpoint manipulation. And configure the state diagram of the dialog.
     * SHOULD BE PROTECTED METHOD
     */
    virtual void SetMode( const CATBasic3DViewpointEditorMode iMode);
    
    /**
     * Get the mode of viewpoint manipulation. SHOULD BE PROTECTED METHOD
     */
    virtual CATBasic3DViewpointEditorMode GetMode() const;
  virtual void SpaceMove (CATMathVectorf& translation, CATMathVectorf& rotation);

  inline void SetHandTrackingMode(int mode) { _handTrackingMode=mode;}
  inline void SetHeadTrackingMode(int mode) { _headTrackingMode=mode;}
  inline int GetHandTrackingMode() { return _handTrackingMode;}
  inline int GetHeadTrackingMode() { return _headTrackingMode;}

//------------------------------------------------------------------------------
  protected :
    virtual void Seek( CATMouseEvent &MouseEvent);
    virtual void StepBack( CATMouseEvent &MouseEvent);
    virtual void ToggleSpeed( CATMouseEvent &MouseEvent);
    virtual void DoNothing( CATMouseEvent &MouseEvent);
    virtual void StartThisTilt( CATMouseEvent &MouseEvent);
    virtual void StartAnimation( CATMouseEvent &MouseEvent);

    // ZoomArea
    virtual void StartZoomArea( CATMouseEvent &MouseEvent);
    virtual void DriveZoomArea( CATMouseEvent &MouseEvent);
    virtual void StopZoomArea( CATMouseEvent &MouseEvent);
    virtual void StartDirectFly ( CATMouseEvent &MouseEvent);
    virtual void StopDirectFly ( CATMouseEvent &MouseEvent);

    void DrawIndicationRectangle();
    void UndrawIndicationRectangle();

    virtual void SetAutoSpaceTargetSuspend(const int suspend);
    virtual int GetAutoSpaceTargetSuspend();
    virtual void CalculateAutoSpaceTarget();

    virtual void OnViewpointModified(CATCallbackEvent Id, void *From,
      CATNotification *Event, CATSubscriberData Data, CATCallback Callback);

    CATBasic3DViewpointEditorMode _EditorMode;

//------------------------------------------------------------------------------
  private :
    // ZoomArea
    CAT2DIndicator *_ViewpointIndicator;
    CAT2DRep *_2DRectangleRep;	// Feedback of the rectangle zone
    CATMathPoint2D _BottomLeft, _TopRight;
    CATMathPoint2Df _PressPosition;
    int _spaceAnimation;
    CATMathVectorf _spaceDrift;
    CATSpaceExamine *_pSpaceExamine;
    int _ModifiedCB;
    int _showSpaceTargetSuspend;
    int _headTrackingMode;
    int _handTrackingMode;

};
#endif

