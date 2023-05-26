/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2006
#ifndef CATIPLMFillEngine_H
#define CATIPLMFillEngine_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfacesRestrictedUse.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
class CATLISTV(CATComponentId);

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMFillEngine;
#else
extern "C" const IID IID_CATIPLMFillEngine;
#endif

/**
 * This interface defines the unique protocol of communication between the users and the fill engine.
 * Use @href CATPLMEnginesToolbox#GetFillEngine to get a pointer on the fill engine.
 * <br>Thanks to this component, the user can complement the provided components in the session in accordance
 * with the data available in the database.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMFillEngine: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/** 
 * Enables to complement the component in the session.
 *
 * <br><b>Role</b>: This method enables to make the component already available in the workspace in a navigated state
 * to an authored state by completing the data with some information brought from the database.
 * <li>The components provided by the caller must be available in the workspace in a navigated state.</li>
 * <li>The error informations are communicated by the engine through the @href CATIPLMEngineListener protocol
 * provided by the user on engine creation (@href CATPLMEnginesToolbox#GetFillEngine).</li>
 *
 * @param iComponents [in]
 *   The components which must be complemented in the session.
 *
 * @return
 *   <code>S_OK</code> if everything ran ok.
 *   <code>E_INVALIDARG</code> if invalid components are provided.
 *   <code>E_FAIL</code> if a fatal error occured during the transaction. Nothing was done during the operation.
 */
  virtual HRESULT Fill( const CATLISTV(CATComponentId) & iComponents ) = 0;
};
CATDeclareHandler(CATIPLMFillEngine, CATBaseUnknown);
#endif
