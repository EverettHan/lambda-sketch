#ifndef _VisSGUnionOfBitfields_H_
#define _VisSGUnionOfBitfields_H_

#include "CATDataType.h"
#include "VisOccurrencesGraph.h"

// This is the number of the bit set to '1' in the feature flag.
using FeatureIdentifier = CATULONG32;
// FDT1: it must be FeatureIdentifier = VisSGFeatureType;

// A number with one bit set to '1' which represents a unique feature
using FeatureFlag = CATULONG32;
// A number with one bit set to '1' which represents a unique post-process
using PostProcessFlag = CATULONG32;

// A mask containing the flags of one or several features.
using FeaturesMask = CATULONG32;
// A mask containing the flags of one or several post-processes.
using PostProcessesMask = CATULONG32;




/**
 * @enum VisSGFeatureType to set into the m_Id of VisSGFeatureBitfield
 * It represents the unique Id for each feature.
**/
enum class ExportedByVisOccurrencesGraph VisSGFeatureType {
  Matrix = 0,
  Material = 1,
  Attributes = 2,
  MultiFather = 3,
  AnnotationFilter = 4,
  Geometry = 5,
  AnnotationValue = 6,
  RenderProp = 7,
  TextureMatrix = 8,
  Filter = 9,
  LayerPriority = 10,
  Count
};

constexpr unsigned int VisSGFeatureIdSize = 5;

// check the size consistency
static_assert(static_cast<int>(VisSGFeatureType::Count) <= (1 << VisSGFeatureIdSize), "VisSGFeatureType values cannot exceed VisSGFeatureBitfield::m_Id size");


/**
* @struct VisSGFeatureBitfield common bitfield for all features.
* The Bitfield structures allow to share the same place but with different definitions.
* It is clearer than shifting and masking a single integer.
*/
struct ExportedByVisOccurrencesGraph VisSGFeatureBitfield {
  //Flag storing the feature ID, can be used by derived class to add additional flags.
  CATULONG64 m_Id : VisSGFeatureIdSize;      // 5 bit. always at the first place
  CATULONG64 m_Dirty : 1;   // 6 bit . unused for the moment. it seems that most of the features need it! It has to be added to all bitfields at the same place.
  CATULONG64 m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor : 58;  // 64 bit . to ease the initialization

  VisSGFeatureBitfield(VisSGFeatureType iType) : m_Id((CATULONG64)iType), m_Dirty(0), m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor(0) {}
};


/**
* @struct VisSGTextureMatrixBitfield bitfield for @class VisSGTextureMatrixFeature
*/
struct ExportedByVisOccurrencesGraph VisSGTextureMatrixBitfield {
  //Flag storing the feature ID, can be used by derived class to add additional flags.
  CATULONG64 m_Id : VisSGFeatureIdSize;      //  5 bit. always at the first place
  CATULONG64 m_LocalTextureMtxDefinition : 1; // 6 bit
  CATULONG64 m_parentHasTextureMtx : 1; // 7 bit
  CATULONG64 m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor : 57;  // 64 bit . to ease the initialization

  VisSGTextureMatrixBitfield() :m_Id((CATULONG64)VisSGFeatureType::TextureMatrix), m_LocalTextureMtxDefinition(0), m_parentHasTextureMtx(0), m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor(0){}
};

/**
* @struct VisSGAnnotationValueBitfield bitfield for @class VisSGAnnotationValueFeature
*/
struct ExportedByVisOccurrencesGraph VisSGAnnotationValueBitfield {
  //Flag storing the feature ID, can be used by derived class to add additional flags.
  CATULONG64 m_Id : VisSGFeatureIdSize;      //  5 bit. always at the first place
  CATULONG64 m_AnnoteValue : 1; // 6 bit
  CATULONG64 m_Dirty : 1; // 7 bit
  CATULONG64 m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor : 57;  // 64 bit . to ease the initialization

  VisSGAnnotationValueBitfield() :m_Id((CATULONG64)VisSGFeatureType::AnnotationValue), m_AnnoteValue(0), m_Dirty(0), m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor(0){}
};

/**
* @struct VisSGMultiFatherBitfield bitfield for @class VisSGMultiFatherFeature
*/
struct ExportedByVisOccurrencesGraph VisSGMultiFatherBitfield {
  //Flag storing the feature ID, can be used by derived class to add additional flags.
  CATULONG64 m_Id : VisSGFeatureIdSize;      //  5 bit. always at the first place
  CATULONG64 m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor : 59;  // 64 bit . to ease the initialization

