// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCkeObjectAttrWriteServices.h
// Header definition of CATCkeObjectAttrWriteServices
//
//===================================================================
//
// Usage notes:
// - Used to write public attributes (published in CAA) on a Knowledge object
// - Used in particular to write public attributes on a PLM object
//
//===================================================================

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#ifndef CATCkeObjectAttrWriteServices_H
#define CATCkeObjectAttrWriteServices_H

// Module export
#include "CATLifSpecs.h"
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATListValCATICkeParm.h"
#include "CATListOfCATUnicodeString.h"

class CATICkeObject_var;
class CATIType_var;
class CATIValue_var;
class CATUnicodeString;
class CATTime;

/**
 * Services to easily write attribute values on a Knowledge object.<br>
 * <b>Role</b>: A Knowledge object implements CATICkeObject. These services enable to valuate its attributes values.<br>
 * Note also that if the object does not publish its attributes it CAA (CATICkeObject::IsPublic), those services do not work.<br>
 * @see CATIValue, CATICkeObject, CATCkeObjectAttrReadServices
 */
class ExportedByCATLifSpecs CATCkeObjectAttrWriteServices
{

  public:

    /**
	 * Sets the value of an attribute as an integer . Works on Integer, Real, Dimensioned attributes.<br>
	 * @param iObject
 	 * Knowledge object on which we want to write an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param iValInt
	 * Value that we want to use to set the attribute value.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the valuation has failed (attribute non existing on object, attribute of a bad type).
	 * 	 <li> E_ACCESSDENIED if the valuation has failed (read only attribute, object not editable).
	 * 	 <li> S_OK	if the attribute has been set successfully.
	 * 	 <li> E_FAIL otherwise.
	 *  </ol>
     */
	static HRESULT SetValueWithInteger (const CATICkeObject_var &iObject, 
										const CATUnicodeString& iAttributeName,
										int iValInt);

	/**
	 * Sets the value of an attribute as a double .Works on Integer, Real, Dimensioned attributes. Note that attributes defined as dimensions must be written as a double.<br>
	 * @param iObject
 	 * Knowledge object on which we want to write an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param iValReal
	 * Value that we want to use to set the attribute value.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the valuation has failed (attribute non existing on object, attribute of a bad type).
	 * 	 <li> E_ACCESSDENIED if the valuation has failed (read only attribute, object not editable).
	 * 	 <li> S_OK	if the attribute has been set successfully.
	 * 	 <li> E_FAIL otherwise.
	 *  </ol>
     */
	static HRESULT SetValueWithReal    (const CATICkeObject_var &iObject,
										const CATUnicodeString& iAttributeName,
										double iValReal); 

	/**
	 * Sets the value of an attribute as a string . Works on String and enumerated attributes.<br>
	 * @param iObject
 	 * Knowledge object on which we want to write an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param iValString
	 * Value that we want to use to set the attribute value.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the valuation has failed (attribute non existing on object, attribute of a bad type).
	 * 	 <li> E_ACCESSDENIED if the valuation has failed (read only attribute, object not editable).
	 * 	 <li> S_OK	if the attribute has been set successfully.
	 * 	 <li> E_FAIL otherwise.
	 *  </ol>
     */
	static HRESULT SetValueWithString   (const CATICkeObject_var &iObject,
										 const CATUnicodeString& iAttributeName,
										 const CATUnicodeString &iValString);

