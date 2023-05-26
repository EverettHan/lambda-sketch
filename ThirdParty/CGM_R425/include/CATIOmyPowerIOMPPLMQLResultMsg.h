
/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATIOmyPowerIOMPPLMQLResultMsg_H
#define __CATIOmyPowerIOMPPLMQLResultMsg_H

#include "CATUuid.h"
#include "CATVVSUrl.h"
#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"

#include "CATCollec.h"
#include "CATOmyAsyncProcessConstants.h"

#include "CATIOmyPowerIOMPTransactionMsg.h"

extern ExportedByCATOMYCuteIO IID IID_CATIOmyPowerIOMPPLMQLResultMsg ;

class ExportedByCATOMYCuteIO CATIOmyPowerIOMPPLMQLResultMsg : public CATIOmyPowerIOMPTransactionMsg
{
	CATDeclareInterface;

public :
	virtual HRESULT GetExpandResultStep(CATOmyAsyncProcessConstants::ExpandResultState & oResultState) = 0;
	virtual HRESULT SetExpandResultStep(CATOmyAsyncProcessConstants::ExpandResultState   iResultState) = 0;
	virtual HRESULT SetIntArg(int iArg) = 0;
	virtual HRESULT GetIntArg(int & oArg) = 0;
	virtual HRESULT SetRecordRead(CATBaseUnknown * iRecordRead, CATBoolean iAlreadyVisited) = 0;
	virtual HRESULT GetRecordRead(CATBaseUnknown ** oRecordRead, CATBoolean & oAlreadyVisited) = 0;
	virtual HRESULT SetGlobalReport(CATBaseUnknown * iError) = 0;
	virtual HRESULT GetGlobalReport(CATBaseUnknown ** oError) = 0;

};
#endif
