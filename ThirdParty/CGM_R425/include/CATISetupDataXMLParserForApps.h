#ifndef CATISetupDataXMLParserForApps_h
#define CATISetupDataXMLParserForApps_h

// COPYRIGHT Dassault Systemes 2015

// System framework
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATISetupDataXMLParserForApps;
#else
extern "C" const IID IID_CATISetupDataXMLParserForApps;
#endif

class CATIContainer_var;
class CATIKweAppResourcesTable_var;

/**
* Interface used to parse the XML declaration files used 
* for the Setup Data Management.
* This interface can be used to build a resources table skeleton from
* the corresponding XML declaration file present in the runtime view
* subdirectory $OS/resources/knowledge/AppResourceSetDescriptions
* @see CATIKweAppResourcesTable
*/
class ExportedByCATLifSpecs CATISetupDataXMLParserForApps : public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	* Creates a new resources table from the a set of XML declaration files under a specific 
	* directory.  Each XML declaration file can only declare a single setup data usage, and must 
	* be compliant with the AppResourceSetDescription.xsd schema description file.
	* @param iAppResourceSetDir
	*   The directory name under which a set of XML declaration files are located.
	*   <b>NOTE:</b> under this direcotry, there must exist a xml file (called iAppResourceSetDir.xml 
	*   corresponding to the given iAppResourceSetDir string). This xml file is used
	*   to define the AppResourceSetID to which all setup data items will belong
	*   Example,
	*   $OS/resources/knowledge/AppResourceSetDescriptions/iAppResourceSetDir/
	*        |--- iAppResourceSetDir.xml  (must)
	*        |--- <setupDataItem_1>.xml
	*        |--- <setupDataItem_2>.xml
	*        |---  ...
	*        |--- <setupDataItem_n>.xml
	*    
	* @param iContainer
	*   Container in which the table will be created
	* @param oTable
	*  Created resources table
	* @return
	*   S_OK if successful, E_FAIL otherwise
	*   This method can fail for several different reasons :
	*      - the XML declaration file <iAppResourceSetDir>.xml does not exist or not compliant with the .xsd
	*      - any setup data declaration file under .../iAppResourceSetDir is not compliant with the .xsd
	*   Use CATError::CATGetLastError() to retrieve the error description.
	*/
	virtual HRESULT CreateResourcesTableFromDir(
		const CATUnicodeString &iAppResourceSetDir,
		const CATIContainer_var& iContainer,
		CATIKweAppResourcesTable_var& oTable) = 0;

	/**
	* Updates an existing resources table from a set of XML declaration files under a specific 
	* directory.
	* @param iAppResourceSetDir
	*   The directory name under which a set of XML declaration files are located.
	* @param ioTable
	*  Existing resources table
	* @parma oUpgradeReport
	*   oUpgradeReport contains the description of the modifications taken into account during the upgrade. 
	* @param iRemoveObsoleteItems
	*   Specify whether the obsolete items must be removed or not during the upgrade.
	* @return
	*   S_OK if successful, E_FAIL otherwise
	*/
	virtual HRESULT UpgradeTableFromDir(
		const CATUnicodeString &iAppResourceSetDir,
		CATIKweAppResourcesTable_var& ioTable,
		CATUnicodeString& oUpgradeReport,
		CATBoolean iRemoveObsoleteItems) = 0;

};

CATDeclareHandler(CATISetupDataXMLParserForApps, CATBaseUnknown);

#endif // CATISetupDataXMLParserForApps_h

