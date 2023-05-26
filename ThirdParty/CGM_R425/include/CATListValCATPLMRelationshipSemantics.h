//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef CATListValCATPLMRelationshipSemantics_h
#define CATListValCATPLMRelationshipSemantics_h

class CATPLMRelationshipSemantics;

/**
 * @collection CATLISTP(CATPLMRelationshipSemantics)
 * Collection class for Unicode strings.
 */

// Clean previous functions requests
#include  <CATLISTV_Clean.h>

// Specify the function to take into account.
#define CATLISTV_Append
#define CATLISTV_RemoveValue
#define CATLISTV_RemovePosition
#define CATLISTP_RemoveAll
#define CATLISTV_Locate

// Get macros
#include  <CATLISTV_Declare.h>

// Define the NT DLL export macro
#include "CATPLMSemantics.h"
#undef    CATCOLLEC_ExportedBy
#define    CATCOLLEC_ExportedBy ExportedByCATPLMSemantics

// Declare the CATLISTP(CATPLMRelationshipSemantics) type.
#include "CATPLMRelationshipSemantics.h"
CATLISTV_DECLARE( CATPLMRelationshipSemantics )

#endif


