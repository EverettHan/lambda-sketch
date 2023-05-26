/* -*-c++-*- */
#ifndef CATPLMLoadingSpec_H
#define CATPLMLoadingSpec_H
//
// CATIA Version 6 Release 208
// Copyright   : Dassault Systemes 2009
//-----------------------------------------------------------------------------
// Description :
// C++ class header file for the class named "CATPLMLoadingSpec"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Inheritance : CATPLMLoadingSpec
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//

/**
* @level Protected
* @usage U1
*/

#include "CATPLMModelBuilder.h"
#include "CATPLMLoadingLevels.h"
#include "CATUnicodeString.h"
#include "CATLISTV_CATPLMID.h"
#include "CATOmxKeyString.h"
#include "CATOmxSR.h"
#include "CATPLMQEConstants.h"

class CAT3DViewer;
class CATSupport;
class CAT3DViewpoint;
class CATIPLMQueryFilter;
class CATIAdpErrorMonitor;
class CATPLMOperation;
class CATPLMLXNode;
class CATMathPoint;
class CATMathVector;
class CATMathTransformation;
class CATPLMQEIndexQuery;

#define LS_Explore    "Explore"
#define LS_Authoring  "Authoring"

#ifndef CATIAR424
/*
  * DO NOT USE: will be removed once migration done by the applications
  */
enum CATPLMQEOptionToRemove
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
  QE_NoRFLImplementLinks,
  QE_LoadTimeAnalysis,
  QE_LoadAECObjectType,
  QE_LoadPLMParameters,
  QE_LoadConfigContext,
  QE_LoadConfigEffectivities
};
#endif

template <> CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMQEOption>::manager();
template <> CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMQEOptionState>::manager();

typedef CATOmxOHMap<CATPLMQEOption, CATPLMQEOptionState > CATPLMOptionsMap;
typedef CATOmxPair< CATPLMQEOption, CATPLMQEOptionState > CATPLMQEOptionDef;
template <> CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMQEOptionDef>::manager();

typedef CATOmxOHMap< CATUnicodeString, CATPLMQEOptionDef > CATPLMOptionsTable;
typedef CATOmxOHMap< CATPLMQEOption, CATUnicodeString > CATPLMReverseOptionsTable;

class ExportedByCATPLMModelBuilder CATPLMLoadingSpec : public CATPLMLoadingLevels
{
public:
  enum CATPLMLSVolumeType { FullyIn, PartlyIn, PartlyOut, FullyOut };

  // ctor / dtor
  CATPLMLoadingSpec();
  CATPLMLoadingSpec(const char* iName, CATBoolean iEstimateExpandResultCount = TRUE);
  CATPLMLoadingSpec(const CATPLMLoadingSpec&);
  virtual ~CATPLMLoadingSpec();

#ifndef CATIAR424
  static CATPLMLoadingSpec Factory(const char* iName, int iDensity = 5, CATBoolean iEstimateExpandResultCount = TRUE);
#endif

  // Hash function
  CATHashKey Hash() const;

  // Full comparison of all elements
  int operator==(const CATPLMLoadingSpec&) const;
  int operator!=(const CATPLMLoadingSpec&) const;

  // assignment operator
  CATPLMLoadingSpec& operator=(const CATPLMLoadingSpec&);

  // Stream / Unstream
  HRESULT Stream(CATOmxSR<CATPLMLXNode> ioNode, DebugMode iForDebug) const;
  HRESULT Unstream(const CATOmxSR<CATPLMLXNode> iNode);

  // Specifies whether the caller wishes 3D visualisation loading
  void Get3DLoading(CATBoolean& oNeed3DVisuLoading) const;
  void Set3DLoading(CATBoolean iNeed3DVisuLoading);

  /*BVL: specifies whether the expand query should be made on index or not*/
  void GetExpandMode(CATBoolean& oNeedExpandOnIndex) const;
  void SetExpandMode(CATBoolean iNeedExpandOnIndex);
  /*BVL*/

