// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisInfiniteEnvironment_H
#define CATVisInfiniteEnvironment_H

#include "SGInfra.h"
#include "CATVizBaseIUnknown.h"

#include "list.h"
#include "CATVisInfiniteEnvironmentData.h"          // pour definir les class de passage de donnees
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATVisEffectPositionEnum.h"
#include "CATVisPostEffects.h"
#include "CATCallbackManager.h"

class CATVisInfiniteEnvironmentExtendedData;
class CATVisGlowingData;
class CATVisInfiniteEnvironmentOverload;
class CATVisInfiniteEnvironmentStack;
class CATTexturePixelImage;
class CATSupport;
class CATFrameData;
class CATUnicodeString;
class CATString;
class CATSysPreferenceRepository;
class CATVisStreamer;
class CATSupport;
class CATString;
class CATVisAmbiance;
class CATVisPostEffects;
class ExportedBySGInfra CATVisInfiniteEnvironment : public CATVizBaseIUnknown
{
  friend class CATVisInfiniteEnvironmentStack;
  friend class CATVisInfiniteEnvironmentStreamer;
  friend class CATVisInfiniteEnvironmentFactory;
  friend class l_CATSupport;

  
public:

  //-------------------------
  // Events
  CATDeclareCBEvent(AMBIANCE_MODIFED);

    //-------------------------
    // lifecycle

    // factory pour creer un env vide
  static CATVisInfiniteEnvironment* Create();

  // factory pour creer des env predefinis
  // iName permet de gerer un certain nombre d'environnements predefinis :
  //      * "Shiny"    
  //      * "Neon"     
  //      * "Summer"   
  //      * "Icy"      
  static CATVisInfiniteEnvironment* Create(const CATString& iID);


  // factory pour creer un env a partir du nouvel objet d'ambiance
  static CATVisInfiniteEnvironment* Create(CATVisAmbiance* iAmbiance, CATVisPostEffects* iPostEffects = nullptr);

  // clone
  CATVisInfiniteEnvironment* Clone() const;

  
  //-------------------------
  // General

  const CATString& GetID() const;
  const CATString& GetName() const;
  const CATString& GetInfoName() const;
  void             SetInfoName(const CATString& iName);
  const int        GetVersion();

  enum CATVisInfiniteEnvType
  {
    GeneralInfiniteEnv = 0,
    PLMInfiniteEnv,
    DesignInfiniteEnv,
    ReviewInfiniteEnv
  };

  void             SetType(CATVisInfiniteEnvType iType);
  CATVisInfiniteEnvType GetType()const;

  enum EProperty
  {
    eEnvironment,
    ePushEnv,
    eDefaultBackground,
    eDefaultLights,
    eDefaultProjection,
    eDefaultGravity,
    eMirroring,
    eMirroringInterObjects,
    eSSAO,
    eVoxelAO,
    eVoxelAOBoundingBox,
    eShadowInterObjects,
    eShadowOnPlane,
    eShadow,
    ePlanePositionAuto,
    eGroundRadiusAuto,
    eUpdate,
    eAll
  };
  
  enum EInternalType
  {
    eInfEnv,
    eAmbiance
  };

  EInternalType GetInternalType() const;

  //-------------------------
  // Unit/Referential System

  void             SetUnitRatio(float iUnitRatio);
  float            GetUnitRatio() const;

  enum EReferentialSystemType
  {
    eCustom = 0,
    eEarth
  };
  void             SetReferentialSystem(EReferentialSystemType iType);
  EReferentialSystemType GetReferentialSystem() const;

  //-------------------------
  // Setting

