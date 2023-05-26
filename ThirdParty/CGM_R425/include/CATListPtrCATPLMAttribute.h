/**
* @level Protected
* @usage U1
*/
#ifndef INCL_CATListPtrCATPLMAttribute_h
#define INCL_CATListPtrCATPLMAttribute_h

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @collection CATLISTP(CATPLMAttribute)
 * Collection class for pointers to <tt>CATPLMAttribute</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATPLMAttribute
 */

// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.
#define CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define CATLISTP_ReSize
#define CATLISTP_RemoveNulls
#define CATLISTP_Locate

// Get macros
#include  <CATLISTP_Declare.h>

#include "CATPLMAttribute.h"

// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(CATPLMAttribute) type.
CATLISTP_DECLARE( CATPLMAttribute )

#endif
