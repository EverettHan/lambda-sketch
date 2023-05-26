#ifndef CATKnowledgeDirectoryServices_H
#define CATKnowledgeDirectoryServices_H

// COPYRIGHT DASSAULT SYSTEMES 2005

// Export Module 
#include "CATExpressionEngine.h"

#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"


class ExportedByCATExpressionEngine CATKnowledgeDirectoryServices : public CATBaseUnknown
{
public:
	
	
	// constructeurs  
	CATKnowledgeDirectoryServices();
	virtual ~CATKnowledgeDirectoryServices() ;

	/**
	* Get the content  of the CATKnowledgeBuildPath setting.
	* This content may be a single directory path or the empty string.
	* In pratice, this setting :
	*
	* - is valuated by the architect during the building stage of an application. It 
	*   gives the path of the Build part of the Runtime view, that is the path of 
	*   the Knowledge directory located in the CNext directory of the corresponding 
	*   framework. Then it allows the architect to create/modify knowledges resources 
	*   directly in the Build part (in order to get those resources managed by SCM) 
	*   without having to close the CATIA session and to run mkrtv to get those 
	*   creations/modifications immediately taken in  account.
	*	#################################################################################
	*	WARNING : 
	*   When you valuate CATKnowledgeBuildPath manually, make sure that the pointed
	*   directory respects the following hierarchy :
	*			XXXXX (directory pointed instead of the Knowledge one)
	*			  |_ knowledgeResources
	*			  |_ knowledgeResourcesCatalogs
	*			  |_ knowledgeTypesCustom
	*			  |_ knowledgeTypesDS
	*   because the resources are looked for in their "own directory". For instance : if you
	*   put a catalog directly under the XXXXX directory and you want to find a resource in it
	*   using ARM (see CATIApplicationResourcesManager), this catalog won't be instrospected.
	*   Indeed, the catalog will be searched in the path retrieved by 
	*   GetListOfKnowledgeResourcesCatalogsPathes(), that is XXXXX\knowledgeResourcesCatalogs,
	*   and will not be found.
	*   ##################################################################################
	*
	* - is empty and locked when the application is deployed.
	*
	* @param oCATKnowledgeBuildPath
	* The content of the CATKnowledgeBuildPath setting.
	* @param iCreateIfNotExist
	* Set it to 1 if you want the corresponding XXXXX directory (usually a "knowledge" one) and its structure to
	* be automatically created if they do not exist. Default value is 0, so that the returned path may point 
	* to a not existing directory.
	* @return
	* - S_OK if the content of the of the CATKnowledgeBuildPath setting have been read and the corresponding
	* struture of directories have been correctly created (if iCreateIfNotExist == 1).
	* - E_FAIL else (CATKnowledgeBuildPath setting is empty or can not be read or the corresponding
	* struture of directories can not be created).
	*/
	static HRESULT GetContentOfCATKnowledgeBuildPathSetting(CATUnicodeString & oCATKnowledgeBuildPath, int iCreateIfNotExist = 0);
//	static HRESULT GetContentOfCATKnowledgeBuildPath(CATUnicodeString & oCATKnowledgeBuildPath, int iCreateIfNotExist = 0);

	/**
	* Get the content  of the CATKnowledgePath environment variable.
	* By default, its gives the concatenation of the pathes to access to the "Knowledge"
	* directories of the CATInstallPath (in the Runtime view).
	* #################################################################################
	* WARNING : 
	* - if you valuate CATKnowledgePath manually, make sure that the pointed
	*   directory(ies) respect(s) the following hierarchy :
	*			XXXXX (directory pointed instead of the Knowledge one)
	*			  |_ knowledgeResources
	*			  |_ knowledgeResourcesCatalogs
	*			  |_ knowledgeTypesCustom
	*			  |_ knowledgeTypesDS
	*   because the resources are looked for in their "own directory". For instance : if you
	*   put a catalog directly under the XXXXX directory and you want to find a resource in it
	*   using ARM (see CATIApplicationResourcesManager), this catalog won't be instrospected.
	*   Indeed, the catalog will be searched in the path retrieved by 
	*   GetListOfKnowledgeResourcesCatalogsPathes(), that is XXXXX\knowledgeResourcesCatalogs,
	*   and will not be found.
	*
	* #################################################################################
	* @param oCATKnowledgePath
	* The content of the CATKnowledgePath variable.
	* @return
	* - S_OK if the content of the CATKnowledgePath environment variable have been read.
	* - E_FAIL else (CATKnowledgePath is empty or can not be read).
	*/
	static HRESULT GetContentOfCATKnowledgePathVariable(CATUnicodeString & oCATKnowledgePath);


