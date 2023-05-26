#ifndef CATIKweAppResourceSubItem_h
#define CATIKweAppResourceSubItem_h

// COPYRIGHT Dassault Systemes 2007

// System framework
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"
#include "CatKweAppRscItemType.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIKweAppResourceSubItem;
#else
extern "C" const IID IID_CATIKweAppResourceSubItem;
#endif

class CATIKweAppResourceItem_var;
class CATIValue_var;
class CATIInstance_var;
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
class CATString;
class CATIAdpPLMIdentificator;
class CATIKwdRunFrame_var;
class PLMIKbaRunAppliComponent_var;
class CATIKweFunctionsProvider_var;

/**
 * Interface used to represent a sub item in a Table of Application Resources.
 * A sub item is contained by a CATIKweAppResourceItem and is identified by a list
 * of criteria values.
 * @see CATIKweAppResourceItem
 */
class ExportedByCATLifSpecs CATIKweAppResourceSubItem : public CATBaseUnknown
{
	CATDeclareInterface;
	
  public:
	
	  /**
	   * Returns the resource sub item id.
	   * This identifier is computed from the containing item logical name 
	   * and can not be changed.
	   */
	  virtual CATUnicodeString GetId() = 0;

	  /**
	   * Returns the resource name.
	   * This name is automatically set according to the pointed resource and can not be changed.
	   * Note that this name is only used for display, not for a resource search.
	   */
	  virtual CATUnicodeString GetName() = 0;

	  /**
	   * Returns the resource display name.
	   * The display name consists in the resource name and 
	   * optionally the containing PLM component name.
	   */
	  virtual CATUnicodeString GetDisplayName() = 0;

	  /**
	   * Returns the comment describing the usage of the resource sub item.
	   * Note that this description is not used as a search criterium.
	   */
	  virtual CATUnicodeString GetDescription() = 0;

	  /**
	   * Returns the resource sub item type.
	   * Note that this type is equal to the containing item type.
	   */
	  virtual CatKweAppRscItemType GetType() = 0;

	  /**
	   * Returns TRUE if the pointed resource is set, FALSE otherwise.
	   */
	  virtual CATBoolean IsResourceSet() = 0;

	  /**
	   * Returns the pointed resource.
	   */
	  virtual CATBaseUnknown_var GetResource() = 0;

	  // Resource Type specifics methods

	  /**
	   * Retrieves the catalog pointed by the sub item.
	   * @param oCatalog
	   *   The retrieved pointed catalog if successful, NULL_var otherwise
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscCatalog, E_FAIL otherwise
	   */
	  virtual HRESULT GetCatalog(PLMICLGCatalog_var& oCatalog) = 0;

	  /**
	   * Retrieves the chapter pointed by the sub item.
	   * @param oChapter
	   *   The retrieved pointed chapter if successful, NULL_var otherwise
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscChapter, E_FAIL otherwise
	   */
	  virtual HRESULT GetChapter(PLMICLGChapter_var& oChapter) = 0;

	  /**
	   * Retrieves the document (Text or XML document) pointed by the sub item.
	   * @param oProjectedDocumentPath
	   *   The path of the retrieved pointed document if successful.
	   *   The document is automatically projected on the local disk by this method.
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscDocument, CatKweAppRscTextDocument, 
	   *   CatKweAppRscXMLDocument, CatKweAppRscSheet or CatKweAppRscDesignTable, E_FAIL otherwise
	   */
	  virtual HRESULT GetDocument(CATUnicodeString& oProjectedDocumentPath) = 0;

	  /**
	   * Retrieves the name of the icon pointed by the sub item.
	   * @param oIconName
	   *   The name of the retrieved pointed icon if successful.
	   *   The icon file is automatically projected in the runtime view by this method,
	   *   so that it can be used as any installed icons.
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscIcon, E_FAIL otherwise
	   */
	  virtual HRESULT GetIcon(CATString& oIconName) = 0;

	  /**
	   * Retrieves the PLM Directory pointed by the sub item.
	   * @param oPLMDirectory
	   *   The retrieved pointed PLM Directory if successful, NULL_var otherwise
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscPLMDirectory, E_FAIL otherwise
	   */
	  virtual HRESULT GetPLMDirectory(PLMIKbaZippedFolder_var& oPLMDirectory) = 0;

