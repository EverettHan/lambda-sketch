#ifndef CATIKweAppResourceItem_h
#define CATIKweAppResourceItem_h

// COPYRIGHT Dassault Systemes 2007

// System framework
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"
#include "CatKweAppRscItemType.h"
#include "CATListOfCATIKweAppResourceCriterion.h"
#include "CATIKweAppResourceSubItem.h"
#include "CATListOfCATIKweAppResourceSubItem.h"
#include "CATListOfCATIValue.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIKweAppResourceItem;
#else
extern "C" const IID IID_CATIKweAppResourceItem;
#endif

class CATIKweAppResourceCriterion_var;
class CATIKweAppResourcesTable_var;
class CATIInstance_var;

/**
 * Interface used to represent an item in an Application Resources Table and identified
 * by a logical name.
 * A resource item can also handle a list of additional criteria in order to support multiple 
 * pointed resources per logical name. These criteria will be specifics to each application. 
 * Each CATIKweAppResourceItem contains at least one sub item represented by the interface 
 * CATIKweAppResourceSubItem.
 * The resource item makes the link between a logical name (and optional  criteria values) 
 * and the corresponding pointed physical PLM resource.
 * Use criteria values to distinguish the different sub items of a same resource item.
 *
 * @see CATIKweAppResourcesTable
 * @see CATIKweAppResourceCriterion
 * @see CatKweAppRscItemType.h for the list of possible resource item types.
 * @see CATIKweAppResourceSubItem
 */
class ExportedByCATLifSpecs CATIKweAppResourceItem : public CATBaseUnknown
{
	CATDeclareInterface;
	
  public:
	
	  /**
	   * Returns the resource item logical name.
	   * This logical name represents the resource identifier ; the value must then
	   * be unique in a resource table since it will be used later to find the corresponding 
	   * resource in the table.
	   */
	  virtual CATUnicodeString GetLogicalName() = 0;

	  /**
	   * Returns the resource item alias.
	   * If no alias has been defined (either through the NLS Messages Catalogs or through
	   * the method CATIKweAppResourceItemEdit::SetAlias()), then the logical name is returned.
	   */
	  virtual CATUnicodeString GetAlias() = 0;

	  /**
	   * Returns the resource item type.
	   * Note that this type can be used as a search criterium.
	   */
	  virtual CatKweAppRscItemType GetType() = 0;

	  /**
	   * Returns the name of the resource item type.
	   */
	  virtual CATUnicodeString GetTypeName() = 0;

	  /**
	   * Returns TRUE if the resource item must necessarily have an assigned resource,
	   * FALSE otherwise.
	   */
	  virtual CATBoolean IsMandatory() = 0;

	  /**
	   * Returns TRUE if the item supports multiple sub items, FALSE otherwise.
	   * If the item uses a list of criteria, an item can have multiple sub items.
	   */
	  virtual CATBoolean SupportsMultipleResources() = 0;

	  /**
	   * Returns TRUE if the item contains criteria, FALSE otherwise.
	   */
	  virtual CATBoolean HasCriteria() = 0;

	  /**
	   * Returns the list of criteria used to distinguish resources sub items.
	   * Note that this list can be empty ; in such case, there can be only one resource
	   * for this item.
	   */
	  virtual HRESULT GetCriteria(CATListOfCATIKweAppResourceCriterion& oCriteria) = 0;

	  /**
	   * Retrieve the criterion corresponding to the given name if it exists.
	   * @param iCriterionName
	   *   The name of the criterion to retrieve
	   * @param oCriterion
	   *   The retrieved criterion if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a criterion has been found with the given name,
	   *   E_FAIL otherwise
	   */
	  virtual HRESULT GetCriterion(
		  const CATUnicodeString& iCriterionName,
		  CATIKweAppResourceCriterion_var& oCriterion) = 0;

	  /**
	   * Returns the comment describing the usage of the resource item.
	   * Note that this description is not used as a search criterium.
	   */
	  virtual CATUnicodeString GetDescription() = 0;

	  /**
	   * Returns the count of Sub Items corresponding to the current resource item.
	   */
	  virtual int SubItemsCount() = 0;

	  /**
	   * Returns the Resource Sub Item stored at the given index in 
	   * the current resource item.
	   * Note that the first sub item has an index equal to 1.
	   * @param iIndex
	   *   The given index of the resource sub item to retrieve
	   */
	  virtual CATIKweAppResourceSubItem_var GetSubItem(int iIndex) = 0;

