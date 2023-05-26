// definition de l'interface CATSysNetworkStatisticsSettingCtrl

# ifndef _CATSYSNETWORKSTATSTGCTRL
# define _CATSYSNETWORKSTATSTGCTRL

# include "JS03TRA.h"
# include "CATBaseUnknown.h"
# include "CATSysGeneralStatisticsSettingCtrl.h"
# include "CATSysStatisticsDef.h"

// COPYRIGHT DASSAULT SYSTEMES 2003


class ExportedByJS03TRA CATSysNetworkStatisticsSettingCtrl : public CATSysGeneralStatisticsSettingCtrl
{
   // Macro for declaration of the SysNetworkStatisticsSetting controller
  CATDeclareSettingCtrl(CAT,Sys,NetworkStatistics);
HRESULT GetThematicsParameterInfo (CATSettingInfo *iOutputFormat);
public :
};

# endif /* _CATSYSNETWORKSTATSTGCTRL */


