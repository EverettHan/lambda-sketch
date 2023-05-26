//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003                                         
//===========================================================================
//                                                                           
//  CATSysLicenseSettingCtrl                                               
//                                                                           
//  Usage Notes: Interface Definition                                          
//===========================================================================
//  Creation fevrier  2003                                 adt         	
//===========================================================================
#ifndef __CATSYSLICENSESETTINGCTRL
#define __CATSYSLICENSESETTINGCTRL
#include "JS0LIB0.h"
#include "CATBaseUnknown.h"   
#include "CATISysSettingController.h"
#include "CATSysMacroSettingCtrl.h"
// ++vxg - 11:11:14
#include "CATLib0Debug.h"
// --vxg - 11:11:14
// COPYRIGHT DASSAULT SYSTEMES 2003


class CATUnicodeString;
class CATSettingInfo;
class CATTrace;




/**
* Interface to handle the Licensing.
* <b>Role</b>: This interface is implemented by a component which
* represents the controller of the static Licenses. 
* <br>This interface defines:
* <ul>
* <li>A method to set each License</li>
* <li>A method to get the value of each License</li>
* <li>A method to lock/unlock each parameter</li>
* <li>A method to retrieve the informations concerning each parameter</li>
* </ul>
*/
class ExportedByJS0LIB0 CATSysLicenseSettingCtrl : public CATSysSettingController
{
	CATDeclareSettingCtrl(CAT,Sys,License);
public :
  static CATSysLicenseSettingCtrl *GetTheController();
	
public :
	virtual ~CATSysLicenseSettingCtrl();
	
	HRESULT Initialize();
	
	/* si besoin 
    HRESULT ResetToAdminValues(char** iAttList=NULL, int iNbAtt=0);
    HRESULT SaveRepository(const char *tmp=0);
    HRESULT Rollback();
    HRESULT Commit(int iNoEvent);
	*/
	HRESULT UnMake();
	
	/**
	* Retrieves server time out .
	* <br><b>Role</b>:  Retrieves the value of the parameter describing the 
	* licensing server time out.
	* @param oTimeOut
	*     Licensing server time out in seconds.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on failure
	*/
	HRESULT GetServerTimeOut (float &oTimeOut);
	
	
	/**
	* Sets server time out .
	* <br><b>Role</b>:  Sets the value of the parameter describing the
	* licensing server time out.
	* @param iTimeOut
	*     Licensing server time out in seconds.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on failure
	*/
	HRESULT SetServerTimeOut (float iTimeOut);
	
	
	/**
	* Retrieves the state of the parameter TimeOut
	* <br><b>Role</b>:  Retrieves the state of the parameter describing the
	* licensing server time out.
	* @param oInfo
	*     Address of an object CATSettingInfo.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on failure
	*/
	HRESULT GetServerTimeOutInfo (CATSettingInfo *oInfo);
	
	/**
	* Locks or unlocks the parameter TimeOut
	* <br><b>Role</b>:  Locks or unlocks the parameter describing the
	* licensing server time out,if the  operation is allowed in the current 
	* administrated environment. In user mode  this method
	* will always return E_FAIL.
	* @param iLocked
	*	the locking operation to be performed
	*	<b>Legal values</b>:
	*	<br><tt>1 :</tt>   to lock the parameter.
	* 	<br><tt>0:</tt>   to unlock the parameter.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	*	<br><tt>E_OUTOFMEMORY:</tt> on allocation failure
	* 	<br><tt>E_FAIL:</tt>  on other failures
	*/
	HRESULT SetServerTimeOutLock (unsigned char iLock);
	
	
	/**
	* Retrieves nodelock alert .
	* <br><b>Role</b>:  Retrieves the value of the parameter describing the 
	* licensing nodelock alert . 
	* @param oAlert
	*     Licensing nodelock alert in days.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on failure
	*/
	HRESULT GetNodelockAlert (long &oAlert);
	
	
	/**
	* Sets nodelock alert .
	* <br><b>Role</b>:  Sets the value of the parameter describing the
	* licensing nodelock alert . The value of the parameter must be between 0 and 90.
	* @param iTimeOut
	*     Licensing nodelock alert in days.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on failure
	*/
	HRESULT SetNodelockAlert (long iAlert);
	
	
	/**
	* Retrieves the state of the parameter nodelock alert .
	* <br><b>Role</b>:  Retrieves the state of the parameter describing the
	* licensing nodelock alert.
	* @param oInfo
	*     Address of an object CATSettingInfo.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on failure
	*/
	HRESULT GetNodelockAlertInfo (CATSettingInfo *oInfo);
	

