// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATCkePLMNavServices.h
// Header definition of CATCkePLMNavServices
//
//===================================================================
//
// Usage notes:
// Provides services for UI navigation layer based on new typing system.
// The objective of those services is to provide a stable view between V1 (current typing system) and V2 (target typing system)
//
//===================================================================



#ifndef CATCkePLMNavServices_H 
#define CATCkePLMNavServices_H 

// Module export
#include "PLMDictionaryNavServices.h"
#include "CATCkePLMNavPublicServices.h"
#include "CATBoolean.h"
#include "CATListValCATICkeParm.h"
#include "CATCkePLMTypeAttrServices.h"
#include "CATPLMCoreType.h"
#include "CATListValCATIType.h"
#include "CATListOfCATUnicodeString.h"
#include "CATICkeObject.h"
#include "CATIType.h"

#include <functional>

class CATIType_var;
class CATUnicodeString;
class CATIInstance_var;


class CATIAdpEnvironment; 
class CATIAdpType;
class CATIPLMComponent_var;
class CATBRExtraParameters;


/**
* Services used by navigation UI to manipulate objects, attributes, and types.<br> 
* These services have a different implementation in V1 (current typing system) and V2 (target typing system). But their objective is to provide a service that can be used by applications in order to 
* protect them from the switch from V1 to V2. Note that SOME SERVICES are usable only in V2. So it does not allow a smooth transition.
*
* What about custo types (CATIAdpEnvironment::GetAuthoringType) ?
* ---------------------------------------------------------------
* In the previous typing system, to create an object of a given top modeler type, applications were <br> 
* 1) starting from their modeler type (more precisely, from the doublet: MetadataName + CoreType) <br>
* 2) then they retrieved the corresponding custo type from the environment using CATIAdpEnvironment::GetAuthoringType (using the MetadataName+CoreType) <br>
* 3) finally, calling PLM Core APIs for creating the object by passing this authoring type.<br>
* Inside PLM Core modeler API, it works because the Custo type inherits from the modeler type.
* <br>
* In the new typing system, we want to completely mask the notion of custo type (that we call deployment type). In fact, this notion still exists and is retrieved automatically from the CATIAdpEnvironment <br>
* But this type is no more the primary type of the object. As a consequence, it is not the one that should be passed to PLMCore factories.<br> 
* The services that we propose here, take in input the CATIAdpEnvironment and the primary type that corresponds to the type we want to create. <br>
* Internally, it will add the custo type on the object.<br>
*
* What about disciplines ?
* ------------------------
* In previous typing system, applications were tagging objects with a V_Discipline attribute that corresponds to a sort of type.<br>
* As a consequence, to create an object, they first created the object, then assigned the V_Discipline attribute to precise the "applicative type".
* In the new typing system , we want to integrate disciplines as types inheriting from the modeler types. And the new PLM Core API need to take this discipline type as an argument, 
* in order to create the object of the right type.
*
* What about functional specialization ?
* --------------------------------------
* Functional specialization does not exist in previous typing system. In the new one, in the future, the customer will be able to specialize some modeler types. 
* In the PLM New of a modeler type, the end user will be able to select a sub type (functional specialization). As a consequence, the new PLM Core API need to take this type as argument.
* <br>
* * What is the primary type of an object ?
* --------------------------------------
* The primary type of the object, is the type given at its creation: the modeler type or the discipline (if any) or the functional specialization if any.<br>
* From an object, it can be retrieved with CATCkeObjectTypeAccessServices::GetPrimaryType
*
* Consequence: what all services have in common:
* ----------------------------------------------
* As a consequence, all services have a Knowledge type as input. This Knowledge type, depending on the cases, will be either the modeler type, the discipline type (if any) and potentially the 
* functional specialization (coming from the PLM New)
* The service will create the right object in memory (and afterwards in database).
* This API will have the same behavior in V1 and in V2. In V2, the PLM New will be modified to produce a functional specialization type if any.
* Both in V1 and V2, the application can retrieve the modeler type (or the discipline) and call the PLM Core API.
* To retrieve the Knowledge type or the discipline one, applications code will start from a string that corresponds to the modeler type name or the discipline name (as defined in PLM Metadata).<br>
* To retrieve a CATIType from this string, it is recommended to use CATCkeTypeServices::RetrieveKnowledgeType.
* 
* How to debug those services if you don't have the source code....
* -----------------------------------------------------------------
* Please activate CKE_NEWTYPING_TRACES=1 and you will get messages of what is happening and success
* For each method, the cases of failures are documented
*
* @see CATCkePLMNavPublicServices, CATIType, CATAttributeInfos, CATIInstance, CATCkeObjectTypeAccessProtectedServices, CATCkeObjectAttrReadServices, CATCkeObjectAttrWriteServices, CATCkeTypeProtectedServices, 
*/
class ExportedByPLMDictionaryNavServices CATCkePLMNavServices : public CATCkePLMNavPublicServices
{

public:

	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	// SERVICES FOR CREATING PROXY OR INITIALIZING PROXIES
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------