  VisSGMultiFatherBitfield() :m_Id((CATULONG64)VisSGFeatureType::MultiFather), m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor(0) {}
};

/**
* @struct VisSGRenderPropBitfield bitfield for @class class ExportedByVisOccurrencesGraph VisSGRenderPropFeature: public VisSGOccurrenceFeature
*/
struct ExportedByVisOccurrencesGraph VisSGRenderPropBitfield {
  //Flag storing the feature ID, can be used by derived class to add additional flags.
  CATULONG64 m_Id : VisSGFeatureIdSize;      //  5 bit. always at the first place
  CATULONG64 m_CastShadows : 1; // 6 bit
  CATULONG64 m_ReceiveShadows : 1; // 7 bit
  CATULONG64 m_CastReflections : 1; // 8 bit
  CATULONG64 m_ReceiveReflections : 1; // 9 bit
  CATULONG64 m_LightMapIlluminanceMode : 1; // 10 bit
  CATULONG64 m_ZMapRequired : 1; // 11 bit
  CATULONG64 m_NotRaytraceable : 1; // 12 bit
  CATULONG64 m_NotRaytraceableInherit : 1; // 13 bit
  CATULONG64 m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor : 51; // 64 bit . to ease the initialization

  VisSGRenderPropBitfield() :
    m_Id((CATULONG64)VisSGFeatureType::RenderProp),
    m_CastReflections(1),
    m_CastShadows(1),
    m_ReceiveReflections(1),
    m_ReceiveShadows(1),
    m_LightMapIlluminanceMode(0),
    m_ZMapRequired(0),
    m_NotRaytraceable(0),
    m_NotRaytraceableInherit(0),
    m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor(0)
  {}

  bool isDefault() const
  {
    return m_CastReflections == 1
      && m_CastShadows == 1
      && m_ReceiveShadows == 1
      && m_ReceiveReflections == 1
      && m_NotRaytraceable == 0
      && m_NotRaytraceableInherit == 0
      && m_LightMapIlluminanceMode == 0
      && m_ZMapRequired == 0;
  }

  VisSGRenderPropBitfield& operator= (const VisSGRenderPropBitfield& iFlags) {
    m_Id = iFlags.m_Id;
    m_CastReflections = iFlags.m_CastReflections;
    m_CastShadows = iFlags.m_CastShadows;
    m_ReceiveReflections = iFlags.m_ReceiveReflections;
    m_ReceiveShadows = iFlags.m_ReceiveShadows;
    m_LightMapIlluminanceMode = iFlags.m_LightMapIlluminanceMode;
    m_ZMapRequired = iFlags.m_ZMapRequired;
    m_NotRaytraceable = iFlags.m_NotRaytraceable;
    m_NotRaytraceableInherit = iFlags.m_NotRaytraceableInherit;
    return *this;
  }
};

/**
* @struct VisSGAnnotationFilterBitfield bitfield for @class VisSGAnnotationFilterFeature
*/
struct ExportedByVisOccurrencesGraph VisSGAnnotationFilterBitfield {
  //Flag storing the feature ID, can be used by derived class to add additional flags.
  CATULONG64 m_Id : VisSGFeatureIdSize;      //  5 bit. always at the first place
  CATULONG64 m_AnnoteFilter : 1; // 6 bit
  CATULONG64 m_ReScanNeededInPostProcess : 1; // 7 bit
  CATULONG64 m_Dirty : 1; // 8 bit
  CATULONG64 m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor : 56; // 64 bit . to ease the initialization

  VisSGAnnotationFilterBitfield() :m_Id((CATULONG64)VisSGFeatureType::AnnotationFilter), m_AnnoteFilter(0), m_ReScanNeededInPostProcess(0), m_Dirty(0), m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor(0){}
};

/**
* @struct VisSGMatrixBitfield bitfield for @class VisSGDefaultMatrixFeature and inheritance
*/
struct ExportedByVisOccurrencesGraph VisSGMatrixBitfield {
  //Flag storing the feature ID, can be used by derived class to add additional flags.
  CATULONG64 m_Id : VisSGFeatureIdSize;      //  5 bit. always at the first place

  CATULONG64 m_Unscalable : 1; // 6 bit
  CATULONG64 m_RepWorldScalable : 1; // 7 bit.

  CATULONG64 m_Dirty : 1; // 7 bit

  CATULONG64 m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor : 56; // 64 bit . to ease the initialization

  VisSGMatrixBitfield() :m_Id((CATULONG64)VisSGFeatureType::Matrix), m_Unscalable(0), m_Dirty(0), m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor(0) {}
};

