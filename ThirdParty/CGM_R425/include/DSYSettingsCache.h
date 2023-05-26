

#ifndef _DSYSETTINGSCACHE_H_
#define _DSYSETTINGSCACHE_H_

#include "CATLib.h"
#include "JS0SETT.h"
#include "CATSysTSListOfUnicodeString.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATGetEntryPoint.h"


#define DEFAULT_ENVNAME "DefaultEnv"



class ExportedByJS0SETT  DSYSettingsCache
{

public:
	//----------------
	// Constructors 
	//----------------
	DSYSettingsCache(); 

	//-----------
	//Destructor
	//------------
	virtual ~DSYSettingsCache();
	
	
	HRESULT InitCache(CATUnicodeString * iCacheDir=NULL);	
	/*
	* Check that the provided environment folder has a correct folder strcture in cache
	*/
	HRESULT CheckEnvFolders(const CATUnicodeString iEnvName);
	/*
	* Read the environment hierarchy of the  provided environment name , provide  a list starting from the current environment and higher.
	*/
	HRESULT ReadHierarchy(CATListOfCATUnicodeString & oEnvList, CATUnicodeString & iEnvName);
	/*
	* Write  the environment hierarchy  provided  as  a list in the same format described  above.
	*/
	HRESULT WriteHierarchy(CATUnicodeString & iEnvName, CATListOfCATUnicodeString & iEnvList);
	/*
	* Retrieve the environment directory in cache for the provided environment name. 
	*/
	HRESULT GetEnvDir( CATUnicodeString & iEnvName,char iMode, CATUnicodeString & oEnvDir);
	/*
	* Create the environment directory in cache for the provided environment name. The directory is created without any settings ( blank environment )
	*/
	HRESULT CreateEnvFoldersInCache(CATUnicodeString & iEnvToCreate);
	/*
	* Update a list of settings files provided with iStreamsToUpdate in the iEnvToUpdate environment, in iMode mode.
	*/
	HRESULT UpdateEnvRepositories(CATUnicodeString & iEnvToUpdate, char iMode , CATListOfCATUnicodeString iStreamsToUpdate  );
	/*
	* Read the last environment used in cache
	*/
	HRESULT ReadLastEnv(CATUnicodeString & oEnv);
	/*
	* Set the last environment used in cache
	*/
	HRESULT WriteLastEnv(CATUnicodeString  iEnv);	
	/*
	* Copy settings files from one environment to another in the provided Mode.
	*/
	HRESULT CopySettings(CATUnicodeString & iEnvFrom,CATUnicodeString & iEnvTo,char iMode );
	/*
	* Remove a settings environment directory.
	*/	
	HRESULT RemoveEnvFromCache(CATUnicodeString & iEnvName);
	/*
	*
	*/
	HRESULT RemoveAllSettingsInEnvironment(CATUnicodeString & iEnvName , char iMode);
	
private:
	CATUnicodeString _SettingsCacheDir;
};


#endif 

