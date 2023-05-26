#ifndef CATVisAmbiance_H
#define CATVisAmbiance_H

#include "SGInfra.h"
#include "CATVizBaseIUnknown.h"

#include "CATVisColorf.h"
#include "list.h"

#include "CATString.h"
#include "CAT4x4Matrix.h"
#include "CATMathPoint.h"
#include "IVisTexturePtr.h"

class CATGraphicMaterial;
class CATVisAmbianceData;
class CATVisInfiniteEnvironmentStack;
class CATVisParameters;
class CATMathTransformation;
class CATVisStreamer;

class ExportedBySGInfra CATVisAmbiance : public CATVizBaseIUnknown
{
  friend class VisAmbiancePanel;
  friend class CATVisInfiniteEnvironment;
  friend class l_CATSupport;

public:
  static CATVisAmbiance* Create(const char* iID = nullptr);
  CATVisAmbiance* Clone() const;
  const CATVisAmbiance& operator=(const CATVisAmbiance& iAmbiance);
  bool operator==(const CATVisAmbiance& iAmbiance) const;
  bool operator!=(const CATVisAmbiance& iAmbiance) const;
  
  // Settings
  static CATVisAmbiance* CreateFromSettings (const char* iID);

  //--------------------------
  // Image
  // Class to internaly manage a texture.
  // The texture can be:
  // * a string   : a full path to the texture's file
  // * a pointer  : an IVisTexture

  class ExportedBySGInfra Image
  {
  public:
    Image();
    Image(const Image& iImage);
    const Image& operator=(const Image& iImage);
    ~Image();
    bool operator==(const Image& iData) const;
    bool operator!=(const Image& iData) const;
    
    // Service
    // This method forces IVisTexture loading from path if a path has been set on thie Image
    // NB: if loading is a success, path is unset
    void LoadIVisTexture();

    // IVisTexture
    IVisTexture*          GetTexture()          { return m_Texture.Get();};
    const IVisTexturePtr& GetTexturePtr() const { return m_Texture; };
    const Image& operator=(const IVisTexturePtr& iTexture);

    // Path
    const CATString& GetPath() const { return m_Path; };
    const Image& operator=(const CATString&   iPath);

    // Parameters
    void SetParameter(const CATString& iName, const CATVisParameters& iParameters);
    void GetParameter(const CATString& iName, CATVisParameters& oParameters) const;

  private:
    CATString       m_Path;
    IVisTexturePtr  m_Texture;
  };

  //--------------------------
  // Material
  // Class to internaly manage a Material.

  class ExportedBySGInfra Material
  {
  public:
    Material();
    Material(const Material& iMaterial);
    const Material& operator=(const Material& iMaterial);
    ~Material();
    bool operator==(const Material& iData) const;
    bool operator!=(const Material& iData) const;

    const CATGraphicMaterial* GetMaterial() const { return m_Material; };
    const Material& operator=(CATGraphicMaterial* iMaterial);
        
  private:
    CATGraphicMaterial* m_Material;
  };
  

  //--------------------------
  // Global

  const CATString& GetID() const { return m_ID; }; 

  void SetTranslation(const CATMathVector&  iTranslation);
  void GetTranslation(CATMathVector&        oTranslation) const;

  void SetRotationAngles(float  iAngleX, float  iAngleY, float  iAngleZ);
  void GetRotationAngles(float& oAngleX, float& oAngleY, float& oAngleZ) const;

  void GetTransformation(CATMathTransformation&       oTransfo) const;
  void SetTransformation(const CATMathTransformation& iTransfo);

  //--------------------------
  // Services

  // Load all IVisTextures
  // This methode is going to force loading of all IVisTexture for all Image's parameters that are currently present in CATVisAmbiance
  // By this way, all images that uses only path are going to load associated IVisTexture and unset their path.
  // Before: image.GetPath()      -> "myPath\myTexture.dds"
  //         image.GetTexture()   -> NULL
  // After:  image.GetPath()      -> ""
  //         image.GetTexture()   -> pointer to IVisTexture
  void LoadAllIVisTexture();

