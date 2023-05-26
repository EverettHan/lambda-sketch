/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATOmyPowerIOMPUpdateNotifyMsg_H
#define __CATOmyPowerIOMPUpdateNotifyMsg_H

#include "CATOmyPowerIOMPTransactionMsg.h"
#include "CATUuid.h"
#include "CATVVSUrl.h"

#include "CATCollec.h"
#include "CATListOfInt.h"
#include "CATUnicodeString.h"
#include "CATListOfCATVVSUrl.h"
#include "CATOMYCuteIO.h"

class ExportedByCATOMYCuteIO CATOmyPowerIOMPUpdateNotifyMsg : public CATOmyPowerIOMPTransactionMsg
{
	CATDeclareClass;

public :

	CATOmyPowerIOMPUpdateNotifyMsg();
	virtual ~CATOmyPowerIOMPUpdateNotifyMsg();

	// CATIStreamMsg Interface
	virtual HRESULT StreamData    ( void **oBuffer, uint32 *oLen);
	virtual HRESULT UnstreamData  ( void  *iBuffer, uint32  iLen);
	virtual HRESULT FreeStreamData( void  *iBuffer, uint32  iLen);
	virtual HRESULT SetMessageSpecifications();

	virtual HRESULT GetUpdateStats(int &oPart, int &oTotal);
	virtual HRESULT SetUpdateStats(int iPart, int iTotal);


private :
	int _transfertPart;
	int _transfertSize;

};

#endif