	  /**
	  * Retrieves all the resource sub items stored in the current resource item.
	  * @param oSubItemsList
	  *   The list of retrieved resource sub items
	  * @return
	  *   S_OK if successful, E_FAIL otherwise
	  */
	  virtual HRESULT GetAllSubItems(CATListOfCATIKweAppResourceSubItem& oSubItemsList) = 0;

	  /**
	   * Retrieves the first resource sub item that is matching the given criteria.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the resource item to retrieve.
	   *   This list of criteria values must correspond to existing item criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindMatchingResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oResourceSubItem
	   *   The retrieved resource sub item if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a resource item has been found with the given logical name,
	   *   E_FAIL otherwise
	   */
	  virtual HRESULT FindResource(
		  const CATIInstance_var& iCriteriaValues,
		  CATIKweAppResourceSubItem_var& oResourceSubItem) = 0;

	  /**
	   * Retrieves all the resource sub items matching the given criteria values.
	   * @param iIsResourceSet
	   *   Specifies whether the retrieved resources items must have a pointed resource set or not.
	   *   Legal values :
	   *     -1 : parameter ignored
	   *     0  : the retrieved resources items have no pointed resource set
	   *     1  : the retrieved resources items have a pointed resource set
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the resource items to retrieve.
	   *   This list of criteria values must correspond to existing item criteria.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oResourcesList
	   *   The list of retrieved resource sub items
	   * @return
	   *   S_OK if at least one resource item has been found with the given logical pattern name and type,
	   *   E_FAIL otherwise
	   */
	  virtual HRESULT FindMatchingResources(
		  int iIsResourceSet,
		  const CATIInstance_var& iCriteriaValues,
		  CATListOfCATIKweAppResourceSubItem& oResourcesList) = 0;

	  /**
	   * Returns the name of the first resource sub item.
	   * This name is automatically set according to the pointed resource and can not be changed.
	   * Note that this name is only used for display, not for a resource search.
	   * If the current item contains several sub items, use the method 
	   * CATIKweAppResourceSubItem::GetName() instead.
	   */
	  virtual CATUnicodeString GetName() = 0;

	  /**
	   * Returns the display name of the first resource sub item.
	   * The display name consists in the resource name and 
	   * optionally the containing PLM component name.
	   * If the current item contains several sub items, use the method 
	   * CATIKweAppResourceSubItem::GetDisplayName() instead.
	   */
	  virtual CATUnicodeString GetDisplayName() = 0;

	  /**
	   * Returns the pointed resource of the first resource sub item.
	   * If the current item contains several sub items, use the method 
	   * CATIKweAppResourceSubItem::GetResource() instead.
	   */
	  virtual CATBaseUnknown_var GetResource() = 0;

	  /**
	   * Returns TRUE if at least one of the sub items has 
	   * its pointed resource set, FALSE otherwise.
	   */
	  virtual CATBoolean HasResourceSet() = 0;

	  /**
	   * Returns TRUE if at least one of the sub items has 
	   * its pointed resource unset, FALSE otherwise.
	   */
	  virtual CATBoolean HasResourceUnset() = 0;

	  /**
	   * Retrieves the possible values held by the sub items for the 
	   * specified criterion name (and optional other criteria values used 
	   * to filter the sub items).
	   * @param iCriterionName
	   *   The name of the criterion for whom the possible values must be retrieved.
	   * @param iOtherCriteriaValues
	   *   The optional other criteria values used to filter the resource sub items
	   *   in which this method must look for.
	   *   Pass NULL_var if there is no other criteria to use.
	   * @param oValues
	   *   The retrieved possible values if successful, NULL_var otherwise
	   * @return
	   *   S_OK if the values have been correctly retrieved, E_FAIL otherwise
	   */
	  virtual HRESULT GetPossibleCriterionValues(
		  const CATUnicodeString& iCriterionName,
		  const CATIInstance_var& iOtherCriteriaValues,
		  CATListOfCATIValue& oValues) = 0;

	  /**
	   * Retrieves the table that contains the current resource item.
	   * @param oTable
	   *   The retrieved containing table if successful, NULL_var otherwise
	   * @return
	   *   S_OK if the containing table has been correctly retrieved, E_FAIL otherwise
	   */
	  virtual HRESULT GetContainingTable(CATIKweAppResourcesTable_var& oTable) = 0;

};

CATDeclareHandler(CATIKweAppResourceItem, CATBaseUnknown);


#endif // CATIKweAppResourceItem_h

