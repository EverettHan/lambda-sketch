// definition de l'interface CATSysAccesslogStatisticsSettingCtrl

# ifndef _CATSYSACCESSLOGSTATSTGCTRL
# define _CATSYSACCESSLOGSTATSTGCTRL

# include "JS03TRA.h"
# include "CATBaseUnknown.h"
# include "CATSysGeneralStatisticsSettingCtrl.h"
# include "CATSysStatisticsDef.h"

// COPYRIGHT DASSAULT SYSTEMES 2003



class ExportedByJS03TRA CATSysAccesslogStatisticsSettingCtrl : public CATSysGeneralStatisticsSettingCtrl
{
   // Macro for declaration of the SysAccesslogStatisticsSetting controller
  CATDeclareSettingCtrl(CAT,Sys,AccesslogStatistics);
  HRESULT GetThematicsParameterInfo (CATSettingInfo *iOutputFormat);

public :

};

# endif /* _CATSYSACCESSLOGSTATSTGCTRL */


