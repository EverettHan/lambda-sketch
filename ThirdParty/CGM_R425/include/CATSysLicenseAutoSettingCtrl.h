//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003                                         
//===========================================================================
//                                                                           
//  CATSysLicenseAutoSettingCtrl                                               
//  Implementation for License Setting Controller                                
//                                                                           
//  Usage Notes: Interface Definition                                          
//===========================================================================
//  Creation fevrier  2003                                 adt         	
//===========================================================================
#ifndef __CATSYSLICENAUTOSESETTINGCTRL
#define __CATSYSLICENAUTOSESETTINGCTRL
#include "JS0LIB0.h"

#include "CATCORBABoolean.h"
#include "CAT_VARIANT_BOOL.h"
#include "CATBSTR.h"
#include "CATIASettingController.h"
#include "CATSafeArray.h"
#include "CATSysMacroSettingCtrl.h"



class ExportedByJS0LIB0 CATSysLicenseAutoSettingCtrl : public CATSysAutoSettingController
{
  // Macro for declaration of the SysLicenseSetting controller
	CATDeclareAutoSettingCtrl(CAT,Sys,License);
	

public :
	
	HRESULT get_ServerTimeOut (float &oTimeOut);
	
	HRESULT put_ServerTimeOut (float iTimeOut);

	HRESULT GetServerTimeOutInfo (CATBSTR & AdminLevel, 
				     CATBSTR & oLocked, 
				     CAT_VARIANT_BOOL & oModified);
	
	HRESULT SetServerTimeOutLock (CAT_VARIANT_BOOL iLock);

	
	HRESULT get_NodelockAlert (CATLONG &oAlert);
	
	HRESULT put_NodelockAlert (CATLONG iAlert);

	HRESULT GetNodelockAlertInfo (CATBSTR & AdminLevel, 
				     CATBSTR & oLocked, 
				     CAT_VARIANT_BOOL & oModified);
	
	HRESULT SetNodelockAlertLock (CAT_VARIANT_BOOL iLock);


	HRESULT get_Frequency (float &oFrequency);
	
	HRESULT put_Frequency (float iFrequency);
	
	HRESULT GetFrequencyInfo (CATBSTR & AdminLevel, 
				     CATBSTR & oLocked, 
				     CAT_VARIANT_BOOL & oModified);
	
	HRESULT SetFrequencyLock (CAT_VARIANT_BOOL iLock);

	
	HRESULT get_ShowLicense (CAT_VARIANT_BOOL &oRight);
	
	HRESULT put_ShowLicense (CAT_VARIANT_BOOL iRight);
	
	HRESULT GetShowLicenseInfo (CATBSTR & AdminLevel, 
				     CATBSTR & oLocked, 
				     CAT_VARIANT_BOOL & oModified);
	
	HRESULT SetShowLicenseLock (CAT_VARIANT_BOOL iLock);

	
	HRESULT GetLicensesList (CATLONG iDefaultLicenses, CATSafeArrayVariant *&oTabLic);

	HRESULT GetLicensesListInfo (CATBSTR & AdminLevel, 
				     CATBSTR & oLocked, 
				     CAT_VARIANT_BOOL & oModified);
	
	HRESULT SetLicensesListLock ( CAT_VARIANT_BOOL iLock);

	
	HRESULT GetLicense(const CATBSTR &iLicense, CATBSTR &oValue);
	
    HRESULT SetLicense(const CATBSTR &iLicense, const CATBSTR &iValue);
	
    HRESULT GetLicenseInfo (const CATBSTR &iLicense,
		             CATBSTR & AdminLevel, 
				     CATBSTR & oLocked, 
				     CAT_VARIANT_BOOL & oModified);
	
	HRESULT SetLicenseLock (const CATBSTR &iLicense, CAT_VARIANT_BOOL iLock);	
};




#endif


