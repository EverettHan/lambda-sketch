//===================================================================
// COPYRIGHT Dassault Systemes 2016/01/05
//===================================================================
// CATIPLMSecurity2.cpp
// Header definition of class CATIPLMSecurity2
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2016/01/05 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIPLMSecurity2_H
#define CATIPLMSecurity2_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

class CATPLMTypeId;
class CATUnicodeString;

extern ExportedByCATPLMServicesItf  IID IID_CATIPLMSecurity2 ;


class ExportedByCATPLMServicesItf CATIPLMSecurity2: public CATBaseUnknown
{
CATDeclareInterface;

public:

    /**
     * Returns the security information. 
     * Some of Those security parameters could be different from connection parameters.
     * 
     * @param oUserId
     * PLM User Identifier. (Connected User)
     * @param oOrganisationId
     * PLM Organization Identifier.
     * @param oProjectId
     * PLM Project Identifier.
     * @param oRoleId
     * PLM Role Identifier.
     * @return
     * Method execution status.
     * Possible values are:
     * S_OK    successful.
     * E_FAIL  when an error occurs.
     */
     virtual HRESULT GetSecurityParameters(CATUnicodeString & oUserId
       , CATUnicodeString & oOrganisationId
       , CATUnicodeString & oProjectId
       , CATUnicodeString & oRoleId) = 0;

    /**
     * Checks the security access to a global Command.
     * <br><b>Role</b>: This method computes the access to the specified global
     * command (e.g. <code>Tree sort</code>), thus indicating if that function
     * should be made available to the connected user by the relevant modeler(s).
     * 
     * @param iCommandId
     * PLM global function name.
     * @return
     * Method execution status.
     * Possible values are:
     * S_OK    if the access to the function is granted;
     * S_FALSE if the access to the function is denied;
     * E_FAIL  when an error occurs while valuating the security access.
     */
    virtual HRESULT CheckAccess(const CATUnicodeString & iCommandId) = 0;
    /**
     * Checks the security access to an entity Command.
     * <br><b>Role</b>: This method computes the access to the specified
     * function (e.g. <code>Delete</code>) of the specified PLM Type (e.g.
     * <code>RscPerson</code>), thus indicating if that Command should
     * be made available to the connected user by the relevant modeler(s).
     * 
     * @param iTypeId
     * PLM Type Identifier.
     * @param iFunction
     * PLM entity function name.
     * @return
     * Method execution status.
     * Possible values are:
     * S_OK    if the access to the function is granted;
     * S_FALSE if the access to the function is denied;
     * E_FAIL when an error occurs while valuating the security access.
     */
    virtual HRESULT CheckAccess(const CATPLMTypeId & iTypeId, const CATUnicodeString & iCommandId) = 0;

};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIPLMSecurity2, CATBaseUnknown );

#endif
