#ifndef	CATListPtrCATOmbStreamDescriptorDefinitionKey_h
#define	CATListPtrCATOmbStreamDescriptorDefinitionKey_h

/**
* @level  Private
* @usage   U1
*/

// type of elements
#include "CATOmbStreamDescriptorDefinitionKey.h"

// clean previous functions requests
#include  "CATLISTP_Clean.h"

// require needed functions
#define CATLISTP_Append
#define CATLISTP_RemoveAll

// get macros
#include  "CATLISTP_Declare.h"

// exporting module
#include  "CATOmbSelectiveLoading.h"

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATOmbSelectiveLoading

//
// generate interface of collection-class
// (functions declarations)
//
CATLISTP_DECLARE(CATOmbStreamDescriptorDefinitionKey)

#define CATListPtrCATOmbStreamDescriptorDefinitionKey CATListPtrCATOmbStreamDescriptorDefinitionQualifiers

#endif	// CATListPtrCATOmbStreamDescriptorDefinitionKey_h
