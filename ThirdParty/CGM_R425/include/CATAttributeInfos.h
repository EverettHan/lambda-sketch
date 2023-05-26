#ifndef CATAttributeInfos_h
#define CATAttributeInfos_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/*  CAA2Reviewed */

#include "CATLifSpecs.h"
#include "CATUnicodeString.h"
#include "CATIType.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfDouble.h"
#include "CATSysBoolean.h"

#include "CATICkeParm.h"
#include "CATListValCATICkeParm.h"

class CATICkeUnit_var;
class CATAttributeInfosAbstractLetter;
class CATIValue_var;
class CATIAttributesController_var;

/**
* Class to be used to define attributes of a Knowledge type.<br>
* <b>Role</b>: A Knowledge type is defined as a collection of attributes with names and characteristics. This class is the definition of such an attribute.<br>
* <p>

* @see CATIAttributesDescription, CATITypeDictionary#CreateType, CATIType, CATICkeObject, CATIAttributeComputed
*/

class ExportedByCATLifSpecs CATAttributeInfos {
public:
	/**
	 * Copy constructor.
	 * @param iInfos attribute to be copied.
	 */
	CATAttributeInfos( const CATAttributeInfos& iInfos );

	/**
	* Constructor: this constructor is made for standard attributes creation. It is available for applications that are defining their types.
	* For PLM attributes, see at the end of this header file.
	*
	* @param iType            Type the attribute is added to.
	* @param iName            Internal name of the attribute.
	* @param iNLSName         NLS (user) name of the attribute.
	* @param isWriteable      TRUE if the attribute can be modified, else FALSE. Default is TRUE.
	* @param isComponent      TRUE if the attribute contains a component. If TRUE,
	*                         the component's owner should be the owner of the attribute, and its
	*                         name the attribute name. Default is FALSE.
	* @param isVisible        TRUE if the attribute is visible by the user, else FALSE. Default is TRUE.
	* @param iAttributeAccess Only Use the Default Value = "".<br>
	*						  (Name of the CATIAttributeComputed implementation class used to
	*                         delegate the valuation of this particular attribute)
	* Note finally, that by default, an attribute is not mandatory
	*/
	CATAttributeInfos( const CATIType_var& iType,
					   const CATUnicodeString& iName,
					   const CATUnicodeString& iNLSName,
					   const boolean isWriteable = 1,
					   const boolean isComponent = 0,
					   const boolean isVisible = 1,
					   const CATUnicodeString& iAttributeAccess = "");

	/**
	 * Destructor.
	 */
	virtual  ~CATAttributeInfos();

	/**
	* Returns the type the attribute belongs to.
	*
	* @return a type.
	*/
	CATIType_var Type() const;

	/**
	* Returns the internal name of the attribute.
	*
	* @return a string.
	*/
	CATUnicodeString Name() const;

	/**
	* @nodoc to be suppressed
	* Sets the NLS name of the attribute.
	*
	* @return void.
	*/
	void SetNLSName(const CATUnicodeString &iNlsName);

	/**
	* Returns the visibility of the attribute.
	*
	* @return TRUE if visible, else FALSE.
	*/
	boolean IsVisible() const;

	/**
	* Returns the writability of the attribute.
	*
	* @return TRUE if writable, else FALSE.
	*/
	boolean IsWritable() const;

	/**
	* Returns the aggregability of the attribute.
	*
	* @return TRUE if it an aggregation, else FALSE.
	*/
	boolean IsComponent() const;

	/**
	* Do Not Use this method.
	* Returns the name of the CATIAttributeComputed implementation.
	* @return a string.
	*/
	const CATUnicodeString& GetAttributeAccess() const;

	/**
	 * Operator to compare equality.
	 * @param iInfos Attribute to be compared with.
	 * @return Result of the comparison.
	 */
	boolean           operator==(const CATAttributeInfos& iInfos ) const;

	/**
	 * Operator to compare difference.
	 * @param iInfos Attribute to be compared with.
	 * @return Result of the comparison.
	 */
	boolean           operator!=(const CATAttributeInfos& iInfos ) const;

	/**
	 * Operator to affect a value.
	 * @param iInfos Value to valuate with.
	 * @return Handler on the attribute itself
	 */
	CATAttributeInfos &operator=(const CATAttributeInfos& iInfos ) ;

	/**
	* Returns the dynamicity of the attribute. Default value is FALSE.
	*
	* @return TRUE if it is a dynamic attribute, FALSE instead
	*/
	boolean IsDynamic() const;
	/**
	* Indicates if the attribute is dynamically added on an object.
	*/
	void    SetDynamic() ;

	/**
	* Indicates if the attribute is mandatory. It means that this attribute must always be filled on the object.
	*
	* @return TRUE if it is mandatory, else FALSE.
	*/
	boolean IsMandatory () const;

	/**
	* This method returns a standard attribute accessor (to be passed as 7th argument in CATAttributeInfos constructor).
	* that enables to read and/or write attributes by Knowledge rules.
	* @return The standard attribute accessor.
	*/
	static CATUnicodeString AccessByRule () ;