  //--------------------------
  // Background

  struct ExportedBySGInfra Background
  {
    Background();
    bool operator==(const Background& iData) const;
    bool operator!=(const Background& iData) const;
    
    enum EType
    {
      eNone = 0,
      eColor,
      eGradient,
      eGradientWithHorizon,
      eCubeMap,
      eLatLong,
      eBackPlate
    };

    float intensity;

    struct ExportedBySGInfra Color
    {
      Color();
      bool operator==(const Color& iData) const;
      bool operator!=(const Color& iData) const;

      CATVisColorf color;
    };

    struct ExportedBySGInfra Gradient
    {
      Gradient();
      bool operator==(const Gradient& iData) const;
      bool operator!=(const Gradient& iData) const;

      // Gradient from color[0] to color[1]
      // color[0]: top     (0,0, 1)
      // color[1]: bottom  (0,0,-1)
      CATVisColorf color[2];
    };

    struct ExportedBySGInfra GradientWithHorizon
    {
      GradientWithHorizon();
      bool operator==(const GradientWithHorizon& iData) const;
      bool operator!=(const GradientWithHorizon& iData) const;

      // Gradient from color[0] to color[1] to color[2] to color[3]
      // Color[0]: top (0,0, 1)
      // Color[1]: horizon+horizonHeight  
      // Color[2]: horizon+horizonHeight  
      // Color[3]: bottom (0,0,-1)
      CATVisColorf  color[4];
      float         horizonHeight;
    };

    struct ExportedBySGInfra CubeMap
    {
      CubeMap();
      bool operator==(const CubeMap& iData) const;
      bool operator!=(const CubeMap& iData) const;

      Image   image;
    };

    struct ExportedBySGInfra LatLong
    {
      LatLong();
      bool operator==(const LatLong& iData) const;
      bool operator!=(const LatLong& iData) const;

      Image image;
    };

    struct ExportedBySGInfra BackPlate
    {
      BackPlate();
      bool operator==(const BackPlate& iData) const;
      bool operator!=(const BackPlate& iData) const;

      enum ESizeScaling
      {
        eBestFit,
        eFitWidth,
        eFitHeight
      };

      Image         image;
      ESizeScaling  sizeScaling;
    };
  };

  Background::EType GetBackgroundType() const;


  void GetBackground(Background&                      oData) const;
  void GetBackground(Background::Color&               oData) const;
  void GetBackground(Background::Gradient&            oData) const;
  void GetBackground(Background::GradientWithHorizon& oData) const;
  void GetBackground(Background::CubeMap&             oData) const;
  void GetBackground(Background::LatLong&             oData) const;
  void GetBackground(Background::BackPlate&           oData) const;
  void GetBackground(CATVisParameters&                oParameters) const;

  void SetBackground(const Background&                      iData);
  void SetBackground(const Background::Color&               iData);
  void SetBackground(const Background::Gradient&            iData);
  void SetBackground(const Background::GradientWithHorizon& iData);
  void SetBackground(const Background::CubeMap&             iData);
  void SetBackground(const Background::LatLong&             iData);
  void SetBackground(const Background::BackPlate&           iData);
  void SetBackground(const CATVisParameters&                iParameters);

  void RemoveBackground();



  //--------------------------
  // Background Geometry

  struct ExportedBySGInfra BackgroundGeometry
  {
    BackgroundGeometry();
    bool operator==(const BackgroundGeometry& iData) const;
    bool operator!=(const BackgroundGeometry& iData) const;

    enum EType
    {
      eNone = 0,
      eSphere
    };

    float           size;
    CATMathPoint    shootPosition;

    struct ExportedBySGInfra Sphere
    {
      Sphere();
      bool operator==(const Sphere& iData) const;
      bool operator!=(const Sphere& iData) const;
    };
  };

  BackgroundGeometry::EType GetBackgroundGeometryType() const;

  void GetBackgroundGeometry(BackgroundGeometry&          oData)        const;
  void GetBackgroundGeometry(BackgroundGeometry::Sphere&  oData)        const;
  void GetBackgroundGeometry(CATVisParameters&            oParameters)  const;

