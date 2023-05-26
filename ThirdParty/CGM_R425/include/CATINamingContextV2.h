// COPYRIGHT DASSAULT SYSTEMES 2012

#ifndef CATINamingContextV2_H
#define CATINamingContextV2_H

/**
* @level Protected
* @usage U4 [CATINamingContextV2Adapter]
*/

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "sequence_octet.h"
#include "CATOmxSR.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATINamingContextV2 ;
#else
extern "C" const IID IID_CATINamingContextV2 ;
#endif

class CATOmxKeyValueBlock ;
class CATILinkableObjectV2 ;


/** 
* Universal link binding protocol.
* Must not be used, just implemented.
* 
* @href CATILinkableObjectV2
*
*/
class ExportedByCATObjectModelerBase CATINamingContextV2 : public CATBaseUnknown
{
    CATDeclareInterface ;

    friend class CATLinkRootBinderBase ;  

private : 

    /**
     * @param iVersion [in]
     *    Parameters that describe the identifier content.
     * @param iIdentifier [in]
     *    The relative identifier of the required object in the current naming context.
     * @param oObject [out]
     *    the required object.  
     * @return
     *    An HRESULT value.
     *    <code>S_OK</code> if everything ran ok, otherwise associated failure code.
     *    <code>E_INVALIDARG</code>  if inconsistent parameters
     *    <code>HR_LINKSOLVE_DataNotLoaded</code>  if naming context is not in session
     *    <code>HR_LINKSOLVE_ObjectDoesNotExist</code>  if naming context cannot be found
     *    <code>HR_LINKSOLVE_MismatchingUUID</code>  if naming context cannot be found (sepecific to container & feature)
     */
    virtual HRESULT RetrieveLinkableObject (const CATOmxKeyValueBlock & iVersion, const SEQUENCE (octet) & iIdentifier, CATOmxSR <CATBaseUnknown> & oObject) = 0 ;

} ;

#endif

