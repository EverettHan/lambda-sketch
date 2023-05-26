/**
* @level Protected
* @usage U1
*/
#ifndef INCL_CATListPtrCATPLMEnvironment_h
#define INCL_CATListPtrCATPLMEnvironment_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @collection CATLISTP(CATPLMEnvironment)
 * Collection class for pointers to <tt>CATPLMEnvironment</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATPLMEnvironment
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

#include "CATPLMEnvironment.h"

// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(CATPLMEnvironment) type.
CATLISTP_DECLARE( CATPLMEnvironment )

#endif
