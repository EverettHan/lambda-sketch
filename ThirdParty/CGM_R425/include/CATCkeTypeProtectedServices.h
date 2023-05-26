#ifndef CATCkeTypeProtectedServices_h
#define CATCkeTypeProtectedServices_h

// COPYRIGHT Dassault Systemes 2009

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"
#include "CATCkeTypeQualification.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListValCATIType.h"

#include "CATListValCATAttributeInfos.h"

#include "CATBoolean.h"

class CATIType_var;
class CATUnicodeString;
class CATIValue_var;

/**        
 * Global services dealing with types. In particular, access to type qualifications. Class of services dedicated for internal software components (UI, Nav, New, Modeler, PLMCore, ...)
 * These services have an implementation that does not differ between V1 (current typing system) and V2 (target typing system)
 */  

class ExportedByCATLifSpecs CATCkeTypeProtectedServices
{      
public  :  

	/** 
	 * TypingVersion: on an object, we can deduce if it is based on Typing version 1 (Custo types) or version 2 (Disciplines, Functional Specialization, and deployment types)
	 *  In some case we cannot decide (modeler types). We will answer V2
	 * @param V1
	 * @param V2
	 */
	enum TypingVersion { V1, V2 };

    /**
	 * @deprecated 3DEXPERIENCER2023x: DO NOT USE THIS METHOD UNDER ANY CONDITION
	 * 
	 * Returns the Icon associated to a type in the PLM Dictionary. Can take inheritance into account. Just provides the Icon name associated that may be "".<br>
	 * Usage: UI Layer (search, new). <br>
	 * @param iType
	 * The type in input
	 * @param oName
	 * the name of the icon in output
	 * @param iWithInheritance
	 * Indicates if we want to use inheritance to find the icon or not
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type in input is NULL 
	 * 	 <li> S_OK	if the icon name has been found
	 * 	 <li> S_FALSE	if the icon name is empty string
	 *  </ol>
     */
	static HRESULT  GetIconName  (const CATIType_var &iType,CATUnicodeString&  oName,CATBoolean iWithInheritance=FALSE);

	/**
	 * Returns the Knowledge type from a type name.<br>
	 * Usage: All contexts (UI Layer (search, new), Modeler, PLMCore, ...).<br>
	 * DOES NOT WORK for customer types. Because we want prevent applications to be custo dependent
	 * The right usage if for applications that want to retrieve the CATIType from an hard coded name that correspond to an OOTB type
	 * @param iTypeName
	 * The type name in input
	 * @param oType
	 * the type found
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is not found or if it is a customer type.
	 * 	 <li> S_OK	if the type has been found
	 *  </ol>
     */
	static HRESULT RetrieveKnowledgeType (const char *iTypeName,CATIType_var &oType);


