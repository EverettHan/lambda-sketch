#ifndef CATIManageRepInstOccurrences_H
#define CATIManageRepInstOccurrences_H

#include "CATPLMModelerOccInterfaces.h"
#include "CATIBaseOccurrencesManager.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerOccInterfaces IID IID_CATIManageRepInstOccurrences;
#else
extern "C" const IID IID_CATIManageRepInstOccurrences;
#endif

/**
* @level Private
* @usage U3
*/

class CATBaseUnknown;
class CATListPtrCATBaseUnknown;

class ExportedByCATPLMModelerOccInterfaces CATIManageRepInstOccurrences : public CATIBaseOccurrencesManager
{
  CATDeclareInterface;

public:

  /**
  * @nodoc 
  */
  virtual HRESULT ListRelatedOccurrences(CATBaseUnknown* iContext, CATListPtrCATBaseUnknown& ioRelatedOccurrences) = 0;

  /**
  * @nodoc
  */
  virtual HRESULT ListAllRelatedOccurrences(CATListPtrCATBaseUnknown& ioRelatedOccurrences) = 0;
};

#endif
