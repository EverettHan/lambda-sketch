//-------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2010/04/23
//-------------------------------------------------------------------

#ifndef CATVisRayTracer_H
#define CATVisRayTracer_H

#include "SGInfra.h"
#include "CATVizBaseIUnknown.h"
#include "CATVisRayTracingProperties.h"
#include "CATString.h"
#include "VisQualityData.h"
#include "CATPixelImage.h"
#include "IVisTexturePtr.h"

//-----------------------------------------------------------------------

class ExportedBySGInfra CATVisRTAOProperties
{
public:
  CATVisRTAOProperties();
  ~CATVisRTAOProperties();

  unsigned int 	_activation;
  float         _radius;
  float         _numSample;
};

class ExportedBySGInfra CATVisRTShadowProperties
{
public:
  CATVisRTShadowProperties();
  ~CATVisRTShadowProperties();

  float 		    _angle;
  float 		    _numSample;
};

#define CATVisRTEffectTypeNum 3
enum ExportedBySGInfra CATVisRTEffectType
{
  CATVisRTAO=0,
  CATVisRTShadow,
  CATVisRTFullRayTracing
};

class CAT3DRep;
class CAT3DViewpoint;
class CAT3DLightSourceRep;
class CATVisuTextureData;
class CATMathPointf;
class CATMathDirectionf;
class CATVisEffect;
class CAT3DViewer;
class CATSupport;
class CATViewpoint;
class CATVisAmbiance;
class CATVisPostEffects;
class ExportedBySGInfra CATVisRayTracer: public CATVizBaseIUnknown
{
public:
  //--------------------------------
  // Geometry and Cameras

  virtual void DefineGeometry(CAT3DRep*  iRep) = 0;
  virtual void DefineEnvironmentPlane(int iActivation, const CATMathPointf& iPosition, const CATMathDirectionf& iNormal) = 0;
  virtual void DefineEnvironmentPlane(int iActivation, const CATMathPointf& iPosition, const CATMathDirectionf& iNormal, float iRadius);
    
  virtual void AddViewpoint(unsigned int iWidth,  unsigned int iHeight, 
                            float iMMUnit, float iRatioWH,
                            const CAT3DViewpoint& iViewpoint);

  virtual void AddViewpoint(unsigned int iWidth,  unsigned int iHeight, 
                            float iMMUnit, float iRatioWH,
                            const CAT3DViewpoint& iViewpoint,
                            unsigned int iX, unsigned int iY,
                            unsigned int iDx, unsigned int iDy); 
  virtual void ResetViewpoints() = 0;

  //--------------------------------
  // Ambiance
  // This method can be overload to be warmed when ambiance has been  modified.
  // When ambiance is modified, this method is called with the new current ambiance
  // NB: this method is called just before a new frame generation 
  // NB2: To keep a pointer on the new current ambiance, it is necessary to duplicate it:
  //   m_Ambiance = iAmbiance->Clone();
  virtual void UpdateAmbiance(const CATVisAmbiance& iAmbiance);

  //--------------------------------
  // Quality
  // This method can be overload to be warmed when raytracing quality has been modified.
  // When quality is modified, this method is called with the new current quality.
  // NB: this method is called just before a new frame generation 

  virtual void UpdateQuality(const VisQualityData::StellarPreciseData& iQuality);

  //--------------------------------
  // Post Effects
  // This method can be overload to be warmed when post effects have been modified.
  // When post effects are modified, this method is called with the new current post effects.
  // NB: this method is called just before a new frame generation 

  virtual void UpdatePostEffects(const CATVisPostEffects& iPostEffects);

  //--------------------------------
  // Hardware properties
  // This method is called when hardware properties are modified (Me preferences)

  virtual void UpdateHarwareProperties(const CATVisRayTracingProperties::Hardware& iProperties);

  //--------------------------------
  // Computing and results
  
  virtual void  StartNewComputing() = 0;
  virtual int   ComputeNextStep(CATVisRTEffectType iEffect,int& oRefreshViewpointID, int& oRefeshID) = 0;
  virtual void  AbortComputing() = 0;
  