	/**
	* Locks or unlocks the parameter nodelock alert .
	* <br><b>Role</b>:  Locks or unlocks the parameter describing the
	* licensing server time out,if the  operation is allowed in the current 
	* administrated environment. In user mode this method
	* will always return E_FAIL.
	* @param iLocked
	*	the locking operation to be performed
	*	<b>Legal values</b>:
	*	<br><tt>1 :</tt>   to lock the parameter.
	* 	<br><tt>0:</tt>   to unlock the parameter.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	*	<br><tt>E_OUTOFMEMORY:</tt> on allocation failure
	* 	<br><tt>E_FAIL:</tt>  on other failures
	*/
	HRESULT SetNodelockAlertLock (unsigned char iLock);
	

	/**
	* Retrieves the server contact frequency .
	* <br><b>Role</b>:  Retrieves the value of the parameter describing the 
	* licensing server contact frequency. A value of 0 represent the maximum .
	* @param oFrequency
	*     Licensing server contact frequency.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on failure
	*/
	HRESULT GetFrequency (float &oFrequency);
	
	
	/**
	* Sets the server contact frequency.
	* <br><b>Role</b>:  Sets tthe value of the parameter describing the 
	* licensing server contact frequency. A value of 0 represent the maximum .
	* @param iFrequency
	*     Licensing server contact frequency.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on failure
	*/
	HRESULT SetFrequency (unsigned int iFrequency);
	
	
	/**
	* Retrieves the state of the parameter server contact frequency .
	* <br><b>Role</b>:  Retrieves the state of the parameter describing the
	* licensing server contact frequency.
	* @param oInfo
	*     Address of an object CATSettingInfo.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on failure
	*/
	HRESULT GetFrequencyInfo (CATSettingInfo *oInfo);
	
	
	/**
	* Locks or unlocks the parameter server contact frequency .
	* <br><b>Role</b>:  Locks or unlocks the parameter describing the
	* server contact frequency, if the  operation is allowed in the current
	*  administrated environment. In user mode  this method
	* will always return E_FAIL.
	* @param iLocked
	*	the locking operation to be performed
	*	<b>Legal values</b>:
	*	<br><tt>1 :</tt>   to lock the parameter.
	* 	<br><tt>0:</tt>   to unlock the parameter.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	*	<br><tt>E_OUTOFMEMORY:</tt> on allocation failure
	* 	<br><tt>E_FAIL:</tt>  on other failures
	*/
	HRESULT SetFrequencyLock (unsigned char iLock);
	
	
	
	
	/**
	* Retrieves if licenses information has to be shown .
	* <br><b>Role</b>:  Retrieves the value of the parameter describing if complete 
	* licenses information has to be shown.
	* When the parameter is set, the user gets more information about the reason of the failure to request a license.
	* @param oRight
	*     TRUE if the information has to be shown.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on failure
	*/
	HRESULT GetShowLicense (unsigned char &oRight);
	
	
	/**
	* Sets the value of the parameter ShowLicense.
	* <br><b>Role</b>:  Sets the value of the parameter that discribing if complete
	* license information has to be shown.
	* When the parameter is set, the user gets more information about the reason of the failure to request a license.
	* @param iRight
	*     TRUE if the information has to be shown.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on failure
	*/
	HRESULT SetShowLicense (unsigned char iRight);
	
	
	/**
	* Retrieves the state of the parameter ShowLicense .
	* <br><b>Role</b>:  Retrieves the state of the parameter describing if complete
	* license information has to be shown.
	* @param oInfo
	*     Address of an object CATSettingInfo.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on failure
	*/
	HRESULT GetShowLicenseInfo (CATSettingInfo *oInfo);
	
	/**
	* Locks or unlocks the parameter ShowLicense .
	* <br><b>Role</b>:  Locks or unlocks the parameter describing the if complete
	* license information has to be shown, if the  operation is allowed in the current
	* administrated environment. In user mode  this method will always return E_FAIL.
	* @param iLocked
	*	the locking operation to be performed
	*	<b>Legal values</b>:
	*	<br><tt>1 :</tt>   to lock the parameter.
	* 	<br><tt>0:</tt>   to unlock the parameter.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	*	<br><tt>E_OUTOFMEMORY:</tt> on allocation failure
	* 	<br><tt>E_FAIL:</tt>  on other failures
	*/
	HRESULT SetShowLicenseLock (unsigned char iLock);
	
	
	/**
	* Retrieves the List of the requested or locked Licenses .
	* <br><b>Role</b>: Retrieves the list of the Licenses.
	* @param oNbLic
	*   The number of License
	* @param oTabLic
	*	The array of Licenses
    *   You are responsible of the deallocation of oTabLic:
    *	if (oTabLic)
    *	{
    *		for (int Index = 0; Index < oNbLic; Index++)
    *			delete oTabLic[Index];
    *		delete [] oTabLic;
    *		oTabLic = NULL;
    *	}
    * @param iDefaultLicenses
    *  If iDefaultLicenses!=0 and the settings are empty, returns the default licenses,
    *  that is, the visible nodolocked licenses
	*  If iDefaultLicenses == 0 and the settings are empty, returns the selected licenses.
	*
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on failure
	*/
	HRESULT GetLicensesList (int &oNbLic, long iDefaultLicenses , CATUnicodeString **&oTabLic);
	
