#ifndef CATIOOCAnimation_H
#define CATIOOCAnimation_H


#include "CATBaseUnknown.h"
#include "CATVisItf.h"

class CATViewer;
class CAT3DRep;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIOOCAnimation;
#else
extern "C" const IID IID_CATIOOCAnimation;
#endif

#include "DSYSysMainThreadMsgQ.h"
class OOCPointCloudVisitMsg : public DSYSysMainThreadMsgQ::Message
{
public:

    static DSYSysSharedPtr<OOCPointCloudVisitMsg> Create()
    {
        OOCPointCloudVisitMsg *msg = new OOCPointCloudVisitMsg();
        DSYSysSharedPtr<OOCPointCloudVisitMsg> spMsg( msg );
        msg->Release();
        spMsg->Message::SetType( "OOCPointCloudVisitMsg" );

        return spMsg;
    }

private:

    OOCPointCloudVisitMsg() {}
};

class OOCPointCloudTraverseMsg : public DSYSysMainThreadMsgQ::Message
{
public:

    static DSYSysSharedPtr<OOCPointCloudTraverseMsg> Create()
    {
        OOCPointCloudTraverseMsg *msg = new OOCPointCloudTraverseMsg();
        DSYSysSharedPtr<OOCPointCloudTraverseMsg> spMsg( msg );
        msg->Release();
        spMsg->Message::SetType( "OOCPointCloudTraverseMsg" );

        return spMsg;
    }

private:

    OOCPointCloudTraverseMsg() {}
};


class ExportedByCATVisItf CATIOOCAnimation : public CATBaseUnknown
{
    CATDeclareInterface;

public:

    virtual bool Create( CATViewer* ipViewer, CAT3DRep* iRep ) = 0;

    virtual bool SetViewer( CATViewer* ipViewer ) = 0;

};


CATDeclareHandler( CATIOOCAnimation, CATBaseUnknown );

#endif
