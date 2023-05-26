#ifndef CATLeaveEvent_H
#define CATLeaveEvent_H

// COPYRIGHT DASSAULT SYSTEMES 2011

#include "CATVisFoundation.h"
#include "CATTimeStampedEvent.h"
class CATDevice;
class CATSupport;

class ExportedByCATVisFoundation CATLeaveEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

public:

  CATLeaveEvent();

  virtual ~CATLeaveEvent();

  CATDevice* Device;

  CATSupport *pSupport;
};
#endif
