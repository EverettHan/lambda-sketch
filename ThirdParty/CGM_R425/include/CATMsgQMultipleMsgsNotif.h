#ifndef CATMsgQMultipleMsgsNotif_H
#define CATMsgQMultipleMsgsNotif_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATMsgQNotification.h"
class ExportedByCATSysMainThreadMQ  CATMsgQMultipleMsgsNotif : public CATMsgQNotification
{
  public :
  CATMsgQMultipleMsgsNotif(CATThrMessageQueue *iMQ , CATThrMessage **iMsg);
  ~CATMsgQMultipleMsgsNotif();
  CATDeclareClass;
  CATThrMessage **_MessageArray; 
};

#endif