	/**
	 * Enable to retrieve a dynamic property on a Knowledge type.<br>
	 * A dynamic property is an information declared by an application in the metadata , that is not interpreted by generic toolkits & dictionary but that can be retrieved by applications on their types.
	 * Usage: All contexts (UI Layer (search, new), Modeler,..).<br>
	 * Note that this service reads the property LOCALLY to the type. If it is not defined on the type itself, it won't try to find the property on the super type.<br>
	 * If you want to find a property on super types potentially, use ReadDynamicPropertyWithInheritance service.<br>
	 * @param iTypeName
	 * The type name in input
	 * @param iDynamicPropertyName
	 * name of the dynamic property
	 * @param oValue
	 * value read. Can be NULL if property not found
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is not found.
	 * 	 <li> S_OK	if the property has been read
	 * 	 <li> S_FALSE	if the property has not been found
	 * 	 <li> E_FAIL	otherwise
	 *  </ol>
     */
	static HRESULT ReadDynamicProperty (const CATIType_var &iType,const CATUnicodeString &iDynamicPropertyName,CATIValue_var &oValue);

 
	/**
	 * Enable to retrieve a dynamic properties on a Knowledge type.<br>
	 * A dynamic property is an information declared by an application in the metadata , that is not interpreted by generic toolkits & dictionary but that can be retrieved by applications on their types.
	 * Usage: All contexts (UI Layer (search, new), Modeler,..).<br>
	 * Note that this service reads the property on the type or one of its supertype.<br> 
	 * If you want to find a property defined locally on the type use ReadDynamicProperty service instead.<br>
	 * @param iTypeName
	 * The type name in input
	 * @param iDynamicPropertyName
	 * name of the dynamic property
	 * @param oValue
	 * value read. Can be NULL if property not found
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is not found.
	 * 	 <li> S_OK	if the property has been read
	 * 	 <li> S_FALSE	if the property has not been found
	 * 	 <li> E_FAIL	otherwise
	 *  </ol>
     */
	static HRESULT ReadDynamicPropertyWithInheritance (const CATIType_var &iType,const CATUnicodeString &iDynamicPropertyName,CATIValue_var &oValue);

 
	/**
	 * Enable to retrieve a dynamic properties on a Knowledge type and locate on which precise type it is defined.<br>
	 * A dynamic property is an information declared by an application in the metadata , that is not interpreted by generic toolkits & dictionary but that can be retrieved by applications on their types.
	 * Usage: All contexts (UI Layer (search, new), Modeler,..).<br>
	 * Note that this service reads the property on the type or one of its supertype.<br> 
	 * If you want to find a property defined locally on the type use ReadDynamicProperty service instead.<br>
	 * @param iTypeName
	 * The type name in input
	 * @param iDynamicPropertyName
	 * name of the dynamic property
	 * @param oValue
	 * value read. Can be NULL if property not found
	 * @param oTypeWherePropertyIsDefined
	 * Type in the hierarchy where the property is defined
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is not found.
	 * 	 <li> S_OK	if the property has been read
	 * 	 <li> S_FALSE	if the property has not been found
	 * 	 <li> E_FAIL	otherwise
	 *  </ol>
     */
	static HRESULT LocateDynamicPropertyWithInheritance (const CATIType_var &iType,const CATUnicodeString &iDynamicPropertyName,CATIValue_var &oValue,CATIType_var &oTypeWherePropertyIsDefined);


	/**
	 * Some properties are defined as strings but they are Boolean (possible values "true" and "false".
	 * This service converts it to a boolean
	 * @return
	 *  <ol>
	 * 	 <li> S_OK	if the property has been read
	 * 	 <li> E_FAIL	otherwise (unable to convert)
	 *  </ol>
	 */
	static HRESULT PropertyFromStringToBoolean (const CATUnicodeString &value, CATBoolean &oValueAsBoolean);
	static CATUnicodeString PropertyFromBooleanToString (CATBoolean &iValueAsBoolean);

	/**
	 * Indicates if a type is a sub type of another, passed as a string.<br>
	 * @param iType
	 * the type that we want to test
	 * @param iTypeName
	 * The oIsaSubtype sur-type
	 * @param oBoolean
	 * result
 	 *  <ol>
	 * 	 <li> TRUE if the type in input is a subtype of iTypeName (or same)
	 * 	 <li> FALSE instead
	 *  </ol>
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if no type with name iTypeName has been found of if iType is NULL
	 * 	 <li> S_OK	if the type has been found
	 *  </ol>
     */
	static HRESULT IsaSortOf (const CATIType_var &iType,const char *iTypeName, CATBoolean &oIsaSubtype);

	/**
	 * Tests if the name of the type contains only valid characters.<br>
	 * @param iTypeName
	 * name of the type that we want to test
	 * @return
 	 *  <ol>
	 * 	 <li> TRUE if the type name is valid
	 * 	 <li> FALSE if it is not valid (including NULL)
	 *  </ol>
     */
	static CATBoolean TestNameValidity (const CATUnicodeString &iTypeName);

	/**
	 * Produces a name that can be used for late types.<br>
	 * @param iTypeName
	 * name of the type
	 * @param oNameForLateType
	 * name that can be used in a late type
	 * @param iWithPrefix
	 * TRUE if the late type generated will be used with a prefix (avoid creating NUM prefix inside this code)
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if name is input contains characters that are not valid (see previous method)
	 * 	 <li> S_OK	if the type name is valid
	 *  </ol>
     */
	static HRESULT GenerateNameFromLateType (const CATUnicodeString &iTypeName,CATUnicodeString &oNameForLateType,const CATBoolean iWithPrefix=FALSE);

	/**
	 * This method is called to retrieve the Knowledge type of a discipline from the value stored in the V_Discipline attribute
	 * @param iDisciplineValue
	 * value of the V_discipline attribute
	 * @param oType
	 * Knowledge type corresponding to this discipline
	 * @return
	 *  <ol>
	 * 	 <li> S_FALSE if we didn't find such a valid discipline attribute value 
	 * 	 <li> S_OK	if we found the corresponding type
	 *  </ol>
	 */
	static HRESULT RetrieveDisciplineTypeFromAttributeValue (const CATUnicodeString &iDisciplineValue,CATIType_var &oType);

