
/**
 * @level Protected
 * @usage U1
 */


#ifndef CATOmyVVSAsyncCallBackNotifier_H
#define CATOmyVVSAsyncCallBackNotifier_H

#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATIOmyAsyncResult.h"

class CATUuid;

enum CATOmyVVSAsyncCallBackNotifierResult
{
  CATOmyVVSAsyncCallBackNotifierResult_Succeeded = 0,
  CATOmyVVSAsyncCallBackNotifierResult_Failed,
  CATOmyVVSAsyncCallBackNotifierResult_Canceled
};

/**
 * Class Specifying the Callback class for the Asynchronous Save. 
 *   Notifies both the upload percentage & the transaction end
 */
class ExportedByCATOMYCuteIO CATOmyVVSAsyncCallBackNotifier : public CATBaseUnknown
{

public : 
	CATOmyVVSAsyncCallBackNotifier() {};
	virtual ~CATOmyVVSAsyncCallBackNotifier(){};

	/**
	 * Specifies percentage update information.
	 *  returns S_OK if notify is OK, otherwise E_FAIL.
	 */
	virtual HRESULT UpdateProgressBar(int iTransfertPart, int iTransfertTotal)=0;

  /**
	 * Specifies percentage update information with byte count;
	 *  returns S_OK if notify is OK, otherwise E_FAIL.
	*/
	virtual HRESULT UpdateProgressBar(int /*iTransfertPart*/, int /*iTransfertTotal*/, int /*iByteCountTransfertPart*/) { return E_NOTIMPL; };

	/**
	 * Notifies the end of deported treatment.
	 *  returns S_OK if notify is OK, otherwise E_FAIL.
	 */
	virtual HRESULT TransactionIsCompleted(CATIOmyAsyncResult& /*iResult*/)  { return E_NOTIMPL; };

	/**
	 * Notifies the end of deported treatment.
	 *  returns S_OK if notify is OK, otherwise E_FAIL.
	 */
	virtual HRESULT TransactionIsCompleted(CATOmyVVSAsyncCallBackNotifierResult& /*iResult*/) { return E_NOTIMPL; };
};

#endif
