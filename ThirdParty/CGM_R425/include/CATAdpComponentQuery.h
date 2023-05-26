/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
* @level Protected
* @usage U1
*/
#ifndef CATAdpComponentQuery_H
#define CATAdpComponentQuery_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATIAdpErrorMonitor.h"
#include "CATAdpMask.h"
#include "CATLISTP_CATAdpExtendedQueryResult.h"
class CATIAdpPLMIdentificator;
class CATAdpComponentUniqueKey;
class CATAdpComponentsInfos;
class CATAdpComponentInfos;
class CATListPtrCATIAdpPLMIdentificator;
class CATPLMTypeHArray;
class CATPLMTypeH;

/**
* Class enabling to get information about Components.
*
* <br><b>Role</b>: Provides basic behaviors on/about Components.
*/
class ExportedByCATPLMIntegrationAccess CATAdpComponentQuery
{
public:
  CATAdpComponentQuery( CATIAdpErrorMonitor * iErrorMonitor );
  virtual ~CATAdpComponentQuery();

  /** 
  * Search the Unique Key of a Component.
  * <br><b>Role</b>: This method enables to search in the connected Database the Unique Key of a give PLM Component. This Unique Key 
  * represents an identifier enabling to retrieve the Component from the Database later on.
  * <ul>
  * <li><code>E_FAIL</code> is returned if no provider is currently connected.</li>
  * <li><code>ERR_01_QUERY</code> error is available through the given @href CATIAdpErrorMonitor if the given component whose type is V1 has no unique key definition in the metadata.</li>
  * <li><code>ERR_02_QUERY</code> error is available through the given @href CATIAdpErrorMonitor if the given component is not available in the Database.</li>
  * <li><code>ERR_06_QUERY</code> error is available through the given @href CATIAdpErrorMonitor if the given component has no unique key definition in the metadata.</li>
  * </ul>
  *
  * @param iComponentIdentifier [in]
  * The identifier of the object on which user wants to retrieve the Unique Key.
  * <ul>
  * <li><code>E_INVALIDARG</code> is returned if invalid Component is given.</li>
  * <li><code>E_FAIL</code> is returned if the given Component is not yet supported by this API.</li>
  * </ul>
  * @param oUniqueKey [out]
  * The Unique Key of the given Component.
  * @param iUKId [in]
  * A Unique Key identifier if available.
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if search successfully done. The <tt>oUniqueKey</tt> is available.</li>
  *   <li><code>S_FALSE</code> if the given component does not provide any unique key (for V2 types) or identification set (for V1 types).
  *                            In this case, the retrieved key may not ensure a unique matching component in the DB.
  *   <li><code>E_INVALIDARG</code> if input arguments are invalid.</li> 
  *   <li><code>E_FAIL</code> if an error occured. The blocking error can be accessed through @href CATIAdpErrorMonitor.</li> 
  *   </ul>
  */
  HRESULT GetUniqueKey( CATIAdpPLMIdentificator * iComponentIdentifier, CATAdpComponentUniqueKey & oUniqueKey, CATUnicodeString * iUKId=0 );

