#ifndef CATVisNextDeferredDrawEvent_H
#define CATVisNextDeferredDrawEvent_H

#include "CATTimeStampedEvent.h"
#include "CATVisFoundation.h"

class ExportedByCATVisFoundation CATVisNextDeferredDrawEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

public :
    CATVisNextDeferredDrawEvent();
    virtual ~CATVisNextDeferredDrawEvent();
};

#endif
