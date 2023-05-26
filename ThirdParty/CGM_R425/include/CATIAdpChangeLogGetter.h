#ifndef CATIAdpChangeLogGetter_H
#define CATIAdpChangeLogGetter_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @level Private
 * @usage U3
 */

#include "CATPLMIntegrationAccess.h"
#include "IUnknown.h"
#include "CATBaseUnknown_var.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationAccess IID IID_CATIAdpChangeLogGetter;
#else
extern "C" const IID IID_CATIAdpChangeLogGetter;
#endif

#include "CATPLMID.h"

/**
 * Class that defines an assistant, that will provide information about 
 * 
 */
class  ExportedByCATPLMIntegrationAccess CATIAdpChangeLogGetter : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  /**
   * Returns the PLMID of the current action.
   * @param oId
   *   The PLMId of the Current action.
   * @return
   *  An HRESULT value
   * <dl>
   *  <dt>S_OK</dt><dd>oId is valuated</dd>
   *  <dt>S_FALSE</dt><dd>there is no action set by the end user under which the propagation has to be done</dd>
   * </dl>  
   */
  virtual HRESULT GetPLMIDOfTheCurrentAction ( CATPLMID & oId ) =0;

  /*
  * Return the Historisation Mode activation.
  *
  * @return
  *  An HRESULT value
   * <dl>
   * <dt>S_OK</dt><dd>The Historisation Mode is activated.</dd>
   * <dt>S_FALSE</dt><dd>The Historisation Mode is not activated.</dd>
   * <dt>E_FAIL</dt>an error has occurred.
   * </dl>  
  */
  virtual HRESULT IsHistorisationModeActivated ( ) =0;

  /**
   * Returns the message entered by the end user to explain its modification
   * @param oMessage
   *   The Message 
   * @return
   *  An HRESULT value
   * <dl>
   *  <dt>S_OK</dt><dd>oMessage is valuated (even with an empty string)</dd>
   * </dl>  
   */
  virtual HRESULT GetCurrentMessage ( CATUnicodeString & oMessage ) =0;
 
};
CATDeclareHandler(CATIAdpChangeLogGetter, CATBaseUnknown);
#endif