	  /**
	   * Retrieves the PLM Reference pointed by the sub item.
	   * @param oPLMReference
	   *   The retrieved pointed PLM Reference if successful, NULL_var otherwise
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscPLMReference, E_FAIL otherwise
	   */
	  virtual HRESULT GetPLMReference(CATIPLMNavReference_var& oPLMReference) = 0;

	  /**
	   * Retrieves the PLM RepReference pointed by the sub item.
	   * @param oPLMRepReference
	   *   The retrieved pointed PLM RepReference if successful, NULL_var otherwise
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscPLMRepReference, E_FAIL otherwise
	   */
	  virtual HRESULT GetPLMRepReference(CATIPLMNavRepReference_var& oPLMRepReference) = 0;

	  /**
	   * Retrieves the PLM Rule Set pointed by the sub item.
	   * @param oRuleBase
	   *   The retrieved pointed Rule Base if successful, NULL_var otherwise
	   * @return
	   *   S_OK if the resource sub item of type CatKweAppRscPLMRuleSet, E_FAIL otherwise
	   */
	  virtual HRESULT GetPLMRuleSet(CATIRuleBase_var& oRuleBase) = 0;

	  /**
	  * Retrieves the PLM Business Rule pointed by the sub item.
	  * @param oBusinessRule
	  *   The retrieved pointed Business Rule if successful, NULL_var otherwise
	  * @return
	  *   S_OK if the resource sub item of type CatKweAppRscPLMBusinessRule, E_FAIL otherwise
	  */
	  virtual HRESULT GetPLMBusinessRule(CATBaseUnknown_var& oBusinessRule) = 0;

	  /**
	   * Retrieves the PLM Template pointed by the sub item.
	   * @param oPLMTemplate
	   *   The retrieved pointed PLM Template if successful, NULL_var otherwise
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscPLMTemplate, E_FAIL otherwise
	   */
	  virtual HRESULT GetPLMTemplate(CATIUdfInstantiate_var& oPLMTemplate) = 0;

	  /**
	   * Retrieves the Power Copy pointed by the sub item.
	   * @param oPowerCopy
	   *   The retrieved pointed Power Copy if successful, NULL_var otherwise
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscPowerCopy, E_FAIL otherwise
	   */
	  virtual HRESULT GetPowerCopy(CATIUdfInstantiate_var& oPowerCopy) = 0;

	  /**
	   * Retrieves the User Defined Feature pointed by the sub item.
	   * @param oUDF
	   *   The retrieved pointed User Defined Feature if successful, NULL_var otherwise
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscUserDefinedFeature, E_FAIL otherwise
	   */
	  virtual HRESULT GetUserDefinedFeature(CATIUdfInstantiate_var& oUDF) = 0;

	  /**
	   * Retrieves the sheet pointed by the sub item.
	   * @param oSheet
	   *   The retrieved pointed sheet if successful, NULL_var otherwise
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscSheet or CatKweAppRscDesignTable,
	   *   E_FAIL otherwise
	   */
	  virtual HRESULT GetSheet(CATICkeSheet_var& oSheet) = 0;

	  /**
	   * Retrieves the VBScript program pointed by the sub item.
	   * This method also returns the script container, so the program is still valid.
	   * @param oContainer
	   *   The retrieved pointed script container if successful, NULL otherwise
	   * @param oProgram
	   *   The retrieved pointed VBScript program if successful, NULL otherwise
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscVBScriptProgram, E_FAIL otherwise
	   */
	  virtual HRESULT GetVBScriptProgram(
		  CATIScriptContainer *& oContainer,
		  CATIScriptProgram *& oProgram) = 0;

	  /**
	   * Retrieves the VBA program pointed by the sub item.
	   * This method also returns the script container, so the program is still valid.
	   * @param oContainer
	   *   The retrieved pointed script container if successful, NULL otherwise
	   * @param oProgram
	   *   The retrieved pointed VBA program if successful, NULL otherwise
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscVBScriptProgram, E_FAIL otherwise
	   */
	  virtual HRESULT GetVBAProgram(
		  CATIScriptContainer *& oContainer,
		  CATIScriptProgram *& oProgram) = 0;

