#ifndef CATVisCamera_H
#define CATVisCamera_H

#include "SGInfra.h"

#include "CATVisSpace.h"

#include "CATMathVectorf.h"


/** @class This class represents a camera.
 *  It can be added to the visualization scene through CATSGCATVisTransaction.
 *  It must be selected as active camera to modify the viewpoint.
 *  @see CATSceneGraph, CATSGCATVisTransaction
 *  @warning This is only managed by NRE.
 */
class ExportedBySGInfra CATVisCamera
{
public:
  /** Increment reference counter for lifecycle management
   *  On object creation, the reference counter starts at 1.
   */
  void AddRef() const;
  /** Decrement reference counter for lifecycle management
   *  If the reference counter reaches 0, this camera is automatically destroyed.
   */
  void Release() const;
  
  enum EType
  {
    ePerspective,
    eOrthogonal,
    eUnknownType
  };

  /** Gets this camera type
   *  @return The camera type
   */
  virtual const EType GetType() const { return eUnknownType; }

  enum EEvent
  {
    eModification_Space,
    eModification_NearFar,
    eModification_Other,
    eDestruction
  };

  /** @class This class represents the camera callback interface.
   *  It must be inherited and registered to a light in order to catch camera events.
   */
  class CallbackItf
  {
  public:
    virtual void OnEvent(const CATVisCamera* iCamera, EEvent iEvent) = 0;
  };
    
  /** Registers a callback interface object 
   *  On this camera changes, the "OnEvent" method will be called on all registered callback interface objects.
   *  @warning This method is not thread-safe!
   *  @param iCBItfObj The callback interface object to register
   *  @return true if the callback interface object was properly registered (if it wasn't already registered)
   */
  bool RegisterCallback(CallbackItf* iCBItfObj);
  /** Unregisters a callback interface object 
   *  @warning This method is not thread-safe!
   *  @param iCBItfObj The callback interface object to unregister
   *  @return true if the callback interface object was properly unregistered (if it was registered before)
   */
  bool UnregisterCallback(CallbackItf* iCBItfObj);

  /** Sets the camera position
   *  @param iPos The camera position
   */
  void SetPosition(const CATMathPoint& iPos) { m_Position = iPos; _Event(eModification_Space); }
  /** Gets the camera position
   *  @return The camera position
   */
  const CATMathPoint& GetPosition() const { return m_Position; }

  /** Sets the camera main direction
   *  @param iPos The camera main direction
   */
  void SetDirection(const CATMathDirectionf& iDir);
  /** Gets the camera main direction
   *  @return The camera main direction
   */
  const CATMathDirectionf& GetDirection() const { return m_Direction; }

  /** Sets the camera up direction
   *  @param iPos The camera up direction
   */
  void SetUpDirection(const CATMathDirectionf& iDir);
  /** Gets the camera up direction
   *  @return The camera up direction
   */
  const CATMathDirectionf& GetUpDirection() const { return m_UpDirection; }

  /** Gets the light right direction
   *  No setter for right direction, it is the result of the cross product between the other directions.
   *  @return The light right direction
   */
  const CATMathDirectionf GetRightDirection() const { return CATMathDirectionf(m_Direction ^ m_UpDirection); }


  /** Sets the near and far plane distances computation activation
   *  When it is activated, the near and far plane distances will be computed from the displayed scene bounding sphere.
   *  @param iNear The near plane distance
   */
  void SetAutoNearFarDistances(const bool iAuto) { if (iAuto != m_AutoNearFar) { m_AutoNearFar = iAuto; _Event(eModification_NearFar); } }
  /** Gets if the near and far plane distances computation is active
   *  @return true if the near and far plane distances computation is active
   */
  bool IsAutoNearFarDistances() const { return m_AutoNearFar; }

  /** Sets the near plane distance
   *  @param iNear The near plane distance
   *  @return true if given near plane distance is valid
   */
  bool SetNearDistance(const float iNear);
  /** Gets the near plane distance
   *  @return The near plane distance
   */
  const float GetNearDistance() const { return m_Near; }

  /** Sets the far plane distance
   *  @param iNear The far plane distance
   *  @return true if given far plane distance is valid
   */
  bool SetFarDistance(const float iFar);
  /** Gets the far plane distance
   *  @return The far plane distance
   */
  const float GetFarDistance() const { return m_Far; }


