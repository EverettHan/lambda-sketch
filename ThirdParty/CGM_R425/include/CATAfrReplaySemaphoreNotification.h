//===================================================================
// COPYRIGHT Dassault Systemes 2016-04-08
//===================================================================
//
// Abstract: Notification that should trigger a pause on ODT replays.
//           Replay unpause should be triggered by the CATCommand
//           that pushed that notification during the ODT record.
//
//===================================================================
// 2016-04-08 Creation: ???
//===================================================================

#ifndef CATAfrReplaySemaphoreNotification_H
#define CATAfrReplaySemaphoreNotification_H

// AfrFoundation
#include "CATAfrFoundation.h"
// System
#include "CATNotification.h"

class ExportedByCATAfrFoundation CATAfrReplaySemaphoreNotification : public CATNotification
{
  CATDeclareClass;

public:
  CATAfrReplaySemaphoreNotification();
  ~CATAfrReplaySemaphoreNotification();

private:
  CATAfrReplaySemaphoreNotification(CATAfrReplaySemaphoreNotification&);
  CATAfrReplaySemaphoreNotification& operator=(CATAfrReplaySemaphoreNotification&);
};

#endif