	/**
	* Creates a PLM Proxy from a type. It can be the modeler type, or the discipline if any, or a functional specialization if any in V2. It can be a modeler or a discipline in V1.<br>
	* This method is introduced as an alternative to CATIBRExecutionServices::CreateVolatileInstanceFromTypeAndCustomType.<br>
	* The main difference is that the custo type is computed inside the method.<br>
	* The type in input cannot be a custo type nor a secondary type
	* Note that as custo type in previous typing system was the final primary type, people have used CATIBRExecutionServices::CreateVolatileInstanceFromType and passed the custo type.<br>
	* The V_discipline attribute will be automatically valuated if the type in input inherits from a discipline 
	* The policy is computed by the business rule and set on the proxy
	* Additionnal extensions may be added to the proxy if requested by metadata & business rules (deployment extensions or merged extensions)
	* @param iType
	* The type
	* @param ipiEnv
	* The environment. Usually null(interpreted as “current environment”)
	* @param oInstance
	* PLM proxy created in output
	* @param pListDefaultAttributeValues
	* List of default values for the attributes (usually NULL)
	* By default the attributes are filled with the default values coming from Metadata
	* Do not pass V_discipline attribute !!!
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type in input is NULL or environment is NULL
	* 	 <li> S_OK	if the object has been created sucessfuly
	* 	 <li> E_FAIL otherwise
	*  </ol>
	*/	
	static HRESULT CreatePLMProxyFromTypeAndEnvironment (	const CATIType_var &iType, 
		const CATIAdpEnvironment * ipiEnv,
		CATIInstance_var &oInstance,
		CATLISTV(CATICkeParm_var) *pListDefaultAttributeValues = NULL) ;

	/**
	* Creates a PLM Proxy of an aggregated object from a type. It can be the modeler type, or the discipline if any, or a functional specialization if any in V2. It can be a modeler or a discipline in V1.<br>
	* This method is introduced as an alternative to CATIBRExecutionServices::CreateVolatileInstanceFromTypeAndCustomType.<br>
	* The main difference is that the custo type is computed inside the method.<br>
	* The type in input cannot be a custo type nor a secondary type
	* Note that as custo type in previous typing system was the final primary type, people have used CATIBRExecutionServices::CreateVolatileInstanceFromType and passed the custo type.<br>
	* The V_discipline attribute will be automatically valuated if the type in input inherits from a discipline 
	* The policy is computed by the business rule and set on the proxy. It may depend on the aggregator
	* Additionnal extensions may be added to the proxy if requested by metadata & business rules (deployment extensions or merged extensions)
	* @param iAggregator
	* The aggregator
	* @param iType
	* The type
	* @param ipiEnv
	* The environment. Usually null(interpreted as “current environment”)
	* @param oInstance
	* PLM proxy created in output
	* @param pListDefaultAttributeValues
	* List of default values for the attributes (usually NULL)
	* By default the attributes are filled with the default values coming from Metadata
	* Do not pass V_discipline attribute !!!
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type in input is NULL or environment is NULL
	* 	 <li> S_OK	if the object has been created sucessfuly
	* 	 <li> E_FAIL otherwise
	*  </ol>
	*/	
	static HRESULT CreateAggregatedPLMProxyFromTypeAndEnvironment (	const CATIInstance_var &iAggregator,
		const CATIType_var &iType, 
		const CATIAdpEnvironment * ipiEnv,
		CATIInstance_var &oInstance,
		CATLISTV(CATICkeParm_var) *pListDefaultAttributeValues = NULL) ;

	/**
	* Creates a PLM Proxy from another one, with the same type.
	* The proxy is initialized and there is no copy of attributes except policy attribute
	* @param iProxyOrigin
	* The proxy 
	* @param oProxyCreated
	* PLM proxy created in output
	* @param iCopyExtension
	* Do I Copy extension ?
	* @return 
	*  <ol>
	* 	 <li> E_INVALIDARG if the type in input is NULL or environment is NULL
	* 	 <li> S_OK	if the object has been created sucessfuly
	* 	 <li> E_FAIL otherwise
	*  </ol>
	*/	
	static HRESULT CreatePLMProxyOfSameType (	const CATIInstance_var &iProxyOrigin, 
		CATIInstance_var       &oProxyCreated,
		CATBoolean			   iCopyExtension=FALSE) ;

	/**
	* This service is used to initialize a proxy with business logic.<br>
	* @param iProxy
	* Type in input (only modeler types are supported)
	* @param piExtraParameters
	* The list is filled by the service
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL
	* 	 <li> S_OK	if the list of types is retrieved and is not empty
	* 	 <li> S_FALSE if there was no BL to trigger
	*  </ol>
	*/
	static HRESULT InitializeProxyWithBusinessLogic ( const CATIInstance_var        &iProxy,
		const CATBRExtraParameters	*piExtraParameters);

	/**
	* This service is used to initialize a proxy with business logic.<br>
	* @param iProxy
	* Type in input (only modeler types are supported)
	* @param piExtraParameters
	* The list is filled by the service
	* @param pAttributesToBeTruncated
	* If not null, the list is filled with the possible names of string attributes with over-sized values
	* Be aware that if a script was run, its execution may have been interrupted
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL
	* 	 <li> S_OK	if the list of types is retrieved and is not empty
	* 	 <li> S_FALSE if there was no BL to trigger
	*  </ol>
	*/
	static HRESULT InitializeProxyWithBusinessLogic2 ( const CATIInstance_var        &iProxy,
		const CATBRExtraParameters	*piExtraParameters,
		CATListOfCATUnicodeString    *pAttributesToBeTruncated);

