// (C) Copyright Dassault Systemes - 2006
// -----------------------------------------------------------------------
// Function declaration PLMPosSecurityAudit
// -----------------------------------------------------------------------
// Creation: 2006-07-21
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U2
 */

#ifndef _PLMPosSecurityAudit_H_
#define _PLMPosSecurityAudit_H_

#include "ExportedByGUIDPLMPosBaseInterfaces.h"
#include "PLMIPosSecurityAudit.h"

/**
 * PLM Security Audit manager class.
 * <b>Role</b>: This is a hook class for a user-exit to audit security events.
 */
class ExportedByGUIDPLMPosBaseInterfaces PLMPosSecurityAudit
{
public:
    /** Returns a hook on security audit user-exit.
     * @returns
     *   S_OK       we are in a unsecured mode (security calls are desactivated).
     *   S_FALSE    we are in a normal mode    (security calls are activated).
     */     
    static int isActive();
    /** Returns a hook on security audit user-exit.
     * @returns
     *   S_OK       we are in a unsecured mode (security calls are desactivated).
     *   S_FALSE    we are in a normal mode    (security calls are activated).
     */
    static PLMIPosSecurityAudit_var & get();
protected:
    /** @nodoc */
    PLMPosSecurityAudit();
    /** @nodoc */
    ~PLMPosSecurityAudit();
};

#endif
