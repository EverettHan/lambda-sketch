// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATCkeObjectAttrReadUIServices.h
// Header definition of CATCkeObjectAttrReadUIServices
//
//===================================================================
//
// Usage notes:
// Services dedicated to PLM New UI.
// Provides services to interrogate a PLM Proxy, once it has been valuated by business rules. In order to read the constance and the list of authorized values
// Provides also services to access proxy used in PLM New to pass additional information
// Provides also services to create proxy in the context of PLM New UI
// Provides services to interpret such a proxy (access its extensions, access its attributes, access its type)
//
// Additionaly, it provides access to the fake types (implemented in KML)
// 
//===================================================================



#ifndef CATCkeObjectAttrReadUIServices_H
#define CATCkeObjectAttrReadUIServices_H

// Module export
#include "PLMDictionaryNavServices.h"
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListValCATICkeParm.h"
#include "CATListValCATAttributeInfos.h"
#include "CATCkePLMTypeAttrServices.h"
#include "CATListOfDouble.h"
#include "CATIType.h"

class CATICkeObject_var;
class CATIInstance_var;
class CATIValue_var;
class CATUnicodeString; 
class CATTime;
class CATIAdpEnvironment;
class CATCkePLMNavBusinessLogic;
class CATListValCATIType_var;


/**
 * Services to read sub characteristics of an attribute once they have been modified by business rules.<br>
 * Works on PLM Proxy.<br>
 * Contains also services to enrich PLM Proxy used in PLM New to pass additional information.<br>
 * Services dedicated to PLM New UI.
 * @see CATIValue
 * @see CATIInstance
 * @see CATCkeObjectAttrReadServices
 * @see CATIType
 */
class ExportedByPLMDictionaryNavServices CATCkeObjectAttrReadUIServices
{

  public:

	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
	// SERVICES TO CREATE A PLM PROXY FOR PLM NEW UI
	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

	/**
	 * Creates a PLM Proxy from a type for PLM New UI exclusively
	 * It can be the modeler type, or the discipline if any, or a functional specialization if any in V2. 
	 * It can be a modeler or a discipline in V1.<br>
	 * The type can be a secondary type (functional specialization or discipline a posteriori). In this case, we create the extended object and then we add the extension.
	 * The type in input cannot be a custo type
	 * @param iType
	 * The type
	 * @param ipiEnv
	 * The environment. Usually null(interpreted as “current environment”)
	 * @param oInstance
	 * PLM proxy created in output
	 * @param pIResultOfBusinessLogic
	 * If deployment extension business logic has been computed before, this is the way to pass the information
 	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type in input is NULL , or type is a custo type
	 * 	 <li> S_OK	if the object has been created sucessfuly
	 * 	 <li> E_FAIL otherwise
	 *  </ol>
     */		
	static HRESULT CreatePLMProxyForPLMNew (	const CATIType_var			&iType, 
												const CATIAdpEnvironment	*ipiEnv,
												CATIInstance_var			&oProxyCreated,
												CATCkePLMNavBusinessLogic	*pIResultOfBusinessLogic = NULL
												);

	   
	/**
	 * This service tests if a given type can be created by PLM New UI.
	 * We can pass a modeler, discipline or functional specialization type in input.
	 * This service tests if the type 
	 * - is not abstract
	 * - is declared as newable in the dictionary
	 * - if the corresponding license is available
	 * - if the security authorizes the creation
	 * Note that this service had a different behavior at DS-BSF and in a packaged environment
	 * @param iType
     * Type in input. Modeler, Discipline or even functional specialization type.
	 * @param ipiEnv	 
	 * The environment. Usually null(interpreted as “current environment”)
	 * @param oAvailable
	 * Indicates if the creation is available or not
	 *  <ol>  
	 *  	 <li> TRUE if the type can be created
	 *  	 <li> FALSE if the type cannot be created
	 *  </ol>
	 * @param oMessage
	 * Message to be returned to the end-user (license not available, security, ...)
	 *   @param iCid 
	 *      The name of the type package owner (customer-id, partner-id,"") of the type. 
	 *      (must be provided as a non null string for non DS type)
     * @param iTestNewableProperty
 	 * requires that the newable property is set with Newable or insertable
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is NULL
	 * 	 <li> S_OK instead
	 *  </ol>
	*/
 	static HRESULT CanBeCreatedFromUI (	const CATIType_var			&iType,
										const CATIAdpEnvironment	*ipiEnv,
										CATBoolean					&oAvailable,
  										CATUnicodeString			&oMessage,
										const char					*iCid=NULL,
										CATBoolean					iTestLicense = TRUE,
										const CATBoolean			iTestNewableProperty = FALSE);


    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
	// SERVICES TO INTROSPECT A PROXY USED FOR PLM NEW UI
	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
	
