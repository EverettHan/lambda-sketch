// COPYRIGHT DASSAULT SYSTEMES	<1998>
//=============================================================================
//
// Function CATReframeOn :
// This Function is the interface to Reframe On a specific selection.
//
//=============================================================================
// Usage Notes:
//
//  IHSO       : the HSO to use.
//  In3DViewer : Is the viewer where the reframe has to be done.
//
//=============================================================================

class CATXSO;
class CATHSO;
class CAT3DViewer;
class CAT2DViewer;
class CAT3DBoundingSphere;
class CAT2DBoundingBox;
class CATViewpoint;

#include "CATVisController.h"
#include <stdlib.h>

ExportedByCATVisController void  CATReframeOn(CATHSO &iHSO, CAT3DViewer * In3DViewer);
ExportedByCATVisController void  CATReframeOn(CATXSO &iXSO, CAT3DViewer * In3DViewer);

ExportedByCATVisController void  CATReframeOn(CATHSO &iHSO, CAT2DViewer * In2DViewer);
ExportedByCATVisController void  CATReframeOn(CATXSO &iXSO, CAT2DViewer * In2DViewer);

ExportedByCATVisController CAT3DBoundingSphere Get3DBoundingSphereOn(CATXSO &iXSO, CATViewpoint * iViewpoint = NULL);
ExportedByCATVisController CAT3DBoundingSphere Get3DBoundingSphereOnXSO(CATXSO &iXSO, CATViewpoint * iViewpoint);

ExportedByCATVisController CAT2DBoundingBox Get2DBoundingBoxOn(CATXSO &iXSO);