  void SetBackgroundGeometry(const BackgroundGeometry&          iData);
  void SetBackgroundGeometry(const BackgroundGeometry::Sphere&  iData);
  void SetBackgroundGeometry(const CATVisParameters&            iParameters);

  void RemoveBackgroundGeometry();



  //--------------------------
  // Ground

  struct ExportedBySGInfra Ground
  {
    Ground();
    bool operator==(const Ground& iData) const;
    bool operator!=(const Ground& iData) const;

    enum EType
    {
      eNone = 0,
      eTransparent,
      ePhysical
    };

    float height;

    struct ExportedBySGInfra Transparent
    {
      Transparent();
      bool operator==(const Transparent& iData) const;
      bool operator!=(const Transparent& iData) const;

      float         reflectivity;
      float         glossiness;
      float         shadowIntensity;
    };

    struct ExportedBySGInfra Physical
    {
      Physical();
      bool operator==(const Physical& iData) const;
      bool operator!=(const Physical& iData) const;

      Material      material;
    };
  };

  Ground::EType GetGroundType() const;

  void GetGround(Ground&              oData)        const;
  void GetGround(Ground::Transparent& oData)        const;
  void GetGround(Ground::Physical&    oData)        const;
  void GetGround(CATVisParameters&    oParameters)  const;

  void SetGround(const Ground&                iData);
  void SetGround(const Ground::Transparent&   iData);
  void SetGround(const Ground::Physical&      iData);
  void SetGround(const CATVisParameters&      iParameters);

  void RemoveGround();


  //--------------------------
  // Directionnal Lights

  struct ExportedBySGInfra Light
  {
    Light();
    bool operator==(const Light& iData) const;
    bool operator!=(const Light& iData) const;

    void SetDirection(const CATMathDirectionf& iDirection);
    void GetDirection(CATMathDirectionf& oDirection) const;

    CATVisColorf  color;
    CAT4x4Matrix  matrix;
    float         value;
    bool          castShadows;

    enum EAxis
    {
      eGlobal = 0,
      eCamera
    };

    EAxis         axis;

    bool          facticeLight;
  };
  
  unsigned int GetNumLights() const;
  void GetLight(unsigned int iID, Light& oData)         const;
  void GetLight(unsigned int iID, CATVisParameters& oParameters)   const;

  unsigned int AddLight(const Light& iData);

  void ModifyLight(unsigned int iID, const Light& iData);
  void ModifyLight(unsigned int iID, const CATVisParameters& iParameters);

  void RemoveLight(unsigned int iID);

  void EmptyLights();


  //--------------------------
  // Environment Light

  struct ExportedBySGInfra EnvironmentLight
  {
    EnvironmentLight();
    bool operator==(const EnvironmentLight& iData) const;
    bool operator!=(const EnvironmentLight& iData) const;

    enum EType
    {
      eNone = 0,
      eCubeMap,
      eLatLong
    };

    float         value;
    Image         image;
    EType         type;
    CAT4x4Matrix  matrix;
  };

  EnvironmentLight::EType GetEnvironmentLightType() const;
  void GetEnvironmentLight(EnvironmentLight& oData)       const;
  void GetEnvironmentLight(CATVisParameters& oParameters) const;
  void SetEnvironmentLight(const EnvironmentLight& iData);
  void SetEnvironmentLight(const CATVisParameters& iParameters);
  void RemoveEnvironmentLight();

  double GetIlluminance() const;

  //--------------------------
  // Sky Light

  struct ExportedBySGInfra SkyLight
  {
    SkyLight();
    bool operator==(const SkyLight& iData) const;
    bool operator!=(const SkyLight& iData) const;

    CATMathDirectionf   sunDirection;
    float               observerAltitude;
    float               intensity;
    bool                enabled;
  };

  void GetSkyLight(SkyLight& oData)               const;
  void GetSkyLight(CATVisParameters& oParameters) const;
  void SetSkyLight(const SkyLight& iData);
  void SetSkyLight(const CATVisParameters& iParameters);
  void RemoveSkyLight();


