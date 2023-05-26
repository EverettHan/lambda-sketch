// COPYRIGHT Dassault Systemes 2012

#ifndef CATVisRenderingQualityManager_H
#define CATVisRenderingQualityManager_H

#include "SGInfra.h"

#include "CATVisDynamicRenderingQualityData.h"
#include "CATErrorDef.h" // for HRESULT
#include "CATVisInfiniteEnvironment.h"

class CATString;
class CATUnicodeString;
class CATVisRayTracingProperties;
class CATVisHighlightRenderingData;
class CATVisICCProfile;
class CATVizViewer;
class CATVisAmbiance;
class CATVisPostEffects;
class CATVisInfiniteEnvironment;
class CATCommand;
class CATPixelImage;
class IVisTexturePtr;
class CATVisGPUPickingData;
class CATVizViewer;

class ExportedBySGInfra CATVisRenderingQualityManager 
{
public:
  //----------------------------------
  // Dyanmic mode Quality

  static void   SetDefaultDynamicQuality(const CATVisDynamicRenderingQualityData& iDefaultData);
  static const  CATVisDynamicRenderingQualityData& GetDefaultDynamicQuality(int iWithGraphicOptimizerCusto = 0);
  static void   UpdateDefaultDynamicQuality();
  static void   UpdateDynamicWithStaticQuality(CATSupport& iSupport);

  
  //----------------------------------
  // Raytracing Management

  //-----------
  // Clap Mode

  // Activate Raytracing for Clap mode
  static void   ActivateRayTracing     (CATSupport& iSupport, const char* iRayTracingFactoryName);

  // Return if raytyracing is activated for Clap mode
  static bool   IsRayTracingActivated  (const CATSupport& iSupport);

  // Set/Get raytracing properties for Clap Mode
  static void   SetRayTracingProperties(CATSupport& iSupport, const CATVisRayTracingProperties& iQuality);
  static const CATVisRayTracingProperties& GetRayTracingProperties(const CATSupport& iSupport);
    
  

  //-----------
  // View Mode

  // retreive if raytracing view mode is available or not
  static bool IsRayTracingViewModeAvailable ();

  // Show a warning panel when raytracing view mode is run
  static bool ShowRayTracingWarning         (CATCommand* iFather);

  // Activate/Deactivate visibility of warning panel
  static void ActivateRayTracingWarning     (bool iOnOff);

  // do not use
  static void EnableRTVM(CATSupport& iSupport);

  //-----------
  // Fake Raytracing
  static void ActivateFakeRayTracing(CATSupport& iSupport, const IVisTexturePtr& iTexture);
  
  //-----------
  // General

  // retreive if a raytracer is computing or not a picture on current viewer
  static bool   IsRayTracerWorking(const CATSupport& iSupport);
    
  // Generate a CATPixelImage from current raytracing's rendering
  static CATPixelImage* GenerateRayTracingPicture(const CATSupport& iSupport, unsigned int iViewpointID = 0);
  
  // Retreive what factory is used to compute raytracing in Clap mode
  // If rraytracing isn't activated, it returns an empty string ""
  static void GetRayTracingFactoryName(const CATSupport& iSupport, CATString& oFactoryName);

  // Update raytracing properties from settings if it is necessary
  static void UpdateRayTracingProperties(CATSupport& iSupport);

  // Activates batch preview mode
  // in this mode:
  // * elements which aren't managed by raytracer aren't drawn (no rasterizer fallback)
  // * Alpha blending mode is always deactivated (no fallback with rasterizer for ambiance)
  // * some black border are displayed on screen to show what area will be used for batch rendering
  static void   SetRayTracingBatchPreviewMode(const CATSupport& iSupport, unsigned int iWidth, unsigned int iHeight);

  // Deactivate batch preview mode
  static void   UnsetRayTracingBatchPreviewMode(const CATSupport& iSupport);

  //----------------------------------
  // Highlight Customization

  // iMode: 0 Highlight
  //        1 Prehighlight
  static void   SetHighlightRendering  (CATSupport& iSupport, int iMode, const CATVisHighlightRenderingData& iData);
  static const CATVisHighlightRenderingData& getHighlightRendering(const CATSupport& iSupport, int iMode);
  
  // iMode: 0 Basic Highlight (V5)
  //        1 Halo mode
  //        2 Polite mode
  //        3 Advanced Polite
  static void   PushHighlightRenderingMode (CATSupport& iSupport, unsigned int iMode);
  static void   PushHighlightRenderingMode (CATSupport& iSupport, const CATVisHighlightRenderingData& iData);
  static void   PopHighlightRenderingMode  (CATSupport& iSupport);

  static void   UpdateHighlightDataFromMode (unsigned int iMode, CATVisHighlightRenderingData& ioData);

  // iEnable: 0 Transparency is not written in ZMap
  //          1 Transparency is written in ZMap
  static void RequestTransparencyInZMap (CATSupport& iSupport, bool iEnable);

  // iMode: 0 XOR
  //        1 Halo mode
  //        2 Polite mode
  //        3 Advanced Polite

  static void   PushPreHighlightRenderingMode (CATSupport& iSupport, unsigned int iMode);
  static void   PushPreHighlightRenderingMode (CATSupport& iSupport, const CATVisHighlightRenderingData& iData);
  static void   PopPreHighlightRenderingMode  (CATSupport& iSupport);

  static void   UpdatePreHighlightDataFromMode (unsigned int iMode, CATVisHighlightRenderingData& ioData);

    
  //----------------------------------
  // Style Management

