
/**
 * @level Protected
 * @usage U1
 */
#ifndef __CATIOmyPowerIOMPEndTransactionMsg_H
#define __CATIOmyPowerIOMPEndTransactionMsg_H

#include "CATUuid.h"
#include "CATVVSUrl.h"
#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"

#include "CATCollec.h"
#include "CATUnicodeString.h"

#include "CATIOmyPowerIOMPTransactionMsg.h"

extern ExportedByCATOMYCuteIO IID IID_CATIOmyPowerIOMPEndTransactionMsg ;

class CATIOmyPowerIOMPEndTransactionMsg : public CATIOmyPowerIOMPTransactionMsg
{
	CATDeclareInterface;

public :
	virtual HRESULT PushVVSTransactionParam(CATUnicodeString &iParamName, CATUnicodeString &iParamValue) = 0;
	virtual HRESULT GetListVVSTransactionParam(CATListOfCATUnicodeString &oListParamName, CATListOfCATUnicodeString &oListParamValue) = 0;
  virtual HRESULT SetTransactionSuccess(CATBoolean iTransactionSucceess) = 0;
	virtual HRESULT GetTransactionSuccess(CATBoolean & oTransactionSuccess) = 0;
};
#endif
