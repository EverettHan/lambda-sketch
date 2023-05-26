//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003                                         
//===========================================================================
//                                                                           
//  CATSysDynLicenseSettingCtrl                                               
//                                                                           
//  Usage Notes: Interface Definition                                          
//===========================================================================
//  Creation fevrier  2003                                         	
//===========================================================================
#ifndef __CATSYSDYNLICENSESETTINGCTRL
#define __CATSYSDYNLICENSESETTINGCTRL
#include "JS0LIB0.h"
#include "CATBaseUnknown.h"   
#include "CATISysSettingController.h"
#include "CATSysMacroSettingCtrl.h"
// ++vxg - 11:11:14
#include "CATLib0Debug.h"
// --vxg - 11:11:14
// COPYRIGHT DASSAULT SYSTEMES 2003


class LicenseDyn;  // defined in CATSysDynLicenseSettingCtrl.cpp
class CATUnicodeString;
class CATSettingInfo;
class CATTrace;




/**
* Interface to handle the Dynamic Licensing.
* <b>Role</b>: This interface is implemented by a component which
* represents the controller of the Dynamic Licenses. 
* <br>This interface defines:
* <ul>
* <li>A method to set each Dynamic License</li>
* <li>A method to get the value of each DynamicLicense</li>
* <li>A method to lock/unlock each parameter</li>
* <li>A method to retrieve the informations concerning each parameter</li>
* </ul>
*/
class ExportedByJS0LIB0 CATSysDynLicenseSettingCtrl : public CATSysSettingController
{
	CATDeclareSettingCtrl(CAT,Sys,DynLicense);
	
public :
	virtual ~CATSysDynLicenseSettingCtrl();
	
	HRESULT Initialize();
	
    HRESULT ResetToAdminValues(char** iAttList=NULL, int iNbAtt=0);
    HRESULT SaveRepository(const char *tmp=0);
    HRESULT Rollback();
    //HRESULT Commit(int iNoEvent);
	

/**
 * Retrieves the List of the Licenses.
 * <br><b>Role</b>: Retrieves the list of locked Licenses.
 * There are no nodelock licenses for shareable products.
 * @param oNbLic
 *   The number of License
 * @param oTabLic
 *	The array of Licenses
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
 */
	HRESULT GetLicensesList (int &oNbLic, CATUnicodeString **&oTabLic);

  
/**
 * @nodoc
 * Retrieves the List of the Licenses.
 * <br><b>Role</b>: Retrieves the list of the Licences. It is equivalent to the GetLicensesList method.
 * @param oNbLic
 *   The number of License
 * @param oTabLic
 *	The array of Licenses
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
 */
    HRESULT GetGrantedLicensesList (int &oNbLic, CATUnicodeString **&oTabLic);


/**
 * Retrieves information about the LicensesList setting locking state (global lock for the LicensesList) 
 * <br><b>Role</b>: Retrieves information about the LicensesList setting locking state (global lock for the LicensesList) 
 * It is used to get the lock status of the List of the Licenses.
 * If the LicenseList is locked all the licenses are locked.
 * When the licenses are locked, it means that an administrator has locked the attribute.
 * It does not means that an administrator has changed the value of the attribute.
 * That is the return value is false.
 * Parameter values in dump: 
 * Parameter 1 : "Value taken in case of reset" : useless
 * Parameter 2 : "Locking state" value : unlocked / locked / locked at Admin Level n
 * Parameter 3 : "Returned value" : useless, default value : False
 * @param oInfo
 *     Address of an object CATSettingInfo.
 * @return
 *	<b>Legal values</b>:
 * 	<br><tt>E_FAIL:</tt>  
*/
  HRESULT GetLicensesListInfo (CATSettingInfo * oInfo);
  
  


/**
 * Locks or unlocks the List of the Licenses .
 * <br><b>Role</b>:  Locks or unlocks the parameter describing the list of 
 * installed licenses, if the  operation is allowed in the current
 * administrated environment. In user mode  this method will always return E_FAIL.
 * If the LicenseList is locked all the licenses are locked.
 * If the LicenseList is locked all the licenses are unlocked.
 * @param iLocked
 *	the locking operation to be performed
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt>   to lock the parameter.
 * 	<br><tt>0:</tt>   to unlock the parameter.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success (the list has been successfully lock or unlocked).
 *	<br><tt>E_OUTOFMEMORY:</tt> on allocation failure
 * 	<br><tt>E_FAIL:</tt>  on other failures  
 */
  
