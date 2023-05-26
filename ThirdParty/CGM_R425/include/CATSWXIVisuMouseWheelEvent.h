//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2012/10/09
//===================================================================
// CATSWXIVisuMouseWheelEvent.cpp
// Header definition of class CATSWXIVisuMouseWheelEvent
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/10/09 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATSWXIVisuMouseWheelEvent_H
#define CATSWXIVisuMouseWheelEvent_H

#include "CATVisFoundation.h"
#include "CATBaseUnknown.h"
#include "CATEventSubscriberTypedefs.h"

class CATNotification;

extern ExportedByCATVisFoundation  IID IID_CATSWXIVisuMouseWheelEvent ;

class ExportedByCATVisFoundation CATSWXIVisuMouseWheelEvent: public CATBaseUnknown
{
    CATDeclareInterface;

public:
    virtual void MousePress(void*,CATNotification *iEvent,CATSubscriberData is, CATCallback icb) = 0;
    virtual bool NeedSpecialWheelHandler(void*,CATNotification *iEvent,CATSubscriberData is, CATCallback icb) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATSWXIVisuMouseWheelEvent, CATBaseUnknown );

#endif