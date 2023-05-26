// COPYRIGHT DASSAULT SYSTEMES 2010

/**
 * @level Protected
 * @usage U3
 */

#ifndef _CATIPLMLoginServices_h_
#define _CATIPLMLoginServices_h_


// PLM POS base
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "ExportedByGUIDPLMPosBaseInterfaces.h"


// Interface identifier declaration
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDPLMPosBaseInterfaces IID IID_CATIPLMLoginServices;
#else
extern "C" const IID IID_CATIPLMLoginServices;
#endif


/**
 * V6 provider login services interface.
 * <b>Role</b>: This interface provides services to login to V6.
 */
class ExportedByGUIDPLMPosBaseInterfaces CATIPLMLoginServices: public CATBaseUnknown
{
    // Interface declaration
    CATDeclareInterface;

  public:
    /**
     * Creates a Login Ticket.
     * 
     * @return
     *   Method execution status.
     *   <br><b>Legal values</b>:
     *   <dl>
     *     <dt>S_OK</dt>
     *       <dd>The login ticket creation succeeded.</dd>
     *     <dt>E_FAIL</dt>
     *       <dd>The login ticket creation failed.</dd>
     *   </dl>
     */
    virtual HRESULT CreateLoginTicket(
            const unsigned int      iNumberOfUse,
            const CATUnicodeString &iRunasUser,
            const CATUnicodeString &iRunasContext,
            CATUnicodeString       &oTicket)=0;
    /**
     * Invalidates a Login Ticket.
     * 
     * @return
     *   Method execution status.
     *   <br><b>Legal values</b>:
     *   <dl>
     *     <dt>S_OK</dt>
     *       <dd>The login ticket invalidation succeeded.</dd>
     *     <dt>E_FAIL</dt>
     *       <dd>The login ticket invalidation failed.</dd>
     *   </dl>
     */
    virtual HRESULT InvalidateLoginTicket(const CATUnicodeString &iTicket)=0;
    /**
     * Flushes a Login Ticket.
     * 
     * @return
     *   Method execution status.
     *   <br><b>Legal values</b>:
     *   <dl>
     *     <dt>S_OK</dt>
     *       <dd>The login ticket flush succeeded.</dd>
     *     <dt>E_FAIL</dt>
     *       <dd>The login ticket flush failed.</dd>
     *   </dl>
     */
    virtual HRESULT FlushLoginTicket()=0;
    /**
     * Checks whether connection using Login Ticket is supported.
     * 
     * @return
     *   Method execution status.
     *   <br><b>Legal values</b>:
     *   <dl>
     *     <dt>S_OK</dt>
     *       <dd>The login ticket connection is supported.</dd>
     *     <dt>S_FALSE</dt>
     *       <dd>The login ticket connection is not supported.</dd>
     *     <dt>E_FAIL</dt>
     *       <dd>Could not determine whether login ticket connection is supported.</dd>
     *   </dl>
     */
    virtual HRESULT IsLoginTicketConnectionSupported()=0;
};


CATDeclareHandler(CATIPLMLoginServices,CATBaseUnknown);

/**
 * V6 provider login services factory method.
 * <b>Role</b>: This method creates a V6 provider login services instance that
 * can be used by applications to execute V6 login services.
 *
 * @param oCmdHandler
 *   V6 provider login services handler if the object was successfully created, or NULL_var otherwise;
 * @return
 *   S_OK if the object was successfully created,
 *   or error code otherwise.
 *
 * @see CATIPLMLoginServices
 */
HRESULT ExportedByGUIDPLMPosBaseInterfaces CATPLMGetV6Provider(CATIPLMLoginServices_var& oCmdHandler);

#endif
