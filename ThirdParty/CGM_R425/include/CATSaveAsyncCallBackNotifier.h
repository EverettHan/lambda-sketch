 /**
 * @level Protected
 * @usage U1
 */
 
 
 #ifndef CATSaveAsyncCallBackNotifier_H
 #define CATSaveAsyncCallBackNotifier_H
 
 
 #include "CATBaseUnknown.h"
   
/**
 * Class Specifying the Callback class for the Asynchronous Save. 
 *   Notifies the transaction end
 */
class ExportedByCATPLMIntegration CATSaveAsyncCallBackNotifier : public CATBaseUnknown
{

public : 
CATSaveAsyncCallBackNotifier() {};
virtual ~CATSaveAsyncCallBackNotifier(){};


  /**
  * Specifies the save end transaction.
  *  returns S_OK if notify is OK, otherwise E_FAIL.
*/
virtual HRESULT End(){return E_NOTIMPL;};
 
  /**
  * Specifies the save abort transaction.
  *  returns S_OK if notify is OK, otherwise E_FAIL.
*/
virtual HRESULT Abort(){return E_NOTIMPL;};

};

#endif