  // OPTIONS MANAGEMENT
  /**
  * Compares the options.
  * @param CATPLMLoadingSpec
  *    The other loading spec to compare with.
  * @return
  *    1 if the options are identical.
  *    0 otherwise.
  **/
  int CompareOptions(const CATPLMLoadingSpec&) const;

#ifndef CATIAR424
  /**
   * DO NOT USE - deprecated
   * Adds a new option to the list of options.
   * If a value already existed for this option, it will be overriden.
   * @param iOption
   *    Name of the option to add.
   * @param iOptionState
   *    Activation value of the option (QE_Activated/QE_NotActivated).
   * @return HRESULT
   *    S_OK        : if option has been successfully added to the list of options with specified value.
   *    S_FALSE     : if option already existed, in which case value has been overriden.
   *    E_INVALIDARG: if QE_Undefined option state has been specified or requested option is invalid.
   */
  HRESULT AddOption(CATPLMQEOptionToRemove iOption, CATPLMQEOptionState iOptionState = CATPLMQEOptionState::QE_Activated);
#endif

  /**
  * Adds a new option to the list of options.
  * If a value already existed for this option, it will be overriden.
  * @param iOption
  *    Name of the option to add.
  * @param iOptionState
  *    Activation value of the option (QE_Activated/QE_NotActivated).
  * @return HRESULT
  *    S_OK        : if option has been successfully added to the list of options with specified value.
  *    S_FALSE     : if option already existed, in which case value has been overriden.
  *    E_INVALIDARG: if QE_Undefined option state has been specified or requested option is invalid.
  */
  HRESULT AddOption(CATPLMQEOption iOption, CATPLMQEOptionState iOptionState = CATPLMQEOptionState::QE_Activated);

#ifndef CATIAR424
  /**
   * DO NOT USE - deprecated
   * Removes an option from the list of options.
   * @param iOption
   *    Name of the option to remove.
   * @return CATBoolean
   *    S_OK          : if option has been successfully removed.
   *    S_FALSE       : if option did not exist in the list of options (nothing to do).
   *    E_INVALIDARG  : if requested option is invalid.
   *
   **/
  HRESULT RemoveOption(CATPLMQEOptionToRemove iOption);
#endif

  /**
  * Removes an option from the list of options.
  * @param iOption
  *    Name of the option to remove.
  * @return CATBoolean
  *    S_OK          : if option has been successfully removed.
  *    S_FALSE       : if option did not exist in the list of options (nothing to do).
  *    E_INVALIDARG  : if requested option is invalid.
  *
  **/
  HRESULT RemoveOption(CATPLMQEOption iOption);

  /**
  * Removes all options from the list of options.
  * @param CATBoolean
  *        Specifies if default options should be added to the new list of options.
  *
  **/
  void ResetAllOptions(CATBoolean iAddDefaultOptions = TRUE);

  /**
  * Retrieves a specific option value.
  * @param iOption
  *    Name of the option to be retrieved.
  * @param oOptionState
  *    Activation value of the option (QE_Activated/QE_NotActivated).
  * @return CATBoolean
  *    S_OK          : if option has been successfully queried and associated value returned.
  *    S_FALSE       : if option did not exist in the list of options (nothing to do).
  *    E_INVALIDARG  : if requested option is invalid.
  *
  **/
  HRESULT GetOption(CATPLMQEOption iOption, CATPLMQEOptionState& oOptionState) const;

  /**
  * Specifies whether corresponding option is activated or not.
  * @param iOption
  *    Name of the option to be retrieved.
  * @return CATBoolean
  *    TRUE          : if option has been successfully queried and it is currently activated.
  *    FALSE        : if option did not exist in the list of options (nothing to do) or if it not activated.
  *
  **/
  CATBoolean IsOptionActivated(CATPLMQEOption iOption) const;

  /**
  * Retrieves all options corresponding to a specific state.
  * @param oOptionList
  *    The list of options matching specified criteria.
  * @param iOptionState
  *    Specific option state to match.
  *       - QE_Undefined   : all options will be returned (activated or not).
  *       - QE_Activated   : only activated options will be returned.
  *       - QE_NotActivated: only NOT activated options will be returned.
  * @return
  *    S_OK        : if search went fine, and option list successfully built.
  *    E_INVALIDARG: oOptionList was not empty.
  *
  **/
  HRESULT GetOptionsWithStatus(CATOmxArray<CATPLMQEOption>& oOptionList, CATPLMQEOptionState iOptionState = CATPLMQEOptionState::QE_Activated) const;

  /*
  * Returns an iterator on all the options set.
  */
  CATPLMOptionsMap::IteratorType GetAllOptionDefinitions() const;

  /*
   * Transfers all the options from input loading level to this one.
   * @param CATPLMLoadingSpec
   *    The other loading spec to transfer options from.
   */
  HRESULT TransferOptions(const CATPLMLoadingSpec& iLevels);

