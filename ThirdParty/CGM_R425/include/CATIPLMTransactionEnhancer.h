#ifndef CATIPLMTransactionEnhancer_H
#define CATIPLMTransactionEnhancer_H

// small checks
#if defined (private) || defined(friend) || defined (protected)
#error Forbidden re-define of 'private', 'friend' or 'protected'
@error
#endif

#define AuthorizedModule 999
#define CATPLMIntegrationInterfaces  AuthorizedModule
#define CATPLMIntegration            AuthorizedModule
#define CATPLMItgTests               AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error This header is for internal use only
// Fatal error on solaris
@error
#endif
#undef CATPLMIntegrationInterfaces
#undef CATPLMIntegration
#undef CATPLMItgTests

#if _MK_MODNAME_ == AuthorizedModule
#pragma message("[Warning] Delared module has not been undeclared correctly.")
#endif
#undef AuthorizedModule

#include "CATBaseUnknown.h"
#include "CATPLMIntegrationInterfaces.h"
class CATUnicodeString;
class CATOmxKeyString;
class CATOmxAny;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMTransactionEnhancer;
#else
extern "C" const IID IID_CATIPLMTransactionEnhancer;
#endif

/**
 * This interface aims to give the ability to customize a server transaction.
 *
 * USAGE IS FORBIDDEN unless allowed by CATPLMIntegration team
 *
 */
 /**
  * Helper enabling to give the ability to customize a server transaction.
  * <br><b>Role</b>: This interface aims to enable the caller to valuate specific parameters on the next transaction launched by the engine.
  *
  * <code> Usage sample:
  *   CATPLMSessionManagementBuilder Builder;
  *   CATOmxSR<CATIPLMSaveEngine> srEngine;
  *   CATPLMSessionManagementBuilder::GetSaveEngine(srEngine.AsPtrRef());
  *   CATOmxQIPtr<CATIPLMTransactionEnhancer> srSaveTransactionEnhancer(srEngine);
  *   srSaveTransactionEnhancer->AddCustomizedParameter("customdata", "Change Id", "1032547698BADCFE1032547698BADCFE");
  *   srSaveTransactionEnhancer->AddCustomizedParameter("customlisteners", "com.dassault_systemes.enovia.changeaction.servicesimpl.ChangeActionTransactionListener", "");
  *   srSaveTransactionEnhancer->AddCustomizedParameter("customlisteners", "com.dassault_systemes.enovia.test.tests.impl.testTransactionListener", "");
  *   srEngine->Save();
  * </code>
  */
class ExportedByCATPLMIntegrationInterfaces CATIPLMTransactionEnhancer : public CATBaseUnknown
{
  CATDeclareInterface;

public:

/**
 * Valuate a parameter for the next write transaction.
 * <br><b>Role</b>: Enables to give as in put a parameter which will be added to the next write transaction launched on the server (save, versioning).
 *
 * @param iName [in]
 *  iName can be "customdata" or "customlisteners" or "customtransactionparameters"
 * @param iKey [in]
 *  The parameter to set
 * @param iValue [in]
 *  The value to set for this parameter
 *
 * @return
 * <dl>
 * <dt><code>S_OK</code> if the operation is enabled.
 * <dt><code>E_FAIL</code> if an unexpected error occured.
 * </dl>
 */
  virtual HRESULT AddCustomizedParameter( const CATUnicodeString & iName, const CATOmxKeyString & iKey, const CATOmxAny & iValue ) = 0;
};

#endif
