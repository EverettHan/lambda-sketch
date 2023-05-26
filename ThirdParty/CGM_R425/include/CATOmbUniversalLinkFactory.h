#ifndef CATOmbUniversalLinkFactory_h
#define CATOmbUniversalLinkFactory_h
// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIOmbVirtualObject.h
//
//===================================================================
//
// Usage notes:
// Interface to manage persistent linkability in CATIA session.
//
//===================================================================
//
//  Sept 2006  Creation: pbv 
//===================================================================
/**
  * @CAA2Required                   
  */
#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "CATListPtrCATIPLMComponent.h"

class CATIOmbUniversalLink;

/**
* Factory class to create a link intention.
* <br>Role:</b>This class creates a link intention implementing the @href CATIOmbUniversalLink 
* interface and used for valuating external attributes @href CATISpecAttrAccess#SetExternalLink .
* The link intention is created with a target object and optionally its context.
* When the attribute is read through @href CATISpecAttrAccess#GetExternalObject, 
* the result is:
* <ul>
* <li>the target object itself if the link intention was created with only a target object 
*       (first @href CATOmbUniversalLinkFactory#Create method)</li>
* <li>a virtual object ( implementing @href CATIOmbVirtualObject ) if the link intention was created with a target and its context
*       (second @href CATOmbUniversalLinkFactory#Create method)</li>
* </ul>
* <br>Refer to Object Modeler technical article for more information.
*/
class ExportedByCATObjectModelerBase CATOmbUniversalLinkFactory
{
public: 

    /**
     * Creates an Universal Link for an object.
     * @param iTarget
     *    The target to be pointed.
     * @param oUniversalLink [out, CATBaseUnknown#Release]
     *    The build universal link.
     * @return
     *    <ul><li>S_OK if oUniversalLink has been successfully instanciated.</li>
     *        <li>E_FAIL otherwise.</li>
     *    </ul>
     */
	static HRESULT Create(CATBaseUnknown& iTarget, CATIOmbUniversalLink*& oUniversalLink);

    /**
     * Creates an Universal Link for an object and its contextual path.
     * @param iInstances
     *    The path of first instances describing the context of the target object (optional).
     * @param iRepInstance
     *    The instance of the representation containing the target object (optional).
     * @param iTarget
     *    The target object (optional).
     * @param oUniversalLink [out, CATBaseUnknown#Release]
     *    The build universal link.
     * @return
     *    <ul><li>S_OK if oUniversalLink has been successfully created.</li>
     *        <li>E_INVALIDARG if iInstances, iRepInstance and iTarget are all not valuated</li>
     *        <li>E_FAIL otherwise.</li>
     *    </ul>
     */
	static HRESULT Create(const CATLISTP(CATIPLMComponent)& iInstances, CATIPLMComponent * iRepInstance,
                        CATBaseUnknown* iTarget, CATIOmbUniversalLink *& oUniversalLink);
};


#endif


