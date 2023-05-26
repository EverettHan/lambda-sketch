#ifndef CATAdpChangeLogGetter_H
#define CATAdpChangeLogGetter_H

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
class CATIAdpChangeLogGetter;

/**
* Class to access the getter
**/
class ExportedByCATPLMIntegrationAccess CATAdpChangeLogGetter
{
public:
  /**
   * Constructor
   * @param *iUnknown
   *   For further use
   */
  CATAdpChangeLogGetter(CATBaseUnknown *iUnknown = NULL);
  virtual ~CATAdpChangeLogGetter();
   
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
  HRESULT GetPLMIDOfTheCurrentAction ( CATPLMID & oId );
  
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
  HRESULT IsHistorisationModeActivated ( );

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
  HRESULT GetCurrentMessage ( CATUnicodeString & oMessage );
  
private:
  CATOmxQIPtr<CATIAdpChangeLogGetter> _Wrapped;
};

#endif
