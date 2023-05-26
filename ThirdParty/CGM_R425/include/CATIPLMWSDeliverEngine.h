 /* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U3
 */

#ifndef CATIPLMWSDeliverEngine_h
#define CATIPLMWSDeliverEngine_h

#include "CATPLMWorkspaceReferenceUsers.h"
#include "CATBaseUnknown.h"
class CATIPLMAttributeSet;
class CATUnicodeString;
class CATIPLMWSSynchronizeResult;
class CATPLMID;
class CATIPLMWSDeliverResult;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMWSDeliverEngine;
#else
extern "C" const IID IID_CATIPLMWSDeliverEngine ;
#endif

/**
 * Interface defining the communication protocol between a user and workspace/reference delivery processor.
 * <b>Role</b>: This protocol enables to launch a delivery of a workspace into its reference.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMWSDeliverEngine : public CATBaseUnknown
{
  CATDeclareInterface;

public :

/** 
 * Ask for the creation of a component in the Reference.
 * <br><b>Role</b>: Enables to create a component in the Reference and valuate specific properties on the created component.
 * <ul>
 * <li> <code>ERR_01</code> error will be available on the provided @href CATIAdpErrorMonitor if the component is currently edited in the Authoring Session.</li>
 * <li> <code>ERR_02</code> error will be available on the provided @href CATIAdpErrorMonitor if the provided attributes do not match with the provided component.</li>
 * </ul>
 *
 * @param iWorkspaceId [in]
 *   The idenfifier in the Workspace of the component which will be created in the Reference.
 * @param iAttributes [in]
 *   The attributes the users wants to valuate on the created component in the Reference. 
 * <ul>
 * <li>It can be created thanks to the @href CATIPLMWSDeliverEngine#CreateAttributeSet entry point.</li>
 * <li>It can be null.</li>
 * <li>The attributes must match with the provided component.</li>
 * </ul>
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the component was successfully added into the set of components to treat.
 *   <li><code>E_FAIL</code> if an unexpected error occured.
 *   <li><code>E_INVALIDARG</code> if the provided attributes do not match with the component.
 *   </ul>
 *
 */
  virtual HRESULT CreateComponent( const CATPLMID & iWorkspaceId, CATIPLMAttributeSet * iAttributes=0 )=0;

/** 
 * Ask for the update of a component in the Reference.
 * <br><b>Role</b>: Enables to update a component in the Reference and valuate specific properties on the updated component.
 * <ul>
 * <li> <code>ERR_01</code> error will be available on the provided @href CATIAdpErrorMonitor if the component is currently edited in the Authoring Session.</li>
 * <li> <code>ERR_02</code> error will be available on the provided @href CATIAdpErrorMonitor if the provided attributes do not match with the provided component.</li>
 * <li> <code>ERR_04</code> error will be available on the provided @href CATIAdpErrorMonitor if the provided ids are not compatible.</li>
 * </ul>
 *
 * @param iWorkspaceId [in]
 *   The idenfifier in the Workspace of the component which will be updated.
 * @param iReferenceId [in]
 *   The idenfifier in the Reference of the component which will be updated.
 * @param iAttributes [in]
 *   The attributes the users wants to valuate on the updated component in the Reference.
 * <ul>
 * <li>It can be created thanks to the @href CATIPLMWSDeliverEngine#CreateAttributeSet entry point.</li>
 * <li>It can be null.</li>
 * <li>The attributes must match with the provided component.</li>
 * </ul>
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the component was successfully added into the set of components to treat.
 *   <li><code>E_FAIL</code> if an unexpected error occured.
 *   <li><code>E_INVALIDARG</code> if the provided attributes do not match with the component.
 *   </ul>
 *
 */
  virtual HRESULT UpdateComponent( const CATPLMID & iWorkspaceId, const CATPLMID & iReferenceId, CATIPLMAttributeSet * iAttributes=0 )=0;

/** 
 * Ask for the deletion of a component in the Reference.
 * <br><b>Role</b>: Enables to delete a component in the Reference.
 * <ul>
 * <li> <code>ERR_01</code> error will be available on the provided @href CATIAdpErrorMonitor if the component is currently edited in the Authoring Session.</li>
 * <li> <code>ERR_04</code> error will be available on the provided @href CATIAdpErrorMonitor if the provided ids are not compatible.</li>
 * </ul>
 *
 * @param iWorkspaceId [in]
 *   The idenfifier in the Workspace of the component which will be removed from the Reference.
 * @param iReferenceId [in]
 *   The idenfifier in the Reference of the component which will be removed.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the component was successfully added into the set of components to treat.
 *   <li><code>E_FAIL</code> if an unexpected error occured.
 *   </ul>
 *
 */
  virtual HRESULT DeleteComponent( const CATPLMID & iWorkspaceId, const CATPLMID & iReferenceId )=0;

