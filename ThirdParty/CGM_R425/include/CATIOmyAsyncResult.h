/**
 * @level Protected
 * @usage U1
 */
#ifndef __CATOmyAsyncResult__H
#define __CATOmyAsyncResult__H

#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATError.h"

class ExportedByCATOMYCuteIO CATIOmyAsyncResult : public CATBaseUnknown
{
public:

  CATIOmyAsyncResult(int iTransactionId);

  ~CATIOmyAsyncResult();

	//Returns whether the asynchronous treatment is completed
	virtual HRESULT IsCompleted() = 0;
	
	
	/*
	* Request current task to be canceled
	* @return 
	* <code>S_OK</code> Task is being canceled
	* <code>S_FALSE</code> Task was alreay finished before cancel had been called
	* <code>E_*</code> Unexpected error
	*/
	virtual HRESULT CancelAsync() = 0;

	/*
	* Indicated whether the task has ended with sucess or failire. 
	* @return 
	* <code>S_OK</code> Task has ended with success
	* <code>S_FALSE</code> Task has been canceled. Task has failed but it was the caller aim
	* <code>E_FAIL</code> Error while executing the task. 
  */
  virtual HRESULT IsSuccess() = 0;

  virtual	HRESULT SetErrorMsg(const CATUnicodeString& iErrorMsg);

  virtual HRESULT GetErrorMsg(CATUnicodeString &oErrorMsg);

  void SetTransactionId(int iTransactionId){_transactionId = iTransactionId;};

protected:

  int _transactionId;
  CATError * _error;

private:

  static CATBoolean _isRunning;

  //Complets the treatment synchronously - only low level code can now use this method (friend class)
  HRESULT CompleteSynchronously();

  friend class CATOmyCioAccess;
  friend class CATOmySaveMPTestServices;
  friend class CATPLMGenericSaver;
  friend class CATPLMAsyncImpl;
};

#endif
