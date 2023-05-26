// COPYRIGHT Dassault Systemes 2009
/**
 * @level Protected
 * @usage U1
 */

#ifndef CATIPLMCompletionCheck_H
#define CATIPLMCompletionCheck_H

#include "CATPLMIntegration.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATPLMID.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegration IID IID_CATIPLMCompletionCheck;
#else
extern "C" const IID IID_CATIPLMCompletionCheck ;
#endif

//------------------------------------------------------------------

/**
* Interface to check the result of the new completion implementation versus an existing one
*/
class ExportedByCATPLMIntegration CATIPLMCompletionCheck: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * @returns
    *   S_OK    if the completion result is the same as the reference one
    *   S_FALSE if the completion result is different from the reference one
    *   E_*     if the completion or the comparaison failed
    */
    virtual HRESULT CheckCompletionResult(const CATLISTV(CATPLMID) & iReferenceIds)=0;
};
CATDeclareHandler(CATIPLMCompletionCheck, CATBaseUnknown);

class CATIPLMCompleteGraph;
class CATPLMIDSet;
class ExportedByCATPLMIntegration CATPLMCompletionCheckFactory
{
public:
  static CATIPLMCompletionCheck_var GetCompletionCheckFromCompleteGraph(CATIPLMCompleteGraph * iCompleteGraph);
  static CATIPLMCompletionCheck_var GetCompletionCheckFromList(const CATPLMIDs & iPLMIDs);
  static CATIPLMCompletionCheck_var GetCompletionCheckFromSet(const CATPLMIDSet & iPLMIDs);
};
//------------------------------------------------------------------

#endif
