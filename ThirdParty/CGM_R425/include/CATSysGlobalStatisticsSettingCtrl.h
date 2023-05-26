// implementation des methodes de CATSysGeneralStatisticsSettingCtrl

#ifndef __CATSYSGLOBALSTATISTICSSTGCTRL
#define __CATSYSGLOBALSTATISTICSSTGCTRL

#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"
#include "CATSysMacroSettingCtrl.h"
#include "CATSafeArray.h"
#include "JS03TRA.h"
#include "CATLib.h"
#include "CATISysGlobalStatisticsSettingAtt.h"

class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATSettingInfo;
class CATSysStatsOpenedFile;

class ExportedByJS03TRA CATSysGlobalStatisticsSettingCtrl:public CATSysSettingController
{
//	Macro for declaration of the SysGlobalStatisticsSetting controller
	CATDeclareSettingCtrl(CAT,Sys,GlobalStatistics);

public:
	~CATSysGlobalStatisticsSettingCtrl();

	HRESULT GetMaxSizePerFile(unsigned int *oSize);
	HRESULT SetMaxSizePerFile(unsigned int iSize);

	HRESULT GetMaxCopyFile(unsigned int *oNb);
	HRESULT SetMaxCopyFile(unsigned int iNb);

	HRESULT GetBufferSize(unsigned int *oSize);
	HRESULT SetBufferSize(unsigned int iSize);

	HRESULT GetCopyDirectory(CATUnicodeString *oCopyDir);
	HRESULT SetCopyDirectory(CATUnicodeString *iCopyDir);

  HRESULT GetEventScheduling(bool* oSet);
  HRESULT SetEventScheduling(bool iSet);
#define USAGE_COLLECT_FORMAT_SYNCHRO
  HRESULT GetUsageCollectFormat(bool* oSet);
  HRESULT SetUsageCollectFormat(bool iSet);

	HRESULT SetThematicsParameterLock ( unsigned char Lock);
	HRESULT GetThematicsParameterInfo (CATSettingInfo * oInfo);

  virtual HRESULT Commit(int iNoEvent=0);
  virtual HRESULT SaveRepository(const char *itmp=NULL);

protected :
	CATSysGlobalStatisticsSettingCtrl ();

};

# endif /* __CATSYSGLOBALSTATISTICSSTGCTRL */
