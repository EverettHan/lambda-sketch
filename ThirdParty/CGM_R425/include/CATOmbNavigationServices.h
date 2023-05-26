// COPYRIGHT Dassault Systemes 2007


#ifndef CATOmbNavigationServices_H
#define CATOmbNavigationServices_H

/**
* @level Protected
* @usage U1
*/
#include "CATOmbLinkNavigationAccess.h"
#include "IUnknown.h"

class CATBaseUnknown ;
class CATIPLMComponent ;


/**
* Static class providing service to navigate between objects.
*/
class ExportedByCATOmbLinkNavigationAccess CATOmbNavigationServices
{
public : 

    /** 
    * Get the PLM component that contain a given object.
    * @param ipiObject [in]
    *   The object.
    * @param opiComponent [out, CATBaseUnknown#Release]
    *   The PLM component that contain the given object.
    * @return
    *   <code>S_OK</code> if everything ran ok.
    *   <code>E_INVALIDARG</code> if ipiObject is <code>NULL</code>. 
    *   <code>E_NOTIMPL</code> if the given object is not supported by this service.
    *   <code>E_FAIL</code> if the given object do not belong to a PLM component.  
    */
    static HRESULT GetComponent (CATBaseUnknown * ipiObject, CATIPLMComponent *& opiComponent) ;
} ;

#endif
