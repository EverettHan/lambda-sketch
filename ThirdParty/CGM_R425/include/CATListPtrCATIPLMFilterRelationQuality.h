/**
* @level Private
* @usage U1
*/
#ifndef INCL_CATListPtrCATIPLMFilterRelationQuality_h
#define INCL_CATListPtrCATIPLMFilterRelationQuality_h

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @collection CATLISTP(CATIPLMFilterRelationQuality)
 * Collection class for pointers to <tt>CATIPLMFilterRelationQuality</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATIPLMFilterRelationQuality
 */

// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.
//#include <CATLISTP_AllFunct.h>
#define CATLISTP_Append
#define CATLISTP_Locate
#define CATLISTP_RemoveAll
#define CATLISTP_AppendList

// Get macros
#include  <CATLISTP_Declare.h>

// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(CATIPLMFilterRelation) type.
#include "CATIPLMFilterRelationQuality.h"
CATLISTP_DECLARE( CATIPLMFilterRelationQuality )

#endif
