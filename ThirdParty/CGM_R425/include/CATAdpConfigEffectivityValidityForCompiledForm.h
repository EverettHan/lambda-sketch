/*
 * CATAdpConfigComponentValidityForCompiledForm.h
 *
 *  Created on: May 18, 2015
 *      Author: pjq
 */

#ifndef CATADPCONFIGCOMPONENTVALIDITYFORCOMPILEDFORM_H_
#define CATADPCONFIGCOMPONENTVALIDITYFORCOMPILEDFORM_H_

#include "CATPLMIntegrationAccess.h"
#include "CATOmxCollecManager.h"
#include "CATOmxOHMap.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATSysBoolean.h"
#include "CATBinary.h"
#include "CATAdpConfigClientValidationResults.h"

/**
 * Class to hold the validity of various effectivities with regard to a filter
 */
ExportedByCATPLMIntegrationAccess CATOmxCollecManager& CATAdpConfigBinaryManager();
typedef CATOmxOHMap<CATBinary, CATAdpConfigClientValidity, CATAdpConfigBinaryManager, CATOmxDefaultCollecManager<int>::manager > CATAdpConfigComponentValidityMapImpl;
class CATAdpConfigComponentValidityMap : public CATOmxSharable
{
  CATAdpConfigComponentValidityMapImpl _map;
  CATBinary _filterCompiledForm;
public:
  /**
   * Constructor for the validity map.
   * @param iFilterCompiledForm [in] : the filter compiled form for the included effectivities.
   */
  CATAdpConfigComponentValidityMap(const CATBinary & iFilterCompiledForm)
  :_filterCompiledForm(iFilterCompiledForm)
  {
  }

  /**
   * Inserts an effectivity through its binary compiled form
   *
   * @param iEffectivity [in]: the effectivity compiled form
   * @return
   *    TRUE  : if the effectivity wasn't already in the collection
   *    FALSE : if the effectivity was already in the collection
   */
  inline CATBoolean InsertEffectivityToValidate(const CATBinary & iEffectivity)
  {
    return _map.Insert(iEffectivity, cfg_unknown);
  }

  /**
   * Computes the validity of the effectivities with regard to the filter given in the cstor.
   * Note that if the validities have already been computed, they won't be recomputed
   *
   * @return
   *    S_OK : if everyting went smoothly
   *    E_*  : if something went wrong
   */
  HRESULT ComputeValidities();

  /**
   * Retrieves the validity of a given effectivity.
   *
   * @param iEffectivity [in]: the effectivity compiled form
   * @return
   *    cfg_valid     : if the effectivity is valid
   *    cfg_not_valid : if the effectivity is not valid
   *    cfg_unknown   : if the effectivity validity hasn't been computed,  either because
   *                    InsertEffectityToCompute or ComputeValidities has not been called.
   */
  inline CATAdpConfigClientValidity GetEffectivityValidity(const CATBinary & iEffectivity) const
  {
    const CATAdpConfigClientValidity * validity = _map.Locate(iEffectivity);
    if(!validity)
      return cfg_unknown;
    else
      return (CATAdpConfigClientValidity) *validity;
  }
};

//-----------------------------------------------------------------------------
// NB : Comme on mute le contenu de collections en cours d'iteration, on est plus
//      ou moins obliges de faire du boxing sur CATAdpConfigComponentValidityMap.
//      On pourrait s'en sortir sans, mais prix d'algos encore plus complexes.
//-----------------------------------------------------------------------------
typedef CATOmxOHMap<CATBinary, CATAdpConfigComponentValidityMap *, CATAdpConfigBinaryManager, com_manager> CATAdpConfigEffectivityValidityForCompiledFormImpl;
class CATAdpConfigEffectivityValidityForCompiledForm
{
  CATAdpConfigEffectivityValidityForCompiledFormImpl _map;
public:
  /**
   * Adds a new effectivity to compute for the given filter compiledForm
   *
   * @param iFilterCompiledForm [in]: the filter compiled form
   * @param iEffectivityToCompute [in]: the effectivity compiledform
   * @return
   *    TRUE  : the given effectivity wasn't already associated with the given filter
   *    FALSE : the given effectivity was already associated with the given filter
   */
  CATBoolean InsertEffectityToCompute(
      const CATBinary & iFilterCompiledForm,
      const CATBinary & iEffectivityToCompute);

  /**
   * Computes the valitidities of all the given effectivities with regard to their associated filter
   * @return
   *   S_OK if everything went well
   *   E_* if something went wrong
   */
  HRESULT ComputeValidities();

  /**
   * Retrieves the validity of an effectity for a given filter compiledForm
   *
   * @param iFilterCompiledForm [in]: the filter compiled form
   * @param iEffectivityToCompute [in]: the effectivity compiledform
   * @return
   *    cfg_valid     : if the effectivity is valid with regard to the given filter
   *    cfg_not_valid : if the effectivity is not valid with regard to the given filter
   *    cfg_unknown   : if the effectivity validity hasn't been computed,  either because
   *                    InsertEffectityToCompute or ComputeValidities has not been called.
   */
  inline CATAdpConfigClientValidity GetEffectityValidity(
      const CATBinary & iFilterCompiledForm,
      const CATBinary & iEffectivity) const
  {
    CATAdpConfigComponentValidityMap * const * ppMap = _map.Locate(iFilterCompiledForm);
    if (!ppMap)
      return cfg_unknown;
    else
      return (*ppMap)->GetEffectivityValidity(iEffectivity);
  }
};
#endif /* CATADPCONFIGCOMPONENTVALIDITYFORCOMPILEDFORM_H_ */