  HRESULT SetLicensesListLock ( unsigned char iLock);
  
  

/**
 * Retrieves the value of the license.
 * <br><b>Role</b>: Retrieves the mapping between a name of a license and 
 * the value of the license.
 * Note that nodelock licenses are note different then the other licenses.
 * The nodelock licenses are as if there were requested by the end user.
 *
 * Note : generated macro after a dump action : method displayed by default when parameters are locked 
 * This method appears after a dump action by default in the generated macro when
 * administrator parameters are locked.
 * It does not return a granted or not granted status on the license.
 * Use this call to get the check_lock status of a license.
 * 
 * @param iLicense
 * <br> The license name begins with Check_
 *
 * @param oValue
 *	the value of the License.
 *	<b>Legal values</b>:
 *	<br><tt> CheckLockRequested :</tt>   check_lock requested.
 * 	<br><tt> CheckLockNotRequested :</tt>  check_lock requested.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  HRESULT GetLicense(const CATUnicodeString *iLicense, 
			     CATUnicodeString *oValue);


/**
 * Sets the License.
 * <br><b>Role</b>: Sets the value of the license.
 * It it not possible to grant a license with this call.
 * @param iLicense
 * <br> The license name begins with Check_
 *
 * @param iValue
 *	the value of the License.
 *	<b>Legal values</b>:
 *	<br><tt> CheckLockRequested :</tt>   check_lock requested.
 * 	<br><tt> CheckLockNotRequested :</tt>  check_lock requested.
 * 
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  HRESULT SetLicense(const CATUnicodeString *iLicense, 
			     const CATUnicodeString *iValue);

  HRESULT SetLicenseA(const CATUnicodeString *iLicense, 
			     const CATUnicodeString *iValue);

/**
 * Retrieves the state of a given License.
 * <br><b>Role</b>:  Retrieves the state of a given License.
 * It it is used to get le lock status of a specific license.
 * It is depricated for the check_lock status
 * When the license is locked, it means that an administrator has locked the attribute.
 * It does not means that an administrator has changed the value of the license.
 * That is why the return value is false.
 *
 * Parameter 1 : indicates the value that will be taken in case of reset (dynamic mode : Parameter 1 always equal to
 *               Default Value=> Parameter 1 is useless) 
 * In dynamic mode, an administrator cannot set the values of dynamic licenses for a user (the information is temporary)
 * no action has been done by an upper level administrator 
 * Parameter 1 = Default Value 
 * Parameter 1 : useless
 * Parameter 2 : locking state of the licenses Unlocked / Locked / Locked at Admin Level j 
 * Parameter 3 : Returned Value : True or False
 * True :  Condition 1: the setting has been explicitely modified at the current level and           
 *         Condition 2:the setting is not inherited (always True : inheritance of administrator values)
 * False : Condition 1 : the setting has not been modified at the current level or 
 *         Condition 2 : the setting has been reset (always False : Reset) or
 *         Condition 3 : the current setting value is inherited from an administrator (always False : see note 2)
 * Note 1 : Reset : dynamic mode
 * Note 2 : inheritance of administrator values 
 *
 * @param oInfo
 *	Address of an object CATSettingInfo.
 * @return
 *	<b>Legal values</b>:
 * 	<br><tt>E_FAIL:</tt> 
*/
  HRESULT GetLicenseInfo (const CATUnicodeString *iLicense,
				  CATSettingInfo* oInfo);


/** 
 * Locks or unlocks the License
 * <br><b>Role</b>: Locks or unlocks the given DLName if the
 * operation is allowed in the current administrated environment.
 * It is the global lock on all the licenses.
 * In user mode this method will always return E_FAIL.
 * @param iLocked
 *	the locking operation to be performed
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt>   to lock the parameter.
 * 	<br><tt>0:</tt>   to unlock the parameter.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  HRESULT SetLicenseLock (const CATUnicodeString *iLicense,
				  unsigned char iLock);


/** 
 * Dump the Shareable Products
 * Only status about the locks of licenses are dumped.
 * If the shareable products are not locked, there is nothing in the dump.
 * In admin mode the status checked/unchecked in taken in accont for the locks
 * When a license LLL.prd is check_locked there is a GetLicense in the dump,
 * with parameter Check_LLL.prd and value CheckLockRequested.
 * The license is not check_locked when there is no GetLicense or when the value is CheckLockNotRequested
 * There is also a GetLicenseInfo for Check_LLL.prd but it is deprecated.
 *
 * The lock on a MMM.prd is defined by the GetLicenseInfo()
 * There is a GetLicense for MMM.prd but it is deprecated.
 *
 * When the license is locked, it means that an administrator has locked the attribute.
 * It does not means that an administrator hsa changed the value of the license.
 * That is why the return value of GetLicenseListInfo and GetLicenseList is false,
 */
  virtual HRESULT Dump(char **iList=NULL, unsigned int iNb=0);

private:
	
  HRESULT AnalyzeSettings();
	
	static int Initialize_not_done;
    static CATTrace * _t;
    static LicenseDyn               * _dyn_lic;
    static int                    _ls;
    static unsigned int _NbLicAtt;
    static char ** _LicAtt;
    static unsigned int _NbLic;
    static char ** _Lic;
    static unsigned int _NbLicSorted;
    static char ** _LicSorted;
	static CATUnicodeString **_TabLic;
	static CATUnicodeString **_TabGrantedLic;
 
  

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif
