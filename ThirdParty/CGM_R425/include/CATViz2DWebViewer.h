#ifndef CATViz2DWebViewer_H
#define CATViz2DWebViewer_H

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATVisFoundation.h"
#include "CATViz2DViewer.h"
#include "CATString.h"
#include "CATSysWidget.h"
#include "CATSysWidgetEx.h"

class CAT2DViewpointEditor;

class ExportedByCATVisFoundation CATViz2DWebViewer : public CATViz2DViewer
{
    CATDeclareClass;
public:

  CATDeclareCBEvent (NAVIGATION_VIEWPOINT_ACTION_ENDED);

    CATViz2DWebViewer(const CATString & iName,
        const int iWidth= 800,
        const int iHeight= 500,
        const CATViewerStyle iViewerStyle=NULL);
    
    virtual ~CATViz2DWebViewer();
    
    enum ViewpointManipulationType { NoViewpointManipulation, Translate, Zoom, ZoomArea};
    /** @nodoc */
    virtual void SetViewpointManipulation( const ViewpointManipulationType Type);
    
    // @deprecated R425 Use CreateEx
    virtual void Create(CATSysWidget parent);

    virtual void Create(const CATSysWidgetEx& parent);
    
protected:
    
    virtual void InterpretDeviceEvent( CATCallbackEvent, void *, CATNotification *Event, CATSubscriberData, CATCallback);
    virtual void InterpretKeybdEvent( CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);
    virtual void EndManipulate( CATCommand *Command, CATNotification *Notification, CATCommandClientData Data);
    
    /** @nodoc */
    CAT2DViewpointEditor *_ManipulatedViewpointEditor;
    /** @nodoc */
    CAT2DViewpointEditor *_default2DViewpointEditor;
    
    /** @nodoc */
    CATIndicator *_ViewpointIndicator;
    /** @nodoc */
    CATIndicator *_LastIndicator;
    
    CATCallback _DeviceInterpretationCB;
    CATCallback _KeybdCB;
};

#endif
