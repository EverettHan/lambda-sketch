/**
* @level Protected
* @usage U1
*/
#ifndef CATListPtrCATPLMSemanticRelation_h
#define CATListPtrCATPLMSemanticRelation_h

/**
 * @collection CATLISTP(CATPLMSemanticRelation)
 * Collection class for pointers to <tt>CATPLMSemanticRelation</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATPLMSemanticRelation
 */

// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.
#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_RemoveAll
#define CATLISTP_RemovePosition
#define CATLISTP_Locate

// Get macros
#include  <CATLISTP_Declare.h>

// Define the NT DLL export macro
#include "CATPLMIdentificationAccess.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMIdentificationAccess

// Declare the CATLISTP(CATPLMSemanticRelation) type.
#include "CATPLMSemanticRelation.h"
CATLISTP_DECLARE( CATPLMSemanticRelation )

#endif