  static CATVisInfiniteEnvironment* CreateFromSettings(const CATString& iEnvID);
  void            SaveToSettings(const CATString& iID);
  static unsigned int GetEnvNumberInSettings();
  static HRESULT  IsEnvPresentInSettings(const CATString& iID);
  static HRESULT  GetCustomEnvNameFromSettings(unsigned int iID, CATString& oCustomEnvID, CATString& oCustomEnvName);
  static HRESULT  GetCustomEnvNameFromSettings(unsigned int iID, CATString& oCustomEnvID, CATString& oCustomEnvName, EInternalType& oType);
  static HRESULT  SwapEnvInSettings(unsigned int iID1, unsigned int iID2);
  static void     DeleteEnvInSettings(const CATString& iID);
  static void     DeleteAllEnvInSettings();
  static void     SetDefaultEnv(const CATString& iID);
  static void     SetDefaultEnv(const CATString& iID, const CATString& iWindowType);
  static void     SetDefaultEnv(const CATString& iID, const CATSupport& iSupport);
  static void     GetDefaultEnv(CATString& oID);
  static void     GetDefaultEnv(CATString& oID, const CATString& iWindowType);
  static void     GetDefaultEnv(CATString& oID, const CATSupport& iSupport);
  static void     SetInfEnvWindowType(const CATString& iWindowType, const CATSupport& iSupport);

  
  //-------------------------
  // Backgrounds

  CATVisBackgroundEnvData::CATVisBackgroundType GetBackgroundType(unsigned int iID) const;

  int     AddBasicBackground(const CATVisBackgroundEnvData& iData);
  int     AddBasicBackground(const CATVisBackgroundEnvData& iData, const CATVisUniformBackgroundEnvData& iUniformData);
  int     AddTexturedBackground(const CATVisBackgroundEnvData& iData, CATTexturePixelImage* iTextures[6]);
  int     Add2DTexturedBackground(const CATVisBackgroundEnvData& iData, const CATVisTextured2DBackgroundEnvData& iTexturedBackgroundData);
  int     AddTexturedBackground(const CATVisBackgroundEnvData& iData, const CATVisTexturedBackgroundEnvData& iTexturedBackgroundData);
  int     AddSky(const CATVisBackgroundEnvData& iData, const CATVisSkyEnvData& iSkyData);
  int     AddShaderBackground(const CATVisBackgroundEnvData& iData, const CATVisShaderBackgroundEnvData& iShaderData);

  HRESULT GetBackgroundData(unsigned int iID, CATVisBackgroundEnvData& oData) const;
  HRESULT GetBackgroundData(unsigned int iID, CATVisBackgroundEnvData& oData, CATVisBackgroundEnvData::CATVisBackgroundType& oType) const;
  HRESULT GetUniformBackgroundData(unsigned int iID, CATVisUniformBackgroundEnvData& oUniformData) const;
  HRESULT GetTexturedBackgroundData(unsigned int iID, CATVisTexturedBackgroundEnvData& oTexturedBackgroundData) const;
  HRESULT GetSkyData(unsigned int iID, CATVisSkyEnvData& oSkyData) const;
  HRESULT GetShaderBackgroundParam(unsigned int iID, unsigned int iParamID, CATString& oParamShader) const;
  HRESULT GetShaderBackgroundData(unsigned int iID, CATVisShaderBackgroundEnvData& oShaderData) const;
  HRESULT GetShaderBackgroundData(unsigned int iID, const CATString& iParamShader, float& oValue, float& oMinValue, float& oMaxValue, float& oStepValue) const;
  HRESULT GetShaderBackgroundData(unsigned int iID, const CATString& iParamShader, CATVisColorf& oColor) const;
  HRESULT GetShaderBackgroundData(unsigned int iID, const CATString& iParamShader, CATString& oString) const;

  HRESULT ModifyBackground(unsigned int iID, const CATVisBackgroundEnvData& iData);
  HRESULT ModifyBasicBackground(unsigned int iID, const CATVisUniformBackgroundEnvData& iUniformData);
  HRESULT ModifyTexturedBackground(unsigned int iID, const CATVisTexturedBackgroundEnvData& iTexturedBackgroundData);
  HRESULT ModifySky(unsigned int iID, const CATVisSkyEnvData& iData);
  HRESULT ModifyShaderBackground(unsigned int iID, const CATVisShaderBackgroundEnvData& iData);
  HRESULT ModifyShaderBackground(unsigned int iID, const CATVisParameters& iParameters, bool iReplaceAllParameters = false);
  HRESULT ModifyShaderBackground(unsigned int iID, const CATString& iParamShader, const float iValue);
  HRESULT ModifyShaderBackground(unsigned int iID, const CATString& iParamShader, const CATVisColorf& iColor);
  HRESULT ModifyShaderBackground(unsigned int iID, const CATString& iParamShader, const CATString& iString);
  
