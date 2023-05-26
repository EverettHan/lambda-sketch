/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2006
#ifndef CATIPLMMaturityEngine_H
#define CATIPLMMaturityEngine_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfacesRestrictedUse.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
class CATLISTV(CATPLMID);
class CATIPLMMaturityAnalyzer;
class CATIPLMMaturityOrderedAnalyzer;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMMaturityEngine;
#else
extern "C" const IID IID_CATIPLMMaturityEngine;
#endif

/**
 * This interface defines the unique protocol of communication between the users and the maturity engine.
 * Use @href CATPLMEnginesToolbox#GetMaturityEngine to get a pointer on the maturity engine.
 * <br>Globally, the user can:
 * <ul>
 *   <li>Ask for an analyze of some components to get its maturity state.</li>
 *   <li>Ask for a modification of the maturity of those components in accordance to what is authorized by the server.</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMMaturityEngine: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/** 
 * Enables to obtain maturity information.
 *
 * <br><b>Role</b>: This method enables to retrieve the maturity informations of the provided components.
 * <li>The caller will be provided a @href CATIPLMMaturityAnalyzer component which will enable him
 * to read the data describing the maturity state of the component through the @href CATIPLMMaturityDescriptor.
 * This protocol also enables to validate events which would be applied to the component later on.</li>
 * <li>The error informations are communicated by the engine through the @href CATIPLMEngineListener protocol
 * provided by the user on engine creation (@href CATPLMEnginesToolbox#GetMaturityEngine).</li>
 *
 * @param iComponents [in]
 *   The components which maturity informations must be retrieved.
 * @param oAnalyzer [out]
 *   The component enabling the user to analyze the result of the requirement.
 *
 * @return
 *   <code>S_OK</code> if everything ran ok.
 *   <code>E_INVALIDARG</code> if invalid components are provided.
 *   <code>E_FAIL</code> if a fatal error occured during the transaction. Nothing was done during the operation.
 */
  virtual HRESULT AnalyzeMaturity(const CATLISTV(CATPLMID) & iComponents, CATIPLMMaturityAnalyzer *& oAnalyzer) = 0;

  /**
  * Enables to obtain maturity information, ordered version. See previous.
  *
  * <br><b>Role</b>: As previous, but keeping iComponents order ensured in server input message, and in analyzer.
  *
  * @param iComponents [in]
  *   The components which maturity informations must be retrieved.
  * @param oAnalyzer [out]
  *   The component enabling the user to analyze the result of the requirement.
  *
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_INVALIDARG</code> if invalid components are provided.
  *   <code>E_FAIL</code> if a fatal error occured during the transaction. Nothing was done during the operation.
  */

  virtual HRESULT AnalyzeMaturity(const CATLISTV(CATPLMID) & iComponents, CATIPLMMaturityOrderedAnalyzer *& oAnalyzer) = 0;
/** 
 * Enables the user to trigger maturity modifications.
 *
 * <br><b>Role</b>: This method enables to modify the maturity of the components previously analyzed.
 * <li>Based on the events which were asked to apply on the @href CATIPLMMaturityDescriptor following
 * maturity analyze done by the user through the @href CATIPLMMaturityAnalyzer protocol, the engine triggers 
 * a maturity modification of the components flagged -to be modified-.</li>
 * <li>The error informations are communicated by the engine through the @href CATIPLMEngineListener protocol
 * provided by the user on engine creation (@href CATPLMEnginesToolbox#GetMaturityEngine).</li>
 *
 * @param iAnalyzer [in]
 *   The analyzing component provided through the @href CATIPLMMaturityEngine#AnalyzeMaturity entry point.
 *
 * @return
 *   <code>S_OK</code> if everything ran ok.
 *   <code>S_FALSE</code> if nothing was asked to performed during the analyze performed by the user.
 *   <code>E_INVALIDARG</code> if invalid component is provided.
 *   <code>E_FAIL</code> if a fatal error occured during the transaction. Nothing was done during the operation.
 *
 */
  virtual HRESULT ManageMaturity( CATIPLMMaturityAnalyzer * iAnalyzer ) = 0;

  /**
  * Enables the user to trigger maturity modifications. Keep order
  * <br><b>Role</b>: As previous, but keeping iComponents order ensured in server input message, and in analyzer
  *
  * @param iAnalyzer [in]
  *   The analyzing component provided through the @href CATIPLMMaturityEngine#AnalyzeMaturity entry point.
  *
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>S_FALSE</code> if nothing was asked to performed during the analyze performed by the user.
  *   <code>E_INVALIDARG</code> if invalid component is provided.
  *   <code>E_FAIL</code> if a fatal error occured during the transaction. Nothing was done during the operation.
  *
  */
  virtual HRESULT ManageMaturity(CATIPLMMaturityOrderedAnalyzer * iAnalyzer) = 0;
};
CATDeclareHandler(CATIPLMMaturityEngine, CATBaseUnknown);
#endif
