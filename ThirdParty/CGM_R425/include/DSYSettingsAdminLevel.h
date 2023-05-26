


#ifndef _DSYSettingsAdminLevel_H_
#define _DSYSettingsAdminLevel_H_

#include "JS0SETT.h"

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATSysTSUnicodeString.h"

#define INITIAL_CHILDREN_NUMBER 10


enum DSYSettingAdminLevelType { ORGANISATION = 1, PROJECT = 2};

class ExportedByJS0SETT DSYSettingsAdminLevel : public CATBaseUnknown {
	
	CATDeclareClass;
	
	public:
	
	/*
    * @deprecated R417.
	* Constructor.
	* iType: type of the P&O object the settings level is attached to 
	*
	*/	
	DSYSettingsAdminLevel(DSYSettingAdminLevelType iType,CATSysTSUnicodeString iName,
							int initial_max_nbc  = INITIAL_CHILDREN_NUMBER);
	/*
	* Constructor.
	* iType: type of the P&O object the settings level is attached to 
	*
	*/	
	DSYSettingsAdminLevel(DSYSettingAdminLevelType iType,char * iName,
							int initial_max_nbc  = INITIAL_CHILDREN_NUMBER);
							
	/*
	* Constructor.
	* iType: type of the P&O object the settings level is attached to 
	*
	*/	
	DSYSettingsAdminLevel(DSYSettingAdminLevelType iType,CATUnicodeString  iName,
							int initial_max_nbc  = INITIAL_CHILDREN_NUMBER );
	
	
	~DSYSettingsAdminLevel();
	
	/*
	* Add a child to the settings level. No limit in children number. Name unicity is enforced.
	* Fails if child is already attached.
	*/	
	HRESULT AddChild(DSYSettingsAdminLevel * iLevel);
	
	/*
	*
	* 
	*/	
	CATUnicodeString getName();
	
	/*
	*
	*   Fills oChildren with an array of pointers to the children of the current level.
	*   Children are ordered the way they were added.
	* 	oChildren is allocated inside the method and must be freed after use with a delete [] oChildren;
	*/	
	int GetChildren(DSYSettingsAdminLevel ** & oChildren);
	
	
	bool IsRefreshed();
	
	void setRefreshed(bool iRefreshedFlag);
	
	
	/*
	* Delete the iRootNode passed to the method and all its children 
	* The pointer is also set to NULL.
	*/	
	static void DeleteTree(DSYSettingsAdminLevel *& iRootNode, bool iTreeClean = true);
	
	
	/*
	*  Search for given settings level based on its name. Search is case sensitive. It is performed downward starting from 
	* the provided level. The first level matching the provided name is returned.
	* return vale:
	*	S_OK : when the level is found 
	*	S_FALSE : when no level matching the provided name is found.
	*/	
	static HRESULT SearchByName(DSYSettingsAdminLevel * startNode,CATUnicodeString & iNameToSearchFor,DSYSettingsAdminLevel *& oFound);
	
	
	/*
	*  Builds a path going upward from the provided ipLowestPathLevel of the unrefreshed administration levels.
	*  Path building stops at the first refreshed administration level which is not included in the returned array.
	*  oPathLength is the number of levels included in tha path
	*  This method allows selective refreshing of a settings administration subtree.
	*/
	static HRESULT GetPathToUpdate(DSYSettingsAdminLevel * ipLowestPathLevel, DSYSettingsAdminLevel ** & oLevelsPath, int &oPathLength);

	static void FreeLevelsTab(DSYSettingsAdminLevel **& lvTab, int iLvlNb);
	
	bool HasChild(CATUnicodeString iName);
	
	int GetChildrenNb();
	
	DSYSettingsAdminLevel * GetFather();
	
	HRESULT GetParents(CATListOfCATUnicodeString &  iParentsList);
	
	private:
		
	static void RemoveChild(DSYSettingsAdminLevel * iNode);

	bool _refreshed;
	DSYSettingsAdminLevel * _father;
	DSYSettingsAdminLevel ** _children;
	int nb_children;
	int max_nb_children;
	int _index;
	CATUC2Bytes * _name;
	DSYSettingAdminLevelType _type;
	
};

//CATDeclareHandler (DSYSettingsAdminLevel, CATBaseUnknown);

#endif

