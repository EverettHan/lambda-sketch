#ifndef __CATIAfrCustomize_h
#define __CATIAfrCustomize_h

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "CATLISTP_CATBaseUnknown.h"
#include "CATString.h"

class CATDlgSelectorList;
class CATCommand;
class CATCommandHeader;
class CATCmdAccess;
class CATIScriptContainer;
class CATCmdContainer;
class CATCmdStarter;
class CATCmdWorkshop;
class CATCmdWorkbench;

typedef unsigned long CATULong;

extern ExportedByCATAfrItf IID IID_CATIAfrCustomize;


/**
 * @nodoc
 * Interface between AfrFoundation and AfrCustomization frameworks.
 * See implementation in AfrCustomization framework.
 * These methods are redirected to the same methods of CATDndCustomize class.
 */
class ExportedByCATAfrItf CATIAfrCustomize : public CATBaseUnknown
{
	
  CATDeclareInterface;
  
public:

  /** @nodoc */
  virtual CATCommand * GetCustomizeCommand() = 0;

  /** @nodoc */
  virtual void UpdateAcceleratorEditor(CATCommandHeader *ipHdr, CATULong iUL) = 0;

  /** @nodoc */
  virtual void EnableAcceleratorEditor () = 0;

  /** @nodoc */
  virtual CATDlgSelectorList * GetCommandsList() = 0;

  /** @nodoc */
  virtual void ButtonSelected (CATCommandHeader & iHdr, CATCmdAccess & iAcc) = 0;

  /** @nodoc */
  virtual void UpdatePages () = 0;

  /** @nodoc */
  virtual void SaveCustomization (CATCmdAccess * access) = 0;

  /** @nodoc */
  virtual void DelSavedCustomization (CATCmdAccess * access) = 0;

  /** @nodoc
   * Gets the name of the macros contained in the supplied container.
   */
  virtual HRESULT GetMacroNames(CATIScriptContainer* iContainer, CATListOfCATUnicodeString & oList) = 0;

  /** @nodoc
   * Tests if a macro exists in the current macro container.
   * targetPath is the path of the macro
   * RecomputeContainer is TRUE if we have to look for the current container and retrieve the macros from it;
   *                    is FALSE if we have to look into the same container as we looked in the last time we were called.
   * Returns S_OK if the macro was found, E_FAIL if the macro was not found.
   */
  virtual HRESULT CheckIfMacroExist(const CATUnicodeString & targetPath, const CATBoolean RecomputeContainer) = 0;



	//====================================================================
	//Method added by isp for Action bar customization (R215 delivery).
	//====================================================================

	//Generic method to add a section in the existing command container model.
	//This API make the model impact in the Global workshop and in the current workshop\workbench (if given).
	//Arguments : 
	//CATCmdContainer * iAddedGlobalSection : the input section, instantiated by the customer. It cannot be NULL. It is Set as the Global section.
	//It must not have any parent. It is added to the global worshop and if needed to the current workshop\workbench.
	//CATCmdContainer * & oCreatedWSWBSection : the section (clone of input section) created and added in workshop or workbench if one of them exists.
	//CATCmdContainer * iFollowingSection : the section which will follow the added section. It can be the Global or workshop\workbench section.
	//CATCmdWorkshop * iCurrentWorkshop : optional argument. If it is not NULL and iCurrentWorkbench is NULL, the Section is duplicated at the workshop.
	//CATCmdWorkbench * iCurrentWorkbench : optional argument. If it is not NULL, the section.
	//Return : 0 if the method ended successfully : section is added to the command container model.
	//				 1 if the command is not removed from the section.
	virtual int AddSection(CATCmdContainer * iAddedGlobalSection, CATCmdContainer * & oCreatedWSWBSection, CATCmdContainer * iFollowingSection, CATCmdWorkshop * iCurrentWorkshop, CATCmdWorkbench * iCurrentWorkbench) = 0;

	//Generic method to remove a section from the command container model.
	//Warning : only section added by the user can be removed!!!!!!!!!!!!!!!!!!!
	//Section is removed from the global workshop and also from the current workshop\workbench (if it exists).
	//Return : 0 if the method ended successfully : section is added to the command container model.
	//				 1 if the command is not removed from the section.
	//Warning : returned list oRemovedSections must have all its items released by the caller!!!!!
	virtual int RemoveSection(CATCmdContainer *& ioSectionToRemove, CATListPtrCATBaseUnknown & oRemovedSections) = 0;

	//Generic method to add a group in a given section.	
	//Group is added to the section in global workshop and also in the current workshop\workbench (if it exists).
	//Added group is a child of iFatherGroup(if it exists) and a previous brother of iFollowingGroup (if it exists)
	//if iFatherGroup is NULL : iGroupToAdd is added directly under the input section.
	//if iFollowingGroup is NULL : iGroupToAdd is added as last brother of the father group.
	//Return : 0 if the method ended successfully : group is added to input section.
	//				 1 if the group is not added to the section.
	virtual int AddGroup(CATCmdContainer * iSection, CATCmdContainer * iGroupToAdd, CATCmdContainer * iFatherGroup = NULL, CATCmdAccess * iFollowingAccess = NULL, float iweight = 1.0) = 0;

