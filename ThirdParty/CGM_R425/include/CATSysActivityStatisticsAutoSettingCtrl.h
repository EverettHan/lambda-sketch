// COPYRIGHT DASSAULT SYSTEMES 2006

#ifndef __CATSYSActivitySTATISTICSAUTOSTGCTRL
#define __CATSYSActivitySTATISTICSAUTOSTGCTRL
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
class CATISysActivityStatisticsSettingAtt;


class ExportedByJS03TRA CATSysActivityStatisticsAutoSettingCtrl:public CATSysGeneralStatisticsAutoSettingCtrl
{
 // Macro for declaration of the SysActivityStatisticsSetting controller
 CATDeclareAutoSettingCtrl(CAT,Sys,ActivityStatistics);

public :
  HRESULT GetMyPtr (  CATISysGeneralStatisticsSettingAtt *&oItf);

};

#endif /*__CATSYSActivitySTATISTICSAUTOSTGCTRL */
