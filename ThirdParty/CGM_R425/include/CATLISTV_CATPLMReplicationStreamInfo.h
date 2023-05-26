/* -*-c++-*- */
#ifndef CATLISTV_CATPLMReplicationStreamInfo_H
#define CATLISTV_CATPLMReplicationStreamInfo_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
/**
 * @level Private
 * @usage U3
 */

#include "CATPLMServicesItf.h"

class CATPLMReplicationStreamInfo;

// Clean previous functions requests
#include "CATLISTV_Clean.h"

// Require needed functions

/** @nodoc INTERNAL */
#define CATLISTV_Append

// Get macros
// Generate interface of collection-class

#include "CATLISTV_Declare.h"

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMServicesItf

CATLISTV_DECLARE( CATPLMReplicationStreamInfo )

#endif