  virtual float GetComputingRatio(CATVisRTEffectType iEffect, unsigned int iViewpointID, unsigned int iID=0) = 0; 

  // NB: there is an AddRef on output CATVisuTextureData
  virtual CATVisuTextureData* GetResultTexture(CATVisRTEffectType iEffect, unsigned int iViewpointID, unsigned int iID=0) = 0;

  virtual IVisTexturePtr GetResultTexturePtr(unsigned int iViewpointID);

  virtual bool ErrorOccured() { return false; }
  virtual void SetPausableMode(bool enable) {}
  virtual void AddUser(void* user) {}
  virtual void RemoveUser(void* user) {}
  virtual void SceneModified() {}
  virtual bool SupportPauseMode() { return false; }


  //--------------------------------
  // Batch rendering mode

  // Specific input parameters for a batch rendering job
  struct VisRayTracingBatchSettings
  {
    // Dimentions of the result image
    int width = 960, height = 540;

    // Maximum time to wait for rendering result.
    int renderTimeoutInMS = 0; // 0 means no timeout

    // Which view point to render. Default the first one
    int viewpointID = 0;

    //! Controls if the result texture is RGB or RGBA
    bool generateAlphaChannel = false;
    //! Controls if the result image uses FLOAT32 or UINT8 type for color representation in each channel
    bool generateFloatResult = false;
  };

  // All the results from a batch rendering job
  struct VisRayTracingBatchResult
  {
    // The user will get the result in the format of CATPixelImage, as it is expected
    // to be used for storage in most of the cases and that format is designed for such purposes.
    CATPixelImage ResultImage_Beauty;
  };


  // Generate a raytraced image of the current scene without showing it on the display
  // What is rendered is determined by the current instance of the CATVisRayTracer class:
  //  - to set the scene use DefineGeometry and DefineEnvironmentPlane
  //  - to set the ambiance use UpdateAmbiance
  //  - to define the camera use AddViewpoint. Note that if there are more than one
  // viewpoint you shoud provide the ID of the one to be used in the VisRayTracingBatchSettings
  //  - to select which post processing steps will be applied to the result use UpdatePostEffects
  //  - to set the raytracing quality settings use UpdateQuality
  //  - to select which hardware will be used for the rendering use UpdateHarwareProperties
  //
  // After configure all desired data for the rendering with the functions listed above,
  // make sure you call StartNewComputing and then this function.
  //
  // open questions:
  //   - How can we continue rendering with mulitple calls?
  //   - Should we return the status from the renderer (like progress)?
  virtual HRESULT RenderBatch_Blocking(const VisRayTracingBatchSettings& settings, VisRayTracingBatchResult& renderResult);

  //--------------------------------
  // Properties

  void SetProperties(const CATVisRayTracingProperties& iValue);
  inline const CATVisRayTracingProperties& GetProperties() const;
    
  //--------------------------------
  // Mode
  enum EMode
  {
    eDeferred,
    eDynamic,
    eStatic,
    eNone
  };

  EMode GetMode() const;
  void SetMode(EMode iMode);
  
  //--------------------------------
  // Associated Viewer
  virtual void SetViewer  (CAT3DViewer *iViewer){};
  virtual void SetSupport (const CATSupport* iSupport){};  

protected:
  CATVisRayTracer ();
  virtual ~CATVisRayTracer ();

private:
  CATVisRayTracer (CATVisRayTracer &);
  CATVisRayTracer& operator=(CATVisRayTracer&);
  
  CATVisRayTracingProperties  m_Properties;
  
  EMode                       m_Mode;
  

  
  //------------------------------------------------------------
  // deprecated
public:
  virtual void SetAOProperties(const CATVisRTAOProperties& iAOProperties) {};
  virtual void AddShadow(const CAT3DLightSourceRep& iLight, const CATVisRTShadowProperties& iShadowProperties) {};
  virtual void ResetShadows() {};
  
  //------------------------------------------------------------
  // only for build
public:
  void SetFactoryName(const char* iFactoryName){}
};

inline const CATVisRayTracingProperties& CATVisRayTracer::GetProperties() const
{
  return m_Properties;
};

#endif
