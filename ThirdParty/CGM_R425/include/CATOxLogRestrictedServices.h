#ifndef _CATOxLogRestrictedServices_H
#define _CATOxLogRestrictedServices_H
/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMTos                         AuthorizedModule
#define CATPLMLog                         AuthorizedModule
#define CATOxiOnlineOffline               AuthorizedModule
#define CATPLMLocalSaveBase               AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATOxLogRestrictedServices from a non-infrastructure module
@error 
#endif
#undef CATPLMTos
#undef CATPLMLog
#undef CATOxiOnlineOffline
#undef CATPLMLocalSaveBase
// ----------------------------------------------------------------------------------------------------------------------

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"

class CATComponentId;

class ExportedByCATPLMTos CATOxLogRestrictedServices
{
public:

  /**
  * Check if component was created offline
  *
  * @param iComponent
  *        Component to work on
  * @param oIsCreatedOffline
  *        The offline status
  * @return
  *        S_OK   : if status is available (created online or created offline)
  *        E_FAIL : if status cannot be returned
  *                 Invalid handle, or component is not ToCreate.
  */
  static HRESULT IsCreatedOffline (const CATComponentId & iComponent, CATBoolean & oIsCreatedOffline);

  /**
  * Check if component was created as duplicate
  *
  * @param iComponent
  *        Component to work on
  * @param oIsCreatedAsDuplicate
  *        The duplicate status
  * @return
  *        S_OK   : if status is available (created as duplicate or not)
  *        E_FAIL : if status cannot be returned
  *                 Invalid handle, or component is not ToCreate.
  */
  static HRESULT IsCreatedAsDuplicate (const CATComponentId & iComponent, CATBoolean & oIsCreatedAsDuplicate);

  /**
  * Force offline status
  * 
  * @param iComponent
  *        Component to work on
  * @param iCreatedOffline
  *        The new offline status
  * @return
  *        S_OK   : if status is changed
  *        E_FAIL : if status cannot be changed (e.g. : component is not logged as ToCreate).
  */
  static HRESULT ForceCreatedOffline (const CATComponentId & iComponent, CATBoolean iCreatedOffline);

private:

  CATOxLogRestrictedServices();
};

#endif
