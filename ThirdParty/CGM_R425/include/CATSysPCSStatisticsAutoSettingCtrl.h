// COPYRIGHT DASSAULT SYSTEMES 2004

#ifndef __CATSYSPCSSTATISTICSAUTOSTGCTRL
#define __CATSYSPCSSTATISTICSAUTOSTGCTRL
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
#include "CAT_VARIANT_BOOL.h"

class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATSettingInfo;

class CATSysGeneralStatisticsAutoSettingCtrl;
class CATISysPCSStatisticsSettingAtt;


class ExportedByJS03TRA CATSysPCSStatisticsAutoSettingCtrl:public CATSysGeneralStatisticsAutoSettingCtrl
{
 // Macro for declaration of the SysPCSStatisticsSetting controller
CATDeclareAutoSettingCtrl(CAT,Sys,PCSStatistics);

public :
	HRESULT GetMyPtr (  CATISysGeneralStatisticsSettingAtt *&oItf);

	HRESULT get_MemUse (CAT_VARIANT_BOOL & oStatus);
	HRESULT put_MemUse (CAT_VARIANT_BOOL iStatus);
};

#endif /*__CATSYSPCSSTATISTICSAUTOSTGCTRL */
