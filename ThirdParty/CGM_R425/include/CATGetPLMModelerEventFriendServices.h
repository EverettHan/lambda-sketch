// COPYRIGHT Dassault Systemes 2008
#ifndef CATGetPLMModelerEventFriendServices_h
#define CATGetPLMModelerEventFriendServices_h

/**
* @level Protected
* @usage U1 
*/

#include "CATPLMModelerBaseInterfaces.h"
#include "IUnknown.h"

class CATIPLMModelerEventFriendServices;


/**
* Provides a pointer to the services singleton.
* @param occServices [out, CATBaseUnknown#Release]
*		The singleton.
*    <br><b>Note</b>: the pointer should be <em>RELEASED</em>.
* @return
*  <ol>
* 	 <li> S_OK	if the singleton is successfully retrieved </li>
* 	 <li> E_FAIL otherwise </li> 
*  </ol>
*/
ExportedByCATPLMModelerBaseInterfaces HRESULT CATGetPLMModelerEventFriendServices(CATIPLMModelerEventFriendServices*& eventServices);

#endif
