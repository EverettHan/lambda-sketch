// COPYRIGHT DASSAULT SYSTEMES 2006

#ifndef __CATSYSAuditSTATISTICSAUTOSTGCTRL
#define __CATSYSAuditSTATISTICSAUTOSTGCTRL
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
class CATISysAuditStatisticsSettingAtt;


class ExportedByJS03TRA CATSysAuditStatisticsAutoSettingCtrl:public CATSysGeneralStatisticsAutoSettingCtrl
{
 // Macro for declaration of the SysAuditStatisticsSetting controller
 CATDeclareAutoSettingCtrl(CAT,Sys,AuditStatistics);

public :
  HRESULT GetMyPtr (  CATISysGeneralStatisticsSettingAtt *&oItf);

};

#endif /*__CATSYSAuditSTATISTICSAUTOSTGCTRL */
