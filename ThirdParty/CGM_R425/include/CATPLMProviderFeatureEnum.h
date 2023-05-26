// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATPLMProviderFeatureEnum.h
// Define the enums used in CATIPLMCompProviderFeatureService
//
//===================================================================
/**
* @level Protected
* @usage U1
*/
#ifndef CATPLMProviderFeatureEnum_H
#define CATPLMProviderFeatureEnum_H

#include "CATPLMServicesItf.h"

/**
 * List of possible features to ask to providers.
 */
enum ExportedByCATPLMServicesItf CATPLMProviderFeatureEnum
{
  PF_MaturityHandling         = 0
 ,PF_NewVersionHandling       = 1
 ,PF_SelectClause             = 2
 ,PF_WhereClause              = 3
 ,PF_WhereCondition           = 4
 ,PF_CaseSensitive            = 5
 ,PF_OrderBy                  = 6
 ,PF_QueryCount               = 7
 ,PF_PrdWithRepFilter         = 8 // deprecated ?
 ,PF_VolumeFilter             = 9
 ,PF_ConfigFilter             = 10
 ,PF_UISave                   = 11
 ,PF_BasicSave                = 12
 ,PF_QueryBasic               = 13
 ,PF_ResultDisplay            = 14
 ,PF_InPlaceAndTurnTable      = 15
 ,PF_ExploreParents           = 16
 ,PF_ExpandFilterSupport      = 17
 ,PF_AttrFilter               = 18
 ,PF_FetchQuery               = 19
 ,PF_PathExpandHandler        = 20
 ,PF_ImportHandling           = 21
 ,PF_FilteredExpandLimit      = 22
 ,PF_QueryOnLastVersion       = 23
 ,PF_LicensingBehaviour       = 24
 ,PF_SemanticRelationHandling = 25
 ,PF_SaveExtension            = 26
 ,PF_NavigateFilterSupport    = 27
 ,PF_AdvancedSearchSupport    = 28
 ,PF_ExpandCnxAndPorts        = 29
 ,PF_PersistedFilter          = 30
 ,PF_StreamIntegrity          = 31
};

/**
 * List of possible feature return values.
 */
enum ExportedByCATPLMServicesItf CATPLMProviderFeatureResult
{
  FR_FullyImpl // All High priority SubFeatures are fully implemented.All Low priority SubFeatures are at least partially implemented.
 ,FR_Usable    // All High priority SubFeature are fully implemented. At least one Low priority SubFeature is not at least Partially Implemented.
 ,FR_Partially // At least one High priority SubFeature is partially implemented.
 ,FR_MayFail   // At least one High priority SubFeature is not implemented.
 ,FR_NotImpl   // All High priority SubFeature are not at least partially implemented.
};

#endif
