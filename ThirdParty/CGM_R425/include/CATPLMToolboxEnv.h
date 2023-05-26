//===================================================================
// COPYRIGHT Dassault Systemes 2004
//===================================================================
// Header definition of CATPLMToolboxEnv
//===================================================================
// Usage notes:
// Runtime environment variables to activate/deactivate specific behaviors
//===================================================================
//  Mar 2004  Creation: jsy
//===================================================================
#ifndef CATPLMToolboxEnv_H
#define CATPLMToolboxEnv_H

#include "CATPLMToolkit.h"

#include "CATUnicodeString.h"
#include "CATOmxKeyString.h"
#include "CATBoolean.h"
#include "CATPLMQueryFilterEnum.h"

class ExportedByCATPLMToolkit CATPLMToolboxEnv
{
  friend class ContextTSTCATPLMxFilterConditionOperandCountLimit;
  CATPLMToolboxEnv();
public:
  unsigned int ADL_ODT_IN : 1;
  unsigned int PLM_PLMIDFROMURL : 1;
  unsigned int PLM_DOUBLEABSTRACTION : 1;
  unsigned int PLM_ALLFACETS : 1;
  unsigned int PLM_BSF_NO_FILTER : 1;
  unsigned int PLM_DATASETSUBSTITUTES : 1;
  unsigned int PLM_NOTRUEFILTER : 1;
  unsigned int PLM_MANDATORY_SRS_IN_REMOTE : 1;
  unsigned int PLM_MANDATORY_SRS_IN_SPDC : 1;
  unsigned int PLM_IS_TYPENAME_IN_ADDSELECTCOND_DEFINED : 1;
  CATOmxKeyString PLM_TYPENAME_IN_ADDSELECTCOND_VALUE;
  unsigned int PLM_IS_ATTRNAME_IN_ADDSELECTCOND_DEFINED : 1;
  CATOmxKeyString PLM_ATTRNAME_IN_ADDSELECTCOND_VALUE;
  unsigned int PLM_RANDOMIZE_RECORDS : 1;
  CATPLMQueryFilterEnum::OpenMode PLM_OPEN_MODE;
  // Try to clarify a bit this horrible algorithm...
  // Today, on open queries, real inheritance is applied
  // For expand queries, job is made by server and only best matching type is taken into account
  CATBoolean PLM_BestMatchingTypeAtOpen;

  int PLM_QUERY_LIMIT_MAX_IN;
  CATBoolean PLM_QUERY_SPLIT_APPLICATION_LOADER;
  CATBoolean PLM_S_FALSE_IF_REPORT;

  // Activated
  unsigned int PLM_MLCCONNECTION : 1;

  // Autonames
  unsigned int PLMBL_FORCE_SERVER_KEY_IN_ODT_ENV : 1;
  CATBoolean PLM_GENERATE_AUTONAMES_ON_CLIENT_SIDE;
  CATBoolean PLM_GENERATE_AUTONAMES_UUID;
  int PLM_AUTO_NAMING_MAX_NUMBER_NAMES_REQUESTED;
  CATBoolean PLM_AUTO_NAMING_RESERVATIONNUMBERSERVICE_ENABLED;
  CATBoolean PLM_AUTO_NAMING_CACHE_ENABLED;

  CATBoolean _PLMxWarningInGlobalReportIfInvalidType;
  CATBoolean _PLMxWarningInGlobalReportIfErrorInRecordReport;

  CATBoolean PLM_CHECKCONSISTENCYOFSD;

  CATBoolean isNoAutoIdDump;

  CATBoolean PLM_RESEND_IF_NETWORK_ERROR;

  CATBoolean PLM_RAISE_ERROR_ON_SR_WITH_IDREL_ALREADY_FOUND, PLM_RAISE_ERROR_ON_SR_WITH_IDREL_ALREADY_FOUND_WRITE_STEP;

  CATBoolean PLM_ADDITIONAL_QUERY_PERFORMED_FOR_PATHID_ON_SRS_STREAMED_IN_PLMQL;

  CATBoolean PLM_GETXXXVALUE_FAILS_ON_MULTI;

  CATBoolean _BasicQueryOnXMQL; // active les queries serveur en xMQL - coming from CATPLMToolboxEnv
  CATBoolean _NavigateQueryOnXMQL; // active les queries serveur de type navigate en xMQL - coming from CATPLMToolboxEnv
  CATBoolean _PushNavigateQueryOnXMQL; // active les queries serveur de type push navigate en xMQL. Requiert _NavigateQueryOnXMQL pour être effectif - coming from CATPLMToolboxEnv
  CATBoolean _InContextNavigateQueryOnXMQL; // active les queries serveur de type navigate in_context en xMQL. Requiert _NavigateQueryOnXMQL pour être effectif - coming from CATPLMToolboxEnv

  CATBoolean _SRAndSDByDefault; // coming from CATPLMToolboxEnv

  /**
  * Resets singleton for test purpose.
  */
  void reset();

  /**
  * Returns the singleton.
  */
  static const CATPLMToolboxEnv &s();
private:
  static CATPLMToolboxEnv& nocsts();
};

#endif
