// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATAdpOpenSaveServices.h
// Header definition of CATAdpOpenSaveServices
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  May 2005  Creation: Code generated by the CAA wizard  PMM
//===================================================================
/**
* @level Protected
* @usage U1
*/
#ifndef CATAdpProtectedQueryServices_H
#define CATAdpProtectedQueryServices_H

#include "CATPLMIntegrationAccess.h"

#include "IUnknown.h"
#include "CATCollec.h"
#include "CATPLMIDCollections.h"

class CATLISTP(CATAdpQueryResult);
class CATIAdpType;
class CATPLMTypeH;
class CATUnicodeString;
class CATLISTP(CATAdpBasicQueryResult);
class CATIAdpPLMIdentificator;
class CATAdpIdentifierSet;
class CATAdpAttributeSet;
class CATIAdpErrorMonitor;
class CATListPtrCATIAdpPLMIdentificator;
class CATLISTP(CATAdpQueryResult);

#include "CATString.h"

//-----------------------------------------------------------------------

/**
* Class to manage Query PLM data from CATIA session.
*
* <br><b>Role</b>: Provides all basic functions to query PLM data.
*/
class ExportedByCATPLMIntegrationAccess CATAdpProtectedQueryServices
{

public:
  /**
  * @deprecated V6R2013
  * @nodoc
  */
  static HRESULT FindNamedElements(CATIAdpType * iType, const CATUnicodeString & iSearchKey,
    CATLISTP(CATAdpBasicQueryResult)& oQueryResults, CATIAdpErrorMonitor * iopErrorMonitor = NULL);

  /**
   * DO NOT USE
   * Performs unsensitive case query up to V6R2020x release thus results in very poor performances on cloud and premise servers which are set to case sensitive by default.
   * From V6R2021x , queries are case sensitive.
   * @deprecated V6R419
   * @use CATAdpExtendedQueryServices#GetElementsFromQueryFilter
   */
  static HRESULT FindNamedElements(const CATPLMTypeH & iType, const CATUnicodeString & iSearchKey,
    CATLISTP(CATAdpBasicQueryResult)& oQueryResults, CATIAdpErrorMonitor * iopErrorMonitor = NULL);

  /**
   * @deprecated R421
   * @use CATAdpProtectedQueryServices#FindNotInstanciatedReferences
   * No safe implementation can be made for this service. It will result in poor performances and possibly will crash the server when the database becomes too big (Cloud database for example).
   * If such a service is needed, the application must be re-designed to avoid this need.
  */
  static HRESULT GetRoots(const CATString & iModeler, CATLISTP(CATAdpBasicQueryResult)& oRoots);

 /**
  * Search in the database if the given references are instancianted 
  *
  * <br><b>Role</b>: Given a set of PLMReferences, this service performs queries in the database to determine if it is instanciated or not.
  * <ul>
  * <li> This service only works for IRPC PLMReferences. Components from other PLM types are ignored</li>
  * <li> This service can only retrieve the information depending on the P&O of the connected user</li>
  * <li> If some references can be instanciated by instances which are not visible for the connected user, it won't be taken into account and the reference will be seen as not instanciated</li>
  * </ul>
  *
  * @param iReferences [in]
  *   The given references.
  * @param iErrorMonitor [in]
  *   Error management
  * @param oResult [out]
  *   The references which are not seen as instanciated for the connected user.
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> success</li>
  *   <li><code>E_XXX</code> failure</li>
  *   </ul>
  *
  */
  static HRESULT FindNotInstanciatedReferences(const CATPLMIDOSet & iReferences, CATIAdpErrorMonitor * iErrorMonitor, CATPLMIDOSet & oResult);

  /**
  * Retrieves in the specified repository the object corresponding to the URL provided.
  *
  * <br><b>Role</b>: This method retrieves in the specified repository, the unique object responding
  * to the criteria defined by the identification set included in the URL.
  * <ul>
  * <li> If no repository is specified, the query will result in a E_ INVALIDARG return.</li>
  * </ul>
  *
  * @param iRepository [in]
  *   The repository name.
  * @param iURL [in]
  *   The parameters enabling the repository to retreive the encoded identifier.
  *   The URL format for automatic connection of the provider is like this pattern :
  *      repoName://UserName:Password@server:port/rootURI/providerIdentifier?CnxParam1=CnxVal1&CnxParam2=CnxVal2
  *      All elements will be mapped to the appropriate ConnectionParameter.
  *      The repoName, server and providerIdentifier are mandatory.
  *      The UserName/Password/port/rootURI are optional.
  *      All CnxParam will be processed at the end, so they will override values if needed (even server).
  *      You can use %xx to encode speicifc characters (%2f and %3f will be changed to '/' and '?' for example).
  *   The URL is UTF-8 encoded.
  * @param oComponentIdentifier [out]
  *   The PLM identificator corresponding to the retrived object in the repository. The component is not loaded in memory
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if the component was found in the database.</li>
  *   <li><code>E_FAIL</code> if the component was not found.</li>
  *   <li><code>E_INVALIDARG</code> if the provided <tt>iRepository</tt> is invalid.</li>
  *   </ul>
  *
  */
  static HRESULT GetPLMIDFromURL(const char * iRepository, const CATUnicodeString & iURL, CATIAdpPLMIdentificator *& oComponentIdentifier);

