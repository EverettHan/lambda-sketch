#ifndef CATLISTP_CATIPLMModelerEventAccess_H
#define CATLISTP_CATIPLMModelerEventAccess_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATLISTP_Clean.h"

#define  CATLISTP_Append
#define  CATLISTP_Locate
#define  CATLISTP_InsertAt
#define  CATLISTP_RemoveValue
#define  CATLISTP_RemovePosition
#define  CATLISTP_RemoveAll

#include "CATLISTP_Declare.h"

#include "CATPLMModelerBaseInterfaces.h"

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATPLMModelerBaseInterfaces

class CATIPLMModelerEventAccess;

CATLISTP_DECLARE(CATIPLMModelerEventAccess)

#endif



