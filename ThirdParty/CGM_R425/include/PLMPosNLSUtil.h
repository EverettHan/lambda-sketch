#ifndef _PLMPosNLSUtil_h_
#define _PLMPosNLSUtil_h_


// COPYRIGHT DASSAULT SYSTEMES 2013

/**
 * @level Protected
 * @usage U1
 */

#include "ExportedByGUIDPLMPosBaseInterfaces.h"

class CATUnicodeString;


/**
 * PLM P&O NLS utility class.
 * <b>Role</b>: This class provides services to retrieve NLS value for P&O components.
 */
class ExportedByGUIDPLMPosBaseInterfaces PLMPosNLSUtil
{
  public:
    /**
     * Gets role NLS value.
     * <br><b>Role</b>: This method retrieves the NLS value for the specified P&O role.
     * If no NLS string is defined for the role, role name is returned.
     * 
     * @param iName
     *    P&O role name.
     * @return
     *    NLS value.
     **/
    static CATUnicodeString GetRoleNLSValue(const CATUnicodeString& iName);

    /**
     * Gets security context NLS value.
     * <br><b>Role</b>: This method retrieves the NLS value for the specified P&O security context.
     * If no NLS string is defined for the security context, security context name is returned.
     * Note that only role may have an NLS value; organization and project components will always remain unchanged.
     * 
     * @param iName
     *    P&O security context name.
     * @return
     *    NLS value.
     **/
    static CATUnicodeString GetSecurityContextNLSValue(const CATUnicodeString& iName);

  private:
    /** @nodoc */
    PLMPosNLSUtil();

    /** @nodoc */
    virtual ~PLMPosNLSUtil();
};

#endif
