#ifndef CATListPtrCATILinkableObject_h
#define CATListPtrCATILinkableObject_h

/**
* @level Protected
* @usage U1
 */

#include "CATILinkableObject.h"

#include "CATLISTP_Clean.h"
//  Require needed functions
#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_InsertAt
#define CATLISTP_Locate
#define CATLISTP_RemoveAll
#define CATLISTP_RemoveValue
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveDuplicatesCount
#include "CATLISTP_Declare.h"


#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATOMY


CATLISTP_DECLARE(CATILinkableObject)

#endif
