#ifndef CATISetupDataFinder_h
#define CATISetupDataFinder_h

// COPYRIGHT Dassault Systemes 2007

// System framework
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"
#include "CATListOfCATIKweAppResourcesTable.h"
#include "CATListOfCATIKweAppResourceSubItem.h"
#include "CATIInstance.h"
#include "CATListOfCATIValue.h"
#include "CATListValCATIType.h"
#include "CATListValCATIInstance.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATISetupDataFinder;
#else
extern "C" const IID IID_CATISetupDataFinder;
#endif

class CATIKweAppResourcesTable_var;
class CATIKweAppResourceItem_var;
class CATIKweAppResourceSubItem_var;
class CATIUdfInstantiate_var;
class CATIPLMNavReference_var;
class CATIPLMNavRepReference_var;
class CATIRuleBase_var;
class CATICkeSheet_var;
class PLMICLGCatalog_var;
class PLMICLGChapter_var;
class CATIScriptContainer;
class CATIScriptProgram;
class PLMIKbaZippedFolder_var;
class CATIKweFunctionsProvider_var;
class CATString;

/**
 * Interface used to find Setup data contained in the Application Resources Tables
 * specifics to the current P&O Context.
 * A P&O context is defined by notions like User, Role, Organization, Project, ... This 
 * context is set when the user logs in, which gives him access to a defined set of applicative
 * resources.
 * This class manages a list of the Resources Tables that are linked to the current P&O Context.
 * The goal of this interface is to ease the usage of each supported resource types for application :
 * it allows to return the most accurate interface according to the retrieved resource type.
 *
 * Note that the life cycle of the PLM resources loaded with a Setup Data Finder 
 * instance is linked to the life cycle of this finder.
 *
 * @see CATIKweAppResourcesTable
 */
class ExportedByCATLifSpecs CATISetupDataFinder : public CATBaseUnknown
{
	CATDeclareInterface;
	
  public:
	
	  /**
	   * Returns the Applications Resources Table associated to the current P&O Context.
	   * @param oTables
	   *   The retrieved tables
	   * @return
	   *   S_OK if the tables have been correctly retrieved, E_FAIL otherwise
	   */
	  virtual HRESULT GetCurrentTables(CATListOfCATIKweAppResourcesTable& oTables) = 0;

	  /**
	   * Retrieves the table of the given Id associated to the current P&O Context.
	   * @param oTable
	   *   The retrieved table if successful, NULL_var otherwise
	   * @return
	   *   S_OK if the table has been correctly retrieved, E_FAIL otherwise
	   */
	  virtual HRESULT GetTable(
		  const CATUnicodeString& iAppResourceSetId,
		  CATIKweAppResourcesTable_var& oTable) = 0;

	  /**
	   * Creates an empty CATIInstance object that can be used to pass criteria values
	   * to the different Findxxx methods.
	   * To provide specific criteria values to the object, please use the CATIDynamicAttributes::Add 
	   * method.
	   * @param iName
	   *   Name of the created CATIInstance object
	   * @param oCriteriaValues
	   *  Created CATIInstance object
	   */
	  virtual HRESULT CreateCriteriaValues(
		  const CATUnicodeString &iName,
		  CATIInstance_var& oCriteriaValues) = 0;

	  /**
	   * Retrieves the resource item stored in the table whose identifier is 
	   * equal to the given one.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource.
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param oResourceItem
	   *   The retrieved resource item if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a resource item has been found with the given logical name,
	   *   E_FAIL otherwise
	   */
	  virtual HRESULT FindResourceItem(
		  const CATUnicodeString& iSetupDataUsageID, 
		  CATIKweAppResourceItem_var& oResourceItem) = 0;

	  /**
	   * Retrieves the resource pointed by the item stored in the current managed tables whose identifier is 
	   * equal to the given one and who is fitting the given criteria values.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource.
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oResource
	   *   The retrieved pointed resource if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a resource item has been found with the given identifier and criteria values,
	   *   E_FAIL otherwise
	   */
	  virtual HRESULT FindPointedResource(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATIInstance_var& iCriteriaValues,
		  CATBaseUnknown_var& oResource) = 0;

