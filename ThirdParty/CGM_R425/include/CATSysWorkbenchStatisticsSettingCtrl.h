// definition de l'interface CATSysWorkbenchStatisticsSettingAtt

# ifndef _CATSYSWKBSTATSTGCTRL
# define _CATSYSWKBSTATSTGCTRL

# include "JS03TRA.h"
# include "CATBaseUnknown.h"
# include "CATSysGeneralStatisticsSettingCtrl.h"
# include "CATSysStatisticsDef.h"

// COPYRIGHT DASSAULT SYSTEMES 2003


class ExportedByJS03TRA CATSysWorkbenchStatisticsSettingCtrl : public CATSysGeneralStatisticsSettingCtrl
{
   // Macro for declaration of the SysWorkbenchStatisticsSetting controller
  CATDeclareSettingCtrl(CAT,Sys,WorkbenchStatistics);
HRESULT GetThematicsParameterInfo (CATSettingInfo *iOutputFormat);
public :
	
};

# endif /* _CATSYSWKBSTATSTGCTRL */


