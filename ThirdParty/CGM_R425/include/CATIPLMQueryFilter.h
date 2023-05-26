// COPYRIGHT Dassault Systemes 2004
//===================================================================
// CATIPLMQueryFilter.h
//===================================================================
// 
// note:
// suppose you perform a NAVIGATE (or and EXPAND with filter on relation)
// suppose you use following parameter: CATIPLMQueryFilterAdditionalParams::SetParameter("SR_Optimisation", "SRUsedDuringNavigation") <=> Only SR crossed while navigating are returned by server
// Then use of CATIPLMQueryFilter::AddFilterSelectCriteria(<your type with SR>, PLMQY_RELATIONS, PLMQY_ALL) is meaningless and so is useless and has no effect
//  Apr 2004  Creation: jsy
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMQueryFilter_H
#define CATIPLMQueryFilter_H

//System/SpeciaAPI
#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "CATSysBoolean.h"
#include "CATIAV5Level.h"

//ObjectModelerCollection
#include "CATPLMOmxCollections.h"
#include "CATOmxOSet.h"

//CATPLMIdentificationAccess
#include "CATPLMID.h"
#include "CATLISTV_CATPLMTypeId.h"
#include "CATPLMStrongRelationshipId.h"
#include "CATPLMRepositoryName.h"

//CATPLMServices
#include "CATPLMQueryFilterEnum.h"

#define MandatorySemanticRelations

class CATUnicodeString;
class CATString;

class CATPLMType;
class CATPLMTypeH;

class CATIPLMFilterCriteria;
class CATIPLMFilterSelectCondition;
class CATIPLMFilterObjectToTreat;
class CATIPLMFilterOrderBy;
class CATIPLMFilterCriteria;
class CATIPLMFilterSelectCriteria;
class CATIPLMProviderDesc;
class CATIPLMFilterExplicit;
class CATIPLMFilterSimilar;
class CATIPLMVisualFilterWrap;
class CATIPLMVisualFilterViewpoint;

class CATListPtrCATIPLMFilterCriteria;
class CATListPtrCATIPLMFilterOrderBy;
class CATListPtrCATIPLMFilterObjectToTreat;
class CATListPtrCATIPLMFilterSelectCondition;
class CATListPtrCATIPLMFilterSelectCriteria;
class CATListPtrCATIPLMFilterExplicit;

#include "CATCollec.h"
class CATLISTV(CATPLMID);
class CATLISTP(CATPLMType);

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMQueryFilter;
#else
extern "C" const IID IID_CATIPLMQueryFilter;
#endif

