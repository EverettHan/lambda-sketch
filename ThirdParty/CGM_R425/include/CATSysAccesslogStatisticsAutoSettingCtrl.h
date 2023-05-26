// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef __CATSYSAccesslogSTATISTICSAUTOSTGCTRL
#define __CATSYSAccesslogSTATISTICSAUTOSTGCTRL
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
class CATISysAccesslogStatisticsSettingAtt;


class ExportedByJS03TRA CATSysAccesslogStatisticsAutoSettingCtrl:public CATSysGeneralStatisticsAutoSettingCtrl
{
 // Macro for declaration of the SysAccesslogStatisticsSetting controller
 CATDeclareAutoSettingCtrl(CAT,Sys,AccesslogStatistics);

public :
  HRESULT GetMyPtr (  CATISysGeneralStatisticsSettingAtt *&oItf);

};

#endif /*__CATSYSAccesslogSTATISTICSAUTOSTGCTRL */
