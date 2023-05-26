// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// Header definition of CATAdpPublicSecurityServices
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2008  Creation: JPA
//===================================================================
/**
* @CAA2Level L1
* @CAA2Usage U1  
*/
#ifndef CATAdpPublicSecurityServices_H
#define CATAdpPublicSecurityServices_H

#include "CATPLMIntegrationAccess.h"
#include "CATUnicodeString.h"
#include "IUnknown.h"

class CATString ;


//-----------------------------------------------------------------------

/**
 * Class to manage Security services on client.
 *
 * <b>Role</b>: This class provides services
 * <ul>
 *   <li>to retrieve login information, such as current user, projet, etc.</li>
 *   <li>to check access to PLM functions, such as object creation
 *       and global functions (e.g. Import, Export, etc.)</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationAccess CATAdpPublicSecurityServices
{
public:

    /**
     * Retrieves current login information of the specified repository.
     *
     * <br><b>Role</b>:
     *          Retrieves repository's current user, project, role and organization
     * 
     * @param iRepository
     *          The repository name.
     *          <br><b>Legal value</b>: This parameter cannot be null;
     *          if the empty string ("") is specified, the first open repository is used.
     * @param oUserId
     *          Identifier of the user currently logged in.
     * @param oOrganisationId
     *          Current Organisation Identifier.
     * @param oProjectId
     *          Current Project Identifier.
     * @param oRoleId
     *          Current Role Identifier.
     * @return
     *          The method execution status.
     *          <br>Possible values are:
     *          <dl>
     *              <dt>S_OK</dt>    <dd>When information was successfully retrieved.</dd>
     *              <dt>E_FAIL</dt>  <dd>In any other error case.</dd>
     *          </dl>
     */
    static HRESULT GetSecurityParameters(const char * iRepository,
                                         CATString  & oUserId,
                                         CATString  & oOrganisationId,
                                         CATString  & oProjectId,
                                         CATString  & oRoleId);

    /**
     * Checks the security access to a global function.
     *
     * <br><b>Role</b>:
     *          Checks the access to the specified global function of the specified repository.
     *          <br>A global function is a function that is not relative to a PLM Type object.
     *          <br><b>Example</b>:
     *            <code>Import</code>, checks whether the interactive <code>Import</code> function
     *            can be used by the user.
     * 
     * @param iRepository
     *          The repository name.
     *          <br><b>Legal value</b>: This parameter cannot be null;
     *          if the empty string ("") is specified, the first open repository is used.
     * @param iFunctionName
     *          The global function name (e.g. <code>Import, Export, Myfunction1</code>, etc.).
     *          <br>Note: the function name is case insensitive.
     * @return
     *          The method execution status.
     *          <br>Possible values are:
     *          <dl>
     *              <dt>S_OK</dt>    <dd>When the access to the function is granted.</dd>
     *              <dt>E_FAIL</dt> <dd>When the access to the function is denied (or does not exist), and in any other error case.</dd>
     *          </dl>
     */
    static HRESULT CheckAccess(const char * iRepository, const CATString & iFunctionName);
    /**
     * Create a one-use login ticket for CAA batch purpose.
     *
     * <br><b>Role</b>:
     *          It creates a ticket based on current user credentials.
     *          This ticket can be used to connect to ENOVIA using CAA API such as <code>CAAAdpCreateSession</code>.
     * 
     * @param iKey
     *          Currently unused, reserved for future.
     *          <br><b>Legal value</b>: This parameter should be null
     * @param oTicket
     *          The returned login ticket.
     * @return
     *          The login ticket creation status.
     *          <br>Possible values are:
     *          <dl>
     *              <dt>S_OK</dt>   <dd>When the ticket was created.</dd>
     *              <dt>E_FAIL</dt> <dd>When the ticket could not be created.</dd>
     *          </dl>
     */
    static HRESULT CreateOnceUseLoginTicket(const char * iRepository, const char *iKey, CATUnicodeString &oTicket);
};

//-----------------------------------------------------------------------

#endif
