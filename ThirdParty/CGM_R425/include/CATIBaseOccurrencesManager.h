#ifndef CATIBaseOccurrencesManager_H
#define CATIBaseOccurrencesManager_H

#include "CATBaseUnknown.h"
#include "CATPLMModelerOccInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerOccInterfaces IID IID_CATIBaseOccurrencesManager;
#else
extern "C" const IID IID_CATIBaseOccurrencesManager ;
#endif

/**
* @level Private
* @usage U3
*/

/**
* @nodoc 
*/
struct ChainedOccurrence;

/**
* @nodoc 
*/
class ExportedByCATPLMModelerOccInterfaces CATIBaseOccurrencesManager : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * @nodoc 
  */
  virtual void ReferenceOccurrence(CATBaseUnknown* occurrence, CATBaseUnknown* context = NULL) = 0;  

  /**
  * @nodoc 
  */
  virtual void UnreferenceOccurrence(CATBaseUnknown* occurrence) = 0;

  /**
  * @nodoc - not used
  */
  virtual void UnreferenceAllOccurrences() = 0;

  /**
  * @nodoc 
  */
  virtual ChainedOccurrence* GetChainedOccurrence() = 0;

  /**
  * @nodoc 
  */
  virtual ChainedOccurrence* ListReferencedOccurrencesInContext(CATBaseUnknown* context) = 0;
};

#endif