  /**
  * Sets the LDH interface to retrieve the Bounding box from 3D Index.
  * @param ipBoundingBox
  *    The implementation of LDH interface.
  * @return
  *    S_OK        : if the implementation was successfully set.
  *    E_INVALIDARG: if the implementation was already provided.
  *
  **/
  HRESULT SetBoundingBoxImplementationForLDH(const CATIPLMBoundingBoxForLDH* ipBoundingBox);

  /**
  * Gets the LDH interface to retrieve the Bounding box from 3D Index.
  * @param opBoundingBox (to be released by caller)
  *    The implementation of LDH interface.
  * @return
  *    S_OK        : if the implementation was successfully returned.
  *    E_FAIL      : if there was no available implementation.
  *
  **/
  HRESULT GetBoundingBoxImplementationForLDH(CATIPLMBoundingBoxForLDH*& opBoundingBox) const;

  /**
  * Compares the LDH interface implementation.
  * @param CATPLMLoadingSpec
  *    The other loading spec to compare with.
  * @return
  *    1 if the implementations are identical.
  *    0 otherwise.
  **/
  int CompareBoundingBoxImplementationForLDH(const CATPLMLoadingSpec&) const;

  /**
   * Retrieves the QE option associated to provided string.
   * @param iProfileOption
   *    The string of the option to be retrieved
   * @param oQEOption
   *    The QE option associated to the provided string
   * @param oQEDefaultState
   *    The current state of the associated QE option
   * @return
   *    S_OK if the QE option has been successfully retrieves.
   *    E_INVALIDARG if there is no QE option associated to the provided string.
   **/
  HRESULT MapOptionFromProfile(const CATUnicodeString& iProfileOption, CATPLMQEOption& oQEOption, CATPLMQEOptionState& oQEDefaultState) const;

  /**
   * Retrieves the string associated to provided QE option.
   * @param iQEOption
   *    The QE option which string is to be retrieved
   * @param oProfileOption
   *    The string associated to the provided QE option
   * @return
   *    S_OK if the QE option has been successfully retrieves.
   *    E_INVALIDARG if there is no QE option associated to the provided string.
   **/
  HRESULT MapOptionToProfile(CATPLMQEOption   iQEOption, CATUnicodeString& oProfileOption) const;

  /*
   * Resets the index query parameters of this loading spec.
   *   After calling this method, the current loading spec won't have any index query specified.
   */
  void ResetQuery();

  // How? 3D part. May be not applicable depending of the states level (as of today, meaningless on Navigation and Full states)
  void SetIndexQuery(const CATPLMQEIndexQuery* iIndexQuery);
  CATOmxSR<CATPLMQEIndexQuery> GetIndexQuery() const;
  CATUnicodeString GetIndexTypeName() const;

  // EXPAND QUERY
  HRESULT SetExpandQuery();

  // EXPAND WITH DEPTH
  HRESULT SetExpandWithDepthQuery(int iDepth = 1);

  // WRAP QUERY
#ifndef CATIAR424
  HRESULT SetWrapQuery(int iDensity); // 0 to 9
#endif
  HRESULT SetWrapQuery(unsigned char iDensity = 5); // 0 to 9

  // VIEWPOINT QUERY
#ifndef CATIAR424
  HRESULT SetViewpointQuery(const CAT3DViewer* iViewer,
    const CATLISTV(CATPLMID)* iList = NULL);
#endif

  HRESULT SetViewpointQuery(const CAT3DViewer* iViewer,
    const CATPLMIDs& iPlmids);

#ifndef CATIAR424
  HRESULT SetViewpointQuery(const CAT3DViewpoint* iViewpoint,
    const CATSupport* iSupport,
    const CATLISTV(CATPLMID)* iList = NULL);
#endif

  HRESULT SetViewpointQuery(const CAT3DViewpoint* iViewpoint,
    const CATSupport* iSupport,
    const CATPLMIDs& iPlmids);

  // VIEWPOINT HALFSPACE QUERY
  HRESULT SetViewpointHalfSpaceQuery(const CAT3DViewer* iViewer,
    const CATMathPoint& iOrigin,
    const CATMathVector& iNormal);

  // BOX QUERY
#ifndef CATIAR424
  HRESULT SetBoxQuery(const CATMathPoint& iBoxMinPoint,
    const CATMathPoint& iBoxMaxPoint,
    const CATMathTransformation& iBoxPosition,
    CATPLMLSVolumeType iType = PartlyIn);
#endif

