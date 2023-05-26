
/**
 * @level Protected
 * @usage U1
 */

#ifndef  __CATOmyProcessMPAsyncMsgHandler_H
#define  __CATOmyProcessMPAsyncMsgHandler_H

// System Framework
#include "CATOmyPowerIOMPMsgHandler.h"
#include "CATOMYCuteIO.h"

class CATICommMsg ;

class  ExportedByCATOMYCuteIO CATOmyProcessMPAsyncMsgHandler : public CATOmyPowerIOMPMsgHandler
{
	CATDeclareClass;

public:

	CATOmyProcessMPAsyncMsgHandler();
	virtual ~CATOmyProcessMPAsyncMsgHandler();

  virtual HRESULT HandleCATOmyPowerIOMPListUrlsMsg(CATICommMsg *ipiMessage);
  virtual HRESULT HandleCATOmyPowerIOMPGenericTransactionMsg(CATICommMsg *ipiMessage);
  virtual HRESULT HandleCATOmyPowerIOMPPLMQLTransactionMsg(CATICommMsg *ipiMessage);
  virtual HRESULT HandleCATOmyPowerIOMPConnectMsg(CATICommMsg *ipiMessage);
  
 protected:
 
	HRESULT HandleCATIOmyPowerIOMPTransactionMsg(const char * iMsgName, CATICommMsg * iMessage);

private:

	CATOmyProcessMPAsyncMsgHandler(const CATOmyProcessMPAsyncMsgHandler &iObjectToCopy) = delete;
	CATOmyProcessMPAsyncMsgHandler & operator = (const CATOmyProcessMPAsyncMsgHandler &iObjectToCopy) = delete;
};

#endif
