#ifndef CATViz3DWebViewer_H
#define CATViz3DWebViewer_H

#include "CATVisFoundation.h"
#include "CATViz3DViewer.h"
#include "CATString.h"
#include "CATSysWidget.h"

ExportedByCATVisFoundation CATVizViewer * CATGetWebViewerByName(CATString name);

class ExportedByCATVisFoundation CATViz3DWebViewer : public CATViz3DViewer
{
    CATDeclareClass;
public:
    CATViz3DWebViewer(const CATString & iName,
        const int iWidth= 800,
        const int iHeight= 500,
        const CATViewerStyle iViewerStyle=NULL);
    
    virtual ~CATViz3DWebViewer();
    
    virtual void Create(CATSysWidget parent);
    
protected:
    
    virtual void InterpretDeviceEvent( CATCallbackEvent, void *, CATNotification *Event, CATSubscriberData, CATCallback);
    virtual void InterpretKeybdEvent( CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);
   
    CATCallback _DeviceInterpretationCB;
    CATCallback _KeybdCB;
    
};

#endif
