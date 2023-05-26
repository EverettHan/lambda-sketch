// COPYRIGHT Dassault Systemes 2008


#ifndef CATIOmbProxyFactory_H
#define CATIOmbProxyFactory_H

/**
* @level Protected
* @usage U4 CATOmbProxyFactoryAdapter
*/
#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "sequence_octet.h"

class CATIOmbProxySpecifications;
class CATIOmbProxySpecifications_var ;
class CATIOmbProxy_var ;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbProxyFactory;
#else
extern "C" const IID IID_CATIOmbProxyFactory ;
#endif



/**
* Interface representing Proxy factories.
*
* <br><b>Role</b>: Implement this interface if you want to create a Proxy Factory.
* CATIOmbFunctionCallFactory are applicative objects able to create and unmarshal proxies.
* Before implementing this interface you must ask a persistent ID to Omb.
* Persistent Ids are registered in CATOmbUniversalLinkFactoryRegisterKey.h
* Proxy factories are instanciated and called only by Omb when creating CATOmbUniversalLinkResult.
* <p>
*
* @href CATIOmbProxySpecifications, CATIOmbProxy, CATOmbUniversalLinkResult
*/
class ExportedByCATObjectModelerBase CATIOmbProxyFactory : public CATBaseUnknown
{
    CATDeclareInterface;

public :

    /** 
    * Creates a proxy
    *
    * <br><b>Role</b>: Creates a proxy from a @href CATIOmbProxySpecifications and a proxyfiable object.
    *
    * @param iProxyfiableObject [in]
    *   Object to proxify
    * @param iSpecifications [in]
    *    Specifications giving information about the proxy to create.
    * @param opiProxy [out]
    *   The created proxy
    *
    * @return
    *   <code>S_OK</code>         if everything ran ok
    *   <code>E_INVALIDARG</code> if iData is not compatible with iSpecifications (cannot be proxified)
    *   <code>E_FAIL</code>       otherwise
    *
    */
    virtual HRESULT CreateProxy (CATBaseUnknown * iProxyfiableObject, CATIOmbProxySpecifications * iSpecifications, 
            CATIOmbProxy_var& opiProxy) = 0 ;
    

    /** 
    * Creates a proxy at unmarshalling.
    *
    * <br><b>Role</b>: Creates a proxy from specifications and an unmarshalled stream. @see CATIOmbProxy::GetProxyStream
    *                  for marshalling operations. 
    *
    * @param iSpecifications [in]
    *   The specifications of the proxy to create.
    * @param iProxyStream [in]
    *   The unmarshalled stream of the proxyfied data: a proxy holds a subset of the proxyfied object features.
    *   iProxyStream is the unmarsalled stream of this subset.
    * @param opiProxy [out]
    *   The created proxy.
    *
    * @return
    *   <code>S_OK</code>         if everything ran ok
    *   <code>E_INVALIDARG</code> if stream or specifications are not recognized.
    *   <code>E_FAIL</code>       otherwise
    *
    */
    virtual HRESULT UnmarshallProxy (CATIOmbProxySpecifications * iSpecifications, SEQUENCE (octet) & iProxyStream, 
            CATIOmbProxy_var& opiProxy) = 0 ;


    /** 
    * Creates a proxy specifications at unmarshalling.
    *
    * <br><b>Role</b>: Creates a proxy specifications from one unmarshalled stream. @see CATIOmbProxySpecifications::GetSpecificationsStream
    * for marshalling operations. 
    *
    * @param iSpecificationsStream [in]
    *   The unmarshalled stream of the Proxy Specifications
    * @param oSpecifications [out]
    *   The created proxy specifications.
    *
    * @return
    *   <code>S_OK</code>         if everything ran ok
    *   <code>E_INVALIDARG</code> if stream is not recognized.
    *   <code>E_FAIL</code>       otherwise
    *
    */
    virtual HRESULT UnmarshallProxySpecifications (SEQUENCE (octet) & iSpecificationsStream, CATIOmbProxySpecifications_var &oSpecifications) = 0 ;
} ;

CATDeclareHandler(CATIOmbProxyFactory, CATBaseUnknown);

#endif