  static void   SetStyle               (CATSupport& iSupport, const CATString& iStyle);
  static const CATString& GetStyle     (CATSupport& iSupport);

  
  //----------------------------------
  // ICC Profile
  static void ActivateICCProfile        (CATSupport& iSupport, const CATVisICCProfile& iICCProfile);
  static void DeactivateICCProfile      (CATSupport& iSupport);
  static bool IsICCProfileActivated     (const CATSupport& iSupport);
  static HRESULT GetICCProfile          (const CATSupport& iSupport, CATVisICCProfile& oICCProfile);

  //----------------------------------
  // Capping
  static void SetMulticolorCapping(const CATSupport& iSupport, bool iEnable);
  static bool GetMulticolorCapping(const CATSupport& iSupport);
  
  //----------------------------------
  // Inf Env Filtering

  static void FilterGround (CATSupport& iSupport, int iOnOff);
  static void FilterGrid   (CATSupport& iSupport, int iOnOff);

  static bool IsGroundLocked(CATSupport& iSupport);

  //----------------------------------
  // Ambiance

  static void     SetAmbiance     (CATSupport& iSupport, CATVisAmbiance* iAmbiance, CATVisPostEffects* iPostEffects = nullptr);

  // This method with a CATVizViewer as input sends and event to indicate ambiance has been modified
  static void     SetAmbiance     (CATVizViewer* iViewer, CATVisAmbiance* iAmbiance, CATVisPostEffects* iPostEffects = nullptr);

  // oAmbiance:           ambiance to fill with current root ambiance of iSupport
  // iFallbackActivation: This flag is used when a CATVisIfniteEnvironment has been set on iSupport,
  //                      A translator can be used to translate the current CATVisIfniteEnvironment into a CATVisAmbiance
  struct FallbackAmbiance
  {
    enum EType
    {
      eNone,                // No fallbacks -> no CATVisAmbiance is generated
      eBasic,               // A CATVisAmbiances is generated from CATVisIfiniteEnvironment
      eAdvanced             // idem but if BC6H textures are used, we try to use them
    };
  };
  static HRESULT  GetAmbiance       (CATSupport& iSupport, CATVisAmbiance& oAmbiance, FallbackAmbiance::EType iFallback = FallbackAmbiance::eBasic);

  // same as previous method but return the ambiance with all overload
  static HRESULT  GetResultAmbiance (CATSupport& iSupport, CATVisAmbiance& oAmbiance, FallbackAmbiance::EType iFallback = FallbackAmbiance::eBasic);

  static HRESULT  GetPostEffects    (CATSupport& iSupport, CATVisPostEffects& oPostEffects);
  
  //----------------------------------
  // Infinite environment

  struct VisInfEnvClone
  {
    enum Mode
    {
      eRoot,
      eResult
    };
  };
  static CATVisInfiniteEnvironment* CloneInfiniteEnvironment(const CATSupport& iSupport, VisInfEnvClone::Mode iMode);

  static bool IsPLMAmbiance(const CATSupport& iSupport);

  //----------------------------------
  // Gamma Correction

  static bool IsGammaCorrectionAvailable(const CATSupport& iSupport);

  //----------------------------------
  // GPU Picking
  static void PushActivateGPUPicking(CATSupport& iSupport, unsigned int iOnOff, const CATVisGPUPickingData& iData);
  static void PopActivateGPUPicking(CATSupport& iSupport);
  static void ActivateGPUPicking(CATSupport& iSupport, unsigned int iOnOff, const CATVisGPUPickingData& iData);
  static int IsGPUPickingActivated(const CATSupport& iSupport);
  static bool IsGPUPickingOverridden(const CATSupport& iSupport);
  static const CATVisGPUPickingData& GetGPUPickingData(const CATSupport& iSupport);

  static void ForceActivateOptimizedRendering(CATSupport& iSupport, bool iOnOff);
  static bool IsOptimizedRenderingForced(CATSupport& iSupport);

  /* Alterate rep visualization:
  * If alternate rep visualization is activated, all surfacic reps with a specified alternate rep (using CATModifyAlternateRepForVisu notif or CATVisAlternateRepManager)
  * will use this alternate rep for visualization instead of itself.
  */
  static void ActivateAlternateRepVisu(CATSupport& iSupport, bool iOnOff);
  static bool IsAlternateRepVisuActivated(CATSupport& iSupport);

private:
  CATVisRenderingQualityManager();
  ~CATVisRenderingQualityManager();
  
  static CATVisDynamicRenderingQualityData m_DefaultDynamicQuality;
  static CATVisDynamicRenderingQualityData m_DefaultDynamicQualityWithCusto;

public:
  // OBSOLETE
  // "Save as Picture" command only allows to save a picture with current viewer resolution
  // "Batch preview mode" allows to have a preview of batch result
  static void   SetRayTracingFixedResolutionMode(const CATSupport& iSupport, unsigned int iWidth, unsigned int iHeight) {};
  static void   UnsetRayTracingFixedResolutionMode(const CATSupport& iSupport) {};

};

//-----------------------------------------------------------------------

#include "IUnknown.h"

class CATSupport;
extern  ExportedBySGInfra HRESULT sCATVisForceDynamicMode    (CATSupport& iSupport, int iOnOff);
extern  ExportedBySGInfra int     sCATVisGetDynamicMode      (CATSupport& iSupport);

#endif
