#ifndef CATADPCONFIGCLIENTVALIDATION_H_
#define CATADPCONFIGCLIENTVALIDATION_H_

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"

#include "CATPLMID.h"
#include "CATLISTV_CATPLMID.h"
#include "CATPLMIDSet.h"
#include "CATOmxSR.h"
#include "CATBinary.h"
#include "CATAdpConfigClientValidationResults.h"
#include "CATBoolean.h"
class CATAdpConfigComponentData;

/**
 * Class to validate on the client various complex plmids in a specific configuration.
 *
 * Retrieving the configuration information on the server is expensive and must be done
 * before validating the data. To optimize this step, it is better to batch the processsing.
 *
 * Sample usage (error are not fully chekced, but you should check them in production code !):
 * <code>
 * CATIPLMQueryFilter * myQueryFilterWithConfigFilter;
 * CATPLMIDs theComplexPLMIDsToValidate;
 * //...
 *
 * // First, you need the compiled form for your filter.
 * CATBinary myCfgFilterCompiledForm;
 * if(S_OK != CATAdpConfigFilterAccess::GetConfigFilterCompiledForm(
 *   myQueryFilterWithConfigFilter, myCfgFilterCompiledForm))
 * {
 *   // No config filter found. Exit
 *   return;
 * }
 *
 * // If you don't have any specific previous informations regarding the data to validate,
 * // don't specify any CATAdpConfigComponentData. On the overside, if you have any information
 * // on the data to validate (CEStamps or ConfigInfos from a previous query or BSM model), first
 * // fill a CATAdpConfigComponentData with it and give it to the CATAdpConfigClientValidation cstor.
 * CATAdpConfigClientValidation myValidation(myCfgFilterCompiledForm);
 * myValidation.AddPathsToValidate(theComplexPLMIDsToValidate);
 *
 * CATAdpConfigClientValidationResults myValidationResults;
 * myValidation.Validate(myValidationResults);
 *
 * // Here, I remember all the valid paths, including those that are only partially valid,
 * // you can do whatever you want in function of the validity of your components.
 * // If you want to keep your original order, iterate on your inputs collection and use
 * // CATAdpConfigClientValidationResults::GetResult.
 * CATPLMIDSet validSubPaths;
 * CATAdpConfigClientValidationResultsIter iter = myValidationResults.ResultsIterator();
 * while(iter.Next())
 * {
 *    switch(iter.Validity())
 *    {
 *      case cfg_valid:
 *      case cfg_partially_valid:
 *      case cfg_not_accessible:
 *      {
 *        const CATPLMID & validSubPart = iter.ValidSubPath();
 *        if(!!validSubPart)
 *          validSubPaths.Insert(validSubPart);
 *      }
 *      case cfg_not_valid:
 *      case cfg_not_accessible:
 *      case cfg_unknown:
 *      default: // No known other value in the enum for the time being...
 *        break;
 *    }
 * }
 * //...
 * </code>
 */
class ExportedByCATPLMIntegrationAccess CATAdpConfigClientValidation
{
  friend class CATAdpConfigClientValidationVisitor;
  friend class CATAdpConfigComponentValidityVisitor;

  CATPLMIDSet _paths;
  CATOmxSR<CATAdpConfigComponentData> _cfgData;
  CATBinary _filterCompiledForm;
public:
  /**
   * Cstr
   * @param iFilterCompiledForm:
   *   The compiled form of the configuration filter to apply.
   *   If you have a CATIPLMQueryFilter, it can be retrieved through CATAdpConfigFilterAccess API.
   * @param iCfgData
   *   If you have config data around, you may pass it in order to save unnecessary queries. Note
   *   that it will be enriched with the missing data necessary for the execution of the validation.
   *   See @href CATAdpConfigComponentData for details.
   */
  CATAdpConfigClientValidation(const CATBinary & iFilterCompiledForm,
      CATAdpConfigComponentData * iCfgData=NULL);

  /**
   * Retrieves the iternal configdata if you want to enrich it with more data.
   * @returns
   *   The intenal CATAdpConfigComponentData used for the validation process. No addref done.
   */
  CATAdpConfigComponentData * GetConfigData();

  /**
   * Adds a path to validate.
   * @param iPLMID
   *   a complex plmid representing a path of components to validate
   */
  void AddPathToValidate(const CATPLMID & iPLMID);

  /**
   * Adds many paths to validate through a list
   * @param iPLMIDs
   *   a list of complex plmids representing paths of components to validate
   */
  void AddPathsToValidate(const CATPLMIDs & iPLMIDs);

  /**
   * Adds many paths to validate through a set
   * @param iPLMIDs
   *   a set of complex plmids representing paths of components to validate
   */
  void AddPathsToValidate(const CATPLMIDSet & iPLMIDs);

  /**
   * Runs the validation of the various paths.
   * @params oResults [out]
   *   The results of the validation
   * @param iUseSessionData [in]
   *   For config data not available through the given CATAdpConfigComponentData,
   *   authorize the usage of the session data if the component is opened in session
   * @return
   *   S_FALSE if no components has been added through AddPath(s)ToValidate methods
   *   S_OK if everything went well
   *   E_* if error in treatment, mainly an install issue (config dlls not available)
   */
  HRESULT Validate(CATAdpConfigClientValidationResults & oResults, CATBoolean iUseSessionData = FALSE);
};

#endif /* CATADPCONFIGCLIENTVALIDATION_H_ */
