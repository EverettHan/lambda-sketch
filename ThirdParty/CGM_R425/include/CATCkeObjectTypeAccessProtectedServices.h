// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATCkeObjectTypeAccessProtectedServices.h
// Header definition of CATCkeObjectTypeAccessProtectedServices
//
//===================================================================
//
// Usage notes:
// Provides services to interrogate the different types of an object.
//
//===================================================================
//
//===================================================================



#ifndef CATCkeObjectTypeAccessProtectedServices_H
#define CATCkeObjectTypeAccessProtectedServices_H

// Module export
#include "CATLifSpecs.h"
#include "CATCkeObjectAttrReadServices.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATListValCATIType.h"

class CATICkeObject_var;
class CATIType_var;
class CATUnicodeString;

/**
 * Services to access the different types of an object.<br>
 * These services have an implementation that does not differ between V1 (current typing system) and V2 (target typing system)
 *
 * @see CATIValue
 * @see CATICkeObject
 * @see CATIInstance
 */
class ExportedByCATLifSpecs CATCkeObjectTypeAccessProtectedServices : public CATCkeObjectAttrReadServices
{

  public:

	
	  /**
	 * Indicates if an object is supporting a given type.<br>
	 * Encapsulates CATIInstance::IsSupporting
	 * @param iObject
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
	static HRESULT DoesObjectSupportsType (const CATICkeObject_var iObject,const CATIType_var iType, CATBoolean &oResult);
	
	 
	

	  /** 
	 * Returns the icon name used to represent the object.<br>
	 * Information is retrieved on the main type of the object based on PLM Dictionary declarations.<br>
	 * It finds the first name of icon in the main type hierarchy.
	 * Exception: if a discipline a posteriori is set on the object and has an icon defined, it will return this icon first
	 * defined on the functional type (type defined by the customer)
	 * @param iObject
	 * object in input. A PLM object.
	 * @param oIconName
	 * name of the icon
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object in input is NULL.
	 * 	 <li> S_OK	if the icon name has been retrieved.
	 * 	 <li> S_FALSE if the icon name is empty.
	 *  </ol>
     */
	static HRESULT GetIconNameOfObject		(const CATICkeObject_var &iObject,
											  CATUnicodeString  &oIconName);
  
/**
	 * Enable to retrieve a dynamic properties on a Knowledge object.<br>
	 * A dynamic property is an information declared by an application in the metadata , that is not interpreted by generic toolkits & dictionary but that can be retrieved by applications on their types.
	 * Usage: All contexts (UI Layer (search, new), Modeler,..).<br>
	 * Note that this service reads the property LOCALLY to the type. If it is not defined on the type itself, it won't try to find the property on the super type.<br>
	 * If you want to find a property on super types potentially, use ReadDynamicPropertyWithInheritance service.<br>
	 * @param iObject
	 * object in input. A PLM object.
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
	static HRESULT ReadDynamicPropertyOnObject (const CATICkeObject_var &iObject,const CATUnicodeString &iDynamicPropertyName,CATIValue_var &oValue);

 

	/**
	 * Enable to retrieve a dynamic properties on a Knowledge object.<br>
	 * A dynamic property is an information declared by an application in the metadata , that is not interpreted by generic toolkits & dictionary but that can be retrieved by applications on their types.
	 * Usage: All contexts (UI Layer (search, new), Modeler,..).<br>
	 * Note that this service reads the property on the type or one of its supertype.<br> 
	 * If you want to find a property defined locally on the type use ReadDynamicProperty service instead.<br>
	 * @param iObject
	 * object in input. A PLM object.
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
	static HRESULT ReadDynamicPropertyWithInheritanceOnObject (const CATICkeObject_var &iObject,const CATUnicodeString &iDynamicPropertyName,CATIValue_var &oValue);

	/**
	 * Returns the primary type of an object.<br>
	 * In most cases, you never need to access the types. If you're asking a question on the type, please ask on the object itself.
	 * Contact FRH if you have doubts.
	 * For V1 objects, it returns the discipline or the modeler type.<br>
	 * For V2 objects, it returns the primary type of the object (either functional specialization or discipline or modeler).<br>
	 * The primary type is the most important one. It is the one given at creation time and represents the identity of the object.<br>
	 * It can be used to retrieve informations on the type of the object (list its attributes, etc...).<br>
	 * @param iObject
	 * object in input. A PLM object.
	 * @param oPrimaryType
	 * primary type of the object
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object in input is NULL.
	 * 	 <li> S_OK	if the type has been retrieved.
	 * 	 <li> E_FAIL otherwise.
	 *  </ol> 
     */
	static HRESULT GetPrimaryType		(const CATICkeObject_var &iObject,
										  CATIType_var      &oPrimaryType);


	/**
	 * Returns the first DS Type.<br>
	 * In most cases, you never need to access the types. If you're asking a question on the type, please ask on the object itself.
	 * Contact FRH if you have doubts.
	 * For V1 objects, it returns the discipline or the modeler type.<br>
	 * For V2 objects, it returns the primary type of the object (either functional specialization or discipline or modeler).<br>
	 * The primary type is the most important one. It is the one given at creation time and represents the identity of the object.<br>
	 * It can be used to retrieve informations on the type of the object (list its attributes, etc...).<br>
	 * @param iObject
	 * object in input. A PLM object.
	 * @param oPrimaryType
	 * primary type of the object
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object in input is NULL.
	 * 	 <li> S_OK	if the type has been retrieved.
	 * 	 <li> E_FAIL otherwise.
	 *  </ol> 
     */
	static HRESULT GetFirstDSType		(const CATICkeObject_var &iObject,
										 CATIType_var      &oDSType);


