// COPYRIGHT Dassault Systemes 2009
/**
 * @level Protected
 * @usage U1
 */

#ifndef CATIPLMCompletionTypeRetriever_H
#define CATIPLMCompletionTypeRetriever_H

#include "CATPLMIntegration.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATPLMID.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegration IID IID_CATIPLMCompletionTypeRetriever;
#else
extern "C" const IID IID_CATIPLMCompletionTypeRetriever ;
#endif

//------------------------------------------------------------------

/**
* Interface representing an object that retrieve the PLMType to select for completion
* from a given PLMType . TO BE REMOVED ASAP !!!!
*/
class CATPLMType;
class CATListPtrCATPLMType;
class ExportedByCATPLMIntegration CATIPLMCompletionTypeRetriever: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
    virtual HRESULT GetPLMTypeForCompletion(CATPLMType * iType, CATListPtrCATPLMType & iTypesForCompletion)  =0;
};
CATDeclareHandler(CATIPLMCompletionTypeRetriever, CATBaseUnknown);
//------------------------------------------------------------------

#endif
