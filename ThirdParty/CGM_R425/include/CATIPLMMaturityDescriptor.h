/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2006
#ifndef CATIPLMMaturityDescriptor_H
#define CATIPLMMaturityDescriptor_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
class CATPLMID;
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMMaturityDescriptor;
#else
extern "C" const IID IID_CATIPLMMaturityDescriptor;
#endif

/**
 * This interface defines the unique protocol of communication between the users and the maturity engine.
 * Use @href CATIPLMMaturityAnalyzer#NextDescription to get a pointer on the maturity analyzer.
 * <br>Globally, the user can:
 * <ul>
 *   <li>Retrieve the maturity state of the component.</li>
 *   <li>Parse the events which can possibly be applied to the component.</li>
 *   <li>Ask for an event to be applied during the next @href CATIPLMMaturityEngine#ManageMaturity call.</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMMaturityDescriptor: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/** 
 * Enables to obtain the component the descriptor deals with and its maturity state.
 *
 * <br><b>Role</b>: This method enables to retrieve information the descriptor deals with:
 * <li> The component which maturity descriptor deals with.</li>
 * <li> The current state of this component.</li>
 *
 * @param oComponent [out]
 *   The component described by the descriptor.
 * @param oState [out]
 *   The current state of the component.
 *
 * @return
 *   <code>S_OK</code> if everything ran ok.
 *   <code>E_FAIL</code> if a fatal error occured during the transaction. Nothing was done during the operation.
 *
 */
  virtual HRESULT GetComponentInfo( CATPLMID & oComponent, CATUnicodeString & oState ) = 0;

/** 
 * Enables to obtain the events which can be applied to the described component.
 *
 * <br><b>Role</b>: This method enables to retrieve the events the user can apply to the component to make its 
 * maturity evolve.
 *
 * @param ioPosition [inout]
 *   The index of the current event. Provide 0 value to start from the first position. The protocol
 * increments itself the counter which must be re-provided by the caller.
 * @param oEvent [out]
 *   An event which can be applied to the component.
 *
 * @return
 *   <code>S_OK</code> if everything ran ok.
 *   <code>S_FALSE</code> if no more event are available.
 *   <code>E_INVALIDARG</code> if invalid position is provided.
 *   <code>E_FAIL</code> if a fatal error occured during the transaction. Nothing was done during the operation.
 *
 */
  virtual HRESULT NextApplicableEvent( int & ioPosition, CATUnicodeString & oEvent ) = 0;

/** 
 * Enables to valuate an event which will be applied on the component.
 *
 * <br><b>Role</b>: This method enables the user to apply an event to the described component to make its maturity
 * evolve.
 * <li> The maturity evolution will be taken into account during the @href CATIPLMMaturityEngine#ManageMaturity call.</li>
 * <li> Only one event can be set to be applied. If one was already set, the new call to the ApplyEvent method will
 * replace the previous one.</li>
 *
 * @param iEvent [in]
 *   The event to apply. If the event is invalid, this will result in a E_INVALIDARG return. 
 *   The event provided must have been retrieved through the @href CATIPLMMaturityDescriptor#NextApplicableEvent protocol.
 *
 * @return
 *   <code>S_OK</code> if everything ran ok.
 *   <code>E_INVALIDARG</code> if an invalid event is provided by the user.
 *   <code>E_FAIL</code> if a fatal error occured during the transaction. Nothing was done during the operation.
 *
 */
  virtual HRESULT ApplyEvent( const CATUnicodeString & iEvent ) = 0;
};
CATDeclareHandler(CATIPLMMaturityDescriptor, CATBaseUnknown);
#endif
