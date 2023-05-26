#include "CATVisFoundation.h"
#ifndef CAT2DViewpointEditor_H
#define CAT2DViewpointEditor_H
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
// Class :	CAT2DViewpointEditor
//		  CATManipulator
//		    CATDlgComponent
//------------------------------------------------------------------------------

#include "CATViewpointEditor.h"

#include "CATMathVectorf.h"
#include "CATMathPoint2D.h"

# define DBG(a) " "#a"=" << a

class CATViz2DViewer;
class CAT2DViewpoint;
class CAT2DViewpointEditor;
class CATManipulator;
class CAT2DRep;
class CAT2DIndicator;
class VisTouchGesture;
class CATMathVector2Df;
class CATMathPoint2Df;

/** 	Basic class of 2D Viewpoint manipulation describing the basic
 *      movements of manipulation.
 *     <p>
 *     Contains the basic movements that can be driven with devices.
 */
class ExportedByCATVisFoundation CAT2DViewpointEditor : public CATViewpointEditor
{
  CATDeclareClass;

  //------------------------------------------------------------------------------
public :

  enum Mode 
  {
    DefaultMode,
    ZoomMode, 
    ZoomAreaMode, 
    TranslateMode,
    RecenterMode
  };

  CAT2DViewpointEditor( const CATString &iName, CAT2DViewpoint &Viewpoint, const Mode iMode=DefaultMode);

  // Dialog interface
  virtual void Activate( CATNotification *event);
  virtual void EndActivate( CATNotification *event);

  void SetMode( const Mode iMode);

  void SpaceMove (const CATMathVectorf & translation);

  /**
   * Method to handle all keyboard events related to viewpoint location modification.
   */
  virtual void HandleKeyboardEvent(const CATNotification* ipEvent, CATVizViewer* ipViewer);

  /**
   * Method to handle all touch gestures related to viewpoint modification.
   */
  virtual void TouchGesture(const VisTouchGesture* ipTouchGesture);

  virtual CATBoolean IsMouseInsideClipped(const CATMathPoint2Df& ibottomLeft, const CATMathPoint2Df& itopRight);

  virtual void MouseWheelZoom(CATMouseEvent &MouseEvent);
  virtual void MouseWheelTranslate(CATMouseEvent &MouseEvent);

  //------------------------------------------------------------------------------
protected :

  // Referenced objects
  CAT2DViewpoint *_2DViewpoint;

  // Mouse Actions
 

  virtual void MouseTranslate( CATMouseEvent &MouseEvent);
  virtual void DriveZoom( CATMouseEvent &MouseEvent);
  virtual void Center( CATMouseEvent &MouseEvent);	// Center the indicated point
  virtual void RecenterWithAnimation( CATMouseEvent &MouseEvent);	// Center the indicated point

  virtual void StartViewpointDefinition( CATMouseEvent &MouseEvent);
  virtual void DriveViewpointDefinition( CATMouseEvent &MouseEvent);
  virtual void StopViewpointDefinition( CATMouseEvent &MouseEvent);

  // Keyboard actions
  virtual void KeyboardTranslate( CATKeyboardEvent &KeyboardEvent);
  virtual void KeyZoom( CATKeyboardEvent &KeyboardEvent);

  //  Tools of viewpoint movement
  void Jump( const CATMathVectorf &DeltaCommand);

  //  Touch methods
  HRESULT EndTouchManipulate();
  HRESULT TouchManipulate(const VisTouchGesture * ipGesture);

  // Touch actions
  virtual HRESULT Navigate(const VisTouchGesture* ipGesture);
  virtual HRESULT Zoom(float iZoomDisplacement);
  virtual HRESULT Translate(const CATMathVector2Df& iTranslationVector);
  virtual HRESULT Recentring(const CATMathPoint2Df& iRecentringPoint);
  virtual HRESULT Reframe();
  virtual HRESULT PinchZoom(const CATMathPoint2Df& iZoomCenter , float iZoomDisplacement);
  virtual HRESULT RecentringTouch(const CATMathPoint2Df& iRecentringPoint);
  virtual HRESULT ReframeTouch();

  // Mode
  Mode _Mode;

  // ZoomArea
  void DrawIndicationRectangle();
  void UndrawIndicationRectangle();

  // ViewpointDestroyed
  void ViewpointDestroyedCB(CATCallbackEvent, void *, CATNotification *Event, CATSubscriberData , CATCallback);

  //------------------------------------------------------------------------------
private :

  // ZoomArea
  CAT2DIndicator *_ViewpointIndicator;
  CAT2DRep *_2DRectangleRep;	// Feedback of the rectangle zone
  CATMathPoint2D _BottomLeft, _TopRight;

};
#endif