/**
* CATIPLMQueryFilter provides for classes for applying various filter to the Query call.
* For methods in the CATIPLMQueryFilter object create instances of these classes. These classes and the methods which create them are listed below:
*
* 1.	CATIPLMFilterAttribute -created by the method CreateFilterAttribute. A CATIPLMFilterAttribute object is used for filtering query result from attributes.
* 2.	CATIPLMFilterRelation -created by the method CreateFilterRelation. A CATIPLMFilterRelation object is used for applying filter on the object relations.
* 3.	CATIPLMFilterVolume -created by the method CreateFilterVolume. A CATIPLMFilterVolume object is used for applying volume filter. CATIPLMFilterVolume has a group of methods which set for example the value of Matching bounding box parameters, the clearance, the existing zones…
* 4.	CATIPLMFilterConfig -created by the method CreateFilterConfig. A CATIPLMFilterConfig object is used for applying a configuration handler on the Root PRC during the expand operation.
*
* All these objects extend CATIPLMFilterBase which has the potential to be more efficient than a CATIPLMFilterXXX object because it can take a PPRQL expression as parameter.
*
* Each call CreateFilterXXX can be combine with another call in order to apply several filters with AND relations.
*/
class ExportedByCATPLMServicesItf CATIPLMQueryFilter : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**
  * Add a select condition in the select clause.
  * Objects of type "ipType" will be returned  with PLMID and cestamp.
  * @param ipType
  *    NULL type is forbidden of course...
  */
  virtual HRESULT AddSelectCondition(CATPLMType* ipType) = 0;

  /**
  * Add a select condition in the select clause.
  * Objects of type "ipType" will be returned  with PLMID, cestamp and "iAttributeId".
  * @param ipType
  *    NULL type is forbidden.
  *    Usage of V_Owner, V_InstanceOf, from, fromrel, to, torel is forbidden, use AddAssociatedObj(...).
  * @param iAttributeId
  *    the attribute value we want to get in the result. Empty string is forbidden.
  */
  virtual HRESULT AddSelectCondition(CATPLMType* ipType, const CATString& iAttributeId) = 0;

  /**
  * Adds a select condition on an extension attribute in the select clause.
  * The select clause picks which objects and properties to return in the query result set.
  * @param ipExtType
  *    NULL type is forbidden of course...
  * @param iRequestedBaseType
  *    The list of base type to use for this extension. List cannot be empty (iRequestedBaseTypes.Size()>0, iRequestedBaseTypes[1]!=NULL).
  * @return
  *         Error code of function :
  *   <dl>
  *     <dt>S_OK</dt><dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt><dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
  *     <dt>E_INVALIDARG </dt><dd>if ipType is not an extension</dd>
  *     <dt>E_INVALIDARG </dt><dd>if extension found in iRequestedBaseTypes</dd>
  *     <dt>E_INVALIDARG </dt><dd>if iRequestedBaseTypes.Size()==0</dd>
  *   </dl>
  */
  virtual HRESULT AddExtensionSelectCondition(CATPLMType* ipExtType, CATPLMTypeList& iRequestedBaseTypes) = 0;

  /**
  * Adds a select condition on an extension attribute in the select clause.
  * The select clause picks which objects and properties to return in the query result set.
  * @param ipExtType
  *    NULL type is forbidden of course...
  * @param iAttributeId
  *    the attribute value we want to get in the result. Empty string is forbidden.
  * @param iRequestedBaseType
  *    The list of base type to use for this extension. List cannot be empty (iRequestedBaseTypes.Size()>0, iRequestedBaseTypes[1]!=NULL).
  * @return
  *         Error code of function :
  *   <dl>
  *     <dt>S_OK</dt><dd>operation is successfully.</dd>
  *     <dt>E_FAIL </dt><dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
  *     <dt>E_INVALIDARG </dt><dd>if ipType is not an extension</dd>
  *     <dt>E_INVALIDARG </dt><dd>if extension found in iRequestedBaseTypes</dd>
  *     <dt>E_INVALIDARG </dt><dd>if iRequestedBaseTypes.Size()==0</dd>
  *   </dl>
  */
  virtual HRESULT AddExtensionSelectCondition(CATPLMType* ipExtType, const CATString& iAttributeId, CATPLMTypeList& iRequestedBaseTypes) = 0;

  /**
  * Adds a select condition in the select clause.
  * Select condition relation to strong relationship (from, to, ...)
  * <br><b>Role</b>:
  * @param ipType
  *   Type of object of which strong relationship will be added
  * @param iStrongRelId
  *   Strong relationship identifier
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code>Unable to add condition<dd>
  * <dt><code>E_INVALIDARG</code>ipType==NULL or ipType is an extension or relation iStrongRelId not found on ipType<dd>
  * </dl>
  */
  virtual HRESULT AddAssociatedObj(CATPLMType* ipType, CATPLMStrongRelationshipId::eStrongRelId iStrongRelId) = 0;

  /**
  * Returns the list of Select conditions. Each select clause picks which objects and properties to return in the query result set.
  *
  * @param oFilterSelectClauses
  *   List of select clauses. If the list already contains data, it won't be removed.
  *   Using a CATOmxList free the caller from releasing the contained objects.
  * @return
  *   S_OK if some select clauses have been added to the filter.
  *   S_FALSE if no select clause have been given to the query filter.
  *   E_* in case of internal error.
  */
  virtual HRESULT ListSelectConditions(CATIPLMFilterSelectConditionList & oFilterSelectClauses) = 0;

  /**
  * Adds a FilterSelectCriteria in the Filter.
  * A select criteria defines whether all attributes, Extension, Stream or relations are needed or not.
  *
  * @param iType
  * @param iQueryInfo
  *  The input query info, possible value is only  <tt>PLMQY_EXTENSIONS</tt>, <tt>PLMQY_STREAMS</tt> or <tt>PLMQY_RELATIONS</tt> or<tt>PLMQY_PATHTYPES</tt>.
  * @param iQueryValue
  *  The input query info, possible value is only <tt>PLMQY_ALL</tt> or <tt>PLMQY_NONE</tt>.
  *  For PLMQY_PATHTYPES, we can have <tt>PLMQY_ALL</tt> or <tt>PLMQY_NONE</tt> or <tt>PLMQY_PUREPATHTYPE</tt> or <tt>PLMQY_ALL_ID_ONLY</tt> or <tt>PLMQY_SR_ID_IDREL_ONLY</tt>
  *
  * When you READ data:
  * If in CATIPLMQueryFilter you set PLMQY_PATHTYPES to PLMQY_PUREPATHTYPE or to PLMQY_ALL then iState == CATPLMPathDataEnum::eall.
  * If in CATIPLMQueryFilter you set PLMQY_PATHTYPES to PLMQY_PUREPATHTYPE_ID_ONLY or to PLMQY_ALL_ID_ONLY then iState == CATPLMPathDataEnum::eall_except_id.
  * If in CATIPLMQueryFilter you set PLMQY_PATHTYPES to PLMQY_SR_ID_IDREL_ONLY then iState == CATPLMPathDataEnum::eid_idrel.
  *
  * When you WRITE data:
  * then iState == CATPLMPathDataEnum::eall_except_id (it is automatically set).
  *
  * Sibling option accepted above PLMAdapter:
  * PLMQY_RELATIONS PLMQY_NONE and PLMQY_PATHTYPES PLMQY_NONE for IRPC and ER types
  * PLMQY_RELATIONS PLMQY_ALL and PLMQY_PATHTYPES PLMQY_NONE for IRPC types (ipType->IsERType() != S_OK)
  * PLMQY_RELATIONS PLMQY_NONE and PLMQY_PATHTYPES PLMQY_ALL for ER types (ipType->IsERType() == S_OK) at import      ]oo, R423FD4]
  * PLMQY_RELATIONS PLMQY_NONE and PLMQY_PATHTYPES PLMQY_ALL for ER types (ipType->IsERType() == S_OK) at import/save [R423FD4, oo[
  *
  * Sibling option accepted for internal PLMAdapter use:
  * PLMQY_RELATIONS PLMQY_ALL and PLMQY_PATHTYPES PLMQY_PUREPATHTYPE
  * PLMQY_RELATIONS PLMQY_ALL and PLMQY_PATHTYPES PLMQY_PUREPATHTYPE_ID_ONLY
  * PLMQY_RELATIONS PLMQY_NONE and PLMQY_PATHTYPES PLMQY_SR_ID_IDREL_ONLY
  *
  * Following cases are forbidden:
  * PLMQY_RELATIONS PLMQY_ALL and PLMQY_PATHTYPES PLMQY_ALL at same time
  * PLMQY_RELATIONS PLMQY_ALL and PLMQY_PATHTYPES PLMQY_ALL_ID_ONLY at same time
  * PLMQY_RELATIONS PLMQY_ALL and PLMQY_PATHTYPES PLMQY_SR_ID_IDREL_ONLY at same time
  */
  virtual HRESULT AddFilterSelectCriteria(CATPLMType* iType, QueryInfo iQueryInfo, QueryValue iQueryValue) = 0;

  /**
  * Returns the list of CATPLMFilterSelectCriteria in the Filter. Each select criteria lists whether the Attributes,
  * Extensions, Streams or Relations are asked for or not.
  *
  * @param oFilterSelectCriterias
  *   The list of CATIPLMFilterSelectCriteria set on the filter.
  *   If the list already contains data, it won't be removed.
  *   Using a CATOmxList free the caller from releasing the contained objects.
  * @return
  *   S_OK if some select criteria have been added.
  *   S_FALSE if select criteria have been added to the query filter
  *   E_* in case of internal error.
  */
  virtual HRESULT ListFilterSelectCriterias(CATIPLMFilterSelectCriteriaList & oFilterSelectCriterias) = 0;

  /**
  * Returns the value of CATPLMFilterSelectCriteria in the Filter.
  * @param iQueryInfo
  *    The inputinformation
  * @param oQueryValue
  *     The output query Value
  *   The FilterSelectCriterias allow you to get informations about Attributes/Extensions/Streams/Relations.
  */
  virtual HRESULT GetFilterSelectCriteria(CATPLMType* iType, QueryInfo iQueryInfo, QueryValue * oQueryValue) = 0;

  /**
  * Adds a Criteria in the Filter.
  * The FilterCriteria allows you to narrow the list of objects returned by adding in it filters on
  * - config
  * - volume
  * - attribute
  * @param oFilterCriteria [out, CATBaseUnknown#Release]
  *   the new FilterCriteria.
  * @param iObjectContext
  *   the context in which criteria will be applied. Not used for BASIC_QUERY
  *   Mandatory for others query type. This object Context has to be added in the object Selection list. @see AddObject.
  */
  virtual HRESULT AddCriteria(CATIPLMFilterCriteria ** oFilterCriteria, const CATPLMID & iObjectContext = CATPLMID_Null) = 0;

  /**
   * Adds an Iterative Criteria in the Filter.
   * This is a replacement to CATIPLMQueryFilter::AddCriteria + CATIPLMFilterCriteria::MakeIterativeFilter, this API beeing suppressed in R419
   * An Iterative Criteria can only contain filter on attribute (either directly in the criteria, or through condition(s))
   * It only makes sence for QueryFilter used for expand.
   *
   * For a given PLMType, a query filter can only contain 1 keep and 1 remove criteria, both of same Overlay nature. use API GetIterativeCriteria to retrieve it.
   *
   * @param oFilterCriteria [out, CATBaseUnknown#Release]
   *   the new FilterCriteria.
   * @param iMode
   *   Remove/ Keep
   * @param iType
   *   On which type of objects the criteria applies (it applies to that type and its subtypes)
   * @param iOverlay
   *   When there's an iterative criteria on a parent type of iType, what does the newly defined criteria
   *   - true  : It completely overlay the filtering for iType and its subTypes, filtering on the parent type is disregarded.
   *             This is a new beheavior in R419, only implemented in MQL
   *   - false : The filtering on iType and its subTypes is an OR between the filtering defined on the parent type and the new defined criteria
   *
   * @return
   *    S_OK :
   *    E_INVALIDARG : iType is NULL or is extension
   *    E_INVALIDCRITERIA : (from CATPLMServicesHRESULT.h)  Attempting to add an iterative criteria in a query filter that is not for expand
   *    E_INVALIDOVERLAY : (from CATPLMServicesHRESULT.h) The query filter contains already an iterative criteria of that type but with a different Overlay
   *    E_EXISTINGCRITERIA : (from CATPLMServicesHRESULT.h) The query filter contains already an iterative criteria of that type / Iterative::Mode / Overlay
   */
  virtual HRESULT AddIterativeCriteria(CATIPLMFilterCriteria ** oFilterCriteria, Iterative::Mode iMode, CATPLMType *iType, bool iOverlay = false) = 0;

  /**
   * Get an already Iterative Criteria in the Filter, and optionally create it.
   * It only makes sense for QueryFilter used for expand.
   *
   * For a given PLMType, a query filter can only contain 1 keep and 1 remove criteria, both of same Overlay nature.
   *
   * @param oFilterCriteria [out, CATBaseUnknown#Release]
   *   the FilterCriteria, NULL if option create is false, and if the query filter does not contain a criteria of that type / mode.
   * @param iMode
   *   Remove/ Keep
   * @param iType
   *   On which type of objects the criteria applies (it applies to that type and its subtypes)
   * @param iOverlay
   *   When there's an iterative criteria on a parent type of iType, what does the newly defined criteria
   *   - true  : It completely overlay the filtering for iType and its subTypes, filtering on the parent type is disregarded.
   *             This is a new beheavior in R419, only implemented in MQL
   *   - false : The filtering on iType and its subTypes is an OR between the filtering defined on the parent type and the new defined criteria
   * @param Create
   *   Should the criteria be created if it does not already exist
   *
   * @return
   *    S_OK : Criteria returned
   *    E_FAIL : the QueryFilter does not contain an iterative criteria of that type/mode and the option create has not been specified.
   *    E_INVALIDARG : iType is NULL or is extension.
   *    E_INVALIDOVERLAY : (from CATPLMServicesHRESULT.h) The query filter contains an iterative criteria of that type but with a different Overlay
   *    E_INVALIDCRITERIA : (from CATPLMServicesHRESULT.h)  Attempting to add an iterative criteria in a query filter that is not for expand
   */
  virtual HRESULT GetIterativeCriteria(CATIPLMFilterCriteria ** oFilterCriteria, Iterative::Mode iMode, CATPLMType *iType, bool iOverlay, bool Create) = 0;

  /**
  * Returns the list of CATPLMFilterCriteria in the Filter.
  *
  * @param oFilterCriterias
  *   The list of cirterias set in the queryfiler.
  *   If the list already contains data, it won't be removed.
  *   Using a CATOmxList free the caller from releasing the contained objects.
  * @returns
  *   S_OK if some criterias have been added.
  *   S_FALSE if the filter doesn't have any criteria. No criteria has been added to oFilterCriterias.
  *   E_FAIL in case of internal error.
  */
  virtual HRESULT ListCriterias(CATIPLMFilterCriteriaList & oFilterCriterias) = 0;

  /**
  * WARNING: Useful for BASIC/OPEN query, ignored for NAVIGATE/EXPAND query.
  * WARNING: For attribute of extension, please use AddExtensionOrderBy.
  * Adds the result sort attribute.
  * The list returned by a query may be ordered by any attribute of a returned object Type
  * @param ipBaseType
  *    Base type.
  * @param iAttributeName
  *    Attribute name declared on current extension type ipExtType.
  * @param iAscending
  *    if = 0 Ascending (A then B then C...), if = 1 descending (C then B then A...).
  */
  virtual HRESULT AddOrderBy(CATPLMType* ipBaseType, const CATString& iAttributeName, int iAscending = 0) = 0;

  /**
  * WARNING: Useful for BASIC/OPEN query, ignored for NAVIGATE/EXPAND query.
  * Adds the result sort for an extension attribute.
  * The list returned by a query may be ordered by any attribute of a returned object Type
  * @param ipExtType
  *    Extension type.
  * @param iAttributeName
  *    Attribute name declared on current extension type ipExtType.
  * @param ilRequestedBaseTypes
  *    List of base type to use for this extension. list cannot be empty.
  * @param iAscending
  *    if = 0 Ascending (A then B then C...), if = 1 descending (C then B then A...).
  */
  virtual HRESULT AddExtensionOrderBy(CATPLMType* ipExtType, const CATString& iAttributeName, CATPLMTypeList& ilRequestedBaseTypes, int iAscending = 0) = 0;

  /**
  * Returns the list of the result sort attributes.
  * @param oFilterOrderBys
  *   The list of CATIPLMFilterOrderBy set on the filter.
  *   If the list already contains data, it won't be removed.
  *   Using a CATOmxList free the caller from releasing the contained objects.
  * @returns
  *   S_OK if some criterias have been added.
  *   S_FALSE if the filter doesn't have any criteria. No criteria has been added to oFilterCriterias.
  *   E_FAIL in case of internal error.
  */
  virtual HRESULT ListOrderBys(CATIPLMFilterOrderByList & oFilterOrderBys) = 0;

  /**
  * Adds an object involving in the filter.
  * For each ObjectToTreat, we get back :
  * attributes of the object if its type is defined in the select clause
  * attributes of all objects that this object can aggregate and that are listed in the select clause
  *
  * @param iObjectId
  *    The object Id.
  * @param iRepRole
  *     Several streams can be associated to a single object. The iRole parameter identifies the stream role.
  * (sample: a DV can have a MASTER representation and a CGR one)
  *
  * @returns
  *   S_OK
  *   E_NOPROVIDER : (from CATPLMServicesHRESULT.h) iObjectId does not contain provider info. Object is not added.
  *   E_MULTIPLEPROVIDERS : (from CATPLMServicesHRESULT.h) The query filter already contains object belonging to other providers. Object is not added.
  *   E_FAIL : other non documented error.
  *
  */
  virtual HRESULT AddObjectToTreat(const CATPLMID & iObjectId, CATUnicodeString * iRepRole = NULL) = 0;

  /**
  * Returns the list of object to treat.
  * <br><b>Role:</b>This method returns the list of the objects to treat.
  * @param oFilterObjectToTreats
  *   List of object to treat.
  *   If the list already contains data, it won't be removed.
  *   Using a CATOmxList free the caller from releasing the contained objects.
  * @return
  *   S_OK if some object to treat have been added.
  *   S_FALSE if no object to treat have been given to the query filter
  *   E_* in case of internal error.
  */
  virtual HRESULT ListObjectToTreats(CATIPLMFilterObjectToTreatList & oFilterObjectToTreats) = 0;

  /**
  * Sets the Query Mode.
  * <br><b>Role:</b>This method allows to set the query mode.
  * @param iQueryMode
  *   The input query mode, possible value is only <tt>BASIC_QUERY</tt>, <tt>EXPAND_QUERY</tt> or <tt>OPEN_QUERY</tt>.
  */
  virtual HRESULT SetQueryMode(CATPLMQueryFilterEnum::QueryMode iQueryMode) = 0;
  
  // @deprecated
  // Please use HRESULT SetSearchMode(CATPLMQueryFilterEnum::SearchMode iSearchMode)
  virtual HRESULT SetQueryMode(QueryMode iQueryMode) = 0;

  /**
  * Gets the Query Mode.
  * <br><b>Role:</b>This method allows to retrieve the query mode.
  * @param oQueryMode
  *   The output query mode.
  */
  virtual CATPLMQueryFilterEnum::QueryMode GetQueryMode() const = 0;
  
  // @deprecated
  // Please use HRESULT SearchMode GetSearchMode()
  virtual HRESULT GetQueryMode(QueryMode * oQueryMode) const = 0;

  /**
  * Sets the Search Mode.
  * <br><b>Role:</b>This method allows to set the seach mode.
  * @param iSearchMode
  *   The input search mode, possible value is only <tt>NORMAL_QUERY</tt> or <tt>SEARCH_QUERY</tt>.
  *
  * WARNING: SEARCH_QUERY is used to make query on index implemented over AUTONOMY. SEARCH_QUERY mustn't be used now that we use CLOUD VIEW instead of AUTONOMY.
  *          SEARCH_QUERY usage is DEPRECATED and FORBIDDEN. It has no sense.
  */
  virtual void SetSearchMode(CATPLMQueryFilterEnum::SearchMode iSearchMode) = 0;

  // @deprecated
  // Please use HRESULT SetSearchMode(CATPLMQueryFilterEnum::SearchMode iSearchMode)
  virtual HRESULT SetSearchMode(SearchMode iSearchMode) = 0;

  /**
  * Gets the Search Mode.
  * <br><b>Role:</b>This method allows to retrieve the search mode.
  *   return The output search mode.
  */
  virtual CATPLMQueryFilterEnum::SearchMode GetSearchMode() = 0;

  // @deprecated
  // Please use HRESULT SearchMode GetSearchMode()
  virtual HRESULT GetSearchMode(SearchMode * oSearchMode) = 0;

  /**
  * Get the expression of the query condition in XML format.
  * @param oXML
  *   The query condition expression in XML format.
  */
  virtual HRESULT GetXMLExpression(CATUnicodeString& oXML, const CATPLMRepositoryName& iRepo = CATPLMRepositoryName_Null) const = 0;

  // @deprecated
  virtual HRESULT GetXMLExpression(CATUnicodeString ** oXML, const CATPLMRepositoryName& iRepo = CATPLMRepositoryName_Null) const = 0;

  /**
  * Sets the number of result per page expected in the Fetch Query.
  * @param iPageSize
  *   The number (maximum) of objects returned in this result page,
  *      <br><b>Legal Values</b>:
  *      <ol>
  *      <li> n=-1 : for a full result
  *      <li> n>=1
  *      </ol>
  */
  virtual HRESULT SetFetchQueryPageSize(int iPageSize) = 0;
  /** Returns the number of result per page expected in the Fetch Query.*/
  virtual HRESULT GetFetchQueryPageSize(int * oPageSize) = 0;

  /**
  * Support the Last Version Only search when it becomes available. By default FALSE
  * @param iLastVersion
  *    Last Version Only search.
  *      <br><b>Legal Values</b>:
  *      <ol><li> n=1 : for Last Version Only
  *           <li> n = 0 otherwise (by default)</ol>
  */
  virtual HRESULT LastVersionOnly(int iLastVersion) = 0;
  /** Returns if Support the Last Version Only search when it becomes available.*/
  virtual HRESULT IsLastVersionOnly(int * oLastVersion) = 0;

  /**
  * Ask only for Best So Far object of the family.
  * WARNING:
  *   -without any explicit call on a QueryFilter, default value is considered to be TRUE.
  *   -disabling BSF mode is only possible on Basic Queries.
  * @param iBSFOnly
  *    BSF Only search.
  *      <br><b>Legal Values</b>:
  *      <ol><li> n=1 : for Last Version Only
  *           <li> n = 0 otherwise</ol>
  */
  virtual HRESULT BSFOnly(int iBSFOnly) = 0;
  /** Returns if BSF Only search when it becomes available.*/
  virtual HRESULT IsBSFOnly(int *oBSFOnly) const = 0;

  /**
  * Specifies if search is case sensitive. By default FALSE
  * @param iCaseSensitive
  *    CaseSensitive search.
  *      <br><b>Legal Values</b>:
  *      <ol><li> n=1 : search is Case-Sensitive
  *          <li> n = 0 search is Case-Insensitive (by default)</ol>
  */
  virtual HRESULT CaseSensitive(int iCaseSensitive) = 0;
  /** Returns if search is Case sensitive.*/
  virtual HRESULT IsCaseSensitive(int * oCaseSensitive) = 0;

  /**
  * Sets the depth of the expanded tree from the ObjectToTreat
  * @param iLevel
  *      The depth of the expanded tree from the ObjectToTreat. -1 for "ALL"
  */
  virtual HRESULT SetLevel(int iLevel) = 0;
  /**
  * Gets the depth of the expanded tree from the ObjectToTreat
  * @param oLevel
  *      The depth of the expanded tree from the ObjectToTreat.
  *      depth <= 0 means all levels
  */
  virtual HRESULT GetLevel(int * oLevel) = 0;

  /**
  * Clones the query into another one.
  * This method is used to copy all the sets of select, where and order by clauses to another query.
  * It allows to use a invariable base query from which a copy will be customized with variable data such as ObjectToTreat for example.
  * @param ioNewQuery [out, CATBaseUnknown#Release]
  *      The targeted QueryFilter where the copy will occur.
  */
  virtual HRESULT CloneQuery(CATIPLMQueryFilter * ioNewQuery) = 0;

  /**
  * Sets the depth and number of iteration of the expand messages.
  * @param iDepthLevel
  *      The depth of the expanded tree from the ObjectToTreat.
  *      Default is -1 meaning all elements will be returned.
  * @param iIterationLevel
  *      The number of iteration used to check the conditions of the query.
  *      Default is -1.
  */
  virtual HRESULT SetExpandLevels(int iDepthLevel, int iIterationLevel) = 0;

  /**
  * Gets the depth and number of iteration of the expand messages.
  * @param oDepthLevel
  *    The depth of the expanded tree from the ObjectToTreat.
  * @param oIterationLevel
  *    The number of iteration used to check the conditions of the query.
  */
  virtual HRESULT GetExpandLevels(int * oDepthLevel, int * oIterationLevel) = 0;


  /**
  * Sets the Filtered Expand behavior.
  * <br><b>Role:</b>This method allows to set the Filtered Expand behavior.
  * @param iFilteredExpandLimit
  *    The input Filtered Expand Limit, possible value is only <tt>NO_STOP</tt>, <tt>STOP_AT_FIRST</tt>, <tt>STOP_AT_LAST</tt> or <tt>LEAF_ONLY</tt>.
  *    The NO_STOP mode is the expected default behavior.
  *    The STOP_AT_LAST mode is used for backward compatibility which EV5 provider behavior.
  *    Error Management :
  *    - Returns S_FALSE if QueryMode is not set to EXPAND.
  *    - Returns S_OK otherwise.
  */
  virtual HRESULT SetFilteredExpandLimit(FilteredExpandLimit iFilteredExpandLimit) = 0;


  /**
  * Gets the Filtered Expand Limit.
  * <br><b>Role:</b>This method allows to retrieve the Filtered Expand Limit.
  * @param oFilteredExpandLimit
  *    The output the Filtered Expand Limit.
  */
  virtual HRESULT GetFilteredExpandLimit(FilteredExpandLimit * oFilteredExpandLimit) = 0;

  /**
  * SEARCH mode specific API (Full Text Search)
  * Specify the list of Taxon Categories to query.
  * <br><b>Role:</b>This method allows to set the list of Taxon Categories.
  * @param iTaxonCategoriesList
  *    The list of Taxon Categories to be used by the Query (in SEARCH mode).
  * @return
  *      S_OK  : Taxon Categories has been correctly added.
  *      E_FAIL: otherwise.
  */
  virtual HRESULT SetRequiredTaxonCategories(const CATListOfCATUnicodeString &iTaxonCategoriesList) = 0;

  /**
  * SEARCH mode specific API (Full Text Search)
  * Specify the list of Taxon Categories that will be quieried.
  * <br><b>Role:</b>This method allows to Get the list of Taxon Categories.
  * @param oTaxonCategoriesList
  *    The list of Taxon Categories to be used by the Query (in SEARCH mode).
  * @return
  *      S_OK  : Taxon Categories are correctly returned.
  *      E_FAIL: otherwise.
  */
  virtual HRESULT GetRequiredTaxonCategories(CATListOfCATUnicodeString &oTaxonCategoriesList) = 0;

  /**
  * SEARCH mode specific API (Full Text Search)
  * Remove Taxon Categories from the query.
  * <br><b>Role:</b>This method allows to remove Taxon Categories from the query.
  * @return
  *      S_OK  : Taxon Categories are correctly removed.
  *      E_FAIL: otherwise.
  */
  virtual HRESULT RemoveAllTaxonCategories() = 0;

  /**
  * SEARCH mode specific API (Full Text Search)
  * Specify the list of required Facetsto query.
  * <br><b>Role:</b>This method allows to set the list of Facets.
  * @param iFacets
  *    The list of Facets to be used by the Query (in SEARCH mode).
  *    Use "*" to get the list of all facets.
  * @return
  *      S_OK  : Facets has been correctly added.
  *      E_FAIL: otherwise.
  */
  virtual HRESULT SetRequiredFacets(const CATListOfCATUnicodeString &iFacets) = 0;

  /**
  * SEARCH mode specific API (Full Text Search)
  * Get the list of Facets that will be queried.
  * <br><b>Role:</b>This method allows to Get the list of required Facets.
  * @param oFacets
  *    The list of Facets to be used by the Query (in SEARCH mode).
  * @return
  *      S_OK  : Facets are correctly returned.
  *      E_FAIL: otherwise.
  */
  virtual HRESULT GetRequiredFacets(CATListOfCATUnicodeString &oFacets) = 0;

  /**
  * SEARCH mode specific API (Full Text Search)
  * Remove Facets from the query.
  * <br><b>Role:</b>This method allows to remove Facets from the query.
  * @return
  *      S_OK  : Facets are correctly removed.
  *      E_FAIL: otherwise.
  */
  virtual HRESULT RemoveAllFacets() = 0;

  /**
  * SEARCH mode specific API (Full Text Search)
  * Specify if suggestions are required during the query.
  * @param iMode
  *      <br><b>Legal Values</b>:
  *      <ol><li> TRUE : for search with suggestions
  *          <li> FALSE: otherwise (by default)</ol>
  */
  virtual void SearchSuggestions(CATBoolean iMode) = 0;

  /**
  * SEARCH mode specific API (Full Text Search)
  * Does suggestions are required during the query.
  * @return
  *      <br><b>Legal Values</b>:
  *      <ol><li> TRUE : for search with suggestions
  *          <li> FALSE: otherwise (by default)</ol>
  */
  virtual CATBoolean SuggestionsRequested() = 0;

  /*
  * @nodoc
  */
  virtual int IsEmpty() = 0;

  /** Attribute category.*/
