/**
* @level Protected
* @usage U1
*/
#ifndef INCL_CATListPtrCATIPLMProviderDesc_h
#define INCL_CATListPtrCATIPLMProviderDesc_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @collection CATLISTP(CATIPLMProviderDesc)
 * Collection class for pointers to <tt>CATIPLMProviderDesc</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATIPLMProviderDesc
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

// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(CATIPLMProviderDesc) type.
#include "CATIPLMProviderDesc.h"
CATLISTP_DECLARE( CATIPLMProviderDesc )

#endif