	/**
	* Indicates if the attribute is a simple one (a value) or if it is a reference to an object, or list of object.
	*
	* @return TRUE if simple, else FALSE.
	*/
	boolean IsSimple() const;

	/**
	* Indicates if the attribute is computed with an attribute access.
	*
	* @return TRUE if writable, else FALSE.
	*/
	boolean IsComputed() const;

	/**
	 * Returns the maximum length for a string attribute.<br>
	 * @return 0 by default
	 */
	int GetMaxLength() const ;

	/**
	 * Returns if objects using this attribute will get an implicit default value at creation.
	 * @param oHasImplicitDefaultValue
	 *  <ol>
	 * 	 <li> TRUE	if the objects will get an implicit default value.
	 *   <li> FALSE	if the objects will not get an implicit default value.
	 *  </ol>
	 * @return
	 * <ol>
	 * 	 <li> S_OK	oHasImplicitDefaultValue can be used.
	 *   <li> S_FALSE This method does not apply to the attribute.
	 *  </ol>
	 */
	HRESULT HasImplicitDefaultValue(boolean &oHasImplicitDefaultValue) const;

	/**
	 * Returns the default value if any.<br>
	 * @param oDefaultValue
	 * Default value in output if any, NULL_var by default.
	 * @return
	 *  <ol>
	 * 	 <li> S_OK	if default value has been defined.
	 *   <li> S_FALSE	if no default value was defined.
	 *  </ol>
	 */
	HRESULT GetDefaultValue(CATICkeParm_var & oDefaultValue) const;

	/**
	 * Returns the help values if any.<br>
	 * @param oListValueAsString
	 * The list if filled with values as strings.
 	 * @param opListValueAsStringNLS
	 * The list if filled with values as strings translated if necessary. If NULL, then it is not used
	 * @return
	 *  <ol>
	 * 	 <li> S_OK	if help values have been filled.
	 *   <li> S_FALSE	if no help values defined. List is emptied.
	 *  </ol>
	 */
	HRESULT GetHelpValues (CATListOfCATUnicodeString &oListValueAsString) const;

	/**
	 * Returns the help values if any.<br>
	 * @param oListValueAsDouble
	 * The list if filled with values as double.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the attribute is not of type real/integer/dimension
	 * 	 <li> S_OK	if help values have been filled.
	 *   <li> S_FALSE	if no help values defined. List is emptied.
	 	 *  </ol>
	 */
	HRESULT GetHelpValues (CATListOfDouble &oListValueAsDouble) const;

	/**
	 * Returns the NLS Name of an attribute in the context of a type. A same attribute can have 2 NLS names for two types of the same hierarchy.<br>
	 * @param iType
	 * The type that contains the attribute
	 * @param iAttribute
	 * The attribute
	 * @param oNLSName
	 * The NLS Name in output
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the attribute is not part of this type
	 * 	 <li> E_FAIL if the NLS name has not been found
	 * 	 <li> S_OK	if NLS name has been retrieved
 	 *  </ol>
	 */
	static HRESULT GetNLSName(const CATIType_var &iType,const CATAttributeInfos &iAttribute,CATUnicodeString &oNLSName);

	/**
	 * Returns the authorized values if any (use TranslateValues to get NLS translations).<br>
	 * @param oListValueAsString
	 * The list is filled with values as strings.
	 *  <ol>
	 * 	 <li> S_OK	if authorized values have been filled.
	 *   <li> S_FALSE	if no authorized values defined. List is emptied.
 	 *  </ol>
	 */
	HRESULT GetAuthorizedValues (CATListOfCATUnicodeString &oListValueAsString) const;

	/**
	 * Returns the authorized values if any.<br>
	 * @param oListValueAsDouble
	 * The list if filled with values as double.
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the attribute is not of type real/integer/dimension
	 * 	 <li> S_OK	if authorized values have been filled.
	 *   <li> S_FALSE	if no authorized values defined. List is emptied.
 	 *  </ol>
	 */
	HRESULT GetAuthorizedValues (CATListOfDouble &oListValueAsDouble) const;

	/**
	 * Indicates if the attribute values need to be translated.<br>
	 * Must be called before calling TranslateValue for performance considerations.
	 * @param iType
	 * The type that contains the attribute
	 * @param iAttribute
	 * The attribute
	 * @param oRequiresTranslation
	 * TRUE if the attribute values require translation
	 * @param pListOValue
	 * If not NULL, will be filled with the list of values to be translated
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the attribute is not part of this type
	 * 	 <li> S_OK	instead
 	 *  </ol>
	 */
	static HRESULT RequireTranslationForValues (const CATIType_var &iType,const CATAttributeInfos &iAttribute,CATBoolean &oRequiresTranslation,CATListOfCATUnicodeString *pListOValue = NULL);

