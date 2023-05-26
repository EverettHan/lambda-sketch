#ifndef CATVisEnvMapGenerator_H
#define CATVisEnvMapGenerator_H

#include "CATVisFoundation.h"

#include "CATSupport.h"
#include "CATVisHDRData.h"
#include "VisAntialiasingInfo.h"
#include "CATIVizVisualizationSettingAtt.h"
#include "VisCustomizeShadows.h"
#include "IVisTexturePtr.h"
#include "VisQualityData.h"
#include <memory>

class CATVisEnvMapGenConfig;
class CATTexturePixelImage;
class CAT3DViewpoint;
class CATVisInfiniteEnvironment;
class VisComputeBaseProgram;
class CustomPassManager;

class ComputeProgramSmartPtr
{
public :

  ComputeProgramSmartPtr();

  ComputeProgramSmartPtr(const ComputeProgramSmartPtr & iCopy);
  ComputeProgramSmartPtr & operator = (const ComputeProgramSmartPtr& rhs);

  void Assign(VisComputeBaseProgram * iProgram);

  virtual ~ComputeProgramSmartPtr();

  VisComputeBaseProgram * operator->();

  bool operator == (const ComputeProgramSmartPtr & rhs) const;

  VisComputeBaseProgram * Ptr() { return m_ref; }

private :

  VisComputeBaseProgram * m_ref;
};


/**
 * Service class for environment map generation
 */
class ExportedByCATVisFoundation CATVisEnvMapGenerator
{
public:

  /** This service method is used to set up a configuration on a support for environment map generator.
   *  The environment map generator configuration will follows the support and support configuration copies.
   *  @warning Only one generator configuration can be set on a support, the next one will overwrite the previous one!
   *  @param iConfig The environment map generator configuration
   *  @param iSupport The support which will be modified to host the generator configuration
   */
  static void SetConfigurationForSupport(CATSupport& iSupport, CATVisEnvMapGenConfig* iConfig);

  /** This service method is used to retrieve an environment map generator configuration from a support.
   *  @warning This method doesn't increment the returned "CATVisEnvMapGenConfig" reference counter.
   *  @param iSupport The support which will be modified to host the generator configuration
   *  @return the retrieved environment map generator configuration
   */
  static CATVisEnvMapGenConfig* GetConfigurationForSupport(const CATSupport& iSupport);


  /**
   * class which embed all required support settings for an environment map generation
   */
  class ExportedByCATVisFoundation SupportConfig
  {
  public:
    friend class CATVisEnvMapGenerator;

    SupportConfig();
    SupportConfig(const CATSupport& iRefSupport);

    void UpdateFromSupport(const CATSupport& iRefSupport);

    CATVisEnvMapGenConfig* GenConfig; // WARNING: Lifecycle isn't managed!

    // Force a specific visual quality on output
    enum EQuality
    {
      eNone,
      eLow,
      eMedium,
      eHigh,
      eUltra
    };
    EQuality ForceQuality;

    // Force output to use volatile mode, it can be more efficient when only one picture is generated
    bool ForceVolatilMode;
    
    int                 ViewMode;
    VisAntialiasingInfo AntiAliasing;
    bool                LogZ;
    CATIVizVisualizationSettingAtt::CATTransparencyMode TransparencyMode;
   
    // Shadow customization
    struct ShadowsConfig
    {
      ShadowsConfig();

      CATSupport::ShadowBe::Type ShadowBE;
      VisCustomizeShadows::Filtering::Mode FilteringMode;
      VisCustomizeShadows::Quality::Mode QualityMode;
      bool UseAdvancedBias;
      float FixedBias;
    };
    ShadowsConfig Shadows;

    // Cascaded shadows customization
    struct CascadedShadowsConfig
    {
      CascadedShadowsConfig();

      unsigned int NbCascade;
      float MaxFarDistance;
      VisCustomizeShadows::Split::Mode SplitMode;
      float PracticalFactor;
      bool ExtendedFrustum;
      VisCustomizeShadows::Occluder::Mode OccluderMode;
      float ExtendedFactor[8];
    };
    CascadedShadowsConfig CascadedShadows;
  
    std::shared_ptr<CustomPassManager> CustomPassManager;

  private:
    bool            m_ApplyQuality;
    VisQualityData  m_Quality;
  };

  /** This service method is used to create a cube map CPU texture from a viewpoint (which can contains some models) and an infinite environment.
   *  The returned texture format will on some input parameters combination.
   *  @param iVp The viewpoint (with attached scene graph) which must be shot
   *  @param iSupportConfig The support configuration
   *  @param iEnv The infinite environment (its mode is changed adapted to HDR given mode and if a null pointer is given, it will be replaced by a transparent black background)
   *  @param iHDR Activates the HDR mode: environment will be modified to match this mode and returned texture format will be RGB_f or RGBA_f (instead of RGB or RGBA for LDR)
   *  @param iSize The returned texture resolution (iSize x iSize)
   *  @param iOutAlpha Activates the transparency channel on the returned texture: USELESS on most cube map usages! (the returned texture format will be RGBA_f or RGBA)
   *  @return the generated cube map CPU texture (or a null pointer if there was an error)
   */
  static CATTexturePixelImage* CreateCubeMapFromViewpoint(const CAT3DViewpoint& iVp, SupportConfig* iSupportConfig, const CATVisInfiniteEnvironment* iEnv, bool iHDR, unsigned int iSize, bool iOutAlpha = false);