	/**
	 * Returns the type of an object in order to show it in the UI.<br>
	 * DO NOT USE THIS SERVICE TO DEDUCE ANYTHING ABOUT THE OBJECT.
	 * For V1 objects, it returns custo type (or modeler if no custo).<br>
	 * For V2 objects, it returns the primary type of the object (either functional specialization or discipline or modeler).<br>
	 * @param iObject
	 * object in input. A PLM object.
	 * @param oTypeToShowInUI
	 * type to show in user interface
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object in input is NULL.
	 * 	 <li> S_OK	if the type has been retrieved.
	 *  </ol>
         */

	static HRESULT GetObjectTypeToPresentInUI	(const CATICkeObject_var &iObject,
												 CATIType_var      &oTypeToShowInUI);
	
	/**
	 * Lists the applicative extensions to show in Edit properties (to produce the different tabs)
	 * Fills the given list with types supported by this instance that correspond to applicative extensions.
	 * It also adds the customer extensions.
	 * But it does not show deployment extensions, since that mustn't be perceived as such
	 * @param iolListOfCATIType the filled list.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object in input is NULL.
	 * 	 <li> S_OK	if the type has been retrieved.
	 *  </ol>
	 */
	static  HRESULT ListApplicativeExtensionTypesForUI(	const CATICkeObject_var &iObject,
														CATListValCATIType_var& iolListOfCATIType ) ;

	
	/**
	 * Decomposes an object in its list of types. Should be used only by Spreadsheet editor.
	 * @param iObject the object
	 * @param oPhysicalType the main type of the object
	 * @param oDeploymentExtensionType the deployment extension type
	 * @param oListOfApplicativeTypes the list of applicative types
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object in input is NULL.
	 * 	 <li> S_OK	instead
	 *  </ol>
	 */
	static  HRESULT DecomposeObjectTypesForUI (	const CATICkeObject_var &iObject,
												CATIType_var &oPhysicalType,
												CATIType_var &oDeploymentExtensionType,
												CATListValCATIType_var& oListOfApplicativeTypes ) ;

    /**
	 * Starting from an object and the name of an attribute, finds the attribute and the PLM Type from which it comes from.<br>
	 * It scans the PLMTypes implemented by the object to find the attribute on the type
	 * @param iAttributeName
 	 * Name of the attribute
	 * @param iObject
	 * object in input
	 * @param oAttributeInfos
	 * attribute found in output. oAttributeInfos is allocated and must be deleted
	 * @param oType
	 * oType is valuated and contains the type that owns the attribute. Note that it is not the precise type (the exact type that contains the attribute). It is the type that may have the attribute due to inheritance
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the attribute is not found
	 * 	 <li> S_FALSE if the two lists are incompatible
	 * 	 <li> S_OK	if the list of authorized values has been filled succesfully.
	 *  </ol>
     */
	static HRESULT LocateAttributeAndTypeFromNameAndObject (const CATUnicodeString &iAttributeName,const CATICkeObject_var &iObject,CATAttributeInfos*& oAttributeInfos,CATIType_var &oType);

