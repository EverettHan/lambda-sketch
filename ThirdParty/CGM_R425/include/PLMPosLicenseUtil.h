#ifndef _PLMPosLicenseUtil_h_
#define _PLMPosLicenseUtil_h_

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @level Protected
 * @usage U1
 */

#define PLMLicensingV6

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfInt.h"
#include "CATHashDicOfCATUnicodeString.h"
#include "ExportedByGUIDPLMPosBaseInterfaces.h"



#include "PLMIVariableManager.h"



/**
 * PLM security token class.
 * <b>Role</b>: This class contains and manages the Security Token, i.e. the 
 * information that is necessary for the ENOVIA Core Server to setup the P&O
 * and Security environment, so as to provide run-time security services to PLM
 * commands.
 */
class ExportedByGUIDPLMPosBaseInterfaces PLMPosLicenseUtil
{

  public:
    /**
     * Get the EV6 connection's variable manager
     **/
    static HRESULT GetVariableManager(PLMIVariableManager_var &oVarMgr);
    /**
     * Get list of license servers
     **/
    static HRESULT GetLicenseServers(CATListValCATUnicodeString& oList);
    /**
     * Get list of licenses
     **/
    static HRESULT GetLicenses(CATListValCATUnicodeString& oList);
    /**
     * Get list of casual licenses
     **/
    static HRESULT GetCasualLicenses(CATListValCATUnicodeString& oList, CATListOfInt& oListHours);
    /**
     * Get list of contexts
     **/
    static HRESULT GetListOfContexts(CATListValCATUnicodeString& oList);
    /**
     * Get list of commands
     **/
    static HRESULT GetListOfCommands(CATListValCATUnicodeString& oList);
    /**
     * Gets mask name
     **/
    static HRESULT GetMaskName(CATUnicodeString& osMaskName);
    /**
     * Gets server ID
     **/
    static HRESULT GetServerID(CATUnicodeString& osID);
    /**
     * Gets user alias
     **/
    static HRESULT GetUserAlias(CATUnicodeString& osID);
    /**
     * Gets a variable's value
     **/
    static HRESULT GetVar(const CATUnicodeString& isVar, CATUnicodeString& osValue);
    /** @nodoc */
    static HRESULT NextVar(CATUnicodeString& osVar, CATUnicodeString& osValue);
    /**
     * Gets current login project solution
     **/
    static HRESULT GetCurrentLoginProjectSolution(CATUnicodeString& oProjectSolution);
    /**
     * Gets current login project family
     **/
    static HRESULT GetCurrentLoginProjectFamily(CATUnicodeString& oProjectFamily);
    /**
     * Reset list of licenses
     **/
    static HRESULT ResetLicenses(const CATListValCATUnicodeString& iList, const CATListValCATUnicodeString& iCasualList, const CATListOfInt& iCasualListHours);
    /**
     * reserved
     **/
    static HRESULT AvoidReset(int iAvoid);

  protected:
    /** @nodoc */
    PLMPosLicenseUtil();
    /** @nodoc */
    ~PLMPosLicenseUtil();
    /**
     * List of license servers
     */
    CATListValCATUnicodeString _servers;
    /**
     * List of licenses
     */
    CATListValCATUnicodeString _licenses;
    /**
     * List of casual licenses
     */
    CATListValCATUnicodeString _casuallicenses;
    CATListOfInt _casualhours;
    /**
     * List of security contexts
     */
    CATListValCATUnicodeString _contexts;
    /**
     * List of global commands
     */
    CATListValCATUnicodeString _commands;
    /**
     * Mask name
     */
    CATUnicodeString           _mask_name;
    /**
     * Current login project solution
     */
    CATUnicodeString           _cur_prj_solution;
    /**
     * Current login project family
     */
    CATUnicodeString           _cur_prj_family;
    /**
     * Server ID
     */
    CATUnicodeString           _server_id;
    /**
     * Server ID
     */
    CATUnicodeString           _user_alias;
    /**
     * @nodoc
     */
    int                        _initialized;
    /**
     * @nodoc
     */
    int                        _avoid_reset;
    /**
     * @nodoc
     */
    PLMIVariableManager_var    _vVarMgr;
    /**
     * @nodoc
     */
    CATHashDicCATUnicodeString _vars;
    /** @nodoc */
    static int _nVarBucket;
    static int _nVarPosition;
    static void ResetVarIterator();
    /**
     * LicenseUtil singleton
     */
    static const PLMPosLicenseUtil* _util_ptr;
    static const PLMPosLicenseUtil& util();
};

#endif
