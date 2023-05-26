/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpProtectedDWSAccess_H
#define CATAdpProtectedDWSAccess_H

#include "CATAdpDWSAccessUsers.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
#include "CATIAdpErrorMonitor.h"
#include "CATProxySpace.h"
class CATAdpDWSQueryAttachmentResult;
class CATAdpDWSQueryWorkspaceIdResult;
class CATLISTP(CATIAdpPLMIdentificator);
class CATIAdpPLMIdentificator;
class CATIPLMSpace;

class ExportedByCATPLMIntegrationDWSAccessUse CATAdpProtectedDWSAccess
{
public:
/**
 * @param iResolutionDataspace [in]
 * The memory dataspace the components are represented in.
 * <ul>
 * <li>It can be obtained through the @href CATPLMSpaceServices#GetResolutionSpace entry point.</li>
 * <li>It is mandatory, else an <code>E_UNEXPECTED</code> return should be expected on each entry point.</li>
 * </ul>
 * @param iErrorMonitor [in]
 * The Error Monitor dedicated to store and handle all PLM Errors raised during the execution of this operation.
 * <ul>
 * <li>It can be created through the @href CATAdpErrorMonitorFactory#CreateErrorMonitor entry point.</li>
 * <li>It is mandatory, else an <code>E_UNEXPECTED</code> return should be expected on each entry point.</li>
 * </ul>
 */
  CATAdpProtectedDWSAccess( CATIPLMSpace * iResolutionDataspace, CATIAdpErrorMonitor * iErrorMonitor );
  CATAdpProtectedDWSAccess( const CATProxySpace & iResolutionDataspace, CATIAdpErrorMonitor * iErrorMonitor );
  virtual ~CATAdpProtectedDWSAccess();

/**
 * Determines if Components are associated to a given Workspace.
 * <br><b>Role:</b>This method introspects the components in the Session to determine its Workspace attachment.
 * <ul>
 * <li>A Component with no Workspace attachment information is intended to be attached to the Enterprise Reference.</li>
 * <li>A Component which has not been propagated to the Database yet (Created status) is intended to be attached 
 to the connected Workspace. If no connected Workspace is available, it is intended to be part of the Enterprise Reference.</li>
 * </ul>
 *
 * @param iWorkspace [in]
 * The identifier of the Workspace the given components must be searched in.
 * <ul>
 * <li>If a nul workspace identifier is given, the Components will be searched in the Enterprise Reference.</li>
 * <li>A complex identifier will result in a <code>E_INVALIDARG</code> return.</li>
 * </ul>
 * @param iComponents [in]
 * The components which will be searched in the given Workspace.
 * <ul>
 * <li>An empty set will result in an <code>E_INVALIDARG</code> return.</li>
 * <li>If components are duplicated in this input set, it won't anyway be duplicated in the output set.</li>
 * <li>If a given Component is not found in the Session, an <code>ERR_05</code> error will be posted on this Error Monitor.</li>
 * </ul>
 * @param iErrorMonitor [in]
 * The Error Monitor dedicated to store and handle all PLM Errors raised during the execution of this operation.
 * <ul>
 * <li>It can be created through the @href CATAdpErrorMonitorFactory#CreateErrorMonitor entry point.</li>
 * <li>It is mandatory, else an <code>E_INVALIDARG</code> return should be expected.</li>
 * </ul>
 * @param oResults [in]
 * The results of the operation. Each found component is associated to a <code>TRUE</code>/<code>FALSE</code> status
 * representing its attachement to the given Workspace. A not-empty set will result in an <code>E_INVALIDARG</code> return.
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the operation could be performed in the Session. Results are then available.</li> 
 *   <li><tt>S_FALSE</tt> if the operation could be performed in the Session but errors were encountered. Results are then available for found Components.</li> 
 *   <li><tt>E_INVALIDARG</tt> if at least one entry was invalid.</li> 
 *   <li><tt>E_FAIL</tt> if the operation failed. Errors encountered can be read on the @href CATIAdpErrorMonitor.</li>
 *  </ul>
 */
  HRESULT IsAttachedToWorkspace( CATIAdpPLMIdentificator * iWorkspaceId,
                                 const CATLISTP(CATIAdpPLMIdentificator) & iComponents,
                                 CATAdpDWSQueryAttachmentResult & oResults );

/**
 * Determines if Components are associated to the connected Workspace.
 * <br><b>Role:</b>This method introspects the components in the Session to determine its Workspace attachment.
 * <ul>
 * <li>A Component with no Workspace attachment information is intended to be attached to the Enterprise Reference.</li>
 * <li>A Component which has not been propagated to the Database yet (Created status) is intended to be attached 
 to the connected Workspace. If no connected Workspace is connected, it is intended to be part of the Enterprise Reference.</li>
 * </ul>
 *
 * @param iComponents [in]
 * The components which will be searched in the connected Workspace.
 * <ul>
 * <li>An empty set will result in an <code>E_INVALIDARG</code> return.</li>
 * <li>If components are duplicated in this input set, it won't anyway be duplicated in the output set.</li>
 * <li>If a given Component is not found in the Session, an <code>ERR_05</code> error will be posted on this Error Monitor.</li>
 * </ul>
 * @param iErrorMonitor [in]
 * The Error Monitor dedicated to store and handle all PLM Errors raised during the execution of this operation.
 * <ul>
 * <li>It can be created through the @href CATAdpErrorMonitorFactory#CreateErrorMonitor entry point.</li>
 * <li>It is mandatory, else an <code>E_INVALIDARG</code> return should be expected.</li>
 * </ul>
 * @param oResults [in]
 * The results of the operation. Each found component is associated to a <code>TRUE</code>/<code>FALSE</code> status
 * representing its attachement to the connected Workspace. A not-empty set will result in an <code>E_INVALIDARG</code> return.
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the operation could be performed in the Session. Results are then available.</li> 
 *   <li><tt>S_FALSE</tt> if the operation could be performed in the Session but errors were encountered. Results are then available for found Components.</li> 
 *   <li><tt>E_INVALIDARG</tt> if at least one entry was invalid.</li> 
 *   <li><tt>E_FAIL</tt> if the operation failed. Errors encountered can be read on the @href CATIAdpErrorMonitor.</li>
 *  </ul>
 */
  HRESULT IsAttachedToConnectedWorkspace( const CATLISTP(CATIAdpPLMIdentificator) & iComponents,
                                          CATAdpDWSQueryAttachmentResult & oResults );

/**
 * Retrieves the identifier of the Workspace each given Component is attached to.
 * <br><b>Role:</b>This method introspects the Components in the Session to determine its Workspace attachment.
 * <ul>
 * <li>A Component with no Workspace attachment information is intended to be attached to the Reference.</li>
 * <li>A Component which has not been propagated to the Database yet (Created status) is intended to be attached 
 to the connected Workspace. If no connected Workspace is available, it is intended to be part of the Reference.</li>
 * <li>A Component which is not attached to the connected Workspace or the Reference is seen as Undefined. A <code>ERR_06</code> error will be raised for this Component.</li>
 * </ul>
 *
 * @param iComponents [in]
 * The components which will be introspected.
 * <ul>
 * <li>An empty set will result in an <code>E_INVALIDARG</code> return.</li>
 * <li>If Components are duplicated in this input set, it won't anyway be duplicated in the output set.</li>
 * <li>If a given Component is not found in the Session, an <code>ERR_05</code> error will be posted on this Error Monitor.</li>
 * </ul>
 * @param iErrorMonitor [in]
 * The Error Monitor dedicated to store and handle all PLM Errors raised during the execution of this operation.
 * <ul>
 * <li>It can be created through the @href CATAdpErrorMonitorFactory#CreateErrorMonitor entry point.</li>
 * <li>It is mandatory, else an <code>E_INVALIDARG</code> return should be expected.</li>
 * </ul>
 * @param oResults [in]
 * The results of the operation. Each found component is associated to a @href CATIAdpPLMIdentificator representing the
 * identifier of the Workspace it is attached to. A not-empty set will result in an <code>E_INVALIDARG</code> return.
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the operation could be performed in the Session. Results are then available.</li> 
 *   <li><tt>S_FALSE</tt> if the operation could be performed in the Session but errors were encountered. Results are then available for found Components.</li> 
 *   <li><tt>E_INVALIDARG</tt> if at least one entry was invalid.</li> 
 *   <li><tt>E_FAIL</tt> if the operation failed. Errors encountered can be read on the @href CATIAdpErrorMonitor.</li>
 *  </ul>
 */
  HRESULT GetAttachedWorkspace( const CATLISTP(CATIAdpPLMIdentificator) & iComponents, 
                                CATAdpDWSQueryWorkspaceIdResult & oResults );

private:
  CATAdpProtectedDWSAccess( const CATAdpProtectedDWSAccess & );
  CATAdpProtectedDWSAccess & operator =( const CATAdpProtectedDWSAccess & );

private:
  CATIAdpErrorMonitor_var _ErrorMonitor;
  CATProxySpace _Dataspace;
};
#endif
