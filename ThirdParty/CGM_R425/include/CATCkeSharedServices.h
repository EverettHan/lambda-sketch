// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCkeSharedServices.h
// Header definition of CATCkeSharedServices
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  July 2007  Creation: Code generated by the CAA wizard  frh
//===================================================================

#ifndef CATCkeSharedServices_H
#define CATCkeSharedServices_H

// Module export
#include "CATLifSpecs.h"

#include "CATTime.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATIParmVariable.h"
#include "CATIForwardsDecl.h"
#include "CATListValCATIType.h"
#include "CATIKweVolatileSheetFactory.h"
#include "CATListValCATICkeParm.h"
#include "CATICkeUnit.h"
#include "CATListOfCATUnicodeString.h"
#include "CATIParmDictionary.h"
#include "CATListValCATAttributeInfos.h"
#include "CATListOfDouble.h"
#include "CATListPV.h"

class CATUnicodeString;
class CATICkeParm_var;
class CATICkeType_var;
class CATIInstance_var;
class CATAttributeInfos;
class CATIParmPublisher_var;
class CATICkeParmFactory_var;
class CATCkeEvalContext;
class CATIList_var;
class CATIEnumere_var;
class CATInstanciationContext;
class CATCkeLanguageServices;

typedef unsigned long CATCkeSubCharacteristicChoice;

 
//-----------------------------------------------------------------------
/**
 * Shared services for Knowledge. Those services, usually, reuse the interfaces to provide higher level services<br>
 * Those services are intented to be used by DS applications (& Knowledge toolkits)<br>
 * One important class of services are the ones that enables to access methods on CATICkeObject (that can be a CATIInstance or a CATIExposeObject).
 * You have also the services equivalent of CATCkeObjectAttrWriteServices and CATCkeObjectAttrReadServices that can be used internally and that violates the CAA protection.
 */
class ExportedByCATLifSpecs CATCkeSharedServices
{

  public:

	//--------------------------------------------------------
	// Basic services for accessing values and types
	//--------------------------------------------------------
	
	/**
	* Returns 1 if iParameter type is a kind of iType, 0 if not.
	* works on any parameter (value (persistent or volatile), object with multi typing, list, pointer
	* There are two intents in using this method
	*   -1- you may be interested to control the strict belonging of a parameter to a given type hierarchy
	*   -2- you may want to know if such a value (the iParameter) can be used at a place where a type iType is expected.
	* Those two sentences may seem 100% equivalent, especially if you think of the type of an object. Because you can use a parameter of type A when we expect a type B if A isakindof B
	* But we have a particular behavior on real values (real includes, real but also integers and dimensioned values).
	* We authorize the usage of any kind of real value when any kind of real value is expected.
	* For example, we can use a Length where an int is expected...
	* So if you want to control strictly the type (case 1), use strict=1
	* So if you do not want to control strictly the type (case 2), use strict=0 which is the default
	*/
	static int IsaKindOf(const CATICkeParm_var& iParameter, const CATICkeType_var& iType,const int strict = 0 );

	/**
	* Returns 1 if iObject is a kind of iType, 0 if not.
	* works on any Object: if it is a CATIInstance, a CATICkeFeaure, a CATICkeParm (calling previous one) and eventually nothing (answer is 0 in this case
	* There are two intents in using this method
	*   -1- you may be interested to control the strict belonging of a parameter to a given type hierarchy
	*   -2- you may want to know if such a value (the iParameter) can be used at a place where a type iType is expected.
	* Those two sentences may seem 100% equivalent, especially if you think of the type of an object. Because you can use a parameter of type A when we expect a type B if A isakindof B
	* But we have a particular behavior on real values (real includes, real but also integers and dimensioned values).
	* We authorize the usage of any kind of real value when any kind of real value is expected.
	* For example, we can use a Length where an int is expected...
	* So if you want to control strictly the type (case 1), use strict=1
	* So if you do not want to control strictly the type (case 2), use strict=0 which is the default
	*/
	static int IsaKindOfObject (const CATBaseUnknown_var & iObject, const CATICkeType_var& iType,const int strict = 0 );

	/**
	 * This service returns the identification of a parameter 
	 */
	static 	HRESULT IdentifyParameter (const CATICkeParm_var &Parameter,CATIParmVariable::ParameterIdentification &oIdentification);

	// Indicates if a parameter is an object (other than list)
	static int IsaReferenceToObject (const CATICkeType_var& iType);
	
