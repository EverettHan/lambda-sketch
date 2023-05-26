// COPYRIGHT DASSAULT SYSTEMES 2010

#ifndef CATILinkableObjectV2_H
#define CATILinkableObjectV2_H

/**
* @level Protected
* @usage U4 [CATILinkableObjectV2Adapter]
*/

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "sequence_octet.h"
#include "CATINamingContext.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATILinkableObjectV2 ;
#else
extern "C" const IID IID_CATILinkableObjectV2 ;
#endif

class CATOmxKeyValueBlock ;

/** 
* Interface to implement in order to make an object linkable for standard infrastructure mechanisms.
* Must not be used, just implemented.
*/
class ExportedByCATObjectModelerBase CATILinkableObjectV2 : public CATBaseUnknown
{
    CATDeclareInterface ;

    friend class CATLinkPrivateServices ;

protected :

    /**
     * Return struct for GetIdentifier method. 
     */
    struct GetIdentifier_Result
    {
        void Reset ()
        {
            namingContext = NULL_var ;
            identifier = (octet) NULL ;
        } ;

        /*    
        * The context object from which the identifier can be solved in case of a relative identification,
        * or NULL in case of an absolute identification.
        */
        CATBaseUnknown_var namingContext ;

        /*
         * The object identifier (can be solved from oNaminingContext in the cas of a relative identification). 
         */
        SEQUENCE (octet) identifier ;
    } ;

private :

    /**
     * Retrieve the object persistent absolute or relative (in the scope of a given NamingContext) identifier.
     * @param iVersion [in]
     *    Parameters that describe the requirements of the identifier,
     *    such as V5, V6... If (iVersion.Size() == 0), there is no specific
     *    requirement, the current/default identifier is returned.
     * @param oResult [out]
     *    See below.  
     * @return
     *    An HRESULT value.
     *    <code>S_OK</code> if everything ran ok, otherwise associated failure code.
     *    
     */
    virtual HRESULT GetIdentifier (const CATOmxKeyValueBlock & iVersion, GetIdentifier_Result & oResult) = 0 ;

} ;

CATDeclareHandler (CATILinkableObjectV2, CATBaseUnknown) ;

#endif

