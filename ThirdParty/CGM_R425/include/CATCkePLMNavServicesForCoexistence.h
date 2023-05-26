// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATCkePLMNavServicesForCoexistence.h
// Header definition of CATCkePLMNavServicesForCoexistence
//
//===================================================================
//
// Usage notes:
// Provides services for coexistence mechanisms ONLY
//
//===================================================================

 

#ifndef CATCkePLMNavServicesForCoexistence_H 
#define CATCkePLMNavServicesForCoexistence_H 

// Module export
#include "PLMDictionaryNavServices.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATListValCATICkeParm.h"
#include "CATCkePLMTypeAttrServices.h"

class CATUnicodeString;
class CATIInstance_var;
class CATIAdpEnvironment; 
class CATCkePLMNavBusinessLogic;
class CATPathDescriptor;


// HRESULT in case of BL failing
#define CATCkePLMNav_PolicyBLFailing 110

/**
 * Services used by coexistence mechanisms (import V4, V5, Smarteam, Briefcase, 3D XML, XPG) 
 * @see CATCkePLMNavServices, CATIType, CATIInstance, CATCkeTypeProtectedServices, CATCkeObjectTypeAccessProtectedServices
 */
class ExportedByPLMDictionaryNavServices CATCkePLMNavServicesForCoexistence 
{

  public:

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
	// SERVICES FOR COEXISTENCE TO CREATE PROXIES
	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

	  /**
	 * Creates a PLM Proxy from a type name computed by an import business logic.<br>
	 * It works in V1 and in V2 on primary types (custo, specialization, modeler, discipline<br>
	 * Note that the method will obey to the request whatever the current typing system (it can create V1 in V2 or V2 in V1 !)
	 * One of the parameter in the list can be the discipline (a priori or a posteriori)
	 * @param iTypeName
	 * The name of the type of the proxy to create
	 * @param oInstance
	 * PLM proxy created in output
	 * It will be a proxy of the type passed in input.
	 * If the discipline is passed as an attribute (or deduced from the type in input), and if there are Related Extensions, they will be created
	 * @param pListDefaultAttributeValues
	 * List of default values for the attributes (usually NULL)
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type name in input is not a type name
	 * 	 <li> S_OK	if the object has been created sucessfuly
	 * 	 <li> E_ACCESSDENIED	if the you tried to create a custo type in V2 or a specialization type in V1
	 * 	 <li> E_FAIL otherwise 
	 *  </ol>
     */	
	static HRESULT CreatePLMProxyFromTypeName (	const CATUnicodeString &iTypeName, 
															CATIInstance_var &oInstance,
															CATLISTV(CATICkeParm_var) *pListDefaultAttributeValues = NULL) ;

			/**
		 * Creates a PLM Proxy from a type name computed by an import business logic for FBDI.<br>
		 * It works in V1 and in V2 on primary types (custo, specialization, modeler, discipline<br>
		 * Note that the method will obey to the request whatever the current typing system (it can create V1 in V2 or V2 in V1 !)
		 * It will add the extensions if necessary and will valuate the V_SubType
		 * @param iTypeName
		 * The name of the type of the proxy to create
		 * @param iTargetApplicativeType
		 * The type given by the application
  		 * @param oInstance
	  	 * PLM proxy created in output
		 * @return
		 *  <ol>
		 * 	 <li> E_INVALIDARG if the type name in input is not a type name
		 * 	 <li> S_OK	if the object has been created sucessfuly
		 * 	 <li> E_FAIL otherwise 
		 *  </ol>
	     */	
		static HRESULT CreatePLMProxyFromTypeNameForFBDI (	const CATUnicodeString &iTypeName, 
															const CATIType_var &iTargetApplicativeType,
															CATIInstance_var &oInstance);


		
		/**
		* For coexistence, a proxy is used to be filled by the customer in order to build a query
		* The customer valuates the attributes that he wants to query.
		* It valuates the V_Version (by SetAttributeString). It does not work on normal proxies.
		* The objective is to build a proxy that will support this scenario
		* @param iTypeName
		* The name of the type of the proxy to create
		*/ 
		static HRESULT CreatePLMProxyUsedForQueryFromTypeName(	const CATUnicodeString &iTypeName, 
														const CATIAdpEnvironment * ipiEnv,
														CATIInstance_var &oInstance,
														CATLISTV(CATICkeParm_var) *pListDefaultAttributeValues = NULL) ;


	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
	// SERVICES FOR ADDING POLICIES AND DEPLOYMENT EXTENSIONS ON ALREADY DEFINED PROXIES
	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

