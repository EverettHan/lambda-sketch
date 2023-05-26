#ifndef CATVisLight_H
#define CATVisLight_H

#include "SGInfra.h"

#include "CATVisSpace.h"

#include "CATDataType.h"
#include "CATVisColorf.h"
#include "CATMathVectorf.h"
#include "IVisTexturePtr.h"


/** @class This class represents a light.
 *  It can be added to the visualization scene through CATSGCATVisTransaction.
 *  @see CATSceneGraph, CATSGCATVisTransaction
 *  @warning This is only managed by NRE.
 */
class ExportedBySGInfra CATVisLight
{
public:
  /** Increment reference counter for lifecycle management
   *  On object creation, the reference counter starts at 1.
   */
  void AddRef() const;
  /** Decrement reference counter for lifecycle management
   *  If the reference counter reaches 0, this light is automatically destroyed.
   */
  void Release() const;

  enum EType
  {
    ePoint,
    eDirectional,
    eSpot,
    eProfiled,
    eArea_Sphere,
    eArea_Disk,
    eArea_Tube,
    eArea_Rectangle,
    eUnknownType
  };

  /** Gets this light type
   *  @return The light type
   */
  virtual const EType GetType() const { return eUnknownType; }

  /** Cloning method
   *  @return The duplication result
   */
  virtual CATVisLight* Clone() const = 0;

  enum EEvent
  {
    eModification_Channels,
    eModification_Space,
    eModification_Size,
    eModification_Strength,
    eModification_Color,
    eModification_Other,
    eDestruction
  };

  /** @class This class represents the light callback interface.
   *  It must be inherited and registered to a light in order to catch light events.
   */
  class CallbackItf
  {
  public:
    virtual void OnEvent(const CATVisLight* iLight, EEvent iEvent) = 0;
  };
  
  /** Registers a callback interface object 
   *  On this light changes, the "OnEvent" method will be called on all registered callback interface objects.
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

  /** Activates this light on a specific channel
   *  There is a maximum of 7 supported channels.
   *  @param iChannelIndex The channel index (from 1 to 7)
   *  @return true if the light can be activated for asked channel
   */
  bool ActivateOnChannel(const unsigned int iChannelIndex);
  /** Deactivates this light on a specific channel
   *  There is a maximum of 7 supported channels.
   *  @param iChannelIndex The channel index (from 1 to 7)
   *  @return true if the light can be deactivated for asked channel
   */
  bool DeactivateOnChannel(const unsigned int iChannelIndex);
  /** Deactivates this light all channels
   *  By default, a light is activate for all channels.
   */
  void DeactivateOnAllChannels();
  /** Sets channels that this object lights
   *  There is a maximum of 8 supported channels which are given through the 8 first bits of iChannels.
   *  @param iChannels The channels list (by flags field)
   */
  void SetLightedChannels(const CATULONG32 iChannels);
  /** Gets channels that this object lights
   *  @return The channels list (by flags field)
   */
  const CATULONG32 GetLightedChannels() const { return m_LightedChannels; }

  static const unsigned int kChannelsCount;
  static const CATULONG32 kAllChannels;

  /** Indicates which kind of space definition this light requires
   *  @return The required space kind
   */
  virtual const CATVisSpace::FComponents GetRequiredSpace() const { return CATVisSpace::fNone; }

  /** Sets the light position
   *  @param iPos The light position
   *  @return true if this light requires the position parameter in its kind of space
   */
  virtual bool SetPosition(const CATMathPoint& iPos) { return false; }
  /** Gets the light position
   *  @return The light position
   */
  virtual const CATMathPoint& GetPosition() const { return s_ErrorPoint; }

  /** Sets the light main direction
   *  @param iPos The light main direction
   *  @return true if this light requires the main direction parameter in its kind of space
   */
  virtual bool SetDirection(const CATMathDirectionf& iDir) { return false; }
  /** Gets the light main direction
   *  @return The light main direction
   */
  virtual const CATMathDirectionf& GetDirection() const { return s_ErrorDir; }

  /** Sets the light up direction
   *  @param iPos The light up direction
   *  @return true if this light requires the up direction parameter in its kind of space
   */
  virtual bool SetUpDirection(const CATMathDirectionf& iDir) { return false; }
  /** Gets the light up direction
   *  @return The light up direction
   */
  virtual const CATMathDirectionf& GetUpDirection() const { return s_ErrorDir; }

