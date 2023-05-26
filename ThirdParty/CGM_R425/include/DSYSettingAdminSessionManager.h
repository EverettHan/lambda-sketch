



#ifndef _DSYSETTINGADMINSESSIONMANAGER_H_
#define _DSYSETTINGADMINSESSIONMANAGER_H_





#include "DSYSettingSessionManager.h"
#include "JS0SETT.h"
#include "DSYSettingsAdminLevel.h"

#define VIRTUAL_ROOT_LEVEL_NAME "My settings database"
#define PROJECT_TYPE 1
#define ORG_TYPE 2


typedef  HRESULT ( * GetRootResourceNodesFunction )(CATListOfCATUnicodeString & oEnvList,int iType );
typedef  HRESULT ( * ExpandChildrenFunction )(CATUnicodeString & iEnvName, CATListOfCATUnicodeString & oChildrenList );
typedef  HRESULT ( * CleanBagsFunction )();


class ExportedByJS0SETT  DSYSettingAdminSessionManager : public DSYSettingSessionManager
{

public:
	//----------------
	// Constructors 
	//----------------
	DSYSettingAdminSessionManager();
	//-----------
	//Destructor
	//------------
	virtual ~DSYSettingAdminSessionManager();
	
	/*
	*	Change current working environment to a provided target environment.
	*/
	HRESULT ChangeEnvironment(CATUnicodeString & iTargetEnvName );

	static HRESULT GetManager(DSYSettingSessionManager *& opSessionMan);
	
	HRESULT ExpandEnvironment(CATUnicodeString & iEnvName, CATListOfCATUnicodeString &oChildren,bool forceExpand);
	
	HRESULT ExpandEnvironment(CATUnicodeString  iEnvName = VIRTUAL_ROOT_LEVEL_NAME,int  iHowDeep = -1);	

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
	HRESULT SetupOnline(CATSettingEnv *&  pioUserEnv,CATSettingEnv *& pioAdminEnv, 
															char * iProviderName,DSYSettingReloadLevel & oReloadLevel);
	
	HRESULT RefreshReloadSettings();

	HRESULT GetTopEnvironment(DSYSettingsAdminLevel *& oTopEnv);

	HRESULT ImportAdminSettings(CATUnicodeString & iEnvFrom,CATUnicodeString & iEnvTo);

	/*
	* To be called at the end of all settings edition in admin mode before disconnection.
	*/
	HRESULT Clean();
	
private: 

	HRESULT InternalExpandAllEnvironments(CATUnicodeString  iEnvName,int & ioCounter, int iHowDeep);
	
	HRESULT InitAccessMethods();

	DSYSettingsAdminLevel * _pVirtualTreeRoot;
	
		
	GetRootResourceNodesFunction _GetRootEnvironments;
	ExpandChildrenFunction _ExpandChildren;
	CleanBagsFunction _CleanBags;

};



#endif





