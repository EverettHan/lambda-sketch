// COPYRIGHT DASSAULT SYSTEMES 2012

#ifndef CATINamingContextV2Adapter_H
#define CATINamingContextV2Adapter_H

/**
* @level Protected
* @usage U2
*/

#include "CATObjectModelerBase.h"
#include "CATINamingContextV2.h"

/** 
 * Adapter for CATINamingContextV2.
 */

class ExportedByCATObjectModelerBase CATINamingContextV2Adapter : public CATINamingContextV2
{
private : 

    /**
     *  @href CATINamingContextV2
     */
    virtual HRESULT RetrieveLinkableObject (const CATOmxKeyValueBlock & iVersion, const SEQUENCE (octet) & iIdentifier, CATOmxSR <CATBaseUnknown> & oObject) ;

} ;

#endif

