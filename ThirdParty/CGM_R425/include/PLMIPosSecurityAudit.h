// (C) Copyright Dassault Systemes - 2006
// -----------------------------------------------------------------------
// Interface declaration: PLMIPosSecurityAudit
// -----------------------------------------------------------------------
// Creation: 2006-07-21
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U3
 */

#ifndef _PLMIPosSecurityAudit_H_
#define _PLMIPosSecurityAudit_H_

#include "CATBaseUnknown.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "ExportedByGUIDPLMPosBaseInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDPLMPosBaseInterfaces IID IID_PLMIPosSecurityAudit;
#else
extern "C" const IID IID_PLMIPosSecurityAudit;
#endif


/** @nodoc */
typedef enum {
    PLMPosSecAuditChkDENIED    = 0,
    PLMPosSecAuditChkGRANTED   = 1,
    PLMPosSecAuditChkIS_ADMIN  = 2
} PLMPosSecAuditCheckResult;


/** @nodoc */
typedef enum {
    PLMPosSecAuditFILTERED       = 0,
    PLMPosSecAuditNOT_FILTERED   = 1,
} PLMPosSecAuditFilterResult;


/** @nodoc */
class ExportedByGUIDPLMPosBaseInterfaces PLMIPosSecurityAudit : public CATBaseUnknown
{
    CATDeclareInterface;
public:
    /**
     * Check access audit.
     * @param requiredClass
     *    class parameter that was provided to the security check
     * @param requiredMethod
     *    method parameter that was provided to the security check
     * @param privilegeClass
     *    class really tested, as it was found in privileges
     * @param checkResult
     *    check result (revoked, granted, not granted, etc.)
     * @param checkHR
     *    check HRESULT value
     */
    virtual void onCheckAccess(const CATUnicodeString &requiredClass,
			       const CATUnicodeString &requiredMethod,
			       const CATUnicodeString &privilegeClass,
			       const PLMPosSecAuditCheckResult  checkResult,
			       const HRESULT          &checkHR) = 0;
    /**
     * Query filter audit.
     * @param requiredClass
     *    class parameter that was provided to the security check
     * @param privilegeClass
     *    class really tested, as it was found in privileges
     * @param checkResult
     *    check result (revoked, granted, not granted, etc.)
     * @param checkHR
     *    check HRESULT value
     */
    virtual void onQueryFilter(const CATUnicodeString &requiredClass,
			       const CATUnicodeString &privilegeClass,
			       const PLMPosSecAuditFilterResult  checkResult,
			       const HRESULT          &checkHR) = 0;
    /**
     * Filter (post-query and expand) audit.
     * @param requiredClass
     *    class parameter that was provided to the security check
     * @param privilegeClass
     *    class really tested, as it was found in privileges
     * @param checkResult
     *    check result (revoked, granted, not granted, etc.)
     * @param checkHR
     *    check HRESULT value
     */
    virtual void onFilter(const CATUnicodeString &requiredClass,
			  const CATUnicodeString &privilegeClass,
			  const PLMPosSecAuditFilterResult  checkResult,
			  const HRESULT          &checkHR) = 0;
};

/** @nodoc */
CATDeclareHandler(PLMIPosSecurityAudit,CATBaseUnknown);

#endif
