// Copyright Dassault Systemes 2000
#ifndef CATKweInstanceAdapter_H
#define CATKweInstanceAdapter_H

#include "CATLifSpecs.h"


// forwards
#include "CATIForwardsDecl.h"
#include "CATListValCATIType.h"
#include "CATIVisitor.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATParmPublisherAdapter.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATListValCATAttributeInfos.h"
#include "CATKWEErrorSeverity.h"
#include "CATIType.h"

class CATIInstanceListener_var;
class CATIInstance_var;

class CATICkeParm;


class CATIAttributeAccess;
class CATIInstance;

/**
* Class to be used as an adapter for objects that want to be used through Knowledge Expert and Search.<br>
*
* First of all, it inherits from CATParmPublisherAdapter which is an adapter of CATIParmPublisher interface. This interface is used
* by a feature to publish its parameters so that they can be used in F(x).<br>
*
* It is also an adapter of CATIInstance. This interface is used by Knowledge Expert to 
* identify an object through its type. It is also used by GenerativeKnwoledge and the search 
* of CATIA.
* In addition to that, the object may implement CATIInstance to give access
* to its attributes. It may also implement CATIDynamicAttributes and CATIAttributesDescription
* to support the ability for a user to add dynamic attributes on it.
* It may also implement CATICkeFeature which is the interface for objects that can be selected in our rules.
*
* In addition to extension, you must create the TIE object with 
* - TIEchain_CATIParmPublisher (optional)
* - TIEchain_CATIInstance (mandatory)
* - TIEchain_CATICkeFeature (optional)
* - TIEchain_CATIDynamicAttributes (optional)
* - TIEchain_CATIAttributesDescription (optional)
*/

class ExportedByCATLifSpecs CATKweInstanceAdapter : public CATParmPublisherAdapter
{
public:
	
	CATKweInstanceAdapter();

	virtual ~CATKweInstanceAdapter() ;
		
	//-------------------------------------------
	// Interface CATIInstance implementation
	//-------------------------------------------
	
   /**
	*  Description: Returns the main type of an object.<br>
	*  An AddRef is done. Warning : Do not redefined this method.<br>
	*  Default implementation calls GetTypeInternal(). And if the result is NULL, will return the root type "Feature".<br>
	*  @return [CATBaseUnknown#Release] the main type of the object.
	*/
	CATIType* Type() const ;


   
   /**
	*  Description: Tests if an object supports a given type.<br>
	*  @param iType type that we want to check.<br>
	*  An AddRef is done. Warning : In most cases, you don't need to override this method.<br>
	*  Default implementation returns this if the type belongs to the list of supported types.
	*  You may overide this method if you want to return another object (delegation).
	*  @return [CATBaseUnknown#Release] the instance supporting this type (may be NULL or self)
	*/
	CATIInstance* IsSupporting( const CATIType_var& iType ) const ;
	
   /**
	*  Description: fills the list of types supported by this object.
	*  Default implementation returns a list containing main Type first returned by Type method.
    *  and the list of types returned by ListSupportedTypesInternal. 
    *  @param oListOfCATIType this list is filled.<br>
	*/
	HRESULT ListSupportedTypes( CATListValCATIType_var& oListOfCATIType ) const ;


	
	/**
	*	Description: adds a listener to the object.
	*  The Listerner is called back when events are raised by the object.
	*  Default implementation works very well. You shouldn't overide this method.
	*  @param iListerner listener to be called back.<br>
	*/
	HRESULT AddInstanceListener( const CATIInstanceListener_var &iListener ) ;
	
	/**
	*	Description: removes a listener to the object.
	*  The Listerner is called back when events are raised by the object.
	*  Default implementation works very well. You shouldn't overide this method.
	*  @param iListerner listener to be called back.<br>
	*/
	HRESULT RemoveInstanceListener( const CATIInstanceListener_var &iListener ) ;
	
    /**
	*  Description: propagates an attribute changed information on an instance to all its listeners.
	*  if the name of attribute is different of the name of parm, you must overload this method to
	*  call AdviseAttributeChanged with the attribute name.
	*  @param iKey Parm Name
	*  @param iValue 
	*/
	virtual HRESULT AdviseAttributeChanged( const CATUnicodeString &iKey, 
		const CATIValue_var& iValue );
	
	/**
	*  Description: propagates a remove information on an instance to all its listeners.
    */
	HRESULT AdviseRemoved(  );
		
    /**
    *  Description: propagates a modification information on an instance to all its listeners.
    */
	HRESULT AdviseModification(  );
	
	/**
    *  Description: propagates a change type information on an instance to all its listeners.
    */
	HRESULT AdviseTypeChanged( );
		
	/**
	*  Description: propagates an attribute creation information on an instance to all its listeners.
	*  @param iKey attribute added 
	*  @param iValue  value added
	*/ 
	HRESULT AdviseDynamicAttributeAdded( const CATUnicodeString& iKey,
		const CATIValue_var& iValue );