	/**
	* To facilitate modeler code that creates objects outside of PLM New, this service calls the Initialization Business Logic for a given type of object.
	* In output, it returns a proxy which contains the list of attributes to modify on the modeler object to be created.<br>
	* If you can, prefer the usage of FillAttributesFromProxyOrBusinessLogic which embeds the following behavior into one.
	* @param iType
	* The type
	* @param ipiEnv	
	* The environment. Usually null(interpreted as “current environment”)
	* @param oProxy
	* Proxy created and intialized by BL
	* @param piExtraParameters
	* Some modeler APIs are getting some additional information from the caller of the API, that must be provided to identification the business logic
	* @param pListDefaultAttributeValues
	* List of default values for the attributes (usually NULL)
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the input PLM type is NULL or environment is NULL
	* 	 <li> S_OK	if the list of attributes is valuated (even if empty)
	* 	 <li> E_FAIL otherwise	 
	* 	 <li> S_FALSE if there was no BL to trigger
	*  </ol>
	*/
	static HRESULT InitializeAttributesWithBusinessLogic ( const CATIType_var			&iType,	
		const CATIAdpEnvironment	*ipiEnv,
		CATIInstance_var			&oProxy,
		const CATBRExtraParameters	*piExtraParameters = NULL,
		CATLISTV(CATICkeParm_var) *pListDefaultAttributeValues = NULL);

	/**
	* This service is used to launch offline business logic on an object.<br>
	* @param iObject
	* Object in input
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object is NULL
	* 	 <li> S_OK	if the business logic have been successful
	* 	 <li> S_FALSE if the business logic have failed 
	*  </ol>
	*/
	static HRESULT ApplyFinalizeOfflineBusinessLogic ( const CATIInstance_var        &iObject,
		const CATBRExtraParameters	*piExtraParameters);



	/**
	* To facilite transfer of public attribute from an object to another.<br>
	* @param iOrigin
	* object that contains the attributes
	* @param iTarget
	* Object on which we want to modify the attributes
	* @param iCopyAllPublicAttribute
	* By default only the modified attributes (by business logic) are valuated. You can decide to copy all the attributes
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the core iObject is NULL or type and proxy are NULL
	* 	 <li> S_OK	if everything went OK
	* 	 <li> E_FAIL otherwise	(incompatibility of attribute types for example) 
	*  </ol>
	*/ 
	static HRESULT TransferAttributesValues (	const CATIInstance_var &iOrigin,
		const CATIInstance_var &iTarget,
		const CATBoolean &iCopyAllPublicAttribute = FALSE);

	/**
	* This service tests if a given type can be created by PLM New.
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
	* @param iCid 
	*      The name of the type package owner (customer-id, partner-id,"") of the type. 
	*      (must be provided as a non null string for non DS type)
	* @param iTestLicense
	* Tests license or not
	* @param iTestNewableProperty
	* requires that the newable property is set with Newable or insertable
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL
	* 	 <li> S_OK instead
	*  </ol>
	*/
	static HRESULT CanBeCreated (const CATIType_var &iType,
		const CATIAdpEnvironment * ipiEnv,
		CATBoolean &oAvailable,
		CATUnicodeString &oMessage,
		const char* iCid=NULL,
		CATBoolean iTestLicense = TRUE,
		const CATBoolean iTestNewableProperty = FALSE);





	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	// SERVICES FOR INTROSPECTING OBJECTS (AND TYPES) 
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	/**
	* Indicates if an object is supporting a given type.<br>
	* @param iPLMIdentificator
	* object in input. A PLM object.	 
	* @param iType
	* type to test.
	* @param oBoolean
	* result
	*  <ol>
	* 	 <li> TRUE if the object supports the type
	* 	 <li> FALSE instead
	*  </ol>
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object or the type in input is NULL
	* 	 <li> S_OK	if the service worked
	*  </ol>
	*/
	static HRESULT DoesObjectSupportsType (const CATIAdpPLMIdentificator_var iPLMIdentificator,const CATIType_var iType, CATBoolean &oResult);

	/**
	* Retrieves the list of all PLM attributes of a PLM object that matches the PLM Mask criteria in input.<br>
	* The attributes are the one of the primary type of the object (modeler type, discipline or functional specialization or custo type) in addition with the attributes of all the extensions.<br>
	* This method is usually used on an object to show the list of PLM public attributes in UI (Edit properties, PLM New, Dedicated applicative UI).<br>
	* @param iObject
	* The object
	* @param iPLMMaskCriteria
	*   Filtering PLM Mask criteria to apply
	* @param oListFilteredAttr
	*   The list of PLM attributes obtained. It is filled by the service.
	*   The service removes elements of the list in input first.
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the input PLM Object is NULL
	* 	 <li> S_OK if the list of attributes is valuated (even if empty)
	* 	 <li> E_FAIL if failure
	*  </ol>
	*/
	static HRESULT ListAllFilteredAttributesFromMaskAndObject ( const CATICkeObject_var &iObject, 
		const  CATCkePLMTypeAttrServices::PLMMaskCriteria iPLMMaskCriteria,
		CATListValCATAttributeInfos &oListFilteredAttr);
	/** 
	* This service is used to retrieve the list of possible secondary searchable types (extensions) that can exist on an object of a given type. It works in V1 and in V2.<br>
	* Advanced Search functionality will use this service to propose an advanced search on extensions.<br>
	* The type in input cannot be a custo type nor an extension
	* @param ipiEnv	
	* The environment. Usually null(interpreted as “current environment”)
	* @param iPrimaryType
	* primary type
	* @param oListSecondaryTypes
	* The list is filled by the service
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL
	* 	 <li> S_OK	if the list of types is retrieved and is not empty
	* 	 <li> S_FALSE if no secondary type found 
	*  </ol>
	*/
	static HRESULT ListPossibleSecondaryTypesForType(  const CATIAdpEnvironment * ipiEnv,
		const CATIType_var & iPrimaryType,
		CATListValCATIType_var & oListSecondaryTypes);