  /**
  * Retrieve all the Parents of a given Reference in the connected database.
  *
  * <br><b>Role</b>: This method searches in database for PLMCoreReference,
  * - of any modeler, or
  * - of a given PLM modeler (domain), or
  * - of a given PLM Modeler customization (business domain),
  * for parent references (aggregating instances) of a given PLMCoreReference.
  *
  * @param iSon [in]
  *   A PLMCoreReference son of the parents to retreive.
  *   The coresponding components are not loaded in memory.
  *
  * @param oParents [out]
  *   Returned list of all the direct parents.
  *   Provided List must be empty. No attribute available on those results.
  *   The coresponding components are not loaded in memory.
  *   Elements CATAdpBasicQueryResult of the returned list have to be deleted.
  *   The same parent reference will be returned MULTIPLE TIMES, if iSon is instanciated multiple times under the same parent.
  *
  * @param iModeler [in]
  *   The modeler in which the parents are to be searched.
  *   Can be left blank to deal with any modeler.
  *   Can be left blank only if the iCustoModeler is also blank.
  *
  * @param iCustoModeler [in]
  *   Useless. Cannot be used anymore.
  *
  * @return
  *   <code>S_OK</code>: Search successfully done.
  *   <code>E_FAIL</code>: Error during query.
  *   <code>E_INVALIDARG</code>: Invalid input Parameters -
  *                              If the input Object is an invalid Reference.
  *                              Provided Return List is not empty.
  *
  */
  static HRESULT GetParentsThroughInstances(CATIAdpPLMIdentificator* iSon, CATLISTP(CATAdpQueryResult)& oParents, const CATString iModeler = "", const CATString iCustoModeler = "");

  /**
  * Retrieve all the Parents of a given RepReference plus all instance which are instance of the RepReference in the connected database.
  *
  * <br><b>Role</b>: This method searches in database for PLMCoreRepReference and PLMCoreRepInstance,
  * - of any modeler, or
  * - of a given PLM modeler (domain), or
  * - of a given PLM Modeler customization (business domain),
  * for parent references (aggregating instances) of a given PLMCoreReference.
  *
  * @param iSon [in]
  *   A PLMCoreRepReference son of the parents to retreive.
  *   The coresponding components are not loaded in memory.
  *
  * @param oParents [out]
  *   Returned list of all the direct parents.
  *   Provided List must be empty. No attribute available on those results.
  *   The coresponding components are not loaded in memory.
  *   Elements CATAdpBasicQueryResult of the returned list have to be deleted.
  *   The same parent reference will be returned MULTIPLE TIMES, if iSon is instanciated multiple times under the same parent.
  *
  * @param iModeler [in]
  *   The modeler in which the parents are to be searched.
  *   Can be left blank to deal with any modeler.
  *   Can be left blank only if the iCustoModeler is also blank.
  *
  * @param iCustoModeler [in]
  *   Useless. Cannot be used anymore.
  *
  * @return
  *   <code>S_OK</code>: Search successfully done.
  *   <code>E_FAIL</code>: Error during query.
  *   <code>E_INVALIDARG</code>: Invalid input Parameters (ex : not a rep reference) -
  *                              If the input Object is an invalid Reference.
  *                              Provided Return List is not empty.
  *
  */
  static HRESULT GetParentsWithInstancesFromRepRef(CATIAdpPLMIdentificator* iSon, CATLISTP(CATAdpQueryResult)& oParents, const CATString iModeler = "", const CATString iCustoModeler = "");
  /** @nodoc */ //to be withdrawn soon
  static HRESULT GetParentsThroughInstances(const CATString& iCustoModeler, const CATString& iModeler,
    CATIAdpPLMIdentificator* iSon, CATLISTP(CATAdpQueryResult)& oParents);


