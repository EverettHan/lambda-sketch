/**
* @level Protected
* @usage U1
*/
#ifndef CATListPtrCATPLMSemanticRelationId_h
#define CATListPtrCATPLMSemanticRelationId_h

/**
 * @collection CATLISTP(CATPLMSemanticRelationId)
 * Collection class for pointers to <tt>CATPLMSemanticRelationId</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATPLMSemanticRelationId
 */

// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.
#define CATLISTP_Append
#define CATLISTP_RemoveAll
#define CATLISTP_Locate

// Get macros
#include  <CATLISTP_Declare.h>

// Define the NT DLL export macro
#include "CATPLMIdentificationAccess.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMIdentificationAccess

// Declare the CATLISTP(CATPLMSemanticRelationId) type.
#include "CATPLMSemanticRelationId.h"
CATLISTP_DECLARE( CATPLMSemanticRelationId )

#endif
