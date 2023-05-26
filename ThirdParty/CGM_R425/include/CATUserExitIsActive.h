#ifndef CATUserExitIsActive_H
#define CATUserExitIsActive_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0SCBAK.h"
#include "IUnknown.h"
#include "CATSysSimpleUE.h"

/**
	*  User Exit Management.
	**/

/**
	* Indicate the user exit status.  
	* @param iExitName
	*  User exit name.
	*  <b>Example</b>: For the interface CATIUserExitMySample 
	*  exit name parameter is MySample 
	*/

ExportedByJS0SCBAK HRESULT CATUserExitIsActive ( const char *iExitName );

/** @nodoc */
#define CATGetUserExitInterface(UEname)                                             \
	CATIUExit##UEname *lpiUE##UEname=NULL;                                              \
	CATUExit##UEname *lpoUE##UEname=NULL;                                               \
	CATSysSimpleUE *lpBO##UEname=NULL;                                                  \
	if ( CATUserExitIsActive(#UEname) == S_OK )                                         \
	{                                                                                   \
		HRESULT lHR=E_FAIL;                                                               \
		lpoUE##UEname=new CATUExit##UEname;                                             \
		if ( lpoUE##UEname )                                                            \
		{                                                                               \
			lHR=lpoUE##UEname->QueryInterface( IID_CATIUExit##UEname,(void **)&lpiUE##UEname);\
			if(lHR != S_OK)                                                                \
			{                                                                              \
				lpoUE##UEname->Release();                                                     \
				lpoUE##UEname=NULL;                                                           \
			}                                                                              \
		}                                                                               \
		if(lHR != S_OK)                                                                   \
		{                                                                                 \
			lpiUE##UEname=NULL;                                                             \
		}                                                                                 \
	}

/** @nodoc */
#define CATReleaseUserExitObjects(UEname)                                           \
	if (lpBO##UEname)                                                                   \
	{                                                                                   \
		lpBO##UEname->Release();                                                          \
		lpBO##UEname=NULL;                                                                \
	}                                                                                   \
	if (lpiUE##UEname)                                                                  \
	{                                                                                   \
		lpiUE##UEname->Release();                                                         \
		lpiUE##UEname=NULL;                                                               \
	}                                                                                   \
	if (lpoUE##UEname)                                                                  \
	{                                                                                   \
		lpoUE##UEname->Release();                                                         \
		lpoUE##UEname=NULL;                                                               \
	}


#endif
