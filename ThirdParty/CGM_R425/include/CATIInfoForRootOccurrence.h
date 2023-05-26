#ifndef CATIInfoForRootOccurrence_H
#define CATIInfoForRootOccurrence_H

/**
* @level Private
* @usage U3
*/

#include "CATPLMModelerOccInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerOccInterfaces IID IID_CATIInfoForRootOccurrence;
#else
extern "C" const IID IID_CATIInfoForRootOccurrence ;
#endif

/**
 * Totally deprecated interface, DO NOT USE
 */
class ExportedByCATPLMModelerOccInterfaces CATIInfoForRootOccurrence: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**return E_FAIL*/
  virtual HRESULT GetMicInstance(CATBaseUnknown*& piMicInstance) const = 0;
};

CATDeclareHandler(CATIInfoForRootOccurrence, CATBaseUnknown);

#endif
