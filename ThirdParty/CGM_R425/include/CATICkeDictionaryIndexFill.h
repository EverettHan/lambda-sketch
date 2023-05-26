/**
 * @level Protected
 * @usage U1
 */

// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATICkeDictionaryIndexFill.h
// Define the CATICkeDictionaryIndexFill interface
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
#ifndef CATICkeDictionaryIndexFill_H
#define CATICkeDictionaryIndexFill_H

#include "CATLifDictionary.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifDictionary IID IID_CATICkeDictionaryIndexFill;
#else
extern "C" const IID IID_CATICkeDictionaryIndexFill ;
#endif

//------------------------------------------------------------------

class CATCkeDictionaryIndex;

/**
* Interface for filling the index
*
* Use @href CATCkeDictionaryIndexFillAdapter for implementation.
*/
class ExportedByCATLifDictionary CATICkeDictionaryIndexFill: public CATBaseUnknown
{
	CATDeclareInterface;
	
public:

	/**
	* @nodoc
	*
	* Fill the index with new elements
	*
	* @param iDictionaryIndex
	*/
	virtual int fill(CATCkeDictionaryIndex& iDictionaryIndex) const = 0;

	/**
	* Fill the index with new elements
	*
	* @param iDictionaryIndex
	* @param restrictionPaths Paths (if any) to take into account
	*/
	virtual int fillWithContext(CATCkeDictionaryIndex& iDictionaryIndex, CATListOfCATUnicodeString restrictionPaths) const = 0;
};

//------------------------------------------------------------------

#endif