	/**
	*  Description: propagates an attribute deletion information on an instance to all its listeners.
	*  @param iAttributes instance where attribute is deleted
	*  @param iKey attribute deleted 
	*  @param iValue  value deleted
	*/ 
	HRESULT AdviseDynamicAttributeRemoved( const CATUnicodeString& iKey,
		const CATIValue_var& iValue );

	/**
	*  Description: propagates an attribute rename information on an instance to all its listeners.
	*  @param iAttributes instance where attribute is renamed
	*  @param iKey attribute renamed
	*  @param iValue  value renamed
	*/ 
	HRESULT AdviseDynamicAttributeRenamed( const CATUnicodeString& iKey,
		const CATUnicodeString& iNewKey);

	/**
	* Propagates a specific event that occured on the instance.
	*
	* @param iEvent Event that happened.
	* @param iList  List of values carried by the event.
	*/
	HRESULT AdviseSpecificEvent( const CATBaseUnknown_var &iEvent,
										 const CATListValCATBaseUnknown_var &iList );
	
	
	//-------------------------------------------
	// Interface CATIInstance (Attributes)
	//-------------------------------------------
	

	/**
	*  Description: Gets an attributes value.<br>
	*  Default implementation calls first GetValueInternal to have access to your attributes. 
	*  Then it calls GetAccessors, trying to read value for the attributes that have accessors.
	*  able to access those kind of attributes.
	*  Do not override this method.<br>
    *  @param iKey: the name of the attribute.
	*  @return [CATBaseUnknown#Release] iValue: the value of the attribute (an AddRef is done) It can return NULL.
	*/
	CATIValue* GetValue( const CATUnicodeString& iKey ) ;

	/**
	*  Description: Sets an attributes value.
	*  Default implementation calls first SetValueIntenal,and finally, tries to valuate the attribute if it has an accessor.<br>
	*  Do not override this method.
	*  @param iKey: the name of the attribute.
	*  @param iValue: the value of the attribute.
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the valuation has failed (attribute non existing on object, attribute of a bad type).
	* 	 <li> E_ACCESSDENIED if the valuation has failed (read only attribute, object not editable).
	* 	 <li> S_OK	if the attribute has been set successfully.
	*  </ol>
	*/
	HRESULT SetValue( const CATUnicodeString& iKey, const CATIValue_var& iValue ) ;
     
	/**
	* Description: returns the owner of the object.
	* Default implementation returns NULL
	*  @return [CATBaseUnknown#Release] the owner (an AddRef is done) It can return NULL.
	*/
	virtual CATIInstance* GetOwner() const ;

		
	//-------------------------------------------
	// Interface CATICkeFeature (to be selected in rules/formulas/checks
	//-------------------------------------------
	

 	/**
	 * Returns the type of the object.
	 * This type is used to check that the formula (rule or check) syntax is correct. 
	 * If your object implements CATIInstance, the classical implementation returns the CATIInstance::Type method.
	 * If not, usually the implementation consists in calling CATGlobalFunctions::GetTypeDictionary()->FindTypeSafe("TypeName","PackageName",oType)
	 * Default implementation returns CATIInstance::Type method.
	 *
	 * @return the main type of the object. It is also a CATIType.
	 */
	virtual CATICkeType_var GetType    () const ;


	//===========================================================
	// CATIDynamicAttributes
	//===========================================================

	/**
	 *	Description: Use this method to dynamically add an attribute to an instance.<br>
   	 *  @param iKey: the name of the attribute which will be used by the GetValue method of CATIInstance to retrieve the attribute on the instance.
	 *  @param iType: the type of the attribute which is being added.
	 *  @param iValue: the value of the attribute which is being added
	 *  Default implementation returns E_FAIL
	 */
	virtual HRESULT Add( const CATUnicodeString& iKey, const CATIType_var& iType, const CATIValue_var& iValue, boolean iIsComponent ) ;

	/**
	 *	Description: Removes an attribute from its name.<br>
   	 *  @param iKey: the name of the attribute.
	 *  Default implementation returns E_FAIL
	 */
	virtual HRESULT Remove( const CATUnicodeString& iKey ) ;

	/**
	 *	Description: Renames an attribute.<br>
   	 *  @param iOldKey: the old name of the attribute.
	 *  @param iNewKey: the new name of the attribute.	 
	 *  Default implementation returns E_FAIL
	 */
	virtual HRESULT Rename( const CATUnicodeString& iOldKey, const CATUnicodeString& iNewKey ) ;

	/**
	 *	Description: Add the support of a type.<br>
   	 *  @param iTypeAdded: type added.
 	 *  Default implementation returns E_FAIL
	 */
	virtual HRESULT AddTypeSupport ( const CATIType_var &iTypeAdded) ;

