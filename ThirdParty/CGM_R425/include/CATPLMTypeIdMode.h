// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATPLMTypeIdMode.h
// Header definition of CATPLMTypeIdMode
//
//===================================================================
//
// Usage notes:
// Enum that is used when you want to use the method CATPLMType::GetTypeId
// with or without restrictions using the method SetTypeIdMode
//
//===================================================================
// Feb 2010  Creation: EPB
//===================================================================

/**
 * @level Protected
 * @usage U1
 */

#ifndef CATPLMTypeIdMode_H
#define CATPLMTypeIdMode_H

#include "CATPLMServicesItf.h"

enum ExportedByCATPLMServicesItf CATPLMTypeIdMode{ CATPLM_NORESTRICTION , CATPLM_BASICRESTRICTIONS};

#endif
