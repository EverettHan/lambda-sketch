 /* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U3
 */

#ifndef CATIPLMWSDeliverResult_h
#define CATIPLMWSDeliverResult_h

#include "CATPLMWorkspaceReferenceUsers.h"
#include "CATBaseUnknown.h"
#include "CATPLMWSOperationType.h"
class CATPLMCEStamp;
class CATPLMID;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMWSDeliverResult;
#else
extern "C" const IID IID_CATIPLMWSDeliverResult;
#endif

/**
 * Interface defining the protocol enabling to read results of a delivery transaction.
 * <b>Role</b>: This protocol enables to obtain informations about what happened on components during the delivery of a Workspace.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMWSDeliverResult : public CATBaseUnknown
{
  CATDeclareInterface;

public :

/** 
 * Get the identifiers of a component both in the Reference and the Workspace.
 * <br><b>Role</b>: Enables to retrieve the identifiers of a component in the Workspace and the Reference, together with its concurrency stamp in the Reference.
 *
 * @param oWorkspaceId [out]
 *   The idenfifier in the Workspace.
 * @param oReferenceId [out]
 *   The idenfifier in the Reference. It can be <code>CATPLMID_Null</code> if the component was removed from the Reference.  
 * @param oReferenceConcurrencyStamp [out]
 *   The concurrency stamp in the Reference.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the information about the component were successfully retrieved.
 *   <li><code>E_FAIL</code> if an unexpected error occured.
 *   </ul>
 *
 */
  virtual HRESULT GetDeliverResultIdentifiers( CATPLMID & oWorkspaceId, CATPLMID & oReferenceId )=0;

/** 
 * Get the new concurrency stamp of the component in the Reference.
 * <br><b>Role</b>: Enables to retrieve the new concurrency stamp of the component in the Reference.
 *
 * @param oReferenceConcurrencyStamp [out]
 *   The concurrency stamp in the Reference.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the information about the component were successfully retrieved.
 *   <li><code>E_FAIL</code> if an unexpected error occured.
 *   </ul>
 *
 */
  virtual HRESULT GetReferenceConcurrencyStamp( CATPLMCEStamp & oReferenceConcurrencyStamp )=0;

/** 
 * Get the operation type for a component.
 * <br><b>Role</b>: Enables to retrieve the operation type performed on the component during the delivery operation.
 *
 * @param oOperationType [out]
 *   The operation type.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the component operation type was successfully retrieved.
 *   <li><code>E_FAIL</code> if an unexpected error occured.
 *   </ul>
 *
 */
  virtual HRESULT GetDeliverOperationType( CATPLMWSOperationType::OperationType & oOperationType )=0;
};
CATDeclareHandler(CATIPLMWSDeliverResult, CATBaseUnknown);
#endif
