// definition de l'interface CATSysSessionStatisticsSettingCtrl

# ifndef _CATSYSSESSIONSTATSTGCTRL
# define _CATSYSSESSIONSTATSTGCTRL

# include "JS03TRA.h"
# include "CATBaseUnknown.h"
# include "CATSysGeneralStatisticsSettingCtrl.h"
# include "CATSysStatisticsDef.h"

// COPYRIGHT DASSAULT SYSTEMES 2003

class ExportedByJS03TRA CATSysSessionStatisticsSettingCtrl : public CATSysGeneralStatisticsSettingCtrl
{
   // Macro for declaration of the SysSessionStatisticsSetting controller
  CATDeclareSettingCtrl(CAT,Sys,SessionStatistics);
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

};

# endif /* _CATSYSSESSIONSTATSTGCTRL */


