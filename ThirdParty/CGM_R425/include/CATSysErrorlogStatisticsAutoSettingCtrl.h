// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef __CATSYSErrorlogSTATISTICSAUTOSTGCTRL
#define __CATSYSErrorlogSTATISTICSAUTOSTGCTRL
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
class CATISysErrorlogStatisticsSettingAtt;


class ExportedByJS03TRA CATSysErrorlogStatisticsAutoSettingCtrl:public CATSysGeneralStatisticsAutoSettingCtrl
{
 // Macro for declaration of the SysErrorlogStatisticsSetting controller
 CATDeclareAutoSettingCtrl(CAT,Sys,ErrorlogStatistics);

public :

	HRESULT  get_WKBN(CAT_VARIANT_BOOL & oStatus);
	HRESULT  put_WKBN(CAT_VARIANT_BOOL iStatus);

	HRESULT  get_CMND(CAT_VARIANT_BOOL & oStatus);
	HRESULT  put_CMND(CAT_VARIANT_BOOL iStatus);

	HRESULT  get_MSGE(CAT_VARIANT_BOOL & oStatus);
	HRESULT  put_MSGE(CAT_VARIANT_BOOL iStatus);

	HRESULT  get_ABND(CAT_VARIANT_BOOL & oStatus);
	HRESULT  put_ABND(CAT_VARIANT_BOOL iStatus);

	HRESULT  get_CERR(CAT_VARIANT_BOOL & oStatus);
	HRESULT  put_CERR(CAT_VARIANT_BOOL iStatus);

	HRESULT  get_WARN(CAT_VARIANT_BOOL & oStatus);
	HRESULT  put_WARN(CAT_VARIANT_BOOL iStatus);

	HRESULT  get_COMT(CAT_VARIANT_BOOL & oStatus);
	HRESULT  put_COMT(CAT_VARIANT_BOOL iStatus);

	HRESULT  get_UREP(CAT_VARIANT_BOOL & oStatus);
	HRESULT  put_UREP(CAT_VARIANT_BOOL iStatus);

	HRESULT GetMyPtr (  CATISysGeneralStatisticsSettingAtt *&oItf);
};

#endif /*__CATSYSErrorlogSTATISTICSAUTOSTGCTRL */
