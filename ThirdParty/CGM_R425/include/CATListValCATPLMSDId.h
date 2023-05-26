/**
* @level Protected
* @usage U1
*/
#ifndef INCL_CATListValCATPLMSDId_h
#define INCL_CATListValCATPLMSDId_h

#include "CATPLMSDId.h" // a forward decl should suffice if it weren't for .cpps that rely on this...

// COPYRIGHT DASSAULT SYSTEMES 2003
/**
 * @collection CATLISTV(CATPLMSDId)
 * Collection class for pointers to <tt>CATPLMSDId</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATPLMSDId
 */

// Clean previous functions requests
#include  <CATLISTV_Clean.h>

// Specify the function to take into account.
#define CATLISTV_Append
// Get macros
#include  <CATLISTV_Declare.h>

#include "CATPLMSDId.h"

// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(CATPLMSDId) type.
CATLISTV_DECLARE( CATPLMSDId )

#endif
