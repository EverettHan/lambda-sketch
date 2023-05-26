/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2006
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATAdpProtectedMaturityServices_H
#define CATAdpProtectedMaturityServices_H

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
class CATIAdpPLMIdentificator;
class CATUnicodeString;
class CATIAdpErrorMonitor;

/**
 * Class of services enabling to manage maturity of components in the database.
 *
 * <br><b>Role</b>: Provides a set of services enabling the user to manage maturity of a component in the database.
 * <ul>
 * <li> To process such operations, you will need a @href CATIAdpPLMIdentificator . You can obtain it by using Query services 
 * before using maturity services (@href CATAdpQueryServices ).</li>  
 * </ul>
 */
class ExportedByCATPLMIntegrationAccess CATAdpProtectedMaturityServices
{
public:

/** 
 * Applies the provided transition to the provided component.
 * <br><b>Role:</b> Makes the maturity of the component evolve in the database by applying the provided transition. 
 * <ul>
 * <li>The database informations are imbedded in the identifier of the object itself.</li>
 * <li><code>ERR_02_MATURITY</code> error is available through @href CATError#CATGetLastError if the provided transition cannot be applied to the component.</li>
 * </ul>
 *
 * @param iComponent [in]
 *   The identifier of the component which maturity is required to evolve.
 * @param iTransition [in]
 *   The transition requested to be applied to the component.
 *   <ul>
 *   <li> To ensure that the transition can be applied, make sure it was obtained through the @href CATAdpMaturityServices#GetStateAndPossibleTransitions.</li> 
 *   <li> Nevertheless, concurrency management could lead to a failure if the component has been modified by other user. Error should be available through @href CATError#CATGetLastError .</li> 
 *   </ul>
	* @param iopErrorMonitor [inout]
	*   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the the maturity transition could successfully be applied to the component in the database.</li>
 *   <li><code>E_INVALIDARG</code> if <tt>iComponent</tt> is invalid.</li>
 *   <li><code>E_FAIL</code> if the operation failed. Nothing was done during the operation. The blocking error can be accessed through @href CATError#CATGetLastError method.</li>
 *   </ul>
 */
  static HRESULT ApplyMaturityTransition( CATIAdpPLMIdentificator * iComponent, const CATUnicodeString & iTransition, CATIAdpErrorMonitor *  iopErrorMonitor = NULL );
};
#endif
