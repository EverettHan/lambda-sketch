#ifndef CATSearchNotificationBeforeResults_H
#define CATSearchNotificationBeforeResults_H

// COPYRIGHT DASSAULT SYSTEMES 2000

//================================================================//
//
// Definition of the notification sent by the CATMultiselManager 
// before it sends the results from the Search Command. 
// In the case of the Select command, we want this notification 
// to be analysed as a EmptyCSO command.
// In other cases, it is up to the command to subscribe to the
// notification and decide which steps to apply when receiving it.
//
//================================================================//
// Creation July 99 by jac Johann Chemin
//================================================================//
#include "CATNotification.h"
#include "CATAfrSelection.h"

class ExportedByCATAfrSelection CATSearchNotificationBeforeResults : public CATNotification
{
  CATDeclareClass;

public:
  CATSearchNotificationBeforeResults();
  virtual ~CATSearchNotificationBeforeResults();
};
#endif