	/**
	 * Sets the value of an attribute as a boolean .Works only on boolean attributes<br>
	 * @param iObject
 	 * Knowledge object on which we want to write an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param iValBoolean
	 * Value that we want to use to set the attribute value.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the valuation has failed (attribute non existing on object, attribute of a bad type).
	 * 	 <li> E_ACCESSDENIED if the valuation has failed (read only attribute, object not editable).
	 * 	 <li> S_OK	if the attribute has been set successfully.
	 * 	 <li> E_FAIL otherwise.
	 *  </ol>
     */
	static HRESULT SetValueWithBoolean  (const CATICkeObject_var &iObject,
										 const CATUnicodeString& iAttributeName,
										 const CATBoolean iValBoolean);
	/**
	 * Sets the value of an attribute as a time .Works only on Date attributes<br>
	 * @param iObject
 	 * Knowledge object on which we want to write an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param iValTime
	 * Value that we want to use to set the attribute value.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the valuation has failed (attribute non existing on object, attribute of a bad type).
	 * 	 <li> E_ACCESSDENIED if the valuation has failed (read only attribute, object not editable).
	 * 	 <li> S_OK	if the attribute has been set successfully.
	 * 	 <li> E_FAIL otherwise.
	 *  </ol>
     */
	static HRESULT SetValueWithTime (const CATICkeObject_var &iObject,
								     const CATUnicodeString& iAttributeName,
									 const CATTime &iValTime );
	/**
	 * Sets the value of an attribute in a generic manner (as a value) .<br>
	 * @param iObject
 	 * Knowledge object on which we want to write an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param iValue
	 * Value that we want to use to set the attribute value.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the valuation has failed (attribute non existing on object, attribute of a bad type).
	 * 	 <li> E_ACCESSDENIED if the valuation has failed (read only attribute, object not editable).
	 * 	 <li> S_OK	if the attribute has been set successfully.
 	 * 	 <li> E_FAIL otherwise.
	 *  </ol>
     */
	static HRESULT SetValue				(const CATICkeObject_var &iObject,
										 const CATUnicodeString& iAttributeName,
										 const CATIValue_var& iValue );

	/**
	 * To prepare valuation of attributes from the explicit PLM factories we provide a service to create a Value from a type/attribute name and attribute value written as a string .<br>
	 * Note that this services only eases the creation of a CATIValue. It does not take into account information hold by the attribute like default value and so forth.<br>
	 * This service will work on basic values (boolean, string, integer, real, dimensions, enumerated values. It does not work on Lists.<br>
	 * @param iType
	 * Knowledge type
	 * @param iAttributeName
	 * Name of the attribute
	 * @param iValueAsString
	 * Value as a string to create the attribute. If you give "", we will create a parameter with default value
	 * @param oValue
	 * Value in output
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the creation of the value has failed (bad attribute regarding to type, or string cannot be converted.
	 * 	 <li> S_OK	if the value has been successfully created.	 
	 * 	 <li> E_FAIL otherwise.
	 *  </ol>
	 */
	static HRESULT CreateValueFromString	(const CATIType_var     &iType,
											 const CATUnicodeString &iAttributeName,
											 const CATUnicodeString &iValueAsString,
										     CATIValue_var          &oValue) ;
	/**
	 * To prepare valuation of attributes from the explicit PLM factories we provide a service to create a list of Values from a list of type/attribute name and attribute value written as a string .<br>
	 * Note that this services only eases the creation of a CATIValue. It does not take into account information hold by the attribute like default value and so forth.<br>
 	 * This service will work on basic values (boolean, string, integer, real, dimensions, enumerated values. It does not work on Lists.<br>
     * @param iType
	 * Knowledge type
	 * @param piListAttributeName
	 * List containing names of the attribute
	 * @param piListValueAsString
	 * List containing Value as a string to create the attribute. If you give "", we will create a parameter with default value<br>.
	 * The two list must have same size.
	 * @param oListOfValue
	 * List that will be filled by the service. We do not empty the list at the beginning so that you can use the service several time.<br>
	 * In case of error for one element, we won't fill the list
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the creation of one of the values has failed (bad attribute regarding to type, or string cannot be converted).
	 * 	 <li> S_OK	if the value has been successfully created.
	 * 	 <li> E_FAIL otherwise.
	 *  </ol>
	 */
	static HRESULT CreateListOfValuesFromListOfStrings	(const CATIType_var     &iType,
														 const CATListOfCATUnicodeString *piListAttributeName,
														 const CATListOfCATUnicodeString *piListValueAsString,
														 CATLISTV(CATICkeParm_var) &oListOfValue );


	

};

//-----------------------------------------------------------------------

#endif
