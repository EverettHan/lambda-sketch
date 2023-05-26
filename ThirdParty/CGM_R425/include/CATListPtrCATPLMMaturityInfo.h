/**
* @level Protected
* @usage U1
*/
#ifndef INCL_CATListPtrCATPLMMaturityInfo_h
#define INCL_CATListPtrCATPLMMaturityInfo_h

// COPYRIGHT DASSAULT SYSTEMES 2003
/**
 * @collection CATLISTP(CATPLMMaturityInfo)
 * Collection class for pointers to <tt>CATPLMMaturityInfo</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATPLMMaturityInfo
 */

// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.
#define CATLISTP_Append
#define CATLISTP_AppendList
// Get macros
#include  <CATLISTP_Declare.h>

#include "CATPLMMaturityInfo.h"

// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(CATPLMMaturityInfo) type.
CATLISTP_DECLARE( CATPLMMaturityInfo )

#endif