	/**
	 * From the types obtained from ListApplicativeExtensionTypesForUI, we may want to filter attributes by mask. 
	 * The type can be any type finally
  	 * @param iType
	 * The type
	 * @param iPLMMaskCriteria
     *   Filtering PLM Mask criteria to apply
     * @param oListFilteredAttr
     *   The list of PLM attributes obtained. It is filled by the service.
     *   The service removes elements of the list in input first.
     * @return
     *  <ol>
     * 	 <li> E_INVALIDARG if the input PLM type is invalid
     * 	 <li> E_FAIL if failure
     * 	 <li> S_OK if the list of attributes is valuated (even if empty)
     *  </ol>
     */
    static HRESULT ListFilteredAttributesFromMaskAndTypeForUI (const CATIType_var &iType, 
														       const  CATCkePLMTypeAttrServices::PLMMaskCriteria iPLMMaskCriteria,
												               CATListValCATAttributeInfos &oListFilteredAttr);
 



	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
	// SERVICES TO ACCESS ATTRIBUTES ON A PROXY, AFTER ITS MODIFICATION BY A BUSINESS RULE
	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

	/**
	 * Reads constance of an attribute. If constant, the editor must be grayed out.<br>
	 * Equivalent of reading the value of the attribute and call GetConst on CATIValue.<br>
	 * @param iObject
 	 * Knowledge object on which we want to read its constance.
	 * @param iKey
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param oIsConst
	 * Const/Non const status of the attribute
	 *  <ol>
	 * 	 <li> TRUE if the attribute is constant.
	 * 	 <li> FALSE if the attribute is not constant.
	 *  </ol>
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the read operation has failed (attribute non existing on object).
	 * 	 <li> S_OK	if the attribute has been accessed successfully.
	 *  </ol>
     */
	static HRESULT IsConst				(const CATICkeObject_var &iObject,
										 const CATUnicodeString& iAttributeName,
										 CATBoolean     &oIsConst) ;

	/**
	 * Reads list of authorized values for a string attribute on a PLM Proxy. If there is a list, a combo must be proposed to the end user.<br>
	 * This service only scans the local information stored on the attribute. It is filled either because a business rules has defined some or because it was defined on the default value in the dictionary.<br>
	 * Dictionary contains list of authorized values for Strings defined with a range
	 * @param iObject
 	 * Knowledge object on which we want to read its authorized values.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param oAuthorizedValues
	 * List filled by this service. An empty list means no authorized values. The service empties the list.
	 * @param opAuthorizedValuesNLS
	 * List filled by this service. An empty list means no authorized values. The service empties the list. It contains the NLS translation to be presented in the combo
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the read operation has failed (attribute non existing on object).
	 * 	 <li> S_FALSE if no authorized values defined.
	 * 	 <li> S_OK	if the attribute has been accessed successfully.
	 *  </ol>
     */
	static HRESULT GetAuthorizedValues	(const CATICkeObject_var &iObject,
										 const CATUnicodeString& iAttributeName,
										 CATListOfCATUnicodeString     &oAuthorizedValues,
										 CATListOfCATUnicodeString     *opAuthorizedValuesNLS = NULL ) ;
	
	/**
	 * Reads list of authorized values for a string attribute on an object. If there is a list, a combo must be proposed to the end user.<br>
	 * This service concatenates the information local to the attribute (previous service) and informations coming from the mask. It intersects the two lists.<br>
	 * Dictionary contains list of authorized values for Strings defined with a range
	 * @param iObject
 	 * Knowledge object on which we want to read its authorized values.
	 * @param iKweType
	 * Type of the object that we want to filter with the mask if secondary type. Not usefull to set this information for main type
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param iPLMMaskCriteria
	 * Mask that we want to consider
	 * @param oAuthorizedValues
	 * List filled by this service. The service empties the list. An empty list may mean two things. Either there is no authorized values defined (HRESULT=S_OK) or there is a conflict between what is defined in the mask and on the value.<br>
	 * @param opAuthorizedValuesNLS
	 * List filled by this service. An empty list means no authorized values. The service empties the list. It contains the NLS translation to be presented in the combo
	 * A conflict means that the intersection is NULL. It is identified with a HRESULT=S_FALSE
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the read operation has failed (attribute non existing on object).
	 * 	 <li> S_FALSE if the two lists are incompatible
	 * 	 <li> S_OK	if the list of authorized values has been filled succesfully.
	 *  </ol> 
     */
	static HRESULT GetAuthorizedValuesWithMasks	(const CATICkeObject_var &iObject,
												const CATUnicodeString& iAttributeName,
												const CATIType_var& iKweType,
												const CATCkePLMTypeAttrServices::PLMMaskCriteria iPLMMaskCriteria,
												CATListOfCATUnicodeString     &oAuthorizedValues,
												CATListOfCATUnicodeString     *opAuthorizedValuesNLS = NULL) ;

