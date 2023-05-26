/**
* @level Protected
* @usage U1
*/
#ifndef CATListPtrCATIPLMFilterExplicit_h
#define CATListPtrCATIPLMFilterExplicit_h

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * @collection CATLISTP(CATIPLMFilterExplicit)
 * Collection class for pointers to <tt>CATIPLMFilterExplicit</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATIPLMFilterExplicit
 */

// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.
//#include <CATLISTP_AllFunct.h>
#define CATLISTP_Append
#define CATLISTP_RemoveAll

// Get macros
#include  <CATLISTP_Declare.h>

// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(CATIPLMFilterExplicit) type.
#include "CATIPLMFilterExplicit.h"
CATLISTP_DECLARE( CATIPLMFilterExplicit )

#endif