/** 
 * Inform the engine about the content of the workspace.
 * <br><b>Role</b>: Enables to inform the engine about the components being part of the workspace.
 * <ul>
 * <li> <code>ERR_01</code> error will be available on the provided @href CATIAdpErrorMonitor if the component is currently edited in the Authoring Session.</li>
 * <li> <code>ERR_04</code> error will be available on the provided @href CATIAdpErrorMonitor if the provided ids are not compatible.</li>
 * </ul>
 *
 * @param iWorkspaceId [in]
 *   The idenfifier in the Workspace of the component of the Workspace.
 * @param iReferenceId [in]
 *   The idenfifier in the Reference of the component. It can be <code>CATPLMID_Null</code> if the component is not available in the Reference yet.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the component was successfully added into the set of components.</li>
 *   <li><code>E_FAIL</code> if an unexpected error occured.</li>
 *   </ul>
 *
 */
  virtual HRESULT InformWorkspaceComponent( const CATPLMID & iWorkspaceId, const CATPLMID & iReferenceId )=0;

/** 
 * Trigger a delivery operation.
 * <br><b>Role</b>: All the components provided will be delivered in the Reference.</li>
 * <ul>
 * <li> <code>ERR_03</code> error will be available on the provided @href CATIAdpErrorMonitor if no component were provided.</li>
 * </ul>
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the operation ran succesfully.</li>
 *   <li><code>E_FAIL</code> if an unexpected error occured.</li>
 *   </ul>
 *
 */
  virtual HRESULT RunDeliverOperation()=0;
  virtual HRESULT RunDeliverOperation(CATBoolean iTriggersOff)=0;

/** 
 * Get the result of the delivery operation for a component.
 * <br><b>Role</b>: Enables to obtain the result of the delivery for a component being part of the transaction.
 *
 * @param iWorkspaceId [in]
 *   The idenfifier in the Workspace of the component which the operation result is required.
 * @param oResult [out, CATBaseUnknown#Release]
 *   The result.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the result is available for this component.</li>
 *   <li><code>S_FALSE</code> if the component is not found in the results.</li>
 *   <li><code>E_FAIL</code> if an unexpected error occured.</li>
 *   </ul>
 *
 */
  virtual HRESULT GetDeliverResultFromWorkspaceId( const CATPLMID & iWorkspaceId, CATIPLMWSDeliverResult *& oResult )=0;

/** 
 * Prepare the parsing of the complete set of results.
 * <br><b>Role</b>: Enables to inform the engine that the results will be parsed.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the results are reqdy to be parsed.</li>
 *   <li><code>E_FAIL</code> if an unexpected error occured.</li>
 *   </ul>
 *
 */
  virtual HRESULT StartParsingDeliverResults()=0;

/** 
 * Get the results of the delivery operation.
 * <br><b>Role</b>: Enables to obtain the results of the delivery.
 * The component might have been modified (as required by the user) or really impacted during the transaction. 
 *
 * @param oResult [out, CATBaseUnknown#Release]
 *   The result.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if access is given to the next result.</li>
 *   <li><code>S_FALSE</code> if end of the enumeration is reached. No more results are available.</li>
 *   <li><code>E_FAIL</code> if an unexpected error occured.</li>
 *   <li><code>E_INVALIDARG</code> if invalid position is provided.</li>
 *   </ul>
 *
 */
  virtual HRESULT NextDeliverResult( CATIPLMWSDeliverResult *& oResult )=0;

/**
 * Create an empty attribute set.
 * <br><b>Role:</b>: This method enables to create an empty attribute set in order to ask for attributes modification on a component during the delivery operation.
 *
 * @param oAttributeSet  [out,CATBaseUnknown#Release]
 *   A pointer on the attribute set.
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if access is given to an attribute set.</li> 
 *   <li><tt>E_FAIL</tt> if the operation failed.</li>
 *   </ul>
 */
  virtual HRESULT CreateAttributeSet( CATIPLMAttributeSet *& oAttributeSet ) = 0;
};
CATDeclareHandler(CATIPLMWSDeliverEngine, CATBaseUnknown);
#endif