   /**
    * Retrieves information about the LicensesList setting locking state
	* <br><b>Role</b>: Retrieves information about the LicensesList setting locking state
	* (global lock for the LicensesList).
	* Retrieves the state of the parameter List of the
	* Licenses. It is used to get the lock status of the List of the Licenses.
	* If the LicenseList is locked all the licenses are locked.
	* Information returned in the dump:
    * Parameter 1 : "Value taken in case of reset" : useless 
    *                default value : Default value
    * Parameter 2 : "Locking state"
    *                value : unlocked / locked / locked at Admin Level n
    * Parameter 3 : "Returned value" : useless 
    *                 default value : False
	* @param oInfo
	*     Address of an object CATSettingInfo.
    * @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on failure
	*/
	HRESULT GetLicensesListInfo (CATSettingInfo * oInfo);
	
	
	
	
	/**
	* Locks or unlocks the List of the Licenses.
	* <br><b>Role</b>:  Locks or unlocks the parameter describing the list of 
	* installed licenses, if the  operation is allowed in the current
	* administrated environment. It is the global lock on all the licenses.
	* In user mode  this method will always return E_FAIL.
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
	* The license does not need to be returned by GetLicensesList().
	* If the license is nodelock no information is returned.
	* 
	* @param iLicense
	*
	* @param oValue
	*	the value of the License.
	*	<b>Legal values</b>:
	*	<br><tt> Not requested :</tt>   License is not Requested.
	* 	<br><tt> key :</tt>  a License Name. License is Requested.
	*   <br><tt> License Number :</tt> a Number of License. License is Requested.
	*
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* 	<br><tt>E_FAIL:</tt>  on Failure. A problem occured during setting file access. 
	*/
	HRESULT GetLicense(const CATUnicodeString *iLicense, CATUnicodeString *oValue);
	
	
    /**
     * Sets the License.
	 * <br><b>Role</b>: Sets the value of the license.
	 * @param iLicense
	 *
	 * @param iValue
	 *	the value of the License.
	 *	<b>Legal values</b>:
	 *	<br><tt> Not requested :</tt>   License is not Requested
	 * 	<br><tt> key :</tt>  a License Name. License is Requested.
	 *  <br><tt> License Number :</tt> a Number od License. License is Requested.
	 * 
	 * @return
	 *	<b>Legal values</b>:
	 *	<br><tt>S_OK :</tt>   on Success
	 * 	<br><tt>E_FAIL:</tt>  on failure
	 */
	 HRESULT SetLicense(const CATUnicodeString *iLicense, const CATUnicodeString *iValue);
	
	
/**
* Retrieves the state of a given License.
* <br><b>Role</b>:  Retrieves the state of a given License.
* It it is used to get le lock status of a specific license.
* It is depricated for the check_lock status
* When the license is locked, it means that an administrator has locked the attribute.
* It does not means that an administrator has changed the value of the license.
* That is why the return value is false.
*
* Analysis of the returned parameters in dump: 
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
	 HRESULT GetLicenseInfo (const CATUnicodeString *iLicense, CATSettingInfo* oInfo);
	
	
    /** 
	 * Locks or unlocks the License
	 * <br><b>Role</b>: Locks or unlocks the given DLName if the
	 * operation is allowed in the current administrated environment. In user mode 
	 * this method will always return E_FAIL.
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
	HRESULT SetLicenseLock (const CATUnicodeString *iLicense, unsigned char iLock);
	
     virtual HRESULT Dump(char **iList=NULL, unsigned int iNb=0);

	enum DemoMode
	{
		DemoOff = 0,
			DemoOn,
			NoDemoMode
	};
	
	enum LicServerInfo
	{
		InfoOff = 0,
			InfoOn
	};	

private:
	HRESULT AnalyzeSettings ();
	
	static int Initialize_not_done;
    static CATTrace * t;
    static unsigned int _NbLicAtt;
    static char ** _LicAtt;
    static unsigned int _NbLic;
    static char ** _Lic;
    static unsigned int _NbLicSorted;
    static unsigned int _NbGrantedLicSorted;
    static char ** _LicSorted;
	static CATUnicodeString **_TabLic;
	static CATUnicodeString **_TabGrantedLic;
    static DemoMode      dm;
    static CATSysLicenseSettingCtrl::LicServerInfo so;
    static float                             to;
    static long                               ea;
    static float                             cf;
    static int                               ls;
	
	
};




#endif


