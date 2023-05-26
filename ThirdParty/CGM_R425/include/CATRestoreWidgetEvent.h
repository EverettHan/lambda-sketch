#ifndef CATRestoreWidgetEvent_H
#define CATRestoreWidgetEvent_H

// COPYRIGHT DASSAULT SYSTEMES 2011

#include "CATVisFoundation.h"
#include "CATTimeStampedEvent.h"
class CATDevice;
class CATSupport;

class ExportedByCATVisFoundation CATRestoreWidgetEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

public:

  CATRestoreWidgetEvent();

  virtual ~CATRestoreWidgetEvent();

  CATDevice* Device;

  CATSupport *pSupport;
};
#endif
