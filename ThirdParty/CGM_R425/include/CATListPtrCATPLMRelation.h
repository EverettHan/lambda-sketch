/**
* @level Protected
* @usage U1
*/
// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
#ifndef INCL_CATListPtrCATPLMRelation_h
#define INCL_CATListPtrCATPLMRelation_h

// COPYRIGHT DASSAULT SYSTEMES 2003
/**
 * @collection CATLISTP(CATPLMRelation)
 * Collection class for pointers to <tt>CATPLMRelation</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATPLMRelation
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

#include "CATPLMRelation.h"

// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(CATPLMRelation) type.
CATLISTP_DECLARE( CATPLMRelation )

#endif
