//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef VPMIDicRole_h
#define VPMIDicRole_h

#include "VPMIDicInterfaces.h"

#include "VPMIDicComment.h"

class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicRole;
#else
extern "C" const IID IID_VPMIDicRole;
#endif

/**
 * Interface to manage the Role.
 */

class  ExportedByVPMIDicInterfaces VPMIDicRole: public VPMIDicComment
{
    CATDeclareInterface;

public:
//    virtual HRESULT GetFreeText   ( CATUnicodeString * ioText ) = 0;
//    virtual HRESULT SetFreeText   ( const CATUnicodeString *iText ) = 0;
};
#endif
