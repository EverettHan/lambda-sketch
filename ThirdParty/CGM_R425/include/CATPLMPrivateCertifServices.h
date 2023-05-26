//
// COPYRIGHT Dassault Systemes 2007
//

/**
* @level Private
* @usage U1
*/

#ifndef CATPLMPrivateCertifServices_H
#define CATPLMPrivateCertifServices_H


#include "CATPLMCertifServicesLimitedAccess.h"
#include "IUnknown.h"

/**
 * RESTRICTED TOOLBOX
 * @nodoc
 */

class ExportedByCATPLMCertifServicesLimitedAccess CATPLMPrivateCertifServices
{
	public:

	/** 
	* No Doc.
	*/
	static HRESULT CertifSwitchTestCleanUp ();
};


#endif
