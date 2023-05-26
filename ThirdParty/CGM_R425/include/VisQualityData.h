//===================================================================
// COPYRIGHT Dassault Systemes 2015-10-27
//===================================================================
// VisQualityData.cpp
// Header definition of class VisQualityData
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015-10-27 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef VisQualityData_H
#define VisQualityData_H

#include "SGInfra.h"
#include "CATVisDynamicRenderingQualityData.h"
#include "VisAntialiasingInfo.h"
#include "VisCustomizeShadows.h"
#include "VisCustomizeReflections.h"
#include "VisCustomizeAO.h"
#include "VisCustomizeRTAO.h"
#include "VisCustomizeDLSS.h"
#include "CATUnicodeString.h"
#include "VisQuality.h"

//-----------------------------------------------------------------------
// For internal use only. API might change without intimation. DO NOT USE.
//-----------------------------------------------------------------------

class ExportedBySGInfra VisQualityData
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	VisQualityData();
	virtual ~VisQualityData();

	VisQualityData(const VisQualityData &iIn) = default;
	VisQualityData& operator=(const VisQualityData& iIn) = default;

	int SetValue(const CATUnicodeString &iParam, const CATUnicodeString &iValue);
	int GetValue(const CATUnicodeString &iParam, CATUnicodeString &oValue) const;

	static int GetDisabledValue(const CATUnicodeString &iParam, CATUnicodeString &oValue);

	bool operator==(const VisQualityData&) const;
	bool operator!=(const VisQualityData&) const;

