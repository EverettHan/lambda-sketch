// definition de l'interface CATSysErrorLogStatisticsSettingCtrl

# ifndef _CATSYSERRORLOGSTATSTGCTRL
# define _CATSYSERRORLOGSTATSTGCTRL

# include "JS03TRA.h"
# include "CATBaseUnknown.h"
# include "CATSysGeneralStatisticsSettingCtrl.h"
# include "CATSysStatisticsDef.h"

// COPYRIGHT DASSAULT SYSTEMES 2003


class ExportedByJS03TRA CATSysErrorlogStatisticsSettingCtrl : public CATSysGeneralStatisticsSettingCtrl
{
   // Macro for declaration of the SysErrorlogStatisticsSetting controller
  CATDeclareSettingCtrl(CAT,Sys,ErrorlogStatistics);
HRESULT GetThematicsParameterInfo (CATSettingInfo *iOutputFormat);
public :

	HRESULT  GetTHEM (CATBoolean &oStatus);
	HRESULT  GetTIME (CATBoolean &oStatus);
	HRESULT  GetCPUS (CATBoolean &oStatus);
	HRESULT  GetRTIM (CATBoolean &oStatus);
	HRESULT  GetELPS (CATBoolean &oStatus);
	HRESULT  GetUPID (CATBoolean &oStatus);
	HRESULT  GetUSER (CATBoolean &oStatus);
	HRESULT  GetHOST (CATBoolean &oStatus);
	HRESULT  GetTimeUnit (CATSysStatisticsTimeUnit &iTimeUnit);
	HRESULT  GetDateFormat  (CATSysStatisticsDateFormat &DateFormat);
	HRESULT  GetOutputFormat (CATSysStatisticsOutputFormat &iOutputFormat);

	HRESULT GetWKBN (CATBoolean &oStatus);
	HRESULT SetWKBN (const CATBoolean &iStatus);

	HRESULT GetCMND (CATBoolean &oStatus);
	HRESULT SetCMND (const CATBoolean &iStatus);

	HRESULT GetMSGE (CATBoolean &oStatus);
	HRESULT SetMSGE (const CATBoolean &iStatus);

	HRESULT GetABND (CATBoolean &oStatus);
	HRESULT SetABND (const CATBoolean &iStatus);

	HRESULT GetCERR (CATBoolean &oStatus);
	HRESULT SetCERR (const CATBoolean &iStatus);

	HRESULT GetWARN (CATBoolean &oStatus);
	HRESULT SetWARN (const CATBoolean &iStatus);

	HRESULT GetCOMT (CATBoolean &oStatus);
	HRESULT SetCOMT (const CATBoolean &iStatus);

	HRESULT GetUREP (CATBoolean &oStatus);
	HRESULT SetUREP (const CATBoolean &iStatus);

	HRESULT SetThematicsParameterLock( unsigned char iLock );

};

# endif /* _CATSYSERRORLOGSTATSTGCTRL */


