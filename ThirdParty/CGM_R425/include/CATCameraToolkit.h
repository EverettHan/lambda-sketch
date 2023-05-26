#ifndef CATCameraToolkit_H
#define CATCameraToolkit_H

// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//------------------------------------------------------------------------------
// Abstract: Provide services for 
//             - retrieving camera from viewpoint.
//             - setting camera to viewpoint.
//           
//
//------------------------------------------------------------------------------
// Usage:    A CATFrmWindow is a rectanglar subarea of an application frame.
//           It allows to display and manipulate application data.
//           It has always a ApplicationWindow as Parent.
// 
//           This class will be derived by application to display in Windows
//           of the ApplicationFrame the application data.   
//------------------------------------------------------------------------------
// Inheritance: None
//------------------------------------------------------------------------------
// Main methods:    
//
//           CATCreateCameraFromViewer
//           CATCreateCameraFromViewpoint
//           CATCreateDefaultCamera
//           CATApplyCameraToViewer
//           CATApplyCameraToViewpoint
//=============================================================================
// Function:
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
#include "CATAfrFoundation.h"

#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATICamera.h"

class CATViewer;
class CATViewpoint;


/**
 * Creates a camera from a viewer.
 * @param iViewer 
 *   The viewer from which a camera is created. Camera is created form the main viewpoint of the viewer.
 * @param opICamera 
 *   The address where the returned pointer to the interface CATICamera is located.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if the query succeeds
 *   <dt><tt>E_FAILED</tt>  <dd>if the camera creation fails.
 *   </dl>
 * @see CATViewer
 */
ExportedByCATAfrFoundation HRESULT CATCreateCameraFromViewer (CATViewer * iViewer, CATICamera *&opICamera);     


/**
 * Creates a camera from a viewpoint.
 * @param iViewpoint 
 *   The viewpoint from which a camera is created.
 * @param opICamera 
 *   The address where the returned pointer to the interface CATICamera is located.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if the query succeeds
 *   <dt><tt>E_FAILED</tt>  <dd>if the camera creation fails.
 *   </dl>
 * @see CATViewpoint
 */
ExportedByCATAfrFoundation HRESULT CATCreateCameraFromViewpoint (CATViewpoint * iViewpoint, CATICamera *&opICamera);     


/**
 * Creates a camera with default parameters.
 * @param iCameraType 
 *   The type of camera.
 * @param opICamera 
 *   The address where the returned pointer to the interface CATICamera is located.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if the query succeeds
 *   <dt><tt>E_FAILED</tt>  <dd>if the camera creation fails.
 *   </dl>
 * @see CATCameraType
 */
ExportedByCATAfrFoundation HRESULT CATCreateDefaultCamera (CATCameraType iCameraType, CATICamera *&opICamera);     


/**
 * Applies a camera to a viewer.
 * @param ioViewer 
 *   The viewpoint to which a camera is applied.
 * @param ipICamera 
 *   The pointer to the interface CATICamera which defines the camera to apply.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if the query succeeds
 *   <dt><tt>E_FAILED</tt>  <dd>otherwise.
 *   </dl>
 * @see CATViewer
 */
ExportedByCATAfrFoundation HRESULT CATApplyCameraToViewer (CATViewer * ioViewer, CATICamera * ipICamera);     


/**
 * Applies a camera to a viewpoint.
 * @param ioViewpoint 
 *   The viewpoint to which a camera is applied.
 * @param ipICamera 
 *   The pointer to the interface CATICamera which defines the camera to apply.
 * @param iReframeRequested 
 *   The boolean value requesting a reframe on the viewpoint.
 * <br><b>Legal values:</b>: must be set to @href TRUE or @href FALSE.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if the query succeeds
 *   <dt><tt>E_FAILED</tt>  <dd>otherwise.
 *   </dl>
 * @see CATViewpoint
 */
ExportedByCATAfrFoundation HRESULT CATApplyCameraToViewpoint (CATViewpoint * ioViewpoint, CATICamera * ipICamera, CATBoolean iReframeRequested=FALSE);     


#endif