	// Indicates if a parameter is a List
	static int IsaList (const CATICkeType_var& iType);


	//--------------------------------------------------------
	// Services that lists attributes of an object: by concatenating information on the types of the object
	//--------------------------------------------------------

	// Finds an attribute from its name and starting from an object
	// It scans the types implemented by the object to find the attribute on the type
	// Returns E_INVALIDARG if attribute is not found
	// oAttributeInfos is allocated and must be deleted
	static HRESULT FindAttributeFromNameAndObject    (const CATUnicodeString &iName,const CATICkeObject_var &iObject,CATAttributeInfos*& oAttributeInfos);
	static HRESULT FindAttributeFromNLSNameAndObject (const CATUnicodeString& iNLSName,const CATICkeObject_var &iObject,CATAttributeInfos*& oAttributeInfos )  ;

	// Finds an attribute from its name and starting from an object
	// It scans the types implemented by the object to find the attribute on the type
	// Returns E_INVALIDARG if attribute is not found
	// oAttributeInfos is allocated and must be deleted
	// oType is valuated and contains the type that owns the attribute. Note that it is not the precise type (the exact type that contains the attribute). It is the type that may have the attribute due to inheritance
	static HRESULT FindAttributeAndTypeFromNameAndObject (const CATUnicodeString &iName,const CATICkeObject_var &iObject,CATAttributeInfos*& oAttributeInfos,CATIType_var &oType);

	// Finds the precise type that contains an attribute (in the hierarchy)
	// Returns E_INVALIDARG if attribute is not found
	// oAttributeInfos is allocated and must be deleted
	// oType is valuated and contains the precise type that owns the attribute
	// Note that by combining FindAttributeAndTypeFromNameAndObject and this method you can find the righ type starting from an object
	static HRESULT FindAttributeAndPreciseTypeFromNameAndType (const CATUnicodeString &iName,const CATIType_var &iType,CATAttributeInfos*& oAttributeInfos,CATIType_var &oPreciseType);

	
	/**
	*	Returns the list of informations on attributes held by the object.<br>
	*   @param iObject : the object
	*   @param oListOfAttributeInfos : the list of attributes in input that is filled by the service
	*	@param recursively : if true, the output list will also contain the attributes given by 
	*	the inheritance mechanism provided by CATIType
	*/
	static HRESULT ListAttributes (const CATICkeObject_var &iObject,CATListValCATAttributeInfos* oListOfAttributeInfos, boolean recursively = 1 ) ;



	//--------------------------------------------------------
	// Services that federates the access to common methods of a CATIInstance or a CATIExposeObject
	// CATIInstance is the implementation of a Knowledge object by DS
	// CATIExposeObject is the implementation of a Knowledge object by a partner
	// Software that wants to be independent of this duality must use these services.
	//--------------------------------------------------------
	/**
	* Indicates if an object supports a given type.
	* @param iObject the object. 
	* @param iType the type. 
	* @return [CATBaseUnknown#Release] the object itself or another one that supports the type (an AddRef is done, if not NULL).
	*/
	static CATICkeObject *  IsSupporting( const CATICkeObject_var &iObject,const CATIType_var& iType );
	// Returns the list of types supported by an object
	static HRESULT			ListSupportedTypes( const CATICkeObject_var &iObject,CATListValCATIType_var& iolListOfCATIType ) ;

	/** 
	* Gets the value of an attribute on an object.
	* You can also used more precise services that converts the value in the right format.
	* @param iObject the object. 
	* @param iKey name of the attribute
	* @return [CATBaseUnknown#Release] the value (an AddRef is done, if not NULL).
	*/
	static CATIValue*		GetValue( const CATICkeObject_var &iObject,const CATUnicodeString& iKey ); 

	/**
	* Sets the value of an attribute on an object.
	* You can also used more precise services that converts the value in the right format.
	*/
	static HRESULT			SetValue( const CATICkeObject_var &iObject, const CATUnicodeString& iKey, const CATIValue_var& iValue );

	/**
	* Returns the type of an object (main type).
	* @param iObject the object. 
	* @return [CATBaseUnknown#Release] the type (an AddRef is done, if not NULL).
	*/
	static CATIType*		Type( const CATICkeObject_var &iObject) ;

	/**
    * Returns the owner of the object (in terms of tree aggregation.<br> 
	* May be NULL. An AddRef is done
	* @return  [CATBaseUnknown#Release] the owner of the object..
	*/
	static CATICkeObject* GetOwner(const CATICkeObject_var &iObjec);