/**
* @struct VisSGGeometryBitfield bitfield for @class VisSGGeometryFeature
*/
struct ExportedByVisOccurrencesGraph VisSGGeometryBitfield {
  //Flag storing the feature ID, can be used by derived class to add additional flags.
  CATULONG64 m_Id : VisSGFeatureIdSize;      //  5 bit. always at the first place
  CATULONG64 m_TCUpToDate : 1; // 6 bit
  CATULONG64 m_WithMat : 1; // 7 bits 
  CATULONG64 m_NumMaterials : 24; // 31 bits
  CATULONG64 m_GeomFeature : 1; // 32 bits
  CATULONG64 m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor : 32;  // 64 bit . to ease the initialization

  VisSGGeometryBitfield() :m_Id((CATULONG64)VisSGFeatureType::Geometry), m_TCUpToDate(0), m_WithMat(0), m_NumMaterials(0), m_GeomFeature(0), m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor(0) {}
};


/**
* @struct VisSGMaterialBitfield bitfield for @class VisSGMaterialFeature
*/
struct ExportedByVisOccurrencesGraph VisSGMaterialBitfield {
  //Flag storing the feature ID, can be used by derived class to add additional flags.
  CATULONG64 m_Id : VisSGFeatureIdSize;      //  5 bit. always at the first place
  CATULONG64 m_MatInherit : 1; // 6 bit
  CATULONG64 m_MatForceInherit : 1; // 7 bit
  CATULONG64 m_Raytraceability : 1; // 8 bit
  CATULONG64 m_Dirty : 1; // 9 bit
  CATULONG64 m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor : 55;  // 64 bit . to ease the initialization

  VisSGMaterialBitfield() :m_Id((CATULONG64)VisSGFeatureType::Material), m_MatInherit(0), m_MatForceInherit(0), m_Raytraceability(0), m_Dirty(0), m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor(0){}
};

/**
* @struct VisSGLayerPriorityBitfield bitfield for @class VisSGLayerPriorityFeature
*/
struct ExportedByVisOccurrencesGraph VisSGLayerPriorityBitfield {
  //Flag storing the feature ID, can be used by derived class to add additional flags.
  CATULONG64 m_Id : VisSGFeatureIdSize;      //  5 bit. always at the first place
  CATULONG64 m_IsIsoPriority : 1; // 6 bit
  CATULONG64 m_IsDrawPriority : 1; // 7 bit
  CATULONG64 m_IsoPriority : 2; // 9 bit
  CATULONG64 m_DrawPriority : 16; // 25 bit
  CATULONG64 m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor : 39;  // 64 bit . to ease the initialization

  VisSGLayerPriorityBitfield() : m_Id((CATULONG64)VisSGFeatureType::LayerPriority), m_IsIsoPriority(false), m_IsDrawPriority(false), m_IsoPriority(0), m_DrawPriority(0), m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor(0){}
};

/**
* @struct VisSGAttributesBitfield bitfield for @class VisSGAttributesFeature
*/
struct ExportedByVisOccurrencesGraph VisSGAttributesBitfield {
#if 0 //  2021/05/07: FDT1: TODO: i'm not sure of the alignment . Please check.
  //Flag storing the feature ID, can be used by derived class to add additional flags.
  CATULONG64 m_Id : VisSGFeatureIdSize;      //  5 bit. always at the first place

  CATULONG64 m_Highlight : 1; // 6 bit
  CATULONG64 m_LineWidth : 1; // 7 bit
  CATULONG64 m_LineType : 1;  // 8 bit
  CATULONG64 m_Background3DViewMode : 1; // 9 bit
  CATULONG64 m_AsmColor : 1; // 10 bit
  CATULONG64 m_GASLook : 1;  // 11 bit
  CATULONG64 m_TopPriority : 1; // 12 bit
  CATULONG64 m_2DMode : 1; // 13 bit
  // match IsFiltered flag on CATRep.
  CATULONG64 m_Filtered : 1; // 14 bit
  //-- Generic filter values, shifted for each attributes
  //Alpha et color sont géré a part des autres modes car ils sont aussi dans les filtres.  CATULONG64 k_AlphaMask : 5; // 19 bit
  CATULONG64 m_Alpha : 5; // 19 bit
  CATULONG64 m_Color : 5; // 24 bit
  CATULONG64 m_Dummy : 8; // 32 bit. unused ?

