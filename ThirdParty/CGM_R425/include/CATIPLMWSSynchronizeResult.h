 /* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U3
 */

#ifndef CATIPLMWSSynchronizeResult_h
#define CATIPLMWSSynchronizeResult_h

#include "CATPLMWorkspaceReferenceUsers.h"
#include "CATBaseUnknown.h"
#include "CATPLMWSOperationType.h"
class CATPLMCEStamp;
class CATPLMID;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMWSSynchronizeResult;
#else
extern "C" const IID IID_CATIPLMWSSynchronizeResult;
#endif

/**
 * Interface defining the protocol enabling to read results of a synchronization transaction.
 * <b>Role</b>: This protocol enables to obtain informations about what happened on components during the synchronization of a Workspace.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMWSSynchronizeResult : public CATBaseUnknown
{
  CATDeclareInterface;

public :

/** 
 * Get the identifiers of a component both in the Reference and the Workspace.
 * <br><b>Role</b>: Enables to retrieve the identifiers of a component in the Workspace and the Reference.
 *
 * @param oReferenceId [out]
 *   The idenfifier in the Reference.  
 * @param oWorkspaceId [out]
 *   The idenfifier in the Workspace. It can be <code>CATPLMID_Null</code> if the component was detached from the workspace.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the information about the component were successfully retrieved.
 *   <li><code>E_FAIL</code> if an unexpected error occured.
 *   </ul>
 *
 */
  virtual HRESULT GetSynchronizeResultIdentifiers( CATPLMID & oReferenceId, CATPLMID & oWorkspaceId )=0;

/** 
 * Get the new concurrency stamp of the component in the Workspace.
 * <br><b>Role</b>: Enables to retrieve the new concurrency stamp of the component in the Workspace.
 *
 * @param oWorkspaceConcurrencyStamp [out]
 *   The concurrency stamp in the workspace.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the information about the component were successfully retrieved.
 *   <li><code>E_FAIL</code> if an unexpected error occured.
 *   </ul>
 *
 */
  virtual HRESULT GetWorkspaceConcurrencyStamp( CATPLMCEStamp & oWorkspaceConcurrencyStamp )=0;

/** 
 * Get the operation type for a component.
 * <br><b>Role</b>: Enables to retrieve the operation type performed on the component during the synchronization operation.
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
  virtual HRESULT GetSynchronizeOperationType( CATPLMWSOperationType::OperationType & oOperationType )=0;
};
CATDeclareHandler(CATIPLMWSSynchronizeResult, CATBaseUnknown);
#endif
