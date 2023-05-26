// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef __CATSYSSessionSTATISTICSAUTOSTGCTRL
#define __CATSYSSessionSTATISTICSAUTOSTGCTRL
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
class CATISysSessionStatisticsSettingAtt;


class ExportedByJS03TRA CATSysSessionStatisticsAutoSettingCtrl:public CATSysGeneralStatisticsAutoSettingCtrl
{
 // Macro for declaration of the SysSessionStatisticsSetting controller
 CATDeclareAutoSettingCtrl(CAT,Sys,SessionStatistics);

public :
  HRESULT GetMyPtr (  CATISysGeneralStatisticsSettingAtt *&oItf);

};

#endif /*__CATSYSSessionSTATISTICSAUTOSTGCTRL */
