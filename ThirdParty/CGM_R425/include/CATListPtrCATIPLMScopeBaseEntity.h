/**
* @level Protected
* @usage U1
*/
#ifndef CATListPtrCATIPLMScopeBaseEntity_H
#define CATListPtrCATIPLMScopeBaseEntity_H


#include "CATLISTP_Clean.h" 
#define CATLISTP_Append
#define CATLISTP_RemoveAll

#include <CATLISTP_Declare.h>

class CATIPLMScopeBaseEntity;

#include "CATPLMIntegrationInterfaces.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMIntegrationInterfaces
CATLISTP_DECLARE(CATIPLMScopeBaseEntity)

typedef class CATLISTP (CATIPLMScopeBaseEntity) CATListPtrCATIPLMScopeBaseEntity;


#endif
