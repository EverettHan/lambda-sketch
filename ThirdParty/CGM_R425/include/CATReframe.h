// COPYRIGHT DASSAULT SYSTEMES	<2020>
//=============================================================================
//
// Function CATReframe :
// This Function is the interface to Reframe On a specific selection.
//
//=============================================================================
// Usage Notes:
//
//  IHSO       : the HSO to use.
//  In3DViewer : Is the viewer where the reframe has to be done.
//
//=============================================================================

class CATVizViewer;
class CAT3DViewpoint;
class CAT2DViewpoint;
class CAT3DBoundingSphere;

#include "CATVisFoundation.h"

ExportedByCATVisFoundation void CATReframe(CATVizViewer* iVizViewer, CAT3DViewpoint& ipMain3DViewpoint, int iViewpointAnimationMode);
ExportedByCATVisFoundation void CATReframe(CATVizViewer* iVizViewer, CAT3DViewpoint& ipMain3DViewpoint, CAT3DBoundingSphere& i3DBoundingSphere, int iViewpointAnimationMode);
ExportedByCATVisFoundation void CATReframe(CATVizViewer* iVizViewer, CAT2DViewpoint& ipMain2DViewpoint, int iViewpointAnimationMode);

