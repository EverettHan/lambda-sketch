//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef VPMIDicCAAComment_h
#define VPMIDicCAAComment_h

#include "VPMIDicComment.h"
#include "VPMIDicInterfaces.h"

class VPMIDicRole;
class VPMIDicShortRole;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicCAAComment;
#else
extern "C" const IID IID_VPMIDicCAAComment;
#endif

class  ExportedByVPMIDicInterfaces VPMIDicCAAComment: public VPMIDicComment
{
    CATDeclareInterface;

public:
//    virtual HRESULT GetFreeText   ( CATUnicodeString * ioText ) = 0;
//    virtual HRESULT SetFreeText   ( const CATUnicodeString *iText ) = 0;

        /**
        * @nodoc
        * @param oDicRole [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT CreateRole      ( VPMIDicRole ** oDicRole ) = 0;

        /**
        * @nodoc
        * @param oDicRole [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetRole         ( VPMIDicRole ** oDicRole ) = 0;

        /**
        * @nodoc
        * @param oDicShortRole [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT CreateShortRole ( VPMIDicShortRole ** oDicShortRole ) = 0;

        /**
        * @nodoc
        * @param oDicShortRole [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetShortRole    ( VPMIDicShortRole ** oDicShortRole ) = 0;


};
#endif
