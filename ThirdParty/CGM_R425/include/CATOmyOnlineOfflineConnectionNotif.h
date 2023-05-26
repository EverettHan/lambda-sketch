#ifndef CATOmyOnlineOfflineConnection_h
#define CATOmyOnlineOfflineConnection_h

/**
 * @level Protected
 * @usage U1
 */
#include "CATNotification.h"
#include "CATOMYBaseSession.h"

/**
 * Notification emmitted after the connection succeeded during online/offline switchs.
 * See CATIOmyOnlineOfflineConnection.
 */
class ExportedByCATOMYBaseSession CATOmyOnlineOfflineConnectionNotif : public CATNotification
{
  CATDeclareClass;
public:
  enum CATOmyOnlineOfflineConnectionResult{success, failure, offlineFailure};

  CATOmyOnlineOfflineConnectionNotif(CATOmyOnlineOfflineConnectionResult iResult):_result(iResult){};
  virtual ~CATOmyOnlineOfflineConnectionNotif(){};

  CATOmyOnlineOfflineConnectionResult Result(){return _result;}
private:
  CATOmyOnlineOfflineConnectionResult _result;
};
#endif
