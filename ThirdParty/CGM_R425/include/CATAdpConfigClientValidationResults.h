#ifndef CATADPCONFIGCLIENTVALIDATIONRESULTS_H_
#define CATADPCONFIGCLIENTVALIDATIONRESULTS_H_

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"

#include "CATPLMID.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxOHMap.h"
#include "CATOmxMapIter.h"
class CATOmxCollecManager;

/**
 * Those classes are used as output to CATAdpConfigClientValidation.
 * See @href CATAdpConfigClientValidation for usage details.
 */

/**
 * Enum to represent the validity status of a component with regards to a configuration filter
 * See @href CATAdpConfigClientValidationResult for details on the specific values
 */
enum CATAdpConfigClientValidity{
  cfg_valid,
  cfg_partially_valid,
  cfg_not_valid,
  cfg_not_accessible,
  cfg_unknown
};


/**
 * Struct to represent the result of the validation of a given plmid path.
 *
 * When created through CATAdpConfigClientValidation, the content of ValidSubPath,
 * will be linked to the value of Result :
 *
 * @enum cfg_valid :
 *    The path is valid in the given configuration filter.
 *    ValidSubPath is the full associated path.
 * @enum cfg_partially_valid :
 *    The path is partially valid in the given configuration filter.
 *    ValidSubPath is the valid part, from the beginning of the path up to the first invalid element.
 * @enum cfg_not_valid :
 *    The path is accessible but not valid in the given configuration filter.
 *    ValidSubPath is Null.
 * @enum cfg_not_accessible :
 *    Part of the path cannot be accessed. It may have been deleted or access not granted by PnO rules.
 *    ValidSubPath is the valid part, from the beginning of the path up to the first unaccessible element.
 * @enum cfg_unknown :
 *    The plmid wasn't part of the validation.
 *    ValidSubPath is Null.
 */
struct ExportedByCATPLMIntegrationAccess CATAdpConfigClientValidationResult{
  /**
   * Result : The global result of the validation for the given path.
   */
  CATAdpConfigClientValidity Validity;

  /**
   * ValidSubPath : The valid sub part of the given path.
   */
  CATPLMID ValidSubPath;

  inline CATAdpConfigClientValidationResult()
  :Validity(cfg_unknown), ValidSubPath(CATPLMID_Null)
  {
  }

  inline CATAdpConfigClientValidationResult(
      const CATAdpConfigClientValidity & iValidity,
      const CATPLMID & iValidSubPath)
  :Validity(iValidity), ValidSubPath(iValidSubPath)
  {
  }
};
template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATAdpConfigClientValidationResult>::manager();


/**
 * Iterator on the CATAdpConfigClientValidationResult collections with helper access to the value data.
 */
typedef CATOmxOHMap<CATPLMID, CATAdpConfigClientValidationResult> CATAdpConfigClientValidationResultMap;
class ExportedByCATPLMIntegrationAccess CATAdpConfigClientValidationResultsIter
{
  CATAdpConfigClientValidationResultMap::MapIteratorType _iter;
public:
  CATAdpConfigClientValidationResultsIter(const CATAdpConfigClientValidationResultMap::MapIteratorType & iMapIter)
  :_iter(iMapIter)
  {
  }

  /**
   * Advances to tne next result in the collection.
   * @return
   *   TRUE if a new result is available (through the next acces methods)
   *   FALSE if the end of the collection has been reached (the next methods will assert...)
   */
  inline CATBoolean Next()
  {
    return _iter.Next();
  }

  /**
   * Accessor to the current input path.
   */
  inline const CATPLMID & PLMID()
  {
    return _iter.Key();
  }

  /**
   * Helper to rapidily access the validity result of the current path
   */
  inline CATAdpConfigClientValidity Validity()
  {
    return _iter.Value().Validity;
  }

  /**
   * Helper to rapidily access the valid sub part of the current path
   */
  inline const CATPLMID & ValidSubPath()
  {
    return _iter.Value().ValidSubPath;
  }

  /**
   * Accessor to the CATAdpConfigClientValidationResult for the current path
   */
  inline const CATAdpConfigClientValidationResult & Result()
  {
    return _iter.Value();
  }
};


/**
 * Collection to access the result of a validation session.
 */
class ExportedByCATPLMIntegrationAccess CATAdpConfigClientValidationResults
{
  CATAdpConfigClientValidationResultMap _results;
public:
  /**
   * Add or overrides the validity result for the given path
   * @param iPLMID [in]
   *   The plmid representing the given path
   * @param iValidity [in]
   *   The validity status of the given path
   * @param iValidSubPath [in]
   *   The valid sub part of the given path (may be null)
   */
  void AddResult(const CATPLMID & iPLMID,
      CATAdpConfigClientValidity iValidity,
      const CATPLMID & iValidSubPath);

  /**
   * Accessor to the collection size.
   */
  inline unsigned int Size() const
  {
    return _results.Size();
  }

  /**
   * Accessor to the validation result for a given path.
   * See @href CATAdpConfigClientValidationResult for details on the returned value.
   */
  const CATAdpConfigClientValidationResult & GetResult( const CATPLMID & iPLMID ) const;

  /**
   * Iterator on the collection content.
   * See @href CATAdpConfigClientValidationResultsIter
   */
  inline CATAdpConfigClientValidationResultsIter ResultsIterator()
  {
    return CATAdpConfigClientValidationResultsIter(_results.MapIterator());
  }
};
#endif /* CATADPCONFIGCLIENTVALIDATIONRESULTS_H_ */
