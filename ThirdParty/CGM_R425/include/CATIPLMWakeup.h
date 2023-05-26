// COPYRIGHT DASSAULT SYSTEMES 2010

/**
 * @level Protected
 * @usage U3
 */

#ifndef _CATIPLMWakeup_h_
#define _CATIPLMWakeup_h_


// PLM POS base
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "ExportedByGUIDPLMPosBaseInterfaces.h"


// Interface identifier declaration
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDPLMPosBaseInterfaces IID IID_CATIPLMWakeup;
#else
extern "C" const IID IID_CATIPLMWakeup;
#endif


/**
 * Security kernel checker interface.
 * <b>Role</b>: This interface provides services to check security conditions.
 */
class ExportedByGUIDPLMPosBaseInterfaces CATIPLMWakeup: public CATBaseUnknown
{
    // Interface declaration
    CATDeclareInterface;

  public:
    /**
     * Wakes up server session (if necessary).
     * 
     * @return
     *   Method execution status.
     *   <br><b>Legal values</b>:
     *   <dl>
     *     <dt>S_OK
     *       <dd>The wake up command succeeded.
     *     <dt>E_FAIL
     *       <dd>The wake up command failed.
     *   </dl>
     */
    virtual HRESULT Execute(CATUnicodeString &oOneShotTicket, CATUnicodeString &oSession)=0;
    virtual HRESULT Switch(CATUnicodeString &iContext)=0;
    virtual HRESULT CreateLoginTicket(const unsigned int iNumberOfUse, CATUnicodeString &oTicket)=0;
    virtual HRESULT InvalidateLoginTicket(const CATUnicodeString &iTicket)=0;
};


CATDeclareHandler(CATIPLMWakeup,CATBaseUnknown);

/**
 * Security kernel checker factory method.
 * <b>Role</b>: This method creates a security kernel checker instance that
 * can be used by applications to perform security conditions checks.
 *
 * @param oSecurityChecker
 *   Object handler if the security checker instance was successfully created, or NULL_var otherwise;
 * @return
 *   S_OK if the security checker instance was successfully created,
 *   or error code otherwise.
 *
 * @see CATIPLMWakeup
 */
HRESULT ExportedByGUIDPLMPosBaseInterfaces GetWakeupCommand(CATIPLMWakeup_var& oCmdHandler);

#endif