	/**
	* Get the content  of the CATKnowledgePath environment variable.
	* By default, its gives a list of the pathes to access to the "Knowledge"
	* directories of the CATKnowledgePath (in the Runtime view).
	* #################################################################################
	* WARNING : 
	* - Make sure that the pointed directory(ies) respect(s) the following hierarchy :
	*			XXXXX (directory pointed instead of the Knowledge one)
	*			  |_ knowledgeResources
	*			  |_ knowledgeResourcesCatalogs
	*			  |_ knowledgeTypesCustom
	*			  |_ knowledgeTypesDS
	*   because the resources are looked for in their "own directory". For instance : if you
	*   put a catalog directly under the XXXXX directory and you want to find a resource in it
	*   using ARM (see CATIApplicationResourcesManager), this catalog won't be instrospected.
	*   Indeed, the catalog will be searched in the path retrieved by 
	*   GetListOfKnowledgeResourcesCatalogsPathes(), that is XXXXX\knowledgeResourcesCatalogs,
	*   and will not be found.
	*
	* #################################################################################
	* @param oListOfCATKnowledgePathes
	* The content of the CATKnowledgePath variable (list of the pathes).
	* @param iKeepOnlyExistingDirInReturnedList
	* Set it to 1 if you want to keep in the returned list, only the existing directories.
	* Default value is 0, so that the returned list may contain pathes pointing not existing directories.
	* @param iCreateIfNotExist
	* Set it to 1 if you want the corresponding XXXXX directory (usually a "knowledge" one) and its structure to
	* be automatically created if they do not exist. Default value is 0, so that the returned path may point 
	* to a not existing directory.
	* @return
	* - S_OK if the content of the CATKnowledgePath environment variable have been read.
	* - E_FAIL else (CATKnowledgePath is empty or can not be read).
	*/
	static HRESULT GetContentOfCATKnowledgePathVariable(CATListOfCATUnicodeString& oListOfCATKnowledgePathes, 
														int iKeepOnlyExistingDirInReturnedList = 0, 
														int iCreateIfNotExist = 0);


	/**
	* Gets the concatenation of all Knowledge pathes (CATKnowledgeBuildPath + CATKnowledgePath).
	* @return
	* if succeeded it returns a string containing the concatenation, and "" else.
	*/
	static HRESULT GetConcatenationOfKnowledgePathes(	CATUnicodeString & oConcatenation);

	/**
	* Gets the list of the Knowledge directories pathes found in the concatenation of Knowledge pathes.
	* It parses the string returned by GetConcatenationOfKnowledgePathes() to retrieve each path
	* one by one, and to return them in the output list.
	* See also WARNING in the GetContentOfCATKnowledgePathVariable() description.
	* @param ioListOfKowledgePathes
	* list of the Knowledge directories found in the knowledge concatenation.
	* Notice that ioListOfKnowledgePathes[i] is the ith Knowledge path of the concatenation.
	* @param iKeepOnlyExistingDirInReturnedList
	* Set it to 1 if you want to keep in the returned list, only the existing directories.
	* Default value is 0, so that the returned list may contain pathes pointing not existing directories.
	* @param iCreateIfNotExist
	* Set it to 1 if you want the corresponding XXXXX directory (usually a "knowledge" one) and its structure to
	* be automatically created if they do not exist. Default value is 0, so that the returned path may point 
	* to a not existing directory.
	* @return
	* - S_FALSE if iKeepOnlyExistingDirInReturnedList = 0 whereas not existing directories pathes are returned in the list.
	* - S_OK if the returned list contains only existing directories pathes
	* - E_FAIL else (Knowledge concatenation is empty, so that output list is empty).
	*/
	static HRESULT GetListOfKnowledgePathes(CATListOfCATUnicodeString& ioListOfKnowledgePathes, 
											int iKeepOnlyExistingDirInReturnedList = 0, 
											int iCreateIfNotExist = 0);

	/**
	* Gets the list of the KnowledgeResources directories pathes.
	* They are subdirectories of the Knowledge directories found in the concatenation of Knowledge pathes.
	* See also WARNING in the GetContentOfCATKnowledgePathVariable() description.
	* @param ioListOfKnowledgeResourcesPathes
	* List of the KnowledgeResources directories
	* @param iKeepOnlyExistingDirInReturnedList
	* Set it to 1 if you want to keep in the returned list, only the existing directories.
	* Default value is 0, so that the returned list may contain pathes pointing not existing directories.
	* @param iCreateIfNotExist
	* Set it to 1 if you want the corresponding XXXXX directory (usually a "knowledge" one) and its structure to
	* be automatically created if they do not exist. Default value is 0, so that the returned path may point 
	* to a not existing directory.
	* @return
	* - S_FALSE if iKeepOnlyExistingDirInReturnedList = 0 whereas not existing directories pathes are returned in the list.
	* - S_OK if the returned list contains only existing directories pathes
	* - E_FAIL else (Knowledge concatenation is empty, so that output list is empty).
	*/
	static HRESULT GetListOfKnowledgeResourcesPathes(CATListOfCATUnicodeString& ioListOfKnowledgeResourcesPathes, int iKeepOnlyExistingDirInReturnedList = 0);
	
