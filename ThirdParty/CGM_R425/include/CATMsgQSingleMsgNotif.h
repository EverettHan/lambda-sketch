#ifndef CATMsgQSingleMsgNotif_H
#define CATMsgQSingleMsgNotif_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATMsgQNotification.h"
class ExportedByCATSysMainThreadMQ   CATMsgQSingleMsgNotif :public CATMsgQNotification
{
  public:
  CATMsgQSingleMsgNotif(CATThrMessageQueue *iMQ,CATThrMessage_var iMsg);
  ~CATMsgQSingleMsgNotif();
  CATDeclareClass;
  CATThrMessage_var _MessageHandler; 
};
#endif
