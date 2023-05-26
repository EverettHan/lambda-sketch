/* -*-c++-*- */
#ifndef CATPLMQEConstants_H
#define CATPLMQEConstants_H

#include "CATUnicodeString.h"
#include "CATOmxDefaultCollecManager.h"

namespace CATPLMQEConstants
{
  // enum non scopé ! Le user peut spécifier n'importe quelle profondeur d'expand (1, 2, 3 ...)
  enum CATPLMLoadingLevel { Level_None = -3, Level_Inherited = -2, Level_All = -1, Level_Self = 0, Level_One = 1, Level_Two = 2, LevelDefault = -999 };

  enum class CATPLMLoadingState { Undefined, Light, Navigation, Full };

  enum class CATPLMQEOption
  {
    /*
    * default option (no option).
    */
    QE_None = 0,   // do not modify this option
    /*
    * for ODTs.
    */
    QE_NotInTable, // invalid option
    QE_DebugOption,
    QE_OtherDebugOption,
    /*
    * OC_Session options.
    */
    QE_LoadDocuments,
    QE_RemoveFasteners,
    QE_LoadLayouts,
    QE_LoadMaterials,
    QE_LoadReps,
    QE_AuthoringReviews,
    QE_DMUMonoContext,
    /*
    * OC_Completion options.
    */
    QE_TestCase,
    QE_TestExec,
    QE_IntegrityReps,
    QE_3DShapeReps,
    QE_CustomReps,
    QE_AllReps,
    QE_WithReps,
    QE_FilterStaticMappings,
    QE_WithPortsAndCnxs,
    QE_FilterEffectivities,
    QE_FilterBrokenEffectivities,
    QE_NoEffectivities,
    QE_FilterRFLImplementLinks,
    QE_FilterMFGImplementLinks,
    QE_NoRFLImplementLinks,
    QE_FilterAllocatedResourceLinks,
    QE_FilterTimeConstraintLinks,
    QE_FilterProcessPrerequisiteLinks,
    QE_LoadTimeAnalysis,
    QE_LoadAECObjectType,
    QE_LoadPLMParameters,
    QE_LoadConfigContext,
    QE_LoadConfigEffectivities,
    QE_RemoveOldTypingFastenerMcxs,
    QE_RemoveNewTypingFastenerMcxs,
    QE_NoComponentTypeRetriever
  };

  enum class CATPLMQEOptionState
  {
    QE_Undefined = 0,
    QE_Activated,
    QE_NotActivated
  };

  enum class CATPLMOCFiltering
  {
    Disable,
    Enable
  };

  enum class CATPLMOCGraphFilterMode
  {
    Merge,
    Flush,
    Append,
    Update,
    PartialFlush
  };

  enum class CATPLMOCOptimized
  {
    Disable,
    Enable
  };

  enum class CATPLMQEVolumeType { FullyIn, PartlyIn, PartlyOut, FullyOut };

  enum class CATPLMQEIndexQueryType
  {
    Undefined = 0,
    Expand = 1,
    Wrap = 2,
    Viewpoint = 3,
    Box = 4,
    ViewpointHalfSpace = 5,
    Sphere = 6,
    Proximity = 7,
    InContext = 8,
    ExpandWithDepth = 9
  };

  enum class DebugMode { NoDebug, Log, OMB_XML };

  enum class TypingSystem { OldTyping, NewTyping };

  enum class CATPLMQEProfileContext
  {
    QE_Session = 0,
    QE_OpenCompletion = 1,
    QE_Debug_Session = 2, // Internal use !
    QE_Debug_OpenCompletion = 3, // Internal use !
  };

  enum class CATPLMLoadInContextTarget { LoadInContext_DB = 0, LoadInContext_Index = 1 };

  enum class CATPLMQECBEvent { Begin, Progress, EndBlock, Interrupted, End };

}

template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMQEConstants::CATPLMOCFiltering>::manager();

template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMQEConstants::CATPLMOCGraphFilterMode>::manager();

template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMQEConstants::CATPLMOCOptimized>::manager();

template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMQEConstants::CATPLMQEVolumeType>::manager();

//template<>
//CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMQEConstants::CATPLMQEIndexQueryType>::manager();

template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMQEConstants::TypingSystem>::manager();

template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMQEConstants::CATPLMLoadInContextTarget>::manager();

#endif
