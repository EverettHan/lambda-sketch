#ifndef CATIManageOccurrences_H
#define CATIManageOccurrences_H

#include "CATIBaseOccurrencesManager.h"
#include "CATPLMModelerOccInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerOccInterfaces IID IID_CATIManageOccurrences;
#else
extern "C" const IID IID_CATIManageOccurrences ;
#endif

/**
* @level Private
* @usage U3
*/

class CATBaseUnknown;
class CATListPtrCATIPLMNavOccurrence;

/**
* @nodoc 
*/
class ExportedByCATPLMModelerOccInterfaces CATIManageOccurrences : public CATIBaseOccurrencesManager
{
  CATDeclareInterface;

public:

  /**
  * @nodoc 
  */
  virtual HRESULT ListRelatedOccurrences(CATBaseUnknown* iContext, CATListPtrCATIPLMNavOccurrence& ioRelatedOccurrences) = 0;

  /**
  * @nodoc  - not used
  */
  virtual HRESULT ListAllRelatedOccurrences(CATListPtrCATIPLMNavOccurrence& ioRelatedOccurrences, int includingMyInstances = 0) = 0;

  /**
  * @nodoc  - not used
  */
  virtual HRESULT CountAllRelatedOccurrences(int & oNbAllOccurrences) = 0;
};

#endif
