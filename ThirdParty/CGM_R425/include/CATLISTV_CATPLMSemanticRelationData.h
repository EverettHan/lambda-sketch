/* -*-c++-*- */
#ifndef CATLISTV_CATPLMSemanticRelationData_H
#define CATLISTV_CATPLMSemanticRelationData_H

/**
 * @level Private
 * @usage U3
 */
#include "CATPLMIdentificationAccess.h"

class CATPLMSemanticRelationData;

// Clean previous functions requests
#include "CATLISTV_Clean.h"

#define CATLISTV_MinimalFunct
#undef CATLISTV_eqOP
#undef CATLISTV_neOP

#define CATLISTV_Append
#define CATLISTV_RemovePosition
// Get macros
#include "CATLISTV_Declare.h"

// Generate interface of collection-class
#undef CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMIdentificationAccess

CATLISTV_DECLARE(CATPLMSemanticRelationData)

typedef CATLISTV(CATPLMSemanticRelationData) CATPLMSemanticRelationDatas;

#undef CATLISTV_MinimalFunct

#endif
