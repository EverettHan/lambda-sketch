/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATOmyPowerIOMPPLMQLTransactionMsg_H
#define __CATOmyPowerIOMPPLMQLTransactionMsg_H

#include "CATOmyPowerIOMPTransactionMsg.h"
#include "CATUuid.h"
#include "CATVVSUrl.h"

#include "CATCollec.h"
#include "CATMessageClass.h"
#include "CATUnicodeString.h"

#include "CATOMYCuteIO.h"

class CATICommMsg ;

class ExportedByCATOMYCuteIO CATOmyPowerIOMPPLMQLTransactionMsg : public CATOmyPowerIOMPTransactionMsg
{
	CATDeclareClass;

public :

	CATOmyPowerIOMPPLMQLTransactionMsg();
	virtual ~CATOmyPowerIOMPPLMQLTransactionMsg();

	// CATIStreamMsg Interface
	virtual HRESULT StreamData    ( void **oBuffer, uint32 *oLen);
	virtual HRESULT UnstreamData  ( void  *iBuffer, uint32  iLen);
	virtual HRESULT FreeStreamData( void  *iBuffer, uint32  iLen);
	virtual HRESULT SetMessageSpecifications();

	virtual HRESULT SetXMLFilter(CATUnicodeString & iXMLFilter){_XML = iXMLFilter; return S_OK;};
	virtual HRESULT GetXMLFilter(CATUnicodeString & oXMLFilter){oXMLFilter = _XML; return S_OK;};

	virtual HRESULT SetQueryType(CATBoolean iIsQueryPush){_IsQueryPush=iIsQueryPush ;return S_OK;};
	virtual HRESULT GetQueryType(CATBoolean &oIsQueryPush){oIsQueryPush=_IsQueryPush;return S_OK;};
private :
	CATUnicodeString _XML;
	CATBoolean _IsQueryPush;
};

#endif