		/** 
		 * This method is computing the policy to be set on a proxy of a given type (through business logic).
		 * If the policy was already set, it won't add it.
		 * @param iProxy
		 * The proxy
		 * @param pMajorMinorAtImport
		 * NULL: not an import scenario
		 * TRUE: to use major/minor policy
		 * FALSE: to use major policy
		 * @return
		 *  <ol>
		 * 	 <li> E_INVALIDARG if the proxy in input was NULL.
		 * 	 <li> S_OK	if the policy attribute has been set
		 * 	 <li> S_FALSE	if the policy attribute has not been set (not defined by BL or already set)
		 *   <li> CATCkePLMNavBusinessLogic::GetPolicyComputationFailedID if the BL failed
		 * 	 <li> E_FAIL otherwise 
		 *  </ol>
		 */ 
		static HRESULT AddPolicyOnProxy (const CATIInstance_var &iProxy, CATBoolean* pMajorMinorAtImport =NULL);

		/** 
		 * For coexistence: a proxy has been created and may have been extended by a deployment extension by another business rule defined by the customer.
		 * If the deployment extension is not defined on this proxy, this service will fire the business rule and add the deployment extension & customer extension.
		 * Before this method is called, the policy may have been added to the proxy. This method will internally compute the policy (using previous method)
		 * It is possible to declare that we already called this method before to avoid to trigger it twice
		 * @param iProxy
		 * The proxy
		 * @param iAddPolicy
		 * FALSE if we don't ask for the valuation of the policy because it has already been done.
		 * @return
		 *  <ol>
		 * 	 <li> E_INVALIDARG if the proxy in input was NULL.
		 * 	 <li> S_OK	if some extension has been added (deployment or customer)
		 * 	 <li> S_FALSE	if the no extension added (because there was some already)
		 *   <li> CATCkePLMNavBusinessLogic::GetPolicyComputationFailedID if the BL failed
		 * 	 <li> E_FAIL otherwise 
		 *  </ol>
		 */
		static HRESULT AddExtensions (const CATIInstance_var &iProxy,const CATBoolean iAddPolicy = TRUE);


	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
	// SERVICES FOR LISTING ATTRIBUTES ON A TYPE, WHATEVER ITS NATURE
	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------


