// Copyright Dassault Systemes 2008
#ifndef CATKweExposeObjectAdapter_H
#define CATKweExposeObjectAdapter_H

#include "CATLifSpecs.h"

/** 
* @CAA2Level L1
* @CAA2Usage U2 
*/

/*  CAA2Reviewed by FRH */


#include "CATKweObjectAdapter.h"

// forwards
#include "CATIForwardsDecl.h"
#include "CATListValCATIType.h"
#include "CATIVisitor.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATListValCATAttributeInfos.h"
#include "CATKWEErrorSeverity.h"



/**
* Class to be used as an adapter for objects that want to be used through Knowledge Expert and Search. Dedicated for CAA partner<br>
*
* First of all, it inherits from CATKweObjectAdapter which is an adapter of CATICkeObject interface. This interface enables to represent Knowledge objects.
*
* It is mainly an adapter of CATIExposeObject. This interface is used by Knowledge Expert to 
* identify an object through its type. It is also used by the Edit/Find of CATIA.
*
* In addition to extension, you must create the TIE object with 
* - TIEchain_CATIExposeObject
*
*/

class ExportedByCATLifSpecs CATKweExposeObjectAdapter : public CATKweObjectAdapter
{
public:
	
	/**
	 * Constructor.
	 */
	CATKweExposeObjectAdapter();

	/**
	 * Destructor.
	 */
	virtual ~CATKweExposeObjectAdapter() ;
		
	//-------------------------------------------
	// Interface CATIExposeObject implementation
	//-------------------------------------------
	
   /**
	*  Description: Returns the main type of an object.<br>
	*  An AddRef is done. Warning : Do not redefined this method. Redefine TypeInternal.<br>
	*  Default implementation calls TypeInternal(). And if the result is NULL, will return the root type "Feature".<br>
	*  @return  [CATBaseUnknown#Release]  the main type of the object.
	*/
	CATIType* Type() const ;


   
   /**
	*  Description: Tests if an object supports a given type.<br>
	*  @param iType type that we want to check.<br>
	*  An AddRef is done. Warning : In most cases, you don't need to override this method.<br>
	*  Default implementation returns this if the type belongs to the list of supported types.
	*  You may overide this method if you want to return another object (delegation).
	*  @return  [CATBaseUnknown#Release]  the instance supporting this type (may be NULL or self)
	*/
	virtual CATICkeObject* IsSupporting( const CATIType_var& iType ) const ;
	
   /**
	*  Description: fills the list of types supported by this object.
	*  Warning : Do not redefined this method. Redefine ListSupportedTypesInternal.
	*  Default implementation returns a list containing main Type first returned by Type method.
    *  and the list of types returned by ListSupportedTypesInternal. 
    *  @param oListOfCATIType this list is filled.<br>
	*  @return classic HRESULT
	*/
	HRESULT ListSupportedTypes( CATListValCATIType_var& oListOfCATIType ) const ;

	/**
	*  Description: Gets an attributes value.<br>
	*  Default implementation calls first GetValueInternal to have access to your attributes. 
	*  Then it calls GetAccessors, trying to read value for the attributes that have accessors.
	*  able to access those kind of attributes.
	*  Do not override this method.<br>
    *  @param iKey: the name of the attribute.
	*  @return  [CATBaseUnknown#Release] iValue: the value of the attribute (an AddRef is done) It can return NULL.
	*/
	CATIValue* GetValue( const CATUnicodeString& iKey ) ;

	/**
	*  Description: Sets an attributes value.
	*  Default implementation calls first SetValueIntenal, and finally, tries to valuate the attribute if it has an accessor.<br>
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
	* @return [CATBaseUnknown#Release] The Owner (an  AddRef  is  done,  if  not  NULL).  
	*/
	virtual CATICkeObject* GetOwner() const ;

	
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
	*  @return  [CATBaseUnknown#Release] the main type of the object.
	*/
	virtual CATIType* TypeInternal() const;

   /**
	*  Description: fills the list of types supported by this object in addition to the one returned by Type method.<br>
    *  Default implementation adds nothing. In most cases, you don't need to implement this method. This method is called by the ListSupportedTypes method.
    *  @param oListOfCATIType this list is filled.<br>
	*  @return classic HRESULT
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
	*  @return  [CATBaseUnknown#Release] iValue: the value of the attribute (an AddRef is done) It can return NULL.
	*/
	virtual CATIValue* GetValueInternal( const CATUnicodeString& iKey );

	/**
	*  Description: Raises an error. Use this method inside the GetValueInternal & SetValueInternal
	*  when you want to bring to the user more explanation about why the read or write operations has failed.<br>
	*  Note that you don't need to raise message (& use this method) in the standard error cases (bad type, attribute not found, attribute read only, ...
	*  Simply return the right HRESULT (E_INVALID_ARG, E_ACCESSDENIED) and a standard error message is raised (InexistingAttribute, ReadAttributeBadKind, ReadOnlyAttribute ).<br>  
    *  @param iMessage: the NLS message that will be brought to the end-user.
    *  @param iSeverity: severity of the error.
	*  @return classic HRESULT
	*/
	HRESULT SendError  (const CATUnicodeString				&iMessage, 
						const CATKWEErrorSeverity::Severity	iSeverity	= CATKWEErrorSeverity::Error) const ;



  	
 
private:
	 
	/**
	*  Description: Get parameter from the name of the attribute.<br>
	*  Default implementation returns NULL. This method is called by the GetValue method.
	*  You may implement this method if your object implements CATIParmPublisher and you want to see those parameters as attributes.
	*  In this case the GetParmFromName method should try to find a parameter by its name.
	*  @param iKey: the name of the attribute.
	*  @return the value of the attribute.
	*/
	// Accesses a value thanks to the accessors
	CATIValue* GetValueThroughAccess(const CATUnicodeString& iKey);
	HRESULT SetValueThroughAccess( const CATUnicodeString& iKey, const CATIValue_var& iValue );
	CATAttributeInfos* checkAttribute(const CATIAttributesDescription_var &attributes, const CATUnicodeString& iKey) const;


	CATKweExposeObjectAdapter(const CATKweExposeObjectAdapter&);
	
};

#endif
