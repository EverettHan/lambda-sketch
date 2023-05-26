#ifndef CATFrm3DCamera_H 
#define CATFrm3DCamera_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//------------------------------------------------------------------------------
// Abstract: Implementation of 3D Conic Camera
//
//------------------------------------------------------------------------------
// Usage:    Each visualizable Document can have one or more saved viewpoints.
//
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
// Main methods:    
//
//       
//------------------------------------------------------------------------------

#include "CATAfrFoundation.h"
#include "CATFrmCamera.h"
//#include "CATICamera.h"

#include "CATMathDirection.h"
#include "CATMathPoint.h"
#include "CATMathDef.h"

#include "CATUnicodeString.h"

/**
 * deprecated V5R16
 * <br>Instead, use the factory @href CATCreateDefaultCamera in CATCameraToolkit to create a camera and
 * the APIs of the interface @href CATICamera and @href CATI3DCamera
 * <br>Implementation class of the CATI3DCamera interface.
 * <br><b>Role</b>:This implementation class provides methods to manage
 * parameters of a 3D camera. 
 * @see CAT3DViewpoint
 */
class ExportedByCATAfrFoundation CATFrm3DCamera: public CATFrmCamera
{
//------------------------------------------------------------------------------
   CATDeclareClass;

 public:


// Constructor / Destructor
// ------------------------
/**
 * Constructs a 3D camera with default parameters.
 * @param iName
 *    the name of the 3D camera.
 */
   CATFrm3DCamera(CATUnicodeString iName);
/**
 * Constructs a 3D camera.
 * @param iName
 *    the name of the 3D camera.
 * @param iOrigin
 *    the origin of the 3D camera.
 * @param iDirection
 *    the sight direction of the 3D camera (must be perpendicular to the up direction).
 * @param iZenith
 *    the up direction of the 3D camera (must be perpendicular to the sight direction).
 */
   CATFrm3DCamera(CATUnicodeString iName, CATMathPoint iOrigin,  CATMathDirection iDirection,  CATMathDirection iZenith);
   virtual ~CATFrm3DCamera();

/**
 * Makes a 3D camera identical with another one in copying all its parameters.
 * @param iCamera
 *    camera to copy.
 */
   virtual void CopyFrom(CATICamera * iCamera);
 
// CATICamera data
// ---------------
/**
 * Changes the type of a 3D camera.
 * @param iCameraType
 *    New camera type. 
 *   <br><b> Legal values</b>:
 *   <li><tt>CAT3DConicCamera</tt> 3D perspective projection</li>
 *   <li><tt>CAT3DCylindricCamera</tt> 3D parallel projection</li>.
 *   <li><tt>CAT3DUnknownCamera</tt> Any type of 3D projection</li>
 * @See CATCameraType
 */
   virtual void             SetType(CATCameraType iCameraType);

/** @nodoc */
   virtual void WriteToStream(void ** stream, CATULONG32& length);
/** @nodoc */
   virtual void ReadFromStream(void * stream, CATULONG32  length);

// CATI3DCamera data
// -----------------
/**
 * Returns the origin (eye position) of a 3D camera.
 */
   virtual CATMathPoint      GetOrigin() ;
/**
 * Returns the sight direction of a 3D camera.
 */
   virtual CATMathDirection  GetDirection() ;
/**
 * Returns the up direction of a 3D camera.
 */
   virtual CATMathDirection  GetZenith() ;
/**
 * Returns the target point of a 3D camera.
 */
   virtual CATMathPoint      GetTarget() ;

/**
 * Changes the origin of a 3D camera.
 * It results a translation of the camera.
 * @param iOrigin
 *    New position of the camera origin.
 */
   virtual void              SetOrigin( CATMathPoint iOrigin);
/**
 * Changes the sight direction of a 3D camera.
 * It results a rotation of the camera around it's origin.
 * @param iDirection
 *    New sight direction of the camera.
 *    This direction must be perpendicular to the up direction.
 */
   virtual void              SetDirection( CATMathDirection iDirection);
/**
 * Changes the up direction of a 3D camera.
 * It results a rotation of the camera around it's sight direction.
 * @param iZenith
 *    New up direction of the camera.
 *    This direction must be perpendicular to the sight direction.
 */
   virtual void              SetZenith( CATMathDirection iZenith);
/**
 * Changes the target point of a 3D camera.
 * It results a change of the camera sight direction.
 * @param iTarget
 *    New target point of the camera.
 */
   virtual void              SetTarget( CATMathPoint iTarget);

// CATI3DConicCamera data
// ----------------------
/**
 * Returns the view angle of a 3D conic camera.
 * It is the half of the vertical vision field angle (in degrees).
 */
   virtual CATAngle          GetViewAngle() ;
/**
 * Changes the view angle of a 3D conic camera.
 * @param iViewAngle
 *    New view angle of the camera.
 *    It is the half of the vertical vision field angle (in degrees).
 */
   virtual void              SetViewAngle( CATAngle iViewAngle);

// CATI3DCylindricCamera data
// --------------------------
/**
 * Returns the zoom value of a 3D cylindric camera.
 */
   virtual double            GetZoom() ;
/**
 * Changes the zoom value of a 3D cylindric camera.
 * @param iZoom
 *    New zoom value of the camera. iZoom must be >=0 . 
 */
   virtual void              SetZoom(double iZoom);

 private:

   CATMathPoint             _origin; 
   CATMathDirection         _direction; 
   CATMathDirection         _zenith; 
   CATPositiveLength        _targetDistance; 

   CATAngle                 _viewAngle;
   double                   _zoom;

   CATMathDirection         VerifyDirection(CATMathDirection dir1, CATMathDirection dir2);
}; 
#endif