  /** Gets the light right direction
   *  No setter for right direction, it is the result of the cross product between the other directions
   *  @return The light right direction
   */
  virtual const CATMathDirectionf GetRightDirection() const { return s_ErrorDir; }
  
  enum EStrengthUnit
  {
    eScalar,      // Constant
    ePower,       // lm
    eIntensity,   // cd
    eIlluminance, // lm/m^2
    eLuminance    // cd/m^2
  };

  /** Indicates which kind of unit must be considered when a "strength" is set up
   *  @return The kind of dimensional homogeneity
   */
  virtual const EStrengthUnit GetStrengthUnit() const { return eScalar; }

  /** Sets the light "strength"
   *  Call "GetStrengthUnit" to get the light "strength" unit
   *  @param iStrength The light "strength"
   *  @return true if the given "strength" is valid
   */
  bool SetStrength(const float iStrength);
  /** Gets the light "strength"
   *  @return The light "strength"
   */
  const float GetStrength() const { return m_Strength; }

  /** Sets the light color
   *  @param iColor The light color
   */
  void SetColor(const CATVisColorf& iColor) { m_Color = iColor; _Event(eModification_Color); }
  /** Gets the light color
   *  @return The light color
   */
  const CATVisColorf& GetColor() const { return m_Color; }
  
  static const CATVisColorf kWhite;

private:
  CATVisLight(const CATVisLight&);
  CATVisLight& operator =(const CATVisLight&);

  CallbackItf** m_CBIftObjects;
  unsigned int m_CBCount;

  mutable int m_RefCount;
  CATULONG32 m_LightedChannels;

protected:
  static const CATULONG32 kLegacyChannel;
  static const CATULONG32 kInternalAllChannels;

  CATVisLight(const CATULONG32 iChannels = kInternalAllChannels);
  virtual ~CATVisLight();
  
  static const CATMathPoint s_ErrorPoint;
  static const CATMathDirectionf s_ErrorDir;
  
  void _Event(EEvent iType) const;

  float m_Strength;
  CATVisColorf m_Color;
};


/** 
 * @class This class represents a point light.
 */
class ExportedBySGInfra CATVisPointLight : public CATVisLight
{
public:
  /** Point light creation method
   *  @param iPos The light position
   *  @param iPower The light power
   *  @param iColor The light color
   *  @return The created point light
   */
  static CATVisPointLight* Create(const CATMathPoint& iPos, const float iPower, const CATVisColorf& iColor = kWhite);

  // Overridden methods
  const EType GetType() const { return ePoint; }
  CATVisLight* Clone() const;

  const CATVisSpace::FComponents GetRequiredSpace() const { return CATVisSpace::fPosition; }

  bool SetPosition(const CATMathPoint& iPos) { m_Position = iPos; _Event(eModification_Space); return true; }
  const CATMathPoint& GetPosition() const { return m_Position; }
  
  const EStrengthUnit GetStrengthUnit() const { return ePower; }
  
private:
  CATMathPoint m_Position;

  CATVisPointLight(const CATULONG32 iChannels = kInternalAllChannels);
  virtual ~CATVisPointLight();
};


/**
 * @class This class represents a directional light.
 */
class ExportedBySGInfra CATVisDirectionalLight : public CATVisLight
{
public:
  /** Directional light creation method
   *  @param iDir The light direction
   *  @param iIlluminance The light illuminance
   *  @param iColor The light color
   *  @return The created directional light
   */
  static CATVisDirectionalLight* Create(const CATMathDirectionf& iDir, const float iIlluminance, const CATVisColorf& iColor = kWhite);

  // Overridden methods
  const EType GetType() const { return eDirectional; }
  CATVisLight* Clone() const;

  const CATVisSpace::FComponents GetRequiredSpace() const { return CATVisSpace::fDirection; }

  bool SetDirection(const CATMathDirectionf& iDir) { m_Direction = iDir; _Event(eModification_Space); return true; }
  const CATMathDirectionf& GetDirection() const { return m_Direction; }
  
  const EStrengthUnit GetStrengthUnit() const { return eIlluminance; }
  
private:
  CATMathDirectionf m_Direction;

