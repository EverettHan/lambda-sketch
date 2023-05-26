// COPYRIGHT DASSAULT SYSTEMES  1999
#ifndef CATListPtrCATIPLMIdentifierSet_H
#define CATListPtrCATIPLMIdentifierSet_H

/**
 * @level Private
 * @usage U3
*/

class CATIPLMIdentifierSet;

#include "CATLISTP_Clean.h"

// choice of services to be implemented
#define CATLISTP_CtorFromArrayPtrs
#define CATLISTP_Append
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define CATLISTP_AppendList
#define CATLISTP_RemoveDuplicatesCount

// tells NT which module exports the collection
#include "CATPLMComponentInterfaces.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByCATPLMComponentInterfaces

#include "CATLISTP_Declare.h"
CATLISTP_DECLARE( CATIPLMIdentifierSet )

#endif

