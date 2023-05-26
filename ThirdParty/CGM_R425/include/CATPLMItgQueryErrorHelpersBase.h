#ifndef CATPLMItgQueryErrorHelpersBase_h
#define CATPLMItgQueryErrorHelpersBase_h

#include "CATPLMIntegrationBase.h"
#include "CATOmxSR.h"
#include "CATString.h"
#include "CATIPLMError.h"
#include "CATOmyAsserts.h"
#include "CATIPLMRecordRead.h"
#include "CATPLMID.h"
#include "CATIAdpPLMIdentificator.h"
#include "CATIOmyIncidentCollector.h"
#include "CATSysBoolean.h"

class ExportedByCATPLMIntegrationBase CATPLMItgQueryErrorHelpersBase
{
public:
  /**
   * Analyses the content of the error to detect if it is only ComponentNotFound errors
   * @returns
   *    TRUE if the error is only componentNotFound.
   *    FALSE if the error is not only ComponentNotFound
   */
  static CATBoolean ErrorIsOnlyComponentNotFound(CATIPLMError * iError);

  /**
  * Analyses the content of the error to detect if it is only ComponentNotFound errors
  * @returns
  *    TRUE if the error is only componentNotFound.
  *    FALSE if the error is not only ComponentNotFound
  */
  static CATBoolean ErrorIsOnlyComponentNotFound(CATString iKey, CATString iCatalog);

  /**
   * Tells if the record contains an error
   */
  static CATBoolean RecordContainsError(CATIPLMRecordRead * record);

  /**
   * Extracts error detail from the record.
   *
   * @retrun
   *    S_OK if the record contains a error and related information has been found
   *    S_FALSE if the record doesn't contains any error
   *    E_INVALIDARG if the record is NULL
   *    E_* if the record contains a error but related infos couldn't be extracted
   */
  static HRESULT GetErrorDetails(CATIPLMRecordRead * record, CATPLMSeverity & oSeverity, CATString & oCatalog, CATString & oKey);


  /**
   * Report record error in the given incident collector. If the collector is NULL, this method is
   * equivalent to RecordContainsError with S_OK if an error is found and S_FALSE if no error.
   *
   * @retrun
   *    S_OK if the record contains a error and related information has been found
   *         and added to the monitor (if the collector is NULL, no error is reported)
   *    S_FALSE if the record doesn't contains any error
   *    E_INVALIDARG if the record is NULL
   *    E_* if the record contains a error but related infos couldn't be extracted
   */
  static HRESULT ReportRecordError(CATIOmyIncidentCollector* iIncidentCollector, CATIPLMRecordRead * record, CATBoolean iConvertErrorsToWarnings = FALSE);

  /**
   * Writes the error details along with the PLMID associated to the record to the given error monitor
   * If the monitor is empty, nothing happens.
   */
  static void ReportRecordError(CATIOmyIncidentCollector* iIncidentCollector, CATIPLMRecordRead * record, CATPLMSeverity iSeverity, const CATString & iCatalog, const CATString & iKey, CATBoolean iConvertErrorsToWarnings = FALSE);

  /*
  * Converts Severity to ErrorType, extracts adp from the record. These are the monitor/collector inputs
  */
  static void ConvertForErrorCell(CATPLMSeverity iSeverity, CATIPLMRecordRead& iRecord, CATBoolean iConvertErrorsToWarnings, CATErrorType &oSeverity, CATOmxSR<CATIAdpPLMIdentificator> &oId);
};

#endif