	/** 
	* This service is used to retrieve the list of possible secondary searchable types (extensions) that can be added to an object of a given type. It works in V1 and in V2.<br>
	* @param iObject
	* the object
	* @param oListSecondaryTypes
	* The list is filled by the service
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL
	* 	 <li> S_OK	if the list of types is retrieved and is not empty
	* 	 <li> S_FALSE if no secondary type found 
	*  </ol>
	*/
	static HRESULT ListPossibleSecondaryTypesForObject(  const CATICkeObject_var & iObject,
		CATListValCATIType_var & oListSecondaryTypes);

	/** 
	* This service is used to retrieve the list of extendable types for a given extension (the scopes).
	* @param iSecondaryType
	* the extension type
	* @param oListPrimaryTypes
	* The list is filled by the service
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL
	* 	 <li> S_OK	if the list of types is retrieved and is not empty
	* 	 <li> S_FALSE if no secondary type found 
	*  </ol>
	*/
	static HRESULT ScopesOfAnExtension(  const CATIType_var & iSecondaryType,
		CATListValCATIType_var & oListPrimaryTypes);

	/**
	* Indicates if an object can be extended by a given extension.<br>
	* @param iObject
	* the object to be extended
	* @param iSecondaryType
	* type of the extension
	* @param oMessage
	* Message to be returned to end user (kind of error)
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if input are NULL or incorrect (not primary, not secondary)
	* 	 <li> S_OK	if the extension can extend
	* 	 <li> S_FALSE, instead
	*  </ol>
	*/ 
	static HRESULT CanBeExtendedBy ( const  CATICkeObject_var & iObject,const CATIType_var &iSecondaryType,CATUnicodeString *oMessage=NULL); 

	/**
	* This service is used to retrieve the persistent type of an object. It works in V1 and in V2.<br>
	* In V1 it will access the custo type and retrieve it. In V2, it will return the business type.<br>
	* USAGE: ALMOST NEVER. 
	* @param iObject
	* Object in input.
	* @param oTypeForQuery
	* The type that must be used to manage persistency. An AddRef is done
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object is NULL
	* 	 <li> S_OK	if the type has been found
	* 	 <li> E_FAIL if no queryable type found
	*  </ol>
	*/
	static HRESULT RetrievePersistentType (const CATICkeObject_var &iObject,CATIAdpType *&oTypeForQuery);


	/** CATCkePLMNavPublicServices::GetAttributeNLSNameFromType
	* This service is used to translate in NLS the name of an attribute of a type. It works in V1 and in V2.<br>
	* In V1 it will access the custo type and retrieve it. In V2, it will use the main type.<br>
	* @param iType
	* Type in input. Modeler, Discipline or even functional specialization type.
	* @param ipiEnv	
	* The environment. Usually null(interpreted as “current environment”)
	* @param iAttributeName
	* Name of the attribute in the Knowledge dictionary (internal name)
	* @param oNLSName
	* NLS Name of the attribute
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL
	* 	 <li> S_OK	if the attribute has been found
	* 	 <li> E_FAIL if not found
	*  </ol>
	*/


	/**
	* This service is used to retrieve from a modeler type (or discipline) the type that must be used to call query services (like CATAdpQueryServices). It works in V1 and in V2.<br>
	* In V1 it will access the custo type and retrieve it. In V2, it will return the same type.<br>
	* @param iType
	* Type in input. Modeler, Discipline or even functional specialization type.
	* @param oTypeForQuery
	* The type that must be used to give to query services. An AddRef is done
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL
	* 	 <li> S_OK	if the type has been found
	* 	 <li> E_FAIL if no queryable type found
	*  </ol>
	*/
	static HRESULT RetrieveTypeForQuery  (const CATIType_var &iType,CATIAdpType *&oTypeForQuery);

	/**
	* Ask if the corresponding object is exposed to Knowledge & public view and in User Interface (CustomerExposition="Programmer")
	* @param iPLMIdentificator
	* Identificator of an object.
	* @param oIsExposed
	* TRUE is exposed, FALSE instead
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the iPLMIdentificator is NULL 
	* 	 <li> S_OK	if identificator not null
	*  </ol>
	*/
	static HRESULT IsExposed (	const CATIAdpPLMIdentificator_var &iPLMIdentificator, 
		CATBoolean &oIsExposed);

