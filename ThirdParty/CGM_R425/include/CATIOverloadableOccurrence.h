#ifndef CATIOverloadableOccurrence_H
#define CATIOverloadableOccurrence_H
/**
* @level Private
* @usage U1  
*/
#include "CATBaseUnknown.h"
#include "CATPLMIdentificationAccess.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentificationAccess IID IID_CATIOverloadableOccurrence;
#else
extern "C" const IID IID_CATIOverloadableOccurrence ;
#endif

class CATListPtrCATIPLMComponent;

/**
* Interface representing an overloadable occurrence.
*/
class ExportedByCATPLMIdentificationAccess CATIOverloadableOccurrence: public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /**
  * Get the first overloadable occurrence.
  * @param iOccurrenceToTest
  *  The input occurrence.
  * @param oFirstOverloadableOccurrence
  *  The first overloadable occurrence of the input occurrence
  * @param oRemainingOccurrence
  *  What is left of the input occurrence when the first overloadable occurrence has been removed.
  * @return
  *  <code>S_OK</code> if result could be computed
  *  <code>E_FAIL</code> otherwise.
  */
  virtual HRESULT GetFirstOverloadableOccurrence(CATListPtrCATIPLMComponent & iOccurrenceToTest,
                                         CATListPtrCATIPLMComponent & oFirstOverloadableOccurrence,
                                         CATListPtrCATIPLMComponent & oRemainingOccurrence) = 0;
};

#endif
