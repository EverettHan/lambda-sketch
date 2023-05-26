// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef __CATSYSCommandSTATISTICSAUTOSTGCTRL
#define __CATSYSCommandSTATISTICSAUTOSTGCTRL
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
class CATISysCommandStatisticsSettingAtt;


class ExportedByJS03TRA CATSysCommandStatisticsAutoSettingCtrl:public CATSysGeneralStatisticsAutoSettingCtrl
{
 // Macro for declaration of the SysCommandStatisticsSetting controller
CATDeclareAutoSettingCtrl(CAT,Sys,CommandStatistics);

public :
  HRESULT GetMyPtr (  CATISysGeneralStatisticsSettingAtt *&oItf);

};

#endif /*__CATSYSCommandSTATISTICSAUTOSTGCTRL */