	/**
	* Service to retrieve the modeler type of the object.
	* This service is to be called when we want from an object, to operate a query to find an object of the same "type" in order to operate a replace.
	* In this case, we don't want to find the precise type of the object. We want to retrieve the modeler type
	* @param iComponent
	* Component	
	* @param oModelerType
	* The modeler type	 
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the component was empty
	* 	 <li> S_OK	if found
	*  </ol>
	*/
	static HRESULT RetrieveModelerTypeFromComponent (const CATIPLMComponent_var iComponent,CATIType_var &oModelerType);


	/**
	* This service returns from a type (custo or applicative) the type that must be used to compute unique number (in BL). It works in V1 and in V2.<br>
	* In V1 it will access the custo type corresponding to the type in input (in the current environment.<br>
	* In V2 it is OK to compute a unique number on an applicative type.<br>
	* @param iType
	* Type in input. Modeler, Discipline or even functional specialization type.
	* @param oTypeForUniqueNumber
	* The type that must be used to compute the unique numbers. An AddRef is done
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL or the type is not a concrete type
	* 	 <li> S_OK	if the type has been found
	* 	 <li> E_FAIL if no  type found
	*  </ol>
	*/
	static HRESULT RetrieveTypeForUniqueNumberComputation  (const CATIType_var &iType,CATIAdpType *&oTypeForUniqueNumber);


	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	// SERVICES FOR INTROSPECTING DICTIONARY
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------

	/**
	* This service is used to retrieve the list of searchable types in a given package. It works in V1 and in V2.<br>
	* Advanced Search functionality will use this service to propose the selection of primary types from a package.<br>
	* Watch out: this service does not use the notion of Usable types coming from the environment because it is a notion we want to suppress.
	* It returns primary types only. Modeler or discipline.
	* @param ipiEnv	
	* The environment. Usually null(interpreted as “current environment”)
	* @param iPackageName
	* Package in input
	* @param oListSearchableTypes
	* The list is filled by the service
	* @param iAddCustoInV2
	* By default, the service hides custo types (V1) when V2 is activated. Toggle to true if you want to see the custo V1 in V2
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the package is not found
	* 	 <li> S_OK	if the list of types is retrieved and is not empty
	* 	 <li> S_FALSE if no type found 
	*  </ol>
	*/
	static HRESULT ListSearchableTypesFromPackage (  const CATIAdpEnvironment * ipiEnv,
		const CATUnicodeString& iPackageName,
		CATListValCATIType_var & oListSearchableTypes,
		CATBoolean iAddCustoInV2 = FALSE);



	/**
	* This service is used to retrieve the list of newable (that can be created) types in a given package. It works in V1 and in V2.<br>
	* PLM New functionality will use this service to propose the selection of types from a package.<br>
	* This list is limited to modeler & discipline types and does not propose the list of customer types.<br>
	* @param ipiEnv	
	* The environment. Usually null(interpreted as “current environment”)
	* @param iPackageName
	* Package in input
	* @param oListNewableTypes
	* The list is filled by the service
	* @param iInsertableAlso
	* By default the service only returns types in PLM New panel. If you choose InsertableAlso, you will get the list of insertable types
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the package is not found
	* 	 <li> S_OK	if the list of types is retrieved and is not empty
	* 	 <li> S_FALSE if no type found 
	*  </ol>
	*/
	static HRESULT ListNewableTypesFromPackage (  const CATIAdpEnvironment * ipiEnv,
		const CATUnicodeString& iPackageName,
		CATListValCATIType_var & oListNewableTypes,
		CATBoolean iInsertableAlso=FALSE);

	/**
	* This service is used to retrieve the sub types of a list of newable (that can be created) types in a given package. It works in V1 and in V2.<br>
	* In V1 it always returns an empty list. In V2, it will use the specialization mechanism provided.
	* PLM New functionality will use this service to propose the selection of sub types .<br>
	* @param ipiEnv	
	* The environment. Usually null(interpreted as “current environment”)
	* @param iType
	* Type in input
	* @param oListNewableSubTypes
	* The list is filled by the service
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the package is not found
	* 	 <li> S_OK	if the list of types is retrieved and is not empty
	* 	 <li> S_FALSE if no type found 
	*  </ol>
	*/
	static HRESULT ListCustomerSpecialization (  const CATIAdpEnvironment * ipiEnv,
		const CATIType_var & iPrimaryType,
		CATListValCATIType_var & oListNewableSubTypes);

	/**
	* This service is used to retrieve the searchable sub types of a given type. It works in V1 and in V2.<br>
	* @param iType
	* Type in input (only modeler types are supported)
	* @param oListSearchableSubTypes
	* The list is filled by the service
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL
	* 	 <li> S_OK	if the list of types is retrieved and is not empty
	* 	 <li> S_FALSE if no type found 
	*  </ol>
	*/
	static HRESULT ListSearchableSubTypes    (  const CATIType_var & iPrimaryType,
		CATListValCATIType_var & oListSearchableSubTypes);


	/**
	* Returns the list of loaded packages names and force loading of PLM dictionary
	*
	* @param olListOfPackages list of packages
	* @return classic HRESULT
	*/
	static  HRESULT ListPackagesForPLMSearch ( CATListOfCATUnicodeString& olListOfPackages );


	/**
	* Fills the list of package that are candidates to contain objects that can be created via PLM New
	*/
	static HRESULT ListPackagesForPLMNew ( CATListOfCATUnicodeString& olListOfPackages ) ;