	  /**
	  * Retrieves the KBE Concept pointed by the sub item.
	  * @param oConcept
	  *   The retrieved pointed concept if successful, NULL_var otherwise
	  * @return
	  *   S_OK if the resource sub item is of type CatKweAppRscKBEConcept, E_FAIL otherwise
	  */
	  virtual HRESULT GetKBEConcept(
		  CATBaseUnknown_var &oContainer) = 0;

	  /**
	  * Retrieves the EKL Library pointed by the sub item.
	  * @param oLibrary
	  *   The retrieved pointed Library if successful, NULL_var otherwise
	  * @return
	  *   S_OK if the resource sub item is of type CATKweAppRscPLMKHLibrary, E_FAIL otherwise
	  */
	  virtual HRESULT GetEKLLibrary(
		  CATIKweFunctionsProvider_var &oLibrary) = 0;

	  /**
	  * Retrieves the Machining Process pointed by the sub item.
	  * @param oMachiningProcess
	  *   The retrieved pointed Machining Process if successful, NULL_var otherwise
	  * @return
	  *   S_OK if the resource sub item is of type CatKweAppRscPowerCopy, E_FAIL otherwise
	  */
	  virtual HRESULT GetMachiningProcess(CATBaseUnknown_var& oMachiningProcess) = 0;

	  /**
	   * Retrieves the Dialog Frame pointed by the sub item.
	   * @param oFrame
	   *   The retrieved pointed Dialog Frame if successful, NULL otherwise
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscCustoDialogTopFrame, E_FAIL otherwise
	   */
	  virtual HRESULT GetCustoDialogTopFrame(
		  CATIKwdRunFrame_var& oFrame) = 0;

	  /**
	   * Retrieves the PLM Knowledge Applicative Component pointed by the sub item.
	   * @param oKComp
	   *   The retrieved pointed PLM Knowledge Applicative Component if successful, NULL otherwise
	   * @return
	   *   S_OK if the resource sub item is of type CatKweAppRscPLMKnowledgeAppliComponent, E_FAIL otherwise
	   */
	  virtual HRESULT GetPLMKnowledgeAppliComponent(
		  PLMIKbaRunAppliComponent_var& oKComp) = 0;


	  // Criteria specifics methods

	  /**
	   * Retrieves the value of the specified criterion.
	   * This method returns an error if the containing table does not
	   * have a criterion with the specified name.
	   * @param iCriterionName
	   *   The name of the criterion to retrieve.
	   * @param oCriterionValue
	   *   The retrieved value of the criterion.
	   *   Note that this value can be unset.
	   * @return
	   *   S_OK if successful, E_FAIL otherwise
	   */
	  virtual HRESULT GetCriterionValue(
		  const CATUnicodeString& iCriterionName,
		  CATIValue_var& oCriterionValue) = 0;

	  /**
	   * Returns TRUE if the resource sub item matches the given criteria values,
	   * FALSE otherwise.
	   * The sub item matches a given criterion value in the two following cases :
	   *   - its value for this criterion is Unset (which means it accepts any value)
	   *   - its value for this criterion is equal to the given one. In this case,
	   *   the criterion is exactly matched.
	   * @param iCriteriaValues
	   *   The given criteria values.
	   * @param oNbExactlyMatching
	   *   Optional returned parameter specifying how many criteria values are 
	   *   matched exactly by this sub item. If the sub item has an unset value for 
	   *   a given criterion, then it is considered as matching the given criterion value
	   *   but not exactly.
	   */
	  virtual CATBoolean MatchCriteriaValues(
		  const CATIInstance_var& iCriteriaValues,
		  int * oNbExactlyMatching = NULL) = 0;

	  /**
	   * Returns the PLM component identificator.
	   */
	  virtual CATIAdpPLMIdentificator * GetPLMIdentificator() = 0;

	  /**
	   * Returns the PLM component corresponding to the pointed resource.
	   */
	  virtual CATBaseUnknown_var GetPLMComponent() = 0;

	  /**
	   * Retrieves the resource item that contains the current sub item.
	   * @param oItem
	   *   The retrieved containing item if successful, NULL_var otherwise
	   * @return
	   *   S_OK if the containing item has been correctly retrieved, E_FAIL otherwise
	   */
	  virtual HRESULT GetContainingItem(CATIKweAppResourceItem_var& oItem) = 0;

};

CATDeclareHandler(CATIKweAppResourceSubItem, CATBaseUnknown);


#endif // CATIKweAppResourceSubItem_h