	/**
	* Fills the given list with types supported by this instance that correspond to applicative extensions.
	* It also returns the customer extensions.
	* But it filters deployment extensions
	* @param iolListOfCATIType the filled list.
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object in input is NULL.
	* 	 <li> S_OK	if the type has been retrieved.
	*  </ol>
	*/
	static  HRESULT ListApplicativeExtensionTypes(	const CATICkeObject_var &iObject,
													CATListValCATIType_var& iolListOfCATIType ) ;


	  /**
	 * Returns the 3D icon name used to represent the object.<br>
	 * Information is retrieved on the main type of the object based on PLM Dictionary declarations.<br>
	 * @param iObject
	 * object in input. A PLM object.
	 * @param oIconName
	 * name of the 3D  icon
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object in input is NULL.
	 * 	 <li> S_OK	if the icon name has been retrieved.
	 * 	 <li> S_FALSE if the icon name is empty.
	 *  </ol>
     */
	static HRESULT Get3DIconNameOfObject		(const CATICkeObject_var &iObject,
												  CATUnicodeString  &oIconName);
	
	/**
	 * Indicates if an object is supporting a given type.<br>
	 * Encapsulates CATIInstance::IsSupporting
	 * @param iObject
	 * object in input. A PLM object.	 
	 * @param iNameOfType
	 * name of type
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object does not support this type, or this type 
	 * 	 <li> S_OK	it does
	 *  </ol>
	 */
	static HRESULT ObjectMustSupportsType (const CATICkeObject_var iObject,const CATUnicodeString &iNameOfType);
  
	/**
	 * Returns the deployment extension of an object, if any. In reality, it returns the first one.<br>
	 * OBSOLETE: use ListDeploymentExtensions instead, now that we support to have several ones from an object.
	 * For V1 objects, it returns None.<br>
	 * For V2 objects, it may return the deployment extension if any.<br>
	 * @param iObject
	 * object in input. A PLM object.
	 * @param oDeploymentExtensionType
	 * deployment type of the object
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object in input is NULL.
	 * 	 <li> S_OK	if the extension type has been found (existed on the object)
	 * 	 <li> S_FALSE	if no deployment extension has been found.
	 *  </ol>
     */
	static HRESULT GetDeploymentExtension  (const CATICkeObject_var &iObject,
											CATIType_var      &oDeploymentExtensionType);

	
	/**
	* Fills the given list with types supported by this object that correspond to customer extensions.
	* @param iObject the object in input.
	* @param iolListOfCATIType the filled list.
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object in input is NULL.
	* 	 <li> S_OK	if the type has been retrieved.
	* 	 <li> S_FALSE	if the list is empty
	*  </ol>
	*/
	static  HRESULT ListCustomerExtensions(	const CATICkeObject_var &iObject,
											CATListValCATIType_var& iolListOfCATIType ) ;
	
	/**
	* Fills the given list with types supported by this object that correspond to deployment extensions.
	*
	* @param iObject the object in input.
	* @param iolListOfCATIType the filled list.
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object in input is NULL.
	* 	 <li> S_OK	if the type has been retrieved.
	* 	 <li> S_FALSE	if the list is empty
	*  </ol>
	*/
	static  HRESULT ListDeploymentExtensions(	const CATICkeObject_var &iObject,
												CATListValCATIType_var& iolListOfCATIType ) ;
	/**
	 * Indicates if the object is a PLM object
	 * @param iObject the object in input.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object in input is NULL.
	 * 	 <li> S_OK	if the object is a PLM object
	 * 	 <li> S_FALSE if the object is not a PLM object
	 *  </ol>
	 */
	static  HRESULT IsAPLMObject(	const CATICkeObject_var &iObject ) ;

	/**
	* Fills the given list with types supported by this instance that correspond to extensions (applicative, customer, deployment).
	* This method suppress the types that are useless (upper in the hierarchy of an already available type)
	*
	* @param iolListOfCATIType the filled list.
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object in input is NULL.
	* 	 <li> S_OK	if the type has been retrieved.
	*  </ol>
	*/
	static  HRESULT ListExtensionTypes(	const CATICkeObject_var &iObject,
										CATListValCATIType_var& iolListOfCATIType ) ;

  
	/**
	* Indicates if an object is considered as standard (a standard part, a standard notion) because of one of its type.
	* @param iObject the object in input.
	* @param oIsStandard True if it is a standard, False instead.
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the object in input is NULL.
	* 	 <li> S_OK	if we found the information on one of its type
	* 	 <li> S_FALSE	if we didn't find the information
	*  </ol>
	*/
	static  HRESULT GetStandardStatus (	const CATICkeObject_var &iObject, CATBoolean &oIsStandard);
	
private:






};

//-----------------------------------------------------------------------

#endif
