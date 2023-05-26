/**
* @level Protected
* @usage U1
*/
#ifndef CATListPtrCATIPLMTransaction_h
#define CATListPtrCATIPLMTransaction_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @collection CATLISTP(CATIPLMTransaction)
 * Collection class for pointers to <tt>CATIPLMTransaction</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATIPLMTransaction
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
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(CATIPLMTransaction) type.
#include "CATIPLMTransaction.h"
CATLISTP_DECLARE( CATIPLMTransaction )

#endif
