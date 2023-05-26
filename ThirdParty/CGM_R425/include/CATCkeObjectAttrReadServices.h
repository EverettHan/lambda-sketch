// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCkeObjectAttrReadServices.h
// Header definition of CATCkeObjectAttrReadServices
//
//===================================================================
//
// Usage notes:
// - Used to read public attributes (published in CAA) on a Knowledge object
// - Used in particular to read public attributes on a PLM object
//
//===================================================================

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#ifndef CATCkeObjectAttrReadServices_H
#define CATCkeObjectAttrReadServices_H

// Module export
#include "CATLifSpecs.h"
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListValCATICkeParm.h"
#include "CATListValCATIType.h"

#include "CATICkeUnit.h"

class CATICkeObject_var;
class CATIValue_var;
class CATUnicodeString;
class CATTime;

/**
 * Services to easily read attribute values on a Knowledge object.<br>
 * <b>Role</b>: A Knowledge object implements CATICkeObject. These services enable to read its attributes values.<br>
 * Note that only simple (boolean, integer, real, string) and persistent values are accessed by those services. As opposed to computed values.<br>
 * Note also that if the object does not publish its attributes in CAA (CATICkeObject::IsPublic), those services do not work.<br>
 * @see CATIValue, CATICkeObject, CATCkeObjectAttrWriteServices, CATIAttributeComputed, CATICkeUnit
 */
class ExportedByCATLifSpecs CATCkeObjectAttrReadServices
{

  public:
	
	/**
	 * Reads the value of an attribute as an integer. Works on Integer, Real, Dimensioned attributes.<br>
	 * @param iObject
 	 * Knowledge object on which we want to read an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name): it should be
	 * @param oValInt
	 * Value that we will read on the attribute.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the read operation has failed (attribute non existing on object, attribute of a bad type).
	 * 	 <li> S_OK	if the attribute has been read successfully.
	 *  </ol>
     */
	static HRESULT GetValueAsInteger   (const CATICkeObject_var &iObject, 
										const CATUnicodeString& iAttributeName,
										int &oValInt);

    /**
	 * Reads the value of an attribute as a double. Works on Integer, Real, Dimensioned attributes. Note that attributes defined as dimensions must be read as a double.<br>
	 * @param iObject
 	 * Knowledge object on which we want to read an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param oValReal
	 * Value that we will read on the attribute.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the read operation has failed (attribute non existing on object, attribute of a bad type).
	 * 	 <li> S_OK	if the attribute has been read successfully.
	 *  </ol>
     */
	static HRESULT GetValueAsReal      (const CATICkeObject_var &iObject,
										const CATUnicodeString& iAttributeName,
										double &oValReal); 
	
	/**
	 * Reads the value of an attribute as a string. Works on String and enumerated attributes.<br>
	 * @param iObject
 	 * Knowledge object on which we want to read an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param oValString
	 * Value that we will read on the attribute.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the read operation has failed (attribute non existing on object, attribute of a bad type).
	 * 	 <li> S_OK	if the attribute has been read successfully.
	 *  </ol>
     */
	static HRESULT GetValueAsString     (const CATICkeObject_var &iObject,
										 const CATUnicodeString& iAttributeName,
										 CATUnicodeString &oValString);

	/**
	 * Reads the value of an attribute as a boolean. Works only on boolean attributes.<br>
	 * @param iObject
 	 * Knowledge object on which we want to read an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param oValBoolean
	 * Value that we will read on the attribute.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the read operation has failed (attribute non existing on object, attribute of a bad type).
	 * 	 <li> S_OK	if the attribute has been read successfully.
	 *  </ol>
     */
	static HRESULT GetValueAsBoolean    (const CATICkeObject_var &iObject,
										 const CATUnicodeString& iAttributeName,
										 CATBoolean &oValBoolean);

    /**
	 * Reads the value of an attribute as a Time. Works on date attributes<br>
	 * @param iObject
 	 * Knowledge object on which we want to read an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name): it should be
	 * @param oValTime
	 * Value that we will read on the attribute.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the read operation has failed (attribute non existing on object, attribute of a bad type).
	 * 	 <li> S_OK	if the attribute has been read successfully.
	 * 	 <li> S_FALSE	if the attribute is Unset
	 *  </ol>
     */
	static HRESULT GetValueAsTime   (const CATICkeObject_var &iObject, 
									 const CATUnicodeString& iAttributeName,
									 CATTime &oValTime);

	/**
	 * Reads the value of an attribute in a generic manner (as a value). Works in all cases. Must be used to read List attributes.<br>
	 * @param iObject
 	 * Knowledge object on which we want to read an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param oValue
	 * Value that we will read on the attribute.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the read operation has failed (attribute non existing on object, attribute of a bad type).
	 * 	 <li> S_OK	if the attribute has been read successfully.
	 *  </ol>
     */
	static HRESULT GetValue				(const CATICkeObject_var &iObject,
										 const CATUnicodeString& iAttributeName,
										 CATIValue_var          &oValue) ;