	/**
	  * This service is used to get the list of attributes from a Knowledge type filtered by a criteria.<br>
	  * The type in input can be anything. But only coexistence can use this service
	  * If you're interested in the list of attributes on a particular object you must use ListAttributesFromObject instead of this method.
	  * This method is introduced as an alternative to CATCkePLMTypeAttrServices::ListAttributes.<br>
	  * @param iFilteringCriteria
      * Filtering criteria to apply. Note that the Identifier criteria does not make sense on a type so it will return in error
	  * Note also that the notion of mandatory/optional will disappear at model level. It will be
	  * @param iType
	  * The primary Knowledge type
	  * @param ipiEnv	 
	  * Useless
	  * @param oListAttr
	  * The list of PLM attributes obtained. It is filled by the service. The service removes elements of the list in input first.
	  * @param iReadWriteOnly
	  * Specify if we want to apply an additional filter to access only Read/Write attributes
	  *  <ol>
	  * 	 <li> TRUE if we want to obtain a list of the Read/Write attributes only.
	  * 	 <li> FALSE	(default value) if we do not want to apply this additional filter, and we want to obtain both Read Only attributes and Read/Write.
	  *  </ol>
	  * @return
	  *  <ol>
	  * 	 <li> E_INVALIDARG if the input PLM type is NULL or environment is NULL, or if the type is a custo type.
	  * 	 <li> S_OK	if the list of attributes is valuated (even if empty)
	  * 	 <li> E_FAIL otherwise	 
	  *  </ol>
	  */
		static HRESULT ListAttributesFromAnyType	   (const CATCkePLMTypeAttrServices::FilteringCriteria iFilteringCriteria,
													const CATIType_var &iType, 
													const CATIAdpEnvironment * ipiEnv,
													CATListValCATAttributeInfos &oListAttr,
													CATBoolean iReadWriteOnly);

	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
	// SERVICES FOR UNDERSTANDING TYPES AND CONVERTING FORMER TYPING TO NEW TYPING
	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

		/** Temporary service for FBDI: do not use
		 * A partir d'un type modeler, discipline ou specialise, rend le type qui doit etre cree reellement
		 * en typage V1, remonte au type modeler
		 * en typage V2, rend le meme type
	     * @param iTypeInput
	     * The type in input (can be a discipline)
	     * @param oTypeToCreate
	     * The type to create
		 * @return
	 	 *  <ol>
	     * 	 <li> E_INVALIDARG if the input type is NULL
	     * 	 <li> S_OK	if type found
	     * 	 <li> E_FAIL if type not founr	 
	     *  </ol>
		 */
		static HRESULT RetrieveTypeToCreate (const CATIType_var iTypeInput,CATIType_var &oTypeToCreate);

		
		/** Service for briefcase
		 * In the briefcase, an object is of a given type (that may be V1 or V2 type). It has also a discipline
		 * In typing V1, we can create a V1 type but not a V2 type
		 * In typing V2, we can create a V2 type but not a V1
		 * In the cases where we cannot, this service returns the best type to create...
	     * @param iTypeInput
	     * The type in input 
	     * @param iDisciplineAttributeName
	     * The value of the V_Discipline attribute
	     * @param oBestTypeToCreate
	     * The type to create depending on typing system
		 * @return
	 	 *  <ol>
	     * 	 <li> E_INVALIDARG if the input type is NULL
	     * 	 <li> S_OK	if type found
	     * 	 <li> E_FAIL if type cannot be created
	     *  </ol>
		 */
		static HRESULT RetrieveBestTypeToCreateAfterImport (const CATIType_var iTypeInput,const CATUnicodeString &iDisciplineAttributeName,CATIType_var &oBestTypeToCreate);
		
		/** Service for DBDI
		 * In DBDI, if a type to create is an applicative sub type, it is too late to create an object of this subtype
		 * In this situation, we need to create the old model (made of an extension and a discipine
	     * @param iTypeInput
	     * The type in input 
	     * @param oDisciplineAttributeName
	     * The value of the V_Discipline attribute
	     * @param oListOfExtensionsToFill
	     * The list containing the extension types to create
		 * @return
	 	 *  <ol>
	     * 	 <li> E_INVALIDARG if the input type is NULL
	     * 	 <li> S_OK	if type in input is a type that correspond to this pattern
	     * 	 <li> S_FALSE if type in input does not correspond to this pattern
	     *  </ol>
		 */
		static HRESULT RetrieveOldTypingApplicativeModel (const CATIType_var iTypeInput,CATUnicodeString &oDisciplineAttributeName,CATLISTV(CATIType_var) &oListOfExtensionsToFill);