  /** This service method is used to create a cube map CPU texture an infinite environment.
   *  The returned texture format will on some input argument combination (iHDR and iOutAlpha).
   *  @param iEnv The infinite environment (its mode is changed adapted to HDR given mode)
   *  @param iShotHeight The shot altitude from infinite environment ground
   *  @param iHDR Activates the HDR mode: environment will be modified to match this mode and returned texture format will be RGB_f or RGBA_f (instead of RGB or RGBA for LDR)
   *  @param iSize The returned texture resolution (iSize x iSize)
   *  @param iOutAlpha Activates the transparency channel on the returned texture: USELESS on most cube map usages! (the returned texture format will be RGBA_f or RGBA)
   *  @return the generated cube map CPU texture (or a null pointer if there was an error)
   */
  static CATTexturePixelImage* CreateCubeMapFromAmbiance(const CATVisInfiniteEnvironment& iEnv, float iShotHeight, bool iHDR, unsigned int iSize, bool iOutAlpha = false);

  /**
   * Class which encapsulate everything required for an environment generation on GPU
   * An instance of this object could be retrieve to avoid heavy CPU/GPU structure recreation for environment map update.
   * In this case, the service method UpdateGPUCubeMapUsingGPUData can be called with this object to update the exact same IVisTexture.
   * @warning DO NOT use a GPUData object retrieved from an IVisTexture generation with another IVisTexture!
   */
  class ExportedByCATVisFoundation GPUData
  {
    friend class CATVisEnvMapGenerator;

  public:
    GPUData();
    GPUData(const GPUData& iSrc);
    ~GPUData();
    GPUData& operator = (const GPUData& iSrc);

    /** This method is used to retrieve the internal viewpoint: it allows modifications on camera or attached scene graph.
     *  @return the internal viewpoint
     */
    CAT3DViewpoint* GetViewpoint();

  private:
    CATSupport* m_Support;
    CAT3DViewpoint* m_Viewpoint;
    IVisTexturePtr m_CubeMapForLatLong; ///< This pointer is only used in case of latlong conversion
    ComputeProgramSmartPtr m_LatLongProgram;
    bool m_Retarget;
  };

  /** This service method is used to create a cube map GPU texture from a viewpoint (which can contains some models) and an infinite environment.
   *  The returned texture format will on iHdrMode argument value.
   *  @warning This is a NRE feature only.
   *  @see UpdateGPUCubeMapUsingGPUData for oGPUData usage
   *  @param iVp The viewpoint (with attached scene graph) which must be shot
   *  @param iSupportConfig The support configuration
   *  @param iEnv The infinite environment (its mode is changed adapted to HDR given mode and if a null pointer is given, it will be replaced by a transparent black background)
   *  @param iHDRMode Select the HDR mode: environment will be modified to match this mode and returned texture format will be defined from this mode
   *  @param iSize The returned texture resolution (iSize x iSize)
   *  @param oGPUData Output pointer on all data used to generate this cube map (data is destroyed if this pointer is null)
   *  @return the generated cube map GPU texture (or a null pointer if there was an error)
   */
  static IVisTexturePtr CreateGPUCubeMapFromViewpoint(const CAT3DViewpoint& iVp, SupportConfig* iSupportConfig, const CATVisInfiniteEnvironment* iEnv, CATVisHDRData::EMode iHDRMode, unsigned int iSize, GPUData* oGPUData = NULL);

  /** This service method is used to create a cube map GPU texture from an infinite environment.
   *  The returned texture format will on iHdrMode argument value.
   *  @warning This is a NRE feature only.
   *  @see UpdateGPUCubeMapUsingGPUData for oGPUData usage
   *  @param iEnv The infinite environment (its mode is changed adapted to HDR given mode)
   *  @param iShotHeight The shot altitude from infinite environment ground
   *  @param iHDRMode Select the HDR mode: environment will be modified to match this mode and returned texture format will be defined from this mode
   *  @param iSize The returned texture resolution (iSize x iSize)
   *  @param oGPUData Output pointer on all data used to generate this cube map (data is destroyed if this pointer is null)
   *  @return the generated cube map GPU texture (or a null pointer if there was an error)
   */
  static IVisTexturePtr CreateGPUCubeMapFromAmbiance(const CATVisInfiniteEnvironment& iEnv, float iShotHeight, CATVisHDRData::EMode iHDRMode, unsigned int iSize, GPUData* oGPUData = NULL);

  /** This service method is used to create a latlong GPU texture from a viewpoint (which can contains some models) and an infinite environment.
   *  The returned texture format will depend on iHdrMode argument value.
   *  @warning This is a NRE feature only.
   *  @see UpdateGPUCubeMapUsingGPUData for oGPUData usage
   *  @param iVp The viewpoint (with attached scene graph) which must be shot
   *  @param iSupportConfig The support configuration
   *  @param iEnv The infinite environment (its mode is changed adapted to HDR given mode and if a null pointer is given, it will be replaced by a transparent black background)
   *  @param iHDRMode Select the HDR mode: environment will be modified to match this mode and returned texture format will be defined from this mode
   *  @param iWidth The returned texture width
   *  @param iHeight The returned texture height
   *  @param oGPUData Output pointer on all data used to generate this map (data is destroyed if this pointer is null)
   *  @return the generated cube map GPU texture (or a null pointer if there was an error)
   */
  static IVisTexturePtr CreateGPULatLongFromViewpoint(const CAT3DViewpoint& iVp, SupportConfig* iSupportConfig, const CATVisInfiniteEnvironment* iEnv, CATVisHDRData::EMode iHDRMode, unsigned int iWidth, unsigned int iHeight, GPUData* oGPUData = NULL);

  /** This service method is used to modify a cube map GPU texture from an infinite environment.
   *  Infinite environment HDR mode will be deduced and modified from given GPU texture format.
   *  @warning This is a NRE feature only.
   *  @see UpdateGPUCubeMapUsingGPUData for oGPUData usage
   *  @param ioCubeMap The cube map GPU texture to modify
   *  @param iEnv The infinite environment (its mode is changed adapted to HDR given mode)
   *  @param iShotHeight The shot altitude from infinite environment ground
   *  @param oGPUData Output pointer on all data used to generate this cube map (data is destroyed if this pointer is null)
   *  @return true if the generation was a success
   */
  static bool UpdateGPUCubeMapFromAmbiance(IVisTexturePtr & ioCubeMap, const CATVisInfiniteEnvironment& iEnv, float iShotHeight, GPUData* oGPUData = NULL);

  /** This service method is used to modify a cube map GPU texture from a given GPU support and GPU viewpoint.
   *  @warning This is a NRE feature only.
   *  @see CreateGPUCubeMapFromViewpoint, CreateGPUCubeMapFromAmbiance, UpdateGPUCubeMapFromViewpoint and UpdateGPUCubeMapFromAmbiance for ioGPUData creation
   *  @param ioCubeMap The cube map GPU texture to modify
   *  @param ioGPUData GPU data to use to modify the given cube map (this data state can be changed by this function)
   *  @return true if the generation was a success
   */
  static bool UpdateGPUCubeMapUsingGPUData(IVisTexturePtr & ioCubeMap, GPUData& ioGPUData);

    /** This function is used to modify a cube map GPU texture from a given GPU support and GPU viewpoint.
   *  @warning This is a NRE feature only.
   *  @see CreateGPUCubeMapFromViewpoint, CreateGPUCubeMapFromAmbiance, UpdateGPUCubeMapFromViewpoint and UpdateGPUCubeMapFromAmbiance for ioGPUData creation
   *  @param ioCubeMap The cube map GPU texture to modify
   *  @param ioGPUData GPU data to use to modify the given cube map (this data state can be changed by this function)
   *  @return true if the generation was a success
   */
  static bool UpdateGPULatLongUsingGPUData(IVisTexturePtr & ioLatlongMap, GPUData& ioGPUData);


  /** Convert a cube map into a latlong of the desired size.
   *  @param iCubeMap is the cube map you want to convert.
   *  @param iLatlongWidth is the width of desired latlong.
   *  @param iLatlongHeight is the height of desired latlong.
   *  @param iKeepFormat allows you to keep the same format between input map and output map if set to TRUE
   *  @param iThetaOffset offset from [-1,1] to offset theta angle from [-2*PI, 2*PI]
   *  @return NULL in case of fail else a cube map. You are owner of the lifecycle of the object.
   */
  static IVisTexturePtr ConvertCubeMapToLatLong(IVisTexturePtr & iCubeMap, unsigned int iLatlongWidth, unsigned int iLatlongHeight, bool iKeepFormat = false, float iThetaOffset = 0.25f);
  

private:
  static CATVisInfiniteEnvironment* _SetupEnvironment (const CATVisInfiniteEnvironment& iEnv, unsigned int iCleanFlags);
  static bool                       _SetupSupport     (CATSupport& iSupport, CATVisEnvMapGenerator::SupportConfig* iConfig, CAT3DViewpoint* &ioVp, CATVisInfiniteEnvironment* &ioEnv);
  static bool                       _UpdateGPUCubeMapFromViewpoint(IVisTexturePtr & ioCubeMap, const CAT3DViewpoint& iVp, SupportConfig* iSupportConfig, const CATVisInfiniteEnvironment* iEnv, GPUData* oGPUData = NULL);
  static void                       _ConvertToLatLong (IVisTexturePtr & iCubeMap, IVisTexturePtr & iLatlongMap, const CAT3DViewpoint& iVp, GPUData* ioGPUData, float iThetaOffset = 0.25f);
  static bool                       _GetGPUTextureCubeInfo(IVisTexturePtr & ioCubeMap, unsigned int& oSize, IVisTextureFormat::Type& oFormat, IVisTextureFormat::Type& oAlphaFormat, bool& oHdrOutput, CATVisHDRData::EMode& oHdrMode);
};

#endif
