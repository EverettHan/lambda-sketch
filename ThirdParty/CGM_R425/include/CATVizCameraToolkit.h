#ifndef CATVizCameraToolkit_H
#define CATVizCameraToolkit_H

// COPYRIGHT DASSAULT SYSTEMES 2005

//------------------------------------------------------------------------------
// Abstract: Provide services for 
//             - apply standard camera to VizViewer.
//             - retrieving camera from viewpoint/VizViewer.
//             - setting camera to viewpoint/VizViewer.
//             - create standard camera list.
//------------------------------------------------------------------------------
// Usage:    
//------------------------------------------------------------------------------
// Inheritance: None
//------------------------------------------------------------------------------
// Main methods:    
//
//           CATCreateCameraFromViewer
//           CATCreateCameraFromViewpoint
//           CATApplyCameraToViewer
//           CATApplyCameraToViewpoint
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"

//system
#include "CATUnicodeString.h"
#include "CATBoolean.h"
#include "CATListPV.h" 

class CATVizViewer;
class CATViewpoint;
class CATVizCamera;

/**
 * Apply a standard camera to a viewer.
 * @param iViewer 
 *   The viewer to which a standard camera is to be applied. Camera is applied to the 
 *   main viewpoint of the viewer.
 * @param iStdCameraName
 *   Standard camera name.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if the standard camera applied succeesfuly.
 *   <dt><tt>E_FAIL</tt>  <dd>if failed to apply the standard camera.
 *   </dl>
 */
ExportedByCATVisFoundation HRESULT CATVizApplyStandardCamera (CATVizViewer * iViewer, 
                                                    CATUnicodeString &iStdCameraName);     

/**
 * Creates a camera from a viewer.
 * @param iViewer 
 *   The viewer from which a camera is created. Camera is created form the main 
 *   viewpoint of the viewer.
 * @param opCamera 
 *   The address where the returned pointer to the CATVizCamera will be located. 
 *   Calling function is responcible to call Release on the camera created by this function.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if the query succeeds.
 *   <dt><tt>E_FAIL</tt>  <dd>if the camera creation fails.
 *   </dl>
 * @see CATVizCamera 
 */
ExportedByCATVisFoundation HRESULT CATVizCreateCameraFromViewer (CATVizViewer * iViewer, 
                                                       CATVizCamera *&opCamera);     


/**
 * Creates a camera from a viewpoint.
 * @param iViewpoint 
 *   The viewpoint from which a camera is created.
 * @param opCamera 
 *   The address where the returned pointer to the CATVizCamera will be located.
 *   Calling function is responcible to call Release on the camera created by this function.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if the query succeeds.
 *   <dt><tt>E_FAIL</tt>  <dd>if the camera creation fails.
 *   </dl>
 * @see CATViewpoint
 */
ExportedByCATVisFoundation HRESULT CATVizCreateCameraFromViewpoint (CATViewpoint * iViewpoint, 
                                                          CATVizCamera *&opCamera);     

/**
 * Applies a camera to a viewer.
 * @param ioViewer 
 *   The viewer to which a camera is applied. Camera is aplied to main viewpoint of viewer
 * @param ipICamera 
 *   The pointer to the CATVizCamera which defines the camera to apply.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if the query succeeds.
 *   <dt><tt>E_FAIL</tt>  <dd>if fails to apply camera.
 *   </dl>
 * @see CATVizCamera
 */
ExportedByCATVisFoundation HRESULT CATVizApplyCameraToViewer (CATVizViewer * ioViewer, 
                                                    CATVizCamera * ipCamera);     


/**
 * Applies a camera to a viewpoint.
 * @param ioViewpoint 
 *   The viewpoint to which a camera is applied.
 * @param ipCamera 
 *   The pointer to the CATVizCamera which defines the camera to apply.
 * @param iReframeRequested 
 *   The boolean value requesting a reframe on the viewpoint.
 *   <br><b>Legal values:</b>: must be set to @href TRUE if reframe is to be performed.
 *   Default is false @href FALSE.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if the query succeeds.
 *   <dt><tt>E_FAIL</tt>  <dd>if fails to apply camera.
 *   </dl>
 * @see CATViewpoint
 */
ExportedByCATVisFoundation HRESULT CATVizApplyCameraToViewpoint (CATViewpoint * ioViewpoint, 
                                                       CATVizCamera * ipCamera,
                                                       CATBoolean iReframeRequested=FALSE); 

/**
 * Creats list of standard cameras.
 * @param iViewer
 *   The viewer for which standard camera list is required. Camera list is created by 
 *   looking at type of viewer (2D/3D) and type of viewpoint (2D/3D).
 * @param oStdCameraList
 *   The list of CATVizCamera of the type CATListPV containing standard cameras.
 *   Make sure, while calling the function, that the list provided is empty.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if camera list is created.
 *   <dt><tt>E_FAIL</tt>  <dd>if fails to create camera list.
 *   </dl>
 */
ExportedByCATVisFoundation HRESULT CATVizCreateStandardCameraList (CATVizViewer * iViewer,
                                                         CATListPV &oStdCameraList);     

/**
 * Creats list of standard cameras for 3D viewer.
 * @param oStdCameraList
 *   The list of CATVizCamera of the type CATListPV containing standard cameras.
 *   Make sure, while calling the function, that the list provided is empty.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if camera list is created.
 *   <dt><tt>E_FAIL</tt>  <dd>if fails to create camera list.
 *   </dl>
 */
ExportedByCATVisFoundation HRESULT CATVizCreateStandardCameraList3DViewer(CATListPV &oStdCameraList);

/**
 * Creats list of standard cameras for 2D viewer.
 * @param oStdCameraList
 *   The list of CATVizCamera of the type CATListPV containing standard cameras.
 *   Make sure, while calling the function, that the list provided is empty.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if camera list is created.
 *   <dt><tt>E_FAIL</tt>  <dd>if fails to create camera list.
 *   </dl>
 */
ExportedByCATVisFoundation HRESULT CATVizCreateStandardCameraList2DViewer(CATListPV &oStdCameraList);

/**
 * Creats list of standard cameras for graph viewer.
 * @param oStdCameraList
 *   The list of CATVizCamera of the type CATListPV containing standard cameras.
 *   Make sure, while calling the function, that the list provided is empty.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if camera list is created.
 *   <dt><tt>E_FAIL</tt>  <dd>if fails to create camera list.
 *   </dl>
 */
ExportedByCATVisFoundation HRESULT CATVizCreateStandardCameraListGraphViewer(CATListPV &oStdCameraList);


#endif //CATVizCameraToolkit_H