	/**
	 * Reads list of authorized values for an attribute (integer, real, date, dimensioned or enum) on a PLM Proxy. If there is a list, a combo must be proposed to the end user.<br>
	 * This service only scans the local information stored on the attribute. It is filled either because a business rules has defined some or because it was defined on the default value in the dictionary.<br>
	 * Dictionary contains list of authorized values for enum, or for int/real/dimensions defined with a range
	 * @param iObject
 	 * Knowledge object on which we want to read its authorized values.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param oAuthorizedValues
	 * List filled by this service. An empty list means no authorized values. The service empties the list.
	 * @param opAuthorizedValuesNLS
	 * List filled by this service. An empty list means no authorized values. The service empties the list. It contains the NLS translation to be presented in the combo
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the read operation has failed (attribute non existing on object).
	 * 	 <li> S_FALSE if no authorized values defined.
	 * 	 <li> S_OK	if the attribute has been accessed successfully.
	 *  </ol>
     */
	static HRESULT GetAuthorizedValuesAsDouble	(const CATICkeObject_var &iObject,
												 const CATUnicodeString& iAttributeName,
												 CATListOfDouble     &oAuthorizedValues ,
												 CATListOfCATUnicodeString     *opAuthorizedValuesNLS = NULL) ;
	
	/**
	 * Reads list of authorized values for an attribute (integer, real, date, dimensioned or enum) on an object. If there is a list, a combo must be proposed to the end user.<br>
	 * This service concatenates the information local to the attribute (previous service) and informations coming from the mask. It intersects the two lists.<br>
	 * Dictionary contains list of authorized values for enum, or for int/real/dimensions defined with a range
	 * @param iObject
 	 * Knowledge object on which we want to read its authorized values.
	 * @param iKweType
	 * Type of the object that we want to filter with the mask
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param iPLMMaskCriteria
	 * Mask that we want to consider
	 * @param oAuthorizedValues
	 * List filled by this service. The service empties the list. An empty list may mean two things. Either there is no authorized values defined (HRESULT=S_OK) or there is a conflict between what is defined in the mask and on the value.<br>
	 * @param opAuthorizedValuesNLS
	 * List filled by this service. An empty list means no authorized values. The service empties the list. It contains the NLS translation to be presented in the combo
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the read operation has failed (attribute non existing on object).
	 * 	 <li> S_FALSE if the two lists are incompatible
	 * 	 <li> S_OK	if the list of authorized values has been filled succesfully.
	 *  </ol>
     */
	static HRESULT GetAuthorizedValuesWithMasksAsDouble	(	const CATICkeObject_var &iObject,
															const CATUnicodeString& iAttributeName,
															const CATIType_var& iKweType,
															const CATCkePLMTypeAttrServices::PLMMaskCriteria iPLMMaskCriteria,
															CATListOfDouble     &oAuthorizedValues,
															CATListOfCATUnicodeString     *opAuthorizedValuesNLS = NULL) ;



	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
	// SERVICES TO ENRICH A PROXY USED FOR PLM NEW UI WITH INFORMATION, THAT CAN BE RETRIEVED BY THE FACTORY AFTERWARDS
	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
	
