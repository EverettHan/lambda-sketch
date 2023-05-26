#ifndef CATOmyOnlineOfflineSwitchOccured_h
#define CATOmyOnlineOfflineSwitchOccured_h

/**
 * @level Protected
 * @usage U1
 */

#include "CATNotification.h"
#include "CATOMYBaseSession.h"

/**
 * Notification emmitted after a switch to online or offline mode.
 * See CATOmyOnlineOfflineSwitch.
 */
class ExportedByCATOMYBaseSession CATOmyOnlineOfflineSwitchOccured : public CATNotification
{
  CATDeclareClass;
public:
  CATOmyOnlineOfflineSwitchOccured(){};
  virtual ~CATOmyOnlineOfflineSwitchOccured(){};
};
#endif
