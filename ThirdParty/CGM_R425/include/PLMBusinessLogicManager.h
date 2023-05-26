/* COPYRIGHT DASSAULT SYSTEMES 2007
===================================================================

===================================================================
Apr 07. Creation                                              DOV
===================================================================*/

#ifndef PLMBusinessLogicManager_H
#define PLMBusinessLogicManager_H

/**
* @level Protected
* @usage U1
*/

// Export
#include "PLMBusinessLogicInterfaces.h"

// System
#include "CATBaseUnknown.h"

// PLMBusinessLogicInterfaces
#include "PLMBusinessLogicAccessId.h"

class PLMIBusinessLogicServices;
class PLMIBusinessLogicRestrictedServices;
class PLMIBusinessLogicProtectedServices;


/**
* Manager that provides handles on business logic access interfaces.
*/
class ExportedByPLMBusinessLogicInterfaces PLMBusinessLogicManager
{

public:

    /**
    * Factory method to retrieve a business logic access interface handle.
    *
    * @param opiBusinessLogicAccess [out, CATBaseUnknown#Release]
    *   The business logic access interface pointer
    *
    * @return
    *   <ul>
    *       <li> S_OK       if successful </li>
    *       <li> E_FAIL     if an error occurs. It is most likely due to one of the reasons hereafter:
    *           <ul>
    *               <li>    The input iID is not a valid business logic access identifier </li>
    *               <li>    The requested business logic access does not implement interface identified with the input iIID </li>
    *           </ul>
    *       </li>
    *   </ul>
    */
    static HRESULT GetBusinessLogicAccess(PLMBusinessLogicAccessId::AccessId iID, const IID & iIID, CATBaseUnknown *& opiBusinessLogicAccess);

    /**
    * Factory method to retrieve a business logic services interface handle.
    *
    * @param opiBusinessLogicServices [out, CATBaseUnknown#Release]
    *   The business logic services interface pointer
    *
    * @return
    *   <ul>
    *       <li> S_OK       if successful </li>
    *       <li> E_FAIL     if an error occurs. </li>
    *   </ul>
    */
    static HRESULT GetBusinessLogicServices(PLMIBusinessLogicServices *& opiBusinessLogicServices);

    /**
    * Factory method to retrieve a business logic restricted services interface handle.
    *
    * @param opiBusinessLogicRestrictedServices [out, CATBaseUnknown#Release]
    *   The business logic restricted services interface pointer
    *
    * @return
    *   <ul>
    *       <li> S_OK       if successful </li>
    *       <li> E_FAIL     if an error occurs. </li>
    *   </ul>
    */
    static HRESULT GetBusinessLogicRestrictedServices(PLMIBusinessLogicRestrictedServices *& opiBusinessLogicRestrictedServices);

    /**
    * Factory method to retrieve a business logic protected services interface handle.
    *
    * @param opiBusinessLogicProtectedServices [out, CATBaseUnknown#Release]
    *   The business logic protected services interface pointer
    *
    * @return
    *   <ul>
    *       <li> S_OK       if successful </li>
    *       <li> E_FAIL     if an error occurs. </li>
    *   </ul>
    */
    static HRESULT GetBusinessLogicProtectedServices(PLMIBusinessLogicProtectedServices *& opiBusinessLogicProtectedServices);

private:

    // Static Construction
    static PLMBusinessLogicManager _PLMBusinessLogicManager;

    PLMBusinessLogicManager();
    ~PLMBusinessLogicManager();

    PLMBusinessLogicManager(PLMBusinessLogicManager &);
    PLMBusinessLogicManager & operator=(PLMBusinessLogicManager &);

};

#endif
