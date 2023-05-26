#ifndef CATOmyAuditLogMgt_H
#define CATOmyAuditLogMgt_H

#include <stdio.h>
#include "IUnknown.h"   
#include "CATDataType.h"
#include "CATOMYBaseSession.h"
class CATUnicodeString ;
/**
* PLM Audit Log Management
*/
class CATOmyLogInfos;
class ExportedByCATOMYBaseSession CATOmyAuditLogMgt
{
public:
	CATOmyAuditLogMgt();

	virtual ~CATOmyAuditLogMgt();
	void AddLogInfo(CATOmyLogInfos & iLogInfo);
private :
	FILE  *_Fd;
  CATLONG64 _fcsStartDate;

//#define ROOT_AUDITV6 "AuditV6"
	static  int GetAuditRootDirectory ( CATUnicodeString &oDirPath);
	static int GetNewAuditFile ( CATUnicodeString &oAuditFilePath);
	static void GetClientId ( char *&oClientId );
};
#endif
