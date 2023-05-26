/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATOmyPowerIOMPInstanciateAckMsg_H
#define __CATOmyPowerIOMPInstanciateAckMsg_H


#include "CATOmyPowerIOMPTransactionMsg.h"
#include "CATUuid.h"
#include "CATVVSUrl.h"

#include "CATCollec.h"
#include "CATListOfInt.h"
#include "CATUnicodeString.h"
#include "CATOMYCuteIO.h"

class ExportedByCATOMYCuteIO CATOmyPowerIOMPInstanciateAckMsg : public CATOmyPowerIOMPTransactionMsg
{
	CATDeclareClass;

public :

	CATOmyPowerIOMPInstanciateAckMsg();
	virtual ~CATOmyPowerIOMPInstanciateAckMsg();

	// CATIStreamMsg Interface
	virtual HRESULT StreamData    ( void **oBuffer, uint32 *oLen);
	virtual HRESULT UnstreamData  ( void  *iBuffer, uint32  iLen);
	virtual HRESULT FreeStreamData( void  *iBuffer, uint32  iLen);
	virtual HRESULT SetMessageSpecifications();

	virtual HRESULT SetProcessPid(int iProcPid){_procPid = iProcPid; return S_OK;};
	virtual HRESULT GetProcessPid(int & oProcessIdf){oProcessIdf = _procPid; return S_OK;};

private :
	int _procPid;
};

#endif
