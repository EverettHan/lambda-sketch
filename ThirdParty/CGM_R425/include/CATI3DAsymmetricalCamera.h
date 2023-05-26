#ifndef CATI3DAsymmetricalCamera_H
#define CATI3DAsymmetricalCamera_H

// COPYRIGHT DASSAULT SYSTEMES 2003

//===========================================================================
// Interface for 3D Viewpoint Manipulation
//===========================================================================
#include "CATVisItf.h"
#include "CATI3DCamera.h"

class CATMathDirection;
class CATViewer;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATI3DAsymmetricalCamera;
#else
extern "C" const IID IID_CATI3DAsymmetricalCamera;
#endif
/**
 * Interface to make 3D asymmetrical viewpoint persistent.
 * <b>Role</b>:
 * This interface class provides the prototype of methods to manage
 * the projection direction of 3D camera. 
 * @see CATICamera , CATI3DCamera, CAT3DViewpoint
 */
class  ExportedByCATVisItf CATI3DAsymmetricalCamera : public CATI3DCamera
{
   CATDeclareInterface;

   public:

// Get/Set 3D Asymmetrical Camera data
// -----------------------------------
/**
 * Returns: 0 if the projection direction is the same than sight direction.
 *          1 otherwise.
 */
   virtual int               IsProjectionDirection() =0;
/**
 * Returns the projection direction of a 3D camera.
 */
   virtual CATMathDirection  GetProjectionDirection() =0;
/**
 * Changes the projection direction of a 3D camera.
 * It results a difference between the projection direction and the sight direction.
 * @param iDirection
 *    New projection direction of the camera.
 */
   virtual void              SetProjectionDirection( CATMathDirection iDirection) =0;
/**
 * Apply the 3D asymmetrical camera to the current active viewer.
 * It results an asymmetrical viewpoint.
 * @param iViewer
 *    The viewer to which the asymmetrical camera will be applied.
 */
   virtual void              ApplyToViewer(CATViewer * iViewer) =0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler(CATI3DAsymmetricalCamera, CATI3DCamera);

#endif
