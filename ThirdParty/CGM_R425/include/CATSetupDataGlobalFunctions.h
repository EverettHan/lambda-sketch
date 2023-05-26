#ifndef CATSetupDataGlobalFunctions_h
#define CATSetupDataGlobalFunctions_h

// COPYRIGHT Dassault Systemes 2007

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"
#include "CATISetupDataFinder.h"

class CATISetupDataGlobalFunctions_var;
class CATISetupDataXMLParser_var;
class CATISetupDataXMLParserForApps_var;

#include "CatKweAppRscItemType.h"

// System framework
#include "CATUnicodeString.h"

/**
* Class used to provide global services for the Set Up Data management.
* @see CATISetupDataFinder
*/
class ExportedByCATLifSpecs CATSetupDataGlobalFunctions
{
public:

	/**
	* Creates a new CATISetupDataFinder instance.
	* Note that the life cycle of the PLM resources loaded with the returned 
	* Setup Data Finder instance is linked to the life cycle of this finder.
	* With this method, the returned Setup Data Finder instance and PLM resources
	* loaded via this finder will be kept in the memory until the V5 session is deleted.
	* Use the methods GetSetupDataFinder(iFinderId) and RemoveSetupDataFinder(iFinderId)
	* instead of this method if you want to easily manage this life cycle.
	*/
	static CATISetupDataFinder_var GetSetupDataFinder();

	/**
	* Retrieves the CATISetupDataFinder instance whose identifier is equal to the given one.
	* If there is no existing CATISetupDataFinder instance with this identifer, 
	* this method creates a new one and keep it internally.
	* You must use the method RemoveSetupDataFinder with the same identifier to remove
	* this instance once you have finished with its corresponding loaded PLM resources.
	*/
	static CATISetupDataFinder_var GetSetupDataFinder(const CATUnicodeString& iFinderId);

	/**
	* Removes the CATISetupDataFinder instance whose identifier is equal to the given one.
	* This will remove all the resource tables managed by this Setup Data Finder instance,
	* and then all the PLM resources loaded from these tables.
	*/
	static HRESULT RemoveSetupDataFinder(const CATUnicodeString& iFinderId);

	/**
	* Returns the Knowledge Type corresponding to the given type.
	*/
	static HRESULT GetKnowledgeType(CatKweAppRscItemType iType, CATIType_var & oType);

	/**
	* Creates a new CATISetupDataXMLParser instance.
	*/
	static CATISetupDataXMLParser_var GetSetupDataXMLParser();

	/**
	* Creates a new CATISetupDataXMLParserforApps instance.
	*/
	static CATISetupDataXMLParserForApps_var GetSetupDataXMLParserForApps();

private:

	static CATISetupDataGlobalFunctions_var _GetSetupDataGlobalFunctions();
};

#endif // CATSetupDataGlobalFunctions_h
