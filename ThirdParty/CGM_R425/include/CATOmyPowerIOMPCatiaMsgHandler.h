/**
* @level Protected
* @usage U1
*/

#ifndef  __CATOmyPowerIOMPCatiaMsgHandler_H
#define  __CATOmyPowerIOMPCatiaMsgHandler_H

// System Framework
#include "CATOmyPowerIOMPMsgHandler.h"
#include "CATOMYCuteIO.h"

class CATICommMsg ;
class CATIOmyPowerIOMPPLMQLResultMsg;

class  ExportedByCATOMYCuteIO CATOmyPowerIOMPCatiaMsgHandler : public CATOmyPowerIOMPMsgHandler
{
  CATDeclareClass;

public:

  CATOmyPowerIOMPCatiaMsgHandler();
  virtual ~CATOmyPowerIOMPCatiaMsgHandler();

  /** Following methods deal with messages that can be received by 'this'
  * Their common argument, ipiMessage, is the message received by
  * HandleMessage. They must be virtual so that their behaviors will be easily
  * tested by inheritance.
  */
  virtual HRESULT HandleCATOmyPowerIOMPInstanciateAckMsg(CATICommMsg *ipiMessage);
  virtual HRESULT HandleCATOmyPowerIOMPProcessIsConnectedMsg(CATICommMsg *ipiMessage);
  virtual HRESULT HandleCATOmyPowerIOMPUpdateNotifyMsg(CATICommMsg *ipiMessage);
  virtual HRESULT HandleCATPLMQLAsyncResultMsg(CATICommMsg *ipiMessage);  
  virtual HRESULT HandleCATOmyPowerIOMPEndTransactionMsg(CATICommMsg *ipiMessage);
  virtual HRESULT HandleCATPLMQLAsyncResultMsgList(CATICommMsg *ipiMessage);
  virtual HRESULT HandleCATOmyPowerIOMPTestTransactionMsg(CATICommMsg *ipiMessage);

protected:
  virtual HRESULT HandleCATIOmyPowerIOMPTransactionMsg(const char * iMsgName, CATICommMsg * iMessage);

private:

  static void AnalyseAsyncData(void * iAsyncData);

  HRESULT HandleCATIOmyPowerIOMPPLMQLResultMsg(CATIOmyPowerIOMPPLMQLResultMsg *ipiMessage);
  
  CATOmyPowerIOMPCatiaMsgHandler(const CATOmyPowerIOMPCatiaMsgHandler &iObjectToCopy) = delete;
  CATOmyPowerIOMPCatiaMsgHandler & operator = (const CATOmyPowerIOMPCatiaMsgHandler &iObjectToCopy) = delete;
};

#endif