	  /**
	   * Retrieves the resource sub item stored in the current managed tables whose identifier is 
	   * equal to the given one and that is matching the given criteria.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item to retrieve
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the resource item to retrieve.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oResourceSubItem
	   *   The retrieved resource sub item if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a resource item has been found with the given identifier,
	   *   E_FAIL otherwise
	   */
	  virtual HRESULT FindResource(
		  const CATUnicodeString& iSetupDataUsageID,
		  const CATIInstance_var& iCriteriaValues,
		  CATIKweAppResourceSubItem_var& oResourceSubItem) = 0;

	  /**
	   * Retrieves all the resource sub items stored in the current managed tables matching the given logical 
	   * pattern name  and criteria values.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item to retrieve
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the resource items to retrieve.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oResourcesList
	   *   The list of retrieved resource sub items
	   * @param iIsResourceSet
	   *   Specifies whether the retrieved resources items must have a pointed resource set or not.
	   *   Legal values :
	   *     -1 : parameter ignored
	   *     0  : the retrieved resources items have no pointed resource set
	   *     1  : the retrieved resources items have a pointed resource set
	   * @return
	   *   S_OK if at least one resource sub item has been found with the given logical pattern name and type,
	   *   E_FAIL otherwise
	   */
	  virtual HRESULT FindResources(
		  const CATUnicodeString& iSetupDataUsageID,
		  const CATIInstance_var& iCriteriaValues,
		  CATListOfCATIKweAppResourceSubItem& oResourcesList,
		  int iIsResourceSet = -1) = 0;

	  // Resource Type specifics methods
	  
	  /**
	   * Retrieves the catalog pointed by the item stored in the current managed tables whose identifier is 
	   * equal to the given one and who is fitting the given criteria values.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oCatalog
	   *   The retrieved pointed catalog if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a resource item of type CatKweAppRscCatalog has been found with 
	   *   the given identifier and criteria values, E_FAIL otherwise
	   */
	  virtual HRESULT FindCatalog(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATIInstance_var& iCriteriaValues,
		  PLMICLGCatalog_var& oCatalog) = 0;

	  /**
	   * Retrieves the chapter pointed by the item stored in the table whose logical name is 
	   * equal to the given one and who is fitting the given criteria values.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oChapter
	   *   The retrieved pointed chapter if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a resource item of type CatKweAppRscChapter has been found with 
	   *   the given logical name and criteria values, E_FAIL otherwise
	   */
	  virtual HRESULT FindChapter(
		  const CATUnicodeString& iLogicalName, 
		  const CATIInstance_var& iCriteriaValues,
		  PLMICLGChapter_var& oChapter) = 0;

	  /**
	   * Retrieves the document (Text or XML document) pointed by the item stored in the current 
	   * managed tables whose identifier is equal to the given one and who is fitting the 
	   * given criteria values.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oProjectedDocumentPath
	   *   The path of the retrieved pointed document if successful
	   *   The document is automatically projected on the local disk by this method.
	   * @return
	   *   S_OK if a resource item of type CatKweAppRscDocument, CatKweAppRscTextDocument, 
	   *   CatKweAppRscXMLDocument, CatKweAppRscSheet or CatKweAppRscDesignTable has been found
	   *   with the given identifier and criteria values, E_FAIL otherwise
	   */
	  virtual HRESULT FindDocument(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATIInstance_var& iCriteriaValues,
		  CATUnicodeString& oProjectedDocumentPath) = 0;

	  /**
	   * Retrieves the name of the icon pointed by the item stored in the current managed tables whose identifier is 
	   * equal to the given one and who is fitting the given criteria values.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oIconName
	   *   The name of the retrieved pointed icon if successful
	   *   The icon file is automatically projected in the runtime view by this method,
	   *   so that it can be used as any installed icons.
	   * @return
	   *   S_OK if a resource item of type CatKweAppRscIcon has been found with 
	   *   the given identifier and criteria values, E_FAIL otherwise
	   */
	  virtual HRESULT FindIcon(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATIInstance_var& iCriteriaValues,
		  CATString& oIconName) = 0;

