/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2006
#ifndef CATIPLMMaturityAnalyzer_H
#define CATIPLMMaturityAnalyzer_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
class CATIPLMMaturityDescriptor;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMMaturityAnalyzer;
#else
extern "C" const IID IID_CATIPLMMaturityAnalyzer;
#endif

/**
 * This interface defines the unique protocol of communication between the users and the maturity engine.
 * Use @href CATIPLMMaturityEngine#AnalyzeMaturity to get a pointer on the maturity analyzer.
 * <br>Globally, the user can:
 * <ul>
 *   <li>Retrieve the maturity descriptions of components.</li>
 *   <li>Prepare the maturity changes he will apply through the CATIPLMMaturityEngine#ManageMaturity entry point.</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMMaturityAnalyzer: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/** 
 * Enables to obtain the next maturity descriptor available in the transaction.
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
  virtual HRESULT NextDescription( int & ioPosition, CATIPLMMaturityDescriptor *& oDescriptor ) = 0;
};
CATDeclareHandler(CATIPLMMaturityAnalyzer, CATBaseUnknown);
#endif
