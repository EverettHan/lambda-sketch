// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIPLMSynchronizationProposal.h
// Define the CATIPLMSynchronizationProposal interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Sep 2004  Creation: Code generated by the CAA wizard  pbv 
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMSynchronizationProposal_H
#define CATIPLMSynchronizationProposal_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
#include "CATPLMSynchronizationStrategy.h"
#include "CATPLMSynchronizationSessionStatus.h"
#include "CATPLMSynchronizationRemoteStatus.h"
#include "CATPLMSynchronizationProposalType.h"

class CATComponentId;
class CATLISTV(CATComponentId);
class CATIPLMSynchronizationProposals;
class CATProxySpace;
class CATIAdpPLMIdentificator;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMSynchronizationProposal;
#else
extern "C" const IID IID_CATIPLMSynchronizationProposal ;
#endif

//------------------------------------------------------------------

/**
* Allows to solve concurrencies by selecting the appropriate strategy
*/
class ExportedByCATPLMIntegrationInterfaces CATIPLMSynchronizationProposal: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  
  /**
  * Returns component's status in session
  *
  * @return
  *        The session status
  */
  virtual CATPLMSynchronizationProposalType GetType() = 0;

  /**
  * Returns the component's identifier.
  *
  * @param opIdentifier [out, CATBaseUnknown#Release]
  *        The component's identifier
  *
  * @return
  *        S_OK if request succeeded.
  *        E_FAIL if request failed.
  */
  virtual HRESULT GetComponentIdentifier (CATIAdpPLMIdentificator *& opIdentifier) = 0;

  /**
  * Returns the component's handle (If FW prerequisite is authorized).
  *
  * @return
  *        S_OK if request succeeded.
  *        E_FAIL if request failed.
  */
  virtual CATComponentId & GetComponentId() = 0;

  /**
  * Returns component's status in session
  *
  * @return
  *        The session status
  */
  virtual CATPLMSynchronizationSessionStatus GetSessionStatus() = 0;

  /**
  * Returns component's status on remote repository
  * 
  * @return
  *        The remote status
  */
  virtual CATPLMSynchronizationRemoteStatus GetRemoteStatus() = 0;

	/**
  * Returns component's concurrency type
  * 
  * @return
  *        The concurrency type
  */
	virtual CATPLMSynchronizationConcurrencyType GetConcurrencyType() = 0;

  /**
  * Suggests a refresh strategy if no ambiguity
  * 
  * @return
  *      == CATPLMSynchronizationStrategy_None several strategies are possible.
  *      != CATPLMSynchronizationStrategy_None a default strategy is assigned.
  */
  virtual CATPLMSynchronizationStrategy GetProposedStrategy() = 0;

  /**
  * List all possible strategies according to concurrent changes and allowed strategies
  * 
  * @return 
  *      The possible strategies
  */
  virtual CATPLMSynchronizationStrategy GetPossibleStrategies() = 0;

  /**
  * Returns the strategy selected by user
  * 
  * @return 
  *      The selected strategy
  */
  virtual CATPLMSynchronizationStrategy GetUserStrategy() = 0;

  /**
  * Select a strategy from the list of possible strategies [NOT IMPLEMENTED FOR THE WHILE]
  * 
  * @param iStrategy
  *        The selected strategy
  * @return
  *        S_OK if request succeeded.
  *        E_FAIL if request failed.
  */
  virtual HRESULT SetUserStrategy(CATPLMSynchronizationStrategy iStrategy) = 0;

  /**
  * Returns the strategy use by the system
  * Is the proposal or the selected strategy
  * 
  * @return 
  *      The final strategy
  */
  virtual CATPLMSynchronizationStrategy GetFinalStrategy() = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

CATDeclareHandler( CATIPLMSynchronizationProposal, CATBaseUnknown );
//------------------------------------------------------------------

#endif