	  /**
	   * Retrieves the PLM Directory pointed by the item stored in the table whose logical name is 
	   * equal to the given one and who is fitting the given criteria values.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oPLMDirectory
	   *   The retrieved pointed PLM Directory if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a resource item of type CatKweAppRscPLMDirectory has been found with 
	   *   the given logical name and criteria values, E_FAIL otherwise
	   */
	  virtual HRESULT FindPLMDirectory(
		  const CATUnicodeString& iLogicalName, 
		  const CATIInstance_var& iCriteriaValues,
		  PLMIKbaZippedFolder_var& oPLMDirectory) = 0;

	  /**
	   * Retrieves the PLM Reference pointed by the item stored in the current managed tables whose identifier is 
	   * equal to the given one and who is fitting the given criteria values.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oPLMReference
	   *   The retrieved pointed PLM Reference if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a resource item of type CatKweAppRscPLMReference has been found with 
	   *   the given identifier and criteria values, E_FAIL otherwise
	   */
	  virtual HRESULT FindPLMReference(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATIInstance_var& iCriteriaValues,
		  CATIPLMNavReference_var& oPLMReference) = 0;

	  /**
	   * Retrieves the PLM RepReference pointed by the item stored in the current managed tables whose identifier is 
	   * equal to the given one and who is fitting the given criteria values.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oPLMRepReference
	   *   The retrieved pointed PLM RepReference if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a resource item of type CatKweAppRscPLMRepReference has been found with 
	   *   the given identifier and criteria values, E_FAIL otherwise
	   */
	  virtual HRESULT FindPLMRepReference(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATIInstance_var& iCriteriaValues,
		  CATIPLMNavRepReference_var& oPLMRepReference) = 0;

	  /**
	   * Retrieves the PLM Rule Set pointed by the item stored in the current managed tables whose identifier is 
	   * equal to the given one and who is fitting the given criteria values.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oRuleBase
	   *   The retrieved pointed Rule Base if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a resource item of type CatKweAppRscPLMRuleSet has been found with 
	   *   the given identifier and criteria values, E_FAIL otherwise
	   */
	  virtual HRESULT FindPLMRuleSet(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATIInstance_var& iCriteriaValues,
		  CATIRuleBase_var& oRuleBase) = 0;

	  /**
	   * Retrieves the PLM Template pointed by the item stored in the current managed tables whose identifier is 
	   * equal to the given one and who is fitting the given criteria values.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oPLMTemplate
	   *   The retrieved pointed PLM Template if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a resource item of type CatKweAppRscPLMTemplate has been found with 
	   *   the given identifier and criteria values, E_FAIL otherwise
	   */
	  virtual HRESULT FindPLMTemplate(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATIInstance_var& iCriteriaValues,
		  CATIUdfInstantiate_var& oPLMTemplate) = 0;

	  /**
	   * Retrieves the Power Copy pointed by the item stored in the current managed tables whose identifier is 
	   * equal to the given one and who is fitting the given criteria values.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oPowerCopy
	   *   The retrieved pointed Power Copy if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a resource item of type CatKweAppRscPowerCopy has been found with 
	   *   the given identifier and criteria values, E_FAIL otherwise
	   */
	  virtual HRESULT FindPowerCopy(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATIInstance_var& iCriteriaValues,
		  CATIUdfInstantiate_var& oPowerCopy) = 0;

	  /**
	   * Retrieves the User Defined Feature pointed by the item stored in the current managed tables whose identifier is 
	   * equal to the given one and who is fitting the given criteria values.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oUDF
	   *   The retrieved pointed User Defined Feature if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a resource item of type CatKweAppRscUserDefinedFeature has been found with 
	   *   the given identifier and criteria values, E_FAIL otherwise
	   */
	  virtual HRESULT FindUserDefinedFeature(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATIInstance_var& iCriteriaValues,
		  CATIUdfInstantiate_var& oUDF) = 0;

