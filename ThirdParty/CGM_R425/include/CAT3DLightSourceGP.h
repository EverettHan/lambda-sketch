#ifndef CAT3DLightSourceGP_H
#define CAT3DLightSourceGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATGraphicPrimitive.h"
#include "CATMathDirectionf.h"
#include "CATMathPointf.h"
#include "CATVizMacForMetaClass.h"
#include "CATVisMacroForInterfaces.h"
#include "CATTexturePixelImage.h"


class CATStreamer;

class IVisSG3DPrimitive;
class CAT3DLightSourceGPIVisSG3DPrimitiveBOAImpl;
class CAT3DLightSourceRep;

/**
* Type of light source.
* @param LS_INFINITE
*   Infinitely distant like the sun,
* @param LS_SPOT
*   Spotlight with a cutoff angle between 0 and 90 degrees,
*   or equal to 180 degrees (lightbulb equivalent)
* @param LS_AREA
*   Reserved, DO NOT USE!
* @param LS_PROFILE
*   Reserved, DO NOT USE!
*
* @see CAT3DLightSourceGP
*/
enum CATLightSourceType { LS_INFINITE, LS_SPOT, LS_AREA , LS_PROFILE };

/** @nodoc */
typedef CATLightSourceType LightSourceType;

/**
* Mode of light source.
* @param  Local
*  Attached to the viewpoint
* @param  Global
*  Attached to the model
* @see CAT3DLightSourceGP
*/
enum CATLightSourceMode { Local, Global };

/** @nodoc */
typedef CATLightSourceMode LightSourceMode ;

/** @nodoc */
enum CATLightSourceAreaType { InvalidAreaLight, SphereAreaLight, TubeAreaLight, DiskAreaLight, RectangleAreaLight };

/** @nodoc */
typedef CATLightSourceAreaType LightSourceAreaType;

typedef struct _LightsParameters
{
  _LightsParameters() : profile(NULL) {}

  ~_LightsParameters()
  {
    if ( NULL != profile )
    {
#ifdef ADDREFERENCE_MIGRATION
      profile->Release();
#else
      profile->SubReference();
      profile->Destroy();
#endif
      profile = NULL;
    }
  }

  CATLightSourceType      type;
  CATLightSourceMode      mode;
  CATMathPointf           origin;
  CATMathDirectionf       direction;
  CATMathDirectionf       up;
  CATMathDirectionf       right;
  float ambient[4];
  float diffuse[4];
  float specular[4];
  float areaGeometry[2]; // TODELETE AFTER IMPACT CHECK
  float spotAngle;
  float spotExponent;
  float spotInnerAngle;
  float constantAttenuation;
  float linearAttenuation;
  float quadraticAttenuation;
  float axialFalloffStart;
  float axialFalloffEnd;
  float areaType; // TODELETE AFTER IMPACT CHECK
  float areaStatus; // TODELETE AFTER IMPACT CHECK
  CATTexturePixelImage*   profile;
  CATLightSourceAreaType  areaShape;
  float areaSize[2];
  CATBoolean physical;
  float physPower;
} LightProperties;

#include "SGInfra.h"
/**
 * Class to create light source graphic primitives.
 * <b>Role</b>: A light source graphic primitive indicates the position
 * and orientation of lights in the viewer. A light source can be of
 * two different types : <br>
 *    <tt>LS_INFINITE</tt> infinitely distant like the sun,
 *    <tt>LS_SPOT</tt> spotlight with a cutoff angle between 0 and 90 degrees,
 *                     or equal to 180 degrees (lightbulb equivalent)
 * A light source can be of two differents modes : <br>
 *    <tt>Local</tt> attached to the viewpoint
 *    <tt>Global</tt> attached to the model
 * By default, one light source is created and activated. A viewer can handle
 * a maximum of eight light source graphic primitives.
 * To add a light source, prefer adding a CAT3DLightSourceRep.
 */
