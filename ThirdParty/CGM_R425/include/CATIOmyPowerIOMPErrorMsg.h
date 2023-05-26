/**
 * @level Protected
 * @usage U1
 */


#ifndef __CATIOmyPowerIOMPErrorMsg_H
#define __CATIOmyPowerIOMPErrorMsg_H

#include "CATUuid.h"
#include "CATVVSUrl.h"
#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"

#include "CATCollec.h"
#include "CATUnicodeString.h"

#include "CATIOmyPowerIOMPTransactionMsg.h"

extern ExportedByCATOMYCuteIO IID IID_CATIOmyPowerIOMPErrorMsg ;

class CATIOmyPowerIOMPErrorMsg : public CATIOmyPowerIOMPTransactionMsg
{
	CATDeclareInterface;

public :
	virtual HRESULT SetErrorMsg(int iErrorType, CATUnicodeString iErrorDescription) = 0;
	virtual HRESULT GetErrorMsg(int &oErrorType, CATUnicodeString & oErrorDescription) = 0;
};
#endif

