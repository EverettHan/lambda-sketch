

#ifndef _DSYSETTINGSESSIONMANAGER_H_
#define _DSYSETTINGSESSIONMANAGER_H_


#include "DSYSettingsCache.h"
#include "CATHashDico.h"
#include "CATUnicodeString.h"
#include "env.h"


enum DSYSettingSaveLevel { SAVE_TO_DATABASE =1, SAVE_TO_FILE=0, NO_SAVE=-1};
enum DSYSettingReloadLevel {TOTAL=2 , PARTIAL=1 , NO_RELOAD=0 };
enum UpdateMode {CRC_CHECK, VERSION_CHECK};


// Access to setting streams in DB
typedef  HRESULT ( * InitSettingsEnvironment )(CATUnicodeString & iEnvName, char iMode,const char * iProviderName);
typedef  HRESULT (* GetParentUserSettingsEnvironmentNames) (CATListOfCATUnicodeString & oParents);
typedef  HRESULT  (* GetSettingsStreams) (CATUnicodeString  &iSettingsName,CATListOfCATUnicodeString & oStreams ); 
typedef  HRESULT  (*GetAllSettingsStreams) (CATHashDico  & oStreamsDic,CATHashDico  & oPreferencesDic, CATSysTSUnicodeString  iStopAtLevel);
typedef  HRESULT (*SetSettingsStreams)(const CATUnicodeString &iSettingsName, const CATUnicodeString &iFilePath);
typedef  HRESULT (*SaveSettingsStreams)();
typedef HRESULT (*CloseEnv)();
typedef  HRESULT ( * DeleteAllSettingsFunction )();

/*
* This class represents the settings session seen as 
*/

class ExportedByJS0SETT  DSYSettingSessionManager
{

public:
	//----------------
	// Constructors 
	//----------------
	DSYSettingSessionManager();
	
	//-----------
	//Destructor
	//------------
	virtual ~DSYSettingSessionManager();
	
	DSYSettingsCache * GetCacheManager();
	
	/*
	* Input params:
	* pioUserEnv : User input settings path object to be positioned when method succeeds.
	* pioAdminEnv : Admin input settings path object to be positioned when method succeeds. Remains NULL when in admin mode.
	* iMode: Desired mode for setup.
	* oMode: Obtained mode for setup.
	*
	* Setup a minimal settings environment with the information available in cache to allow the application to start settings edition. 
	* If the cache doesn't show a last environment then the environment used is called "DefaultEnv" until a new environment name is defined in online setup.
	* If the cache shows a last used environment then it is used until final setup where it can be changed or not depending on whether the user chooses
	* to keep the previous environment or not. 
	*/
	HRESULT SetupFromCache(char iMode,char & oMode,CATSettingEnv * & pioUserEnv,CATSettingEnv *& pioAdminEnv);
	
	/*
	* Input params:
	* pioUserEnv : User input settings path object to be positioned when method succeeds.
	* pioAdminEnv : Admin input settings path object to be positioned when method succeeds. Remains NULL when in admin mode.
	* oReloadLevel : Level at which settings must be reloaded to be consistant with the new cache structure.
	*
	*  Setup an offline session. This means settings are edited and saved in cache but no interaction with the server is possible
	*  This might be useful in batch mode for example.
	*/
	HRESULT SetupOffline(CATSettingEnv * & pioUserEnv,CATSettingEnv *& pioAdminEnv,
											DSYSettingReloadLevel & oReloadLevel);
	
	/*
	* Input params:
	* pioUserEnv : User input settings path object to be positioned when method succeeds.
	* pioAdminEnv : Admin input settings path object to be positioned when method succeeds. Remains NULL when in admin mode.
	* iProviderName: Name of the provider on which settings should be initialized. Currently only "PLM1" is supported. Any other input leads t initialisation failure.
	* oReloadLevel : Level at which settings must be reloaded to be consistant with the new cache structure.
	*
	* Returns:
	* S_OK if successful
	* E_ACCESSDENIED when administration priveleges are required on a non authorized context or with a non authorized user.
	* E_FAIL for any other inialisation failure. 
	*
	*  Setup an online session. Allows settings to be edited and saved in cache. If this method succeeds, online environment is also available 
	*  and settings can be retrieved from/saved to the database
	*  oEnvSwitch : Tells whether the current environment is the one that was used in the previous session. 
	*/
	virtual HRESULT SetupOnline(CATSettingEnv *&  pioUserEnv,CATSettingEnv *& pioAdminEnv, 
															char * iProviderName,DSYSettingReloadLevel & oReloadLevel);
		
