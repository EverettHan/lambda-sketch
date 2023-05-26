/**
 * @level Protected
 * @usage U1
 */

#ifndef  __CATOmyPowerIOMPErrorHandler_H
#define  __CATOmyPowerIOMPErrorHandler_H

// System Framework
#include "CATOmyPowerIOMPMsgHandler.h"
#include "CATOMYCuteIO.h"

class CATICommMsg ;

class  ExportedByCATOMYCuteIO CATOmyPowerIOMPErrorMsgHandler : public CATOmyPowerIOMPMsgHandler
{
	CATDeclareClass;

public:

	CATOmyPowerIOMPErrorMsgHandler();
	virtual ~CATOmyPowerIOMPErrorMsgHandler();

 protected:
	HRESULT HandleCATIOmyPowerIOMPTransactionMsg(const char * iMsgName, CATICommMsg * iMessage);

private:

	CATOmyPowerIOMPErrorMsgHandler(const CATOmyPowerIOMPErrorMsgHandler &iObjectToCopy);
	CATOmyPowerIOMPErrorMsgHandler & operator = (const CATOmyPowerIOMPErrorMsgHandler &iObjectToCopy);
};

#endif
