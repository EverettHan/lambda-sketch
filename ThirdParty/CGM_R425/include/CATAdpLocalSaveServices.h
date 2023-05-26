#ifndef CATAdpLocalSaveServices_h
#define CATAdpLocalSaveServices_h

#include "CATPLMIntegrationAccess.h"
#include "CATBoolean.h"
#include "IUnknown.h"

/**
* @level Protected
* @usage U1
*/

/**
 * This service class is dedicated for LocalSave management.
 */


class ExportedByCATPLMIntegrationAccess CATAdpLocalSaveServices
{
public:
 /**
  * Performs a local save.
  */
  static HRESULT RunLocalSave();

  /**
   * This method is an access to LocalSave LOG status. It tells if there is something to save locally or not.
   * This method is dedicated to UI management or to automatic LocalSave management.
   * If your aim is to perform a LocalSave, you have to call LocalSave always (even if this method tells that it is not required)
   *                                        (for the editors and undo/redo management)
   * @param oIsRequired [out] TRUE if a localsave launched just after this call would have something to save locally
   *                          FALSE if a localsave launched just after this call would have nothing to save locally
   * @return S_OK : if the call ran OK
   *         E_FAIL if LocalSave is not activated or if an internal error occured
   */

  static HRESULT IsLocalSaveRequired (CATBoolean & oIsRequired);

private:
  CATAdpLocalSaveServices();
};


#endif
