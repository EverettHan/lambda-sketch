#ifndef CATIViewerInitHandler_H
#define CATIViewerInitHandler_H

#include "CATVisItf.h"
#include "CATBaseUnknown.h"

#include "CATSysErrorDef.h"
class CATSupport;
class CATVizViewer;
namespace CSI {
    class Node;
}

extern ExportedByCATVisItf  IID IID_CATIViewerInitHandler;

class ExportedByCATVisItf CATIViewerInitHandler : public CATBaseUnknown
{
    CATDeclareInterface;

public :
    virtual HRESULT UnRegisterScene(CATSupport* iSupport) = 0;
    virtual HRESULT RegisterScene(CATULONG32& ioSceneID, CATSupport* iSupport, CATVizViewer* iVizViewer) = 0;
    virtual HRESULT GetSceneID(CATSupport* iSupport, CATULONG32& ioSceneID) const = 0;
    virtual HRESULT RegisterSpecTree(const CATULONG32& iSceneID, CATBaseUnknown* iSpecTreeRoot) = 0;
    virtual HRESULT GetCIDSupportType(CATSupport* iSupport, int& ioCIDSupportType) const = 0;
    // Internal use only
    virtual HRESULT SetDefaultNode(CSI::Node* iDefaultNode) = 0;
    // To be deprecated kinda ugly, io better at the end
    virtual HRESULT GetSceneID(CATULONG32& ioSceneID, CATSupport* iSupport) const = 0;
};

// Enable handlers
CATDeclareHandler (CATIViewerInitHandler, CATBaseUnknown);

#endif
