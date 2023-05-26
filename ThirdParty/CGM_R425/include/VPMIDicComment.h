//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef VPMIDicComment_h
#define VPMIDicComment_h

#include "VPMIDicInterfaces.h"

#include "VPMIDicElement.h"

class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicComment;
#else
extern "C" const IID IID_VPMIDicComment;
#endif

class  ExportedByVPMIDicInterfaces VPMIDicComment: public VPMIDicElement
{
    CATDeclareInterface;

    public:
        /**
        * Get the free text of the Comment.
        * @param oText
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetFreeText   ( CATUnicodeString * oText ) = 0;


        /**
        * Set the free text of the Comment.
        * @param iText
        * @return S_OK, E_FAIL
        */
        virtual HRESULT SetFreeText   ( const CATUnicodeString *iText ) = 0;
};
#endif