	/**
	* Gets the list of the KnowledgeResourcesCatalogs directories pathes.
	* They are subdirectories of the Knowledge directories found in the concatenation of Knowledge pathes.
	* See also WARNING in the GetContentOfCATKnowledgePathVariable() description.
	* @param ioListOfKnowledgeResourcesCatalogsPathes
	* List of the KnowledgeResourcesCatalogs directories
	* @param iKeepOnlyExistingDirInReturnedList
	* Set it to 1 if you want to keep in the returned list, only the existing directories.
	* Default value is 0, so that the returned list may contain pathes pointing not existing directories.
	* @return
	* - S_FALSE if iKeepOnlyExistingDirInReturnedList = 0 whereas not existing directories pathes are returned in the list.
	* - S_OK if the returned list contains only existing directories pathes
	* - E_FAIL else (Knowledge concatenation is empty, so that output list is empty).
	*/
	static HRESULT GetListOfKnowledgeResourcesCatalogsPathes(CATListOfCATUnicodeString& ioListOfKnowledgeResourcesCatalogsPathes, int iKeepOnlyExistingDirInReturnedList = 0);

	/**
	* Gets the list of the KnowledgeTypesCustom directories pathes.
	* They are subdirectories of the Knowledge directories found in the concatenation of Knowledge pathes.
	* See also WARNING in the GetContentOfCATKnowledgePathVariable() description.
	* @param ioListOfKnowledgeResourcesTypesCustomPathes
	* List of the KnowledgeTypesCustom directories
	* @param iKeepOnlyExistingDirInReturnedList
	* Set it to 1 if you want to keep in the returned list, only the existing directories.
	* Default value is 0, so that the returned list may contain pathes pointing not existing directories.
	* @return
	* - S_FALSE if iKeepOnlyExistingDirInReturnedList = 0 whereas not existing directories pathes are returned in the list.
	* - S_OK if the returned list contains only existing directories pathes
	* - E_FAIL else (Knowledge concatenation is empty, so that output list is empty).
	*/
	static HRESULT GetListOfKnowledgeTypesCustomPathes(CATListOfCATUnicodeString& ioListOfKnowledgeTypesCustomPathes, int iKeepOnlyExistingDirInReturnedList = 0);

	/**
	* Gets the list of the KnowledgeTypesDS directories pathes.
	* They are subdirectories of the Knowledge directories found in the concatenation of Knowledge pathes.
	* See also WARNING in the GetContentOfCATKnowledgePathVariable() description.
	* @param ioListOfKnowledgeTypesDSPathes
	* List of the KnowledgeTypesDS directories
	* @param iKeepOnlyExistingDirInReturnedList
	* Set it to 1 if you want to keep in the returned list, only the existing directories.
	* Default value is 0, so that the returned list may contain pathes pointing not existing directories.
	* @return
	* - S_FALSE if iKeepOnlyExistingDirInReturnedList = 0 whereas not existing directories pathes are returned in the list.
	* - S_OK if the returned list contains only existing directories pathes
	* - E_FAIL else (Knowledge concatenation is empty, so that output list is empty).
	*/
	static HRESULT GetListOfKnowledgeTypesDSPathes(CATListOfCATUnicodeString& ioListOfKnowledgeTypesDSPathes, int iKeepOnlyExistingDirInReturnedList = 0);


	/**
	* Service to create the knowledge filetree in the first path of the concatenation of CATKnowledgePath environment variable.
	* If this fisrt path does exist in the file system, this service will create the whole structure ("knowledge" and every necessary subdirectories)
	* If this first path exists, following the value of the iCreateOnlyWorkbenchDir argument, the service will create:
	* 1/ only the workbench subdirectory (used for the deployed workbenches
	* 2/ the whole structure
	* @param iCreateOnlyWorkbenchDir
	* Set to FALSE if you want to create the whole knowledge file tree under the first path concatenate in the CATKnoledgePath environment variable
	* Default is TRUE, so that only the workbench directory will be created
	*/
	static HRESULT CreateKnowledgeTreeifNecessary(CATBoolean iCreateOnlyWorkbenchDir = TRUE);


	static CATUnicodeString GetSlash(){return _slash;};
	static CATUnicodeString GetSeparator(){return _separator;};
	
private:

	/**
	* @return 
	* S_FALSE if the iConcatenation is empty, E_FAIL if the iConcatenation begins or ends with a 
	* separator (";" on Windows and ":" on Unix), and S_OK else.
	*/
	static HRESULT ParseConcatenation(const CATUnicodeString& iConcatenation, CATListOfCATUnicodeString& ioListOfPathes);
	CATKnowledgeDirectoryServices(const CATKnowledgeDirectoryServices&);

	static CATUnicodeString _separator;
	static CATUnicodeString _slash ;
	static CATUnicodeString _knowledgeResourcesDir;
	static CATUnicodeString _knowledgeResourcesCatalogsDir;
	static CATUnicodeString _knowledgeTypesCustomDir;
	static CATUnicodeString _knowledgeTypesDSDir;

	static CATUnicodeString _errorsCatalogName;

};

#endif