  /** 
  * Searches in the Database the Components which corresponds to the given Unique Key. Note that for certain types, the uniqueKey may not lead to a unique component in database (see @href GetUniqueKey and @href GetElementsByUniqueKey).
  * <br><b>Role</b>: This method enables to search in the connected Database the Component which has the given Unique Key.
  * <ul>
  * <li><code>E_FAIL</code> is returned if no or more than one provider is currently connected.</li>
  * <li><code>ERR_03_QUERY</code> error is available through the given @href CATIAdpErrorMonitor if no Component was found with the given Unique Key. The Key might be invalid.
  * <li><code>ERR_07_QUERY</code> error is available through the given @href CATIAdpErrorMonitor if more than one Component has the given Unique Key. The Key might be invalid.
  * <li> The service will always query a distant repository irrespective of the fact that the Component is loaded or not in the current 
  * Authoring Session. Since communication to a distant server (net access) is far less efficient than querying the local Session 
  * (local CPU access), a performance degradation is unavoidable, each time this API is called. It is thus strongly recommended not to 
  * use this API if the component is loaded in session, and use it if necessary otherwise.</li>
  * </ul>
  *
  * @param iUniqueKey [in]
  *   The Unique Key of the searched Component
  * <ul>
  * <li><code>E_INVALIDARG</code> return is expected if the given Unique Key is invalid.</li>
  * </ul>
  * @param oComponentIdentifier [out, CATBaseUnknown#Release]
  *   The PLM Identificator of the found Component. It is not loaded in the Authoring Session. Use @href CATAdpProtectedOpener to load it.
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if the Component was found in the Database.</li>
  *   <li><code>E_FAIL</code> if no Component was found given this Unique Key.</li>
  *   <li><code>E_INVALIDARG</code> if the given Unique Key is invalid.</li>
  *   </ul>
  */
  HRESULT GetElementByUniqueKey( const CATAdpComponentUniqueKey & iUniqueKey, CATIAdpPLMIdentificator *& oComponentIdentifier );

  /** 
  * Searches in the Database the Components which corresponds to the given Unique Key. Note that for certain types, the uniqueKey may not lead to a unique component in database (see @GetUniqueKey).
  * <br><b>Role</b>: This method enables to search in the connected Database the Component which has the given Unique Key.
  * <ul>
  * <li><code>E_FAIL</code> is returned if no or more than one provider is currently connected.</li>
  * <li><code>ERR_03_QUERY</code> error is available through the given @href CATIAdpErrorMonitor if no Component was found with the given Unique Key. The Key might be invalid.
  * <li> The service will always query a distant repository irrespective of the fact that the Component is loaded or not in the current 
  * Authoring Session. Since communication to a distant server (net access) is far less efficient than querying the local Session 
  * (local CPU access), a performance degradation is unavoidable, each time this API is called. It is thus strongly recommended not to 
  * use this API if the component is loaded in session, and use it if necessary otherwise.</li>
  * </ul>
  *
  * @param iUniqueKey [in]
  *   The Unique Key of the searched Components
  * <ul>
  * <li><code>E_INVALIDARG</code> return is expected if the given Unique Key is invalid.</li>
  * </ul>
  * @param oRetrievedComponent [out]
  *   Informations on the found components. See @href CATAdpComponentsInfos for details. They are not loaded in the Authoring Session. Use @href CATAdpProtectedOpener to load it.
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if some Components were found in the Database.</li>
  *   <li><code>E_FAIL</code> if no Component was found given this Unique Key or if an error occured.</li>
  *   <li><code>E_INVALIDARG</code> if the given Unique Key is invalid.</li>
  *   </ul>
  */
  HRESULT GetElementsByUniqueKey( const CATAdpComponentUniqueKey & iUniqueKey, CATAdpComponentsInfos & oComponentsInfos); 

  /** 
  * Query on a mask of attributes on a Component. If you need the values for many component, see @href GetMaskValueFromList to reduce the number of client/server calls.
  * <br><b>Role</b>: This method enables to query attributes values in the connected Database on a given PLM Component. Set of 
  * attributes to be read is given by a Mask. The mask is also applied on each avalaible extension.
  * <ul>
  * <li><code>E_FAIL</code> is returned if no provider is currently connected.</li>
  * <li><code>ERR_02_QUERY</code> error is available through the given @href CATIAdpErrorMonitor if the given component is not available in the Database.</li>
  * <li><code>ERR_04_QUERY</code> error is available through the given @href CATIAdpErrorMonitor if there is an invalid mask definition.</li>
  * </ul>
  *
  * @param iComponentIdentifier [in]
  * The identifier of the object on which user wants to query attribute values.
  * <ul>
  * <li><code>E_INVALIDARG</code> is returned if invalid Component is given.</li>
  * <li><code>E_FAIL</code> is returned if the given Component is not yet supported by this API.</li>
  * </ul>
  * @param iMask [in]
  * The mask defining a set of attributes to be read. See @href CATAdpMask to get avalaible mask values.
  * <ul>
  * <li><code>E_INVALIDARG</code> is returned if invalid mask is given.</li>
  * </ul>
  *
  * @param oComponentInfos[out]
  *   A set of attributes corresponding to the main type and extensions as defined by the given mask for the component type. See @href CATAdpComponentInfos for details.
  * <ul>
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if query successfully done. Values are available.</li> 
  *   <li><code>E_INVALIDARG</code> if input arguments are invalid.</li> 
  *   <li><code>E_FAIL</code> if an error occured. The blocking error can be accessed through @href CATIAdpErrorMonitor.</li> 
  *   </ul>
  */
  HRESULT GetMaskValues(CATIAdpPLMIdentificator * iComponentIdentifier, CATAdpMask::MaskValue iMask, CATAdpComponentInfos & oComponentInfos);

