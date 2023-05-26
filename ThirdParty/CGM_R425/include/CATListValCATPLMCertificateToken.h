/* -*-c++-*- */
#ifndef CATLISTV_CATPLMCertificateToken_H
#define CATLISTV_CATPLMCertificateToken_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
/**
 * @level Private
 * @usage U3
 */

#include "CATPLMServicesItf.h"

class CATPLMCertificateToken;

// Clean previous functions requests
#include "CATLISTV_Clean.h"

// Require needed functions

/** @nodoc INTERNAL */
#define CATLISTV_Append
#define CATLISTV_Locate
#define CATLISTV_RemoveAll

// Get macros
// Generate interface of collection-class

#include "CATLISTV_Declare.h"

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMServicesItf

CATLISTV_DECLARE( CATPLMCertificateToken )

typedef CATLISTV(CATPLMCertificateToken) CATListOfCATPLMCertificateToken;

#endif
