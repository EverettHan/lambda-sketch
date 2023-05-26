#ifndef CATLicenseAllowed_H
#define CATLicenseAllowed_H
// CATIA Version 5 Release 1 Framework ApplicationFrame
// Copyright Dassault Systemes 1998
//------------------------------------------------------------------------
//
// Abstract : 
// ---------- 
//
//------------------------------------------------------------------------
//
// Usage :    
// -------    
//
//------------------------------------------------------------------------
//
// Inheritance : 
// -----------  
//
//------------------------------------------------------------------------
//
// Main Methods :  
// -------------- 
//
//------------------------------------------------------------------------
#include "CATIAV5Level.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATLM.h"
#include "CATLicE.h"



class ExportedByCATLicE CATLicenseAllowed
{
public:

	CATLicenseAllowed ( );
	~CATLicenseAllowed ( );

	static HRESULT GetLicenses (CATListValCATUnicodeString & oNameList, CATListValCATUnicodeString & oDescList);
	static int GetNodelockAlertMsg (CATUnicodeString &oMsg, int iNbDaysAlert =0);

    // 1: Il faut afficher le panel de logon
    // 0: Il ne faut pas afficher le panel de logon
    static int IsLogOnPanelToLaunch();
    static void SetPanelToLaunch(int iPanel);

private:
	static unsigned int IsRADEProduct (CATUnicodeString & iName);
    static int IsPanelToLaunch;


};
#endif
