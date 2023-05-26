// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef __CATSYSWorkbenchSTATISTICSAUTOSTGCTRL
#define __CATSYSWorkbenchSTATISTICSAUTOSTGCTRL
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

class CATISysWorkbenchStatisticsSettingAtt;
class CATSysGeneralStatisticsAutoSettingCtrl;

class ExportedByJS03TRA CATSysWorkbenchStatisticsAutoSettingCtrl:public CATSysGeneralStatisticsAutoSettingCtrl
{
 // Macro for declaration of the SysWorkbenchStatisticsSetting controller
  CATDeclareAutoSettingCtrl(CAT,Sys,WorkbenchStatistics);

public :
  HRESULT GetMyPtr (  CATISysGeneralStatisticsSettingAtt *&oItf);
  
};

#endif /*__CATSYSWorkbenchSTATISTICSAUTOSTGCTRL */
