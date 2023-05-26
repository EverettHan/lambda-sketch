#ifndef CATIPLMReplaceAbilityCheckerActivation_H
#define CATIPLMReplaceAbilityCheckerActivation_H

// small checks
#if defined (private) || defined(friend) || defined (protected)
#error Forbidden re-define of 'private', 'friend' or 'protected'
@error
#endif

#define AuthorizedModule 999
#define CATPLMIntegrationInterfaces  AuthorizedModule
#define CATPLMIntegration            AuthorizedModule
#define CATItgTestLib                AuthorizedModule
#define CATPLMManagementDlg          AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error This header is for internal use only
// Fatal error on solaris
@error
#endif
#undef CATPLMIntegrationInterfaces
#undef CATPLMIntegration
#undef CATItgTestLib
#undef CATPLMManagementDlg

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
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMReplaceAbilityCheckerActivation;
#else
extern "C" const IID IID_CATIPLMReplaceAbilityCheckerActivation;
#endif

/**
* This interface aims to give the ability to deactivate replace ability pre-checks on duplication engines.
*
* USAGE IS FORBIDDEN unless allowed by CATPLMIntegration team
*
*/
/**
* Helper enabling to give the ability to deactivate some replace ability pre-checks on duplication engines.
* <br><b>Role</b>: This interface aims to enable the caller to deactivate some checks performed by a duplication engine when the "replace in session" mode is activated. 
* When "replace in session" is asked for the duplicated components, the replace operation is made by deleting the instance of the duplicated object 
* and creating an instance of the new object. To prevent the user from performing the duplication in database and then faced up the impossibility to
* save his session to the database because he has no right to modify the instances, some editability checks are made on the instances which will be deleted 
* during the replace operation. If deletion will be refused by the server, then the user is warned that the duplication operation with replace in session is not possible.
*/
class ExportedByCATPLMIntegrationInterfaces CATIPLMReplaceAbilityCheckerActivation : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Deactivate some replace checks made by duplication engines.
  * <br><b>Role</b>: enables the user to deactivate the editability checks made on the instances before performing the duplicate operation. 
  */
  virtual void DeactivateEditabilityChecksOnInstances() = 0;
};

#endif
