#ifndef CATDynProductList_h
#define CATDynProductList_h
// COPYRIGHT DASSAULT SYSTEMES 2002
//=================================================================
#define _NEW_SETTINGS_R14 1
//#define _SETTINGS_R15 1
#define _SETTINGS_NOKIA_R15 1

#include "LicensingFR.h"  // exportedby
#include "CATDlgInclude.h"
#ifdef _NEW_SETTINGS_R14
#include "CATISysDynLicenseSettingAtt.h"
#include "CATIADynLicenseSettingAtt.h"
#endif
#ifdef _SETTINGS_NOKIA_R15 
#include "CATDynProd.h"
#endif

#ifdef _NEW_SETTINGS_R14
class CATISysLicenseSettingAtt;
class CATIALicenseSettingAtt;
#endif

class CATDynProduct;
class CATDlgLock;
#ifdef _SETTINGS_NOKIA_R15 
class CATDynProd;
#endif

#include "CATListOfCATUnicodeString.h"

#define R12SortedLic 

//------------------------------------------------------------------
class ExportedByLicensingFR CATDynProductList : public CATDlgFrame
{
public:
	
	enum Style {
		ActiveAndLicDyn = 0,
			ActiveAndNoLicDyn,
			NotActive
	};
	
	CATDynProductList (       CATDialog                 * father,
		const CATString                 & name,
		CATListOfCATUnicodeString & LintName,
		CATListOfCATUnicodeString & LoffName,
#ifdef _SETTINGS_NOKIA_R15 
		CATDynProd               ** DynProd,
		unsigned int              & NbConfig,
#endif
		Style                       style=ActiveAndLicDyn);
	
	~CATDynProductList ( );
	
	void SetDefault     ( );
	void SetSensitivity ( CATULong mode );
	void ShowLock       ( char oLock );
	void GetDefault      (CATListOfCATUnicodeString & LintNameSorted, CATListOfCATUnicodeString & LoffNameSorted); 
	
protected:
	
	void ManageLock         (CATCommand *, CATNotification *, CATCommandClientData);
	void ManageCheck        (CATCommand *, CATNotification *, CATCommandClientData);
	void SigModification    (CATCommand *, CATNotification *, CATCommandClientData);
	
	CATListOfCATUnicodeString _LintName;
	CATListOfCATUnicodeString _LoffName;
	CATListOfCATUnicodeString _LintNameRequest;
	CATListOfCATUnicodeString _LoffNameRequest;
	CATListOfCATUnicodeString _LintNameNotRequest;
	CATListOfCATUnicodeString _LoffNameNotRequest;
	
	CATDynProduct  ** _rp;
	CATDlgLock     ** _lk;
	int               _UnCoup;
	Style             _style;
	
#ifdef _NEW_SETTINGS_R14
	CATISysDynLicenseSettingAtt * _LicAttr;
	CATIADynLicenseSettingAtt * _LicAttrVB;
#endif
//#ifdef _SETTINGS_R15
	int _RequestedMode;
	int _RealMode;
//#endif
#ifdef _SETTINGS_NOKIA_R15 
	CATDynProd ** _DynProd;
	unsigned int  _NbConfig;
#endif
	
	
};
#endif
