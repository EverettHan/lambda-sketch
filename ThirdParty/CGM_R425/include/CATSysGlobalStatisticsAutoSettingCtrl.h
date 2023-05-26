// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef __CATSYSGlobalSTATISTICSAUTOSTGCTRL
#define __CATSYSGlobalSTATISTICSAUTOSTGCTRL
#include "JS03TRA.h"
#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"
#include "CATSysMacroSettingCtrl.h"
#include "CATIAGlobalStatisticsSettingAtt.h"
#include "CAT_VARIANT_BOOL.h"

class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATSettingInfo;

class CATISysGlobalStatisticsSettingAtt;


class ExportedByJS03TRA CATSysGlobalStatisticsAutoSettingCtrl:public CATSysAutoSettingController
{
//	Macro for declaration of the SysGeneralStatisticsSetting controller
	CATDeclareAutoSettingCtrl(CAT,Sys,GlobalStatistics);

public :

	HRESULT get_MaxSizePerFile(CATLONG & oSize);
	HRESULT put_MaxSizePerFile(CATLONG iSize);

	HRESULT get_MaxCopyFile(CATLONG & oNb);
	HRESULT put_MaxCopyFile(CATLONG iNb);

	HRESULT get_BufferSize(CATLONG & oSize);
	HRESULT put_BufferSize(CATLONG iSize);

	HRESULT get_CopyDirectory( CATBSTR &oCopyDir);
	HRESULT put_CopyDirectory(const CATBSTR & iCopyDir);

  HRESULT get_EventScheduling(CAT_VARIANT_BOOL& oSet);
  HRESULT put_EventScheduling(const CAT_VARIANT_BOOL& iSet);

  HRESULT get_UsageCollectFormat(CAT_VARIANT_BOOL& oSet);
  HRESULT put_UsageCollectFormat(const CAT_VARIANT_BOOL& iSet);

	HRESULT SetThematicsParameterLock(CAT_VARIANT_BOOL iLocked);
	HRESULT GetThematicsParameterInfo(CATBSTR & AdminLevel,
				  CATBSTR & oLocked,
				  CAT_VARIANT_BOOL & oModified);
};

#endif /*__CATSYSGlobalSTATISTICSAUTOSTGCTRL */
