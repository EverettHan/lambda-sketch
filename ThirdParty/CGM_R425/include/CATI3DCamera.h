#ifndef CATI3DCAMERA_H
#define CATI3DCAMERA_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

//===========================================================================
// General Interface for 3D Viewpoint Manipulation
//===========================================================================
#include "CATVisItf.h"
#include "CATICamera.h"

class CATMathPoint;
class CATMathDirection;
#include "CATMathDef.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATI3DCamera;
#else
extern "C" const IID IID_CATI3DCamera;
#endif
/**
 * Interface to make 3D viewpoint persistent.
 * <b>Role</b>:
 * This interface class provides the prototype of methods to manage
 * the parameters of 3D camera. 
 * @see CATICamera , CAT3DViewpoint
 */
class  ExportedByCATVisItf CATI3DCamera : public CATICamera
{
   CATDeclareInterface;

   public:

// Get/Set 3D Camera data
// ----------------------
/**
 * Returns the origin (eye position) of a 3D camera.
 */
   virtual CATMathPoint      GetOrigin() =0;
/**
 * Returns the sight direction of a 3D camera.
 */
   virtual CATMathDirection  GetDirection() =0;
/**
 * Returns the up direction of a 3D camera.
 */
   virtual CATMathDirection  GetZenith() =0;
/**
 * Returns the target point of a 3D camera.
 */
   virtual CATMathPoint      GetTarget() =0;

/**
 * Changes the origin of 3D camera.
 * It results a translation of the camera.
 * @param iOrigin
 *    New position of the camera origin.
 */
   virtual void              SetOrigin( CATMathPoint iOrigin)=0;
/**
 * Changes the sight direction of a 3D camera.
 * It results a rotation of the camera around it's origin.
 * @param iDirection
 *    New sight direction of the camera.
 *    This direction must be perpendicular to the up direction.
 */
   virtual void              SetDirection( CATMathDirection iDirection)=0;
/**
 * Changes the up direction of a 3D camera.
 * It results a rotation of the camera around it's sight direction.
 * @param iZenith
 *    New up direction of the camera.
 *    This direction must be perpendicular to the sight direction.
 */
   virtual void              SetZenith( CATMathDirection iZenith)=0;
/**
 * Changes the target point of a 3D camera.
 * It results a change of the camera sight direction.
 * @param iTarget
 *    New target point of the camera.
 */
   virtual void              SetTarget( CATMathPoint iTarget)=0;

// Get/Set 3D Conic Camera data
// ----------------------------
/**
 * Returns the view angle of a 3D conic camera.
 * It is the half of the vertical vision field angle (in degrees).
 * @see CATAngle
 */
   virtual CATAngle  GetViewAngle() =0;
/**
 * Changes the view angle of a 3D conic camera.
 * @param iViewAngle
 *    New view angle of the camera.
 *    It is the half of the vertical vision field angle (in degrees).
 * @see CATAngle
 */
   virtual void      SetViewAngle( CATAngle iViewAngle)=0;

// Get/Set 3D Cylindric Camera data
// --------------------------------
/**
 * Returns the zoom value of a 3D cylindric camera.
 */
   virtual double     GetZoom() =0;
/**
 * Changes the zoom value of a 3D cylindric camera.
 * @param iZoom
 *    New zoom value of the camera. This value must be >=0
 */
   virtual void       SetZoom( double iZoom)=0;

// Change 3D Camera Type
// ---------------------
/**
 * Changes the type of a 3D camera.
 * @param iCameraType
 *    New camera type.
 *   <br><b> Legal values</b>:
 *   <li><tt>CAT3DConicCamera</tt> for a 3D perspective projection</li>
 *   <li><tt>CAT3DCylindricCamera</tt> for a 3D parallel projection</li>.
 *   <li><tt>CAT3DUnknownCamera</tt> for any type of 3D projection</li>
 * @see CATCameraType
 */
   virtual void       SetType(CATCameraType iCameraType)=0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler(CATI3DCamera, CATICamera);

#endif
