#ifndef CATGeoMap3DViewpointEditor_H
#define CATGeoMap3DViewpointEditor_H
//
// CATIA Version 6 Release 1 Framework Visualization
// Copyright Dassault Systemes 2008
//------------------------------------------------------------------------------
// Abstract : 	Basic class of Viewpoint manipulation of a (3D) viewer. Drive
//		the basic movement and the side movement
//------------------------------------------------------------------------------
// Usage :	Derive from this class to give a specific behaviour of your
//		manipulation in the xxxManipulate methods 
//------------------------------------------------------------------------------
// Class :	CATGeoMap3DViewpointEditor
//		      CAT3DViewpointEditor
//		      CATViewpointEditor
//		      CATCommand
//------------------------------------------------------------------------------
#include "CATVisFoundation.h"

#include "CAT3DViewpointEditor.h"
#include "CAT3DViewpoint.h"
#include "CATString.h"

class CATNotification;
class CATVizViewer;
class CATMouseEvent;
class CATKeyboardEvent;

/**
* Class defining the basic Local Transformation behavior.
*/
class ExportedByCATVisFoundation CATGeoMap3DViewpointEditor : public CAT3DViewpointEditor
{
   CATDeclareClass;

//------------------------------------------------------------------------------
public :

   /** Create a viewpoint editor that will modify the 3D viewpoint.
   *  To be activated, the viewpointEditor has to be declared to the viewer
   *  with CATViewer::SetViewpointEditor( iViewpointEditor)
   *  @param iName name for record
   *  @param iViewpoint The viewpoint manipulated.
   */
   CATGeoMap3DViewpointEditor( const CATString & iName, CAT3DViewpoint & iViewpoint);

   virtual ~CATGeoMap3DViewpointEditor();

   /** 
   * Activate the Viewpoint editor. This method is called by the viewers only.
   * The activation is called when the Viewpoint editor is attached to the viewer.
   * see CATViewer::SetViewpointEditor
   */
   virtual void Activate( CATNotification *event);

   /** 
   * Begin the manipulation of  the Viewpoint editor. This method is called by the viewers only
   */
   virtual void BeginManipulate( CATNotification *event);
   /** 
   * Manipulate the Viewpoint editor. This method is called by the viewers only
   */
   virtual void Manipulate( CATNotification *event);
   /** 
   * Ends the manipulation of the Viewpoint editor. This method is called by the viewers only
   */
   virtual void EndManipulate( CATNotification *event);

   /**
   * Method to handle all keyboard events related to viewpoint modification.
   */
   virtual void HandleKeyboardEvent(const CATNotification * ipEvent, CATVizViewer * ipViewer);

   /**
   * Method to handle mouse wheel events for viewpoint zooming
   */
   virtual int ZoomOnWheel(const CATNotification* ipEvent);

   /**
   * Set the mode of viewpoint manipulation. And configure the state diagram of the dialog.
   * SHOULD BE PROTECTED METHOD
   */
   virtual void SetMode( const CATBasic3DViewpointEditorMode iMode = VPEditorDefaultMode);

//------------------------------------------------------------------------------
protected :

   /**
   * Method to handle mouse events for viewpoint translation
   */
   virtual void StartMouseTranslate( CATMouseEvent & MouseEvent);
   virtual void DriveMouseTranslate( CATMouseEvent & MouseEvent);
   virtual void StopMouseTranslate ( CATMouseEvent & MouseEvent);
   virtual void TranslateOnPlane( float translatX, float translatY);

   /**
   * Method to handle mouse events for viewpoint rotation
   */
   virtual void StartMouseRotate( CATMouseEvent & MouseEvent);
   virtual void DriveMouseRotate( CATMouseEvent & MouseEvent);
   virtual void StopMouseRotate ( CATMouseEvent & MouseEvent);
   virtual void RotateAroundPoint( float translatX, float translatY);

   virtual void SetDefaultAction();
   virtual void SynchronizeViewpoint();

   //virtual CATMathPointf GetDynamicRotationCenter(CATNotification * event = NULL);
   virtual CATMathPoint GetDynamicRotationCenter(CATNotification * event = NULL);
   virtual CATMathPointf GetDynamicViewpointTarget();

   CAT3DRep * CreateRotationAxisRep(const CATMathPointf & rotationCenter);

   CATBasic3DViewpointEditorMode _EditorMode;

//------------------------------------------------------------------------------
//private :

};
#endif