	//-------------------------------------------------------------------------------------
	// Services equivalent to CATCkeObjectAttrReadServices without the CAA protection
	// Enables also to access computed attributes
	//-------------------------------------------------------------------------------------
	 /**
	 * Reads the value of an attribute as an integer. Works on Integer, Real, Dimensioned attributes.<br>
	 * @param iObject
 	 * Knowledge object on which we want to read an attribute.
	 * @param iKey
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
	 * @param iKey
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
	 * @param iKey
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
	 * @param iKey
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
	 * @param iKey
	 * Name of the attribute in the Knowledge dictionary (internal name): it should be
	 * @param oValTime
	 * Value that we will read on the attribute.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the read operation has failed (attribute non existing on object, attribute of a bad type).
	 * 	 <li> S_OK	if the attribute has been read successfully.
	 *  </ol>
     */
	static HRESULT GetValueAsTime   (const CATICkeObject_var &iObject, 
									 const CATUnicodeString& iAttributeName,
									 CATTime &oValTime);
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

	
	

	//-------------------------------------------------------------------------------------
	// Services equivalent to CATCkeObjectAttrWriteServices without the CAA protection
	// Enables also to access computed attributes
	//-------------------------------------------------------------------------------------
    /**
	 * Sets the value of an attribute as an integer . Works on Integer, Real, Dimensioned attributes.<br>
	 * @param iObject
 	 * Knowledge object on which we want to write an attribute.
	 * @param iKey
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
	 * @param iKey
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
	 * @param iKey
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
	 * @param iKey
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
	 * @param iKey
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
	

	//--------------------------------------------------------
	// Services that encapsulates a call to CATIParmPublisher::AppendElement, CATIParmPublisher::RemoveElement, and CATIParmPublisher::GetFactory to ease internal migration
	//--------------------------------------------------------
	static void AppendElement  (const CATIParmPublisher_var &iPublisher,const CATBaseUnknown_var & iObject )    ;
    static void RemoveElement  (const CATIParmPublisher_var &iPublisher,const CATBaseUnknown_var & iObject )    ;
    static CATICkeParmFactory_var GetFactory (const CATIParmPublisher_var &iPublisher) ;
	 

	//--------------------------------------------------------
	// Service that returns the attribute used on a PLMEntity of a given type, to be used as the logical name.
	// This service may invoke a business rule. Result can be no attribute defined!
	// HRESULT=E_INVALIDARG if iType is NULL_var
	//--------------------------------------------------------
	static HRESULT          GetAttributeUsedForLogicalName (const CATIType_var &iType,CATUnicodeString &oAttributeName);

	//--------------------------------------------------------
	// Service that returns the list of attributes used on a PLMEntity of a given type, to be used as the display name.
	// This service may invoke a business rule. Result can be no attribute defined!
	// HRESULT=E_INVALIDARG if iType is NULL_var
	//--------------------------------------------------------
	static HRESULT          GetAttributesUsedForDisplayName (const CATIType_var &iType,CATListOfCATUnicodeString &oAttributeNames);



	
	//--------------------------------------------------------
	// Services that find the online help associated with an attribute, a type, a method
	//--------------------------------------------------------
	// In input, the package name and the method name. 
	// In output the documentation long help if if any
	// HRESULT =S_OK if found, E_FAIL if not found
	static HRESULT ComputeLongHelpIdForMethod (const CATUnicodeString &iPackageName,const CATUnicodeString &iMethodName,CATUnicodeString &oLongHelpId);

	// In input, the package name, the type name and the attribute name (empty to access to online help for the type). 
	// In output the documentation long help if if any
	// HRESULT =S_OK if found, E_FAIL if not found
	static HRESULT ComputeLongHelpIdForType (const CATUnicodeString &iPackageName,const CATUnicodeString &iTypeName,const CATUnicodeString &iAttributeName,CATUnicodeString &oLongHelpId);

	// Computes the NLS name of the package (which is set in the CATPackage***.CATNls file
	// Returns E_FAIL if the NLS name is not found. In this case, we set the NLS name in output with the internal name
	static HRESULT ComputePackageNLSName (const CATUnicodeString &iPackageName,CATUnicodeString &iPackageNLSName);

	// Replaces in a string the " " by a "_" in order to build the name of a CATNls file or the name of a key in the CATNlsFile 
	static HRESULT GenerateNameForNLSKey (const CATUnicodeString &iName,CATUnicodeString &oNameForKey);



	//--------------------------------------------------------
	// Services to call when implementing CATIInstance::SetValue
	//--------------------------------------------------------
	/**
	 * We may be interested to check the validity of a value before setting an attribute with it. This method does it.<br>
     * At the moment, it will check only STRING attributes regarding the MaxLength.<br>
	 * Note that you may use FindAttributeFromNameAndObject service to retrieve the attribute from its name (and the object). It is not very performant.<br>
	 * @param iValue
	 * Value that we want to check.<br>
	 * @param iAttribute
	 * Attribute that we want to valuate.<br>
	 * @param iRaiseEvaluationError
	 * TRUE if we want to raise an evaluation error explaining what is the problem.<br>
	 * @return
	 *  <ol>
	 * 	 <li> S_OK	if the value is correct 
	 * 	 <li> E_INVALIDARG if the iValue is NULL
	 * 	 <li> E_FAIL otherwise.
	 *  </ol>
	 */
	static HRESULT CheckValueValidity (const CATIValue_var &iValue, const CATAttributeInfos &iAttribut, const CATBoolean iRaiseEvaluationError = TRUE );