	//Generic method to Remvoe a group from a given section.	
	//Group is removed from the section in global workshop and also in the current workshop\workbench (if it exists).
	//Return : 0 if the method ended successfully : group is removed from the input section.
	//				 1 if the group is not removed of the section.
	virtual int RemoveGroup(CATCmdContainer * iSection, CATCmdContainer * iGroupToRemove) = 0;

	//Generic method to restore a section in the command container model.
	//Section is restored in the global workshop and also in the current workshop\workbench (if it exists).
	//To be restorable, a section have to have been set as a user section, and in some cases cloned and chained (case of WSWB custo or global custo for global section). No default section are restored by this method.
	//Return : 0 if the method ended successfully : section is restored successfully.
	//				 1 section not restored.
	//Warning : returned list oRemovedSections must have all its items released by the caller!!!!!
	virtual int RestoreSection(CATCmdContainer *& ioSectionToRestore, CATListPtrCATBaseUnknown & oRemovedSections) = 0;

	//Generic method to restore all sections in the command container model.
	//Section is restored in the global workshop and also in the current workshop\workbench (if it exists).
	//To be restorable, a section have to have been set as a user section, and in some cases cloned and chained (case of WSWB custo or global custo for global section). No default section are restored by this method.
	//Return : 0 if the method ended successfully : all sections are restored successfully.
	//				 1 section not restored.
	//Warning : returned list oRemovedSections must have all its items released by the caller!!!!!
	virtual int RestoreAllSections(CATListPtrCATBaseUnknown & oRemovedSections) = 0;

	//Generic method to rename a section.
	//Return : 0 if the method ended successfully : section is renamed as expected.
	//				 1 if the section is not renamed.
	virtual int RenameSection(CATCmdContainer * iSectionToReName, CATUnicodeString iNewSectionName) = 0;

	//Generic method to add a command (owned by iStarter) into a section.
	//CATCmdContainer * iSection : The section in which we add a new command.
	//CATString iCmd : aommand ID of the added command.
	//CATCmdContainer * iContainingContainer : the container (group) in which(optional) we will put created starter. If NULL and if iFollowingStarter is NULL, a new group is created (first time only).
	//CATCmdAccess * iFollowingAccess : Starter which will follow new created starter.
	//float iweight : the weight of added command. it represents the fact that a command is in primary or secondary area of the section.
	//CATString StarterName : Name of instantiated starter. (will be the same than iCmd if asked value is default ("")).
	//Return : 0 if the method ended successfully : command is added to the section.
	//				 1 if the command is not added to the section.
	virtual int AddCommand(CATCmdContainer * iSection, CATString iCmd, CATCmdContainer * iContainingContainer = NULL, CATCmdAccess * iFollowingAccess = NULL, float iweight = 1.0, CATString iStarterName = "") = 0;

	//Generic method to remove a command (owned by iStarter) into a section.
	//CATCmdContainer * iSection : Section in which we will remove a given starter.
	//CATCmdStarter * iStarter : the starter to remove. Warning : given starter is deleted by the method.	
	//Return : 0 if the method ended successfully : command is removed of the section.
	//				 1 if the command is not removed from the section.
	virtual int RemoveCommand(CATCmdContainer * iSection, CATCmdStarter * iStarter) = 0;

    //Generic method to remove lightweight accesses in a group.
    //Every CATCmdAccess with a weight < .5f will be removed from the group.
    //CATCmdContainer * iGroup: Group from which access needs to be removed.
    //Return: 0 if the method ended successfully,
    //		  1 otherwise.
    virtual int RemoveLightweightAccessInGroup(CATCmdContainer * iGroup) = 0;

	//Generic method to change a command priority (owned by iStarter) into a section.
	//CATCmdContainer * iSection : the section  owning the starter in which we want to change the priority.
	//CATCmdStarter * iStarter : the starter we want to change the priority.
	//float iweight : wished starter weight.
	//Return : 0 if the method ended successfully : Starter prriority has been changed.
	//				 1 if the starter priority is not changed.
	virtual int ChangePriority(CATCmdContainer * iSection, CATCmdStarter * iStarter, float iweight) = 0;	

	//Generic method to save Global Workshop preferences in the Settings files.
	//Return : 0 if the method ended successfully : Seetings file is updated with current Global workshop preferences.
	//		     1 Settings files are unchanged.
	virtual int SavePreferencesInSettingsFiles() = 0;

	//check if we try to add a local cmd to a global toolbar.
	virtual int CanAddCommand(CATString iCmd, CATCmdContainer * iSection) = 0;
};

CATDeclareHandler(CATIAfrCustomize,CATBaseUnknown);

#endif
