#ifndef CATPLMProtectedTypeServices_H
#define CATPLMProtectedTypeServices_H
// COPYRIGHT DASSAULT SYSTEMES 2007

/**
* @level Private
* @usage U1
*/

#include "CATPLMServicesLimitedAccess.h"


#include "CATString.h"
#include "CATError.h"

/**
 * TOOLBOX for special Type API access
 * @nodoc
 */
class ExportedByCATPLMServicesLimitedAccess CATPLMProtectedTypeServices
{
public:
/**
 * Try to find a typename based on the triplette Custo/Modeler/Core.
 * The custo can be empty, but Modeler and core can't.
 * If not found and a custo was given try to return the modeler type
 * PCS info : no internal hash is created in this method. If PCS is needed caller should create an internal table.
 * @output 
 *   S_OK : Type was found
 *   S_FALSE : Type was not found but the modeler type was found and returned.
 *             Futur (?) : a mapping was found and used to return a type. Not implemented yet
 *   E_INVALIDARG : iCoreName or iModelerName was empty
 *   E_FAIL : No type was found
 * @nodoc
 */
  static HRESULT FindTypeNameFromTriplette ( const CATString &iCustoName, const CATString &iModelerName, const CATString &iCoreName
                                     , CATString &oTypeName);
};

#endif
