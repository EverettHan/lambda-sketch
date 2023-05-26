/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATOmyPowerIOMPProcessIsConnectedMsg_H
#define __CATOmyPowerIOMPProcessIsConnectedMsg_H

#include "CATOmyPowerIOMPTransactionMsg.h"
#include "CATOMYCuteIO.h"
#include "CATUnicodeString.h"

class ExportedByCATOMYCuteIO CATOmyPowerIOMPProcessIsConnectedMsg : public CATOmyPowerIOMPTransactionMsg
{
	CATDeclareClass;

public :

	CATOmyPowerIOMPProcessIsConnectedMsg();
	virtual ~CATOmyPowerIOMPProcessIsConnectedMsg();

	// CATIStreamMsg Interface
	virtual HRESULT StreamData    ( void **oBuffer, uint32 *oLen);
	virtual HRESULT UnstreamData  ( void  *iBuffer, uint32  iLen);
	virtual HRESULT FreeStreamData( void  *iBuffer, uint32  iLen);
	virtual HRESULT SetMessageSpecifications();

	virtual HRESULT GetTaskType(CATUnicodeString & oTaskType){oTaskType = _Type; return S_OK;};
	virtual HRESULT SetTaskType(CATUnicodeString  iTaskType){_Type = iTaskType; return S_OK;};

	virtual HRESULT GetConnectionStatus(CATBoolean& oValue){oValue = _ConnectionStatus;return S_OK;};
	virtual HRESULT SetConnectionStatus(CATBoolean& iValue){_ConnectionStatus = iValue;return S_OK;};

private :
	CATUnicodeString _Type;
	CATBoolean _ConnectionStatus;

};

#endif
