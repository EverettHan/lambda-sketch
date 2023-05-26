#ifndef CATIKweAppResourcesTable_h
#define CATIKweAppResourcesTable_h

// COPYRIGHT Dassault Systemes 2007

// System framework
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"
#include "CATIKweAppResourceItem.h"
#include "CATIKweAppResourcesTableFinder.h"
#include "CATListOfCATIKweAppResourceItem.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIKweAppResourcesTable;
#else
extern "C" const IID IID_CATIKweAppResourcesTable;
#endif

/**
 * Interface used to read the contents of an Application Resources Table.
 * A table, identified by a name, represents a list of pointed PLM application 
 * resource items. Each resource item can be located in the table from its logical name, 
 * which must be unique inside the table. 
 *
 * @see CATIKweAppResourceItem
 * @see CatKweAppRscItemType.h for the list of possible resource item types.
 */
class ExportedByCATLifSpecs CATIKweAppResourcesTable : public CATBaseUnknown
{
	CATDeclareInterface;
	
  public:
	
	  /**
	   * Returns the identifier of the table.
	   */
	  virtual CATUnicodeString GetId() = 0;

	  /**
	   * Returns the name of the table.
	   */
	  virtual CATUnicodeString GetName() = 0;

	  /**
	   * Returns the table description.
	   */
	  virtual CATUnicodeString GetDescription() = 0;

	  /**
	   * Returns the count of stored Application Resource Items in the table.
	   */
	  virtual int ItemsCount() = 0;

	  /**
	   * Returns the Application Resource Item stored at the given index in the table.
	   * Note that the first item has an index equal to 1.
	   * @param iIndex
	   *   The given index of the resource item to retrieve
	   */
	  virtual CATIKweAppResourceItem_var GetItem(int iIndex) = 0;

	  /**
	   * Retrieves all the resource items stored in the table.
	   * @param oResourcesList
	   *   The list of retrieved resource items
	   * @return
	   *   S_OK if successful, E_FAIL otherwise
	   */
	  virtual HRESULT GetAllResourcesItems(CATListOfCATIKweAppResourceItem& oResourcesItemsList) = 0;

	  /**
	   * Returns the finder associated to this Applications Resources Table.
	   */
	  virtual CATIKweAppResourcesTableFinder_var GetTableFinder() = 0;

	  /**
	   * Returns the name of the given resource item type.
	   * @param iType
	   *   The given resource item type.
	   */
	  virtual CATUnicodeString GetTypeName(CatKweAppRscItemType iType) = 0;

};

CATDeclareHandler(CATIKweAppResourcesTable, CATBaseUnknown);

#endif // CATIKweAppResourcesTable_h

