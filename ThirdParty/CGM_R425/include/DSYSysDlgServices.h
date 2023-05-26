#ifndef DSYSysDlgServices_H
#define DSYSysDlgServices_H

#include "WebLogonPanel.h"
#include "CATError.h"
#include "CATLib.h"
#include "CATTSLib.h"
#include "JS0TSSTUBS.h"
#include "CATUnicodeString.h"

#include "CATBaseUnknown.h"
#include "CATInternalError.h"
#include "CATErrorDefs.h"


class DSYSysReconnectionNotif;

class DSYSysIsSIDLTimeoutError : public CATInternalError
{
public :
	CATDeclareError(DSYSysIsSIDLTimeoutError, CATInternalError)
};

enum DSYSysIsTimeoutService {
	DSYSysIsTimeout3DSpace = 0,
	DSYSysIsTimeoutOther = 1
};

CATBoolean	ExportedByJS0TSSTUBS DSYSysIsTimeout(HRESULT iRC, DSYSysIsTimeoutService iService);
CATBoolean	ExportedByJS0TSSTUBS DSYSysIsTimeout(CATUnicodeString iMsgCatalog, CATUnicodeString iMsgId, DSYSysIsTimeoutService iService);

CATBoolean	ExportedByJS0TSSTUBS DSYSysIsSIDLTimeout(HRESULT iRC, bool IsLoginNeeded = true);
CATBoolean	ExportedByJS0TSSTUBS DSYSysIsSIDLTimeout(CATUnicodeString iMsgCatalog, CATUnicodeString iMsgId, bool iIsLoginNeeded = true);
extern "C" {
	HRESULT		ExportedByJS0TSSTUBS DSYSysCredentialsUpdate(int iID = 0);
}
HRESULT		ExportedByJS0TSSTUBS DSYSysGetCredentialsNotif(DSYSysReconnectionNotif *&oNotif);

#endif