  /** 
  * Query on a mask of attributes on a Component.
  * <br><b>Role</b>: This method enables to query attributes values in the connected Database on a given PLM Component. Set of 
  * attributes to be read is given by a Mask. The mask is also applied on each avalaible extension.
  * <ul>
  * <li><code>E_FAIL</code> is returned if no provider is currently connected.</li>
  * <li><code>ERR_02_QUERY</code> error is available through the given @href CATIAdpErrorMonitor if a given component is not available in the Database.</li>
  * </ul>
  *
  * @param iComponentIdentifier [in]
  * The identifier of the object on which user wants to query attribute values.
  * <ul>
  * <li><code>E_INVALIDARG</code> is returned if invalid Component is given.</li>
  * <li><code>E_FAIL</code> is returned if the given Component is not yet supported by this API.</li>
  * </ul>
  * @param iMask [in]
  * The mask defining a set of attributes to be read. See @href CATAdpMask to get avalaible mask values.
  * <ul>
  * <li><code>E_INVALIDARG</code> is returned if invalid mask is given.</li>
  * </ul>
  *
  * @param oComponentInfos[out]
  *   A set of attributes corresponding to the main type and extensions as defined by the given mask for the component type.
  * <ul>
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if query successfully done. Values are available.</li> 
  *   <li><code>E_INVALIDARG</code> if input arguments are invalid.</li> 
  *   <li><code>E_FAIL</code> if an error occured. The blocking error can be accessed through @href CATIAdpErrorMonitor.</li> 
  *   </ul>
  */
  HRESULT GetMaskValuesFromList(const CATListPtrCATIAdpPLMIdentificator & iComponentIdentifiers, CATAdpMask::MaskValue iMask, CATAdpComponentsInfos & oComponentsInfos);

  /** 
  * Set the query to target the persistency repository for next queries.
  * <br><b>Role</b>: This method enables the user to specify that he wants the future queries to be made on persistency repository (M1 or TST). 
  * <ul>
  * <li>If no persistency repository is connected, queries will fail..</li>
  * <li>If the method is not called, behavior is unspecified (!).</li>
  * </ul>
  */
  void TargetM1Repository() { _TargetM1Repository=TRUE; }

private:
  CATAdpComponentQuery( const CATAdpComponentQuery & );
  CATAdpComponentQuery & operator =( const CATAdpComponentQuery & );
  /* version GetMaskValuesFromList sans remontée d'erreur sur le mask si iIgnoreMaskError positionné a TRUE - utilisée par GetDisplayNameFromDataBase */
  HRESULT GetMaskValuesFromList(const CATListPtrCATIAdpPLMIdentificator & iComponentIdentifiers, CATAdpMask::MaskValue iMask, CATAdpComponentsInfos & oComponentsInfos, CATBoolean iIgnoreMaskError);

  HRESULT BuildExtendedQueryFromUniqueKey( const CATAdpComponentUniqueKey & iUniqueKey, CATAdpComponentsInfos & oQueryResults, CATBoolean iWithQueryMask=FALSE );

private:
  CATIAdpErrorMonitor_var _ErrorMonitor;
  CATBoolean _TargetM1Repository; // Initialized to false to keep compatibility with existing odts.
  CATBoolean _IgnoreMaskError;// Initialized to false
  friend class CATAdpProtectedQueryServices;
};
#endif