    	/** Service for DBDI
		 * In DBDI, if a type to create is an applicative sub type, it is too late to create an object of this subtype
		 * In this situation, DBDI will tag the object as "to be migrated" 
	     * @param iTargetedType
	     * The desired target type (which is not the type of the object)
	     * @param iObject
	     * The object to be tagged
		 *   @return
	 	 *  <ol>
	     * 	 <li> E_INVALIDARG if the input type is NULL or the object is NULL
	     * 	 <li> E_FAILED if the input object is not a PC2 object
	     * 	 <li> S_OK	if everything has worked fine
	     *  </ol>
	  	 */
  		static HRESULT MarkV5ImportedObjectAsToBeMigrated (const CATIType_var iTargetedType,const CATIInstance_var &iObject);
	

	
		/**
		 * In the migration, looking at the type for determining if an object is a V1 or V2 object is not obvious.
		 * In some cases, it can be deduced but in other cases, it is undetermined.
		 */
		 enum  TypeDetermination { V1, V2, Undetermined, Iso };
	
		/**
		 * First step to determine the typing version of a type.<br>
 	     * For specialization types, it returns V2.<br>
 	     * For discipline types, it returns V2.<br>
		 * For modeler types (that were CAA derivable in V1),  it returns V2.<br>
		 * For modeler types (that were not CAA derivable in V1), it returns Undetermined.<br>
		 * In this last case, we will need the value of the discipline to be more precise.
		 * @param &iType
		 * type in input
		 * @return 
		 * S_OK if we have succeeded in determining the typing version
		 * S_FALSE if we are in the undetermined case
		 * E_INVALIDARG if the type was not a primary type
		 */
		static HRESULT DetermineTypingVersionOfType	(const CATIType_var &iType,TypeDetermination &oTypeDetermination);
		
		/**
		 * Second step to determine the typing version of a type.<br>
		 * Watch out, call this second step only if the first step was Undetermined
		 * If no discipline, will return Iso meaning that we have no migration to perform
		 * If a secondary discipline, will return Iso 
		 * If the discipline is a sub type, we consider we are in V1
		 * @param &iType
		 * type in input
 		 * @param &iDisciplineAttributeValue
		 * Discipline attribute value
		 * @return
		 * S_OK if we have succeeded in determining the typing version
		 * E_INVALIDARG if the type was not a primary type
		 */
		static HRESULT DetermineTypingVersionOfModelerType	(const CATIType_var &iType,const CATUnicodeString &iDisciplineAttributeValue,TypeDetermination &oTypeDetermination);

    /**
     * Returns the type that determines the space where all objects are named using the same abbreviation: used in OCDX context
     * Usage: Briefcase that needs to prepare the numbering for a set of objects 
     @param iType
	 * The type in input
	 * @param oAbbreviation
	 * abbreviation defined on the type. May be "" if abbreviation not found
  *  @param oTypeWhereAbbreviationIsDefined
	 * Type in the hierarchy where the property is defined
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is not found.
	 * 	 <li> S_OK	if the abbreviation has been found
	 * 	 <li> S_FALSE	if the abbreviation has not been found
	 * 	 <li> E_FAIL	otherwise
	 *  </ol>
     */
	static HRESULT LocateTypeForNumberingSpace (const CATIType_var &iType,CATUnicodeString &oAbbreviation,CATIType_var &oTypeWhereAbbreviationIsDefined);

  	//--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
  	// SERVICES FOR DOWNWARD COMPATIBILITY
	  //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    /**
     * Returns the 3 information to put in 3DXML persistence for old path (before path project)
     @param iPath
	 * The path as it it is modeled today
  *  @param oRole
	 * The information to put in the role
  *  @param oCategory
	 * The information to put in the category
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the path in input is invalid (cannot be downwarded...)
	 * 	 <li> S_OK	if the downward is possible
	 *  </ol>
     */
    static HRESULT ProduceFormerPathModel (const CATPathDescriptor &iPath,CATUnicodeString &oRole,CATUnicodeString &oCategory);
}; 
//-----------------------------------------------------------------------

#endif

