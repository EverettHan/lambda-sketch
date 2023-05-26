/* -*-c++-*- */
#ifndef CATLISTV_CATPLMValidityResult_H
#define CATLISTV_CATPLMValidityResult_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
/**
 * @level Private
 * @usage U3
 */

#include "CATPLMServicesItf.h"

class CATPLMValidityResult;

// Clean previous functions requests
#include "CATLISTV_Clean.h"

// Require needed functions

/** @nodoc INTERNAL */
#define CATLISTV_Append
#define CATLISTV_RemoveAll

// Get macros
// Generate interface of collection-class

#include "CATLISTV_Declare.h"

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMServicesItf

CATLISTV_DECLARE( CATPLMValidityResult )

#endif