class ExportedBySGInfra CAT3DLightSourceGP : public CATGraphicPrimitive
{
  CATDeclareClass;
  CATVizDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT3DLightSourceGP, IVisSG3DPrimitive, CAT3DLightSourceGPIVisSG3DPrimitiveBOAImpl);

public:

  /** Constructs an empty light source graphic primitive of type LS_INFINITE. */
  CAT3DLightSourceGP();

  /**
   * Constructs a light source graphic primitive.
   * @param iType
   * The type of the light source.
   * @param iMode
   * The mode of the light source.
   * @param iOrigin
   * The location of the light source.
   * @param iDirection
   * The direction of the light source.
   * @param iSpotAngle
   * The cutoff angle of a spotlight.
   * @param iSpotExponent
   * value used for specular component calculations 
   * @param iConstantAttenuation
   * The constant factor of the attenuation equation.
   * @param iLinearAttenuation
   * The linear factor of the attenuation equation.
   * @param iQuadraticAttenuation
   * The quadraric factor of the attenuation equation.
   */
  CAT3DLightSourceGP (CATLightSourceType        iType,
		      CATLightSourceMode        iMode,
		      const CATMathPointf     & iOrigin,
		      const CATMathDirectionf & iDirection,
		      const float               iSpotAngle             = 180.f,
		      const float               iSpotExponent          = 0.f,
		      const float               iConstantAttenuation   = 1.f,
		      const float               iLinearAttenuation     = 0.f,
		      const float               iQuadraticAttenuation  = 0.f);

  /** @nodoc */
  CAT3DLightSourceGP(const LightSourceType      iType,
                     const LightSourceMode      iMode,
                     const CATMathPointf      & iOrigin,
                     const CATMathDirectionf  & iDirection,
                     const CATMathDirectionf  & iUp,
                     const CATMathDirectionf  & iRight,
                     const float              * iAmbient,
                     const float              * iDiffuse,
                     const float              * iSpecular,
                     const CATBoolean           iPhysical,
                     const float                iPhysPower,
                     CATTexturePixelImage     * iProfile,
                     const float                iSpotAngle,
                     const float                iSpotExponent,
                     const float                iSpotInnerAngle,
                     const float                iConstantAttenuation,
                     const float                iLinearAttenuation,
                     const float                iQuadraticAttenuation,
                     const float                iAxialFalloffStart,
                     const float                iAxialFalloffEnd,
                     const LightSourceAreaType  iAreaType,
                     const float              * iAreaSize);

  /** @nodoc TODELETE AFTER IMPACT CHECK */
  CAT3DLightSourceGP(const LightSourceType      iType,
                     const LightSourceMode      iMode,
                     const CATMathPointf      & iOrigin,
                     const CATMathDirectionf  & iDirection,
                     const CATMathDirectionf  & iUp,
                     const CATMathDirectionf  & iRight,
                     const float              * iAmbient,
                     const float              * iDiffuse,
                     const float              * iSpecular,
                     const float                iSpotAngle,
                     const float                iSpotExponent,
                     const float                iSpotInnerAngle,
                     const float                iConstantAttenuation,
                     const float                iLinearAttenuation,
                     const float                iQuadraticAttenuation,
                     const float                iAxialFalloffStart,
                     const float                iAxialFalloffEnd,
                     const float                iAreaType,
                     const float                iAreaStatus,
                     const float              * iAreaGeometry);

  /**
   * Retrieves the color components of the light source.
   * All float values are in [0,1].
   * @param oAmbient
   * Red, green, blue and alpha values of ambient component.
   * @param oDiffuse
   * Red, green, blue and alpha values of diffuse component.
   * @param oSpecular
   * Red, green, blue and alpha values of specular component.
   */
  inline void GetColor (const float       * oAmbient[4],
		        const float       * oDiffuse[4],
		        const float       * oSpecular[4]);

  /**
   * Sets the color components of the light source.
   * All float values are in [0,1].
   * @param iAmbient
   * Red, green, blue and alpha values of ambient component.
   * @param iDiffuse
   * Red, green, blue and alpha values of diffuse component.
   * @param iSpecular
   * Red, green, blue and alpha values of specular component.
   */
  inline void SetColor (const float         iAmbient[4],
		        const float         iDiffuse[4],
		        const float         iSpecular[4]);

  /**
   * Retrieves the parameters of a light source.
   * @param iType
   * The type of the light source.
   * @param oMode
   * The mode of the light source.
   * @param oOrigin
   * The point where the light source is located. This parameter has
   * no meaning for LS_INFINITE light sources.
   * @param oDirection
   * The direction of the light source.
   * @param oSpotAngle
   * The half-angle aperture of the cone of the spotlight.
   * @param oSpotExponent
   * The exponent value used for specular component calculations.
   * @param oConstantAttenuation
   * The constant factor of the attenuation function.
   * @param oLinearAttenuation
   * The light factor of the attenuation function.
   * @param oQuadraticAttenuation
   * The quadratic factor of the attenuation function.
   */
  inline void Get    (CATLightSourceType   & iType,
    CATLightSourceMode   & oMode,
    CATMathPointf     & oOrigin,
    CATMathDirectionf & oDirection,
    float             * oSpotAngle,
    float             * oSpotExponent,
    float             * oConstantAttenuation,
    float             * oLinearAttenuation,
    float             * oQuadraticAttenuation);

  /** @nodoc */
  void Get(CATLightSourceType & oType,
           CATLightSourceMode & oMode,
           CATMathPointf      & oOrigin,
           CATMathDirectionf  & oDirection,
           CATMathDirectionf  & oUp,
           CATMathDirectionf  & oRight,
           float              * oAmbient,
           float              * oDiffuse,
           float              * oSpecular,
           CATBoolean         * oPhysical,
           float              * oPhysPower,
           CATTexturePixelImage** oProfile,
           float              * oSpotAngle,
           float              * oSpotExponent,
           float              * oSpotInnerAngle,
           float              * oConstantAttenuation,
           float              * oLinearAttenuation,
           float              * oQuadraticAttenuation,
           float              * oAxialFalloffStart,
           float              * oAxialFalloffEnd,
           CATLightSourceAreaType& iAreaType,
           float              * oAreaSize);

  /** @nodoc TODELETE AFTER IMPACT CHECK */
  void Get(CATLightSourceType & oType,
           CATLightSourceMode & oMode,
           CATMathPointf      & oOrigin,
           CATMathDirectionf  & oDirection,
           CATMathDirectionf  & oUp,
           CATMathDirectionf  & oRight,
           float              * oAmbient,
           float              * oDiffuse,
           float              * oSpecular,
           float              * oSpotAngle,
           float              * oSpotExponent,
           float              * oSpotInnerAngle,
           float              * oConstantAttenuation,
           float              * oLinearAttenuation,
           float              * oQuadraticAttenuation,
           float              * oAxialFalloffStart,
           float              * oAxialFalloffEnd,
           float              * oAreaType,
           float              * oAreaStatus,
           float              * oAreaGeometry);

  /** @nodoc */
  void Get(LightProperties& p);
  
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override Draw function.")
#endif
  /** @nodoc */
  virtual void Draw (CATRender & render) GP_FUNC_OVERRIDE_FINAL;
  
  /** @nodoc
  *  Streams the graphic primitive of a light source.
  * <br><b>Role:</b>This method streams a <tt>CAT3DLightSourceGP</tt> .
  *  @param   oStr
  *    The streamer used to stream the <tt>CAT3DLightSourceGP</tt>.
  *  @param   iSavetype
  *    <br><b>legal values</b>
  *    <ul>
  *         <li>0 the name of the GP will not be saved</li>
  *         <li>1 the name of the GP will be saved</li>
  *    </ul>
  */
  virtual void Stream(CATStreamer& oStr,int iSavetype=0);
  
  /** @nodoc
  *  Unstreams the graphic primitive of a light source.
  * <br><b>Role:</b>This method unstreams a <tt>CAT3DLightSourceGP</tt> .
  *  @param   iStr
  *    The streamer used to unstream the <tt>CAT3DLightSourceGP</tt>.
  */
  virtual void UnStream(CATStreamer& iStr);

  /** @nodoc */
  void SetApplicativeMode(unsigned int iMode);
  /** @nodoc */
  inline unsigned int GetApplicativeMode() const;

  /**
  * Returns the type of the light source.
  * @see CATLightSourceType
  */
  inline CATLightSourceType GetType() const;
  /** @nodoc
  * Returns if the light source is physical.
  */
  inline CATBoolean IsPhysical() const;
  
  /** @nodoc : deprecated R419 : Internal use only */
  inline float GetSpotAngle() const;
  /** @nodoc : deprecated R419 : Internal use only */
  inline CATLightSourceMode GetLightSourceMode() const;
  /** @nodoc : deprecated R419 : Internal use only */
  inline void SetMotherRepConnection(CAT3DLightSourceRep *motherRep);
  /** @nodoc : deprecated R419 : Internal use only */
  inline const void* GetMotherRepConnection() const;
  /** @nodoc : deprecated R419 : Internal use only */
  inline void SetVolUpdateNeeded(unsigned int updated);
  /** @nodoc : deprecated R419 : Internal use only */
  inline unsigned int GetVolUpdateNeeded() const ;
  /** @nodoc : deprecated R419 : Internal use only */
  inline CATLightSourceMode GetMode() const;

  /** @nodoc : deprecated R419 : Internal use only */
  inline void GetDirection(CATMathDirectionf& oDirection) const;
  /** @nodoc : deprecated R419 : Internal use only */
  inline void GetOrigin(CATMathPointf& oOrigin) const;
  /** @nodoc : deprecated R419 : Internal use only */
  void GatherPointLightInfo(CATMathPointf& oOrigin, float* oDiffuse, float& oPower) const;
  /** @nodoc : deprecated R419 : Internal use only */
  void GatherDirectionalLightInfo(CATMathDirectionf& oDirection, float* oDiffuse, float& oPowerPerArea) const;
  /** @nodoc : deprecated R419 : Internal use only */
  void GatherSpotLightInfo(CATMathPointf& oOrigin, CATMathDirectionf& oDirection, float* oDiffuse, float& oPower, float& oInnerAngle, float& oOuterAngle) const;
  /** @nodoc : deprecated R419 : Internal use only */
  void GatherProfileLightInfo(CATMathPointf& oOrigin, CATMathDirectionf& oDirection, CATMathDirectionf& oNullAngleDir, CATTexturePixelImage* oProfile, float* oDiffuse, float& oPowerFactor) const;

  /** @nodoc */
  inline CATLightSourceAreaType GetAreaType() const;
  /** @nodoc */
  void GatherSphereLightInfo(CATMathPointf& oOrigin, float& oRadius, float* oDiffuse, float& oPower) const;
  /** @nodoc */
  void GatherTubeLightInfo(CATMathPointf& oOrigin, CATMathDirectionf& oTubeDir, float& oLength, float& oRadius, float* oDiffuse, float& oPower) const;
  /** @nodoc */
  void GatherDiskLightInfo(CATMathPointf& oOrigin, CATMathDirectionf& oNormal, float& oRadius, float* oDiffuse, float& oPower) const;
  /** @nodoc */
  void GatherRectangleLightInfo(CATMathPointf& oOrigin, CATMathDirectionf& oNormal, CATMathDirectionf& oUpDir, float& oRightSize, float& oUpSize, float* oDiffuse, float& oPower) const;

