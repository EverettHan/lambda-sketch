// (C) Copyright Dassault Systemes - 2005
// -----------------------------------------------------------------------
// Interface declaration: PLMIPosSecurityEngine
// -----------------------------------------------------------------------
// Creation:     2005-12-12
// Modification: 2006-09-15 added Filter(PLMIPosNavigableObject)
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U3
 */

#ifndef _PLMIPosSecurityEngine_H_
#define _PLMIPosSecurityEngine_H_

#include "CATBaseUnknown.h"

class CATUnicodeString;
class CATListValCATUnicodeString;
class PLMIPosNavigableObject_var;
#include "ExportedByGUIDPLMPosBaseInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDPLMPosBaseInterfaces IID IID_PLMIPosSecurityEngine;
#else
extern "C" const IID IID_PLMIPosSecurityEngine;
#endif



/**
 * PLM Security Engine interface.
 * <b>Role</b>: This interface provides run-time security services to
 * PLM components that need to secure their data.
 */
class ExportedByGUIDPLMPosBaseInterfaces PLMIPosSecurityEngine : public CATBaseUnknown
{
    CATDeclareInterface;
public:
    /**
     * Retrieves the login user id.
     * <br><b>Role</b>: This method retrieves the identifier of the current P&O
     * user.
     * 
     * @param oUserId
     *    Login user identifier.
     * @return
     *    Method execution status.
     *    Possible values are:
     *    S_OK   if the method is successfully executed;
     *    E_FAIL when an error occurs while retrieving the login user
     *    identifier.
     */
    virtual HRESULT GetLoginUserId(CATUnicodeString& oUserId) = 0;
    /**
     * Retrieves the all login context ids.
     * <br><b>Role</b>: This method retrieves the identifiers of all login
     * contexts, i.e. dot-separated P&O role/organization/project triplets.
     * 
     * @param oListContextId
     *    List of login context identifiers.
     * @return
     *    Method execution status.
     *    Possible values are:
     *    S_OK   if the method is successfully executed;
     *    E_FAIL when an error occurs while retrieving the login context
     *    identifiers.
     */
    virtual HRESULT GetLoginContextIds(CATListValCATUnicodeString& oListContextId) = 0;
    /**
     * Retrieves the current login context id.
     * <br><b>Role</b>: This method retrieves the identifier of the current
     * login context, i.e. a dot-separated P&O role/organization/project
     * triplet.
     * 
     * @param oContextId
     *    Login context identifier.
     * @return
     *    Method execution status.
     *    Possible values are:
     *    S_OK   if the method is successfully executed;
     *    E_FAIL when an error occurs while retrieving the login context
     *    identifier.
     */
    virtual HRESULT GetCurrentLoginContextId(CATUnicodeString& oContextId) = 0;
    /**
     * Retrieves the current login role id.
     * <br><b>Role</b>: This method retrieves the identifier of the current
     * login role, i.e. the role of the current login P&O context.
     * 
     * @param oRoleId
     *    Login role identifier.
     * @return
     *    Method execution status.
     *    Possible values are:
     *    S_OK   if the method is successfully executed;
     *    E_FAIL when an error occurs while retrieving the login role
     *    identifier.
     */
    virtual HRESULT GetCurrentLoginRoleId(CATUnicodeString& oRoleId) = 0;
    /**
     * Retrieves the current login organization id.
     * <br><b>Role</b>: This method retrieves the identifier of the current
     * login organization, i.e. the organization of the current login P&O
     * context.
     * 
     * @param oOrganizationId
     *    Login organization identifier.
     * @return
     *    Method execution status.
     *    Possible values are:
     *    S_OK   if the method is successfully executed;
     *    E_FAIL when an error occurs while retrieving the login organization
     *    identifier.
     */
    virtual HRESULT GetCurrentLoginOrganizationId(CATUnicodeString& oOrganizationId) = 0;
    /**
     * Retrieves the current login project id.
     * <br><b>Role</b>: This method retrieves the identifier of the current
     * login project, i.e. the project of the current login P&O context.
     * 
     * @param oProjectId
     *    Login project identifier.
     * @return
     *    Method execution status.
     *    Possible values are:
     *    S_OK   if the method is successfully executed;
     *    E_FAIL when an error occurs while retrieving the login project
     *    identifier.
     */
    virtual HRESULT GetCurrentLoginProjectId(CATUnicodeString& oProjectId) = 0;
    /**
     * Checks the security access to a global function.
     * <br><b>Role</b>: This method computes the access to the specified global
     * function (e.g. <code>Tree sort</code>), thus indicating if that function
     * should be made available to the user by the relevant modeler(s).
     * 
     * @param iFunction
     *    PLM global function name.
     * @return
     *    Method execution status.
     *    Possible values are:
     *    S_OK    if the access to the function is granted;
     *    S_FALSE if the access to the function is denied;
     *    E_FAIL  when an error occurs while valuating the security access.
     */
    virtual HRESULT CheckAccess(const CATUnicodeString& iFunction) = 0;
    /**
     * Checks the security access to an entity function.
     * <br><b>Role</b>: This method computes the access to the specified
     * function (e.g. <code>Delete</code>) of the specified PLM entity (e.g.
     * <code>VPMReference</code>), thus indicating if that function should
     * be made available to the user by the relevant modeler(s).
     * 
     * @param iEntity
     *    PLM entity name.
     * @param iFunction
     *    PLM entity function name.
     * @return
     *    Method execution status.
     *    Possible values are:
     *    S_OK    if the access to the function is granted;
     *    S_FALSE if the access to the function is denied;
     *    E_FAIL when an error occurs while valuating the security access.
     */
    virtual HRESULT CheckAccess(const CATUnicodeString& iEntity, const CATUnicodeString& iFunction) = 0;
    /**
     * Retrieves the security access to an navigable object.
     * <br><b>Role</b>: This method computes the access to the specified
     * function (e.g. <code>Delete</code>) on the specified navigable object
     * (e.g. an <code>VPMReference</code> PLM object), thus indicating if
     * that function should be executed on that object by the relevant
     * modeler(s).
     * 
     * @param iObject
     *    Navigable object.
     * @param iFunction
     *    PLM entity function name.
     * @param oAccess
     *    Security access, <code>TRUE</code> indicating access to the function is
     *    granted.
     * @return
     *    Method execution status.
     *    Possible values are:
     *    S_OK    if the access to the function is granted;
     *    S_FALSE if the access to the function is denied;
     *    E_FAIL when an error occurs while valuating the security access.
     */
    virtual HRESULT CheckAccess(const PLMIPosNavigableObject_var& iObject, const CATUnicodeString& iFunction) = 0;
    /**
     * Retrieves the security filter to an navigable object.
     * <br><b>Role</b>: This method computes the access to the Expand function
     * on the specified navigable object (e.g. an <code>VPMReference</code> PLM object),
     * thus indicating if expand could be executed on that object.
     * 
     * @param iObject
     *    Navigable object.
     * @return
     *    Method execution status.
     *    Possible values are:
     *    S_OK    if the access to the function is granted;
     *    S_FALSE if the access to the function is denied;
     *    E_FAIL  when an error occurs while valuating the security access.
     */
    virtual HRESULT Filter(const PLMIPosNavigableObject_var& iObject) = 0;
};

CATDeclareHandler(PLMIPosSecurityEngine,CATBaseUnknown);

#endif
