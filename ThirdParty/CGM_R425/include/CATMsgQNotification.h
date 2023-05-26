#ifndef CATMsgQNotification_H
#define CATMsgQNotification_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATSysMainThreadMQ.h"
#include "CATNotification.h"
#include "CATThrMessageQueue.h"
#include "CATThrMessage.h"
class ExportedByCATSysMainThreadMQ  CATMsgQNotification :public CATNotification
{
  public:
  CATMsgQNotification(CATThrMessageQueue *iMQ);
  ~CATMsgQNotification();
  CATDeclareClass;
  CATThrMessageQueue *_MessageQueue;
};
#endif