	/**
	 * Translates the value of an attribute in the context of a type.<br>
	 * You may call RequireTranslationForValues before to optimize performance.
	 * @param iType
	 * The type that contains the attribute
	 * @param iAttribute
	 * The attribute
 	 * @param iListOfValue
	 * The values to be translated (for performance consideration, a list is provided)
	 * @param oListOfNLSValue
	 * The Values translated
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the attribute is not part of this type
	 * 	 <li> S_FALSE if the value had no translation
	 * 	 <li> S_OK	if NLS name has been retrieved
 	 *  </ol>
	 */
	static HRESULT TranslateValues (const CATIType_var &iType,const CATAttributeInfos &iAttribute,const CATListOfCATUnicodeString &iListOfValue,CATListOfCATUnicodeString &oListOfNLSValue);

	/**
	 * Returns the current unit to use to manipulate the attribute in the user interface.<br>
	 * Depends on the Tools Options Settings by default.<br>
	 * If the unit to use has been precised in PLM Dictionary, it will be this one chosen.<br>
	 * If the unit to use for this attribute is overriden in settings, it is the one that will be chosen.<br>
	 * @param iType
	 * The type that contains the attribute
	 * @param iAttribute
	 * The attribute
	 * @param oUnit
	 * The unit to manipulate it
	 * @param iScaleContext
	 * the PLM Component owning the attribute. It allows to retrieve its scales which may change the unit to use
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the attribute is not an attribute with a magnitude, ot input are NULL
	 * 	 <li> S_OK	if unit retrieved and was precised in the dictionary (different from the setting)
	 * 	 <li> S_FALSE	if unit retrieved but was not precised in the dictionary (we return the unit of the setting)
 	 *  </ol>
	 */
	static HRESULT GetCurrentUnitForManipulation (const CATIType_var &iType,const CATAttributeInfos &iAttribute,CATICkeUnit_var &oUnit, const CATBaseUnknown_var &iScaleContext = NULL_var);

	/**
	 * Indicates if the attribute is controlled by the modeler or not.
	 */
	CATBoolean IsControlledByModeler ();

	/**
	 * Enable to retrieve a dynamic properties on an attribute.<br>
	 * A dynamic property is an information declared by an application in the metadata , that is not interpreted by generic toolkits & dictionary but that can be retrieved by applications on their types.
	 * Usage: All contexts (UI Layer (search, new), Modeler,..).<br>
	 * @param iDynamicPropertyName
	 * name of the dynamic property
	 * @param oValue
	 * value read. Can be NULL if property not found
	 * @return
	 *  <ol>
	 * 	 <li> S_OK	if the property has been read
	 * 	 <li> S_FALSE	if the property has not been found
	 * 	 <li> E_FAIL	otherwise
	 *  </ol>
     */
	HRESULT ReadDynamicProperty (const CATUnicodeString &iDynamicPropertyName,CATIValue_var &oValue);

    /** @nodoc
	* For internal usage only
	*/
	CATLISTV(CATICkeParm_var)	ListProperties() const;

	/**
	* Indicates if the attribute is faceted or not (used by index/search.
	*
	* @return TRUE if Faceted, else FALSE.
	*/
	boolean IsFaceted() const;

	/** @nodoc
	* For internal usage only
	*/
	CATIAttributesController_var GetController () const;

	/**
	 * Indicates if this attribute is a multi valuated (in other word a list).<br>
	 * Note that in this case, the type returned by the Type method is the type List.<br>
	 * If you want to access the type of the elements of the list (if any), you'll have to use the
	 *
	 * @return TRUE if multi valuated, else FALSE.
	 */
	boolean IsMultiValuated () const;

	/**
	* Returns the type of values in case of multi valuated.<br>
	* Returns also the type of value in case of mono valuated.<br>
	* @return a type. Returns NULL_var if type is not precised...
	*/
	CATIType_var TypeForValues() const;

  /**
	* Returns the fact that the attribute is multiline (by default FALSE).
	*
	* @return TRUE if it is a multiline attribute, else FALSE.
	*/
	boolean IsMultiline() const;

  /**
	* Returns the fact that the attribute can be set only once. 
	* @param atCreation
	* TRUE if it can be set only at creation, false if it can be set afterwards.
	* @return TRUE if it is the case, else FALSE.
	*/
	boolean CanBeWrittenOnlyOnce(boolean &atCreation) const;

  /**
	* Returns the fact that the attribute can be seen in UI
	* @param readWrite
	* TRUE if it can be modified
	* @return TRUE if it is the case
	*/
	boolean IsShownInUI (boolean &readWrite) const ;

protected:
	// Lettre
	CATAttributeInfosAbstractLetter *_pLetter;
	/**
	 * @nodoc
	 */
	CATAttributeInfos(CATAttributeInfosAbstractLetter *ipLetter );

private:

	HRESULT ExtractFromCatalog (const CATIType_var &iType,
							CATBoolean &oRequiresTranslation,
							const CATListOfCATUnicodeString &iListOfValue,
							CATListOfCATUnicodeString &oListOfNLSValue,
							CATListOfCATUnicodeString *pListOValueToTranslate);
};

#endif
