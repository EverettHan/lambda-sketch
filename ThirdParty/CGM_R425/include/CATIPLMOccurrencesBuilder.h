// COPYRIGHT Dassault Systemes 2015
#ifndef CATIPLMOccurrencesBuilder_H
#define CATIPLMOccurrencesBuilder_H

/**
* @level Protected
* @usage U3
*/

#include "CATPLMIntegrationInterfaces.h"

#include "CATBaseUnknown.h"

class CATIPLMNavOccurrence;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMOccurrencesBuilder;
#else
extern "C" const IID IID_CATIPLMOccurrencesBuilder ;
#endif

/**
* This interface exposes services dedicated to build the filtered occurrence tree resulting from an open operation.
* Use @href CATIPLMOpenEngine#GetOccurrencesBuilder to get a pointer on this interface.
*/
class ExportedByCATPLMIntegrationInterfaces CATIPLMOccurrencesBuilder: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**
  * Creates a new root occurrence and the occurrence tree under
  *
  * @param iRootComponent [in]
  *   The input complete graph defining the set of elements to open.
  * @param oRootOccurrence [out,CATBaseUnknown#Release]
  *   The out pointer.
  *
  * @return
  *   <code>S_OK</code> OK.
  *   <code>E_FAIL</code> Failure.
  */
  virtual HRESULT CreateOccurrences(CATBaseUnknown & iRootComponent, CATIPLMNavOccurrence *& oRootOccurrence)=0; 

  /**                                            
  * Updates the occurrence tree under an existing root occurrence
  *
  * @param iRootComponent [in]
  *   The input complete graph defining the set of elements to open.
  * @param iRootOccurence [in]
  *   The out pointer.
  *
  * @return
  *   <code>S_OK</code> OK.
  *   <code>E_FAIL</code> Failure.
  */
  virtual HRESULT EnrichOccurrences(CATBaseUnknown & iRootComponent, const CATIPLMNavOccurrence & iRootOccurrence)=0; 
};
#endif