	/**
	 * Tests if a type is a discipline and indicates if it is a discipline primary (at creation) or secondary (a posteriori).<br>
	 * Usage: this method may be used to differentiate modeler type (that can be used whatever typing system) from applicative ones that can generate objects only in Unified typing
	 * @param iType
	 * Type
	 * @param iIsADiscipline
	 * TRUE is it is a discipline
	 * @param isPrimary
	 * TRUE is it is a discipline a priori
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if type NULL
	 * 	 <li> S_OK	if the type is a discipline
	 *  </ol>
     */
	static HRESULT IsADiscipline (const CATIType_var &iType,CATBoolean &iIsADiscipline,CATBoolean &isPrimary);

	/**
	 * Some disciplines have one or several related extensions (that are always added on the object when the discipline is set.<br>
	 * @param iDisciplineType
	 * Discipline type
	 * @param oListToFill
	 * Extension types
	 * @param iAccessInV2
	 * Computes also the list of related extensions even in typing V2.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if type NULL in input
	 * 	 <li> S_OK	if the discipline related extension exists (one or several)
	 * 	 <li> S_FALSE	if the discipline related extension does not exists
	 *  </ol>
     */
	static HRESULT RelatedExtensions (const CATIType_var &iDisciplineType,CATLISTV(CATIType_var) &oListToFill,CATBoolean iAccessInV2=FALSE);
 
    /**
	 * Returns the 3DIcon associated to a type in the PLM Dictionary. Can take inheritance into account. Just provides the Icon name associated that may be "".<br>
	 * Usage: UI Layer (search, new). <br>
	 * @param iType
	 * The type in input
	 * @param oName
	 * the name of the icon in output
	 * @param iWithInheritance
	 * Indicates if we want to use inheritance to find the icon or not
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type in input is NULL 
	 * 	 <li> S_OK	if the icon name has been found
	 * 	 <li> S_FALSE	if the icon name is empty string
	 *  </ol>
     */
	static HRESULT  Get3DIconName  (const CATIType_var &iType,CATUnicodeString&  oName,CATBoolean iWithInheritance=FALSE);

	/**
	 * Enable to retrieve the list of aggregated types for a composed type (ex: 3DPart).<br>
	 * Usage: All contexts (UI Layer (New)).<br>
	 * @param iType
	 * The type  in input
	 * @param iListToFill
	 * list that is filled with the types
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is not found.
	 * 	 <li> S_OK	if the property has been read and the list of types filled
	 * 	 <li> S_FALSE	if the type was not a composed type (list is empty)
	 * 	 <li> E_FAIL	otherwise
	 *  </ol> 
     */
	static HRESULT AccessListOfAggregatedTypes (const CATIType_var &iType,CATLISTV(CATIType_var) &iListToFill);


	 /**
	 * Enable to skip the customer types to find the first DS type in the hierarchy (including disciplines)
	 * @param iType
	 * The type  in input
 	 * @param oTypeFound
	 * The DS Type
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is NULL
	 * 	 <li> S_OK	if the DS type has been found
	 * 	 <li> S_FALSE	if the DS type has not been found
	 *  </ol>
	 */
  	static HRESULT FindFirstDSType   		 (const CATIType_var &iType,
											  CATIType_var      &oTypeFound);

	
	 /**
	 * Indicates if the type is a primary type or a secondary (extension)
	 * This method is used to differentiate types from extension types.
	 * As a consequence, custo V1 are considered as primary whereas deployment extensions are considered as secondary
	 * @param iType
	 * The type  in input
 	 * @param oPrimary
	 * TRUE if primary, FALSE if secondary
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is NULL
	 * 	 <li> S_OK  
	 *  </ol>
	 */
  	static HRESULT IsAPrimaryType ( const CATIType_var &iType,
									CATBoolean      &oPrimary);

	
	 /**
	 * Indicates if the type is a secondary type (extension) and if it is a customer extension (not inheriting from DS type)
	 * this INCLUDES the deployment extensions, the customer extensions but not the specialized extensions
	 * @param iType
	 * The type  in input
 	 * @param oResult
	 * TRUE if customer extension, FALSE if not
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is NULL 
	 * 	 <li> S_FALSE if the type is not an extension 
	 * 	 <li> S_OK if it is an extension 
	 *  </ol>
	 */
  	static HRESULT IsACustomerExtension ( const CATIType_var &iType,
										  CATBoolean      &oResult);

