/**
* @level Protected
* @usage U1
*/
#ifndef __CATListPtrCATListPtrCATPLMType_h__
#define __CATListPtrCATListPtrCATPLMType_h__

#include "CATListPtrCATPLMType.h" // a forward decl should suffice if it weren't for .cpps that rely on this...

// COPYRIGHT DASSAULT SYSTEMES 2003
/**
 * @collection CATLISTP(CATPLMType)
 * Collection class for pointers to <tt>CATPLMType</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATPLMType
 */

// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.
#define CATLISTP_Append
#define CATLISTP_RemoveAll
#define CATLISTP_Size
// Get macros
#include  <CATLISTP_Declare.h>

// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(CATListPtrCATPLMType) type.
CATLISTP_DECLARE( CATListPtrCATPLMType )

#endif
