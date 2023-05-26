// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATPLMProviderCapabilityEnum.h
// Define the enums used in CATIPLMProviderCapability
//
//===================================================================
/**
* @level Protected
* @usage U1
*/
#ifndef CATPLMProviderCapabilityEnum_H
#define CATPLMProviderCapabilityEnum_H

#include "CATPLMServicesItf.h"

#include "CATListOfInt.h"
#include "IUnknown.h"  // For HRESULT definition

/**
 * List of possible capability asked to providers.
 */
enum ExportedByCATPLMServicesItf CATPLMProviderCapabilityEnum
{
  PC_Maturity                     = 0
 ,PC_NewVersion                   = 1
 ,PC_TypeAttrInSelect             = 2
 ,PC_ExtAttrInSelect              = 3
 ,PC_NOExtAttrInSelect            = 4
 ,PC_MVAAttrInSelect              = 5
 ,PC_TypeAttrInWhere              = 6
 ,PC_ExtAttrInWhere               = 7
 ,PC_AVHVAttrInWhere              = 8
 ,PC_DateAttrInWhere              = 9
 ,PC_UnaryOperators               = 10 // Deprecated ?
 ,PC_BinaryOperators              = 11 // Deprecated ?
 ,PC_TernaryOperators             = 12 // Deprecated ?
 ,PC_MVAAttrInWhere               = 13
 ,PC_ANDORConditionOperator       = 14 // Deprecated -=> 36 - 37
 ,PC_ComplexQuery                 = 15 // Deprecated -=>
 ,PC_AttrInOrderBy                = 16 // Deprecated -=> Always true
 ,PC_ExtAttrInOrderBy             = 17
 ,PC_DateAttrInOrderBy            = 18
 ,PC_NotMandatoryAttrInOrderBy    = 19
 ,PC_CaseSensitiveInQuery         = 20
 ,PC_QueryFetchSupport            = 21
 ,PC_SortInFetch                  = 22
 ,PC_QueryCountSupport            = 23
 ,PC_FilterPrdWithRep             = 24 // Deprecated
 ,PC_BBHandling                   = 25
 ,PC_BBSelectionMode              = 26
 ,PC_BBClearance                  = 27
 ,PC_OctreeFilter                 = 28
 ,PC_LineicFilter                 = 29
 ,PC_ConfigHandling               = 30
 ,PC_SaveHandling                 = 31
 ,PC_StreamProcessing             = 32
 ,PC_SessionUpdate                = 33
 ,PC_SortingOrderInOrderBy        = 34
 ,PC_EnableBasicQuery             = 35
 ,PC_ANDConditionOperator         = 36
 ,PC_ORConditionOperator          = 37
 ,PC_CaseSensitiveInFilter        = 38
 ,PC_EnableSort                   = 39
 ,PC_AdvResultsDisplay            = 40
 ,PC_InPlaceAndTurnTable          = 41
 ,PC_ExploreParents               = 42
 ,PC_ExpandFilter                 = 43
 ,PC_ExpandAttrFilter             = 44
 ,PC_PathExpandHandler            = 45
 ,PC_Import                       = 46
 ,PC_NoStop                       = 47
 ,PC_StopAtFirst                  = 48
 ,PC_StopAtLast                   = 49
 ,PC_LeafOnly                     = 50
 ,PC_QueryOnLastVersion_BQ        = 51
 ,PC_LicensingClientServerSide    = 52
 ,PC_SemanticRelationHandling     = 53
 ,PC_DeltaSaveOfSRs               = 54
 ,PC_RemoveExtension              = 55
 ,PC_RelationFilterHandling       = 56
 ,PC_AttrFilterInNav              = 57
 ,PC_ConfigFilterInNav            = 58
 ,PC_AdvancedSearchSupport        = 59
 ,PC_AdvancedSearchActivated      = 60
 ,PC_ExpandPortsOnReps            = 61
 ,PC_PersistedFilter              = 62
 ,PC_StreamIntegrity              = 63
};

/**
 * List of possible Capability return values.
 */
enum ExportedByCATPLMServicesItf CATPLMProviderCapabilityResult
{
  CR_FullyImpl     // Capability fully understand by provider
 ,CR_Partially     // Some elements of the capability are not implemented
 ,CR_NotImpl       // The capability is not implemented
 ,CR_Unknown       // Mainly used when the information is inside the server and not accessible in the client
 ,CR_NotApplicable // Seen as CR_NotImpl : defines a PRS closure of a NotImpl :)
 ,CR_InDev         // Seen as CR_NotImpl if CNEXT_CLIENT is set when building CATPLMImplAdapter (CR_FullyImpl otherwise)
};

/**
 * Class used to adress a list of couple Capability/CapabilityReturn.
 */
class ExportedByCATPLMServicesItf CATPLMCapabilityRecord
{
public:

/**
 * Constructor.
 */
  CATPLMCapabilityRecord ();

/**
 * Destructor.
 */
  ~CATPLMCapabilityRecord ();

/**
 * Find a specific capability in the record.
 * @param iCapability
 *   The capability to find.
 * @param oCapabilityResult
 *   The result associated.
 * @result
 *   S_OK   : the capability is found in the record
 *   E_FAIL : the capability is not in the record
 */
  HRESULT GetCapabilityResult (CATPLMProviderCapabilityEnum iCapability
                              ,CATPLMProviderCapabilityResult &oCapabilityResult );

/**
 * Used to add a couple Capability/CapabilityResult in the record.
 * Should not be used outside private scope.
 */
  void AddCapabilityRecord (CATPLMProviderCapabilityEnum iCapability, CATPLMProviderCapabilityResult iCapabilityResult);
private:
  CATListOfInt _CapabilityList;
  CATListOfInt _CapabilityResultList;
};

#endif
