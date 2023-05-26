#ifndef CAT3DLightSourceRep_H
#define CAT3DLightSourceRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CAT3DRep.h"
#include "CAT3DLightSourceGP.h"
#include "SGInfra.h"

#include "CATIAV5Level.h"

class CATTexturePixelImage;

#include "CAT4x4Matrix.h"

/**
 * Class to create light source representations.
 * <b>Role</b>: A light source representation indicates the position
 * and orientation of lights in the viewer. A light source representation
 * can be of two different types :
 * <ol>
 * <li><tt>LS_INFINITE</tt> infinitely distant like the sun, </li>
 * <li><tt>LS_SPOT</tt> spotlight with a cutoff angle between 0 and 90 degrees,
 *                     or equal to 180 degrees (lightbulb equivalent) </li>
 * </ol>
 * A light source representation can be of two differents modes :
 * <ol>
 * <li><tt>Local</tt> attached to the viewpoint </li>
 * <li><tt>Global</tt> attached to the model </li>
 * </ol>
 * By default, one light source is created and activated. A viewer can handle
 * a maximum of eight light source representations.
 */
class ExportedBySGInfra CAT3DLightSourceRep : public CAT3DRep
{
  friend class CATDmuStream3DLightSourceRep;
  friend class CAT3DFinalLightSourceRep;
  friend class CAT3DSlaveLightSourceRep;

  // macros
  CATDeclareClass;

public:
  virtual ~CAT3DLightSourceRep();
  
  /** Constructs an empty light source graphic representation. */
  static CAT3DLightSourceRep* CreateRep();

  /**
   * Constructs the representation of a light source.
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
   * <br><b>Legal Values</b>: in the range [0,90] or 180.
   * <br><b>Default Value</b>: 180. This constructs an equivalent to a lightbulb.
   */
  static CAT3DLightSourceRep* CreateRep(const CATLightSourceType iType,
		      const CATLightSourceMode    iMode,
		      const CATMathPointf       & iOrigin,
		      const CATMathDirectionf   & iDirection,
		      const float                 iSpotAngle = 180.f);

  /**
   * Copy constructor.
   * @param iLightSourceRep
   * The light source representation to be duplicated
   */
  static CAT3DLightSourceRep* CreateRep(const CAT3DLightSourceRep & iLightSourceRep);

protected:

  BEGIN_MIGRATE_REP_CTOR_PRIVATE
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Use CAT3DFinalLightSourceRep if you want to derive this class" )
#endif

  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DLightSourceRep();


  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DLightSourceRep(const CATLightSourceType iType,
		      const CATLightSourceMode    iMode,
		      const CATMathPointf       & iOrigin,
		      const CATMathDirectionf   & iDirection,
		      const float                 iSpotAngle = 180.f);

  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DLightSourceRep(const CAT3DLightSourceRep & iLightSourceRep);
  END_MIGRATE_REP_CTOR

public:

  /**
   * Assignement operator.
   * @param iLightSourceRep
   * The light source representation to be copied
   */
  CAT3DLightSourceRep & operator = (const CAT3DLightSourceRep & iLightSourceRep);

  /**
   * Retrieves the type of the light source.
   * @param oType
   * The type of the light source representation.
   */
  void GetType(CATLightSourceType       & oType);

  /**
   * Sets the type of the light source representation.
   * @param iType
   * The type of the light source representation.
   */
  void SetType(const CATLightSourceType   iType);

  /**
   * Retrieves the mode of the light source.
   * @param oMode
   * The mode of the light source representation.
   */
  void GetMode(CATLightSourceMode       & oMode);

  /**
   * Sets the mode of the light source representation.
   * @param iMode
   * The mode of the light source representation.
   */
  void SetMode(const CATLightSourceMode iMode);


  /**
   * Retrieves the color components of the light source representation.
   * All float values are in [0,1].
   * @param oAmbient
   * Red, green, blue and alpha values of ambient component.
   * @param oDiffuse
   * Red, green, blue and alpha values of diffuse component.
   * @param oSpecular
   * Red, green, blue and alpha values of specular component.
   */
  void GetColorParameters(const float ** oAmbient,
                          const float ** oDiffuse,
                          const float ** oSpecular) const;
  /**
   * Sets the color components of the light source representation.
   * All float values are in [0,1].
   * @param iAmbient
   * Red, green, blue and alpha values of ambient component (array of four floats).
   * @param iDiffuse
   * Red, green, blue and alpha values of diffuse component (array of four floats).
   * @param iSpecular
   * Red, green, blue and alpha values of specular component (array of four floats).
   */
  void SetColorParameters(const float  * iAmbient,
                          const float  * iDiffuse,
                          const float  * iSpecular);

  /**
   * Retrieves the location and direction of a light source representation.
   * @param oOrigin
   * The point where the light source is located. This parameter has
   * no meaning for <tt>LS_INFINITE>/tt> light source representations.
   * @param oDirection
   * The direction of the light source.
   */
  void GetLocationParameters(CATMathPointf     & oOrigin,
                             CATMathDirectionf & oDirection) const;

