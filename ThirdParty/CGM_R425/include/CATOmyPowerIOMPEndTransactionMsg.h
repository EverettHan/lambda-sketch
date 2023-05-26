/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATOmyPowerIOMPEndTransactionMsg_H
#define __CATOmyPowerIOMPEndTransactionMsg_H

#include "CATOmyPowerIOMPTransactionMsg.h"
#include "CATUuid.h"
#include "CATVVSUrl.h"

#include "CATCollec.h"
#include "CATUnicodeString.h"
#include "CATOMYCuteIO.h"
#include "CATBoolean.h"

class ExportedByCATOMYCuteIO CATOmyPowerIOMPEndTransactionMsg : public CATOmyPowerIOMPTransactionMsg
{
	CATDeclareClass;

public :

	CATOmyPowerIOMPEndTransactionMsg();
	virtual ~CATOmyPowerIOMPEndTransactionMsg();

	// CATIStreamMsg Interface
	virtual HRESULT StreamData    ( void **oBuffer, uint32 *oLen);
	virtual HRESULT UnstreamData  ( void  *iBuffer, uint32  iLen);
	virtual HRESULT FreeStreamData( void  *iBuffer, uint32  iLen);
	virtual HRESULT SetMessageSpecifications();

	virtual HRESULT PushVVSTransactionParam(CATUnicodeString &iParamName, CATUnicodeString &iParamValue);
	virtual HRESULT GetListVVSTransactionParam(CATListOfCATUnicodeString &oListParamName, CATListOfCATUnicodeString &oListParamValue);

	virtual HRESULT SetTransactionSuccess(CATBoolean iTransactionSucceess) ;
	virtual HRESULT GetTransactionSuccess(CATBoolean & oTransactionSuccess);

private :
	CATBoolean _isSucceeded;
	CATListOfCATUnicodeString _listParamName;
	CATListOfCATUnicodeString _listParamValue;

};

#endif
