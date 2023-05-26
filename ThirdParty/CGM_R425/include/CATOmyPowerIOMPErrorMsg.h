/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATOmyPowerIOMPErrorMsg_H
#define __CATOmyPowerIOMPErrorMsg_H

#include "CATOmyPowerIOMPTransactionMsg.h"
#include "CATUuid.h"
#include "CATVVSUrl.h"

#include "CATCollec.h"
#include "CATUnicodeString.h"
#include "CATOMYCuteIO.h"

class ExportedByCATOMYCuteIO CATOmyPowerIOMPErrorMsg : public CATOmyPowerIOMPTransactionMsg
{
	CATDeclareClass;

public :

	CATOmyPowerIOMPErrorMsg();
	virtual ~CATOmyPowerIOMPErrorMsg();

	// CATIStreamMsg Interface
	virtual HRESULT StreamData    ( void **oBuffer, uint32 *oLen);
	virtual HRESULT UnstreamData  ( void  *iBuffer, uint32  iLen);
	virtual HRESULT FreeStreamData( void  *iBuffer, uint32  iLen);
	virtual HRESULT SetMessageSpecifications();

	virtual HRESULT SetErrorMsg(int iErrorType, CATUnicodeString iErrorDescription);
	virtual HRESULT GetErrorMsg(int &oErrorType, CATUnicodeString & oErrorDescription);

private:
	CATUnicodeString _Message;
	int _type;
};

#endif
