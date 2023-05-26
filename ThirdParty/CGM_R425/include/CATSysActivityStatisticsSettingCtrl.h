// definition de l'interface CATSysActivityStatisticsSettingCtrl

# ifndef _CATSYSActivitySTATSTGCTRL
# define _CATSYSActivitySTATSTGCTRL

# include "JS03TRA.h"
# include "CATBaseUnknown.h"
# include "CATSysGeneralStatisticsSettingCtrl.h"
# include "CATSysStatisticsDef.h"

// COPYRIGHT DASSAULT SYSTEMES 2003



class ExportedByJS03TRA CATSysActivityStatisticsSettingCtrl : public CATSysGeneralStatisticsSettingCtrl
{
   // Macro for declaration of the SysActivityStatisticsSetting controller
  CATDeclareSettingCtrl(CAT,Sys,ActivityStatistics);
  HRESULT GetThematicsParameterInfo (CATSettingInfo *iOutputFormat);

public :

};

# endif /* _CATSYSActivitySTATSTGCTRL */