	/**
	 * We may be interested to check the validity of a value before setting an attribute with it. This method does it.<br>
     * At the moment, it will check only STRING attributes regarding the MaxLength.<br>
	 * Note that you may use FindAttributeFromNameAndObject service to retrieve the attribute from its name (and the object). It is not very performant.<br>
	 * @param iValue
	 * Value that we want to check.<br>
	 * @param iType
	 * Type of the object<br>
	 * @param iAttribute
	 * Attribute that we want to valuate.<br>
	 * @param iRaiseEvaluationError
	 * TRUE if we want to raise an evaluation error explaining what is the problem.<br>
	 * @param oValue
	 * New value in output computed if possible.<br>
	 * @return
	 *  <ol>
	 * 	 <li> S_OK	if the value is correct 
	 * 	 <li> E_INVALIDARG if the iValue is NULL
	 * 	 <li> S_FALSE if the value is not correct but we succeeded in computing the output value.
	 * 	 <li> E_FAIL otherwise.
	 *  </ol>
	 */
	static HRESULT CheckValueValidityAndApplyCorrection (const CATICkeObject_var &iObject,const CATIValue_var &iValue, const CATIType_var &iType,const CATAttributeInfos &iAttribut, CATIValue_var &oValue,const CATBoolean iRaiseEvaluationError = TRUE );

	 /**
	  * Valuates a parameter, taking into account the manipulator
      *    <li> E_INVALIDARG if iObject NULL or not recognized bu the factory.
      *    <li> S_OK if the valuation has been successful
      *    <li> E_ACCESSDENIED if iObject cannot be valuated with this value
      */
	 static HRESULT ValuatesAttributeValueWihRange(const CATICkeParm_var &pParmToValuate,const CATICkeParm_var &pParmValue,CATBoolean iRaiseEvaluationError=FALSE);






 	//--------------------------------------------------------
	// Other services for applications 
	//--------------------------------------------------------

	/**
	 * Returns a volatile sheet factory instance.
	 */
	static CATIKweVolatileSheetFactory_var GetVolatileSheetFactory();


	 
	//--------------------------------------------------------
	// Internal services for Knowledge 
	//--------------------------------------------------------

	 /**
	 * Loads a text file and converts it into a string
	 * @param iScriptFilePath
	 * File path (containing the extension)
	 * @param oScriptBody
	 * String filed
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if script file is empty does not correspond to an existing file
	 * 	 <li> S_OK	if the list of attributes is valuated (even if empty)
	 *  </ol>
     */
    static HRESULT LoadScriptFromFile (const CATUnicodeString& iScriptFilePath, CATUnicodeString& oScriptBody);

	// Positions the BR traces 
	static  void  BusinessRulesTrace (int b) ;

	// Reads the BR traces 
    static  int   BusinessRulesTrace () ;

	// In CATCkeInstance implementation we use parameter to model attributes and we need to indicate if they are read only
	static void MarkParmAsAttributeReadOnly (const CATICkeParm_var &iParm);
	static CATBoolean ReadParmAsAttributeReadOnlyStatus (const CATICkeParm_var &iParm);

