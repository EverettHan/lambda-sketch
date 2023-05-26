#ifndef CATIPLMTransferOwnershipEngine_H
#define CATIPLMTransferOwnershipEngine_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfacesRestrictedUse.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"

class CATUnicodeString;
class CATListPtrCATIAdpPLMIdentificator;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMTransferOwnershipEngine;
#else
extern "C" const IID IID_CATIPLMTransferOwnershipEngine;
#endif

/**
 * This interface defines the unique protocol of communication between the users and the TO engine.
 * Use @href CATPLMEnginesToolbox#GetTransferOwnershipEngine to get a pointer on the maturity engine.
 * <br>Globally, the user can:
 * <ul>
 *   <li>Ask for a modification of the owner of PLM components.</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMTransferOwnershipEngine: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  virtual HRESULT AddComponents(const CATListPtrCATIAdpPLMIdentificator & iObjects) = 0;
  virtual HRESULT ChangeOwnership(const CATUnicodeString & iPerson,
                                  const CATUnicodeString & iOrganization,
                                  const CATUnicodeString & iProject) = 0;

};
CATDeclareHandler(CATIPLMTransferOwnershipEngine, CATBaseUnknown);
#endif
