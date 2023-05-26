#ifndef CATITypeDictionaryListener_h
#define CATITypeDictionaryListener_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */


/*  CAA2Reviewed by FRH */
 
// inherited class 
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

// load module
#include "CATLifSpecs.h"

class CATICkeObject_var;
class CATIType_var;

// OLE IID
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATITypeDictionaryListener;
#else
extern "C" const IID IID_CATITypeDictionaryListener;
#endif


/**
 * Interface dedicated to monitor the changes on a dictionary.
 * This interface is multi implemented.
 *
 * @see CATIType, CATITypeDictionary
 *
 */

class ExportedByCATLifSpecs CATITypeDictionaryListener : public CATBaseUnknown
{
public:
	/**
 	* Called whenever an instance is created from a type.
	* @param iType Type of the instance.
	* @param iInstance Created instance.
	* @return classic HRESULT
	*/
	virtual HRESULT Instanciated( const CATIType_var &iType,
								  const CATICkeObject_var &iInstance) = 0;

	/**
 	* Called whenever a type is added to the dictionary.
	* @param iType Added type.
	* @return classic HRESULT
	*/
	virtual HRESULT TypeAdded( const CATIType_var &iType ) = 0;
	
	/**
    * Called whenever a type is modified.
	* @param iType Modified type.
	* @return classic HRESULT
	*/
	virtual HRESULT TypeUpdated(const CATIType_var & iType ) = 0;

	/**
 	* Called whenever a type is removed from the dictionary.
	* @param iType Removed type.
	* @return classic HRESULT
	*/
	virtual HRESULT TypeRemoved( const CATIType_var &iType ) = 0;
	
	/**
 	* Called whenever a method is added to the dictionary.
	* @param iMethod Added method.
	* @return classic HRESULT
	*/
	virtual HRESULT MethodAdded( const CATBaseUnknown_var &iMethod ) = 0;
	
	/**
 	* Called whenever a method is removed from the dictionary.
	* @param iMethod Removed method.
	* @return classic HRESULT
	*/
	virtual HRESULT MethodRemoved( const CATBaseUnknown_var &iMethod ) = 0;

	/**
 	* Called to synchronize the dictionary description whenever asked by dictionary.
	* @return classic HRESULT
	*/
	virtual HRESULT MustBeSynchronized() = 0;
	
private:
  CATDeclareInterface;
}; 

CATDeclareHandler(CATITypeDictionaryListener, CATBaseUnknown);

#endif
