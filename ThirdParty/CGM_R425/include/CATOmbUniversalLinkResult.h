// COPYRIGHT Dassault Systemes 2009

/**
 * @level Protected
 * @usage U1
 **/

#ifndef CATOmbUniversalLinkResult_H
#define CATOmbUniversalLinkResult_H

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"


class ExportedByCATObjectModelerBase CATOmbUniversalLinkResult : public CATBaseUnknown 
{

public :

    /** 
     * Retrieves the pointed object. Never returns a proxy.
     *
     * <br><b>Role</b>: Always retrieves the statically or dynamically pointed object. Never returns proxy.
     *
     * @param oRealTarget [out]
     *   the pointed object
     */
    virtual HRESULT GetRealResultTarget (CATBaseUnknown_var & oRealTarget) const = 0 ;

    virtual ~CATOmbUniversalLinkResult () {} ;

protected :

    CATOmbUniversalLinkResult () {} ;
    CATOmbUniversalLinkResult (const CATOmbUniversalLinkResult &) {} ;

};

#endif

