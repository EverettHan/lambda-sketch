#ifndef CATPLMSplitRegistration_H 
#define CATPLMSplitRegistration_H
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMIdentificationAccess        AuthorizedModule
#define CATAuthoringBaseUI                AuthorizedModule
#define CATOxiUFOLog                      AuthorizedModule
#define CATOxiUFOSaveLog                      AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMSplitRegistration from a non-infrastructure module
@error 
#endif
#undef CATPLMIdentificationAccess
#undef CATAuthoringBaseUI
#undef CATOxiUFOLog
#undef CATOxiUFOSaveLog

  // ----------------------------------------------------------------------------------------------------------------------


#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"

class CATComponentId;

/**
* Configured delete registration
*/
class ExportedByCATPLMIdentificationAccess CATPLMConfiguredDeleteRegistration
{
public:
  
  /**
  *
  * <br><b>Role</b>: warn the log of operations
  * that a configured delete is about to happen.
  * All split that will occur until End or Cancel
  * is called will be flagged as configured delete
  * splits.
  * 
  * @return
  * <dl>
  * <dt><code>S_OK</code>log is successfully warned<dd>
  * <dt><code>E_FAIL</code>a configured delete is already under way<dd>
  * </dl>
  */
  static HRESULT BeginConfiguredDelete();

  /**
  *
  * <br><b>Role</b>: warn the log of operations
  * that the configured delete has ended. The splits
  * that occured since previous call to Begin are
  * flagged as configured delete and will be sent as
  * such at next save.
  * @return
  * <dl>
  * <dt><code>S_OK</code>log is successfully warned<dd>
  * <dt><code>E_FAIL</code>no configured delete was already under way<dd>
  * </dl>
  */
  static HRESULT EndConfiguredDelete();

};

#endif
