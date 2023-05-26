 /* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U3
 */

#ifndef CATIPLMContentRefresher_h
#define CATIPLMContentRefresher_h

#include "CATPLMContentRefreshUsers.h"
#include "CATBaseUnknown.h"
class CATIPLMAttributeSet;
class CATPLMID;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMContentRefresher;
#else
extern "C" const IID IID_CATIPLMContentRefresher;
#endif

/**
 * Interface defining the communication protocol between a user and workspace/reference delivery processor.
 * <b>Role</b>: This protocol enables to launch a delivery of a workspace into its reference.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMContentRefresher : public CATBaseUnknown
{
  CATDeclareInterface;

public :

/** 
 * Ask for the refreshing of a component from a reference one.
 * <br><b>Role</b>: Enables to update the content of a component with the content of another.
 * <ul>
 * <li> <code>ERR_04</code> error will be available on the provided @href CATIAdpErrorMonitor if the provided ids are not compatible.</li>
 * <li> <code>ERR_01</code> error will be available on the provided @href CATIAdpErrorMonitor if the component to refresh is currently edited in the Authoring Session.</li>
 * <li> <code>ERR_02</code> error will be available on the provided @href CATIAdpErrorMonitor if the provided attributes do not match with the provided component.</li>
 * </ul>
 *
 * @param iSourceComponent [in]
 *   The idenfifier of the component which content will be the reference for refresh.
 * @param iTargetComponent [in]
 *   The component which must be refreshed.
 * @param iAttributes [in]
 *   The attributes the users wants to valuate on the updated component.
 * <ul>
 * <li>It can be created thanks to the @href CATIPLMContentRefresher#CreateAttributeSet entry point.</li>
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
  virtual HRESULT RefreshFrom( const CATPLMID & iSourceComponent, const CATPLMID & iTargetComponent, CATIPLMAttributeSet * iAttributes=0 )=0;

/** 
 * Trigger a content refresh operation.
 * <br><b>Role</b>: All the components provided will be refreshed from its reference.</li>
 * <ul>
 * <li> <code>ERR_04</code> error will be available on the provided @href CATIAdpErrorMonitor if no component were provided.</li>
 * </ul>
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the operation ran succesfully.</li>
 *   <li><code>E_FAIL</code> if an unexpected error occured.</li>
 *   </ul>
 *
 */
  virtual HRESULT RunRefreshOperation()=0;

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
CATDeclareHandler(CATIPLMContentRefresher, CATBaseUnknown);
#endif
