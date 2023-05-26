/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATIOmyPowerIOMPPLMQLTransactionMsg_H
#define __CATIOmyPowerIOMPPLMQLTransactionMsg_H

#include "CATUuid.h"
#include "CATVVSUrl.h"
#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"
#include "CATMessageClass.h"

#include "CATCollec.h"
#include "CATUnicodeString.h"

#include "CATIOmyPowerIOMPTransactionMsg.h"

extern ExportedByCATOMYCuteIO IID IID_CATIOmyPowerIOMPPLMQLTransactionMsg ;

class CATIOmyPowerIOMPPLMQLTransactionMsg : public CATIOmyPowerIOMPTransactionMsg
{
	CATDeclareInterface;

public :
	virtual HRESULT SetXMLFilter(CATUnicodeString & iXMLFilter) =0;
	virtual HRESULT GetXMLFilter(CATUnicodeString & oXMLFilter) =0;
	virtual HRESULT SetQueryType(CATBoolean iIsQueryPush) =0;
	virtual HRESULT GetQueryType(CATBoolean &iosQueryPush) =0;
};
#endif