public:
	struct AntiAliasingData
	{
		VisQuality::PresetID lvl;
		VisAntialiasingInfo info;
	} aa = {};

  struct OutlineData
  {
    VisQuality::PresetID lvl;
    CATBoolean allow;
  } outline = {};

  struct PxlCullingAndLODData
  {
    VisQuality::PresetID lvl;
    int minPxlSz; // Range="0-400"
    float lod;    // Range="0.0-40.0"
    bool occlusion;
	VisQuality::OcclusionManagement occlusionStrategy;
    bool forceCompiledPath;
  } pxlCullAndLOD = {};

  struct TransparencyData
  {
    VisQuality::PresetID lvl;
    VisQuality::TransparencyMode mode; // Range="ScreenDoor,AlphaBlendingNoSort,AlphaBlendingWithSort,WeightedAverage,OrderIndependant,OrderIndependantWithColor"
  } transp = {};

  struct ShadowsData
  {
    VisQuality::PresetID lvl;
    CATBoolean allowGround;
    CATBoolean allowInterObj;
    unsigned int maxMapSize; //Range="64,128,256,512,1024,2024,4096,8192"
    CATBoolean useBoundingBox;
    CATBoolean allowTransparentShadow;
    CATBoolean allowAreaLightShadows;
    VisCustomizeShadows::Filtering::Mode filteringMode;
    VisCustomizeShadows::Quality::Mode filteringQuality;
  } shadows = {};

  struct ReflectionsData
  {
    VisQuality::PresetID lvl;
    VisQuality::ReflectionMode groundMode;
    VisQuality::ReflectionMode interObjMode;
    VisCustomizeReflections::Quality::Mode ssrQuality;
  } reflections = {};

  struct SSAOData
  {
    VisQuality::PresetID lvl;
    CATBoolean allow;
    VisCustomizeAO::AO::Mode mode;
    unsigned int maxSampling;  // Range="8,16,32,64"
    VisCustomizeAO::Blur::Mode blurMode;
    unsigned int maxBlurLevel; // Range="0-10"
  } ssao = {};

  struct DLSSdata
  {
    VisQuality::PresetID lvl;
    VisCustomizeDLSS::DLSSPerfoMode mode;

    float extraSharpening;

    CATBoolean allow;
  } dlssData = {};

  struct RTAOData
  {
    VisCustomizeRTAO::ECacheSize cacheSize = VisCustomizeRTAO::ECacheSize::eHigh;
    VisCustomizeRTAO::EQuality minQuality = VisCustomizeRTAO::EQuality::eLow;
    VisCustomizeRTAO::EQuality maxQuality = VisCustomizeRTAO::EQuality::eHigh;
    CATBoolean enableSpecularShadows = CATFalse;
  } rtao;

  struct DepthOfFieldData
  {
    VisQuality::PresetID lvl;
    CATBoolean allow;
  } dof = {};

  struct BloomData
  {
    VisQuality::PresetID lvl;
    CATBoolean allow;
    int maxBloomQuality; // Range="1-10"
    unsigned int maxTexLevel;
    unsigned int maxBlurNumPass;
    float        maxBlurSize;
    float        maxBlurNumSamples;
  } bloom = {};

  struct CappingData
  {
    VisQuality::PresetID lvl;
    CATBoolean multiColor;
  } cap = {};

  struct DownsamplingData
  {
    VisQuality::PresetID lvl;
    float factor; // range=0.0-1.0
    VisQuality::ShadingRate shadingMode;
  } downsample = {};

  struct MaterialData
  {
    VisQuality::PresetID lvl;
    VisQuality::MetallicFlakesQuality metallicFlakesQuality;
    CATBoolean closeupFlakesMode;
    CATBoolean xriteNativeShader;
  } material = {};

  struct DepthData
  {
    VisQuality::PresetID lvl;
    VisQuality::DepthMode depthMode;
    VisQuality::DepthOffset depthOffset;
    bool depthFlickeringReduction;
  } depth = {};

  // --- Stellar Precise specific ---
  struct StellarPreciseData
  {
    ExportedBySGInfra StellarPreciseData();

    VisQuality::PresetID lvl;
    struct AccumulationData
    {
      VisQuality::PresetID lvl;
      int maxSamplesPerPixel; // must be a power of 2
	  int targetQuality;
      int minSamplesPerFrame; // must be a power of 2
      CATBoolean enableSampleLuminance;
      float clampValue;

      struct GaussFilterData
      {
        CATBoolean enabled;
        float size;
        float centerWeight;
      } gaussFilter;

      struct DenoisingData
      {
          CATBoolean enabled;
          int applyDenoisingAfterIteration;

          const bool operator!=(const DenoisingData &d) const {
              return enabled != d.enabled
                  || applyDenoisingAfterIteration != d.applyDenoisingAfterIteration;
          }
      } denoiser;

      const bool operator!=(const AccumulationData &a) const {
        return lvl                      != a.lvl
            || maxSamplesPerPixel       != a.maxSamplesPerPixel
            || targetQuality            != a.targetQuality
            || enableSampleLuminance    != a.enableSampleLuminance
            || minSamplesPerFrame       != a.minSamplesPerFrame
            || clampValue               != a.clampValue
            || gaussFilter.enabled      != a.gaussFilter.enabled
            || gaussFilter.size         != a.gaussFilter.size
            || gaussFilter.centerWeight              != a.gaussFilter.centerWeight
            || denoiser.enabled                      != a.denoiser.enabled
            || denoiser.applyDenoisingAfterIteration != a.denoiser.applyDenoisingAfterIteration;
      }

    } accumulation;

    struct GlobalIlluminationData
    {
      VisQuality::PresetID lvl;
      int maxTraceDepth;
      float glossyThreshold;
      CATBoolean renderRefractiveShadow;
	  CATBoolean lightTracing;
      CATBoolean wavefrontCausticPhotons;
      float wavefrontCausticPhotonsRadius;
	  CATBoolean fastSubsurfaceScattering;
      CATBoolean locationBasedImportanceSampling;
      VisQuality::DistributionMethod importanceDistributionMethod;
      float importanceSamplingFactor;
      int pathTerminationStartDepth;
      VisQuality::PhotonVisualizationMode photonVisualizationMode;

      struct FinalGatheringData
      {
        VisQuality::PresetID lvl;
        CATBoolean enabled;
        int numberOfPhotons;
        int pathDepth;
        float photonRadius;
        CATBoolean refineFinalGatherMap;
        CATBoolean precalculateIrradiance;
      } finalGathering = {};

      struct CausticData
      {
        VisQuality::PresetID lvl;
        VisQuality::CausticsMode mode;
        int numberOfPhotons;
        int pathDepth;
        float causticsRadius;
        CATBoolean refineCausticsPhotonMap;
      } caustics;
    } globalIllumination = {};

    struct SceneData
    {
      float rayOffset;
    } scene = {};

  } stellarPrecise = {};

private:

  int GetGroupValue(const CATUnicodeString &iParam, VisQuality::PresetID &oID) const;
  int SetGroupValue(const CATUnicodeString &iParam, VisQuality::PresetID iValue);

};

//-----------------------------------------------------------------------

#endif