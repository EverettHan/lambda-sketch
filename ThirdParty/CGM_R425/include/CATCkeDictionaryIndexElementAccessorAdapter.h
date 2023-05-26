/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/

// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATCkeDictionaryIndexElementAccessorAdapter.h
//
//===================================================================
//  Sep 2004  Creation: Code generated by the CAA wizard  sgq
//===================================================================
#ifndef CATCkeDictionaryIndexElementAccessorAdapter_H
#define CATCkeDictionaryIndexElementAccessorAdapter_H

#include "CATLifDictionary.h"
#include "CATBaseUnknown.h"

//------------------------------------------------------------------
class CATString;
class CATCkeDictionaryIndexElement;

/**
* Adapter class for implementing CATICkeDictionaryIndexElementAccessor interface
*/
class ExportedByCATLifDictionary CATCkeDictionaryIndexElementAccessorAdapter: public CATBaseUnknown
{
public:
	CATCkeDictionaryIndexElementAccessorAdapter();
	virtual ~CATCkeDictionaryIndexElementAccessorAdapter();

	// From object to index key
	virtual CATString getIndexName(const CATBaseUnknown_var& iObjectToIndex) const;

	// From index key to object (loads whatever it needs)
	virtual CATBaseUnknown_var getIndexedObject(const CATCkeDictionaryIndexElement& anElt, CATBaseUnknown_var& iContext) const;

	// Determines without loading anything if the object may be accessible
	virtual int isInstalled(const CATCkeDictionaryIndexElement& anElt) const;
};

//------------------------------------------------------------------

#endif
