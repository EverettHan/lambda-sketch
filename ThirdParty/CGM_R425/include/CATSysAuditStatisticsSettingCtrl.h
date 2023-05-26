// definition de l'interface CATSysAuditStatisticsSettingCtrl

# ifndef _CATSYSAuditSTATSTGCTRL
# define _CATSYSAuditSTATSTGCTRL

# include "JS03TRA.h"
# include "CATBaseUnknown.h"
# include "CATSysGeneralStatisticsSettingCtrl.h"
# include "CATSysStatisticsDef.h"

// COPYRIGHT DASSAULT SYSTEMES 2003



class ExportedByJS03TRA CATSysAuditStatisticsSettingCtrl : public CATSysGeneralStatisticsSettingCtrl
{
   // Macro for declaration of the SysAuditStatisticsSetting controller
  CATDeclareSettingCtrl(CAT,Sys,AuditStatistics);
  HRESULT GetThematicsParameterInfo (CATSettingInfo *iOutputFormat);

public :
};

# endif /* _CATSYSAuditSTATSTGCTRL */


