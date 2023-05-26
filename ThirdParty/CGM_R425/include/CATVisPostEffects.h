#ifndef CATVisPostEffects_H
#define CATVisPostEffects_H

#include "SGInfra.h"
#include "CATVizBaseIUnknown.h"

#include "CATVisParameters.h"
#include "IVisTexturePtr.h"
#include "list.h"
#include "CATVisColorf.h"

class CATVisInfiniteEnvironmentStack;
class CATVisStreamer;
class CATString;
class ExportedBySGInfra CATVisPostEffects : public CATVizBaseIUnknown
{
  friend class CATVisInfiniteEnvironment;

public:
  //--------------------------------------------------
  // Lifecycle

  static CATVisPostEffects* Create();
  const CATVisPostEffects& operator=(const CATVisPostEffects& iPostEffects);
  CATVisPostEffects* Clone() const;
  
  // Settings
  static CATVisPostEffects* CreateFromSettings(const char* iID);
  
  //--------------------------------------------------
  // Tone Mapper

  struct ExportedBySGInfra ToneMapping
  {
    enum EType
    {
      eNone,
      ePhotographic,
      eFilmic
    };
    
    struct ExportedBySGInfra Generic
    {
      Generic();
      bool operator==(const Generic& iData) const;

      float         exposure;         // exposition in EV

      struct AutoExposure
      {
        bool            activation;
        float           clampMin;
        float           clampMax;
        IVisTexturePtr  regionOfInterest;
      };
      AutoExposure  autoExposure;

      float         vignetting;       // vigneting's power : color *= (focalLength^2 / (sensorSize^2 * distance(pos,center)^2 - focalLength^2))^vignetting
      float         gammaCorrection;  // gamma correction
    };

    struct ExportedBySGInfra Photographic : public Generic
    {
      Photographic();
      bool operator==(const Photographic& iData) const;

      float         crushBlack;       // from 0 to 1
      float         burnHighlight;    // from 0 to 1
      float         saturation;       // from 0 to 1
      CATVisColorf  colorCorrection;  // color correction (see CATRamHDRAmbienceToneMappingParameter::ComputeColorCorrection to have the formula)
    };

    struct ExportedBySGInfra Filmic : public Generic
    {
      // Formula: 
      //  F(x) = ((x*(a*x+c*b)+d*e)/(x*(a*x+b)+d*f))-e/f;
      //  col  = F(col)/F(w);

      Filmic();
      bool operator==(const Filmic& iData) const;
      
      float         a; // Shoulder Strength
      float         b; // Linear Strength
      float         c; // Linear Angle
      float         d; // Toe Strength
      float         e; // Toe Numerator
      float         f; // Toe Denominator
      float         w; // Linear White Point Value
    };
  };

  ToneMapping::EType GetToneMappingType() const;
  bool  GetToneMapping    (ToneMapping::Photographic& oData) const;
  bool  GetToneMapping    (ToneMapping::Filmic& oData) const;
  void  SetToneMapping    (const ToneMapping::Photographic& iData);
  void  SetToneMapping    (const ToneMapping::Filmic& iData);
  void  UnsetToneMapping  ();
  


  //--------------------------------------------------
  // Bloom

  struct ExportedBySGInfra Bloom
  {
    enum EType
    {
      eNone,
      eBasic
    };
    
    struct ExportedBySGInfra Basic
    {
      Basic();
      bool operator==(const Basic& iData) const;

      float intensity;
      float intensityThreshold;
    };
  };

  Bloom::EType GetBloomType() const;
  bool  GetBloom(Bloom::Basic& oData) const;
  void  SetBloom(const Bloom::Basic& iData);
  void  UnsetBloom();

  // Motionblur
  struct ExportedBySGInfra MotionBlur
  {
    enum EType
    {
      eNone,
      eCameraMotion
    };

    struct ExportedBySGInfra CameraMotion
    {
      CameraMotion();
      bool operator==(const CameraMotion& iData) const;

      float strength; // scale parameter for the length of the motion vectors.
    };
  };

  MotionBlur::EType GetMotionBlurType() const;
  bool  GetMotionBlur(MotionBlur::CameraMotion& oData) const;
  void  SetMotionBlur(const MotionBlur::CameraMotion& iData);
  void  UnsetMotionBlur();
  // Motionblur !

  //--------------------------------------------------
  // Depth of field

  struct ExportedBySGInfra DepthOfField
  {
    enum EType
    {
      eNone,
      eBokeh
    };
    
    struct ExportedBySGInfra Bokeh
    {
      Bokeh();
      bool operator==(const Bokeh& iData) const;

      IVisTexturePtr bokehTexture;    // Bokeh's Pattern
    };
  };

  DepthOfField::EType GetDepthOfFieldType() const;
  bool  GetDepthOfField(DepthOfField::Bokeh& oData) const;
  void  SetDepthOfField(const DepthOfField::Bokeh& iData);
  void  UnsetDepthOfField();



  //--------------------------------------------------
  // Color Grading

  struct ExportedBySGInfra ColorGrading
  {
    enum EType
    {
      eNone,
      eLUT
    };
    
    struct ExportedBySGInfra LUT
    { 
      LUT();
      bool operator==(const LUT& iData) const;

      // lookuptTable to transform color
      // Basicaly, it is a (tileSize*tileSize, tileSize) texture (tileSize Tiles of tileSize*tileSize pixels)
      //
      //          B=0                   B=1.f/_size      ...             B=1.f       
      //     R=0 ------> R=1          R=0 ------> R=1    ...         R=0 ------> R=1
      // G=0                      G=0                    ...     G=0                
      // 0                        0                      ...     0                  
      // |                        |                      ...     |                  
      // |                        |                      ...     |                  
      // |                        |                      ...     |                  
      // V                        V                      ...     V                  
      //                                                 ...                        
      // G=1                      G=1                    ...     G=1   
      //
      IVisTexturePtr  lookupTable;      
      unsigned int    tileSize;         // size of one tile (width or height of each tile. NB: width and height have to be equal)
    };
  };

  ColorGrading::EType GetColorGradingType() const;
  bool  GetColorGrading(ColorGrading::LUT& oData) const;
  void  SetColorGrading(const ColorGrading::LUT& iData);
  void  UnsetColorGrading();


  //--------------------------------------------------
  // Generic

  enum EObjectType
  {
    eNone,
    eToneMapping,
    eBloom,
    eDepthOfField,
    eColorGrading,
    eMotionBlur,
    eCount
  };
  
  bool    Get   (CATVisPostEffects::EObjectType iType, CATVisParameters& oParameters) const;
  void    Set   (CATVisPostEffects::EObjectType iType, const CATVisParameters& oParameters);
  void    Unset (EObjectType iType);

  bool operator!=(const CATVisPostEffects& iPostEffects) const;
  bool operator==(const CATVisPostEffects& iPostEffects) const;
  

private:
  CATVisPostEffects();
  CATVisPostEffects(const CATVisPostEffects& iPostEffects);
  ~CATVisPostEffects();

  void _Write     (CATVisStreamer& ioStreamer, const CATString& iID) const;

  void _SetModify (bool iUpdateDeferredAlgo = false);
  void _Detach    (CATVisInfiniteEnvironmentStack* iStack);
  void _Attach    (CATVisInfiniteEnvironmentStack* iStack);

  void _GetToneMapping(ToneMapping::Generic& oData) const;
  void _SetToneMapping(ToneMapping::Generic iData);

  list<CATVisInfiniteEnvironmentStack> m_Stacks;

  CATVisParameters  m_Parameters[eCount];
};


#endif