  CATVisDirectionalLight(const CATULONG32 iChannels = kInternalAllChannels);
  virtual ~CATVisDirectionalLight();
};


/**
 * @class This class represents a spot light.
 */
class ExportedBySGInfra CATVisSpotLight : public CATVisLight
{
public:
  /** Spot light creation method
   *  @param iPos The light position
   *  @param iDir The light direction
   *  @param iInAngle The spot inner angle in degree (before falloff starts)
   *  @param iOutAngle The spot outer angle in degree (when falloff ends)
   *  @param iPower The light power
   *  @param iColor The light color
   *  @return The created spot light
   */
  static CATVisSpotLight* Create(const CATMathPoint& iPos, const CATMathDirectionf& iDir, const float iInAngle, const float iOutAngle, const float iPower, const CATVisColorf& iColor = kWhite);

  /** Sets the spot angles (in degree)
   *  @param iOuter The outer angle (beyond this angle, there won't be any lighting)
   *  @param iInner The inner angle (below this angle, the lighting will have a constant intensity)
   *  @return true if given angles are valid and compatible
   */
  bool SetAngles(const float iOuter, const float iInner = 0.0)
  {
    if ( iInner < 0.0f || iOuter > 180.0f || iInner > iOuter ) return false;
    m_InnerAngle = iInner;
    m_OuterAngle = iOuter;
    _Event(eModification_Other);
    return true;
  }
  /** Gets the inner angle
   *  @return The inner angle (in degree)
   */
  const float GetInnerAngle() const { return m_InnerAngle; }
  /** Gets the outer angle
   *  @return The inner outer (in degree)
   */
  const float GetOuterAngle() const { return m_OuterAngle; }
  
  // Overridden methods
  const EType GetType() const { return eSpot; }
  CATVisLight* Clone() const;

  const CATVisSpace::FComponents GetRequiredSpace() const { return CATVisSpace::fPosAndDir; }

  bool SetPosition(const CATMathPoint& iPos) { m_Position = iPos; _Event(eModification_Space); return true; }
  const CATMathPoint& GetPosition() const { return m_Position; }

  bool SetDirection(const CATMathDirectionf& iDir) { m_Direction = iDir; _Event(eModification_Space); return true; }
  const CATMathDirectionf& GetDirection() const { return m_Direction; }

  const EStrengthUnit GetStrengthUnit() const { return ePower; }
  
private:
  CATMathPoint m_Position;
  CATMathDirectionf m_Direction;
  
  float m_InnerAngle;
  float m_OuterAngle;

  CATVisSpotLight(const CATULONG32 iChannels = kInternalAllChannels);
  virtual ~CATVisSpotLight();
};


/**
 * @class This class represents a profiled light.
 */
class ExportedBySGInfra CATVisProfiledLight : public CATVisLight
{
public:
  /** Profiled light creation method
   *  @param iPos The light position
   *  @param iDir The light direction
   *  @param iUpDir The light up direction
   *  @param iSphericalIntensity The profile spherical intensity texture
   *  @param iFactor Factor for the spherical intensity
   *  @param iColor The light color
   *  @return The created profile light
   */
  static CATVisProfiledLight* Create(const CATMathPoint& iPos, const CATMathDirectionf& iDir, const CATMathDirectionf& iUpDir, const IVisTexturePtr& iSphericalIntensity, const float iFactor = 1.0, const CATVisColorf& iColor = kWhite);

  /** Sets the profile spherical intensity
   *  @param iInt The profile spherical intensity texture
   *  @return true if the new profile has been set properly
   */
  bool SetSphericalIntensity(const IVisTexturePtr& iInt)
  {
    if (!iInt || IVisTextureType::eTexture2D != iInt->GetType()) return false;
    m_Profile = iInt;
    _Event(eModification_Other);
    return true;
  }
  /** Gets the profile spherical intensity
   *  @return The profile spherical intensity texture
   */
  const IVisTexturePtr& GetSphericalIntensity() const { return m_Profile; }

  // Overridden methods
  const EType GetType() const { return eProfiled; }
  CATVisLight* Clone() const;

  const CATVisSpace::FComponents GetRequiredSpace() const { return CATVisSpace::fReferential; }

  bool SetPosition(const CATMathPoint& iPos) { m_Position = iPos; _Event(eModification_Space); return true; }
  const CATMathPoint& GetPosition() const { return m_Position; }

