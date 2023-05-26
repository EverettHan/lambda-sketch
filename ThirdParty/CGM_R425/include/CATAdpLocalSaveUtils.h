#ifndef CATAdpLocalSaveUtils_h
#define CATAdpLocalSaveUtils_h

#include "CATPLMIntegrationAccess.h"
#include "CATBoolean.h"
#include "IUnknown.h"
#include "CATOmbLifeCycleRootsBag.h"

/**
* @level Protected
* @usage U1
*/

/**
 * This service class is dedicated for LocalSave management.
 */
#define AuthorizedModule     999
#define CATPLMIntegrationAccess  AuthorizedModule
#define CATPLMTestAPI  AuthorizedModule
#define X3DSessionLocalSave AuthorizedModule
#define CATMaintenanceIntegrationTest AuthorizedModule
#define CATPLMItgTestLocalSave AuthorizedModule
#define CATPLMSettingsLocalSaveIntegration AuthorizedModule
#define CATPLMIdentification_PLM AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else
#error Forbidden Access to CATAdpLocalSaveUtils
@error
#endif

#undef CATPLMIntegrationAccess
#undef CATPLMTestAPI
#undef X3DSessionLocalSave
#undef CATMaintenanceIntegrationTest
#undef CATPLMItgTestLocalSave
#undef CATPLMSettingsLocalSaveIntegration
#undef CATPLMIdentification_PLM

class ExportedByCATPLMIntegrationAccess CATAdpLocalSaveUtils
{
public:
 /**
  * Restore the valid image, as if restored launching a session.
  * This must be called only once, and NOT in any process which launch a Local save restore
  * Returns S_OK if succeeded
  * E_ABORT if image is broken (but a new one is automatically created ! You can continue, but user image is lost)
  * E_XXX else
  */
  static HRESULT Restore();

  //Use this if you have no editor which can handle opened elements.
  static HRESULT Restore(CATOmbLifeCycleRootsBag &iBag);

  /*
  * Starts a new session. Previous Local save image is erased.
  * This must be called only once, and NOT in any process which launch a Local save restore
  * Returns S_OK if succeeded
  * E_ABORT if image is broken (but a new one is automatically created ! You can continue, but user image is lost)
  * E_XXX else
  */
  static HRESULT NewSession();

private:
  CATAdpLocalSaveUtils();
};


#endif
