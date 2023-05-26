/*
 * CATAdpConfigAccess.h
 *
 *  Created on: Dec 16, 2013
 *      Author: pjq
 */

#ifndef CATADPCONFIGACCESS_H_
#define CATADPCONFIGACCESS_H_
/**
 * @level Protected
 * @usage U1
 */
#include "CATPLMIntegrationAccess.h"
#include "CATAdpConfigInfo.h"
#include "CATBinary.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATBinary.h"
#include "CATListOfCATBoolean.h"

class ExportedByCATPLMIntegrationAccess CATAdpConfigAccess
{
public:
  virtual ~CATAdpConfigAccess(){}

protected:
  friend class CATAdpConfigFilterAccess;
  friend class CATAdpConfigClientValidation;
  friend class CATAdpConfigComponentData;
  friend class CATAdpStaticMappingQueryParser;
  friend class CATAdpClientValidationTestsAvailability;
  friend class CATAdpConfigComponentValidityMap;

  /**
   * Retrieves config informations in session on the given component
   *
   * @param iComponentInSession [in]:
   *   The component handle in session. Should be an instance.
   * @param oHasEffectivity [out]:
   *   TRUE if the component holds an effectivity. The effectivity compiled form
   *   will be found in oEffectivityCompiledForm.
   * @param oEffectivityCompiledForm [out]:
   *   The compiled form of the component's effectivity if relevant
   * @param oHasStaticMapping [out]:
   *   TRUE if the instance has an associated static mapping.
   */
  virtual HRESULT GetConfigInfos(CATBaseUnknown * iComponentInSession,
      CATBoolean & oHasEffectivity, CATBinary & oEffectivityCompiledForm,
      CATBoolean & oHasStaticMapping){return E_NOTIMPL;}

  /**
   * Computes the validity of various instances with regard to a given filter.
   * @param iFilterCompiledForm [in]:
   *   The filter compiled form to apply. Note that it should have been completed
   *   with its composition rules (see @href CATAdpConfigAccess::CompleteFilterCompiledForm)
   * @param iInstancesEffectivitesCompiledForms [in]:
   *   The instances effectities compiled forms (retrieved by @href CATAdpConfigAccess::
   *   GetConfigInfos or a dedicated query)
   * @param oInstancesValidities [out]:
   *   The instances validity. TRUE if the given effectivity compiled form match the
   *   filter compile form.
   */
  virtual HRESULT ComputeValidities(const CATBinary & iFilterCompiledForm,
      const  CATListOfCATBinary & iInstancesEffectivitesCompiledForms,
      CATListOfCATBoolean   & oInstancesValidities){return E_NOTIMPL;}

  static CATAdpConfigAccess * Get();
};
#endif /* CATADPCONFIGACCESS_H_ */
