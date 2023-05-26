/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATOMYASYNCCIONOTIFIERADAPTER_H
#define __CATOMYASYNCCIONOTIFIERADAPTER_H

#include "CATOMYCuteIO.h"
#include "CATOmyCioNotifier.h"
#include "CATListOfCATOmyCioUrlUsageCtx.h"

#include "CATVVSUrlToVoidPtrHashMap.h"
#include "CATVVSUrlToBaseUnknownVarHashMap.h"

class ExportedByCATOMYCuteIO CATOmyAsyncCioNotifierAdapter: public CATOmyCioNotifier
{
public:

	CATOmyAsyncCioNotifierAdapter(): CATOmyCioNotifier(), _TransactionNumber(0), _StreamCached(0), 
		_CtxNotificationMode(CATIOmyCioNotifier::NoCtxNotification), 
		_TransactionNotificationMode(CATIOmyCioNotifier::Commitment|CATIOmyCioNotifier::Abort|CATIOmyCioNotifier::Closure){};

	int GetTransactionNotificationMode() const;
	int GetContextNotificationMode() const;

	// Associate CATOmyCioUrlUsageCtx <-> void*
	void PutVoidPtr(CATOmyCioUrlUsageCtx& iUrlKey, void* iPtrVal);
	void GetVoidPtr(CATOmyCioUrlUsageCtx& iUrlKey, void*& oPtrVal);
	void RemoveVoidPtr(CATOmyCioUrlUsageCtx& iUrlKey, void*& oPtrVal);

	// Associate CATOmyCioUrlUsageCtx <-> CATBaseUnknown_var	
	void PutBaseUnknownVar(CATOmyCioUrlUsageCtx& iUrlKey, const CATBaseUnknown_var& iPtrVal);
	void GetBaseUnknownVar(CATOmyCioUrlUsageCtx& iUrlKey, CATBaseUnknown_var& oPtrVal);
	void RemoveBaseUnknownVar(CATOmyCioUrlUsageCtx& iUrlKey);

	// To be re-implemented by user !
	virtual ~CATOmyAsyncCioNotifierAdapter();

	virtual void OnStreamsInCache(CATListOfCATOmyCioUrlUsageCtx& iListOfStreams) = 0;
	virtual void OnEndOfAsyncTransaction(CATListOfCATOmyCioUrlUsageCtx& iListOfStreams) = 0;
	virtual void OnAbortOfAsyncTransaction(CATListOfCATOmyCioUrlUsageCtx& iListOfStreams) = 0;

protected:

	int _TransactionNumber;
	int _StreamCached;	

	CATVVSUrlToVoidPtrHashMap _VVSVoidPtrHashMap;
	CATVVSUrlToBaseUnknownVarHashMap _VVSBaseUnknownVarHashMap;

private:

	void TransCommitment(const CATOmyCuteIOTransaction* iTransaction);
	void TransAbort(const CATOmyCuteIOTransaction* iTransaction);
	void TransClosure(const CATOmyCuteIOTransaction* iTransaction);

	int _CtxNotificationMode;
	int _TransactionNotificationMode;
};
#endif