  void    RemoveBackground(unsigned int iID);
  void    RemoveBackgrounds(CATVisBackgroundEnvData::CATVisBackgroundPosition iPosition);
  void    RemoveAllBackgrounds();

  void    SetBackgroundMainColor(const CATVisColor& iColor);


  //-------------------------
  // Lighting

  // 1. Lights

  CATVisLightEnvData::CATVisLightType GetLightType(unsigned int iID) const;

  int     AddLight(const CATVisLightEnvData& iData);
  int     AddMinerLamp(const CATVisLightEnvData& iData);
  int     AddSun(const CATVisLightEnvData& iData, const CATVisSunEnvData& iSunData);

  HRESULT GetLightData(unsigned int iID, CATVisLightEnvData& oData) const;
  HRESULT GetLightData(unsigned int iID, CATVisLightEnvData& oData, CATVisLightEnvData::CATVisLightType& oType) const;
  HRESULT GetSunData(unsigned int iID, CATVisSunEnvData& oSunData) const;

  HRESULT ModifyLight(unsigned int iID, const CATVisLightEnvData& iData);

  void    RemoveLight(unsigned int iID);
  void    RemoveAllLights();


  // 2. Global lighting

  // 2.1 Global Illumination
  CATVisGlobalIlluminationEnvData::EType GetGlobalIlluminationType() const;
  int     IsGlobalIlluminationActivated();
  HRESULT GetGlobalIlluminationData(CATVisUniformGIEnvData& oData)        const;
  HRESULT GetGlobalIlluminationData(CATVisFacticeLightsGIEnvData& oData)  const;
  void    RemoveGlobalIllumination();
  void    SetGlobalIllumination(const CATVisUniformGIEnvData& iData);
  void    SetGlobalIllumination(const CATVisFacticeLightsGIEnvData& iData);

  // 2.2 Ambient Occlusion
  HRESULT GetAmbOcclusionData(CATVisSSAOData& oData)   const;
  HRESULT GetAmbOcclusionData(CATVisVoxelAOData& oData)   const;
  HRESULT GetAmbOcclusionData(CATVisHQAOData& oData)   const;
  void    SetAmbOcclusion(const CATVisSSAOData& iData);
  void    SetAmbOcclusion(const CATVisVoxelAOData& iData);
  void    SetAmbOcclusion(const CATVisHQAOData& iData);

  struct AO
  {
    ;
    enum EType
    {
      eSSAO,
      eVoxelAO,
      eHQAO
    };
  };
  void    RemoveAmbOcclusion(AO::EType iType = AO::eSSAO);
  

  // 3. Sky Lighting
  CATVisSkyLightingData::EType GetSkyLightingType()           const;
  HRESULT GetSkyLightingData(CATVisIBLData& oData)            const;
  HRESULT GetSkyLightingData(CATVisProceduralIBLData& oData)  const;
  void    RemoveSkyLighting();
  void    SetSkyLighting(const CATVisIBLData& iData);
  void    SetSkyLighting(const CATVisProceduralIBLData& iData);

  // 4. Reflected Lighting
  CATVisReflectedLightingData::EType GetReflectedLightingType() const;
  HRESULT GetReflectedLightingData(CATVisSSRData& oData) const;
  void    RemoveReflectedLighting();
  void    SetReflectedLighting(const CATVisSSRData& iData);

  // old methode (obsolete with NRE)
  void    SetEnvMap(const CATVisEnvMapData& iData);
  HRESULT GetEnvMap(CATVisEnvMapData& oData);


 //-------------------------
  // Plane

  CATVisPlaneEnvData::CATVisPlaneTextureType GetPlaneTextureType() const;
  void    SetPlane(const CATVisPlaneEnvData& iData);
  void    SetPlaneTexture(const CATVisPlaneShaderEnvData&          iTextureData);
  void    SetPlaneTexture(const CATVisPlaneFacticeCatcherEnvData&  iTextureData);
  void    SetPlaneTexture(const CATVisPlaneInvisibleEnvData&       iTextureData);
  void    SetPlaneShader(const CATVisPlaneShaderEnvData&          iTextureData);
  HRESULT GetPlaneData(CATVisPlaneEnvData& oData) const;
  HRESULT GetPlaneTextureData(CATVisPlaneShaderEnvData&          oTextureData)  const;
  HRESULT GetPlaneTextureData(CATVisPlaneFacticeCatcherEnvData&  oTextureData)  const;
  HRESULT GetPlaneTextureData(CATVisPlaneInvisibleEnvData&       oTextureData)  const;
  HRESULT GetPlaneShaderData(CATVisPlaneShaderEnvData&          oTextureData)  const;
  void    RemovePlane();
  void    RemovePlaneTexture();