private:
  // data
  CATLightSourceType _type;
  CATLightSourceMode _mode;
  CATMathPointf      _origin;
  CATMathDirectionf  _direction;
  CATMathDirectionf  _up;
  CATMathDirectionf  _right;
  CATLightSourceAreaType _areaType;
  float              _areaSize[2];
  float              _spotInnerAngle;
  float              _spotAngle;
  float              _spotExponent;
  float              _axialFalloffStart;
  float              _axialFalloffEnd;
  float              _constantAttenuation;
  float              _linearAttenuation;
  float              _quadraticAttenuation;
  CATBoolean         _physical;
  float              _physPower;
  float              _ambient[4];
  float              _diffuse[4];
  float              _specular[4];
  CATTexturePixelImage* _profile;
  unsigned int       _applicativeMode;

  float              _areaTypeOld; // TODELETE
  float              _areaStatusOld; // TODELETE

/* Added for volatile */
  CAT3DLightSourceRep* m_originalRep;
  unsigned int m_volUpdateNeeded;


  virtual ~CAT3DLightSourceGP();
};

// inline method definition
inline void CAT3DLightSourceGP::SetColor(const float iAmbient[4],
					 const float iDiffuse[4],
					 const float iSpecular[4])
{
  for ( int i = 0; i<4; i++ )
  {
    _ambient[i]  = iAmbient[i];
    _diffuse[i]  = iDiffuse[i];
    _specular[i] = iSpecular[i];
  }
  
}