	/**
	 * Adds a dynamic attribute on a PLM Proxy.<br>
	 * This attribute is not persistent. It is used to communicate an information from the application (implementing PLM New) to the modeler code.
	 * @param iProxy
	 * Proxy
	 * @param iAttributeName
	 * Name of the attribute. We recommend to prefix it to avoid conflicts
	 * @param iAttributeType
	 * Type of the attribute
	 * @param iAttributeValue
	 * Value of the attribute	 
	 * @return
	 *  <ol>
	 * 	 <li> E_FAIL if proxy or type or value is NULL (or iProxy is not a proxy)
	 * 	 <li> E_INVALIDARG if an attribute already exist with the same name
	 * 	 <li> S_OK	if succesful
	 *  </ol>
 
	 */
	static HRESULT AddDynamicAttributeOnProxy  (const CATIInstance_var &iProxy,
												const CATUnicodeString &iAttributeName,
												const CATIType_var	   &iAttributeType,
												const CATIValue_var	   &iAttributeValue);
	/**
	 * Accesses a dynamic attribute on a PLM Proxy.<br>
	 * This attribute is not persistent. It is used to communicate an information from the application (implementing PLM New) to the modeler code.
	 * @param iProxy
	 * Proxy
	 * @param iAttributeName
	 * Name of the attribute. We recommend to prefix it to avoid conflicts
	 * @param oAttributeValue
	 * Value of the attribute in output.	 
	 * @return
	 *  <ol>
	 * 	 <li> E_FAIL if proxy  or value is NULL (or iProxy is not a proxy)
	 * 	 <li> E_INVALIDARG if attribute didn't exist
	 * 	 <li> S_OK	if succesful
	 *  </ol>
 
	 */
	static HRESULT GetDynamicAttributeOnProxy  (const CATIInstance_var &iProxy,
													const CATUnicodeString &iAttributeName,
													CATIValue_var	   &oAttributeValue);
	/**
	 * Valuates a dynamic attribute on a PLM Proxy.<br>
	 * This attribute is not persistent. It is used to communicate an information from the application (implementing PLM New) to the modeler code.
	 * @param iProxy
	 * Proxy
	 * @param iAttributeName
	 * Name of the attribute. We recommend to prefix it to avoid conflicts
	 * @param iAttributeValue
	 * Value of the attribute	 
	 * @return
	 *  <ol>
	 * 	 <li> E_FAIL if proxy  or value is NULL (or iProxy is not a proxy)
	 * 	 <li> E_INVALIDARG if attribute didn't exist
	 * 	 <li> S_OK	if succesful
	 *  </ol>
 
	 */
	static HRESULT ValuateDynamicAttributeOnProxy  (const CATIInstance_var &iProxy,
													const CATUnicodeString &iAttributeName,
													const CATIValue_var	   &iAttributeValue);
	
	/**
	 * Lists dynamic attributes existing on proxy.<br>
	 * These attribute are not persistent. They are used to communicate an information from the application (implementing PLM New) to the modeler code.
	 * @param iProxy
	 * Proxy
	 * @param oList
	 * List of attribute values: the name of the parameter is the name of the attribute
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if proxy  is NULL (or iProxy is not a proxy)
	 * 	 <li> S_OK	if succesful
	 *  </ol>
 	 */
	static HRESULT ListDynamicAttributeOnProxy  (const CATIInstance_var &iProxy,CATLISTV(CATICkeParm_var) &oList);



	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
	// SERVICES FOR PLM NEW UI TO MANAGE KML BASED TYPES
	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

	/**
	 * This services reads the KML types that can be used in PLM New. The
	 * types are found in the runtime view, in $CATKnowledgePath and the
	 * files that are to be suffixed with ".plmnewtype" extension.
	 * They are added to the Knowledge Dictionary and every call to this
	 * service should be followed by a call to ResetPLMNewKMLTypes in order
	 * to avoid that they remain in the dictionary, once they are not needed
	 * anymore.
	 * @param oFoundTypes: a list of types that can be used in PLM New
	 * @return
	 *   <ol>
	 * 	 <li> S_OK if all types that were found in the runtime view were succesfully parsed
	 * 	 <li> S_FALSE if some types were parsed, but some other failed
	 * 	 <li> E_FAIL not type was added to the dictionary because none was found or succesfully parsed
	 *  </ol>
	 */
	static HRESULT InitializePLMNewKMLTypes(CATListValCATIType_var &oFoundTypes);

	/**
	 * This services removes from the Knowledge dictionary all the types that were
	 * added through InitialitePLMNewKMLTypes. These types are not to be used
	 * in any other context than PLM New and therefore MUST be removed from dictionary
	 * right afther usage.
	 * @return
	 *  <ol>
	 * 	 <li> S_OK if all types were succesfully remove from Knowledge Dictionary
	 * 	 <li> E_FAIL otherwise (should never happen...)
	 *  </ol>
	 */
	static HRESULT ResetPLMNewKMLTypes();


private:
	static CATLISTV(CATBaseUnknown_var) _PLMNewLibrariesToFlush;
};

//-----------------------------------------------------------------------

#endif
