#ifndef CATIInstanceListener_h
#define CATIInstanceListener_h

// COPYRIGHT DASSAULT SYSTEMES 2000


//System
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

//KnowledgeInterfaces
#include "CATIInstance.h"
#include "CATIValue.h" 

// load module
#include "CATLifSpecs.h"
#include "CATLISTV_CATBaseUnknown.h"

class CATIInstance_var;

// OLE IID
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIInstanceListener;
#else
extern "C" const IID IID_CATIInstanceListener;
#endif

/**   
 * Interface dedicated to implementing reactions to instances changes.
 *
 * <b>Role</b>: this interface allows one to be called on instances events, as soon as
 * one has subscribed to such events with @href CATIInstance#AddInstanceListener .
 *
 * @see CATIInstance
 * @see CATIValue
 */
class ExportedByCATLifSpecs CATIInstanceListener : public CATBaseUnknown
{
public:
	/**
	* Called whenever the object to which the listener has been added to is instanciated.
	*
	* @param iOwner owner of the new instance
	* @param iKey   name of the attribute where the new instance is stored
	* @param iValue	new instance
	*/
	virtual HRESULT Instanciated( const CATIInstance_var& iOwner,
								  const CATUnicodeString& iKey,
								  const CATIValue_var& iValue ) = 0;

	/**
	* Called whenever the object to which the listener has been added is removed.
	*
	* @param iInstance removed instance.
	*/
	virtual HRESULT Removed( const CATIInstance_var& iInstance ) = 0;

	/**
	* Called whenever the object to which the listener has been added has changed.
	*
	* @param iInstance modified instance.
	*/
	virtual HRESULT Modification( const CATIInstance_var& iInstance ) = 0;

	/**
	* Called whenever the type of object to which the listener has been added has changed.
	*
	* @param iInstance instance which type has changed.
	*/
	virtual HRESULT TypeChanged( const CATIInstance_var& iInstance) = 0;

	/**
	* Called whenever an attribute of the object to which the listener has been added is changed.
	*
	* @param iInstance listened object
	* @param iKey      attribute name
	* @param iValue    new attribute value 
	*/
	virtual HRESULT AttributeChanged( const CATIInstance_var& iAttributes,
									  const CATUnicodeString &iKey,
									  const CATIValue_var& iValue ) = 0;

	/**
	* Called whenever an attribute of the object to which the listener has been added is added.
	*
	* @param iInstance listened object
	* @param iKey      attribute name
	* @param iValue    value of the added attribute
	*/
	virtual HRESULT AttributeAdded( const CATIInstance_var& iAttributes,
									const CATUnicodeString& iKey,
									const CATIValue_var& iValue ) = 0;

	/**
	* Called whenever an attribute of the object to which the listener has been added is removed.
	*
	* @param iInstance listened object
	* @param iKey      name of the removed attribute
	*/
	virtual HRESULT AttributeRemoved( const CATIInstance_var& iAttributes, const CATUnicodeString& iKey) = 0;

	/**
	* Called whenever an attribute of the object to which the listener has been added is renamed.
	*
	* @param iInstance listened object
	* @param iKey      attribute name
	* @param iNewKey    new attribute name
	*/
	virtual HRESULT AttributeRenamed( const CATIInstance_var& iInstance,
		                              const CATUnicodeString& iKey,
									  const CATUnicodeString& iNewKey) = 0;

	/**
	* Called whenever an event is triggered by the object to which the listener has been added.
	*
	* @param iInstance listened object
	* @param iEvent	   triggered event
	* @param iList     arguments of the event
	*/
	virtual HRESULT SpecificEvent( const CATIInstance_var& iInstance,
								   const CATBaseUnknown_var &iEvent,
								   const CATListValCATBaseUnknown_var &iList) = 0;

private:
  CATDeclareInterface;
}; 

CATDeclareHandler(CATIInstanceListener, CATBaseUnknown);

#endif
