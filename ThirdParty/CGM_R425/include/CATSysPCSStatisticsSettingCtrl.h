// definition de l'interface CATSysPCSStatisticsSettingCtrl

# ifndef _CATSYSPCSSTATSTGCTRL
# define _CATSYSPCSSTATSTGCTRL

# include "JS03TRA.h"
# include "CATBaseUnknown.h"
# include "CATSysGeneralStatisticsSettingCtrl.h"
# include "CATSysStatisticsDef.h"

// COPYRIGHT DASSAULT SYSTEMES 2004

class ExportedByJS03TRA CATSysPCSStatisticsSettingCtrl : public CATSysGeneralStatisticsSettingCtrl
{
   // Macro for declaration of the SysPCSStatisticsSetting controller
  CATDeclareSettingCtrl(CAT,Sys,PCSStatistics);
HRESULT GetThematicsParameterInfo (CATSettingInfo *iOutputFormat);
public :
	HRESULT GetMemUse(CATBoolean &oStatus);
	HRESULT SetMemUse(const CATBoolean &iStatus);
	HRESULT GetActivation(int *oActivationState);
	HRESULT GetTHEM (CATBoolean &oStatus);
	HRESULT GetTIME (CATBoolean &oStatus);
	HRESULT GetCPUS (CATBoolean &oStatus);
	HRESULT GetRTIM (CATBoolean &oStatus);
	HRESULT GetELPS (CATBoolean &oStatus);
	HRESULT GetUPID (CATBoolean &oStatus);
	HRESULT GetUSER (CATBoolean &oStatus);
	HRESULT GetHOST (CATBoolean &oStatus);
	HRESULT GetTimeUnit (CATSysStatisticsTimeUnit &iTimeUnit);
	HRESULT GetDateFormat  (CATSysStatisticsDateFormat &DateFormat);
	HRESULT GetOutputFormat (CATSysStatisticsOutputFormat &iOutputFormat);
};

# endif /* _CATSYSPCSSTATSTGCTRL */

