#ifndef CATEnterEvent_H
#define CATEnterEvent_H

// COPYRIGHT DASSAULT SYSTEMES 2011

#include "CATVisFoundation.h"
#include "CATTimeStampedEvent.h"
class CATDevice;
class CATSupport;

class ExportedByCATVisFoundation CATEnterEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

public:

  CATEnterEvent();

  virtual ~CATEnterEvent();

  CATDevice* Device;

  CATSupport *pSupport;
};
#endif