  //-------------------------
  // Effets

  // 1. Common Effects

  // 1.1 Bloom
  CATVisBloomData::EType GetBloomType() const;
  HRESULT   GetBloomData(CATVisBloomBasicData& oData) const;
  void      RemoveBloom();
  void      SetBloom(const CATVisBloomBasicData& iData);

  // 1.2 Depth Of Field
  CATVisDOFData::EType GetDOFType() const;
  HRESULT   GetDOFData(CATVisDOFBokehData&  oData) const;
  HRESULT   GetDOFData(CATVisDOFShaderData& oData) const;
  void      RemoveDOF();
  void      SetDOF(const CATVisDOFBokehData&  iBokehData);
  void      SetDOF(const CATVisDOFShaderData& iShaderData);

  // 1.3 Vignetting

  CATVisVignettingData::EType GetVignettingType() const;
  HRESULT   GetVignettingData(CATVisVignettingPhotographicData& oData) const;
  void      RemoveVignetting();
  void      SetVignetting(const CATVisVignettingPhotographicData& iData);


  // 2. Custom Effects
  int AddEffect(const CATVisEffectData& iData);

  HRESULT GetEffectParam(unsigned int iID, unsigned int iParamID, CATString& oParamShader) const;
  HRESULT GetEffectData(unsigned int iID, CATVisEffectData& oEffectData) const;
  HRESULT GetEffectData(unsigned int iID, const CATString& iParamShader, float& oValue, float& oMinValue, float& oMaxValue, float& oStepValue) const;
  HRESULT GetEffectData(unsigned int iID, const CATString& iParamShader, CATVisColorf& oColor) const;
  HRESULT GetEffectData(unsigned int iID, const CATString& iParamShader, CATString& oString) const;

  HRESULT ModifyEffect(unsigned int iID, const CATVisParameters& iParameters);
  HRESULT ModifyEffect(unsigned int iID, const CATString& iParamShader, const float iValue);
  HRESULT ModifyEffect(unsigned int iID, const CATString& iParamShader, const CATVisColorf& iColor);
  HRESULT ModifyEffect(unsigned int iID, const CATString& iParamShader, const CATString& iString);

  void    RemoveEffects(CATVisEffectPositionEnum iPosition);
  void    RemoveAllEffects();


  //-------------------------
  // Color Processing

  // Exposure
  CATVisExposureData::EType GetExposureType() const;
  HRESULT GetExposureData(CATVisExposureFixData&                oData)  const;
  HRESULT GetExposureData(CATVisExposureAutomaticBasicData&     oData)  const;
  HRESULT GetExposureData(CATVisExposureAutomaticHistogramData& oData)  const;
  void    RemoveExposure();
  void    SetExposure(const CATVisExposureFixData&                iData);
  void    SetExposure(const CATVisExposureAutomaticBasicData&     iData);
  void    SetExposure(const CATVisExposureAutomaticHistogramData& iData);

  // Tone Mapping
  CATVisToneMappingData::EType GetToneMappingType() const;
  HRESULT GetToneMappingData(CATVisToneMappingReinhardData&     oData) const;
  HRESULT GetToneMappingData(CATVisToneMappingFilmicALUData&    oData) const;
  HRESULT GetToneMappingData(CATVisToneMappingPhotographicData& oData) const;
  void    RemoveToneMapping();
  void    SetToneMapping(const CATVisToneMappingReinhardData&     iData);
  void    SetToneMapping(const CATVisToneMappingFilmicALUData&    iData);
  void    SetToneMapping(const CATVisToneMappingPhotographicData& iData);

  // Gamma Correction
  void    GetGammaCorrectionData(CATVisGammaCorrectionData& oData) const;
  void    SetGammaCorrection(const CATVisGammaCorrectionData& iData);

