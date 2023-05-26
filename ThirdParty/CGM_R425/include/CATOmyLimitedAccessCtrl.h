// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATOmyLimitedAccessCtrl.h
// How to restrict access to certain infra services, when infra is calling applications or user code
//
//
//  April 2009  Creation  JRZ
//===================================================================
/**
* @level Private
* @usage U1
*/
#ifndef CATOmyLimitedAccessCtrl_H
#define CATOmyLimitedAccessCtrl_H

#include "CATOMYBaseSession.h"
#include "CATSysErrorDef.h"
#include "CATOmxSR.h"
#include "CATErrorMacrosEx.h"
#include "IUnknown.h"

/**
 * Obsolete, prefer CATProxyTransaction
 */
class ExportedByCATOMYBaseSession CATOmyLimitedAccessCtrl
{
public:

  // Type of application operations we want to enforce limited services
  enum OmyApplicationOperation
  {
    OmyImportNotification = 0x0,
    OmyRedrawListenerNotification = 0x1,
    OmyReplaceNotification = 0x2,
  };

  // Type of system components enforcing limited services 

  enum OmySystemComponent
  {
    OmyPLMAdapter = 0x0,
    OmySwitchEngine = 0x1,
    OmyTOS = 0x2,
    OmyClientCore = 0x3,
  };

  // list of system operation that may be restricted if an application operation is in progress
  // ForbiddenMatrix defines a binary | of forbidden operation.
  enum OmySystemOperation
  {
    Nothing = 0x0,
    AdapterAllAccess = 0x1,
    AdapterProviderAccess = 0x2,
    AdapterProviderDB = 0x4,
    Switch = 0x10,
    Modif = 0x100
  };

  /**
   * Set the system to restricted service before starting an application operation.
   * @param OmyApplicationOperation [in]
   *   The kind of application operation
   * @return
   *   an object which Release is mandatory to restore former state of the system
   *   this Release must performed even if an exception is thrown
   *
   * prefer calling OMY_START_RESTRICTED_ACCESS/OMY_END_RESTRICTED_ACCESS
   */
  static IUnknown* UnsafeStartRestrictedAccess(OmyApplicationOperation iOperation);

  /**
   * Controled if the passed in component operation is allowed by the system component.
   * This may not be the case if an application operation(s) is(are) in progress
   * @param OmySystemComponent [in]
   *   The system component
   * @param OmySystemOperation [in]
   *   The tested operation
   * @return
   *   S_OK
   *   E_FAIL operation not allowed by the component (+ logabend)
   *
   * All "operations" are allowed by default.
   * If OmyImportNotification or OmyReplaceNotification are set, the following become forbidden:
   *    { (OmyPLMAdapter,AdapterProviderDB), (OmySwitchEngine,Switch), (OmyTOS,Modif), (OmyClientCore,Modif) }
   * If OmyRedrawListenerNotification is set, the following become forbidden:
   *    { (OmyTOS,Modif), (OmyClientCore,Modif) }
   */
  static HRESULT IsOperationAllowed(OmySystemComponent iComponent, OmySystemOperation iOperation);

  /**
   * legacy for ODT, do not use
   */
  static void NoAssert();
};

/**
 * Yet another ugly macros set.
 * They allow to enter a "restricted access" section and ensure that whatever occurs (exceptions...) this section is closed
 *
 * @usage:
 * OMY_START_RESTRICTED_ACCESS(OmyXXXNotification);
 * {
 *   your code
 * }
 * OMY_END_RESTRICTED_ACCESS(OmyXXXNotification);
 */
#define OMY_START_RESTRICTED_ACCESS(iOmyApplicationOperation) \
  { \
    CATOmxSR<IUnknown> hCookie##iOmyApplicationOperation(CATOmyLimitedAccessCtrl::UnsafeStartRestrictedAccess(CATOmyLimitedAccessCtrl::iOmyApplicationOperation),Steal); \
    CATXH_ENSURE_DESTRUCTION(hCookie##iOmyApplicationOperation)

#define OMY_END_RESTRICTED_ACCESS(iOmyApplicationOperation) \
  } \
  do {} while (false)

#endif
