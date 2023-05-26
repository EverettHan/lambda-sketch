/**
 * @level Protected 
 * @usage U1
 */

#ifndef __CATOmyPLMQLAsyncCallBackNotifier_H
#define __CATOmyPLMQLAsyncCallBackNotifier_H


#include "CATCollec.h"
#include "CATUnicodeString.h"
#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"
class CATIOmyAsyncResult;
class CATIPLMCompRecordReadSet;

class ExportedByCATOMYCuteIO CATOmyPLMQLAsyncCallBackNotifier : public CATBaseUnknown
{  
public :
	
	virtual	HRESULT StartResult(int iVersion)=0;

	virtual HRESULT EndResult(int iElapseTime)=0;

	virtual HRESULT StartBlock()=0;
		
	virtual HRESULT EndBlock(int iElapseTime)=0;

	virtual HRESULT StartPath(int iRank)=0;
		
	virtual HRESULT EndPath()=0;

	virtual HRESULT Record( CATBaseUnknown * iRecord, CATBoolean iAlreadyVisited)=0;

	virtual HRESULT GlobalReport(CATBaseUnknown * iError) = 0;

	virtual CATBoolean IsQueryPush() = 0;
	
  virtual HRESULT TransactionIsCompleted(CATIOmyAsyncResult& iResult)=0;

  virtual HRESULT GetRecordReadSet(CATIPLMCompRecordReadSet*& iResult)=0;

};

#endif