	/**
	* This service is used to retrieve the NLS name and the Icon of a package.<br>
	* @param iPackageName
	* Name of the package
	* @param oNLSName
	* NLS name of the package (may be "")
	* @param oIconName
	* Icon name (may be "")
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the package has not been found
	* 	 <li> S_OK	if the package found. But icon may be "" and NLS may be ""
	*  </ol>
	*/
	static HRESULT RetrievePackageNameAndIcon(  const CATUnicodeString  & iPackageName,
		CATUnicodeString		& oNLSName,
		CATUnicodeString		& oIconName	);


	/**
	* This service is used to retrieve the name of the package of a PLM type.<br>
	* WATCH OUT: DO NOT USE this information to implement a logic (for example, to test the package name
	* @param iType
	* The type
	* @param oPackageName
	* Name of the package. Is not NLS
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL or a type is not a PLM Type
	* 	 <li> S_OK	if the package found. 
	*  </ol>
	*/
	static HRESULT RetrievePackageNameFromType (  	const CATIType_var			&iType,	
		CATUnicodeString		& oPackageName	);

	/**
	* This service is used to retrieve the name of the modeler of a PLM type.<br>
	* The modeler name is the package of the core modeler type that the type in input inherits from.
	* (for example Product for all the types inheriting from product reference, product instance, ....)
	* @param iType
	* The type
	* @param oModelerName
	* Name of the modeler. Is not NLS
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL or a type is not a PLM Type, or we didn't find the core modeler type
	* 	 <li> S_OK	if the modeler found. 
	*  </ol>
	*/
	static HRESULT RetrieveModelerPackageNameFromType (  	const CATIType_var			&iType,	
		CATUnicodeString		& oModelerName	);


	/**
	* This service is used to retrieve the newable DS sub types of a given type. It works in V1 and in V2.<br>
	* @param iType
	* Type in input (only modeler types are supported)
	* @param oListNewableSubTypes
	* The list is filled by the service
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL
	* 	 <li> S_OK	if the list of types is retrieved and is not empty
	* 	 <li> S_FALSE if no type found 
	*  </ol>
	*/
	static HRESULT ListNewableSubTypes    (  const CATIType_var & iPrimaryType,
		CATListValCATIType_var & oListNewableSubTypes);

	/**
	* This service is used to retrieve the insertable DS sub types of a given type. It works in V1 and in V2.<br>
	* @param iType
	* Type in input (only modeler types are supported)
	* @param oListInsertableSubTypes
	* The list is filled by the service
	* @param iAggregatingObject
	* If not NULL, the list will be filtered by the types that are allowed to be inserted under the objest
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL
	* 	 <li> S_OK	if the list of types is retrieved and is not empty
	* 	 <li> S_FALSE if no type found 
	*  </ol>
	*/
	static HRESULT ListInsertableSubTypes     ( const CATIType_var & iPrimaryType,
		CATListValCATIType_var & oListInsertableSubTypes,
		const CATICkeObject_var &iAggregatingObject = NULL_var);



	/**
	* This service indicates if a package is supposed to be shown as part of another package.<br>
	* @param iPackageName
	* Name of the package
	* @param oRootPackageName
	* Name of the package where this package is supposed to be part of
	* @return
	* 	 <li> E_INVALIDARG if the package has not been found
	* 	 <li> S_OK	if the package found and there is a package that it is part of
	* 	 <li> S_FALSE	if the package found and there is no package that it is part of
	*  </ol>
	*/
	static HRESULT RetrieveRootPackage(  const CATUnicodeString  & iPackageName,
		CATUnicodeString		& oRootPackage);


	// returns S_OK ou S_FALSE
	static HRESULT IsaV2TypeOnly (const CATIType_var &itype);


	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	// SERVICES FOR INTEGRITY CHECKS
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------

	/**
	* Indicates the list of types that can be aggregated under an object of a given type
	* This information is based on reading a property in metadata
	* @param iObject
	* Object that will aggregate
	* @param oListOfAggregatableTypes
	* List of objects that can be aggregated under this object
	* @param iRootTypeImInterestedIn
	* Filters this list by the types that are sub types of a given types
	* Is NULL if no filter applied
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object is NULL
	* 	 <li> S_OK	if we found a constraint. The list in output can be empty. Means no objects corresponding to the filter can be aggregated
	* 	 <li> S_FALSE	if no constraint has been defined. If a filter is provided, we return this filter type since all sub types of this filter are aggregatable
	*  </ol>
	*/
	static  HRESULT ListAggregatableTypesUnderAnObject ( const CATICkeObject_var &iObject,CATListValCATIType_var& oListOfAggregatableTypes, const CATIType_var iRootTypeImInterestedIn=NULL_var );

	/**
	* Indicates if an object can be aggregated under another based on dictionary definitions
	* This information is based on reading a keyword OwnerType in metadata
	* @param iObject
	* Object that will aggregate
	* @param iObjectToAggregate
	* Object that we want to aggregated
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object is NULL
	* 	 <li> S_OK	if the object can be aggregated
	* 	 <li> S_FALSE	if the object cannot be aggregated
	*  </ol>
	*/
	static  HRESULT CanBeAggregated ( const CATICkeObject_var &iObject,const CATICkeObject_var &iObjectToAggregate);

