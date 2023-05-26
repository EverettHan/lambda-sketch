/**
* @level Protected
* @usage U4 CATOmbProxyAdapter
*/

// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
//  Oct 2006  Creation: Code generated by the CAA wizard  juz
//===================================================================
#ifndef CATIOmbProxy_H
#define CATIOmbProxy_H

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "sequence_octet.h"


#include "CATOmbTimeStamp.h"
class CATStreamDefinition;
class CATOmbProxyEvent;
class CATIOmbProxy_var;
class CATIOmbFunction;
class CATIOmbProxySpecifications;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbProxy;
#else
extern "C" const IID IID_CATIOmbProxy ;
#endif

/**
* Interface dedicated to Proxy infrastructure.
* To be implemented by Pointed Modeler who wish provide Proxy linking capabilities.
* Used by Link Infrastructure to achieve persistency mechanisms
* @see CATIOmbProxySpecifications
*/
/**
* Interface representing Proxies.
*
* <br><b>Role</b>: A proxy is an object implementing a subset of a pointed object behaviors. 
* <p>
* If the services asked by the pointing application are implemented on the proxy it enables to avoid the loading 
* of the pointed object. Pointed modelers can implement a proxy for performance increase if they are able to 
* define a subset of services their pointing applications are the most interested in.
* 
* Proxies are created and managed by Omb (via applicative Proxy Factories). If you implement CATIOmbProxy
* do not forget to create the associated factory (implement @href CATIOmbProxyFactory).
*
* @href CATOmbUniversalLinkResult, @href CATIOmbProxySpecifications, @href CATIOmbProxyFactory
*/
class ExportedByCATObjectModelerBase CATIOmbProxy : public CATBaseUnknown
{
    CATDeclareInterface;

public:

    /** 
    * Creates a copy of this.
    *
    * <br><b>Role</b>: Universal Link Results are not shared objects. Each Universal Link Result owns at most one 
    *                  Proxy. Proxies are applicative objects but CANNOT be shared. To copy a Universal Link Result
    *                  Omb needs to ask for the copy of its Proxy. The result of the copy of a Proxy will
    *                  always be a new proxy object (it will never be the Proxy itself))
    *                  This and the returned copy must be identical.
    *
    * @param oProxy [out]
    *   The copy of this
    *
    * @return
    *   <code>S_OK</code> if everything ran ok
    *   <code>E_FAIL</code>       otherwise
    *
    */
    virtual HRESULT Copy(CATIOmbProxy_var &oProxy) = 0;


    /** 
    * Marshall the subset of the proxyfied object features used by proxy. 
    *
    * <br><b>Role</b>: A proxy is an object implementing a subset of a pointed object behaviors. 
    *                  Returns the stream of these behaviors features for marshalling purpose.
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
    virtual HRESULT MarshallProxy (SEQUENCE (octet) & oStream) const = 0 ;


    /** 
    * Returns the persistent ID of the associated Proxy Factory. 
    *
    * <br><b>Role</b>: Each proxy is associated to exactly one factory. Each Factory has its 
    *                  persistent ID. Persistent IDs are registered by Omb in 
    *                  CATOmbUniversalLinkFactoryRegisterKey.h. Proxies are able to return their 
    *                  associated Proxy Factory IDs for marshalling purpose.
    * @return
    *   the persistent ID of the associated Proxy Factory
    */
    virtual int GetFactoryID () const = 0 ; 

    
    /** 
    * Returns the proxy value.
    *
    * <br><b>Role</b>: Returns the proxy value containing information useful for pointing entity.
    *
    * @param iFunction [in]
    *   A function specified by the pointing entity that may help the proxy to select the value it will return.
    *   Can be NULL.
    * @param oValue [out]
    *   The value to return.
    *
    * @return
    *   <code>S_OK</code> if everything ran ok, otherwise...
    *
    */
    virtual HRESULT GetProxyValue ( CATIOmbFunction *iFunction, CATBaseUnknown_var &oValue ) = 0;
	// Old deprecated methods ....
    // ////////////////////////////
    /** 
    * Returns the proxy value.
    *
    * <br><b>Role</b>: Returns the proxy value containing information useful for pointing entity.
    *
    * @param iFunction [in]
    *   A function specified by the pointing entity that may help the proxy to select the value it will return.
    *   Can be NULL.
    * @param oValue [out]
    *   The value to return.
    *
    * @return
    *   <code>S_OK</code> if everything ran ok, otherwise...
    *
    */
    virtual HRESULT GetProxyValue ( CATIOmbFunction *iFunction,CATIOmbProxySpecifications * iProxySpecs, CATBaseUnknown_var &oValue ) = 0;
    

    /**
    * @deprecated R206 NoReplacement
    *
    * Loading management.
    * <b>Role</b>:<br>
    * When the selective loading of a rep ref changes, delegates are informed thanks to this interface and method.
    * @param iEvent [in]
    *   The event.
    * @return
    *   E_FAIL if problem.
    */
    virtual HRESULT OnEvent (const CATOmbProxyEvent& iEvent) = 0;

    /**
    * @deprecated R206 GetSpecificationsStream, GetProxyStream 
    *
    * Proxy management.
    * <b>Role</b>:<br>
    * Used for getting the stream of a proxy on a proxyfied delegate.
    * @param oStream [out]
    *   The proxy stream.
    * @param oTS [out]
    *   The proxy time stamp.
    * @return
    *   E_FAIL if problem.
    */
    virtual HRESULT GetProxyStream ( CATStreamDefinition& oStream, CATOmbTimeStamp& oTS ) = 0;

};

CATDeclareHandler(CATIOmbProxy, CATBaseUnknown);


#endif
