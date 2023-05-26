/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
#ifndef CATAdpQueryFilter_H
#define CATAdpQueryFilter_H

/**
* @level Protected
* @usage U1
*/


#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
#include "CATAdpQueryAttributeOperator.h"
#include "CATSysBoolean.h"
#include "CATUnicodeString.h"
#include "CATOmxAutoPtr.h"
class CATString;
class CATUnicodeString;
class CATPLMTypeH;
class CATIAdpType;
class CATIAdpExtType;
class CATAdpQueryAttributeSet;
class CATAdpPrivateQueryFilter;
// ecn comment : support du filtre pour generaliser un service de requete avec les extensions
/**
* Class defining a Filter to adress a query with extension
*
* <br><b>Role</b>: provide a set of attributes made of an attribute name and a value and operators for query.
*/
class ExportedByCATPLMIntegrationAccess CATAdpQueryFilter
{
public:

  /**
  * @deprecated V6R2013
  * @nodoc
  */
  CATAdpQueryFilter(CATIAdpType * iType, const CATAdpQueryAttributeSet  & iQueryAttributeSet, const CATAdpQueryAttributeOperator::LogicalOperator &iCondition = CATAdpQueryAttributeOperator::AND);
  /**
  * Constructs a Query Filter.
  * <br><b>Role</b>: Constructs a Query filter and initializes it with a  CATAdpQueryAttributeSet.
  * <ul>
  * <li> Until V6R2020x , by default, queries are case insensitive.
  * <li> From V6R2021x , the default mode is changed to case sensitive in order to avoid performance issues.
  * <li> Nevertheless , you have still the possibility to make a query with case insensitive.
  * <li> See  @href CATAdpQueryFilter#CaseSensitiveMode method to modify the case.</li>
  * </ul>
  *
  * @param iType [in]
  *   The PLM  Type.  .
  * @param iQueryAttributeSet [in]
  *   The set of attribute with a list of values and operators on a base PLM Type defining the filter.
  * @param iCondition[in]
  *   The logical condition to be applied between each attribute constraint inside the query attribute set .
  *
  */
  CATAdpQueryFilter(const CATPLMTypeH &iType, const CATAdpQueryAttributeSet  & iQueryAttributeSet, const CATAdpQueryAttributeOperator::LogicalOperator &iCondition = CATAdpQueryAttributeOperator::AND);
  
  /**
  * Copy constructs a query filter.
  * @return
  *   The copy of the query filter .
  */
  CATAdpQueryFilter(const CATAdpQueryFilter &);
  CATAdpQueryFilter & operator =(const CATAdpQueryFilter &);

  /**
  * Destructs an attribute set.
  */
  virtual ~CATAdpQueryFilter(void);

  /**
  * Specifies if the query should only yield the best so far minor versions of the components.
  * By default, this parameter is set to TRUE.
  */
  HRESULT RetrieveOnlyBSF(const CATBoolean & iRetrieveOnlyBSF = TRUE);

  /**
  * @deprecated V6R2013
  * @nodoc
  */
  HRESULT AddFilterOnExtensionAttributeSet(CATIAdpExtType * iType, CATAdpQueryAttributeSet  & iQueryAttributeSet, const CATAdpQueryAttributeOperator::LogicalOperator &iCondition = CATAdpQueryAttributeOperator::AND);
  /**
  * Adds an extension  on a query filter.
  *
  * <br><b>Role</b>: Adds an extension query attribute set on a query filter.
  *
  * @param iType [in]
  *   The extension PLM type.
  * @param iQueryAttributeSet [in]
  *   The set of attribute with a list of values and operators which definies the query attribute set.
  * @param iCondition[in]
  *   The logical condition to be applied between each attribute constraint inside the query attribute set. Between two query attribute sets
  *   a AND condition is applied.
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> .</li>
  *   <li><code>S_FALSE</code> .</li>
  *   <li><code>E_FAIL</code> if an internal error occured.</li>
  *   <li><code>E_INVALIDARG</code> if an invalid input was provided.</li>
  *   </ul>
  */
  HRESULT AddFilterOnExtensionAttributeSet(const CATPLMTypeH &iType, CATAdpQueryAttributeSet  & iQueryAttributeSet, const CATAdpQueryAttributeOperator::LogicalOperator &iCondition = CATAdpQueryAttributeOperator::AND);

  /**
  * @deprecated V6R214
  * @use ReturnQueryAttributes
  */
  HRESULT ReturnAllQueryMaskAttributes(const CATBoolean &iMode = TRUE);

  enum PLMFilterAttributesReturn { None = 0, FromQueryMaskAttributes = 1, CompleteQueryMaskAttributes = 2 };
  /**
  * Activate completion of query result
  *
  * <br><b>Role</b>: Activate the attribute completion of query result with the query mask on PLM type defined in the constructor. By default,
  *                  the return attribute list is built with attributes defined in the query attribute sets. It activates also the completion on
  *                  each extension attribute set.
  *
  * @param iMode [in]
  *   The filter on returned attributes from Query mask.
  *   <ul>
  *   <li>No attributes are returned if <code>None</code> value is given.</li>
  *   <li>Attributes from the input filter are returned if <code>FromQueryMaskAttributes</code> value is given and if it is part of the Query Mask. If not part of the Query Mask, a warning is given.</li>
  *   <li>All attributes being part of the Query Mask are returned if <code>CompleteQueryMaskAttributes</code> value is given.</li>
  *   </ul>
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if everything ran ok.</li>
  *   </ul>
  *
  */
  HRESULT ReturnQueryAttributes(PLMFilterAttributesReturn iMode);


  /**
  * Activate mode sensitive case for query
  *
   * <br><b>Role</b>:Activate mode sensitive case for query on string. By default, until V6R2020x,
  *                  the applied mode is not sensitive. From V6R2021x, the default mode is changed to case sensitive.
  *
  * @param iMode [in]
  *   Boolean value. If TRUE, the query is on case sensitive mode.
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if everything ran ok.</li>
  *   </ul>
  *
  */
  HRESULT CaseSensitiveMode(const CATBoolean &iMode = TRUE);

  /**
  * Force the query to be performed on a persistency repository.
  * <br><b>Role</b>: enables the user to force the query to be performed on a persistency repository.
  * <ul>
  * <li>If no persistency provider is connected, <code>E_UNEXPECTED</code> is returned.</li>
  * </ul>
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if everything ran ok.</li>
  *   </ul>
  *
  */
  HRESULT AimPersistencyRepository();

private:

  friend class CATAdpExtendedQueryServices;
  friend class CATAdpPLMQueryFilter;
  CATAdpPrivateQueryFilter & GetLetter() const { return *m_letter; }
  HRESULT  AddFilterOnDiscipline(const CATUnicodeString &iDiscipline);
  CATUnicodeString GetDiscipline() const;
  void ResetDiscipline();
  HRESULT ChangeMainType(const CATPLMTypeH & iNewMainType);
  void GetMainTypes(CATPLMTypeH & oRealMainType, CATPLMTypeH & oDowngradedMainType) const;
  void SetMainTypes(const CATPLMTypeH & iRealMainType, const CATPLMTypeH & iDowngradedMainType);

  CATOmxAutoPtr<CATAdpPrivateQueryFilter> m_letter;

};
#endif
