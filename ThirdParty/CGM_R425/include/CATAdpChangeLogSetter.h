#ifndef CATAdpChangeLogSetter_H
#define CATAdpChangeLogSetter_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @level Private
 * @usage U3
 */

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATOmxQIPtr.h"

class CATPLMID;
class CATUnicodeString;
class CATIAdpChangeLogSetter;

class ExportedByCATPLMIntegrationAccess CATAdpChangeLogSetter 
{
  //Add friend of classes doing set
  //friend class ImDoingSetAction...
  friend class SavePanel;
  friend class CATPLMItgTestAdpChangeLog;
public:
   /**
   * Constructor
   * @param *iUnknown
   *   For further use
   */
  CATAdpChangeLogSetter(CATBaseUnknown *iUnknown = NULL);
  ~CATAdpChangeLogSetter();
   
  /**
   * Set the action identifier under which the propagation has to be done .
   * @param iId
   *   The PLMId of the Current action.
   * @return
   *  An HRESULT value
   * <dl>
   *  <dt>S_OK</dt><dd>The Action is succesfully set</dd>
   *  <dt>E_FAIL</dt><dd>The PLMID is not valid. Some checking will be done on the PLM Type of the Action</dd>
   * </dl>  
   */
  HRESULT SetPLMIDOfTheCurrentAction (const CATPLMID & iId);

  /**
  * Activate the historisation mode for the ChangeLog.
  */
  HRESULT ActivateHistorisationMode () ;

   /**
   * Reset the current Action .  There is no more action set by the end user under which the propagation has to be done
   * @return
   *  An HRESULT value
   * <dl>
   *  <dt>S_OK</dt><dd>The Reset has been done successfully</dd>
   * </dl> 
   */
  HRESULT Reset();
  
  /**
   * Set the current message that will be supplied to the Transaction
   * @param iMessage
   *   The message as a CATUnicodeString
   * @return
   *  An HRESULT value
   * <dl>
   *  <dt>S_OK</dt><dd>The message is succesfully set</dd>
   * </dl>  
   */
  HRESULT SetCurrentMessage (const CATUnicodeString & iId);

private:
  CATOmxQIPtr<CATIAdpChangeLogSetter> _Wrapped;
};

#endif