  HRESULT SetBoxQuery(const CATMathPoint& iBoxMinPoint,
    const CATMathPoint& iBoxMaxPoint,
    const CATMathTransformation& iBoxPosition,
    CATPLMQEVolumeType iType = CATPLMQEVolumeType::PartlyIn);

  // SPHERE QUERY
#ifndef CATIAR424
  HRESULT SphereQuery(const CATMathPoint& iCenter,
    double iRadius,
    CATPLMLSVolumeType iType = PartlyIn);
#endif

  HRESULT SphereQuery(const CATMathPoint& iCenter,
    double iRadius,
    CATPLMQEVolumeType iType = CATPLMQEVolumeType::PartlyIn);

  // PROXIMITY QUERY
#ifndef CATIAR424
  HRESULT ProximityQuery(const CATPLMID& iRep,
    const CATMathTransformation& iUselessRepPosition,
    double iClearance,
    CATPLMLSVolumeType iType = PartlyIn);
#endif

  HRESULT ProximityQuery(const CATPLMID& iRep,
    float iClearance,
    CATPLMQEVolumeType iType = CATPLMQEVolumeType::PartlyIn);

  // INCONTEXT QUERY
  HRESULT SetInContextQuery(const CATLISTV(CATPLMID)& iSearched);

  CATBoolean IsIndexEqual(const CATPLMLoadingSpec& iOther) const;

  CATPLMQEVolumeType ConvertVolumeEnum(CATPLMLSVolumeType iVolumeType);

  /*
   * Restores all the parameters of this loading spec.
   *   like it was a brand loading spec created through the default constructor.
   */
  void RestoreDefaultValues();

protected:
  friend class CATPLMQEBuilder;
  friend class CATPLMQEBuildFilter;
  friend class CATPLMLoadingProfile;
  friend class CATPLMOperationQueryBuilder;
  friend class CATPLMQueryEngine;
  friend class CATPLMOperationLoadBase_QueryVisitor;
  friend class CATPLMQETaskPushExpand;
  friend class CATPLMCompletionExpandDindeAction;
  friend class CATPLMQETrace;
  friend class TSTCATPLMOperationContext_LoadingLevelsComponentTypeRetrieverTests_Spec;
  friend class CATPLMOperationLoadBase;

  /*
   * INTERNAL USE ONLY
   */

  HRESULT _PrivateGetOption(CATPLMQEOption iOption, CATPLMQEOptionState& oOptionState) const;
  CATBoolean _IsOptionActivated(CATPLMQEOption iOption) const;

  // Component retriever management for open completion
  const CATPLMTypeHSet& GetComponentRetrieverTypes() const;
  CATBoolean IsAComponentRetrieverAddedType(const CATPLMTypeH& iTypeH) const; // exact match
  CATBoolean IsAComponentRetrieverMatchingType(const CATPLMTypeH& iTypeH) const; // IsKindOf match
  int CompareComponentRetrieverTypes(const CATPLMLoadingSpec& iOther) const;
  void SetComponentRetrieverTypes(const CATPLMTypeHSet& iComponentRetrieverTypes);
  void InsertComponentRetrieverType(const CATPLMTypeH& iTypeH);

private:
  CATBoolean                         m_need3DVisuLoading;
  /*BVL*/CATBoolean                  m_needExpandOnIndex;/*BVL*/
  CATOmxSR<CATPLMQEIndexQuery>       m_spec_index;
  CATPLMOptionsMap                   m_listOfOptions;
  CATOmxSR<CATIPLMBoundingBoxForLDH> m_spBoundingBox;
  CATPLMTypeHSet                     m_componentRetrieverTypes;

  static CATPLMOptionsTable m_mappingTable;
  static CATPLMReverseOptionsTable m_reverseMappingTable;

  HRESULT _InitMappingTable() const;
  HRESULT _InitOption(const CATUnicodeString& iProfileOption,
    CATPLMQEOption iQEOption,
    CATPLMQEOptionState iDefaultOptionState) const;

  HRESULT _AddDefaultOptions();
  HRESULT _PrivateAddOption(CATPLMQEOption iOption, CATPLMQEOptionState iOptionState = CATPLMQEOptionState::QE_Activated);


  CATPLMQEOptionDef make_option_def(CATPLMQEOption iOption, CATPLMQEOptionState iOptionState) const
  {
    CATPLMQEOptionDef optionDef = { iOption, iOptionState };
    return optionDef;
  }
};
#endif
