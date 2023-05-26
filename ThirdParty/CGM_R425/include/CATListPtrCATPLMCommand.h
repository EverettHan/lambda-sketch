/**
* @level Private
* @usage U1
*/
#ifndef INCL_CATListPtrCATPLMCommand_h
#define INCL_CATListPtrCATPLMCommand_h

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @collection CATLISTP(CATPLMCommand)
 * Collection class for pointers to <tt>CATPLMCommand</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATPLMCommand
 */

// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.
#define CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define CATLISTP_Locate

// Get macros
#include  <CATLISTP_Declare.h>

#include "CATPLMCommand.h"

// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(CATPLMCommand) type.
CATLISTP_DECLARE( CATPLMCommand )

#endif