#define CATPLMQFAttribute 0x1 
  /** Volume category.*/
#define CATPLMQFVolume    0X2
  /** Configuration category.*/
#define CATPLMQFConfig    0X4
  /** Function category.*/
#define CATPLMQFFunction  0X8
  /** Relation category.*/
#define CATPLMQFRelation  0X10
  /** Object to treat category.*/
#define CATPLMQFObjToTreat  0X20
  /** Minor explicit object category. */
#define CATPLMQFMinorExplicit  0X40
  /** Minor explicit object category. */
#define CATPLMQFFilterExplicit  0X80
  /** Iterative Filter. */
#define CATPLMQFFilterStepByStep 0x100
  /** Iterative Filter. */
#define CATPLMQFFilterSimilar 0X200
  /** Wrap or Viewpoint. */
#define CATPLMQFFilterVisual 0X400
  /** On which types of BO / relationship to expand */
#define CATPLMQFTypeToExpand 0X800
  /** Condition category (that contains filters of other categories */
#define CATPLMQFCondition 0X1000
  /** All category.*/
#define CATPLMQFAll  0Xffff

  /**
  * Removes filter elements of a specified kind.
  * This method is used after a copy to filter out some elements that are known to be useless for the next query.
  * @param iListOfCategory
  *      The bitfield value of categories to remove. example : CATPLMQFConfig|CATPLMQFRelation
  * @return
  *      S_OK   : The remove is succeeded. If the filter does not contain the requested category, there is no error.
  *      E_FAIL : If an unvalid input is given or something goes wrong.
  */
  virtual HRESULT RemoveFilterCategory(int iListOfCategory) = 0;

  /**
  * Inside an expand query possibility to explicitly provide PLMID of object to use instead of the default BSF object.
  *
  * @param iExplicitObjectList
  *
  * @return
  *      S_OK   :
  *      E_MULTIPLEMINORS : Attempting to declare as explicit objets several minor of the same BSF
  *      E_FAIL :
  */
  virtual HRESULT AddMinorExplicitObjects(const CATLISTV(CATPLMID) &iExplicitObjectList) = 0;

  /**
  * Inside an expand query possibility to explicitly provide PLMID of object to use instead of the default BSF object.
  *
  * @param iExplicitObjectList
  *
  * @return
  *      S_OK   :
  *      E_FAIL :
  */
  virtual HRESULT GetMinorExplicitObjects(CATLISTV(CATPLMID) &oExplicitObjectList) = 0;

  /**
  * Substitute instance filtering on expand query.
  * @param iPreferedOnly
  *      <br><b>Legal Values</b>:
  *      <ol><li> iPreferedOnly = 1 : only the prefered substitute should be returned (Default)
  *          <li> iPreferedOnly = 0 : otherwise
  *      </ol>
  */
  virtual HRESULT PreferedSubstituteOnly(int iPreferedOnly) = 0;

  /** Returns if Substitute instance filtering is on or off during expand.*/
  virtual HRESULT IsPreferedSubstituteOnly(int *oPreferedOnly) const = 0;

  /** Sets the Open query in a specific mode so only Snapshot are accessible .*/
  virtual void OpenOnSnapshot() = 0;

  /** Returns if the open queruy should find results in Snapshot objects. */
  virtual CATBoolean GetOpenOnSnapshotMode() const = 0;

  /** */
  virtual void ActivateIterationMode() = 0;

  /** */
  virtual CATBoolean IsIterationModeActivated() = 0;

  /**
  * Adds an explicit filter to the query filter.
  * Suppose you call AddExplicitFilter with parameters: CATPLMQueryFilterEnum::Remove, CATPLMQueryFilterEnum::Physical, iInputPath
  * branch with plmids == iInputPath will be removed
  * CAUTION: filtering doesn't apply on root (root can be a single plmids or a path)
  *
  * @param iMode
  *   The mode of the explicit filter
  * @param iBehavior
  *   The behavior of the explicit filter
  * @param iInputPath
  *   The path of elements to check. The path should be in the IIR format.
  */
  // namespace added to protect against global method, global enum...
  virtual HRESULT AddExplicitFilter(CATPLMQueryFilterEnum::ExplicitMode iMode, CATPLMQueryFilterEnum::ExplicitBehavior iBehavior, CATPLMID &iInputPath) = 0;

  /**
  * Return the explicit filters defined in the query.
  *
  * @param oExplicitFilters [out]:
  *   List of explicit filters set on the query filter.
  *   If the list already contains data, it won't be removed.
  *   Using a CATOmxList free the caller from releasing the contained objects.
  * @return
  *   S_OK if some explicit filter have been added.
  *   S_FALSE if no explicit filter have been set on the query filter
  *   E_* in case of internal error.
  */
  virtual HRESULT ListExplicitFilters(CATIPLMFilterExplicitList & oExplicitFilters) = 0;

  /**
  * Creates or return the similar filter to provide filter information.
  * This method should be used if a BASIC_QUERY of subtype SIMILAR_QUERY is requested to set information on the specific filter.
  * @param oSSFilter [out, CATBaseUnknown#Release]
  *   the oSSFilter.
  * @return
  *     S_OK : the similar filter was retrieved
  *     E_FAIL : Query type was not of the good type
  */
  virtual HRESULT GetSimilarSearchFilter(CATIPLMFilterSimilar *&oSSFilter) = 0;


  /**
  * Returns the created visual filter wrap to provide filter information.
  * @return
  *		 E_INVALIDARG : oSSFilter is not null
  *     S_OK : the visual filter wrap filter was created &/or retrieved
  *     E_FAIL : problem in the creation or retrieval of the filter
  */
  virtual HRESULT GetVisualFilterWrap(CATIPLMVisualFilterWrap *&oFilter) = 0;

  /**
   *@param oFilter [out, CATBaseUnknown#Release]
  */
  virtual HRESULT CreateVisualFilterWrap(CATIPLMVisualFilterWrap *&oFilter) = 0;


  /**
  * Returns the created visual filter viewpoint to provide filter information.
  * @param oFilter [out, CATBaseUnknown#Release]
  *   the oFilter
  * @return
  *		 E_INVALIDARG : oSSFilter is not null
  *     S_OK : the visual filter viewpoint filter was created &/or retrieved
  *     E_FAIL : problem in the creation or retrieval of the filter
  */
  virtual HRESULT GetVisualFilterViewpoint(CATIPLMVisualFilterViewpoint *&oFilter) = 0;

  virtual HRESULT CreateVisualFilterViewpoint(CATIPLMVisualFilterViewpoint *&oFilter) = 0;

  /**
  * Gets filter elements.
  * @param oListOfCategory
  *      The bitfield value of categories. example : CATPLMQFConfig|CATPLMQFRelation
  * @return
  *      S_OK   : The categories have been retrieved successfully.
  *      E_FAIL : An unvalid input is given or something goes wrong.
  */
  virtual HRESULT GetFilterCategory(int &oListOfCategory) const = 0;

  /**
  * Removes the Select Clauses + Select Filter Criterias.
  * @return
  *      S_OK   : The Select Clauses have been removed successfully.
  *      E_FAIL : No Select Clause to remove.
  */
  virtual HRESULT RemoveSelectClauses() = 0;

  /**
  * Removes the Order Bys.
  * @return
  *      S_OK   : The Order Bys have been removed successfully.
  *      E_FAIL : No Order By to remove.
  */
  virtual HRESULT RemoveOrderBys() = 0;

  /**
  * @nodoc
  * @deprecated R212 use @href CATIPLMQueryFilter::ListObjectToTreats with a CATOmxList
  */
  virtual HRESULT ListObjectToTreats(CATListPtrCATIPLMFilterObjectToTreat ** oFilterObjectToTreats) = 0;

  /**
  * @nodoc
  * @deprecated R212 use @href CATIPLMQueryFilter::ListCriterias with a CATOmxList
  */
  virtual HRESULT ListCriterias(CATListPtrCATIPLMFilterCriteria ** oFilterCriterias) = 0;

  /**
  * @nodoc
  * @deprecated R212 use @href CATIPLMQueryFilter::ListSelectConditions with a CATOmxList
  */
  virtual HRESULT ListSelectConditions(CATListPtrCATIPLMFilterSelectCondition ** oFilterSelectClause) = 0;

  /**
  * @nodoc
  * @deprecated R212 use @href CATIPLMQueryFilter::ListFilterSelectCriterias with a CATOmxList
  */
  virtual HRESULT ListFilterSelectCriterias(CATListPtrCATIPLMFilterSelectCriteria ** oFilterSelectCriterias) = 0;

  /**
  * @nodoc
  * @deprecated R212 use @href CATIPLMQueryFilter::ListFilterSelectCriterias with a CATOmxList
  */
  virtual HRESULT ListOrderBys(CATListPtrCATIPLMFilterOrderBy ** oFilterOrderBys) = 0;

  /**
  * @nodoc
  * @deprecated R212 use @href CATIPLMQueryFilter::ListExplicitFilters with a CATOmxList   */
  virtual HRESULT ListExplicitFilters(CATListPtrCATIPLMFilterExplicit &oList) = 0;

  /**
  * Following methods are restricted:
  *   AddMandatorySemanticRelation
  *   GetMandatorySemanticRelations
  *   IsSemanticRelationMandatory
  *   HasSomeSemanticRelationMandatory
  *   SetSemanticRelationMode
  *   GetSemanticRelationMode
  */
