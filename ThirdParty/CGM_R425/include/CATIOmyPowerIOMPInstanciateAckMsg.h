
/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATIOmyPowerIOMPInstanciateAckMsg_H
#define __CATIOmyPowerIOMPInstanciateAckMsg_H

#include "CATUuid.h"
#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"

#include "CATIOmyPowerIOMPTransactionMsg.h"

extern ExportedByCATOMYCuteIO IID IID_CATIOmyPowerIOMPInstanciateAckMsg ;

class CATIOmyPowerIOMPInstanciateAckMsg : public CATIOmyPowerIOMPTransactionMsg
{
	CATDeclareInterface;

public :
  virtual HRESULT SetProcessPid(int iProcPid) = 0;
	virtual HRESULT GetProcessPid(int & oProcPid) = 0;
};
#endif