	/*
	* Input params:
	* iExcludedSettings : Settings that should not be refreshed even if a newer version is available from the server. 
	* oSettingsToReload : Settings that were replaced by the refresh operation. 
	* ioReloadLevel: Required reload level obtained from setup operation.
	*Returns:
	* S_OK if succcessful
	* E_FAIL on failure
	*
	* Refresh  settings from the server for an initialized session.
	*/
	HRESULT RefreshSettings(CATListOfCATUnicodeString & iExcludedSettings,CATListOfCATUnicodeString & oRefreshedSettings, DSYSettingReloadLevel & ioReloadLevel,CATUnicodeString  iStopAtLevel="");	
	/*
	* Tells the CATIA session that the provided setting  should be saved at the next "save" operation.
	*/
	HRESULT Dirtify(CATUnicodeString & iSettingToDirtify);
	
	/*
	* Tells the CATIA session that the provided settings list should be saved at the next "save" operation.
	*/
	HRESULT Dirtify(CATListOfCATUnicodeString & iSettingsToDirtify);	
	
	/*
	* Tells where setttings can be saved at this stahe of session life.
	*/
	DSYSettingSaveLevel GetSaveLevel();
	/*
	*  Set the same save level.
	*/
	HRESULT SetSaveLevel(DSYSettingSaveLevel iSaveLevel);
	/*
	* Save dirty settings in session.
	*/
	HRESULT Save();
	/*
	* Delete all settings in the current environment.
	*/
	HRESULT DeleteAllSettings();
	
	/*
	* Clean editor bag for settings in session (  P&O Objects )
	*/
	virtual HRESULT Clean();
	/*
	* Has RefreshSettings  been successfully called ? 
	*/
	bool IsCacheRefreshed();
	/*
	* Has setup ( online/offline )  been successfully called ? 
	*/
	bool IsSessionSetup();
	
	/*
	*Initialize P&O access methods used to interact with the server. 
	*/
	HRESULT InitAccessMethods();
	
	static HRESULT GetManager(DSYSettingSessionManager *& opSessionMan);
	
	static DSYSettingSessionManager * _pSingleton;
	
	HRESULT InitCache(CATUnicodeString * pFullCacheDir=NULL);

	HRESULT Clear();

	char GetCurrentMode();

	CATUnicodeString GetCurrentEnvName();

	HRESULT AddSaveAfterlogon(CATUnicodeString & iSettingName);

	bool CanBeReloaded(CATUnicodeString & iSettingName);
	
	HRESULT ReservePrefrences(CATUnicodeString & iPath);
	
	HRESULT ImportPrefrences(CATUnicodeString & iPath);
	
	CATListOfCATUnicodeString _saveAfterLogon;
	
private:

	/*
	* Input params : 
	*oEnvSwitch : Has settings path changed during setup ?
	*Internal version of the offline setup method 
	*/
	HRESULT SetupOffline(CATSettingEnv *&  pioUserEnv,CATSettingEnv *& pioAdminEnv,bool & oEnvSwitch);
	
	HRESULT UpdateSettingFile(CATUnicodeString & iTarget, CATUnicodeString & iOrigin, UpdateMode iMode );
	
	
	
	CATListOfCATUnicodeString _settingToBeCRCCompared;
	
	
	
	DSYSettingSaveLevel _SaveLevel;
	bool _refreshState;
	bool _setupState;
	
protected:

	char _Mode;
	DSYSettingsCache * _pCacheManager;
	CATUnicodeString _envName;
	CATListOfCATUnicodeString _remoteParentsList;
	CATListOfCATUnicodeString _localParentsList;
	CATListOfCATUnicodeString _noReloadSettings;
		
	//Pointers to remote access methods , see previous typedefs 
	InitSettingsEnvironment _InitEnv;
	GetParentUserSettingsEnvironmentNames _QueryParents;
	GetAllSettingsStreams _GetAllStreams;
	SetSettingsStreams _SetStream;
	SaveSettingsStreams _Save;
	CloseEnv _Clean;
	DeleteAllSettingsFunction _Delete;
	
};

#endif
