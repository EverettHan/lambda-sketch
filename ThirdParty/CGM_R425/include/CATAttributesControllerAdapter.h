#ifndef CATAttributesControllerAdapter_H
#define CATAttributesControllerAdapter_H

// COPYRIGHT DASSAULT SYSTEMES 2012

// Export Module 
#include "CATLifSpecs.h" 

// inherit from
#include "CATBaseUnknown.h"
#include "CATIAttributesController.h" 
#include "CATLISTV_CATBaseUnknown.h"
class CATIInstance_var;
class CATIValue_var;
class CATUnicodeString;

/**   
 *  Adapter to CATIAttributesController Interface.
 * <b>Role</b>: This class must be derived to implement  extension to CATIAttributesController.<br>
 */
class ExportedByCATLifSpecs CATAttributesControllerAdapter : public CATIAttributesController
{
public:

   /** 
    * Constructs the adapter.
    */ 
    CATAttributesControllerAdapter();

   /** 
    * Deletes the adapter.
    */ 
    virtual ~CATAttributesControllerAdapter();

	//-------------------------------------------------------------------
	// 	 Methods available on interface CATIAttributesController
	//-------------------------------------------------------------------

	/**
	 * Computes the list of authorized values for the attribute of an object.<br>
	 * @param iObject
 	 * objets (PLM or proxy) that we are manipulating
	 * @param iAttributeName
 	 * name of the attribute
	 * @return
	 *  <ol>
	 * 	 <li> S_OK computation succesful. 
	 * 	 <li> E_FAIL instead. This method calls ComputeAuthorizedValues
	 *  </ol>
     */
	 HRESULT InitializeAuthorizedValues (const CATICkeObject_var &iObject,const CATUnicodeString &iAttributeName);


	/**
	 * When an attribute is modified (event on CATIInstanceListener)
	 * we may want to force the list of authorized attributes to other attributes
	 * this method can be used 
	 */
	HRESULT SetAuthorizedValuesAsStrings (const CATICkeObject_var &iObject,const CATUnicodeString &iAttributeName,const CATListOfCATUnicodeString& oListAuthorizedValuesString);

	/**
	 * When an attribute is modified (event on CATIInstanceListener)
	 * we may want to force the list of authorized attributes to other attributes
	 * this method can be used 
	 */
	HRESULT SetAuthorizedValuesAsDoubles (const CATICkeObject_var &iObject,const CATUnicodeString &iAttributeName,const CATListOfDouble &oListAuthorizedValuesDouble);

	//-------------------------------------------------------------------
	// 	 Methods available on interface CATIInstanceListener
	//-------------------------------------------------------------------

	/**
	* Called whenever the object to which the listener has been added to is instanciated.
	*
	* @param iOwner owner of the new instance
	* @param iKey   name of the attribute where the new instance is stored
	* @param iValue	new instance
	*/
	virtual HRESULT Instanciated( const CATIInstance_var& iOwner,
								  const CATUnicodeString& iKey,
								  const CATIValue_var& iValue ) { return S_OK;}

	/**
	* Called whenever the object to which the listener has been added is removed.
	*
	* @param iInstance removed instance.
	*/
	virtual HRESULT Removed( const CATIInstance_var& iInstance ) { return S_OK;}

	/**
	* Called whenever the object to which the listener has been added has changed.
	*
	* @param iInstance modified instance.
	*/
	virtual HRESULT Modification( const CATIInstance_var& iInstance ) { return S_OK;}

	/**
	* Called whenever the type of object to which the listener has been added has changed.
	*
	* @param iInstance instance which type has changed.
	*/
	virtual HRESULT TypeChanged( const CATIInstance_var& iInstance) { return S_OK;}

	/**
	* Called whenever an attribute of the object to which the listener has been added is changed.
	* Must be overriden by implementer
	*
	* @param iInstance listened object
	* @param iKey      attribute name
	* @param iValue    new attribute value 
	*/
	virtual HRESULT AttributeChanged( const CATIInstance_var& iAttributes,
									  const CATUnicodeString &iKey,
									  const CATIValue_var& iValue )  { return S_OK;}

	/**
	* Called whenever an attribute of the object to which the listener has been added is added.
	*
	* @param iInstance listened object
	* @param iKey      attribute name
	* @param iValue    value of the added attribute
	*/
	virtual HRESULT AttributeAdded( const CATIInstance_var& iAttributes,
									const CATUnicodeString& iKey,
									const CATIValue_var& iValue ){ return S_OK;}

	/**
	* Called whenever an attribute of the object to which the listener has been added is removed.
	*
	* @param iInstance listened object
	* @param iKey      name of the removed attribute
	*/
	virtual HRESULT AttributeRemoved( const CATIInstance_var& iAttributes, const CATUnicodeString& iKey){ return S_OK;}

	/**
	* Called whenever an attribute of the object to which the listener has been added is renamed.
	*
	* @param iInstance listened object
	* @param iKey      attribute name
	* @param iNewKey    new attribute name
	*/
	virtual HRESULT AttributeRenamed( const CATIInstance_var& iInstance,
		                              const CATUnicodeString& iKey,
									  const CATUnicodeString& iNewKey) { return S_OK;}

	/**
	* Called whenever an event is triggered by the object to which the listener has been added.
	*
	* @param iInstance listened object
	* @param iEvent	   triggered event
	* @param iList     arguments of the event
	*/
	virtual HRESULT SpecificEvent( const CATIInstance_var& iInstance,
								   const CATBaseUnknown_var &iEvent,
								   const CATListValCATBaseUnknown_var &iList) { return S_OK;}
protected: 

	/**
	 * Computes the list of authorized values for the attribute of an object.<br>
	 * @param iObject
 	 * objets (PLM or proxy) that we are manipulating
	 * @param iAttributeName
 	 * name of the attribute
	 * @param oListAuthorizedValuesString
 	 * list of authorized values (for string attributes)
	 * @param oListAuthorizedValuesDouble
 	 * list of authorized values (for double or int attributes)
	 * @param oString
 	 * TRUE if you used the string list, FALSE if double list is used
	 * @return
	 *  <ol>
	 * 	 <li> S_OK computation succesful. 
	 * 	 <li> E_FAIL instead. This method returns by default E_FAIL and must be overwritten
	 *  </ol>
     */
	virtual HRESULT ComputeAuthorizedValues (const CATICkeObject_var &iObject,const CATUnicodeString &iAttributeName,CATListOfCATUnicodeString& oListAuthorizedValuesString,CATListOfDouble &oListAuthorizedValuesDouble,CATBoolean &oString);

private:
 
  /**
   */
   CATAttributesControllerAdapter(const CATAttributesControllerAdapter&);
};


#endif
