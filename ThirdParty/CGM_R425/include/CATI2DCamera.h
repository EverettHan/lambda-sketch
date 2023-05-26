#ifndef CATI2DCAMERA_H
#define CATI2DCAMERA_H
// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#include "CATVisItf.h"
//===========================================================================
// General Interface for 2D Viewpoint Manipulation
//===========================================================================
#include "CATICamera.h"

class CATMathPoint2D;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATI2DCamera;
#else
extern "C" const IID IID_CATI2DCamera;
#endif
/**
 * Interface to make 2D viewpoint persistent.
 * <b>Role</b>:
 * This interface class provides the prototype of methods to manage
 * the parameters of 2D camera. 
 * @see CATICamera , CAT2DViewpoint
 */
class  ExportedByCATVisItf CATI2DCamera : public CATICamera
{
   CATDeclareInterface;

   public:

// Get/Set 2D Camera data
// ----------------------
/**
 * Returns the origin (eye position) of a 2D camera.
 */
   virtual CATMathPoint2D GetOrigin() =0;
/**
 * Changes the origin of 2D camera.
 * It results a translation of the camera.
 * @param iOrigin
 *    New position of the camera origin.
 */
   virtual void           SetOrigin(CATMathPoint2D iOrigin)=0;

/**
 * Returns the scale value of a 2D camera.
 */
   virtual double         GetScale() =0;
/**
 * Changes the scale value of a 2D camera.
 * @param iScale
 *    New scale value of the camera. This value must be >=0
 */
   virtual void           SetScale(double iScale)=0;
}; 

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler(CATI2DCamera, CATICamera);

#endif
