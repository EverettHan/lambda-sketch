#ifndef CATLISTP_CATIGenericSessionFilter_H
#define CATLISTP_CATIGenericSessionFilter_H

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

#include "CATPLMModelerOccInterfaces.h"

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATPLMModelerOccInterfaces

class CATIGenericSessionFilter;

CATLISTP_DECLARE(CATIGenericSessionFilter)

#endif