	/**
	 *	Description: Remove the support of a type.<br>
   	 *  @param iTypeRemoved: type added.
	 *  Default implementation returns E_FAIL
	 */
	virtual HRESULT RemoveTypeSupport ( const CATIType_var &iTypeRemoved) ;

	//===========================================================
	// CATIAttributesDescription
	//===========================================================

	/**
	*	Returns the list of informations on attributes held by the object.<br>
	*   @param oListOfAttributeInfos : the list of informations on attributes
	*	@param recursively : if true, the output list will also contain the attributes given by 
	*	the inheritance mechanism provided by CATIType
	*   Default implementation returns the attributes retrieved on the types of the object (CATCkeSharedServices::List)
	*/
	virtual HRESULT List( CATListValCATAttributeInfos* oListOfAttributeInfos, boolean recursively = 1 ) const ;

	/**
	*	Returns information about the attribute whose name is specified as argument.<br>
	*   @param iName : the name of the attribute for which informations are required
	*	@param oAttributeInfos : the output informations about the attribute. This object is allocated
	*   Default implementation returns the attributes retrieved on the types of the object (CATCkeSharedServices::FindByName)
	*/
	virtual HRESULT FindByName( const CATUnicodeString& iName, CATAttributeInfos*& oAttributeInfos ) const ;

	/**
	*	Returns information about the attribute whose NLS-name is specified as argument.<br>
	*	@param iName : the name of the attribute for which informations are required
	*	@param oAttributeInfos : the output informations about the attribute
	*   Default implementation returns the attributes retrieved on the types of the object (CATCkeSharedServices::FindByNLSName)
	*/
	virtual HRESULT FindByNLSName( const CATUnicodeString& iNLSName, CATAttributeInfos*& oAttributeInfos ) const ;

	

	//-------------------------------------------
	// Interface CATICkeObject implementation
	//-------------------------------------------
	/**
	* Returns the Logical name of the object. The logical name is a name that the end-user can give (modify) and that has no constraint of unicity.<br>
	* Default implementation relies on CATIAlias::GetAlias method.<br>
	* For objects in representation, it is usually sufficient. For PLM objects CATIAlias has been used to provide a computed name. That's why it cannot be used for logical name implementation.<br>
	* As a consequence, for PLM objects, this method MUST BE overriden.<br>
	* @param oLogicalName
	* Logical name in output
    * @return
	*  <ol>
	* 	 <li> E_ACCESSDENIED if the logical name cannot be read.
	* 	 <li> E_FAIL if the logical name cannot be read.
	* 	 <li> S_OK	if the logical name has been read successfully.
	*  </ol>
	*/
	virtual HRESULT  GetLogicalName    (CATUnicodeString &oLogicalName) const ;

	/**
	* Sets the Logical name of the object. The logical name is a name that the end-user can give (modify) and that has no constraint of unicity.<br>
	* Default implementation relies on CATIAlias::SetAlias method.<br>
	* For objects in representation, it is usually sufficient. For PLM objects CATIAlias has been used to provide a computed name. That's why it cannot be used for logical name implementation.<br>
	* As a consequence, for PLM objects, this method MUST BE overriden.<br>
	* @param iLogicalName
	* Logical name in input
	* @return
	*  <ol>
	* 	 <li> E_ACCESSDENIED if the valuation has failed (read only attribute, object not editable).
	* 	 <li> E_FAIL if the logical name cannot be set.
	* 	 <li> S_OK	if the logical name has been set successfully.
	*  </ol>
	*/
	virtual HRESULT  SetLogicalName    (const CATUnicodeString &iLogicalName) ;


	/**
	* Indicates if this object provides access to its simple attributes through generic methods CATCkeObjectAttrReadServices and CATCkeObjectAttrWriteServices.<br>
	* Default implementation returns TRUE. Can be overriden.<br>
	*/
	virtual CATBoolean IsPublic () const ;


	/**
	* Returns this object. Must be overriden in order to be helpful. See the exemples
	*/
	virtual CATICkeObject_var GetRealObject() const ;

	/**
	 * When V_Discipline changes on a CATIInstance implementation, we must update the cache that stores the CATIType of the discipline 
	 * Please call this method when the discipline attribute is changed
	 */
  	HRESULT PropagateV_disciplineChange (const CATUnicodeString &iDisciplineValue);

	/**
	 * Returns the type corresponding to the discipline if any.
	 * This method is here for PCS optimizations because it returns a data member
	 */
	CATIType_var ComputeDisciplineType (const CATIType_var &typePhysique) const;

protected:

   /**
	*  Description: Returns the main type of an object.
	*  An AddRef must be done. This method must be re-implemented.
	*  The classic implementation of this method is to use
	*  CATGlobalFunctions::GetTypeDictionary()->FindSafe("MyType","MyPackage",oType)
	*  and return oType after having done an AddRef.
	*  This method finds a type by its name and loads the package in which the type
	*  is defined if needed.
    *  this method is called by the Type() method.
	*  If you do not want to specify an accurate type, you can return NULL and Type method
	*  will return the type Feature
	*  @return [CATBaseUnknown#Release] the main type of the object.
	*/
	virtual CATIType* TypeInternal() const;

   /**
	*  Description: fills the list of types supported by this object in addition to the one returned by Type method.<br>
    *  Default implementation adds nothing. In most cases, you don't need to implement this method. This method is called by the ListSupportedTypes method.
    *  @param oListOfCATIType this list is filled.<br>
	*/
	virtual HRESULT ListSupportedTypesInternal( CATListValCATIType_var& oListOfCATIType ) const ;

	/**
	*  Description: Sets an attributes value. Must be re-implemented when deriving 
    *  from this adapter.<br>
	*  Default implementation returns E_NOTIMPL. This method is called by the SetValue method
    *
	*  @param iKey: the name of the attribute.
	*  @param iValue: the value of the attribute.
	*  @return
	*  <ol>
	* 	 <li> E_NOTIMPL if this method is overridden but that the SetValue is not done by your implementation.
	* 	 <li> E_INVALIDARG if the valuation has failed (attribute non existing on object, attribute of a bad type).
	* 	 <li> E_ACCESSDENIED if the valuation has failed (read only attribute, object not editable).
	* 	 <li> S_OK	if the attribute has been set successfully.
	*  </ol>
	*/
	virtual HRESULT SetValueInternal( const CATUnicodeString& iKey, const CATIValue_var& iValue );

	/**
	*  Description: Gets an attributes value. Must be re-implemented when deriving 
    *  from this adapter.<br>
	*  Default implementation does nothing. This method is called by GetValue.
    *  @param iKey: the name of the attribute.
	*  @return [CATBaseUnknown#Release] iValue: the value of the attribute (an AddRef is done) It can return NULL.
	*/
	virtual CATIValue* GetValueInternal( const CATUnicodeString& iKey );

	/**
	*  Description: Raises an error. Use this method inside the GetValueInternal & SetValueInternal
	*  when you want to bring to the user more explanation about why the read or write operations has failed.<br>
	*  Note that you don't need to raise message (& use this method) in the standard error cases (bad type, attribute not found, attribute read only, ...
	*  Simply return the right HRESULT (E_INVALID_ARG, E_ACCESSDENIED) and a standard error message is raised (InexistingAttribute, ReadAttributeBadKind, ReadOnlyAttribute ).<br>  
    *  @param iMessage: the NLS message that will be brought to the end-user.
    *  @param iSeverity: severity of the error.
	*/
	HRESULT SendError  (const CATUnicodeString				&iMessage, 
						const CATKWEErrorSeverity::Severity	iSeverity	= CATKWEErrorSeverity::Error) const ;


	/**
	 * Indicates if this object can be typed by a discipline.
	 * Default implementation (for PLM objects) returns true.
	 */
	virtual CATBoolean IsTypedByDiscipline () const ;

	/**
	 * If the object is typed by discipline, and it is optimized, it means that when the value of the discipline attribute is modified, PropagateV_disciplineChange is called
	 * Default implementation (for PLM objects) returns true.
	 */
	virtual CATBoolean IsDisciplineAttributeOptimized () const ;

	

	// Accesses a value thanks to the accessors static method 
	static CATIValue* GetValueThroughAccessGlobal(const CATIInstance_var &iInstanceWhereAttributeIs,const CATUnicodeString& iKey,const CATIInstance_var &iInstanceToPassToAccessor);
	static HRESULT SetValueThroughAccessGlobal(const CATIInstance_var &iInstanceWhereAttributeIs, const CATUnicodeString& iKey, const CATIValue_var& iValue,const CATIInstance_var &iInstanceToPassToAccessor);
	static CATAttributeInfos* checkAttribute(const CATIAttributesDescription_var &attributes, const CATUnicodeString& iKey) ;
	

  	
 
private:
	  
	// Accesses a value thanks to the accessors
	CATIValue* GetValueThroughAccess(const CATUnicodeString& iKey);
	HRESULT SetValueThroughAccess( const CATUnicodeString& iKey, const CATIValue_var& iValue );
	

	CATKweInstanceAdapter(const CATKweInstanceAdapter&);
	
	CATListPV* _instanceListeners;
	//boolean _hasCallbackOnInstanceDeletion:1;

	
	// Adding a type corresponding to the discipline. May be null
	CATIType_var _disciplineType;
	int _isTypedByDiscipline; // -1 non calcule, 0 non, 1 oui
	CATBoolean IsTypedByDisciplineInternal () const ;

    //CATDeclareClass;

};

#endif
