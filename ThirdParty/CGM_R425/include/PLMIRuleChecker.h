// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @level Protected
 * @usage U3
 */

#ifndef _PLMIRuleChecker_h_
#define _PLMIRuleChecker_h_


// PLM POS base
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "ExportedByGUIDPLMPosBaseInterfaces.h"


// Interface identifier declaration
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDPLMPosBaseInterfaces IID IID_PLMIRuleChecker;
#else
extern "C" const IID IID_PLMIRuleChecker;
#endif


/**
 * Security kernel checker interface.
 * <b>Role</b>: This interface provides services to check security conditions.
 */
class ExportedByGUIDPLMPosBaseInterfaces PLMIRuleChecker: public CATBaseUnknown
{
    // Interface declaration
    CATDeclareInterface;

  public:
    /**
     * Check the syntax of a security condition.
     * <br><b>Role</b>: This method checks whether a security condition is
     * valid or not.
     * 
     * @param isCondition
     *   The condition string.
     * @return
     *   Method execution status.
     *   <br><b>Legal values</b>:
     *   <dl>
     *     <dt>S_OK
     *       <dd>The condition syntax is right.
     *     <dt>E_FAIL
     *       <dd>A syntax error occured.
     *   </dl>
     */
    virtual HRESULT CheckSyntax(const CATUnicodeString& isCondition)=0;
};


CATDeclareHandler(PLMIRuleChecker,CATBaseUnknown);

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
 * @see PLMIRuleChecker
 */
HRESULT ExportedByGUIDPLMPosBaseInterfaces GetSecurityRuleChecker(PLMIRuleChecker_var& oSecurityChecker);

#endif