  //--------------------------
  // Render settings

  struct ExportedBySGInfra RenderSettings
  {
    //--------------------------
    // Ambient Occlusion
    struct ExportedBySGInfra AmbientOcclusion
    {
      AmbientOcclusion();
      bool operator==(const AmbientOcclusion& iData) const;
      bool operator!=(const AmbientOcclusion& iData) const;

      float radius;     // radius in model unit which defines the influence sphere of ambient occlusion
      float hqaoRadius; // specific radius (usually much larger) for ray traced ambient occlusion only
      float intensity;  // factor to ponderate ambient occlusion (0-> no effect)
      bool  activation; 
    };

    //--------------------------
    // Reflections
    struct ExportedBySGInfra Reflections
    {
      Reflections();
      bool operator==(const Reflections& iData) const;
      bool operator!=(const Reflections& iData) const;

      bool activation;
    };
  };

  void SetAmbientOcclusion(const RenderSettings::AmbientOcclusion& iData);
  void SetAmbientOcclusion(const CATVisParameters& oParameters);
  void GetAmbientOcclusion(RenderSettings::AmbientOcclusion& oData) const;
  void GetAmbientOcclusion(CATVisParameters& oParameters) const;

  void SetReflections(const RenderSettings::Reflections& iData);
  void SetReflections(const CATVisParameters& oParameters);
  void GetReflections(RenderSettings::Reflections& oData) const;
  void GetReflections(CATVisParameters& oParameters) const;

  //--------------------------
  // Generic

  enum EObjectType
  {
    eNone,
    eGlobal,
    eInfo,
    eBackground,
    eBackgroundGeometry,
    eGround,
    eLight,
    eEnvironmentLight,
    eAmbientOcclusion,
    eReflections,
    eSkyLight
  };

  void Set(EObjectType iObjectType, unsigned int iID, const CATVisParameters& iParameters);
  void Get(EObjectType iObjectType, unsigned int iID, CATVisParameters& oParameters) const;

private:
  CATVisAmbiance(const char* iID);
  CATVisAmbiance(const CATVisAmbiance& iAmbience);
  virtual ~CATVisAmbiance();

  void _Write(CATVisStreamer& ioStreamer, const CATString& iID) const;

  bool _IsIdentical(const CATVisAmbiance& iAmbience);

  void _SetModify (bool iUpdateDeferredAlgo = false);
  void _Detach    (CATVisInfiniteEnvironmentStack* iStack);
  void _Attach    (CATVisInfiniteEnvironmentStack* iStack);

  void             _SetID   (const CATString& iID)    { m_ID = iID; };
  const CATString& _GetName ()                        { return m_Name; };
  void             _SetName (const CATString& iName)  { m_Name = iName; };

  bool _IsDefaultAmbientOcclusion() const;

  class color_t {
  private:
    float data[3];
  public:
    explicit color_t(const float& r, const float& g, const float& b) : data{ r, g, b } {}
    explicit color_t(const float* const ptr) : data{ ptr[0], ptr[1], ptr[2] } {}
    inline const float& operator[](const size_t& idx) const { return data[idx]; }
    inline float& operator[](const size_t& idx) { return data[idx]; }
    inline color_t& operator+=(const color_t& rhs) {
      data[0] += rhs.data[0]; data[1] += rhs.data[1]; data[2] += rhs.data[2]; return *this; }
    inline color_t operator*(const float& k) const {
      return color_t(k * data[0], k * data[1], k * data[2]); }
    inline color_t operator+(const color_t& v) const {
      return color_t(data[0] + v.data[0], data[1] + v.data[1], data[2] + v.data[2]); }
    inline color_t operator-(const color_t& v) const {
      return color_t(data[0] - v.data[0], data[1] - v.data[1], data[2] - v.data[2]); }
  };

  double CalculateAmbianceIlluminance() const;
  double CalculateImageIlluminance(const CATPixelImage* const image) const;

  list<CATVisInfiniteEnvironmentStack> m_Stacks;

  CATVisAmbianceData* m_Data;
  CATString           m_ID, m_Name;
};

#endif