	/**
	* Indicates if an object can be instantiated under another based on dictionary definitions
	* This information is based on reading the keyword InstantiationOwnerType in metadata
	* @param iObject
	* Object that will aggregate
	* @param iObjectToAggregate
	* Object that we want to aggregated
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object is NULL
	* 	 <li> S_OK	if the object can be aggregated
	* 	 <li> S_FALSE	if the object cannot be aggregated
	*  </ol>
	*/
	static  HRESULT CanBeInstantiatedUnder ( const CATICkeObject_var &iObject,const CATICkeObject_var &iObjectToAggregate);
	static  HRESULT CanBeInstantiatedUnder ( const CATICkeObject_var &iObject,const CATICkeObject_var &iObjectToAggregate, CATUnicodeString* cannotBeInstanciatedReason);

	/**
	* Indicates if a type is a valid type to be use to be aggregated under another based on dictionary definitions
	* This information is based on reading a property in metadata
	* @param iObject
	* Object that will aggregate
	* @param iTypeToAggregate
	* type that we want to aggregate
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object is NULL
	* 	 <li> S_OK	if the object can be aggregated
	* 	 <li> S_FALSE	if the object cannot be aggregated
	*  </ol>
	*/
	static HRESULT TypeCanBeAggregated ( const CATICkeObject_var &iObject,const CATIType_var &iTypeToAggregate);

	/**
	* Indicates if a type is a valid type to be use to be aggregated under another based on dictionary definitions
	* This information is based on reading a property in metadata
	* @param iObject
	* Object that will aggregate
	* @param iTypeToAggregate
	* type that we want to aggregate
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object is NULL
	* 	 <li> S_OK	if the object can be aggregated
	* 	 <li> S_FALSE	if the object cannot be aggregated
	*  </ol>
	*/
	static HRESULT TypeCanBeInstantiatedUnder ( const CATICkeObject_var &iObject,const CATIType_var &iTypeToAggregate);



	/**
	* Retrieve the list of possible instanciation type for a given reference.
	* This information is based on reading a property in metadata
	* @param iObject
	* Object that we want to instantiate
	* @param oInstanciationType
	* Type that will be used by default
	* @param oListOfInstantiationTypes
	* List of possible instantiation type. The first one being the default
	* @param iBaseTypeToRestrict
	* Sometimes, the application knows which base type they expect. This type is used as a restriction. It filters both the list and the default will be the first type
	* If NULL, the information in the metadata is returned as is
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object is NULL
	* 	 <li> S_OK	if we found a constraint. The list in output can be empty (in particular when the restriction was used). 
	* 	 <li> S_FALSE	if no constraint has been defined. 
	*  </ol>
	*/
	static HRESULT RetrieveInstantiationTypesOfObject	 (const CATICkeObject_var &iObject,CATIType_var &oInstanciationType,CATListValCATIType_var &oListOfInstantiationTypes,const CATIType_var &iBaseTypeToRestrict=NULL_var);


	/**
	* Triggers the modeler integrity business rule on an object in memory.
	* @param iObject
	* Object that we want to test regarding integrity business logic
	* @param oValidationResult
	* TRUE if the object is considered as valid, FALSE instead
	* @param oMessage
	* In case of invalidation, contains a message produced by the business rule to indicate the reason of the invalidation
	* @param oSeverity
	* In case of invalidation, returns a severity (produced by the business rule).<br>
	* The severity is an integer produced within the rule by the customer.
	* Severity==2 means that the operation will be cancelled, whereas severity==1 means it is just a warning.
	* @param piExtraParameters
	* Some modeler APIs are getting some additional information from the caller of the API, that must be provided to integrity business logic
	* @return S_OK
	*   The business rule has been successfully executed (potentially, no rule was fired)
	* @return E_FAIL
	*   The business rule was not successfully executed. The reason may be a rule that is not syntaxically valid or an evaluation error raised during the execution.
	*/
	static  HRESULT PerformIntegrityCheck ( const CATICkeObject_var &iObject,
		CATBoolean & oValidationResult ,
		CATUnicodeString &oMessage,
		int &oSeverity,
		const CATBRExtraParameters	*piExtraParameters =NULL);


	/**
	* Retrieve the list of possible instanciation type for a given type of a given reference.
	* We highly recommend that you use RetrieveInstantiationTypesOfObject instead, if you have an object.
	* This information is based on reading a property in metadata
	* @param iType
	* type of the reference that we want to instantiate
	* @param oInstanciationType
	* Type that will be used by default.
	* @param oListOfInstantiationTypes
	* List of possible instantiation type. The first one being the default
	* @param iBaseTypeToRestrict
	* Sometimes, the application knows which base type they expect. This type is used as a restriction. It filters both the list and the default will be the first type
	* If NULL, the information in the metadata is returned as is
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL
	* 	 <li> S_OK	if we found a constraint. The list in output can be empty. 
	* 	 <li> S_FALSE	if no constraint has been defined. 
	*  </ol>
	*/
	static HRESULT RetrieveInstantiationTypesForAGivenType	 (const CATIType_var &iType,CATIType_var &oInstanciationType,CATListValCATIType_var &oListOfInstantiationTypes,const CATIType_var &iBaseTypeToRestrict=NULL_var);