  bool SetDirection(const CATMathDirectionf& iDir);
  const CATMathDirectionf& GetDirection() const { return m_Direction; }

  bool SetUpDirection(const CATMathDirectionf& iDir);
  const CATMathDirectionf& GetUpDirection() const { return m_UpDirection; }

  const CATMathDirectionf GetRightDirection() const { return CATMathDirectionf(m_Direction ^ m_UpDirection); }

  const EStrengthUnit GetStrengthUnit() const { return eScalar; }
  
private:
  CATMathPoint m_Position;
  CATMathDirectionf m_Direction;
  CATMathDirectionf m_UpDirection;

  IVisTexturePtr m_Profile;

  CATVisProfiledLight(const CATULONG32 iChannels = kInternalAllChannels);
  virtual ~CATVisProfiledLight();
};


/**
 * @class This class is the base class for all area light types.
 */
class ExportedBySGInfra CATVisAreaLight : public CATVisLight
{
public:
  // Overridden methods
  bool SetPosition(const CATMathPoint& iPos) { m_Position = iPos; _Event(eModification_Space); return true; }
  const CATMathPoint& GetPosition() const { return m_Position; }

  const EStrengthUnit GetStrengthUnit() const { return ePower; }

protected:
  CATMathPoint m_Position;

  CATVisAreaLight(const CATULONG32 iChannels = kInternalAllChannels);
  virtual ~CATVisAreaLight();
};


/**
 * @class This class represents a sphere area light.
 */
class ExportedBySGInfra CATVisSphereLight : public CATVisAreaLight
{
public:
  /** Sphere area light creation method
   *  @param iPos The light position
   *  @param iRadius The sphere radius
   *  @param iPower The light power
   *  @param iColor The light color
   *  @return The created sphere area light
   */
  static CATVisSphereLight* Create(const CATMathPoint& iPos, const float iRadius, const float iPower, const CATVisColorf& iColor = kWhite);

  /** Sets the sphere radius
   *  @param iRadius The sphere radius
   *  @return true if the given radius is valid
   */
  bool SetRadius(const float iRadius);
  /** Gets the sphere radius
   *  @return the sphere radius
   */
  const float GetRadius() const { return m_Radius; }

  // Overridden methods
  const EType GetType() const { return eArea_Sphere; }
  CATVisLight* Clone() const;

  const CATVisSpace::FComponents GetRequiredSpace() const { return CATVisSpace::fPosition; }

private:
  float m_Radius;

  CATVisSphereLight(const CATULONG32 iChannels = kInternalAllChannels);
  virtual ~CATVisSphereLight();
};


/**
 * @class This class represents a disk area light.
 */
class ExportedBySGInfra CATVisDiskLight : public CATVisAreaLight
{
public:
  /** Disk area light creation method
   *  @param iPos The light position
   *  @param iDir The light direction
   *  @param iRadius The disk radius
   *  @param iPower The light power
   *  @param iColor The light color
   *  @return The created disk area light
   */
  static CATVisDiskLight* Create(const CATMathPoint& iPos, const CATMathDirectionf& iDir, const float iRadius, const float iPower, const CATVisColorf& iColor = kWhite);

  /** Sets the disk radius
   *  @param iRadius The disk radius
   *  @return true if the given radius is valid
   */
  bool SetRadius(const float iRadius);
  /** Gets the disk radius
   *  @return the disk radius
   */
  const float GetRadius() const { return m_Radius; }

  // Overridden methods
  const EType GetType() const { return eArea_Disk; }
  CATVisLight* Clone() const;

  const CATVisSpace::FComponents GetRequiredSpace() const { return CATVisSpace::fPosAndDir; }

  bool SetDirection(const CATMathDirectionf& iDir) { m_Direction = iDir; _Event(eModification_Space); return true; }
  const CATMathDirectionf& GetDirection() const { return m_Direction; }

private:
  CATMathDirectionf m_Direction;

  float m_Radius;

  CATVisDiskLight(const CATULONG32 iChannels = kInternalAllChannels);
  virtual ~CATVisDiskLight();
};


/**
 * @class This class represents a tube area light.
 */