	/**
	 * Returns the abstract status (if the type is abstract, it cannot be created)
	 * Usage: PLM New
	 * - This information will be used in PLM New, to propose the New of the object
 	 * @param iType
	 * The type  in input
 	 * @param oAbstractStatus
	 * TRUE if abstract, FALSE if concrete
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is NULL 
	 * 	 <li> S_OK  
	 *  </ol>
 	 */
    static HRESULT  GetAbstractStatus (const CATIType_var &iType,CATBoolean &oAbstractStatus);

	/**
	 * Returns the list of attributes local to an extension: suppresses the list of attributes corresponding to the type extended by the extension.
	 * In the Knowledge dictionary construction from PLM Dictionary, we made an error that we need to assume now.
	 * - Applicative extensions (not customer extensions, nor deployment extensions) are declared as inheriting from the type they extend.
	 * - As a consequence, when we list attributes with standard Knowledge API, we find the attributes of this extended type
	 * The goal of this service is to avoid this error when we are interested in listing the PLM attributes of the extension ONLY
	 * @param iType
	 * the extension type
 	 * @param oListOfAttributeInfos
	 * contains the list of attributes local to the extension
 	 * @param recursively
	 * if true, the output list will also contain the attributes given by the inheritance mechanism provided by CATIType
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is NULL or not an extension 
	 * 	 <li> S_OK  
	 *  </ol>
	 */
	static HRESULT ListAttributesOfExtension (const CATIType_var &iType, CATListValCATAttributeInfos &oListOfAttributeInfos, boolean recursively = 1 );

	/**
	 * From a type that we retrieved for searching or filtering an object, under an application request 
	 * We extract the type on which we need to search and potentially the discipline attribut name
	 * By doing so, a search will retrieve the V1 objects and the V2 objects, since the V_discipline attribute is maintained between V1 and V2
	 * This method does not work on extensions but it works on V1 type
	 * It is used by CAA query
	 * @param iInputTypeToSearch
	 * type retrieved from search selection
 	 * @param iOutputTypeToSearch
	 *  type that we must used to perform the query
 	 * @param oOptionalDisciplineAttributeValue
	 * oOptionalDisciplineAttributeValue
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is NULL or not an primary type or a custo type
	 * 	 <li> S_OK  
	 *  </ol>
	 */
	static HRESULT RetrieveTypeAndDisciplineToUseToSearch (	const CATIType_var &iInputTypeToSearch,
															CATIType_var &iOutputTypeToSearch,
															CATUnicodeString &oOptionalDisciplineAttributeValue);
	
	/**
	 * From a discipline type, finds the attribute value to set
	 * @param iTypeDiscipline
	 * The type  in input
 	 * @param oDiscAttributeValue
	 * The value of the V_discipline attribute
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is NULL 
	 * 	 <li> S_OK instead 
	 *  </ol>
	 */
	static HRESULT GetDisciplineAttribute (const CATIType_var &iTypeDiscipline,CATUnicodeString &oDiscAttributeValue);

	/**
	 * Returns the typing "version" of a type.<br>
 	 * For custo type, it returns V1.<br>
	 * For the other it returns V2.<br>
	 * @param &iType
	 * type in input
	 * @return
     */
	static CATCkeTypeProtectedServices::TypingVersion GetTypingVersionOfType	(const CATIType_var &iType);



	/**
	 * Finds the first top modeler type. Skips the customer type and the discipline types
	 * @param iType
	 * The type  in input
 	 * @param oTypeFound
	 * The DS Type
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is NULL
	 * 	 <li> S_OK	if the DS type has been found
	 * 	 <li> S_FALSE	if the DS type has not been found
	 *  </ol>
	 */
  	static HRESULT FindFirstModelerType		(const CATIType_var &iType,
											  CATIType_var      &oTypeFound);


	/**
	 * Tests if the V_Discipline attribute value can be used on an object of a given type
	 * @param iType
	 * The type  in input
 	 * @param iDisciplineValue
	 * The value of the V_Discipline
	 * @param iAcceptOnlySecondary
	 * Accepts only to consider secondary discipline. If not, we accept the primary discipline
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is NULL
	 * 	 <li> S_OK	if the value of the attribute is compatible
	 * 	 <li> S_FALSE	if it is not compatible
	 *  </ol>
	 */
	static HRESULT DisciplineCompatible (const CATIType_var &iType, const CATUnicodeString &iDisciplineValue,const CATBoolean iAcceptOnlySecondary);

