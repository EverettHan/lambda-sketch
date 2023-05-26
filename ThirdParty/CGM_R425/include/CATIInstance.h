#ifndef CATIInstance_h
#define CATIInstance_h

// COPYRIGHT DASSAULT SYSTEMES 2000



// inherited class 
#include "CATICkeObject.h"
#include "CATUnicodeString.h"
#include "CATListValCATIType.h"

#include "CATIType.h"
#include "CATIValue.h"
#include "CATLISTV_CATBaseUnknown.h"

// load module
#include "CATLifSpecs.h"
class CATIInstanceListener_var;

// OLE IID
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIInstance;
#else
extern "C" const IID IID_CATIInstance;
#endif

/**
* Internal Use.
*/
#define CATIInstanceOnly 1


/**   
 * Interface dedicated to manipulating objects in Knowledgeware.
 *
 * <b>Role</b>: this interface allows one to make his objects utilizable
 * in KnowledgeWare and in Search by granting objects with static type information
 * and event reactiveness.<br>
 * <br>
 * Implementations of that interface should derive from CATKweInstanceAdapter.
 *
 * <p><b>BOA information</b>: this interface CANNOT be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 *
 * This interface is multi implemented.
 * @see CATIType
 * @see CATIValue
 */
class ExportedByCATLifSpecs CATIInstance : public CATICkeObject
{
public :

	/**
	* Returns the main Knowledge type of an object.
	*
	* An AddRef is done.
	* @return [CATBaseUnknown#Release] the main type of the object.
	*/
	virtual CATIType* Type() const = 0;

	/**
	* Casts an instance to another one supporting the given type.
	*
	* An AddRef is done, if not NULL.
	* @param iType type we want to cast the instance to.
	* @return [CATBaseUnknown#Release] the instance supporting this type (may be NULL or self).
	*/
	virtual CATIInstance* IsSupporting( const CATIType_var& iType ) const = 0;

	/**
	* Fills the given list with types supported by this instance.
	*
	* @param iolListOfCATIType the filled list.
	*/
	virtual HRESULT ListSupportedTypes( CATListValCATIType_var& iolListOfCATIType ) const = 0;

	/**
	* Adds a listener to the instance.
	*
	* The listeners are called back when events are raised by the instance.
	* @param iListener a listener.
	*/
	virtual HRESULT AddInstanceListener( const CATIInstanceListener_var &iListener ) = 0;

	/**
	* Removes a listener to the instance.
	*
	* The listeners are called back when events are raised by the instance.
	* @param iListener a listener.
	*/
	virtual HRESULT RemoveInstanceListener( const CATIInstanceListener_var &iListener ) = 0;

	/**
	* Propagates an attribute value change event on all the listeners of the instance.
	*
	* @param iKey Name of the attribute to monitor.
	* @param iValue Value of the attribute.
	*/
	virtual HRESULT AdviseAttributeChanged( const CATUnicodeString &iKey, 
							                const CATIValue_var& iValue ) =0;

    /**
	* Propagates a dynamic attribute add event on all the listeners of the instance.
	*
	* @param iKey Name of the added attribute.
	* @param iValue Value of the attribute.
	*/ 
	virtual HRESULT AdviseDynamicAttributeAdded( const CATUnicodeString& iKey,
												 const CATIValue_var& iValue ) =0;

    /**
	* Propagates a dynamic attribute remove event on all the listeners of the instance.
	*
	* @param iKey Name of the removed attribute.
	* @param iValue Value of the attribute.
	*/
	virtual HRESULT AdviseDynamicAttributeRemoved( const CATUnicodeString& iKey,
												   const CATIValue_var& iValue ) =0;
	/**
	* Propagates a dynamic attribute rename event on all the listeners of the instance.
	*
	* @param iKey Name of the renamed attribute.
	* @param iValue Value of the attribute.
	*/
	virtual HRESULT AdviseDynamicAttributeRenamed( const CATUnicodeString &iKey, 
												   const CATUnicodeString &iNewKey ) =0;
 
    /**
	* Propagates an instance remove event on all the listeners of the instance.
	*/
	virtual HRESULT AdviseRemoved(  ) =0;

    /**
	* Propagates an instance modification event on all the listeners of the instance.
	*/
	virtual HRESULT AdviseModification(  ) =0;

    /**
	* Propagates an instance type modification event on all the listeners of the instance.
	*/
	virtual HRESULT AdviseTypeChanged( ) =0;

	/**
	* Sets an attribute value.<br>
	* The contract of this method is to copy the value in input in its internal attribute value.<br>
	* If the value passed as argument is Unset, the contract of this method is to Unset the attribute value (if it makes sense).<br>
	*
	* @param iKey Name of the attribute.
	* @param iValue Value of the attribute.
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the valuation has failed (attribute non existing on object, attribute of a bad type).
	* 	 <li> E_ACCESSDENIED if the valuation has failed (read only attribute, object not editable).
	* 	 <li> S_OK	if the attribute has been set successfully.
	*  </ol>
	*/
	virtual HRESULT SetValue( const CATUnicodeString& iKey,
							  const CATIValue_var& iValue ) = 0;

	/**
	* Gets an attribute value.<br>
	* The contract of this method is to retrieve the value from its internal attribute value and return it.<br>
	* In some contexts a copy may be created. But if the attribute is a parameter, the method is supposed to return the parameter itself.<br>
	* If the internal attribute value is Unset, the contract of this method is to Unset the attribute value that is returned.<br>
	*
	* @param iKey Name of the attribute.
	* @return [CATBaseUnknown#Release] The Value  of  the  attribute  (an  AddRef  is  done,  if  not  NULL).  
	*/
	virtual CATIValue* GetValue( const CATUnicodeString& iKey ) = 0;
	
	/**
	* Returns the owner of the instance.
	* @return [CATBaseUnknown#Release] the owner (an  AddRef  is  done,  if  not  NULL).  
	*/
	virtual CATIInstance* GetOwner() const = 0;

	/**
	* Propagates a specific event that occured on the instance.
	*
	* @param iEvent Event that happened.
	* @param iList  List of values carried by the event.
	*/
	virtual HRESULT AdviseSpecificEvent( const CATBaseUnknown_var &iEvent,
										 const CATListValCATBaseUnknown_var &iList ) =0;

private:
  CATDeclareInterface;
}; 

CATDeclareHandler(CATIInstance, CATICkeObject);

#endif