inline float CAT3DLightSourceGP::GetSpotAngle() const
{
  return _spotAngle;
}

inline void CAT3DLightSourceGP::GetColor(const float ** oAmbient,
					 const float ** oDiffuse,
					 const float ** oSpecular)
{
  if (oAmbient)  *oAmbient  = _ambient;
  if (oDiffuse)  *oDiffuse  = _diffuse;
  if (oSpecular) *oSpecular = _specular;
}

inline void CAT3DLightSourceGP::Get(CATLightSourceType   & oType,
				    CATLightSourceMode   & oMode,
				    CATMathPointf     & oOrigin,
				    CATMathDirectionf & oDirection,
				    float             * oSpotAngle,
				    float             * oSpotExponent,
				    float             * oConstantAttenuation,
				    float             * oLinearAttenuation,
				    float             * oQuadraticAttenuation)
{
  oType        = _type;
  oMode        = _mode;
  oOrigin      = _origin;
  oDirection   = _direction;
  if (oSpotAngle)            *oSpotAngle            = _spotAngle;
  if (oSpotExponent)         *oSpotExponent         = _spotExponent;
  if (oConstantAttenuation)  *oConstantAttenuation  = _constantAttenuation;
  if (oLinearAttenuation)    *oLinearAttenuation    = _linearAttenuation;
  if (oQuadraticAttenuation) *oQuadraticAttenuation = _quadraticAttenuation;
}
                                   

