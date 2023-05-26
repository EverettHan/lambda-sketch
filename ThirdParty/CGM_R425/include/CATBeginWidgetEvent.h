#ifndef CATBeginWidgetEvent_H
#define CATBeginWidgetEvent_H

// COPYRIGHT DASSAULT SYSTEMES 2011

#include "CATVisFoundation.h"
#include "CATTimeStampedEvent.h"
class CATDevice;
class CATSupport;

class ExportedByCATVisFoundation CATBeginWidgetEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

public:

  CATBeginWidgetEvent();

  virtual ~CATBeginWidgetEvent();

  CATDevice* Device;

  CATSupport *pSupport;
};
#endif
