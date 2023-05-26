/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpRestrictedDWSAccess_H
#define CATAdpRestrictedDWSAccess_H

#include "CATBaseUnknown.h"
class CATBinary;
class CATPLMID;
class CATComponentId;

#undef ExportedByCATPLMIntegrationAccess 
#if defined (private) || defined(friend) || defined (protected)
#error Forbidden re-define of 'private', 'friend' or 'protected'
// Fatal error on solaris
@error 
#endif

#define AuthorizedModule     999
// List of authorized infrastructure modules 
#define CATPLMSessionContentAccess AuthorizedModule
#define CATPLMItgTestIntegrationAccess AuthorizedModule
#define CATPLMClientCoreModel AuthorizedModule
#define CATPLMIntegration AuthorizedModule
#define CATPLMIntegrationAccessBase AuthorizedModule
#define CATPLMIntegrationAccess AuthorizedModule
#define CATPLMEditabilityImpl AuthorizedModule
#define CATPLMItgTests AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access to CATAdpProtectedDWSAccess from a non-authorized module
// Fatal error on solaris
@error 
#endif
#undef CATPLMSessionContentAccess
#undef CATPLMItgTestIntegrationAccess
#undef CATPLMClientCoreModel
#undef CATPLMIntegration
#undef CATPLMIntegrationAccessBase
#undef CATPLMIntegrationAccess
#undef CATPLMEditabilityImpl
#undef CATPLMItgTests

#if defined(__CATPLMIntegrationAccess)
#define ExportedByCATPLMIntegrationAccess DSYExport
#else
#define ExportedByCATPLMIntegrationAccess DSYImport
#endif
#include "DSYExport.h"

class ExportedByCATPLMIntegrationAccess CATAdpRestrictedDWSAccess
{
public:
  CATAdpRestrictedDWSAccess();
  virtual ~CATAdpRestrictedDWSAccess();

 /**
  * Returns the workspaceID of the connected Workspace.
  * <br><b>Role:</b>This method allows you to get the workspaceID of the connected Design Workspace.
  * @param oWorkspaceID [out]
  *   The workspaceID of the connected Workspace.
  * @return HRESULT
  * <ul>
  * <li><b>S_OK</b> if a Workspace is connected.</li>
  * <li><b>S_FALSE</b> if no Workspace is connected.</li> 
  * <li><b>E_FAIL</b> if an error occured.</li>
  * </ul>
  */
  HRESULT GetConnectedWorkspaceID( CATBinary & oWorkspaceID );

 /**
  * Returns the connected Workspace.
  * <br><b>Role:</b>This method allows you to get the connected Design Workspace.
  * @param oWorkspace [out]
  *   The connected Workspace.
  * @return HRESULT
  * <ul>
  * <li><b>S_OK</b> if a Workspace is connected.</li>
  * <li><b>S_FALSE</b> if no Workspace is connected.</li> 
  * <li><b>E_FAIL</b> if an error occured.</li>
  * </ul>
  */
  HRESULT GetConnectedWorkspace( CATPLMID & oWorkspace );

  /**
   * Tells if the session is connected to a designer workspace
   */
  CATBoolean IsConnected();

 /**
  * Retrieves the workspaceid from a TOS cell.
  * <br><b>Role:</b>This method allows to get the workspaceid of a Component if available in Full Authoring mode in the Session.
  * @param iComponent [in]
  *   The Component handle in the Dataspace.
  * @param oWorkspaceId [out]
  *   The workspaceid associated to the Component. If the Component is in the Reference, value is null.
  * @return HRESULT
  * <ul>
  * <li><b>S_OK</b> if the workspaceid could be retrieved.</li>
  * <li><b>E_NOT_VALID_STATE</b> if the workspaceid is not available on the Component handle (its state in the dataspace is probably not high enough).</li>
  * <li><b>E_FAIL</b> if an error occured.</li>
  * </ul>
   */
  HRESULT GetComponentWorkspaceId( const CATComponentId & iComponent, CATBinary & oWorkspaceId );

  /**
   * Checks that one given component belongs to a workspace.
   */
  HRESULT CheckComponentAttachment( const CATBinary & iWorkspaceId, const CATComponentId & iComponent, CATBoolean & oAttachmentStatus );

private:
  CATAdpRestrictedDWSAccess( const CATAdpRestrictedDWSAccess & );
  CATAdpRestrictedDWSAccess & operator =( const CATAdpRestrictedDWSAccess & );
};
#endif