inline unsigned int CAT3DLightSourceGP::GetApplicativeMode() const
{
  return _applicativeMode;
}

inline CATLightSourceType CAT3DLightSourceGP::GetType() const
{
  return _type;
}

inline CATBoolean CAT3DLightSourceGP::IsPhysical() const
{
  return _physical;
}

inline CATLightSourceMode CAT3DLightSourceGP::GetLightSourceMode() const
{
  return _mode;
}

inline void CAT3DLightSourceGP::SetMotherRepConnection(CAT3DLightSourceRep *motherRep)
{
  m_originalRep = motherRep;
}

inline const void* CAT3DLightSourceGP::GetMotherRepConnection() const
{
  return (void*) m_originalRep;
}

inline void CAT3DLightSourceGP::SetVolUpdateNeeded(unsigned int updated)
{
  m_volUpdateNeeded = updated;
}

inline unsigned int CAT3DLightSourceGP::GetVolUpdateNeeded() const 
{
  return m_volUpdateNeeded;
}

inline CATLightSourceMode CAT3DLightSourceGP::GetMode() const
{
  return _mode;
}

inline void CAT3DLightSourceGP::GetDirection(CATMathDirectionf& oDirection) const
{
  oDirection = _direction;
}

inline void CAT3DLightSourceGP::GetOrigin(CATMathPointf& oOrigin) const
{
  oOrigin = _origin;
}

inline CATLightSourceAreaType CAT3DLightSourceGP::GetAreaType() const
{
  return _areaType;
}

#endif // CAT3DLightSourceGP
