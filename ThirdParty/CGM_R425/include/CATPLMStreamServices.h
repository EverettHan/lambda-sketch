// COPYRIGHT Dassault Systemes 2012
//===================================================================

/**
* @level Protected
* @usage U1  
*/
#ifndef CATPLMStreamServices_H
#define CATPLMStreamServices_H

#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"
#include "CATIPLMComponent.h"


class ExportedByCATPLMIdentificationAccess CATPLMStreamServices
{
public:
  
  /**
  * Set a component as eligible for a V_Description streaming 
  *
  * @param iComponent [int]
  *   the component
  *
  * @return
  *   S_OK if successful
  *   E_FAIL if failure
  */
  static HRESULT SetComponentVDescriptionStreamingEligibility(const CATIPLMComponent_var & iComponent);

    
};

//------------------------------------------------------------------

#endif
