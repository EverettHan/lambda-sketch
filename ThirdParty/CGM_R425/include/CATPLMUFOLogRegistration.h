#ifndef CATPLMUFOLogRegistration_H 
#define CATPLMUFOLogRegistration_H

// COPYRIGHT DASSAULT SYSTEMES 2013
/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATUFO                            AuthorizedModule
#define CATOxiUFOLog                      AuthorizedModule
#define CATOxiUFOSaveLog                  AuthorizedModule
#define CATPLMTransaction                 AuthorizedModule
#define CATOxUFOCMMTestLib                AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMSplitRegistration from a non-infrastructure module
@error
#endif
#undef CATUFO
#undef CATOxiUFOLog
#undef CATOxiUFOSaveLog
#undef CATPLMTransaction
#undef CATOxUFOCMMTestLib                
// ----------------------------------------------------------------------------------------------------------------------

#include "IUnknown.h"
#include "ExportedByCATPLMIdentification.h"
#include "CATListPtrCATIPLMComponent.h"

class CATComponentId;
class CATUnicodeString;

class ExportedByCATPLMIdentification CATPLMUFOLogRegistration
{
public:
  /**
  * Register change of applicability
  *
  * @param iUpdatedApplicability
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RegisterModifyApplicability(const CATComponentId & iUpdatedApplicability);

  static HRESULT RegisterOperation(const CATComponentId & iComponent, const CATUnicodeString & iOperation);
  static HRESULT RegisterOperation(const CATListPtrCATIPLMComponent  & iComponents, const CATUnicodeString & iOperation);
  static HRESULT RegisterLogicalCloneAndCreateOldConnection(const CATIPLMComponent & iNewConnection, const CATIPLMComponent & iOldConnection, const CATIPLMComponent & iOldInstance, const CATIPLMComponent & iNewInstance);
  static HRESULT RegisterLogicalCloneAndUpdateOldConnection(const CATIPLMComponent & iNewConnection, const CATIPLMComponent & iOldConnection, const CATIPLMComponent & iOldInstance, const CATIPLMComponent & iNewInstance);


};

#endif
