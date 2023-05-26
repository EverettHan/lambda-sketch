#ifndef GetRepresentationReferenceFactory_h
#define GetRepresentationReferenceFactory_h

/**
* @level Protected
* @usage U1 
*/

#include "CATPLMModelerRepInterfaces.h"
#include "PLMIRepresentationReferenceFactory.h"

// --- System framework
#include "IUnknown.h"
#include "CATString.h"

/**
 * Retrieves the multi-instantiable representation reference factory, given a macro modeler name.
 *
 *  @param  iMacroModelerName
 *      The macro modeler name. <br>
 *      It can be retrieved using a dedicated service provided by each macro modeler. <br>
 *      Example: For the Logical macro modeler, use CATLogicalMacroModeler::GetMacroModelerName()
 *      Input Parameter.
 *  @param opRepReferenceFactory  [CATBaseUnknown#Release]
 *      The representation reference factory. <br>
 *      Output parameter. <br>
 *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
 *      This parameter is returned to caller as NULL if method fails. <br>
 *      This parameter is valuated if method succeeds.
 *  @param  iIID
 *      The desired interface (PLMIRepresentationReferenceFactory by default). <br>
 *      Input Parameter.
 */
ExportedByCATPLMModelerRepInterfaces HRESULT GetRepresentationReferenceFactory(const CATString iMacroModelerName, void **opRepReferenceFactory, const IID &iIID = IID_PLMIRepresentationReferenceFactory);

#endif
