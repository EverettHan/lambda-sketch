#ifndef CATPLMServicesForECA_H
#define CATPLMServicesForECA_H

/**
* @level Protected
* @usage U1
*/
#include "CATPLMIdentificationAccess.h"
#include "CATListPtrCATPLMECAErrors.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATPLMID.h"
#include "CATListOfCATBoolean.h" 

class CATLISTP(CATIPLMComponent);
class CATPLMID;

class ExportedByCATPLMIdentificationAccess CATPLMServicesForECA
{
public:
  /**
  * Retrieves the change actions for a set of components
  *
  * @param ipListObj [in]
  * a set of components
  * @param iECAId [in]
  * the change action
  * @param iPropagateToSubStructure [in]
  * if TRUE the propagate recursively  the change action to the aggregated components.
  * @param opListFailedObj [out]
  * the change action cannot be associated to these components
  * @param opListOfECAErrors [out]
  * Erros for each components in the previous parameter opListFailedObj
  * @return
  * <dt> <code>S_OK</code>         <dd> Success
  * <dt> <code>E_FAIL</code>       <dd> Failure
  */
  static HRESULT AssociateECAToObjectInLog(const CATLISTP(CATIPLMComponent) & ipListObj,
    const CATPLMID &iECAId,
    const CATBoolean iPropagateToSubStructure,
    CATLISTP(CATIPLMComponent) & opListFailedObj,
    CATListOfCATPLMECAErrors  & opListOfECAErrors);

  /**
  * Retrieves the change actions for a set of components
  *
  * @param ipObj [in]
  * a set of components
  * @param oListECA [out]
  * the set of change actions
  * @param oListIsModifiable [out]
  * the dirty status for the components
  * @return
  * <dt> <code>S_OK</code>         <dd> Success
  * <dt> <code>E_FAIL</code>       <dd> Failure
  */
  static HRESULT GetAssociatedECAInLog(const CATLISTP(CATIPLMComponent) & ipObj,
    CATPLMIDs & oListECA,
    CATListOfCATBoolean & oListIsModifiable);

  /*
  * Reset the change action for the given components.

  * @param ipListObj [in]
  * The change action will be removed fot this set of components.
  * @param iPropagateToSubStructure [in]
  * if TRUE the propagate recursively  the change action to the aggregated components.
  */
  static HRESULT ResetChangeAction(const CATLISTP(CATIPLMComponent) & ipListObj, const CATBoolean iPropagateToSubStructure = FALSE);

};

#endif