  /** Sets the camera focus distance
   *  @param iFocus The camera focus distance
   *  @return true if given distance is valid
   */
  bool SetFocusDistance(const float iFocus);
  /** Gets the camera focus distance
   *  @return The camera focus distance
   */
  const float GetFocusDistance() const { return m_FocusDistance; }

  /** Sets the camera angle (in degree)
   *  @param iAngle The camera angle
   *  @return true if given angle is valid
   */
  bool SetAngle(const float iAngle);
  /** Gets the camera angle
   *  @return The camera angle (in degree)
   */
  const float GetAngle() const { return m_Angle; }

  /** Sets the camera aperture
  *  @param iAperture The camera aperture
  *  @return true if given aperture is valid
  */
  bool SetAperture(const float iAperture);
  /** Gets the camera aperture
  *  @return The camera aperture
  */
  const float GetAperture() const { return m_Aperture; }

private:
  CATVisCamera(const CATVisCamera&);
  CATVisCamera& operator =(const CATVisCamera&);

  CallbackItf** m_CBIftObjects;
  unsigned int m_CBCount;

  mutable int m_RefCount;

protected:
  CATVisCamera(const CATMathPoint& iPos, const CATMathDirectionf& iDir, const CATMathDirectionf& iUpDir);
  virtual ~CATVisCamera();

  void _Event(EEvent iType) const;

  CATMathPoint m_Position;
  CATMathDirectionf m_Direction;
  CATMathDirectionf m_UpDirection;

  bool  m_AutoNearFar;
  float m_Near;
  float m_Far;

  float m_FocusDistance;
  float m_Angle;
  float m_Aperture;
};


/** 
 * @class This class represents a perspective camera.
 */
class ExportedBySGInfra CATVisPerspectiveCamera : public CATVisCamera
{
public:
  /** Perspective camera creation method
   *  @param iPos The camera position (eye world position)
   *  @param iDir The camera direction (eye world direction)
   *  @param iUpDir The camera up direction
   *  @return The created perspective camera
   */
  static CATVisPerspectiveCamera* Create(const CATMathPoint& iPos, const CATMathDirectionf& iDir, const CATMathDirectionf& iUpDir);

  // Overridden methods
  const EType GetType() const { return ePerspective; }


  /** Sets the number of the camera blades
   *  @param iBlades The bumber of blades
   *  @return true if given number is valid
   */
  bool SetBlades(const int iBlades);
  /** Gets the number of the camera blades
   *  @return The camera angle (in degree)
   */
  const int GetBlades() const { return m_Blades; }

  /** Sets the rotation angle of the camera blades
   *  @param iBladeRotation The rotation angle of the camera blades in degrees
   *  @return true if given angle is valid
   */
  bool SetBladeRotation(const float iBladeRotation);
  /** Gets the rotation angle of camera blades
   *  @return The camera blades rotation angle (in degree)
   */
  const float GetBladeRotation() const { return m_BladeRotation; }

private:
  CATVisPerspectiveCamera(const CATMathPoint& iPos, const CATMathDirectionf& iDir, const CATMathDirectionf& iUpDir);
  ~CATVisPerspectiveCamera(); // Not virtual: final class

  int m_Blades = 6;         // The number of camera blades. According to 3DXM spec v.3.2 the default number is 6
  float m_BladeRotation;    // The rotation angle of the blades in degrees.  According to 3DXM spec v.3.2 the default value is 0
};


/**
 * @class This class represents an orthogonal camera.
 */
class ExportedBySGInfra CATVisOrthogonalCamera : public CATVisCamera
{
public:
  /** Orthogonal camera creation method
   *  @param iPos The camera position (eye world position)
   *  @param iDir The camera direction (eye world direction)
   *  @param iUpDir The camera up direction
   *  @return The created orthogonal camera
   */
  static CATVisOrthogonalCamera* Create(const CATMathPoint& iPos, const CATMathDirectionf& iDir, const CATMathDirectionf& iUpDir);

  // Overridden methods
  const EType GetType() const { return eOrthogonal; }

private:
  CATVisOrthogonalCamera(const CATMathPoint& iPos, const CATMathDirectionf& iDir, const CATMathDirectionf& iUpDir);
  ~CATVisOrthogonalCamera(); // Not virtual: final class
};

#endif
