/**
* @level Private
* @usage U1
*/

#ifndef __CATLISTP_CATPLMProviderEvent_H__
#define __CATLISTP_CATPLMProviderEvent_H__
/**
* @collection CATLISTP(CATPLMProviderReference)
* Collection class for pointers to <tt>CATPLMProviderReference</tt>.
* All the methods of pointer collection classes are available.
* Refer to the articles dealing with collections in the encyclopedia.
* @see CATPLMProviderReference
*/

// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.

#define CATLISTP_Append
#define CATLISTP_Locate
#define CATLISTP_RemoveAll

// Get macros
#include  <CATLISTP_Declare.h>


// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

class CATPLMProviderEvent;
CATLISTP_DECLARE(CATPLMProviderEvent)
typedef CATLISTP(CATPLMProviderEvent) CATLISTP_CATPLMProviderEvent;

#endif // __CATLISTP_CATPLMProviderEvent_H__
