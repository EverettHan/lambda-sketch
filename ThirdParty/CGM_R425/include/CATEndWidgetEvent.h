#ifndef CATEndWidgetEvent_H
#define CATEndWidgetEvent_H

// COPYRIGHT DASSAULT SYSTEMES 2011

#include "CATVisFoundation.h"
#include "CATTimeStampedEvent.h"
class CATDevice;
class CATSupport;

class ExportedByCATVisFoundation CATEndWidgetEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

public:

  CATEndWidgetEvent();

  virtual ~CATEndWidgetEvent();

  CATDevice* Device;

  CATSupport *pSupport;
};
#endif
