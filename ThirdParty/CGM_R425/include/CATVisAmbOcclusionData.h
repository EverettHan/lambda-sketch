// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisAmbOcclusionEnvData_H
#define CATVisAmbOcclusionEnvData_H

#include "SGInfra.h"

#include "CATVisColor.h" 
#include "CATVisColorf.h" 
#include "CATVisParameters.h"

#include "CATString.h"

class ExportedBySGInfra CATVisAmbOcclusionData
{
public:
  CATVisAmbOcclusionData();
  virtual ~CATVisAmbOcclusionData();

  enum EType
  {
    eNone,
    eSSAO,
    eVXAO,
    eHQAO
  };
  
  unsigned int _usePlane;

private:
  friend class  VisCustomizeAO;
  friend class  CATVisInfiniteEnvironmentStreamer;
  friend class  vREPassSystemUpdater;
  friend class  VisAmbiancePerfoBehaviour;
  friend class  VisInfiniteEnvNewPanel;

  // allow not to take into account Quality Manager
  unsigned int _ignoreQualitySetting;
};

class ExportedBySGInfra CATVisSSAOData : public CATVisAmbOcclusionData
{
public:
  CATVisSSAOData();
  virtual ~CATVisSSAOData();
  bool operator==(const CATVisSSAOData& iData) const;
  bool operator!=(const CATVisSSAOData& iData) const;

  enum ERadiusType
  {
    FixedRadius         = 0,
    DynamicRadiusFromBE = 1
  };

  ERadiusType             _radiusType;

  // depend de _radiusType:
  // * FixedRadius : valeur en mm de 0 a l'infini
  // * DynamicRadiusFromBE : pourcentage du BE allant de 0 a 100
  float                   _radius;    

  // en % en la taille de la fenetre
  unsigned int            _adaptativeRadius;
  float                   _adaptativeMaxRadius;       // in % of window size
  unsigned int            _adaptativeMaxRadiusPixel;  // in pixels
  float                   _adaptativeMinRadius;       // in % of window size
  unsigned int            _adaptativeMinRadiusPixel;  // in pixels
  
  CATVisColor             _shadowsColor;
  float                   _contrast;
  float                   _power;
  float                   _attenuation;
  float                   _slotAngle;                 // entre 0 et 90
  unsigned int            _samplingQuality;
  unsigned int            _randomKernelSize;          // kernel is a _randomKernelSize*_randomKernelSize matrix

  enum EAOMode
  {
    eSSAO = 0,
    eHBAO,
    eHQAO,
    eHQAO_IBL
  };
  EAOMode                 _aoMode;

  enum EComputeAOMode
  {
    eInvDistance,         // ao = 1/(1+ratio*distance)
    eLinear               // ao = clamp(1-ratio*distance, 0, 1)
  };
  EComputeAOMode          _computeAOMode;

  enum EBlurAOMode
  {
    eAccurateLinear,      // linear blur cumulative ratio for edge detection from Z and Normal
    eFastGaussian         // gaussian blur with detection from Z and Normal
  };
  EBlurAOMode             _blurMode;
  unsigned int            _blur;
  unsigned int            _blurLevel;
  float                   _blurEdgeDetectionFromZ;
  float                   _blurEdgeDetectionFromNormal;
  float                   _blurEdgeDetectionFromZStrength;
  
  // optim perfo
  enum EOptimAOMode
  {
    eNone = 0,                                // No optimization
    eDownscale,                               // use _aoMapScale to downscale AO map 
    eInterleavingMultiPass,                   // use de/interleaving to generate AO map with various pass
    eInterleavingGeometryShader               // use de/interleaving to generate AO map in one pass with a geometry shader
  };
  EOptimAOMode             _optimAOMode;
  
  float                   _aoMapScale;        // scale factor for tje AO map before smooth post process -> only usefull in eDownscale mode 
  unsigned int            _linearZActivation; // activate linear z generation to enhance performances
  unsigned int            _mergeAOAndZ;       // Optim: AO factor and DeltaZ are writtent in a same texture 
                                              //        It allows optimizing texture access in the shader 
                                              //       (one call allow accessing ao and deltaz both)

  // ORE only
  unsigned int            _forceUniqueShaderImplementation;
  unsigned int            _forceCgFxTechnique; // 0: pas actif, 1: nv40, 2: glsl, 3:nv30, 4:arb;

  // NB: obsolete, ne sert plus a rien
  unsigned int            _randomQuality; 

  unsigned int GetNumAOSample       ()  const;
  unsigned int GetNumAOSamplingDir  ()  const;
};

class ExportedBySGInfra CATVisVoxelAOData : public CATVisAmbOcclusionData
{
public:
  CATVisVoxelAOData();
  virtual ~CATVisVoxelAOData();
  bool operator==(const CATVisVoxelAOData& iData) const;
  bool operator!=(const CATVisVoxelAOData& iData) const;

  //----------------------
  // Properties

  struct Radius
  {
    enum EType
    {
      eFixed,
      eFromBE
    };
  };
  
  CATVisColorf  color;
  float         power;    // ao = ao^power
  float         contrast; // ao = ao * contrast;

  float         offsetMultiplier;
  float         angleMultiplier;
  float         distanceMultiplier;
  float         startDistanceMultiplier;
  Radius::EType radiusType;
  float         radius;
  float         aoMin, aoMax;
  float         slotAngle;


  //----------------------
  // Quality
  bool          boundingBox;
  bool          updateEachFrame;

  struct Voxel
  {
    enum ESize
    {
      eSize32 = 0,
      eSize64,  
      eSize128,  
      eSize256, 
      eSize512,  
      eSize1024
    }; 
    
    enum EMode
    {
      eDefault = 0,
      eDerivative,          // dFdx, dFdy
      eConservativeRaster   // conervative rasterization
    };
  };

  struct Mipmap
  {
    enum EMode
    {
      eDefault = 0,
      eTrilinearFiltering,
      eOccFiltering,
      eTriOcc
    };
  };
  
  Voxel::ESize  voxelSize;
  unsigned int  sampling;
  Mipmap::EMode mipmapMode;
  Voxel::EMode  voxelMode;
  bool          disableMSAA;

  
  unsigned int GetVoxelSize()  const;
  unsigned int GetVoxelMipLevels() const;
  
  
  //----------------------
  // Debug

  struct Debug
  {
    enum EDirection
    {
      eNone = 0,
      eX,
      eY,
      eZ
    };

    enum EColorMode
    {
      eTextureCoord = 0,
      eValue
    };
        
    bool              activation;
    unsigned int      mip;
    bool              zTest;
    float             alpha;
    EDirection        direction;
    EColorMode        colorMode;
    float             occRef;
    EDirection        occDirection;
  } debug;
  
  //----------------------
  // Parameters
  struct Parameters
  {
    enum Type
    {
      eProperties = 0,
      eQuality,
      eDebug,
      eCount,
      eAll
    };
  };

  virtual void GetParameters(CATVisParameters&       oParameters, Parameters::Type iType) const;
  virtual void SetParameters(const CATVisParameters& iParameters, Parameters::Type iType);
};


class ExportedBySGInfra CATVisHQAOData : public CATVisAmbOcclusionData
{
public:
  CATVisHQAOData();
  virtual ~CATVisHQAOData();
  bool operator==(const CATVisHQAOData& iData) const;
  bool operator!=(const CATVisHQAOData& iData) const;

  virtual void GetParameters(CATVisParameters& oParameters) const;
  virtual void SetParameters(const CATVisParameters& iParameters);

  float radius;
  float power;
};

#endif
