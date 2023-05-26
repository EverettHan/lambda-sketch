// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMSecurityAdapter.h
// Define the CATPLMSecurityAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMSecurity
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMSecurityAdapter_H
#define CATPLMSecurityAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterQLBase

#include "CATIPLMSecurity.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

class CATString;
class CATPLMTypeId;

/**
 * gives an adapter to the interface CATIPLMSecurity
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMSecurityAdapter : public CATIPLMSecurity
{
public:
    CATPLMSecurityAdapter();
    virtual ~CATPLMSecurityAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT GetSecurityParameters(  CATString & oUserId             ,
                                    CATString & oOrganisationId     ,
                                    CATString & oProjectId          ,
                                    CATString & oRoleId);

    /** 
    * @nodoc
    */
    virtual HRESULT CheckAccess(const CATString & iCommandId);

    /** 
    * @nodoc
    */
    virtual HRESULT CheckAccess(    const CATPLMTypeId & iTypeId,
                            const CATString & iCommandId);

private:
    CATPLMSecurityAdapter (CATPLMSecurityAdapter &);
    CATPLMSecurityAdapter& operator=(CATPLMSecurityAdapter&);
};

#endif