class ExportedBySGInfra CATVisTubeLight : public CATVisAreaLight
{
public:
  /** Tube area light creation method
   *  @param iPos The light position
   *  @param iDir The light direction
   *  @param iUpDir The light up direction
   *  @param iRadius The tube radius
   *  @param iLength The tube length
   *  @param iPower The light power
   *  @param iColor The light color
   *  @return The created tube area light
   */
  static CATVisTubeLight* Create(const CATMathPoint& iPos, const CATMathDirectionf& iDir, const CATMathDirectionf& iUpDir, const float iRadius, const float iLength, const float iPower, const CATVisColorf& iColor = kWhite);

  /** Sets the disk radius
   *  @param iRadius The disk radius
   *  @return true if the given radius is valid
   */
  bool SetRadius(const float iRadius);
  /** Gets the disk radius
   *  @return the disk radius
   */
  const float GetRadius() const { return m_Radius; }

  /** Sets the disk length
   *  @param iRadius The disk length
   *  @return true if the given length is valid
   */
  bool SetLength(const float iLength);
  /** Gets the disk length
   *  @return the disk length
   */
  const float GetLength() const { return m_Length; }  

  // Overridden methods
  const EType GetType() const { return eArea_Tube; }
  CATVisLight* Clone() const;

  const CATVisSpace::FComponents GetRequiredSpace() const { return CATVisSpace::fReferential; }

  bool SetDirection(const CATMathDirectionf& iDir);
  const CATMathDirectionf& GetDirection() const { return m_Direction; }

  bool SetUpDirection(const CATMathDirectionf& iDir);
  const CATMathDirectionf& GetUpDirection() const { return m_UpDirection; }

  const CATMathDirectionf GetRightDirection() const { return CATMathDirectionf(m_Direction ^ m_UpDirection); }

private:
  CATMathDirectionf m_Direction;
  CATMathDirectionf m_UpDirection;

  float m_Radius;
  float m_Length;

  CATVisTubeLight(const CATULONG32 iChannels = kInternalAllChannels);
  virtual ~CATVisTubeLight();
};


/**
 * @class This class represents a rectangle area light.
 */
class ExportedBySGInfra CATVisRectangleLight : public CATVisAreaLight
{
public:
  /** Rectangle area light creation method
   *  @param iPos The light position
   *  @param iDir The light direction
   *  @param iUpDir The light up direction
   *  @param iRightSize The rectangle size following the right direction axis
   *  @param iUpSize The rectangle size following the up direction axis
   *  @param iPower The light power
   *  @param iColor The light color
   *  @return The created rectangle area light
   */
  static CATVisRectangleLight* Create(const CATMathPoint& iPos, const CATMathDirectionf& iDir, const CATMathDirectionf& iUpDir, const float iRightSize, const float iUpSize, const float iPower, const CATVisColorf& iColor = kWhite);

  /** Sets the rectangle size following the right direction axis
   *  @param iSize The rectangle size
   *  @return true if the given size is valid
   */
  bool SetRightSize(const float iSize);
  /** Gets the rectangle size following the right direction axis
   *  @return the rectangle size
   */
  const float GetRightSize() const { return m_RightSize; }

  /** Sets the rectangle size following the up direction axis
   *  @param iSize The rectangle size
   *  @return true if the given size is valid
   */
  bool SetUpSize(const float iSize);
  /** Gets the rectangle size following the up direction axis
   *  @return the rectangle size
   */
  const float GetUpSize() const { return m_UpSize; }

  // Overridden methods
  const EType GetType() const { return eArea_Rectangle; }
  CATVisLight* Clone() const;

  const CATVisSpace::FComponents GetRequiredSpace() const { return CATVisSpace::fReferential; }

  bool SetDirection(const CATMathDirectionf& iDir);
  const CATMathDirectionf& GetDirection() const { return m_Direction; }

  bool SetUpDirection(const CATMathDirectionf& iDir);
  const CATMathDirectionf& GetUpDirection() const { return m_UpDirection; }

  const CATMathDirectionf GetRightDirection() const { return CATMathDirectionf(m_Direction ^ m_UpDirection); }

private:
  CATMathDirectionf m_Direction;
  CATMathDirectionf m_UpDirection;

  float m_RightSize;
  float m_UpSize;

  CATVisRectangleLight(const CATULONG32 iChannels = kInternalAllChannels);
  virtual ~CATVisRectangleLight();
};

#endif