  /**
   * Sets the location and direction of a light source representation.
   * This method has no meaning for <tt>LS_INFINITE</tt> light source representations.
   * @param iOrigin
   * The point where the light source is located. This parameter has
   * no meaning for <tt>LS_INFINITE</tt> light source representations.
   * @param iDirection
   * The direction of the light source.
   */
  void SetLocationParameters(const CATMathPointf     & iOrigin,
                             const CATMathDirectionf & iDirection);

  /**
   * Retrieves the specific parameters of a spotlight source representation.
   * This method has no meaning for <tt>LS_INFINITE</tt> light source representations.
   * @param oSpotAngle
   * The half-angle aperture of the cone of the spotlight.
   * @param oSpotExponent
   * The exponent value used for specular component calculations.
   */
  void GetSpotLightParameters(float & oSpotAngle, float & oSpotExponent) const;

  /**
   * Sets the specific parameters of a spotlight source representation.
   * @param iSpotAngle
   * The half-angle aperture of the cone of the spotlight.
   * @param iSpotExponent
   * The exponent value used for specular component calculations.
   */
  void SetSpotLightParameters(const float iSpotAngle, const float iSpotExponent);

  /**
   * Retrieves the attenuation parameters of the light source representation.
   * @param oConstant
   * The constant factor of the attenuation function.
   * @param oLinear
   * The light factor of the attenuation function.
   * @param oQuadratic
   * The quadratic factor of the attenuation function.
   */
  void GetAttenuationParameters(float & oConstant,
                                float & oLinear,
                                float & oQuadratic) const;
  /**
   * Sets the attenuation parameters of the light source representation.
   * @param iConstant
   * The constant parameter of the attenuation function
   * @param iLinear
   * The light parameter of the attenuation function
   * @param iQuadratic
   * The quadratic parameter of the attenuation function
   */
  void SetAttenuationParameters(const float iConstant,
                                const float iLinear,
                                const float iQuadratic);

  /** @nodoc */
  void DrawShading(CATRender & iRender, int iInside);

  /** @nodoc */
  inline int IsActive() {return _active;};

  /** @nodoc */
  inline void SetActive(int active) {_active = active;};
  
  /** @nodoc */
  void SetShadowFlag(CATBoolean i_shadowFlag);
  /** @nodoc */
  CATBoolean GetShadowFlag() const;

  /** @nodoc */
  void SetShadowColor(const float* i_plShadowColor);
  /** @nodoc */
  void GetShadowColor(const float** o_plShadowColor) const;

  /** @nodoc TODELETE*/
  CATTexturePixelImage *GetShadowTextureToModify(){return NULL;};
  /** @nodoc TODELETE*/
  void SetShadowTexture(CATTexturePixelImage *i_pShadowDepthTexture){};

  /** @nodoc TODELETE*/
  void SetRefreshShadowMapFlag(int i_flag){};
  /** @nodoc TODELETE*/
  int GetRefreshShadowMapFlag(){return 0;};

  /** @nodoc*/
  void SetNear(float i_near);
  /** @nodoc */
  float GetNear();
  
  /** @nodoc*/
  void SetAutomaticNearPlanFlag(short i_automaticNearPlanFlag);
  /** @nodoc */
  short GetAutomaticNearPlanFlag();
  
  /** @nodoc */
  void SetApplicativeMode(unsigned int iMode);
  /** @nodoc */
  unsigned int GetApplicativeMode() const;

  /** @nodoc */
  CAT3DLightSourceRep(const LightSourceType      type,
                      const LightSourceMode      mode,
                      const CATMathPointf      & origin,
                      const CATMathDirectionf  & direction,
                      const CATMathDirectionf  & up,
                      const CATMathDirectionf  & right,
                      const float              * ambient,
                      const float              * diffuse,
                      const float              * specular,
                      const CATBoolean           physical,
                      const float                physPower,
                      CATTexturePixelImage     * profile,
                      const float                spotAngle,
                      const float                spotExponent,
                      const float                spotInnerAngle,
                      const float                constantAttenuation,
                      const float                linearAttenuation,
                      const float                quadraticAttenuation,
                      const float                axialFalloffStart,
                      const float                axialFalloffEnd,
                      const LightSourceAreaType& areaType,
                      const float              * areaSize);

  /** @nodoc TODELETE AFTER IMPACT CHECK */
  CAT3DLightSourceRep(const LightSourceType      type,
    const LightSourceMode      mode,
    const CATMathPointf      & origin,
    const CATMathDirectionf  & direction,
    const CATMathDirectionf  & up,
    const CATMathDirectionf  & right,
    const float              * ambient,
    const float              * diffuse,
    const float              * specular,
    const float                spotAngle,
    const float                spotExponent,
    const float                spotInnerAngle,
    const float                constantAttenuation,
    const float                linearAttenuation,
    const float                quadraticAttenuation,
    const float                axialFalloffStart,
    const float                axialFalloffEnd,
    const float                areaType,
    const float                areaStatus,
    const float              * areaGeometry);