	  /**
	   * Retrieves the sheet pointed by the item stored in the current managed tables whose identifier is 
	   * equal to the given one and who is fitting the given criteria values.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oSheet
	   *   The retrieved pointed sheet if successful, NULL_var otherwise
	   * @return
	   *   S_OK if a resource item of type CatKweAppRscSheet or CatKweAppRscDesignTable has been found with 
	   *   the given identifier and criteria values, E_FAIL otherwise
	   */
	  virtual HRESULT FindSheet(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATIInstance_var& iCriteriaValues,
		  CATICkeSheet_var& oSheet) = 0;

	  /**
	   * Retrieves the VBScript program pointed by the item stored in the current managed tables whose identifier is 
	   * equal to the given one and who is fitting the given criteria values.
	   * This method also returns the script container, so the program is still valid.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oContainer
	   *   The retrieved pointed script container if successful, NULL otherwise
	   * @param oProgram
	   *   The retrieved pointed VBScript program if successful, NULL otherwise
	   * @return
	   *   S_OK if a resource item of type CatKweAppRscVBScriptProgram has been found with 
	   *   the given identifier and criteria values, E_FAIL otherwise
	   */
	  virtual HRESULT FindVBScriptProgram(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATIInstance_var& iCriteriaValues,
		  CATIScriptContainer *& oContainer,
		  CATIScriptProgram *& oProgram) = 0;

	  /**
	   * Retrieves the VBA program pointed by the item stored in the current managed tables whose identifier is 
	   * equal to the given one and who is fitting the given criteria values.
	   * This method also returns the script container, so the program is still valid.
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   The optional given criteria values to identify the corresponding resource item.
	   *   This list of criteria values must correspond to existing table criteria.
	   *   If there are several resource items matching these criteria, only the first one
	   *   is returned by this method ; to retrieve all the matching resource items, use the 
	   *   FindResources method.
	   *   Pass NULL_var if there is no criteria to use.
	   * @param oContainer
	   *   The retrieved pointed script container if successful, NULL otherwise
	   * @param oProgram
	   *   The retrieved pointed VBA program if successful, NULL otherwise
	   * @return
	   *   S_OK if a resource item of type CatKweAppRscVBScriptProgram has been found with 
	   *   the given identifier and criteria values, E_FAIL otherwise
	   */
	  virtual HRESULT FindVBAProgram(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATIInstance_var& iCriteriaValues,
		  CATIScriptContainer *& oContainer,
		  CATIScriptProgram *& oProgram) = 0;

	  /**
	  * Retrieves the Machining Process pointed by the item stored in the current managed tables whose identifier is 
	  * equal to the given one and who is fitting the given criteria values.
	  * @param iSetupDataUsageID
	  *   The given identifier of the resource item containing the expected pointed resource
	  *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	  *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	  * @param iCriteriaValues
	  *   The optional given criteria values to identify the corresponding resource item.
	  *   This list of criteria values must correspond to existing table criteria.
	  *   If there are several resource items matching these criteria, only the first one
	  *   is returned by this method ; to retrieve all the matching resource items, use the 
	  *   FindResources method.
	  *   Pass NULL_var if there is no criteria to use.
	  * @param oMachiningProcess
	  *   The retrieved pointed Machining Process if successful, NULL_var otherwise
	  * @return
	  *   S_OK if a resource item of type CATKweAppRscMachiningProcess has been found with 
	  *   the given identifier and criteria values, E_FAIL otherwise
	  */
	  virtual HRESULT FindMachiningProcess(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATIInstance_var& iCriteriaValues,
		  CATBaseUnknown_var& oMachiningProcess) = 0;