  /**
  * @deprecated V6R2013
  * @use CATAdpComponentQuery#GetElementUniqueKey
  * @use CATAdpExtendedQueryServices
  */
  static HRESULT GetElementByIdentifierSet(CATIAdpType * iType, const CATAdpIdentifierSet & iIdentifierSet,
    CATIAdpPLMIdentificator *& oComponentIdentifier);

  /**
  * @deprecated V6R2013
  * @use CATAdpComponentQuery#GetUniqueKey
  */
  static HRESULT GetIdentifierSet(CATIAdpPLMIdentificator * iComponentIdentifier, CATAdpIdentifierSet & oIdentifyingSet, CATIAdpErrorMonitor * iopErrorMonitor = NULL);
  /**
  * Gets the display name of the provided components from the database.
  * Most of the time, the display name is a composition between several attributes of the component.
  *
  * <br><b>Role</b>: This method is made to retrieve the display name of a component from the database.
  * <ul>
  * <li>This method systematically triggers a query on the database. The display name won't be retrieved from the authoring session
  * through @href CATIAlias, even if the component is loaded in the authoring session.</li>
  * <li>The protocol used to determine the attributes defining the display name is not available yet. Thus, temporarily, the attributes
  * used will be the ones defining the @href CATAdpIdentifierSet.</li>
  * <li>The display name will be created from the attributes separated by a blank.</li>
  * <li><code>ERR_03_QUERY</code> error is available through the provided @href CATIAdpErrorMonitor if the display name is not defined for the component.</li>
  * </ul>
  *
  * @param iComponents [in]
  *   The identifiers of the objects on which user wants to retrieve the display name.
  *   An empty list results in a <code>E_INVALIDARG</code> return.
  * @param oQueryResults [out]
  *   The retrieved display name.
  * <ul>
  * <li>It will be available in the @href CATAdpAttributeSet exposed by the @href CATAdpQueryResult.</li>
  * <li>It will be available in the @href CATAdpAttributeSet through attribute identifier <code>DISPLAYNAME</code>.</li>
  * <li>The display name is calculated with attributes values separated with blanks (for example <code>ExternalID ---</code>).</li>
  * </ul>
  * @param iopErrorMonitor [inout]
  *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.
  *   a NULL value results in a <code>E_INVALIDARG</code> return.
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if the display name could be retrieved.</li>
  *   <li><code>E_INVALIDARG</code> if input arguments are invalid.</li>
  *   <li><code>E_FAIL</code> if an error occured. The blocking error can be accessed through @href CATIAdpErrorMonitor.</li>
  *   </ul>
  *
  */
  static HRESULT GetDisplayNameFromDataBase(const CATListPtrCATIAdpPLMIdentificator & iComponents,
    CATLISTP(CATAdpQueryResult)& oQueryResults,
    CATIAdpErrorMonitor * iopErrorMonitor);


  /**
  * Retrieves all the representation references from a PLM reference object.
  *
  * <br><b>Role</b>: This method retrieves PLM identicators of all representations associated to a PLMCoreReference object.
  * Lists should be empty when calling this method otherwise this method returns <tt>E_INVALIDARG</tt>.
  *
  * @param iReference  [in]
  *   The reference object on which user wants to retrieve all representations.
  * @param oRepresentations [out]
  *   The list of representations of the reference, all elements of this list should be released.
  *
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt>: Search successfully done. </li>
  *   <li><tt>E_INVALIDARG</tt>: if input arguments are not corrects (NULL or not Empty List or not a CoreReference)</li>
  *   <li><tt>E_FAIL</tt>: Error during query</li>
  *  </ul>
  *
  */
  static HRESULT GetRepresentationsFromReference(CATBaseUnknown * iReference,
    CATListPtrCATIAdpPLMIdentificator & oRepresentations);

  /**
  * @deprecated V6R2013
  * @nodoc
  */
  static HRESULT GetElementsFromAttributes(CATIAdpType * iType, const CATAdpAttributeSet & iAttributeSet,
    CATLISTP(CATAdpQueryResult) & oQueryResults);

  /**
  * DO NOT USE
  * Performs unsensitive case query thus results in very poor performances on cloud and premise servers which are set to case sensitive by default.
  * @deprecated V6R419
  * @use CATAdpExtendedQueryServices#GetElementsFromQueryFilter
  */
  static HRESULT GetElementsFromAttributes(const CATPLMTypeH & iType, const CATAdpAttributeSet & iAttributeSet,
    CATLISTP(CATAdpQueryResult) & oQueryResults);

  private:
    static void CATAdpProtectedQueryServices_GetRoots_use(const CATString & input);
    static void CATAdpProtectedQueryServices_GetRoots_M1_use();
};
#endif
