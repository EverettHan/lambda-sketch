// COPYRIGHT DASSAULT SYSTEMES 2010

#ifndef CATIOmbLinkSynchroStamp_H
#define CATIOmbLinkSynchroStamp_H

/**
* @level Protected
* @usage U1
*/

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbLinkSynchroStamp ;
#else
extern "C" const IID IID_CATIOmbLinkSynchroStamp ;
#endif

class CATOmxAny ;

/** 
* Interface to implement in order to enable for an object link synchronization standard infrastructure mechanisms (IN or OUT orientation).
* Must be used ONLY by infrastructure and for delegation purpose, otherwise must only be implemented.
*/
class ExportedByCATObjectModelerBase CATIOmbLinkSynchroStamp : public CATBaseUnknown
{
    CATDeclareInterface ;

public :

    static const unsigned char SynchroStampVersion_lastest ;
    static const unsigned char SynchroStampVersion_Compatibility ;

    /**
     * Retrieve the object synchronization stamp used by link infrastructure.
     * @param ioVersion [in, out]
     *    Use omx_octet for memory concerns.
     *    If ioVersion is SynchroStampVersion_lastest (omx_octet, == 0) in input, then assign to it latest version and modifed ioVersion for output.
     *    Otherwise (ioVersion != SynchroStampVersion_lastest), DO NOT change ioVersion for output.
     *    If ioVersion is SynchroStampVersion_Compatibility (omx_octet, == 1), then oStamp must contain an integer (compatibility). This must be 
     *      compatible with previous algorithms (@see CATIOmbUpdate#GetUpdateStamp).
     *    If you use a delegation, be careful, it is not because you implement a version N that your callees do.
     *    Expected result (with a complex delegation on N objects sample) :
     *    version 1:
     *      ioVersion         = 1
     *      oLinkSynchroStamp = subObject_1.UpdateStamp + ... + subObject_N.UpdateStamp
     *    version 2:
     *      ioVersion         = [ 2 , subObject_1.Version_X1                   , ... , subObject_N.Version_XN                   ]
     *      oLinkSynchroStamp = [     subObject_1.LinkSynchroStamp(Version_X1) , ... , subObject_N.LinkSynchroStamp(Version_XN) ]
     * @param oStamp [out]
     *    The link synchronization stamp.  
     *    If version 1 (integer, compatibility) is used, the integer must be different from 0.
     *    Otherwise, it must be different from a null UUID.
     * @return
     *    An HRESULT value.
     *    <code>S_OK</code> if everything ran ok (the link synchronization stamp is available).
     *    <code>E_INVALIDARG</code> if input ioVersion is not supported (the link will be consider as not synchronized).
     *    Otherwise associated failure code.
     *    
     */
    virtual HRESULT GetLinkSynchroStamp (CATOmxAny & ioVersion, CATOmxAny & oStamp) = 0 ;

} ;
 
CATDeclareHandler (CATIOmbLinkSynchroStamp, CATBaseUnknown) ;

#endif

