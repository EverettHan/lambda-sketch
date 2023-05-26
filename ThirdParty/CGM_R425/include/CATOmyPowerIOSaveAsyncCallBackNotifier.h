
/**
 * @level Protected
 * @usage U1
 */


#ifndef CATOmyPowerIOSaveAsyncCallBackNotifier_H
#define CATOmyPowerIOSaveAsyncCallBackNotifier_H

#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATOmyVVSAsyncCallBackNotifier.h"

/**
 * Class Specifying the Callback class for the Asynchronous Save. 
 *   Notifies both the upload percentage & the transaction end
 */
class ExportedByCATOMYCuteIO CATOmyPowerIOSaveAsyncCallBackNotifier : public CATOmyVVSAsyncCallBackNotifier
{

public : 
	CATOmyPowerIOSaveAsyncCallBackNotifier() {};
	virtual ~CATOmyPowerIOSaveAsyncCallBackNotifier(){};

	/**
	 * Specifies percentage update information.
	 *  returns S_OK if notify is OK, otherwise E_FAIL.
	 */
	virtual HRESULT UpdateProgressBar(int iTransfertPart, int iTransfertTotal){return E_NOTIMPL;};

	/**
	 * Notifies the end of deported treatment.
	 *  returns S_OK if notify is OK, otherwise E_FAIL.
	 */
	virtual HRESULT TransactionIsCompleted(CATIOmyAsyncResult& iResult){return E_NOTIMPL;};

	/**
	 * Pushes an error msg (then call Abort).
	 *  returns S_OK if notify is OK, otherwise E_FAIL.
	 */
	virtual HRESULT PushErrorMsg(CATUnicodeString iErrorMsg){return E_NOTIMPL;};

};

#endif
