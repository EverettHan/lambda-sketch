/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATIOmyPowerIOMPUpdateNotifyMsg_H
#define __CATIOmyPowerIOMPUpdateNotifyMsg_H

#include "CATUuid.h"
#include "CATVVSUrl.h"
#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"

#include "CATCollec.h"
#include "CATUnicodeString.h"

#include "CATIOmyPowerIOMPTransactionMsg.h"

extern ExportedByCATOMYCuteIO IID IID_CATIOmyPowerIOMPUpdateNotifyMsg ;

class CATIOmyPowerIOMPUpdateNotifyMsg : public CATIOmyPowerIOMPTransactionMsg
{
	CATDeclareInterface;

public :
	virtual HRESULT GetUpdateStats(int &oPart, int &oTotal) = 0;
	virtual HRESULT SetUpdateStats(int iPart, int iTotal) = 0;

};
#endif