	/** 
	 * Service used to propagate some sub characteristics from one parameter to another one.<br>
	 * Note that parameters must be of the same type (not checked by the method). Usually destination parameter was created from origin parameter.<br>
	 * Sub characteristics are set-unset status, constance, show, list of authorized values, ranges.<br>
	 * @param iOriginParameter
	 * Parameter that contains the sub characteristics.<br>
	 * @param iDestinationParameter
	 * Parameter where we want to copy the subcharacteristics.<br>
	 * @param iChoice
	 * Choice expressed as a combination.<br>
	 * @return
	 */
    static const CATCkeSubCharacteristicChoice  NoCharacteristic;         
    static const CATCkeSubCharacteristicChoice  UnsetCharacteristic;         
    static const CATCkeSubCharacteristicChoice  ConstCharacteristic;       
	static const CATCkeSubCharacteristicChoice  AuthorizedValuesCharacteristic;  
	static const CATCkeSubCharacteristicChoice  MinMax;        
	static const CATCkeSubCharacteristicChoice  All;         
	static HRESULT PropagateParameterSubCharacteristics (const CATICkeParm_var &iOriginParameter, const CATICkeParm_var &iDestinationParameter,
												  		const CATCkeSubCharacteristicChoice iChoice = NoCharacteristic);

	// Extracts strings separated by a separator 
	// returns S_OK 
	static HRESULT ExtractStrings (const CATUnicodeString &iStringOrigin,const CATUnicodeString &iSeparator,CATListOfCATUnicodeString& oListStrings);
	// returns S_FALSE if some types do not exist. they are ignored
	static HRESULT ExtractTypes (const CATUnicodeString &iStringOrigin,const CATUnicodeString &iSeparator,const CATUnicodeString &iMessage,CATListValCATIType_var& iolListOfCATIType);

	/**
	 *   Default implementation of suppress object on CATIDelegateInstanciation
     *   SuppressObject (remove an object or suppress an extension).<br>
     *   @param iObject
     *   Object to suppress or on which we want to suppress the extension.
     *   @param iType
     *   Type of the extension to suppress
	 *	 @param iContext the context of removal
	 *   @return
     *  <ol>
     *    <li> E_INVALIDARG if iObject NULL or not recognized bu the factory.
     *    <li> S_OK if the suppression of the object succeeded
     *    <li> E_ACCESSDENIED if iObject cannot be suppressed.
     *  </ol>
     */
     static HRESULT SuppressObjectDefaultImplementation ( const CATICkeObject_var& iObject,const CATIType_var &iType,const CATCkeEvalContext *iContext) ;

	
	 /**
	  * converts a list of values (as strings) corresponding to enum values, to list of double (from 1 to N)
	  * return E_FAIL, if one of the values is not recognized
	  * List in output is not emptied
	  */
	 static HRESULT ConvertEnumeratedValueToDoubles (const CATIEnumere_var &iEnumere,const CATListOfCATUnicodeString &oListValueAsString,CATListOfDouble &oListValueAsDouble);

	 /**
	  * converts a list of values (as doubles) corresponding to enum values, to list of strings (from 1 to N)
	  * return E_FAIL, if one of the values is not recognized
	  * If enum is NULL, we convert double as strings
	  * List in output is not emptied
	  */
	 static HRESULT ConvertEnumeratedValueToStrings (const CATIEnumere_var &iEnumere,const CATListOfDouble &oListValueAsDouble,CATListOfCATUnicodeString &oListValueAsString);

   /**
	  * converts a list of values (as strings) as produced by EKL to a standard list of strings
	  * return E_FAIL, if one of the values is not recognized
	  * List in output is not emptied
	  */
	 static HRESULT ConvertListToStrings (const CATIList_var &iList,CATListOfCATUnicodeString &oListValueAsString);

   /**
	  * converts a standard list of strings to a list of values (as EKL list) as produced by EKL 
	  * return E_FAIL, if one of the values is not recognized
	  * List in output is not emptied
	  */
   static HRESULT ConvertStringsToList (const CATListOfCATUnicodeString &oListValueAsString,const CATIList_var &iList);

   /**
	 * Used to indicate that an open was launched and avoir open re-entrance issues
	 */
	static void SetDuringOpen(CATBoolean iValue);
	static CATBoolean IsDuringOpen();

private: 

	static int _btrace;
	static CATIParmDictionary_var _pdic;

	static CATBoolean _OpenOnGoing;

};

//-----------------------------------------------------------------------

#endif