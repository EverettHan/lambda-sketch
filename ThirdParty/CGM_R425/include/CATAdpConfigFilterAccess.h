/*
 * CATAdpConfigFilterAccess.h
 *
 *  Created on: Dec 16, 2013
 *      Author: pjq
 */

#ifndef CATADPCONFIGFILTERACCESS_H_
#define CATADPCONFIGFILTERACCESS_H_

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"
#include "CATOmxSR.h"
class CATIPLMFilterConfig;
class CATIPLMQueryFilter;
class CATBinary;

/**
 * Api to extract the compiledForm form a query filter in order to
 * use it for various client side validation (see  @href CATAdpConfigClientValidation)
 */
class ExportedByCATPLMIntegrationAccess CATAdpConfigFilterAccess
{
  CATOmxSR<CATIPLMFilterConfig> _configFilter;
public:
  /**
   * Initialize the configuration filter on which to retrieve the compiledForm binary.
   * @parama iQueryFilter [in]
   *   A query filter containing a configuration filter.
   * @return
   *   S_OK if a configuration filter has been found on the query filter
   *   S_FALSE if no configuration filter has been found on the query filter
   *   E_* if case of error (NULL input...)
   */
  HRESULT SetConfigFilter(CATIPLMQueryFilter * iQueryFilter);

  /**
   * Retrieves the compiled form binary from the setted configuration filter.
   * @param oCompiledForm [out]
   *   The compiled form binary associated to the configuration filter.
   * @param iApplyCompositionRules [in]
   *   Specifies whether matrice composition rules should be applied to the compiled form.
   * @return
   *   S_OK if everything went well
   *   E_* if an error occured
   */
  HRESULT GetFilterCompiledForm(CATBinary & oCompiledForm, CATBoolean iApplyCompositionRules=TRUE);

  /**
   * Static helper method to extract the configuration binary compiled form form a query filter.
   * @parama iQueryFilter [in]
   *   A query filter containing a configuration filter.
   * @param oCompiledForm [out]
   *   The compiled form binary associated to the configuration filter.
   * @param iApplyCompositionRules [in]
   *   Specifies whether matrice composition rules should be applied to the compiled form.
   * @return
   *   S_OK if a configuration filter has been found on the query filter and the binary has been extracted
   *   S_FALSE if no configuration filter has been found on the query filter
   *   E_* if case of error (NULL input or internal error)
   */
  static HRESULT GetConfigFilterCompiledForm(CATIPLMQueryFilter * iQueryFilter, CATBinary & oCompiledForm, CATBoolean iApplyCompositionRules=TRUE)
  {
    CATAdpConfigFilterAccess cfgAccess;
    HRESULT hr = cfgAccess.SetConfigFilter(iQueryFilter);
    if(S_OK == hr)
		hr = cfgAccess.GetFilterCompiledForm(oCompiledForm,iApplyCompositionRules);
    return hr;
  }

  /**
   * Static helper method to extract the configuration binary compiled form form a config filter.
   * @parama iConfigFilter [in]
   *   A configuration filter.
   * @param oCompiledForm [out]
   *   The compiled form binary associated to the configuration filter.
   * @param iApplyCompositionRules [in]
   *   Specifies whether matrice composition rules should be applied to the compiled form.
   * @return
   *   S_OK if the binary has been extracted
   *   E_* if case of error (NULL input or internal error)
   */
  static HRESULT GetConfigFilterCompiledForm(CATIPLMFilterConfig * iConfigFilter, CATBinary & oCompiledForm, CATBoolean iApplyCompositionRules=TRUE);


};

#endif /* CATADPCONFIGFILTERACCESS_H_ */
