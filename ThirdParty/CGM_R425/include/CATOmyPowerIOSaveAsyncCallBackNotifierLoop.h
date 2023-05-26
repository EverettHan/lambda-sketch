/**
 * @level Protected
 * @usage U1
 */


#ifndef CATOmyPowerIOSaveAsyncCallBackNotifierLoop_H
#define CATOmyPowerIOSaveAsyncCallBackNotifierLoop_H

#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATOmyPowerIOSaveAsyncCallBackNotifier.h"
#include "CATListOfCATUnicodeString.h"


class CATICommunicatorLoop;
/**
 * Class Specifying the Callback class for the Asynchronous Save.
 *   Notifies both the upload percentage & the transaction end
 */
class ExportedByCATOMYCuteIO CATOmyPowerIOSaveAsyncCallBackNotifierLoop : public CATOmyPowerIOSaveAsyncCallBackNotifier
{

public :
  CATOmyPowerIOSaveAsyncCallBackNotifierLoop();
  virtual ~CATOmyPowerIOSaveAsyncCallBackNotifierLoop();

  /**
   * Specifies percentage update information.
   *  returns S_OK if notify is OK, otherwise E_FAIL.
   */
  virtual HRESULT UpdateProgressBar(int iTransfertPart, int iTransfertTotal);

  /**
   * Notifies the end of deported treatment.
   *  returns S_OK if notify is OK, otherwise E_FAIL.
   */
  virtual HRESULT TransactionIsCompleted(CATIOmyAsyncResult& iResult);

  /**
   * Pushes an error msg (then call Abort).
   *  returns S_OK if notify is OK, otherwise E_FAIL.
   */
  virtual HRESULT PushErrorMsg(CATUnicodeString iErrorMsg);


  /*
   * For synchronous interrogation
   */
  virtual HRESULT GetUpdatedProcessBar(CATULONG64 &oTransfertPart, CATULONG64 &oTransfertTotal);
  virtual CATBoolean IsSucceeded(){return _IsSucceeded;};
  virtual HRESULT GetErrorMsg(CATListOfCATUnicodeString &oListErrorMsg);

private:
  CATBoolean _IsReady;
  CATBoolean _IsSucceeded;
  CATULONG64 _TransfertPart, _TransfertTotal;
  CATListOfCATUnicodeString _listErrorMsg;

};

#endif
