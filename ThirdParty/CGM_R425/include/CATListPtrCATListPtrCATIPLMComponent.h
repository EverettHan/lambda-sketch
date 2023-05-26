#ifndef CATListPtrCATListPtrCATIPLMComponent_h
#define CATListPtrCATListPtrCATIPLMComponent_h
//===================================================================
// COPYRIGHT Dassault Systemes 2003
//===================================================================

// COPYRIGHT DASSAULT SYSTEMES 2003
/**
 * @collection CATLISTP(CATListPtrCATIPLMComponent)
 * Collection class for pointers to <tt>CATListPtrCATIPLMComponent</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATListPtrCATIPLMComponent
 */
/**
* @CAA2Level L1 
* @CAA2Usage U1 
*/

// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.
#define CATLISTP_Append
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll

// Get macros
#include  <CATLISTP_Declare.h>

// Define the NT DLL export macro
#include "CATPLMIdentificationAccess.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMIdentificationAccess

// Declare the CATLISTP(CATPLMRelation) type.
#include "CATListPtrCATIPLMComponent.h"
CATLISTP_DECLARE( CATListPtrCATIPLMComponent )

#endif
