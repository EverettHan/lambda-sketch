// COPYRIGHT Dassault Systemes 2008


#ifndef CATIOmbProxySpecifications_H
#define CATIOmbProxySpecifications_H

/**
* @level Protected
* @usage U4 CATOmbProxySpecificationsAdapter
*/
#include "CATBaseUnknown.h"
#include "CATObjectModelerBase.h"
#include "sequence_octet.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbProxySpecifications;
#else
extern "C" const IID IID_CATIOmbProxySpecifications ;
#endif

/**
* Interface representing specifications for proxy creation.
*
* <br><b>Role</b>: To create a @href CATIOmbUniversalLink with proxy services an object of type 
*                  @href CATIOmbProxySpecifications is required. @href CATIOmbProxySpecifications is the object 
*                  describing the subset of the proxyfiable object features the proxy will contain (LIGHT or 
*                  HEAVY for instance). Proxy Specifications are owned and called by proxies (@href CATIOmbProxy). 
* <p>
* Proxy Specifications are marshalled by proxy factories. Each object of type @href CATIOmbProxySpecifications
* can be used by a single type of @href CATIOmbProxy. Then it is able to return the persistent ID of the associated
* Proxy Factory (@href CATIOmbProxyFactory). Persistent IDs are created, assigned and managed by Omb and can be 
* found in CATOmbUniversalLinkFactoryRegisterKey.h
*
* @href CATIOmbProxy, @href CATIOmbProxyFactory, @href CATOmbUniversalLinkResult
*/
class ExportedByCATObjectModelerBase CATIOmbProxySpecifications : public CATBaseUnknown
{

    CATDeclareInterface;


public :

    /** 
    * Returns the ID of the associated Proxy Factory
    *
    * <br><b>Role</b>: Returns the persistent ID of the only Factory (@href CATIOmbProxyFactory) able to 
    *                  create Proxies (@href CATIOmbProxy) of type compatible with the use of this 
    *                  as specifications. 
    *
    *
    * @return
    *   the ID of the associated Proxy Factory.
    *
    */
    virtual int GetFactoryID () const = 0 ; 


   /** 
    * Marshall the Proxy Specifications.
    *
    * <br><b>Role</b>: returns the stream of the Proxy Specifications for marshalling purpose.
    *                  This stream will be interpreted by associated Proxy Factory at unmarshalling.
    *
    * @param oStream [out]
    *   The stream of the Proxy Specifications
    *
    * @return
    *   <code>S_OK</code> if everything ran ok
    *   <code>E_FAIL</code>       otherwise
    *
    */
    virtual HRESULT MarshallProxySpecifications (SEQUENCE (octet) & oStream) const = 0 ; 

} ;

CATDeclareHandler(CATIOmbProxySpecifications, CATBaseUnknown);

#endif
