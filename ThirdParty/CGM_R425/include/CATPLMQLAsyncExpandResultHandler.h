#ifndef  __CATPLMQLAsyncExpandResultHandler_H
#define  __CATPLMQLAsyncExpandResultHandler_H

#include "CATUnicodeString.h"
#include <iostream.h>

#include "CATAsyncServices.h"

// Sys.
#include "CATAssert.h"
#include "CATSysMacros.h"

// Comm.
#include "CATGetBackboneConnection.h"
#include "CATICommunicator.h"
#include "CATICommunicatorLoop.h"    // To wait a message
#include "CATIMessageReceiver.h"     // To set the handle class
#include "CATCommunicatorFactory.h"
#include "CATInstantiateComponent.h"

#include "CATIOmyPowerIOMPEndTransactionMsg.h"
#include "CATIPLMExpandResultHandler.h"
#include "CATIPLMRecordRead.h"

class CATIOmyPowerIOMPPLMQLResultMsgList;

class ExportedByCATAsyncServices CATPLMQLAsyncExpandResultHandler : public CATIPLMExpandResultHandler
{

CATDeclareClass;

public:
	CATPLMQLAsyncExpandResultHandler(int iTransactionId);
	~CATPLMQLAsyncExpandResultHandler();

	HRESULT StartResult(int iVersion);

	HRESULT EndResult(int iElapseTime);

	HRESULT StartBlock();

	HRESULT EndBlock(int iElapseTime);

	HRESULT StartPath(int iRank);

	HRESULT EndPath();

	HRESULT Record( CATIPLMRecordRead * iRecord, CATBoolean iAlreadyVisited);

	HRESULT GlobalReport(CATIPLMError * iError);

private:
	int _TransactionId;
  CATIOmyPowerIOMPPLMQLResultMsgList* _piMessages;
  void CleanMessageList();

  inline void dumpMessage(const CATUnicodeString& message) const;
  FILE* _outputFile;
  /** in ms */
  CATLONG32 _nbMilliSecondsBeforeSending;
  CATTimeValue _timeOfLastSent;
};
#endif
