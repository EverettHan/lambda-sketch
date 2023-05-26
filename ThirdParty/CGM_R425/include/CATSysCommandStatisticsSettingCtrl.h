// definition de l'interface CATSysCommandStatisticsSettingCtrl

# ifndef _CATSYSCMDSTATSTGCTRL
# define _CATSYSCMDSTATSTGCTRL

# include "JS03TRA.h"
# include "CATBaseUnknown.h"
# include "CATSysGeneralStatisticsSettingCtrl.h"
# include "CATSysStatisticsDef.h"

// COPYRIGHT DASSAULT SYSTEMES 2003

class ExportedByJS03TRA CATSysCommandStatisticsSettingCtrl : public CATSysGeneralStatisticsSettingCtrl
{
   // Macro for declaration of the SysCommandStatisticsSetting controller
  CATDeclareSettingCtrl(CAT,Sys,CommandStatistics);
HRESULT GetThematicsParameterInfo (CATSettingInfo *iOutputFormat);
public :
};

# endif /* _CATSYSCMDSTATSTGCTRL */


