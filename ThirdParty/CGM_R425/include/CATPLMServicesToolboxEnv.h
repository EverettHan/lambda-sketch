// COPYRIGHT Dassault Systemes 2014
//===================================================================
// CATPLMServicesToolboxEnv.h
// Header definition of CATPLMServicesToolboxEnv
//===================================================================
//
// Usage notes:
//   Temporary: created to import CATPsVpmToolbox methods used here
//              and to remove the link towards EnoviaV5Adapter
//
//===================================================================
// July 2004  Creation: EPB
//===================================================================
#ifndef CATPLMServicesToolboxEnv_H
#define CATPLMServicesToolboxEnv_H

#include "CATPLMServicesItf.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATBoolean.h"
#include "CATOmxKeyString.h"

/**
* Describe your class here.
* <p>
* Using this prefered syntax will enable mkdoc to document your class.
*/
class ExportedByCATPLMServicesItf CATPLMServicesToolboxEnv
{
  CATPLMServicesToolboxEnv();
public:
  unsigned int PLM_REMOVE_OWNER_INSTOF_ON_INST : 1;
  CATUnicodeString ADL_ODT_OUT;
  CATUnicodeString ADL_ODT_SLASH;
  // for CATPLMChronoExecution
  CATUnicodeString PLM_ACTIVE_PERFO_TIME_AND_SET_REPO;
  CATBoolean PLM_ACTIVE_PERFO_TIME;
  // Activated
  unsigned int PLM_MLCCONNECTION : 1;
  CATListOfCATUnicodeString PLM1_LOAD_LIST_OF_METADATAS;
  unsigned int IS_PLM1_LOAD_LIST_OF_METADATAS_ACTIVATED : 1;
  unsigned int PLM1_LOADATTR_AT_FIRST_REQUEST_ON_LIST_OF_ATTR : 1;
  CATBoolean bActivateOldDicoLoading;
  unsigned int ADL_ODT_IN : 1;
  unsigned int PLM_APPLY_CS_AND_CI_ON_FILTER_ON_ATTR_AT_EXPAND : 1;

  CATString PLM_LOAD_DICO_CLASSNAME_GETRELATIONSHIP;
  CATString PLM_LOAD_DICO_RELCLASSNAME_GETRELATIONSHIP;

  CATBoolean PLM_IsGetGenericClassFromTypeIdDefined;

  CATBoolean PLM_IsCallToBuildMaskForPackageDelayed;

  CATBoolean IsChangeLogOnFlatTableOn() const;

  CATBoolean PLM_SPLIT_QUERY_TRACE;

  CATBoolean PLM_SPLIT_QUERY;

  CATBoolean PLM_SET_CS_OR_CI_USING_DB_SETTINGS;
  CATBoolean PLM_APPLY_CS_CI_ON_MULTIVALUATED_ATTRIBUTE;
  CATBoolean PLM_ASYNCEXPAND_WITHOUT_SPDC;

  CATBoolean PLM_NLS_ON_RANGE;

  CATBoolean PLM_ODT_ACCEPT_UPDATE_DELETE_OF_FT_WITHOUT_CES;

  // ******************************************************************************************
  // In such a case, we call CATPLMAttributeInternal::GetAuthorizedValues and we take the first authorized value, server should do same job...
  // ******************************************************************************************
  CATBoolean PLM_FIX_RangeWithoutDefaultValue;

  CATBoolean PLM_DETECT_LEAK_ON_PLMTYPE;
  CATOmxKeyString PLM_DETECT_LEAK_ON_PLMTYPE_STR;

  CATBoolean PLM_ACCEPT_ADD_PATH_DATA_ON_SR;

  // 554770 'Select Under' displays wrong state of Requirement. GetAuthorizedValues with nls.
  CATBoolean PLM_GET_AUTHORIZED_VALUES_WITH_NLS;

  CATBoolean _PLMxRestrictedVaultsUsedForRequestWithPath;

  CATBoolean _PLMxIsLastPIDAndRoleActivated;

  CATBoolean _PLM_COMPUTE_TREE_MASK_FOR_EXTENSION;

  int _PLM_VARIANTIMPL;

  int _PLM_VARIANTIMPL_FULLYFINISHED;

  CATBoolean _PLM_IS_EXPAND_ON_INDEX_ACTIVATED;

  int _FTMAXOperators;

  CATUnicodeString _ODT_LOG_NAME, _ADL_ODT_IN;

  CATBoolean _PLM_CLIENT_INFO_FOR_MONITORING;

  CATBoolean _PLM_ODT_TSTCATPLMWMBadQuery;

  CATUnicodeString _CATInstallPath;
  CATBoolean _PLM_DEC_ON_ASYNC_XMQL_REQUEST;
  CATBoolean _PLM_DEC_ON_ASYNC_XMQL_REQUEST_ACCEPT_ALL_SELECT_CLAUSE;

  CATBoolean _PLM_USE_GETLISTOFGENERICCLASSFROMTYPEID;

  CATString _PLM_TraceTypeNameOnSearchByName;

  CATBoolean _PLM_TraceAllTypeNameDomainNameOnAddType;

  CATBoolean _PLM_SearchByNameOnGetPLMTypeFromTypeId;

  CATBoolean _PLM_FORGET_OPERATOR_NULL_NOT_NULL;

  CATBoolean _PLM_IS_SIDL_ACTIVATED_WITH_NLV;

  CATBoolean _PLM_ISCOMPOSEE_ON_DEFAULTMASK;

  /** reset singleton for test purpose */
  void reset();
  /**
  * get the singleton.
  */
  static const CATPLMServicesToolboxEnv &s();

  //@deprecated
  static const CATPLMServicesToolboxEnv &env() { return CATPLMServicesToolboxEnv::s(); }


};

#endif