  //Rep view mode hold by filters.
  CATULONG64 m_RepViewFilterMesh : 1; // 33 bit
  CATULONG64 m_RepViewFilterEdge : 1; // 34 bit
  CATULONG64 m_RepViewFilterNoWire : 1; // 35 bit
  CATULONG64 m_RepViewFilterNoAxis : 1; // 36 bit
  CATULONG64 m_RepViewFilterNoPoints : 1; // 37 bit
  CATULONG64 m_RepViewFilterNoOutline : 1; // 38 bit
  CATULONG64 m_RepViewFilterInh : 6; // 44 bit

  //Nunused for the moment (annotations).
  CATULONG64 m_Invisibility : 1; // 45 bit
  CATULONG64 m_InvertVisibility : 1; // 46 bit
  CATULONG64 m_InvertVisibilityInh : 1; // 47 bit

  CATULONG64 m_HasAttrFilter : 1; // 48 bit
  CATULONG64 m_GASLookValueMask : 2; // 50 bit

  CATULONG64 m_HasZmodeFilter : 1; // 51 bit
  CATULONG64 m_ZmodeFilterValue : 1; // 52 bit

  CATULONG64 m_HasGASFilter : 1; // 53 bit
  CATULONG64 m_IsDirty : 1; // 54 bit
  CATULONG64 m_EmptyBitsForInitToZeroAwaintingForAFullBitFieldConstructor : 10;  // 64 bit . to ease the initialization

  VisSGAttributesBitfield() :m_Id((CATULONG64)VisSGFeatureType::Attributes), m_Dirty(0) {}
#else
  CATULONG64 m_Flags;
  VisSGAttributesBitfield() :m_Flags((CATULONG64)VisSGFeatureType::Attributes) {}
#endif
};


/**
* @union VisSGUnionOfBitfields which allows to share the same 64 bits for different bitfields.
*/
union ExportedByVisOccurrencesGraph VisSGUnionOfBitfields {
  VisSGFeatureBitfield Common;
  VisSGAttributesBitfield Attributes;
  VisSGMaterialBitfield Material;
  VisSGMultiFatherBitfield MultiFather;
  VisSGGeometryBitfield Geometry;
  VisSGMatrixBitfield Matrix;
  VisSGAnnotationValueBitfield AnnotationValue;
  VisSGAnnotationFilterBitfield AnnotationFilter;
  VisSGRenderPropBitfield RenderProp;
  VisSGTextureMatrixBitfield TextureMatrix;
  VisSGLayerPriorityBitfield LayerPriority;

  VisSGUnionOfBitfields(VisSGFeatureType iFeatId)
  {
    switch (iFeatId)
    {
    case VisSGFeatureType::Attributes:
      Attributes = VisSGAttributesBitfield();
      break;
    case VisSGFeatureType::Material:
      Material = VisSGMaterialBitfield();
      break;
    case VisSGFeatureType::MultiFather:
      MultiFather = VisSGMultiFatherBitfield();
      break;
    case VisSGFeatureType::Geometry:
      Geometry = VisSGGeometryBitfield();
      break;
    case VisSGFeatureType::Matrix:
      Matrix = VisSGMatrixBitfield();
      break;
    case VisSGFeatureType::AnnotationValue:
      AnnotationValue = VisSGAnnotationValueBitfield();
      break;
    case VisSGFeatureType::AnnotationFilter:
      AnnotationFilter = VisSGAnnotationFilterBitfield();
      break;
    case VisSGFeatureType::RenderProp:
      RenderProp = VisSGRenderPropBitfield();
      break;
    case VisSGFeatureType::TextureMatrix:
      TextureMatrix = VisSGTextureMatrixBitfield();
      break;
    case VisSGFeatureType::LayerPriority:
      LayerPriority = VisSGLayerPriorityBitfield();
      break;
    default:
      Common = VisSGFeatureBitfield(iFeatId);
      break;
    }
  }
};


static_assert(sizeof(VisSGUnionOfBitfields) == sizeof(CATULONG64), "bit fields cannot exceed 64 bits in union");


/**
 * @enum VisSGPostProcessType is the type of the post process
 * It represents the unique Id for each post process.
**/
enum class ExportedByVisOccurrencesGraph VisSGPostProcessType {
  Compile = 0,
  BBox = 1,
  Matrix = 2,
  Attribute = 3,
  Material = 4,
  AnnotationFilter = 5,
  AnnotationValue = 6,
  Count
};

constexpr unsigned int VisSGPostProcessIdSize = 4;

// check the size consistency
static_assert(static_cast<int>(VisSGPostProcessType::Count) <= (1 << VisSGPostProcessIdSize), "VisSGPostProcessType values cannot exceed VisSGPostProcess::k_PPFlagShift size (1<<4)");

#endif
