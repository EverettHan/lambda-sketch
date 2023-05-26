// (C) Copyright Dassault Systemes - 2015
// -----------------------------------------------------------------------
// Interface declaration: CATIPLMSecurityServices
// -----------------------------------------------------------------------
// Creation: 2015-02-10
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U3
 */

#ifndef CATIPLMSecurityServices_H
#define CATIPLMSecurityServices_H

#include "CATBaseUnknown.h"
#include "CATTime.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

#include "CATPLMServicesItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMSecurityServices;
#else
extern "C" const IID IID_CATIPLMSecurityServices;
#endif



/** @nodoc */
class ExportedByCATPLMServicesItf CATIPLMSecurityServices : public CATBaseUnknown
{
    CATDeclareInterface;
public:
    /**
     * Create a login ticket. 
     * 
     * @param iNumberOfUse
     *   number of use (0 means unlimited).
     * @param iSecurityContext
     *   the security context. Take current security context if none is set.
     * @param iStart
     *   the optional ticket validity start time.
     * @param iExpiration
     *   the optional ticket expiration time.
     * @param iRestrictions
     *   the optional list of restrictions (format is : "attr=value"). 
     *   (not implemented - reserved for future use).
     * @param iKey
     *   an optional ticket hash key, to secure use of ticket.
     *   If one is specified, it must be set when the ticket is used for login
     *   (not implemented - reserved for future use).
     * @param oTicket
     *   the generated login ticket.
     * @return
     *   Method execution status.
     *   Possible values are:
     *   S_OK    successful;
     *   E_FAIL  when an error occurs.
     */
    virtual HRESULT CreateLoginTicket(unsigned int iNumberOfUse, CATUnicodeString *iSecurityContext, CATTime *iStart, CATTime *iExpiration, CATListOfCATUnicodeString *iRestrictions, const char *iKey, CATUnicodeString &oTicket) = 0;
};

CATDeclareHandler(CATIPLMSecurityServices,CATBaseUnknown);

#endif