#if !defined(_WINDOWS_SOURCE) || \
    /* PLMAdapter */        defined(__CATPLMImplAdapterBase) || defined(__CATPLMImplAdapterQLBase) || defined(__CATPLMxReadWriteXMQL) || defined(__CATPLMImplAdapterAsync) || \
    /* PLMAdapter ODTs */   defined(__AdpQLTests) || defined(__AdpTests) || defined(__TSTCATPLMAppIdOpen) || defined(__TSTCATPLMxQueryExpand) || defined(__TSTCATPLMxNavSR) || \
                            defined(__TSTCATPLMxExpandSR) || defined(__TSTCATPLMxExpandSRBenchmark) || defined(__CATPCTExpand) || defined(__TSTCATPLMxLinkOnAttrAndSRv3) || \
                            defined(__TSTCATPLMxLinkSRv3) || defined(__TSTCATPLMxExpandModePushDecorate) || defined(__TSTCATPLMxExpandModePushDecorate) || \
    /* TSTProvider */       defined(__CATPLMDebugEngineImpl) || defined(__TSTCATPLMDbgLinkSRv3) || defined(__TSTCATPLMDbgLinkOnAttrAndSRv3) || \
    /* Integration */       defined(__CATPLMCompletion) || defined(__CATPLMModelBuilder) || defined(__CATPLMStatutRemote) || defined(__CATPLMIntegrationBase) || \
                            defined(__CATPLMCAAIntegAccess) || defined(__CATPLMDWSAccess) || defined(__CATPLMIntegrationAccess) || defined(__CATPLMIntegrationAccessBase) || \
                            defined(__CATPLMItgQuery) || \
    /* Integration ODts */  defined(__CATPLMItgRemoteStatusTests) || defined(__CATPLMItgTests) || \
    /* Others */            defined(__AUTBm2Migration) || defined(__CATPLMComponentChecker) || \
                            defined(__CATPLMxMQL)

  /**
   * Adds a filter on Semantic Relations to be retrieved. This information is used for performance
   * optimisations. The Semantic Relations asked in through this api are guaranted to be retrieved
   * with its synchronisation status computed if asked for.
   *
   * The provider executing the query may not take this information into account or only partially.
   * In this case, if a filter on SR is put on a type, all Semantic Relations may be retrieved and
   * all synchronisation statuses may be computed. Therefore, when a filter is added to a type,
   * AddFilterSelectCriteria on PLMQY_RELATIONS is automatically done.
   *
   * Calling this api many times will cumulate the mandatory roles for a given type.
   * To flush the whole filtering, use AddFilterSelectCriteria(myType, PLMQY_RELATIONS, PLMQY_NONE).
   *
   * @param iType
   *   The PLMType for which to set the mandatory semantic relation.
   * @param iSRRole
   *   The role on which to filter the relations.
   * @return
   *   S_OK if the filtering role has been added.
   *   E_* in case of error (like type not found...).
   */
  virtual HRESULT AddMandatorySemanticRelation(
    const CATPLMTypeH & iType,
    const CATUnicodeString & iSRRole) = 0;

  /**
   * Get the whole list of mandatory semantic relations to retrieve for a given type.
   *
   * If iWithInheritance is TRUE, this methods takes inheritance into account : if roleA has
   * been set mandatory for typeA and roleB for typeB, if typeB inherits from typeA, then this
   * method will list [roleA] for typeA and [roleA, roleB] for typeB.
   *
   * @param iType
   *   The PLMType for which to set the mandatory semantic relation.
   * @param oSRRoles
   *   The roles on which to filter the relations.
   *   WARNING : the previous content of the set is not removed.
   * @param iWithTypeInheritance
   *   Set this to TRUE if you want type inheritance to be taken into account.
   * @return
   *   S_OK if some filtering roles have been retrieved.
   *   S_FALSE if no filtering roles have been retrieved. Note that it could mean that the type
   *           doesn't need any relations or that all relations are needed. You should check
   *           GetFilterSelectCriteria to get the get required behavior in this case.
   *   E_* in case of error (like type not found...).
   */
  virtual HRESULT GetMandatorySemanticRelations(
    const CATPLMTypeH & iType,
    CATOmxOSet<CATUnicodeString> & oSRRoles,
    CATBoolean iWithTypeInheritance) = 0;

  /**
   * Tells if a given relation role is mandatory for a given type.
   *
   * This method takes inheritance into account : in the above scenario, roleA and roleB will
   * be said as mandatory for typeB. If AddFilterSelectCriteria(myType, PLMQY_RELATIONS, PLMQY_ALL)
   * has been called, but no mandatory relation has been set, all roles will be reported as mandatory.
   * Similarly, if AddFilterSelectCriteria(myType, PLMQY_RELATIONS, PLMQY_NONE) has been called,
   * no roles will be given as mandatory.
   *
   * @param iType
   *   The PLMType for which to set the mandatory semantic relation.
   * @param iSRRole
   *   The roles on which to filter the relations.
   * @return
   *   S_OK if the semantic relation is mandatory.
   *   S_FALSE if the semantic relation is not mandatory.
   *   E_* in case of error (like type not found...).
   */
  virtual HRESULT IsSemanticRelationMandatory(
    const CATPLMTypeH & iType,
    const CATUnicodeString & iSRRole) = 0;

  /**
   * Tells if a given type has some mandatory filtering
   *
   * This method takes inheritance into account.
   *
   * @param iType
   *   The PLMType for which to set the mandatory semantic relation.
   * @return
   *   S_OK if the type has some mandatory filtering.
   *   S_FALSE if the type has no mandatory filtering
   *   E_* in case of error (like type not found...).
   */
  virtual HRESULT HasSomeSemanticRelationMandatory(
    const CATPLMTypeH & iType) = 0;

  /**
  * Sets the Semantic Relation mode.
  * The mode defines which SR data you want to retrieve.
  * It may be used to improve performances.
  * Existing modes and behavior defined here: SemanticRelationMode (CATPLMQueryFilterEnum.h)
  *
  * @param iMode
  *   The mode to enable.
  *      FullSR:     SRv1 mode. PLMIDs + Synchro status + Data
  *      LightSR:    SRv2 mode. PLMIDs + Data (Synchro status computed on client side)
  *      SlimSR:     SRv3 mode. PLMIDs only
  */
  virtual void SetSemanticRelationMode(SemanticRelation::Mode iMode) = 0;

  /**
  * Checks if the given Semantic Relation mode is enabled.
  * Existing modes and behavior defined here: SemanticRelationMode (CATPLMQueryFilterEnum.h)
  *
  * @param iMode
  *   The Semantic Relation mode to check.
  *
  * @return
  *   TRUE if the iMode is enabled. FALSE otherwise.
  *      FullSR:     SRv1 mode. PLMIDs + Synchro status + Data
  *      LightSR:    SRv2 mode. PLMIDs + Data (Synchro status computed on client side)
  *      SlimSR:     SRv3 mode. PLMIDs only
  */
  virtual CATBoolean IsSemanticRelationMode(SemanticRelation::Mode iMode) = 0;

