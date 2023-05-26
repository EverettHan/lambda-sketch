// Copyright Dassault Systemes 2000
#ifndef CATKweInstanceDelegationAdapter_H
#define CATKweInstanceDelegationAdapter_H

#include "CATLifSpecs.h"


// forwards
#include "CATIInstanceDelegation.h"
#include "CATUnicodeString.h"
#include "CATListValCATIType.h"
#include "CATBaseUnknown.h"
#include "CATIValue.h"


/**   
 * This class should be used as an adapter for PLM Disciplines that want to be used through
 * Knowledge Expert, the Search and GenerativeKnowledge.
 *
 * It is an adapter of CATIInstanceExtension interface. This interface is used
 * by a feature extension to declare its types and attributes so that they can be used in Knowledge Expert to 
 * identify an object through its type. It is also used by GenerativeKnwoledge and the search 
 * of CATIA
 *
 * In addition to extension, you must create the TIE object with 
 * - TIEchain_CATIInstanceExtension
 *
 * @see CATIInstance,CATIType,CATIValue
 */

class ExportedByCATLifSpecs CATKweInstanceDelegationAdapter : public CATIInstanceDelegation
{
public:
	
	
	CATKweInstanceDelegationAdapter();
	virtual ~CATKweInstanceDelegationAdapter() ;
		
	//-------------------------------------------
	// Interface CATIInstanceExtension implementation
	//-------------------------------------------
	
   /**
	* Fills the given list with types supported by this feature extension.
	* <br>
	* The list is input may not be empty. This method is supposed to add some types to the list.
	* <br>
	* Default implementation does nothing
	*
	* @param iolListOfCATIType the filled list.
	*/
	virtual HRESULT ListSupportedTypes( CATListValCATIType_var& iolListOfCATIType ) const ;

	/**
	* Sets an attribute value.
	*
	* <br>
	* Default implementation does nothing
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
							  const CATIValue_var& iValue ) ;

	/**
	* Gets an attribute value.
	* <br>
	* Default implementation does nothing, and returns NULL
	*
	* @param iKey Name of the attribute.
	* @return [CATBaseUnknown#Release]  iValue Value of the attribute (an AddRef is done, if not NULL).
	*/
	virtual CATIValue* GetValue( const CATUnicodeString& iKey ) ;
   
 
private:

	
};

#endif
