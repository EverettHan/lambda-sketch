/**
 * @level Protected
 * @usage U1
 */

#ifndef  __CATOmyPowerIOMPDeathMsgHandler_H
#define  __CATOmyPowerIOMPDeathMsgHandler_H

// System Framework
#include "CATBBMessage.h"
#include "CATOMYCuteIO.h"
#define CATOmyCommandAsync_Migrated
#include "CATOmyCommandAsync.h"
#undef CATOmyCommandAsync_Migrated
#include "CATOmyAsyncProcess.h"

class CATICommMsg ;
class CATOmyAsyncProcess;


class CATOmyPowerIOMPDeathMsgCommand : public CATOmyCommandAsync<CATOmyAsyncProcessImplCATIA>
{
public:
  CATOmyPowerIOMPDeathMsgCommand():CATOmyCommandAsync<CATOmyAsyncProcessImplCATIA>(){}
  ~CATOmyPowerIOMPDeathMsgCommand() {}

  virtual void ReceiveMessage(CATOmyAsyncProcessImplCATIA* pProcess);
};

/** Handler of death messages. It receives messages sent by process registered
    to backbone when they die and check if is an check if they are relative to
    current process. */
class ExportedByCATOMYCuteIO CATOmyPowerIOMPDeathMsgHandler : public CATBBMessage
{
	CATDeclareClass;

public:

	CATOmyPowerIOMPDeathMsgHandler();
	virtual ~CATOmyPowerIOMPDeathMsgHandler();

	void HandleMessage(CATICommMsg * iMessage);

private:

	HRESULT InformCallerThatItsProcessIsDead(const char * iMsgName, CATICommMsg * iMessage);
	CATOmyPowerIOMPDeathMsgHandler(const CATOmyPowerIOMPDeathMsgHandler &iObjectToCopy);
	CATOmyPowerIOMPDeathMsgHandler & operator = (const CATOmyPowerIOMPDeathMsgHandler &iObjectToCopy);

  CATOmyPowerIOMPDeathMsgCommand* _pAsyncCommand; 
};

#endif