	// Do we want to produce traces related to new typing behavior

	// Indicates if CKE_NEWTYPING_TRACES=1 is positioned to generate traces regarding new typing
	static CATBoolean NewTypingTracesActive ();

	// Returns 0 if no traces, 1 for first level, 2 for second level
	static int NewTypingTracesLevel ();

	//-------------------------------------------------------------------------------------
	// Returns the extensibility status (can the type be extended by a customer extension)
	// 
	// Usage: DMC / Ontology modeler
	// - This information will be used in IDE (ontology modeling, DMC) to decide if they can add a customer extension on a given type.
	// 
	// HRESULT=INVALID_ARG if type is NULL, S_OK instead
	//-------------------------------------------------------------------------------------
    static HRESULT  GetExtensibilityStatus (const CATIType_var &iType,CATBoolean &oExtensibilityStatus);

	//-------------------------------------------------------------------------------------
	// Returns the derivability status (can the type be deriuved by a customer extension)
	// 
	// Usage: DMC / Ontology modeler
	// - This information will be used in IDE (ontology modeling, DMC) to decide if they can add a customer primary deriving from a given type.
	// 
	// HRESULT=INVALID_ARG if type is NULL, S_OK instead
	//-------------------------------------------------------------------------------------
    static HRESULT  GetDerivabilityStatus (const CATIType_var &iType,CATBoolean &oDerivabilityStatus);
	
	//-------------------------------------------------------------------------------------
	// Returns the searchable status (if the type can be used for a search)
	// 
	// Usage: Search
	// - This information will be used in Advanced search, to propose the search of the object
	// 
	// HRESULT=INVALID_ARG if type is NULL, S_OK instead
	//-------------------------------------------------------------------------------------
    static HRESULT  GetSearchableStatus (const CATIType_var &iType,CATBoolean &oSearchable);

	/**
	 * Indicates if the type is a PLM type (primary of extension)
	 * @param iType the type in input.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type in input is NULL.
	 * 	 <li> S_OK	if the type is a PLM type
	 * 	 <li> S_FALSE if the type is not a PLM type
	 *  </ol>
	 */
	static  HRESULT IsAPLMType(	const CATIType_var &iType ) ;
 /**
	 * Some disciplines have one or several merged extensions (that are always added on the object when the discipline is set.<br>
	 * @param iDisciplineType
	 * Discipline type
	 * @param oListToFill
	 * Extension types
	 * @param iAccessInV2
	 * Computes also the list of related extensions even in typing V2.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if type NULL in input
	 * 	 <li> S_OK	if the discipline related extension exists (one or several)
	 * 	 <li> S_FALSE	if the discipline related extension does not exists
	 *  </ol>
     */
	static HRESULT MergedExtensions (const CATIType_var &iDisciplineType,CATLISTV(CATIType_var) &oListToFill,CATBoolean iAccessInV2=FALSE);


	/**
	 * Indicates if the type is to be exposed in UI 
	 * @param iType the type in input.
	 * @param oExposedInUI in output, indicates if the type is exposed in UI or nor
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type in input is NULL.
	 * 	 <li> S_OK instead
	 *  </ol>
	 */
	 static  HRESULT IsExposedInUI (const CATIType_var &iType,CATBoolean &oExposedInUI);


	// Suppression de la projection du dico PLM: on tire les infos directement des classes dico PLM
	static CATBoolean NativePLMKnowledgeDictionary();

  // Chargement du dico incremental
	static CATBoolean IncrementalDictionary();

  	/**
	* Indicates if a type (or an extension type) is considered as standard (a standard part, a standard notion) 
  * @param iType the type in input.
	* @param oIsStandard True if it is a standard, False instead.
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the type in input is NULL.
	* 	 <li> S_OK	if we found the information
	* 	 <li> S_FALSE	if we didn't find the information
	*  </ol>
	*/

  static HRESULT GetStandardStatus (	const CATIType_var &iType, CATBoolean &oIsStandard);


protected:
	static CATListValCATUnicodeString _listDisciplineAttributeValue;
	static CATLISTV(CATIType_var) _listDisciplines;
};

#endif // CATCkeTypeProtectedServices_h

