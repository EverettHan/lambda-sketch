//===================================================================
// COPYRIGHT Dassault Systemes 2017/08/02
//===================================================================
// CATIPLMMaturityOrderedAnalyzer.cpp
// Header definition of class CATIPLMMaturityOrderedAnalyzer
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2017/08/02 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIPLMMaturityOrderedAnalyzer_H
#define CATIPLMMaturityOrderedAnalyzer_H

#include "CATPLMIntegrationInterfacesRestrictedUse.h"
#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
class CATIPLMMaturityDescriptor;


extern ExportedByCATPLMIntegrationInterfaces  IID IID_CATIPLMMaturityOrderedAnalyzer ;


class ExportedByCATPLMIntegrationInterfaces CATIPLMMaturityOrderedAnalyzer: public CATBaseUnknown
{
CATDeclareInterface;

public:

  /**
  * Enables to obtain the next maturity descriptor available in the transaction.
  * We ensure the identifier are matured with the same order as MaturityEngine input when communicating with the server.
  *
  * <br><b>Role</b>: This method enables the user to retrieve the maturity informations which were obtained from the
  * server during the transaction.
  * <li> The caller will be provided a @href CATIPLMMaturityDescriptor describing the component, its current state
  * and the differents events which can possibly be applied to make its maturity evolve.</li>
  * <li> The caller can specify to the descriptor a requirement for a future evolution through the
  * @href CATIPLMMaturityDescriptor#ApplyEvent method. The change will be really applied when triggering the
  * engine through the @href CATIPLMMaturityEngine#ManageMaturity call.</li>
  *
  * @param ioPosition [inout]
  *   The index of the current descriptor. Provide 0 value to start from the first position. The protocol
  * increments itself the counter which must be re-provided by the caller.
  *   The order in MaturityEngine input order.
  * @param oDescriptor [out]
  *   The maturity description of a component.
  *
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>S_FALSE</code> if no more descriptor are available.
  *   <code>E_INVALIDARG</code> if invalid position is provided.
  *   <code>E_FAIL</code> if a fatal error occured during the transaction. Nothing was done during the operation.
  *
  */
  virtual HRESULT NextDescription(int & ioPosition, CATIPLMMaturityDescriptor *& oDescriptor) = 0;

};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIPLMMaturityOrderedAnalyzer, CATBaseUnknown );

#endif