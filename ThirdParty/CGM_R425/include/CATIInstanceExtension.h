#ifndef CATIInstanceExtension_H
#define CATIInstanceExtension_H

// COPYRIGHT DASSAULT SYSTEMES 2002

/** 
* Usage U4 CATKweInstanceExtensionAdapter
*/

#include "CATLifSpecs.h"
#include "CATUnicodeString.h"
#include "CATListValCATIType.h"
#include "CATBaseUnknown.h"
#include "CATIValue.h"

extern ExportedByCATLifSpecs IID IID_CATIInstanceExtension ;

/**   
 * Interface to declare Knowledgeware access on Feature extensions.
 *
 * <b>Role</b>: this interface allows a feature extension to publish its types and values
 * to KnowledgeWare and to the Search functionality by granting objects with static type information.
 * <br>
 * This interface should be implemented by feature extensions.
 * <br>
 * The extended feature is supposed to delegate its implementation of @href CATIInstance to the implementation of 
 * CATIInstanceExtension on its feature extensions.
 * <br>
 * Watch out: an extended feature can decide or not to give a Knowledge visibility to its extensions.
 * <br>
 * Implementations of that interface should derive from @href CATKweInstanceExtensionAdapter.
 *
 * <p><b>BOA information</b>: this interface CAN be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 *
 * @see CATIInstance,CATIType,CATIValue
 */
class ExportedByCATLifSpecs CATIInstanceExtension: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
 
   /**
	* Fills the given list with types supported by this feature extension.
	* <br>
	* The list is input may not be empty. This method is supposed to add some types to the list.
	*
	* @param iolListOfCATIType the filled list.
	*/
	virtual HRESULT ListSupportedTypes( CATListValCATIType_var& iolListOfCATIType ) const = 0;

	/**
	* Sets an attribute value.<br>
	* The contract of this method is to copy the value in input in its internal attribute value.<br>
	* If the value passed as argument is Unset, the contract of this method is to Unset the attribute value (if it makes sense).<br>
	*
	* @param iKey Name of the attribute.
	* @param iValue Value of the attribute.
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
	* @return [CATBaseUnknown#Release]iValue Value of the attribute (an AddRef is done, if not NULL).
	*/
	virtual CATIValue* GetValue( const CATUnicodeString& iKey ) = 0;
	


};

CATDeclareHandler(CATIInstanceExtension,CATBaseUnknown);

//------------------------------------------------------------------

#endif
