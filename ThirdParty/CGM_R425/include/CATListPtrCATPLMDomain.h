/**
* @level Private
* @usage U1
*/
#ifndef INCL_CATListPtrCATPLMDomain_h
#define INCL_CATListPtrCATPLMDomain_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @collection CATLISTP(CATPLMDomain)
 * Collection class for pointers to <tt>CATPLMDomain</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATPLMDomain
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

#include "CATPLMDomain.h"

// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(CATPLMDomain) type.
CATLISTP_DECLARE( CATPLMDomain )

#endif
