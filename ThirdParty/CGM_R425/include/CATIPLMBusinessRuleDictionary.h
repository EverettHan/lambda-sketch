#ifndef CATIPLMBusinessRuleDictionary_h
#define CATIPLMBusinessRuleDictionary_h

// COPYRIGHT Dassault Systemes 2008

// System framework
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"

// System framework
#include "CATUnicodeString.h"
#include "CATString.h"

class CATListValCATBaseUnknown_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIPLMBusinessRuleDictionary;
#else
extern "C" const IID IID_CATIPLMBusinessRuleDictionary;
#endif

/**
 * Interface providing services for PLM Business Rules.
 * @see CATIPLMBusinessRuleNode
 * @see CATIPLMBusinessRule
 */
class ExportedByCATLifSpecs CATIPLMBusinessRuleDictionary : public CATBaseUnknown
{
	CATDeclareInterface;
	
  public:
	
	  /**
	   * Retrieves the existing Business Rules from the given Opening Id.
	   * @param iOpeningId
	   * The given Opening Id
	   * @param oBusinessRules
	   * The retrieved Business Rules whose opening id is equal to the given one.
	   * Each Business Rule object implements the CATIPLMBusinessRuleNode interface.
	   */
	  virtual HRESULT GetBusinessRulesFromOpeningId(
		  const CATUnicodeString& iOpeningId,
		  CATListValCATBaseUnknown_var& oBusinessRules) = 0;

	  /**
	   * Returns the alias of the given Opening Id.
	   */
	  virtual CATUnicodeString GetOpeningAlias(const CATUnicodeString& iOpeningId) = 0;

	  /**
	   * Returns the full opening Id from the given opening Id.
	   * This method may add the prefix '<AppResourceSetId>|'
	   */
	  virtual CATUnicodeString GetFullOpeningId(const CATUnicodeString& iOpeningId) = 0;

	  /**
	   * Returns the PLM Business Rule corresponding to the given Business Rule node.
	   * @see CATIPLMBusinessRuleNode
	   */
	  virtual HRESULT GetPLMBusinessRule(
		  const CATBaseUnknown_var& iBusinessRuleNode,
		  CATBaseUnknown_var& oPLMBusinessRule) = 0;

	  /**
	   * Returns the description of the given Business Rule Node.
	   * @see CATIPLMBusinessRuleNode
	   */
	  virtual HRESULT GetBusinessRuleNodeDescription(
		  const CATBaseUnknown_var& iBusinessRuleNode,
		  CATUnicodeString& oDescription) = 0;

	  /**
	   * Returns the body of the given Business Rule.
	   * @see CATIPLMBusinessRule
	   */
	  virtual HRESULT GetBusinessRuleBody(
		  const CATBaseUnknown_var& iBusinessRule,
		  CATUnicodeString& oBody) = 0;

	  /**
	   * Returns the fact type of the given Business Rule.
	   * @see CATIPLMBusinessRule
	   */
	  virtual HRESULT GetBusinessRuleFactType(
		  const CATBaseUnknown_var& iBusinessRule,
		  CATUnicodeString& oFactType) = 0;

	  /**
	   * Returns the scope (as an integer) of the given Business Rule.
	   * @see CATIPLMBusinessRule
	   */
	  virtual HRESULT GetBusinessRuleScope(
		  const CATBaseUnknown_var& iBusinessRule,
		  int& oScope) = 0;

	  /**
	   * Returns the help identifier for the given Opening Id.
	   */
	  virtual CATString GetOpeningHelpId(const CATUnicodeString& iOpeningId) = 0;

	  /**
	   * Clears the cached dictionary.
	   */
	  virtual HRESULT Clear() = 0;


      /**
      * Returns the priority (as an integer) of the given Business Rule.
      * @see CATIPLMBusinessRule
      */
      virtual HRESULT GetBusinessRulePriority(
        const CATBaseUnknown_var& iBusinessRule,
        int& oPriority) = 0;

};

CATDeclareHandler(CATIPLMBusinessRuleDictionary, CATBaseUnknown);

#endif // CATIPLMBusinessRuleDictionary_h

