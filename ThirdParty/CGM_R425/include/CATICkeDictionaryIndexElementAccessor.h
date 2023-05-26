/**
 * @level Protected
 * @usage U1
 */

// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATICkeDictionaryIndexElementAccessor.h
// Define the CATICkeDictionaryIndexElementAccessor interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Sep 2004  Creation: Code generated by the CAA wizard  sgq
//===================================================================
#ifndef CATICkeDictionaryIndexElementAccessor_H
#define CATICkeDictionaryIndexElementAccessor_H

#include "CATLifDictionary.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifDictionary IID_CATICkeDictionaryIndexElementAccessor;
#else
extern "C" const IID IID_CATICkeDictionaryIndexElementAccessor ;
#endif

//------------------------------------------------------------------
class CATCkeDictionaryIndexElement;
class CATString;

/**
* Interface to generate the index name from the object to index and
* conversely to fetch this object from its index name.
*
* Use @href CATCkeDictionaryIndexElementAccessorAdapter for implementation.
*/
class ExportedByCATLifDictionary CATICkeDictionaryIndexElementAccessor : public CATBaseUnknown
{
	CATDeclareInterface;
	
public:

	/**
	* generate the non-NLS name referencing iObjectToIndex in the index
	*
	* @param iObjectToIndex
	*/
	virtual CATString getIndexName(const CATBaseUnknown_var& iObjectToIndex) const = 0;

	/**
	* Retrieve the object thanks to its index name and a context
	*
	* @param iIdxElement
	* @param iContext
	*/
	virtual CATBaseUnknown_var getIndexedObject(const CATCkeDictionaryIndexElement& iIdxElement, CATBaseUnknown_var& iContext) const = 0;

	/**
	* Determines if the object corresponding to the index element, is accessible, without loading it
	*
	* @param iElt
	*/
	virtual int isInstalled(const CATCkeDictionaryIndexElement& iElt) const = 0;
};

//------------------------------------------------------------------

#endif
