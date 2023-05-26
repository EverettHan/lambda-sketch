// COPYRIGHT Dassault Systemes 2012
#ifndef CATGetPLMLoadModeServices_h
#define CATGetPLMLoadModeServices_h

/**
* @level Protected
* @usage U1 
*/

#include "CATPLMModelerRepInterfaces.h"
#include "IUnknown.h"

class PLMIRepresentationsLoadModeServices;


/**
* Provides a pointer to the services singleton.
* @param overloadingServices [out, CATBaseUnknown#Release]
*		The singleton.
*    <br><b>Note</b>: the pointer should be <em>RELEASED</em>.
* @return
*  <ol>
* 	 <li> S_OK	if the singleton is successfully retrieved </li>
* 	 <li> E_FAIL otherwise </li> 
*  </ol>
*/
ExportedByCATPLMModelerRepInterfaces HRESULT CATGetPLMLoadModeServices(PLMIRepresentationsLoadModeServices*& oLoadModeServices);

#endif
