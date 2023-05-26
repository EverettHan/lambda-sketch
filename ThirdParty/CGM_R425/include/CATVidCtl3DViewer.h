// COPYRIGHT Dassault Systemes 2011
//===================================================================
//  Oct 2011  Creation: jov
//===================================================================
#ifndef CATVidCtl3DViewer_H
#define CATVidCtl3DViewer_H

#include <CATVisImmersivePanel.h>
#include <CATVidCtlViewerBase.h>
#include <CATVidInformation.h>
#include <CATVisRepresentationRole.h>
#include <CATVisInvalidationToken.h>
#include <CATMotionEvent.h>
#include <CATVid3DCamera.h>
#include <CATPickPath.h>
#include <CATSYPArray.h>

class CATViewer;
class CATVidCtlDlgContainer;
class CATVidGPSquare;
class CATIndicator;
class CATRep;
class CATViewpoint;
class CAT3DLightSourceRep;
class CAT3DBoundingSphere;
class CAT3DViewer;

/**
 * This component is a 3D specialization of the CATVidCtlViewerBase.
 */
class ExportedByCATVisImmersivePanel CATVidCtl3DViewer: public CATVidCtlViewerBase
{
  CATDeclareClass;
public:
  /**
   * Default constructor. 
   */
  CATVidCtl3DViewer();
  /**
   * Static method allowing to create a %CATVidCtl3DViewer.
   * @param i_pParent the CATCommand parent, used to send events.
   * @param i_pIdentifier the name of the widget.
   * @returns the created %CATVidCtl3DViewer
   */
  static CATVidCtl3DViewer* Create3DViewer(CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
  * Static method allowing to create a %CATVidCtl3DViewer.
  * @param i_pParent the CATCommand parent, used to send events.
  * @param i_pIdentifier the name of the widget.
  * @returns the created %CATVidCtl3DViewer
  */
  static CATVidCtl3DViewer* Create3DViewer(CATCommand *i_pParent, const CATString & i_pIdentifier, CAT3DViewer* i_pViewer);

  /**
   * Sets the camera.
   */
  void SetCamera(const CATVid3DCamera& i_camera);
  /**
   * Updates the camera from the view if needed, and returns it.
   */
  const CATVid3DCamera& GetCamera();

  /**
   * Returns the pick path
   */
  const CATPickPath& GetPickPath();
  /** 
   * Sets the two CAT3DLightSourceRep associated to the viewer.  
   * If this method is not called, the lights that are used in the CtlViewer are the same of those of the viewer the widget is attached.
   * Note thate these light sources are used only if there is no ambiance that is set. That is if AutoAmbianceflag is 0 and AmbianceName is not set.
   * @param lightRep1 the first light source
   * @param lightRep2 the second light source
   */
  void SetLightSourceReps(CAT3DLightSourceRep* i_pLightRep1, CAT3DLightSourceRep* i_pLightRep2);
  /** 
   * Gets the two CAT3DLightSourceRep associated to the viewer.
   */
  void GetLightSourceReps(const CAT3DLightSourceRep *& o_pLightRep1, const CAT3DLightSourceRep *& o_pLightRep2);

  /**
   * Computes model point from a given pixel point.
   * @param i_x the x pixel value.
   * @param i_y the y pixel value
   * @return the corresponding floating point in model referential.
   */
  void ComputeModelFromPixel(int i_x, int i_y, CATMathPointf& o_near, CATMathPointf& o_far);

  /**
   * Computes pixel point from a given 2D model point.
   * @param i_x the x model point value.
   * @param i_y the y model point value
   * @param i_z the z model point value
   * @return the corresponding 2D floating point in view referential.
   */
  CATMathPoint2Df ComputePixelFromModel(float i_x, float i_y, float i_z = 0.f);

  /**
  * Modifies the camera so that the specified CAT3DBoundingSphere 
  * takes as much place as possible on the screen.
  * @param iBs3D The CAT3DBoundingSphere you want to reframe on
  * @see CAT3DBoundingSphere
  */
  void ReframeOn(const CAT3DBoundingSphere &i_boundingSphere);

  void SetCullingBox(const CATSYPConstArray<CATMathPointf>& i_pointsArray, const CATSYPConstArray<CATMathDirectionf>& i_directionsArray);
  void RemoveCullingBox();
protected:
  /** Destructor */
  virtual ~CATVidCtl3DViewer ();
  /** @copydoc CATVidCtlViewerBase#ReactOnViewpointModified*/
  virtual void ReactOnViewpointModified();
private:
  void UpdateCameraFromViewpoint();
private:
  CATVid3DCamera _camera;
  CATBoolean _cameraUpToDateFlag;
  CATPickPath _pickPath;
public:
  void SetHiddenViewer(CAT3DViewer* i_pViewer);
};
//-----------------------------------------------------------------------
#endif

