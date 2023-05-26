#ifndef CATIAdpChangeLogSetter_H
#define CATIAdpChangeLogSetter_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @level Private
 * @usage U3
 */

#include "CATPLMIntegrationAccess.h"
#include "IUnknown.h"
#include "CATBaseUnknown_var.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationAccess IID IID_CATIAdpChangeLogSetter;
#else
extern "C" const IID IID_CATIAdpChangeLogSetter;
#endif

#include "CATPLMID.h"

/**
 * Class that defines an assistant, that will provide information about 
 * 
 */
class  ExportedByCATPLMIntegrationAccess CATIAdpChangeLogSetter : public CATBaseUnknown
{
  CATDeclareInterface;
public:

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
  virtual HRESULT SetPLMIDOfTheCurrentAction (const CATPLMID & iId) =0;

  /**
  * Activate the historisation mode for the ChangeLog.
  * @return
  *  An HRESULT value
  * <dl>
  *  <dt>S_OK</dt><dd>The historisation Mode is succesfully set</dd>
  *  <dt>E_FAIL</dt><dd>An error has occurred.</dd>
  * </dl>  
  */
  virtual HRESULT ActivateHistorisationMode () =0;

  /**
   * Reset the current Action or the historisation.  There is no more action set by the end user under which the propagation has to be done
   * @return
   *  An HRESULT value
   * <dl>
   *  <dt>S_OK</dt><dd>The Reset has been done successfully</dd>
   * </dl> 
   */
   virtual HRESULT Reset() =0;

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
  virtual HRESULT SetCurrentMessage (const CATUnicodeString & iId) =0;
};
CATDeclareHandler(CATIAdpChangeLogSetter, CATBaseUnknown);
#endif