  // Color Grading
  CATVisColorGradingData::EType GetColorGradingType() const;
  HRESULT GetColorGradingData(CATVisColorGradingLUTData& oData) const;
  HRESULT GetColorGradingData(CATVisColorGradingSMHData& oData) const;
  void    SetColorGrading(const CATVisColorGradingLUTData& iData);
  void    SetColorGrading(const CATVisColorGradingSMHData& iData);
  void    RemoveColorGrading();

  // hdr
  void SetHDRMode(CATVisHDRData::EMode iMode);
  CATVisHDRData::EMode GetHDRMode(int iSolveAutoMode = 1) const;

  //-------------------------
  // Media
  CATVisMediaData::EType GetMediaType() const;
  HRESULT   GetMediaData(CATVisMediaSkyScatteringData& oData) const;
  void      RemoveMedia();
  void      SetMedia(const CATVisMediaSkyScatteringData& iData);

  //---- Motionblur----------------
  CATVisMotionBlurData::EType GetMotionBlurType() const;
  HRESULT   GetMotionBlurData(CATVisMotionBlurCameraMotionData& oData) const;
  void      RemoveMotionBlurData();
  void      SetMotionBlurData(const CATVisMotionBlurCameraMotionData& iData);

  //-------------------------
  // Generic Parameters

  void  AddGenericParameters(const CATVisParameters & iParamsToAdd);
  const CATVisParameters & GetGenericParameter() const;


  //-------------------------
  // Prototype Visu. Not yet fully available 
  // Do not use that if your are an application

  /** This method enables the refraction.
   *  This is a prototype. DO NOT USE THIS !
   */
  void EnableRefraction();

  /** This method disables the refraction.
   *  This is a prototype. DO NOT USE THIS !
   */
  void DisableRefraction();


  //-------------------------
  // Dump

  void DumpCCode(CATUnicodeString& oCode);

  //-------------------------
  // Private Access
  // Allow giving access to specific private method for an object

  friend class PrivateAccess;
  class PrivateAccess
  {
    friend class l_CATSupport;
    friend class vREShadows;
    friend class vREVoxels;
    friend class vREAmbiance;
    friend class vREPassSystemUpdater;
    friend class vREViewpoint;
    friend class l_vREPassSystemFactory;
    friend class CATVisInfiniteEnvGroundOverload;
    friend class VisRayTracingDlg;
    friend class VisInfiniteEnvNewPanel;
    friend class VisAmbianceOverloaderPanel;
    friend class CATVisAmbianceTranslator;
    friend class VisGenerateAmbianceBehaviour;

  private:
    static const CATVisInfiniteEnvironmentExtendedData* GetData           (const CATVisInfiniteEnvironment* iEnv) {return iEnv ? iEnv->GetData() : NULL;}
    static const CATVisAmbiance*                        GetAmbiance       (const CATVisInfiniteEnvironment* iEnv) {return iEnv ? iEnv->GetAmbiance() : NULL;}
    static void                                         SwapBackgrounds   (CATVisInfiniteEnvironment* iEnv, unsigned int iID1, unsigned int iID2) { if (iEnv) iEnv->SwapBackgrounds(iID1, iID2); }
    static void                                         ApplicateOverload (CATVisInfiniteEnvironment* iEnv, CATVisInfiniteEnvironmentOverload& ioOverloadEnv, bool iAmbiance) { if (iEnv) iEnv->ApplicateOverload(ioOverloadEnv, iAmbiance); }
    static int                                          IsActivated       (const CATVisInfiniteEnvironment* iEnv, EProperty iProperty) { return iEnv ? iEnv->IsActivated(iProperty) : 0; }
    static void                                         ConvertToInfEnv   (CATVisInfiniteEnvironment* iEnv) { if (iEnv) iEnv->ConvertToInfEnv(); }
  };
    
