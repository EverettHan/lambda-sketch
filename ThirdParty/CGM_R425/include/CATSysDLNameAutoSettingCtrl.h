#ifndef CATIADLNameAutoSettingCtrl_h
#define CATIADLNameAutoSettingCtrl_h

#include "CATCORBABoolean.h"
#include "CAT_VARIANT_BOOL.h"
#include "CATBSTR.h"
#include "CATIASettingController.h"
#include "CATSafeArray.h"
#include "CATSysMacroSettingCtrl.h"


class ExportedByJS0STDLIB CATSysDLNameAutoSettingCtrl : 
  public CATSysAutoSettingController
{
  CATDeclareAutoSettingCtrl(CAT,Sys,DLName);

  
public:
  
  HRESULT get_DLNameCreationRight(CAT_VARIANT_BOOL & oAllowed);
    
  HRESULT put_DLNameCreationRight(CAT_VARIANT_BOOL oAllowed);
  
  HRESULT SetDLNameCreationRightLock(CAT_VARIANT_BOOL iLocked);

  HRESULT GetDLNameCreationRightInfo(CATBSTR & AdminLevel, 
				     CATBSTR & oLocked, 
				     CAT_VARIANT_BOOL & oModified);
  HRESULT get_RootDLNameCreationRight(CAT_VARIANT_BOOL & oAllowed);
    
  HRESULT put_RootDLNameCreationRight(CAT_VARIANT_BOOL oAllowed);
  
  HRESULT SetRootDLNameCreationRightLock(CAT_VARIANT_BOOL iLocked);

  HRESULT GetRootDLNameCreationRightInfo(CATBSTR & AdminLevel, 
					 CATBSTR & oLocked, 
					 CAT_VARIANT_BOOL & oModified);
  
  HRESULT GetDLNameList(CATSafeArrayVariant *& oTabDLName);
  
  HRESULT GetDLNameSubList(const CATBSTR & iDLName, 
			   CATSafeArrayVariant *& oTabDLName);
  
  HRESULT GetDLName(const CATBSTR & iDLName, CATBSTR & oRealNameUnix, 
		    CATBSTR & oRealNameNT, CATBSTR & oFather);
  
  HRESULT GetDLNameExp(const CATBSTR & iDLName, CATBSTR & oRealNameUnix, 
		       CATBSTR & oRealNameNT, CATBSTR & oFather);
  
  HRESULT SetDLName(const CATBSTR & iDLName, const CATBSTR & iRealNameUnix, 
		    const CATBSTR & iRealNameNT, const CATBSTR & iFather, 
		    CAT_VARIANT_BOOL iVerifDirectory);
  
  HRESULT SetDLNameLock(const CATBSTR & iDLName, CAT_VARIANT_BOOL iLocked);
  
  HRESULT GetDLNameInfo(const CATBSTR & iDLName, 
			CATBSTR & AdminLevel, 
			CATBSTR & oLocked, 
			CAT_VARIANT_BOOL & oModified);
  
  HRESULT RemoveDLName(const CATBSTR & iDLName);
  
  HRESULT RenameDLName(const CATBSTR & iDLName, const CATBSTR & iNewName);
  
  
};


#endif