#endif /* End restricted methods*/

  /**
   * Same as AddFilterSelectCriteria and GetFilterSelectCriteria with CATPLMTypeH.
   */
  virtual HRESULT AddFilterSelectCriteria(const CATPLMTypeH & iType, QueryInfo iQueryInfo, QueryValue iQueryValue) = 0;

  /**
   * Same as GetFilterSelectCriteria with CATPLMTypeH and return by reference.
   *
   * If iWithInheritance is TRUE, the type hierarchy taken into account
   * to find the highest value to use for the type. This is usefull if your are
   * working on query results whose type inherits from the queried ones.
   *
   * @param iType
   *   The PLMType for which to retrieve the info.
   * @param iQueryInfo
   *   The type of query info to retrieve on the given type.
   * @param oQueryValue
   *   The value of the info for the given type.
   * @param iWithInheritance
   *   Set it to TRUE, to use type hierarchy to get the best status.
   * @return
   *   S_OK if the information has been found
   *   S_FALSE if no information has been found (default mode is used, provider dependant)
   *   E_* in case of error.
   */
  virtual HRESULT GetFilterSelectCriteria(const CATPLMTypeH & iType, QueryInfo iQueryInfo, QueryValue & oQueryValue, CATBoolean iWithInheritance) = 0;

  /**
  * @ Deprecated
  */
  virtual HRESULT AddSelectCondition(CATPLMType* ipType, CATString* iAttributeId) = 0;

  /**
  * @ Deprecated
  */
  virtual HRESULT AddExtensionSelectCondition(CATPLMType* ipExtType, CATString* iAttributeId, CATLISTV(CATPLMTypeId)* iRequestedBaseTypes = NULL) = 0;

  /**
  * @ Deprecated
  */
  virtual HRESULT AddExtensionSelectCondition(CATPLMType* ipExtType, CATString* iAttributeId, CATLISTP(CATPLMType)& iRequestedBaseTypes) = 0;

  /**
  * @ Deprecated
  */
  virtual HRESULT AddExtensionSelectCondition(CATPLMType* ipExtType, CATString * iAttributeId, CATPLMTypeList& iRequestedBaseTypes) = 0;

  /**
  * @ Deprecated
  */
  virtual HRESULT AddExtensionOrderBy(CATPLMType * iType, CATString * iAttributeId, CATLISTV(CATPLMTypeId)* iRequestedBaseTypes = NULL, int iDescending = 0) = 0;

  /**
  * @ Deprecated
  */
  virtual HRESULT AddExtensionOrderBy(CATPLMType * iType, CATString * iAttributeId, CATLISTP(CATPLMType)& iRequestedBaseTypes, int iDescending = 0) = 0;

  /**
  * @ Deprecated
  */
  virtual HRESULT AddExtensionOrderBy(CATPLMType * iType, CATString * iAttributeId, CATPLMTypeList& iRequestedBaseTypes, int iDescending = 0) = 0;

  /**
  * @ Deprecated
  */
  virtual HRESULT AddOrderBy(CATPLMType * iType, CATString * iAttributeId, int iDescending = 0) = 0;
};

#endif
