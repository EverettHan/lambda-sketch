#ifndef CATVid3DCamera_H 
#define CATVid3DCamera_H
// COPYRIGHT DASSAULT SYSTEMES 2012
//------------------------------------------------------------------------------

#include "CATVisImmersivePanel.h"
#include "CATMathDirection.h"
#include "CATMathPoint.h"
#include "CAT4x4Matrix.h"
/**
* Value class defining a camera. Inspired by CATViz3DCamera, but it is only a value class, 
* and not the implementation of 
*/
class ExportedByCATVisImmersivePanel CATVid3DCamera
{
public:
  enum CameraType{ConicCamera=0, CylindricCamera};
  /** Constructor.*/
  CATVid3DCamera();
  /**
  * Constructs a 3D camera.
  * @param iOrigin
  *    the origin of the 3D camera.
  * @param iDirection
  *    the sight direction of the 3D camera (must be perpendicular to the up direction).
  * @param iZenith
  *    the up direction of the 3D camera (must be perpendicular to the sight direction).
  */
  CATVid3DCamera(const CATMathPoint& i_origin, const CATMathDirection& i_direction, const CATMathDirection& i_zenith);
  /** Destructor.*/
  ~CATVid3DCamera();
  /**
  * Changes the type of a 3D camera.
  * @param iCameraType
  *    New camera type. 
  *   <br><b> Legal values</b>:
  *   <li><tt>CAT3DConicCamera</tt> 3D perspective projection</li>
  *   <li><tt>CylindricCamera</tt> 3D parallel projection</li>.
  *   <li><tt>CAT3DUnknownCamera</tt> Any type of 3D projection</li>
  * @See CameraType
  */
  void SetType(CameraType iCameraType);
  /**
  * Returns the type of a camera. 
  * @see CameraType
  */
  CameraType    GetType() const;
  /**
  * Returns the origin (eye position) of a 3D camera.
  */
  const CATMathPoint& GetOrigin() const;
  /**
  * Returns the sight direction of a 3D camera.
  */
  const CATMathDirection&  GetDirection() const;
  /**
  * Returns the up direction of a 3D camera.
  */
  const CATMathDirection& GetZenith() const;
  /**
  * Computes and return the target of a camera.
  */
  CATMathPoint GetTarget() const;
  /**
  * Changes the origin of a 3D camera.
  * It results a translation of the camera.
  * @param iOrigin
  *    New position of the camera origin.
  */
  void SetOrigin(const CATMathPoint& iOrigin);
  /**
  * Changes the sight direction of a 3D camera.
  * It results a rotation of the camera around it's origin.
  * @param iDirection
  *    New sight direction of the camera.
  *    This direction must be perpendicular to the up direction.
  */
  void SetDirection(const  CATMathDirection& iDirection);
  /**
  * Changes the up direction of a 3D camera.
  * It results a rotation of the camera around it's sight direction.
  * @param iZenith
  *    New up direction of the camera.
  *    This direction must be perpendicular to the sight direction.
  */
  void SetZenith(const CATMathDirection& iZenith);
  /**
  * Changes the target point of a 3D camera.
  * It results a change of the camera sight direction.
  * @param iTarget
  *    New target point of the camera.
  */
  void SetTarget(const CATMathPoint& iTarget);
  /**
  * Returns the view angle of a 3D conic camera.
  * It is the half of the vertical vision field angle (in degrees).
  */
  CATAngle GetViewAngle() const;
  /**
  * Changes the view angle of a 3D conic camera.
  * @param iViewAngle
  *    New view angle of the camera.
  *    It is the half of the vertical vision field angle (in degrees).
  */
  void SetViewAngle( CATAngle iViewAngle);
  /**
  * Returns the zoom value of a 3D cylindric camera.
  */
  double GetZoom() const;
  /**
  * Changes the zoom value of a 3D cylindric camera.
  * @param iZoom
  *    New zoom value of the camera. iZoom must be >=0 . 
  */
  void SetZoom(double iZoom);

  /**
  * Returns the near and far planes
  * @param oNear
  *    Near plane distance
  * @param oFar
  *    Far plane distance
  */
  void GetNearAndFarPlanes( double &oNear, double &oFar );

  /**
  * Changes the near and far plane values
  * @param iNear
  *    Near plane distance
  * @param iFar
  *    Far plane distance
  */
  void SetNearAndFarPlanes( double iNear, double iFar );

  /**
  * Returns the gravity direction of the camera
  */
  const CATMathDirection& GetGravityDirection() const;

  /**
  * Changes the gravity direction of the camera
  * @param iGravity
  *    gravity direction
  */
  void SetGravityDirection(const CATMathDirection& iGravity);

  /** @return the camera model/view matrix */
  CAT4x4Matrix ComputeModelViewMatrix() const;
  /** == operator.*/
  unsigned char operator==(const CATVid3DCamera& i_right) const;
  /** != operator.*/
  unsigned char operator!=(const CATVid3DCamera& i_right) const;
  /** = operator.*/
  CATVid3DCamera &operator =(const CATVid3DCamera &i_right);
private:
  CATMathDirection CheckDirection(const CATMathDirection& i_dir1, const CATMathDirection& i_dir2);
private:
  CameraType            _cameraType;
  CATMathPoint     _origin; 
  CATMathDirection _direction; 
  CATMathDirection _zenith; 
  CATMathDirection _gravity; 
  double  _targetDistance; 
  CATAngle          _viewAngle;
  double            _near;
  double            _far;
}; 

#include <CATSYPDeclareBoxing.h>
CATSYP_DECLARE_BOXING(ExportedByCATVisImmersivePanel, CATVid3DCamera);

#endif