  //-------------------------
  // deprecated -> ORE
  void    ActivateGlobalIllumination(int iOnOff);
  HRESULT GetSSAOGIData(CATVisSSAOGIEnvData& oData);
  HRESULT GetGlobalIllumination(CATVisGlobalIlluminationEnvData& oData);
  HRESULT GetGlobalIllumination(CATVisGlobalIlluminationEnvData& oData, CATVisGlobalIlluminationEnvData::EType& oType);
  void SetGlobalIllumination(const CATVisGlobalIlluminationEnvData& iData);
  void SetGlobalIllumination(const CATVisGlobalIlluminationEnvData& iData, const CATVisAmbOcclusionGIEnvData& iAOData);
  void SetGlobalIllumination(const CATVisGlobalIlluminationEnvData& iData, const CATVisUniformGIEnvData& iUniformData);
  void SetGlobalIllumination(const CATVisGlobalIlluminationEnvData& iData, const CATVisFacticeLightsGIEnvData& iFacticeLightsData);
  
  void    SetGlow(const CATVisGlowingData& iData);
  HRESULT GetGlow(CATVisGlowingData& oData);

  void    SetRealisticEnvironment(
    const CATVisLightEnvData& iSunLightData, const CATVisRealisticSunEnvData&  iSunData,
    const CATVisLightEnvData& iMoonLightData, const CATVisRealisticMoonEnvData& iMoonData,
    const CATVisBackgroundEnvData& iData, const CATVisRealisticSkyEnvData&  iSkyData);

  int     AddCloud(const CATVisBackgroundEnvData& iData, const CATVisCloudEnvData& iCloudData);
  HRESULT GetCloudData(unsigned int iID, CATVisCloudEnvData& oCloudData) const;
  HRESULT ModifyCloud(unsigned int iID, const CATVisCloudEnvData& iCloudData);
  
private:
  CATVisInfiniteEnvironment(const CATString& iName, CATVisAmbiance* iAmbiance = nullptr, CATVisPostEffects* iPostEffects = nullptr);
  CATVisInfiniteEnvironment(const CATVisInfiniteEnvironment& iInfEnv);
  virtual ~CATVisInfiniteEnvironment();

  CATVisInfiniteEnvironment& operator=(CATVisInfiniteEnvironment&) = delete;
    
  void Detach(CATVisInfiniteEnvironmentStack* iStack);
  void Attach(CATVisInfiniteEnvironmentStack* iStack);
  const CATVisInfiniteEnvironmentExtendedData* GetData() const;

  int IsActivated(EProperty iProperty)   const;
  
  // private because use is dangerous
  // only used by internal editor
  void SwapBackgrounds(unsigned int iID1, unsigned int iID2);

  void SetModify(bool iUpdateDeferredAlgo = false);
  void InvalidSkyLighting();

  void SetVersion(const int& iVersion);

  void ApplicateOverload  (CATVisInfiniteEnvironmentOverload& ioOverloadEnv, bool iAmbiance = false);

  // gestion des surcharge des proprietes par defaut 
  // sur le CATSupport et CATVizViewer
  void SetOverloadBg(int iOnOff);
  void SetOverloadLights(int iOnOff);
  void SetOverloadGlobalIllumination(int iOnOff);
  
  // streal/unstream
  void Read(CATVisStreamer& ioStreamer, const CATString& iID);
  void Write(CATVisStreamer& ioStreamer, const CATString& iID);
  static void InitStreamer(CATVisStreamer& oStreamer);

  CATVisInfiniteEnvType                   _type;
  CATVisInfiniteEnvironmentExtendedData*  _data;

  list<CATVisInfiniteEnvironmentStack>    _stacks;

  // Update
  void                  Update();
  void                  UpdateForODT();

  // Remove link to CATVisAmbiance and CATVisPostEffects
  void ConvertToInfEnv();

  // Ambiance 
  void                  UpdateFromAmbiance();
  CATVisAmbiance*       GetAmbiance();
  const CATVisAmbiance* GetAmbiance() const;

  CATVisAmbiance* _ambiance;

  // Post Effects
  void                  UpdateFromPostEffects();
  void                  UpdateFromPostEffects(const CATVisPostEffects::ToneMapping::Generic& iData);
  CATVisPostEffects*    GetPostEffects();
  const CATVisPostEffects* GetPostEffects() const;
  
  CATVisPostEffects* _postEffects;

  //Generic Parameters
  CATVisParameters _genericParameters;
};

//-----------------------------------------------------------------------

#endif
