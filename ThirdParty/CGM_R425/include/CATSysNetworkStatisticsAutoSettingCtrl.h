// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef __CATSYSNETWORKSTATISTICSAUTOSTGCTRL
#define __CATSYSNETWORKSTATISTICSAUTOSTGCTRL
#include "JS03TRA.h"
#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"
#include "CATSysMacroSettingCtrl.h"
#include "JS03TRA.h"
#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"
#include "CATSysMacroSettingCtrl.h"
#include "CATSysGeneralStatisticsAutoSettingCtrl.h"
#include "CATISysGeneralStatisticsSettingAtt.h"

class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATSettingInfo;

class CATSysGeneralStatisticsAutoSettingCtrl;
class CATISysNetworkStatisticsSettingAtt;


class ExportedByJS03TRA CATSysNetworkStatisticsAutoSettingCtrl:public CATSysGeneralStatisticsAutoSettingCtrl
{
 // Macro for declaration of the SysNetworkStatisticsSetting controller
 CATDeclareAutoSettingCtrl(CAT,Sys,NetworkStatistics);

public :

  HRESULT GetMyPtr (  CATISysGeneralStatisticsSettingAtt *&oItf);

};

#endif /*__CATSYSNETWORKSTATISTICSAUTOSTGCTRL */
