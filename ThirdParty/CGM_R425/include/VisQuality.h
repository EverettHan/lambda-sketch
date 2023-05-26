//===================================================================
// COPYRIGHT Dassault Systemes 2015-10-28
//===================================================================
// VisQualityParamList.cpp
// Header definition of class VisQualityParamList
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015-10-28 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef VisQuality_H
#define VisQuality_H

#include "SGInfra.h"
#include "CATUnicodeString.h"

class ExportedBySGInfra VisQuality
{
public:

  //-----------------------------------------------------------------------

  enum ParamType
  {
    eInvalid=0,
    eBool,
    eInt,
    eFloat,
    eEnum,
    eGroup,
    ePowerInt,
    eLabel,
    eTwoDecimalFloat,
    eThreeDecimalFloat
  };

  static CATUnicodeString Convert(VisQuality::ParamType iType);
  static void Convert(CATUnicodeString iEnumStr, VisQuality::ParamType &oType);

  //-----------------------------------------------------------------------

  enum PresetID
  {
    Invalid=0,
    Low,
    Medium,
    High,
    Ultra,
    Default,
    Custom,
    Immersive,
    User_1,
    User_2,
    User_3,
    User_4,
    User_5,
    User_6,
    User_7,
    User_8,
    User_9,
    User_10,
    Modified,
    Min,
    Max,
    Last,
    Init,
    Appli,
    Disabled,
    GIStandard,
    GIOptInt,
    GIOptCaust,
    VQM_User_1,
    VQM_User_2,
    VQM_User_3,
    VQM_User_4,
    VQM_User_5,
    VQM_User_6,
    VQM_User_7,
    VQM_User_8,
    VQM_User_9,
    VQM_User_10,
    MAX_ID
  };

  static CATUnicodeString Convert(VisQuality::PresetID iID);
  static void Convert(CATUnicodeString iEnumStr, VisQuality::PresetID &oID);

  //-----------------------------------------------------------------------

  enum RenderMode
  {
    NoMode=0,
    Static,
    Dynamic,
    VirtualReality,
    GIStatic,
    GIDynamic,
    GIBatch,
    GIVirtualReality  //Use only in case of VR. Will return quality for GI Static
  };

  static CATUnicodeString Convert(VisQuality::RenderMode iMode);
  static void Convert(CATUnicodeString iEnumStr, VisQuality::RenderMode &oMode);

  //-----------------------------------------------------------------------

  enum TransparencyMode
  {
    ScreenDoor=0,
    AlphaBlendingWithSort,
    WeightedAverage,
    MODE_NOT_USED,
    OrderIndependant,
    AlphaBlendingNoSort,
    OrderIndependantWithColor
  };

  static CATUnicodeString Convert(VisQuality::TransparencyMode iMode);
  static void Convert(CATUnicodeString iEnumStr, VisQuality::TransparencyMode &oMode);

  //-----------------------------------------------------------------------

  enum OcclusionManagement
  {
	  Precise = 0,
	  Optimal,
	  Fast
  };

  static CATUnicodeString Convert(VisQuality::OcclusionManagement iMode);
  static void Convert(CATUnicodeString iEnumStr, VisQuality::OcclusionManagement &oMode);

  //-----------------------------------------------------------------------

  enum ReflectionMode
  {
    NoReflection=0,
    Mirror,
    ScreenSpaceReflections
  };

  static CATUnicodeString Convert(VisQuality::ReflectionMode iMode);
  static void Convert(CATUnicodeString iEnumStr, VisQuality::ReflectionMode &oMode);

  enum ShadingRate
  {
      Rate1x1,
      Rate2x2,
      Rate4x4
  };

  static CATUnicodeString Convert(VisQuality::ShadingRate iMode);
  static void Convert(CATUnicodeString iEnumStr, VisQuality::ShadingRate& oMode);

  //-----------------------------------------------------------------------

  enum MetallicFlakesQuality
  {
    MetallicFlakesQualityLow=0,
    MetallicFlakesQualityMedium,
    MetallicFlakesQualityHigh,
    MetallicFlakesQualityUltra
  };

  static CATUnicodeString Convert(VisQuality::MetallicFlakesQuality iMode);
  static void Convert(CATUnicodeString iEnumStr, VisQuality::MetallicFlakesQuality &oMode);

  enum DepthMode
  {
    DepthModeDefault = 0,
    DepthModeLog,
  };

  static CATUnicodeString Convert(VisQuality::DepthMode iMode);
  static void Convert(CATUnicodeString iEnumStr, VisQuality::DepthMode &oMode);

  enum DepthOffset
  {
    DepthOffsetFace = 0,
    DepthOffsetEdge
  };

  static CATUnicodeString Convert(VisQuality::DepthOffset iMode);
  static void Convert(CATUnicodeString iEnumStr, VisQuality::DepthOffset &oMode);

  enum DistributionMethod
  {
      Equal = 0,
      ProportionalToPower
  };

  static CATUnicodeString Convert(VisQuality::DistributionMethod iMode);
  static void Convert(CATUnicodeString iEnumStr, VisQuality::DistributionMethod &oMode);

  enum CausticsMode
  {
      CausticsModeNone = 0,
      Pathtracer,
      CausticPhotons
  };

  static CATUnicodeString Convert(VisQuality::CausticsMode iMode);
  static void Convert(CATUnicodeString iEnumStr, VisQuality::CausticsMode &oMode);

  enum PhotonVisualizationMode
  {
    VisualizeNone = 0,
    VisualizeFinalGathering,
    VisualizeCaustics
  };

  static CATUnicodeString Convert(VisQuality::PhotonVisualizationMode iMode);
  static void Convert(CATUnicodeString iEnumStr, VisQuality::PhotonVisualizationMode &oMode);

  enum UseCaseGI
  {
    Standard,
    OptInterior,
    OptCaustics,
  };

  static CATUnicodeString Convert(VisQuality::UseCaseGI iUseCase);
  static void Convert(CATUnicodeString iEnumStr, VisQuality::UseCaseGI &oUseCase);

};

#define VisQualityDefault VisQuality::Default  // to correct compile error in vuEngine.cpp

#endif