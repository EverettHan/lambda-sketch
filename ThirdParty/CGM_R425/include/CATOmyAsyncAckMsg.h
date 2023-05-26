/**
 * @level Protected 
 * @usage U1
 */

#ifndef __CATOmyAsyncAckMsg_H
#define __CATOmyAsyncAckMsg_H

#include "CATBBMessage.h"
#include "CATCollec.h"
#include "CATOMYCuteIO.h"

class ExportedByCATOMYCuteIO CATOmyAsyncAckMsg : public CATBBMessage
{  
	CATDeclareClass;

public :

	CATOmyAsyncAckMsg();
	virtual ~CATOmyAsyncAckMsg();

	// CATIStreamMsg Interface
	virtual HRESULT StreamData    ( void **oBuffer, uint32 *oLen);
	virtual HRESULT UnstreamData  ( void  *iBuffer, uint32  iLen);
	virtual HRESULT FreeStreamData( void  *iBuffer, uint32  iLen);
	virtual HRESULT SetMessageSpecifications();
	
};

#endif
