// COPYRIGHT Dassault Systemes 2008


#ifndef CATIOleImportLinkAnalysis_H
#define CATIOleImportLinkAnalysis_H

/**
* @level Protected
* @usage U3 
*/


#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"

class CATIDocId ;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOleImportLinkAnalysis ;
#else
extern "C" const IID IID_CATIOleImportLinkAnalysis ;
#endif


/**
* @nodoc
*/
class ExportedByCATObjectModelerBase CATIOleImportLinkAnalysis : public CATBaseUnknown
{
    CATDeclareInterface ;

public : 

    enum CATOleLinkStatus { NotIsolable, Isolable, AlwaysIsolable, Useless } ;

    /** @nodoc */
    virtual HRESULT GetOleLinkStatus (CATIDocId * ipiPointedDocId, CATOleLinkStatus & oStatus) = 0 ;
} ;

#endif