	/**
	* Retrieve the list of possible types that can aggregate an object of a given type.
	* We highly recommend that you use TypeCanBeAggregated or CanBeAggregated instead, if you have an object.
	* This information is based on reading a property in metadata
	* @param iTypeToAggregate
	* type of the object that we want to aggregate
	* @param oListOfAggregators
	* List of possible types that can aggregate such a type
	* Note that if the list is empty, there may be two reasons. One is that there is no constraints defined, which means we can aggregate this object anywhere
	* Or because it is a constraint. It means that this object cannot be aggregated. The HRESULT differentiates the two cases
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL
	* 	 <li> S_OK	if we found a constraint. The list in output can be empty. 
	* 	 <li> S_FALSE	if no constraint has been defined. 
	*  </ol>
	*/
	static HRESULT RetrieveTypesThanCanAggregateAGivenType	 (const CATIType_var &iTypeToAggregate,CATListValCATIType_var &oListOfAggregators);

	/**
	* Retrieve the list of possible types that can insert an instance of an object of a given type.
	* We highly recommend that you use TypeCanBeInstantiatedUnder or CanBeInstantiatedUnder instead, if you have an object.
	* This information is based on reading a property in metadata
	* @param iTypeToInsert
	* type of the object that we want to insert
	* @param oListOfAggregatorsOfInstances
	* List of possible types that can aggregate such a type
	* Note that if the list is empty, there may be two reasons. One is that there is no constraints defined, which means we can insert this object anywhere
	* Or because it is a constraint. It means that this object cannot be aggregated. The HRESULT differentiates the two cases
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type is NULL
	* 	 <li> S_OK	if we found a constraint. The list in output can be empty. 
	* 	 <li> S_FALSE	if no constraint has been defined. 
	*  </ol>
	*/
	static HRESULT RetrieveTypesThanCanInsertAGivenType	 (const CATIType_var &iTypeToInsert,CATListValCATIType_var &oListOfAggregatorsOfInstances);


	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	// MISCELLANEOUS
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------


	/**
	* Service to ask if the object is locked.
	* @param iObject
	* Object	
	* @param oLocked
	* Locked status (true=locked)		 
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the attribute was not available on the object or object NULL_var
	* 	 <li> S_OK	if found
	*  </ol>
	*/
	static HRESULT IsLocked (const CATICkeObject_var &iObject,CATBoolean &oLocked);




	// 
	/**
	* This service is used to identify if a type is LA
	* @param iType
	* Type in input
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object is NULL
	* 	 <li> S_OK	if the type needs to be ignored since it is LA
	* 	 <li> S_FALSE instead
	*  </ol>
	*/
	static HRESULT IsTypeInLimitedAvailability ( const CATIType_var & iType );
	static HRESULT IsTypeInLimitedAvailability ( const CATUnicodeString  & iName );

	static HRESULT IsPackageInLimitedAvailability ( const CATUnicodeString & iName );


	/**
	* This service is used to determine whether a Business Rule has precedence or not (cf "Privileged Business Rules" Project). 
	* This ruling is based on the content of the Business Rule body, which is given as input/output argument: 
	* - if it starts with the "\* -- HASPRIORITY -- *\" eyecatcher , then the Business Rule is assumed to have precedence, and the eyecatcher is removed from the body
	* - if it does not start with the \* -- HASPRIORITY -- *\" eyecatcher, then the Business Rule is assumed NOT to have precedence, and the body is not changed
	* @param ioBusinessRuleBody the BusinessRule body (plain text) 
	* @return
	*  <ol>
	* 	 <li> true   the Business Rule is assumed to have precedence
	* 	 <li> false  the Business Rule is assumed NOT to have precedence
	*  </ol>
	*/
	static boolean doesBusinessRuleHavePrecedence(CATUnicodeString & ioBusinessRuleBody);

	/**
	* Retrieves the list of all PLM attributes of a PLM object that matches the PLM Mask criteria and attribute infos criteria in input.<br>
	* The attributes are the one of the primary type of the object (modeler type, discipline or functional specialization or custo type) in addition with the attributes of all the extensions.<br>
	* This method is usually used on an object to show the list of PLM public attributes in UI (Edit properties, PLM New, Dedicated applicative UI).<br>
	* @param iObject
	* The object
	* @param iPLMMaskCriteria
	*   Filtering PLM Mask criteria to apply
	* @param iAttributeInfosFilter
	*   Filter for attributes
	* @param oListFilteredAttr
	*   The list of PLM attributes obtained. It is filled by the service.
	*   The service removes elements of the list in input first.
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the input PLM Object is NULL
	* 	 <li> S_OK if the list of attributes is valuated (even if empty)
	* 	 <li> E_FAIL if failure
	*  </ol>
	*/
	static HRESULT ListFilteredAttributesFromMaskAndObject2 (const CATICkeObject_var &iObject, 
		const  CATCkePLMTypeAttrServices::PLMMaskCriteria iPLMMaskCriteria,
		const std::function<bool (const CATAttributeInfos&)>& iAttributeInfosFilter,
		CATListValCATAttributeInfos &oListFilteredAttr);

private:
	static	HRESULT ListNewableOrInsertableSubTypes ( const CATIType_var & iPrimaryType, CATListValCATIType_var & oListNewableSubTypes, CATBoolean iNewable, const CATICkeObject_var &iAggregatingObject );




};
//-----------------------------------------------------------------------

#endif

