/*
 * CATAdpConfigFilterCompletion
 *
 *  Created on: Dec 16, 2013
 *      Author: pjq
 */

#ifndef CATAdpConfigFilterCompletion_H_
#define CATAdpConfigFilterCompletion_H_
/**
 * @level Protected
 * @usage U1
 */
#include "CATPLMIntegrationAccess.h"
#include "CATBinary.h"

class ExportedByCATPLMIntegrationAccess CATAdpConfigFilterCompletion
{
public:
  virtual ~CATAdpConfigFilterCompletion(){}

protected:
  friend class CATAdpConfigFilterAccess;
  friend class CATAdpConfigClientValidation;
  friend class CATAdpConfigComponentData;
  friend class CATAdpStaticMappingQueryParser;
  friend class CATAdpClientValidationTestsAvailability;

  /**
   * Completes the given filter compile form to apply the related composition rules.
   * @param iOriginalFilterCompiledForm [in]:
   *   The raw filter compiled form.
   * @param oCompletedFilterCompiledForm [out]:
   *   The completed compiled form.
   */
  virtual HRESULT CompleteFilterCompiledForm(
      const CATBinary & iOriginalFilterCompiledForm,
      CATBinary & oCompletedFilterCompiledForm ){return E_NOTIMPL;}

  static CATAdpConfigFilterCompletion * Get();
};
#endif /* CATAdpConfigFilterCompletion_H_ */