	 /**
	  * Retrieves EKL Library described by the logical name iLibraryID.
	  * /!\ In deviation from the standard PRM model, this method only
	  * searches in one Resource Set: the one that is dedicated to includable
	  * Libraries.
	  * @param iLibraryID
	  *   The logical name of the Library to retrieve.
	  * @param oLib
	  *   The retrieved pointed PLM EKL Library if found
	  * @return
	  *   S_OK if a resource item of type CATKweAppRscPLMKHLibrary has been found with 
	  *   the given identifier, E_FAIL otherwise
	  */
	  virtual HRESULT FindEKLLibrary(
		  const CATUnicodeString &iLibraryID,
		  CATIKweFunctionsProvider_var &oLib) = 0 ;

	  /**
	   * Retrieves EKL Libraries names declared in the Resource Set
	   * dedicated to EKL Libraries.
	   * @param oIncludableLibs a list containing all logical names found for EKL Libraries
	   * @return
	   *  S_OK if the list was correctly built
	   *  E_FAIL if the list could not be built
	   */
	  virtual HRESULT GetAllEKLLibrariesLogicalNames(
		  CATListOfCATUnicodeString &oIncludableLibs) = 0;

	  // Criteria specifics methods

	  /**
	   * Retrieves the possible values held by the resource item of the given 
	   * identifier for the specified criterion name (and optional other criteria values 
	   * used to filter the sub items).
	   * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the sub items in which this
	   *   method must look for.
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
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
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATUnicodeString& iCriterionName,
		  const CATIInstance_var& iOtherCriteriaValues,
		  CATListOfCATIValue& oValues) = 0;
    
    /**
	   * Retrieves the Types dictionary pointed by the item stored in the current managed tables whose identifier is  equal to the given one and who is fitting the given criteria values.
	   * Load it and retrieve the root types
     * @param iSetupDataUsageID
	   *   The given identifier of the resource item containing the expected pointed resource.
	   *   The Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and 
	   *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
	   * @param iCriteriaValues
	   *   For the moment, this argument is useless. Simply pass NULL_var.
	   * @return 
	   *   S_OK if a resource item has been found with the given identifier and criteria values,
	   *   E_FAIL otherwise
	   */
	  virtual HRESULT FindAndLoadTypesDictionary(
		  const CATUnicodeString& iSetupDataUsageID, 
		  const CATICkeObject_var& iCriteriaValues,
		  CATListValCATIType_var & oRootTypes) = 0;

		/**
		 * Loads the resources pointed by the items stored in the current managed tables whose identifiers are
		 * equal to the given ones and who are fitting the given criteria values.
		 *
		 * Be careful: it works only for simple PLM resources (document, text document, XML document, JSON document, sheets, design tables).
		 * 
		 * @param ilSetupDataUsageID
		 *   The given identifiers of the resource items containing the expected pointed resources.
		 *   A Setup Data Usage ID consists in a couple of strings representing the Resource Set Id and
		 *   the Resource Id with the following pattern : “AppResourceSetId|ResourceId”.
		 * @param ilCriteriaValues
		 *   The optional given criteria values to identify a corresponding resource item.
		 *   This list of criteria values must correspond to existing table criteria.
		 *   If there are several resource items matching these criteria, only the first one
		 *   is returned by this method ; to retrieve all the matching resource items, use the
		 *   FindResources method.
		 *   Pass NULL_var if there is no criteria to use, or even an empty list if not a single criteria to use
		 * 
		 * 	Be careful, if not empty, this list must have the same size as the one for ilSetupDataUsageID
		 *
		 * @return
		 *   S_OK if a resource item has been found with the given identifier and criteria values,
		 * 	 E_INVALIDARG if size of ilCriteriaValues is not nul and does not match size of ilSetupDataUsageID, or
		 * 			if a requested resource type is not one of the supported ones
		 *   E_FAIL otherwise
		 */
		virtual HRESULT LoadPointedResources(
			const CATListOfCATUnicodeString& ilSetupDataUsageID,
			const CATListValCATIInstance_var& ilCriteriaValues) = 0;

};

CATDeclareHandler(CATISetupDataFinder, CATBaseUnknown);

#endif // CATISetupDataFinder_h

