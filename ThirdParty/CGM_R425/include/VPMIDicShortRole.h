//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef VPMIDicShortRole_h
#define VPMIDicShortRole_h

#include "VPMIDicInterfaces.h"

#include "VPMIDicComment.h"

class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicShortRole;
#else
extern "C" const IID IID_VPMIDicShortRole;
#endif

/**
 * Interface to manage the ShortRole.
 */

class  ExportedByVPMIDicInterfaces VPMIDicShortRole: public VPMIDicComment
{
    CATDeclareInterface;

public:
//    virtual HRESULT GetFreeText   ( CATUnicodeString * ioText ) = 0;
//    virtual HRESULT SetFreeText   ( const CATUnicodeString *iText ) = 0;
};
#endif
