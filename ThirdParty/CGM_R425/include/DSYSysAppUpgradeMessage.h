#ifndef DSYSysAppUpgradeMessage_h
#define DSYSysAppUpgradeMessage_h

/************************************************************************/
/* Defines                                                              */
/************************************************************************/

#if defined(__DSYSysAppUpgradeMessage)
# define ExportedByDSYSysAppUpgradeMessage   DSYExport
#else // __DSYSysAppUpgradeMessage
# define ExportedByDSYSysAppUpgradeMessage   DSYImport
#endif  // __DSYSysAppUpgradeMessage

/************************************************************************/
/* Includes                                                             */
/************************************************************************/

// fw System
#include "DSYSysMainThreadMsgQ.h"
// fw SystemTS
#include "DSYSysAppUpgradeHelper.h"
#include "DSYExport.h"

class DSYSysAppUpgradeInfo;
struct DSYSysAppUpgradeAccessLocks;

/**
* Class to call SystemTS API as message.
*/
class ExportedByDSYSysAppUpgradeMessage DSYSysAppUpgradeMessage : public DSYSysMainThreadMsgQ::Message {
  DSYSysMainThreadMsgQMessageDecl(DSYSysAppUpgradeMessage);
public:
  virtual ~DSYSysAppUpgradeMessage();

  static HRESULT LaunchAsyncCheck( const bool ibWithLocks = true);

  HRESULT GetLastCallResult() const
  { return _hrLastCallResult; };

  HRESULT GetInfo(DSYSysAppUpgradeInfo & oAppUpgradeInfo) const;

  HRESULT GetAccessLocksResult() const
  { return _hrAccessLocks; };

  DSYSysAppUpgradeAccessLocks GetAccessLocks() const
  { return _accessLocks; };

private:
  static void RequestUpgradeInfo();
  static void RequestUpgradeInfoWithLocks();

  HRESULT SetMessage( const HRESULT &iHr
                    , const DSYSysAppUpgradeInfo &iAppUpgradeInfo);

  HRESULT SetMessage( const HRESULT &iHr
                    , const DSYSysAppUpgradeInfo &iAppUpgradeInfo
                    , const HRESULT &iHrAccessLocks
                    , const DSYSysAppUpgradeAccessLocks iAccessLocks);

  // Members.
  HRESULT                     _hrLastCallResult;
  DSYSysAppUpgradeInfo*       _appUpgradeInfo;
  HRESULT                     _hrAccessLocks;
  DSYSysAppUpgradeAccessLocks _accessLocks;
};

HRESULT ExportedByDSYSysAppUpgradeMessage DSYSysAppUpgradeLaunchOnlineUpdate();

#endif // DSYSysAppUpgradeMessage_h