   /**
	* Produces a string to represent the value of an attribute on an object.<br>
	* This method produces a value with unit for an attribute with a magnitude.<br>
	* @param iObject
	* object in input. A PLM object.
	* @param iAttributeName
	* Name of the attribute in the Knowledge dictionary (internal name)
	* @param oValueToShow
	* Value to show
	* @param oUnit
	* The unit to show the attribute. If set to NULL, the default unit will be chosen
	* @return classic HRESULT 
	*/
	static HRESULT ShowAttributeValue    (	const CATICkeObject_var &iObject,
											const CATUnicodeString& iAttributeName,
											CATUnicodeString &oValueToShow,
											const CATICkeUnit_var &iUnit = NULL_var);
    
	/**
	 * Reads the value of an attribute and tests if it is set or not. Works in all cases. .<br>
	 * If you need to access the value afterwards, it is more efficient to use GetValue and to access the Unset status on the returned value.<br>
	 * @param iObject
 	 * Knowledge object on which we want to read an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param oIsSetStatus
	 * Unset/Set status of the attribute
	 *  <ol>
	 * 	 <li> TRUE if the attribute is set.
	 * 	 <li> FALSE if the attribute is unset.
	 *  </ol>
	 * TRUE is it is set, FALSE instead
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the read operation has failed (attribute non existing on object, attribute of a bad type).
	 * 	 <li> S_OK	if the attribute has been accessed successfully.
	 *  </ol>
     */
	static HRESULT IsSet				(const CATICkeObject_var &iObject,
										 const CATUnicodeString& iAttributeName,
										 CATBoolean     &oIsSetStatus) ;

	/**
	 * Returns all the PLM attributes of an object (it scans all types that the object supports including extensions). Or fills the values for a list of  attributes in input <br>
	 * @param iObject
 	 * Knowledge object on which we want to list the attributes
	 * @param ioAttributeNameList
	 * List in input that is filled by the method and that returns the attributes names. It should be empty before calling the method. If it is not empty, this method will fill the values for the attributes in this list.<br>
	 * @param ioAttributeValueAsStringList
	 * List in input that is filled by the method and that returns the attributes values as strings. It should be empty before calling the method.
	 * @param ioAttributeValueList
	 * List in input that is filled by the method and that returns the attributes values as values. It should be empty before calling the method.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if iObject is NULL. Or if one of the attributes in the list does not exist on the object.
	 * 	 <li> S_OK	if the attributes have been read successfully.
	 *  </ol>
     */
	static HRESULT GetListOfAttributes	(const CATICkeObject_var &iObject,
										 CATListOfCATUnicodeString  &  ioAttributeNameList,
										 CATListOfCATUnicodeString  &  ioAttributeValueAsStringList,
										 CATLISTV(CATICkeParm_var)  &  ioAttributeValueList); 


	

   /**
	* Produces the NLS name of an attribute for a given object. Used for edit properties/browse properties<br>
	* @param iObject
	* object in input. A PLM object.
	* @param iAttributeName
	* Name of the attribute in the Knowledge dictionary (internal name)
	* @param oNLSName
	* NLS Name of the attribute
    * @return
	*  <ol>
	* 	 <li> E_INVALIDARG if iObject NULL of attribute not found
	* 	 <li> S_FALSE if no NLS translation found: we will return the name of the attribute
	* 	 <li> S_OK if translation found
	*  </ol>
	*/
	static HRESULT GetAttributeNLSNameFromObject	    (	const CATICkeObject_var &iObject,
															const CATUnicodeString& iAttributeName,
															CATUnicodeString &oNLSName);
	

	/**
	* Extends an object by a virtual extension that contains only computed attributes.<br>
	* This method returns an object that enables to access the computed attributes on the object to extend.<br>
	* The implementation of the computed attributs must be done on a late type with a prefix CATInstanceFederation* where * is the name of the extension type.<br>
	* The implementation implements CATIAttributeComputed
	* @param iObjectToDelegateTo
	* object in input 
	* @param iExtensionType
	* Type of the virtual extension
	* @param oFederatedObject
	* Object used to federate attributes
	* @return 
	 *  <ol>
	 * 	 <li> E_INVALIDARG if iObjectToExtend NULL or iExtension NULL).
	 * 	 <li> S_OK	if the instance has been correctly created
	 * 	 <li> E_FAIL	if we didn't find the factory that computes attribute
	 * 	 <li> S_FALSE	if the implementation of the computed attribute cannot work on this object
	 *  </ol>
	 */
	static HRESULT RetrieveInstanceUsedForFederation (const CATICkeObject_var &iObjectToExtend,const CATIType_var &iExtensionType,CATICkeObject_var &oFederatedObject);

	/**
    * Fills the given list with types supported by this object that correspond to customer extensions.
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
	static  HRESULT ListCustomerExtensions(	const CATICkeObject_var &iObject,
											CATListValCATIType_var& iolListOfCATIType ) ;


	/**
	 * Returns a display name for the object in input.<br>
	 * Note that information is computed each time we ask for it. There is no cache.
	 * @param iObject the object in input.
	 * @param oDisplayName the object in output.
	 * @return 
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object in input is NULL.
	 * 	 <li> S_OK	if the type has been retrieved.
 	 * 	 <li> S_FALSE	if the list is empty
	 *  </ol>
	 */
	static  HRESULT ProduceDisplayName (	const CATICkeObject_var &iObject,
											CATUnicodeString &oDisplayName);



};

//-----------------------------------------------------------------------

#endif
