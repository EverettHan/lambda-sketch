/**
* @level Protected
* @usage U1
*/
#ifndef INCL_CATListPtrCATIPLMFilterSelectCriteria_h
#define INCL_CATListPtrCATIPLMFilterSelectCriteria_h

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * @collection CATLISTP(CATIPLMFilterSelectCriteria)
 * Collection class for pointers to <tt>CATIPLMFilterSelectCriteria</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATIPLMFilterSelectCriteria
 */

// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.
//#include <CATLISTP_AllFunct.h>
#define CATLISTP_Append
#define CATLISTP_InsertAt
#define CATLISTP_Locate
#define CATLISTP_RemoveAll

// Get macros
#include  <CATLISTP_Declare.h>

// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(CATIPLMFilterSelectCriteria) type.
#include "CATIPLMFilterSelectCriteria.h"
CATLISTP_DECLARE( CATIPLMFilterSelectCriteria )

#endif