  /** @nodoc */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);
  /** @nodoc */
  virtual int GetGeomIndex(const CATGraphicPrimitive * gp);

  /** @nodoc */
  void GetSpotLightInnerParameters(float & oSpotInnerAngle) const;

  /** @nodoc */
  void SetSpotLightInnerParameters(const float iSpotInnerAngle);

  /** @nodoc TODELETE AFTER IMPACT CHECK */
  void GetAreaParameters(float & oAreaType, float & oAreaStatus, float ** oAreaGeometry) const;

  /** @nodoc TODELETE AFTER IMPACT CHECK */
  void SetAreaParameters(const float iAreaType, float  iAreaStatus, float * iAreaGeometry);

  /** @nodoc
  * Set the light source as physical
  * By default, point, spot and directional lights are not physical but it can be changed.
  * Area and profile lights are physical and it can't be changed.
  * @param iPhysical
  *   Set this light source as physical if true
  * @return boolean
  *   Returns if the light source physical flag has been changed to iPhysical
  */
  CATBoolean SetPhysical(const CATBoolean iPhysical);

  /** @nodoc
  * Returns if the light source is physical.
  * The power of a physical light is defined by "SetPhysicalPower" method.
  * All other power setting tricks (spot exponent or direction norm) will be ignored.
  * A physical light will be attenuated by the distance square (distance is in mm).
  * Other attenuation parameters will be ignored.
  */
  CATBoolean IsPhysical() const;

  /** @nodoc
  * Set the power of the light source if it is physical
  * The power will have different meaning depending on the light type:
  *   - For point, spot and area lights, it truly represents the power (in lumen, lm)
  *   - For directional lights, it is the power per area unit (in lm/m^2, lux)
  *   - For profile lights, it is a factor applied to the given profile map
  */
  void SetPhysicalPower(const float iPower);

  /** @nodoc
  * Returns the power of a physical light source
  */
  float GetPhysicalPower() const;

  /** @nodoc */
  CATBoolean SetProfile(CATTexturePixelImage* iProfile);

  /** @nodoc */
  CATBoolean GetProfile(CATTexturePixelImage** oProfile) const;

  /** @nodoc */
  void GetAreaType(CATLightSourceAreaType & oAreaType) const;

  /** @nodoc */
  void SetSphereArea(const float iRadius);

  /** @nodoc */
  CATBoolean GetSphereAreaSize(float& oRadius) const;

  /** @nodoc */
  void SetTubeArea(const float iLength, const float iRadius);

  /** @nodoc */
  CATBoolean GetTubeAreaSize(float& oLength, float& oRadius) const;

  /** @nodoc */
  void SetDiskArea(const float iRadius);

  /** @nodoc */
  CATBoolean GetDiskAreaSize(float& oRadius) const;

  /** @nodoc */
  void SetRectangleArea(const float iRightSize, const float iUpSize);

  /** @nodoc */
  CATBoolean GetRectangleAreaSize(float& oRightSize, float& oUpSize) const;

  /** @nodoc */
  void GetUpAndRightParameters(CATMathDirectionf & oUp,
                               CATMathDirectionf & oRight) const;

  /** @nodoc */
  void SetUpAndRightParameters(const CATMathDirectionf & iUp,
                               const CATMathDirectionf & iRight);

  /** @nodoc */
  CATBoolean CorrectOrthogonalSpace();

  /** @nodoc */
  void GetFalloffParameters(float & oAxialFalloffStart,
                            float & oAxialFalloffEnd) const;

  /** @nodoc */
  void SetFalloffParameters(const float iAxialFalloffStart,
                            const float  iAxialFalloffEnd);

private :

  /** @nodoc */
  void _BuildGP();

  /** @nodoc */
  bool _CorrectOrthogonalSpace();

  // data
  CATLightSourceType _type;
  CATLightSourceMode _mode;
  CATMathPointf      _origin;
  CATMathDirectionf  _direction;
  CATMathDirectionf  _up;
  CATMathDirectionf  _right;
  float              _spotInnerAngle;
  float              _spotAngle;
  float              _spotExponent;
  float              _axialFalloffStart;
  float              _axialFalloffEnd;
  float              _constantAttenuation;
  float              _linearAttenuation;
  float              _quadraticAttenuation;
  float              _physPower;
  CATLightSourceAreaType _areaType;
  float              _areaSize[2];
  float              _ambient[4];
  float              _diffuse[4];
  float              _specular[4];
  CATTexturePixelImage* _profile;
  int                _active;

  float              _areaTypeOld; // TODELETE
  float              _areaStatusOld; // TODELETE

  CAT3DLightSourceGP * _gp;                   // light source graphic primitive

  float         _nearPlan;
  short         _automaticNearPlanFlag;
  CATBoolean    _physicalFlag;
  CATBoolean    _shadowFlag;
  float         _shadowColor[4];

  unsigned int  _applicativeMode;
};

#endif // CAT3DLightSourceRep_H
